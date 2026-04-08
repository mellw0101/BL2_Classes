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