class VABs_Core {
    MPD_ARROW_C(CHAN, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_T_Y, 4)
    MPD_TEXT_C(CHAN, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("CHAN"))

    MPD_ARROW_C(ASE, MPD_POS_BUTTON_TB_2_X, MPD_POS_BUTTON_T_Y,3)
    MPD_TEXT_C(ASE, MPD_POS_BUTTON_TB_2_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("ASE"))

    MPD_ARROW_C(CODE, MPD_POS_BUTTON_TB_4_X, MPD_POS_BUTTON_T_Y,4)
    MPD_TEXT_C(CODE, MPD_POS_BUTTON_TB_4_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("CODE"))

    MPD_ARROW_C(COORD, MPD_POS_BUTTON_TB_5_X, MPD_POS_BUTTON_T_Y,5)
    MPD_TEXT_C(COORD, MPD_POS_BUTTON_TB_5_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("COORD"))

    MPD_ARROW_C(UTIL, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y,4)
    MPD_TEXT_C(UTIL, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("UTIL"))
    
    MPD_TEXT_L(TRAIN, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_4_Y, MPD_TEXT_STATIC("TRAIN"))

    MPD_TEXT_L(LRFD, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_5_Y - 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("LRFD"))
    MPD_BOX_L(FIRST, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_5_Y + 0.5 * MPD_TEXT_HEIGHT, 5)
    MPD_TEXT_L(FIRST, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_5_Y + 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("FIRST"))

    MPD_TEXT_L(ACQ_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_6_Y - 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("ACQ"))

