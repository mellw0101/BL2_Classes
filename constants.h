#pragma once

/* ---------------------------------------------------------- AResourcePoolManager ---------------------------------------------------------- */

static const int MAX_RESOURCE_POOLS = 16;

/* ---------------------------------------------------------- UWillowDamageTypeDefinition ---------------------------------------------------------- */

static const int DAMAGEFLAG_CriticalHit = 1;
static const int DAMAGEFLAG_Healing     = 2;
static const int DAMAGEFLAG_Resist      = 4;

/* ---------------------------------------------------------- AController ---------------------------------------------------------- */

static const int LATENT_MOVETOWARD = 503;

/* ---------------------------------------------------------- UWillowWeaponTypes ---------------------------------------------------------- */

static const int HolsteredWeaponSize_Small = 1;
static const int HolsteredWeaponSize_Medium = 2;
static const int HolsteredWeaponSize_Large = 4;
static const int HolsteredWeaponSize_ExtraLarge = 8;

/* ---------------------------------------------------------- UWillowInventoryDefinition ---------------------------------------------------------- */

static const int MAX_UI_STATS = 7;

/* ---------------------------------------------------------- UFont ---------------------------------------------------------- */

#define UCONST_NULLCHARACTER 127
static const signed char NULLCHARACTER = UCONST_NULLCHARACTER;

/* ---------------------------------------------------------- AWillowInventory ---------------------------------------------------------- */

/* Constants */
static const int USE_FAILURE_LEVEL               = 0;
static const int USE_FAILURE_CONSTRAINTS         = 1;
static const int USE_FAILURE_DLC                 = 2;
static const int InventoryNetUpdateHigh          = 100;
static const int InventoryNetUpdateLow           = 1;
static const int MAX_INVENTORY_ATTRIBUTE_SLOTS   = 19;
static const int INVENTORY_SERIAL_NUMBER_SIZE    = 40;
static const int REVISION_BITS                   = 7;
static const int GRADE_BITS                      = 7;
static const int GAME_STAGE_BITS                 = 7;
static const int UNIQUE_INVENTORY_ID_BITS        = 32;
static const int STORED_AMMO_BITS                = 13;
static const int ENCODED_ITEM_TYPE               = 0;
static const int ENCODED_WEAPON_TYPE             = 1;
static const int UNIQUE_INVENTORY_ID_BYTE_OFFSET = 1;
static const int CRC_BYTE_OFFSET                 = 5;
static const int CRC_BITS                        = 16;

/* ---------------------------------------------------------- APlayerController ---------------------------------------------------------- */

static const float MAXPOSITIONERRORSQUARED        = 3.f;
static const float MAXNEARZEROVELOCITYSQUARED     = 9.f;
static const float MAXVEHICLEPOSITIONERRORSQUARED = 900.f;
static const float CLIENTADJUSTUPDATECOST         = 180.f;
static const float MAXCLIENTUPDATEINTERVAL        = .25f;

/* ---------------------------------------------------------- ACamera ---------------------------------------------------------- */

static const int MAX_ACTIVE_CAMERA_ANIMS = 8;

/* ---------------------------------------------------------- AActor ---------------------------------------------------------- */

static const int    TRACEFLAG_Bullet                    = 1;
static const int    TRACEFLAG_PhysicsVolumes            = 2;
static const int    TRACEFLAG_SkipMovers                = 4;
static const int    TRACEFLAG_Blocking                  = 8;
static const int    TRACEFLAG_LightProjectile           = 8192;
static const int    TRACEFLAG_IgnoreNonBlockingTriggers = 16384;
static const int    TRACEFLAG_FieldVolumes              = 32768;
static const int    TRACEFLAG_Projectiles               = 65536;
static const int    TRACEFLAG_Listener                  = 131072;
static const int    TRACEFLAG_Water                     = 262144;
static const int    TRACEFLAG_BlockingMesh              = 524288;
static const int    TRACEFLAG_IgnoreBlockingMesh        = 1048576;
static const float  REP_RBLOCATION_ERROR_TOLERANCE_SQ   = 16.0f;
static const double MINFLOORZ                           = 0.7;
static const double ACTORMAXSTEPHEIGHT                  = 35.0;
static const double RBSTATE_LINVELSCALE                 = 10.0;
static const double RBSTATE_ANGVELSCALE                 = 1000.0;
static const int    RB_None                             = 0x00;
static const int    RB_NeedsUpdate                      = 0x01;
static const int    RB_Sleeping                         = 0x02;

