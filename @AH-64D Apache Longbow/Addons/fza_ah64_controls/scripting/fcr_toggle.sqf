_heli = _this select 0;

if (isVehicleRadarOn _heli && (isengineon _heli || fza_ah64_apuon == 1) && (typeof _heli == "fza_ah64d_b2e")) then
{
fza_ah64_fcrstate = fza_ah64_fcrstate + 1;
if (fza_ah64_fcrstate > 1) then {fza_ah64_fcrstate = 0;};
};
