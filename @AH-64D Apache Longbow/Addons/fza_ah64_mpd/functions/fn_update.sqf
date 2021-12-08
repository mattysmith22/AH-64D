/* ----------------------------------------------------------------------------
Function: fza_mpd_fnc_update

Description:
	Updates the MPDs inside the apache to show the correct visuals. Should be run regularly.

Parameters:
	_heli - the apache to show the correct values for.

Returns:
	Nothing.

Examples:
    --- Code
	[_heli] call fza_mpd_fnc_update
    ---

Author:
	mattysmith22
---------------------------------------------------------------------------- */
params ["_heli"];
#include "\fza_ah64_mpd\headers\mfdConstants.h"
(_heli getVariable "fza_ah64_mpdPage") params ["_lmpdNext", "_rmpdNext"];
(_heli getVariable "fza_ah64_mpdCurrPage") params ["_lmpdCurr", "_rmpdCurr"];

if (_heli animationphase "plt_batt" < 0.5 && (_lmpdCurr != "OFF" || _rmpdCurr != "OFF")) then {
	[_heli, 1, "off"] call fza_mpd_fnc_setCurrentPage;
	[_heli, 0, "off"] call fza_mpd_fnc_setCurrentPage;
};
if ((_heli animationphase "plt_batt" > 0.5) && (_lmpdCurr == "OFF" || _rmpdCurr == "OFF")) then {
	[_heli, 0, "fuel"] call fza_mpd_fnc_setCurrentPage;
	[_heli, 1, "eng"] call fza_mpd_fnc_setCurrentPage;
};

// Left MPD checks

if (_lmpdNext != _lmpdCurr) then {
	// If the page has been changed since the last update.
	switch (_lmpdNext) do {
		case "off" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_OFF]; };
		case "eng" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_ENG]; };
		case "menu" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_MENU];};
		case "flt" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_FLT];};
		case "fuel" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_FUEL]; };
		case "wca" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_WCA];};
		case "wpn" : { _heli setUserMfdValue[MFD_IND_PAGE_LEFT, MPD_PAGE_WPN];};
	};
	_lmpdCurr = _lmpdNext;
};

if (_rmpdNext != _rmpdCurr) then {
	_rmpdCurr = _rmpdNext;
};


switch (_lmpdCurr) do {
	case "flt" : { [_heli, 0] call fza_mpd_fnc_pageFLTDraw; };
	case "fuel" : { [_heli, 0] call fza_mpd_fnc_pageFUELDraw; };
	case "wca" : { [_heli, 0] call fza_mpd_fnc_pageWCADraw; };
	case "wpn" : { [_heli, 0] call fza_mpd_fnc_pageWPNDraw; };
	case "eng" : { [_heli, 0] call fza_mpd_fnc_pageENGDraw; };
};

_heli setVariable ["fza_ah64_mpdCurrPage", [_lmpdCurr, _rmpdCurr]];