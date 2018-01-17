//  S 3   I N S T R U C T O R S   A N D   S T U D E N T S

// SCHOOL OF INFANTRY

class CAV_SOI_INSTR : CAV_Charlie_Base {  // Instructor

    uniform[] = {"LOP_U_ISTS_Fatigue_19"};
    headgear[] = {"DAR_Beret_Mar"};
    goggles[] = {""};
    vest[] = {"V_TacVest_khk"};
    backpack[] = {"tf_rt1523g_rhs"};
    binoculars[] = {"ACE_Vector"};

    magazines[] = {
        "rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",6,

        "rhs_mag_m67",2,

        "SmokeShell",2,
        "SmokeShellBlue",1,
        "SmokeShellGreen",1,
        "SmokeShellRed",1,
        "SmokeShellYellow",1
    };

    items[] = {

        // Standard
        "ACE_EarPlugs",
        "ACE_MapTools",
        "ACE_CableTie",
        "H_Cap_tan_specops_US",

        // Electronics
        "ACE_microDAGR",
        "ACE_HuntIR_monitor",

        // Tools
        "ACE_SpraypaintRed",
        "ACE_EntrenchingTool"
    };

    gps[] = {"ItemAndroid"};

    insignia[] = {"Follow_Me"};

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

class CAV_JM_INSTR : CAV_Charlie_Base {  // Instructor

    uniform[] = {"LOP_U_ISTS_Fatigue_19"};
    headgear[] = {"DAR_JMCap_Blk"};
    goggles[] = {""};
    vest[] = {"V_TacVest_khk"};
    backpack[] = {"tf_rt1523g_rhs"};
    binoculars[] = {"ACE_Vector"};

    magazines[] = {
        "rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",6,

        "rhs_mag_m67",2,

        "SmokeShell",2,
        "SmokeShellBlue",1,
        "SmokeShellGreen",1,
        "SmokeShellRed",1,
        "SmokeShellYellow",1
    };

    items[] = {

        // Standard
        "ACE_EarPlugs",
        "ACE_MapTools",
        "ACE_CableTie",
        "H_Cap_tan_specops_US",

        // Electronics
        "ACE_microDAGR",
        "ACE_HuntIR_monitor",

        // Tools
        "ACE_SpraypaintRed",
        "ACE_EntrenchingTool"
    };

    gps[] = {"ItemAndroid"};

    insignia[] = {"CAG"};

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

class CAV_SOI_STUD : CAV_Bravo_Base {  // Rifleman

    backpack[] = {"B_AssaultPack_mcamo"};
    vest[] = {"rhsusf_iotv_ocp_Rifleman"};

    magazines[] = {
        "rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",10,

        "rhs_mag_m67",6,

        "SmokeShell",6,

        "rhs_200rnd_556x45_M_SAW",2
    };

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

// THE ARMOR SCHOOL

class CAV_TAS_INSTR : CAV_Bravo_Base {  // Instructor

    headgear[] = {"H_Cap_usblack"};
    goggles[] = {"rhsusf_shemagh_od"};
    vest[] = {"rhsusf_iotv_ocp_Repair"};
    backpack[] = {"tf_rt1523g_big_rhs"};
    binoculars[] = {"ACE_Vector"};

    primary[] = {"rhs_weap_m4a1_m320","rhsusf_acc_anpeq15side","rhsusf_acc_compm4"};

    secondary[] = {"rhsusf_weap_m9"};

    magazines[] = {
        "rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",6,
        "rhsusf_mag_15Rnd_9x19_JHP",4,

        "rhs_mag_m714_White",
        "rhs_mag_m713_Red",
        "rhs_mag_m715_Green",
        "rhs_mag_m662_red",
        "rhs_mag_m661_green",

        "rhs_mag_m67",2,

        "SmokeShell",2,
        "SmokeShellBlue",1,
        "SmokeShellYellow",1
    };

    items[] = {
        // Personal Medical Equipment
        "ACE_quikclot",6,
        "ACE_tourniquet",2,

        // Standard
        "ACE_EarPlugs",
        "ACE_MapTools",
        "ACE_CableTie",
        "ToolKit",

        // Electronics
        "ACE_microDAGR"
    };

    gps[] = {"ItemAndroid"};

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

class CAV_TAS_STUD : CAV_Bravo_Base {  // Crewman
    headgear[] = {"rhsusf_cvc_green_helmet"};
    goggles[] = {"rhsusf_shemagh_gogg_tan"};
    vest[] = {"rhsusf_iotv_ocp_Repair"};
    backpack[] = {"B_AssaultPack_mcamo"};

