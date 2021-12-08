class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F : Helicopter {
        class MFD;
    };
    class fza_ah64base : Helicopter_Base_F {
        class MFD : MFD {
			#define MFD_IND_PAGE MFD_IND_PAGE_LEFT
			#define MFD_OFFSET MFD_OFFSET_L
			class MPD_L {
				topLeft = "PLT_MPD_L_TL";
				topRight = "PLT_MPD_L_TR";
				bottomLeft = "PLT_MPD_L_BL";
				#include "mpd.hpp"
			};
		};
    }
};