/* ---------------------------------------------------------- UHUDWidget_Minimap ---------------------------------------------------------- */

static const int   MAX_IO_ICONS_PER_TYPE = 4;
static const int   MAX_SHOPS_ICONS       = 8;
static const int   MAX_VEHICLES          = 2;
static const float MINIMAP_WIDTH         = 58.f;
static const float MINIMAP_HEIGHT        = 48.f;

/* ---------------------------------------------------------- UMissionDefinition ---------------------------------------------------------- */

static const int MAX_MISSION_OBJECTIVES         = 20;
static const int MAX_MISSION_SUB_OBJECTIVE_SETS = 4;

/* ---------------------------------------------------------- UWillowUIInteraction ---------------------------------------------------------- */

static const float MenuRefreshRate = 0.5;
static const float SCROLL_ACCEL_RATE = 0.85f;
static const float SCROLL_MIN_DELAY = 0.02f;
static const float SCROLL_INITIAL_DELAY = 0.1f;
static const float INTERRUPT_FADE_OUT_TIME = 0.1f;
static const float CLOSE_FADE_OUT_TIME = 0.3f;
static const char *TOOLTIP_SPACING = "    ";
static const int   GEARBUILDER_MAX_CONFIGURABLE_ITEM_PARTS = 9;
static const int   GEARBUILDER_MAX_CONFIGURABLE_WEAPON_PARTS = 9;
static const int   InProgressMenu = 0;
static const int   NotStartedMenu = 1;
static const int   CompletedMenu = 2;
static const int   IneligibleMenu = 3;
static const int   FastTravelMenu = 0;
static const int   LevelTravelMenu = 1;

/* ---------------------------------------------------------- UFastTravelStationGFxMovie ---------------------------------------------------------- */

static const int MAX_LOCATION_MISSIONS = 4;
static const int SORT_GAME = 0;
static const int SORT_ALPHABETICAL = 1;
static const int COLOR_HEADER = 5352150;
static const int COLOR_DEFAULT = 14679039;
static const int NUM_LIST_ITEM_RENDERERS = 13;

/* ---------------------------------------------------------- UAssetLibraryManager ---------------------------------------------------------- */

static const int LIB_TYPE_BITS = 4;
static const int SKU_ID_BITS = 8;
static const int MAIN_GAME_SKU_ID = 0;

/* ---------------------------------------------------------- UGameplayEventsWriter ---------------------------------------------------------- */

