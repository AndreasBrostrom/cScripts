//#include "\x\cba addons\main\script_macros_common.hpp"
//#include "\x\cba\addons\main\script_macros_mission.hpp"

#define QUOTE(var) #var
#define DOUBLES(var1,var2) ##var1##_##var2
#define TRIPLES(var1,var2,var3) ##var1##_##var2##_##var3

#define ARR_1(ARG1) ARG1
#define ARR_2(ARG1,ARG2) ARG1, ARG2
#define ARR_3(ARG1,ARG2,ARG3) ARG1, ARG2, ARG3
#define ARR_4(ARG1,ARG2,ARG3,ARG4) ARG1, ARG2, ARG3, ARG4
#define ARR_5(ARG1,ARG2,ARG3,ARG4,ARG5) ARG1, ARG2, ARG3, ARG4, ARG5
#define ARR_6(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6
#define ARR_7(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7
#define ARR_8(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8

#define GVAR(var1) DOUBLES(PREFIX,var1)
#define EGVAR(var1,var2) TRIPLES(PREFIX,var1,var2)
#define QGVAR(var1) QUOTE(GVAR(var1))
#define QEGVAR(var1,var2) QUOTE(EGVAR(var1,var2))
#define QQGVAR(var1) QUOTE(QGVAR(var1))
#define QQEGVAR(var1,var2) QUOTE(QEGVAR(var1,var2))

#define FUNC(var) TRIPLES(PREFIX,fnc,var)
#define EFUNC(var1,var2) FUNC(DOUBLES(var1,var2))
#define QFUNC(var) QUOTE(FUNC(var))
#define QEFUNC(var1,var2) QUOTE(EFUNC(var1,var2))

#define GETVAR_SYS(var1,var2) getVariable [ARR_2(QUOTE(var1),var2)]
#define SETVAR_SYS(var1,var2) setVariable [ARR_2(QUOTE(var1),var2)]
#define SETPVAR_SYS(var1,var2) setVariable [ARR_3(QUOTE(var1),var2,true)]

#define GETVAR(var1,var2,var3) (var1 GETVAR_SYS(var2,var3))
#define GETMVAR(var1,var2) (missionNamespace GETVAR_SYS(var1,var2))
#define GETUVAR(var1,var2) (uiNamespace GETVAR_SYS(var1,var2))
#define GETPRVAR(var1,var2) (profileNamespace GETVAR_SYS(var1,var2))
#define GETPAVAR(var1,var2) (parsingNamespace GETVAR_SYS(var1,var2))

#define SETVAR(var1,var2,var3) var1 SETVAR_SYS(var2,var3)
#define SETPVAR(var1,var2,var3) var1 SETPVAR_SYS(var2,var3)
#define SETMVAR(var1,var2) missionNamespace SETVAR_SYS(var1,var2)
#define SETUVAR(var1,var2) uiNamespace SETVAR_SYS(var1,var2)
#define SETPRVAR(var1,var2) profileNamespace SETVAR_SYS(var1,var2)
#define SETPAVAR(var1,var2) parsingNamespace SETVAR_SYS(var1,var2)

#define GETGVAR(var1,var2) GETMVAR(GVAR(var1),var2) // FIXME: REMOVE?
#define GETEGVAR(var1,var2,var3) GETMVAR(EGVAR(var1,var2),var3) // FIXME: REMOVE?

#define FORMAT_1(STR,ARG1) format[STR, ARG1]
#define FORMAT_2(STR,ARG1,ARG2) format[STR, ARG1, ARG2]
#define FORMAT_3(STR,ARG1,ARG2,ARG3) format[STR, ARG1, ARG2, ARG3]
#define FORMAT_4(STR,ARG1,ARG2,ARG3,ARG4) format[STR, ARG1, ARG2, ARG3, ARG4]
#define FORMAT_5(STR,ARG1,ARG2,ARG3,ARG4,ARG5) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5]
#define FORMAT_6(STR,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6]
#define FORMAT_7(STR,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7]
#define FORMAT_8(STR,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) format[STR, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8]

/* Logistics macros */
#define GET_CONTAINER(BOX) [QUOTE(BOX)] call EFUNC(logistics,getContainer)
#define GET_CONTAINER_KEYS(BOX) [QUOTE(BOX),true] call EFUNC(logistics,getContainer)


/* LOGGING */
#define LOG_SYS(COMPONANT,MESSAGE,CHAT,SERVER) [MESSAGE,COMPONANT,CHAT,SERVER] call FUNC(log)
#define INFO_SYS(COMPONANT,MESSAGE,CHAT,SERVER) [MESSAGE,COMPONANT,CHAT,SERVER] call FUNC(info)
#define ERROR_SYS(COMPONANT,MESSAGE,CHAT,SERVER) [MESSAGE,COMPONANT,CHAT,SERVER] call FUNC(error)
#define WARNING_SYS(COMPONANT,MESSAGE,CHAT,SERVER) [MESSAGE,COMPONANT,CHAT,SERVER] call FUNC(warning)