    MPD_BOX_L(ACQ, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_6_Y + 0.5 * MPD_TEXT_HEIGHT, 3)
    MPD_TEXT_L(ACQ, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_6_Y + 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_ACQ))

    MPD_TEXT_C(MANRNG_Label, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_B_Y - MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("MANRNG>"))
    MPD_TEXT_C(MANRNG, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("800"))

    #define WPN_WEAPON_OPTION(className, posX, weaponIndex, weaponName)\
        class className {\
            MPD_TEXT_C(Name, posX, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC(weaponName))\
            class Selected{\
                condition = __EVAL(format [STRINGIFY(EQ(user%1,weaponIndex)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);\
                MPD_BOX_C(Name, posX, MPD_POS_BUTTON_B_Y, 3)\
            }\
            class Actioned{\
                condition = __EVAL(format [STRINGIFY(EQ(user%1,weaponIndex)), MFD_OFFSET + MFD_IND_WPN_WAS]);\
                color[] = {0.05,0.25,0,0.5};\
                class Polygon {\
                type = polygon;\
                points[] = {\
                    {\
                        { {posX-1.5*MPD_TEXT_WIDTH - MPD_BOX_PAD_X, MPD_POS_BUTTON_B_Y + MPD_TEXT_HEIGHT}, 1 },\
                        { {posX+1.5*MPD_TEXT_WIDTH + MPD_BOX_PAD_X, MPD_POS_BUTTON_B_Y + MPD_TEXT_HEIGHT}, 1 },\
                        { {posX+1.5*MPD_TEXT_WIDTH + MPD_BOX_PAD_X, MPD_POS_BUTTON_B_Y + 1.2*MPD_TEXT_HEIGHT}, 1 },\
                        { {posX-1.5*MPD_TEXT_WIDTH - MPD_BOX_PAD_X, MPD_POS_BUTTON_B_Y + 1.2*MPD_TEXT_HEIGHT}, 1 },\
                    },\
                };\
            };\
        };\
    };

    WPN_WEAPON_OPTION(GUN, MPD_POS_BUTTON_TB_2_X, 1, "GUN")
    WPN_WEAPON_OPTION(RKT, MPD_POS_BUTTON_TB_5_X, 2, "RKT")
    WPN_WEAPON_OPTION(MSL, MPD_POS_BUTTON_TB_3_X, 3, "MSL")

    MPD_BOX_C(WPN, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_B_Y, 3)
    MPD_TEXT_C(WPN, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("WPN"))
}

class VABs_Mode_Unselected {
    condition =  __EVAL(format [STRINGIFY(EQ(user%1,0)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);
    MPD_ARROW_R(BORESIGHT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, 9)
    MPD_TEXT_R(BORESIGHT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("BORESIGHT"))
    MPD_TEXT_R(GRAYSCALE, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC("GRAYSCALE"))
};

class VABs_Mode_Gun {
    condition =  __EVAL(format [STRINGIFY(EQ(user%1,1)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);
    #define WPN_GUN_BURST_LIMIT(className, burstIndex, posY, numChars, burstName) \
    class className {\
        MPD_TEXT_R(Name, MPD_POS_BUTTON_L_X, posY, MPD_TEXT_STATIC(burstName)) \
        class Box {\
            condition =  __EVAL(format [STRINGIFY(EQ(user%1,burstIndex)), MFD_OFFSET + MFD_IND_WPN_SELECTED_BURST_LIMIT]);\
            MPD_BOX_R(Null, MPD_POS_BUTTON_L_X, posY, numChars)\
        };\
    };
   
    WPN_GUN_BURST_LIMIT(Burst_Limit_10, 0, MPD_POS_BUTTON_LR_1_Y, 2, "10")
    WPN_GUN_BURST_LIMIT(Burst_Limit_20, 1, MPD_POS_BUTTON_LR_2_Y, 2, "20")
    WPN_GUN_BURST_LIMIT(Burst_Limit_50, 2, MPD_POS_BUTTON_LR_3_Y, 2, "50")
    WPN_GUN_BURST_LIMIT(Burst_Limit_100, 3, MPD_POS_BUTTON_LR_4_Y, 3, "100")
    WPN_GUN_BURST_LIMIT(Burst_Limit_All, 4, MPD_POS_BUTTON_LR_5_Y, 3, "ALL")

    MPD_TEXT_R(Harmonize, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC("HARMONIZE"))

    MPD_TEXT_R(Burst_Limit_Label_1, 0.11, MPD_POS_BUTTON_LR_3_Y - 5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("B"))
    MPD_TEXT_R(Burst_Limit_Label_2, 0.11, MPD_POS_BUTTON_LR_3_Y - 4*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("U"))
    MPD_TEXT_R(Burst_Limit_Label_3, 0.11, MPD_POS_BUTTON_LR_3_Y - 3*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("R"))
    MPD_TEXT_R(Burst_Limit_Label_4, 0.11, MPD_POS_BUTTON_LR_3_Y - 2*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("S"))
    MPD_TEXT_R(Burst_Limit_Label_5, 0.11, MPD_POS_BUTTON_LR_3_Y - 1*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("T"))
    MPD_TEXT_R(Burst_Limit_Label_6, 0.11, MPD_POS_BUTTON_LR_3_Y + 1*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("L"))
    MPD_TEXT_R(Burst_Limit_Label_7, 0.11, MPD_POS_BUTTON_LR_3_Y + 2*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
    MPD_TEXT_R(Burst_Limit_Label_8, 0.11, MPD_POS_BUTTON_LR_3_Y + 3*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("M"))
    MPD_TEXT_R(Burst_Limit_Label_9, 0.11, MPD_POS_BUTTON_LR_3_Y + 4*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
    MPD_TEXT_R(Burst_Limit_Label_10, 0.11, MPD_POS_BUTTON_LR_3_Y + 5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("T"))

    class Static {
        type = line;
        width = 3;
        points[] = {
            // Burst limit box
            {{0.02,MPD_POS_BUTTON_LR_1_Y - MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_1_Y - MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_3_Y - 5*MPD_TEXT_HEIGHT}, 1}, {},
            {{0.11,MPD_POS_BUTTON_LR_3_Y + 6*MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_5_Y + 2*MPD_TEXT_HEIGHT}, 1},
            {{0.02,MPD_POS_BUTTON_LR_5_Y + 2*MPD_TEXT_HEIGHT}, 1}
        };
    };

    MPD_TEXT_L(Mode_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("MODE"))
    MPD_BOX_L(Mode, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y + 0.5*MPD_TEXT_HEIGHT, 4)
    MPD_TEXT_L(Mode, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("NORM"))
};

class VABs_Mode_Rkt {
    condition =  __EVAL(format [STRINGIFY(EQ(user%1,2)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);
    #define WPN_RKT_INVENTORY(className, invIndex, posY, nameSource, qtySource) \
    class className {\
        MPD_TEXT_R(Name, MPD_POS_BUTTON_L_X, posY - 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_USER(nameSource)) \
        MPD_TEXT_R(Qty, MPD_POS_BUTTON_L_X, posY + 0.5 * MPD_TEXT_HEIGHT, MPD_TEXT_USER(qtySource)) \
        class Box {\
            condition =  __EVAL(format [STRINGIFY(EQ(user%1,invIndex)), MFD_OFFSET + MFD_IND_WPN_SELECTED_RKT_INV]);\
            class Line { \
                type = line;\
                width = 3;\
                points[] = {\
                    {{MPD_POS_BUTTON_L_X - 0.01, posY - 0.5 * MPD_TEXT_HEIGHT}, 1},\
                    {{MPD_POS_BUTTON_L_X + 0.01 + 3 * MPD_TEXT_WIDTH, posY - 0.5 * MPD_TEXT_HEIGHT}, 1},\
                    {{MPD_POS_BUTTON_L_X + 0.01 + 3 * MPD_TEXT_WIDTH, posY + 1.5 * MPD_TEXT_HEIGHT}, 1},\
                    {{MPD_POS_BUTTON_L_X - 0.01, posY + 1.5 * MPD_TEXT_HEIGHT}, 1},\
                    {{MPD_POS_BUTTON_L_X - 0.01, posY - 0.5 * MPD_TEXT_HEIGHT}, 1}\
                };\
            }; \
        };\
    };
    
    WPN_RKT_INVENTORY(Inv1, 0, MPD_POS_BUTTON_LR_1_Y, MFD_TEXT_IND_WPN_RKT_INV_1_NAME, MFD_TEXT_IND_WPN_RKT_INV_1_QTY)
    WPN_RKT_INVENTORY(Inv2, 1, MPD_POS_BUTTON_LR_2_Y, MFD_TEXT_IND_WPN_RKT_INV_2_NAME, MFD_TEXT_IND_WPN_RKT_INV_2_QTY)
    WPN_RKT_INVENTORY(Inv3, 2, MPD_POS_BUTTON_LR_3_Y, MFD_TEXT_IND_WPN_RKT_INV_3_NAME, MFD_TEXT_IND_WPN_RKT_INV_3_QTY)
    WPN_RKT_INVENTORY(Inv4, 3, MPD_POS_BUTTON_LR_4_Y, MFD_TEXT_IND_WPN_RKT_INV_4_NAME, MFD_TEXT_IND_WPN_RKT_INV_4_QTY)
    WPN_RKT_INVENTORY(Inv5, 4, MPD_POS_BUTTON_LR_5_Y, MFD_TEXT_IND_WPN_RKT_INV_5_NAME, MFD_TEXT_IND_WPN_RKT_INV_5_QTY)

    class Static {
        type = line;
        width = 3;
        points[] = {
            // Burst limit box
            {{0.02,MPD_POS_BUTTON_LR_1_Y - MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_1_Y - MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_3_Y - 4*MPD_TEXT_HEIGHT}, 1}, {},
            {{0.11,MPD_POS_BUTTON_LR_3_Y + 5*MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_5_Y + 2*MPD_TEXT_HEIGHT}, 1},
            {{0.02,MPD_POS_BUTTON_LR_5_Y + 2*MPD_TEXT_HEIGHT}, 1}, {},
            MPD_POINTS_BOX_PAD(Null, 0.5-6.5*MPD_TEXT_WIDTH, 0.78, 13*MPD_TEXT_WIDTH, 2*MPD_TEXT_HEIGHT, 0.01)
        };
    };
    MPD_TEXT_C(Total_Rockets_Label, 0.5, 0.78, MPD_TEXT_STATIC("TOTAL ROCKETS"))
    MPD_TEXT_C(Total_Rockets, 0.5, 0.78+MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_RKT_TOT_QTY))

    MPD_TEXT_R(Inventory_Label_1, 0.11, MPD_POS_BUTTON_LR_3_Y - 4*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("I"))
    MPD_TEXT_R(Inventory_Label_2, 0.11, MPD_POS_BUTTON_LR_3_Y - 3*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("N"))
    MPD_TEXT_R(Inventory_Label_3, 0.11, MPD_POS_BUTTON_LR_3_Y - 2*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("V"))
    MPD_TEXT_R(Inventory_Label_4, 0.11, MPD_POS_BUTTON_LR_3_Y - 1*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("E"))
    MPD_TEXT_R(Inventory_Label_5, 0.11, MPD_POS_BUTTON_LR_3_Y - 0*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("N"))
    MPD_TEXT_R(Inventory_Label_6, 0.11, MPD_POS_BUTTON_LR_3_Y + 1*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("T"))
    MPD_TEXT_R(Inventory_Label_7, 0.11, MPD_POS_BUTTON_LR_3_Y + 2*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("O"))
    MPD_TEXT_R(Inventory_Label_8, 0.11, MPD_POS_BUTTON_LR_3_Y + 3*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("R"))
    MPD_TEXT_R(Inventory_Label_9, 0.11, MPD_POS_BUTTON_LR_3_Y + 4*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("Y"))

    MPD_TEXT_L(Qty_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("QTY"))
    MPD_BOX_L(Qty, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, 1)
    MPD_TEXT_L(Qty, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("4"))
};

class VABs_Mode_Msl {
    condition =  __EVAL(format [STRINGIFY(EQ(user%1,3)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);
    MPD_TEXT_L(Mode_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("MODE"))
    MPD_BOX_L(Mode, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y + 0.5*MPD_TEXT_HEIGHT, 3)
    MPD_TEXT_L(Mode, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_2_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("MAN"))
};

class VABs_Mode_Msl_SAL {
    condition =  __EVAL(format [STRINGIFY(EQ(user%1,3) * (1-user%2)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN, MFD_OFFSET + MFD_IND_WPN_SELECTED_MSL_TYPE]);
    MPD_TEXT_R(Pri_Label, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("PRI"))
    MPD_BOX_R(Pri, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, 1)
    MPD_TEXT_R(Pri, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_MSL_PRI_CODE))

    MPD_TEXT_R(ALT_Label, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("ALT"))
    MPD_BOX_R(ALT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y + 0.5*MPD_TEXT_HEIGHT, 1)
    MPD_TEXT_R(ALT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_MSL_ALT_CODE))

    MPD_TEXT_R(SAL_SEL_Label, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("SAL SEL"))
    MPD_BOX_R(SAL_SEL, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y + 0.5*MPD_TEXT_HEIGHT, 4)
    MPD_TEXT_R(SAL_SEL, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_MSL_SAL_SEL))

    MPD_TEXT_R(DEICE, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("DEICE"))
    MPD_TEXT_R(MSL_CCM, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC(" MSL CCM"))

    class MSL_CCM_Circle {
        type = line;
        width = 3;
        points[] = {
            MPD_POINTS_CURVED_CORNER(Null, MPD_POS_BUTTON_L_X + 0.35*MPD_TEXT_WIDTH, MPD_POS_BUTTON_LR_6_Y + 0.5*MPD_TEXT_HEIGHT, 0.35*MPD_TEXT_WIDTH, 0.35*MPD_TEXT_WIDTH), {},
            MPD_POINTS_CURVED_CORNER(Null, MPD_POS_BUTTON_L_X + 0.35*MPD_TEXT_WIDTH, MPD_POS_BUTTON_LR_6_Y + 0.5*MPD_TEXT_HEIGHT, 0.35*MPD_TEXT_WIDTH, -0.35*MPD_TEXT_WIDTH), {},
            MPD_POINTS_CURVED_CORNER(Null, MPD_POS_BUTTON_L_X + 0.35*MPD_TEXT_WIDTH, MPD_POS_BUTTON_LR_6_Y + 0.5*MPD_TEXT_HEIGHT, -0.35*MPD_TEXT_WIDTH, 0.35*MPD_TEXT_WIDTH), {},
            MPD_POINTS_CURVED_CORNER(Null, MPD_POS_BUTTON_L_X + 0.35*MPD_TEXT_WIDTH, MPD_POS_BUTTON_LR_6_Y + 0.5*MPD_TEXT_HEIGHT, -0.35*MPD_TEXT_WIDTH, -0.35*MPD_TEXT_WIDTH), {},
        };
    };

    MPD_TEXT_L(Type_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("TYPE"))
    MPD_BOX_L(Type, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, 3)
    MPD_TEXT_L(Type, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("SAL"))

    MPD_TEXT_L(Traj_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_3_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("TRAJ"))
    MPD_BOX_L(Traj, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_3_Y + 0.5*MPD_TEXT_HEIGHT, 3)
    MPD_TEXT_L(Traj, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_3_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_MSL_TRAJ))

    MPD_TEXT_C(HFMSN, MPD_POS_BUTTON_TB_3_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("HFMSN"))

    // Missile Channels
    class Static {
        type = line;
        width = 3;
        points[] = {
            MPD_POINTS_BOX_PAD_EXTERNAL(Null, 0.275, 0.76, 0.45, 0.15, 0.02)
        };
    };

    MPD_TEXT_C(Channels, 0.5, 0.76, MPD_TEXT_STATIC("CHANNELS"))

    #define WPN_MISSILE_CHANNEL(className, posX, channelNum, textSourceInd) \
    class className {\
        class Pri {\
            condition = __EVAL(format [STRINGIFY(EQ(user%1,channelNum)), MFD_OFFSET + MFD_IND_WPN_SELECTED_PRI_CH]);\
            color[] = {1,1,1,1};\
            MPD_TEXT_C(Label, posX, 0.77+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("PRI"))\
            MPD_TEXT_C(Value, posX, 0.77+2*MPD_TEXT_HEIGHT, MPD_TEXT_USER(textSourceInd))\
            class Box {\
                type = line;\
                width = 3;\
                points[] = {\
                    {{posX - 1.5 * MPD_TEXT_WIDTH - 0.01, 0.77+MPD_TEXT_HEIGHT}, 1},\
                    {{posX + 1.5 * MPD_TEXT_WIDTH + 0.01, 0.77+MPD_TEXT_HEIGHT}, 1},\
                    {{posX + 1.5 * MPD_TEXT_WIDTH + 0.01, 0.77+3*MPD_TEXT_HEIGHT}, 1},\
                    {{posX - 1.5 * MPD_TEXT_WIDTH - 0.01, 0.77+3*MPD_TEXT_HEIGHT}, 1},\
                    {{posX - 1.5 * MPD_TEXT_WIDTH - 0.01, 0.77+MPD_TEXT_HEIGHT}, 1}\
                };\
            };\
        };\
        class Alt {\
            condition = __EVAL(format [STRINGIFY(EQ(user%1,channelNum)), MFD_OFFSET + MFD_IND_WPN_SELECTED_ALT_CH]);\
            MPD_TEXT_C(Label, posX, 0.77+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("ALT"))\
            MPD_TEXT_C(Value, posX, 0.77+2*MPD_TEXT_HEIGHT, MPD_TEXT_USER(textSourceInd))\
            class Box {\
            type = line;\
            width = 3;\
            points[] = {\
                    {{posX - 1.5 * MPD_TEXT_WIDTH - 0.01, 0.77+MPD_TEXT_HEIGHT}, 1},\
                    {{posX + 1.5 * MPD_TEXT_WIDTH + 0.01, 0.77+MPD_TEXT_HEIGHT}, 1},\
                    {{posX + 1.5 * MPD_TEXT_WIDTH + 0.01, 0.77+3*MPD_TEXT_HEIGHT}, 1},\
                    {{posX - 1.5 * MPD_TEXT_WIDTH - 0.01, 0.77+3*MPD_TEXT_HEIGHT}, 1},\
                    {{posX - 1.5 * MPD_TEXT_WIDTH - 0.01, 0.77+MPD_TEXT_HEIGHT}, 1}\
                };\
            };\
        };\
        class Unused {\
            condition = __EVAL(format [STRINGIFY((1-(EQ(user%1,channelNum) + EQ(user%2,channelNum)))), MFD_OFFSET + MFD_IND_WPN_SELECTED_PRI_CH,  MFD_OFFSET + MFD_IND_WPN_SELECTED_ALT_CH]);\
            MPD_TEXT_C(Label, posX, 0.77+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC(channelNum))\
            MPD_TEXT_C(Value, posX, 0.77+2*MPD_TEXT_HEIGHT, MPD_TEXT_USER(textSourceInd))\
        };\
    };

    WPN_MISSILE_CHANNEL(Channel_1, 0.335, 1, MFD_TEXT_IND_WPN_MSL_CHAN_1_CODE)
    WPN_MISSILE_CHANNEL(Channel_2, 0.445, 2, MFD_TEXT_IND_WPN_MSL_CHAN_2_CODE)
    WPN_MISSILE_CHANNEL(Channel_3, 0.555, 3, MFD_TEXT_IND_WPN_MSL_CHAN_3_CODE)
    WPN_MISSILE_CHANNEL(Channel_4, 0.665, 4, MFD_TEXT_IND_WPN_MSL_CHAN_4_CODE)
};

class VABs_Mode_Msl_Rf {
    condition =  __EVAL(format [STRINGIFY(EQ(user%1,3) * user%2), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN, MFD_OFFSET + MFD_IND_WPN_SELECTED_MSL_TYPE]);
    MPD_TEXT_R(Msl_Pwr_All, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y, MPD_TEXT_STATIC("ALL"))
    MPD_TEXT_R(Msl_Pwr_Auto, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y, MPD_TEXT_STATIC("AUTO"))
    MPD_BOX_R(Msl_Pwr_Auto, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y, 4)
    MPD_TEXT_R(Msl_Pwr_None, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y, MPD_TEXT_STATIC("NONE"))

    MPD_TEXT_R(Msl_Pwr_Label_1, 0.11, MPD_POS_BUTTON_LR_2_Y - 3 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("M"))
    MPD_TEXT_R(Msl_Pwr_Label_2, 0.11, MPD_POS_BUTTON_LR_2_Y - 2 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("S"))
    MPD_TEXT_R(Msl_Pwr_Label_3, 0.11, MPD_POS_BUTTON_LR_2_Y - 1 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("L"))
    MPD_TEXT_R(Msl_Pwr_Label_4, 0.11, MPD_POS_BUTTON_LR_2_Y + 1 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("P"))
    MPD_TEXT_R(Msl_Pwr_Label_5, 0.11, MPD_POS_BUTTON_LR_2_Y + 2 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("W"))
    MPD_TEXT_R(Msl_Pwr_Label_6, 0.11, MPD_POS_BUTTON_LR_2_Y + 3 * MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("R"))

    class Static {
        type = line;
        width = 3;
        points[] = {
            {{0.02,MPD_POS_BUTTON_LR_1_Y - MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_1_Y - MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_2_Y - 3*MPD_TEXT_HEIGHT}, 1}, {},
            {{0.11,MPD_POS_BUTTON_LR_2_Y + 4*MPD_TEXT_HEIGHT}, 1},
            {{0.11,MPD_POS_BUTTON_LR_3_Y + 2*MPD_TEXT_HEIGHT}, 1},
            {{0.02,MPD_POS_BUTTON_LR_3_Y + 2*MPD_TEXT_HEIGHT}, 1}
        };
    };

    MPD_TEXT_R(LOBL_INHIBIT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("LOBL INHIBIT"))
    MPD_TEXT_R(SECOND_TARGET_INHIBIT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC("2ND TARGET INHIBIT"))

    MPD_TEXT_L(Type_Label, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("TYPE"))
    MPD_BOX_L(Type, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, 2)
    MPD_TEXT_L(Type, MPD_POS_BUTTON_R_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("RF"))
};

class Static {
    type = line;
    width = 3;
    points[] = {
        {{0.420,0.575},1}, {{0.189,0.552},1}, {{0.189,0.456},1}, {{0.421,0.437},1}, {{0.420,0.286},1}, {{0.424,0.270},1}, {{0.435,0.254},1}, {{0.451,0.243},1}, {{0.469,0.239},1}, {},
        {{0.470,0.239}, 1}, {{0.473,0.228}, 1}, {{0.480,0.220}, 1}, {{0.490,0.214}, 1}, {{0.503, 0.213}, 1}, {},
        {{0.579,0.575}, 1}, {{0.811,0.552}, 1}, {{0.811,0.456}, 1}, {{0.579,0.437}, 1}, {{0.579,0.286}, 1}, {{0.575,0.270}, 1}, {{0.564,0.254}, 1}, {{0.548,0.243}, 1}, {{0.530,0.239}, 1}, {},

        {{0.530,0.239}, 1}, {{0.527,0.228}, 1}, {{0.523,0.220}, 1}, {{0.513,0.214}, 1}, {{0.503,0.213}, 1}, {},
        {{0.579,0.575}, 1}, {{0.579,0.756}, 1}, {{0.420,0.756}, 1}, {{0.420,0.575},1}, {},
        //Sight Box
        MPD_POINTS_BOX_PAD(Null, 0.27, 0.13, 0.09, 0.06, 0.02), {},
        //ACQ
        MPD_POINTS_BOX_PAD(Null, 0.64, 0.13, 0.09, 0.06, 0.02), {},
        //LST
        MPD_POINTS_BOX_PAD(Null, 0.27, 0.26, 0.07, 0.05, 0.02), {},
        //LRFD
        MPD_POINTS_BOX_PAD(Null, 0.66, 0.26, 0.07, 0.05, 0.02), {},
        //Chaff
        MPD_POINTS_BOX_PAD(Null, 0.46, 0.601, 0.08, 0.12, 0.02), {},
    };
};

MPD_TEXT_C(Chaff_Label, 0.5, 0.59, MPD_TEXT_STATIC("CHAFF"))
MPD_TEXT_C(Chaff_Qty, 0.5, 0.59+MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_CHAFF_QTY))
class ChaffArming {
	class Safe {
		condition =  __EVAL(format ["1 - user%1", MFD_OFFSET + MFD_IND_WPN_CHAFF_ARM]);
        MPD_TEXT_C(Chaff_Armed, 0.5, 0.60+2*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("SAFE"))
	};
	class Arm {
		condition = __EVAL(format ["user%1", MFD_OFFSET + MFD_IND_WPN_CHAFF_ARM]);
        class Yellow {
            color[] = {1,1,0,1};
            class Polygon {
                type = polygon;
                points[] = {
                    {
                        {{0.5-1.5*MPD_TEXT_WIDTH, 0.60+2*MPD_TEXT_HEIGHT}, 1},
                        {{0.5+1.5*MPD_TEXT_WIDTH, 0.60+2*MPD_TEXT_HEIGHT}, 1},
                        {{0.5+1.5*MPD_TEXT_WIDTH, 0.60+3*MPD_TEXT_HEIGHT}, 1},
                        {{0.5-1.5*MPD_TEXT_WIDTH, 0.60+3*MPD_TEXT_HEIGHT}, 1}
                    },
                };
            };
        };
        class Black {
            color[] = {0,0,0,1};
            MPD_TEXT_C(Chaff_Armed, 0.5, 0.60+2*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("ARM"))
        };
	};
};

class Gun {
	class Selected {
		condition =  __EVAL(format [STRINGIFY(EQ(user%1,1)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);
        //Here
        class Polygon {
            type = polygon;
            points[] = {
                {
                    { {0.4775, 0.3220}, 1 },
                    { {0.4788, 0.3170}, 1 },
                    { {0.4875, 0.3220}, 1 },
                }, {
                    { {0.4788, 0.3170}, 1 },
                    { {0.4825, 0.3133}, 1 },
                    { {0.4875, 0.3220}, 1 },
                }, {
                    { {0.4825, 0.3133}, 1 },
                    { {0.4875, 0.3120}, 1 },
                    { {0.4875, 0.3220}, 1 },
                }, {
                    { {0.4875, 0.3220}, 1 },
                    { {0.4875, 0.3133}, 1 },
                    { {0.5125, 0.3133}, 1 },
                    { {0.5125, 0.3220}, 1 },
                }, {
                    { {0.5125, 0.3120}, 1 },
                    { {0.5175, 0.3133}, 1 },
                    { {0.5125, 0.3220}, 1 },
                }, {
                    { {0.5175, 0.3133}, 1 },
                    { {0.5212, 0.3170}, 1 },
                    { {0.5125, 0.3220}, 1 },
                }, {
                    { {0.5212, 0.3170}, 1 },
                    { {0.5225, 0.3220}, 1 },
                    { {0.5125, 0.3220}, 1 },
                }, {
                    { {0.4775, 0.3220}, 1 },
                    { {0.5225, 0.3220}, 1 },
                    { {0.5225, 0.3720}, 1 },
                    { {0.4775, 0.3720}, 1 },
                }, {
                    //Gun Tip
                    {{0.507, 0.236}, 1}, 
                    {{0.492, 0.236}, 1}, 
                    {{0.492, 0.254}, 1}, 
                    {{0.507, 0.254}, 1},
                }, {
                    //Gun Barrel
                    {{0.505, 0.254}, 1}, 
                    {{0.495, 0.254}, 1}, 
                    {{0.495, 0.312}, 1}, 
                    {{0.505, 0.312}, 1},
                }, {
                    //Gun Ammo Box
                    {{0.445, 0.372}, 1}, 
                    {{0.555, 0.372}, 1}, 
                    {{0.555, 0.372+0.06}, 1}, 
                    {{0.445, 0.372+0.06}, 1},
                },
            };
        };
        class Ammo {
            color[] = {0,0,0,0};
            MPD_TEXT_C(Gun_Ammo, 0.5, 0.382, MPD_TEXT_USER(MFD_TEXT_IND_WPN_GUN_ROUNDS))
        };
    };
	class Deselected {
		condition = __EVAL(format [STRINGIFY(1-EQ(user%1,1)), MFD_OFFSET + MFD_IND_WPN_SELECTED_WPN]);
        MPD_TEXT_C(Ammo, 0.5, 0.382, MPD_TEXT_USER(MFD_TEXT_IND_WPN_GUN_ROUNDS))
        class Lines {
            type = line;
            width = 3;
            points[] = {
                 //Gun Tip
                {{0.507, 0.236}, 1}, {{0.492, 0.236}, 1}, {{0.492, 0.254}, 1}, {{0.507, 0.254}, 1}, {{0.507, 0.236}, 1}, {},
                //Gun Barrel
                {{0.505, 0.254}, 1}, {{0.495, 0.254}, 1}, {{0.495, 0.312}, 1}, {{0.505, 0.312}, 1}, {{0.505, 0.254}, 1}, {},
                
                //Gun Base
                MPD_POINTS_CURVED_CORNER(Null, 0.5125, 0.322, 0.01, -0.01), {},
                MPD_POINTS_CURVED_CORNER(Null, 0.4875, 0.322, -0.01, -0.01), {},
                {{0.4875, 0.312}, 1}, {{0.5125, 0.312}, 1}, {},
                {{0.5225,0.322}, 1}, {{0.5225,0.372}, 1}, {{0.4775,0.372}, 1}, {{0.4775,0.322}, 1}, {},
                //Gun Ammo Box
                {{0.445, 0.372}, 1}, {{0.555, 0.372}, 1}, {{0.555, 0.372+0.06}, 1}, {{0.445, 0.372+0.06}, 1}, {{0.445, 0.372}, 1},
            };
        };
	};
};

MPD_TEXT_C(Sight_Label, 0.315, 0.12, MPD_TEXT_STATIC("SIGHT"))
MPD_TEXT_C(Sight, 0.315, 0.12+MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_SIGHT))
MPD_TEXT_C(Box_ACQ_Label, 0.685, 0.12, MPD_TEXT_STATIC("ACQ"))
MPD_TEXT_C(Box_ACQ, 0.685, 0.12+MPD_TEXT_HEIGHT, MPD_TEXT_USER(MFD_TEXT_IND_WPN_ACQ))

MPD_TEXT_C(LST_Label, 0.305, 0.24, MPD_TEXT_STATIC("LST"))
MPD_TEXT_C(LST, 0.305, 0.24+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("B"))
MPD_TEXT_C(Box_LRFD_Label, 0.695, 0.24, MPD_TEXT_STATIC("LRFD"))
MPD_TEXT_C(Box_LRFD, 0.695, 0.24+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("A"))


// Hellfire icons
class HellfirePylon1
{
    type	= pylonicon;
    pos[]	= { {0.245,0.43}, 1 };
    pylon	= 1;
    name	= fza_ah64_hellfire_inverse;
};
#define MFD_WPN_HF_PYLON(num, posX, posY) \
    class HellfirePylon##num : HellfirePylon1 { \
        pos[] = {{posX, posY}, 1};\
        pylon = num;\
    };
MFD_WPN_HF_PYLON(2, 0.29, 0.43)
MFD_WPN_HF_PYLON(3, 0.245, 0.565)
MFD_WPN_HF_PYLON(4, 0.29, 0.565)

MFD_WPN_HF_PYLON(5, 0.345, 0.43)
MFD_WPN_HF_PYLON(6, 0.39, 0.43)
MFD_WPN_HF_PYLON(7, 0.345, 0.565)
MFD_WPN_HF_PYLON(8, 0.39, 0.565)

MFD_WPN_HF_PYLON(9, 0.61, 0.43)
MFD_WPN_HF_PYLON(10, 0.655, 0.43)
MFD_WPN_HF_PYLON(11, 0.61, 0.565)
MFD_WPN_HF_PYLON(12, 0.655, 0.565)

MFD_WPN_HF_PYLON(13, 0.71, 0.43)
MFD_WPN_HF_PYLON(14, 0.755, 0.43)
MFD_WPN_HF_PYLON(15, 0.71, 0.565)
MFD_WPN_HF_PYLON(16, 0.755, 0.565)


// RocketPylons
class RocketPylon1
{
    type	= pylonicon;
    pos[]	= { {0.27,0.5}, 1 };
    pylon	= 1;
    name	= fza_ah64_rocket_inverse;
};
#define MFD_WPN_ROCKET_PYLON(num, posX, posY) \
    class RocketPylon##num : RocketPylon1 { \
        pos[] = {{posX, posY}, 1};\
        pylon = num;\
    };
MFD_WPN_ROCKET_PYLON(5, 0.37, 0.5)
MFD_WPN_ROCKET_PYLON(9, 0.63, 0.5)
MFD_WPN_ROCKET_PYLON(13, 0.73, 0.5)

#define WPN_CHECKER(posX, posY) \
    {\
        {{posX - 0.01, posY - 0.01}, 1},\
        {{posX + 0.01, posY - 0.01}, 1},\
        {{posX + 0.01, posY + 0.01}, 1},\
        {{posX - 0.01, posY + 0.01}, 1},\
    }

#define WPN_CHECKERS \
    WPN_CHECKER(0.535, 0.093),\
    WPN_CHECKER(0.5, 0.093),\
    WPN_CHECKER(0.465, 0.093),\
    WPN_CHECKER(0.445, 0.117),\
    WPN_CHECKER(0.445, 0.143),\
    WPN_CHECKER(0.535, 0.167),\
    WPN_CHECKER(0.5, 0.167),\
    WPN_CHECKER(0.465, 0.167),\
    WPN_CHECKER(0.555, 0.117),\
    WPN_CHECKER(0.555, 0.143)

class ArmSafe {
    class Safe {
        condition = 0;
        MPD_TEXT_C(Safe, 0.5, 0.13-0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("SAFE"))
        //Safe Box
        class Static {
            type = line;
            width = 3;
            points[] = {
                MPD_POINTS_BOX_PAD(Null, 0.45, 0.1, 0.10, 0.06, 0.02)
            };
        };
    };
    class Safe_WAS {
        condition = 0;
        class Polygons {
            type = polygon;
            points[] = {
                WPN_CHECKERS
            };
        };
    };
    class Arm {
        condition = 1;
        color[] = {1,1,0,1};
        class Polygons {
            type = polygon;
            points[] = {
                {
                    {{0.4300, 0.1000}, 1},  //upper left corner
                    {{0.4327, 0.0900}, 1},
                    {{0.4500, 0.1000}, 1},
                }, {
                    {{0.4327, 0.0900}, 1},
                    {{0.4400, 0.0827}, 1},
                    {{0.4500, 0.1000}, 1},
                }, {
                    {{0.4400, 0.0827}, 1},
                    {{0.4500, 0.0800}, 1},
                    {{0.4500, 0.1000}, 1},
                }, {
                    {{0.4500, 0.1000}, 1}, //top box
                    {{0.4500, 0.0800}, 1},
                    {{0.5500, 0.0800}, 1},
                    {{0.5500, 0.1000}, 1},
                }, {
                    {{0.5500, 0.0800}, 1}, //upper right corner
                    {{0.5600, 0.0827}, 1},
                    {{0.5500, 0.1000}, 1},
                }, {
                    {{0.5600, 0.0827}, 1},
                    {{0.5673, 0.0900}, 1},
                    {{0.5500, 0.1000}, 1},
                }, {
                    {{0.5673, 0.0900}, 1},
                    {{0.5700, 0.1000}, 1},
                    {{0.5500, 0.1000}, 1},
                }, {
                    {{0.5500, 0.1000}, 1}, //right box
                    {{0.5700, 0.1000}, 1},
                    {{0.5700, 0.1600}, 1},
                    {{0.5500, 0.1600}, 1},
                }, {
                    {{0.5500, 0.1800}, 1}, //bottom right corner
                    {{0.5600, 0.1773}, 1},
                    {{0.5500, 0.1600}, 1},
                }, {
                    {{0.5600, 0.1773}, 1},
                    {{0.5673, 0.1700}, 1},
                    {{0.5500, 0.1600}, 1},
                }, {
                    {{0.5673, 0.1700}, 1},
                    {{0.5700, 0.1600}, 1},
                    {{0.5500, 0.1600}, 1},
                },  {
                    {{0.4500, 0.1800}, 1}, //bottom box
                    {{0.5500, 0.1800}, 1},
                    {{0.5500, 0.1600}, 1},
                    {{0.4500, 0.1600}, 1},
                }, {
                    {{0.4500, 0.1800}, 1}, //bottom left corner
                    {{0.4400, 0.1773}, 1},
                    {{0.4500, 0.1600}, 1},
                }, {
                    {{0.4400, 0.1773}, 1},
                    {{0.4327, 0.1700}, 1},
                    {{0.4500, 0.1600}, 1},
                }, {
                    {{0.4327, 0.1700}, 1},
                    {{0.4300, 0.1600}, 1},
                    {{0.4500, 0.1600}, 1},
                }, {
                    {{0.4300, 0.1000}, 1}, //left box
                    {{0.4500, 0.1000}, 1},
                    {{0.4500, 0.1600}, 1},
                    {{0.4300, 0.1600}, 1},
                }, {
                    {{0.4300, 0.1000}, 1}, //center box
                    {{0.5500, 0.1000}, 1},
                    {{0.5500, 0.1600}, 1},
                    {{0.4300, 0.1600}, 1},
                }
            };
        }
        class Black {
            color[] = {0,0,0,1};
            MPD_TEXT_C(Arm, 0.5, 0.13-0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("ARM"))
        }
    };
    class Arm_WAS {
        condition = 1;
        color[] = {0,0,0,1};
        class Polygons {
            type = polygon;
            points[] = {
                WPN_CHECKERS
            };
        };
    };
};