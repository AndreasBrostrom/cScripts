#include "..\script_component.hpp";
/*
 * Author: CPL.Brostrom.A
 * This function handle all our custom chat commands
 *
 * Example:
 * call cScripts_fnc_init_ChatCommands
 *
 * Public: No
 */

["attendance", {
    [QGVAR(getAttendance)] call CBA_fnc_localEvent;
}, "all"] call CBA_fnc_registerChatCommand;

// Help and diagnostic commands
["cScripts", {

    private _args = (_this select 0) splitString " ";

    private _isAdmin = call EFUNC(player,isMissionAdmin);

    private _sys_err = {systemChat format["cScripts argument '%1' is not supported", _this];};
    private _sys_version = {systemChat format["cScripts version: %1", VERSION];};
    private _sys_diagnose = {
        private _players = (count allPlayers);

        systemChat format["MISSION DIAGNOSTICS START"];
        systemChat "---";
        
        private _fps = (round diag_fps);
        private _fpsMin = (round diag_fpsMin);
        private _upTime = (round (diag_tickTime/60));
        private _missionTime = (round (time/60));
        
        private _activeScripts = diag_activeScripts;
        private _spawn = _activeScripts#0;
        private _execVM = _activeScripts#1;
        private _exec = _activeScripts#2;
        private _execFSM = _activeScripts#3;
    
        systemChat "Client";
        systemChat format["Performance - FPS: %1 | FpsMin: %2 | Uptime: %3min | MissionTime: %4min",_fps,_fpsMin,_upTime,_missionTime];
        SHOW_INFO_4("DIAG Client","Performence - FPS: %1 | FpsMin: %2 | Uptime: %3min | MissionTime: %4min",_fps,_fpsMin,_upTime,_missionTime);
        systemChat format["Scripts - Spawn: %1 | execVM: %2 | Exec: %3 | execFSM: %4",_spawn,_execVM,_exec,_execFSM];
        SHOW_INFO_4("DIAG Client","Scripts - Spawn: %1 | execVM: %2 | Exec: %3min | execFSM: %4min",_spawn,_execVM,_exec,_execFSM);
        systemChat "---";
        
        systemChat "Server";
        [QEGVAR(diag,server)] call CBA_fnc_serverEvent;
        waitUntil { !(GETMVAR(diag_server,[]) isEqualTo []) };
        private _serverDiag = GETMVAR(diag_server,[]);
        systemChat format["Performance - FPS: %1 | FpsMin: %2 | Uptime: %3min | MissionTime: %4min",_serverDiag#0#0,_serverDiag#0#1,_serverDiag#0#2,_serverDiag#0#3];
        SHOW_INFO_4("DIAG Server","Performence - FPS: %1 | FpsMin: %2 | Uptime: %3min | MissionTime: %4min",_serverDiag#0#0,_serverDiag#0#1,_serverDiag#0#2,_serverDiag#0#3);
        systemChat format["Scripts - Spawn: %1 | execVM: %2 | Exec: %3 | execFSM: %4",_serverDiag#1#0,_serverDiag#1#1,_serverDiag#1#2,_serverDiag#1#3];
        SHOW_INFO_4("DIAG Server","Scripts - Spawn: %1 | execVM: %2 | Exec: %3min | execFSM: %4min",_serverDiag#1#0,_serverDiag#1#1,_serverDiag#1#2,_serverDiag#1#3);
        systemChat "---";
        SETMVAR(diag_server,[]);
        
        
        private _allObjects = player nearObjects 1000000;
        private _thingx = [];
        private _thingxSimple = [];
        private _thing = [];
        private _thingSimple = [];
        private _static = []; // Buildings
        private _vehicles = [];
        private _logics = [];
        private _other = [];
        {
            diag_log str (typeOf _x);
            if (_x isKindOf "ThingX") then {
                if (isSimpleObject _x || simulationEnabled _x) then {
                    _thingxSimple append [_x];
                } else {
                    _thingx append [_x];
                };
                continue;
            };
            if (_x isKindOf "Thing") then {_thing append [_x]; continue};
        
            if (_x isKindOf "Static") then {_static append [_x]; continue};
        
            if (_x isKindOf "LandVehicle") then {_vehicles append [_x]; continue};
            if (_x isKindOf "Ship") then {_vehicles append [_x]; continue};
            if (_x isKindOf "Air") then {_vehicles append [_x]; continue};
            
            if (_x isKindOf "Logic") then {_logics append [_x]; continue};
            _other append [_x];
        } forEach _allObjects;
        
        _allObjects = (count _allObjects);
        _thingx = (count _thingx);
        _thingxSimple = (count _thingxSimple);
        _thing = (count _thing);
        _thingSimple = (count _thingSimple);
        _static = (count _static);
        _vehicles = (count _vehicles);
        _logics = (count _logics);
        _other = (count _other);
        
        private _players = (count allPlayers);
        private _aliveUnits = ((count allUnits) - (count allPlayers));
        private _deadMen = ((count allDead) - (count allDeadMen));
        private _deadVehicles = ((count allDead) - (count allDeadMen));
        
        systemChat format["Players: %1", _players];
        SHOW_INFO_1("DIAG Objects","Players: %1 (Dead: %2)",_players);
        systemChat format["Units: %1",_aliveUnits];
        SHOW_INFO_2("DIAG Objects","Units: %1 (Dead: %2)",_aliveUnits, _deadMen);
        systemChat "---";
        
        systemChat format["Total items: %1",_allObjects];
        SHOW_INFO_1("DIAG Objects","Total items: %1",_allObjects);
        systemChat format["Vehicles: %1 (Killed: %2)",_vehicles,_deadVehicles];
        SHOW_INFO_2("DIAG Objects","Vehicles: %1 (Killed: %2)",_vehicles,_deadVehicles);
        systemChat format["Items thing: %1 (PF: %2) | thingX %3 (PF: %4)",_thingx,_thingxSimple,_thing,_thingSimple];
        SHOW_INFO_4("DIAG Objects","Items thing: %1 (PF: %2) | thingX %3 (PF: %4)",_thingx,_thingxSimple,_thing,_thingSimple);
        systemChat format["Other items: %1",_other];
        SHOW_INFO_1("DIAG Objects","Other items: %1",_other);
        systemChat "---";
        
        systemChat format["MISSION DIAGNOSTICS ENDED"];
    };

    if (_args#0 == "version") exitWith {call _sys_version};
    if (!_isAdmin && count _args >= 1) exitWith { _args#0 call _sys_err};
    if (!_isAdmin) exitWith {call _sys_version};

    switch (_args#0) do {
        case "diag";
        case "diagnose": {call _sys_diagnose};
        case "v";
        case "ver";
        case "version": {call _sys_version};
        default {_args#0 call _sys_err};
    };

}, "all"] call CBA_fnc_registerChatCommand;

["loadout", {
    private _name = [player] call EFUNC(gear,getLoadoutDisplayName);
    private _loadout = [player] call EFUNC(gear,getLoadoutName);
    systemChat format["Your current loadout is: %1 [%2]",_name,_loadout];
}, "all"] call CBA_fnc_registerChatCommand;
