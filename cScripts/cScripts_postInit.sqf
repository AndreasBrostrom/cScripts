#include "script_component.hpp";
/*
 * Author: CPL.Brostrom.A
 * This is the rules set for the mission using the cba XEH. Each setting here is alterd via cbaSettings
 */
if (is3DEN) exitWith {};

INFO("postInit", "Initializing...");

// Initialises player data
[true] call EFUNC(player,setData)

// Change inventory content of supply crates on mission start.
call EFUNC(init,vehicle);

// item replacement
if (EGVAR(Settings,allowReplaceItem)) then {
    call EFUNC(init,aceItemReplace);
};

// staging
call EFUNC(init,staging);

// messages 
call EFUNC(init,message);

// diary records
if (EGVAR(Settings,showDiaryRecords)) then {
    call EFUNC(init,diary);
};

onPlayerConnected { 
    [QEGVAR(log,player), [name player]] call CBA_fnc_serverEvent;
};

INFO("postInit", "Initialization completed.");
