///////////////// L ///////////////
MPD_TEXT_R(Waterline, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y, MPD_TEXT_STATIC("-W-"))
MPD_TEXT_R(Bias, MPD_POS_BUTTON_L_X, MPD_POS_BUTTON_LR_5_Y+MPD_TEXT_HEIGHT, MPD_TEXT_STATIC("BIAS"))


///////////////// T ///////////////
MPD_ARROW_C(ENG, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_T_Y, 3)
MPD_TEXT_C(ENG, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("ENG"))

MPD_ARROW_C(FUEL, MPD_POS_BUTTON_TB_3_X, MPD_POS_BUTTON_T_Y, 4)
MPD_TEXT_C(FUEL, MPD_POS_BUTTON_TB_3_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("FUEL"))

MPD_ARROW_C(PERF, MPD_POS_BUTTON_TB_4_X, MPD_POS_BUTTON_T_Y, 4)
MPD_TEXT_C(PERF, MPD_POS_BUTTON_TB_4_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("PERF"))

MPD_ARROW_C(UTIL, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y, 4)
MPD_TEXT_C(UTIL, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_T_Y, MPD_TEXT_STATIC("UTIL"))

///////////////// B ///////////////
MPD_BOX_C(FLT, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_B_Y, 3)
MPD_TEXT_C(FLT, MPD_POS_BUTTON_TB_1_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("FLT"))

MPD_ARROW_C(SET, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_B_Y, 3)
MPD_TEXT_C(SET, MPD_POS_BUTTON_TB_6_X, MPD_POS_BUTTON_B_Y, MPD_TEXT_STATIC("SET"))

///////////////// Torque ///////////////
MPD_TEXT_L(Torque, 0.15, 0.14, MPD_TEXT_USER(MFD_IND_FLT_TORQUE))

///////////////// Heading ///////////////
MPD_TEXT_C(Heading, 0.5, 0.12, source = heading; sourceScale = 1;)

///////////////// Altitude ///////////////
MPD_TEXT_L(AltMSL, 0.93, 0.13, source = altitudeASL; sourceScale = MPD_SCALE_METERS_FEET;)
MPD_TEXT_L(AltAGL, 0.92, 0.5, source = altitudeAGL; sourceScale = MPD_SCALE_METERS_FEET;)

///////////////// Airspeed ///////////////
MPD_TEXT_L(Airspeed, 0.16, 0.5, MPD_TEXT_USER(MFD_IND_FLT_AIRSPEED))

///////////////// Heading Tape ///////////////
class HeadingTape {
    //SOurce info
    source = heading;
    sourceScale = 1;

    //Tape setup
    type = scale;
    horizontal = 1;
    neverEatSeaWeed = 1;
    step = 10;
    stepSize = __EVAL(0.5/18-0.001);
    lineXLeft = 0.15;
    lineYRight = 0.165;
    lineXLeftMajor = 0.15;
    lineYRightMajor = 0.18;
    top = 0.25;
    bottom = 0.75;
    center = 0.5;
    majorLineEach = 3;
    numberEach = 3;


    //Text config
    align = center;
    scale = 1;
    pos[] = {0.25, 0.15-MPD_TEXT_HEIGHT};
    right[] = {0.25 + MPD_TEXT_WIDTH_VEC, 0.15-MPD_TEXT_HEIGHT};
    down[] = {0.25, 0.15};
};

class TestHorizon {
    type = line;
    width = 2;
    points[] = {
        {"Flt_Horizon", {-0.1, 0.0}, 1},
        {"Flt_Horizon", {0.1, 0.0}, 1}};
};
