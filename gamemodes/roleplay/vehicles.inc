#if defined _INCLUDED_VEHICLES
    #endinput
#endif
#define _INCLUDED_VEHICLES

//-----------------------------------------------------

LockVehicle(vehicleid) {
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, engine, lights, alarm, 1, bonnet, boot, objective);
}

UnlockVehicle(vehicleid) {
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, engine, lights, alarm, 0, bonnet, boot, objective);
}

LockVehicleForPlayer(vehicleid, forplayerid) {
    SetVehicleParamsForPlayer(vehicleid, forplayerid, 0, 1);
}

UnlockVehicleForPlayer(vehicleid, forplayerid) {
    SetVehicleParamsForPlayer(vehicleid, forplayerid, 0, 0);
}

EnableVehicleAlarm(vehicleid) {
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, engine, lights, true, doors, bonnet, boot, objective);
}

function DisableVehicleAlarm(vehicleid) {
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(vehicleid, engine, lights, false, doors, bonnet, boot, objective);
}