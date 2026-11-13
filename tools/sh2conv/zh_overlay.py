"""Convert the PC Simplified Chinese messages and font for sh23ds v0.3.0."""
import argparse
from pathlib import Path
import struct

from PIL import Image
import numpy as np

from events_pack import DC_STAGE_MSG, write_msg
from pcexe import Exe
from sh2mes import full_width
from ui import FONT_CODES, FONT_SIZES, FONT_SX, FONT_SY, font_glyph

GLYPH_OFFSET = 0x2000
CONTROLS = {0xfffd: '\n', 0xfffe: full_width(0xfffe), 0xfff6: '\x05',
            0xffe0: '\x01', 0xffe1: '\x02', 0xffe2: '\x03', 0xffe3: '\x04'}


def read_messages(path, capacity, glyphs):
    data = path.read_bytes()
    count, = struct.unpack_from('<H', data)
    offsets = (*struct.unpack_from(f'<{count}H', data, 2), len(data) // 2)
    messages = []
    for start, end in zip(offsets, offsets[1:]):
        pages, page = [], []
        for code in struct.unpack_from(f'<{end - start}H', data, 2 * start):
            if code == 0xffff:
                pages.append(''.join(page))
                page = []
            elif code in CONTROLS:
                page.append(CONTROLS[code])
            elif 0xfc00 <= code <= 0xfdff:
                page.append(full_width(code))
            elif code < capacity:
                glyphs.add(code)
                page.append(full_width(GLYPH_OFFSET + code))
            elif code not in (0x1000, 0x8000, 0x9000) and code < 0xf800:
                raise ValueError(f'{path.name}: unexpected character code 0x{code:04x}')
        if page:
            pages.append(''.join(page))
        messages.append('\f'.join(p for p in pages if p))
    return messages


def font_inputs(lang):
    path = lang / 'font/font000.png'
    image = Image.open(path).convert('RGBA')
    with path.open('rb') as stream:
        stream.seek(-16, 2)
        tag, columns, rows = struct.unpack('<8sII', stream.read(16))
    if tag != b'SH2EEFNT':
        columns, rows = image.width // 44, image.height // 64
    if not columns or not rows or rows % 2 or image.width % columns or image.height % rows:
        raise ValueError('Unexpected Chinese font grid')
    widths = (lang / 'font/fontwdata.bin').read_bytes()
    if len(widths) != 448:
        raise ValueError('Unexpected Chinese font width table')
    return image.getchannel('A'), widths, columns, rows


def glyph_records(exe, font, source, codes):
    alpha, widths, columns, rows = source
    cell_w, cell_h = struct.unpack('<HH', exe.read(FONT_SIZES + 4 * font, 4))
    height = round(cell_h * FONT_SY)
    records = []
    for code in FONT_CODES:
        width, pixels = font_glyph(exe, font, code)
        advance = 7 if code == 0 else width + 2 if code < 0xe0 else cell_w + 2
        bitmap = Image.fromarray(pixels[:, :width]) if width and np.any(pixels) and code else None
        records.append((code, bitmap, max(1, round(width * FONT_SX)), height, advance))

    grid_w, grid_h = alpha.width // columns, alpha.height // rows
    for code in sorted(codes):
        row, column = divmod(code, columns)
        x = column * grid_w
        y = (row + font * (rows // 2)) * grid_h
        width = widths[font * 0xe0 + code] if code < 0xe0 else cell_w
        crop_width = max(1, min(grid_w, round(grid_w * width / cell_w)))
        bitmap = alpha.crop((x, y, x + crop_width, y + grid_h)) if width and code else None
        records.append((GLYPH_OFFSET + code, bitmap, max(1, round(width * FONT_SX)),
                        height, 7 if not code else width + 2))
    return cell_w, cell_h, records


def write_font(out, exe_path, source, codes, name="font"):
    exe = Exe(exe_path)
    atlas = Image.new('RGBA', (1024, 1024), (255, 255, 255, 0))
    font_bin = [struct.pack('<4sH', b'FNT1', 2)]
    shelves = []
    used_height = 0
    for font in range(2):
        cell_w, cell_h, records = glyph_records(exe, font, source, codes)
        font_bin.append(struct.pack('<HHH', cell_w, cell_h, len(records)))
        for code, bitmap, width, height, advance in records:
            if bitmap is None or not bitmap.getbbox():
                font_bin.append(struct.pack('<HHHBBBB', code, 0, 0, 0, 0, advance, 0))
                continue
            shelf = min(
                (row for row in shelves if row[0] + width <= atlas.width and height <= row[2]),
                key=lambda row: (row[2], -row[0]), default=None,
            )
            if shelf is None:
                if used_height + height > atlas.height:
                    raise ValueError('Chinese font atlas exceeds the 3DS texture size')
                shelf = [0, used_height, height]
                shelves.append(shelf)
                used_height += height
            x, y, _ = shelf
            glyph = Image.new('RGBA', (width, height), (255, 255, 255, 255))
            glyph.putalpha(bitmap.resize((width, height), Image.Resampling.LANCZOS))
            atlas.paste(glyph, (x, y))
            font_bin.append(struct.pack('<HHHBBBB', code, x, y, width, height, advance, 0))
            shelf[0] += width
    atlas = atlas.crop((0, 0, 1024, 1 << (min(used_height, atlas.height) - 1).bit_length()))
    (out / 'ui').mkdir(exist_ok=True, parents=True)
    (out / 'ui' / f'{name}.bin').write_bytes(b''.join(font_bin))
    atlas.save(out / 'ui' / f'{name}.png')


def main():
    parser = argparse.ArgumentParser()
    for name in ('lang', 'pack', 'exe', 'out'):
        parser.add_argument(name, type=Path)
    args = parser.parse_args()
    source = font_inputs(args.lang)
    capacity = source[2] * source[3] // 2
    events = args.pack / 'events'
    targets = {'common': 'common', 'item': 'item_x', 'memo': 'memo_x'}
    for path in events.glob('s[0-9][0-9].s3e'):
        stage = int(path.stem[1:])
        stage_name = path.read_bytes()[24:48].split(b'\0', 1)[0].decode('ascii')
        targets[path.stem] = f'stage_{DC_STAGE_MSG.get(stage, stage_name[4:].lower())}'
    codes = set()
    args.out.joinpath('events').mkdir(parents=True, exist_ok=True)
    written = 0
    for dest, name in sorted(targets.items()):
        source_path = args.lang / 'etc/message' / f'{name}_msg_j.mes'
        base = events / f'{dest}.msg'
        if not source_path.is_file() or not base.is_file():
            if base.is_file():
                print(f'Keeping {dest}: no Chinese source')
            continue
        local_codes = set()
        messages = read_messages(source_path, capacity, local_codes)
        count, = struct.unpack_from('<I', base.read_bytes(), 4)
        if len(messages) != count:
            print(f'Keeping {dest}: PC Chinese has {len(messages)} entries, 3DS has {count}')
            continue
        write_msg(args.out / 'events' / base.name, messages)
        codes.update(local_codes)
        written += 1
    write_font(args.out, args.exe, source, codes)
    print(f'Converted {written} message tables and {len(codes)} Chinese font codes')


if __name__ == '__main__':
    main()