static const int GAMEEVENT_MATCH_STARTED            = 0;
static const int GAMEEVENT_MATCH_ENDED              = 1;
static const int GAMEEVENT_ROUND_STARTED            = 2;
static const int GAMEEVENT_ROUND_ENDED              = 3;
static const int GAMEEVENT_GAME_CLASS               = 6;
static const int GAMEEVENT_GAME_OPTION_URL          = 7;
static const int GAMEEVENT_GAME_MAPNAME             = 8;
static const int GAMEEVENT_MEMORYUSAGE_POLL         = 35;
static const int GAMEEVENT_FRAMERATE_POLL           = 36;
static const int GAMEEVENT_NETWORKUSAGEIN_POLL      = 37;
static const int GAMEEVENT_NETWORKUSAGEOUT_POLL     = 38;
static const int GAMEEVENT_PING_POLL                = 39;
static const int GAMEEVENT_RENDERTHREAD_POLL        = 40;
static const int GAMEEVENT_GAMETHREAD_POLL          = 41;
static const int GAMEEVENT_GPUFRAMETIME_POLL        = 42;
static const int GAMEEVENT_FRAMETIME_POLL           = 43;
static const int GAMEEVENT_TEAM_CREATED             = 50;
static const int GAMEEVENT_TEAM_GAME_SCORE          = 51;
static const int GAMEEVENT_TEAM_MATCH_WON           = 4;
static const int GAMEEVENT_TEAM_ROUND_WON           = 5;
static const int GAMEEVENT_TEAM_ROUND_STALEMATE     = 52;
static const int GAMEEVENT_PLAYER_LOGIN             = 100;
static const int GAMEEVENT_PLAYER_LOGOUT            = 101;
static const int GAMEEVENT_PLAYER_SPAWN             = 102;
static const int GAMEEVENT_PLAYER_MATCH_WON         = 103;
static const int GAMEEVENT_PLAYER_KILL              = 104;
static const int GAMEEVENT_PLAYER_LOCATION_POLL     = 105;
static const int GAMEEVENT_PLAYER_TEAMCHANGE        = 106;
static const int GAMEEVENT_PLAYER_KILL_STREAK       = 107;
static const int GAMEEVENT_PLAYER_DEATH             = 108;
static const int GAMEEVENT_PLAYER_ROUND_WON         = 109;
static const int GAMEEVENT_PLAYER_ROUND_STALEMATE   = 110;
static const int GAMEEVENT_WEAPON_DAMAGE            = 150;
static const int GAMEEVENT_WEAPON_DAMAGE_MELEE      = 151;
static const int GAMEEVENT_WEAPON_FIRED             = 152;
static const int GAMEEVENT_PLAYER_KILL_NORMAL       = 200;
static const int GAMEEVENT_GENERIC_PARAM_LIST_START = 300;
static const int GAMEEVENT_GENERIC_PARAM_LIST_END   = 400;
static const int GAMEEVENT_GAME_SPECIFIC            = 1000;
static const int GAMEEVENT_MAX_EVENTID              = 0x0000FFFF;

/* ---------------------------------------------------------- UGameplayEvents ---------------------------------------------------------- */

static const int HeaderFlags_NoEventStrings = 1;

/* ---------------------------------------------------------- ANavigationPoint ---------------------------------------------------------- */

static const int INFINITE_PATH_COST = 10000000;

/* ---------------------------------------------------------- ACoverLink ---------------------------------------------------------- */

static const float COVERLINK_ExposureDot = 0.4f;
static const float COVERLINK_EdgeCheckDot = 0.25f;
static const float COVERLINK_EdgeExposureDot = 0.85f;
static const float COVERLINK_DangerDist = 1536.f;

/* ---------------------------------------------------------- AGearboxMind ---------------------------------------------------------- */

static const double TimeToMarkTargetsWhoShotAtMe = 10.0;

/* ---------------------------------------------------------- UConsole ---------------------------------------------------------- */

static const int MaxHistory = 16;

/* ---------------------------------------------------------- UReachSpec ---------------------------------------------------------- */

static const int BLOCKEDPATHCOST = 10000000;

/* ---------------------------------------------------------- UBadassPanelGFxObject ---------------------------------------------------------- */

static const int BADASS_REWARD_CHOICES = 5;

/* ---------------------------------------------------------- AWillowLightProjectileManager ---------------------------------------------------------- */

static const int MAX_PROJECTILES = 16;
static const int MAX_BEAMS = 20;

/* ---------------------------------------------------------- AWillowPawn ---------------------------------------------------------- */

static const double MINTIMEBETWEENPAINSOUNDS       = 0.35;
static const int    NUM_EQUIPMENT_LOCATIONS        = 4;
static const int    MAX_NUM_HOLSTERED_WEAPON_SLOTS = 3;
static const int    EQUIPPED_WEAPONS_HIDDEN_BIT    = 0x1;
static const int    HOLSTERED_WEAPONS_HIDDEN_BIT   = 0x2;
static const int    HOLSTERED_ITEMS_HIDDEN_BIT     = 0x4;
static const int    MAX_REPLICATED_NOUNS           = 20;

