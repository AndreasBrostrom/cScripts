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
    _this params ["_playerName"];
    private _playerLog = missionNamespace getVariable [QEGVAR(log,players), []];
    _playerLog pushBack _playerName;
    missionNamespace setVariable [QEGVAR(log,players), _playerLog];
}] call CBA_fnc_addEventHandler;


[QEGVAR(diag,server), {
    SHOW_INFO("DIAG","Server told to send diagnostics");
    private _fps = (round diag_fps);
    private _fpsMin = (round diag_fpsMin);
    private _upTime = (round (diag_tickTime/60));
    private _missionTime = (round (time/60));

    private _performance = [_fps,_fpsMin,_upTime,_missionTime];
    
    private _activeScripts = diag_activeScripts;
    private _spawn = _activeScripts#0;
    private _execVM = _activeScripts#1;
    private _exec = _activeScripts#2;
    private _execFSM = _activeScripts#3;

    private _scripts = [_spawn,_execVM,_exec,_execFSM];
    
    SETMVAR(EGVAR(diag,server_data),[_performance,_scripts]);
}] call CBA_fnc_addEventHandler;