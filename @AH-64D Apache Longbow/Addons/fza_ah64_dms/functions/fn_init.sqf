#include "\fza_ah64_dms\headers\constants.h"
params ["_heli"];
private _newPointsArray = {
    params["_size"];
    private _ret = [];
    for "_i" from 1 to _size do {
        _ret pushBack -1;
    };
    _ret;
};

if (!(_heli getVariable ["fza_dms_aircraftInitialised", false]) && local _heli) then {
    _heli setVariable ["fza_dms_aircraftInitialised", true, true];

    _heli setVariable ["fza_dms_waypointsHazards", [POINT_COUNT_WP_HZ] call _newPointsArray, true];
    _heli setVariable ["fza_dms_controlMeasures", [POINT_COUNT_CM] call _newPointsArray, true];
    _heli setVariable ["fza_dms_targetsThreats", [POINT_COUNT_TG_TH] call _newPointsArray, true];
};