/* ---------------------------------------------------------- AWillowItem ---------------------------------------------------------- */

static const int MAX_ITEM_CARD_MODIFIER_STATS = 5;
static const int USE_FAILURE_CHARACTER = 16;

/* ---------------------------------------------------------- AWillowPickup ---------------------------------------------------------- */

static const float PICKUP_SHRINK_STEP_TIME = .1f;

/* ---------------------------------------------------------- UWillowGameViewportClient ---------------------------------------------------------- */

static const int MAX_LOCAL_USERS = 4;

/* ---------------------------------------------------------- UWillowHUDGFxMovie ---------------------------------------------------------- */

static const int NUM_ALLY_CACHES        = 3;
static const int MAX_SKILLICON_TRIGRESP = 11;
static const int MAX_SKILLICON_FLASK    = 1;
static const int MAX_SKILLICON_KILL     = 5;

/* ---------------------------------------------------------- AWillowPlayerController ---------------------------------------------------------- */

static const int   PROPERTY_EXP_LEVEL                      = 0x10000001;
static const int   PROPERTY_PLAYTHROUGH                    = 0x10000009;
static const int   PROPERTY_CURRMISSION                    = 0x1000000C;
static const int   PROPERTY_IS_PUBLIC                      = 0x10000010;
static const int   PROPERTY_CURR_PLOT_MISSION              = 0x10000022;
static const int   PROPERTY_MIN_EXP_LEVEL                  = 0x10000023;
static const int   PROPERTY_MAX_EXP_LEVEL                  = 0x10000024;
static const int   PROPERTY_MIN_PLOT_MISSION               = 0x10000025;
static const int   PROPERTY_MAX_PLOT_MISSION               = 0x10000026;
static const int   PROPERTY_HOST_EXP_LEVEL                 = 0x10000027;
static const int   PROPERTY_DLC_FLAG                       = 0x10000028;
static const int   PROPERTY_DLC_MAP_PACKAGE_ID             = 0x10000029;
static const int   PROPERTY_DLC_MAP_CONTENT_ID             = 0x1000000D;
static const int   QUERY_DEFAULT                           = 0;
static const int   QUERY_SPECIFIC                          = 2;
static const int   QUERY_NARROW                            = 5;
static const int   QUERY_BROAD                             = 6;
static const int   QUERY_CUSTOM                            = 7;
static const int   CONTEXT_GAME_MODE                       = 0x0000800B;
static const int   CONTEXT_GAME_MODE_NORMAL                = 0;
static const int   CONTEXT_CHARACTER_CLASS                 = 0;
static const int   CONTEXT_CHARACTER_CLASS_SOLDIER         = 0;
static const int   CONTEXT_CHARACTER_CLASS_ASSASSIN        = 1;
static const int   CONTEXT_CHARACTER_CLASS_SIREN           = 2;
static const int   CONTEXT_CHARACTER_CLASS_MERCENARY       = 3;
static const int   CONTEXT_CHARACTER_CLASS_MECHROMANCER    = 4;
static const int   CONTEXT_PRESENCE_IDLE                   = 0;
static const int   CONTEXT_PRESENCE_MENU_1                 = 1;
static const int   CONTEXT_PRESENCE_MENU_2                 = 2;
static const int   CONTEXT_PRESENCE_MENU_3                 = 3;
static const int   CONTEXT_PRESENCE_MENU_4                 = 4;
static const int   CONTEXT_PRESENCE_PLAYING_1              = 5;
static const int   CONTEXT_PRESENCE_PLAYING_2              = 6;
static const int   CONTEXT_PRESENCE_PLAYING_3              = 7;
static const int   CONTEXT_PRESENCE_PLAYING_4              = 8;
static const int   WPS_MasterVolume                        = 101;
static const int   WPS_ControllerSensitivityX              = 102;
static const int   WPS_ControllerSensitivityY              = 103;
static const int   WPS_ViewAccel                           = 104;
static const int   WPS_InvertMouseLook                     = 105;
static const int   WPS_IntroMovieViewed                    = 106;
static const int   WPS_MusicVolume                         = 107;
static const int   WPS_SFXVolume                           = 108;
static const int   WPS_AcceptDuels                         = 109;
static const int   WPS_AcceptTrades                        = 110;
static const int   WPS_EnableSubtitles                     = 111;
static const int   WPS_Brightness                          = 112;
static const int   WPS_AutoAim                             = 113;
static const int   WPS_HasUnlockedViralAchievement         = 114;
static const int   WPS_ControllerPreset                    = 115;
static const int   WPS_LastSavedId                         = 116;
static const int   WPS_DisableOptionalVO                   = 117;
static const int   WPS_DisableTrainingMessages             = 118;
static const int   WPS_AmbientOcclusion                    = 119;
static const int   WPS_HUDScaleE                           = 120;
static const int   WPS_MouseSensitivity                    = 121;
static const int   WPS_DlcNotifications                    = 122;
static const int   WPS_VoiceVolume                         = 124;
static const int   WPS_PushToTalk                          = 125;
static const int   WPS_VOVolume                            = 127;
static const int   WPS_PerShotForceFeedback                = 128;
static const int   WPS_PlayerFOV                           = 129;
static const int   WPS_StashSlot0                          = 130;
static const int   WPS_StashSlot1                          = 131;
static const int   WPS_StashSlot2                          = 132;
static const int   WPS_StashSlot3                          = 133;
static const int   WPS_CrouchToggle                        = 134;
static const int   WPS_ZoomToggle                          = 135;
static const int   WPS_BadassPoints                        = 136;
static const int   WPS_BadassPointsSpent                   = 137;
static const int   WPS_BadassTokens                        = 138;
static const int   WPS_BadassTokensEarned                  = 139;
static const int   WPS_AbsoluteMinimap                     = 140;
static const int   WPS_HUDScaleX                           = 141;
static const int   WPS_HUDScaleY                           = 142;
static const int   WPS_BadassRewardsEarned                 = 143;
static const int   WPS_DriftCameraLock                     = 145;
static const int   WPS_VehicleSteering                     = 146;
static const int   WPS_SplitDirection                      = 147;
static const int   WPS_TradingDisabled                     = 148;
static const int   WPS_KeyRebinding                        = 149;
static const int   WPS_CheckedForPreviousGame              = 150;
static const int   WPS_LastNewOfferVersion                 = 151;
static const int   WPS_MouseSmoothing                      = 152;
static const int   WPS_TEST_ItemRotation                   = 153;
static const int   WPS_GamepadInvertTurn                   = 154;
static const int   WPS_GamepadInvertMove                   = 155;
static const int   WPS_GamepadInvertStrafe                 = 156;
static const int   WPS_ShouldCensorContent                 = 157;
static const int   WPS_ControllerRebinding                 = 158;
static const int   WPS_GunzerkingAutoSwitch                = 159;
static const int   WPS_EasterEggOption                     = 160;
static const int   WPS_RewardedForPlayingPreviousGame      = 161;
static const int   WPS_GoldenKeysEarned                    = 162;
static const int   WPS_DisableUISway                       = 163;
static const int   WPS_BadassRewardsToOfferNext            = 164;
static const int   WPS_InvertedReverseSteering             = 165;
static const int   WPS_BackpackSortPreference              = 166;
static const int   WPS_MouseAutoAim                        = 167;
static const int   WPS_ColorBlindMode                      = 168;
static const int   WPS_OakUpsellViewed                     = 169;
static const int   WPS_CustomUnlocks_FIRST                 = 300;
static const int   WPS_CustomUnlocks_MAIN                  = 300;
static const int   WPS_CustomUnlocks_DLC01                 = 301;
static const int   WPS_CustomUnlocks_DLC02                 = 302;
static const int   WPS_CustomUnlocks_DLC03                 = 303;
static const int   WPS_CustomUnlocks_DLC04                 = 304;
static const int   WPS_CustomUnlocks_DLC05                 = 305;
static const int   WPS_CustomUnlocks_DLC06                 = 306;
static const int   WPS_CustomUnlocks_DLC07                 = 307;
static const int   WPS_CustomUnlocks_DLC08                 = 308;
static const int   WPS_CustomUnlocks_DLC09                 = 309;
static const int   WPS_CustomUnlocks_DLC10                 = 310;
static const int   WPS_CustomUnlocks_DLC11                 = 311;
static const int   WPS_CustomUnlocks_DLC12                 = 312;
static const int   WPS_CustomUnlocks_DLC13                 = 313;
static const int   WPS_CustomUnlocks_DLC14                 = 314;
static const int   WPS_CustomUnlocks_DLC15                 = 315;
static const int   WPS_CustomUnlocks_DLC16                 = 316;
static const int   WPS_CustomUnlocks_DLC17                 = 317;
static const int   WPS_CustomUnlocks_DLC18                 = 318;
static const int   WPS_CustomUnlocks_DLC19                 = 319;
static const int   WPS_CustomUnlocks_DLC20                 = 320;
static const int   WPS_CustomUnlocks_DLC21                 = 321;
static const int   WPS_CustomUnlocks_DLC22                 = 322;
static const int   WPS_CustomUnlocks_DLC23                 = 323;
static const int   WPS_CustomUnlocks_DLC24                 = 324;
static const int   WPS_CustomUnlocks_DLC25                 = 325;
static const int   WPS_CustomUnlocks_DLC26                 = 326;
static const int   WPS_CustomUnlocks_DLC27                 = 327;
static const int   WPS_CustomUnlocks_DLC28                 = 328;
static const int   WPS_CustomUnlocks_DLC29                 = 329;
static const int   WPS_CustomUnlocks_DLC30                 = 330;
static const int   WPS_CustomUnlocks_DLC31                 = 331;
static const int   WPS_CustomUnlocks_DLC32                 = 332;
static const int   WPS_CustomUnlocks_DLC33                 = 333;
static const int   WPS_CustomUnlocks_DLC34                 = 334;
static const int   WPS_CustomUnlocks_DLC35                 = 335;
static const int   WPS_CustomUnlocks_DLC36                 = 336;
static const int   WPS_CustomUnlocks_DLC37                 = 337;
static const int   WPS_CustomUnlocks_DLC38                 = 338;
static const int   WPS_CustomUnlocks_DLC39                 = 339;
static const int   WPS_CustomUnlocks_DLC40                 = 340;
static const int   WPS_CustomUnlocks_DLC41                 = 341;
static const int   WPS_CustomUnlocks_DLC42                 = 342;
static const int   WPS_CustomUnlocks_DLC43                 = 343;
static const int   WPS_CustomUnlocks_DLC44                 = 344;
static const int   WPS_CustomUnlocks_DLC45                 = 345;
static const int   WPS_CustomUnlocks_DLC46                 = 346;
static const int   WPS_CustomUnlocks_DLC47                 = 347;
static const int   WPS_CustomUnlocks_DLC48                 = 348;
static const int   WPS_CustomUnlocks_DLC49                 = 349;
static const int   WPS_CustomUnlocks_LAST                  = 350;
static const int   MAX_AMMO_RESOURCE_UPGRADES              = 8;
static const int   MAX_SPLIT_PLAYERS                       = 2;
static const int   MIN_TIME_BETWEEN_SAVES_AT_SAME_STATION  = 60;
static const int   MAX_RECENT_KILLS                        = 25;
static const float MAX_COMBINE_HITS_TIME                   = 0.2f;
static const int   MAX_PLAYER_DAMAGE_NOTIFICATIONS         = 6;
static const int   RECENTLY_RESISTED_ATTACK_HISTORY_LENGTH = 16;
static const int   MAX_ALLOWED_LOCATION_DELTA              = 5000;
static const int   TIME_BETWEEN_LOCATION_STAT_UPDATES_MS   = 5000;
static const int   NETWORK_NOTIFICATION_TIME               = 3.0f;
static const int   GOLDEN_KEY_SOURCE_SPARK                 = 0;

