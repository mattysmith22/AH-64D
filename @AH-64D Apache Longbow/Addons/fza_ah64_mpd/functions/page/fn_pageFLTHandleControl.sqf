#include "\fza_ah64_controls\headers\script_common.hpp"
#include "\fza_ah64_controls\headers\selections.h"
params ["_heli", "_system", "_control"];

switch(_control) do {
	case "t3": {
		[_heli, 0, "fuel"] call fza_mpd_fnc_setCurrentPage;
	};
	case "wpn": {
		[_heli, 0, "wpn"] call fza_mpd_fnc_setCurrentPage;
	};
	case "m": {
		[_heli, 0, "menu"] call fza_mpd_fnc_setCurrentPage;
	};
};