/* DEBUG LOG LOGGING */
#ifdef DEBUG_MODE
#define LOG(COMPONANT,MESSAGE) LOG_SYS(COMPONANT,MESSAGE,false,false)
#define LOG_1(COMPONANT,MESSAGE,ARG1) LOG(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define LOG_2(COMPONANT,MESSAGE,ARG1,ARG2) LOG(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define LOG_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) LOG(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define LOG_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) LOG(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define LOG_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) LOG(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define LOG_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) LOG(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define LOG_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define LOG_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) LOG(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#else

#define LOG(COMPONANT,MESSAGE) /* disabled */
#define LOG_1(COMPONANT,MESSAGE,ARG1) /* disabled */
#define LOG_2(COMPONANT,MESSAGE,ARG1,ARG2) /* disabled */
#define LOG_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) /* disabled */
#define LOG_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) /* disabled */
#define LOG_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) /* disabled */
#define LOG_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) /* disabled */
#define LOG_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) /* disabled */
#define LOG_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) /* disabled */

#endif

/* DEBUG INFO LOGGING */
#ifdef DEBUG_MODE

#define INFO(COMPONANT,MESSAGE) INFO_SYS(COMPONANT,MESSAGE,false,false)
#define INFO_1(COMPONANT,MESSAGE,ARG1) INFO(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define INFO_2(COMPONANT,MESSAGE,ARG1,ARG2) INFO(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define INFO_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) INFO(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define INFO_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) INFO(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define INFO_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) INFO(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define INFO_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) INFO(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define INFO_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) INFO(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define INFO_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) INFO(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#else

#define INFO(COMPONANT,MESSAGE) /* disabled */
#define INFO_1(COMPONANT,MESSAGE,ARG1) /* disabled */
#define INFO_2(COMPONANT,MESSAGE,ARG1,ARG2) /* disabled */
#define INFO_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) /* disabled */
#define INFO_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) /* disabled */
#define INFO_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) /* disabled */
#define INFO_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) /* disabled */
#define INFO_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) /* disabled */
#define INFO_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) /* disabled */

#endif

/* DEBUG WARNING LOGGING */
#ifdef DEBUG_MODE

#define WARNING(COMPONANT,MESSAGE) WARNING_SYS(COMPONANT,MESSAGE,false,false)
#define WARNING_1(COMPONANT,MESSAGE,ARG1) WARNING(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define WARNING_2(COMPONANT,MESSAGE,ARG1,ARG2) WARNING(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define WARNING_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) WARNING(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define WARNING_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) WARNING(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define WARNING_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) WARNING(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define WARNING_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) WARNING(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define WARNING_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) WARNING(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define WARNING_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) WARNING(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#else

#define WARNING(COMPONANT,MESSAGE) /* disabled */
#define WARNING_1(COMPONANT,MESSAGE,ARG1) /* disabled */
#define WARNING_2(COMPONANT,MESSAGE,ARG1,ARG2) /* disabled */
#define WARNING_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) /* disabled */
#define WARNING_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) /* disabled */
#define WARNING_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) /* disabled */
#define WARNING_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) /* disabled */
#define WARNING_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) /* disabled */
#define WARNING_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) /* disabled */

#endif

/* DEBUG ERROR LOGGING */
#ifdef DEBUG_MODE

#define ERROR(COMPONANT,MESSAGE) ERROR_SYS(COMPONANT,MESSAGE,false,false)
#define ERROR_1(COMPONANT,MESSAGE,ARG1) ERROR(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define ERROR_2(COMPONANT,MESSAGE,ARG1,ARG2) ERROR(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define ERROR_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) ERROR(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define ERROR_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) ERROR(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define ERROR_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) ERROR(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define ERROR_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ERROR(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define ERROR_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ERROR(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define ERROR_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ERROR(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#else

#define ERROR(COMPONANT,MESSAGE) /* disabled */
#define ERROR_1(COMPONANT,MESSAGE,ARG1) /* disabled */
#define ERROR_2(COMPONANT,MESSAGE,ARG1,ARG2) /* disabled */
#define ERROR_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) /* disabled */
#define ERROR_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) /* disabled */
#define ERROR_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) /* disabled */
#define ERROR_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) /* disabled */
#define ERROR_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) /* disabled */
#define ERROR_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) /* disabled */

#endif

