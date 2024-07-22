class CommonBlufor {
    //regimentName = "";
    //regiment = -1
    //battalion = -1
    //platoon = -1;
    //squad = -1;
    //team = "";

    //displayName = "";
    //scope = 0;
    //category[] = {};
    //loadout = [[],[],[],[],[],[],"","",[],["","","","","",""]];
    //equipmentTags[] = {};

    //icon = "";
    //insignia = "";

    //abilityMedic = 0;
    //abilityEngineer = 0;
    //abilityEOD = 0;

    //preLoadout = "";
    //postLoadout = "";
};

class Cav_B_Seventh_Cavalry_Base_F: CommonBlufor {
    scope = 0;
    regimentName = "7th Cavalry";
    regiment = "7"
    battalion = "1"

    icon = "iconMan";
};

class Cav_B_Alpha_base_F: Cav_B_Seventh_Cavalry_Base_F {
    category[] = {"cScripts_Loadout_Cat_Alpha"};
    company = "alpha";
    loadout = [[],[],["rhsusf_weap_m9","","","",["rhsusf_mag_15Rnd_9x19_FMJ",15],[],""],["rhs_uniform_cu_ocp_1stcav",[["ACE_MapTools",1],["ACE_fieldDressing",1],["ACE_quikclot",4],["ACE_splint",1],["ACE_tourniquet",1]]],["rhsusf_iotv_ocp",[["rhsusf_mag_15Rnd_9x19_FMJ",1,15]]],[],"rhsusf_patrolcap_ocp","",[],["ItemMap","","","ItemCompass","ItemWatch",""]];

    insignia = "cav_insignia_specialized_pegasus";
    preLoadout = "";
    postLoadout = "";
};

class Cav_B_Bravo_base_F: Cav_B_Seventh_Cavalry_Base_F {
    category[] = {"cScripts_Loadout_Cat_Bravo"};
    company = "bravo";
    insignia = "";
    loadout = [["rhs_weap_m16a4_carryhandle","","","",["rhs_mag_30Rnd_556x45_M855A1_Stanag",30],[],""],[],[],["rhs_uniform_cu_ocp_1stcav",[["ACE_MapTools",1],["ACE_fieldDressing",1],["ACE_quikclot",4],["ACE_splint",1],["ACE_tourniquet",1]]],["rhsusf_iotv_ocp",[["rhs_mag_30Rnd_556x45_M855A1_Stanag",1,30]]],[],"rhsusf_patrolcap_ocp","",[],["ItemMap","","","ItemCompass","ItemWatch",""]];
    
    preLoadout = "";
    postLoadout = "";
};

class Cav_B_Charlie_base_F: Cav_B_Seventh_Cavalry_Base_F {
    category[] = {"cScripts_Loadout_Cat_Charlie"};
    company = "charlie";
    insignia = "";
    loadout = [["rhs_weap_m4a1_carryhandle","","","",["rhs_mag_30Rnd_556x45_M855A1_Stanag",30],[],""],[],[],["rhs_uniform_cu_ocp_1stcav",[["ACE_MapTools",1],["ACE_fieldDressing",1],["ACE_quikclot",4],["ACE_splint",1],["ACE_tourniquet",1]]],["rhsusf_iotv_ocp",[["rhs_mag_30Rnd_556x45_M855A1_Stanag",1,30]]],[],"rhsusf_patrolcap_ocp","",[],["ItemMap","","","ItemCompass","ItemWatch",""]];
    
    equipmentTags[] = {
        "coll_weapons_primary",
        "equ_radio_basic",
        "equ_medical_level_0"
    };

    preLoadout = "";
    postLoadout = "";
};
