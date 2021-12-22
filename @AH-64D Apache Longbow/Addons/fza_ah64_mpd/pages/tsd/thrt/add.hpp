class thrtAdd{
    class vabs {
        #include "..\components\vabs_top.hpp"
        #include "..\components\vabs_right.hpp"

        //L1
        MPD_TEXT_R(POINT_Label, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y - 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("IDENT>"))
        //L2
        MPD_BOX_R(ADD,  MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y, 3)
        MPD_TEXT_R(ADD, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_2_Y, MPD_TEXT_STATIC("ADD"))
        //L3 - Default
        class TypeWp {
            condition = __EVAL(format [STRINGIFY(EQ(user%1, POINT_TYPE_WP)), MFD_OFFSET + MFD_IND_TSD_WPT_ADD_TYPE]);
            MPD_BOX_R(WP,     MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y, 2)
            MPD_TEXT_R(POINT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("WP"))
        };
        MPD_TEXT_R(WP, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_3_Y, MPD_TEXT_STATIC("WP"))
        //L4
        class TypeHz {
            condition = __EVAL(format [STRINGIFY(EQ(user%1, POINT_TYPE_HZ)), MFD_OFFSET + MFD_IND_TSD_WPT_ADD_TYPE]);
            MPD_BOX_R(HZ,     MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_4_Y, 2)
            MPD_TEXT_R(POINT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("HZ"))
        };
        MPD_TEXT_R(HZ, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_4_Y, MPD_TEXT_STATIC("HZ"))
        //L5
        class TypeCm {
            condition = __EVAL(format [STRINGIFY(EQ(user%1, POINT_TYPE_CM)), MFD_OFFSET + MFD_IND_TSD_WPT_ADD_TYPE]);
            MPD_BOX_R(CM,     MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, 2)
            MPD_TEXT_R(POINT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("CM"))
        };
        MPD_TEXT_R(CM, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("CM"))
        //L5
        class TypeTg {
            condition = __EVAL(format [STRINGIFY(EQ(user%1, POINT_TYPE_TG)), MFD_OFFSET + MFD_IND_TSD_WPT_ADD_TYPE]);
            MPD_BOX_R(TG,     MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, 2)
            MPD_TEXT_R(POINT, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_1_Y + 0.5*MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("TG"))
        };
        MPD_TEXT_R(TG, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_6_Y, MPD_TEXT_STATIC("TG"))
    };
};