    primary[] = {"rhs_weap_m4a1_carryhandle","rhsusf_acc_anpeq15side","rhsusf_acc_compm4"};

    magazines[] = {
        "rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",6,

        "rhs_mag_m67",2,

        "SmokeShell",2,
        "SmokeShellBlue",1,
        "SmokeShellYellow",1
    };

    items[] = {
        // Personal Medical Equipment
        "ACE_quikclot",10,
        "ACE_tourniquet",2,

        // Standard
        "ACE_EarPlugs",
        "ACE_MapTools",
        "ACE_CableTie",
        "ToolKit",

        // Electronics
        "ACE_microDAGR"
    };

    gps[] = {"ItemAndroid"};

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

// AVIATION CENTER OF EXCELLENCE

class CAV_ACE_ROTARY_INSTR : CAV_Alpha_Base {  // Rotary Instructor Pilots

    goggles[] = {"rhsusf_shemagh_od"};
    backpack[] = {"tf_rt1523g_rhs"};
    headgear[] = {"rhsusf_hgu56p_visor"};

    gps[] = {"ItemcTab"};

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""tf_receivingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""tf_sendingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

class CAV_ACE_ROTARY_STUD : CAV_Alpha_Base {  // Rotary Instructor Pilots

    backpack[] = {"tf_rt1523g_rhs"};
    headgear[] = {"rhsusf_hgu56p_visor_green"};

    gps[] = {"ItemcTab"};

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""tf_receivingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""tf_sendingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

class CAV_ACE_FIXED_INSTR : CAV_Alpha_Base {

    nvgs[] = {""};
    backpack[] = {"tf_rt1523g_rhs"};
    headgear[] = {"H_PilotHelmetFighter_B"};  // This has been tested by CPT.Blackburn.J
    uniform[] = {"U_B_PilotCoveralls"};
    vest[] = {""};

    primary[] = {""};
    secondary[] = {"rhsusf_weap_m9"};
    launcher[] = {""};

    binoculars[] = {""};

    magazines[] = {

        "rhsusf_mag_15Rnd_9x19_JHP",3,

        "Chemlight_green",
        "ACE_Chemlight_HiRed",
        "ACE_Chemlight_HiYellow",
        "SmokeShell",
        "SmokeShellGreen",
        "SmokeShellRed",
        "B_IR_Grenade",2
    };

    items[] = {
        // Personal Medical Equipment
        "ACE_quikclot",5,
        "ACE_tourniquet",2,

        // Standard
        "ACE_MapTools",
        "ACE_IR_Strobe_Item",
        "ACE_Flashlight_MX991",

        // Electronics
        "ACE_microDAGR"
    };

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""tf_receivingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""tf_sendingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};

class CAV_ACE_FIXED_STUD : CAV_Alpha_Base {

    nvgs[] = {""};
    backpack[] = {"tf_rt1523g_rhs"};
    headgear[] = {"H_PilotHelmetFighter_B"};  // This has been tested by CPT.Blackburn.J
    uniform[] = {"U_B_PilotCoveralls"};
    vest[] = {""};

    primary[] = {""};
    secondary[] = {"rhsusf_weap_m9"};
    launcher[] = {""};

    binoculars[] = {""};

    magazines[] = {

        "rhsusf_mag_15Rnd_9x19_JHP",3,

        "Chemlight_green",
        "ACE_Chemlight_HiRed",
        "ACE_Chemlight_HiYellow",
        "SmokeShell",
        "SmokeShellGreen",
        "SmokeShellRed",
        "B_IR_Grenade",2
    };

    items[] = {
        // Personal Medical Equipment
        "ACE_quikclot",5,
        "ACE_tourniquet",2,

        // Standard
        "ACE_MapTools",
        "ACE_IR_Strobe_Item",
        "ACE_Flashlight_MX991",

        // Electronics
        "ACE_microDAGR"
    };

    preLoadout = " \
        (_this select 0) setVariable [""CAV_isTrainingUnit"", true]; \
        (_this select 0) setVariable [""ACE_medical_medicClass"", 2, true]; \
        (_this select 0) allowDamage false; \
        (_this select 0) setVariable [""tf_receivingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""tf_sendingDistanceMultiplicator"", 2]; \
        (_this select 0) setVariable [""ACE_isEngineer"", true];";
};
