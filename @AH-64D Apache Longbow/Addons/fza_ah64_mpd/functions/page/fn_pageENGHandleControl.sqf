#include "\fza_ah64_controls\headers\script_common.hpp"
#include "\fza_ah64_controls\headers\selections.h"
params ["_heli", "_system", "_control"];

switch(_control) do {
	case "b5": {
		[_heli, 0, "wca"] call fza_mpd_fnc_setCurrentPage;
	};
	case "fcr" : {
		[_heli, 0, "fcr"] call fza_mpd_fnc_setCurrentPage;
	};
	case "tsd": {
		[_heli, 0, "tsd"] call fza_mpd_fnc_setCurrentPage;
	};
	case "m": {
		[_heli, 0, "menu"] call fza_mpd_fnc_setCurrentPage;
	};
};