/* ---------------------------------------------------------- AWillowPlayerPawn ---------------------------------------------------------- */

static const int   MAX_ARMS_LEADING_ROTATION_HISTORY = 10;
static const char *WEATHER_PSC_INSTANCE_DATA_NAME_1  = "WeatherParticle";
static const char *WEATHER_PSC_INSTANCE_DATA_NAME_2  = "WeatherParticle_Screen";

/* ---------------------------------------------------------- UBehaviorBase ---------------------------------------------------------- */

static const int LINK_ID_RESERVED_FOR_DEFAULT_BEHAVIOR_OUTPUT = -1;

/* ---------------------------------------------------------- AGearboxPawn ---------------------------------------------------------- */

static const double SecondsToRememberRecentIncomingShots = 3.0;

/* ---------------------------------------------------------- AGBXNavMesh ---------------------------------------------------------- */

static const int   NUM_EDGES                        = 3;
static const int   WORDSIZE                         = 2;
static const int   NUM_EDGE_BYTES                   = 6;
static const float DESIRED_NAVMESH_LOOKUP_NODE_SIZE = 1024.0f;
static const int   MAX_POLY_OBSTACLES               = 6;
static const int   MAX_POLY_OBSTACLE_BYTES          = 12;
static const int   MAX_POLY_POINT_CHECKS            = 10;

