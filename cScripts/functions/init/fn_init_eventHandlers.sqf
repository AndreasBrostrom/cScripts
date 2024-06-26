#include "..\script_component.hpp";
/*
 * Author: CPL.Brostrom.A
 * This function add eventhandlers.
 *
 * Example:
 * call cScripts_fnc_init_eventHandlers
 *
 * Public: No
 */

INFO("InitEventHandlers","Creating Global EventHandlers");

[QGVAR(getAttendance), {
    call FUNC(getAttendance);
}] call CBA_fnc_addEventHandler;


// Player Events
if (GVAR(isPlayer)) then {
    INFO("InitEventHandlers","Creating Client EventHandlers");

    // TODO: Possibly use in the future 
    //["ace_zeusCreated", {
    //    _this params ["_zeus"];
    //}] call CBA_fnc_addEventHandler;
    //
    //["zen_common_createZeus", {
    //    _this params ["_zeus"];
    //}] call CBA_fnc_addEventHandler;
};


// Server Events
if (!isServer) exitWith {};
INFO("InitEventHandlers","Creating Server EventHandlers");

addMissionEventHandler ["PlayerConnected", {
    params ["", "_uid", "_name"];

    private _playerLog = missionNamespace getVariable [QEGVAR(log,players), createHashMap];

    // Create map if none exist
    // Update connection
    
    missionNamespace setVariable [QEGVAR(log,players), _playerLog];
}];
addMissionEventHandler ["PlayerDisconnected", {
    params ["", "_uid", "_name"];
}];


[QEGVAR(log,text), {
    diag_log text _this;
}] call CBA_fnc_addEventHandler;
