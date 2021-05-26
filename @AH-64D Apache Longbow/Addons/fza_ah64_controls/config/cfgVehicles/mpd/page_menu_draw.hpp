///////////////// L ///////////////
MPD_ARROW_R(ADF, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y, 3)
MPD_TEXT_R(ADF, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y, MPD_TEXT_STATIC("ADF"))

MPD_ARROW_R(ASE, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y, 3)
MPD_TEXT_R(ASE, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y, MPD_TEXT_STATIC("ASE"))

MPD_ARROW_R(TSD, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_4_Y, 3)
MPD_TEXT_R(TSD, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_4_Y, MPD_TEXT_STATIC("TSD"))

MPD_ARROW_R(WPN, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, 3)
MPD_TEXT_R(WPN, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("WPN"))

MPD_ARROW_R(FCR, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, 3)
MPD_TEXT_R(FCR, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC("FCR"))

class Mission_Lines {
type = line;
width = 3;
points[] = {
    {{0.02, 0.38}, 1},
    {{0.11, 0.38}, 1},
    {{0.11, 0.62 - 3.5 * MPD_TEXT_HEIGHT}, 1},
    {},
    {{0.11, 0.62 + 3.5 * MPD_TEXT_HEIGHT}, 1},
    {{0.11, 0.86}, 1},
    {{0.02, 0.86}, 1}};
};
MPD_TEXT_C(MissionChar1, 0.11, 0.62 - 3.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("M"))
MPD_TEXT_C(MissionChar2, 0.11, 0.62 - 2.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
MPD_TEXT_C(MissionChar3, 0.11, 0.62 - 1.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("S"))
MPD_TEXT_C(MissionChar4, 0.11, 0.62 - 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("S"))
MPD_TEXT_C(MissionChar5, 0.11, 0.62 + 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
MPD_TEXT_C(MissionChar6, 0.11, 0.62 + 1.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("O"))
MPD_TEXT_C(MissionChar7, 0.11, 0.62 + 2.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("N"))

///////////////// R ///////////////
MPD_ARROW_L(SOI, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y, 3)
MPD_TEXT_L(SOI, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y, MPD_TEXT_STATIC("SOI"))

MPD_ARROW_L(SINC, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y, 4)
MPD_TEXT_L(SINC, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y, MPD_TEXT_STATIC("SINC"))

MPD_ARROW_L(HQ2, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_3_Y, 3)
MPD_TEXT_L(HQ2, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_3_Y, MPD_TEXT_STATIC("HQ2"))

MPD_ARROW_L(XPNDR, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_4_Y, 5)
MPD_TEXT_L(XPNDR, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_4_Y, MPD_TEXT_STATIC("XPNDR"))

MPD_ARROW_L(COM_UTIL, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_5_Y, 4)
MPD_TEXT_L(COM_UTIL, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("UTIL"))

MPD_ARROW_L(COM, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_6_Y, 3)
MPD_TEXT_L(COM, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC("COM"))

class Comunication_Lines {
type = line;
width = 3;
points[] = {
    {{0.98, 0.15}, 1},
    {{0.85, 0.15}, 1},
    {{0.85, 0.50 - 6.5 * MPD_TEXT_HEIGHT}, 1},
    {},
    {{0.85, 0.50 + 6.5 * MPD_TEXT_HEIGHT}, 1},
    {{0.85, 0.85}, 1},
    {{0.98, 0.85}, 1}};
};
MPD_TEXT_C(ComunicationChar1 , 0.85, 0.50 - 6.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("C"))
MPD_TEXT_C(ComunicationChar2 , 0.85, 0.50 - 5.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("O"))
MPD_TEXT_C(ComunicationChar3 , 0.85, 0.50 - 4.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("M"))
MPD_TEXT_C(ComunicationChar4 , 0.85, 0.50 - 3.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("U"))
MPD_TEXT_C(ComunicationChar5 , 0.85, 0.50 - 2.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("N"))
MPD_TEXT_C(ComunicationChar6 , 0.85, 0.50 - 1.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
MPD_TEXT_C(ComunicationChar7 , 0.85, 0.50 - 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("C"))
MPD_TEXT_C(ComunicationChar8 , 0.85, 0.50 + 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("A"))
MPD_TEXT_C(ComunicationChar9 , 0.85, 0.50 + 1.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("T"))
MPD_TEXT_C(ComunicationChar10, 0.85, 0.50 + 2.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
MPD_TEXT_C(ComunicationChar11, 0.85, 0.50 + 3.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("O"))
MPD_TEXT_C(ComunicationChar12, 0.85, 0.50 + 4.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("N"))
MPD_TEXT_C(ComunicationChar13, 0.85, 0.50 + 5.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("S"))

///////////////// T ///////////////
MPD_ARROW_C(VIDEO, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_T_Y, 5)
MPD_TEXT_C(VIDEO, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("VIDEO"))

MPD_ARROW_C(VCR, MPD_POS_BUTTON_TB_2_X, MPD_POS_BUTTON_T_Y, 3)
MPD_TEXT_C(VCR, MPD_POS_BUTTON_TB_2_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("VCR"))

MPD_ARROW_C(MSG, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y, 4)
MPD_TEXT_C(MSG, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("MSG"))
MPD_TEXT_C(SEND, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("SEND"))

///////////////// B ///////////////
MPD_ARROW_C(DMS, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_B_Y, 3)
MPD_TEXT_C(DMS, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("DMS"))

MPD_ARROW_C(ENG, MPD_POS_BUTTON_TB_2_X, MPD_POS_BUTTON_B_Y, 3)
MPD_TEXT_C(ENG, MPD_POS_BUTTON_TB_2_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("ENG"))

MPD_ARROW_C(FLT, MPD_POS_BUTTON_TB_3_X, MPD_POS_BUTTON_B_Y, 3)
MPD_TEXT_C(FLT, MPD_POS_BUTTON_TB_3_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("FLT"))

MPD_ARROW_C(FUEL, MPD_POS_BUTTON_TB_4_X, MPD_POS_BUTTON_B_Y, 4)
MPD_TEXT_C(FUEL, MPD_POS_BUTTON_TB_4_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("FUEL"))

MPD_ARROW_C(PERF, MPD_POS_BUTTON_TB_5_X, MPD_POS_BUTTON_B_Y, 4)
MPD_TEXT_C(PERF, MPD_POS_BUTTON_TB_5_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("PERF"))

MPD_ARROW_C(AIR_UTIL, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_B_Y, 4)
MPD_TEXT_C(AIR_UTIL, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("UTIL"))

class Aircraft_Lines {
type = line;
width = 3;
points[] = {
    {{0.28, 0.98}, 1},
    {{0.28, 0.89}, 1},
    {{0.57 - 4 * MPD_TEXT_WIDTH - 0.01, 0.89}, 1},
    {},
    {{0.57 + 4 * MPD_TEXT_WIDTH + 0.01, 0.89}, 1},
    {{0.89, 0.89}, 1},
    {{0.89, 0.98}, 1}};
};
MPD_TEXT_C(Aircraft_Text, 0.57, 0.86, MPD_TEXT_STATIC("AIRCRAFT"))