/* ---------------------------------------------------------- UGameStatsAggregator ---------------------------------------------------------- */

static const int GAMEEVENT_AGGREGATED_DATA = 10000;
static const int GAMEEVENT_AGGREGATED_PLAYER_TIMEALIVE = 10001;
static const int GAMEEVENT_AGGREGATED_PLAYER_KILLS = 10002;
static const int GAMEEVENT_AGGREGATED_PLAYER_DEATHS = 10003;
static const int GAMEEVENT_AGGREGATED_PLAYER_MATCH_WON = 10004;
static const int GAMEEVENT_AGGREGATED_PLAYER_ROUND_WON = 10005;
static const int GAMEEVENT_AGGREGATED_DAMAGE_DEALT_NORMALKILL = 10006;
static const int GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_WASNORMALKILL = 10007;
static const int GAMEEVENT_AGGREGATED_TEAM_KILLS = 10100;
static const int GAMEEVENT_AGGREGATED_TEAM_DEATHS = 10101;
static const int GAMEEVENT_AGGREGATED_TEAM_GAME_SCORE = 10102;
static const int GAMEEVENT_AGGREGATED_TEAM_MATCH_WON = 10103;
static const int GAMEEVENT_AGGREGATED_TEAM_ROUND_WON = 10104;
static const int GAMEEVENT_AGGREGATED_DAMAGE_KILLS = 10200;
static const int GAMEEVENT_AGGREGATED_DAMAGE_DEATHS = 10201;
static const int GAMEEVENT_AGGREGATED_DAMAGE_DEALT_WEAPON_DAMAGE = 10202;
static const int GAMEEVENT_AGGREGATED_DAMAGE_DEALT_MELEE_DAMAGE = 10203;
static const int GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_WEAPON_DAMAGE = 10204;
static const int GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_MELEE_DAMAGE = 10205;
static const int GAMEEVENT_AGGREGATED_DAMAGE_DEALT_MELEEHITS = 10206;
static const int GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_WASMELEEHIT = 10207;
static const int GAMEEVENT_AGGREGATED_WEAPON_FIRED = 10300;
static const int GAMEEVENT_AGGREGATED_PAWN_SPAWN = 10400;
static const int GAMEEVENT_AGGREGATED_GAME_SPECIFIC = 11000;