/* VISABLE LOGS */
#define SHOW_LOG(COMPONANT,MESSAGE) LOG_SYS(COMPONANT,MESSAGE,false,false)
#define SHOW_LOG_1(COMPONANT,MESSAGE,ARG1) LOG(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_LOG_2(COMPONANT,MESSAGE,ARG1,ARG2) LOG(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_LOG_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) LOG(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_LOG_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) LOG(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_LOG_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) LOG(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_LOG_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) LOG(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_LOG_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_LOG_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) LOG(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_INFO(COMPONANT,MESSAGE) INFO_SYS(COMPONANT,MESSAGE,false,false)
#define SHOW_INFO_1(COMPONANT,MESSAGE,ARG1) INFO(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_INFO_2(COMPONANT,MESSAGE,ARG1,ARG2) INFO(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_INFO_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) INFO(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_INFO_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) INFO(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_INFO_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) INFO(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_INFO_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) INFO(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_INFO_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) INFO(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_INFO_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) INFO(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_WARNING(COMPONANT,MESSAGE) WARNING_SYS(COMPONANT,MESSAGE,false,false)
#define SHOW_WARNING_1(COMPONANT,MESSAGE,ARG1) WARNING(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_WARNING_2(COMPONANT,MESSAGE,ARG1,ARG2) WARNING(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_WARNING_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) WARNING(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_WARNING_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) WARNING(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_WARNING_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) WARNING(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_WARNING_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) WARNING(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_WARNING_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) WARNING(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_WARNING_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) WARNING(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_ERROR(COMPONANT,MESSAGE) ERROR_SYS(COMPONANT,MESSAGE,true,false)
#define SHOW_ERROR_1(COMPONANT,MESSAGE,ARG1) ERROR(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_ERROR_2(COMPONANT,MESSAGE,ARG1,ARG2) ERROR(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_ERROR_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) ERROR(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_ERROR_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) ERROR(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_ERROR_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) ERROR(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_ERROR_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ERROR(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_ERROR_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ERROR(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_ERROR_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ERROR(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

/* SHOW CHAT LOG */
#define SHOW_CHAT_LOG(COMPONANT,MESSAGE) LOG_SYS(COMPONANT,MESSAGE,true,false)
#define SHOW_CHAT_LOG_1(COMPONANT,MESSAGE,ARG1) LOG(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_LOG_2(COMPONANT,MESSAGE,ARG1,ARG2) LOG(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_LOG_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) LOG(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_LOG_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) LOG(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_LOG_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) LOG(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_LOG_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) LOG(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_LOG_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_LOG_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) LOG(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_CHAT_INFO(COMPONANT,MESSAGE) INFO_SYS(COMPONANT,MESSAGE,true,false)
#define SHOW_CHAT_INFO_1(COMPONANT,MESSAGE,ARG1) INFO(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_INFO_2(COMPONANT,MESSAGE,ARG1,ARG2) INFO(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_INFO_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) INFO(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_INFO_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) INFO(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_INFO_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) INFO(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_INFO_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) INFO(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_INFO_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) INFO(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_INFO_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) INFO(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_CHAT_WARNING(COMPONANT,MESSAGE) WARNING_SYS(COMPONANT,MESSAGE,true,false)
#define SHOW_CHAT_WARNING_1(COMPONANT,MESSAGE,ARG1) WARNING(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_WARNING_2(COMPONANT,MESSAGE,ARG1,ARG2) WARNING(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_WARNING_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) WARNING(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_WARNING_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) WARNING(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_WARNING_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) WARNING(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_WARNING_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) WARNING(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_WARNING_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) WARNING(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_WARNING_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) WARNING(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_CHAT_ERROR(COMPONANT,MESSAGE) ERROR_SYS(COMPONANT,MESSAGE,true,false)
#define SHOW_CHAT_ERROR_1(COMPONANT,MESSAGE,ARG1) ERROR(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_ERROR_2(COMPONANT,MESSAGE,ARG1,ARG2) ERROR(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_ERROR_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) ERROR(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_ERROR_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) ERROR(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_ERROR_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) ERROR(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_ERROR_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ERROR(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_ERROR_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ERROR(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_ERROR_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ERROR(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

