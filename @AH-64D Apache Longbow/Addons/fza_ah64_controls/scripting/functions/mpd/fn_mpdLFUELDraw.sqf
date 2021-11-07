params["_heli", "_leftSide"];
#include "\fza_ah64_controls\headers\selections.h"
#include "\fza_ah64_controls\headers\mfdConstants.h"

//Lbs
//#define FORWARD_FUEL_CELL_WEIGHT 1041
//#define AFT_FUEL_CELL_WEIGHT 1534
//#define TOTAL_FUEL_CELL_WEIGHT 2575
#define KGTOLBS 2.20462


private _forwardCellWeight = [_heli] call fza_fnc_sfmplusSetFuel select 0;
private _aftCellWeight     = [_heli] call fza_fnc_sfmplusSetFuel select 1;
private _totFuelCellWeight = _forwardCellWeight + _aftCellWeight;
_forwardCellWeight = _forwardCellWeight * KGTOLBS;
_aftCellWeight     = _aftCellWeight * KGTOLBS;
_totFuelCellWeight = _totFuelCellWeight * KGTOLBS;

private _enginesOn = if (isObjectRTD _heli && difficultyEnabledRTD && local _heli) then {
	private _engines = enginesIsOnRTD _heli;
	_engines resize 2;
	_engines apply {[_x, false] select isNil "_x"};
} else {
	[[false, false], [true, true]] select isEngineOn _heli;
};

private _fuelFlow = ([_heli] call fza_fnc_sfmplusGetData select 2) * 7936.64;

private _eng1FuelCons = 0;
private _eng1State    = ((_heli getVariable "fza_ah64_engineStates") select 0) select 0;
if (isEngineOn _heli && (_eng1State != "OFF")) then {
	_eng1FuelCons = _fuelFlow / 2;
};

private _eng2FuelCons = 0;
private _eng2State    = ((_heli getVariable "fza_ah64_engineStates") select 1) select 0;
if (isEngineOn _heli && (_eng2State != "OFF")) then {
	_eng2FuelCons = _fuelFlow / 2;
};

//private _engineFuelConsumption = _enginesOn apply {[0, (_fuelFlow / 2)] select _x};
//private _totalFuelConsumption  = _engineFuelConsumption # 0 + _engineFuelConsumption # 1;
private _totalFuelConsumption = _eng1FuelCons + _eng2FuelCons;

private _enduranceNumber = if(_totalFuelConsumption > 0) then {
	private _enduranceTotal = 540 min (_totFuelCellWeight / _totalFuelConsumption * 60); //Minutes
	private _enduranceMinutes = _enduranceTotal % 60;
	private _enduranceHours = floor(_enduranceTotal / 60);
	format["%1:%2", _enduranceHours toFixed 0, [_enduranceMinutes, 2] call CBA_fnc_formatNumber];
} else {"9:99"};

_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_FWD), _forwardCellWeight toFixed 0];
_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_AFT), _aftCellWeight toFixed 0];

_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_FLOW_1), _eng1FuelCons toFixed 0];
_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_FLOW_2), _eng2FuelCons toFixed 0];
_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_FLOW_TOT), _totalFuelConsumption toFixed 0];

_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_INT), _totFuelCellWeight toFixed 0];
_heli setUserMFDText [MFD_INDEX_OFFSET(MFD_TEXT_IND_FUEL_ENDR_INT), _enduranceNumber];