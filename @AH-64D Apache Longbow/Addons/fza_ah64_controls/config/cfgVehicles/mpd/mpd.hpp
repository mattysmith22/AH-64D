color[] = {0, 1, 0.02, 1};
helmetMountedDisplay = false;
borderLeft=0;
borderRight=0;
borderTop=0;
font="LucidaConsoleB";
borderBottom=0;
class material
{
	ambient[]	= { 5, 5, 5, 1 };
	diffuse[]	= { 8, 8, 8, 1 };
	emissive[]	= { 40, 40, 40, 1 };
};
class Bones {
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
};