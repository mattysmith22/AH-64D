params ["_heli", "_system", "_control"];

 systemChat str _this;
switch(_control) do {
	case "b2": {
		[_heli, 0, "flt"] call fza_mpd_fnc_setCurrentPage;
	};
	case "b1": {
		[_heli, 0, "eng"] call fza_mpd_fnc_setCurrentPage;
	};
	case "b3": {
		[_heli, 0, "fuel"] call fza_mpd_fnc_setCurrentPage;
	};
	case "l5": {
		[_heli, 0, "wpn"] call fza_mpd_fnc_setCurrentPage;
	};
	case "wpn": {
		[_heli, 0, "wpn"] call fza_mpd_fnc_setCurrentPage;
	};
	case "m": {
		[_heli, 0, "wca"] call fza_mpd_fnc_setCurrentPage;
	};
};