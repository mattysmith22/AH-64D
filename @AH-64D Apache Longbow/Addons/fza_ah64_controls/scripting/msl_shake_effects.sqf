private["_heli"];
_heli = _this select 0;
_selWeapon = currentWeapon _heli;

_hellfireweps = ["fza_agm114_23_8", "fza_agm114_14_8", "fza_agm114_1_4", "fza_agm114_2_4", "fza_agm114_3_4", "fza_agm114_4_4", "fza_agm114_1_ul", "fza_agm114_1_ur", "fza_agm114_1_ll", "fza_agm114_1_lr", "fza_agm114_2_ul", "fza_agm114_2_ur", "fza_agm114_2_ll", "fza_agm114_2_lr", "fza_agm114_3_ul", "fza_agm114_3_ur", "fza_agm114_3_ll", "fza_agm114_3_lr", "fza_agm114_4_ul", "fza_agm114_4_ur", "fza_agm114_4_ll", "fza_agm114_4_lr", "fza_atas_2"];
_rocketweps = ["fza_m261_1234_zoneE", "fza_m261_14", "fza_m261_14_zoneA", "fza_m261_14_zoneB", "fza_m261_14_zoneE", "fza_m261_23", "fza_m261_23_zoneC", "fza_m261_23_zoneD", "fza_m261_23_zoneE", "fza_m261_1", "fza_m261_1_zone1", "fza_m261_1_zone2", "fza_m261_1_zone3", "fza_m261_2", "fza_m261_2_zone1", "fza_m261_2_zone2", "fza_m261_2_zone3", "fza_m261_3", "fza_m261_3_zone1", "fza_m261_3_zone2", "fza_m261_3_zone3", "fza_m261_4", "fza_m261_4_zone1", "fza_m261_4_zone2", "fza_m261_4_zone3"];

// RKT + MSL SHAKE
if ((player == driver _heli || player == gunner _heli) && (_selWeapon in _hellfireweps || _selWeapon in _rocketweps))
    then 
	{
        private addCamShake [0.40, 0.5, 25];
    };