from pathlib import Path
import json
import os
import re
import struct
import sys

from PIL import Image, ImageDraw, ImageFont
import zh_overlay as zh
from events_pack import write_msg
from ui import decode_tex, encode_textures

repo, pack, overlay, game, lang = map(Path, sys.argv[1:])
rows = {}
for line in (repo / 'review.md').read_text().splitlines():
    if not re.match(r'^\| [A-Z]\d\d \|', line):
        continue
    cells = [cell.strip() for cell in line.split('|')[1:-1]]
    assert cells[0] not in rows
    rows[cells[0]] = cells[1:]
assert len(rows) == 178

glyphs = {}
def encode(text, size=0):
    parts = re.split(r'(\{[A-Z]+\})', text)
    return ''.join(part if i % 2 else ''.join(
        char if ord(char) < 128 and (not size or char == ' ') else
        zh.full_width(glyphs.setdefault((char, size), 0x1000 + len(glyphs)))
        for char in part) for i, part in enumerate(parts))

def entry(key):
    row = rows[key]
    size = 2 if key.startswith('H') else 1 if key.startswith('K') else (
        int(row[4] or 0) if len(row) > 4 else 0)
    return encode(row[3] if len(row) > 3 and key[0] not in 'HK' else row[2], size)

def cstr(value):
    return json.dumps(value, ensure_ascii=True).replace(r'\u0006', r'\006')

def read_msg(path):
    data = path.read_bytes()
    magic, count = struct.unpack_from('<4sI', data)
    assert magic == b'MSG1'
    return [data[i:data.index(0, i)].decode('latin1')
            for i in struct.unpack_from(f'<{count}I', data, 8)]

events = pack / 'events'
for base in events.glob('*.msg'):
    target = events / 'f' / base.name
    localized = overlay / 'events' / base.name
    target.write_bytes((localized if localized.exists() else base).read_bytes())

for file, indices, prefix in [
    ('option.msg', [238,239,240,241,242,243,252,253,246,247,248,249,250,251,210], 'T'),
    ('pause.msg', range(9), 'P'),
]:
    messages = read_msg(events / file)
    for i, index in enumerate(indices, 1):
        messages[index] = entry(f'{prefix}{i:02}')
    if prefix == 'T':
        titles = ['开场混剪', '开场混剪（对白版）', '詹姆斯在洗手间', '墓地遇见安吉拉', '公寓遇见艾迪', '安吉拉的刀', '围墙上的劳拉', '湖畔遇见玛丽亚', '旅馆的回忆', '医院重逢', '铁栏后的玛丽亚', '倒地的艾迪', '艾迪与詹姆斯对峙', '玛丽的录像带', '玛丽亚结局', '重生结局', '入水结局', '离开结局', '玛丽亚篇结局', '狗结局', '寂静岭2 E3 2001 预告片', '寂静岭3 E3 2002 预告片', '寂静岭2 PC版制作人员', '寂静岭3 TGS 2002 预告片']
        movie_names = messages[214:238] + [encode(title) for title in titles]
        messages[214:238] = movie_names[24:]
        messages[244], messages[245] = messages[252], messages[253]
    write_msg(events / 'f' / file, messages)
