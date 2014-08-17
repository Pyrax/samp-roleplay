#if defined _ANIMATIONS_INCLUDED
    #endinput
#endif
#define _ANIMATIONS_INCLUDED

//-----------------------------------------------------

PreloadAnimations(playerid) {
    PreloadAnimLib(playerid, "BOMBER");
    PreloadAnimLib(playerid, "RAPPING");
    PreloadAnimLib(playerid, "SHOP");
    PreloadAnimLib(playerid, "BEACH");
    PreloadAnimLib(playerid, "SMOKING");
    PreloadAnimLib(playerid, "FOOD");
    PreloadAnimLib(playerid, "ON_LOOKERS");
    PreloadAnimLib(playerid, "DEALER");
    PreloadAnimLib(playerid, "CRACK");
    PreloadAnimLib(playerid, "CARRY");
    PreloadAnimLib(playerid, "COP_AMBIENT");
    PreloadAnimLib(playerid, "PARK");
    PreloadAnimLib(playerid, "INT_HOUSE");
    PreloadAnimLib(playerid, "FOOD");
    PreloadAnimLib(playerid, "PED");
}

PreloadAnimLib(playerid, animlib[]) {
    ApplyAnimation(playerid, animlib, "null", 0.0, 0, 0, 0, 0, 0);
}