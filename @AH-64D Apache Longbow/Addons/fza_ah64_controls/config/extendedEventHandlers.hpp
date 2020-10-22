class Extended_PreInit_EventHandlers {
	class fza_ah64_PreInits {
		init = "call compile preprocessFileLineNumbers 'fza_ah64_controls\scripting\XEH_preInit.sqf';";
		clientInit = "call compile preprocessFileLineNumbers 'fza_ah64_controls\scripting\XEH_clientInit.sqf';";
	};
};

class Extended_Init_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_init_eh {
			init = "[_this select 0] execvm ""\fza_ah64_controls\scripting\ah64d_init.sqf"";";
		};
	};
};

class Extended_Engine_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_engine_eh {
			engine = "_this call fza_fnc_engineEventHandler;";
		};
	};
};

class Extended_FiredBIS_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_fired_eh {
			firedBIS = "_this call fza_fnc_eventFired; _this call fza_fnc_fxMuzzle; _this call fza_fnc_weaponHellfireAlign; _this call fza_fnc_weaponRocketAlign";
		};
	};
};

class Extended_GetIn_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_getin_eh {
			getIn = "_this call fza_fnc_eventGetIn;";
		};
	};
};

class Extended_GetOut_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_getout_eh {
			getOut = "_this call fza_fnc_eventGetOut;";
		};
	};
};

class Extended_IncomingMissile_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_incomingMissile_eh {
			incomingMissile = "_this execvm ""\fza_ah64_controls\ecm\CMSmk2.sqf""";
		};
	};
};

class Extended_handleDamage_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_handleDamage_eh {
			handleDamage = "if(alive (_this select 0) && !(surfaceiswater [getposasl (_this select 0) select 0,getposasl (_this select 0) select 1] && getpos (_this select 0)  select 2 < 0)) then {_this call fza_fnc_damageSystem;}; if(alive (_this select 0)) then {_this select 2};";
		};
	};
};

class Extended_Killed_EventHandlers {
	class fza_ah64base {
		class fza_ah64base_killed_eh {
			killed = "_this call BIS_Effects_EH_Killed;";
		};
	};
};