[
	"fza_ah64_showPopup",
	"CHECKBOX",
	["Show Popup Intro", "Show popup when the player gets into an Apache"],
	["AH-64D Official Project", "UI"],
	true
] call CBA_fnc_addSetting;

[
	"fza_ah64_headTrackAllowCursorMove",
	"CHECKBOX",
	"Allow cursor movement while in head tracking mode",
	["AH-64D Official Project", "Control"],
	[true],
	0
] call CBA_fnc_addSetting;

[
	"fza_ah64_headTrackSensitivity",
	"SLIDER",
	"Head tracking mode cursor sensitivity",
	["AH-64D Official Project", "Control"],
	[0, 1, 0.5, 2],
	0
] call CBA_fnc_addSetting;

[
	"fza_ah64_enableClickHelper",
	"CHECKBOX",
	"Enable cockpit hints",
	["AH-64D Official Project", "UI"],
	[true]
] call CBA_fnc_addSetting;

[
	"fza_ah64_vanillaTargetingEnable",
	"CHECKBOX",
	"Show vanilla targeting information (restart needed)",
	["AH-64D Official Project", "UI"],
	[true],
	0,
	{
		profileNamespace setVariable ["fza_ah64_enableTargeting", [0, 1] select _this];
		saveProfileNamespace;
	}
] call CBA_fnc_addSetting;

[
	"fza_ah64_sfmPlusStabilatorEnabled",
	"CHECKBOX",
	["Enable stabilator"],
	["AH-64D Official Project", "Flight model"],
	[true],
	0
] call CBA_fnc_addSetting;

fza_ah64_rocketTable =
        [[0, 5]
        ,[500, 8]
        ,[750, 12]
        ,[1000, 15]
        ,[2000, 28]
        ,[3500, 75]
        ,[4500, 120]];
fza_ah64_weaponDebug = false;
fza_ah64_pylonsLastCheckMags = [];
fza_ah64_mousehorpos = 0.5;
fza_ah64_mousevertpos = 0.5;
fza_ah64_gunheat = 0;
fza_ah64_firekeypressed = 0;
fza_ah64_overallticker = 0;
fza_ah64_locktargstate = 0;
fza_ah64_irjammer = 0;
fza_ah64_rfjammer = 0;
fza_ah64_salvofired = 0;
fza_ah64_mynum = 0;
fza_ah64_lastdir = 0;
fza_ah64_dps = 0;
fza_ah64_slip = 0;
fza_ah64_wptimhr = 0;
fza_ah64_wptim = 0;
fza_ah64_tiron = false;
fza_ah64_wptimtm = 0;
fza_ah64_wptimsm = 0;
fza_ah64_wpdistr = 0;
fza_ah64_targetlist = [];
fza_ah64_mycurrenttarget = objNull;
fza_ah64_tadsLockCheckRunning = false;
fza_ah64_burst = 1;
fza_ah64_pfzcache = ["none", "none", [], 0];
fza_ah64_asethreats = [];
fza_ah64_asethreatsdraw = [];
fza_ah64_threattracking = [];
fza_ah64_threatfiring = [];
fza_ah64_mycurrenttarget = objNull;
fza_ah64_fcrlist = [];
fza_ah64_tsdmap = 0;
fza_ah64_dispfcrlist = [];
fza_ah64_Cscopelist = [];
fza_ah64_hducolor = [0.1, 1, 0, 1];
fza_ah64_schedarray = [fza_fnc_weaponTurretAim, fza_fnc_targetingPNVSControl, fza_fnc_targetingSched, fza_fnc_avionicsSlipIndicator, fza_fnc_navigationWaypointEta, fza_fnc_ihadssDraw, fza_fnc_targetingUpdate, fza_fnc_engineGovernor, fza_fnc_mpdUpdateDisplays, fza_fnc_sfmplusUpdate];
fza_ah64_introShownThisScenario = false;
fza_ah64_slowschedarray = [fza_fnc_targetingUpdate, fza_fnc_weaponPylonCheckValid];
fza_ah64_mapfaker = addMissionEventHandler["Draw3d", {
	[0] call fza_fnc_coreScheduler;
}];
[0] spawn fza_fnc_ufd;