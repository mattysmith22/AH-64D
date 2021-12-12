/* ----------------------------------------------------------------------------
Function: fza_fnc_controlHandleTSDMode

Description:
    Switches between the two TSD modes - ATK and NAV - for the selected heli

Parameters:
    _heli - The helicopter to modify

Returns:
	Nothing

Examples:
	--- Code
    [_heli] call fza_fnc_controlHandleTSDMode
	---

Author:
	Unknown
---------------------------------------------------------------------------- */
params ["_heli"];
switch(_heli getVariable "fza_mpd_tsdMode") do {
	case "nav": {
		_heli setVariable ["fza_mpd_tsdMode", "atk"];
		[_heli] call fza_fnc_targetingVariable;
	};
	case "atk": {
		_heli setVariable ["fza_mpd_tsdMode", "nav"];
	};
}