/* ---------------------------------------------------------- UCustomizationDefinition ---------------------------------------------------------- */

static const int MAX_SECONDARY_PER_PRIMARY = 20;

/* ---------------------------------------------------------- UOnlineMessageGFxMovie ---------------------------------------------------------- */

static const char *TitleFormat    = "<font size='13' color='#FFFFFF'>%message%</font>";
static const char *SubtitleFormat = "<font size='11' color='#CCCCCC'>%message%</font>";

/* ---------------------------------------------------------- URuleEngineLoadBalanceManager ---------------------------------------------------------- */

static const float MaxTimeMSAllowedPerFrame = 1.f;

/* ---------------------------------------------------------- UMindTargetInfo ---------------------------------------------------------- */

static const int MAX_HIT_TARGET_RECORDS = 5;

/* ---------------------------------------------------------- AWillowTradeManager ---------------------------------------------------------- */

static const int MAX_INV_SLOTS = 4;

/* ---------------------------------------------------------- UUISceneClient ---------------------------------------------------------- */

static const int SCENEFILTER_None               = 0x00000000;
static const int SCENEFILTER_IncludeTransient   = 0x00000001;
static const int SCENEFILTER_InputProcessorOnly = 0x00000002;
static const int SCENEFILTER_PausersOnly        = 0x00000004;
static const int SCENEFILTER_PrimitiveUsersOnly = 0x00000008;
static const int SCENEFILTER_UsesPostProcessing = 0x00000010;
static const int SCENEFILTER_ReceivesFocus      = 0x00000020;
static const int SCENEFILTER_Any                = 0xFFFFFFFF;

