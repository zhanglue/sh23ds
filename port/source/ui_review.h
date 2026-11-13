#pragma once
#include "events.h"
#include <string.h>
static inline const char* zh_ui(const char* id, const char* english) {
    if (!strcmp(id, "LanguageChinese")) return "\00612af\006126e";
    if (!strcmp(id, "AuthorCredit")) return "\006138e\006137d\006138f\0061078\0061079";
    if (ev_language() != 2) return english;
    if (!strcmp(id, "P10")) return "\0061044\00610f5";
    if (!strcmp(id, "P11")) return "\00612f5\00612f6\0061067";
    if (!strcmp(id, "S01")) return "\00611dc\0061002";
    if (!strcmp(id, "S02")) return "\0061000\0061001";
    if (!strcmp(id, "S07")) return "\0061091";
    if (!strcmp(id, "S08")) return "\0061092";
    if (!strcmp(id, "B01")) return "\006100c\00612c9";
    if (!strcmp(id, "B02")) return "\006108b\006108c";
    if (!strcmp(id, "B03")) return "\00612f7\0061009";
    if (!strcmp(id, "B04")) return "\00612bb\00611f8";
    if (!strcmp(id, "B05")) return "\00612f8\00610ad";
    if (!strcmp(id, "B06")) return "\0061211\00611af";
    if (!strcmp(id, "B07")) return "\00612f9\0061206";
    if (!strcmp(id, "B08")) return "\00612fa\00612fb";
    if (!strcmp(id, "B09")) return "\00612fc\00612fd";
    if (!strcmp(id, "B10")) return "\00612fe\0061000";
    if (!strcmp(id, "B11")) return "\00611d3\00611f9\00612ff";
    if (!strcmp(id, "B12")) return "\0061004\0061005";
    if (!strcmp(id, "O01")) return "\0061300\00610f0";
    if (!strcmp(id, "O02")) return "\00610ab\00610ac\00610ce";
    if (!strcmp(id, "O03")) return "\0061301\00610fd";
    if (!strcmp(id, "O04")) return "\0061302\006117f";
    if (!strcmp(id, "O05")) return "\0061303\0061304";
    if (!strcmp(id, "O06")) return "\006113f\0061140";
    if (!strcmp(id, "O07")) return "\0061052\0061140";
    if (!strcmp(id, "K01")) return "\00610e2";
    if (!strcmp(id, "K02")) return "\0061305\0061306";
    if (!strcmp(id, "K03")) return "\0061307\0061308";
    if (!strcmp(id, "K04")) return "\0061309\00610f3\00610ef\006130a\006130b";
    if (!strcmp(id, "K05")) return "\0061121\006114e\006114f";
    if (!strcmp(id, "K06")) return "\006130c\006130d";
    if (!strcmp(id, "K07")) return "\006130e\006130f";
    if (!strcmp(id, "K08")) return "\0061310\00610b1";
    if (!strcmp(id, "K09")) return "\00610e6\0061311";
    if (!strcmp(id, "K10")) return "\00610e6\0061312";
    if (!strcmp(id, "K11")) return "\00610fa\00610fb";
    if (!strcmp(id, "K12")) return "\0061307\0061311";
    if (!strcmp(id, "K13")) return "\0061307\0061312";
    if (!strcmp(id, "K14")) return "\0061313\00610ca\0061314\0061315";
    if (!strcmp(id, "K15")) return "\0061316\0061317";
    if (!strcmp(id, "K16")) return "\00610b2\0061141";
    if (!strcmp(id, "K17")) return "\00610f4\00610d6";
    if (!strcmp(id, "K18")) return "\00610f4\00610d6";
    if (!strcmp(id, "K19")) return "\00610f4\00610d6 \0061318\0061319\006131a\006131b";
    if (!strcmp(id, "K20")) return "\00610f4\00610d6 \006131c\0061319\006131a\006131b";
    if (!strcmp(id, "K21")) return "\006131d\006131e\006131f";
    if (!strcmp(id, "K22")) return "\0061320\0061321";
    if (!strcmp(id, "K23")) return "\006131d\006131e";
    if (!strcmp(id, "K24")) return "\0061322\0061323";
    if (!strcmp(id, "The C-Stick turns it")) return "\00611af\00611b1\00611da\00611db\00611cd\0061010\00611ba\00611bb";
    if (!strcmp(id, "The D-Pad or a drag turns it")) return "\00611af\00611d8\00611cf\006120a\0061219\0061324\0061010\00611cd\0061010\00611ba\00611bb";
    if (!strcmp(id, "High")) return "\0061325";
    if (!strcmp(id, "Low")) return "\00612f1";
    if (!strcmp(id, "New")) return "\0061008";
    if (!strcmp(id, "Old")) return "\0061326";
    if (!strcmp(id, "OptionTitle")) return "\0061006\0061007\006100c\006100d";
    if (!strcmp(id, "BrightnessTitle")) return "\0061011\006108f\00612ef\0061026";
    if (!strcmp(id, "Check")) return "\0061327\0061328";
    if (!strcmp(id, "Items")) return "\006117a\0061329";
    if (!strcmp(id, "Light")) return "\0061041\006114d";
    if (!strcmp(id, "Pause")) return "\006132a\006132b";
    if (!strcmp(id, "Attack")) return "\00610cf\00610d0";
    if (!strcmp(id, "No map")) return "\0061095\0061096\006132c\006132d\006132e\006132f\006104e\0061044\00610f5";
    if (!strcmp(id, "Condition")) return "\0061330\0061331";
    if (!strcmp(id, "Fine")) return "\0061332\0061333";
    if (!strcmp(id, "Caution")) return "\0061334\0061335";
    if (!strcmp(id, "Danger")) return "\0061336\0061337";
    if (!strcmp(id, "Weapon")) return "\0061338\0061179";
    if (!strcmp(id, "Healing")) return "\0061339\006133a";
    if (!strcmp(id, "Drink")) return "\006133b\006133c";
    if (!strcmp(id, "First Aid")) return "\006133d\006133e\006133f";
    if (!strcmp(id, "Ampoule")) return "\0061047\0061340";
    if (!strcmp(id, "None")) return "\0061111";
    if (!strcmp(id, "SetupCamera")) return "\00610a3\00610a4";
    if (!strcmp(id, "SetupMovement")) return "\00610b6\0061079\00610d1\00610bb";
    if (!strcmp(id, "SetupOriginal")) return "\00610a5\00610a6";
    if (!strcmp(id, "SetupBehind")) return "\00610a7\00610a8";
    if (!strcmp(id, "SetupTank")) return "\00610b9\00610ba\00610bb";
    if (!strcmp(id, "SetupDirectional")) return "\00610bc\00610bd\00610bb";
    if (!strcmp(id, "SetupOriginalHelp")) return "\0061341\0061342 PC \006103a\0061343\0061344\006109d\0061345\0061042\0061346\0061347\006104e\00610a3\00610a4\0061348";
    if (!strcmp(id, "SetupBehindNew")) return "\00610a3\00610a4\0061349\00610a8\006103c\006103d\006103e\006134a\0061342 C \006134b\006134c\006134d\0061199\0061348";
    if (!strcmp(id, "SetupBehindOld")) return "\00610a3\00610a4\0061349\00610a8\006103c\006103d\006103e\006134a\006134e\0061199\006134f\0061350\0061140\0061351\006134d\0061199\00610a3\00610a4\0061348";
    if (!strcmp(id, "SetupTankHelp")) return "\0061154\0061155\006134d\0061352\006134a\00610bd\0061052\006132d\0061353\006134a\00610bd\006113f\0061063\0061089\0061348";
    if (!strcmp(id, "SetupDirectionalHelp")) return "\0061354\0061355\0061356\006104e\00610d1\00610bd\0061357\006134b\006134c\0061348";
    if (!strcmp(id, "Choose")) return "\0061087\0061358";
    if (!strcmp(id, "Start")) return "\0061033\00610a6";
    if (!strcmp(id, "Move")) return "\0061359\0061199";
    if (!strcmp(id, "Check, pick up")) return "\0061327\0061328\006135a\006135b\0061085";
    if (!strcmp(id, "SetupButtonsHelp")) return "\0061351\006103f\006135c\0061087\0061088\006135d\006104e\006135c\00610b6\0061079\006135d\006135e\006135f\0061360\00610e7\00610ec\0061348";
    if (!strcmp(id, "AimBefore")) return "\0061361\00610d3\0061081\00610e7 ";
    if (!strcmp(id, "AimAfter")) return " \00610cf\00610d0";
    if (!strcmp(id, "ResetCamera")) return " \0061351\0061362\00610a3\00610a4\0061164\006113d\0061348";
    if (!strcmp(id, "Silent Hill")) return "\0061072\0061073\0061074";
    if (!strcmp(id, "South Vale (east)")) return "\0061363\0061364\0061365\006132e";
    if (!strcmp(id, "South Vale (west)")) return "\0061363\0061364\0061366\006132e";
    if (!strcmp(id, "Blue Creek Apartments")) return "\0061367\0061368\006104a\006104b";
    if (!strcmp(id, "Brookhaven Hospital")) return "\0061369\006136a\00610ba\0061104\0061191\006105d\006105e";
    if (!strcmp(id, "Toluca Prison")) return "\006136b\006136c\006136d\006136e\006136f";
    if (!strcmp(id, "Labyrinth")) return "\0061160\0061370";
    if (!strcmp(id, "Baldwin Mansion")) return "\0061371\0061372\0061373\006104a\006105a";
    if (!strcmp(id, "Wood Side Apartments 1F")) return "\0061374\0061156\006104a\006104b1\0061375";
    if (!strcmp(id, "Apartments 1F")) return "\006104a\006104b1\0061375";
    if (!strcmp(id, "Wood Side Apartments 2F")) return "\0061374\0061156\006104a\006104b2\0061375";
    if (!strcmp(id, "Apartments 2F")) return "\006104a\006104b2\0061375";
    if (!strcmp(id, "Wood Side Apartments 3F")) return "\0061374\0061156\006104a\006104b3\0061375";
    if (!strcmp(id, "Apartments 3F")) return "\006104a\006104b3\0061375";
    if (!strcmp(id, "Lakeview Hotel BF")) return "\0061054\00610f9\0061059\006105a\0061044\006113f\0061376";
    if (!strcmp(id, "Lakeview Hotel 1F")) return "\0061054\00610f9\0061059\006105a1\0061375";
    if (!strcmp(id, "Lakeview Hotel 2F")) return "\0061054\00610f9\0061059\006105a2\0061375";
    if (!strcmp(id, "Lakeview Hotel 3F")) return "\0061054\00610f9\0061059\006105a3\0061375";
    if (!strcmp(id, "I07")) return "\0061095\0061096\006117a\0061329";
    if (!strcmp(id, "M02")) return "\006134e\0061199\0061377\0061359\0061199\0061044\00610f5";
    if (!strcmp(id, "M03")) return "\0061052\0061378\0061379\0061375";
    if (!strcmp(id, "M04")) return "\006113f\0061378\0061379\0061375";
    if (!strcmp(id, "M05")) return "\006137a\006137b\0061044\00610f5";
    if (!strcmp(id, "M06")) return "\006137c\006137d";
    if (!strcmp(id, "M07")) return "\006137e\006137f";
    if (!strcmp(id, "M08")) return "\0061380\006105b";
    if (!strcmp(id, "N05")) return "\0061095\0061096\00612f5\00612f6\0061067";
    if (!strcmp(id, "PauseObservationRestroom")) return "\0061388\00610f9\0061389\0061040\0061041\0061042";
    if (!strcmp(id, "PauseTrailer")) return "\0061345\006138a";
    if (!strcmp(id, "PauseNeelysBar")) return "\006138b\0061133\006138c\006138d";
    if (!strcmp(id, "PauseTopTitle")) return "\006132a\006132b";
    if (!strcmp(id, "SaveTimeAndCount")) return "\0061093\0061094\0061081\0061042 %s     \0061082\0061083\0061390\0061391 %d";
    if (!strcmp(id, "SaveDifficulty")) return "\0061392\0061393\0061394\00610c8 %s     \0061395\0061396\0061394\00610c8 %s";
    if (!strcmp(id, "SaveWishDifficulty")) return "\006106c\0061397\0061398\0061399     \0061392\0061393\0061394\00610c8 %s";
    return english;
}
#ifdef ZH_OPTIONS
static const struct { const char* name; const char* values[4]; const char* help; } zh_settings[] = {
    {"\00610a3\00610a4", {"\00610a5\00610a6", "\00610a7\00610a8"}, "\00610a9\00610aa\00610ab\00610ac\00610ad\00610ae\00610af\00610b0\00610b1\00610b2\00610b3\00610b4\00610b5"},
    {"\00610b6\0061079\00610b7\00610b8", {"\00610b9\00610ba\00610bb", "\00610bc\00610bd\00610bb"}, "\00610be\00610bf\00610c0\00610c1\00610c2\00610c3\00610c4\00610c5\00610b4\00610c6"},
    {"\00610a3\00610a4\00610c7\00610c8", {"PC", "PS2"}, "\00610a9\00610aa\00610b0\00610b1\00610c9\00610c6\00610ca\00610cb\00610cc\00610cd\00610ce"},
    {"\00610cf\00610d0\00610d1\00610bb", {"\00610d2\00610d3", "\00610d4\00610d5"}, "{AIM} \00610d6\00610d7\00610d8\00610d9\00610da\00610db\00610dc"},
    {"\00610dd\00610de\00610d4\00610d5", {"\00610dd", "\00610d4\00610d5", "\00610df\00610e0", "\00610de"}, "\00610e1\00610e2\00610db\00610dc\00610d7\00610d8"},
    {"\00610e3\00610e4\00610e5\0061078", {"\00610d2\00610d3", "\00610d4\00610d5"}, "{LOOK} \00610d6\00610c2\00610c3\00610e6\00610c6"},
    {"\006105f\00610d0", {"PC", "\00610e7\00610e8 {ACT}"}, "{ACT} \00610d6\00610e9\00610da\00610ea\00610eb\00610b4\00610b5"},
    {"\00610e7\00610ec", {NULL}, "\00610ed\00610ee\00610ef\00610c5\00610f0\00610f1\00610f2\00610f3\00610ef\00610f4\00610d6"},
    {"\0061044\00610f5", {"\00610f6\00610f7", "\00610f8\00610f9"}, "\00610fa\00610fb\00610fc\00610fd\00610b4\00610b5"},
    {"\00610fe\00610ff\0061100\0061101", {"\00610d2\00610d3", "\0061102", "\0061103", "\0061104"}, "\0061105\0061106\0061107\0061108"},
    {"\0061109\006110a\006110b\006110c", {"x1", "x2", "x3"}, "\006110d\00610f2\006110e\00610b2\006110f\0061110"},
    {"\0061111\0061112\0061113\0061114", {"\0061115", "\0061033"}, "\0061116\0061117\0061118\00610e2\0061119\006111a\00610ad\006111b"},
    {"\0061111\0061112\0061109\006110a", {"\0061115", "\0061033"}, "\006111c\006111d\006111e\006111f\0061120\0061121\0061122"},
    {"\0061123\0061124\0061125\00610c8", {NULL}, "\0061126\0061127\00610ab\00610ac\0061128\0061129\006112a\006112b\006112c\006112d\006112e\006112f"},
    {"\0061123\0061124", {"\0061130\0061131", "\0061132\0061133"}, "\006110d\00610f2\0061128\0061129\006112a\0061134\00610cb"},
    {"3D", {"\0061115", "\0061033"}, "\0061135\0061136\0061137\0061138\0061139\006113a"},
    {"\006113b\006113c\006113d\006113e", {"\006113f\0061140", "\0061052\0061140"}, "\0061141\0061142\0061143\0061144\0061145\006112a\0061146\00610f2"},
    {"\0061147\0061148", {"\0061115", "PC", "PS2"}, "\0061128\0061129\00610af\006112a\0061149\006114a\006114b\006114c"},
    {"\0061041\006114d\00610df\00610bb", {"PC", "PS2"}, "\0061121\006114e\006114f\0061150\0061151\0061152\00610b5"},
    {"\0061123\0061124\0061153\00610d4", {"\0061154\0061155\0061104\0061156", "\0061052\006113f\0061153\00610d4"}, "\00610c0\00610c1\0061157\0061158\0061128\0061129"},
    {"\0061159\006115a", {"\0061115", "\0061033"}, "\006115b\0061108\006115c\006115d\006115e\006115f"},
    {"\0061160\0061161", {"\0061162\0061163", "\0061164\0061165"}, "\006110d\0061166\0061167\0061168\0061169\006116a"},
    {"\00610a3\00610a4\006116b\006116c", {"\0061115", "\0061033"}, "\0061151\006116d\006116e\006116f\00610b0\00610b1\0061170\0061171\0061172\006112a\0061151\0061173\006115e\006115f"},
    {"\0061174\0061175", {"\0061115", "\0061033"}, "\006116f\0061176\0061144\0061145\0061139\006113a"},
    {"\0061177\0061178\0061179", {"\0061163\0061178\006117a", "\006117b\006117c\0061178", "\006117d\006117e"}, "\006117f\006116d\0061180\0061181\0061182\0061183"},
    {"\0061184\0061185\0061184\0061186", {NULL}, "\0061187\00610b3\006117f\0061188\0061143\0061189\006118a\006117f\006118b"},
    {"\0061184\006118c\0061184\0061186", {NULL}, "\006117f\006115e\0061143\006116f\006118d\006117f\006118b"},
    {"\006118e\006118f", {"\0061190\0061191", "\0061192\0061191"}, "\00610ab\00610ac\0061193\0061194\0061195\0061196"},
    {"\0061123\0061124\0061197\0061186", {"\0061198\0061199", "\006119a", "\006119b"}, "\00610ab\00610ac\0061128\0061129\006119c\006119d\006119e\006118b"},
    {"\006119f\00611a0", {"\0061198\0061199", "30", "60"}, "\0061128\0061129\006112a\00611a1\0061110"},
    {"\00611a2\00611a3\00611a4\00611a5", {"\0061198\0061199", "\00611a6\00611a7", "\0061097\00611a7"}, "\00611a8\00611a9\00611aa\0061121\0061135\006112a\00610ab\00610ac\00611ab"},
    {"\00610e7\00610ec\00611ac\00611a5", {"\0061198\0061199", "\00611a6\00611a7", "\0061097\00611a7"}, "\00611ad\00610f1\00611aa\0061121\0061135\006112a\00610ab\00610ac\00611ab\00610f4\00610d6"},
};
static inline const char* zh_help(const char* english) {
    if (ev_language() != 2 || !english) return english;
    if (!strcmp(english, "The PC's own shots, framed for each room. They cut as James moves.")) return "\00611ae\00611af\00611b0\00611b1\00611b2\00611b3\00611b4\00611b5\00611b6\00611b7\00611b8\00611b9\0061009\00611ba\00611bb\00611bc\00611bd\00611be\00611bf\00611c0\0061010\00611c1\00611c2\00611c3\00611c4\00611c5\00611c6\00611c7";
    if (!strcmp(english, "Follows James. {CAMTURN}")) return "\00611ba\00611bb\00611c8\00611c9\00611bd\00611be\00611bf\00611c7{CAMTURN}";
    if (!strcmp(english, "Left and right turn James. Up walks ahead, down backs away.")) return "\00611ca\00611cb\00611cc\00611bd\00611be\00611bf\00611cd\00611ce\00611bc\00611cf\00611d0\00611d1\00611d2\00611bc\00611cf\00611d3\00611d4\0061012\00611c7";
    if (!strcmp(english, "Push the way you want James to go. It holds through camera cuts.")) return "\00611d5\00611d6\00611d7\0061009\00611d8\00611cf\00611d9\00611da\00611db\00611c7\00611c3\00611c4\00611ba\00611bb\00611c1\00611bc\00611c0\0061010\00611d8\00611cf\00611c2\00611dc\00611dd\00611de\00611df\00611c7";
    if (!strcmp(english, "The PC's slower turns, which float and bounce.")) return "\00611ae\00611af\00611b0\00611b1\00611b2\00611e0\00611e1\0061009\00611cd\00611cf\00611bc\00611ba\00611bb\00611cd\0061010\00611c1\00611c2\00611e2\00611e3\00611e4\0061009\00611e5\00611c0\00611e6\00611e7\0061010\00611c7";
    if (!strcmp(english, "Quicker, steadier turns, as on the PS2.")) return "\00611e8\00611af\00611b0\00611e9\00611ea\00611b2\0061009\00611ba\00611bb\00611eb\00611ec\00611bc\00611cd\00611cf\00611ed\00611ee\00611ef\00611ed\00611f0\00611c7";
    if (!strcmp(english, "Hold {AIM} to keep the weapon up. Let go to lower it.")) return "\00611f1\00611f2 {AIM} \00611f3\00611f4\00611f5\00611f6\00611bc\00611f7\006100a\00611d4\00611f8\00611d3\00611c7";
    if (!strcmp(english, "Press {AIM} to raise the weapon, and again to lower it.")) return "\00611f1\00611f9\00611d3 {AIM} \00611f3\00611f4\00611f5\00611f6\00611bc\00611fa\00611f1\00611f9\00611d3\00611f8\00611d3\00611c7";
    if (!strcmp(english, "James walks. Hold {RUN} to run.")) return "\00611fb\00611fc\00611fd\00611fe\00611bc\00611f1\00611f2 {RUN} \00611ff\0061200\00611c7";
    if (!strcmp(english, "Press {RUN} to run, until James stops.")) return "\00611f1\00611f9\00611d3 {RUN} \006100a\006100b\00611ff\0061200\00611bc\0061201\006108d\006107d\00611d3\00611c7";
    if (!strcmp(english, "Push the Circle Pad all the way to run.")) return "\0061202\00611da\00611db\00611d9\006108d\0061203\0061204\0061205\00611ff\0061200\00611c7";
    if (!strcmp(english, "James runs. Hold {RUN} to walk.")) return "\00611fb\00611fc\00611ff\0061200\00611bc\00611f1\00611f2 {RUN} \00611fd\00611fe\00611c7";
    if (!strcmp(english, "Hold {LOOK} to look ahead of James.")) return "\00611f1\00611f2 {LOOK} \0061206\0061207\00611bd\00611be\00611bf\00611d5\00611cf\00611c7";
    if (!strcmp(english, "Press {LOOK} to look ahead of James, and again to stop.")) return "\00611f1\00611f9\00611d3 {LOOK} \0061206\0061207\00611bd\00611be\00611bf\00611d5\00611cf\00611bc\00611fa\00611f1\00611f9\00611d3\0061208\0061209\00611c7";
    if (!strcmp(english, "Every press is heavy, as with a PC key: a downswing or a stomp.")) return "\00611e6\00611b0\00611b1\00611b2\006120a\006120b\006120c\006120d\00611f9\006120e\00611bc\00611b4\006120f\00611f1\00611d3\0061210\0061211\0061013\0061212\0061213\00611bc\0061214\0061215\0061216\00611cf\00611d3\0061217\0061218\0061219\006121a\006121b\00611c7";
    if (!strcmp(english, "Tap {ACT} to swing light or kick. Hold it to swing heavy or stomp.")) return "\00611e3\00611f1 {ACT} \00611e3\0061213\0061219\006121c\0061213\00611bc\006121d\00611f1\006121e\0061212\0061213\0061219\006121a\006121b\00611c7";
    if (!strcmp(english, "Close up on where James is.")) return "\006121f\006100a\0061220\0061221\00611c1\00611f8\0061222\00611bd\00611be\00611bf\0061223\0061224\0061009\00611c6\0061225\00611c7";
    if (!strcmp(english, "The whole floor at once.")) return "\006121f\006100a\0061220\0061221\00611c1\0061226\0061227\0061228\0061229\00611c7";
    if (!strcmp(english, "As on the PC.")) return "\006122a\006122b\006122c\0061001\006122d\006122e\00611b0\00611b1\00611b2\006122f\0061230\00611c7";
    if (!strcmp(english, "Twice the rounds.")) return "\006122c\0061001\0061009\006122a\006122b\006122d\00611b3\0061231\0061017\0061009\0061232\0061233\00611c7";
    if (!strcmp(english, "Three times the rounds.")) return "\006122c\0061001\0061009\006122a\006122b\006122d\00611b3\0061231\0061017\0061009\0061234\0061233\00611c7";
    if (!strcmp(english, "As on the PC: a long run tires James, sooner when he is hurt.")) return "\00611e6\00611b0\00611b1\00611b2\00611f9\006120e\00611bc\00611bd\00611be\00611bf\0061200\0061235\0061236\00611c2\0061237\00611bc\0061238\0061239\00611c1\00611ed\006123a\006123b\006123c\006123d\00611c7";
    if (!strcmp(english, "James runs for as long as you like.")) return "\00611bd\00611be\00611bf\0061205\006123e\00611f9\0061201\0061200\00611bc\00611de\00611c2\006123c\006123d\00611c7";
    if (!strcmp(english, "Every shot uses a round.")) return "\00611b4\006100a\00611f9\006123f\0061240\0061241\00611f9\0061242\006122a\006122b\00611c7";
    if (!strcmp(english, "Guns never run out.")) return "\006100a\006123f\00611de\0061240\0061241\0061243\0061244\0061245\0061009\006122a\006122b\00611c7";
    if (!strcmp(english, "Edges and texture grain smoothed, as the PC looks at this size.")) return "\0061246\0061247\0061248\0061249\00611e6\006124a\006124b\006124c\006124d\00611bc\006124e\006124f\00611b0\00611b1\00611b2\0061250\0061251\006108d\0061252\00611b5\0061253\0061254\00611c1\0061009\0061255\0061256\00611c7";
    if (!strcmp(english, "Every pixel as the console draws it, crisper and grainier.")) return "\00611f1\0061014\00611c5\0061257\0061258\0061009\0061259\006125a\0061201\006124e\0061226\0061227\00611bc\0061011\006108f\00611ed\006125b\006125c\00611bc\006124c\006124d\0061214\00611ed\006125d\0061226\00611c7";
    if (!strcmp(english, "The top screen stays flat whatever the slider says.")) return "\006125e\006125f \0061260\0061261 \0061262\00611db\0061263\006108d\0061264\0061265\00611bc\00611d0\0061266\0061210\006123e\0061267\006108f\0061226\0061227\00611c7";
    if (!strcmp(english, "The world gains depth. Text and menus stay on the screen.")) return "\006100f\0061268\0061269\00611e2\006126a\006126b\006126c\006126d\00611bc\006126e\006126f\00611e6\0061270\006102d\0061271\0061272\0061273\0061266\0061274\0061226\0061227\00611c7";
    if (!strcmp(english, "On the touch screen, which keeps the picture clear.")) return "\0061275\0061227\00611e6\006126f\0061274\0061226\0061227\0061224\0061276\0061277\0061266\00611d0\00611bc\00611d0\0061266\0061011\006108f\00611ed\0061278\0061279\00611c7";
    if (!strcmp(english, "In the PC's message window over the game.")) return "\00611ae\00611af\00611b0\00611b1\00611b2\0061009\0061226\0061227\00611d8\006127a\00611bc\006127b\0061275\0061227\00611e6\006126f\0061274\006127c\0061224\0061006\0061007\0061011\006108f\00611d0\00611c7";
    if (!strcmp(english, "A clean picture, as the PC starts.")) return "\0061011\006108f\006127d\006127e\00611bc\006125e\006124c\006124d\0061255\0061256\00611bc\006122e\00611b0\00611b1\00611b2\00611fb\00611fc\00611b8\0061225\00611f9\006127f\00611c7";
    if (!strcmp(english, "The PC's light grain.")) return "\00611e8\00611af\00611b0\00611b1\00611b2\00611e0\0061280\0061009\0061281\0061030\006124c\006124d\00611c7";
    if (!strcmp(english, "The PS2's darker grain, which the Enhanced Edition restores.")) return "\00611e8\00611af\0061282\0061283\0061284\0061285\0061283\0061286\0061287\0061288 \0061282\0061288\0061289\006128a\0061289\006128b\0061283\0061208\0061209\0061009\00611b0\00611e9\00611ea\00611b2\006124c\006124d\0061255\0061256\00611bc\006128c\0061263\00611ed\006126d\00611c7";
    if (!strcmp(english, "A strong, short beam that washes walls out.")) return "\006128d\006128e\006128f\0061290\0061291\0061292\006124f\00611bc\0061293\006108f\006123a\006123b\0061294\0061291\0061292\0061242\0061295\00611c7";
    if (!strcmp(english, "A softer beam that reaches further. Dark rooms stay dark.")) return "\006128d\006128e\00611ed\0061246\00611e6\00611bc\0061291\0061292\00611ed\0061296\00611bc\0061297\0061298\0061009\00611b6\00611b7\0061299\006129a\0061297\0061298\00611c7";
    if (!strcmp(english, "Scenes widen to the screen and show more at the sides.")) return "\006100e\006100f\0061011\006108f\006129b\006129c\00611d0\0061266\006129d\0061026\00611bc\0061232\006129e\006129f\0061207\006108d\00611ed\00612a0\00612a1\006123a\00611c7";
    if (!strcmp(english, "Scenes keep the width they were framed with, a little closer.")) return "\00611dc\00612a2\006100e\006100f\0061231\0061017\0061009\00612a3\0061221\006129d\0061026\00611bc\0061011\006108f\00612a4\00612a5\006124f\00611c7";
    if (!strcmp(english, "No character shadows. Lighter for the console.")) return "\00612a6\00612a7\00612a8\006128c\00612a9\006102f\00611bc\00612aa\00611e3\0061014\00611c5\00612ab\00612ac\00611c7";
    if (!strcmp(english, "Characters cast shadows, softened as in the Enhanced Edition.")) return "\00612a8\006128c\00611c2\00612ad\00611d3\00612a9\006102f\00611bc\0061248\0061249\00611e6\0061282\0061283\0061284\0061285\0061283\0061286\0061287\0061288 \0061282\0061288\0061289\006128a\0061289\006128b\0061283\00611f9\006120e\0061246\00611e6\00611c7";
    if (!strcmp(english, "Fog without drifting particles. Lighter for the console.")) return "\00612ae\00612af\00612b0\00611e2\00612b1\0061010\0061009\006124d\00612b2\00611bc\0061014\00611c5\00612ab\00612ac\00611ed\00611e3\00611c7";
    if (!strcmp(english, "Drifting fog particles, as on the PC.")) return "\00611e6\00611b0\00611b1\00611b2\00611f9\006120e\00611bc\00612ae\00612af\00611e2\00612b1\0061010\0061009\006124d\00612b2\00611c7";
    if (!strcmp(english, "Lamps show no glow.")) return "\00612b3\0061269\00612b4\00612b5\00611de\0061226\0061227\006128d\00612b6\00611c7";
    if (!strcmp(english, "A lamp facing the camera glows and throws streaks, as on the PC.")) return "\00611e6\00611b0\00611b1\00611b2\00611f9\006120e\00611bc\00612b3\006128d\006102a\00612b7\00611ba\00611bb\00611c1\00611c2\00612b8\006101f\006128d\00612b6\00611e6\006128d\00612b9\00611c7";
    if (!strcmp(english, "Voices only.")) return "\00612ba\00612bb\00611f8\00612bc\00612bd\00611c7";
    if (!strcmp(english, "Spoken lines are written out as they play.")) return "\00612bb\00611f8\00612bc\00612bd\00611c1\0061230\00611fd\0061226\0061227\00612be\00612bf\00611c7";
    if (!strcmp(english, "One channel from both speakers.")) return "\0061232\00611b5\00612c0\00612c1\00611f6\00612bb\00611f8\0061230\00611f9\00611b5\006102d\00612c1\00612c2\00611c7";
    if (!strcmp(english, "Left and right kept apart.")) return "\00611ca\00611cb\00612c1\00612c2\00612c3\006100a\00612bb\00611f8\00611c7";
    if (!strcmp(english, "The 3DS's virtual surround.")) return "\0061211\00611af\0061260\0061261\00611e9\0061009\00612c4\00612c5\00612c6\00612c7\00612c1\00611c7";
    if (!strcmp(english, "This console picks {AUTOQ}.")) return "\00612c8\00611c5\0061018\0061010\006100c\00612c9 {AUTOQ}\00611c7";
    if (!strcmp(english, "Fewer fog particles and lights, no shadows, no supersampling.")) return "\00612aa\00612ca\00612ae\006124d\00612b2\00611e6\006128d\00612cb\00612cc\006122d\00611bc\00612a6\00612a7\00612a9\006102f\00611e6\00612cd\00611e8\006120e\00611c7";
    if (!strcmp(english, "Everything the port draws, supersampled while the frame rate holds.")) return "\00612ce\00611af\00611c0\00612cf\00611b2\006101e\00611dd\0061009\00612d0\00612d1\0061011\006108f\0061255\0061256\00611bc\00612d2\00612d3\00612d4\00612d5\00611c1\0061211\00611af\00612cd\00611e8\006120e\00611c7";
    if (!strcmp(english, "Follows Quality: {AUTOFPS} fps on this console.")) return "\00611c8\00611c9\0061011\00612d6\00611b8\0061225\00611bc\00612c8\00611c5\00611b3 {AUTOFPS} \00612d2\00612d7\00612d8\00611c7";
    if (!strcmp(english, "The steadiest motion, and the most room for supersampling.")) return "\00612d2\00612d3\00612d9\00611f0\00611bc\0061214\00611b3\00612cd\00611e8\006120e\00612a2\0061013\00612d9\00612a0\00612da\006129f\00612db\006122d\00611c7";
    if (!strcmp(english, "Smoother, when the console keeps up.")) return "\0061014\00611c5\00612da\006129f\00611c8\0061292\00611d0\00611c1\00611bc\0061010\006120d\00611ed\00612dc\00612dd\00611c7";
    if (!strcmp(english, "This console, a {CONSOLE} 3DS.")) return "\00611f1\00612c8\00611c5\00612de\00612df\00611b8\0061225\00611bc\00612c8\00611c5\00611b3 {CONSOLE} \0061260\0061261\00611e9\00611c7";
    if (!strcmp(english, "Lighter defaults for quality, frame rate and textures.")) return "\0061011\00612d6\00611ef\00612d2\00612d3\00611e6\0061272\0061221\00611e8\00611af\00612ab\00612ac\00611e0\00611e3\0061009\00611fb\00611fc\00611b8\0061225\00611c7";
    if (!strcmp(english, "Full defaults for quality, frame rate and textures.")) return "\0061011\00612d6\00611ef\00612d2\00612d3\00611e6\0061272\0061221\00611e8\00611af\00612e0\0061228\0061009\00611fb\00611fc\00611b8\0061225\00611c7";
    if (!strcmp(english, "This console's buttons.")) return "\0061211\00611af\00612c8\00611c5\0061009\00611f1\006120a\00612e1\00612e2\00611c7";
    if (!strcmp(english, "No ZL, ZR or C-Stick.")) return "\00612e3\00612e1\00612e2\00611de\0061211\00611af\00612e4\00612e5\00611ef\00612e4\00612e6\0061219\00611b1\00611da\00611db\00611c7";
    if (!strcmp(english, "Adds ZL, ZR and the C-Stick, or a Circle Pad Pro.")) return "\00612ce\00611af\00612e4\00612e5\00611ef\00612e4\00612e6\00611e6\00611b1\00611da\00611db\00611bc\0061214\006101e\00611dd\00612e7\00612e8\00611da\00611db\00611c7";
    if (!strcmp(english, "Scenes and scripted shots always use the PC's camera.")) return "\00612e9\00612ea\0061016 \006100e\006100f\00611e6\00612eb\00612c8\00612ec\00612ed\0061009\00611ba\00611bb\006100b\00612ee\00611ae\00611af\00611b0\00611b1\00611b2\00611c5\00611c6\00611c7";
    if (!strcmp(english, "With the Behind camera, this only applies in scripted shots.")) return "\0061211\00611af\00611c8\00611c9\00611ba\00611bb\00611c1\00611bc\00612e3\00611b8\0061225\00612ba\0061224\00612eb\00612c8\00612ec\00612ed\0061009\00611ba\00611bb\00612af\006101f\0061255\00611c7";
    if (!strcmp(english, "With the Behind camera, {LOOK} swings the camera behind James.")) return "\0061211\00611af\00611c8\00611c9\00611ba\00611bb\00611c1\00611bc{LOOK} \00611c2\0061202\00611ba\00611bb\00611cd\006108d\00611bd\00611be\00611bf\00611ce\00611d4\00611c7";
    if (!strcmp(english, "Brightness Level changes how strong the grain is.")) return "\00612ef\0061026\00611b8\0061225\00611c2\006102f\00612f0\0061281\0061030\006124c\006124d\0061009\006128f\0061026\00611c7";
    if (!strcmp(english, "Low quality turns shadows off.")) return "\00612f1\0061011\00612d6\00611c2\00612a6\00612a7\00612a9\006102f\00611c7";
    if (!strcmp(english, "Low quality draws half as many particles.")) return "\00612f1\0061011\00612d6\00612f2\00612f3\00612ed\00611f9\00612f4\0061009\00612ae\006124d\00612b2\00611c7";
    return english;
}
#endif