/* SHOW CHAT SERVER LOG*/
#define SHOW_CHAT_SERVER_LOG(COMPONANT,MESSAGE) LOG_SYS(COMPONANT,MESSAGE,true,true)
#define SHOW_CHAT_SERVER_LOG_1(COMPONANT,MESSAGE,ARG1) LOG(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_SERVER_LOG_2(COMPONANT,MESSAGE,ARG1,ARG2) LOG(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_SERVER_LOG_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) LOG(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_SERVER_LOG_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) LOG(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_SERVER_LOG_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) LOG(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_SERVER_LOG_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) LOG(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_SERVER_LOG_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_SERVER_LOG_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) LOG(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_CHAT_SERVER_INFO(COMPONANT,MESSAGE) INFO_SYS(COMPONANT,MESSAGE,true,true)
#define SHOW_CHAT_SERVER_INFO_1(COMPONANT,MESSAGE,ARG1) INFO(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_SERVER_INFO_2(COMPONANT,MESSAGE,ARG1,ARG2) INFO(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_SERVER_INFO_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) INFO(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_SERVER_INFO_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) INFO(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_SERVER_INFO_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) INFO(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_SERVER_INFO_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) INFO(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_SERVER_INFO_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) INFO(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_SERVER_INFO_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) INFO(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_CHAT_SERVER_WARNING(COMPONANT,MESSAGE) WARNING_SYS(COMPONANT,MESSAGE,true,true)
#define SHOW_CHAT_SERVER_WARNING_1(COMPONANT,MESSAGE,ARG1) WARNING(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_SERVER_WARNING_2(COMPONANT,MESSAGE,ARG1,ARG2) WARNING(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_SERVER_WARNING_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) WARNING(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_SERVER_WARNING_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) WARNING(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_SERVER_WARNING_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) WARNING(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_SERVER_WARNING_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) WARNING(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_SERVER_WARNING_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) WARNING(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_SERVER_WARNING_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) WARNING(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_CHAT_SERVER_ERROR(COMPONANT,MESSAGE) ERROR_SYS(COMPONANT,MESSAGE,true,true)
#define SHOW_CHAT_SERVER_ERROR_1(COMPONANT,MESSAGE,ARG1) ERROR(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_CHAT_SERVER_ERROR_2(COMPONANT,MESSAGE,ARG1,ARG2) ERROR(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_CHAT_SERVER_ERROR_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) ERROR(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_CHAT_SERVER_ERROR_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) ERROR(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_CHAT_SERVER_ERROR_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) ERROR(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_CHAT_SERVER_ERROR_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ERROR(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_CHAT_SERVER_ERROR_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ERROR(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_CHAT_SERVER_ERROR_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ERROR(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))


/* SHOW SERVER LOG*/
#define SHOW_SERVER_LOG(COMPONANT,MESSAGE) LOG_SYS(COMPONANT,MESSAGE,false,true)
#define SHOW_SERVER_LOG_1(COMPONANT,MESSAGE,ARG1) LOG(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_SERVER_LOG_2(COMPONANT,MESSAGE,ARG1,ARG2) LOG(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_SERVER_LOG_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) LOG(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_SERVER_LOG_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) LOG(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_SERVER_LOG_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) LOG(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_SERVER_LOG_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) LOG(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_SERVER_LOG_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) LOG(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_SERVER_LOG_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) LOG(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_SERVER_INFO(COMPONANT,MESSAGE) INFO_SYS(COMPONANT,MESSAGE,false,true)
#define SHOW_SERVER_INFO_1(COMPONANT,MESSAGE,ARG1) INFO(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_SERVER_INFO_2(COMPONANT,MESSAGE,ARG1,ARG2) INFO(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_SERVER_INFO_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) INFO(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_SERVER_INFO_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) INFO(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_SERVER_INFO_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) INFO(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_SERVER_INFO_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) INFO(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_SERVER_INFO_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) INFO(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_SERVER_INFO_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) INFO(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_SERVER_WARNING(COMPONANT,MESSAGE) WARNING_SYS(COMPONANT,MESSAGE,false,true)
#define SHOW_SERVER_WARNING_1(COMPONANT,MESSAGE,ARG1) WARNING(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_SERVER_WARNING_2(COMPONANT,MESSAGE,ARG1,ARG2) WARNING(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_SERVER_WARNING_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) WARNING(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_SERVER_WARNING_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) WARNING(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_SERVER_WARNING_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) WARNING(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_SERVER_WARNING_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) WARNING(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_SERVER_WARNING_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) WARNING(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_SERVER_WARNING_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) WARNING(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))

#define SHOW_SERVER_ERROR(COMPONANT,MESSAGE) ERROR_SYS(COMPONANT,MESSAGE,false,true)
#define SHOW_SERVER_ERROR_1(COMPONANT,MESSAGE,ARG1) ERROR(COMPONANT,FORMAT_1(MESSAGE,ARG1))
#define SHOW_SERVER_ERROR_2(COMPONANT,MESSAGE,ARG1,ARG2) ERROR(COMPONANT,FORMAT_2(MESSAGE,ARG1,ARG2))
#define SHOW_SERVER_ERROR_3(COMPONANT,MESSAGE,ARG1,ARG2,ARG3) ERROR(COMPONANT,FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define SHOW_SERVER_ERROR_4(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4) ERROR(COMPONANT,FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define SHOW_SERVER_ERROR_5(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) ERROR(COMPONANT,FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#define SHOW_SERVER_ERROR_6(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) ERROR(COMPONANT,FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
#define SHOW_SERVER_ERROR_7(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) ERROR(COMPONANT,FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
#define SHOW_SERVER_ERROR_8(COMPONANT,MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) ERROR(COMPONANT,FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
