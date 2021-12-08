#ifdef __A3_DEBUG__
#define R recompile = 1
#else
#define R recompile = 0
#endif
class CfgFunctions
{
    class fza_ah64_mpd {
        tag="fza_mpd";
        class functions {
            file = "\fza_ah64_mpd\functions";
            class currentPage {R;};
            class drawMap {R;};
            class drawPoints {R;};
            class handleControl {R;};
            class handleZoom {R;};
            class setCurrentPage {R;};
            class update {R;};
        };
        class page {
            file = "\fza_ah64_mpd\functions\page";
            class pageENGDraw {R;};
            class pageENGHandleControl {R;};
            class pageFLTDraw {R;};
            class pageFLTHandleControl {R;};
            class pageFUELDraw {R;};
            class pageFUELHandleControl {R;};
            class pageMENUHandleControl {R;};
            class pageWCADraw {R;};
            class pageWCAHandleControl {R;};
            class pageWPNDraw {R;};
            class pageWPNHandleControl {R;};
        };
    };
};