messages = read_msg(events / 'mcard.msg')
pause_places = messages[157:217]
place_codes = set()
atlas = zh.font_inputs(lang)
pc_locations = zh.read_messages(lang / 'etc/message/m_card_x_msg_j.mes',
                                atlas[2] * atlas[3] // 2, place_codes)
assert len(pc_locations) == len(messages)
for index in (*range(33), 81, 82, 83, *range(159, 217)):
    if pc_locations[index]:
        messages[index] = pc_locations[index].split('\f', 1)[0].strip()
for number, index in {3:154,4:33,5:36,6:46,9:40,10:41}.items():
    messages[index] = entry(f'S{number:02}')
write_msg(events / 'f/mcard.msg', messages)
pause_places += messages[157:217]

options = []
for i in range(1, 33):
    title, values, note = rows[f'C{i:02}'][4].split('_', 2)
    if i == 29:
        values, note = '自动/低/高', note.removeprefix('高_')
    if i == 5:
        values = '走/切换/模拟/跑'
    if i == 32 and note.startswith('老三/新三_'):
        values, note = '自动/老三/新三', note.split('_', 1)[1]
    if i == 28:
        values = '英文/中文'
    options.append((encode(title), [encode(v) for v in values.split('/') if v != '-'], encode(note, 1)))

help_rows = [(rows[f'H{i:02}'][1], entry(f'H{i:02}')) for i in range(1, 68)]
ui = {key: entry(key) for key in rows if key[0] in 'BOK' or key in ('S01','S02','S07','S08','P10','P11')}
extra = {value: encode(translated, 2) for value, translated in [
    ('The C-Stick turns it', '用C摇杆转动镜头'), ('The D-Pad or a drag turns it', '用方向键或拖动转动镜头'),
    ('High', '高'), ('Low', '低'), ('New', '新'), ('Old', '老'), ('LanguageChinese', '中文'),
    ('OptionTitle', '游戏选项'), ('BrightnessTitle', '画面亮度')]}
extra.update({key: encode(value) for key, value in {
    'Check': '检查', 'Items': '道具', 'Light': '手电', 'Pause': '暂停', 'Attack': '攻击',
    'No map': '没有当前区域的地图', 'Condition': '状态', 'Fine': '良好', 'Caution': '警戒', 'Danger': '危险',
    'Weapon': '武器', 'Healing': '治疗', 'Drink': '饮料', 'First Aid': '急救包', 'Ampoule': '安瓿', 'None': '无',
    'SetupCamera': '镜头', 'SetupMovement': '操作方式',
    'SetupOriginal': '原始', 'SetupBehind': '追随', 'SetupTank': '坦克式', 'SetupDirectional': '指向式',
    'SetupOriginalHelp': '沿用 PC 版为每个房间设计的镜头。',
    'SetupBehindNew': '镜头跟随詹姆斯，用 C 摇杆转动。',
    'SetupBehindOld': '镜头跟随詹姆斯，拖动触摸屏可转动镜头。',
    'SetupTankHelp': '左右转身，向上前进，向下后退。',
    'SetupDirectionalHelp': '朝想去的方向推摇杆。',
    'Choose': '选择', 'Start': '开始', 'Move': '移动', 'Check, pick up': '检查、拾取',
    'SetupButtonsHelp': '可在「选项」的「操作」页修改按键。',
    'AimBefore': '瞄准时按 ', 'AimAfter': ' 攻击', 'ResetCamera': ' 可让镜头复位。',
}.items()})
map_names = {
    'Silent Hill': '寂静岭', 'South Vale (east)': '南谷东区', 'South Vale (west)': '南谷西区',
    'Blue Creek Apartments': '蓝溪公寓', 'Brookhaven Hospital': '布鲁克黑文医院',
    'Toluca Prison': '托卢卡监狱', 'Labyrinth': '迷宫', 'Baldwin Mansion': '鲍德温公馆',
}
for floor in range(1, 4):
    map_names[f'Wood Side Apartments {floor}F'] = f'林边公寓{floor}楼'
    map_names[f'Apartments {floor}F'] = f'公寓{floor}楼'
for label, text in [('BF','地下室'),('1F','1楼'),('2F','2楼'),('3F','3楼')]:
    map_names[f'Lakeview Hotel {label}'] = f'湖景旅馆{text}'
extra.update({name: encode(value) for name, value in map_names.items()})
for line in (repo / 'lower-review.md').read_text().splitlines():
    if not re.match(r'^\| [IMN]\d\d \|', line):
        continue
    code, _, english, _, translation = [cell.strip() for cell in line.split('|')[1:-1]]
    if translation:
        extra[code] = encode(translation)

messages = read_msg(events / 'f/option.msg')
for index, value in {4:'调整至竖线隐约可见.', 89:'是否保存修改?', 90:'是', 91:'否'}.items():
    messages[index] = encode(value)
write_msg(events / 'f/option.msg', messages)
extra.update({key: encode(value) for key, value in {
    'PauseObservationRestroom': '观景台洗手间',
    'PauseTrailer': '房车',
    'PauseNeelysBar': '尼利酒吧',
}.items()})
extra['PauseTopTitle'] = encode(rows['P01'][3])
extra['AuthorCredit'] = encode('张大略制作')
extra.update({key: encode(value) for key, value in {
    'SaveTimeAndCount': '游戏时间 %s     保存次数 %d',
    'SaveDifficulty': f"{rows['T09'][3]} %s     {rows['T10'][3]} %s",
    'SaveWishDifficulty': f"生于希望     {rows['T09'][3]} %s",
}.items()})
pause_text = [
    *pause_places,
    read_msg(events / 'pause.msg')[0], 'PAUSED', extra['PauseTopTitle'],
    'Observation Deck Restroom', 'Trailer', "Neely's Bar",
    extra['PauseObservationRestroom'], extra['PauseTrailer'], extra['PauseNeelysBar'],
    '0123456789: ...',
]
def text_codes(strings):
    return {
        int(token[1:], 16) if token.startswith('\x06') else ord(token) - 0x20
        for text in strings
        for token in re.findall(r'\x06[0-9a-fA-F]{4}|[^\x00-\x1f]', text)
    }


pause_codes = text_codes(pause_text)
movie_codes = text_codes(movie_names + ['abcdefghijklmnopqrstuvwxyz0123456789_ ...'])
help_codes = text_codes(text for _, text in help_rows)
header = ['#pragma once', '#include "events.h"', '#include <string.h>',
          'static inline const char* zh_ui(const char* id, const char* english) {',
          '    if (ev_language() != 2) return english;']
header.insert(-1, f'    if (!strcmp(id, "LanguageChinese")) return {cstr(extra.pop("LanguageChinese"))};')
header.insert(-1, f'    if (!strcmp(id, "AuthorCredit")) return {cstr(extra.pop("AuthorCredit"))};')
header += [f'    if (!strcmp(id, "{key}")) return {cstr(value)};' for key,value in (ui | extra).items()]
header += ['    return english;', '}', '#ifdef ZH_OPTIONS',
           'static const struct { const char* name; const char* values[4]; const char* help; } zh_settings[] = {']
for title, values, note in options:
    header += ['    {' + cstr(title) + ', {' + (', '.join(map(cstr,values)) or 'NULL') + '}, ' + cstr(note) + '},']
header += ['};','static inline const char* zh_help(const char* english) {',
           '    if (ev_language() != 2 || !english) return english;']
header += [f'    if (!strcmp(english, {cstr(key)})) return {cstr(val)};' for key,val in help_rows]
header += ['    return english;', '}', '#endif', '']
(repo / 'port/source/ui_review.h').write_text('\n'.join(header))

original_records = zh.glyph_records
font_path = str(lang / 'font/ui.ttc')


def help_bitmap(char, width, height):
    # Hint the outline at its final size and leave space between glyphs.
    size = height - 1
    while True:
        face = ImageFont.truetype(font_path, size)
        left, top, right, bottom = face.getbbox(char)
        if right - left <= width - 1 and bottom - top <= height - 1:
            break
        size -= 1
    bitmap = Image.new('L', (width, height))
    ImageDraw.Draw(bitmap).text(
        ((width - (right - left)) // 2 - left, (height - (bottom - top)) // 2 - top),
        char, font=face, fill=255,
    )
    return bitmap


def with_review(exe, font, source, codes):
    cell_w, cell_h, records = original_records(exe, font, source, codes)
    face = ImageFont.truetype(font_path, 48)
    source_bitmaps = {}
    for (char, size), code in glyphs.items():
        bitmap = Image.new('L', (64, 64))
        ImageDraw.Draw(bitmap).text((32, 32), char, font=face, fill=255, anchor='mm')
        width = round(cell_w * zh.FONT_SX) + size
        height = round(cell_h * zh.FONT_SY) + size
        if code in help_codes:
            source_bitmaps[code] = bitmap
            # Preserve punctuation's original position within its cell.
            if '\u3400' <= char <= '\u9fff':
                bitmap = help_bitmap(char, width, height)
        records.append((code, bitmap, width, height, round((width + 1) / zh.FONT_SX)))
    records += [
        larger(record, 2, 0x4000, source_bitmaps)
        for record in records if record[0] in pause_codes
    ] + [
        larger(record, 4, 0x8000, source_bitmaps)
        for record in records if font == 1 and record[0] in movie_codes
    ]
    return cell_w, cell_h, sorted(records, key=lambda rec: -rec[3])


def larger(record, pixels, offset=0, source_bitmaps=None):
    code, bitmap, width, height, advance = record
    if source_bitmaps is not None:
        bitmap = source_bitmaps.get(code, bitmap)
    return (code + offset, bitmap, width + pixels, height + pixels,
            advance + round(pixels / zh.FONT_SX))


def subtitle_records(exe, font, source, codes):
    cell_w, cell_h, records = original_records(exe, font, source, codes)
    return cell_w, cell_h, sorted(
        (larger(record, 1) for record in records), key=lambda rec: -rec[3]
    )


zh.glyph_records = with_review
codes = set(place_codes)
for path in (overlay / 'events').glob('*.msg'):
    for msg in read_msg(path):
        codes.update(int(m,16) - zh.GLYPH_OFFSET for m in re.findall(r'\x06([0-9a-f]{4})',msg)
                     if zh.GLYPH_OFFSET <= int(m,16) < 0x4000)
zh.write_font(pack, game / 'sh2pc.bak', zh.font_inputs(lang), codes)
zh.glyph_records = subtitle_records
zh.write_font(pack, game / 'sh2pc.bak', atlas, codes, name='font-subtitle')
logo = decode_tex(game / 'sh2e/pic/etc/konami2048x2048.tex').convert('RGB').resize((512,256), Image.Resampling.LANCZOS)
print('KONAMI edge pixels', [logo.getpixel(p) for p in [(0,0),(511,0),(0,255),(511,255)]])
logo.save(pack / 'ui/boot0.png')
poster = repo / 'boot1-poster.jpg'
if poster.is_file():
    with Image.open(poster) as image:
        splash = image.convert('RGB').resize((512, 256), Image.Resampling.LANCZOS)
else:
    splash = decode_tex(game / 'data/pic/etc/splash_logo.tex').convert('RGB')
    splash = splash.resize((512, 256), Image.Resampling.LANCZOS)
splash.save(pack / 'ui/boot1.png')
print(f'{len(rows)} review rows, {len(glyphs)} additional glyphs')

font_jobs = [(f'ui/{name}.png', f'ui/{name}.t3x', True) for name in ('font', 'font-subtitle')]
if os.environ.get('SH2_TEXENC') == 'native':
    from t3x import encode as encode_texture

    for png, texture, _ in font_jobs:
        encode_texture(pack / png, pack / texture, 'la4', mipmaps=False)
    encode_texture(pack / 'ui/boot1.png', pack / 'ui/boot1.t3x', 'rgb565', mipmaps=False)
else:
    encode_textures(font_jobs, pack, fmt='la4', mipmaps=False)
    encode_textures([('ui/boot1.png', 'ui/boot1.t3x', False)], pack, fmt='rgb565', mipmaps=False)
