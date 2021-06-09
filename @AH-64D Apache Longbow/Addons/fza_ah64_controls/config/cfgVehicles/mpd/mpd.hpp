color[] = {0, 1, 0.02, 1};
helmetMountedDisplay = false;
borderLeft=0;
borderRight=0;
borderTop=0;
font="fza_ticketing";
helmetDown[] = {0,-0.075,0};
helmetPosition[] = {-0.0375,0.0375,0.1};
helmetRight[] = {0.075,0,0};
borderBottom=0;
class material
{
	ambient[]	= { 5, 5, 5, 1 };
	diffuse[]	= { 5, 5, 5, 1 };
	emissive[]	= { 200, 200, 200, 1 };
};
class Bones {
    class Null {
        type = fixed;
        pos[] = {0, 0};
    };
    #include "page_flt_bones.hpp"
};
// HUD-Elements definitions
class Draw
{
    class Menu {
        condition = EQ(USER_NUM(MFD_IND_PAGE), MPD_PAGE_MENU);
        #include "page_menu_draw.hpp"
    };
    class Flt {
        condition = EQ(USER_NUM(MFD_IND_PAGE), MPD_PAGE_FLT);
        #include "page_flt_draw.hpp"
    };
    class Wca {
        condition = EQ(USER_NUM(MFD_IND_PAGE), MPD_PAGE_WCA);
        #include "page_wca_draw.hpp"
    };
};