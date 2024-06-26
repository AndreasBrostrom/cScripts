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

[QEGVAR(log,text), {
    diag_log text _this;
}] call CBA_fnc_addEventHandler;

[QEGVAR(log,player), {
    _this params ["_player"];
    private _playerLog = missionNamespace getVariable [QEGVAR(log,players), createHashMap];

    private _data = createHashMapFromArray [
        ["name", name player],
        ["connection", systemTimeUTC],
        ["disconnect", []],
        ["loadout", typeOf player],
    ];
    private _map = createHashMapFromArray [[getPlayerUID _player, _data]];
    
    _playerLog set _map;
    missionNamespace setVariable [QEGVAR(log,players), _playerLog];
}] call CBA_fnc_addEventHandler;