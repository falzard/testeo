/*
 * Originally written by Pussywizard - Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: http://github.com/azerothcore/azerothcore-wotlk/LICENSE-AGPL
*/

#ifndef DEF_EYE_OF_ETERNITY_H
#define DEF_EYE_OF_ETERNITY_H

#include "ScriptPCH.h"

enum Objects
{
    GO_NEXUS_PLATFORM           = 193070,
    GO_IRIS_N                   = 193958,
    GO_IRIS_H                   = 193960,
    GO_EXIT_PORTAL              = 193908,
};
#define ALEXSTRASZA_GIFT        DUNGEON_MODE(193905, 193967)
#define HEART_OF_MAGIC          DUNGEON_MODE(194158, 194159)

enum NPCs
{
    NPC_MALYGOS                 = 28859,
    NPC_PORTAL                  = 30118,
    NPC_WORLD_TRIGGER_LAOI      = 22517,
    NPC_POWER_SPARK             = 30084,
    NPC_VORTEX                  = 30090,
    NPC_NEXUS_LORD              = 30245,
    NPC_SCION_OF_ETERNITY       = 30249,
    NPC_HOVER_DISK              = 30248,
    NPC_ARCANE_OVERLOAD         = 30282,
    NPC_SURGE_OF_POWER          = 30334,
    NPC_WYRMREST_SKYTALON       = 30161,
    NPC_STATIC_FIELD            = 30592,
    NPC_ALEXSTRASZA             = 32295,
};

enum Data
{
    DATA_IRIS_ACTIVATED,
    DATA_ENCOUNTER_STATUS,
    DATA_SET_IRIS_INACTIVE,
    DATA_HIDE_IRIS_AND_PORTAL,
    DATA_MALYGOS_GUID,
};

enum eSpells
{
    SPELL_PORTAL_BEAM                   = 56046,
    SPELL_IRIS_ACTIVATED                = 61012,
    SPELL_POWER_SPARK_VISUAL            = 55845,
    SPELL_POWER_SPARK_GROUND_BUFF       = 55852,
    SPELL_POWER_SPARK_MALYGOS_BUFF      = 56152,

    SPELL_TELEPORT_VISUAL               = 52096,

    SPELL_SCION_ARCANE_BARRAGE          = 56397,
    SPELL_ARCANE_SHOCK_N                = 57058,
    SPELL_ARCANE_SHOCK_H                = 60073,
    SPELL_HASTE                         = 57060,

    SPELL_ALEXSTRASZA_GIFT              = 61028,
};

#define SPELL_ARCANE_SHOCK              DUNGEON_MODE(SPELL_ARCANE_SHOCK_N, SPELL_ARCANE_SHOCK_H)

enum eAchiev
{
    ACHIEV_CRITERIA_DENYIN_THE_SCION_10     = 7573,
    ACHIEV_CRITERIA_DENYIN_THE_SCION_25     = 7574,
    ACHIEV_CRITERIA_A_POKE_IN_THE_EYE_10    = 7174,
    ACHIEV_CRITERIA_A_POKE_IN_THE_EYE_25    = 7175,
    ACHIEV_YOU_DONT_HAVE_AN_ENTERNITY_EVENT = 20387,
};

/*** POSITIONS/WAYPOINTS BELOW ***/

#define INTRO_MOVEMENT_INTERVAL 25000

const Position CenterPos = {754.395f, 1301.27f, 266.10f, 0.0f};

const Position FourSidesPos[] =
{
    {686.417f, 1235.52f, 288.17f, M_PI/4},
    {828.182f, 1379.05f, 288.17f, 5*M_PI/4},
    {681.278f, 1375.796f, 288.17f, 7*M_PI/4},
    {821.182f, 1235.42f, 288.17f, 3*M_PI/4},
};

const Position Phase2NorthPos = {837.22f, 1301.676f, 296.10f, M_PI};

/*** TEXTS/SOUNDS BELOW ***/

enum sounds
{
    SOUND_VORTEX                            = 14525,
    SOUND_SPARK_BUFF                        = 14533,

    SOUND_SLAY_1_1                          = 14519,
    SOUND_SLAY_1_2                          = 14520,
    SOUND_SLAY_1_3                          = 14521,
    SOUND_SLAY_2_1                           = 14526,
    SOUND_SLAY_2_2                           = 14527,
    SOUND_SLAY_2_3                           = 14528,
    SOUND_SLAY_3_1                           = 14534,
    SOUND_SLAY_3_2                           = 14535,
    SOUND_SLAY_3_3                           = 14536,
    
    SOUND_AGGRO_1                            = 14517,
    SOUND_AGGRO_2                            = 14523,
    SOUND_DEEP_BREATH                        = 14518,
    SOUND_DEATH                              = 14540,
    SOUND_PHASE_1_END                        = 14522,
    SOUND_PHASE_2_END                        = 14529,
    SOUND_PHASE_3_START                      = 14530
};

struct Speech
{
    uint32 sound;
    const char* text;
};

const Speech MalygosIntroTexts[] =
{
    {14512, "¿¡Seres inferiores, inmiscuyéndose aquí!? ¡Es una lástima que vuestro exceso de valor no compense vuestra estupidez!"},
    {14513, "Solo el Vuelo Azul es bienvenido aquí. ¿Quizá esto sea obra de Alexstrasza? ¡Bueno, entonces os ha enviado hacia vuestras muertes!"},
    {14514, "¿Qué esperáis conseguir? ¿Adentrándoos descaradamente en mis dominios... para usar magia... contra MÍ?"},
    {14515, "No tengo límites aquí. Las reglas de vuestra amada realidad no son aplicables aquí. ¡En este reino, yo tengo el control!"},
    {14516, "Os daré una oportunidad. Juradme lealtad y quizá no os mate por vuestra insolencia."},
};

const uint32 MalygosIntroIntervals[] = {18000, 19000, 21000, 18000, 15000};

class EoEDrakeEnterVehicleEvent : public BasicEvent
{
    public:
        EoEDrakeEnterVehicleEvent(Creature& owner, uint64 playerGUID) : _owner(owner), _playerGUID(playerGUID) { }
        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/);
    private:
        Creature& _owner;
        uint64 _playerGUID;
};

#endif
