/* ----------------------------------------------------------------------------
Function: fza_mpd_fnc_handleControl

Description:
	Handles any mpd-related cockpit controls.
	
	Works out what MPD is currently open, and calls that respective page's handler

Parameters:
	_heli - The helicopter to act on
	_system - the name of the system that the touched control belongs to
	_control - the name of the control that has been touched

Returns:
	Nothing

Examples:
	--- Code
    [_heli, "lmpd", "r3"] call_mpdHandleControl
	---

Author:
	mattysmith22
---------------------------------------------------------------------------- */
#include "\fza_ah64_controls\headers\script_common.hpp"
#include "\fza_ah64_controls\headers\selections.h"
params ["_heli", "_system", "_control"];

if(_control == "brt") then {
	switch (_heli getVariable "fza_ah64_mpdbrightness") do {
		case 0.2 : {
			_heli setVariable ["fza_ah64_mpdbrightness", 1];
			_heli setobjecttexture [SEL_MPD_BRT, ""];
		};
		case 0.4 : {
			_heli setVariable ["fza_ah64_mpdbrightness", 0.2];
			_heli setobjecttexture [SEL_MPD_BRT, "\fza_ah64_US\tex\MPD\Brt1.paa"];
		};
		case 0.6 : {
			_heli setVariable ["fza_ah64_mpdbrightness", 0.4];
			_heli setobjecttexture [SEL_MPD_BRT, "\fza_ah64_US\tex\MPD\Brt2.paa"];
		};
		case 0.2 : {
			_heli setVariable ["fza_ah64_mpdbrightness", 0.6];
			_heli setobjecttexture [SEL_MPD_BRT, "\fza_ah64_US\tex\MPD\Brt3.paa"];
		};
	};
	["fza_ah64_knob", 0.1] spawn fza_fnc_playAudio;
};

private _mpdIndex = [0,1] select (_system == "rmpd");

switch([_heli, _mpdIndex] call fza_mpd_fnc_currentPage) do {
		case "menu": {
			[_heli, _system, _control, _mpdIndex] call fza_mpd_fnc_pageMENUHandleControl;
		};
		case "flt": {
			[_heli, _system, _control, _mpdIndex] call fza_mpd_fnc_pageFLTHandleControl
		};
		case "fuel": {
			[_heli, _system, _control, _mpdIndex] call fza_mpd_fnc_pageFUELHandleControl;
		};
		case "wca": {
			[_heli, _system, _control, _mpdIndex] call fza_mpd_fnc_pageWCAHandleControl;
		};
		case "wpn": {
			[_heli, _system, _control, _mpdIndex] call fza_mpd_fnc_pageWPNHandleControl;
		};
		case "eng": {
			[_heli, _system, _control, _mpdIndex] call fza_mpd_fnc_pageENGHandleControl;
		};
	};