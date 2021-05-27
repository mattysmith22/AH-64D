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

#define MPD_FLT_HORIZON_LINE_MAIN(angle, directionNum, directionName, horizonLineType, lineColour) class HorizonLine_##angle##_##directionName { \
    condition = (horizonDive > rad (directionNum * angle - 31)) *(horizonDive < rad (directionNum * angle + 31)); \
    color[] = lineColour; \
    class horizontal { \
        type = line; \
        lineType = horizonLineType; \
        width = 3; \
        points[] = { \
            {"Flt_Horizon", {0.7 * (-(0.04 + angle * 0.002)), 0.7 * (- directionNum * angle * 0.014)}, 1}, \
            {"Flt_Horizon", {0.7 * (-(0.18 + angle * 0.002)), 0.7 * (- directionNum * angle * 0.014)}, 1}, \
            {}, \
            {"Flt_Horizon", {0.7 * (0.04 + angle * 0.002), 0.7 * (- directionNum * angle * 0.014)}, 1}, \
            {"Flt_Horizon", {0.7 * (0.18 + angle * 0.002), 0.7 * (- directionNum * angle * 0.014)}, 1}}; \
    }; \
    class vertical { \
        type = line; \
        width = 3; \
        points[] = { \
            {"Flt_Horizon", {0.7 * (-(0.18 + angle * 0.002)), 0.7 * (- directionNum * angle * 0.014)}, 1}, \
            {"Flt_Horizon", {0.7 * (-(0.18 + angle * 0.002)), 0.7 * ((- directionNum * angle * 0.014) + directionNum * 0.026)}, 1}, \
            {}, \
            {"Flt_Horizon", {0.7 * (0.18 + angle * 0.002), 0.7 * (- directionNum * angle * 0.014)}, 1}, \
            {"Flt_Horizon", {0.7 * (0.18 + angle * 0.002), 0.7 * ((- directionNum * angle * 0.014) + directionNum * 0.026)}, 1}}; \
    }; \
};
class testHorizon { \
        type = line; \
        width = 3; \
        points[] = { \
            {"Flt_Horizon", {-0.5, 0}, 1}, \
            {"Flt_Horizon", {0.5, 0}, 1}, \
    }; \
};
#define MPD_COLOUR_GROUND {0, 1, 1, 1}
#define MPD_COLOUR_AIR {1, 0.78, 0.69, 1}
#define MPD_FLT_HORIZON_LINE_MAIN_AIR(angle) MPD_FLT_HORIZON_LINE_MAIN(angle, -1,Ground, 2, MPD_COLOUR_AIR)
#define MPD_FLT_HORIZON_LINE_MAIN_GROUND(angle) MPD_FLT_HORIZON_LINE_MAIN(angle, 1,Air, 0, MPD_COLOUR_GROUND)

MPD_FLT_HORIZON_LINE_MAIN_AIR(10) 
MPD_FLT_HORIZON_LINE_MAIN_AIR(20)
MPD_FLT_HORIZON_LINE_MAIN_AIR(30)
MPD_FLT_HORIZON_LINE_MAIN_AIR(40)
MPD_FLT_HORIZON_LINE_MAIN_AIR(50)
MPD_FLT_HORIZON_LINE_MAIN_AIR(60)
MPD_FLT_HORIZON_LINE_MAIN_AIR(70)
MPD_FLT_HORIZON_LINE_MAIN_AIR(80)
MPD_FLT_HORIZON_LINE_MAIN_AIR(90)
MPD_FLT_HORIZON_LINE_MAIN_AIR(100)
MPD_FLT_HORIZON_LINE_MAIN_AIR(110)
MPD_FLT_HORIZON_LINE_MAIN_AIR(120)
MPD_FLT_HORIZON_LINE_MAIN_AIR(130)
MPD_FLT_HORIZON_LINE_MAIN_AIR(140)
MPD_FLT_HORIZON_LINE_MAIN_AIR(150)
MPD_FLT_HORIZON_LINE_MAIN_AIR(160)
MPD_FLT_HORIZON_LINE_MAIN_AIR(170)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(10)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(20)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(30)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(40)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(50)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(60)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(70)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(80)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(90)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(100)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(110)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(120)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(130)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(140)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(150)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(160)
MPD_FLT_HORIZON_LINE_MAIN_GROUND(170)