/* ---------------------------------------------------------- UOnlinePlaylistManager ---------------------------------------------------------- */

static const int PLAYER_MATCH  = 0;
static const int RANKED_MATCH  = 1;
static const int REC_MATCH     = 2;
static const int PRIVATE_MATCH = 3;

/* ---------------------------------------------------------- UAITracker ---------------------------------------------------------- */

static const int SNAPSHOT_MAX = 50;

/* ---------------------------------------------------------- UScreenSpaceManager ---------------------------------------------------------- */

static const int ScreenBaseX = 640;
static const int ScreenBaseY = 480;

/* ---------------------------------------------------------- AWillowRadarManager ---------------------------------------------------------- */

static const int MAX_ACTIVE_SKILL_STATION_ICONS = 28;
static const int MAX_ACTIVE_DYNAMIC_ICONS       = 18;

/* ---------------------------------------------------------- UPlayerSkillTree ---------------------------------------------------------- */

static const int MAX_SKILL_TYPES = 5;

/* ---------------------------------------------------------- AMissionTracker ---------------------------------------------------------- */

static const int STARTING_MISSION_NUMBER        = 0;
static const int MAX_DYNAMIC_MISSION_DIRECTIVES = 10;
static const int MAX_ACTIVE_MISSION_DIRECTORS   = 14;

/* ---------------------------------------------------------- AWillowGameReplicationInfo ---------------------------------------------------------- */

static const int MAX_ACTIVE_WAYPOINTS      = 6;
static const int MAX_ACTIVE_AREA_WAYPOINTS = 4;
static const int NUM_FAST_TRAVEL_BYTES     = 16;
static const int MAX_NUM_NPC_ALLIES        = 2;

/* ---------------------------------------------------------- UWillowDeclarations ---------------------------------------------------------- */

static const int NUM_MISSION_REWARD_CHOICES = 2;

/* ---------------------------------------------------------- AWillowInventoryManager ---------------------------------------------------------- */

static const int STASH_MAX     = 4;
static const int BUYBACK_SLOTS = 20;

/* ---------------------------------------------------------- UGearboxGlobals ---------------------------------------------------------- */

static const int MAX_VANTAGES_PER_LOOKER = 3;

/* ---------------------------------------------------------- AWillowGameInfo ---------------------------------------------------------- */

static const int MAX_SPLITSCREEN_PLAYERS = 2;
static const int SHOP_TIMER_RESEND_RATE  = 10;
static const int MAX_COLISEUM_PLAYERS    = 4;

/* ---------------------------------------------------------- AWillowPlayerReplicationInfo ---------------------------------------------------------- */

static const int MAX_APPLIED_CUSTOMIZATIONS = 5;
static const int MAX_TRACKED_SKILLS = 17;