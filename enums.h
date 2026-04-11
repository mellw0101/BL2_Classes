#pragma once

#include "macro_helpers.h"

typedef enum : unsigned int {
  FALSE,
  TRUE,
} UBOOL;

/* Internal enums. */
typedef enum ENativeConstructor {EC_NativeConstructor} ENativeConstructor;
typedef enum EStaticConstructor {EC_StaticConstructor} EStaticConstructor;
typedef enum EInternal          {EC_Internal}          EInternal;
typedef enum ECppProperty       {EC_CppProperty}       ECppProperty;
typedef enum EEventParm         {EC_EventParm}         EEventParm;

// Global constants.
enum {MINBYTE		= 0x00       };
enum {MINWORD		= 0x0000U    };
enum {MINDWORD		= 0x00000000U};
enum {MINSBYTE		= 0x80       };
enum {MINSWORD		= 0x8000     };
#undef MININT
enum {MININT		= 0x80000000 };
#define MININT ((INT)~MAXINT)
enum {MAXBYTE		= 0xff       };
enum {MAXWORD		= 0xffffU    };
enum {MAXDWORD		= 0xffffffffU};
enum {MAXSBYTE		= 0x7f       };
enum {MAXSWORD		= 0x7fff     };
enum {MAXINT		= 0x7fffffff };
enum {INDEX_NONE	= -1         };
enum {UNICODE_BOM   = 0xfeff     };
enum ENoInit {E_NoInit = 0};
enum EForceInit {E_ForceInit = 0};
enum {MAX_TEXCOORDS = 4};

/* Sizes. */
enum {MAX_STRING_CONST_SIZE = 1024}; 
/** this is the size of the buffer used by the script interpreter for unused simple (not constructed) return values.
 * Larger return values use the constructed value path (EX_EatReturnValue/execEatReturnValue)
 */
enum {MAX_SIMPLE_RETURN_VALUE_SIZE = 64 };


/**
 * This is the largest possible size that a single variable can be; a variables size is determined by multiplying the
 * size of the type by the variables ArrayDim (always 1 unless it's a static array).
 */
enum {MAX_VARIABLE_SIZE = 0x0FFF};

enum EAIFunctions {
	AI_PollMoveTo = 501,
	AI_PollMoveToward = 503,
	AI_PollStrafeTo = 505,
	AI_PollStrafeFacing = 507,
	AI_PollFinishRotation = 509,
	AI_PollWaitForLanding = 528,
};

/** Texture formats used by FTexture2D */
typedef enum ETexture2DFormats {
  TF_UNKNOWN,
  TF_ARGB8,
  TF_ARGB16F
} ETexture2DFormats;

/* Result of GotoState. */
typedef enum EGotoState {
  GOTOSTATE_NotFound  = 0,
  GOTOSTATE_Success   = 1,
  GOTOSTATE_Preempted = 2,
} EGotoState;

/**
 * Flags describing a class.
 */
typedef enum EClassFlags {
  /** @name Base flags */
  //@{
  CLASS_None				  = 0x00000000,
  /** Class is abstract and can't be instantiated directly. */
  CLASS_Abstract            = 0x00000001,
  /** Script has been compiled successfully. */
  CLASS_Compiled			  = 0x00000002,
  /** Load object configuration at construction time. */
  CLASS_Config			  = 0x00000004,
  /** This object type can't be saved; null it out at save time. */
  CLASS_Transient			  = 0x00000008,
  /** Successfully parsed. */
  CLASS_Parsed              = 0x00000010,
  /** Class contains localized text. */
  CLASS_Localized           = 0x00000020,
  /** Objects of this class can be safely replaced with default or NULL. */
  CLASS_SafeReplace         = 0x00000040,
  /** Class is a native class - native interfaces will have CLASS_Native set, but not RF_Native */
  CLASS_Native			  = 0x00000080,
  /** Don't export to C++ header. */
  CLASS_NoExport            = 0x00000100,
  /** Allow users to create in the editor. */
  CLASS_Placeable           = 0x00000200,
  /** Handle object configuration on a per-object basis, rather than per-class. */
  CLASS_PerObjectConfig     = 0x00000400,
  /** Replication handled in C++. */
  CLASS_NativeReplication   = 0x00000800,
  /** Class can be constructed from editinline New button. */
  CLASS_EditInlineNew		  = 0x00001000,
  /** Display properties in the editor without using categories. */
  CLASS_CollapseCategories  = 0x00002000,
  /** Class is an interface **/
  CLASS_Interface           = 0x00004000,
  /**
   * Indicates that this class contains object properties which are marked 'instanced' (or editinline export).  Set by the script compiler after all properties in the
   * class have been parsed.  Used by the loading code as an optimization to attempt to instance newly added properties only for relevant classes
   */
  CLASS_HasInstancedProps   = 0x00200000,
  /** Class needs its defaultproperties imported */
  CLASS_NeedsDefProps		  = 0x00400000,
  /** Class has component properties. */
  CLASS_HasComponents		  = 0x00800000,
  /** Don't show this class in the editor class browser or edit inline new menus. */
  CLASS_Hidden			  = 0x01000000,
  /** Don't save objects of this class when serializing */
  CLASS_Deprecated		  = 0x02000000,
  /** Class not shown in editor drop down for class selection */
  CLASS_HideDropDown		  = 0x04000000,
  /** Class has been exported to a header file */
  CLASS_Exported			  = 0x08000000,
  /** Class has no unrealscript counter-part */
  CLASS_Intrinsic			  = 0x10000000,
  /** Properties in this class can only be accessed from native code */
  CLASS_NativeOnly		  = 0x20000000,
  /** Handle object localization on a per-object basis, rather than per-class. */
  CLASS_PerObjectLocalized  = 0x40000000,
  /** This class has properties that are marked with CPF_CrossLevel */
  CLASS_HasCrossLevelRefs   = 0x80000000,

  // deprecated - these values now match the values of the EClassCastFlags enum
  /** IsA UProperty */
  CLASS_IsAUProperty        = 0x00008000,
  /** IsA UObjectProperty */
  CLASS_IsAUObjectProperty  = 0x00010000,
  /** IsA UBoolProperty */
  CLASS_IsAUBoolProperty    = 0x00020000,
  /** IsA UState */
  CLASS_IsAUState           = 0x00040000,
  /** IsA UFunction */
  CLASS_IsAUFunction        = 0x00080000,
  /** IsA UStructProperty */
  CLASS_IsAUStructProperty  = 0x00100000,

  //@}


  /** @name Flags to inherit from base class */
  //@{
  CLASS_Inherit           = CLASS_Transient | CLASS_Config | CLASS_Localized | CLASS_SafeReplace | CLASS_PerObjectConfig | CLASS_PerObjectLocalized | CLASS_Placeable
              | CLASS_IsAUProperty | CLASS_IsAUObjectProperty | CLASS_IsAUBoolProperty | CLASS_IsAUStructProperty | CLASS_IsAUState | CLASS_IsAUFunction
              | CLASS_HasComponents | CLASS_Deprecated | CLASS_Intrinsic | CLASS_HasInstancedProps | CLASS_HasCrossLevelRefs,

  /** these flags will be cleared by the compiler when the class is parsed during script compilation */
  CLASS_RecompilerClear   = CLASS_Inherit | CLASS_Abstract | CLASS_NoExport | CLASS_NativeReplication | CLASS_Native,

  /** these flags will be inherited from the base class only for non-intrinsic classes */
  CLASS_ScriptInherit		= CLASS_Inherit | CLASS_EditInlineNew | CLASS_CollapseCategories,
  //@}

  CLASS_AllFlags			= 0xFFFFFFFF,
} EClassFlags;

/**
 * Flags used for quickly casting classes of certain types; all class cast flags are inherited
 */
typedef enum EClassCastFlag {
  CASTCLASS_None						= 0x00000000,
  CASTCLASS_UField					= 0x00000001,
  CASTCLASS_UConst					= 0x00000002,
  CASTCLASS_UEnum						= 0x00000004,
  CASTCLASS_UStruct					= 0x00000008,
  CASTCLASS_UScriptStruct				= 0x00000010,
  CASTCLASS_UClass					= 0x00000020,
  CASTCLASS_UByteProperty				= 0x00000040,
  CASTCLASS_UIntProperty				= 0x00000080,
  CASTCLASS_UFloatProperty			= 0x00000100,
  CASTCLASS_UComponentProperty		= 0x00000200,
  CASTCLASS_UClassProperty			= 0x00000400,
  CASTCLASS_UInterfaceProperty		= 0x00001000,
  CASTCLASS_UNameProperty				= 0x00002000,
  CASTCLASS_UStrProperty				= 0x00004000,

  //@{
  // these match the values of the old class flags to make conversion easier
  CASTCLASS_UProperty					= 0x00008000,
  CASTCLASS_UObjectProperty			= 0x00010000,
  CASTCLASS_UBoolProperty				= 0x00020000,
  CASTCLASS_UState					= 0x00040000,
  CASTCLASS_UFunction					= 0x00080000,
  CASTCLASS_UStructProperty			= 0x00100000,
  //@}

  CASTCLASS_UArrayProperty			= 0x00200000,
  CASTCLASS_UMapProperty				= 0x00400000,
  CASTCLASS_UDelegateProperty			= 0x00800000,
  CASTCLASS_UComponent				= 0x01000000,


  CASTCLASS_AllFlags					= 0xFFFFFFFF,
} EClassCastFlag;

/**
 * Unique stats identifiers. Note these don't have to defined in this header
 * but they do have to be unique. You're better off defining these in your
 * own headers/cpp files
 */
typedef enum EStats {
  // Special stats
  STAT_Error,
  STAT_Root,
  STAT_FrameTime,
  // Used by the per group stats to avoid conflicts
  STAT_ObjectFirstStat				= 100,
  STAT_EngineFirstStat				= 200,
  STAT_GameFirstStat					= 300,
  STAT_UnrealScriptTime,// This stat needs to be visible to core
  STAT_NetFirstStat					= 400,
  STAT_NetPeerFirstStat				= 450,
  STAT_StreamingFirstStat				= 500,
  STAT_AsyncLoadingTime,// This stat needs to be here for include order reasons
  STAT_PhysicsFirstStat				= 700,
  STAT_CollisionFirstStat				= 800,
  STAT_AudioFirstStat					= 900,
  STAT_MemoryFirstStat				= 1000,
  STAT_MemoryChurnFirstStat			= 1100,
  STAT_ParticlesFirstStat				= 1200,
  STAT_BeamParticlesFirstStat			= 1300,
  STAT_D3D9RHIFirstStat				= 1400,
  STAT_StatSystemFirstStat			= 1500,
  STAT_OctreeFirstStat				= 1600,
  STAT_TrailParticlesFirstStat		= 1700,
  STAT_FaceFXFirstStat				= 1800,
  STAT_SceneRenderingFirstStat		= 1900,
  STAT_ThreadingFirstStat				= 2100,
  STAT_SceneUpdateFirstStat			= 2200,
  STAT_AnimFirstStat					= 2300,
  STAT_UIFirstStat					= 2400,
  STAT_DLEFirstStat					= 2500,
  STAT_AsyncIOFirstStat				= 2600,
  STAT_FPSChartFirstStat				= 2700,
  STAT_ShaderCompilingFirstStat		= 2800,
  STAT_PathFindingFirstStat			= 2900,
  STAT_PhysicsFluidFirstStat			= 3000,
  STAT_PhysicsClothFirstStat			= 3100,
  STAT_PhysicsFieldsFirstStat			= 3200,
  STAT_DecalFirstStat					= 3300,
  STAT_CanvasFirstStat				= 3400,
  STAT_MeshParticlesFirstStat			= 3500,
  STAT_PS3RHIFirstStat				= 3700,
  STAT_XeRHIFirstStat					= 3800,
  STAT_FluidsFirstStat				= 3900,
  STAT_MemoryDetailedFirstStat		= 4000,
  STAT_NavMeshFirstStat				= 4100,
  STAT_CrowdFirstStat					= 4200,
  STAT_InstancingFirstStat			= 4300,
  STAT_ShaderCompressionFirstStat		= 4400,
  STAT_InitViewsFirstStat				= 4500,
  STAT_ShadowRenderingFirstStat		= 4600,
  STAT_SceneCapturesFirstStat			= 4700,
  STAT_GFxFirstStat				    = 4800,
  STAT_ES2FirstStat				    = 4900,
  STAT_TexturePoolFirstStat			= 5000,
  STAT_D3D11RHIFirstStat				= 5100,
  STAT_MorphFirstStat					= 5200,
  STAT_GxmFirstStat				    = 5300,
  STAT_OpenGLRHIFirstStat				= 5400,
  STAT_SceneMemoryFirstStat			= 5500,
  // -- Add new stat ranges BELOW this line --

  // -- Add new stat ranges ABOVE this line --

  // stats created from arbitrary runtime strings on the fly
  STAT_FirstStringStat				= 35000,
  STAT_LastStringStat					= 39999,

  // Licensees should create their own enum with the first value being
  // set to the value below
  STAT_LicenseeFirstStat				= 60000
} EStats;

/** Stats for the stat system */
typedef enum EStatSystemStats {
  STAT_PerFrameCapture = STAT_StatSystemFirstStat,
  STAT_PerFrameCaptureRT,
  STAT_DrawStats,
  STAT_TimingCodeCalls,
} EStatSystemStats;

/**
 * Various memory regions that can be used with memory stats. The exact meaning of
 * the enums are relatively platform-dependent, although the general ones (Physical, GPU)
 * are straightforward. A platform can add more of these, and it won't affect other 
 * platforms, other than a miniscule amount of memory for the StatManager to track the
 * max available memory for each region (uses an array MCR_MAX big)
 */
typedef enum EMemoryCounterRegion {
  MCR_Physical, // main system memory
  MCR_GPU, // memory directly a GPU (graphics card, etc)
  MCR_GPUSystem, // system memory directly accessible by a GPU
  MCR_RingBuffer1, // general purpose regions for tracking how full a ring buffer gets (NOT the rendering thread command buffer)
  MCR_RingBuffer2, 
  MCR_RingBuffer3, 
  MCR_TexturePool1, // presized texture pools
  MCR_TexturePool2, 
  MCR_TexturePool3, 
  MCR_MAX
} EMemoryCounterRegion;

/**
 * Texture pool stats
 */
typedef enum ETexturePoolStats {
  STAT_TexturePool_DefragTime = STAT_TexturePoolFirstStat + 1,
  STAT_TexturePool_Blocked,
  STAT_TexturePool_Allocated,
  STAT_TexturePool_Free,
  STAT_TexturePool_RelocatedSize,
  STAT_TexturePool_LargestHole,
  STAT_TexturePool_NumRelocations,
  STAT_TexturePool_NumHoles,
  STAT_TexturePool_TotalAsyncReallocations,
  STAT_TexturePool_TotalAsyncAllocations,
  STAT_TexturePool_TotalAsyncCancellations,
  STAT_TexturePool_PackMipTailSavings,
} ETexturePoolStats;

/** Memory churn stats. */
typedef enum EMemoryChurnStats {
  STAT_MallocCalls = STAT_MemoryChurnFirstStat,
  STAT_FreeCalls,
  STAT_ReallocCalls,
  STAT_PhysicalAllocCalls,
  STAT_PhysicalFreeCalls,
  STAT_TotalAllocatorCalls,
} EMemoryChurnStats;

/**
 * Holds the list of stat ids for object stat gathering
 */
typedef enum EObjectStats {
  STAT_ConstructObject = STAT_ObjectFirstStat,
  STAT_LoadConfig,
  STAT_LoadLocalized,
  STAT_LoadObject,
  STAT_FindObject,
  STAT_FindObjectFast,
  STAT_InitProperties,
  STAT_NameTableEntries,
  STAT_NameTableAnsiEntries,
  STAT_NameTableUnicodeEntries,
  STAT_NameTableMemorySize,
  STAT_DestroyObject,
} EObjectStats;

/* Flags for loading objects. */
typedef enum ELoadFlags {
  LOAD_None			= 0x00000000,	// No flags.
  LOAD_SeekFree		= 0x00000001,	// Loads the package via the seek free loading path/ reader
  LOAD_NoWarn			= 0x00000002,	// Don't display warning if load fails.
  LOAD_Throw			= 0x00000008,	// Throw exceptions upon failure.
  LOAD_Verify			= 0x00000010,	// Only verify existance; don't actually load.
  LOAD_AllowDll		= 0x00000020,	// Allow plain DLLs.
  LOAD_DisallowFiles  = 0x00000040,	// Don't load from file.
  LOAD_NoVerify       = 0x00000080,   // Don't verify imports yet.
  LOAD_Quiet			= 0x00002000,   // No log warnings.
  LOAD_FindIfFail		= 0x00004000,	// Tries FindObject if a linker cannot be obtained (e.g. package is currently being compiled)
  LOAD_MemoryReader	= 0x00008000,	// Loads the file into memory and serializes from there.

  //@script patcher
  LOAD_RemappedPackage= 0x00010000,	// Indicates that is a native script package which has been renamed - GScriptPackageSuffix should be appended to the package name

  LOAD_NoRedirects	= 0x00020000,	// Never follow redirects when loading objects; redirected loads will fail
} ELoadFlags;

/* Flags for saving packages */
typedef enum ESaveFlags {
  SAVE_None			= 0x00000000,	// No flags
  SAVE_NoError		= 0x00000001,	// Don't generate errors on save
  SAVE_FromAutosave	= 0x00000002,   // Used to indicate this save was initiated automatically
  SAVE_KeepDirty		= 0x00000004,	// Do not clear the dirty flag when saving
} ESaveFlags;

/* Package flags. */
typedef enum EPackageFlags {
  PKG_AllowDownload				= 0x00000001,	// Allow downloading package.
  PKG_ClientOptional				= 0x00000002,	// Purely optional for clients.
  PKG_ServerSideOnly				= 0x00000004,   // Only needed on the server side.
  PKG_Cooked						= 0x00000008,	// Whether this package has been cooked for the target platform.
  PKG_Unsecure					= 0x00000010,   // Not trusted.
  PKG_SavedWithNewerVersion		= 0x00000020,	// Package was saved with newer version.
  PKG_Need						= 0x00008000,	// Client needs to download this package.
  PKG_Compiling					= 0x00010000,	// package is currently being compiled
  PKG_ContainsMap					= 0x00020000,	// Set if the package contains a ULevel/ UWorld object
  PKG_Trash						= 0x00040000,	// Set if the package was loaded from the trashcan
  PKG_DisallowLazyLoading			= 0x00080000,	// Set if the archive serializing this package cannot use lazy loading
  PKG_PlayInEditor				= 0x00100000,	// Set if the package was created for the purpose of PIE
  PKG_ContainsScript				= 0x00200000,	// Package is allowed to contain UClasses and unrealscript
  PKG_ContainsDebugInfo			= 0x00400000,	// Package contains debug info (for UDebugger)
  PKG_RequireImportsAlreadyLoaded	= 0x00800000,	// Package requires all its imports to already have been loaded
  PKG_SelfContainedLighting		= 0x01000000,	// All lighting in this package should be self contained
  PKG_StoreCompressed				= 0x02000000,	// Package is being stored compressed, requires archive support for compression
  PKG_StoreFullyCompressed		= 0x04000000,	// Package is serialized normally, and then fully compressed after (must be decompressed before LoadPackage is called)
  PKG_ContainsInlinedShaders		= 0x08000000,	// Package was cooked allowing materials to inline their FMaterials (and hence shaders)
  PKG_ContainsFaceFXData			= 0x10000000,	// Package contains FaceFX assets and/or animsets
  PKG_NoExportAllowed				= 0x20000000,	// Package was NOT created by a modder.  Internal data not for export
  PKG_StrippedSource				= 0x40000000,	// Source has been removed to compress the package size
} EPackageFlags;

/** 
 * These are the types of PerfMem RunResults you the system understands and can achieve.  They are stored in the table as we
 * will get "valid" numbers but we ran OOM.  We want to list the numbers in the OOM case because there is probably something that
 * jumped up to cause the OOM (e.g. vertex lighting).
 **/

//NEW: trace facility
typedef enum ProcessEventType {
  PE_Toggle,
  PE_Suppress,
  PE_Enable,
} ProcessEventType;

typedef enum EDistributionVectorMirrorFlags {
  EDVMF_Same              =0,
  EDVMF_Different         =1,
  EDVMF_Mirror            =2,
  EDVMF_MAX               =3,
} EDistributionVectorMirrorFlags;

typedef enum EDistributionVectorLockFlags {
  EDVLF_None              =0,
  EDVLF_XY                =1,
  EDVLF_XZ                =2,
  EDVLF_YZ                =3,
  EDVLF_XYZ               =4,
  EDVLF_MAX               =5,
} EDistributionVectorLockFlags;

#define DECLARE_UINT64(x)  x##ULL

typedef enum EObjectFlagsEnum {
  RF_InSingularFunc = 0x0000000000000002ULL,
  RF_StateChanged = 0x0000000000000004ULL,
  RF_DebugPostLoad = 0x0000000000000008ULL,
  RF_DebugSerialize = 0x0000000000000010ULL,
  RF_DebugFinishDestroyed = 0x0000000000000020ULL,
  RF_EdSelected = 0x0000000000000040ULL,
  RF_ZombieComponent = 0x0000000000000080ULL,
  RF_Protected = 0x0000000000000100ULL,
  RF_ClassDefaultObject = 0x0000000000000200ULL,
  RF_ArchetypeObject = 0x0000000000000400ULL,
  RF_ForceTagExp = 0x0000000000000800ULL,
  RF_TokenStreamAssembled = 0x0000000000001000ULL,
  RF_MisalignedObject = 0x0000000000002000ULL,
  RF_RootSet = 0x0000000000004000ULL,
  RF_BeginDestroyed = 0x0000000000008000ULL,
  RF_FinishDestroyed = 0x0000000000010000ULL,
  RF_DebugBeginDestroyed = 0x0000000000020000ULL,
  RF_MarkedByCooker = 0x0000000000040000ULL,
  RF_LocalizedResource = 0x0000000000080000ULL,
  RF_InitializedProps = 0x0000000000100000ULL,
  RF_PendingFieldPatches = 0x0000000000200000ULL,
  RF_IsCrossLevelReferenced = 0x0000000000400000ULL,
  RF_Saved = 0x0000000080000000ULL,
  RF_Transactional = 0x0000000100000000ULL,
  RF_Unreachable = 0x0000000200000000ULL,
  RF_Public = 0x0000000400000000ULL,
  RF_TagImp = 0x0000000800000000ULL,
  RF_TagExp = 0x0000001000000000ULL,
  RF_Obsolete = 0x0000002000000000ULL,
  RF_TagGarbage = 0x0000004000000000ULL,
  RF_DisregardForGC = 0x0000008000000000ULL,
  RF_PerObjectLocalized = 0x0000010000000000ULL,
  RF_NeedLoad = 0x0000020000000000ULL,
  RF_AsyncLoading = 0x0000040000000000ULL,
  RF_NeedPostLoadSubobjects = 0x0000080000000000ULL,
  RF_Suppress = 0x0000100000000000ULL,
  RF_InEndState = 0x0000200000000000ULL,
  RF_Transient = 0x0000400000000000ULL,
  RF_Cooked = 0x0000800000000000ULL,
  RF_LoadForClient = 0x0001000000000000ULL,
  RF_LoadForServer = 0x0002000000000000ULL,
  RF_LoadForEdit = 0x0004000000000000ULL,
  RF_Standalone = 0x0008000000000000ULL,
  RF_NotForClient = 0x0010000000000000ULL,
  RF_NotForServer = 0x0020000000000000ULL,
  RF_NotForEdit = 0x0040000000000000ULL,
  RF_NeedPostLoad = 0x0100000000000000ULL,
  RF_HasStack = 0x0200000000000000ULL,
  RF_Native = 0x0400000000000000ULL,
  RF_Marked = 0x0800000000000000ULL,
  RF_ErrorShutdown = 0x1000000000000000LL,
  RF_PendingKill = 0x2000000000000000ULL,
  RF_ContextFlags = (RF_NotForClient | RF_NotForServer | RF_NotForEdit),
  RF_LoadContextFlags = (RF_LoadForClient | RF_LoadForServer | RF_LoadForEdit),
  RF_Load = (RF_ContextFlags | RF_LoadContextFlags | RF_Public | RF_Standalone | RF_Native | RF_Obsolete | RF_Protected | RF_Transactional | RF_HasStack | RF_PerObjectLocalized | RF_ClassDefaultObject | RF_ArchetypeObject | RF_LocalizedResource),
  RF_Keep = (RF_Native | RF_Marked | RF_PerObjectLocalized | RF_MisalignedObject | RF_DisregardForGC | RF_RootSet | RF_LocalizedResource),
  RF_ScriptMask = (RF_Transactional | RF_Public | RF_Transient | RF_NotForClient | RF_NotForServer | RF_NotForEdit | RF_Standalone),
  RF_UndoRedoMask = (RF_PendingKill),
  RF_PropagateToSubObjects = (RF_Public | RF_ArchetypeObject | RF_Transactional),
  RF_AllFlags = 0xFFFFFFFFFFFFFFFFULL
} EObjectFlagsEnum;

typedef enum CPF {
  CPF_Edit	=				DECLARE_UINT64(0x0000000000000001),		// Property is user-settable in the editor.
  CPF_Const =					DECLARE_UINT64(0x0000000000000002),		// Actor's property always matches class's default actor property.
  CPF_Input =					DECLARE_UINT64(0x0000000000000004),		// Variable is writable by the input system.
  CPF_ExportObject =			DECLARE_UINT64(0x0000000000000008),		// Object can be exported with actor.
  CPF_OptionalParm =			DECLARE_UINT64(0x0000000000000010),		// Optional parameter (if CPF_Param is set),.
  CPF_Net =						DECLARE_UINT64(0x0000000000000020),		// Property is relevant to network replication.
  CPF_EditFixedSize =			DECLARE_UINT64(0x0000000000000040),		// Indicates that elements of an array can be modified, but its size cannot be changed.
  CPF_Parm =					DECLARE_UINT64(0x0000000000000080),		// Function/When call parameter.
  CPF_OutParm =					DECLARE_UINT64(0x0000000000000100),		// Value is copied out after function call.
  CPF_SkipParm =				DECLARE_UINT64(0x0000000000000200),		// Property is a short-circuitable evaluation function parm.
  CPF_ReturnParm =				DECLARE_UINT64(0x0000000000000400),		// Return value.
  CPF_CoerceParm =				DECLARE_UINT64(0x0000000000000800),		// Coerce args into this function parameter.
  CPF_Native =      			DECLARE_UINT64(0x0000000000001000),		// Property is native: C++ code is responsible for serializing it.
  CPF_Transient =   			DECLARE_UINT64(0x0000000000002000),		// Property is transient: shouldn't be saved, zero-filled at load time.
  CPF_Config =      			DECLARE_UINT64(0x0000000000004000),		// Property should be loaded/saved as permanent profile.
  CPF_Localized =   			DECLARE_UINT64(0x0000000000008000),		// Property should be loaded as localizable text.

   CPF_EditConst =   			DECLARE_UINT64(0x0000000000020000),		// Property is uneditable in the editor.
   CPF_GlobalConfig =			DECLARE_UINT64(0x0000000000040000),		// Load config from base class, not subclass.
   CPF_Component =				DECLARE_UINT64(0x0000000000080000),		// Property containts component references.
   CPF_AlwaysInit =				DECLARE_UINT64(0x0000000000100000),		// Property should never be exported as NoInit	(@todo - this doesn't need to be a property flag...only used during make),
   CPF_DuplicateTransient =		DECLARE_UINT64(0x0000000000200000),		// Property should always be reset to the default value during any type of duplication (copy/paste, binary duplication, etc.),
   CPF_NeedCtorLink =			DECLARE_UINT64(0x0000000000400000),		// Fields need construction/destruction.
   CPF_NoExport =    			DECLARE_UINT64(0x0000000000800000),		// Property should not be exported to the native class header file.
    CPF_NoImport =				DECLARE_UINT64(0x0000000001000000),		// Property should not be imported when creating an object from text (copy/paste),
   CPF_NoClear =					DECLARE_UINT64(0x0000000002000000),		// Hide clear (and browse), button.
   CPF_EditInline =				DECLARE_UINT64(0x0000000004000000),		// Edit this object reference inline.

  CPF_EditInlineUse =			DECLARE_UINT64(0x0000000010000000),		// EditInline with Use button.
  CPF_Deprecated =  			DECLARE_UINT64(0x0000000020000000),		// Property is deprecated.  Read it from an archive, but don't save it.
  CPF_DataBinding =				DECLARE_UINT64(0x0000000040000000),		// Indicates that this property should be exposed to data stores
  CPF_SerializeText =			DECLARE_UINT64(0x0000000080000000),		// Native property should be serialized as text (ImportText, ExportText),

  CPF_RepNotify =				DECLARE_UINT64(0x0000000100000000),		// Notify actors when a property is replicated
  CPF_Interp =					DECLARE_UINT64(0x0000000200000000),		// interpolatable property for use with matinee
  CPF_NonTransactional =		DECLARE_UINT64(0x0000000400000000),		// Property isn't transacted

  CPF_EditorOnly =				DECLARE_UINT64(0x0000000800000000),		// Property should only be loaded in the editor
  CPF_NotForConsole =			DECLARE_UINT64(0x0000001000000000),		// Property should not be loaded on console (or be a console cooker commandlet),
  CPF_RepRetry =				DECLARE_UINT64(0x0000002000000000),		// retry replication of this property if it fails to be fully sent (e.g. object references not yet available to serialize over the network),
  CPF_PrivateWrite =			DECLARE_UINT64(0x0000004000000000),		// property is const outside of the class it was declared in
  CPF_ProtectedWrite =			DECLARE_UINT64(0x0000008000000000),		// property is const outside of the class it was declared in and subclasses

  //@todo ronp - temporary until we add UArchetypeProperty
  CPF_ArchetypeProperty =		DECLARE_UINT64(0x0000010000000000),		// property should be ignored by archives which have ArIgnoreArchetypeRef set

  CPF_EditHide =				DECLARE_UINT64(0x0000020000000000),		// property should never be shown in a properties window.
  CPF_EditTextBox =				DECLARE_UINT64(0x0000040000000000),		// property can be edited using a text dialog box.

  CPF_CrossLevelPassive =		DECLARE_UINT64(0x0000100000000000),		// property can point across levels, and will be serialized properly, but assumes it's target exists in-game (non-editor)
  CPF_CrossLevelActive =		DECLARE_UINT64(0x0000200000000000),		// property can point across levels, and will be serialized properly, and will be updated when the target is streamed in/out

  /** the flags that should never be set on interface properties */
  CPF_InterfaceClearMask =		(CPF_NeedCtorLink|CPF_ExportObject),

  /** a combination of both cross level types */
  CPF_CrossLevel = (CPF_CrossLevelPassive | CPF_CrossLevelActive),
  /** @name Combinations flags */
  //@{
  CPF_ParmFlags =				(CPF_OptionalParm | CPF_Parm | CPF_OutParm | CPF_SkipParm | CPF_ReturnParm | CPF_CoerceParm),
  CPF_PropagateFromStruct =		(CPF_Const | CPF_Native | CPF_Transient),
  CPF_PropagateToArrayInner =	(CPF_ExportObject | CPF_EditInline | CPF_EditInlineUse | CPF_Localized | CPF_Component | CPF_Config | CPF_AlwaysInit | CPF_EditConst | CPF_Deprecated | CPF_SerializeText | CPF_CrossLevel ),

  CPF_AllFlags =				DECLARE_UINT64(0xFFFFFFFFFFFFFFFF)
} CPF;

/**
 * Enum of different supported reference type tokens.
 */
typedef enum EGCReferenceType {
  GCRT_None			= 0,
  GCRT_Object,
  GCRT_PersistentObject,
  GCRT_ArrayObject,
  GCRT_ArrayStruct,
  GCRT_FixedArray,
  GCRT_EndOfStream,
  GCRT_ScriptDelegate,
} EGCReferenceType;


// File manager.
enum EFileTimes
{
  FILETIME_Create				= 0,
  FILETIME_LastAccess			= 1,
  FILETIME_LastWrite			= 2,
};
enum EFileWrite
{
  FILEWRITE_NoFail            = 0x01,
  FILEWRITE_NoReplaceExisting = 0x02,
  FILEWRITE_EvenIfReadOnly    = 0x04,
  FILEWRITE_Append			= 0x08,
  FILEWRITE_AllowRead         = 0x10,
  FILEWRITE_SaveGame			= 0x20,		// The platform needs to create a platform-specific save game file. The passed in path is relative to the "base" of savegames for that platform
  FILEWRITE_Async				= 0x40,		// Attempt to create an async file archive (use the FArchive::IsCloseComplete to tell if it's completed). Supported in only a VERY small set of cases
};
enum EFileRead
{
  FILEREAD_NoFail             = 0x01,
  FILEREAD_SaveGame			= 0x02,		// The platform needs to load a platform-specific save game file. The passed in path is relative to the "base" of savegames for that platform
  FILEREAD_Silent				= 0x04,
};
enum ECopyResult
{
  COPY_OK						= 0x00,
  COPY_MiscFail				= 0x01,
  COPY_ReadFail				= 0x02,
  COPY_WriteFail				= 0x03,
  COPY_Canceled				= 0x06,
};

enum EFileOpenFlags {
  IO_READ			= 0x01,					// Open for reading
  IO_WRITE		= 0x02,					// Open for writing
  IO_READWRITE	= IO_READ | IO_WRITE,	// Combination of reading and writing
  IO_APPEND		= 0x40,					// When writing, keep the existing data, set the filepointer to the end of the existing data
};

enum EFileSeekFlags
{
  IO_SEEK_BEGIN,
  IO_SEEK_CURRENT,
  IO_SEEK_END
};

typedef enum EUglyHackFlags {
	HACK_DisableSubobjectInstancing		=	0x01,
	HACK_ClassLoadingDisabled			=	0x02,	// indicates that classes aren't being loaded from disk, thus all classes should be treated as intrinsic classes.
	HACK_UpdateArchetypeFromInstance	=	0x04,
	HACK_KeepSequenceObject				=	0x08,	// prevents the code that removes sequences objects from sequences from marking the object pending kill
	HACK_IsReloadObjArc					=	0x10,

	/**
	 * prevents component instancing code from instancing new components from templates;
	 * useful in certain commandlets [like diffpackage] that want to look at data from disk only.
	 * does not prevent existing instanced components from being loaded from disk.
	 */
	HACK_DisableComponentCreation		=	0x40,

	/** Disable loading of objects not contained within script files; used during script compilation */
	HACK_VerifyObjectReferencesOnly		=	0x80,

	/** Bypassses an assert in StaticDuplicateObjectEx() */
	HACK_AllowDifferingClassSizesWhenDuplicatingObjects	= 0x100,

	HACK_SkipCopyDuringRegistration = 0x200, // when performing native registration, skip copying property values from the template when constructing default objects

	/** when constructing objects, use the fast path on consoles... */
	HACK_FastPathUniqueNameGeneration = 0x400, 
} EUglyHackFlags;

/* Flags controlling [de]compression. */
typedef enum ECompressionFlags {
  /** No compression																*/
  COMPRESS_None					= 0x00,
  /** Compress with ZLIB															*/
  COMPRESS_ZLIB 					= 0x01,
  /** Compress with LZO															*/
  COMPRESS_LZO 					= 0x02,
  /** Compress with LZX															*/
  COMPRESS_LZX					= 0x04,
  /** Prefer compression that compresses smaller (ONLY VALID FOR COMPRESSION)		*/
  COMPRESS_BiasMemory 			= 0x10,
  /** Prefer compression that compresses faster (ONLY VALID FOR COMPRESSION)		*/
  COMPRESS_BiasSpeed				= 0x20,
  /** If this flag is present, decompression will not happen on the SPUs.			*/
  COMPRESS_ForcePPUDecompressZLib	= 0x80
} ECompressionFlags;


/* Accepting connection responses. */
typedef enum EAcceptConnection {
  ACCEPTC_Reject,	// Reject the connection.
  ACCEPTC_Accept, // Accept the connection.
  ACCEPTC_Ignore, // Ignore it, sending no reply, while server travelling.
} EAcceptConnection;

/* State of a connection. */
typedef enum EConnectionState {
  USOCK_Invalid   = 0, // Connection is invalid, possibly uninitialized.
  USOCK_Closed    = 1, // Connection permanently closed.
  USOCK_Pending	= 2, // Connection is awaiting connection.
  USOCK_Open      = 3, // Connection is open.
} EConnectionState;

typedef enum ESourceControlState {
  /** Don't know or don't care. */
  SCC_DontCare		= 0,

  /** File is checked out to current user. */
  SCC_CheckedOut		= 1,

  /** File is not checked out (but IS controlled by the source control system). */
  SCC_ReadOnly		= 2,

  /** File is not at the head revision - must sync the file before editing. */
  SCC_NotCurrent		= 3,

  /** File is new and not in the depot - needs to be added. */
  SCC_NotInDepot		= 4,

  /** File is checked out by another user and cannot be checked out locally. */
  SCC_CheckedOutOther	= 5,

  /** Certain packages are best ignored by the SCC system (MyLevel, Transient, etc). */
  SCC_Ignore			= 6
} ESourceControlState;


/* Group of bitflag values for indicating which type of content browser update is desired. */
typedef enum EContentBrowserRefreshFlag {
  CBR_None					= 0x00000000,

  /**
   * A change has occurred which affects the way the visual representation of this object, or this object's package
   * has occurred.  Examples are marking the package dirty, updating a texture, fully loading a package, etc.
   */
  CBR_UpdatePackageListUI		= 0x00000001,
  CBR_UpdateCollectionListUI	= 0x00000002,
  CBR_UpdateAssetListUI		= 0x00000004,

  /**
   * Internal flags used by the combo flags below.  They are used solely for making checks against refresh flag
   * values more concise.
   * While these flags can be used on their own, using them will [probably] not result in desired behavior.
   */
  CBR_InternalPackageUpdate	= 0x00000010,
  CBR_InternalCollectionUpdate= 0x00000020,
  CBR_InternalAssetUpdate		= 0x00000040,
  CBR_InternalQuickAssetUpdate= 0x00000080,

  /** A change has occurred which affects the SCC state of the object's package (i.e. check-in, check-out, etc.) */
  CBR_UpdateSCCState			= 0x00000100,

  /** Asset view should be updated to display only certain objects */
  CBR_SyncAssetView			= 0x00000200,

  /** a new object was created - add system tags to the local database */
  CBR_ObjectCreated			= 0x00000400,

  /** an object was deleted - remove tags from the local database */
  CBR_ObjectDeleted			= 0x00000800,

  /** an object was renamed - update system tags and existing tags/collections */
  CBR_ObjectRenamed			= 0x00001000,

  /** focus the content browser */
  CBR_FocusBrowser			= 0x00002000,

  /** Activates (i.e. opens the object editor for) the object specified in the event parameters */
  CBR_ActivateObject			= 0x00004000,

  /** Empties the content browsers selection and causes a refresh */
  CBR_EmptySelection			= 0x00008000,

  /** A package, that doesn't exist on disk yet, has been saved to disk - update the package view */
  CBR_NewPackageSaved			= 0x00010000,

  /** When used in conjunction with other flags that might cause an asset view sync operation, intentionally ignores the sync request */
  CBR_NoSync					= 0x00020000,

  /** Used to clear the current filter */
  CBR_ClearFilter				= 0x00040000,

  /**
   * A change has occurred which requires the respective list to repopulate its elements.  Examples include
   * creating or deleting an object, creating a collection, etc.
   */
  CBR_UpdatePackageList		= CBR_InternalPackageUpdate		| CBR_InternalQuickAssetUpdate | CBR_UpdatePackageListUI ,
  CBR_UpdateCollectionList	= CBR_InternalCollectionUpdate	| CBR_UpdateCollectionListUI,
  CBR_UpdateAssetList			= CBR_InternalAssetUpdate		| CBR_UpdateAssetListUI,

  /** All flags, for consistency */
  CBR_All						= 0xFFFFFFFF,
} EContentBrowserRefreshFlag;

// Define a message as an enumeration.
#ifndef REGISTER_NAME
  #define REGISTER_NAME(num,name) NAME_##name = num,
  #define REGISTERING_ENUM
  typedef enum EName {
#endif

/*-----------------------------------------------------------------------------
  Hardcoded names which are not messages.
-----------------------------------------------------------------------------*/

// Special zero value, meaning no name.
REGISTER_NAME(   0, None             )

// Class property types
REGISTER_NAME(   1, ByteProperty     )
REGISTER_NAME(   2, IntProperty      )
REGISTER_NAME(   3, BoolProperty     )
REGISTER_NAME(   4, FloatProperty    )
REGISTER_NAME(   5, ObjectProperty   )
REGISTER_NAME(   6, NameProperty     )
REGISTER_NAME(   7, DelegateProperty )
REGISTER_NAME(   8, ClassProperty    )
REGISTER_NAME(   9, ArrayProperty    )
REGISTER_NAME(  10, StructProperty   )
REGISTER_NAME(  11, VectorProperty   )
REGISTER_NAME(  12, RotatorProperty  )
REGISTER_NAME(  13, StrProperty      )
REGISTER_NAME(  14, MapProperty      )
REGISTER_NAME(	15,	InterfaceProperty)

// Packages.
REGISTER_NAME(  20, Core			 )
REGISTER_NAME(  21, Engine			 )
REGISTER_NAME(  22, Editor           )
REGISTER_NAME(  23, Gameplay         )

// UnrealScript types.
REGISTER_NAME(  80, Byte		     )
REGISTER_NAME(  81, Int			     )
REGISTER_NAME(  82, Bool		     )
REGISTER_NAME(  83, Float		     )
REGISTER_NAME(  84, Name		     )
REGISTER_NAME(  85, String		     )
REGISTER_NAME(  86, Struct			 )
REGISTER_NAME(  87, Vector		     )
REGISTER_NAME(  88, Rotator	         )
REGISTER_NAME(  89, SHVector         )
REGISTER_NAME(  90, Color            )
REGISTER_NAME(  91, Plane            )
REGISTER_NAME(  92, Button           )
REGISTER_NAME(  94, Matrix			 )
REGISTER_NAME(	95,	LinearColor		 )
REGISTER_NAME(	96, QWord			 )
REGISTER_NAME(	97, Pointer			 )
REGISTER_NAME(	98, Double			 )
REGISTER_NAME(	99, Quat			 )
REGISTER_NAME(1250, Vector4          )

// Keywords.
REGISTER_NAME( 100, Begin			 )
REGISTER_NAME( 102, State            )
REGISTER_NAME( 103, Function         )
REGISTER_NAME( 104, Self             )
REGISTER_NAME( 105, TRUE             )
REGISTER_NAME( 106, FALSE            )
REGISTER_NAME( 107, Transient        )
REGISTER_NAME( 117, Enum			 )
REGISTER_NAME( 119, Replication      )
REGISTER_NAME( 120, Reliable         )
REGISTER_NAME( 121, Unreliable       )
REGISTER_NAME( 122, Always           )
REGISTER_NAME( 123, Server			 )
REGISTER_NAME( 124, Client			 )
REGISTER_NAME( 125, K2Call			 )
REGISTER_NAME( 126, K2Override		 )
REGISTER_NAME( 127, K2Pure			 )

// Object class names.
REGISTER_NAME( 150, Field            )
REGISTER_NAME( 151, Object           )
REGISTER_NAME( 152, TextBuffer       )
REGISTER_NAME( 153, Linker           )
REGISTER_NAME( 154, LinkerLoad       )
REGISTER_NAME( 155, LinkerSave       )
REGISTER_NAME( 156, Subsystem        )
REGISTER_NAME( 157, Factory          )
REGISTER_NAME( 158, TextBufferFactory)
REGISTER_NAME( 159, Exporter         )
REGISTER_NAME( 160, StackNode        )
REGISTER_NAME( 161, Property         )
REGISTER_NAME( 162, Camera           )
REGISTER_NAME( 163, PlayerInput      )
REGISTER_NAME( 164, Actor			 )
REGISTER_NAME( 165, ObjectRedirector )
REGISTER_NAME( 166, ObjectArchetype  )

// Constants.
REGISTER_NAME( 600, Vect)
REGISTER_NAME( 601, Rot)
REGISTER_NAME( 605, ArrayCount)
REGISTER_NAME( 606, EnumCount)
REGISTER_NAME( 607, Rng)
REGISTER_NAME( 608, NameOf)

// Flow control.
REGISTER_NAME( 620, Else)
REGISTER_NAME( 621, If)
REGISTER_NAME( 622, Goto)
REGISTER_NAME( 623, Stop)
REGISTER_NAME( 625, Until)
REGISTER_NAME( 626, While)
REGISTER_NAME( 627, Do)
REGISTER_NAME( 628, Break)
REGISTER_NAME( 629, For)
REGISTER_NAME( 630, ForEach)
REGISTER_NAME( 631, Assert)
REGISTER_NAME( 632, Switch)
REGISTER_NAME( 633, Case)
REGISTER_NAME( 634, Default)
REGISTER_NAME( 635, Continue)
REGISTER_NAME( 636, ElseIf)

// Variable overrides.
REGISTER_NAME( 640, Private)
REGISTER_NAME( 641, Const)
REGISTER_NAME( 642, Out)
REGISTER_NAME( 643, Export)
REGISTER_NAME( 644, DuplicateTransient )
REGISTER_NAME( 645, NoImport )
REGISTER_NAME( 646, Skip)
REGISTER_NAME( 647, Coerce)
REGISTER_NAME( 648, Optional)
REGISTER_NAME( 649, Input)
REGISTER_NAME( 650, Config)
REGISTER_NAME( 651, EditorOnly)
REGISTER_NAME( 652, NotForConsole)
REGISTER_NAME( 653, EditConst)
REGISTER_NAME( 654, Localized)
REGISTER_NAME( 655, GlobalConfig)
REGISTER_NAME( 656, SafeReplace)
REGISTER_NAME( 657, New)
REGISTER_NAME( 658, Protected)
REGISTER_NAME( 659, Public)
REGISTER_NAME( 660, EditInline)
REGISTER_NAME( 661, EditInlineUse)
REGISTER_NAME( 662, Deprecated)
REGISTER_NAME( 663, Atomic)
REGISTER_NAME( 664, Immutable)
REGISTER_NAME( 665, Automated )
REGISTER_NAME( 666, RepNotify )
REGISTER_NAME( 667, Interp )
REGISTER_NAME( 668, NoClear )
REGISTER_NAME( 669, NonTransactional )
REGISTER_NAME( 670, EditFixedSize)
REGISTER_NAME( 940, ImmutableWhenCooked )
REGISTER_NAME( 941, RepRetry )
REGISTER_NAME( 942, PrivateWrite )
REGISTER_NAME( 943, ProtectedWrite )
REGISTER_NAME( 944, EditHide)
REGISTER_NAME( 945, EditTextBox)

// Class overrides.
REGISTER_NAME( 671, Intrinsic)
REGISTER_NAME( 672, Within)
REGISTER_NAME( 673, Abstract)
REGISTER_NAME( 674, Package)
REGISTER_NAME( 675, Guid)
REGISTER_NAME( 676, Parent)
REGISTER_NAME( 677, Class)
REGISTER_NAME( 678, Extends)
REGISTER_NAME( 679, NoExport)
REGISTER_NAME( 680, Placeable)
REGISTER_NAME( 681, PerObjectConfig)
REGISTER_NAME( 682, NativeReplication)
REGISTER_NAME( 683, NotPlaceable)
REGISTER_NAME( 684,	EditInlineNew)
REGISTER_NAME( 685,	NotEditInlineNew)
REGISTER_NAME( 686,	HideCategories)
REGISTER_NAME( 687,	ShowCategories)
REGISTER_NAME( 688,	CollapseCategories)
REGISTER_NAME( 689,	DontCollapseCategories)
REGISTER_NAME( 698, DependsOn)
REGISTER_NAME( 699, HideDropDown)

REGISTER_NAME( 950, Implements )
REGISTER_NAME( 951, Interface )
REGISTER_NAME( 952, Inherits)
REGISTER_NAME( 953, PerObjectLocalized)
REGISTER_NAME( 954, NonTransient)
REGISTER_NAME( 955, Archetype)

REGISTER_NAME( 956, StrictConfig )
REGISTER_NAME( 957, UnusedStructKeyword1 )
REGISTER_NAME( 958, UnusedStructKeyword2 )
REGISTER_NAME( 959, SerializeText)
REGISTER_NAME( 960, CrossLevel)
REGISTER_NAME( 961, CrossLevelActive)
REGISTER_NAME( 962, CrossLevelPassive)
REGISTER_NAME( 963, ClassGroup)

// State overrides.
REGISTER_NAME( 690, Auto)
REGISTER_NAME( 691, Ignores)

// Auto-instanced subobjects
REGISTER_NAME( 692, Instanced)

// Components.
REGISTER_NAME( 693, Component)
REGISTER_NAME( 694, Components)

// Calling overrides.
REGISTER_NAME( 695, Global)
REGISTER_NAME( 696, Super)
REGISTER_NAME( 697, Outer)

// Function overrides.
REGISTER_NAME( 700, Operator)
REGISTER_NAME( 701, PreOperator)
REGISTER_NAME( 702, PostOperator)
REGISTER_NAME( 703, Final)
REGISTER_NAME( 704, Iterator)
REGISTER_NAME( 705, Latent)
REGISTER_NAME( 706, Return)
REGISTER_NAME( 707, Singular)
REGISTER_NAME( 708, Simulated)
REGISTER_NAME( 709, Exec)
REGISTER_NAME( 710, Event)
REGISTER_NAME( 711, Static)
REGISTER_NAME( 712, Native)
REGISTER_NAME( 713, Invariant)
REGISTER_NAME( 714, Delegate)
REGISTER_NAME( 715, Virtual)
REGISTER_NAME( 716, NoExportHeader)
REGISTER_NAME( 717, DLLImport)
REGISTER_NAME( 718, NativeOnly)
REGISTER_NAME( 719, UnusedFunctionKeyword3)

// Variable declaration.
REGISTER_NAME( 720, Var)
REGISTER_NAME( 721, Local)
REGISTER_NAME( 722, Import)
REGISTER_NAME( 723, From)

// Special commands.
REGISTER_NAME( 730, Spawn)
REGISTER_NAME( 731, Array)
REGISTER_NAME( 732, Map)
REGISTER_NAME( 733,	AutoExpandCategories)
REGISTER_NAME( 734, AutoCollapseCategories)
REGISTER_NAME( 735, DontAutoCollapseCategories)
REGISTER_NAME( 736, DontSortCategories)

// Misc.
REGISTER_NAME( 740, Tag)
REGISTER_NAME( 742, Role)
REGISTER_NAME( 743, RemoteRole)
REGISTER_NAME( 744, System)
REGISTER_NAME( 745, User)
REGISTER_NAME( 746, PersistentLevel)
REGISTER_NAME( 747, TheWorld)

// Platforms
REGISTER_NAME( 750, Windows)
REGISTER_NAME( 751, XBox)
REGISTER_NAME( 752, PlayStation)
REGISTER_NAME( 753, Linux)
REGISTER_NAME( 754, MacOSX)
REGISTER_NAME( 755, PC)

// Log messages.
REGISTER_NAME( 756, DevDecals)
REGISTER_NAME( 757, PerfWarning)
REGISTER_NAME( 758, DevStreaming)
REGISTER_NAME( 759, DevLive)
REGISTER_NAME( 760, Log)
REGISTER_NAME( 761, Critical)
REGISTER_NAME( 762, Init)
REGISTER_NAME( 763, Exit)
REGISTER_NAME( 764, Cmd)
REGISTER_NAME( 765, Play)
REGISTER_NAME( 766, Console)
REGISTER_NAME( 767, Warning)
REGISTER_NAME( 768, ExecWarning)
REGISTER_NAME( 769, ScriptWarning)
REGISTER_NAME( 770, ScriptLog)
REGISTER_NAME( 771, Dev)
REGISTER_NAME( 772, DevNet)
REGISTER_NAME( 773, DevPath)
REGISTER_NAME( 774, DevNetTraffic)
REGISTER_NAME( 775, DevAudio)
REGISTER_NAME( 776, DevLoad)
REGISTER_NAME( 777, DevSave)
REGISTER_NAME( 778, DevGarbage)
REGISTER_NAME( 779, DevKill)
REGISTER_NAME( 780, DevReplace)
REGISTER_NAME( 781, DevUI)
REGISTER_NAME( 782, DevSound)
REGISTER_NAME( 783, DevCompile)
REGISTER_NAME( 784, DevBind)
REGISTER_NAME( 785, Localization)
REGISTER_NAME( 786, Compatibility)
REGISTER_NAME( 787, NetComeGo)
REGISTER_NAME( 788, Title)
REGISTER_NAME( 789, Error)
REGISTER_NAME( 790, Heading)
REGISTER_NAME( 791, SubHeading)
REGISTER_NAME( 792, FriendlyError)
REGISTER_NAME( 793, Progress)
REGISTER_NAME( 794, UserPrompt)
REGISTER_NAME( 795, SourceControl)
REGISTER_NAME( 796, DevPhysics)
REGISTER_NAME( 797, DevTick)
REGISTER_NAME( 798, DevStats)
REGISTER_NAME( 799, DevComponents)
REGISTER_NAME( 809, DevMemory)
REGISTER_NAME( 810, XMA)
REGISTER_NAME( 811, WAV)
REGISTER_NAME( 812, AILog)
REGISTER_NAME( 813, DevParticle)
REGISTER_NAME( 814, PerfEvent )
REGISTER_NAME( 815, LocalizationWarning )
REGISTER_NAME( 816, DevUIStyles )
REGISTER_NAME( 817, DevUIStates )
REGISTER_NAME( 818, DevUIFocus )
REGISTER_NAME( 819, ParticleWarn )
REGISTER_NAME( 854, UTrace )
REGISTER_NAME( 855, DevCollision )
REGISTER_NAME( 856, DevSHA )
REGISTER_NAME( 857, DevSpawn )
REGISTER_NAME( 858, DevAnim )
REGISTER_NAME( 859, Hack ) // useful for putting this where we have have hacks so we can see often they are spamming out
REGISTER_NAME( 1118, DevShaders )
REGISTER_NAME( 1119, DevDataBase )
REGISTER_NAME( 1120, DevDataStore )
REGISTER_NAME( 1121, DevAudioVerbose )
REGISTER_NAME( 1125, DevUIAnimation )
REGISTER_NAME( 1126, DevHDDCaching )
REGISTER_NAME( 1127, DevMovie )
REGISTER_NAME( 1128, DevShadersDetailed )
REGISTER_NAME( 1129, PlayerManagement )		// log messages related to creating and removing local players
REGISTER_NAME( 1130, DevPatch)		// log messages related to script patching and other console patching
REGISTER_NAME( 1131, DevLightmassSolver )
REGISTER_NAME( 1132, DevAssetDataBase )
REGISTER_NAME( 200, GameStats ) //log messages related to the recording of game stats
REGISTER_NAME( 201, DevFaceFX ) // log messages related to FaceFX
REGISTER_NAME( 202, DevCrossLevel ) // log messages relating to cross level references
REGISTER_NAME( 203, DevConfig ) // log messages relating to cross level references
REGISTER_NAME( 204, DevCamera ) // log messages relating to camera
REGISTER_NAME( 205, DebugState )
REGISTER_NAME( 206, DevAbsorbFuncs ) // log messages relating to absorbing non-simulated functions on clients
REGISTER_NAME( 207, DevLevelTools ) // log messages relating to level management tools
REGISTER_NAME( 208, DevGFxUI ) // log messages relating to the GFx UI
REGISTER_NAME( 209, DevGFxUIWarning ) // Warning log messages relating to the GFx UI
REGISTER_NAME( 210, DevNavMesh) // log messages relating to NavMesh
REGISTER_NAME( 211, DevNavMeshWarning ) // Warning log messages relating to NavMesh
REGISTER_NAME( 212, DevMCP ) // log messages relating to MCP/LSP tasks
REGISTER_NAME( 213, DevBeacon ) // log messages for beacon functionality
REGISTER_NAME( 214, DevHTTP ) // log messages for http requests

// Console text colors.
REGISTER_NAME( 800, White)
REGISTER_NAME( 801, Black)
REGISTER_NAME( 802, Red)
REGISTER_NAME( 803, Green)
REGISTER_NAME( 804, Blue)
REGISTER_NAME( 805, Cyan)
REGISTER_NAME( 806, Magenta)
REGISTER_NAME( 807, Yellow)
REGISTER_NAME( 808, DefaultColor)

// Misc.
REGISTER_NAME( 820, KeyType)
REGISTER_NAME( 821, KeyEvent)
REGISTER_NAME( 822, Write)
REGISTER_NAME( 823, Message)
REGISTER_NAME( 824, InitialState)
REGISTER_NAME( 825, Texture)
REGISTER_NAME( 826, Sound)
REGISTER_NAME( 827, FireTexture)
REGISTER_NAME( 828, IceTexture)
REGISTER_NAME( 829, WaterTexture)
REGISTER_NAME( 830, WaveTexture)
REGISTER_NAME( 831, WetTexture)
REGISTER_NAME( 832, Main)
REGISTER_NAME( 834, VideoChange)
REGISTER_NAME( 835, SendText)
REGISTER_NAME( 836, SendBinary)
REGISTER_NAME( 837, ConnectFailure)
REGISTER_NAME( 838, Length)
REGISTER_NAME( 839, Insert)
REGISTER_NAME( 840, Remove)
REGISTER_NAME( 1200, Add)
REGISTER_NAME( 1201, AddItem)
REGISTER_NAME( 1202, RemoveItem)
REGISTER_NAME( 1203, InsertItem)
REGISTER_NAME( 1204, Sort)
REGISTER_NAME( 841, Game)
REGISTER_NAME( 842, SequenceObjects)
REGISTER_NAME( 843, PausedState)
REGISTER_NAME( 844, ContinuedState)
REGISTER_NAME( 845, SelectionColor)
REGISTER_NAME( 846, Find)
REGISTER_NAME( 847, UI)
REGISTER_NAME( 848, DevCooking)
REGISTER_NAME( 849, DevOnline)
REGISTER_NAME( 850, DataBinding )
REGISTER_NAME( 851, OptionMusic)
REGISTER_NAME( 852, OptionSFX)
REGISTER_NAME( 853, OptionVoice)
REGISTER_NAME( 1122, Linear )
REGISTER_NAME( 1123, Point )
REGISTER_NAME( 1124, Aniso )
REGISTER_NAME( 860, Master )
REGISTER_NAME( 861, Ambient )
REGISTER_NAME( 862, UnGrouped )
REGISTER_NAME( 863, VoiceChat )
REGISTER_NAME( 1208, Brush )

/** Virtual data store names */
REGISTER_NAME( 865, Attributes)	// virtual data store for specifying text attributes (italic, bold, underline, etc.)
REGISTER_NAME( 866, Strings )	// virtual data store for looking up localized string values
REGISTER_NAME( 867, Images)		// virtual data store for specifying direct object references
REGISTER_NAME( 868, SceneData)	// virtual data store for per-scene data stores

// Script Preprocessor
REGISTER_NAME( 870, EndIf)
REGISTER_NAME( 871, Include)
REGISTER_NAME( 872, Define)
REGISTER_NAME( 873, Undefine)
REGISTER_NAME( 874, IsDefined)
REGISTER_NAME( 875, NotDefined)
REGISTER_NAME( 876, Debug)
REGISTER_NAME( 877, Counter)
REGISTER_NAME( 878, SetCounter)
REGISTER_NAME( 879, GetCounter)
REGISTER_NAME( 880, EngineVersion)
REGISTER_NAME( 881, IfCondition)

//@compatibility - class names that have property remapping (reserve 900 - 999)
REGISTER_NAME( 900, FontCharacter )
REGISTER_NAME( 901,	SourceState )
REGISTER_NAME( 902, InitChild2StartBone )
REGISTER_NAME( 903, SourceStyle )
REGISTER_NAME( 904, SoundCueLocalized )
REGISTER_NAME( 905, SoundCue )
REGISTER_NAME( 906, RawDistributionFloat )
REGISTER_NAME( 907, RawDistributionVector )
REGISTER_NAME( 908, UIDockingSet )
REGISTER_NAME( 909, DockPadding )
REGISTER_NAME( 912, ScaleType )
REGISTER_NAME( 913, EvalType)
REGISTER_NAME( 914, AutoSizePadding )

// PlayerController states added for efficient replication
REGISTER_NAME( 915, PlayerWalking )
REGISTER_NAME( 916, PlayerClimbing )
REGISTER_NAME( 917, PlayerDriving )
REGISTER_NAME( 918, PlayerSwimming )
REGISTER_NAME( 919, PlayerFlying )
REGISTER_NAME( 920, Spectating )
REGISTER_NAME( 921, PlayerWaiting )
REGISTER_NAME( 922, WaitingForPawn )
REGISTER_NAME( 923, RoundEnded )
REGISTER_NAME( 924, Dead )

// Game specific Logging Categories
REGISTER_NAME( 1000, Gear_General )

REGISTER_NAME( 1001, Gear_ActiveReload )
REGISTER_NAME( 1002, Gear_MiniGames )
REGISTER_NAME( 1003, Gear_ResurrectionSystem )
REGISTER_NAME( 1004, Gear_VehicleSystem )
REGISTER_NAME( 1005, Gear_CheckpointSystem )
REGISTER_NAME( 1006, Cover )
REGISTER_NAME( 1007, AICommand )
REGISTER_NAME( 1008, Success )
REGISTER_NAME( 1009, Failure )
REGISTER_NAME( 1010, Aborted )
REGISTER_NAME( 1011, PlayerTakingCover )
REGISTER_NAME( 1012, Engaging )
REGISTER_NAME( 1013, PlayerTurreting )
REGISTER_NAME( 1014, Reviving )

REGISTER_NAME( 1050, Nano_Locomotion )
REGISTER_NAME( 1051, Nano_Melee )
REGISTER_NAME( 1052, Nano_Powers )
REGISTER_NAME( 1053, Nano_Missions )
REGISTER_NAME( 1054, Nano_Weapons )
REGISTER_NAME( 1055, Nano_Music )
REGISTER_NAME( 1056, Nano_MCP )


REGISTER_NAME( 1080, PlayerID )
REGISTER_NAME( 1081, TeamID )
REGISTER_NAME( 1082, HearSoundFinished )

// Needed for post time/locale deletion to export with proper case
REGISTER_NAME( 1100, Time )
// Post processing volume support.
REGISTER_NAME( 1101, PPVolume_BloomEffect )
REGISTER_NAME( 1102, PPVolume_DOFEffect )
REGISTER_NAME( 1103, PPVolume_MotionBlurEffect )
REGISTER_NAME( 1104, PPVolume_SceneEffect )
REGISTER_NAME( 1105, PPVolume_DOFAndBloomEffect )
REGISTER_NAME( 1106, Desaturation )
REGISTER_NAME( 1107, HighLights )
REGISTER_NAME( 1108, MidTones )
REGISTER_NAME( 1109, Shadows )
REGISTER_NAME( 1110, PPVolume_UberPostProcessEffect )

// Script uses both cases which causes *Classes.h problems
REGISTER_NAME( 1111, DeviceID )

// Needed for interpolation curve fixes.
REGISTER_NAME( 1112, InterpCurveFloat )
REGISTER_NAME( 1113, InterpCurveVector2D )
REGISTER_NAME( 1114, InterpCurveVector )
REGISTER_NAME( 1115, InterpCurveTwoVectors )
REGISTER_NAME( 1116, InterpCurveQuat )

REGISTER_NAME( 1117, UniqueNetId )

REGISTER_NAME( 1133, PopUp )

REGISTER_NAME( 1134, Team )

REGISTER_NAME( 1135, DevDlc )

// For Landscape DebugColorMode
REGISTER_NAME( 1140, Landscape_RedTexture )
REGISTER_NAME( 1141, Landscape_GreenTexture )
REGISTER_NAME( 1142, Landscape_BlueTexture )
REGISTER_NAME( 1143, Landscape_RedMask )
REGISTER_NAME( 1144, Landscape_GreenMask )
REGISTER_NAME( 1145, Landscape_BlueMask )

/*-----------------------------------------------------------------------------
  Special engine-generated probe messages.
-----------------------------------------------------------------------------*/

//
//warning: All probe entries must be filled in, otherwise non-probe names might be mapped
// to probe name indices.
//
#define NAME_PROBEMIN ((EName)300)
#define NAME_PROBEMAX ((EName)332)

// Creation and destruction.
REGISTER_NAME( 300, Destroyed        ) // Called immediately before actor is removed from actor list.

// Gaining/losing actors.
REGISTER_NAME( 301, GainedChild		 ) // Sent to a parent actor when another actor attaches to it.
REGISTER_NAME( 302, LostChild		 ) // Sent to a parent actor when another actor detaches from it.

// Physics & world interaction.
REGISTER_NAME( 303, HitWall			 ) // Ran into a wall.
REGISTER_NAME( 304, Falling			 ) // Actor is falling.
REGISTER_NAME( 305, Landed			 ) // Actor has landed.
REGISTER_NAME( 306, Touch			 ) // Actor was just touched by another actor.
REGISTER_NAME( 307, UnTouch			 ) // Actor touch just ended, always sent sometime after Touch.
REGISTER_NAME( 308, Bump			 ) // Actor was just touched and blocked. No interpenetration. No UnBump.
REGISTER_NAME( 309, BeginState		 ) // Just entered a new state.
REGISTER_NAME( 310, EndState		 ) // About to leave the current state.
REGISTER_NAME( 311, BaseChange		 ) // Sent to actor when its floor changes.
REGISTER_NAME( 312, Attach			 ) // Sent to actor when it's stepped on by another actor.
REGISTER_NAME( 313, Detach			 ) // Sent to actor when another actor steps off it. 
REGISTER_NAME( 314, EncroachingOn    ) // Encroaching on another actor.
REGISTER_NAME( 315, EncroachedBy     ) // Being encroached by another actor.
REGISTER_NAME( 316, MayFall 		 )

// Updates.
REGISTER_NAME( 317, Tick			 ) // Clock tick update for nonplayer.

// AI.
REGISTER_NAME( 318, SeePlayer        ) // Can see player.
REGISTER_NAME( 319, EnemyNotVisible  ) // Current Enemy is not visible.
REGISTER_NAME( 320, HearNoise        ) // Noise nearby.
REGISTER_NAME( 321, UpdateEyeHeight  ) // Update eye level (after physics).
REGISTER_NAME( 322, SeeMonster       ) // Can see non-player.
REGISTER_NAME( 323, SpecialHandling	 ) // Navigation point requests special handling.
REGISTER_NAME( 324, BotDesireability ) // Value of this inventory to bot.

// Controller notifications
REGISTER_NAME( 325, NotifyBump		 )
REGISTER_NAME( 326, NotifyLanded	 )
REGISTER_NAME( 327, NotifyHitWall	 )
REGISTER_NAME( 328, PreBeginPlay	 )
REGISTER_NAME( 329, PostBeginPlay	 )

REGISTER_NAME( 330, UnusedProbe		 )

// Special tag meaning 'All probes'.
REGISTER_NAME( 331, All				 ) // Special meaning, not a message.

REGISTER_NAME(398, PoppedState)
REGISTER_NAME(399, PushedState)

// Misc. Make sure this starts after NAME_ProbeMax
REGISTER_NAME( 400, MeshEmitterVertexColor )
REGISTER_NAME( 401, TextureOffsetParameter )
REGISTER_NAME( 402, TextureScaleParameter )
REGISTER_NAME( 403, ImpactVel )
REGISTER_NAME( 404, SlideVel )
REGISTER_NAME( 405, TextureOffset1Parameter )
REGISTER_NAME( 406, MeshEmitterDynamicParameter )
REGISTER_NAME( 407, ExpressionInput )

REGISTER_NAME(1205, OnAudioFinished )

REGISTER_NAME( 1206, ForceScriptOrder)
REGISTER_NAME( 1207, Mobile)
REGISTER_NAME( 1209, Untitled)


/*-----------------------------------------------------------------------------
  Closing.
-----------------------------------------------------------------------------*/

#ifdef REGISTERING_ENUM
} EName;
# undef REGISTER_NAME
# undef REGISTERING_ENUM
#endif

/**
 * Flags serialized with the bulk data.
 */
enum EBulkDataFlags
{
  /** Empty flag set.																*/
  BULKDATA_None								= 0,
  /** If set, payload is [going to be] stored in separate file.					*/
  BULKDATA_StoreInSeparateFile				= 1<<0,
  /** If set, payload should be [un]compressed using ZLIB during serialization.	*/
  BULKDATA_SerializeCompressedZLIB			= 1<<1,
  /** Force usage of SerializeElement over bulk serialization.					*/
  BULKDATA_ForceSingleElementSerialization	= 1<<2,
  /** Bulk data is only used once at runtime in the game.							*/
  BULKDATA_SingleUse							= 1<<3,
  /** If set, payload should be [un]compressed using LZO during serialization.	*/
  BULKDATA_SerializeCompressedLZO				= 1<<4,
  /** Bulk data won't be used and doesn't need to be loaded						*/
  BULKDATA_Unused								= 1<<5,
  /** If specified, only payload data will be written to archive.					*/
  BULKDATA_StoreOnlyPayload					= 1<<6,
  /** If set, payload should be [un]compressed using LZX during serialization.	*/
  BULKDATA_SerializeCompressedLZX				= 1<<7,
  /** Flag to check if either compression mode is specified						*/
  BULKDATA_SerializeCompressed				= (BULKDATA_SerializeCompressedZLIB | BULKDATA_SerializeCompressedLZO | BULKDATA_SerializeCompressedLZX),

};

/**
 * Enumeration for bulk data lock status.
 */
enum EBulkDataLockStatus
{
  /** Unlocked array													*/
  LOCKSTATUS_Unlocked							= 0,
  /** Locked read-only												*/
  LOCKSTATUS_ReadOnlyLock						= 1,
  /** Locked read-write-realloc										*/
  LOCKSTATUS_ReadWriteLock					= 2,
};

/**
 * Enumeration for bulk data lock behavior
 */
enum EBulkDataLockFlags
{
  LOCK_READ_ONLY								= 1,
  LOCK_READ_WRITE								= 2,
};

/**
 * Enum of token types.
 */
enum EGPPTokenType
{
  GPPToken_Function	= 0,
  GPPToken_Actor		= 1,
  GPPToken_Component	= 2,
  GPPToken_EndOfScope = 3,
  GPPToken_Frame		= 4,
  GPPToken_EOS		= 5,
};

/** Magic number used for .gprof file type and endianness detection. */
#define GPP_MAGIC_NUMBER 0x07210322

/**
 * The platform that this is running on.  This mask is also used by UFunction::PlatformFlags to determine which platforms
 * a native function can be bound for.
 * NOTE: Be sure to check hardcoded/mirrored usage found in LanPacketPlatformMask
 *												            WindowsTools.dll WindowsTarget.h 
 *												            MemoryProfiler2 StreamParser.cs
 * NOTE: Only append to the bottom of the enum to preserve existing values
 * @warning: if this enum gains a multi-byte value, the networking code needs to be updated
 */
typedef enum EPlatformType {
  PLATFORM_Unknown			=	0x00000000,
  PLATFORM_Windows			=	0x00000001,
  PLATFORM_WindowsServer		=	0x00000002,		// Windows platform dedicated server mode ("lean and mean" cooked as console without editor support)
  PLATFORM_Xbox360			=	0x00000004,
  PLATFORM_PS3				=	0x00000008,
  PLATFORM_Linux				=	0x00000010,
  PLATFORM_MacOSX				=	0x00000020,
  PLATFORM_WindowsConsole		=	0x00000040,     // Windows platform cooked as console without editor support
  PLATFORM_IPhone				=	0x00000080,
  PLATFORM_NGP				=	0x00000100,
  PLATFORM_Android			=	0x00000200,

  // Combination Masks
  /** PC platform types */
  PLATFORM_PC					=	PLATFORM_Windows|PLATFORM_WindowsServer|PLATFORM_WindowsConsole|PLATFORM_Linux|PLATFORM_MacOSX,

  /** Windows platform types */
  PLATFORM_AnyWindows			=	PLATFORM_Windows|PLATFORM_WindowsServer|PLATFORM_WindowsConsole,

  /** Console platform types */
  PLATFORM_Console			=	PLATFORM_Xbox360|PLATFORM_PS3|PLATFORM_IPhone|PLATFORM_Android|PLATFORM_NGP,

  /** Mobile platform types */
  PLATFORM_Mobile				=	PLATFORM_IPhone|PLATFORM_Android|PLATFORM_NGP,

  /** Platforms with data that has been stripped during cooking */
  PLATFORM_Stripped			=	PLATFORM_Console|PLATFORM_WindowsServer|PLATFORM_WindowsConsole,

  /** Platforms who's vertex data can't be packed into 16-bit floats */
  PLATFORM_OpenGLES2			=	PLATFORM_IPhone|PLATFORM_Android,
} EPlatformType;

/** Identifier for specifying the type of map check message. */
typedef enum MapCheckType {
  MCTYPE_CRITICALERROR	= 0,
  MCTYPE_ERROR			= 1,
  MCTYPE_PERFORMANCEWARNING = 2,
  MCTYPE_WARNING			= 3,
  MCTYPE_NOTE				= 4,
  MCTYPE_KISMET			= 5,
  MCTYPE_INFO				= 6,
  MCTYPE_NUM
} MapCheckType;

/**
 * Identifier for specifying the recommended action to take when dealing with a check message.
 * CL 289185: The MapCheckAction is now ignored.
 */
typedef enum MapCheckAction {
  MCACTION_NONE	= 0,
  MCACTION_DELETE	= 1,
  MCACTION_NUM
} MapCheckAction;

/** Coordinate system identifiers. */
typedef enum ECoordSystem {
  COORD_None	= -1,
  COORD_World,
  COORD_Local,
  COORD_Max,
} ECoordSystem;

/** Passed to appMsgf to specify the type of message dialog box. */
typedef enum EAppMsgType {
	AMT_OK,
	AMT_YesNo,
	AMT_OKCancel,
	AMT_YesNoCancel,
	AMT_CancelRetryContinue,
	AMT_YesNoYesAllNoAll,
	AMT_YesNoYesAllNoAllCancel,
#if IPHONE
	AMT_Crash,
#endif
} EAppMsgType;


/**
 * The object hash size to use
 *
 * NOTE: This must be power of 2 so that (size - 1) turns on all bits!
 */
// #define OBJECT_HASH_BINS (32*1024)


// Prevents incorrect files from being loaded.

#define PACKAGE_FILE_TAG			0x9E2A83C1
#define PACKAGE_FILE_TAG_SWAPPED	0xC1832A9E

// Cast to ensure that the construct cannot be used in a #if without compiler error.
// This is useful as enum vales cannot be seen by the preprocessor.
#define PREPROCESSOR_ENUM_PROTECT(a) ((unsigned int)(a))

// This is the only VER that needs to be done as #define because it is used
// with #ifdef VER_MESH_PAINT_SYSTEM
#define VER_MESH_PAINT_SYSTEM 615

//
// Package file version log:
//
// Note: The naming convention here is like for macros (#define) because
//       those have been #defines before and now became enums. This can be changed later.
//
enum EUnrealEngineObjectVersion
{
  // - Min version for content resave
  VER_CONTENT_RESAVE_AUGUST_2007_QA_BUILD				= 491,
  // - Static mesh version bump, package version bumped to ease resaving
  VER_STATICMESH_VERSION_16							= 492,
  // - Used 16 bit float UVs for skeletal meshes
  VER_USE_FLOAT16_SKELETAL_MESH_UVS					= 493,
  // - Store two tangent basis vectors instead of three to save memory (skeletal mesh vertex buffers)
  VER_SKELETAL_MESH_REMOVE_BINORMAL_TANGENT_VECTOR	= 494,
  // - Terrain collision data stored in world space.
  VER_TERRAIN_COLLISION_WORLD_SPACE					= 495,
  // - Removed DecalManager ref from UWorld
  VER_REMOVED_DECAL_MANAGER_FROM_UWORLD				= 496,
  // - Modified SpeedTree vertex factory shader parameters.
  VER_SPEEDTREE_SHADER_CHANGE							= 497,
  // - Fix height-fog pixel shader 4-layer 
  VER_HEIGHTFOG_PIXELSHADER_START_DIST_FIX			= 498,
  // - MotionBlurShader recompile (added clamping to render target extents)
  VER_MOTIONBLURSHADER_RECOMPILE_VER2					= 499,
  // - Separate pass for LDR BLEND_Modulate transparency mode
  // - Modulate preserves dest alpha (depth)
  VER_SM2_BLENDING_SHADER_FIXES						= 500,
  // - Terrain material fallback support
  VER_ADDED_TERRAIN_MATERIAL_FALLBACK					= 501,
  // - Added support for multi-column collections to UIDynamicFieldProvider
  VER_ADDED_MULTICOLUMN_SUPPORT						= 503,
  // - Serialize cached displacement values for terrain
  VER_TERRAIN_SERIALIZE_DISPLACEMENTS					= 504,
  // - Fixed bug which allowed multiple instances of a UIState class get added to style data maps
  VER_REMOVED_PREFAB_STYLE_DATA						= 505,
  // - Exposed separate horizontal and vertical texture scale for material texture lookups
  // -  Various font changes that affected serialization
  VER_FONT_FORMAT_AND_UV_TILING_CHANGES				= 506,
  // - Changed UTVehicleFactory to use a string for class reference in its defaults
  VER_UTVEHICLEFACTORY_USE_STRING_CLASS				= 507,
  // - Fixed the special 0.0f value in the velocity buffer that is used to select between background velocity or dynamic velocity
  VER_BACKGROUNDVELOCITYVALUE							= 508,
  // - Reset vehicle usage flags on some NavigationPoints that had been incorrectly set
  VER_FIXED_NAV_VEHICLE_USAGE_FLAGS					= 509,
  // - Changed Texture2DComposite to inherit from Texture instead of Texture2D.
  VER_TEXTURE2DCOMPOSITE_BASE_CHANGE					= 510,
  // - Fixed fonts serializing all members twice.
  VER_FIXED_FONTS_SERIALIZATION						= 511,
  // - Bump to break full version content to work with demo
  VER_FULL_VERSION_OF_UT3_BUMP						= 512,
  // - Throw away Atrac3 data, create MP3 data
  VER_UPGRADE_TO_MP3									= 513,
  // - 
  VER_STATICMESH_FRAGMENTINDEX						= 514,
  // - Added Draw SkelTree Manager. Added FColor to FMeshBone serialization.	
  VER_SKELMESH_DRAWSKELTREEMANAGER					= 515,
  // - Added AdditionalPackagesToCook to FPackageFileSummary	
  VER_ADDITIONAL_COOK_PACKAGE_SUMMARY					= 516,
  // - Add neighbor info to FFragmentInfo
  VER_FRAGMENT_NEIGHBOUR_INFO							= 517,
  // - Added interior fragment index
  VER_FRAGMENT_INTERIOR_INDEX							= 518,
  // - Added bCanBeDestroyed and bRootFragment
  VER_FRAGMENT_DESTROY_FLAGS							= 519,
  // - Add exterior surface normal and neighbor area info to FFragmentInfo
  VER_FRAGMENT_EXT_NORMAL_NEIGH_DIM					= 520,
  // - Add core mesh 3d offset and scale
  VER_FRACTURE_CORE_SCALE_OFFSET						= 521,
  // - Updated mp3 format to account for multichannel sounds
  VER_MP3_FORMAT_UPDATE								= 522,
  // - Moved particle SpawnRate and Burst info into their own module.
  VER_PARTICLE_SPAWN_AND_BURST_MOVE					= 523,
  // - Share modules across particle LOD levels where possible.
  VER_PARTICLE_LOD_MODULE_SHARE						= 524,
  // - Fixing up TypeData modules not getting pushed into lower LODs
  VER_PARTICLE_LOD_MODULE_TYPEDATA_FIXUP				= 525,
  // - Save off PlaneBias with FSM
  VER_FRACTURE_SAVE_PLANEBIAS							= 526,
  // - Fixing up LOD distributions... (incorrect archetypes caused during Spawn conversion)
  VER_PARTICLE_LOD_DIST_FIXUP							= 527,
  // - Added DiffusePower to material inputs
  VER_DIFFUSEPOWER									= 528,
  // - Changed default DiffusePower value
  VER_DIFFUSEPOWER_DEFAULT							= 529,
  // - Allow for '0' in the particle burst list CountLow slot...
  VER_PARTICLE_BURST_LIST_ZERO						= 530,
  // - Added AttenAllowedParameter to FModShadowMeshPixelShader
  VER_MODSHADOWMESHPIXELSHADER_ATTENALLOWED			= 531,
  // - Support for mesh simplification tool.  Static mesh version bump (added named reference to high res source mesh.)
  VER_STATICMESH_VERSION_18							= 532,
  // - Added automatic fog volume components to simplify workflow
  VER_AUTOMATIC_FOGVOLUME_COMPONENT					= 533,
  // - Added an optional array of skeletal mesh weights/bones for instancing 
  VER_ADDED_EXTRA_SKELMESH_VERTEX_INFLUENCES			= 534,
  // - Added an optional array of skeletal mesh weights/bones for instancing 
  VER_UNIFORM_DISTRIBUTION_BAKING_UPDATE				= 535,
  // - Replaced classes for sequences associated with PrefabInstances
  VER_FIXED_PREFAB_SEQUENCES							= 536,
  // - Changed FInputKeyAction's list of sequence actions to a list of sequence output links
  VER_MADE_INPUTKEYACTION_OUTPUT_LINKS				= 537,
  // - Moved global shaders from UShaderCache to a single global shader cache file.
  VER_GLOBAL_SHADER_FILE								= 538,
  // - Using MSEnc to encode mp3s rather than MP3Enc
  VER_MP3ENC_TO_MSENC									= 539,
  // - Fixing up LODValidity...
  VER_EMITTER_LODVALIDITY_FIX							= 540,
  // - Added optional external specification of static vertex normals.
  VER_STATICMESH_EXTERNAL_VERTEX_NORMALS				= 541,
  // - Removed 2x2 normal transform for decal materials
  VER_DECAL_MATERIAL_IDENDITY_NORMAL_XFORM			= 542,
  // - Removed FObjectExport::ComponentMap
  VER_REMOVED_COMPONENT_MAP							= 543,
  // - Fixed back uniform distributions with lock flags set to something other than NONE
  VER_LOCKED_UNIFORM_DISTRIBUTION_BAKING				= 544,
  // - Fixed Kismet sequences with illegal names
  VER_FIXED_KISMET_SEQUENCE_NAMES						= 545,
  // - Added fluid lightmap support
  VER_ADDED_FLUID_LIGHTMAPS							= 546,
  // - Fixing up LODValidity and spawn module outers...
  VER_EMITTER_LODVALIDITY_FIX2						= 547,
  // - Fixing incorrect default properties for new foliage parameters
  VER_FIX_DEFAULT_FOLIAGE_PARAMETERS					= 548,
  // - Add FSM core rotation and 'no physics' flag on chunks
  VER_FRACTURE_CORE_ROTATION_PERCHUNKPHYS				= 549,
  // - New curve auto-tangent calculations; Clamped auto tangent support
  VER_NEW_CURVE_AUTO_TANGENTS							= 550,
  // - Removed 2x2 normal transform from decal vertices 
  VER_DECAL_REMOVED_2X2_NORMAL_TRANSFORM				= 551,
  // - Updated decal vertex factories
  VER_DECAL_VERTEX_FACTORY_VER1						= 552,
  // - Updated fluid vertex factories
  VER_FLUID_VERTEX_FACTORY							= 553,
  // - Updated decal vertex factories
  VER_DECAL_VERTEX_FACTORY_VER2						= 554,
  // - Updated the fluid detail normalmap
  VER_FLUID_DETAIL_UPDATE								= 555,
  // - Fixup particle systems with incorrect distance arrays...
  VER_PARTICLE_LOD_DISTANCE_FIXUP						= 556,
  // - Added FSM build version
  VER_FRACTURE_NONCRITICAL_BUILD_VERSION				= 557,
  // - Added DynamicParameter support for particles
  VER_DYNAMICPARAMETERS_ADDED							= 558,
  // - Added travelspeed parameter to the fluid detail normalmap
  VER_FLUID_DETAIL_UPDATE2							= 559,
  // - /** replaced bAcceptsDecals,bAcceptsDecalsDuringGameplay with bAcceptsStaticDecals,bAcceptsDynamicDecals */
  VER_UPDATED_DECAL_USAGE_FLAGS						= 560,
  // - incremented DOFBloomGather pixel version; added SceneMultipler
  VER_DOFBLOOMGATHER_SCENEMULTIPLIER					= 561,
  // - Added bounced lighting settings to LightComponent
  VER_LIGHTCOMPONENT_BOUNCEDLIGHTING					= 562,
  // - Made bOverrideNormal override the full tangent basis.
  VER_OVERRIDETANGENTBASIS							= 563,
  // - Made LightComponent bounced lighting settings multiplicative with direct lighting.
  VER_BOUNCEDLIGHTING_DIRECTMODULATION				= 564,
  // - Added a shader parameter to the FDistortionApplyScreenPixelShader
  VER_DISTORTIONAPPLYPIXELSHADER_UPDATE				= 565,
  // - Reduced FStateFrame::LatentAction to WORD
  VER_REDUCED_STATEFRAME_LATENTACTION_SIZE			= 566,
  // - Added GUIDs for updating texture file cache
  VER_ADDED_TEXTURE_FILECACHE_GUIDS					= 567,
  // - Fixed scene color and scene depth usage
  VER_FIXED_SCENECOLOR_USAGE							= 568,
  // - Renamed UPrimitiveComponent::CullDistance to MaxDrawDistance
  VER_RENAMED_CULLDISTANCE							= 569,
  // - Fixing up InterpolationMethod mismatches in emitter LOD levels...
  VER_EMITTER_INTERPOLATIONMETHOD_FIXUP				= 570,
  // - Fixing up LensFlare ScreenPercentageMaps
  VER_LENSFLARE_SCREENPERCENTAGEMAP_FIXUP				= 571,
  // - Updated decal vertex factories
  VER_DECAL_VERTEX_FACTORY_VER3						= 572,
  // - Reimplemented particle LOD check distance time
  VER_PARTICLE_LOD_CHECK_DISTANCE_TIME_FIX			= 573,
  // - Decal physical material entry fixups
  VER_DECAL_PHYS_MATERIAL_ENTRY_FIXUP					= 574,
  // - Added persisitent FaceFXAnimSet to the world...
  VER_WORLD_PERSISTENT_FACEFXANIMSET					= 575,
  // - depcreated redundant editor window position
  // - Delete var - SkelControlBase: ControlPosX, ControlPosY, MaterialExpression: EditorX, EditorY
  VER_DEPRECATED_EDITOR_POSITION						= 576,
  // - moved RawAnimData serialization to native
  VER_NATIVE_RAWANIMDATA_SERIALIZATION				= 577,
  // - deprecated sound attenuation ranges
  VER_DEPRECATE_SOUND_RANGES							= 578,
  // - ambient sound update
  VER_AMBIENT_SOUND_UPDATE							= 579,
  // - new conversion required for multichannel sounds
  VER_XAUDIO2_MULTICHANNEL_UPDATE						= 580,
  // - new format stored in the XMA2 file to avoid runtime calcs
  VER_XAUDIO2_FORMAT_UPDATE							= 581,
  // - flip the normal for meshes with negative non-uniform scaling
  VER_VERTEX_FACTORY_LOCALTOWORLD_FLIP				= 582,
  // - add additional sort flags to sprite/subuv particle emitters
  VER_NEW_PARTICLE_SORT_MODES							= 583,
  // - added asset thumbnails to packages
  VER_ASSET_THUMBNAILS_IN_PACKAGES					= 584,
  // - Added Pylon list to Ulevel
  VER_PYLONLIST_IN_ULEVEL								= 585,
  // - Added local object version number to ULevel and NavMesh
  VER_NAVMESH_COVERREF								= 586,
  // - Updates and replaces several kismet objects 
  VER_CONVERT_KISMET_OBJECTS							= 587,
  // - poly height var added to polygons in navmesh
  VER_NAVMESH_POLYHEIGHT								= 588,
  // - simple element shader recompile
  VER_SIMPLE_ELEMENT_SHADER_VER0						= 589,
  // - added rectangular thumbnail support
  VER_RECTANGULAR_THUMBNAILS_IN_PACKAGES				= 590,
  // - changed default for SkeletalMeshActor.bCollideActors to FALSE
  VER_REMOVED_DEFAULT_SKELETALMESHACTOR_COLLISION		= 591,
  // - added skeletalmesh position compression saving 8 bytes
  VER_SKELETAL_MESH_SUPPORT_PACKED_POSITION			= 592,
  // - removed content tags from objects (obsolete by new asset database system)
  VER_REMOVED_LEGACY_CONTENT_TAGS						= 593,
  // - added back refs for SplineActors
  VER_ADDED_SPLINEACTOR_BACK_REFS						= 594,
  // - Changed the format of the base pose for additive animations.
  VER_NEW_BASE_POSE_ADDITIVE_ANIM_FORMAT				= 595,
  // - Fix up 'Bake and Prune' animations where their num frames doesn't match NumKeys.
  VER_FIX_BAKEANDPRUNE_NUMFRAMES						= 596,
  // - added full names to package thumbnails
  VER_CONTENT_BROWSER_FULL_NAMES						= 597,
  // - added profiling system to AnimTree previewing
  VER_ANIMTREE_PREVIEW_PROFILES						= 598,
  // - added triangle sorting options to skeletal meshes
  VER_SKELETAL_MESH_SORTING_OPTIONS					= 599,
  // - Lightmass serialization changes
  VER_INTEGRATED_LIGHTMASS							= 600,
  // - added BoneAtom quaternion math support and convert vars from Matrix
  VER_FBONEATOM_QUATERNION_TRANSFORM_SUPPORT			= 601,
  // - deprecate distributions from sound nodes
  VER_DEPRECATE_SOUND_DISTRIBUTIONS					= 602,
  // - added DontSortCategories option to classes
  VER_DONTSORTCATEGORIES_ADDED						= 603,
  // - Reintroduced lossless compression of Raw Data, and removed redundant KeyTimes array.
  VER_RAW_ANIMDATA_REDUX								= 604,
  // - Fixed bad additive animation base pose data
  VER_FIXED_BAD_ADDITIVE_DATA							= 605,
  // - Add per-poly procbuilding ruleset pointer
  VER_ADD_FPOLY_PBRULESET_POINTER						= 606,
  // - Added precomputed lighting volume to each level
  VER_GI_CHARACTER_LIGHTING							= 607,
  // - SkeletalMesh Compose now done in 3 passes as opposed to 2.
  VER_THREE_PASS_SKELMESH_COMPOSE						= 608,
  // - Added bone influence mapping data per bone break
  VER_ADDED_EXTRA_SKELMESH_VERTEX_INFLUENCE_MAPPING   = 609,
  // - Fix bad AnimSequences.
  VER_REMOVE_BAD_ANIMSEQ								= 610,
  // - added dual quaternion for skeletalmesh skinning
  VER_SKELETAL_MESH_DUAL_QUATERNION_SKINNING			= 611,
  // - disabled dual quaternion and need to bump this again for shader
  VER_SKELETAL_MESH_DISABLE_DQ_SKINNING				= 612,
  // - added editor data to sound classes
  VER_SOUND_CLASS_SERIALISATION_UPDATE				= 613,
  // - older maps may have improper ProcBuilding textures
  VER_NEED_TO_CLEANUP_OLD_BUILDING_TEXTURES			= 614,
  // - Mesh paint system
  VER_MESH_PAINT_SYSTEM_ENUM							= VER_MESH_PAINT_SYSTEM,
  // - Added ULightMapTexture2D::bSimpleLightmap
  VER_LIGHTMAPTEXTURE_VARIABLE						= 616,
  // - Normal shadows on the dominant light
  VER_DOMINANTLIGHT_NORMALSHADOWS						= 617,
  // - Added PlatformMeshData to mesh elements (for PS3 Edge Geometry support)
  VER_ADDED_PLATFORMMESHDATA							= 618,
  // - Disable optimizations (for now) on FSplineMeshVertexFactory to get rid of black flickering.
  VER_DISABLE_SPLINEMESH_OPTIMIZATIONS				= 619,
  // - changed makeup of FPolyReference
  VER_FPOLYREF_CHANGE									= 620,
  // - Added bsp element index to the serialized static receiver data for decals
  VER_DECAL_SERIALIZE_BSP_ELEMENT						= 621,
  // - Added option to spline deform for linear or hermite scale/roll interpolation
  VER_SPLINE_DEFORM_SMOOTH_OPTION						= 622,
  // - Added support for automatic, safe cross-level references
  VER_ADDED_CROSSLEVEL_REFERENCES						= 623,
  // - Changed lightmap encoding to only use two DXT1 textures for directional lightmaps
  VER_MAXCOMPONENT_LIGHTMAP_ENCODING					= 624,
  // - Added instanced rendering to localvertexfactory
  VER_XBOXINSTANCING									= 625,
  // - Fixing up emitter editor color issue.
  VER_FIXING_PARTICLE_EMITTEREDITORCOLOR				= 626,
  // - Added OriginalSizeX/Y to Texture2D
  VER_ADDED_TEXTURE_ORIGINAL_SIZE						= 627,
  // - Added options to generate particle normals from simple shapes
  VER_ANALYTICAL_PARTICLE_NORMALS						= 628,
  // - Spline VF recompile now that the debug flag has been removed
  VER_SPLINEVF_REMOVED_DEBUG							= 629,
  // - Fixup references to removed deprecated ParticleEmitter.SpawnRate
  VER_REMOVED_EMITTER_SPAWNRATE						= 630,
  // - Add support for static normal parameters
  VER_ADD_NORMAL_PARAMETERS							= 631,
  // - Changed UParticleSystem::bLit to be per-LOD
  VER_PARTICLE_LIT_PERLOD								= 632,
  // - Changed byte property serialization to include the enum the property uses (if any)
  VER_BYTEPROP_SERIALIZE_ENUM							= 633,
  // - Added InternalFormatLODBias
  VER_ADDED_TEXTURE_INTERNALFORMATLODBIAS				= 634,
  // - Refactoring particle event receiver classes
  VER_PARTICLE_EVENT_RECEIVER_REFACTOR				= 635,
  // - Added an explicit emissive light radius
  VER_ADDDED_EXPLICIT_EMISSIVE_LIGHT_RADIUS			= 636,
  // - Enabled Custom Thumbnails for shared thumbnail asset types
  VER_ENABLED_CUSTOM_THUMBNAILS_FOR_SHARED_TYPES		= 637,
  // - Added AnimMetaData system to AnimSequence, auto conversion of BoneControlModifiers to that new system.
  // - Fixed FQuatError, automatic animation recompression when needed.
  VER_ADDED_ANIM_METADATA_FIXED_QUATERROR				= 638,
  // - Changed UStruct serialization to include both on-disk and in-memory bytecode size
  VER_USTRUCT_SERIALIZE_ONDISK_SCRIPTSIZE				= 639,
  // - Added new ShadowmapCoordinateScaleBias shader parameter for mesh instancing
  VER_INSTANCED_MESH_SHADOWMAPS						= 640,
  // - Changed the default distance model for the SoundNodeAttenuation class from ATTENUATION_Logarithmic to ATTENUATION_Linear.
  VER_SOUNDNODEATTENUATION_DISTANCEMODEL_CHANGE		= 641,
  // - Added support for spline mesh offsetting
  VER_ADDED_SPLINE_MESH_OFFSET						= 642,
  // - Speedtree 5.0 integration
  VER_SPEEDTREE_5_INTEGRATION							= 643,
  // - Added selected object coloring to Lightmap Density rendering mode
  VER_LIGHTMAP_DENSITY_SELECTED_OBJECT				= 644,
  // - Added LightmapUVs expression
  VER_MATEXP_LIGHTMAPUVS_ADDED						= 645,
  // - Switched AnimMetadata_SkelControl to using a list.
  VER_SKELCONTROL_ANIMMETADATA_LIST					= 646,
  // - Added material vertex shader parameters
  VER_MATERIAL_EDITOR_VERTEX_SHADER					= 647,
  // - Freed up an extra shader constant in the GPU skinning shader (needed for translucent decals)
  VER_FREE_GPUSKIN_SHADER_CONSTANT					= 648,
  // - Added per-object foliage shader parameters
  VER_ADDED_FOLIAGE_PARAMETERS						= 649,
  // - Fixed hit proxy material parameters not getting serialized
  VER_FIXED_HIT_PROXY_VERTEX_OFFSET					= 650,
  // - Added general OcclusionPercentage material expression
  VER_ADDDED_OCCLUSION_PERCENTAGE_EXPRESSION			= 651,
  // - Added the ability to shadow indirect only in Lightmass
  VER_SHADOW_INDIRECT_ONLY_OPTION						= 652,
  // - Changed mesh emitter camera facing options...
  VER_MESH_EMITTER_CAMERA_FACING_OPTIONS				= 653,
  // - Replaced bSimpleLightmap with LightmapFlags in ULightMapTexture2D
  VER_LIGHTMAPFLAGS									= 654,
  // - Added the ability for script to bind DLL functions
  VER_SCRIPT_BIND_DLL_FUNCTIONS						= 655,
  // - Moved uniform expressions from being stored in the UMaterial package to the shader cache
  VER_UNIFORM_EXPRESSIONS_IN_SHADER_CACHE				= 656,
  // - Added dynamic parameter support and second uv set to beams and trails
  VER_BEAM_TRAIL_DYNAMIC_PARAMETER					= 657,
  // - Forced a recompile of vertex shaders
  VER_RECOMPILE_MATERIAL_VERTEX_SHADERS				= 658,
  // - Allow random overrides per-section in ProcBuilding meshes
  VER_PROCBUILDING_MATERIAL_OPTIONS					= 659,
  // - Changed uniform expressions to reference textures by index instead of name
  VER_UNIFORMEXPRESSION_TEXTUREINDEX					= 660,
  // - Regenerate texture array for old materials, so they match the shadercache.
  VER_UNIFORMEXPRESSION_POSTLOADFIXUP					= 661,
  // - Separated DOF and Bloom, invalidate shadercache.
  VER_SEPARATE_DOF_BLOOM								= 662,
  // - Fixed Raw Animation Compression not working properly.
  VER_FIXED_RAW_ANIM_COMPRESSION						= 663,
  // - Change AnimNotify_Trails to use SamplesPerSecond
  VER_ANIMNOTIFY_TRAIL_SAMPLEFRAMERATE				= 664,
  // - Support for attaching static decals to instanced static meshes
  VER_STATIC_DECAL_INSTANCE_INDEX						= 665,
  // - Added support for precomputed shadowmaps to lit decals
  // Teh Forbidden= ?,
  VER_DECAL_SHADOWMAPS								= 666,		
  // - Fixed malformed raw anim data
  VER_FIXED_MALFORMED_RAW_ANIM_DATA					= 667,
  // - Removed unused velocity values from AnimNotify_Trail sampled data
  VER_ANIMNOTIFY_TRAILS_REMOVED_VELOCITY				= 668,
  // - Added SpawnRate support to Ribbon emitters
  VER_RIBBON_EMITTERS_SPAWNRATE						= 669,
  // - Remove ruleset from FPoly and add 'variation name' instead
  VER_FPOLY_RULESET_VARIATIONNAME						= 670,
  // - Added PreViewTranslationParameter in FParticleInstancedMeshVertexFactoryShaderParameters
  VER_ADDED_PRE_VIEW_TRANSLATION_PARAMETER			= 671,
  // - Added shader compression functionality
  VER_SHADER_COMPRESSION								= 672,
  // - Optimized FPropertyTag to store bool properties with 1 byte on disk instead of 4
  VER_PROPERTYTAG_BOOL_OPTIMIZATION					= 673,
  // - Added iPhone cached data (PVRTC textures)
  VER_ADDED_CACHED_IPHONE_DATA						= 674,
  // - Added DOFParameters to BasePassVertexShader for translucency DoF
  VER_ADDED_BASE_PASS_VS_DOF_PARAMETERS				= 675,
  // - Added TextureUsageInfos to UPersistentCookerData for stats tracking
  VER_ADDED_TEXTURE_USAGE_INFO						= 676,
  // - Fixup for ForceFeedbackSerialization
  VER_FORCEFEEDBACKWAVERFORM_NOEXPORT_CHANGE			= 677,
  // - Changed type OverrideVertexColors from TArray<FColor> to FColorVertexBuffer * 
  VER_OVERWRITE_VERTEX_COLORS_MEM_OPTIMIZED			= 678,
  // - Changed the default usage to be SVB_LoadingAndVisibility for level streaming volumes.
  VER_STREAMINGVOLUME_USAGE_DEFAULT					= 679,
  // - Added support to serialize clothing asset properties.
  VER_APEX_CLOTHING                       			= 680,
  // - Added support to serialize destruction cached data
  VER_APEX_DESTRUCTION                      			= 681,
  // - Added spotlight dominant shadow transition handling
  VER_SPOTLIGHT_DOMINANTSHADOW_TRANSITION				= 682,
  // - Added common game type package object lists to GPCD
  VER_PREFIX_GAMETYPE_OBJECTS_IN_GPCD					= 683,
  // - Added PMap forced object lists to GPCD
  VER_PMAP_FORCED_OBJECTS_IN_GPCD						= 684,
  // - Added support for preshadows on translucency
  VER_TRANSLUCENT_PRESHADOWS							= 685,
  // - Removed shadow volume support
  VER_REMOVED_SHADOW_VOLUMES							= 686,
  // - Added procedural texture that contains parameters to fix stereo offseting.
  VER_STEREO_FIX_TEXTURE                              = 687,
  // - Bulk serialize instance data
  VER_BULKSERIALIZE_INSTANCE_DATA						= 688,
  // - Added TerrainVertexFactory TerrainLayerCoordinateOffset Parameter
  VER_ADDED_TERRAINLAYERCOORDINATEOFFSET_PARAM		= 689,
  // - Added CachedPhysConvexBSPData in ULevel for Convex BSP
  VER_CONVEX_BSP										= 690,
  // - Reduced ProbeMask in UState/FStateFrame to DWORD and removed IgnoreMask
  VER_REDUCED_PROBEMASK_REMOVED_IGNOREMASK			= 691,
  // - Changed GDO lighting defaults to be cheap
  VER_CHANGED_GDO_LIGHTING_DEFAULTS					= 692,
  // - Changed way material references are stored/handled for Matinee material parameter tracks
  VER_CHANGED_MATPARAMTRACK_MATERIAL_REFERENCES		= 693,
  // - Added bone influence mapping option per bone break
  VER_ADDED_EXTRA_SKELMESH_VERTEX_INFLUENCE_CUSTOM_MAPPING   = 694,
  // - Changed light shaft shaders
  VER_LIGHTSHAFT_SHADER_CHANGES						= 695,
  // - Changed GDO lighting defaults to be cheap
  VER_CHANGED_GDO_LIGHTING_DEFAULTS2					= 696,
  // - Half resolution scene and depth for DOF, Bloom, MotionBlur
  VER_HALFRESSCENEPOSTPROCESS							= 697,
  // - Changed light shaft shaders
  VER_LIGHTSHAFT_SHADER_CHANGES2						= 698,
  // - Exponential Height Fog
  VER_EXPONENTIAL_HEIGHT_FOG							= 699,
  // - Added chunks/sections when swapping to a vertex influence using IWU_FullSwap
  VER_ADDED_CHUNKS_SECTIONS_VERTEX_INFLUENCE			= 700,
  // - Downsample and blur with masking to avoid leaking
  VER_FILTERPOSTPROCESS_MASKED						= 701,
  // - Downsample and blur with masking to avoid leaking SM2
  VER_FILTERPOSTPROCESS_MASKED2						= 702,
  // - Unified downsample scene for SM2
  VER_UNIFY_HALFSCENE_RES								= 703,
  // - Added support for halfres DOF on SM2
  VER_HALFSCENE_RES_SM2								= 704,
  // - Half scene depth parameter got serialized
  VER_HALFSCENE_DEPTH_PARAM							= 705,
  // - introduced VisualizeTexture shader
  VER_VISUALIZETEXTURE								= 706,
  // - updated bink shader serialization
  VER_BINK_SHADER_SERIALIZATION_CHANGE				= 707,
  // - Added RequiredBones array to extra vertex influence structure
  VER_ADDED_REQUIRED_BONES_VERTEX_INFLUENCE			= 708,
  // - Added multiple UV channels to skeletal meshes
  VER_ADDED_MULTIPLE_UVS_TO_SKELETAL_MESH				= 709,
  // - Added ability to render and import skeletal meshes with vertex colors
  VER_ADDED_SKELETAL_MESH_VERTEX_COLORS				= 710,
  // - Removed SM2 support
  VER_REMOVED_SHADER_MODEL_2							= 711,
  // - Added bloom parameters
  VER_ADDED_BLOOM_PARAMETERS							= 712,
  // - Removed terrain displacement mapping
  VER_TERRAIN_REMOVED_DISPLACEMENTS					= 713,
  // - Added FStaticTerrainLayerWeightParameter
  VER_ADD_TERRAINLAYERWEIGHT_PARAMETERS				= 714,
  // - Added usage specification to vertex influences
  VER_ADDED_USAGE_VERTEX_INFLUENCE					= 715,
  // - Added support for camera offset particles
  VER_PARTICLE_ADDED_CAMERA_OFFSET					= 716,
  // - Merged scalar parameters
  VER_COMBINED_SCALAR_PARAMETERS						= 717,
  // - Added AngleBased SSAO option
  VER_ANGLEBASED_SSAO									= 718,
  // - AngleBasedSSAO 4x4 dither pattern instead of 2x2
  VER_ANGLEBASED_SSAO_DITHER							= 719,
  // - Resolution independent light shafts
  VER_RES_INDEPENDENT_LIGHTSHAFTS						= 720,
  // - Lightmaps on GDOs
  VER_GDO_LIGHTMAPS									= 721,
  // - MotionBlurSeperatePass
  VER_MOTIONBLUR_SEPERATE_PASS						= 722,
  // - Explicit normal support for static meshes					
  VER_STATIC_MESH_EXPLICIT_NORMALS					= 723,
  // - Fix HalfRes MotionBlur&DOF issues
  VER_HALFRES_MOTIONBLURDOF							= 724,
  // - Fix more HalfRes MotionBlur&DOF issues
  VER_HALFRES_MOTIONBLURDOF2							= 725,
  // - Fix more HalfRes MotionBlur&DOF issues
  VER_HALFRES_MOTIONBLURDOF3							= 726,
  // - Reverted HalfRes MotionBlur&DOF for now
  VER_HALFRES_MOTIONBLURDOF4							= 727,
  // - Add parameters to LandscapeVertexFactory
  VER_LANDSCAPEVERTEXFACTORY_ADDPARAMS				= 728,
  // - MotionBlurSeperatePass back in again
  VER_HALFRES_MOTIONBLURDOF5							= 729,
  // - remove SeparateBloom option (Bloom/DOF radius)
  VER_REMOVED_SEPARATEBLOOM							= 730,
  // - bump the version to prevent error message
  VER_REMOVED_SEPARATEBLOOM2							= 731,
  // - Fixed GDO FLightmapRef handling
  VER_FIXED_GDO_LIGHTMAP_REFCOUNTING					= 732,
  // - bump the version to prevent error message
  VER_HQ_DEPTHOFFIELD									= 733,
  // - Precomputed Visibility
  VER_PRECOMPUTED_VISIBILITY							= 734,
  // - sets the StartTime on MITVs to -1 when they were created with that var being transient
  VER_MITV_START_TIME_FIX_UP							= 735,
  // - refactor motionblur
  VER_REFACTOR_MOTIONBLUR								= 736,
  // - Add lightmap to LandscapeComponent
  VER_LANDSCAPECOMPONENT_LIGHTMAPS					= 737,
  // - motionblur improvements
  VER_IMPROVED_MOTIONBLUR								= 738,
  // - Non uniform precomputed visibility
  VER_NONUNIFORM_PRECOMPUTED_VISIBILITY				= 739,
  // - Object based Motion Blur scale fix
  VER_IMPROVED_MOTIONBLUR2							= 740,
  // - Object based Motion Blur scale fix
  VER_HITMASK_MIRRORING_SUPPORT						= 741,
  // - Fixed RadialBlur look
  VER_RADIALBLUR_FIX									= 743,
  // - Add Landscape vertex factory LodBias Parameter
  VER_LANDSCAPEVERTEXFACTORY_ADD_LODBIAS_PARAM		= 744,
  // - Optimized AngleBasedSSAO, better quality 
  VER_IMPROVED_ANGLEBASEDSSAO							= 746,
  // - Optimized AngleBasedSSAO 
  VER_IMPROVED_ANGLEBASEDSSAO2						= 747,
  // - New character indirect lighting controls
  VER_CHARACTER_INDIRECT_CONTROLS						= 748,
  // - Add force script defined ordering per class
  VER_FORCE_SCRIPT_DEFINED_ORDER_PER_CLASS			= 749,
  // - Optimized SSAO SmartBlur making 2 pass
  VER_OPTIMIZEDSSAO									= 750,
  // - Tonemapper now interprets negative colors as black
  VER_TONEMAPPERBEHAVIOR								= 751,
  // - Motion blur not leaking colors outside of the object bound
  VER_MOTIONBLURANTILEAK								= 752,
  // - One pass approximate lighting for translucency
  VER_ONEPASS_TRANSLUCENCY_LIGHTING					= 754,
  // - Refactor uber post processing 
  VER_REFACTOR_UBERPOSTPROCESS						= 755,
  // - Moved UField::SuperField to UStruct
  VER_MOVED_SUPERFIELD_TO_USTRUCT						= 756,
  // - Refactor uber post processing now support image grain
  VER_ADDED_IMAGEGRAIN								= 757,
  // - Added scale for ImageGrain and tone mapper
  VER_ADDED_SCALES									= 758,
  // - Changed Tonemapper scale to be before tone mapping
  VER_ADDED_SCALES2									= 759,
  // - Support AnimNodeSlot dynamic sequence node allocation on demand
  VER_ADDED_ANIMNODESLOTPOOL							= 760,
  // - Optimized UAnimSequence storage
  VER_OPTIMIZED_ANIMSEQ								= 761,
  // - Fixed Distortion effect leaking outside of the view, optimized shader
  VER_DISTORTIONEFFECT								= 762,
  // - removed Direction from cover reference
  VER_REMOVED_DIR_COVERREF							= 763,
  // - Fixed GDO's getting lighting unbuilt when Undestroyed
  VER_GDO_LIGHTING_HANDLE_UNDESTROY					= 764,
  // - Added option for per bone motion blur, made pow() for non PS3 platforms unclamped
  VER_PERBONEMOTIONBLUR								= 766,
  // - Added async texture pre-allocation to level streaming
  VER_TEXTURE_PREALLOCATION							= 767,
  // - Added property to specify bone to use for TRISORT_CustomLeftRight
  VER_ADDED_SKELETAL_MESH_SORTING_LEFTRIGHT_BONE		= 768,
  // - Added new feature: SoftEdge MotionBlur
  VER_SOFTEDGEMOTIONBLUR								= 769,
  // - Compact kDop trees for static meshes
  VER_COMPACTKDOPSTATICMESH,
  // - Compact kDop trees for static meshes
  VER_ADDED_NEW_TONEMAPPER,
  // - Refactoring UberPostProcess, LUT and grain now usable for non tone mapper cases as well
  VER_UBERPOST_REFACTOR,
  // - Refactoring UberPostProcess, removed unused parameters
  VER_UBERPOST_REFACTOR2,
  // - Added XY offset parameters to Landscape vertex factory
  VER_LANDSCAPEVERTEXFACTORY_ADD_XYOFFSET_PARAMS,
  // - Fixed clamping of non tonemapped case
  VER_FIXCLAMP_NON_TONEMAP,
  // - Update uberpostprocess with smaller DOF radius to not reach instruction limit on SM3
  VER_UBERPOSTPROCESS_UPDATE,
  // - Clamped specular pow to prevent image artifacts (see comment in shader)
  VER_CLAMP_SPECULAR_POWER,
  // - Adjusted experimental tonemapper
  VER_TONEMAPPER2ADJUST,
  // - Replaced tonemapper checkbox by combobox
  VER_TONEMAPPER_ENUM,
  // - Fix distortion effect wrong color leaking in
  VER_DISTORTIONEFFECT2,
  // - MotionBlurSoftEdge feature updated
  VER_IMPROVED_MOTIONBLUR4,
  // - MotionBlurSoftEdge fixed for Playstation3
  VER_IMPROVED_MOTIONBLUR5,
  // - Fixed translucent preshadow filtering
  VER_FIXED_TRANSLUCENT_SHADOW_FILTERING,
  // - Added vfetch sprite and subuv particle support on 360
  VER_SPRITE_SUBUV_VFETCH_SUPPORT,
  // - fixed seam in uber postprocessing
  VER_FIXSEAMINPOSTPROCESS,
  // - fixed warning with MotionBlurSkinning
  VER_MOTIONBLURSKINNING								= 787,
  // - adjustable kernel for ReferenceDOF
  VER_POSTPROCESSUPDATE,
  // - Added class group names for grouping in the editor
  VER_ADDED_CLASS_GROUPS,
  // - Bloom after motionblur for better quality
  VER_BLOOM_AFTER_MOTIONBLUR,
  // - DX11 integration
  VER_DX11_TESSELLATION,
  // - MotionBlurSoftEdge fix bias on NV 7800 cards
  VER_IMPROVED_MOTIONBLUR6,
  // - MotionBlur optimizations
  VER_IMPROVED_MOTIONBLUR7,
  // - Removed unused parameter
  VER_REMOVE_MAXBONEINFLUENCE,
  // - Optimized MotionBlurSoftEdge
  VER_IMPROVED_MOTIONBLUR8,
  // - Fixed automatic shader versioning
  VER_FIXED_AUTO_SHADER_VERSIONING,
  // - Added texture instances for non-static actors in ULevel::BuildStreamingData().
  VER_DYNAMICTEXTUREINSTANCES,
  // - Moved Guids previously stored in CoverLink (with many dups) into ULevel
  VER_COVERGUIDREFS_IN_ULEVEL,
  // - Added ability to override Colorgrading with no LUT
  VER_COLORGRADING,
  // - Fix content that lost the flag because of wrong serialization
  VER_COLORGRADING2,
  // - Added code to preserve static mesh component override vertex colors when source verts change
  VER_PRESERVE_SMC_VERT_COLORS,
  // - Added shadowing for image based reflections
  VER_IMAGE_REFLECTION_SHADOWING,
  // - changes displacement from tangent space to world space, now extra TransformVector node is required
  VER_DX11_TESSELLATION_TS_TO_WS,
  // - Added ability to keep degenerate triangles when building static mesh
  VER_KEEP_STATIC_MESH_DEGENERATES,
  // - Added shader cache priority
  VER_SHADER_CACHE_PRIORITY,
  // - Added support for 32 bit vertex indices on skeletal meshes
  VER_DWORD_SKELETAL_MESH_INDICES,
  // - Introduced DepthOfFieldType
  VER_DEPTHOFFIELD_TYPE,
  // - Fixed some serialization issues with 32 bit indices
  VER_DWORD_SKELETAL_MESH_INDICES_FIXUP,
  // - Added DoF two layer effect for simple DoF
  VER_DEPTHOFFIELD_SIMPLE_TWO_LAYER,
  // - Changed material parameter allocation for landscape
  VER_CHANGED_LANDSCAPE_MATERIAL_PARAMS,
  // - fix blue rendering
  VER_INVALIDATE_SHADERCACHE0,
  // - fix blue rendering
  VER_INVALIDATE_SHADERCACHE1,
  // - fixup estimate max particle counts
  VER_RECALCULATE_MAXACTIVEPARTICLE,
  // - serialize raw data info for morph target
  VER_SERIALIZE_MORPHTARGETRAWVERTSINDICES,
  // - fix specular on old terrain on consoles
  VER_TERRAIN_SPECULAR_FIX,
  // - Changed ScenColor texture format
  VER_INVALIDATE_SHADERCACHE2,
  // - Added support for VertexFactoryParameters in pixel shader
  VER_INVALIDATE_SHADERCACHE3,
  // - Fixup empty emitter particle systems
  VER_PARTICLE_EMPTY_EMITTERS_FIXUP,
  // - Renamed old actor groups to layers
  VER_RENAMED_GROUPS_TO_LAYERS,
  // - Deprecated some doubly serialised data
  VER_DEPRECATE_DOUBLY_SERIALISED_SMC,
  // -----<new versions can be added before this line>-------------------------------------------------

  // - this needs to be the last line (see note below)
  VER_AUTOMATIC_VERSION_PLUS_ONE
};

// !!
// !! NOTE: We switched from #define to enum. This means there is no longer a need to update two places and as enum is
// !!       automatically counting up each entry the system is less vulnerable to human error.
// !!       Removing lines in the used enum range need to be done with extreme care to not affect the enum counting.
// !!
// !! WARNING: Only modify this in //depot/UnrealEngine3/Development/Src/Core/Inc/UnObjVer.h on the Epic Perforce server. All 
// !! WARNING: other places should modify VER_LATEST_ENGINE_LICENSEE instead.
// !!
#define VER_LATEST_ENGINE									(PREPROCESSOR_ENUM_PROTECT(VER_AUTOMATIC_VERSION_PLUS_ONE) - 1)

#define VER_LATEST_ENGINE_LICENSEE							0

// Cooked packages loaded with an older package version are recooked
#define VER_LATEST_COOKED_PACKAGE							129
#define VER_LATEST_COOKED_PACKAGE_LICENSEE					0

// Package version that the build system considers old and will resave over the weekends (nothing < VER_ADDED_TERRAINLAYERCOORDINATEOFFSET_PARAM)
#define VER_DEPRECATED_PACKAGE								VER_CHANGED_GDO_LIGHTING_DEFAULTS2

// Version access.

// extern INT GEngineVersion;                   // Engine build number, for displaying to end users.
// extern INT GBuiltFromChangeList;             // Built from changelist, for displaying to end users.
// extern INT GEngineMinNetVersion;             // Earliest engine build that is network compatible with this one.
// extern INT	GEngineNegotiationVersion;        // Base protocol version to negotiate in network play.
// extern INT GPackageFileVersion;              // The current Unrealfile version.
// extern INT			GPackageFileMinVersion;			// The earliest file version that can be loaded with complete backward compatibility.
// extern INT			GPackageFileLicenseeVersion;	// Licensee Version Number.
// extern INT GPackageFileCookedContentVersion; // version of the cooked content

// Results from FPoly.SplitWithPlane, describing the result of splitting
// an arbitrary FPoly with an arbitrary plane.
typedef enum ESplitType : unsigned char {
  SP_Coplanar		= 0, // Poly wasn't split, but is coplanar with plane
  SP_Front		= 1, // Poly wasn't split, but is entirely in front of plane
  SP_Back			= 2, // Poly wasn't split, but is entirely in back of plane
  SP_Split		= 3, // Poly was split into two new editor polygons
} ESplitType;
#define ESplitType  ESplitType

/** 
 * Mask for index bit used to determine whether string is encoded as TCHAR or ANSICHAR. We don't
 * add an extra bool in order to keep the name size to a minimum and 2 billion names is impractical
 * so there are a few bits left in the index.
 */
#define NAME_UNICODE_MASK 0x1
#define NAME_INDEX_SHIFT 1

/** Maximum size of name. */
enum {NAME_SIZE	= 1024};

/** Externally, the instance number to represent no instance number is NAME_NO_NUMBER, 
    but internally, we add 1 to indices, so we use this #define internally for 
  zero'd memory initialization will still make NAME_None as expected */
#define NAME_NO_NUMBER_INTERNAL	0

/** Conversion routines between external representations and internal */
#define NAME_INTERNAL_TO_EXTERNAL(x) (x - 1)
#define NAME_EXTERNAL_TO_INTERNAL(x) (x + 1)

/** Special value for an FName with no number */
#define NAME_NO_NUMBER NAME_INTERNAL_TO_EXTERNAL(NAME_NO_NUMBER_INTERNAL)

/** Enumeration for finding name. */
typedef enum : unsigned char {
  /**
   * Find a name; return 0 if it doesn't exist.
   */
  FNAME_Find,
  /**
   * Find a name or add it if it doesn't exist.
   */
  FNAME_Add,
  /**
   * Finds a name and replaces it. Adds it if missing
   */
  FNAME_Replace,
} EFindName;
#define EFindName  EFindName

/* ---------------------------------------------------------- AActor ---------------------------------------------------------- */

typedef enum EPhysics          : unsigned char {
  PHYS_None,                      // 0
  PHYS_Walking,                   // 1
  PHYS_Falling,                   // 2
  PHYS_Swimming,                  // 3
  PHYS_Flying,                    // 4
  PHYS_Rotating,                  // 5
  PHYS_Projectile,                // 6
  PHYS_Interpolating,             // 7
  PHYS_Spider,                    // 8
  PHYS_Ladder,                    // 9
  PHYS_RigidBody,                 // 10
  PHYS_SoftBody,                  // 11
  PHYS_NavMeshWalking,            // 12
  PHYS_Unused,                    // 13
  PHYS_Custom,                    // 14
  PHYS_MAX                        // 15
} EPhysics;
typedef enum EMoveDir          : unsigned char {
  MD_Stationary,                  // 0
  MD_Forward,                     // 1
  MD_Backward,                    // 2
  MD_Left,                        // 3
  MD_Right,                       // 4
  MD_Up,                          // 5
  MD_Down,                        // 6
  MD_MAX                          // 7
} EMoveDir;
typedef enum EActorMetricsType : unsigned char {
  METRICS_VERTS,                  // 0
  METRICS_TRIS,                   // 1
  METRICS_SECTIONS,               // 2
  METRICS_MAX                     // 3
} EActorMetricsType;
typedef enum ENetRole          : unsigned char {
  ROLE_None,                      // 0
  ROLE_SimulatedProxy,            // 1
  ROLE_AutonomousProxy,           // 2
  ROLE_Authority,                 // 3
  ROLE_MAX                        // 4
} ENetRole;
typedef enum ECollisionType    : unsigned char {
  COLLIDE_CustomDefault,          // 0
  COLLIDE_NoCollision,            // 1
  COLLIDE_BlockAll,               // 2
  COLLIDE_BlockWeapons,           // 3
  COLLIDE_TouchAll,               // 4
  COLLIDE_TouchWeapons,           // 5
  COLLIDE_BlockAllButWeapons,     // 6
  COLLIDE_TouchAllButWeapons,     // 7
  COLLIDE_BlockWeaponsKickable,   // 8
  COLLIDE_BlockAllButVehicles,    // 9
  COLLIDE_MAX                     // 10
} ECollisionType;
typedef enum ETravelType       : unsigned char {
  TRAVEL_Absolute,                // 0
  TRAVEL_Partial,                 // 1
  TRAVEL_Relative,                // 2
  TRAVEL_MAX                      // 3
} ETravelType;
typedef enum EDoubleClickDir   : unsigned char {
  DCLICK_None,                    // 0
  DCLICK_Left,                    // 1
  DCLICK_Right,                   // 2
  DCLICK_Forward,                 // 3
  DCLICK_Back,                    // 4
  DCLICK_Active,                  // 5
  DCLICK_Done,                    // 6
  DCLICK_MAX                      // 7
} EDoubleClickDir;
#define EPhysics           EPhysics
#define EMoveDir           EMoveDir
#define EActorMetricsType  EActorMetricsType
#define ENetRole           ENetRole
#define ECollisionType     ECollisionType
#define ETravelType        ETravelType
#define EDoubleClickDir    EDoubleClickDir

/* ---------------------------------------------------------- ABrush ---------------------------------------------------------- */

typedef enum ECsgOper : unsigned char {
  CSG_Active      = 0,
  CSG_Add         = 1,
  CSG_Subtract    = 2,
  CSG_Intersect   = 3,
  CSG_Deintersect = 4,
  CSG_MAX         = 5
  #define CSG_Active       CSG_Active
  #define CSG_Add          CSG_Add
  #define CSG_Subtract     CSG_Subtract
  #define CSG_Intersect    CSG_Intersect
  #define CSG_Deintersect  CSG_Deintersect
  #define CSG_MAX          CSG_MAX
} ECsgOper;
#define ECsgOper  ECsgOper

/* ---------------------------------------------------------- ACamera ---------------------------------------------------------- */

typedef enum EViewTargetBlendFunction : unsigned char {
  VTBlend_Linear,                 // 0
  VTBlend_Cubic,                  // 1
  VTBlend_EaseIn,                 // 2
  VTBlend_EaseOut,                // 3
  VTBlend_EaseInOut,              // 4
  VTBlend_MAX                     // 5
} EViewTargetBlendFunction;
typedef enum ECameraAnimPlaySpace     : unsigned char {
  CAPS_CameraLocal,               // 0
  CAPS_World,                     // 1
  CAPS_UserDefined,               // 2
  CAPS_MAX                        // 3
} ECameraAnimPlaySpace;
#define EViewTargetBlendFunction  EViewTargetBlendFunction
#define ECameraAnimPlaySpace      ECameraAnimPlaySpace

/* ---------------------------------------------------------- UPrimitiveComponent ---------------------------------------------------------- */

typedef enum ERBCollisionChannel         : unsigned char {
  RBCC_Default,                   // 0
  RBCC_Nothing,                   // 1
  RBCC_Pawn,                      // 2
  RBCC_Vehicle,                   // 3
  RBCC_Water,                     // 4
  RBCC_GameplayPhysics,           // 5
  RBCC_EffectPhysics,             // 6
  RBCC_Untitled1,                 // 7
  RBCC_Untitled2,                 // 8
  RBCC_TossedItems,               // 9
  RBCC_TossedItemsPlayerVehicle,  // 10
  RBCC_Cloth,                     // 11
  RBCC_FluidDrain,                // 12
  RBCC_SoftBody,                  // 13
  RBCC_FracturedMeshPart,         // 14
  RBCC_BlockingVolume,            // 15
  RBCC_DeadPawn,                  // 16
  RBCC_Clothing,                  // 17
  RBCC_ClothingCollision,         // 18
  RBCC_TossedItemsEnemyVehicle,   // 19
  RBCC_PlayerVehicle,             // 20
  RBCC_EnemyVehicle,              // 21
  RBCC_PlayerVehicleEnemyVehicle, // 22
  RBCC_TossedItemsPlayerVehicleEnemyVehicle,// 23
  RBCC_WillowPickup,              // 24
  RBCC_MAX                        // 25
} ERBCollisionChannel;
typedef enum EDynamicShadowCastRelevance : unsigned char {
  SHADOWCAST_Uninitialized,       // 0
  SHADOWCAST_Always,              // 1
  ShadowCast_Far,                 // 2
  ShadowCast_Near,                // 3
  SHADOWCAST_Never,               // 4
  EDynamicShadowCastRelevance_MAX // 5
} EDynamicShadowCastRelevance;
typedef enum EOverrideStaticShadow       : unsigned char {
  OSS_NoOverride,                 // 0
  OSS_CastButDontReceiveStatic,   // 1
  OSS_CastAndReceiveStatic,       // 2
  EOverrideStaticShadow_MAX       // 3
} EOverrideStaticShadow;
typedef enum GJKResult                   : unsigned char {
  GJK_Intersect,                  // 0
  GJK_NoIntersection,             // 1
  GJK_Fail,                       // 2
  GJK_MAX                         // 3
} GJKResult;
typedef enum ERadialImpulseFalloff       : unsigned char {
  RIF_Constant,                   // 0
  RIF_Linear,                     // 1
  RIF_MAX                         // 2
} ERadialImpulseFalloff;
#define ERBCollisionChannel          ERBCollisionChannel
#define EDynamicShadowCastRelevance  EDynamicShadowCastRelevance
#define EOverrideStaticShadow        EOverrideStaticShadow
#define GJKResult                    GJKResult
#define ERadialImpulseFalloff        ERadialImpulseFalloff

/* ---------------------------------------------------------- AWillowHUD ---------------------------------------------------------- */

typedef enum EHUDPickupCardType   : unsigned char {
  HUDPickupCard_Weapon,           // 0
  HUDPickupCard_Shield,           // 1
  HUDPickupCard_GrenadeMod,       // 2
  HUDPickupCard_ClassMod,         // 3
  HUDPickupCard_Artifact,         // 4
  HUDPickupCard_Item,             // 5
  HUDPickupCard_MAX               // 6
} EHUDPickupCardType;
typedef enum EHUDEquippedCardType : unsigned char {
  HUDEquippedCard_Weapon,         // 0
  HUDEquippedCard_Shield,         // 1
  HUDEquippedCard_GrenadeMod,     // 2
  HUDEquippedCard_ClassMod,       // 3
  HUDEquippedCard_Artifact,       // 4
  HUDEquippedCard_MAX             // 5
} EHUDEquippedCardType;
typedef enum EColiseumUpdateMode  : unsigned char {
  E_Toggle,                       // 0
  E_TurnOff,                      // 1
  E_TurnOn,                       // 2
  E_MAX                           // 3
} EColiseumUpdateMode;
typedef enum ECountDownLength     : unsigned char {
  ECDL_Ten,                       // 0
  ECDL_Five,                      // 1
  ECDL_Four,                      // 2
  ECDL_Three,                     // 3
  ECDL_Two,                       // 4
  ECDL_One,                       // 5
  ECDL_None,                      // 6
  ECDL_MAX                        // 7
} ECountDownLength;
typedef enum EColiseumNotifyType  : unsigned char {
  ECNT_Resupply,                  // 0
  ECNT_Refill,                    // 1
  ECNT_WaveEnded,                 // 2
  ECNT_MAX                        // 3
} EColiseumNotifyType;
#define EHUDPickupCardType    EHUDPickupCardType
#define EHUDEquippedCardType  EHUDEquippedCardType
#define EColiseumUpdateMode   EColiseumUpdateMode
#define ECountDownLength      ECountDownLength
#define EColiseumNotifyType   EColiseumNotifyType

/* ---------------------------------------------------------- APlayerController ---------------------------------------------------------- */

typedef enum EInputTypes          : unsigned char {
  IT_XAxis,                       // 0
  IT_YAxis,                       // 1
  IT_MAX                          // 2
} EInputTypes;
typedef enum EInputMatchAction    : unsigned char {
  IMA_GreaterThan,                // 0
  IMA_LessThan,                   // 1
  IMA_MAX                         // 2
} EInputMatchAction;
typedef enum EProgressMessageType : unsigned char {
  PMT_Clear,                      // 0
  PMT_Information,                // 1
  PMT_AdminMessage,               // 2
  PMT_DownloadProgress,           // 3
  PMT_ConnectionFailure,          // 4
  PMT_PeerConnectionFailure,      // 5
  PMT_PeerHostMigrationFailure,   // 6
  PMT_SocketFailure,              // 7
  PMT_MAX                         // 8
} EProgressMessageType;
#define EInputTypes           EInputTypes
#define EInputMatchAction     EInputMatchAction
#define EProgressMessageType  EProgressMessageType

/* ---------------------------------------------------------- UInteractionIconDefinition ---------------------------------------------------------- */

typedef enum EInteractionIcons : unsigned char {
  INTERACTION_ICON_None,          // 0
  INTERACTION_ICON_Use,           // 1
  INTERACTION_ICON_Talk,          // 2
  INTERACTION_ICON_Heal,          // 3
  INTERACTION_ICON_Shop,          // 4
  INTERACTION_ICON_Computer,      // 5
  INTERACTION_ICON_Driver,        // 6
  INTERACTION_ICON_Gunner,        // 7
  INTERACTION_ICON_Smash,         // 8
  INTERACTION_ICON_CannotUse,     // 9
  INTERACTION_ICON_FlipVehicle,   // 10
  INTERACTION_ICON_VehicleMiddleLeftSeat,// 11
  INTERACTION_ICON_VehicleMiddleRightSeat,// 12
  INTERACTION_ICON_Open,          // 13
  INTERACTION_ICON_Trade,         // 14
  INTERACTION_ICON_Objective,     // 15
  INTERACTION_ICON_PickUp,        // 16
  INTERACTION_ICON_Full,          // 17
  INTERACTION_ICON_FullFadeOut,   // 18
  INTERACTION_ICON_MAX            // 19
} EInteractionIcons;
#define EInteractionIcons  EInteractionIcons

/* ---------------------------------------------------------- AWorldInfo ---------------------------------------------------------- */

typedef enum ENetMode                  : unsigned char {
  NM_Standalone,                  // 0
  NM_DedicatedServer,             // 1
  NM_ListenServer,                // 2
  NM_Client,                      // 3
  NM_MAX                          // 4
} ENetMode;
typedef enum EConsoleType              : unsigned char {
  CONSOLE_Any,                    // 0
  CONSOLE_Xbox360,                // 1
  CONSOLE_PS3,                    // 2
  CONSOLE_Mobile,                 // 3
  CONSOLE_IPhone,                 // 4
  CONSOLE_Android,                // 5
  CONSOLE_MAX                     // 6
} EConsoleType;
typedef enum EVisibilityAggressiveness : unsigned char {
  VIS_LeastAggressive,            // 0
  VIS_ModeratelyAggressive,       // 1
  VIS_MostAggressive,             // 2
  VIS_Max                         // 3
} EVisibilityAggressiveness;
typedef enum EHostMigrationProgress    : unsigned char {
  HostMigration_None,             // 0
  HostMigration_FindingNewHost,   // 1
  HostMigration_MigratingAsHost,  // 2
  HostMigration_MigratingAsClient,// 3
  HostMigration_ClientTravel,     // 4
  HostMigration_HostReadyToTravel,// 5
  HostMigration_Failed,           // 6
  HostMigration_MAX               // 7
} EHostMigrationProgress;
#define ENetMode                   ENetMode
#define EConsoleType               EConsoleType
#define EVisibilityAggressiveness  EVisibilityAggressiveness
#define EHostMigrationProgress     EHostMigrationProgress

/* ---------------------------------------------------------- ReverbVolume ---------------------------------------------------------- */

typedef enum ReverbPreset : unsigned char {
  REVERB_Default,                 // 0
  REVERB_Bathroom,                // 1
  REVERB_StoneRoom,               // 2
  REVERB_Auditorium,              // 3
  REVERB_ConcertHall,             // 4
  REVERB_Cave,                    // 5
  REVERB_Hallway,                 // 6
  REVERB_StoneCorridor,           // 7
  REVERB_Alley,                   // 8
  REVERB_Forest,                  // 9
  REVERB_City,                    // 10
  REVERB_Mountains,               // 11
  REVERB_Quarry,                  // 12
  REVERB_Plain,                   // 13
  REVERB_ParkingLot,              // 14
  REVERB_SewerPipe,               // 15
  REVERB_Underwater,              // 16
  REVERB_SmallRoom,               // 17
  REVERB_MediumRoom,              // 18
  REVERB_LargeRoom,               // 19
  REVERB_MediumHall,              // 20
  REVERB_LargeHall,               // 21
  REVERB_Plate,                   // 22
  REVERB_MAX                      // 23
} ReverbPreset;
#define ReverbPreset  ReverbPreset

/* ---------------------------------------------------------- UMaterialInterface ---------------------------------------------------------- */

typedef enum EMaterialUsage  : unsigned char {
  MATUSAGE_SkeletalMesh,          // 0
  MATUSAGE_FracturedMeshes,       // 1
  MATUSAGE_ParticleSprites,       // 2
  MATUSAGE_BeamTrails,            // 3
  MATUSAGE_ParticleSubUV,         // 4
  MATUSAGE_Foliage,               // 5
  MATUSAGE_SpeedTree,             // 6
  MATUSAGE_StaticLighting,        // 7
  MATUSAGE_GammaCorrection,       // 8
  MATUSAGE_LensFlare,             // 9
  MATUSAGE_InstancedMeshParticles,// 10
  MATUSAGE_FluidSurface,          // 11
  MATUSAGE_Decals,                // 12
  MATUSAGE_MaterialEffect,        // 13
  MATUSAGE_MorphTargets,          // 14
  MATUSAGE_FogVolumes,            // 15
  MATUSAGE_RadialBlur,            // 16
  MATUSAGE_InstancedMeshes,       // 17
  MATUSAGE_SplineMesh,            // 18
  MATUSAGE_ScreenDoorFade,        // 19
  MATUSAGE_APEXMesh,              // 20
  MATUSAGE_Terrain,               // 21
  MATUSAGE_Landscape,             // 22
  MATUSAGE_SPHFluid,              // 23
  MATUSAGE_MAX                    // 24
} EMaterialUsage;
typedef enum ECustomSkinType : unsigned char {
  CUSTSKIN_None,                  // 0
  CUSTSKIN_Body,                  // 1
  CUSTSKIN_Head,                  // 2
  CUSTSKIN_MAX                    // 3
} ECustomSkinType;
#define EMaterialUsage   EMaterialUsage
#define ECustomSkinType  ECustomSkinType

/* ---------------------------------------------------------- ULightComponent ---------------------------------------------------------- */

typedef enum ELightAffectsClassification : unsigned char {
  LAC_USER_SELECTED,              // 0
  LAC_DYNAMIC_AFFECTING,          // 1
  LAC_STATIC_AFFECTING,           // 2
  LAC_DYNAMIC_AND_STATIC_AFFECTING,// 3
  LAC_MAX                         // 4
} ELightAffectsClassification;
typedef enum ELightShadowMode            : unsigned char {
  LightShadow_Normal,             // 0
  LightShadow_Modulate,           // 1
  LightShadow_ModulateBetter,     // 2
  LightShadow_MAX                 // 3
} ELightShadowMode;
typedef enum EShadowProjectionTechnique  : unsigned char {
  ShadowProjTech_Default,         // 0
  ShadowProjTech_PCF,             // 1
  ShadowProjTech_VSM,             // 2
  ShadowProjTech_BPCF_Low,        // 3
  ShadowProjTech_BPCF_Medium,     // 4
  ShadowProjTech_BPCF_High,       // 5
  ShadowProjTech_MAX              // 6
} EShadowProjectionTechnique;
typedef enum EShadowFilterQuality        : unsigned char {
  SFQ_Low,                        // 0
  SFQ_Medium,                     // 1
  SFQ_High,                       // 2
  SFQ_MAX                         // 3
} EShadowFilterQuality;
#define ELightAffectsClassification  ELightAffectsClassification
#define ELightShadowMode             ELightShadowMode
#define EShadowProjectionTechnique   EShadowProjectionTechnique
#define EShadowFilterQuality         EShadowFilterQuality

/* ---------------------------------------------------------- UObject ---------------------------------------------------------- */

typedef enum AlphaBlendType             : unsigned char {
  ABT_Linear,                     // 0
  ABT_Cubic,                      // 1
  ABT_Sinusoidal,                 // 2
  ABT_EaseInOutExponent2,         // 3
  ABT_EaseInOutExponent3,         // 4
  ABT_EaseInOutExponent4,         // 5
  ABT_EaseInOutExponent5,         // 6
  ABT_MAX                         // 7
} AlphaBlendType;
typedef enum EAxis                      : unsigned char {
  AXIS_NONE,                      // 0
  AXIS_X,                         // 1
  AXIS_Y,                         // 2
  AXIS_BLANK,                     // 3
  AXIS_Z,                         // 4
  AXIS_MAX                        // 5
} EAxis;
typedef enum EInputEvent                : unsigned char {
  IE_Pressed,                     // 0
  IE_Released,                    // 1
  IE_Repeat,                      // 2
  IE_DoubleClick,                 // 3
  IE_Axis,                        // 4
  IE_MAX                          // 5
} EInputEvent;
typedef enum EAspectRatioAxisConstraint : unsigned char {
  AspectRatio_MaintainYFOV,       // 0
  AspectRatio_MaintainXFOV,       // 1
  AspectRatio_MajorAxisFOV,       // 2
  AspectRatio_MAX                 // 3
} EAspectRatioAxisConstraint;
typedef enum EInterpCurveMode           : unsigned char {
  CIM_Linear,                     // 0
  CIM_CurveAuto,                  // 1
  CIM_Constant,                   // 2
  CIM_CurveUser,                  // 3
  CIM_CurveBreak,                 // 4
  CIM_CurveAutoClamped,           // 5
  CIM_MAX                         // 6
} EInterpCurveMode;
/** Which interpolation method to use, needed for backwards compatibility. */
typedef enum EInterpMethodType          : unsigned char {
  IMT_UseFixedTangentEvalAndNewAutoTangents,// 0
  IMT_UseFixedTangentEval,        // 1
  IMT_UseBrokenTangentEval,       // 2
  IMT_MAX                         // 3
} EInterpMethodType;
/**
 * Determines which ticking group an Actor/Component belongs to
 * @see Object.uc for original definition
 */
typedef enum ETickingGroup              : unsigned char {
  TG_PreAsyncWork,                // 0
  TG_DuringAsyncWork,             // 1
  TG_PostAsyncWork,               // 2
  TG_PostUpdateWork,              // 3
  TG_EffectsUpdateWork,           // 4
  TG_MAX                          // 5
} ETickingGroup;
/** 
 * These are the types of PerfMem RunResults you the system understands and can achieve.  They are stored in the table as we
 * will get "valid" numbers but we ran OOM.  We want to list the numbers in the OOM case because there is probably something that
 * jumped up to cause the OOM (e.g. vertex lighting).
 **/
typedef enum EAutomatedRunResult        : unsigned char {
  ARR_Unknown,                    // 0
  ARR_OOM,                        // 1
  ARR_Passed,                     // 2
  ARR_MAX                         // 3
} EAutomatedRunResult;
typedef enum EDebugBreakType            : unsigned char {
  DEBUGGER_NativeOnly,            // 0
  DEBUGGER_ScriptOnly,            // 1
  DEBUGGER_Both,                  // 2
  DEBUGGER_MAX                    // 3
} EDebugBreakType;
#define AlphaBlendType              AlphaBlendType
#define EAxis                       EAxis
#define EInputEvent                 EInputEvent
#define EAspectRatioAxisConstraint  EAspectRatioAxisConstraint
#define EInterpCurveMode            EInterpCurveMode
#define EInterpMethodType           EInterpMethodType
#define ETickingGroup               ETickingGroup
#define EAutomatedRunResult         EAutomatedRunResult
#define EDebugBreakType             EDebugBreakType

/* ---------------------------------------------------------- UAttributeExpression ---------------------------------------------------------- */

typedef enum EComparisonOperator       : unsigned char {
  OPERATOR_EqualTo,               // 0
  OPERATOR_NotEqualTo,            // 1
  OPERATOR_LessThan,              // 2
  OPERATOR_LessThanOrEqual,       // 3
  OPERATOR_GreaterThan,           // 4
  OPERATOR_GreaterThanOrEqual,    // 5
  OPERATOR_MAX                    // 6
} EComparisonOperator;
typedef enum EOperandUsage             : unsigned char {
  OPERAND_PreferAttribute,        // 0
  OPERAND_Multiply,               // 1
  OPERAND_MAX                     // 2
} EOperandUsage;
typedef enum EExpressionEvaluationMode : unsigned char {
  EXPRMODE_And,                   // 0
  EXPRMODE_Or,                    // 1
  EXPRMODE_MAX                    // 2
} EExpressionEvaluationMode;
#define EComparisonOperator        EComparisonOperator
#define EOperandUsage              EOperandUsage
#define EExpressionEvaluationMode  EExpressionEvaluationMode

/* ---------------------------------------------------------- UAttributeInitializationDefinition ---------------------------------------------------------- */

typedef enum EBaseValueMode                   : unsigned char {
  BASEVALUE_InitializationDefSetsBaseValue,// 0
  BASEVALUE_InitializationDefAddsToBaseValue,// 1
  BASEVALUE_InitializationDefScalesBaseValue,// 2
  BASEVALUE_InitializationDefOffsetByBaseValue,// 3
  BASEVALUE_MAX                   // 4
} EBaseValueMode;
typedef enum EAttributeInitializationRounding : unsigned char {
  ATTRROUNDING_Float,             // 0
  ATTRROUNDING_IntRound,          // 1
  ATTRROUNDING_IntFloor,          // 2
  ATTRROUNDING_IntCeil,           // 3
  ATTRROUNDING_MAX                // 4
} EAttributeInitializationRounding;
#define EBaseValueMode                    EBaseValueMode
#define EAttributeInitializationRounding  EAttributeInitializationRounding

/* ---------------------------------------------------------- UAttributeModifier ---------------------------------------------------------- */

typedef enum EModifierType : unsigned char {
  MT_Scale,                       // 0
  MT_PreAdd,                      // 1
  MT_PostAdd,                     // 2
  MT_MAX                          // 3
} EModifierType;
#define EModifierType  EModifierType

/* ---------------------------------------------------------- UAttributeDefinitionBase ---------------------------------------------------------- */

typedef enum EAttributeDataType : unsigned char {
  ADT_Float,                      // 0
  ADT_Int,                        // 1
  ADT_Bool,                       // 2
  ADT_MAX                         // 3
} EAttributeDataType;
#define EAttributeDataType  EAttributeDataType

/* ---------------------------------------------------------- AWillowInventory ---------------------------------------------------------- */

/* Enums */
typedef enum PlayerMark        : unsigned char {
  PM_Trash,                       // 0
  PM_Standard,                    // 1
  PM_Favorite,                    // 2
  PM_MAX                          // 3
} PlayerMark;
typedef enum SerialNumberState : unsigned char {
  SNS_Empty,                      // 0
  SNS_Writing,                    // 1
  SNS_Full,                       // 2
  SNS_Reading,                    // 3
  SNS_Encrypted,                  // 4
  SNS_MAX                         // 5
} SerialNumberState;
typedef enum EncryptedSerial   : unsigned char {
  ES_Encrypted,                   // 0
  ES_MAX                          // 1
} EncryptedSerial;
#define PlayerMark         PlayerMark
#define SerialNumberState  SerialNumberState
#define EncryptedSerial    EncryptedSerial

/* ---------------------------------------------------------- AWeapon ---------------------------------------------------------- */

typedef enum EWeaponFireType : unsigned char {
  EWFT_InstantHit,                // 0
  EWFT_Projectile,                // 1
  EWFT_Beam,                      // 2
  EWFT_Custom,                    // 3
  EWFT_None,                      // 4
  EWFT_MAX                        // 5
} EWeaponFireType;
#define EWeaponFireType  EWeaponFireType

/* ---------------------------------------------------------- UFontImportOptions ---------------------------------------------------------- */

typedef enum EFontImportCharacterSet : unsigned char {
  FontICS_Default,  /* 0 */
  FontICS_Ansi,     /* 1 */
  FontICS_Symbol,   /* 2 */
  FontICS_MAX       /* 3 */
} EFontImportCharacterSet;
#define EFontImportCharacterSet  EFontImportCharacterSet

/* ---------------------------------------------------------- AWillowWeapon ---------------------------------------------------------- */

static const signed char ZoomedFireModeNum              = 1;
static const signed char MAX_WEAPON_CARD_MODIFIER_STATS = 5;
typedef enum EWeaponReloadState      : unsigned char {
  RELOADSTATE_None,               // 0
  RELOADSTATE_Reloading,          // 1
  RELOADSTATE_Aborted,            // 2
  RELOADSTATE_MAX                 // 3
} EWeaponReloadState;
typedef enum EZoomState              : unsigned char {
  ZST_NotZoomed,                  // 0
  ZST_ZoomingIn,                  // 1
  ZST_Zoomed,                     // 2
  ZST_ZoomingOut,                 // 3
  ZST_MAX                         // 4
} EZoomState;
typedef enum EWeaponSpinState        : unsigned char {
  SPIN_STATE_None,                // 0
  SPIN_STATE_SpinningUp,          // 1
  SPIN_STATE_FullySpunUp,         // 2
  SPIN_STATE_MAX                  // 3
} EWeaponSpinState;
typedef enum EWeaponAnimation        : unsigned char {
  WEAPON_ANIM_Weapon,             // 0
  WEAPON_ANIM_Arm,                // 1
  WEAPON_ANIM_MAX                 // 2
} EWeaponAnimation;
typedef enum EWeaponAnimPutDownState : unsigned char {
  WAPDS_None,                     // 0
  WAPDS_PutDown,                  // 1
  WAPDS_PutDownSwap,              // 2
  WAPDS_PutDownInterrupted,       // 3
  WAPDS_MAX                       // 4
} EWeaponAnimPutDownState;
#define EWeaponReloadState  		 EWeaponReloadState
#define EZoomState 				  		 EZoomState
#define EWeaponSpinState 	  		 EWeaponSpinState
#define EWeaponAnimation 	  		 EWeaponAnimation
#define EWeaponAnimPutDownState  EWeaponAnimPutDownState

/* ---------------------------------------------------------- UWillowWeaponTypes ---------------------------------------------------------- */

typedef enum EWeaponType               : unsigned char {
  WT_Pistol,                      // 0
  WT_Shotgun,                     // 1
  WT_SMG,                         // 2
  WT_SniperRifle,                 // 3
  WT_AssaultRifle,                // 4
  WT_RocketLauncher,              // 5
  WT_MAX                          // 6
} EWeaponType;
typedef enum EWeaponPartType           : unsigned char {
  WP_Body,                        // 0
  WP_Grip,                        // 1
  WP_Barrel,                      // 2
  WP_Sight,                       // 3
  WP_Stock,                       // 4
  WP_Elemental,                   // 5
  WP_Accessory1,                  // 6
  WP_Accessory2,                  // 7
  WP_Material,                    // 8
  WP_Prefix,                      // 9
  WP_Title,                       // 10
  WP_MAX                          // 11
} EWeaponPartType;
typedef enum EWeaponPartVariation      : unsigned char {
  WeaponPartVar_Default,          // 0
  WeaponPartVar_One,              // 1
  WeaponPartVar_Two,              // 2
  WeaponPartVar_Three,            // 3
  WeaponPartVar_MAX               // 4
} EWeaponPartVariation;
typedef enum EWeaponEventType          : unsigned char {
  WEAPONEVENT_Advance,            // 0
  WEAPONEVENT_Stop,               // 1
  WEAPONEVENT_Pause,              // 2
  WEAPONEVENT_UnPause,            // 3
  WEAPONEVENT_MAX                 // 4
} EWeaponEventType;
typedef enum EWeaponBoneControllerType : unsigned char {
  WEAP_BONE_CONTROL_General,      // 0
  WEAP_BONE_CONTROL_BarrelSpinner,// 1
  WEAP_BONE_CONTROL_MagazineSpinner,// 2
  WEAP_BONE_CONTROL_Flap,         // 3
  WEAP_BONE_CONTROL_MAX           // 4
} EWeaponBoneControllerType;
typedef enum EWeaponHand               : unsigned char {
  HAND_Right,                     // 0
  HAND_Left,                      // 1
  HAND_Centered,                  // 2
  HAND_Hidden,                    // 3
  HAND_MAX                        // 4
} EWeaponHand;
typedef enum EWeaponVisibleAmmoState   : unsigned char {
  VISIBLE_AMMO_STATE_Default,     // 0
  VISIBLE_AMMO_STATE_PendingReload,// 1
  VISIBLE_AMMO_STATE_MAX          // 2
} EWeaponVisibleAmmoState;
#define EWeaponType                EWeaponType
#define EWeaponPartType            EWeaponPartType
#define EWeaponPartVariation       EWeaponPartVariation
#define EWeaponEventType           EWeaponEventType
#define EWeaponBoneControllerType  EWeaponBoneControllerType
#define EWeaponHand                EWeaponHand
#define EWeaponVisibleAmmoState    EWeaponVisibleAmmoState

/* ---------------------------------------------------------- UWillowInventoryDefinition ---------------------------------------------------------- */

typedef enum EPlayerDroppability      : unsigned char {
  EPD_Droppable,                  // 0
  EPD_Sellable,                   // 1
  EPD_CannotDropOrSell,           // 2
  EPD_MAX                         // 3
} EPlayerDroppability;
typedef enum ECurrencyType            : unsigned char {
  CURRENCY_Credits,               // 0
  CURRENCY_Eridium,               // 1
  CURRENCY_SeraphCrystals,        // 2
  CURRENCY_Reserved_A,            // 3
  CURRENCY_Reserved_B,            // 4
  CURRENCY_Reserved_C,            // 5
  CURRENCY_Reserved_D,            // 6
  CURRENCY_Reserved_E,            // 7
  CURRENCY_Reserved_F,            // 8
  CURRENCY_Reserved_G,            // 9
  CURRENCY_Reserved_H,            // 10
  CURRENCY_Reserved_I,            // 11
  CURRENCY_Reserved_J,            // 12
  CURRENCY_MAX                    // 13
#define ECurrencyType__MAX  CURRENCY_MAX
} ECurrencyType;
typedef enum EStatCombinationMethod   : unsigned char {
  SCM_Multiply,                   // 0
  SCM_Divide,                     // 1
  SCM_Add,                        // 2
  SCM_Subtract,                   // 3
  SCM_DontCombine,                // 4
  SCM_MAX                         // 5
} EStatCombinationMethod;
typedef enum EAttributeSlotEffectMode : unsigned char {
  ATTRSLOTEFFECTMODE_Default,     // 0
  ATTRSLOTEFFECTMODE_Timed,       // 1
  ATTRSLOTEFFECTMODE_Custom,      // 2
  ATTRSLOTEFFECTMODE_MAX          // 3
} EAttributeSlotEffectMode;
#define EPlayerDroppability       EPlayerDroppability
#define ECurrencyType             ECurrencyType
#define EStatCombinationMethod    EStatCombinationMethod
#define EAttributeSlotEffectMode  EAttributeSlotEffectMode

/* ---------------------------------------------------------- UWeaponTypeDefinition ---------------------------------------------------------- */

typedef enum EBarrelSpinMode : unsigned char {
  BSM_None,                       // 0
  BSM_SpinUpToFullFireRate,       // 1
  BSM_SpinBarrelWithEachShot,     // 2
  BSM_MAX                         // 3
} EBarrelSpinMode;
typedef enum EGbxWeaponLock : unsigned char {
  GBXWEAPLOCK_None,               // 0
  GBXWEAPLOCK_PaintAndHold,       // 1
  GBXWEAPLOCK_MAX                 // 2
} EGbxWeaponLock;
#define EGbxWeaponLock   EGbxWeaponLock

/* ---------------------------------------------------------- UAttributeDefinition ---------------------------------------------------------- */

typedef enum EAttributeTranslationStyle : unsigned char {
  ATTRSTYLE_JustNumber,           // 0
  ATTRSTYLE_ModifierText,         // 1
  ATTRSTYLE_Debug,                // 2
  ATTRSTYLE_LeaveBlank,           // 3
  ATTRSTYLE_MAX                   // 4
} EAttributeTranslationStyle;
#define EAttributeTranslationStyle  EAttributeTranslationStyle

/* ---------------------------------------------------------- URB_BodySetup ---------------------------------------------------------- */

typedef enum ESleepFamily : unsigned char {
  SF_Normal,                      // 0
  SF_Sensitive,                   // 1
  SF_MAX                          // 2
} ESleepFamily;
#define ESleepFamily  ESleepFamily

/* ---------------------------------------------------------- UInterpTrack ---------------------------------------------------------- */

typedef enum ETrackActiveCondition : unsigned char {
  ETAC_Always,                    // 0
  ETAC_GoreEnabled,               // 1
  ETAC_GoreDisabled,              // 2
  ETAC_MAX                        // 3
} ETrackActiveCondition;
typedef enum ETrackPlayDirection   : unsigned char {
  ETPD_PlayBoth,                  // 0
  ETPD_PlayOnlyForward,           // 1
  ETPD_PlayOnlyReverse,           // 2
  ETPD_MAX                        // 3
} ETrackPlayDirection;
#define ETrackActiveCondition  ETrackActiveCondition
#define ETrackPlayDirection    ETrackPlayDirection

/* ---------------------------------------------------------- UAnimSequence ---------------------------------------------------------- */

typedef enum AnimationCompressionFormat : unsigned char {
  ACF_None,                       // 0
  ACF_Float96NoW,                 // 1
  ACF_Fixed48NoW,                 // 2
  ACF_IntervalFixed32NoW,         // 3
  ACF_Fixed32NoW,                 // 4
  ACF_Float32NoW,                 // 5
  ACF_Delta40NoW,                 // 6
  ACF_Delta48NoW,                 // 7
  ACF_Identity,                   // 8
  ACF_PolarEncoded32,             // 9
  ACF_PolarEncoded48,             // 10
  ACF_MAX                         // 11
} AnimationCompressionFormat;
typedef enum AnimationKeyFormat         : unsigned char {
  AKF_ConstantKeyLerp,            // 0
  AKF_VariableKeyLerp,            // 1
  AKF_PerTrackCompression,        // 2
  AKF_MAX                         // 3
} AnimationKeyFormat;
#define AnimationCompressionFormat  AnimationCompressionFormat
#define AnimationKeyFormat          AnimationKeyFormat

/* ---------------------------------------------------------- UEngine ---------------------------------------------------------- */

typedef enum ETransitionType : unsigned char {
  TT_None,                        // 0
  TT_Paused,                      // 1
  TT_Loading,                     // 2
  TT_Saving,                      // 3
  TT_Connecting,                  // 4
  TT_Precaching,                  // 5
  TT_MAX                          // 6
} ETransitionType;
#define ETransitionType  ETransitionType

/* ---------------------------------------------------------- UGameEngine ---------------------------------------------------------- */

typedef enum EFullyLoadPackageType : unsigned char {
  FULLYLOAD_Map,                  // 0
  FULLYLOAD_Game_PreLoadClass,    // 1
  FULLYLOAD_Game_PostLoadClass,   // 2
  FULLYLOAD_Always,               // 3
  FULLYLOAD_Mutator,              // 4
  FULLYLOAD_MAX                   // 5
} EFullyLoadPackageType;
#define EFullyLoadPackageType  EFullyLoadPackageType

/* ---------------------------------------------------------- UGFxMoviePlayer ---------------------------------------------------------- */

typedef enum GFxTimingMode        : unsigned char {
  TM_Game,                        // 0
  TM_Real,                        // 1
  TM_MAX                          // 2
} GFxTimingMode;
typedef enum GFxRenderTextureMode : unsigned char {
  RTM_Opaque,                     // 0
  RTM_Alpha,                      // 1
  RTM_AlphaComposite,             // 2
  RTM_MAX                         // 3
} GFxRenderTextureMode;
typedef enum ASType               : unsigned char {
  AS_Undefined,                   // 0
  AS_Null,                        // 1
  AS_Number,                      // 2
  AS_String,                      // 3
  AS_Boolean,                     // 4
  AS_MAX                          // 5
} ASType;
typedef enum GFxScaleMode         : unsigned char {
  SM_NoScale,                     // 0
  SM_ShowAll,                     // 1
  SM_ExactFit,                    // 2
  SM_NoBorder,                    // 3
  SM_FitVertical,                 // 4
  SM_FitHorizontal,               // 5
  SM_MAX                          // 6
} GFxScaleMode;
typedef enum GFxAlign             : unsigned char {
  Align_Center,                   // 0
  Align_TopCenter,                // 1
  Align_BottomCenter,             // 2
  Align_CenterLeft,               // 3
  Align_CenterRight,              // 4
  Align_TopLeft,                  // 5
  Align_TopRight,                 // 6
  Align_BottomLeft,               // 7
  Align_BottomRight,              // 8
  Align_MAX                       // 9
} GFxAlign;
#define GFxTimingMode         GFxTimingMode
#define GFxRenderTextureMode  GFxRenderTextureMode
#define ASType                ASType
#define GFxScaleMode          GFxScaleMode
#define GFxAlign              GFxAlign

/* ---------------------------------------------------------- UAudioDevice ---------------------------------------------------------- */

typedef enum ESoundClassName : unsigned char {
  Master,                         // 0
  ESoundClassName_MAX             // 1
} ESoundClassName;
typedef enum EDebugState : unsigned char {
  DEBUGSTATE_None,                // 0
  DEBUGSTATE_IsolateDryAudio,     // 1
  DEBUGSTATE_IsolateReverb,       // 2
  DEBUGSTATE_TestLPF,             // 3
  DEBUGSTATE_TestStereoBleed,     // 4
  DEBUGSTATE_TestLFEBleed,        // 5
  DEBUGSTATE_DisableLPF,          // 6
  DEBUGSTATE_DisableRadio,        // 7
  DEBUGSTATE_MAX                  // 8
} EDebugState;
typedef enum ETTSSpeaker : unsigned char {
  TTSSPEAKER_Paul,                // 0
  TTSSPEAKER_Harry,               // 1
  TTSSPEAKER_Frank,               // 2
  TTSSPEAKER_Dennis,              // 3
  TTSSPEAKER_Kit,                 // 4
  TTSSPEAKER_Betty,               // 5
  TTSSPEAKER_Ursula,              // 6
  TTSSPEAKER_Rita,                // 7
  TTSSPEAKER_Wendy,               // 8
  TTSSPEAKER_MAX                  // 9
} ETTSSpeaker;
#define ESoundClassName  ESoundClassName
#define EDebugState      EDebugState
#define ETTSSpeaker      ETTSSpeaker

/* ---------------------------------------------------------- APawn ---------------------------------------------------------- */

static const int MAX_FLASHLOCATIONS = 10;

typedef enum EPathSearchType : unsigned char {
  PST_Default,                    // 0
  PST_Breadth,                    // 1
  PST_NewBestPathTo,              // 2
  PST_Constraint,                 // 3
  PST_MAX                         // 4
} EPathSearchType;
#define EPathSearchType  EPathSearchType

/* ---------------------------------------------------------- UGameViewportClient ---------------------------------------------------------- */

typedef enum ESplitScreenType : unsigned char {
  eSST_NONE,                      // 0
  eSST_2P_HORIZONTAL,             // 1
  eSST_2P_VERTICAL,               // 2
  eSST_3P_FAVOR_TOP,              // 3
  eSST_3P_FAVOR_BOTTOM,           // 4
  eSST_4P,                        // 5
  eSST_MAX                        // 6
} ESplitScreenType;
typedef enum ESafeZoneType    : unsigned char {
  eSZ_TOP,                        // 0
  eSZ_BOTTOM,                     // 1
  eSZ_LEFT,                       // 2
  eSZ_RIGHT,                      // 3
  eSZ_MAX                         // 4
} ESafeZoneType;
typedef enum EShowPathsOutput : unsigned char {
  eShowPaths_Off,                 // 0
  eAllReachSpecs,                 // 1
  eSpecialMovementsOnly,          // 2
  eNoSpecialMovements,            // 3
  EShowPathsOutput_MAX            // 4
} EShowPathsOutput;
#define ESplitScreenType  ESplitScreenType
#define ESafeZoneType     ESafeZoneType
#define EShowPathsOutput  EShowPathsOutput

/* ---------------------------------------------------------- UEngineTypes ---------------------------------------------------------- */

typedef enum EPathFindingError               : unsigned char {
  PATHERROR_STARTPOLYNOTFOUND,    // 0
  PATHERROR_GOALPOLYNOTFOUND,     // 1
  PATHERROR_ANCHORPYLONNOTFOUND,  // 2
  PATHERROR_NOPATHFOUND,          // 3
  PATHERROR_COMPUTEVALIDFINALDEST_FAIL,// 4
  PATHERROR_GETNEXTMOVELOCATION_FAIL,// 5
  PATHERROR_MAX                   // 6
} EPathFindingError;
typedef enum EBlendMode                      : unsigned char {
  BLEND_Opaque,                   // 0
  BLEND_Masked,                   // 1
  BLEND_Translucent,              // 2
  BLEND_Additive,                 // 3
  BLEND_Modulate,                 // 4
  BLEND_SoftMasked,               // 5
  BLEND_AlphaComposite,           // 6
  BLEND_DitheredTranslucent,      // 7
  BLEND_MAX                       // 8
} EBlendMode;
typedef enum EMaterialLightingModel          : unsigned char {
  MLM_Phong,                      // 0
  MLM_NonDirectional,             // 1
  MLM_Unlit,                      // 2
  MLM_SHPRT,                      // 3
  MLM_Custom,                     // 4
  MLM_Anisotropic,                // 5
  MLM_MAX                         // 6
} EMaterialLightingModel;
typedef enum EMaterialTessellationMode       : unsigned char {
  MTM_NoTessellation,             // 0
  MTM_FlatTessellation,           // 1
  MTM_PNTriangles,                // 2
  MTM_MAX                         // 3
} EMaterialTessellationMode;
typedef enum EMobileTextureTransformTarget   : unsigned char {
  MTTT_BaseTexture,               // 0
  MTTT_DetailTexture,             // 1
  MTTT_MAX                        // 2
} EMobileTextureTransformTarget;
typedef enum EMobileValueSource              : unsigned char {
  MVS_Constant,                   // 0
  MVS_VertexColorRed,             // 1
  MVS_VertexColorGreen,           // 2
  MVS_VertexColorBlue,            // 3
  MVS_VertexColorAlpha,           // 4
  MVS_BaseTextureRed,             // 5
  MVS_BaseTextureGreen,           // 6
  MVS_BaseTextureBlue,            // 7
  MVS_BaseTextureAlpha,           // 8
  MVS_MaskTextureRed,             // 9
  MVS_MaskTextureGreen,           // 10
  MVS_MaskTextureBlue,            // 11
  MVS_MaskTextureAlpha,           // 12
  MVS_NormalTextureAlpha,         // 13
  MVS_MAX                         // 14
} EMobileValueSource;
typedef enum EMobileTextureBlendFactorSource : unsigned char {
  MTBFS_VertexColor,              // 0
  MTBFS_MaskTexture,              // 1
  MTBFS_MAX                       // 2
} EMobileTextureBlendFactorSource;
typedef enum EMobileTexCoordsSource          : unsigned char {
  MTCS_TexCoords0,                // 0
  MTCS_TexCoords1,                // 1
  MTCS_TexCoords2,                // 2
  MTCS_TexCoords3,                // 3
  MTCS_MAX                        // 4
} EMobileTexCoordsSource;
typedef enum EMobileEmissiveColorSource      : unsigned char {
  MECS_EmissiveTexture,           // 0
  MECS_BaseTexture,               // 1
  MECS_Constant,                  // 2
  MECS_MAX                        // 3
} EMobileEmissiveColorSource;
typedef enum EMobileEnvironmentBlendMode     : unsigned char {
  MEBM_Add,                       // 0
  MEBM_Lerp,                      // 1
  MEBM_MAX                        // 2
} EMobileEnvironmentBlendMode;
typedef enum EMobileSpecularMask             : unsigned char {
  MSM_Constant,                   // 0
  MSM_Luminance,                  // 1
  MSM_DiffuseRed,                 // 2
  MSM_DiffuseGreen,               // 3
  MSM_DiffuseBlue,                // 4
  MSM_DiffuseAlpha,               // 5
  MSM_MaskTextureRGB,             // 6
  MSM_MAX                         // 7
} EMobileSpecularMask;
typedef enum EMobileAmbientOcclusionSource   : unsigned char {
  MAOS_Disabled,                  // 0
  MAOS_VertexColorRed,            // 1
  MAOS_VertexColorGreen,          // 2
  MAOS_VertexColorBlue,           // 3
  MAOS_VertexColorAlpha,          // 4
  MAOS_MAX                        // 5
} EMobileAmbientOcclusionSource;
typedef enum ELightingBuildQuality           : unsigned char {
  Quality_Preview,                // 0
  Quality_Medium,                 // 1
  Quality_High,                   // 2
  Quality_Production,             // 3
  Quality_NoGlobalIllumination,   // 4
  Quality_MAX                     // 5
} ELightingBuildQuality;
#define EPathFindingError                EPathFindingError
#define EBlendMode                       EBlendMode
#define EMaterialLightingModel           EMaterialLightingModel
#define EMaterialTessellationMode        EMaterialTessellationMode
#define EMobileTextureTransformTarget    EMobileTextureTransformTarget
#define EMobileValueSource               EMobileValueSource
#define EMobileTextureBlendFactorSource  EMobileTextureBlendFactorSource
#define EMobileTexCoordsSource           EMobileTexCoordsSource
#define EMobileEmissiveColorSource       EMobileEmissiveColorSource
#define EMobileEnvironmentBlendMode      EMobileEnvironmentBlendMode
#define EMobileSpecularMask              EMobileSpecularMask
#define EMobileAmbientOcclusionSource    EMobileAmbientOcclusionSource
#define ELightingBuildQuality            ELightingBuildQuality

/* ---------------------------------------------------------- UResourcePool ---------------------------------------------------------- */

typedef enum EResourcePoolState : unsigned char {
  RPS_Depleted,                   // 0
  RPS_Filled,                     // 1
  RPS_Regenerating,               // 2
  RPS_MAX                         // 3
} EResourcePoolState;
#define EResourcePoolState  EResourcePoolState

/* ---------------------------------------------------------- UResourcePoolDefinition ---------------------------------------------------------- */

typedef enum ENetRelevantFor : unsigned char {
  NETRELEVANT_Everyone,           // 0
  NETRELEVANT_Owner,              // 1
  NETRELEVANT_Server,             // 2
  NETRELEVANT_MAX                 // 3
} ENetRelevantFor;
#define ENetRelevantFor  ENetRelevantFor

/* ---------------------------------------------------------- UMusicTrackDataStructures ---------------------------------------------------------- */

typedef enum EMusicState : unsigned char {
  MUSIC_PlayingAmbientMusic,      // 0
  MUSIC_PlayingCustomAmbientMusic,// 1
  MUSIC_PlayingCombatMusicFull,   // 2
  MUSIC_PlayingCombatMusicMid,    // 3
  MUSIC_PlayingBossMusic,         // 4
  MUSIC_PlayingCustomCombatMusic, // 5
  MUSIC_MAX                       // 6
} EMusicState;
#define EMusicState  EMusicState

/* ---------------------------------------------------------- FPacketSimulationSettings ---------------------------------------------------------- */

/* Types of channels. */
typedef enum EChannelType : unsigned char {
	CHTYPE_None			= 0,  // Invalid type.
	CHTYPE_Control		= 1,  // Connection control.
	CHTYPE_Actor  		= 2,  // Actor-update channel.
	CHTYPE_File         = 3,  // Binary file transfer.
	CHTYPE_Voice		= 4,  // VoIP data channel
	CHTYPE_MAX          = 8,  // Maximum.
} EChannelType;
#define EChannelType  EChannelType

/* ---------------------------------------------------------- UWillowDamageTypeDefinition ---------------------------------------------------------- */

typedef enum EDamageType : unsigned char {
  DAMAGE_TYPE_Unknown,            // 0
  DAMAGE_TYPE_Incindiary,         // 1
  DAMAGE_TYPE_Shock,              // 2
  DAMAGE_TYPE_Explosive,          // 3
  DAMAGE_TYPE_Corrosive,          // 4
  DAMAGE_TYPE_Impact,             // 5
  DAMAGE_TYPE_Healing,            // 6
  DAMAGE_TYPE_Amp,                // 7
  DAMAGE_TYPE_MAX                 // 8
} EDamageType;
#define EDamageType  EDamageType
_DECL_TARRAY(EDamageType);

/* ---------------------------------------------------------- UBehaviorBase ---------------------------------------------------------- */

typedef enum EBehaviorContext : unsigned char {
  BCONTEXT_Self,                  // 0
  BCONTEXT_MyInstigator,          // 1
  BCONTEXT_OtherEventParticipant, // 2
  BCONTEXT_EventData,             // 3
  BCONTEXT_UseContextObject,      // 4
  BCONTEXT_MAX                    // 5
} EBehaviorContext;
#define EBehaviorContext  EBehaviorContext

/* ---------------------------------------------------------- UStatusEffectDefinition ---------------------------------------------------------- */

typedef enum EStatusEffectType : unsigned char {
  STATUS_EFFECT_Unknown,          // 0
  STATUS_EFFECT_Ignite,           // 1
  STATUS_EFFECT_Corrosive,        // 2
  STATUS_EFFECT_Shock,            // 3
  STATUS_EFFECT_Amp,              // 4
  STATUS_EFFECT_Slow,             // 5
  STATUS_EFFECT_Healing,          // 6
  STATUS_EFFECT_MAX               // 7
  #define STATUS_EFFECT_Unknown    STATUS_EFFECT_Unknown
  #define STATUS_EFFECT_Ignite     STATUS_EFFECT_Ignite
  #define STATUS_EFFECT_Corrosive  STATUS_EFFECT_Corrosive
  #define STATUS_EFFECT_Shock      STATUS_EFFECT_Shock
  #define STATUS_EFFECT_Amp        STATUS_EFFECT_Amp
  #define STATUS_EFFECT_Slow       STATUS_EFFECT_Slow
  #define STATUS_EFFECT_Healing    STATUS_EFFECT_Healing
  #define STATUS_EFFECT_MAX        STATUS_EFFECT_MAX
  #define EStatusEffectType__MAX   STATUS_EFFECT_MAX
} EStatusEffectType;
#define EStatusEffectType  EStatusEffectType

/* ---------------------------------------------------------- UWillowPhysicalMaterialProperty ---------------------------------------------------------- */

typedef enum EImpactUsage       : unsigned char {
  IU_None,                        // 0
  IU_Footstep,                    // 1
  IU_Bullet,                      // 2
  IU_MAX                          // 3
} EImpactUsage;
typedef enum EDamageSurfaceType : unsigned char {
  DMGSURFACE_Generic,             // 0
  DMGSURFACE_Flesh,               // 1
  DMGSURFACE_Armor,               // 2
  DMGSURFACE_Shield,              // 3
  DMGSURFACE_MAX                  // 4
} EDamageSurfaceType;
#define EImpactUsage        EImpactUsage
#define EDamageSurfaceType  EDamageSurfaceType

/* ---------------------------------------------------------- UIScreenParticle ---------------------------------------------------------- */

typedef enum ScreenParticleScalingMode : unsigned char {
  ESPSM_FitToHorizontal,          // 0
  ESPSM_FitToVertical,            // 1
  ESPSM_FitToExterior,            // 2
  ESPSM_FitToInterior,            // 3
  ESPSM_FitToViewport,            // 4
  ESPSM_MAX                       // 5
} ScreenParticleScalingMode;
#define ScreenParticleScalingMode  ScreenParticleScalingMode

/* ---------------------------------------------------------- UIUpdatePostProcessOverride ---------------------------------------------------------- */

typedef enum EPostProcessOverrideUpdatePhase : unsigned char {
  PPUPDATEPHASE_None,             // 0
  PPUPDATEPHASE_TransitionIn,     // 1
  PPUPDATEPHASE_TransitionHold,   // 2
  PPUPDATEPHASE_TransitionOut,    // 3
  PPUPDATEPHASE_MAX               // 4
} EPostProcessOverrideUpdatePhase;
typedef enum EAttributeScalarParamOperand    : unsigned char {
  ASPO_None,                      // 0
  ASPO_Add,                       // 1
  ASPO_Subtract,                  // 2
  ASPO_MAX                        // 3
} EAttributeScalarParamOperand;
#define EPostProcessOverrideUpdatePhase  EPostProcessOverrideUpdatePhase
#define EAttributeScalarParamOperand     EAttributeScalarParamOperand

/* ---------------------------------------------------------- UDOFEffect ---------------------------------------------------------- */

typedef enum EFocusType : unsigned char {
  FOCUS_Distance,                 // 0
  FOCUS_Position,                 // 1
  FOCUS_MAX                       // 2
} EFocusType;
#define EFocusType  EFocusType

/* ---------------------------------------------------------- FRawDistribution ---------------------------------------------------------- */

typedef enum ERawDistributionType      : unsigned char {
	RDT_Float_Constant,

	DT_Vector_Constant,
} ERawDistributionType;
typedef enum ERawDistributionOperation : unsigned char {
	RDO_Uninitialized,
	RDO_None,
	RDO_Random,
	RDO_Extreme,
} ERawDistributionOperation;
typedef enum ERawDistributionLockFlags : unsigned char {
	RDL_None,
	RDL_XY,
	RDL_XZ,
	RDL_YZ,
	RDL_XYZ,
} ERawDistributionLockFlags;
#define ERawDistributionType       ERawDistributionType
#define ERawDistributionOperation  ERawDistributionOperation
#define ERawDistributionLockFlags  ERawDistributionLockFlags

/* ---------------------------------------------------------- FRunnableThread ---------------------------------------------------------- */

/* The list of enumerated thread priorities we support. */
typedef enum EThreadPriority : unsigned char {
	TPri_Normal,
	TPri_AboveNormal,
	TPri_BelowNormal
} EThreadPriority;
#define EThreadPriority  EThreadPriority

/* ---------------------------------------------------------- Shader PLACEHOLDER ---------------------------------------------------------- */

/**
 * Material shader platforms represent the different versions of FMaterialResources 
 * that will have to be stored for a single UMaterial.  Note that multiple shader platforms 
 * can map to a single material platform.
 */
typedef enum EMaterialShaderPlatform : unsigned char {
	MSP_BASE				=0,
	MSP_SM3                 =0,
	MSP_MAX                 =1
} EMaterialShaderPlatform;
typedef enum EShaderFrequency        : unsigned char {
	SF_Vertex			= 0,
	SF_Hull				= 1,
	SF_Domain			= 2,
	SF_Pixel			= 3,
	SF_Geometry			= 4,
	SF_Compute			= 5,

	SF_NumFrequencies	= 6,
	SF_NumBits			= 3,
} EShaderFrequency;
/** @warning: update ShaderPlatformToText and GetMaterialPlatform when the below changes */
typedef enum EShaderPlatform         : unsigned char {
	SP_PCD3D_SM3		= 0,
	SP_PS3				= 1,
	SP_XBOXD3D			= 2,
	SP_PCD3D_SM4		= 3,
	SP_PCD3D_SM5		= 4,
	SP_NGP				= 5,
	SP_PCOGL			= 6,

	SP_NumPlatforms		= 7,
	SP_NumBits			= 3,
} EShaderPlatform;
typedef enum ECompilerFlags          : unsigned char {
	CFLAG_PreferFlowControl = 0,
	CFLAG_Debug,
	CFLAG_AvoidFlowControl,
	/** Disable shader validation */
	CFLAG_SkipValidation
} ECompilerFlags;
typedef enum EWorkerJobType          : unsigned char {
	WJT_D3D9Shader = 0,
	WJT_D3D11Shader,
	WJT_XenonShader,
	WJT_PS3Shader,
	WJT_WorkerError,
	WJT_JobTypeMax
} EWorkerJobType;
#define ECompilerFlags           ECompilerFlags
#define EMaterialShaderPlatform  EMaterialShaderPlatform
#define EShaderFrequency         EShaderFrequency
#define EShaderPlatform          EShaderPlatform
#define EWorkerJobType           EWorkerJobType

/* ---------------------------------------------------------- UDebugger ---------------------------------------------------------- */

/*-----------------------------------------------------------------------------
	UDebugger Opcodes.
-----------------------------------------------------------------------------*/
typedef enum EDebugInfo  : unsigned char {
	DI_Let					= 0x00,
	DI_SimpleIf				= 0x01,
	DI_Switch				= 0x02,
	DI_While				= 0x03,
	DI_Assert				= 0x04,
	DI_Return				= 0x10,
	DI_ReturnNothing		= 0x11,
	DI_NewStack				= 0x20,
	DI_NewStackLatent		= 0x21,
	DI_NewStackLabel		= 0x22,
	DI_NewStackState		= 0x23,
	DI_PrevStack			= 0x30,
	DI_PrevStackLatent		= 0x31,
	DI_PrevStackLabel		= 0x32,
	DI_PrevStackState		= 0x33,
	DI_EFP					= 0x40,
	DI_EFPOper				= 0x41,
	DI_EFPIter				= 0x42,
	DI_ForInit				= 0x50,
	DI_ForEval				= 0x51,
	DI_ForInc				= 0x52,
	DI_BreakLoop			= 0x60,
	DI_BreakFor				= 0x61,
	DI_BreakForEach			= 0x62,
	DI_BreakSwitch			= 0x63,
	DI_ContinueLoop			= 0x70,
	DI_ContinueForeach		= 0x71,
	DI_ContinueFor			= 0x72,
	DI_MAX					= 0xFF,
} EDebugInfo;
/* The types of user commands that the debugger engine responds to. */
typedef enum EUserAction : unsigned char {
	UA_None,

	/** end the current game session */
	UA_Exit,

	/** step into the current line; if the current line is a function call, steps into that function */
	UA_StepInto,

	/** step over the next instruction (i.e. for stepping into different parts of a for loop); not yet implemented */
	UA_StepOver,

	/** step over the next line of code, skipping all instructions on the current line */
	UA_StepOverStack,

	/** step out of the current function */
	UA_StepOut, 

	/** continue execution until the code reaches the specified line/instruction; not yet implemented */
	UA_RunToCursor,

	/** continue execution and return control to the debugger engine */
	UA_Go,

	UA_MAX,
} EUserAction;
#define EDebugInfo   EDebugInfo
#define EUserAction  EUserAction

/* ---------------------------------------------------------- FIOManager ---------------------------------------------------------- */

typedef enum EIOSystemTag     : unsigned char {
	IOSYSTEM_GenericAsync,
	IOSYSTEM_LastEpicEntry,
} EIOSystemTag;
/* Enum for async IO priorities. */
typedef enum EAsyncIOPriority : unsigned char {
	AIOP_MIN	= 0,
	AIOP_Low,
	AIOP_BelowNormal,
	AIOP_Normal,
	AIOP_High,
	AIOP_MAX
} EAsyncIOPriority;
#define EIOSystemTag      EIOSystemTag
#define EAsyncIOPriority  EAsyncIOPriority

/* ---------------------------------------------------------- USparkInterface ---------------------------------------------------------- */

typedef enum HttpMimeType : unsigned char {
  HMT_Default,                    // 0
  HMT_TEXT_PLAIN,                 // 1
  HMT_JSON,                       // 2
  HMT_PROTOBUF,                   // 3
  HMT_CUSTOM,                     // 4
  HMT_MAX                         // 5
} HttpMimeType;
typedef enum HttpMethod   : unsigned char {
  HM_POST,                        // 0
  HM_GET,                         // 1
  HM_PUT,                         // 2
  HM_MAX                          // 3
} HttpMethod;
#define HttpMimeType  HttpMimeType
#define HttpMethod    HttpMethod

/* ---------------------------------------------------------- UWillowGameEngine ---------------------------------------------------------- */

typedef enum ELevelChangeState : unsigned char {
  LCS_None,                       // 0
  LCS_SyncingCommit,              // 1
  LCS_SyncingUnPause,             // 2
  LCS_MAX                         // 3
} ELevelChangeState;
#define ELevelChangeState  ELevelChangeState

/* ---------------------------------------------------------- UAIComponent ---------------------------------------------------------- */

typedef enum AINodeType   : unsigned char {
  NodeType_Blank,                 // 0
  NodeType_Action,                // 1
  NodeType_Random,                // 2
  NodeType_Priority,              // 3
  NodeType_Sequential,            // 4
  NodeType_MAX                    // 5
} AINodeType;
typedef enum AIFailReason : unsigned char {
  AIFail_None,                    // 0
  AIFail_Timer,                   // 1
  AIFail_Failed,                  // 2
  AIFail_Action,                  // 3
  AIFail_Resource,                // 4
  AIFail_Conditional,             // 5
  AIFail_MAX                      // 6
} AIFailReason;
#define AINodeType    AINodeType
#define AIFailReason  AIFailReason

/*-----------------------------------------------------------------------------
	Level updating. Moved out here from UnLevel.h so that AActor.h can use it (needed for gcc)
-----------------------------------------------------------------------------*/

typedef enum ELevelTick : unsigned char {
	LEVELTICK_TimeOnly		= 0,	// Update the level time only.
	LEVELTICK_ViewportsOnly	= 1,	// Update time and viewports.
	LEVELTICK_All			= 2,	// Update all.
} ELevelTick;
#define ELevelTick  ELevelTick

/* ---------------------------------------------------------- UITargetable ---------------------------------------------------------- */

typedef enum EAutoAimProfile : unsigned char {
  AAP_Heavy,                      // 0
  AAP_Medium,                     // 1
  AAP_Light,                      // 2
  AAP_None,                       // 3
  AAP_MAX                         // 4
} EAutoAimProfile;
typedef enum EInfoBarType    : unsigned char {
  EIBT_Shield,                    // 0
  EIBT_Health,                    // 1
  EIBT_Vehicle,                   // 2
  EIBT_Minibar,                   // 3
  EIBT_MAX                        // 4
} EInfoBarType;
typedef enum EChangeStatus   : unsigned char {
  CHANGE_Toggle,                  // 0
  CHANGE_Enable,                  // 1
  CHANGE_Disable,                 // 2
  CHANGE_MAX                      // 3
} EChangeStatus;
#define EAutoAimProfile  EAutoAimProfile
#define EInfoBarType     EInfoBarType
#define EChangeStatus    EChangeStatus

/* ---------------------------------------------------------- UDamagePipeline ---------------------------------------------------------- */

typedef enum EReflectionType       : unsigned char {
  REFLT_None,                     // 0
  REFLT_Instigator,               // 1
  REFLT_Self,                     // 2
  REFLT_MAX                       // 3
} EReflectionType;
typedef enum EDamageSkillEventType : unsigned char {
  DSET_DamageTaken,               // 0
  DSET_DamageDealt,               // 1
  DSET_MAX                        // 2
} EDamageSkillEventType;
#define EReflectionType        EReflectionType
#define EDamageSkillEventType  EDamageSkillEventType

/**
 * The priority a hit proxy has when choosing between several hit proxies near the point the user clicked.
 * HPP_World - this is the default priority
 * HPP_Wireframe - the priority of items that are drawn in wireframe, such as volumes
 * HPP_UI - the priority of the UI components such as the translation widget
 */
typedef enum EHitProxyPriority : unsigned char {
	HPP_World = 0,
	HPP_Wireframe = 1,
	HPP_UI = 2
} EHitProxyPriority;
typedef enum EMouseCursor      : unsigned char {
	MC_None,
	MC_NoChange,		// Keeps the platform client from calling setcursor so a cursor can be set elsewhere (ie using wxSetCursor).
	MC_Arrow,
	MC_Cross,
	MC_SizeAll,
	MC_SizeUpRightDownLeft,
	MC_SizeUpLeftDownRight,
	MC_SizeLeftRight,
	MC_SizeUpDown,
	MC_Hand,
	MC_GrabHand
} EMouseCursor;
#define EHitProxyPriority  EHitProxyPriority
#define EMouseCursor       EMouseCursor

/* ---------------------------------------------------------- AWillowPlayerPawn ---------------------------------------------------------- */

typedef enum ERegionList           : unsigned char {
  ERL_Firestone,                  // 0
  ERL_NewHaven,                   // 1
  ERL_MAX                         // 2
} ERegionList;
typedef enum EInjuredPreDeathState : unsigned char {
  INJUREDPREDEATH_None,           // 0
  INJUREDPREDEATH_Start,          // 1
  INJUREDPREDEATH_Stop,           // 2
  INJUREDPREDEATH_MAX             // 3
} EInjuredPreDeathState;
#define ERegionList            ERegionList
#define EInjuredPreDeathState  EInjuredPreDeathState

/* ---------------------------------------------------------- UIInstanceData ---------------------------------------------------------- */

typedef enum EInstanceDataType : unsigned char {
  IDT_Bool,                       // 0
  IDT_Int,                        // 1
  IDT_Float,                      // 2
  IDT_Vector,                     // 3
  IDT_Object,                     // 4
  IDT_ActorComponent,             // 5
  IDT_Actor,                      // 6
  IDT_ActorTemplate,              // 7
  IDT_String,                     // 8
  IDT_Switch,                     // 9
  IDT_PickupTemplate,             // 10
  IDT_CustomHead,                 // 11
  IDT_CustomSkin,                 // 12
  IDT_MAX                         // 13
} EInstanceDataType;
typedef enum EReplicationType  : unsigned char {
  IDR_Server,                     // 0
  IDR_Client,                     // 1
  IDR_Local,                      // 2
  IDR_MAX                         // 3
} EReplicationType;
#define EInstanceDataType  EInstanceDataType
#define EReplicationType   EReplicationType

/* ---------------------------------------------------------- UInventoryListPanelGFxObject ---------------------------------------------------------- */

typedef enum EInventoryListType : unsigned char {
  ELT_Weapon,                     // 0
  ELT_Shield,                     // 1
  ELT_GrenadeMod,                 // 2
  ELT_ClassMod,                   // 3
  ELT_Artifact,                   // 4
  ELT_None,                       // 5
  ELT_MAX                         // 6
} EInventoryListType;
#define EInventoryListType  EInventoryListType

/* ---------------------------------------------------------- UInventoryDataProviderGFxObject ---------------------------------------------------------- */

typedef enum EInventorySortType      : unsigned char {
  IST_EquippedThenMajorTypeThenRarityThenSubtype,// 0
  IST_MajorTypeThenSubtypeThenRarity,// 1
  IST_MajorTypeThenRarityThenSubtype,// 2
  IST_Manufacturer,               // 3
  IST_ClassRequirementThenRarity, // 4
  IST_Value,                      // 5
  IST_MAX                         // 6
} EInventorySortType;
typedef enum EInventoryFilterType    : unsigned char {
  IFT_NoFilter,                   // 0
  IFT_FilterUncomparable,         // 1
  IFT_FilterWeapons,              // 2
  IFT_FilterNonWeapons,           // 3
  IFT_FilterNonShields,           // 4
  IFT_FilterNonGrenadeMods,       // 5
  IFT_FilterNonClassMods,         // 6
  IFT_FilterNonUpgrades,          // 7
  IFT_FilterNonHealth,            // 8
  IFT_FilterNonGenerics,          // 9
  IFT_MAX                         // 10
} EInventoryFilterType;
typedef enum ECategoryAssignmentType : unsigned char {
  CAType_None,                    // 0
  CAType_InventoryType,           // 1
  CAType_Manufacturers,           // 2
  CAType_WeaponType,              // 3
  CAType_ClassRequirement,        // 4
  CAType_PersonalOrShop,          // 5
  CAType_Equipped,                // 6
  CAType_MAX                      // 7
} ECategoryAssignmentType;
#define EInventorySortType       EInventorySortType
#define EInventoryFilterType     EInventoryFilterType
#define ECategoryAssignmentType  ECategoryAssignmentType

/* ---------------------------------------------------------- AWillowPlayerController ---------------------------------------------------------- */

typedef enum EInstinctSkillActions    : unsigned char {
  ISA_Targeting,                  // 0
  ISA_Targeted,                   // 1
  ISA_KilledEnemy,                // 2
  ISA_AppliedStatusEffect,        // 3
  ISA_CriticalHit,                // 4
  ISA_TookPhysicalDamage,         // 5
  ISA_GaveDamage,                 // 6
  ISA_TookStatusEffectDamage,     // 7
  ISA_ScoredHit,                  // 8
  ISA_DealtExplosiveDamage,       // 9
  ISA_FriendWentDown,             // 10
  ISA_DealtStatusEffectDamage,    // 11
  ISA_TookShieldDamage,           // 12
  ISA_MAX                         // 13
} EInstinctSkillActions;
typedef enum EMissionFanfareType      : unsigned char {
  EMFT_NewMissionAccepted,        // 0
  EMFT_NewMissionActive,          // 1
  EMFT_NewPlotMissionActive,      // 2
  EMFT_ObjectiveIncremented,      // 3
  EMFT_ObjectiveComplete,         // 4
  EMFT_ObjectiveCleared,          // 5
  EMFT_MissionReadyToTurnIn,      // 6
  EMFT_MissionCompleted,          // 7
  EMFT_PingNonTrackedOnly,        // 8
  EMFT_MAX                        // 9
} EMissionFanfareType;
typedef enum EPresenceModeContext     : unsigned char {
  EPMC_Any,                       // 0
  EPMC_OnFoot,                    // 1
  EPMC_Driving,                   // 2
  EPMC_Dueling,                   // 3
  EPMC_OpenSlots,                 // 4
  EPMC_MAX                        // 5
} EPresenceModeContext;
typedef enum EQuickSelectSlotStatus   : unsigned char {
  QSSS_Available,                 // 0
  QSSS_Locked,                    // 1
  QSSS_Selected,                  // 2
  QSSS_MAX                        // 3
} EQuickSelectSlotStatus;
typedef enum EBackButtonScreen        : unsigned char {
  CS_None,                        // 0
  CS_MissionLog,                  // 1
  CS_Map,                         // 2
  CS_Inventory,                   // 3
  CS_Skills,                      // 4
  CS_Challenges,                  // 5
  CS_MAX                          // 6
} EBackButtonScreen;
typedef enum EMissionSortType         : unsigned char {
  MSORT_Region,                   // 0
  MSORT_Status,                   // 1
  MSORT_Difficulty,               // 2
  MSORT_Chronological,            // 3
  MSORT_Expansion,                // 4
  MSORT_MAX                       // 5
} EMissionSortType;
typedef enum EColiseumGameOver        : unsigned char {
  ECGM_TryAgain,                  // 0
  ECGM_Lobby,                     // 1
  ECGM_MAX                        // 2
} EColiseumGameOver;
typedef enum EColiseumStatType        : unsigned char {
  ECSTAT_Kills,                   // 0
  ECSTAT_MAX                      // 1
} EColiseumStatType;
typedef enum EConnectionAttemptStatus : unsigned char {
  COAS_ServerFull,                // 0
  COAS_ServerUnavailable,         // 1
  COAS_DLCMismatch,               // 2
  COAS_ClientOutdated,            // 3
  COAS_ServerOutdated,            // 4
  COAS_MAX                        // 5
} EConnectionAttemptStatus;
typedef enum ELoadGameResult          : unsigned char {
  LGR_Failure,                    // 0
  LGR_Success,                    // 1
  LGR_Pending,                    // 2
  LGR_CorruptedFailure,           // 3
  LGR_UnloadedDLCFailure,         // 4
  LGR_DuplicateFailure,           // 5
  LGR_MAX                         // 6
} ELoadGameResult;
typedef enum EWillowNetworkType       : unsigned char {
  WNT_Internet,                   // 0
  WNT_SystemLink,                 // 1
  WNT_Offline,                    // 2
  WNT_MAX                         // 3
} EWillowNetworkType;
typedef enum EWillowInviteType        : unsigned char {
  WIT_InviteRequired,             // 0
  WIT_FriendsOnly,                // 1
  WIT_Public,                     // 2
  WIT_MAX                         // 3
} EWillowInviteType;
typedef enum EOnlineMessageType       : unsigned char {
  OMT_None,                       // 0
  OMT_Network,                    // 1
  OMT_Dlc,                        // 2
  OMT_Mission,                    // 3
  OMT_Travel,                     // 4
  OMT_Misc,                       // 5
  OMT_MAX                         // 6
} EOnlineMessageType;
#define EInstinctSkillActions     EInstinctSkillActions
#define EMissionFanfareType       EMissionFanfareType
#define EPresenceModeContext      EPresenceModeContext
#define EQuickSelectSlotStatus    EQuickSelectSlotStatus
#define EBackButtonScreen         EBackButtonScreen
#define EMissionSortType          EMissionSortType
#define EColiseumGameOver         EColiseumGameOver
#define EColiseumStatType         EColiseumStatType
#define EConnectionAttemptStatus  EConnectionAttemptStatus
#define ELoadGameResult           ELoadGameResult
#define EWillowNetworkType        EWillowNetworkType
#define EWillowInviteType         EWillowInviteType
#define EOnlineMessageType        EOnlineMessageType

/* ---------------------------------------------------------- FStreamingManagerBase ---------------------------------------------------------- */

typedef enum EDynamicPrimitiveType : unsigned char {
	DPT_Level,
	DPT_Spawned,
	DPT_MAX
} EDynamicPrimitiveType;
#define EDynamicPrimitiveType  EDynamicPrimitiveType

/* ---------------------------------------------------------- UInstanceDataHelper ---------------------------------------------------------- */

typedef enum EBodyCompositionApplicationMode : unsigned char {
  EBCAM_Game,                     // 0
  EBCAM_BackMenu,                 // 1
  EBCAM_BackMenuInspection,       // 2
  EBCAM_EditorPreview,            // 3
  EBCAM_Frontend,                 // 4
  EBCAM_Foreground,               // 5
  EBCAM_MAX                       // 6
} EBodyCompositionApplicationMode;
#define EBodyCompositionApplicationMode  EBodyCompositionApplicationMode

/* ---------------------------------------------------------- UProjectileDefinition ---------------------------------------------------------- */

typedef enum EProjectileType         : unsigned char {
  PROJECTILE_TYPE_Unknown,        // 0
  PROJECTILE_TYPE_Frag_Grenade,   // 1
  PROJECTILE_TYPE_Protean_Grenade,// 2
  PROJECTILE_TYPE_Rocket,         // 3
  PROJECTILE_TYPE_MAX             // 4
} EProjectileType;
typedef enum EHomingTargetChangeType : unsigned char {
  HTC_AnyTarget,                  // 0
  HTC_NewTarget,                  // 1
  HTC_LostTarget,                 // 2
  HTC_MAX                         // 3
} EHomingTargetChangeType;
typedef enum EProjectileOnHitOutputs : unsigned char {
  ProjectileOnHit_All,            // 0
  ProjectileOnHit_Enemy,          // 1
  ProjectileOnHit_Friendly,       // 2
  ProjectileOnHit_Neutral,        // 3
  ProjectileOnHit_MAX             // 4
} EProjectileOnHitOutputs;
#define EProjectileType          EProjectileType
#define EHomingTargetChangeType  EHomingTargetChangeType
#define EProjectileOnHitOutputs  EProjectileOnHitOutputs

/* ---------------------------------------------------------- UParticleSystemComponent ---------------------------------------------------------- */

typedef enum EParticleSysParamType : unsigned char {
  PSPT_None,                      // 0
  PSPT_Scalar,                    // 1
  PSPT_ScalarRand,                // 2
  PSPT_Vector,                    // 3
  PSPT_VectorRand,                // 4
  PSPT_Color,                     // 5
  PSPT_Actor,                     // 6
  PSPT_Material,                  // 7
  PSPT_MAX                        // 8
} EParticleSysParamType;
typedef enum ParticleReplayState   : unsigned char {
  PRS_Disabled,                   // 0
  PRS_Capturing,                  // 1
  PRS_Replaying,                  // 2
  PRS_MAX                         // 3
} ParticleReplayState;
typedef enum EParticleEventType    : unsigned char {
  EPET_Any,                       // 0
  EPET_Spawn,                     // 1
  EPET_Death,                     // 2
  EPET_Collision,                 // 3
  EPET_Kismet,                    // 4
  EPET_Trace,                     // 5
  EPET_MAX                        // 6
} EParticleEventType;
#define EParticleSysParamType  EParticleSysParamType
#define ParticleReplayState    ParticleReplayState
#define EParticleEventType     EParticleEventType

/* ---------------------------------------------------------- UParticleSystem ---------------------------------------------------------- */

typedef enum EParticleSystemUpdateMode            : unsigned char {
  EPSUM_RealTime,                 // 0
  EPSUM_FixedTime,                // 1
  EPSUM_MAX                       // 2
} EParticleSystemUpdateMode;
typedef enum ParticleSystemLODMethod              : unsigned char {
  PARTICLESYSTEMLODMETHOD_Automatic,// 0
  PARTICLESYSTEMLODMETHOD_DirectSet,// 1
  PARTICLESYSTEMLODMETHOD_ActivateAutomatic,// 2
  PARTICLESYSTEMLODMETHOD_MAX     // 3
} ParticleSystemLODMethod;
typedef enum EParticleSystemOcclusionBoundsMethod : unsigned char {
  EPSOBM_None,                    // 0
  EPSOBM_ParticleBounds,          // 1
  EPSOBM_CustomBounds,            // 2
  EPSOBM_MAX                      // 3
} EParticleSystemOcclusionBoundsMethod;
#define EParticleSystemUpdateMode             EParticleSystemUpdateMode
#define ParticleSystemLODMethod               ParticleSystemLODMethod
#define EParticleSystemOcclusionBoundsMethod  EParticleSystemOcclusionBoundsMethod

/* ---------------------------------------------------------- UShieldDefinition ---------------------------------------------------------- */

typedef enum EShieldType           : unsigned char {
  SHT_Absorption,                 // 0
  SHT_Booster,                    // 1
  SHT_Chimera,                    // 2
  SHT_Impact,                     // 3
  SHT_Juggernaut,                 // 4
  SHT_Nova,                       // 5
  SHT_Roid,                       // 6
  SHT_Spike,                      // 7
  SHT_Standard,                   // 8
  SHT_Custom1,                    // 9
  SHT_Custom2,                    // 10
  SHT_Custom3,                    // 11
  SHT_Custom4,                    // 12
  SHT_Custom5,                    // 13
  SHT_MAX                         // 14
} EShieldType;
typedef enum EShieldPrimeMechanism : unsigned char {
  SPM_NoPrime,                    // 0
  SPM_PrimeOnFull,                // 1
  SPM_PrimeOnEmptyAfterFullRecharge,// 2
  SPM_PrimeOnEmpty,               // 3
  SPM_AlwaysPrimed,               // 4
  SPM_PrimedWhenNotEmpty,         // 5
  SPM_PrimedWhenNotEmptyAfterFullRecharge,// 6
  SPM_MAX                         // 7
} EShieldPrimeMechanism;
#define EShieldType            EShieldType
#define EShieldPrimeMechanism  EShieldPrimeMechanism

/* ---------------------------------------------------------- UAIDefinition ---------------------------------------------------------- */

typedef enum ENPCOnUsedOutputs : unsigned char {
  USEDNPC_HasMissions,            // 0
  USEDNPC_NoMissions,             // 1
  USEDNPC_Generic,                // 2
  USEDNPC_MAX                     // 3
} ENPCOnUsedOutputs;
#define ENPCOnUsedOutputs  ENPCOnUsedOutputs

/* ---------------------------------------------------------- AWillowGameInfo ---------------------------------------------------------- */

typedef enum EStartGameState : unsigned char {
  SGS_None,                       // 0
  SGS_IntroMovie,                 // 1
  SGS_CharacterSelect,            // 2
  SGS_WaitingForPlayerPawns,      // 3
  SGS_Started,                    // 4
  SGS_MAX                         // 5
} EStartGameState;
#define EStartGameState  EStartGameState

/* ---------------------------------------------------------- USettings ---------------------------------------------------------- */

typedef enum EOnlineDataAdvertisementType : unsigned char {
  ODAT_DontAdvertise,             // 0
  ODAT_OnlineService,             // 1
  ODAT_QoS,                       // 2
  ODAT_OnlineServiceAndQoS,       // 3
  ODAT_MAX                        // 4
} EOnlineDataAdvertisementType;
typedef enum ESettingsDataType            : unsigned char {
  SDT_Empty,                      // 0
  SDT_Int32,                      // 1
  SDT_Int64,                      // 2
  SDT_Double,                     // 3
  SDT_String,                     // 4
  SDT_Float,                      // 5
  SDT_Blob,                       // 6
  SDT_DateTime,                   // 7
  SDT_Byte,                       // 8
  SDT_MAX                         // 9
} ESettingsDataType;
typedef enum EPropertyValueMappingType    : unsigned char {
  PVMT_RawValue,                  // 0
  PVMT_PredefinedValues,          // 1
  PVMT_Ranged,                    // 2
  PVMT_IdMapped,                  // 3
  PVMT_MAX                        // 4
} EPropertyValueMappingType;
#define EOnlineDataAdvertisementType  EOnlineDataAdvertisementType
#define ESettingsDataType             ESettingsDataType
#define EPropertyValueMappingType     EPropertyValueMappingType

/* ---------------------------------------------------------- AWillowPlayerStats ---------------------------------------------------------- */

typedef enum EDamageCauserType : unsigned char {
  DAMAGE_CAUSER_TYPE_Unknown,     // 0
  DAMAGE_CAUSER_TYPE_Pistol,      // 1
  DAMAGE_CAUSER_TYPE_Shotgun,     // 2
  DAMAGE_CAUSER_TYPE_AssaultRifle,// 3
  DAMAGE_CAUSER_TYPE_SniperRifle, // 4
  DAMAGE_CAUSER_TYPE_SMG,         // 5
  DAMAGE_CAUSER_TYPE_Frag_Grenade,// 6
  DAMAGE_CAUSER_TYPE_Protean_Grenade,// 7
  DAMAGE_CAUSER_TYPE_Vehicle,     // 8
  DAMAGE_CAUSER_TYPE_VehicleWeapon,// 9
  DAMAGE_CAUSER_TYPE_Melee,       // 10
  DAMAGE_CAUSER_TYPE_Turret,      // 11
  DAMAGE_CAUSER_TYPE_Launcher,    // 12
  DAMAGE_CAUSER_TYPE_ExtraWeapon1,// 13
  DAMAGE_CAUSER_TYPE_ExtraWeapon2,// 14
  DAMAGE_CAUSER_TYPE_ExtraWeapon3,// 15
  DAMAGE_CAUSER_TYPE_ExtraWeapon4,// 16
  DAMAGE_CAUSER_TYPE_MAX          // 17
} EDamageCauserType;
#define EDamageCauserType  EDamageCauserType

/* ---------------------------------------------------------- UOnlinePlayerStorage ---------------------------------------------------------- */

typedef enum EOnlineProfilePropertyOwner    : unsigned char {
  OPPO_None,                      // 0
  OPPO_OnlineService,             // 1
  OPPO_Game,                      // 2
  OPPO_MAX                        // 3
} EOnlineProfilePropertyOwner;
typedef enum EOnlinePlayerStorageAsyncState : unsigned char {
  OPAS_NotStarted,                // 0
  OPAS_Read,                      // 1
  OPAS_Write,                     // 2
  OPAS_Finished,                  // 3
  OPAS_MAX                        // 4
} EOnlinePlayerStorageAsyncState;
#define EOnlineProfilePropertyOwner     EOnlineProfilePropertyOwner
#define EOnlinePlayerStorageAsyncState  EOnlinePlayerStorageAsyncState

/* ---------------------------------------------------------- UOnlineProfileSettings ---------------------------------------------------------- */

typedef enum EProfileSettingID                        : unsigned char {
  PSI_Unknown,                    // 0
  PSI_ControllerVibration,        // 1
  PSI_YInversion,                 // 2
  PSI_GamerCred,                  // 3
  PSI_GamerRep,                   // 4
  PSI_VoiceMuted,                 // 5
  PSI_VoiceThruSpeakers,          // 6
  PSI_VoiceVolume,                // 7
  PSI_GamerPictureKey,            // 8
  PSI_GamerMotto,                 // 9
  PSI_GamerTitlesPlayed,          // 10
  PSI_GamerAchievementsEarned,    // 11
  PSI_GameDifficulty,             // 12
  PSI_ControllerSensitivity,      // 13
  PSI_PreferredColor1,            // 14
  PSI_PreferredColor2,            // 15
  PSI_AutoAim,                    // 16
  PSI_AutoCenter,                 // 17
  PSI_MovementControl,            // 18
  PSI_RaceTransmission,           // 19
  PSI_RaceCameraLocation,         // 20
  PSI_RaceBrakeControl,           // 21
  PSI_RaceAcceleratorControl,     // 22
  PSI_GameCredEarned,             // 23
  PSI_GameAchievementsEarned,     // 24
  PSI_EndLiveIds,                 // 25
  PSI_ProfileVersionNum,          // 26
  PSI_ProfileSaveCount,           // 27
  PSI_MAX                         // 28
} EProfileSettingID;
typedef enum EProfileDifficultyOptions                : unsigned char {
  PDO_Normal,                     // 0
  PDO_Easy,                       // 1
  PDO_Hard,                       // 2
  PDO_MAX                         // 3
} EProfileDifficultyOptions;
typedef enum EProfileControllerSensitivityOptions     : unsigned char {
  PCSO_Medium,                    // 0
  PCSO_Low,                       // 1
  PCSO_High,                      // 2
  PCSO_MAX                        // 3
} EProfileControllerSensitivityOptions;
typedef enum EProfilePreferredColorOptions            : unsigned char {
  PPCO_None,                      // 0
  PPCO_Black,                     // 1
  PPCO_White,                     // 2
  PPCO_Yellow,                    // 3
  PPCO_Orange,                    // 4
  PPCO_Pink,                      // 5
  PPCO_Red,                       // 6
  PPCO_Purple,                    // 7
  PPCO_Blue,                      // 8
  PPCO_Green,                     // 9
  PPCO_Brown,                     // 10
  PPCO_Silver,                    // 11
  PPCO_MAX                        // 12
} EProfilePreferredColorOptions;
typedef enum EProfileAutoAimOptions                   : unsigned char {
  PAAO_Off,                       // 0
  PAAO_On,                        // 1
  PAAO_MAX                        // 2
} EProfileAutoAimOptions;
typedef enum EProfileAutoCenterOptions                : unsigned char {
  PACO_Off,                       // 0
  PACO_On,                        // 1
  PACO_MAX                        // 2
} EProfileAutoCenterOptions;
typedef enum EProfileMovementControlOptions           : unsigned char {
  PMCO_L_Thumbstick,              // 0
  PMCO_R_Thumbstick,              // 1
  PMCO_MAX                        // 2
} EProfileMovementControlOptions;
typedef enum EProfileRaceTransmissionOptions          : unsigned char {
  PRTO_Auto,                      // 0
  PRTO_Manual,                    // 1
  PRTO_MAX                        // 2
} EProfileRaceTransmissionOptions;
typedef enum EProfileRaceCameraLocationOptions        : unsigned char {
  PRCLO_Behind,                   // 0
  PRCLO_Front,                    // 1
  PRCLO_Inside,                   // 2
  PRCLO_MAX                       // 3
} EProfileRaceCameraLocationOptions;
typedef enum EProfileRaceBrakeControlOptions          : unsigned char {
  PRBCO_Trigger,                  // 0
  PRBCO_Button,                   // 1
  PRBCO_MAX                       // 2
} EProfileRaceBrakeControlOptions;
typedef enum EProfileRaceAcceleratorControlOptions    : unsigned char {
  PRACO_Trigger,                  // 0
  PRACO_Button,                   // 1
  PRACO_MAX                       // 2
} EProfileRaceAcceleratorControlOptions;
typedef enum EProfileYInversionOptions                : unsigned char {
  PYIO_Off,                       // 0
  PYIO_On,                        // 1
  PYIO_MAX                        // 2
} EProfileYInversionOptions;
typedef enum EProfileXInversionOptions                : unsigned char {
  PXIO_Off,                       // 0
  PXIO_On,                        // 1
  PXIO_MAX                        // 2
} EProfileXInversionOptions;
typedef enum EProfileOmniDirEvadeOptions              : unsigned char {
  PODI_Off,                       // 0
  PODI_On,                        // 1
  PODI_MAX                        // 2
} EProfileOmniDirEvadeOptions;
typedef enum EProfileControllerVibrationToggleOptions : unsigned char {
  PCVTO_Off,                      // 0
  PCVTO_IgnoreThis,               // 1
  PCVTO_IgnoreThis2,              // 2
  PCVTO_On,                       // 3
  PCVTO_MAX                       // 4
} EProfileControllerVibrationToggleOptions;
typedef enum EProfileVoiceThruSpeakersOptions         : unsigned char {
  PVTSO_Off,                      // 0
  PVTSO_On,                       // 1
  PVTSO_Both,                     // 2
  PVTSO_MAX                       // 3
} EProfileVoiceThruSpeakersOptions;
#define EProfileSettingID                         EProfileSettingID
#define EProfileDifficultyOptions                 EProfileDifficultyOptions
#define EProfileControllerSensitivityOptions      EProfileControllerSensitivityOptions
#define EProfilePreferredColorOptions             EProfilePreferredColorOptions
#define EProfileAutoAimOptions                    EProfileAutoAimOptions
#define EProfileAutoCenterOptions                 EProfileAutoCenterOptions
#define EProfileMovementControlOptions            EProfileMovementControlOptions
#define EProfileRaceTransmissionOptions           EProfileRaceTransmissionOptions
#define EProfileRaceCameraLocationOptions         EProfileRaceCameraLocationOptions
#define EProfileRaceBrakeControlOptions           EProfileRaceBrakeControlOptions
#define EProfileRaceAcceleratorControlOptions     EProfileRaceAcceleratorControlOptions
#define EProfileYInversionOptions                 EProfileYInversionOptions
#define EProfileXInversionOptions                 EProfileXInversionOptions
#define EProfileOmniDirEvadeOptions               EProfileOmniDirEvadeOptions
#define EProfileControllerVibrationToggleOptions  EProfileControllerVibrationToggleOptions
#define EProfileVoiceThruSpeakersOptions          EProfileVoiceThruSpeakersOptions

/* ---------------------------------------------------------- UGearboxProfileSettings ---------------------------------------------------------- */

typedef enum EGenericYesOrNo : unsigned char {
  GPID_VALUE_NO,                  // 0
  GPID_VALUE_YES,                 // 1
  GPID_VALUE_MAX                  // 2
} EGenericYesOrNo;
#define EGenericYesOrNo  EGenericYesOrNo

/* ---------------------------------------------------------- UOnlineSubsystem ---------------------------------------------------------- */

typedef enum ELoginStatus                  : unsigned char {
  LS_NotLoggedIn,                 // 0
  LS_UsingLocalProfile,           // 1
  LS_LoggedIn,                    // 2
  LS_MAX                          // 3
} ELoginStatus;
typedef enum EUserAgeGroup                 : unsigned char {
  UAG_Unknown,                    // 0
  UAG_Child,                      // 1
  UAG_Teen,                       // 2
  UAG_Adult,                      // 3
  UAG_MAX                         // 4
} EUserAgeGroup;
typedef enum EFeaturePrivilegeLevel        : unsigned char {
  FPL_Disabled,                   // 0
  FPL_EnabledFriendsOnly,         // 1
  FPL_Enabled,                    // 2
  FPL_MAX                         // 3
} EFeaturePrivilegeLevel;
typedef enum ENetworkNotificationPosition  : unsigned char {
  NNP_TopLeft,                    // 0
  NNP_TopCenter,                  // 1
  NNP_TopRight,                   // 2
  NNP_CenterLeft,                 // 3
  NNP_Center,                     // 4
  NNP_CenterRight,                // 5
  NNP_BottomLeft,                 // 6
  NNP_BottomCenter,               // 7
  NNP_BottomRight,                // 8
  NNP_MAX                         // 9
} ENetworkNotificationPosition;
typedef enum EOnlineGameState              : unsigned char {
  OGS_NoSession,                  // 0
  OGS_Pending,                    // 1
  OGS_Starting,                   // 2
  OGS_InProgress,                 // 3
  OGS_Ending,                     // 4
  OGS_Ended,                      // 5
  OGS_MAX                         // 6
} EOnlineGameState;
typedef enum EOnlineEnumerationReadState   : unsigned char {
  OERS_NotStarted,                // 0
  OERS_InProgress,                // 1
  OERS_Done,                      // 2
  OERS_Failed,                    // 3
  OERS_MAX                        // 4
} EOnlineEnumerationReadState;
typedef enum EOnlineFriendState            : unsigned char {
  OFS_Offline,                    // 0
  OFS_Online,                     // 1
  OFS_Away,                       // 2
  OFS_Busy,                       // 3
  OFS_MAX                         // 4
} EOnlineFriendState;
typedef enum EVoiceVolumeType              : unsigned char {
  VVT_Capture,                    // 0
  VVT_Playback,                   // 1
  VVT_CaptureAndPlayback,         // 2
  VVT_MAX                         // 3
} EVoiceVolumeType;
typedef enum EOakStoreStatus               : unsigned char {
  OSS_Preorder,                   // 0
  OSS_Released,                   // 1
  OSS_Unavailable,                // 2
  OSS_MAX                         // 3
} EOakStoreStatus;
typedef enum EOakProduct                   : unsigned char {
  OP_Standard,                    // 0
  OP_Deluxe,                      // 1
  OP_SuperDeluxe,                 // 2
  OP_MAX                          // 3
} EOakProduct;
typedef enum EFriendPlatform               : unsigned char {
  FP_Bifrost,                     // 0
  FP_Epic,                        // 1
  FP_Steam,                       // 2
  FP_MAX                          // 3
} EFriendPlatform;
typedef enum EOnlineContentType            : unsigned char {
  OCT_Downloaded,                 // 0
  OCT_SaveGame,                   // 1
  OCT_MAX                         // 2
} EOnlineContentType;
typedef enum ENamedOnlineContentType       : unsigned char {
  NOCT_Content,                   // 0
  NOCT_SeasonPass,                // 1
  NOCT_PreorderBonus,             // 2
  NOCT_CompatibilityPack,         // 3
  NOCT_MAX                        // 4
} ENamedOnlineContentType;
typedef enum EOnlineServerConnectionStatus : unsigned char {
  OSCS_NotConnected,              // 0
  OSCS_Connected,                 // 1
  OSCS_ConnectionDropped,         // 2
  OSCS_NoNetworkConnection,       // 3
  OSCS_ServiceUnavailable,        // 4
  OSCS_UpdateRequired,            // 5
  OSCS_ServersTooBusy,            // 6
  OSCS_DuplicateLoginDetected,    // 7
  OSCS_InvalidUser,               // 8
  OSCS_MAX                        // 9
} EOnlineServerConnectionStatus;
typedef enum ENATType                      : unsigned char {
  NAT_Unknown,                    // 0
  NAT_Open,                       // 1
  NAT_Moderate,                   // 2
  NAT_Strict,                     // 3
  NAT_MAX                         // 4
} ENATType;
typedef enum ELanBeaconState               : unsigned char {
  LANB_NotUsingLanBeacon,         // 0
  LANB_Hosting,                   // 1
  LANB_Searching,                 // 2
  LANB_MAX                        // 3
} ELanBeaconState;
typedef enum EOnlineAccountCreateStatus    : unsigned char {
  OACS_CreateSuccessful,          // 0
  OACS_UnknownError,              // 1
  OACS_InvalidUserName,           // 2
  OACS_InvalidPassword,           // 3
  OACS_InvalidUniqueUserName,     // 4
  OACS_UniqueUserNameInUse,       // 5
  OACS_ServiceUnavailable,        // 6
  OACS_MAX                        // 7
} EOnlineAccountCreateStatus;
typedef enum EOnlineNewsType               : unsigned char {
  ONT_Unknown,                    // 0
  ONT_GameNews,                   // 1
  ONT_ContentAnnouncements,       // 2
  ONT_Misc,                       // 3
  ONT_MAX                         // 4
} EOnlineNewsType;
typedef enum EShowKeyboardType             : unsigned char {
  SKT_Standard,                   // 0
  SKT_Password,                   // 1
  SKT_Email,                      // 2
  SKT_MAX                         // 3
} EShowKeyboardType;
#define ELoginStatus                   ELoginStatus
#define EUserAgeGroup                  EUserAgeGroup
#define EFeaturePrivilegeLevel         EFeaturePrivilegeLevel
#define ENetworkNotificationPosition   ENetworkNotificationPosition
#define EOnlineGameState               EOnlineGameState
#define EOnlineEnumerationReadState    EOnlineEnumerationReadState
#define EOnlineFriendState             EOnlineFriendState
#define EVoiceVolumeType               EVoiceVolumeType
#define EOakStoreStatus                EOakStoreStatus
#define EOakProduct                    EOakProduct
#define EFriendPlatform                EFriendPlatform
#define EOnlineContentType             EOnlineContentType
#define ENamedOnlineContentType        ENamedOnlineContentType
#define EOnlineServerConnectionStatus  EOnlineServerConnectionStatus
#define ENATType                       ENATType
#define ELanBeaconState                ELanBeaconState
#define EOnlineAccountCreateStatus     EOnlineAccountCreateStatus
#define EOnlineNewsType                EOnlineNewsType
#define EShowKeyboardType              EShowKeyboardType

/* ---------------------------------------------------------- UWillowProfileSettings ---------------------------------------------------------- */

typedef enum EProfileViewDistanceOptions   : unsigned char {
  PVDO_Low,                       // 0
  PVDO_Medium,                    // 1
  PVDO_High,                      // 2
  PVDO_UltraHigh,                 // 3
  PVDO_MAX                        // 4
} EProfileViewDistanceOptions;
typedef enum EDecalSettingOptions          : unsigned char {
  DSO_Normal,                     // 0
  DSO_High,                       // 1
  DSO_MAX                         // 2
} EDecalSettingOptions;
typedef enum ESplitDirectionOptions        : unsigned char {
  SDO_Horizontal,                 // 0
  SDO_Vertical,                   // 1
  SDO_MAX                         // 2
} ESplitDirectionOptions;
typedef enum EProfileColorBlindModeOptions : unsigned char {
  PCBMO_Invalid,                  // 0
  PCBMO_Off,                      // 1
  PCBMO_Deuteranopia,             // 2
  PCBMO_Protanopia,               // 3
  PCBMO_Tritanopia,               // 4
  PCBMO_MAX                       // 5
} EProfileColorBlindModeOptions;
#define EProfileViewDistanceOptions    EProfileViewDistanceOptions
#define EDecalSettingOptions           EDecalSettingOptions
#define ESplitDirectionOptions         ESplitDirectionOptions
#define EProfileColorBlindModeOptions  EProfileColorBlindModeOptions

/* ---------------------------------------------------------- UHUDWidget_Crosshairs ---------------------------------------------------------- */

typedef enum ECrosshairColor : unsigned char {
  ECC_None,                       // 0
  ECC_White,                      // 1
  ECC_Red,                        // 2
  ECC_Green,                      // 3
  ECC_MAX                         // 4
} ECrosshairColor;
#define ECrosshairColor  ECrosshairColor

/* ---------------------------------------------------------- UUIRoot ---------------------------------------------------------- */

typedef enum EUIDataProviderFieldType : unsigned char {
  DATATYPE_Property,              // 0
  DATATYPE_Provider,              // 1
  DATATYPE_RangeProperty,         // 2
  DATATYPE_NetIdProperty,         // 3
  DATATYPE_Collection,            // 4
  DATATYPE_ProviderCollection,    // 5
  DATATYPE_MAX                    // 6
} EUIDataProviderFieldType;
typedef enum EInputPlatformType       : unsigned char {
  IPT_PC,                         // 0
  IPT_360,                        // 1
  IPT_PS3,                        // 2
  IPT_MAX                         // 3
} EInputPlatformType;
#define EUIDataProviderFieldType  EUIDataProviderFieldType
#define EInputPlatformType        EInputPlatformType

/* ---------------------------------------------------------- UGFxMovieState ---------------------------------------------------------- */

typedef enum EMovieStateMode : unsigned char {
  MOVIESTATE_Any,                 // 0
  MOVIESTATE_StateMachine,        // 1
  MOVIESTATE_Flags,               // 2
  MOVIESTATE_Custom,              // 3
  MOVIESTATE_MAX                  // 4
} EMovieStateMode;
typedef enum EStateApplyMode : unsigned char {
  SAM_None,                       // 0
  SAM_GotoAndStop,                // 1
  SAM_GotoAndPlay,                // 2
  SAM_ActionScript,               // 3
  SAM_MAX                         // 4
} EStateApplyMode;
#define EMovieStateMode  EMovieStateMode
#define EStateApplyMode  EStateApplyMode

/* ---------------------------------------------------------- UWillowGFxMovie ---------------------------------------------------------- */

typedef enum ERTTType : unsigned char {
  RTTT_Cell,                      // 0
  RTTT_HalfCell,                  // 1
  RTTT_Card,                      // 2
  RTTT_QuickSlot,                 // 3
  RTTT_MAX                        // 4
} ERTTType;
#define ERTTType  ERTTType

/* ---------------------------------------------------------- UWillowGFxMovie3D ---------------------------------------------------------- */

typedef enum MovieFittingStyle : unsigned char {
  MFS_FitWithoutCropping,         // 0
  MFS_FitWithCropping,            // 1
  MFS_FitHorizontal,              // 2
  MFS_FitVertical,                // 3
  MFS_MAX                         // 4
} MovieFittingStyle;
#define MovieFittingStyle  MovieFittingStyle

/* ---------------------------------------------------------- UWillowHUDGFxMovie ---------------------------------------------------------- */

typedef enum EAmmoBar : unsigned char {
  EAB_Default,                    // 0
  EAB_DualWieldLeft,              // 1
  EAB_DualWieldRight,             // 2
  EAB_MAX                         // 3
} EAmmoBar;
#define EAmmoBar  EAmmoBar

/* ---------------------------------------------------------- UFiringModeDefinition ---------------------------------------------------------- */

typedef enum EWillowWeaponFireType : unsigned char {
  EWWFT_Bullet,                   // 0
  EWWFT_Beam,                     // 1
  EWWFT_Rocket,                   // 2
  EWWFT_HitScan,                  // 3
  EWWFT_MAX                       // 4
} EWillowWeaponFireType;
typedef enum ELightBeamLock        : unsigned char {
  LBL_Never,                      // 0
  LBL_Always,                     // 1
  LBL_LockOn,                     // 2
  LBL_MAX                         // 3
} ELightBeamLock;
#define EWillowWeaponFireType  EWillowWeaponFireType
#define ELightBeamLock         ELightBeamLock

/* ---------------------------------------------------------- UITimerBehavior ---------------------------------------------------------- */

typedef enum EBehaviorTimerID    : unsigned char {
  BTIMER_1,                       // 0
  BTIMER_2,                       // 1
  BTIMER_3,                       // 2
  BTIMER_MAX                      // 3
#define EBehaviorTimerID__MAX  BTIMER_MAX
} EBehaviorTimerID;
typedef enum EBehaviorTimerEvent : unsigned char {
  TIMEREVENT_Timer1Elapsed,       // 0
  TIMEREVENT_Timer2Elapsed,       // 1
  TIMEREVENT_Timer3Elapsed,       // 2
  TIMEREVENT_MAX                  // 3
} EBehaviorTimerEvent;
#define EBehaviorTimerID     EBehaviorTimerID
#define EBehaviorTimerEvent  EBehaviorTimerEvent

/* ---------------------------------------------------------- UForceFeedbackWaveform ---------------------------------------------------------- */

typedef enum EWaveformFunction : unsigned char {
  WF_Constant,                    // 0
  WF_LinearIncreasing,            // 1
  WF_LinearDecreasing,            // 2
  WF_Sin0to90,                    // 3
  WF_Sin90to180,                  // 4
  WF_Sin0to180,                   // 5
  WF_Noise,                       // 6
  WF_MAX                          // 7
} EWaveformFunction;
#define EWaveformFunction  EWaveformFunction

/* ---------------------------------------------------------- UWillowGameViewportClient ---------------------------------------------------------- */

typedef enum EDeviceSelectionState : unsigned char {
  EDSS_None,                      // 0
  EDSS_Pending,                   // 1
  EDSS_Succeeded,                 // 2
  EDSS_Failed,                    // 3
  EDSS_MAX                        // 4
} EDeviceSelectionState;
#define EDeviceSelectionState  EDeviceSelectionState

/* ---------------------------------------------------------- UBehaviorProviderDefinition ---------------------------------------------------------- */

typedef enum EBehaviorVariableLinkType : unsigned char {
  BVARLINK_Unknown,               // 0
  BVARLINK_Context,               // 1
  BVARLINK_Input,                 // 2
  BVARLINK_Output,                // 3
  BVARLINK_MAX                    // 4
} EBehaviorVariableLinkType;
typedef enum EBehaviorVariableType     : unsigned char {
  BVAR_None,                      // 0
  BVAR_Bool,                      // 1
  BVAR_Int,                       // 2
  BVAR_Float,                     // 3
  BVAR_Vector,                    // 4
  BVAR_Object,                    // 5
  BVAR_AllPlayers,                // 6
  BVAR_Attribute,                 // 7
  BVAR_InstanceData,              // 8
  BVAR_NamedVariable,             // 9
  BVAR_NamedKismetVariable,       // 10
  BVAR_DirectionVector,           // 11
  BVAR_AttachmentLocation,        // 12
  BVAR_UnaryMath,                 // 13
  BVAR_BinaryMath,                // 14
  BVAR_Flag,                      // 15
  BVAR_MAX                        // 16
} EBehaviorVariableType;
#define EBehaviorVariableLinkType  EBehaviorVariableLinkType
#define EBehaviorVariableType      EBehaviorVariableType

/* ---------------------------------------------------------- UAttributePresentationDefinition ---------------------------------------------------------- */

typedef enum EAttributeValueSignStyle : unsigned char {
  SIGNSTYLE_AsIs,                 // 0
  SIGNSTYLE_Positive,             // 1
  SIGNSTYLE_Negative,             // 2
  SIGNSTYLE_AsIsAnyStyle,         // 3
  SIGNSTYLE_OppositeSign,         // 4
  SIGNSTYLE_MAX                   // 5
} EAttributeValueSignStyle;
#define EAttributeValueSignStyle  EAttributeValueSignStyle

/* ---------------------------------------------------------- UWillowItemTypes ---------------------------------------------------------- */

typedef enum EItemPartType   : unsigned char {
  IP_Alpha,                       // 0
  IP_Beta,                        // 1
  IP_Gamma,                       // 2
  IP_Delta,                       // 3
  IP_Epsilon,                     // 4
  IP_Zeta,                        // 5
  IP_Eta,                         // 6
  IP_Theta,                       // 7
  IP_Material,                    // 8
  IP_Prefix,                      // 9
  IP_Title,                       // 10
  IP_MAX                          // 11
} EItemPartType;
typedef enum EFlashCardIndex : unsigned char {
  FCI_None,                       // 0
  FCI_Weapon,                     // 1
  FCI_Shield,                     // 2
  FCI_GrenadeMod,                 // 3
  FCI_ClassMod,                   // 4
  FCI_Item,                       // 5
  FCI_Blank,                      // 6
  FCI_Artifact,                   // 7
  FCI_MissionItem,                // 8
  FCI_MAX                         // 9
} EFlashCardIndex;
#define EItemPartType    EItemPartType
#define EFlashCardIndex  EFlashCardIndex

/* ---------------------------------------------------------- UStatusMenuExGFxMovie ---------------------------------------------------------- */

typedef enum ECellState : unsigned char {
  CELL_Selected,                  // 0
  CELL_Both,                      // 1
  CELL_Normal,                    // 2
  CELL_Highlight,                 // 3
  CELL_Locked,                    // 4
  CELL_MAX                        // 5
} ECellState;
#define ECellState  ECellState

/* ---------------------------------------------------------- UWillowDeclarations ---------------------------------------------------------- */

typedef enum EQuickWeaponSlot        : unsigned char {
  QuickSelectNone,                // 0
  QuickSelectUp,                  // 1
  QuickSelectDown,                // 2
  QuickSelectLeft,                // 3
  QuickSelectRight,               // 4
  EQuickWeaponSlot_MAX            // 5
} EQuickWeaponSlot;
typedef enum EStoragePanelBackground : unsigned char {
  ESPB_Inventory,                 // 0
  ESPB_Health,                    // 1
  ESPB_Weapons,                   // 2
  ESPB_Ammo,                      // 3
  ESPB_Bank,                      // 4
  ESPB_Stash,                     // 5
  EPSB_Blackmarket,               // 6
  EPSB_Custom,                    // 7
  EStoragePanelBackground_MAX     // 8
} EStoragePanelBackground;
typedef enum EEquipmentLoc           : unsigned char {
  EQUIPLOC_Shield,                // 0
  EQUIPLOC_GrenadeMod,            // 1
  EQUIPLOC_ClassMod,              // 2
  EQUIPLOC_Artifact,              // 3
  EQUIPLOC_None,                  // 4
  EQUIPLOC_MAX                    // 5
} EEquipmentLoc;
typedef enum ERewardPopup            : unsigned char {
  ERP_BadassToken,                // 0
  ERP_CharacterHead,              // 1
  ERP_CharacterSkin,              // 2
  ERP_VehicleSkin,                // 3
  ERP_MAX                         // 4
} ERewardPopup;
#define EQuickWeaponSlot         EQuickWeaponSlot
#define EStoragePanelBackground  EStoragePanelBackground
#define EEquipmentLoc            EEquipmentLoc
#define ERewardPopup             ERewardPopup

/* ---------------------------------------------------------- UBaseTopLevelPanelGFxObject ---------------------------------------------------------- */

typedef enum PanelPosition : unsigned char {
  PP_Focused,                     // 0
  PP_Unfocused,                   // 1
  PP_Compare,                     // 2
  PP_MAX                          // 3
} PanelPosition;
#define PanelPosition  PanelPosition

/* ---------------------------------------------------------- UStatusMenuInventoryPanelGFxObject ---------------------------------------------------------- */

typedef enum EInventoryPanel : unsigned char {
  EIP_Backpack,                   // 0
  EIP_Equipped,                   // 1
  EIP_MAX                         // 2
} EInventoryPanel;
#define EInventoryPanel  EInventoryPanel

/* ---------------------------------------------------------- UGearboxGlobals ---------------------------------------------------------- */

typedef enum EMovementFinishedCause     : unsigned char {
  MOVEFINISHED_None,              // 0
  MOVEFINISHED_FailedToFindCover, // 1
  MOVEFINISHED_FailedFindSearchOrigin,// 2
  MOVEFINISHED_FailedFindSearchDirection,// 3
  MOVEFINISHED_FailedFindNavMeshSpot,// 4
  MOVEFINISHED_FailedToGeneratePath,// 5
  MOVEFINISHED_FailedToCompleteNavigation,// 6
  MOVEFINISHED_Repath,            // 7
  MOVEFINISHED_MovementInterrupted,// 8
  MOVEFINISHED_MoveSuccessfullyEnded,// 9
  MOVEFINISHED_MAX                // 10
} EMovementFinishedCause;
typedef enum EMovementSpeed             : unsigned char {
  MOVESPEED_Stationary,           // 0
  MOVESPEED_Walking,              // 1
  MOVESPEED_Running,              // 2
  MOVESPEED_Sprinting,            // 3
  MOVESPEED_FastSprinting,        // 4
  MOVESPEED_MAX                   // 5
} EMovementSpeed;
typedef enum EFacingPolicy              : unsigned char {
  FACE_Unknown,                   // 0
  FACE_NoChange,                  // 1
  FACE_Actor,                     // 2
  FACE_Vector,                    // 3
  FACE_Destination,               // 4
  FACE_CoverRegionIdle,           // 5
  FACE_MAX                        // 6
} EFacingPolicy;
typedef enum ECameraInterpolationMode   : unsigned char {
  IM_Logarithmic,                 // 0
  IM_Linear,                      // 1
  IM_SineCurve,                   // 2
  IM_MAX                          // 3
} ECameraInterpolationMode;
typedef enum ECameraZoomScale           : unsigned char {
  EZOOM_NoChange,                 // 0
  EZOOM_UltraClose,               // 1
  EZOOM_Close,                    // 2
  EZOOM_MidRange,                 // 3
  EZOOM_Wide,                     // 4
  EZOOM_MAX                       // 5
} ECameraZoomScale;
typedef enum EMaterialParamType         : unsigned char {
  MatParmType_None,               // 0
  MatParmType_Color,              // 1
  MatParmType_Font,               // 2
  MatParmType_Scalar,             // 3
  MatParmType_Texture,            // 4
  MatParmType_Vector,             // 5
  MatParmType_MAX                 // 6
} EMaterialParamType;
typedef enum EDifficultyLevel           : unsigned char {
  DL_Casual,                      // 0
  DL_Normal,                      // 1
  DL_Hardcore,                    // 2
  DL_Insane,                      // 3
  DL_MAX                          // 4
} EDifficultyLevel;
typedef enum EGBXPlatform               : unsigned char {
  GBXPlatform_PC,                 // 0
  GBXPlatform_360,                // 1
  GBXPlatform_PS3,                // 2
  GBXPlatform_MAX                 // 3
} EGBXPlatform;
typedef enum EVantageType               : unsigned char {
  VTYPE_Normal,                   // 0
  VTYPE_StandingUp,               // 1
  VTYPE_OverWall,                 // 2
  VTYPE_AroundCorner,             // 3
  VTYPE_MAX                       // 4
} EVantageType;
typedef enum AwarenessReason            : unsigned char {
  AWAREREASON_SawEnemy,           // 0
  AWAREREASON_HeardEnemy,         // 1
  AWAREREASON_HeardWeaponNoise,   // 2
  AWAREREASON_NotifiedByFireTeam, // 3
  AWAREREASON_NotifiedByPlayer,   // 4
  AWAREREASON_SuppressOrderGiven, // 5
  AWAREREASON_AttackedByEnemy,    // 6
  AWAREREASON_BulletImpactOrWhiz, // 7
  AWAREREASON_GrenadeFromEnemy,   // 8
  AWAREREASON_LevelDesignForceSee,// 9
  AWAREREASON_FriendlyKilled,     // 10
  AWAREREASON_MAX                 // 11
} AwarenessReason;
typedef enum EGearboxCoverState         : unsigned char {
  GBXCOVERSTATE_Uncovered,        // 0
  GBXCOVERSTATE_Covered,          // 1
  GBXCOVERSTATE_PoppedUp,         // 2
  GBXCOVERSTATE_LeanedOut,        // 3
  GBXCOVERSTATE_Peeking,          // 4
  GBXCOVERSTATE_BlindFiring,      // 5
  GBXCOVERSTATE_Mantling,         // 6
  GBXCOVERSTATE_GameSpecific,     // 7
  GBXCOVERSTATE_Reserved1,        // 8
  GBXCOVERSTATE_Reserved2,        // 9
  GBXCOVERSTATE_Reserved3,        // 10
  GBXCOVERSTATE_Reserved4,        // 11
  GBXCOVERSTATE_Reserved5,        // 12
  GBXCOVERSTATE_Reserved6,        // 13
  GBXCOVERSTATE_Reserved7,        // 14
  GBXCOVERSTATE_Reserved8,        // 15
  GBXCOVERSTATE_Reserved9,        // 16
  GBXCOVERSTATE_MAX               // 17
} EGearboxCoverState;
typedef enum EGearboxCoverStateMetaData : unsigned char {
  GBXCOVERMETA_None,              // 0
  GBXCOVERMETA_Detach,            // 1
  GBXCOVERMETA_Left,              // 2
  GBXCOVERMETA_Right,             // 3
  GBXCOVERMETA_Interior,          // 4
  GBXCOVERMETA_Dismount_SurpriseLeft,// 5
  GBXCOVERMETA_Dismount_SurpriseRight,// 6
  GBXCOVERMETA_Dismount_SurpriseTowardCover,// 7
  GBXCOVERMETA_Dismount_SurpriseWith180Turn,// 8
  GBXCOVERMETA_Dismount_Wallhop,  // 9
  GBXCOVERMETA_Dismount_TowardCover,// 10
  GBXCOVERMETA_Dismount_With180Turn,// 11
  GBXCOVERMETA_GameSpecific,      // 12
  GBXCOVERMETA_Reserved1,         // 13
  GBXCOVERMETA_Reserved2,         // 14
  GBXCOVERMETA_Reserved3,         // 15
  GBXCOVERMETA_Reserved4,         // 16
  GBXCOVERMETA_Reserved5,         // 17
  GBXCOVERMETA_Reserved6,         // 18
  GBXCOVERMETA_Reserved7,         // 19
  GBXCOVERMETA_Reserved8,         // 20
  GBXCOVERMETA_Reserved9,         // 21
  GBXCOVERMETA_MAX                // 22
} EGearboxCoverStateMetaData;
typedef enum EGearboxCoverTransition    : unsigned char {
  GBXCOVERTRANS_None,             // 0
  GBXCOVERTRANS_Detach,           // 1
  GBXCOVERTRANS_PoppingUp,        // 2
  GBXCOVERTRANS_LeaningOut,       // 3
  GBXCOVERTRANS_PeekingUp,        // 4
  GBXCOVERTRANS_BlindFiringUp,    // 5
  GBXCOVERTRANS_ReturnToCover,    // 6
  GBXCOVERTRANS_Mounting,         // 7
  GBXCOVERTRANS_Dismounting,      // 8
  GBXCOVERTRANS_Mantling,         // 9
  GBXCOVERTRANS_ChangingDirection,// 10
  GBXCOVERTRANS_GameSpecific,     // 11
  GBXCOVERTRANS_Reserved1,        // 12
  GBXCOVERTRANS_Reserved2,        // 13
  GBXCOVERTRANS_Reserved3,        // 14
  GBXCOVERTRANS_Reserved4,        // 15
  GBXCOVERTRANS_Reserved5,        // 16
  GBXCOVERTRANS_Reserved6,        // 17
  GBXCOVERTRANS_Reserved7,        // 18
  GBXCOVERTRANS_Reserved8,        // 19
  GBXCOVERTRANS_Reserved9,        // 20
  GBXCOVERTRANS_MAX               // 21
} EGearboxCoverTransition;
typedef enum ELocationSearchRandomness  : unsigned char {
  ELOCRAND_PreferIdealDirection,  // 0
  ELOCRAND_PreferRandomLight,     // 1
  ELOCRAND_PreferRandomHeavy,     // 2
  ELOCRAND_MAX                    // 3
} ELocationSearchRandomness;
typedef enum ERepathBehavior            : unsigned char {
  REPATH_None,                    // 0
  REPATH_IfOriginMoves,           // 1
  REPATH_IfCoverBecomesInvalid,   // 2
  REPATH_MAX                      // 3
} ERepathBehavior;
typedef enum ECoverFailureBehavior      : unsigned char {
  COVERFAIL_TryToFindNonCoverSpot,// 0
  COVERFAIL_StopSearch,           // 1
  COVERFAIL_MAX                   // 2
} ECoverFailureBehavior;
typedef enum ECoverSearchFilter         : unsigned char {
  COVERSEARCH_Normal,             // 0
  COVERSEARCH_IgnoreCurrentCover, // 1
  COVERSEARCH_MAX                 // 2
} ECoverSearchFilter;
typedef enum EDestinationAdditionalTest : unsigned char {
  DESTTEST_None,                  // 0
  DESTTEST_HasLOSToTarget,        // 1
  DESTTEST_BlockedLOSToTarget,    // 2
  DESTTEST_MAX                    // 3
} EDestinationAdditionalTest;
#define EMovementFinishedCause      EMovementFinishedCause
#define EMovementSpeed              EMovementSpeed
#define EFacingPolicy               EFacingPolicy
#define ECameraInterpolationMode    ECameraInterpolationMode
#define ECameraZoomScale            ECameraZoomScale
#define EMaterialParamType          EMaterialParamType
#define EDifficultyLevel            EDifficultyLevel
#define EGBXPlatform                EGBXPlatform
#define EVantageType                EVantageType
#define AwarenessReason             AwarenessReason
#define EGearboxCoverState          EGearboxCoverState
#define EGearboxCoverStateMetaData  EGearboxCoverStateMetaData
#define EGearboxCoverTransition     EGearboxCoverTransition
#define ELocationSearchRandomness   ELocationSearchRandomness
#define ERepathBehavior             ERepathBehavior
#define ECoverFailureBehavior       ECoverFailureBehavior
#define ECoverSearchFilter          ECoverSearchFilter
#define EDestinationAdditionalTest  EDestinationAdditionalTest

/* ---------------------------------------------------------- AWillowPawn ---------------------------------------------------------- */

typedef enum EResurrectReason    : unsigned char {
  ERR_Unknown,                    // 0
  ERR_IDied,                      // 1
  ERR_OtherDied,                  // 2
  ERR_FellOutOfWorld,             // 3
  ERR_LDRes,                      // 4
  ERR_Gibbed,                     // 5
  ERR_OutsideWorldBounds,         // 6
  ERR_LevelTravel,                // 7
  ERR_MAX                         // 8
} EResurrectReason;
typedef enum ESecondWindReason   : unsigned char {
  ESECONDWIND_None,               // 0
  ESECONDWIND_KilledEnemy,        // 1
  ESECONDWIND_LeveledUp,          // 2
  ESECONDWIND_PartnerRevived,     // 3
  ESECONDWIND_Skill_Res,          // 4
  ESECONDWIND_AutoRevive,         // 5
  ESECONDWIND_UNUSED_6,           // 6
  ESECONDWIND_UNUSED_7,           // 7
  ESECONDWIND_UNUSED_8,           // 8
  ESECONDWIND_UNUSED_9,           // 9
  ESECONDWIND_UNUSED_10,          // 10
  ESECONDWIND_ReasonExtension_1,  // 11
  ESECONDWIND_ReasonExtension_2,  // 12
  ESECONDWIND_ReasonExtension_3,  // 13
  ESECONDWIND_ReasonExtension_4,  // 14
  ESECONDWIND_ReasonExtension_5,  // 15
  ESECONDWIND_MAX                 // 16
} ESecondWindReason;
typedef enum EHolsteredGearState : unsigned char {
  HGS_None,                       // 0
  HGS_PendingFadeIn,              // 1
  HGS_FadingIn,                   // 2
  HGS_FadingOut,                  // 3
  HGS_MAX                         // 4
} EHolsteredGearState;
typedef enum EInjuredStage       : unsigned char {
  INJURED_Not,                    // 0
  INJURED_Injured,                // 1
  INJURED_Targeted,               // 2
  INJURED_MostlyDead,             // 3
  INJURED_MAX                     // 4
} EInjuredStage;
typedef enum EInjuredDeadState   : unsigned char {
  INJUREDDEAD_None,               // 0
  INJUREDDEAD_Start,              // 1
  INJUREDDEAD_StartCausePlayerDeath,// 2
  INJUREDDEAD_StartKillVolume,    // 3
  INJUREDDEAD_InitRagdoll,        // 4
  INJUREDDEAD_MAX                 // 5
} EInjuredDeadState;
typedef enum EInterpMode         : unsigned char {
  EIM_None,                       // 0
  EIM_Linear,                     // 1
  EIM_NonLinear,                  // 2
  EIM_MAX                         // 3
} EInterpMode;
#define EResurrectReason     EResurrectReason
#define ESecondWindReason    ESecondWindReason
#define EHolsteredGearState  EHolsteredGearState
#define EInjuredStage        EInjuredStage
#define EInjuredDeadState    EInjuredDeadState
#define EInterpMode          EInterpMode

/* ---------------------------------------------------------- UINounAttributeProvider ---------------------------------------------------------- */

typedef enum ENounReplicationStrategy : unsigned char {
  NOUNREP_NoReplication,          // 0
  NOUNREP_RepToOwnerOnly,         // 1
  NOUNREP_RepToEveryone,          // 2
  NOUNREP_MAX                     // 3
} ENounReplicationStrategy;
#define ENounReplicationStrategy  ENounReplicationStrategy

/* ---------------------------------------------------------- USkeletalMeshComponent ---------------------------------------------------------- */

typedef enum EMaxDistanceScaleMode   : unsigned char {
  MDSM_Multiply,                  // 0
  MDSM_Substract,                 // 1
  MDSM_MAX                        // 2
} EMaxDistanceScaleMode;
typedef enum EInstanceWeightUsage    : unsigned char {
  IWU_PartialSwap,                // 0
  IWU_FullSwap,                   // 1
  IWU_MAX                         // 2
} EInstanceWeightUsage;
typedef enum ERootMotionMode         : unsigned char {
  RMM_Translate,                  // 0
  RMM_Velocity,                   // 1
  RMM_Ignore,                     // 2
  RMM_Accel,                      // 3
  RMM_Relative,                   // 4
  RMM_TranslateWithGravity,       // 5
  RMM_MAX                         // 6
} ERootMotionMode;
typedef enum ERootMotionRotationMode : unsigned char {
  RMRM_Ignore,                    // 0
  RMRM_RotateActor,               // 1
  RMRM_MAX                        // 2
} ERootMotionRotationMode;
typedef enum EAnimRotationOnly       : unsigned char {
  EARO_AnimSet,                   // 0
  EARO_ForceEnabled,              // 1
  EARO_ForceDisabled,             // 2
  EARO_MAX                        // 3
} EAnimRotationOnly;
typedef enum EFaceFXBlendMode        : unsigned char {
  FXBM_Overwrite,                 // 0
  FXBM_Additive,                  // 1
  FXBM_MAX                        // 2
} EFaceFXBlendMode;
typedef enum EFaceFXRegOp            : unsigned char {
  FXRO_Add,                       // 0
  FXRO_Multiply,                  // 1
  FXRO_Replace,                   // 2
  FXRO_MAX                        // 3
} EFaceFXRegOp;
typedef enum EBoneVisibilityStatus   : unsigned char {
  BVS_HiddenByParent,             // 0
  BVS_Visible,                    // 1
  BVS_ExplicitlyHidden,           // 2
  BVS_MAX                         // 3
} EBoneVisibilityStatus;
typedef enum EPhysBodyOp             : unsigned char {
  PBO_None,                       // 0
  PBO_Term,                       // 1
  PBO_Disable,                    // 2
  PBO_MAX                         // 3
} EPhysBodyOp;
#define EMaxDistanceScaleMode    EMaxDistanceScaleMode
#define EInstanceWeightUsage     EInstanceWeightUsage
#define ERootMotionMode          ERootMotionMode
#define ERootMotionRotationMode  ERootMotionRotationMode
#define EAnimRotationOnly        EAnimRotationOnly
#define EFaceFXBlendMode         EFaceFXBlendMode
#define EFaceFXRegOp             EFaceFXRegOp
#define EBoneVisibilityStatus    EBoneVisibilityStatus
#define EPhysBodyOp              EPhysBodyOp

/* ---------------------------------------------------------- UStaticMeshComponent ---------------------------------------------------------- */

typedef enum ELightmapModificationFunction : unsigned char {
  MLMF_Modulate,                  // 0
  MLMF_ModulateAlpha,             // 1
  MLMF_MAX                        // 2
} ELightmapModificationFunction;
#define ELightmapModificationFunction  ELightmapModificationFunction

/* ---------------------------------------------------------- UInventoryCardGFx ---------------------------------------------------------- */

typedef enum ETopStatArrow : unsigned char {
  ETSA_Blank,                     // 0
  ETSA_Up,                        // 1
  ETSA_Down,                      // 2
  ETSA_Same,                      // 3
  ETSA_MAX                        // 4
} ETopStatArrow;
#define ETopStatArrow  ETopStatArrow

/* ---------------------------------------------------------- USwfMovie ---------------------------------------------------------- */

typedef enum FlashTextureRescale : unsigned char {
  FlashTextureScale_High,         // 0
  FlashTextureScale_Low,          // 1
  FlashTextureScale_NextLow,      // 2
  FlashTextureScale_Mult4,        // 3
  FlashTextureScale_None,         // 4
  FlashTextureScale_MAX           // 5
} FlashTextureRescale;
typedef enum SwfMovieArenas      : unsigned char {
  SWFARENA_Global,                // 0
  SWFARENA_Default,               // 1
  SWFARENA_HUD,                   // 2
  SWFARENA_StatusMenu,            // 3
  SWFARENA_Menu,                  // 4
  SWFARENA_MAX                    // 5
} SwfMovieArenas;
#define FlashTextureRescale  FlashTextureRescale
#define SwfMovieArenas       SwfMovieArenas

/* ---------------------------------------------------------- AWillowLightProjectileManager ---------------------------------------------------------- */

typedef enum EBulletFromClip : unsigned char {
  BFC_Other,                      // 0
  BFC_First,                      // 1
  BFC_Last,                       // 2
  BFC_MAX                         // 3
} EBulletFromClip;
typedef enum EBeamSource     : unsigned char {
  EBS_Weapon,                     // 0
  EBS_Pawn,                       // 1
  EBS_WorldBody,                  // 2
  EBS_MAX                         // 3
} EBeamSource;
#define EBulletFromClip  EBulletFromClip
#define EBeamSource      EBeamSource

/* ---------------------------------------------------------- UInventoryPartListCollectionDefinition ---------------------------------------------------------- */

typedef enum EPartReplacementMode : unsigned char {
  EPRM_Additive,                  // 0
  EPRM_Selective,                 // 1
  EPRM_Complete,                  // 2
  EPRM_MAX                        // 3
} EPartReplacementMode;
#define EPartReplacementMode  EPartReplacementMode

/* ---------------------------------------------------------- UBodyClassDefinition ---------------------------------------------------------- */

typedef enum EFlinchSeverity : unsigned char {
  EF_NoFlinch,                    // 0
  EF_SmallFlinch,                 // 1
  EF_MediumFlinch,                // 2
  EF_LargeFlinch,                 // 3
  EF_CriticalFlinch,              // 4
  EF_MAX                          // 5
} EFlinchSeverity;
typedef enum ECloakType      : unsigned char {
  CLOAK_Spawn,                    // 0
  CLOAK_AttackMove,               // 1
  CLOAK_AttackAnim,               // 2
  CLOAK_PatrolPath,               // 3
  CLOAK_PatrolPerch,              // 4
  CLOAK_PatrolRandom,             // 5
  CLOAK_RunHome,                  // 6
  CLOAK_Unprovoked,               // 7
  CLOAK_ScriptedMove,             // 8
  CLOAK_SpawnAnim,                // 9
  CLOAK_PhysicsJump,              // 10
  CLOAK_MAX                       // 11
} ECloakType;
typedef enum ECloakStyle     : unsigned char {
  CLOAKSTYLE_None,                // 0
  CLOAKSTYLE_Hide,                // 1
  CLOAKSTYLE_Visible,             // 2
  CLOAKSTYLE_VisibleHUD,          // 3
  CLOAKSTYLE_MAX                  // 4
} ECloakStyle;
#define EFlinchSeverity  EFlinchSeverity
#define ECloakType       ECloakType
#define ECloakStyle      ECloakStyle
_DECL_TARRAY(ECloakType);

/* ---------------------------------------------------------- UBodyHitRegionDefinition ---------------------------------------------------------- */

typedef enum EGoreMode : unsigned char {
  GORE_Full,                      // 0
  GORE_None,                      // 1
  GORE_MAX                        // 2
} EGoreMode;
#define EGoreMode  EGoreMode

/* ---------------------------------------------------------- UDownloadableContentEnumerator ---------------------------------------------------------- */

typedef enum EDlcEnumerationState : unsigned char {
  DLC_ENUM_None,                  // 0
  DLC_ENUM_EnumeratingFiles,      // 1
  DLC_ENUM_EnumerationComplete,   // 2
  DLC_ENUM_MAX                    // 3
} EDlcEnumerationState;
#define EDlcEnumerationState  EDlcEnumerationState

/* ---------------------------------------------------------- UDownloadableContentManager ---------------------------------------------------------- */

typedef enum EInstalledContentType : unsigned char {
  INSTALLED_CONTENT_TYPE_UnNamed, // 0
  INSTALLED_CONTENT_TYPE_Named,   // 1
  INSTALLED_CONTENT_TYPE_Compatibility,// 2
  INSTALLED_CONTENT_TYPE_SeasonPass,// 3
  INSTALLED_CONTENT_TYPE_PreorderBonus,// 4
  INSTALLED_CONTENT_TYPE_CompatibilityPackContainer,// 5
  INSTALLED_CONTENT_TYPE_MAX      // 6
} EInstalledContentType;
typedef enum EInstallDLCResult     : unsigned char {
  INSTALLDLC_RES_Success,         // 0
  INSTALLDLC_RES_InvalidNameInfo, // 1
  INSTALLDLC_RES_InvalidEngineVersion,// 2
  INSTALLDLC_RES_CookedGuidMismatch,// 3
  INSTALLDLC_RES_CorruptContent,  // 4
  INSTALLDLC_RES_UnknownFailure,  // 5
  INSTALLDLC_RES_CannotInstallCompatibility,// 6
  INSTALLDLC_RES_CompabitilityContentNotInstalled,// 7
  INSTALLDLC_RES_UnlicensedNamedContent,// 8
  INSTALLDLC_RES_MAX              // 9
} EInstallDLCResult;
#define EInstalledContentType  EInstalledContentType
#define EInstallDLCResult      EInstallDLCResult

/* ---------------------------------------------------------- UDownloadableContentOfferEnumerator ---------------------------------------------------------- */

typedef enum EDlcOfferEnumerationState : unsigned char {
  DLC_OFFER_ENUM_None,            // 0
  DLC_OFFER_ENUM_EnumeratingOffers,// 1
  DLC_OFFER_ENUM_EnumerationComplete,// 2
  DLC_OFFER_ENUM_MAX              // 3
} EDlcOfferEnumerationState;
#define EDlcOfferEnumerationState  EDlcOfferEnumerationState

/* ---------------------------------------------------------- UWillowDownloadableContentManager ---------------------------------------------------------- */

typedef enum EDlcInstallState      : unsigned char {
  DLC_INSTALL_None,               // 0
  DLC_INSTALL_InstallingBundles,  // 1
  DLC_INSTALL_LoadingAsyncPackages,// 2
  DLC_INSTALL_InstallingContent,  // 3
  DLC_INSTALL_InstallingOfferContent,// 4
  DLC_INSTALL_InstallComplete,    // 5
  DLC_INSTALL_MAX                 // 6
} EDlcInstallState;
typedef enum EMarketplaceOfferType : unsigned char {
  OFFER_CATEGORY_SeasonPass,      // 0
  OFFER_CATEGORY_CompatibilityPack,// 1
  OFFER_CATEGORY_AddOn,           // 2
  OFFER_CATEGORY_Misc,            // 3
  OFFER_CATEGORY_MAX              // 4
} EMarketplaceOfferType;
#define EDlcInstallState       EDlcInstallState
#define EMarketplaceOfferType  EMarketplaceOfferType

/* ---------------------------------------------------------- UMaterialInterface ---------------------------------------------------------- */

typedef enum EParticleDownsampling : unsigned char {
  PDS_Full,                       // 0
  PDS_Half,                       // 1
  PDS_Quarter,                    // 2
  PDS_MAX                         // 3
} EParticleDownsampling;
#define EParticleDownsampling  EParticleDownsampling

/* ---------------------------------------------------------- UAnimNode ---------------------------------------------------------- */

typedef enum ESliderType : unsigned char {
  ST_1D,                          // 0
  ST_2D,                          // 1
  ST_MAX                          // 2
} ESliderType;
#define ESliderType  ESliderType

/* ---------------------------------------------------------- UAnimNodeAimOffset ---------------------------------------------------------- */

typedef enum EAnimAimDir : unsigned char {
  ANIMAIM_LEFTUP,                 // 0
  ANIMAIM_CENTERUP,               // 1
  ANIMAIM_RIGHTUP,                // 2
  ANIMAIM_LEFTCENTER,             // 3
  ANIMAIM_CENTERCENTER,           // 4
  ANIMAIM_RIGHTCENTER,            // 5
  ANIMAIM_LEFTDOWN,               // 6
  ANIMAIM_CENTERDOWN,             // 7
  ANIMAIM_RIGHTDOWN,              // 8
  ANIMAIM_MAX                     // 9
} EAnimAimDir;
typedef enum EAimID      : unsigned char {
  EAID_LeftUp,                    // 0
  EAID_LeftDown,                  // 1
  EAID_RightUp,                   // 2
  EAID_RightDown,                 // 3
  EAID_ZeroUp,                    // 4
  EAID_ZeroDown,                  // 5
  EAID_ZeroLeft,                  // 6
  EAID_ZeroRight,                 // 7
  EAID_CellLU,                    // 8
  EAID_CellCU,                    // 9
  EAID_CellRU,                    // 10
  EAID_CellLC,                    // 11
  EAID_CellCC,                    // 12
  EAID_CellRC,                    // 13
  EAID_CellLD,                    // 14
  EAID_CellCD,                    // 15
  EAID_CellRD,                    // 16
  EAID_MAX                        // 17
} EAimID;
#define EAnimAimDir  EAnimAimDir
#define EAimID       EAimID

/* ---------------------------------------------------------- UDecalComponent ---------------------------------------------------------- */

typedef enum EDecalTransform : unsigned char {
  DecalTransform_OwnerAbsolute,   // 0
  DecalTransform_OwnerRelative,   // 1
  DecalTransform_SpawnRelative,   // 2
  DecalTransform_MAX              // 3
} EDecalTransform;
typedef enum EFilterMode     : unsigned char {
  FM_None,                        // 0
  FM_Ignore,                      // 1
  FM_Affect,                      // 2
  FM_MAX                          // 3
} EFilterMode;
#define EDecalTransform  EDecalTransform
#define EFilterMode      EFilterMode

/* ---------------------------------------------------------- UInteractiveObjectDefinition ---------------------------------------------------------- */

typedef enum ERelevanceDistance   : unsigned char {
  RELEVANCE_Lootable,             // 0
  RELEVANCE_Outpost,              // 1
  RELEVANCE_Huge,                 // 2
  RELEVANCE_MAX                   // 3
} ERelevanceDistance;
typedef enum EOnTouchEventOutputs : unsigned char {
  EONTOUCH_Player,                // 0
  EONTOUCH_NotPlayer,             // 1
  EONTOUCH_MAX                    // 2
} EOnTouchEventOutputs;
#define ERelevanceDistance    ERelevanceDistance
#define EOnTouchEventOutputs  EOnTouchEventOutputs

/* ---------------------------------------------------------- AWillowMind ---------------------------------------------------------- */

typedef enum EScriptFocus  : unsigned char {
  ESF_Path,                       // 0
  ESF_Target,                     // 1
  ESF_MAX                         // 2
} EScriptFocus;
typedef enum AIWeaponState : unsigned char {
  AIWeaponState_Firing,           // 0
  AIWeaponState_NotFiring,        // 1
  AIWeaponState_FiringPaused,     // 2
  AIWeaponState_MAX               // 3
} AIWeaponState;
#define EScriptFocus   EScriptFocus
#define AIWeaponState  AIWeaponState

/* ---------------------------------------------------------- AWillowAIPawn ---------------------------------------------------------- */

typedef enum EStaggerState : unsigned char {
  ESTAGGER_Staggered,             // 0
  ESTAGGER_Unstaggering,          // 1
  ESTAGGER_BlendAnimStart,        // 2
  ESTAGGER_BlendAnimEnd,          // 3
  ESTAGGER_MAX                    // 4
} EStaggerState;
typedef enum EDenStat      : unsigned char {
  DenStat_None,                   // 0
  DenStat_Injured,                // 1
  DenStat_OnFire,                 // 2
  DenStat_Corrosive,              // 3
  DenStat_Shocked,                // 4
  DenStat_Slagged,                // 5
  DenStat_Slowed,                 // 6
  DenStat_Healing,                // 7
  DenStat_MAX                     // 8
} EDenStat;
#define EStaggerState  EStaggerState
#define EDenStat       EDenStat

/* ---------------------------------------------------------- ACoverLink ---------------------------------------------------------- */

typedef enum ECoverAction              : unsigned char {
  CA_Default,                     // 0
  CA_BlindLeft,                   // 1
  CA_BlindRight,                  // 2
  CA_LeanLeft,                    // 3
  CA_LeanRight,                   // 4
  CA_StepLeft,                    // 5
  CA_StepRight,                   // 6
  CA_PopUp,                       // 7
  CA_BlindUp,                     // 8
  CA_PeekLeft,                    // 9
  CA_PeekRight,                   // 10
  CA_PeekUp,                      // 11
  CA_MAX                          // 12
} ECoverAction;
typedef enum ECoverDirection           : unsigned char {
  CD_Default,                     // 0
  CD_Left,                        // 1
  CD_Right,                       // 2
  CD_Up,                          // 3
  CD_MAX                          // 4
} ECoverDirection;
typedef enum ECoverType                : unsigned char {
  CT_None,                        // 0
  CT_Standing,                    // 1
  CT_MidLevel,                    // 2
  CT_MAX                          // 3
} ECoverType;
typedef enum ECoverLocationDescription : unsigned char {
  CoverDesc_None,                 // 0
  CoverDesc_InWindow,             // 1
  CoverDesc_InDoorway,            // 2
  CoverDesc_BehindCar,            // 3
  CoverDesc_BehindTruck,          // 4
  CoverDesc_OnTruck,              // 5
  CoverDesc_BehindBarrier,        // 6
  CoverDesc_BehindColumn,         // 7
  CoverDesc_BehindCrate,          // 8
  CoverDesc_BehindWall,           // 9
  CoverDesc_BehindStatue,         // 10
  CoverDesc_BehindSandbags,       // 11
  CoverDesc_MAX                   // 12
} ECoverLocationDescription;
typedef enum EFireLinkID               : unsigned char {
  FLI_FireLink,                   // 0
  FLI_RejectedFireLink,           // 1
  FLI_MAX                         // 2
} EFireLinkID;
#define ECoverAction               ECoverAction
#define ECoverDirection            ECoverDirection
#define ECoverType                 ECoverType
#define ECoverLocationDescription  ECoverLocationDescription
#define EFireLinkID                EFireLinkID
_DECL_TARRAY(ECoverAction);

/* ---------------------------------------------------------- ANavigationPoint ---------------------------------------------------------- */

typedef enum ENodeSearchType  : unsigned char {
  NODE_Ambush,                    // 0
  NODE_PointOfInterest,           // 1
  NODE_MAX                        // 2
} ENodeSearchType;
#define ENodeSearchType  ENodeSearchType

/* ---------------------------------------------------------- UDynamicLightEnvironmentComponent ---------------------------------------------------------- */

typedef enum EDynamicLightEnvironmentBoundsMethod : unsigned char {
  DLEB_OwnerComponents,           // 0
  DLEB_ManualOverride,            // 1
  DLEB_ActiveComponents,          // 2
  DLEB_MAX                        // 3
} EDynamicLightEnvironmentBoundsMethod;
#define EDynamicLightEnvironmentBoundsMethod  EDynamicLightEnvironmentBoundsMethod

/* ---------------------------------------------------------- UICounterBehavior ---------------------------------------------------------- */


typedef enum EBehaviorCounterID    : unsigned char {
  BCOUNTER_1,                     // 0
  BCOUNTER_2,                     // 1
  BCOUNTER_MAX                    // 2
#define EBehaviorCounterID__MAX  BCOUNTER_MAX
} EBehaviorCounterID;
typedef enum EBehaviorCounterEvent : unsigned char {
  COUNTEREVENT_Counter1AtTarget,  // 0
  COUNTEREVENT_Counter2AtTarget,  // 1
  COUNTEREVENT_MAX                // 2
} EBehaviorCounterEvent;
#define EBehaviorCounterID     EBehaviorCounterID
#define EBehaviorCounterEvent  EBehaviorCounterEvent

/* ---------------------------------------------------------- UPawnAllegiance ---------------------------------------------------------- */

typedef enum EOpinion : unsigned char {
  OPINION_Enemy,                  // 0
  OPINION_Neutral,                // 1
  OPINION_Friendly,               // 2
  OPINION_MAX                     // 3
} EOpinion;
#define EOpinion  EOpinion

/* ---------------------------------------------------------- UInterpTrackMove ---------------------------------------------------------- */

typedef enum EInterpTrackMoveFrame   : unsigned char {
  IMF_World,                      // 0
  IMF_RelativeToInitial,          // 1
  IMF_MAX                         // 2
} EInterpTrackMoveFrame;
typedef enum EInterpTrackMoveRotMode : unsigned char {
  IMR_Keyframed,                  // 0
  IMR_LookAtGroup,                // 1
  IMR_Ignore,                     // 2
  IMR_MAX                         // 3
} EInterpTrackMoveRotMode;
#define EInterpTrackMoveFrame    EInterpTrackMoveFrame
#define EInterpTrackMoveRotMode  EInterpTrackMoveRotMode

/* ---------------------------------------------------------- UAnimNodeSequence ---------------------------------------------------------- */

typedef enum ERootBoneAxis       : unsigned char {
  RBA_Default,                    // 0
  RBA_Discard,                    // 1
  RBA_Translate,                  // 2
  RBA_MAX                         // 3
} ERootBoneAxis;
typedef enum ERootRotationOption : unsigned char {
  RRO_Default,                    // 0
  RRO_Discard,                    // 1
  RRO_Extract,                    // 2
  RRO_MAX                         // 3
} ERootRotationOption;
#define ERootBoneAxis        ERootBoneAxis
#define ERootRotationOption  ERootRotationOption

/* ---------------------------------------------------------- UModel ---------------------------------------------------------- */

enum {MAX_NODES  = 65536};
enum {MAX_POINTS = 128000};
enum {MAX_NODE_VERTICES=255};	// Max vertices in a Bsp node.
enum {MAX_ZONES=64};			// Max zones per level.

/* Flags associated with a Bsp node. */
typedef enum EBspNodeFlags : unsigned char {
	NF_NotCsg         = 0x01,  /* Node is not a Csg splitter, i.e. is a transparent poly. */
	NF_NotVisBlocking = 0x04,  /* Node does not block visibility, i.e. is an invisible collision hull. */
	NF_BrightCorners  = 0x10,  /* Temporary. */
	NF_IsNew          = 0x20,  /* Editor: Node was newly-added. */
	NF_IsFront        = 0x40,  /* Filter operation bounding-sphere precomputed and guaranteed to be front. */
	NF_IsBack         = 0x80,  /* Guaranteed back. */
} EBspNodeFlags;
#define EBspNodeFlags  EBspNodeFlags

/* ---------------------------------------------------------- UGameplayEvents ---------------------------------------------------------- */

typedef enum EGameStatGroups : unsigned char {
  GSG_EngineStats,                // 0
  GSG_Game,                       // 1
  GSG_Team,                       // 2
  GSG_Player,                     // 3
  GSG_Weapon,                     // 4
  GSG_Damage,                     // 5
  GSG_Projectile,                 // 6
  GSG_Pawn,                       // 7
  GSG_GameSpecific,               // 8
  GSG_Aggregate,                  // 9
  GSG_MAX                         // 10
} EGameStatGroups;
#define EGameStatGroups  EGameStatGroups

/* ---------------------------------------------------------- FGameEventType ---------------------------------------------------------- */

/** Enumeration defining the header type in the file stream (changing order breaks backwards compatibility) */
typedef enum EGameplayEventType {
	GET_GameString = 0,
	GET_GameInt,
	GET_TeamInt,
	GET_PlayerInt,
	GET_PlayerFloat,
	GET_PlayerString,
	GET_PlayerSpawn,
	GET_PlayerLogin,
	GET_PlayerLocationPoll,
	GET_PlayerKillDeath,
	GET_PlayerPlayer,
	GET_WeaponInt,
	GET_DamageInt,
	GET_ProjectileInt,
	GET_GenericParamList,
	GET_GameFloat, 
	GET_TeamString,
	GET_TeamFloat,
	GET_GamePosition,
	GET_GameAggregate,
	GET_TeamAggregate,
	GET_PlayerAggregate,
	GET_WeaponAggregate,
	GET_DamageAggregate,
	GET_ProjectileAggregate,
	GET_PawnAggregate,
	GET_GameType = 1000 // Game Specific Values start after this
} EGameplayEventType;
#define EGameplayEventType  EGameplayEventType

/* ---------------------------------------------------------- ULocalMessage ---------------------------------------------------------- */

typedef enum ELocalMessageType : unsigned char {
  LMT_Training,                   // 0
  LMT_ContextHint,                // 1
  LMT_XP,                         // 2
  LMT_Player,                     // 3
  LMT_System,                     // 4
  LMT_ReceivedLoot,               // 5
  LMT_OpenedChest,                // 6
  LMT_Chat,                       // 7
  LMT_MAX                         // 8
} ELocalMessageType;
#define ELocalMessageType  ELocalMessageType

/* ---------------------------------------------------------- UReceivedAmmoMessage ---------------------------------------------------------- */

typedef enum EAmmoMessageSwitch : unsigned char {
  RECEIVEDAMMO_CombatRifle,       // 0
  RECEIVEDAMMO_SMG,               // 1
  RECEIVEDAMMO_Revolver,          // 2
  RECEIVEDAMMO_Repeater,          // 3
  RECEIVEDAMMO_Shotgun,           // 4
  RECEIVEDAMMO_SniperRifle,       // 5
  RECEIVEDAMMO_Rocket,            // 6
  RECEIVEDAMMO_Grenade,           // 7
  RECEIVEDAMMO_MAX                // 8
} EAmmoMessageSwitch;
#define EAmmoMessageSwitch  EAmmoMessageSwitch

/* ---------------------------------------------------------- UParticleModule ---------------------------------------------------------- */

typedef enum EModuleType : unsigned char {
  EPMT_General,                   // 0
  EPMT_TypeData,                  // 1
  EPMT_Beam,                      // 2
  EPMT_Trail,                     // 3
  EPMT_Spawn,                     // 4
  EPMT_Required,                  // 5
  EPMT_Event,                     // 6
  EPMT_MAX                        // 7
} EModuleType;
typedef enum EParticleSourceSelectionMethod : unsigned char {
  EPSSM_Random,                   // 0
  EPSSM_Sequential,               // 1
  EPSSM_MAX                       // 2
} EParticleSourceSelectionMethod;
#define EModuleType                     EModuleType
#define EParticleSourceSelectionMethod  EParticleSourceSelectionMethod

/* ---------------------------------------------------------- UParticleEmitter ---------------------------------------------------------- */

typedef enum EParticleBurstMethod       : unsigned char {
  EPBM_Instant,                   // 0
  EPBM_Interpolated,              // 1
  EPBM_MAX                        // 2
} EParticleBurstMethod;
typedef enum EParticleSubUVInterpMethod : unsigned char {
  PSUVIM_None,                    // 0
  PSUVIM_Linear,                  // 1
  PSUVIM_Linear_Blend,            // 2
  PSUVIM_Random,                  // 3
  PSUVIM_Random_Blend,            // 4
  PSUVIM_MAX                      // 5
} EParticleSubUVInterpMethod;
typedef enum EEmitterRenderMode         : unsigned char {
  ERM_Normal,                     // 0
  ERM_Point,                      // 1
  ERM_Cross,                      // 2
  ERM_None,                       // 3
  ERM_MAX                         // 4
} EEmitterRenderMode;
#define EParticleBurstMethod        EParticleBurstMethod
#define EParticleSubUVInterpMethod  EParticleSubUVInterpMethod
#define EEmitterRenderMode          EEmitterRenderMode

/* ---------------------------------------------------------- FSimpleElementVertex ---------------------------------------------------------- */

/** Blend modes supported for simple element rendering */
typedef enum ESimpleElementBlendMode : unsigned char {
	SE_BLEND_Opaque=0,
	SE_BLEND_Masked,
	SE_BLEND_Translucent,
	SE_BLEND_Additive,
	SE_BLEND_Modulate,
	SE_BLEND_MaskedDistanceField,
	SE_BLEND_MaskedDistanceFieldShadowed,
	SE_BLEND_TranslucentDistanceField,
	SE_BLEND_TranslucentDistanceFieldShadowed,
	SE_BLEND_AlphaComposite,

	SE_BLEND_RGBA_MASK_START,
	SE_BLEND_RGBA_MASK_END = SE_BLEND_RGBA_MASK_START+31, //Using 5bit bit-field for red, green, blue, alpha and desaturation

	SE_BLEND_MAX
} ESimpleElementBlendMode;
#define ESimpleElementBlendMode  ESimpleElementBlendMode

/* ---------------------------------------------------------- FCanvas ---------------------------------------------------------- */

/** Enum that describes what type of element we are currently batching. */
typedef enum EElementType      : unsigned char {
  ET_Line,
  ET_Triangle,
  ET_MAX
} EElementType;
/** Enum for canvas features that are allowed. */
typedef enum ECanvasAllowModes : unsigned char {
  // stencil masked regions
  Allow_MaskedRegions	= 1<<0,
  // depth testing
  Allow_DepthTest		= 1<<1,
  // flushing and rendering
  Allow_Flush			= 1<<2,
  // delete the render batches when rendering
  Allow_DeleteOnRender= 1<<3
} ECanvasAllowModes;
#define EElementType       EElementType
#define ECanvasAllowModes  ECanvasAllowModes

/* ---------------------------------------------------------- UPhysicalMaterial ---------------------------------------------------------- */

typedef enum EPhysEffectType : unsigned char {
  EPMET_Impact,                   // 0
  EPMET_Slide,                    // 1
  EPMET_MAX                       // 2
} EPhysEffectType;
#define EPhysEffectType  EPhysEffectType

/* ---------------------------------------------------------- USkillDefinition ---------------------------------------------------------- */

typedef enum EEffectDurationType       : unsigned char {
  DURATION_Infinite,              // 0
  DURATION_Timed,                 // 1
  DURATION_MAX                    // 2
} EEffectDurationType;
typedef enum EEffectTarget             : unsigned char {
  TARGET_None,                    // 0
  TARGET_Self,                    // 1
  TARGET_Allies,                  // 2
  TARGET_Enemies,                 // 3
  TARGET_All,                     // 4
  TARGET_Pets,                    // 5
  TARGET_MAX                      // 6
} EEffectTarget;
typedef enum ETargetCriteria           : unsigned char {
  CRITERIA_None,                  // 0
  CRITERIA_Nearest,               // 1
  CRITERIA_MAX                    // 2
} ETargetCriteria;
typedef enum ESkillState               : unsigned char {
  SKILL_Deactivated,              // 0
  SKILL_Active,                   // 1
  SKILL_Paused,                   // 2
  SKILL_MAX                       // 3
} ESkillState;
typedef enum ESkillType                : unsigned char {
  SKILL_TYPE_Passive,             // 0
  SKILL_TYPE_Action,              // 1
  SKILL_TYPE_ActionAugment,       // 2
  SKILL_TYPE_Kill,                // 3
  SKILL_TYPE_Proficiency,         // 4
  SKILL_TYPE_MAX                  // 5
} ESkillType;
typedef enum ESkillEventType           : unsigned char {
  SEVT_SkillActivated,            // 0
  SEVT_SkillDeactivated,          // 1
  SEVT_SkillPaused,               // 2
  SEVT_SkillResumed,              // 3
  SEVT_DamagedEnemy,              // 4
  SEVT_DamagedFriendly,           // 5
  SEVT_DamagedNeutral,            // 6
  SEVT_DamagedByEnemy,            // 7
  SEVT_DamagedByFriendly,         // 8
  SEVT_DamagedByNeutral,          // 9
  SEVT_ShieldDepletedAfterBeingFull,// 10
  SEVT_KilledEnemy,               // 11
  SEVT_KilledFriendly,            // 12
  SEVT_KilledNeutral,             // 13
  SEVT_KilledByEnemy,             // 14
  SEVT_KilledByFriendly,          // 15
  SEVT_KilledByNeutral,           // 16
  SEVT_WeaponZoomed,              // 17
  SEVT_WeaponUnzoomed,            // 18
  SEVT_WeaponShotMissed,          // 19
  SEVT_WeaponFired,               // 20
  SEVT_WeaponReloaded,            // 21
  SEVT_PlayerDeathAverted,        // 22
  SEVT_ActionSkillCooldownAbilityActivated,// 23
  SEVT_ActionSkillActiveAbilityActivated,// 24
  SEVT_DamagedUnawareEnemy,       // 25
  SEVT_DamagedEnemyWithMeleeFromBehind,// 26
  SEVT_MeleeOverrideSkillActivated,// 27
  SEVT_ThrowGrenadeOverrideSkillActivated,// 28
  SEVT_WeaponSwapped,             // 29
  SEVT_PlayerRecoveredFromDownState,// 30
  SEVT_ShieldDepleted,            // 31
  SEVT_ShieldFull,                // 32
  SEVT_WeaponStartReload,         // 33
  SEVT_PlayerResurrected,         // 34
  SEVT_WeaponManuallyReloaded,    // 35
  SEVT_AppliedStatusEffectToEnemy,// 36
  SEVT_DownStateBegin,            // 37
  SEVT_DownStateEnd,              // 38
  SEVT_BledOut,                   // 39
  SEVT_OnStatusEffectTypeBegin,   // 40
  SEVT_OnStatusEffectTypeEnd,     // 41
  SEVT_MeleeAttack,               // 42
  SEVT_MAX                        // 43
} ESkillEventType;
typedef enum ESkillDamagedEventType    : unsigned char {
  SDEVT_DamagedEnemy,             // 0
  SDEVT_DamagedFriendly,          // 1
  SDEVT_DamagedNeutral,           // 2
  SDEVT_DamagedByEnemy,           // 3
  SDEVT_DamagedByFriendly,        // 4
  SDEVT_DamagedByNeutral,         // 5
  SDEVT_ShieldDepletedAfterBeingFull,// 6
  SDEVT_MAX                       // 7
} ESkillDamagedEventType;
typedef enum ESkillKilledEventType     : unsigned char {
  SKEVT_KilledEnemy,              // 0
  SKEVT_KilledFriendly,           // 1
  SKEVT_KilledNeutral,            // 2
  SKEVT_KilledByEnemy,            // 3
  SKEVT_KilledByFriendly,         // 4
  SKEVT_KilledByNeutral,          // 5
  SKEVT_MAX                       // 6
} ESkillKilledEventType;
typedef enum ESkillEventGradeType      : unsigned char {
  SEVG_PlayerSkillGrade,          // 0
  SEVG_HardcodedGrade,            // 1
  SEVG_SameAsThisSkillGrade,      // 2
  SEVG_MAX                        // 3
} ESkillEventGradeType;
typedef enum ETrackedSkillType         : unsigned char {
  TRACKEDSKILL_Untracked,         // 0
  TRACKEDSKILL_Kill,              // 1
  TRACKEDSKILL_Triggered,         // 2
  TRACKEDSKILL_Respond,           // 3
  TRACKEDSKILL_ConsumableBuff,    // 4
  TRACKEDSKILL_MeleeOverride,     // 5
  TRACKEDSKILL_TriggeredNotSkillTree,// 6
  TRACKEDSKILL_MAX                // 7
} ETrackedSkillType;
typedef enum ERequiredActionSkillState : unsigned char {
  ERASS_Ignore,                   // 0
  ERASS_MustBeRunning,            // 1
  ERASS_MustNotBeRunning,         // 2
  ERASS_MAX                       // 3
} ERequiredActionSkillState;
typedef enum ESkillDamageEvents        : unsigned char {
  SDE_DamagedEnemy,               // 0
  SDE_DamagedFriendly,            // 1
  SDE_DamagedByEnemy,             // 2
  SDE_DamagedByFriendly,          // 3
  SDE_DamagedNeutral_Deprecated,  // 4
  SDE_DamagedByNeutral_Deprecated,// 5
  SDE_DamagedUnawareEnemy,        // 6
  SDE_DamagedEnemyWithMeleeFromBehind,// 7
  SDE_DamagedEnemyExposeDamageSurfaceType,// 8
  SDE_MAX                         // 9
} ESkillDamageEvents;
typedef enum ESkillKillEvents          : unsigned char {
  SKE_KilledEnemy,                // 0
  SKE_KilledByEnemy,              // 1
  SKE_MAX                         // 2
} ESkillKillEvents;
#define EEffectDurationType        EEffectDurationType
#define EEffectTarget              EEffectTarget
#define ETargetCriteria            ETargetCriteria
#define ESkillState                ESkillState
#define ESkillType                 ESkillType
#define ESkillEventType            ESkillEventType
#define ESkillDamagedEventType     ESkillDamagedEventType
#define ESkillKilledEventType      ESkillKilledEventType
#define ESkillEventGradeType       ESkillEventGradeType
#define ETrackedSkillType          ETrackedSkillType
#define ERequiredActionSkillState  ERequiredActionSkillState
#define ESkillDamageEvents         ESkillDamageEvents
#define ESkillKillEvents           ESkillKillEvents

/* ---------------------------------------------------------- UAchievementUtility ---------------------------------------------------------- */

typedef enum EWillowAchievementList : unsigned char {
  WA_Invalid,                     // 0
  WA_PlotMission1,                // 1
  WA_PlotMission2,                // 2
  WA_PlotMission3,                // 3
  WA_PlotMission4,                // 4
  WA_PlotMission5,                // 5
  WA_PlotMission6,                // 6
  WA_PlotMission7,                // 7
  WA_PlotMission8,                // 8
  WA_PlotMission9,                // 9
  WA_PlotMission10,               // 10
  WA_PlotMission11,               // 11
  WA_PlotMission12,               // 12
  WA_PlotMission13,               // 13
  WA_PlotMission14,               // 14
  WA_PlotMission15,               // 15
  WA_PlotMission16,               // 16
  WA_ChallengeAccepted,           // 17
  WA_GoliathMeetDavid,            // 18
  WA_WentFiveRounds,              // 19
  WA_NotQuiteDead,                // 20
  WA_BetterThanYouWere,           // 21
  WA_AlwaysImproving,             // 22
  WA_CappedOutForNow,             // 23
  WA_ArcticExplorer,              // 24
  WA_UrbanExplorer,               // 25
  WA_HighlandsExplorer,           // 26
  WA_BlightExplorer,              // 27
  WA_WorldTraveler,               // 28
  WA_SugarDaddy,                  // 29
  WA_DeckedOut,                   // 30
  WA_SabreRattler,                // 31
  WA_PhasedAndConfused,           // 32
  WA_SoMuchBlood,                 // 33
  WA_CuteLoot,                    // 34
  WA_TributeToAVaultHunter,       // 35
  WA_DefinitelyAnItalianPlumber,  // 36
  WA_HighFlyingHurler,            // 37
  WA_TokenGesture,                // 38
  WA_WhatDoesItMean,              // 39
  WA_UnseenPredator,              // 40
  WA_BuildBuster,                 // 41
  WA_WellThatWasEasy,             // 42
  WA_HowDoILook,                  // 43
  WA_ThresherThrashed,            // 44
  WA_FriendshipRules,             // 45
  WA_BetterThanMoney,             // 46
  WA_UpHighDownLow,               // 47
  WA_BountyHunter,                // 48
  WA_DidItAll,                    // 49
  WA_FeelsLikeTheFirstTime,       // 50
  WA_DLC1_Achievement1,           // 51
  WA_DLC1_Achievement2,           // 52
  WA_DLC1_Achievement3,           // 53
  WA_Iris_CompleteMainCampaign,   // 54
  WA_Iris_CompleteSideMissions,   // 55
  WA_Iris_CollectItems,           // 56
  WA_Sage_CompleteMainCampaign,   // 57
  WA_Sage_CompleteSideMissions,   // 58
  WA_Sage_DiscoverAllAreas,       // 59
  WA_DLCReserved_10,              // 60
  WA_DLCReserved_11,              // 61
  WA_DLCReserved_12,              // 62
  WA_DLCReserved_13,              // 63
  WA_DLCReserved_14,              // 64
  WA_DLCReserved_15,              // 65
  WA_DLCReserved_16,              // 66
  WA_DLCReserved_17,              // 67
  WA_DLCReserved_18,              // 68
  WA_DLCReserved_19,              // 69
  WA_DLCReserved_20,              // 70
  WA_DLCReserved_21,              // 71
  WA_DLCReserved_22,              // 72
  WA_DLCReserved_23,              // 73
  WA_DLCReserved_24,              // 74
  WA_DLCReserved_25,              // 75
  WA_DLCReserved_26,              // 76
  WA_DLCReserved_27,              // 77
  WA_DLCReserved_28,              // 78
  WA_DLCReserved_29,              // 79
  WA_DLCReserved_30,              // 80
  WA_DLCReserved_31,              // 81
  WA_DLCReserved_32,              // 82
  WA_DLCReserved_33,              // 83
  WA_DLCReserved_34,              // 84
  WA_DLCReserved_35,              // 85
  WA_DLCReserved_36,              // 86
  WA_DLCReserved_37,              // 87
  WA_DLCReserved_38,              // 88
  WA_DLCReserved_39,              // 89
  WA_DLCReserved_40,              // 90
  WA_DLCReserved_41,              // 91
  WA_DLCReserved_42,              // 92
  WA_DLCReserved_43,              // 93
  WA_DLCReserved_44,              // 94
  WA_DLCReserved_45,              // 95
  WA_DLCReserved_46,              // 96
  WA_DLCReserved_47,              // 97
  WA_DLCReserved_48,              // 98
  WA_DLCReserved_49,              // 99
  WA_MAX                          // 100
} EWillowAchievementList;
typedef enum EAchievementUnlockType : unsigned char {
  AUT_ZoneIn,                     // 0
  AUT_EarnMoney,                  // 1
  AUT_LeveledUp,                  // 2
  AUT_InstinctUp,                 // 3
  AUT_FallHeight,                 // 4
  AUT_HangTime,                   // 5
  AUT_QuestCompleted,             // 6
  AUT_ActionSkillKill,            // 7
  AUT_QuestCompletedCoOp,         // 8
  AUT_SpeedyTravel,               // 9
  AUT_SpeedyKills,                // 10
  AUT_RushTime,                   // 11
  AUT_InventorySlotChange,        // 12
  AUT_KilledLeveledUpPawn,        // 13
  AUT_TokensSpent,                // 14
  AUT_CustomizationsUnlocks,      // 15
  AUT_SideMissionsCompleted,      // 16
  AUT_PurchasedBlackMarketItem,   // 17
  AUT_MAX                         // 18
} EAchievementUnlockType;
#define EWillowAchievementList  EWillowAchievementList
#define EAchievementUnlockType  EAchievementUnlockType
_DECL_TARRAY(EWillowAchievementList);

/* ---------------------------------------------------------- USkeletalMesh ---------------------------------------------------------- */

typedef enum BoneBreakOption       : unsigned char {
  BONEBREAK_SoftPreferred,        // 0
  BONEBREAK_AutoDetect,           // 1
  BONEBREAK_RigidPreferred,       // 2
  BONEBREAK_MAX                   // 3
} BoneBreakOption;
typedef enum TriangleSortOption    : unsigned char {
  TRISORT_None,                   // 0
  TRISORT_CenterRadialDistance,   // 1
  TRISORT_Random,                 // 2
  TRISORT_MergeContiguous,        // 3
  TRISORT_Custom,                 // 4
  TRISORT_CustomLeftRight,        // 5
  TRISORT_MAX                     // 6
} TriangleSortOption;
typedef enum ClothMovementScaleGen : unsigned char {
  ECMDM_DistToFixedVert,          // 0
  ECMDM_VertexBoneWeight,         // 1
  ECMDM_Empty,                    // 2
  ECMDM_MAX                       // 3
} ClothMovementScaleGen;
typedef enum TriangleSortAxis      : unsigned char {
  TSA_X_Axis,                     // 0
  TSA_Y_Axis,                     // 1
  TSA_Z_Axis,                     // 2
  TSA_MAX                         // 3
} TriangleSortAxis;
typedef enum ClothBoneType         : unsigned char {
  CLOTHBONE_Fixed,                // 0
  CLOTHBONE_BreakableAttachment,  // 1
  CLOTHBONE_TearLine,             // 2
  CLOTHBONE_MAX                   // 3
} ClothBoneType;
typedef enum SoftBodyBoneType      : unsigned char {
  SOFTBODYBONE_Fixed,             // 0
  SOFTBODYBONE_BreakableAttachment,// 1
  SOFTBODYBONE_TwoWayAttachment,  // 2
  SOFTBODYBONE_MAX                // 3
} SoftBodyBoneType;
#define BoneBreakOption        BoneBreakOption
#define TriangleSortOption     TriangleSortOption
#define ClothMovementScaleGen  ClothMovementScaleGen
#define TriangleSortAxis       TriangleSortAxis
#define ClothBoneType          ClothBoneType
#define SoftBodyBoneType       SoftBodyBoneType
_DECL_TARRAY(BoneBreakOption);
_DECL_TARRAY(TriangleSortOption);

/* ---------------------------------------------------------- UTexture ---------------------------------------------------------- */

typedef enum TextureCompressionSettings : unsigned char {
  TC_Default,                     // 0
  TC_Normalmap,                   // 1
  TC_Displacementmap,             // 2
  TC_NormalmapAlpha,              // 3
  TC_Grayscale,                   // 4
  TC_HighDynamicRange,            // 5
  TC_OneBitAlpha,                 // 6
  TC_NormalmapUncompressed,       // 7
  TC_NormalmapBC5,                // 8
  TC_OneBitMonochrome,            // 9
  TC_SimpleLightmapModification,  // 10
  TC_VectorDisplacementmap,       // 11
  TC_MAX                          // 12
} TextureCompressionSettings;
typedef enum EPixelFormat               : unsigned char {
  PF_Unknown,                     // 0
  PF_A32B32G32R32F,               // 1
  PF_A8R8G8B8,                    // 2
  PF_G8,                          // 3
  PF_G16,                         // 4
  PF_DXT1,                        // 5
  PF_DXT3,                        // 6
  PF_DXT5,                        // 7
  PF_UYVY,                        // 8
  PF_FloatRGB,                    // 9
  PF_FloatRGBA,                   // 10
  PF_DepthStencil,                // 11
  PF_ShadowDepth,                 // 12
  PF_FilteredShadowDepth,         // 13
  PF_R32F,                        // 14
  PF_G16R16,                      // 15
  PF_G16R16F,                     // 16
  PF_G16R16F_FILTER,              // 17
  PF_G32R32F,                     // 18
  PF_A2B10G10R10,                 // 19
  PF_A16B16G16R16,                // 20
  PF_D24,                         // 21
  PF_R16F,                        // 22
  PF_R16F_FILTER,                 // 23
  PF_BC5,                         // 24
  PF_V8U8,                        // 25
  PF_A1,                          // 26
  PF_FloatR11G11B10,              // 27
  PF_MAX                          // 28
} EPixelFormat;
typedef enum TextureFilter              : unsigned char {
  TF_Nearest,                     // 0
  TF_Linear,                      // 1
  TF_MAX                          // 2
} TextureFilter;
typedef enum TextureAddress             : unsigned char {
  TA_Wrap,                        // 0
  TA_Clamp,                       // 1
  TA_Mirror,                      // 2
  TA_MAX                          // 3
} TextureAddress;
typedef enum TextureGroup               : unsigned char {
  TEXTUREGROUP_World,             // 0
  TEXTUREGROUP_WorldNormalMap,    // 1
  TEXTUREGROUP_WorldSpecular,     // 2
  TEXTUREGROUP_Character,         // 3
  TEXTUREGROUP_CharacterNormalMap,// 4
  TEXTUREGROUP_CharacterSpecular, // 5
  TEXTUREGROUP_Weapon,            // 6
  TEXTUREGROUP_WeaponNormalMap,   // 7
  TEXTUREGROUP_WeaponSpecular,    // 8
  TEXTUREGROUP_Vehicle,           // 9
  TEXTUREGROUP_VehicleNormalMap,  // 10
  TEXTUREGROUP_VehicleSpecular,   // 11
  TEXTUREGROUP_Cinematic,         // 12
  TEXTUREGROUP_Effects,           // 13
  TEXTUREGROUP_EffectsNotFiltered,// 14
  TEXTUREGROUP_Skybox,            // 15
  TEXTUREGROUP_UI,                // 16
  TEXTUREGROUP_Lightmap,          // 17
  TEXTUREGROUP_RenderTarget,      // 18
  TEXTUREGROUP_MobileFlattened,   // 19
  TEXTUREGROUP_ProcBuilding_Face, // 20
  TEXTUREGROUP_ProcBuilding_LightMap,// 21
  TEXTUREGROUP_Shadowmap,         // 22
  TEXTUREGROUP_ColorLookupTable,  // 23
  TEXTUREGROUP_Terrain_Heightmap, // 24
  TEXTUREGROUP_Terrain_Weightmap, // 25
  TEXTUREGROUP_ImageBasedReflection,// 26
  TEXTUREGROUP_Bokeh,             // 27
  TEXTUREGROUP_MAX                // 28
} TextureGroup;
typedef enum TextureMipGenSettings      : unsigned char {
  TMGS_FromTextureGroup,          // 0
  TMGS_SimpleAverage,             // 1
  TMGS_Sharpen0,                  // 2
  TMGS_Sharpen1,                  // 3
  TMGS_Sharpen2,                  // 4
  TMGS_Sharpen3,                  // 5
  TMGS_Sharpen4,                  // 6
  TMGS_Sharpen5,                  // 7
  TMGS_Sharpen6,                  // 8
  TMGS_Sharpen7,                  // 9
  TMGS_Sharpen8,                  // 10
  TMGS_Sharpen9,                  // 11
  TMGS_Sharpen10,                 // 12
  TMGS_NoMipmaps,                 // 13
  TMGS_LeaveExistingMips,         // 14
  TMGS_Blur1,                     // 15
  TMGS_Blur2,                     // 16
  TMGS_Blur3,                     // 17
  TMGS_Blur4,                     // 18
  TMGS_Blur5,                     // 19
  TMGS_MAX                        // 20
} TextureMipGenSettings;
typedef enum ETextureMipCount           : unsigned char {
  TMC_ResidentMips,               // 0
  TMC_AllMips,                    // 1
  TMC_AllMipsBiased,              // 2
  TMC_MAX                         // 3
} ETextureMipCount;
#define TextureCompressionSettings  TextureCompressionSettings
#define EPixelFormat                EPixelFormat
#define TextureFilter               TextureFilter
#define TextureAddress              TextureAddress
#define TextureGroup                TextureGroup
#define TextureMipGenSettings       TextureMipGenSettings
#define ETextureMipCount            ETextureMipCount

/* ---------------------------------------------------------- UWillowGFxDialogBox ---------------------------------------------------------- */

static const int MaxButtons = 5;

/* ---------------------------------------------------------- UWillowGameMessage ---------------------------------------------------------- */

typedef enum EWillowGameMessage : unsigned char {
  WGM_PlayerEnteredGame,          // 0
  WGM_PlayerLeftGame,             // 1
  WGM_CreaturesGrowStronger,      // 2
  WGM_CreaturesWeaken,            // 3
  WGM_MAX                         // 4
} EWillowGameMessage;
#define EWillowGameMessage  EWillowGameMessage

/* ---------------------------------------------------------- UGFxManager ---------------------------------------------------------- */

typedef enum EInputResult : unsigned char {
  IR_None,                        // 0
  IR_Handled,                     // 1
  IR_Consumed,                    // 2
  IR_MAX                          // 3
} EInputResult;
#define EInputResult  EInputResult

/* ---------------------------------------------------------- UUIDataProvider ---------------------------------------------------------- */

typedef enum EProviderAccessType : unsigned char {
  ACCESS_ReadOnly,                // 0
  ACCESS_PerField,                // 1
  ACCESS_WriteAll,                // 2
  ACCESS_MAX                      // 3
} EProviderAccessType;
#define EProviderAccessType  EProviderAccessType

/* ---------------------------------------------------------- UGlobalsDefinition ---------------------------------------------------------- */

typedef enum EDropLifeSpanType : unsigned char {
  DROP_VeryShortLived,            // 0
  DROP_ShortLived,                // 1
  DROP_LongLived,                 // 2
  DROP_LiveForever,               // 3
  DROP_LiveAsLongAsLevel,         // 4
  DROP_MAX                        // 5
} EDropLifeSpanType;
typedef enum EItemRarity       : unsigned char {
  RARITY_Unknown,                 // 0
  RARITY_Common,                  // 1
  RARITY_Uncommon,                // 2
  RARITY_Rare,                    // 3
  RARITY_VeryRare,                // 4
  RARITY_Legendary,               // 5
  RARITY_Seraph,                  // 6
  RARITY_Rainbow,                 // 7
  RARITY_MAX                      // 8
} EItemRarity;
typedef enum ENumClassPlayers  : unsigned char {
  NCP_OnePlayer,                  // 0
  NCP_TwoPlayers,                 // 1
  NCP_ThreePlayers,               // 2
  NCP_FourPlayers,                // 3
  NCP_MAX                         // 4
#define ENumClassPlayers__MAX  (NCP_MAX)
} ENumClassPlayers;
#define EDropLifeSpanType  EDropLifeSpanType
#define EItemRarity        EItemRarity
#define ENumClassPlayers   ENumClassPlayers

/* ---------------------------------------------------------- UAssetLibraryManager ---------------------------------------------------------- */

typedef enum EAssetLibrary : unsigned char {
  AL_WeaponTypes,                 // 0
  AL_WeaponParts,                 // 1
  AL_ItemTypes,                   // 2
  AL_ItemParts,                   // 3
  AL_Manufacturer,                // 4
  AL_Balance,                     // 5
  AL_MAX                          // 6
#define EAssetLibrary__MAX  (AL_MAX)
} EAssetLibrary;
#define EAssetLibrary  EAssetLibrary

/* ---------------------------------------------------------- UGFxMovieDrawStyleHUD ---------------------------------------------------------- */

typedef enum EHUDOrientation : unsigned char {
  HO_Horizontal,                  // 0
  HO_Vertical,                    // 1
  HO_MAX                          // 2
#define EHUDOrientation__MAX  (HO_MAX)
} EHUDOrientation;
typedef enum EHUDAnchorPoint : unsigned char {
  HAP_None,                       // 0
  HAP_Center,                     // 1
  HAP_TopLeft,                    // 2
  HAP_TopRight,                   // 3
  HAP_BottomLeft,                 // 4
  HAP_BottomRight,                // 5
  HAP_Left,                       // 6
  HAP_Top,                        // 7
  HAP_Right,                      // 8
  HAP_Bottom,                     // 9
  HAP_Projected,                  // 10
  HAP_ProjectedScaled,            // 11
  HAP_MAX                         // 12
} EHUDAnchorPoint;
typedef enum EHUDCoordType : unsigned char {
  HCT_Scaled,                     // 0
  HCT_Fixed,                      // 1
  HCT_MovieRelative,              // 2
  HCT_MAX                         // 3
} EHUDCoordType;
#define EHUDOrientation  EHUDOrientation
#define EHUDAnchorPoint  EHUDAnchorPoint
#define EHUDCoordType    EHUDCoordType

/* ---------------------------------------------------------- UFastTravelStationGFxMovie ---------------------------------------------------------- */

typedef enum ELocationMissionStatus : unsigned char {
  LMS_ReadyToTurnIn,              // 0
  LMS_New,                        // 1
  LMS_InProgress,                 // 2
  LMS_InProgressStory,            // 3
  LMS_AndMuchMore,                // 4
  LMS_Invalid,                    // 5
  LMS_MAX                         // 6
} ELocationMissionStatus;
#define ELocationMissionStatus  ELocationMissionStatus

/* ---------------------------------------------------------- UFastTravelStationDefinition ---------------------------------------------------------- */

typedef enum EFastTravelAccessibilityTime : unsigned char {
  FTAT_Always,                    // 0
  FTAT_Halloween,                 // 1
  FTAT_Thanksgiving,              // 2
  FTAT_Christmas,                 // 3
  FTAT_MAX                        // 4
} EFastTravelAccessibilityTime;
#define EFastTravelAccessibilityTime  EFastTravelAccessibilityTime
_DECL_TARRAY(EFastTravelAccessibilityTime);

/* ---------------------------------------------------------- UWillowGFxUIManagerDefinition ---------------------------------------------------------- */

typedef enum EUILayout : unsigned char {
  UILAYOUT_16x9,                  // 0
  _UILAYOUT_16x9,                  // 1
  UILAYOUT_16x9_1,                // 2
  UILAYOUT_4x3,                   // 3
  _UILAYOUT_4x3,                   // 4
  UILAYOUT_4x3_1 = 5,                 // 5
  UILAYOUT_MAX                    // 6
#define EUILayout__MAX  (UILAYOUT_MAX)
} EUILayout;
#define EUILayout  EUILayout

/* ---------------------------------------------------------- UWillowUIInteraction ---------------------------------------------------------- */

typedef enum ETextHAlignment               : unsigned char {
  HALIGN_FixedPos,                // 0
  HALIGN_Left,                    // 1
  HALIGN_Center,                  // 2
  HALIGN_MAX                      // 3
} ETextHAlignment;
typedef enum ETextVAlignment               : unsigned char {
  VALIGN_FixedPos,                // 0
  VALIGN_Center,                  // 1
  VALIGN_Bottom,                  // 2
  VALIGN_MAX                      // 3
} ETextVAlignment;
typedef enum EItemTypeForUI                : unsigned char {
  ITEMUI_Armor,                   // 0
  ITEMUI_Item,                    // 1
  ITEMUI_Ammo,                    // 2
  ITEMUI_MAX                      // 3
} EItemTypeForUI;
typedef enum EFontSize                     : unsigned char {
  FONT_Medium,                    // 0
  FONT_Tiny,                      // 1
  FONT_Small,                     // 2
  FONT_Large,                     // 3
  FONT_MAX                        // 4
} EFontSize;
typedef enum EAttributeDebugSort           : unsigned char {
  ATTDEBUGSORT_NameUp,            // 0
  ATTDEBUGSORT_NameDn,            // 1
  ATTDEBUGSORT_MAX                // 2
} EAttributeDebugSort;
typedef enum EMemoryDetailsSortStyle       : unsigned char {
  MEMDETAILSORT_ResourceNameAToZ, // 0
  MEMDETAILSORT_ResourceNameZToA, // 1
  MEMDETAILSORT_SizeSmallToLarge, // 2
  MEMDETAILSORT_SizeLargeToSmall, // 3
  MEMDETAILSORT_CountHighToLow,   // 4
  MEMDETAILSORT_MAX               // 5
} EMemoryDetailsSortStyle;
typedef enum ENetworkActorChannelSortStyle : unsigned char {
  NETACTORSORT_ActorNameAToZ,     // 0
  NETACTORSORT_ActornameZToA,     // 1
  NETACTORSORT_CountHighToLow,    // 2
  NETACTORSORT_CountLowToHigh,    // 3
  NETACTORSORT_MAX                // 4
} ENetworkActorChannelSortStyle;
typedef enum EGearBuilderSortMode          : unsigned char {
  GBSM_None,                      // 0
  GBSM_WeightHighToLow,           // 1
  GBSM_WeightLowToHigh,           // 2
  GBSM_Invalid,                   // 3
  GBSM_MAX                        // 4
} EGearBuilderSortMode;
#define ETextHAlignment                ETextHAlignment
#define ETextVAlignment                ETextVAlignment
#define EItemTypeForUI                 EItemTypeForUI
#define EFontSize                      EFontSize
#define EAttributeDebugSort            EAttributeDebugSort
#define EMemoryDetailsSortStyle        EMemoryDetailsSortStyle
#define ENetworkActorChannelSortStyle  ENetworkActorChannelSortStyle
#define EGearBuilderSortMode           EGearBuilderSortMode

/* ---------------------------------------------------------- UIUsable ---------------------------------------------------------- */

typedef enum EUsabilityType : unsigned char {
  UT_Primary,                     // 0
  UT_Secondary,                   // 1
  UT_MAX                          // 2
} EUsabilityType;
#define EUsabilityType  EUsabilityType

/* ---------------------------------------------------------- UChallengeDefinition ---------------------------------------------------------- */

typedef enum EChallengeType : unsigned char {
  ECT_Stat,                       // 0
  ECT_LevelObject,                // 1
  ECT_DesignerTriggered,          // 2
  ECT_MAX                         // 3
} EChallengeType;
#define EChallengeType  EChallengeType

/* ---------------------------------------------------------- UGearboxDialogEventTag ---------------------------------------------------------- */

typedef enum EDialogEventMatchQuality : unsigned char {
  MQ_NoMatch,                     // 0
  MQ_Match,                       // 1
  MQ_ForceMatch,                  // 2
  MQ_MAX                          // 3
} EDialogEventMatchQuality;
#define EDialogEventMatchQuality  EDialogEventMatchQuality

/* ---------------------------------------------------------- ULANServerBrowserGFxMovie ---------------------------------------------------------- */

typedef enum ESortType      : unsigned char {
  SORT_PlayerCount,               // 0
  SORT_Name,                      // 1
  SORT_Level,                     // 2
  SORT_Mission,                   // 3
  SORT_Ping,                      // 4
  SORT_MAX                        // 5
} ESortType;
typedef enum ESortDirection : unsigned char {
  SORTDIR_Ascending,              // 0
  SORTDIR_Descending,             // 1
  SORTDIR_MAX                     // 2
} ESortDirection;
#define ESortType       ESortType
#define ESortDirection  ESortDirection

/* ---------------------------------------------------------- UPlayerClassDefinition ---------------------------------------------------------- */

typedef enum EPlayerClassAchievementUnlockType : unsigned char {
  PCAUT_PetKills,                 // 0
  PCAUT_TimeSpentInActionSkill,   // 1
  PCAUT_TargetedActionSkillImpacts,// 2
  PCAUT_MAX                       // 3
} EPlayerClassAchievementUnlockType;
#define EPlayerClassAchievementUnlockType  EPlayerClassAchievementUnlockType

/* ---------------------------------------------------------- UPlayerEventProviderDefinition ---------------------------------------------------------- */

typedef enum EPlayerEventMessage : unsigned char {
  PEM_KilledChampion,             // 0
  PEM_SkillKill,                  // 1
  PEM_KilledEnemy,                // 2
  PEM_KillStreak,                 // 3
  PEM_ChallengeCompleted,         // 4
  PEM_JoinedGame,                 // 5
  PEM_SeatSwap,                   // 6
  PEM_VehicleCatchAir,            // 7
  PEM_KilledEnemyVehicle,         // 8
  PEM_VehicleLowHealth,           // 9
  PEM_VehicleFlipped,             // 10
  PEM_RanOverEnemy,               // 11
  PEM_VehicleSpawn,               // 12
  PEM_CriticalHitKill,            // 13
  PEM_CriticalHit,                // 14
  PEM_OutOfAmmo,                  // 15
  PEM_Reloading,                  // 16
  PEM_RareWeaponEquipped,         // 17
  PEM_PlayerIdle,                 // 18
  PEM_PlayerDown,                 // 19
  PEM_Death,                      // 20
  PEM_DeathByFire,                // 21
  PEM_DeathByShock,               // 22
  PEM_EnemyDamaged,               // 23
  PEM_EnemyDamagedCritical,       // 24
  PEM_EnemyShieldDown,            // 25
  PEM_AchievedSecondWind,         // 26
  PEM_RevivingPlayer,             // 27
  PEM_MissionTurnedIn,            // 28
  PEM_IncomingChampion,           // 29
  PEM_MapOpen,                    // 30
  PEM_SkillPointToSpend,          // 31
  PEM_CompareItems,               // 32
  PEM_TravelBlocked,              // 33
  PEM_MAX                         // 34
} EPlayerEventMessage;
#define EPlayerEventMessage  EPlayerEventMessage

/* ---------------------------------------------------------- UCoordinatedEffectDefinition ---------------------------------------------------------- */

typedef enum ECoordinatedParticleScaleMode : unsigned char {
  CPSM_None,                      // 0
  CPSM_LargestAxis,               // 1
  CPSM_SmallestAxis,              // 2
  CPSM_HorizontalAxis,            // 3
  CPSM_VerticalAxis,              // 4
  CPSM_EachAxis,                  // 5
  CPSM_MAX                        // 6
} ECoordinatedParticleScaleMode;
#define ECoordinatedParticleScaleMode  ECoordinatedParticleScaleMode

/* ---------------------------------------------------------- UMissionDefinition ---------------------------------------------------------- */

typedef enum EDefendMission : unsigned char {
  EDM_None,                       // 0
  EDM_NoFail,                     // 1
  EDM_Failable,                   // 2
  EDM_MAX                         // 3
} EDefendMission;
#define EDefendMission  EDefendMission

/* ---------------------------------------------------------- UGFxTextListContainer ---------------------------------------------------------- */

typedef enum ETextListMoveDir : unsigned char {
  TLMD_Up,                        // 0
  TLMD_Down,                      // 1
  TLMD_PageUp,                    // 2
  TLMD_PageDown,                  // 3
  TLMD_First,                     // 4
  TLMD_Last,                      // 5
  TLMD_PreviousCategory,          // 6
  TLMD_NextCategory,              // 7
  TLMD_MAX                        // 8
} ETextListMoveDir;
typedef enum EArrayKind       : unsigned char {
  EAK_Source,                     // 0
  EAK_Categories,                 // 1
  EAK_InvalidEntry,               // 2
  EAK_Unloadable,                 // 3
  EAK_MAX                         // 4
} EArrayKind;
#define ETextListMoveDir  ETextListMoveDir
#define EArrayKind        EArrayKind

/* ---------------------------------------------------------- UIMission ---------------------------------------------------------- */

typedef enum EMissionStatus             : unsigned char {
  MS_NotStarted,                  // 0
  MS_Active,                      // 1
  MS_RequiredObjectivesComplete,  // 2
  MS_ReadyToTurnIn,               // 3
  MS_Complete,                    // 4
  MS_Failed,                      // 5
  MS_MAX                          // 6
} EMissionStatus;
typedef enum EMissionReaction           : unsigned char {
  MR_NotStarted,                  // 0
  MR_Active,                      // 1
  MR_ReadyToTurnIn,               // 2
  MR_Complete,                    // 3
  MR_MAX                          // 4
} EMissionReaction;
typedef enum EObjectiveDependencyStatus : unsigned char {
  EODS_Complete,                  // 0
  EODS_Active,                    // 1
  EODS_MAX                        // 2
} EObjectiveDependencyStatus;
typedef enum EMissionEvent              : unsigned char {
  ME_LevelLoad,                   // 0
  ME_StatusChanged,               // 1
  ME_ObjectiveSetChanged,         // 2
  ME_ObjectiveUpdated,            // 3
  ME_ObjectiveCleared,            // 4
  ME_ObjectiveComplete,           // 5
  ME_ActiveMission,               // 6
  ME_NoLongerActiveMission,       // 7
  ME_MAX                          // 8
} EMissionEvent;
#define EMissionStatus              EMissionStatus
#define EMissionReaction            EMissionReaction
#define EObjectiveDependencyStatus  EObjectiveDependencyStatus
#define EMissionEvent               EMissionEvent

/* ---------------------------------------------------------- UIMissionDirector ---------------------------------------------------------- */

typedef enum EMissionBranchEnding : unsigned char {
  EMBE_None,                      // 0
  EMBE_PathA,                     // 1
  EMBE_PathB,                     // 2
  EMBE_MAX                        // 3
} EMissionBranchEnding;
#define EMissionBranchEnding  EMissionBranchEnding

/* ---------------------------------------------------------- UHUDWidget_WorldSpace ---------------------------------------------------------- */

typedef enum EPlayerIconState : unsigned char {
  EPIS_Normal,                    // 0
  EPIS_Injured,                   // 1
  EPIS_Reviving,                  // 2
  EPIS_MAX                        // 3
} EPlayerIconState;
#define EPlayerIconState  EPlayerIconState

/* ---------------------------------------------------------- UHUDWidget_Missions ---------------------------------------------------------- */

typedef enum EMissionWidgetMessageType     : unsigned char {
  EMWT_None,                      // 0
  EMWT_Init,                      // 1
  EMWT_SetMission,                // 2
  EMWT_AddObjective,              // 3
  EMWT_RemoveObjective,           // 4
  EMWT_SwapInObjective,           // 5
  EMWT_SwapOutObjective,          // 6
  EMWT_CompleteObjective,         // 7
  EMWT_ClearObjective,            // 8
  EMWT_UpdateObjectiveCount,      // 9
  EMWT_EnableTurnIn,              // 10
  EMWT_EnableOr,                  // 11
  EMWT_EnableFailed,              // 12
  EMWT_EnableTimer,               // 13
  EMWT_TickTimer,                 // 14
  EMWT_EnableDefense,             // 15
  EMWT_TickDefense,               // 16
  EMWT_FlyingCheckmark,           // 17
  EMWT_MAX                        // 18
} EMissionWidgetMessageType;
typedef enum EMissionWidgetMessageCategory : unsigned char {
  EMWC_None,                      // 0
  EMWC_Init,                      // 1
  EMWC_PreComplete,               // 2
  EMWC_Complete,                  // 3
  EMWC_Remove,                    // 4
  EMWC_Add,                       // 5
  EMWC_MAX                        // 6
} EMissionWidgetMessageCategory;
#define EMissionWidgetMessageType      EMissionWidgetMessageType
#define EMissionWidgetMessageCategory  EMissionWidgetMessageCategory

/* ---------------------------------------------------------- UWillowDialogNameTag ---------------------------------------------------------- */

typedef enum EchoPortraitType : unsigned char {
  ECHO_PORTRAIT_Scaleform,        // 0
  ECHO_PORTRAIT_Video,            // 1
  ECHO_PORTRAIT_MAX               // 2
} EchoPortraitType;
#define EchoPortraitType  EchoPortraitType

/* ---------------------------------------------------------- UExperienceResourcePool ---------------------------------------------------------- */

typedef enum EExperienceType : unsigned char {
  EXPERIENCE_Generic,             // 0
  EXPERIENCE_Combat,              // 1
  EXPERIENCE_Mission,             // 2
  EXPERIENCE_MAX                  // 3
} EExperienceType;
#define EExperienceType  EExperienceType

/* ---------------------------------------------------------- AWillowGameReplicationInfo ---------------------------------------------------------- */

typedef enum EMatchmakingState : unsigned char {
  MMS_Inactive,                   // 0
  MMS_Searching1,                 // 1
  MMS_Searching2,                 // 2
  MMS_Searching3,                 // 3
  MMS_MatchFound,                 // 4
  MMS_NoMatchFound,               // 5
  MMS_MAX                         // 6
} EMatchmakingState;
#define EMatchmakingState  EMatchmakingState

/* ---------------------------------------------------------- AMissionTracker ---------------------------------------------------------- */

typedef enum EAdvanceTrackedMissionResult : unsigned char {
  ATMR_Success,                   // 0
  ATMR_NothingToDo,               // 1
  ATMR_Error,                     // 2
  ATMR_DidNotAdvanceObjectiveSet, // 3
  ATMR_MAX                        // 4
} EAdvanceTrackedMissionResult;
#define EAdvanceTrackedMissionResult  EAdvanceTrackedMissionResult

/* ---------------------------------------------------------- UWillowPlayerInput ---------------------------------------------------------- */

typedef enum EButtonState : unsigned char {
  BUTTON_STATE_Pressed,           // 0
  BUTTON_STATE_Held,              // 1
  BUTTON_STATE_Released,          // 2
  BUTTON_STATE_Cleared,           // 3
  BUTTON_STATE_MAX                // 4
} EButtonState;
#define EButtonState  EButtonState

/* ---------------------------------------------------------- UInputDeviceDefinition ---------------------------------------------------------- */

typedef enum EAxisParameter : unsigned char {
  AXIS_PARAM_aBaseX,              // 0
  AXIS_PARAM_aBaseY,              // 1
  AXIS_PARAM_aBaseZ,              // 2
  AXIS_PARAM_aMouseX,             // 3
  AXIS_PARAM_aMouseY,             // 4
  AXIS_PARAM_aForward,            // 5
  AXIS_PARAM_aTurn,               // 6
  AXIS_PARAM_aStrafe,             // 7
  AXIS_PARAM_aUp,                 // 8
  AXIS_PARAM_aLookUp,             // 9
  AXIS_PARAM_aPS3AccelX,          // 10
  AXIS_PARAM_aPS3AccelY,          // 11
  AXIS_PARAM_aPS3AccelZ,          // 12
  AXIS_PARAM_aPS3Gyro,            // 13
  AXIS_PARAM_MAX                  // 14
} EAxisParameter;
#define EAxisParameter  EAxisParameter

/* ---------------------------------------------------------- UInputActionDefinition ---------------------------------------------------------- */

typedef enum EInputActionEvent : unsigned char {
  INPUT_ACTION_Begin,             // 0
  INPUT_ACTION_End,               // 1
  INPUT_ACTION_MAX                // 2
} EInputActionEvent;
#define EInputActionEvent  EInputActionEvent

/* ---------------------------------------------------------- UTextureMovie ---------------------------------------------------------- */

typedef enum EMovieStreamSource : unsigned char {
  MovieStream_File,               // 0
  MovieStream_Memory,             // 1
  MovieStream_MAX                 // 2
} EMovieStreamSource;
#define EMovieStreamSource  EMovieStreamSource

/* ---------------------------------------------------------- UAIDebugCamera ---------------------------------------------------------- */

typedef enum EDebugItemType  : unsigned char {
  DEBUGITEM_String,               // 0
  DEBUGITEM_StringSpacer,         // 1
  DEBUGITEM_ScreenIcon,           // 2
  DEBUGITEM_WorldString,          // 3
  DEBUGITEM_Icon,                 // 4
  DEBUGITEM_Line,                 // 5
  DEBUGITEM_Box,                  // 6
  DEBUGITEM_Circle,               // 7
  DEBUGITEM_Cone,                 // 8
  DEBUGITEM_BarGraphScreenTop,    // 9
  DEBUGITEM_BarGraphScreenTopTitle,// 10
  DEBUGITEM_BarGraphScreenCenter, // 11
  DEBUGITEM_BarGraphScreenCenterTitle,// 12
  DEBUGITEM_MAX                   // 13
} EDebugItemType;
typedef enum EDebugAlignment : unsigned char {
  DEBUGALIGN_Left,                // 0
  DEBUGALIGN_Center,              // 1
  DEBUGALIGN_Right,               // 2
  DEBUGALIGN_LeftNoWrap,          // 3
  DEBUGALIGN_LeftColumn2,         // 4
  DEBUGALIGN_LeftColumn2NoWrap,   // 5
  DEBUGALIGN_MAX                  // 6
} EDebugAlignment;
#define EDebugItemType   EDebugItemType
#define EDebugAlignment  EDebugAlignment

/* ---------------------------------------------------------- APylon ---------------------------------------------------------- */

typedef enum ENavMeshEdgeType : unsigned char {
  NAVEDGE_Normal,                 // 0
  NAVEDGE_Mantle,                 // 1
  NAVEDGE_Coverslip,              // 2
  NAVEDGE_SwatTurn,               // 3
  NAVEDGE_DropDown,               // 4
  NAVEDGE_PathObject,             // 5
  NAVEDGE_BackRefDummy,           // 6
  NAVEDGE_Jump,                   // 7
  NAVEDGE_MAX                     // 8
} ENavMeshEdgeType;
#define ENavMeshEdgeType  ENavMeshEdgeType

/* ---------------------------------------------------------- UTargetableList ---------------------------------------------------------- */

typedef enum ETargetableListSearchType : unsigned char {
  TL_Enemy,                       // 0
  TL_Friendly,                    // 1
  TL_Neutral,                     // 2
  TL_All,                         // 3
  TL_MAX                          // 4
} ETargetableListSearchType;
#define ETargetableListSearchType  ETargetableListSearchType

/* ---------------------------------------------------------- UPersistentGameDataManager ---------------------------------------------------------- */

typedef enum EPersistentOperation : unsigned char {
  PO_Saving,                      // 0
  PO_Restoring,                   // 1
  PO_MAX                          // 2
} EPersistentOperation;
#define EPersistentOperation  EPersistentOperation

/* ---------------------------------------------------------- UScene ---------------------------------------------------------- */

typedef enum ESceneDepthPriorityGroup : unsigned char {
  SDPG_UnrealEdBackground,        // 0
  SDPG_World,                     // 1
  SDPG_Foreground,                // 2
  SDPG_UnrealEdForeground,        // 3
  SDPG_PostProcess,               // 4
  SDPG_WorldPreAlphaPostProcess,  // 5
  SDPG_AfterPostProcess,          // 6
  SDPG_MAX                        // 7
} ESceneDepthPriorityGroup;
typedef enum EDetailMode : unsigned char {
  DM_Low,                         // 0
  DM_Medium,                      // 1
  DM_High,                        // 2
  DM_MAX                          // 3
} EDetailMode;
#define ESceneDepthPriorityGroup  ESceneDepthPriorityGroup
#define EDetailMode               EDetailMode

/* ---------------------------------------------------------- URule ---------------------------------------------------------- */

typedef enum EFlagEvalType        : unsigned char {
  FLAG_IsTrue,                    // 0
  FLAG_IsFalse,                   // 1
  FLAG_HasBeenTrueForXSeconds,    // 2
  FLAG_HasBeenFalseForXSeconds,   // 3
  FLAG_MAX                        // 4
} EFlagEvalType;
typedef enum ExecutionPatternType : unsigned char {
  RULEEXEC_Normal,                // 0
  RULEEXEC_Limited,               // 1
  RULEEXEC_MAX                    // 2
} ExecutionPatternType;
#define EFlagEvalType         EFlagEvalType
#define ExecutionPatternType  ExecutionPatternType

/* ---------------------------------------------------------- UGearboxEditorNode ---------------------------------------------------------- */

typedef enum NodeType : unsigned char {
  NT_Event,                       // 0
  NT_Action,                      // 1
  NT_Variable,                    // 2
  NT_MAX                          // 3
} NodeType;
#define NodeType  NodeType

/* ---------------------------------------------------------- AWillowRadarManager ---------------------------------------------------------- */

typedef enum ERadarIconType : unsigned char {
  RadarIconType_None,             // 0
  RadarIconType_Gunfire,          // 1
  RadarIconType_Threat,           // 2
  RadarIconType_BountyBoard,      // 3
  RadarIconType_Shop,             // 4
  RadarIconType_Health,           // 5
  RadarIconType_NewU,             // 6
  RadarIconType_CatchARide,       // 7
  RadarIconType_Settlement,       // 8
  RadarIconType_MissionNPC,       // 9
  RadarIconType_NamedNPC,         // 10
  RadarIconType_Loot,             // 11
  RadarIconType_Objective,        // 12
  RadarIconType_Checkpoint,       // 13
  RadarIconType_TravelStation,    // 14
  RadarIconType_CustomizationStation,// 15
  RadarIconType_LevelTransition,  // 16
  RadarIconType_MAX               // 17
#define ERadarIconType__MAX  (RadarIconType_MAX)
} ERadarIconType;
#define ERadarIconType  ERadarIconType

/* ---------------------------------------------------------- UUIDataProvider_MenuItem ---------------------------------------------------------- */

typedef enum EMenuOptionType : unsigned char {
  MENUOT_ComboReadOnly,           // 0
  MENUOT_ComboNumeric,            // 1
  MENUOT_CheckBox,                // 2
  MENUOT_Slider,                  // 3
  MENUOT_Spinner,                 // 4
  MENUOT_EditBox,                 // 5
  MENUOT_CollectionCheckBox,      // 6
  MENUOT_CollapsingList,          // 7
  MENUOT_MAX                      // 8
} EMenuOptionType;
#define EMenuOptionType  EMenuOptionType

/* ---------------------------------------------------------- UBehaviorKernel ---------------------------------------------------------- */

typedef enum EBehaviorProcessState : unsigned char {
  BPROCESS_Uninitialized,         // 0
  BPROCESS_Terminated,            // 1
  BPROCESS_Running,               // 2
  BPROCESS_Suspended,             // 3
  BPROCESS_MAX                    // 4
} EBehaviorProcessState;
typedef enum EBehaviorThreadState  : unsigned char {
  BTHREAD_Waiting,                // 0
  BTHREAD_Running,                // 1
  BTHREAD_Terminated,             // 2
  BTHREAD_Unknown,                // 3
  BTHREAD_MAX                     // 4
} EBehaviorThreadState;
#define EBehaviorProcessState  EBehaviorProcessState
#define EBehaviorThreadState   EBehaviorThreadState

/* ---------------------------------------------------------- UCombatMusicManager ---------------------------------------------------------- */

typedef enum ECombatMusicManagerState : unsigned char {
  CMMS_Playing,                   // 0
  CMMS_VolumeFading,              // 1
  CMMS_Idle,                      // 2
  CMMS_MAX                        // 3
} ECombatMusicManagerState;
#define ECombatMusicManagerState  ECombatMusicManagerState

/* ---------------------------------------------------------- UTargetIterator ---------------------------------------------------------- */

typedef enum ETargetIterator : unsigned char {
  TARGITER_UpdateState,           // 0
  TARGITER_PriorityCalc,          // 1
  TARGITER_ForgetTarget,          // 2
  TARGITER_RemoveTarget,          // 3
  TARGITER_PostProcess,           // 4
  TARGITER_MAX                    // 5
} ETargetIterator;
#define ETargetIterator  ETargetIterator

/* ---------------------------------------------------------- UKnowledgeRecord ---------------------------------------------------------- */

typedef enum KDBCategory : unsigned char {
  KDB_None,                       // 0
  KDB_Standard,                   // 1
  KDB_MAX                         // 2
} KDBCategory;
typedef enum KDBEvalType : unsigned char {
  Eval_Poll,                      // 0
  Eval_TargetIterator,            // 1
  Eval_MAX                        // 2
} KDBEvalType;
#define KDBCategory  KDBCategory
#define KDBEvalType  KDBEvalType

/* ---------------------------------------------------------- UAITracker ---------------------------------------------------------- */

typedef enum ESnapshotEventType : unsigned char {
  SNAP_NoEvent,                   // 0
  SNAP_ChildSequenceStart,        // 1
  SNAP_RuleStart,                 // 2
  SNAP_RuleEnd,                   // 3
  SNAP_RuleInterrupt,             // 4
  SNAP_SwitchRuleSet,             // 5
  SNAP_PreventNewRules,           // 6
  SNAP_MAX                        // 7
} ESnapshotEventType;
#define ESnapshotEventType  ESnapshotEventType

/* ---------------------------------------------------------- UAwarenessZoneDefinition ---------------------------------------------------------- */

typedef enum EViewConeStyle           : unsigned char {
  VIEWCONE_UseSightBone,          // 0
  VIEWCONE_UsePawnRotation,       // 1
  VIEWCONE_MAX                    // 2
} EViewConeStyle;
typedef enum ESpecialExposureBehavior : unsigned char {
  EXPOSUREBEHAVIOR_Normal,        // 0
  EXPOSUREBEHAVIOR_AlwaysSeeThreats,// 1
  EXPOSUREBEHAVIOR_NeverSeeThreats,// 2
  EXPOSUREBEHAVIOR_MAX            // 3
} ESpecialExposureBehavior;
typedef enum EHearingBehavior         : unsigned char {
  HEARINGBEHAVIOR_NeverHear,      // 0
  HEARINGBEHAVIOR_HearIfExposed,  // 1
  HEARINGBEHAVIOR_AlwaysHear,     // 2
  HEARINGBEHAVIOR_MAX             // 3
} EHearingBehavior;
#define EViewConeStyle            EViewConeStyle
#define ESpecialExposureBehavior  ESpecialExposureBehavior
#define EHearingBehavior          EHearingBehavior

/* ---------------------------------------------------------- UOnlineAuthInterfaceBaseImpl ---------------------------------------------------------- */

typedef enum EAuthStatus : unsigned char {
  AUS_NotStarted,                 // 0
  AUS_Pending,                    // 1
  AUS_Authenticated,              // 2
  AUS_Failed,                     // 3
  AUS_MAX                         // 4
} EAuthStatus;
#define EAuthStatus  EAuthStatus

/* ---------------------------------------------------------- UVendingMachineExGFxMovie ---------------------------------------------------------- */

typedef enum EShopMode : unsigned char {
  SHOPMODE_Sell,                  // 0
  SHOPMODE_Buy,                   // 1
  SHOPMODE_BuyBack,               // 2
  SHOPMODE_MAX                    // 3
} EShopMode;
#define EShopMode  EShopMode

/* ---------------------------------------------------------- UIShop ---------------------------------------------------------- */

typedef enum ETransactionStatus : unsigned char {
  TS_TransactionInProgress,       // 0
  TS_TransactionComplete,         // 1
  TS_TransactionFailed,           // 2
  TS_MAX                          // 3
} ETransactionStatus;
typedef enum EShopItemStatus    : unsigned char {
  SIS_ItemCanBePurchased,         // 0
  SIS_NotEnoughRoomForItem,       // 1
  SIS_PlayerCannotAffordItem,     // 2
  SIS_PlayerCannotUseItem,        // 3
  SIS_InvalidItem,                // 4
  SIS_MAX                         // 5
} EShopItemStatus;
typedef enum EShopType          : unsigned char {
  SType_Weapons,                  // 0
  SType_Items,                    // 1
  SType_Health,                   // 2
  SType_BlackMarket,              // 3
  SType_MAX                       // 4
} EShopType;
#define ETransactionStatus  ETransactionStatus
#define EShopItemStatus     EShopItemStatus
#define EShopType           EShopType

/* ---------------------------------------------------------- UGFxActorMoviePool ---------------------------------------------------------- */

typedef enum EGFxMoviePooling : unsigned char {
  GMP_Pooled,                     // 0
  GMP_Shared,                     // 1
  GMP_Instanced,                  // 2
  GMP_MAX                         // 3
} EGFxMoviePooling;
#define EGFxMoviePooling  EGFxMoviePooling

/* ---------------------------------------------------------- UCameraShake ---------------------------------------------------------- */

typedef enum EInitialOscillatorOffset : unsigned char {
  EOO_OffsetRandom,               // 0
  EOO_OffsetZero,                 // 1
  EOO_MAX                         // 2
} EInitialOscillatorOffset;
#define EInitialOscillatorOffset  EInitialOscillatorOffset

/* ---------------------------------------------------------- UDeveloperPerksDefinition ---------------------------------------------------------- */

typedef enum EGamerPic                : unsigned char {
  GAMERPIC_Min,                   // 0
  GAMERPIC_MAX                    // 1
} EGamerPic;
typedef enum EDeveloperPerksPlatforms : unsigned char {
  DPP_PC,                         // 0
  DPP_360,                        // 1
  DPP_PS3,                        // 2
  DPP_Any,                        // 3
  DPP_MAX                         // 4
} EDeveloperPerksPlatforms;
#define EGamerPic                 EGamerPic
#define EDeveloperPerksPlatforms  EDeveloperPerksPlatforms
_DECL_TARRAY(EGamerPic);

/* ---------------------------------------------------------- UAnimNodeSpecialMoveBlend ---------------------------------------------------------- */

typedef enum EAnimState : unsigned char {
  EAnimState_None,                // 0
  EAnimState_Playing,             // 1
  EAnimState_Finished,            // 2
  EAnimState_BlendingOut,         // 3
  EAnimState_MAX                  // 4
} EAnimState;
#define EAnimState  EAnimState

/* ---------------------------------------------------------- UChallengesPanelGFxObject ---------------------------------------------------------- */

typedef enum EChallengePanelSortMode : unsigned char {
  ECPSM_Category,                 // 0
  ECPSM_LevelCompletion,          // 1
  ECPSM_Max                       // 2
} EChallengePanelSortMode;
#define EChallengePanelSortMode  EChallengePanelSortMode

/* ---------------------------------------------------------- UStanceTypeDefinition ---------------------------------------------------------- */

typedef enum EMoveStyle     : unsigned char {
  MOVE_Strafe,                    // 0
  MOVE_Forward,                   // 1
  MOVE_MAX                        // 2
} EMoveStyle;
typedef enum EDefaultStance : unsigned char {
  STANCE_Patrol,                  // 0
  STANCE_Run,                     // 1
  STANCE_Sprint,                  // 2
  STANCE_Injured,                 // 3
  STANCE_None,                    // 4
  STANCE_Crouch,                  // 5
  STANCE_MAX                      // 6
} EDefaultStance;
#define EMoveStyle      EMoveStyle
#define EDefaultStance  EDefaultStance

/* ---------------------------------------------------------- UGearboxAnimDefinition ---------------------------------------------------------- */

typedef enum EEndingCondition : unsigned char {
  EC_StopOnLastFrame,             // 0
  EC_OnAnimEnd,                   // 1
  EC_OnBlendOut,                  // 2
  EC_Loop,                        // 3
  EC_MAX                          // 4
} EEndingCondition;
#define EEndingCondition  EEndingCondition

/* ---------------------------------------------------------- USkillTreeGFxObject ---------------------------------------------------------- */

typedef enum ESkillIconState         : unsigned char {
  eSIS_Disabled,                  // 0
  eSIS_Enabled,                   // 1
  eSIS_Partial,                   // 2
  eSIS_Maxed,                     // 3
  eSIS_MAX                        // 4
} ESkillIconState;
typedef enum ESkillTreeFailureReason : unsigned char {
  eFR_NoSkillPoints,              // 0
  eFR_SkillLocked,                // 1
  eFR_SkillMaxed,                 // 2
  eFR_DataIssue,                  // 3
  eFR_NoFailure,                  // 4
  eFR_MAX                         // 5
} ESkillTreeFailureReason;
typedef enum ENavDirection           : unsigned char {
  EN_Up,                          // 0
  EN_Down,                        // 1
  EN_Left,                        // 2
  EN_Right,                       // 3
  EN_None,                        // 4
  EN_MAX                          // 5
} ENavDirection;
#define ESkillIconState          ESkillIconState
#define ESkillTreeFailureReason  ESkillTreeFailureReason
#define ENavDirection            ENavDirection

/* ---------------------------------------------------------- UChallengesScreenGFxObject ---------------------------------------------------------- */

typedef enum EChallengePanel : unsigned char {
  ECP_Badass,                     // 0
  ECP_Challenges,                 // 1
  ECP_MAX                         // 2
} EChallengePanel;
#define EChallengePanel  EChallengePanel

/* ---------------------------------------------------------- UBodyWeaponHoldDefinition ---------------------------------------------------------- */

typedef enum EBodyWeaponAction        : unsigned char  {
  BWA_Fire,                       // 0
  BWA_FireRecoil,                 // 1
  BWA_Melee,                      // 2
  BWA_Reload,                     // 3
  BWA_Equip,                      // 4
  BWA_PutDown,                    // 5
  BWA_PutDownSwap,                // 6
  BWA_ThrowGrenade,               // 7
  BWA_GrabEquip,                  // 8
  BWA_MeleeSelf,                  // 9
  BWA_MAX                         // 10
} EBodyWeaponAction;
typedef enum EBodyWeaponActionPosture : unsigned char  {
  BWAP_All,                       // 0
  BWAP_Standing,                  // 1
  BWAP_Crouched,                  // 2
  BWAP_Injured,                   // 3
  BWAP_MAX                        // 4
} EBodyWeaponActionPosture;
#define EBodyWeaponAction         EBodyWeaponAction
#define EBodyWeaponActionPosture  EBodyWeaponActionPosture

/* ---------------------------------------------------------- UDOFAndBloomEffect ---------------------------------------------------------- */

typedef enum EDOFType    : unsigned char  {
  DOFType_SimpleDOF,              // 0
  DOFType_ReferenceDOF,           // 1
  DOFType_BokehDOF,               // 2
  DOFType_MAX                     // 3
} EDOFType;
typedef enum EDOFQuality : unsigned char  {
  DOFQuality_Low,                 // 0
  DOFQuality_Medium,              // 1
  DOFQuality_High,                // 2
  DOFQuality_MAX                  // 3
} EDOFQuality;
#define EDOFType     EDOFType
#define EDOFQuality  EDOFQuality

/* ---------------------------------------------------------- UUberPostProcessEffect ---------------------------------------------------------- */

typedef enum ETonemapperType : unsigned char {
  Tonemapper_Off,                 // 0
  Tonemapper_Filmic,              // 1
  Tonemapper_Customizable,        // 2
  Tonemapper_MAX                  // 3
} ETonemapperType;
#define ETonemapperType  ETonemapperType

/* ---------------------------------------------------------- AWillowTradeManager ---------------------------------------------------------- */

typedef enum TradeManagerStatus  : unsigned char {
  TMS_Uninitialized,              // 0
  TMS_OutgoingRequestPending,     // 1
  TMS_IncomingRequestPending,     // 2
  TMS_Trading,                    // 3
  TMS_Dueling,                    // 4
  TMS_ResolvingTrade,             // 5
  TMS_ResolvingDuelWon,           // 6
  TMS_ResolvingDuelLost,          // 7
  TMS_MAX                         // 8
} TradeManagerStatus;
typedef enum TradeManagerReason  : unsigned char {
  TMR_PlayerBusy,                 // 0
  TMR_PlayerOutOfRange,           // 1
  TMR_PlayerRequestRefusedSelf,   // 2
  TMR_PlayerRequestRefusedPartner,// 3
  TMR_PlayerRequestWithdrawnSelf, // 4
  TMR_PlayerRequestWithdrawnPartner,// 5
  TMR_RedundantRequest,           // 6
  TMR_TradingDisabled,            // 7
  TMR_CanceledBySelf,             // 8
  TMR_CanceledByPartner,          // 9
  TMR_TradeCompleteSuccessfully,  // 10
  TMR_DuelWon,                    // 11
  TMR_DuelLost,                   // 12
  TMR_DuelDraw,                   // 13
  TMR_TradeCanceled,              // 14
  TMR_MAX                         // 15
} TradeManagerReason;
typedef enum PlayerTradingStance : unsigned char {
  PTS_Deciding,                   // 0
  PTS_TradeReady,                 // 1
  PTS_DuelReady,                  // 2
  PTS_Disconnected,               // 3
  PTS_MAX                         // 4
} PlayerTradingStance;
typedef enum TradeSlotStatus     : unsigned char {
  TSS_Empty,                      // 0
  TSS_Item,                       // 1
  TSS_Weapon,                     // 2
  TSS_MAX                         // 3
} TradeSlotStatus;
#define TradeManagerStatus   TradeManagerStatus
#define TradeManagerReason   TradeManagerReason
#define PlayerTradingStance  PlayerTradingStance
#define TradeSlotStatus      TradeSlotStatus

/* ---------------------------------------------------------- USkelControlBase ---------------------------------------------------------- */

typedef enum EBoneControlSpace : unsigned char {
  BCS_WorldSpace,                 // 0
  BCS_ActorSpace,                 // 1
  BCS_ComponentSpace,             // 2
  BCS_ParentBoneSpace,            // 3
  BCS_BoneSpace,                  // 4
  BCS_OtherBoneSpace,             // 5
  BCS_BaseMeshSpace,              // 6
  BCS_SocketSpace,                // 7
  BCS_MAX                         // 8
} EBoneControlSpace;
#define EBoneControlSpace  EBoneControlSpace

/* ---------------------------------------------------------- UGbxMessageDefinition ---------------------------------------------------------- */

typedef enum EGbxMessageDupeStruct : unsigned char {
  GBXMSGDUPE_SameSender,          // 0
  GBXMSGDUPE_SameSubject,         // 1
  GBXMSGDUPE_SameNameData,        // 2
  GBXMSGDUPE_SameIntData,         // 3
  GBXMSGDUPE_SameFloatData,       // 4
  GBXMSGDUPE_SameMetaData1,       // 5
  GBXMSGDUPE_SameMetaData2,       // 6
  GBXMSGDUPE_SameMetaData3,       // 7
  GBXMSGDUPE_SameMetaData4,       // 8
  GBXMSGDUPE_MAX                  // 9
} EGbxMessageDupeStruct;
#define EGbxMessageDupeStruct  EGbxMessageDupeStruct
_DECL_TARRAY(EGbxMessageDupeStruct);

/* ---------------------------------------------------------- UShieldPartDefinition ---------------------------------------------------------- */

typedef enum EShieldPartType : unsigned char {
  SHIELD_PART_Body,               // 0
  SHIELD_PART_Battery,            // 1
  SHIELD_PART_Capacitor,          // 2
  SHIELD_PART_Property1,          // 3
  SHIELD_PART_Property2,          // 4
  SHIELD_PART_Property3,          // 5
  SHIELD_PART_Property4,          // 6
  SHIELD_PART_Accessory,          // 7
  SHIELD_PART_Material,           // 8
  SHIELD_PART_Prefix,             // 9
  SHIELD_PART_Title,              // 10
  SHIELD_PART_MAX                 // 11
} EShieldPartType;
#define EShieldPartType  EShieldPartType

/* ---------------------------------------------------------- AWillowAIMoveNode ---------------------------------------------------------- */

typedef enum EVehicleNodeType : unsigned char {
  VEHNODE_Patrol,                 // 0
  VEHNODE_ScriptedPath,           // 1
  VEHNODE_MAX                     // 2
} EVehicleNodeType;
#define EVehicleNodeType  EVehicleNodeType

/* ---------------------------------------------------------- APerch ---------------------------------------------------------- */

typedef enum EPerchAnimType : unsigned char {
  PAT_Start,                      // 0
  PAT_Idle,                       // 1
  PAT_Stop,                       // 2
  PAT_MAX                         // 3
} EPerchAnimType;
#define EPerchAnimType  EPerchAnimType

/* ---------------------------------------------------------- ULockoutDefinition ---------------------------------------------------------- */

typedef enum ELockoutStyle : unsigned char {
  LOCKOUT_Relative,               // 0
  LOCKOUT_NextDay,                // 1
  LOCKOUT_NextWeek,               // 2
  LOCKOUT_MAX                     // 3
} ELockoutStyle;
#define ELockoutStyle  ELockoutStyle

/* ---------------------------------------------------------- UBehavior_CauseDamage ---------------------------------------------------------- */

typedef enum EDamageTarget : unsigned char {
  DT_BehaviorContext,             // 0
  DT_OtherEventParticipant,       // 1
  DT_CustomTarget,                // 2
  DT_RadiusAroundContext,         // 3
  DT_MAX                          // 4
} EDamageTarget;
#define EDamageTarget  EDamageTarget

/* ---------------------------------------------------------- UPopulationMaster ---------------------------------------------------------- */

typedef enum EPopulationStats : unsigned char {
  STATTYPE_SpawnActor,            // 0
  STATTYPE_PointSearch,           // 1
  STATTYPE_MAX                    // 2
} EPopulationStats;
#define EPopulationStats  EPopulationStats

/* ---------------------------------------------------------- APopulationEncounter ---------------------------------------------------------- */

typedef enum EEncounterConstraintType : unsigned char {
  ENCOUNTERCONSTAINT_All,         // 0
  ENCOUNTERCONSTAINT_Any,         // 1
  ENCOUNTERCONSTAINT_NotAll,      // 2
  ENCOUNTERCONSTAINT_NotAny,      // 3
  ENCOUNTERCONSTAINT_MAX          // 4
} EEncounterConstraintType;
#define EEncounterConstraintType  EEncounterConstraintType

/* ---------------------------------------------------------- UDesignerAttributeDefinition ---------------------------------------------------------- */

typedef enum EDesignerAtttributeScope : unsigned char {
  DASCOPE_Global,                 // 0
  DASCOPE_Local,                  // 1
  DASCOPE_MAX                     // 2
} EDesignerAtttributeScope;
#define EDesignerAtttributeScope  EDesignerAtttributeScope

/* ---------------------------------------------------------- UWillowVersusDuelGlobals ---------------------------------------------------------- */

typedef enum EDuelMsg : unsigned char {
  DMSG_DUELINGDISABLED,           // 0
  DMSG_ALREADYDUELING,            // 1
  DMSG_ALREADYCHALLENGED,         // 2
  DMSG_DUELTIMEOUT,               // 3
  DMSG_ISSUEDCHALLENGE,           // 4
  DMSG_RECEIVEDCHALLENGE,         // 5
  DMSG_ACCEPTEDCHALLENGE,         // 6
  DMSG_DUELSTART,                 // 7
  DMSG_ARENAWARNING,              // 8
  DMSG_DUELDRAW,                  // 9
  DMSG_DUELWIN,                   // 10
  DMSG_NOTRIGHTNOW,               // 11
  DMSG_MAX                        // 12
} EDuelMsg;
#define EDuelMsg  EDuelMsg

/* ---------------------------------------------------------- USnapshotRecord ---------------------------------------------------------- */

static const int MaxContainedRules = 45;

/* ---------------------------------------------------------- UGameStateObject ---------------------------------------------------------- */

typedef enum GameSessionType : unsigned char {
  GT_SessionInvalid,              // 0
  GT_SinglePlayer,                // 1
  GT_Coop,                        // 2
  GT_Multiplayer,                 // 3
  GT_MAX                          // 4
} GameSessionType;
#define GameSessionType  GameSessionType

/* ---------------------------------------------------------- UMeshBeacon ---------------------------------------------------------- */

typedef enum EMeshBeaconPacketType          : unsigned char {
  MB_Packet_UnknownType,          // 0
  MB_Packet_ClientNewConnectionRequest,// 1
  MB_Packet_ClientBeginBandwidthTest,// 2
  MB_Packet_ClientCreateNewSessionResponse,// 3
  MB_Packet_HostNewConnectionResponse,// 4
  MB_Packet_HostBandwidthTestRequest,// 5
  MB_Packet_HostCompletedBandwidthTest,// 6
  MB_Packet_HostTravelRequest,    // 7
  MB_Packet_HostCreateNewSessionRequest,// 8
  MB_Packet_DummyData,            // 9
  MB_Packet_Heartbeat,            // 10
  MB_Packet_MAX                   // 11
} EMeshBeaconPacketType;
typedef enum EMeshBeaconConnectionResult    : unsigned char {
  MB_ConnectionResult_Succeeded,  // 0
  MB_ConnectionResult_Duplicate,  // 1
  MB_ConnectionResult_Timeout,    // 2
  MB_ConnectionResult_Error,      // 3
  MB_ConnectionResult_MAX         // 4
} EMeshBeaconConnectionResult;
typedef enum EMeshBeaconBandwidthTestState  : unsigned char {
  MB_BandwidthTestState_NotStarted,// 0
  MB_BandwidthTestState_RequestPending,// 1
  MB_BandwidthTestState_StartPending,// 2
  MB_BandwidthTestState_InProgress,// 3
  MB_BandwidthTestState_Completed,// 4
  MB_BandwidthTestState_Incomplete,// 5
  MB_BandwidthTestState_Timeout,  // 6
  MB_BandwidthTestState_Error,    // 7
  MB_BandwidthTestState_MAX       // 8
} EMeshBeaconBandwidthTestState;
typedef enum EMeshBeaconBandwidthTestResult : unsigned char {
  MB_BandwidthTestResult_Succeeded,// 0
  MB_BandwidthTestResult_Timeout, // 1
  MB_BandwidthTestResult_Error,   // 2
  MB_BandwidthTestResult_MAX      // 3
} EMeshBeaconBandwidthTestResult;
typedef enum EMeshBeaconBandwidthTestType   : unsigned char {
  MB_BandwidthTestType_Upstream,  // 0
  MB_BandwidthTestType_Downstream,// 1
  MB_BandwidthTestType_RoundtripLatency,// 2
  MB_BandwidthTestType_MAX        // 3
} EMeshBeaconBandwidthTestType;
#define EMeshBeaconPacketType           EMeshBeaconPacketType
#define EMeshBeaconConnectionResult     EMeshBeaconConnectionResult
#define EMeshBeaconBandwidthTestState   EMeshBeaconBandwidthTestState
#define EMeshBeaconBandwidthTestResult  EMeshBeaconBandwidthTestResult
#define EMeshBeaconBandwidthTestType    EMeshBeaconBandwidthTestType

/* ---------------------------------------------------------- UMeshBeaconClient ---------------------------------------------------------- */

typedef enum EMeshBeaconClientState : unsigned char {
  MBCS_None,                      // 0
  MBCS_Connecting,                // 1
  MBCS_Connected,                 // 2
  MBCS_ConnectionFailed,          // 3
  MBCS_AwaitingResponse,          // 4
  MBCS_Closed,                    // 5
  MBCS_MAX                        // 6
} EMeshBeaconClientState;
#define EMeshBeaconClientState  EMeshBeaconClientState

/* ---------------------------------------------------------- ARoute ---------------------------------------------------------- */

typedef enum ERouteFillAction : unsigned char {
  RFA_Overwrite,                  // 0
  RFA_Add,                        // 1
  RFA_Remove,                     // 2
  RFA_Clear,                      // 3
  RFA_MAX                         // 4
} ERouteFillAction;
typedef enum ERouteDirection  : unsigned char {
  ERD_Forward,                    // 0
  ERD_Reverse,                    // 1
  ERD_MAX                         // 2
} ERouteDirection;
typedef enum ERouteType       : unsigned char {
  ERT_Linear,                     // 0
  ERT_Loop,                       // 1
  ERT_Circle,                     // 2
  ERT_MAX                         // 3
} ERouteType;
#define ERouteFillAction  ERouteFillAction
#define ERouteDirection   ERouteDirection
#define ERouteType        ERouteType

/* ---------------------------------------------------------- UOnlineSubsystemSteamworks ---------------------------------------------------------- */

typedef enum ELeaderboardRequestType : unsigned char {
  LRT_Global,                     // 0
  LRT_Player,                     // 1
  LRT_Friends,                    // 2
  LRT_MAX                         // 3
} ELeaderboardRequestType;
typedef enum ELeaderboardSortType    : unsigned char {
  LST_Ascending,                  // 0
  LST_Descending,                 // 1
  LST_MAX                         // 2
} ELeaderboardSortType;
typedef enum ELeaderboardFormat      : unsigned char {
  LF_Number,                      // 0
  LF_Seconds,                     // 1
  LF_Milliseconds,                // 2
  LF_MAX                          // 3
} ELeaderboardFormat;
typedef enum ELeaderboardUpdateType  : unsigned char {
  LUT_KeepBest,                   // 0
  LUT_Force,                      // 1
  LUT_MAX                         // 2
} ELeaderboardUpdateType;
#define ELeaderboardRequestType  ELeaderboardRequestType
#define ELeaderboardSortType     ELeaderboardSortType
#define ELeaderboardFormat       ELeaderboardFormat
#define ELeaderboardUpdateType   ELeaderboardUpdateType

/* ---------------------------------------------------------- USparkTypes ---------------------------------------------------------- */

typedef enum EInitializedResult         : unsigned char {
  INITIALIZED_ValidWithAccount,   // 0
  INITIALIZED_ValidNoAccount,     // 1
  INITIALIZED_InProgress,         // 2
  INITIALIZED_NetworkFailure,     // 3
  INITIALIZED_PlatformFailure,    // 4
  INITIALIZED_NotValid,           // 5
  INITIALIZED_MAX                 // 6
} EInitializedResult;
typedef enum ESparkInitializationStatus : unsigned char {
  SPARKINIT_Uninitialized,        // 0
  SPARKINIT_TMSDownloaded,        // 1
  SPARKINIT_PendingAuthentication,// 2
  SPARKINIT_PendingVerification,  // 3
  SPARKINIT_VerificationComplete, // 4
  SPARKINIT_Initialized,          // 5
  SPARKINIT_Disabled,             // 6
  SPARKINIT_UnrecoverableError,   // 7
  SPARKINIT_MAX                   // 8
} ESparkInitializationStatus;
typedef enum ESparkStepResult           : unsigned char {
  STEP_Success,                   // 0
  STEP_Fail,                      // 1
  STEP_Async,                     // 2
  STEP_Disable,                   // 3
  STEP_Final,                     // 4
  STEP_MAX                        // 5
} ESparkStepResult;
typedef enum EHttpError                 : unsigned char {
  HE_Success,                     // 0
  HE_UnknownFailure,              // 1
  HE_Timeout,                     // 2
  HE_BadUrl,                      // 3
  HE_Connect,                     // 4
  HE_SendRequest,                 // 5
  HE_ReceiveResponse,             // 6
  HE_ReadResponse,                // 7
  HE_WriteData,                   // 8
  HE_HttpStatus,                  // 9
  HE_ServerCertificate,           // 10
  HE_MAX                          // 11
} EHttpError;
typedef enum EAgreementsSigning         : unsigned char {
  AGREEMENTS_Undefined,           // 0
  AGREEMENTS_NoAgreementsToSign,  // 1
  AGREEMENTS_AgreementsToSignPending,// 2
  AGREEMENTS_AgreementsToSignDeclined,// 3
  AGREEMENTS_MAX                  // 4
} EAgreementsSigning;
#define EInitializedResult          EInitializedResult
#define ESparkInitializationStatus  ESparkInitializationStatus
#define ESparkStepResult            ESparkStepResult
#define EHttpError                  EHttpError
#define EAgreementsSigning          EAgreementsSigning

/* ---------------------------------------------------------- UAIPawnBalanceDefinition ---------------------------------------------------------- */

typedef enum EAITransformed       : unsigned char {
  EAIT_None,                      // 0
  EAIT_Fire,                      // 1
  EAIT_Shock,                     // 2
  EAIT_Corrosive,                 // 3
  EAIT_Custom,                    // 4
  EAIT_Slagged,                   // 5
  EAIT_MAX                        // 6
} EAITransformed;
typedef enum EItemGameStageSource : unsigned char {
  IGSS_ExpLevelOfBalancedActor,   // 0
  IGSS_GameStageOfBalancedActor,  // 1
  IGSS_MAX                        // 2
} EItemGameStageSource;
#define EAITransformed        EAITransformed
#define EItemGameStageSource  EItemGameStageSource

/* ---------------------------------------------------------- APopulationPoint ---------------------------------------------------------- */

typedef enum EPopulationPointType   : unsigned char {
  POINT_Ambush,                   // 0
  POINT_PointOfInterest,          // 1
  POINT_Vehicle,                  // 2
  POINT_MAX                       // 3
} EPopulationPointType;
typedef enum EPopPointContraintType : unsigned char {
  POPOINTCONSTRAINT_None,         // 0
  POPOINTCONSTRAINT_Inclusion,    // 1
  POPOINTCONSTRAINT_Exclusion,    // 2
  POPOINTCONSTRAINT_InclusionOr,  // 3
  POPOINTCONSTRAINT_ExclusionOr,  // 4
  POPOINTCONSTRAINT_MAX           // 5
} EPopPointContraintType;
#define EPopulationPointType    EPopulationPointType 
#define EPopPointContraintType  EPopPointContraintType 

/* ---------------------------------------------------------- USoundNodeWave ---------------------------------------------------------- */

typedef enum EDecompressionType : unsigned char {
  DTYPE_Setup,                    // 0
  DTYPE_Invalid,                  // 1
  DTYPE_Preview,                  // 2
  DTYPE_Native,                   // 3
  DTYPE_RealTime,                 // 4
  DTYPE_Procedural,               // 5
  DTYPE_Xenon,                    // 6
  DTYPE_MAX                       // 7
} EDecompressionType;
#define EDecompressionType  EDecompressionType

/* ---------------------------------------------------------- USkill ---------------------------------------------------------- */

typedef enum EAdjustModifierMode : unsigned char {
  WILLOW_ADJUST_InitialAddModifer,// 0
  WILLOW_ADJUST_AddModifer,       // 1
  WILLOW_ADJUST_RemoveModifer,    // 2
  WILLOW_ADJUST_MAX               // 3
} EAdjustModifierMode;
typedef enum PawnListSource : unsigned char {
  PAWN_Teammate,                  // 0
  PAWN_Enemy,                     // 1
  PAWN_MAX                        // 2
} PawnListSource;
#define EAdjustModifierMode  EAdjustModifierMode
#define PawnListSource       PawnListSource

/* ---------------------------------------------------------- ACoverGroup ---------------------------------------------------------- */

typedef enum ECoverGroupFillAction : unsigned char {
  CGFA_Overwrite,                 // 0
  CGFA_Add,                       // 1
  CGFA_Remove,                    // 2
  CGFA_Clear,                     // 3
  CGFA_Cylinder,                  // 4
  CGFA_MAX                        // 5
} ECoverGroupFillAction;
#define ECoverGroupFillAction  ECoverGroupFillAction

/* ---------------------------------------------------------- NamedParameter ---------------------------------------------------------- */

/** A generic container for an event containing a named parameter list */
typedef enum ESupportedParamTypes {
	ESPT_FLOAT
	,ESPT_INT
	,ESPT_FVector
	,ESPT_FString
	,ESPT_NIL
} ESupportedParamTypes;
#define ESupportedParamTypes  ESupportedParamTypes

/* ---------------------------------------------------------- UPopulationDefinition ---------------------------------------------------------- */

typedef enum EPopulationRespawnOptions : unsigned char {
  POPRESPAWN_Never,               // 0
  POPRESPAWN_OnTimeDelay,         // 1
  POPRESPAWN_OnlyOnLevelLoad,     // 2
  POPRESPAWN_MAX                  // 3
} EPopulationRespawnOptions;
#define EPopulationRespawnOptions  EPopulationRespawnOptions

/* ---------------------------------------------------------- UIProjectileBehavior ---------------------------------------------------------- */

typedef enum EHomingTargetType      : unsigned char {
  HTARGET_None,                   // 0
  HTARGET_Instigator,             // 1
  HTARGET_ViewGuidePawn,          // 2
  HTARGET_ViewGuideLocation,      // 3
  HTARGET_NearestActor,           // 4
  HTARGET_NearestFriend,          // 5
  HTARGET_NearestFoe,             // 6
  HTARGET_NearestFriendNotInstigator,// 7
  HTARGET_MAX                     // 8
} EHomingTargetType;
typedef enum EProjectilePayloadType : unsigned char {
  PPT_Standard,                   // 0
  PPT_AreaEffect,                 // 1
  PPT_BouncingBetty,              // 2
  PPT_MIRV,                       // 3
  PPT_Singularity,                // 4
  PPT_TedioreReload,              // 5
  PPT_Transfusion,                // 6
  PPT_MAX                         // 7
} EProjectilePayloadType;
#define EHomingTargetType       EHomingTargetType
#define EProjectilePayloadType  EProjectilePayloadType

/* ---------------------------------------------------------- UGearboxRenderTextureManager ---------------------------------------------------------- */

typedef enum EThumbnailUpdate : unsigned char {
  Thumbnail_Static,               // 0
  Thumbnail_Update,               // 1
  Thumbnail_StreamTextures,       // 2
  Thumbnail_Dynamic,              // 3
  Thumbnail_MAX                   // 4
} EThumbnailUpdate;
#define EThumbnailUpdate  EThumbnailUpdate

/* ---------------------------------------------------------- UOnlineGameSearch ---------------------------------------------------------- */

typedef enum EOnlineGameSearchEntryType      : unsigned char {
  OGSET_Property,                 // 0
  OGSET_LocalizedSetting,         // 1
  OGSET_ObjectProperty,           // 2
  OGSET_MAX                       // 3
} EOnlineGameSearchEntryType;
typedef enum EOnlineGameSearchComparisonType : unsigned char {
  OGSCT_Equals,                   // 0
  OGSCT_NotEquals,                // 1
  OGSCT_GreaterThan,              // 2
  OGSCT_GreaterThanEquals,        // 3
  OGSCT_LessThan,                 // 4
  OGSCT_LessThanEquals,           // 5
  OGSCT_MAX                       // 6
} EOnlineGameSearchComparisonType;
typedef enum EOnlineGameSearchSortType       : unsigned char {
  OGSSO_Ascending,                // 0
  OGSSO_Descending,               // 1
  OGSSO_MAX                       // 2
} EOnlineGameSearchSortType;
#define EOnlineGameSearchEntryType       EOnlineGameSearchEntryType
#define EOnlineGameSearchComparisonType  EOnlineGameSearchComparisonType
#define EOnlineGameSearchSortType        EOnlineGameSearchSortType

/* ---------------------------------------------------------- UWillowPlayerPawnDataManager ---------------------------------------------------------- */

typedef enum DataRequestType : unsigned char {
  DRT_PlayerPawn,                 // 0
  DRT_SkillTreeDef,               // 1
  DRT_VehicleDef,                 // 2
  DRT_MAX                         // 3
} DataRequestType;
#define DataRequestType  DataRequestType

/* ---------------------------------------------------------- UGearLikenessMeshComponent ---------------------------------------------------------- */

typedef enum EGearLikenessSource : unsigned char {
  LOOKLIKE_Source,                // 0
  LOOKLIKE_MainWeapon,            // 1
  LOOKLIKE_OffhandWeapon,         // 2
  LOOKLIKE_EquippedShield,        // 3
  LOOKLIKE_EquippedGrenadeMod,    // 4
  LOOKLIKE_EquippedClassMod,      // 5
  LOOKLIKE_HolsteredSmallWeapon,  // 6
  LOOKLIKE_HolsteredMediumWeapon, // 7
  LOOKLIKE_HolsteredLargeWeapon,  // 8
  LOOKLIKE_HolsteredExtraLargeWeapon,// 9
  LOOKLIKE_MAX                    // 10
} EGearLikenessSource;
#define EGearLikenessSource  EGearLikenessSource

/* ---------------------------------------------------------- UIKilledBehavior ---------------------------------------------------------- */

typedef enum EScriptedKillType : unsigned char {
  KILL_Normal,                    // 0
  KILL_GibOnly,                   // 1
  KILL_TechOnly,                  // 2
  KILL_PreferTech,                // 3
  KILL_SpecialDeath1,             // 4
  KILL_SpecialDeath2,             // 5
  KILL_SpecialDeath3,             // 6
  KILL_MAX                        // 7
} EScriptedKillType;
#define EScriptedKillType  EScriptedKillType

/* ---------------------------------------------------------- UGlobalAttributeValueResolver ---------------------------------------------------------- */

typedef enum EGlobalAttributes : unsigned char {
  GATTR_ExperiencePointTestLevel, // 0
  GATTR_BadassTokenTestRank,      // 1
  GATTR_MAX                       // 2
} EGlobalAttributes;
#define EGlobalAttributes  EGlobalAttributes

/* ---------------------------------------------------------- UWillowSaveGameManager ---------------------------------------------------------- */

typedef enum ESaveVersionType : unsigned char {
  ESVT_File,                      // 0
  ESVT_Player,                    // 1
  ESVT_Graveyard,                 // 2
  ESVT_MAX                        // 3
  #define ESVT_File      ESVT_File
  #define ESVT_Player    ESVT_Player
  #define ESVT_Graveyard ESVT_Graveyard
  #define ESVT_MAX       ESVT_MAX
} ESaveVersionType;
typedef enum CPAsync : unsigned char {
  WORKRESULT_NONE,                // 0
  WORKRESULT_PENDING,             // 1
  WORKRESULT_SUCCESS,             // 2
  WORKRESULT_FAIL,                // 3
  WORKRESULT_FILENOTFOUND,        // 4
  WORKRESULT_MAX                  // 5
  #define WORKRESULT_NONE          WORKRESULT_NONE
  #define WORKRESULT_PENDING       WORKRESULT_PENDING
  #define WORKRESULT_SUCCESS       WORKRESULT_SUCCESS
  #define WORKRESULT_FAIL          WORKRESULT_FAIL
  #define WORKRESULT_FILENOTFOUND  WORKRESULT_FILENOTFOUND
  #define WORKRESULT_MAX           WORKRESULT_MAX
} CPAsync;
typedef enum ESaveGameManagerState : unsigned char {
  ESGMS_Idle,                     // 0
  ESGMS_Saving,                   // 1
  ESGMS_Deleting,                 // 2
  ESGMS_Loading,                  // 3
  ESGMS_ListLoading,              // 4
  ESGMS_LoadingWillowOneSave,     // 5
  ESGMS_SavingProfile,            // 6
  ESGMS_CountingCrossTitleSaveGames,// 7
  ESGMS_MAX                       // 8
  #define ESGMS_Idle                         ESGMS_Idle
  #define ESGMS_Saving                       ESGMS_Saving
  #define ESGMS_Deleting                     ESGMS_Deleting
  #define ESGMS_Loading                      ESGMS_Loading
  #define ESGMS_ListLoading                  ESGMS_ListLoading
  #define ESGMS_LoadingWillowOneSave         ESGMS_LoadingWillowOneSave
  #define ESGMS_SavingProfile                ESGMS_SavingProfile
  #define ESGMS_CountingCrossTitleSaveGames  ESGMS_CountingCrossTitleSaveGames
  #define ESGMS_MAX                          ESGMS_MAX
} ESaveGameManagerState;
typedef enum ELoadPlayerBehavior : unsigned char {
  ELPB_LoadOnly,                  // 0
  ELPB_LoadAndCache,              // 1
  ELPB_MAX                        // 2
  #define ELPB_LoadOnly      ELPB_LoadOnly
  #define ELPB_LoadAndCache  ELPB_LoadAndCache
  #define ELPB_MAX           ELPB_MAX
} ELoadPlayerBehavior;
#define ESaveVersionType       ESaveVersionType
#define CPAsync                CPAsync
#define ESaveGameManagerState  ESaveGameManagerState
#define ELoadPlayerBehavior    ELoadPlayerBehavior

/* ---------------------------------------------------------- UWillowGFxMoviePressStart ---------------------------------------------------------- */

typedef enum EStartupStep : unsigned char {
  STARTUP_NotStarted,             // 0
  STARTUP_DlcEnumeration,         // 1
  STARTUP_PatcherDownload,        // 2
  STARTUP_SparkAuthentication,    // 3
  STARTUP_DeviceSelection,        // 4
  STARTUP_CreateSession,          // 5
  STARTUP_UpdateUpsell,           // 6
  STARTUP_Complete,               // 7
  STARTUP_MAX                     // 8
} EStartupStep;
typedef enum EEggCodeKey  : unsigned char {
  EGG_None,                       // 0
  EGG_Up,                         // 1
  EGG_Down,                       // 2
  EGG_Left,                       // 3
  EGG_Right,                      // 4
  EGG_B,                          // 5
  EGG_A,                          // 6
  EGG_MAX                         // 7
} EEggCodeKey;
#define EStartupStep  EStartupStep
#define EEggCodeKey   EEggCodeKey

/* ---------------------------------------------------------- ALevelLandmark ---------------------------------------------------------- */

typedef enum ELandmarkType : unsigned char {
  LANDMARK_Custom,                // 0
  LANDMARK_Transition,            // 1
  LANDMARK_MAX                    // 2
} ELandmarkType;
#define ELandmarkType  ELandmarkType

/* ---------------------------------------------------------- AInternetLink ---------------------------------------------------------- */

typedef enum ELinkMode    : unsigned char {
  MODE_Text,                      // 0
  MODE_Line,                      // 1
  MODE_Binary,                    // 2
  MODE_MAX                        // 3
} ELinkMode;
typedef enum ELineMode    : unsigned char {
  LMODE_auto,                     // 0
  LMODE_DOS,                      // 1
  LMODE_UNIX,                     // 2
  LMODE_MAC,                      // 3
  LMODE_MAX                       // 4
} ELineMode;
typedef enum EReceiveMode : unsigned char {
  RMODE_Manual,                   // 0
  RMODE_Event,                    // 1
  RMODE_MAX                       // 2
} EReceiveMode;
#define ELinkMode     ELinkMode
#define ELineMode     ELineMode
#define EReceiveMode  EReceiveMode

/* ---------------------------------------------------------- AWorldDiscoveryArea ---------------------------------------------------------- */

static const float DETECTION_TIME_INTERVAL = 0.5f;

/* ---------------------------------------------------------- UWillowAIComponent ---------------------------------------------------------- */

typedef enum TargetExposure  : unsigned char {
  Exposure_None,                  // 0
  Exposure_Half,                  // 1
  Exposure_Full,                  // 2
  Exposure_MAX                    // 3
} TargetExposure;
typedef enum EThreatLevel    : unsigned char {
  ETL_NoThreat,                   // 0
  ETL_InThreatRadius,             // 1
  ETL_SeenInThreatRadius,         // 2
  ETL_Provoked,                   // 3
  ETL_MAX                         // 4
} EThreatLevel;
typedef enum ECombatPointLOS : unsigned char {
  CPLOS_Ignore,                   // 0
  CPLOS_UseLOS,                   // 1
  CPLOS_AvoidLOS,                 // 2
  CPLOS_MAX                       // 3
} ECombatPointLOS;
#define TargetExposure   TargetExposure
#define EThreatLevel     EThreatLevel
#define ECombatPointLOS  ECombatPointLOS

/* ---------------------------------------------------------- UGrenadeModPartDefinition ---------------------------------------------------------- */

typedef enum EGrenadeModPartType : unsigned char {
  GRENADEMOD_PART_Body,           // 0
  GRENADEMOD_PART_Delivery,       // 1
  GRENADEMOD_PART_Trigger,        // 2
  GRENADEMOD_PART_Accessory,      // 3
  GRENADEMOD_PART_Material,       // 4
  GRENADEMOD_PART_Prefix,         // 5
  GRENADEMOD_PART_Title,          // 6
  GRENADEMOD_PART_Property1,      // 7
  GRENADEMOD_PART_Property2,      // 8
  GRENADEMOD_PART_Property3,      // 9
  GRENADEMOD_PART_Property4,      // 10
  GRENADEMOD_PART_MAX             // 11
} EGrenadeModPartType;
#define EGrenadeModPartType  EGrenadeModPartType

/* ---------------------------------------------------------- AWillowPopulationPoint ---------------------------------------------------------- */

typedef enum EStretchyType : unsigned char {
  Stretchy_Linear,                // 0
  Stretchy_Parabola,              // 1
  Stretchy_MAX                    // 2
} EStretchyType;
#define EStretchyType  EStretchyType

/* ---------------------------------------------------------- USparkInterfaceImpl ---------------------------------------------------------- */

typedef enum SparkRequestState : unsigned char {
  SRS_IDLE,                       // 0
  SRS_AWAITING_RETRY,             // 1
  SRS_IN_FLIGHT,                  // 2
  SRS_AWAITING_AUTHENTICATE,      // 3
  SRS_START,                      // 4
  SRS_FAIL,                       // 5
  SRS_QUEUED,                     // 6
  SRS_CLEANUP,                    // 7
  SRS_MAX                         // 8
} SparkRequestState;
#define SparkRequestState  SparkRequestState

/* ---------------------------------------------------------- FFrame ---------------------------------------------------------- */

//
// Evaluatable expression item types.
//
enum EExprToken {
	// Variable references.
	EX_LocalVariable		= 0x00,	// A local variable.
	EX_InstanceVariable		= 0x01,	// An object variable.
	EX_DefaultVariable		= 0x02,	// Default variable for a concrete object.

	// Tokens.
	EX_Return				= 0x04,	// Return from function.
	EX_Switch				= 0x05,	// Switch.
	EX_Jump					= 0x06,	// Goto a local address in code.
	EX_JumpIfNot			= 0x07,	// Goto if not expression.
	EX_Stop					= 0x08,	// Stop executing state code.
	EX_Assert				= 0x09,	// Assertion.
	EX_Case					= 0x0A,	// Case.
	EX_Nothing				= 0x0B,	// No operation.
	EX_LabelTable			= 0x0C,	// Table of labels.
	EX_GotoLabel			= 0x0D,	// Goto a label.
	EX_EatReturnValue       = 0x0E, // destroy an unused return value
	EX_Let					= 0x0F,	// Assign an arbitrary size value to a variable.
	EX_DynArrayElement      = 0x10, // Dynamic array element.!!
	EX_New                  = 0x11, // New object allocation.
	EX_ClassContext         = 0x12, // Class default metaobject context.
	EX_MetaCast             = 0x13, // Metaclass cast.
	EX_LetBool				= 0x14, // Let boolean variable.
	EX_EndParmValue			= 0x15,	// end of default value for optional function parameter
	EX_EndFunctionParms		= 0x16,	// End of function call parameters.
	EX_Self					= 0x17,	// Self object.
	EX_Skip					= 0x18,	// Skippable expression.
	EX_Context				= 0x19,	// Call a function through an object context.
	EX_ArrayElement			= 0x1A,	// Array element.
	EX_VirtualFunction		= 0x1B,	// A function call with parameters.
	EX_FinalFunction		= 0x1C,	// A prebound function call with parameters.
	EX_IntConst				= 0x1D,	// Int constant.
	EX_FloatConst			= 0x1E,	// Floating point constant.
	EX_StringConst			= 0x1F,	// String constant.
	EX_ObjectConst		    = 0x20,	// An object constant.
	EX_NameConst			= 0x21,	// A name constant.
	EX_RotationConst		= 0x22,	// A rotation constant.
	EX_VectorConst			= 0x23,	// A vector constant.
	EX_ByteConst			= 0x24,	// A byte constant.
	EX_IntZero				= 0x25,	// Zero.
	EX_IntOne				= 0x26,	// One.
	EX_True					= 0x27,	// Bool True.
	EX_False				= 0x28,	// Bool False.
	EX_NativeParm           = 0x29, // Native function parameter offset.
	EX_NoObject				= 0x2A,	// NoObject.

	EX_IntConstByte			= 0x2C,	// Int constant that requires 1 byte.
	EX_BoolVariable			= 0x2D,	// A bool variable which requires a bitmask.
	EX_DynamicCast			= 0x2E,	// Safe dynamic class casting.
	EX_Iterator             = 0x2F, // Begin an iterator operation.
	EX_IteratorPop          = 0x30, // Pop an iterator level.
	EX_IteratorNext         = 0x31, // Go to next iteration.
	EX_StructCmpEq          = 0x32,	// Struct binary compare-for-equal.
	EX_StructCmpNe          = 0x33,	// Struct binary compare-for-unequal.
	EX_UnicodeStringConst   = 0x34, // Unicode string constant.
	EX_StructMember         = 0x35, // Struct member.
	EX_DynArrayLength		= 0x36,	// A dynamic array length for setting/getting
	EX_GlobalFunction		= 0x37, // Call non-state version of a function.
	EX_PrimitiveCast		= 0x38,	// A casting operator for primitives which reads the type as the subsequent byte
	EX_DynArrayInsert		= 0x39,	// Inserts into a dynamic array
	EX_ReturnNothing		= 0x3A, // failsafe for functions that return a value - returns the zero value for a property and logs that control reached the end of a non-void function
	EX_EqualEqual_DelDel	= 0x3B,	// delegate comparison for equality
	EX_NotEqual_DelDel		= 0x3C, // delegate comparison for inequality
	EX_EqualEqual_DelFunc	= 0x3D,	// delegate comparison for equality against a function
	EX_NotEqual_DelFunc		= 0x3E,	// delegate comparison for inequality against a function
	EX_EmptyDelegate		= 0x3F,	// delegate 'None'
	EX_DynArrayRemove		= 0x40,	// Removes from a dynamic array
	EX_DebugInfo			= 0x41,	//DEBUGGER Debug information
	EX_DelegateFunction		= 0x42, // Call to a delegate function
	EX_DelegateProperty		= 0x43, // Delegate expression
	EX_LetDelegate			= 0x44, // Assignment to a delegate
	EX_Conditional			= 0x45, // tertiary operator support
	EX_DynArrayFind			= 0x46, // dynarray search for item index
	EX_DynArrayFindStruct	= 0x47, // dynarray<struct> search for item index
	EX_LocalOutVariable		= 0x48, // local out (pass by reference) function parameter
	EX_DefaultParmValue		= 0x49,	// default value of optional function parameter
	EX_EmptyParmValue		= 0x4A,	// unspecified value for optional function parameter
	EX_InstanceDelegate		= 0x4B,	// const reference to a delegate or normal function object




	EX_InterfaceContext		= 0x51,	// Call a function through a native interface variable
	EX_InterfaceCast		= 0x52,	// Converting an object reference to native interface variable
	EX_EndOfScript			= 0x53, // Last byte in script code
	EX_DynArrayAdd			= 0x54, // Add to a dynamic array
	EX_DynArrayAddItem		= 0x55, // Add an item to a dynamic array
	EX_DynArrayRemoveItem	= 0x56, // Remove an item from a dynamic array
	EX_DynArrayInsertItem	= 0x57, // Insert an item into a dynamic array
	EX_DynArrayIterator		= 0x58, // Iterate through a dynamic array
	EX_DynArraySort			= 0x59,	// Sort a list in place

	// Natives.
	EX_ExtendedNative		= 0x60,
	EX_FirstNative			= 0x70,
	EX_Max					= 0x1000,
};

/* ---------------------------------------------------------- UTradingPanelGFxObject ---------------------------------------------------------- */

typedef enum ETradingPanel : unsigned char {
  ETP_Backpack,                   // 0
  ETP_Offers,                     // 1
  ETP_MAX                         // 2
} ETradingPanel;
#define ETradingPanel  ETradingPanel

/* ---------------------------------------------------------- USparkNews ---------------------------------------------------------- */

typedef enum ENewsRetrievalResult : unsigned char {
  NEWSRETRIEVE_Success,           // 0
  NEWSRETRIEVE_GeneralFailure,    // 1
  NEWSRETRIEVE_NetworkFailure,    // 2
  NEWSRETRIEVE_Timeout,           // 3
  NEWSRETRIEVE_MAX                // 4
} ENewsRetrievalResult;
#define ENewsRetrievalResult  ENewsRetrievalResult

/* ---------------------------------------------------------- UParticleModuleRequired ---------------------------------------------------------- */

typedef enum EParticleSortMode   : unsigned char {
  PSORTMODE_None,                 // 0
  PSORTMODE_ViewProjDepth,        // 1
  PSORTMODE_DistanceToView,       // 2
  PSORTMODE_Age_OldestFirst,      // 3
  PSORTMODE_Age_NewestFirst,      // 4
  PSORTMODE_MAX                   // 5
} EParticleSortMode;
typedef enum EEmitterNormalsMode : unsigned char {
  ENM_CameraFacing,               // 0
  ENM_Spherical,                  // 1
  ENM_Cylindrical,                // 2
  ENM_MAX                         // 3
} EEmitterNormalsMode;
#define EParticleSortMode    EParticleSortMode
#define EEmitterNormalsMode  EEmitterNormalsMode

/* ---------------------------------------------------------- UParticleSpriteEmitter ---------------------------------------------------------- */

typedef enum EParticleScreenAlignment : unsigned char {
  PSA_Square,                     // 0
  PSA_Rectangle,                  // 1
  PSA_Velocity,                   // 2
  PSA_TypeSpecific,               // 3
  PSA_MAX                         // 4
} EParticleScreenAlignment;
#define EParticleScreenAlignment  EParticleScreenAlignment

/* ---------------------------------------------------------- USeqAct_ExecuteSkill ---------------------------------------------------------- */

typedef enum EExecuteSkillSequenceInput : unsigned char {
  SEQUENCE_ActivateSkill,         // 0
  SEQUENCE_DeactivateSkill,       // 1
  SEQUENCE_ToggleSkill,           // 2
  SEQUENCE_MAX                    // 3
} EExecuteSkillSequenceInput;
#define EExecuteSkillSequenceInput  EExecuteSkillSequenceInput

/* ---------------------------------------------------------- UParticleModuleOrbit ---------------------------------------------------------- */

typedef enum EOrbitChainMode : unsigned char {
  EOChainMode_Add,                // 0
  EOChainMode_Scale,              // 1
  EOChainMode_Link,               // 2
  EOChainMode_MAX                 // 3
  #define EOChainMode_Add    EOChainMode_Add
  #define EOChainMode_Scale  EOChainMode_Scale
  #define EOChainMode_Link   EOChainMode_Link
  #define EOChainMode_MAX    EOChainMode_MAX
} EOrbitChainMode;
#define EOrbitChainMode  EOrbitChainMode

/* ---------------------------------------------------------- ADeathtrapActionSkill ---------------------------------------------------------- */

typedef enum EMedicBeamState : unsigned char {
  MedicBeam_Inactive,             // 0
  MedicBeam_Active,               // 1
  MedicBeam_Blocked,              // 2
  MedicBeam_MAX                   // 3
  #define MedicBeam_Inactive  MedicBeam_Inactive
  #define MedicBeam_Active    MedicBeam_Active
  #define MedicBeam_Blocked   MedicBeam_Blocked
  #define MedicBeam_MAX       MedicBeam_MAX
} EMedicBeamState;
#define EMedicBeamState  EMedicBeamState

/* ---------------------------------------------------------- UBehavior_StatusEffectSwitch ---------------------------------------------------------- */

typedef enum EStatusEffectSwitchValues : unsigned char {
  OUTPUT_None,                    // 0
  OUTPUT_Ignite,                  // 1
  OUTPUT_Corrosive,               // 2
  OUTPUT_Shock,                   // 3
  OUTPUT_Amp,                     // 4
  OUTPUT_Slow,                    // 5
  OUTPUT_Healing,                 // 6
  OUTPUT_MAX                      // 7
  #define OUTPUT_None       OUTPUT_None
  #define OUTPUT_Ignite     OUTPUT_Ignite
  #define OUTPUT_Corrosive  OUTPUT_Corrosive
  #define OUTPUT_Shock      OUTPUT_Shock
  #define OUTPUT_Amp        OUTPUT_Amp
  #define OUTPUT_Slow       OUTPUT_Slow
  #define OUTPUT_Healing    OUTPUT_Healing
  #define OUTPUT_MAX        OUTPUT_MAX
} EStatusEffectSwitchValues;
#define EStatusEffectSwitchValues  EStatusEffectSwitchValues

/* ---------------------------------------------------------- UWillowPreviewComponent ---------------------------------------------------------- */

typedef enum EPreviewStyle : unsigned char {
  EPS_None,                       // 0
  EPS_Still,                      // 1
  EPS_Playing,                    // 2
  EPS_MAX                         // 3
  #define EPS_None     EPS_None
  #define EPS_Still    EPS_Still
  #define EPS_Playing  EPS_Playing
  #define EPS_MAX      EPS_MAX
} EPreviewStyle;
#define EPreviewStyle  EPreviewStyle
