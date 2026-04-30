#pragma once

#include "macro_helpers.h"

typedef enum : unsigned int {
  FALSE,
  TRUE,
} UBOOL;

/* ---------------------------------------------------------- Internal ---------------------------------------------------------- */

typedef enum ENativeConstructor { EC_NativeConstructor } ENativeConstructor;
typedef enum EStaticConstructor { EC_StaticConstructor } EStaticConstructor;
typedef enum EInternal          { EC_Internal }          EInternal;
typedef enum ECppProperty       { EC_CppProperty }       ECppProperty;
typedef enum EEventParm         { EC_EventParm }         EEventParm;
#define ENativeConstructor  ENativeConstructor
#define EStaticConstructor  EStaticConstructor
#define EInternal           EInternal
#define ECppProperty        ECppProperty
#define EEventParm          EEventParm

// Global constants.
enum { MINBYTE  = 0x00        };
enum { MINWORD  = 0x0000U     };
enum { MINDWORD = 0x00000000U };
enum { MINSBYTE = 0x80        };
enum { MINSWORD = 0x8000      };
#undef MININT
enum { MININT = 0x80000000 };
#define MININT ((INT)~MAXINT)
enum { MAXBYTE     = 0xff        };
enum { MAXWORD     = 0xffffU     };
enum { MAXDWORD    = 0xffffffffU };
enum { MAXSBYTE    = 0x7f        };
enum { MAXSWORD    = 0x7fff      };
enum { MAXINT      = 0x7fffffff  };
enum { INDEX_NONE  = -1          };
enum { UNICODE_BOM = 0xfeff      };
enum ENoInit    { E_NoInit    = 0 };
enum EForceInit { E_ForceInit = 0 };
enum { MAX_TEXCOORDS = 4 };

/** RHI capabilities. */
enum { MAX_TEXTURE_MIP_COUNT        = 14 };  /** Maximum number of miplevels in a texture. */
enum { MaxVertexElementCount        = 16 };  /** The maximum number of vertex elements which can be used by a vertex declaration. */
enum { ShaderArrayElementAlignBytes = 16 };  /** The alignment in bytes between elements of array shader parameters. */

/* Sizes. */
enum { MAX_STRING_CONST_SIZE = 1024 };
/**
 * This is the size of the buffer used by the script interpreter for
 * unused simple (not constructed) return values.  Larger return values
 * use the constructed value path (EX_EatReturnValue/execEatReturnValue)
 */
enum { MAX_SIMPLE_RETURN_VALUE_SIZE = 64 };

/**
 * This is the largest possible size that a single variable can be;
 * a variables size is determined by multiplying the size of the type
 * by the variables ArrayDim (always 1 unless it's a static array).
 */
enum { MAX_VARIABLE_SIZE = 0x0FFF };

typedef enum EAIFunctions {
	AI_PollMoveTo         = 501,
	AI_PollMoveToward     = 503,
	AI_PollStrafeTo       = 505,
	AI_PollStrafeFacing   = 507,
	AI_PollFinishRotation = 509,
	AI_PollWaitForLanding = 528,
  #define AI_PollMoveTo                    AI_PollMoveTo
  #define AI_PollMoveToward                AI_PollMoveToward
  #define AI_PollStrafeTo                  AI_PollStrafeTo
  #define AI_PollStrafeFacing              AI_PollStrafeFacing
  #define AI_PollFinishRotation            AI_PollFinishRotation
  #define AI_PollWaitForLanding            AI_PollWaitForLanding
  #define EAIFunctions_PollMoveTo          AI_PollMoveTo
  #define EAIFunctions_PollMoveToward      AI_PollMoveToward
  #define EAIFunctions_PollStrafeTo        AI_PollStrafeTo
  #define EAIFunctions_PollStrafeFacing    AI_PollStrafeFacing
  #define EAIFunctions_PollFinishRotation  AI_PollFinishRotation
  #define EAIFunctions_PollWaitForLanding  AI_PollWaitForLanding
} EAIFunctions;
#define EAIFunctions  EAIFunctions

/* ---------------------------------------------------------- FTexture2D ! ---------------------------------------------------------- */

/** Texture formats used by FTexture2D */
typedef enum ETexture2DFormats {
  TF_UNKNOWN,
  TF_ARGB8,
  TF_ARGB16F
  #define TF_UNKNOWN                 TF_UNKNOWN
  #define TF_ARGB8                   TF_ARGB8
  #define TF_ARGB16F                 TF_ARGB16F
  #define ETexture2DFormats_UNKNOWN  TF_UNKNOWN
  #define ETexture2DFormats_ARGB8    TF_ARGB8
  #define ETexture2DFormats_ARGB16F  TF_ARGB16F
} ETexture2DFormats;
#define ETexture2DFormats  ETexture2DFormats

#ifndef EGotoState
/** Result of GotoState. */
typedef enum EGotoState {
  GOTOSTATE_NotFound  = 0,
  GOTOSTATE_Success   = 1,
  GOTOSTATE_Preempted = 2,
  #define GOTOSTATE_NotFound    GOTOSTATE_NotFound
  #define GOTOSTATE_Success     GOTOSTATE_Success
  #define GOTOSTATE_Preempted   GOTOSTATE_Preempted
  #define EGotoState_NotFound   GOTOSTATE_NotFound
  #define EGotoState_Success    GOTOSTATE_Success
  #define EGotoState_Preempted  GOTOSTATE_Preempted
} EGotoState;
#define EGotoState  EGotoState
#endif

/** Flags describing a class. */
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

/** Flags used for quickly casting classes of certain types; all class cast flags are inherited. */
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
  /** These match the values of the old class flags to make conversion easier. */
  CASTCLASS_UProperty					= 0x00008000,
  CASTCLASS_UObjectProperty			= 0x00010000,
  CASTCLASS_UBoolProperty				= 0x00020000,
  CASTCLASS_UState					= 0x00040000,
  CASTCLASS_UFunction					= 0x00080000,
  CASTCLASS_UStructProperty			= 0x00100000,
  CASTCLASS_UArrayProperty			= 0x00200000,
  CASTCLASS_UMapProperty				= 0x00400000,
  CASTCLASS_UDelegateProperty			= 0x00800000,
  CASTCLASS_UComponent				= 0x01000000,
  CASTCLASS_AllFlags					= 0xFFFFFFFF,
} EClassCastFlag;

/**
 * Various memory regions that can be used with memory stats. The exact meaning of
 * the enums are relatively platform-dependent, although the general ones (Physical, GPU)
 * are straightforward. A platform can add more of these, and it won't affect other 
 * platforms, other than a miniscule amount of memory for the StatManager to track the
 * max available memory for each region (uses an array MCR_MAX big)
 */
typedef enum EMemoryCounterRegion {
  MCR_Physical,     /** Main system memory. */
  MCR_GPU,          /** Memory directly a GPU (graphics card, etc). */
  MCR_GPUSystem,    /** System memory directly accessible by a GPU. */
  MCR_RingBuffer1,  /** General purpose regions for tracking how full a ring buffer gets (NOT the rendering thread command buffer). */
  MCR_RingBuffer2, 
  MCR_RingBuffer3, 
  MCR_TexturePool1,  /** Presized texture pools. */
  MCR_TexturePool2, 
  MCR_TexturePool3, 
  MCR_MAX
} EMemoryCounterRegion;

/* ---------------------------------------------------------- ?? Stats ?? ---------------------------------------------------------- */

/**
 * Unique stats identifiers. Note these don't have to defined in this header
 * but they do have to be unique. You're better off defining these in your
 * own headers/cpp files
 */
typedef enum EStats {
  /** Special stats. */
  STAT_Error,
  STAT_Root,
  STAT_FrameTime,
  /** Used by the per group stats to avoid conflicts. */
  STAT_ObjectFirstStat            = 100,
  STAT_EngineFirstStat            = 200,
  STAT_GameFirstStat              = 300,
  STAT_UnrealScriptTime,  /** This stat needs to be visible to core. */
  STAT_NetFirstStat               = 400,
  STAT_NetPeerFirstStat           = 450,
  STAT_StreamingFirstStat         = 500,
  STAT_AsyncLoadingTime,  /** This stat needs to be here for include order reasons. */
  STAT_PhysicsFirstStat           = 700,
  STAT_CollisionFirstStat         = 800,
  STAT_AudioFirstStat             = 900,
  STAT_MemoryFirstStat            = 1000,
  STAT_MemoryChurnFirstStat       = 1100,
  STAT_ParticlesFirstStat         = 1200,
  STAT_BeamParticlesFirstStat     = 1300,
  STAT_D3D9RHIFirstStat           = 1400,
  STAT_StatSystemFirstStat        = 1500,
  STAT_OctreeFirstStat            = 1600,
  STAT_TrailParticlesFirstStat    = 1700,
  STAT_FaceFXFirstStat            = 1800,
  STAT_SceneRenderingFirstStat    = 1900,
  STAT_ThreadingFirstStat         = 2100,
  STAT_SceneUpdateFirstStat       = 2200,
  STAT_AnimFirstStat              = 2300,
  STAT_UIFirstStat                = 2400,
  STAT_DLEFirstStat               = 2500,
  STAT_AsyncIOFirstStat           = 2600,
  STAT_FPSChartFirstStat          = 2700,
  STAT_ShaderCompilingFirstStat   = 2800,
  STAT_PathFindingFirstStat       = 2900,
  STAT_PhysicsFluidFirstStat      = 3000,
  STAT_PhysicsClothFirstStat      = 3100,
  STAT_PhysicsFieldsFirstStat     = 3200,
  STAT_DecalFirstStat             = 3300,
  STAT_CanvasFirstStat            = 3400,
  STAT_MeshParticlesFirstStat     = 3500,
  STAT_PS3RHIFirstStat            = 3700,
  STAT_XeRHIFirstStat             = 3800,
  STAT_FluidsFirstStat            = 3900,
  STAT_MemoryDetailedFirstStat    = 4000,
  STAT_NavMeshFirstStat           = 4100,
  STAT_CrowdFirstStat             = 4200,
  STAT_InstancingFirstStat        = 4300,
  STAT_ShaderCompressionFirstStat = 4400,
  STAT_InitViewsFirstStat         = 4500,
  STAT_ShadowRenderingFirstStat   = 4600,
  STAT_SceneCapturesFirstStat     = 4700,
  STAT_GFxFirstStat               = 4800,
  STAT_ES2FirstStat               = 4900,
  STAT_TexturePoolFirstStat       = 5000,
  STAT_D3D11RHIFirstStat          = 5100,
  STAT_MorphFirstStat             = 5200,
  STAT_GxmFirstStat               = 5300,
  STAT_OpenGLRHIFirstStat         = 5400,
  STAT_SceneMemoryFirstStat       = 5500,
  /** -- Add new stat ranges BELOW this line -- */
  /** -- Add new stat ranges ABOVE this line -- */
  /** Stats created from arbitrary runtime strings on the fly. */
  STAT_FirstStringStat            = 35000,
  STAT_LastStringStat             = 39999,
  /** Licensees should create their own enum with the first value being set to the value below. */
  STAT_LicenseeFirstStat          = 60000
} EStats;
/** Stats for the stat system */
typedef enum EStatSystemStats {
  STAT_PerFrameCapture = STAT_StatSystemFirstStat,
  STAT_PerFrameCaptureRT,
  STAT_DrawStats,
  STAT_TimingCodeCalls,
} EStatSystemStats;
/** Texture pool stats */
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
/** Holds the list of stat ids for object stat gathering. */
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
/** Engine stats */
enum EEngineStats {
	/** Terrain stats */
	STAT_TerrainRenderTime = STAT_EngineFirstStat,
	STAT_TerrainSmoothTime,
	STAT_TerrainTriangles,
	/** Input stat */
	STAT_InputTime,
	STAT_InputLatencyTime,
	/** HUD stat */
	STAT_HudTime,
	/** Static mesh tris rendered */
	STAT_StaticMeshTriangles,
	STAT_SkinningTime,
	STAT_UpdateClothVertsTime,
	STAT_UpdateSoftBodyVertsTime,
	STAT_SkelMeshTriangles,
	STAT_SkelMeshDrawCalls,
	STAT_CPUSkinVertices,
	STAT_GPUSkinVertices,
	STAT_FracturePartPoolUsed,
	STAT_GameEngineTick,
	STAT_GameViewportTick,
	STAT_RedrawViewports,
	STAT_UpdateLevelStreaming,
	STAT_RHITickTime
};
/** Game stats */
enum EGameStats {
	STAT_DecalTime = (STAT_UnrealScriptTime + 1),
	STAT_PhysicsTime,
	STAT_SpawnActorTime,
	STAT_MoveActorTime,
	STAT_FarMoveActorTime,
	STAT_GCMarkTime,
	STAT_GCSweepTime,
	STAT_UpdateComponentsTime,
	STAT_KismetTime,
	STAT_TempTime,
	/** Ticking stats */
	STAT_PostUpdateTickTime,
	STAT_PostAsyncTickTime,
	STAT_DuringAsyncTickTime,
	STAT_PreAsyncTickTime,
	STAT_PostUpdateComponentTickTime,
	STAT_PostAsyncComponentTickTime,
	STAT_DuringAsyncComponentTickTime,
	STAT_PreAsyncComponentTickTime,
	STAT_TickTime,
	STAT_WorldTickTime,
	STAT_PostTickComponentUpdate,
	STAT_ParticleManagerUpdateData,
	STAT_PostUpdateWorkActorsTicked,
	STAT_PostAsyncActorsTicked,
	STAT_DuringAsyncActorsTicked,
	STAT_PreAsyncActorsTicked,
	STAT_PostAsyncComponentsTicked,
	STAT_DuringAsyncComponentsTicked,
	STAT_PreAsyncComponentsTicked,
	STAT_AsyncWorkWaitTime,
	STAT_PawnPhysics,
};
/** FPS chart stats */
enum FPSChartStats {
	STAT_FPSChart_0_5	= STAT_FPSChartFirstStat,
	STAT_FPSChart_5_10,
	STAT_FPSChart_10_15,
	STAT_FPSChart_15_20,
	STAT_FPSChart_20_25,
	STAT_FPSChart_25_30,
	STAT_FPSChart_30_35,
	STAT_FPSChart_35_40,
	STAT_FPSChart_40_45,
	STAT_FPSChart_45_50,
	STAT_FPSChart_50_55,
	STAT_FPSChart_55_60,
	STAT_FPSChart_60_INF,
	STAT_FPSChartLastBucketStat,
	STAT_FPSChart_30Plus,
	STAT_FPSChart_UnaccountedTime,
	STAT_FPSChart_FrameCount,
	/** Hitch stats */
	STAT_FPSChart_FirstHitchStat,
	STAT_FPSChart_Hitch_5000_Plus = STAT_FPSChart_FirstHitchStat,
	STAT_FPSChart_Hitch_2500_5000,
	STAT_FPSChart_Hitch_2000_2500,
	STAT_FPSChart_Hitch_1500_2000,
	STAT_FPSChart_Hitch_1000_1500,
	STAT_FPSChart_Hitch_750_1000,
	STAT_FPSChart_Hitch_500_750,
	STAT_FPSChart_Hitch_300_500,
	STAT_FPSChart_Hitch_200_300,
	STAT_FPSChart_Hitch_150_200,
	STAT_FPSChart_Hitch_100_150,
	STAT_FPSChart_LastHitchBucketStat,
	STAT_FPSChart_TotalHitchCount,
	/** Unit time stats */
	STAT_FPSChart_UnitFrame,
	STAT_FPSChart_UnitRender,
	STAT_FPSChart_UnitGame,
	STAT_FPSChart_UnitGPU,
};
/** Path finding stats */
enum EPathFindingStats {
	STAT_PathFinding_Reachable = STAT_PathFindingFirstStat,
	STAT_PathFinding_FindPathToward,
	STAT_PathFinding_BestPathTo,
};
/** UI Stats */
enum EUIStats {
	STAT_UIKismetTime = STAT_UIFirstStat,
	STAT_UITickTime,
	STAT_UIDrawingTime,
};
/** Canvas Stats */
enum ECanvasStats {
	STAT_Canvas_FlushTime = STAT_CanvasFirstStat,	
	STAT_Canvas_DrawTextureTileTime,
	STAT_Canvas_DrawMaterialTileTime,
	STAT_Canvas_DrawStringTime,
	STAT_Canvas_GetBatchElementsTime,
	STAT_Canvas_AddTileRenderTime,
	STAT_Canvas_NumBatchesCreated	
};
/** Decal stats */
enum EDecalStats {
	STAT_DecalAttachTime = STAT_DecalFirstStat,
	STAT_DecalBSPAttachTime,
	STAT_DecalStaticMeshAttachTime,
	STAT_DecalSkeletalMeshAttachTime,
	STAT_DecalTerrainAttachTime,
	STAT_DecalHitComponentAttachTime,
	STAT_DecalHitNodeAttachTime,
	STAT_DecalMultiComponentAttachTime,
	STAT_DecalReceiverImagesAttachTime,
	/** Decal stats */
	STAT_DecalTriangles,
	STAT_DecalDrawCalls,
	STAT_DecalRenderUnlitTime,
	STAT_DecalRenderLitTime,
	STAT_DecalRenderDynamicBSPTime,
	STAT_DecalRenderDynamicSMTime,
	STAT_DecalRenderDynamicTerrainTime,
	STAT_DecalRenderDynamicSkelTime
};
/** Streaming stats */
enum EStreamingStats {
	STAT_StreamingTextures = (STAT_AsyncLoadingTime + 1),
	STAT_StreamingTexturesSize,
	STAT_StreamingTexturesMaxSize,
	STAT_LightmapMemorySize,
	STAT_LightmapDiskSize,
	STAT_TexturePoolAllocatedSize,
	STAT_RequestsInCancelationPhase,
	STAT_RequestsInUpdatePhase,
	STAT_RequestsInFinalizePhase,
	STAT_IntermediateTextures,
	STAT_IntermediateTexturesSize,
	STAT_RequestSizeCurrentFrame,
	STAT_RequestSizeTotal,
	STAT_LightmapRequestSizeTotal,
	STAT_StreamingFudgeFactor,
	STAT_GameThreadUpdateTime,
	STAT_RenderingThreadUpdateTime,
	STAT_RenderingThreadFinalizeTime,
	STAT_StreamingLatency,
	STAT_StreamingBandwidth,
	STAT_DynamicStreamingTotal,
	STAT_AudioResourceCreationTime,
	STAT_VolumeStreamingTickTime,
	STAT_VolumeStreamingChecks,
	STAT_GrowingReallocations,
	STAT_ShrinkingReallocations,
	STAT_FullReallocations,
	STAT_FailedReallocations,
	STAT_PanicDefragmentations,
	STAT_AddToWorldTime,
	STAT_RemoveFromWorldTime,
	STAT_UpdateLevelStreamingTime,
	STAT_OptimalTextureSize,
	STAT_StreamingOverBudget,
	STAT_StreamingUnderBudget,
	STAT_NumWantingTextures,
	STAT_NumStreamingTextureInstances,
	STAT_NumStreamingLightmapInstances,
	STAT_TotalStaticTextureHeuristicSize,
	STAT_TotalLastRenderHeuristicSize,
	STAT_TotalDynamicHeuristicSize,
	STAT_TotalForcedHeuristicSize,
};

/* ---------------------------------------------------------- UPackage ! ---------------------------------------------------------- */

/** Flags for loading objects. */
typedef enum ELoadFlags {
  LOAD_None            = 0x00000000,  /** No flags. */
  LOAD_SeekFree        = 0x00000001,  /** Loads the package via the seek free loading path/ reader */
  LOAD_NoWarn          = 0x00000002,  /** Don't display warning if load fails. */
  LOAD_Throw           = 0x00000008,  /** Throw exceptions upon failure. */
  LOAD_Verify          = 0x00000010,  /** Only verify existance; don't actually load. */
  LOAD_AllowDll        = 0x00000020,  /** Allow plain DLLs. */
  LOAD_DisallowFiles   = 0x00000040,  /** Don't load from file. */
  LOAD_NoVerify        = 0x00000080,  /** Don't verify imports yet. */
  LOAD_Quiet           = 0x00002000,  /** No log warnings. */
  LOAD_FindIfFail      = 0x00004000,  /** Tries FindObject if a linker cannot be obtained (e.g. package is currently being compiled) */
  LOAD_MemoryReader    = 0x00008000,  /** Loads the file into memory and serializes from there. */
  //@script patcher
  LOAD_RemappedPackage = 0x00010000,  /** Indicates that is a native script package which has been renamed - GScriptPackageSuffix should be appended to the package name */
  LOAD_NoRedirects     = 0x00020000,  /** Never follow redirects when loading objects; redirected loads will fail */
  #define LOAD_None                   LOAD_None
  #define LOAD_SeekFree               LOAD_SeekFree
  #define LOAD_NoWarn                 LOAD_NoWarn
  #define LOAD_Throw                  LOAD_Throw
  #define LOAD_Verify                 LOAD_Verify
  #define LOAD_AllowDll               LOAD_AllowDll
  #define LOAD_DisallowFiles          LOAD_DisallowFiles
  #define LOAD_NoVerify               LOAD_NoVerify
  #define LOAD_Quiet                  LOAD_Quiet
  #define LOAD_FindIfFail             LOAD_FindIfFail
  #define LOAD_MemoryReader           LOAD_MemoryReader
  #define LOAD_RemappedPackage        LOAD_RemappedPackage
  #define LOAD_NoRedirects            LOAD_NoRedirects
  #define ELoadFlags_None             LOAD_None
  #define ELoadFlags_SeekFree         LOAD_SeekFree
  #define ELoadFlags_NoWarn           LOAD_NoWarn
  #define ELoadFlags_Throw            LOAD_Throw
  #define ELoadFlags_Verify           LOAD_Verify
  #define ELoadFlags_AllowDll         LOAD_AllowDll
  #define ELoadFlags_DisallowFiles    LOAD_DisallowFiles
  #define ELoadFlags_NoVerify         LOAD_NoVerify
  #define ELoadFlags_Quiet            LOAD_Quiet
  #define ELoadFlags_FindIfFail       LOAD_FindIfFail
  #define ELoadFlags_MemoryReader     LOAD_MemoryReader
  #define ELoadFlags_RemappedPackage  LOAD_RemappedPackage
  #define ELoadFlags_NoRedirects      LOAD_NoRedirects
} ELoadFlags;
/** Flags for saving packages */
typedef enum ESaveFlags {
  SAVE_None         = 0x00000000,  /** No flags */
  SAVE_NoError      = 0x00000001,  /** Don't generate errors on save */
  SAVE_FromAutosave = 0x00000002,  /** Used to indicate this save was initiated automatically */
  SAVE_KeepDirty    = 0x00000004,  /** Do not clear the dirty flag when saving */
  #define SAVE_None                SAVE_None
  #define SAVE_NoError             SAVE_NoError
  #define SAVE_FromAutosave        SAVE_FromAutosave
  #define SAVE_KeepDirty           SAVE_KeepDirty
  #define ESaveFlags_None          SAVE_None
  #define ESaveFlags_NoError       SAVE_NoError
  #define ESaveFlags_FromAutosave  SAVE_FromAutosave
  #define ESaveFlags_KeepDirty     SAVE_KeepDirty
} ESaveFlags;
/** Package flags. */
typedef enum EPackageFlags {
  PKG_AllowDownload               = 0x00000001,  /** Allow downloading package. */
  PKG_ClientOptional              = 0x00000002,  /** Purely optional for clients. */
  PKG_ServerSideOnly              = 0x00000004,  /** Only needed on the server side. */
  PKG_Cooked                      = 0x00000008,  /** Whether this package has been cooked for the target platform. */
  PKG_Unsecure                    = 0x00000010,  /** Not trusted. */
  PKG_SavedWithNewerVersion       = 0x00000020,  /** Package was saved with newer version. */
  PKG_Need                        = 0x00008000,  /** Client needs to download this package. */
  PKG_Compiling                   = 0x00010000,  /** package is currently being compiled */
  PKG_ContainsMap                 = 0x00020000,  /** Set if the package contains a ULevel/ UWorld object */
  PKG_Trash                       = 0x00040000,  /** Set if the package was loaded from the trashcan */
  PKG_DisallowLazyLoading         = 0x00080000,  /** Set if the archive serializing this package cannot use lazy loading */
  PKG_PlayInEditor                = 0x00100000,  /** Set if the package was created for the purpose of PIE */
  PKG_ContainsScript              = 0x00200000,  /** Package is allowed to contain UClasses and unrealscript */
  PKG_ContainsDebugInfo           = 0x00400000,  /** Package contains debug info (for UDebugger) */
  PKG_RequireImportsAlreadyLoaded = 0x00800000,  /** Package requires all its imports to already have been loaded */
  PKG_SelfContainedLighting       = 0x01000000,  /** All lighting in this package should be self contained */
  PKG_StoreCompressed             = 0x02000000,  /** Package is being stored compressed, requires archive support for compression */
  PKG_StoreFullyCompressed        = 0x04000000,  /** Package is serialized normally, and then fully compressed after (must be decompressed before LoadPackage is called) */
  PKG_ContainsInlinedShaders      = 0x08000000,  /** Package was cooked allowing materials to inline their FMaterials (and hence shaders) */
  PKG_ContainsFaceFXData          = 0x10000000,  /** Package contains FaceFX assets and/or animsets */
  PKG_NoExportAllowed             = 0x20000000,  /** Package was NOT created by a modder.  Internal data not for export */
  PKG_StrippedSource              = 0x40000000,  /** Source has been removed to compress the package size */
  #define PKG_AllowDownload                          PKG_AllowDownload
  #define PKG_ClientOptional                         PKG_ClientOptional
  #define PKG_ServerSideOnly                         PKG_ServerSideOnly
  #define PKG_Cooked                                 PKG_Cooked
  #define PKG_Unsecure                               PKG_Unsecure
  #define PKG_SavedWithNewerVersion                  PKG_SavedWithNewerVersion
  #define PKG_Need                                   PKG_Need
  #define PKG_Compiling                              PKG_Compiling
  #define PKG_ContainsMap                            PKG_ContainsMap
  #define PKG_Trash                                  PKG_Trash
  #define PKG_DisallowLazyLoading                    PKG_DisallowLazyLoading
  #define PKG_PlayInEditor                           PKG_PlayInEditor
  #define PKG_ContainsScript                         PKG_ContainsScript
  #define PKG_ContainsDebugInfo                      PKG_ContainsDebugInfo
  #define PKG_RequireImportsAlreadyLoaded            PKG_RequireImportsAlreadyLoaded
  #define PKG_SelfContainedLighting                  PKG_SelfContainedLighting
  #define PKG_StoreCompressed                        PKG_StoreCompressed
  #define PKG_StoreFullyCompressed                   PKG_StoreFullyCompressed
  #define PKG_ContainsInlinedShaders                 PKG_ContainsInlinedShaders
  #define PKG_ContainsFaceFXData                     PKG_ContainsFaceFXData
  #define PKG_NoExportAllowed                        PKG_NoExportAllowed
  #define PKG_StrippedSource                         PKG_StrippedSource
  #define EPackageFlags_AllowDownload                PKG_AllowDownload
  #define EPackageFlags_ClientOptional               PKG_ClientOptional
  #define EPackageFlags_ServerSideOnly               PKG_ServerSideOnly
  #define EPackageFlags_Cooked                       PKG_Cooked
  #define EPackageFlags_Unsecure                     PKG_Unsecure
  #define EPackageFlags_SavedWithNewerVersion        PKG_SavedWithNewerVersion
  #define EPackageFlags_Need                         PKG_Need
  #define EPackageFlags_Compiling                    PKG_Compiling
  #define EPackageFlags_ContainsMap                  PKG_ContainsMap
  #define EPackageFlags_Trash                        PKG_Trash
  #define EPackageFlags_DisallowLazyLoading          PKG_DisallowLazyLoading
  #define EPackageFlags_PlayInEditor                 PKG_PlayInEditor
  #define EPackageFlags_ContainsScript               PKG_ContainsScript
  #define EPackageFlags_ContainsDebugInfo            PKG_ContainsDebugInfo
  #define EPackageFlags_RequireImportsAlreadyLoaded  PKG_RequireImportsAlreadyLoaded
  #define EPackageFlags_SelfContainedLighting        PKG_SelfContainedLighting
  #define EPackageFlags_StoreCompressed              PKG_StoreCompressed
  #define EPackageFlags_StoreFullyCompressed         PKG_StoreFullyCompressed
  #define EPackageFlags_ContainsInlinedShaders       PKG_ContainsInlinedShaders
  #define EPackageFlags_ContainsFaceFXData           PKG_ContainsFaceFXData
  #define EPackageFlags_NoExportAllowed              PKG_NoExportAllowed
  #define EPackageFlags_StrippedSource               PKG_StrippedSource
} EPackageFlags;
#define ELoadFlags     ELoadFlags
#define ESaveFlags     ESaveFlags
#define EPackageFlags  EPackageFlags

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

#define DECLARE_UINT64(x)  x##ULL

typedef enum EObjectFlagsEnum {
  RF_InSingularFunc         = 0x0000000000000002ULL,
  RF_StateChanged           = 0x0000000000000004ULL,
  RF_DebugPostLoad          = 0x0000000000000008ULL,
  RF_DebugSerialize         = 0x0000000000000010ULL,
  RF_DebugFinishDestroyed   = 0x0000000000000020ULL,
  RF_EdSelected             = 0x0000000000000040ULL,
  RF_ZombieComponent        = 0x0000000000000080ULL,
  RF_Protected              = 0x0000000000000100ULL,
  RF_ClassDefaultObject     = 0x0000000000000200ULL,
  RF_ArchetypeObject        = 0x0000000000000400ULL,
  RF_ForceTagExp            = 0x0000000000000800ULL,
  RF_TokenStreamAssembled   = 0x0000000000001000ULL,
  RF_MisalignedObject       = 0x0000000000002000ULL,
  RF_RootSet                = 0x0000000000004000ULL,
  RF_BeginDestroyed         = 0x0000000000008000ULL,
  RF_FinishDestroyed        = 0x0000000000010000ULL,
  RF_DebugBeginDestroyed    = 0x0000000000020000ULL,
  RF_MarkedByCooker         = 0x0000000000040000ULL,
  RF_LocalizedResource      = 0x0000000000080000ULL,
  RF_InitializedProps       = 0x0000000000100000ULL,
  RF_PendingFieldPatches    = 0x0000000000200000ULL,
  RF_IsCrossLevelReferenced = 0x0000000000400000ULL,
  RF_Saved                  = 0x0000000080000000ULL,
  RF_Transactional          = 0x0000000100000000ULL,
  RF_Unreachable            = 0x0000000200000000ULL,
  RF_Public                 = 0x0000000400000000ULL,
  RF_TagImp                 = 0x0000000800000000ULL,
  RF_TagExp                 = 0x0000001000000000ULL,
  RF_Obsolete               = 0x0000002000000000ULL,
  RF_TagGarbage             = 0x0000004000000000ULL,
  RF_DisregardForGC         = 0x0000008000000000ULL,
  RF_PerObjectLocalized     = 0x0000010000000000ULL,
  RF_NeedLoad               = 0x0000020000000000ULL,
  RF_AsyncLoading           = 0x0000040000000000ULL,
  RF_NeedPostLoadSubobjects = 0x0000080000000000ULL,
  RF_Suppress               = 0x0000100000000000ULL,
  RF_InEndState             = 0x0000200000000000ULL,
  RF_Transient              = 0x0000400000000000ULL,
  RF_Cooked                 = 0x0000800000000000ULL,
  RF_LoadForClient          = 0x0001000000000000ULL,
  RF_LoadForServer          = 0x0002000000000000ULL,
  RF_LoadForEdit            = 0x0004000000000000ULL,
  RF_Standalone             = 0x0008000000000000ULL,
  RF_NotForClient           = 0x0010000000000000ULL,
  RF_NotForServer           = 0x0020000000000000ULL,
  RF_NotForEdit             = 0x0040000000000000ULL,
  RF_NeedPostLoad           = 0x0100000000000000ULL,
  RF_HasStack               = 0x0200000000000000ULL,
  RF_Native                 = 0x0400000000000000ULL,
  RF_Marked                 = 0x0800000000000000ULL,
  RF_ErrorShutdown          = 0x1000000000000000LL,
  RF_PendingKill            = 0x2000000000000000ULL,
  RF_ContextFlags           = (RF_NotForClient | RF_NotForServer | RF_NotForEdit),
  RF_LoadContextFlags       = (RF_LoadForClient | RF_LoadForServer | RF_LoadForEdit),
  RF_Load                   = (RF_ContextFlags | RF_LoadContextFlags | RF_Public | RF_Standalone | RF_Native | RF_Obsolete | RF_Protected | RF_Transactional | RF_HasStack | RF_PerObjectLocalized | RF_ClassDefaultObject | RF_ArchetypeObject | RF_LocalizedResource),
  RF_Keep                   = (RF_Native | RF_Marked | RF_PerObjectLocalized | RF_MisalignedObject | RF_DisregardForGC | RF_RootSet | RF_LocalizedResource),
  RF_ScriptMask             = (RF_Transactional | RF_Public | RF_Transient | RF_NotForClient | RF_NotForServer | RF_NotForEdit | RF_Standalone),
  RF_UndoRedoMask           = (RF_PendingKill),
  RF_PropagateToSubObjects  = (RF_Public | RF_ArchetypeObject | RF_Transactional),
  RF_AllFlags               = 0xFFFFFFFFFFFFFFFFULL
} EObjectFlagsEnum;

typedef enum CPF {
  CPF_Edit                  = DECLARE_UINT64(0x0000000000000001),  /** Property is user-settable in the editor. */
  CPF_Const                 = DECLARE_UINT64(0x0000000000000002),  /** Actor's property always matches class's default actor property. */
  CPF_Input                 = DECLARE_UINT64(0x0000000000000004),  /** Variable is writable by the input system. */
  CPF_ExportObject          = DECLARE_UINT64(0x0000000000000008),  /** Object can be exported with actor. */
  CPF_OptionalParm          = DECLARE_UINT64(0x0000000000000010),  /** Optional parameter (if CPF_Param is set),. */
  CPF_Net                   = DECLARE_UINT64(0x0000000000000020),  /** Property is relevant to network replication. */
  CPF_EditFixedSize         = DECLARE_UINT64(0x0000000000000040),  /** Indicates that elements of an array can be modified, but its size cannot be changed. */
  CPF_Parm                  = DECLARE_UINT64(0x0000000000000080),  /** Function/When call parameter. */
  CPF_OutParm               = DECLARE_UINT64(0x0000000000000100),  /** Value is copied out after function call. */
  CPF_SkipParm              = DECLARE_UINT64(0x0000000000000200),  /** Property is a short-circuitable evaluation function parm. */
  CPF_ReturnParm            = DECLARE_UINT64(0x0000000000000400),  /** Return value. */
  CPF_CoerceParm            = DECLARE_UINT64(0x0000000000000800),  /** Coerce args into this function parameter. */
  CPF_Native                = DECLARE_UINT64(0x0000000000001000),  /** Property is native: C++ code is responsible for serializing it. */
  CPF_Transient             = DECLARE_UINT64(0x0000000000002000),  /** Property is transient: shouldn't be saved, zero-filled at load time. */
  CPF_Config                = DECLARE_UINT64(0x0000000000004000),  /** Property should be loaded/saved as permanent profile. */
  CPF_Localized             = DECLARE_UINT64(0x0000000000008000),  /** Property should be loaded as localizable text. */
  CPF_EditConst             = DECLARE_UINT64(0x0000000000020000),  /** Property is uneditable in the editor. */
  CPF_GlobalConfig          = DECLARE_UINT64(0x0000000000040000),  /** Load config from base class, not subclass. */
  CPF_Component             = DECLARE_UINT64(0x0000000000080000),  /** Property containts component references. */
  CPF_AlwaysInit            = DECLARE_UINT64(0x0000000000100000),  /** Property should never be exported as NoInit	(@todo - this doesn't need to be a property flag...only used during make), */
  CPF_DuplicateTransient    = DECLARE_UINT64(0x0000000000200000),  /** Property should always be reset to the default value during any type of duplication (copy/paste, binary duplication, etc.), */
  CPF_NeedCtorLink          = DECLARE_UINT64(0x0000000000400000),  /** Fields need construction/destruction. */
  CPF_NoExport              = DECLARE_UINT64(0x0000000000800000),  /** Property should not be exported to the native class header file. */
  CPF_NoImport              = DECLARE_UINT64(0x0000000001000000),  /** Property should not be imported when creating an object from text (copy/paste), */
  CPF_NoClear               = DECLARE_UINT64(0x0000000002000000),  /** Hide clear (and browse), button. */
  CPF_EditInline            = DECLARE_UINT64(0x0000000004000000),  /** Edit this object reference inline. */
  CPF_EditInlineUse         = DECLARE_UINT64(0x0000000010000000),  /** EditInline with Use button. */
  CPF_Deprecated            = DECLARE_UINT64(0x0000000020000000),  /** Property is deprecated.  Read it from an archive, but don't save it. */
  CPF_DataBinding           = DECLARE_UINT64(0x0000000040000000),  /** Indicates that this property should be exposed to data stores */
  CPF_SerializeText         = DECLARE_UINT64(0x0000000080000000),  /** Native property should be serialized as text (ImportText, ExportText), */
  CPF_RepNotify             = DECLARE_UINT64(0x0000000100000000),  /** Notify actors when a property is replicated */
  CPF_Interp                = DECLARE_UINT64(0x0000000200000000),  /** interpolatable property for use with matinee */
  CPF_NonTransactional      = DECLARE_UINT64(0x0000000400000000),  /** Property isn't transacted */
  CPF_EditorOnly            = DECLARE_UINT64(0x0000000800000000),  /** Property should only be loaded in the editor */
  CPF_NotForConsole         = DECLARE_UINT64(0x0000001000000000),  /** Property should not be loaded on console (or be a console cooker commandlet), */
  CPF_RepRetry              = DECLARE_UINT64(0x0000002000000000),  /** retry replication of this property if it fails to be fully sent (e.g. object references not yet available to serialize over the network), */
  CPF_PrivateWrite          = DECLARE_UINT64(0x0000004000000000),  /** property is const outside of the class it was declared in */
  CPF_ProtectedWrite        = DECLARE_UINT64(0x0000008000000000),  /** property is const outside of the class it was declared in and subclasses */
  /** @todo ronp - temporary until we add UArchetypeProperty */
  CPF_ArchetypeProperty     = DECLARE_UINT64(0x0000010000000000),  /** property should be ignored by archives which have ArIgnoreArchetypeRef set */
  CPF_EditHide              = DECLARE_UINT64(0x0000020000000000),  /** property should never be shown in a properties window. */
  CPF_EditTextBox           = DECLARE_UINT64(0x0000040000000000),  /** property can be edited using a text dialog box. */
  CPF_CrossLevelPassive     = DECLARE_UINT64(0x0000100000000000),  /** property can point across levels, and will be serialized properly, but assumes it's target exists in-game (non-editor) */
  CPF_CrossLevelActive      = DECLARE_UINT64(0x0000200000000000),  /** property can point across levels, and will be serialized properly, and will be updated when the target is streamed in/out */
  /** the flags that should never be set on interface properties */
  CPF_InterfaceClearMask    = (CPF_NeedCtorLink|CPF_ExportObject),
  /** a combination of both cross level types */
  CPF_CrossLevel            = (CPF_CrossLevelPassive | CPF_CrossLevelActive),
  /** @name Combinations flags */
  CPF_ParmFlags             = (CPF_OptionalParm | CPF_Parm | CPF_OutParm | CPF_SkipParm | CPF_ReturnParm | CPF_CoerceParm),
  CPF_PropagateFromStruct   = (CPF_Const | CPF_Native | CPF_Transient),
  CPF_PropagateToArrayInner = (CPF_ExportObject | CPF_EditInline | CPF_EditInlineUse | CPF_Localized | CPF_Component | CPF_Config | CPF_AlwaysInit | CPF_EditConst | CPF_Deprecated | CPF_SerializeText | CPF_CrossLevel ),
  CPF_AllFlags              = DECLARE_UINT64(0xFFFFFFFFFFFFFFFF)
} CPF;

/** Enum of different supported reference type tokens. */
typedef enum EGCReferenceType {
  GCRT_None = 0,
  GCRT_Object,
  GCRT_PersistentObject,
  GCRT_ArrayObject,
  GCRT_ArrayStruct,
  GCRT_FixedArray,
  GCRT_EndOfStream,
  GCRT_ScriptDelegate,
} EGCReferenceType;


// File manager.
enum EFileTimes {
  FILETIME_Create				= 0,
  FILETIME_LastAccess			= 1,
  FILETIME_LastWrite			= 2,
};
enum EFileWrite {
  FILEWRITE_NoFail            = 0x01,
  FILEWRITE_NoReplaceExisting = 0x02,
  FILEWRITE_EvenIfReadOnly    = 0x04,
  FILEWRITE_Append            = 0x08,
  FILEWRITE_AllowRead         = 0x10,
  FILEWRITE_SaveGame          = 0x20,  /** The platform needs to create a platform-specific save game file. The passed in path is relative to the "base" of savegames for that platform. */
  FILEWRITE_Async             = 0x40,  /** Attempt to create an async file archive (use the FArchive::IsCloseComplete to tell if it's completed). Supported in only a VERY small set of cases. */
};
enum EFileRead {
  FILEREAD_NoFail   = 0x01,
  FILEREAD_SaveGame = 0x02,  /** The platform needs to load a platform-specific save game file. The passed in path is relative to the "base" of savegames for that platform. */
  FILEREAD_Silent   = 0x04,
};
enum ECopyResult {
  COPY_OK        = 0x00,
  COPY_MiscFail  = 0x01,
  COPY_ReadFail  = 0x02,
  COPY_WriteFail = 0x03,
  COPY_Canceled  = 0x06,
};

enum EFileOpenFlags {
  IO_READ      = 0x01,                  /** Open for reading. */
  IO_WRITE     = 0x02,                  /** Open for writing. */
  IO_READWRITE = (IO_READ | IO_WRITE),  /** Combination of reading and writing. */
  IO_APPEND    = 0x40,                  /** When writing, keep the existing data, set the filepointer to the end of the existing data. */
};

enum EFileSeekFlags {
  IO_SEEK_BEGIN,
  IO_SEEK_CURRENT,
  IO_SEEK_END
};

typedef enum EUglyHackFlags {
	HACK_DisableSubobjectInstancing  = 0x01,
	HACK_ClassLoadingDisabled        = 0x02,  /** Indicates that classes aren't being loaded from disk, thus all classes should be treated as intrinsic classes. */
	HACK_UpdateArchetypeFromInstance = 0x04,
	HACK_KeepSequenceObject          = 0x08,  /** Prevents the code that removes sequences objects from sequences from marking the object pending kill. */
	HACK_IsReloadObjArc              = 0x10,

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
  COMPRESS_None                   = 0x00,  /** No compression. */
  COMPRESS_ZLIB                   = 0x01,  /** Compress with ZLIB. */
  COMPRESS_LZO                    = 0x02,  /** Compress with LZO. */
  COMPRESS_LZX                    = 0x04,  /** Compress with LZX. */
  COMPRESS_BiasMemory             = 0x10,  /** Prefer compression that compresses smaller (ONLY VALID FOR COMPRESSION). */
  COMPRESS_BiasSpeed              = 0x20,  /** Prefer compression that compresses faster (ONLY VALID FOR COMPRESSION). */
  COMPRESS_ForcePPUDecompressZLib = 0x80   /** If this flag is present, decompression will not happen on the SPUs. */
} ECompressionFlags;

/* Accepting connection responses. */
typedef enum EAcceptConnection {
  ACCEPTC_Reject,  /** Reject the connection. */
  ACCEPTC_Accept,  /** Accept the connection. */
  ACCEPTC_Ignore,  /** Ignore it, sending no reply, while server travelling. */
  #define ACCEPTC_Reject            ACCEPTC_Reject
  #define ACCEPTC_Accept            ACCEPTC_Accept
  #define ACCEPTC_Ignore            ACCEPTC_Ignore
  #define EAcceptConnection_Reject  ACCEPTC_Reject
  #define EAcceptConnection_Accept  ACCEPTC_Accept
  #define EAcceptConnection_Ignore  ACCEPTC_Ignore
} EAcceptConnection;
#define EAcceptConnection  EAcceptConnection

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
# define REGISTER_NAME(num,name) NAME_##name = num,
# define REGISTERING_ENUM
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

/** Flags serialized with the bulk data. */
enum EBulkDataFlags {
  BULKDATA_None                            = 0,         /** Empty flag set. */
  BULKDATA_StoreInSeparateFile             = (1 << 0),  /** If set, payload is [going to be] stored in separate file. */
  BULKDATA_SerializeCompressedZLIB         = (1 << 1),  /** If set, payload should be [un]compressed using ZLIB during serialization */
  BULKDATA_ForceSingleElementSerialization = (1 << 2),  /** Force usage of SerializeElement over bulk serialization. */
  BULKDATA_SingleUse                       = (1 << 3),  /** Bulk data is only used once at runtime in the game. */
  BULKDATA_SerializeCompressedLZO          = (1 << 4),  /** If set, payload should be [un]compressed using LZO during serialization */
  BULKDATA_Unused                          = (1 << 5),  /** Bulk data won't be used and doesn't need to be loaded */
  BULKDATA_StoreOnlyPayload                = (1 << 6),  /** If specified, only payload data will be written to archive. */
  BULKDATA_SerializeCompressedLZX          = (1 << 7),  /** If set, payload should be [un]compressed using LZX during serialization */
  BULKDATA_SerializeCompressed             = (BULKDATA_SerializeCompressedZLIB | BULKDATA_SerializeCompressedLZO | BULKDATA_SerializeCompressedLZX),  /** Flag to check if either compression mode is specified */
};

/** Enumeration for bulk data lock status. */
enum EBulkDataLockStatus {
  LOCKSTATUS_Unlocked      = 0,  /** Unlocked array */
  LOCKSTATUS_ReadOnlyLock  = 1,  /** Locked read-only */
  LOCKSTATUS_ReadWriteLock = 2,  /** Locked read-write-realloc */
};

/** Enumeration for bulk data lock behavior. */
enum EBulkDataLockFlags {
  LOCK_READ_ONLY								= 1,
  LOCK_READ_WRITE								= 2,
};

/** Enum of token types. */
enum EGPPTokenType {
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
  PLATFORM_Unknown        =	0x00000000,
  PLATFORM_Windows        =	0x00000001,
  PLATFORM_WindowsServer  =	0x00000002,  /** Windows platform dedicated server mode ("lean and mean" cooked as console without editor support). */
  PLATFORM_Xbox360        =	0x00000004,
  PLATFORM_PS3            =	0x00000008,
  PLATFORM_Linux          =	0x00000010,
  PLATFORM_MacOSX         =	0x00000020,
  PLATFORM_WindowsConsole =	0x00000040,  /** Windows platform cooked as console without editor support. */
  PLATFORM_IPhone         =	0x00000080,
  PLATFORM_NGP            =	0x00000100,
  PLATFORM_Android        =	0x00000200,
  /** Combination Masks */
  PLATFORM_PC             = (PLATFORM_Windows | PLATFORM_WindowsServer | PLATFORM_WindowsConsole | PLATFORM_Linux | PLATFORM_MacOSX),  /** PC platform types */
  PLATFORM_AnyWindows     = (PLATFORM_Windows | PLATFORM_WindowsServer | PLATFORM_WindowsConsole),                                     /** Windows platform types */
  PLATFORM_Console        = (PLATFORM_Xbox360 | PLATFORM_PS3 | PLATFORM_IPhone | PLATFORM_Android | PLATFORM_NGP),                     /** Console platform types */
  PLATFORM_Mobile         = (PLATFORM_IPhone | PLATFORM_Android | PLATFORM_NGP),                                                       /** Mobile platform types */
  PLATFORM_Stripped       = (PLATFORM_Console | PLATFORM_WindowsServer | PLATFORM_WindowsConsole),                                     /** Platforms with data that has been stripped during cooking */
  PLATFORM_OpenGLES2      = (PLATFORM_IPhone | PLATFORM_Android),                                                                      /** Platforms who's vertex data can't be packed into 16-bit floats */
} EPlatformType;

/** Identifier for specifying the type of map check message. */
typedef enum MapCheckType {
  MCTYPE_CRITICALERROR      = 0,
  MCTYPE_ERROR              = 1,
  MCTYPE_PERFORMANCEWARNING = 2,
  MCTYPE_WARNING            = 3,
  MCTYPE_NOTE               = 4,
  MCTYPE_KISMET             = 5,
  MCTYPE_INFO               = 6,
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
enum EUnrealEngineObjectVersion {
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

/* ---------------------------------------------------------- IConsoleManager ! ---------------------------------------------------------- */

/** Bitmask 0x1, 0x2, 0x4, .. */
typedef enum EConsoleVariableFlags {
	/** Default, no flags are set */
	ECVF_Default = 0x0,
	/**
	 * Console variables marked with this flag behave differently in a final release build.
	 * Then they are are hidden in the console and cannot be changed by the user.
	 */
	ECVF_Cheat = 0x1,
	/**
	 * By default, after creation this flag is not set.
	 * Whenever the value was changes through the Set functions the flag is set.
	 * To detect changes:
	 * if(CVar->TestFlags(ECVF_Changed))
	 * {
	 *     CVar->ClearFlags(ECVF_Changed);
	 *     ... 
	 * }
	 * The old value is not stored as this can be easily done by hand and only when needed.
	 */
	ECVF_Changed = 0x2,
	/**
	 * Console variables cannot be changed by the user (from console or from ini file).
	 * Changing from C++ is still possible.
	 */
	ECVF_ReadOnly = 0x4,
	/**
	 * UnregisterConsoleVariable() was called on this one.
	 * If the variable is registered again with the same type this object is reactivated. This is good for DLL unloading.
	 */
	ECVF_Unregistered = 0x8,
  #define ECVF_Default                        ECVF_Default
  #define ECVF_Cheat                          ECVF_Cheat
  #define ECVF_Changed                        ECVF_Changed
  #define ECVF_ReadOnly                       ECVF_ReadOnly
  #define ECVF_Unregistered                   ECVF_Unregistered
  #define EConsoleVariableFlags_Default       ECVF_Default
  #define EConsoleVariableFlags_Cheat         ECVF_Cheat
  #define EConsoleVariableFlags_Changed       ECVF_Changed
  #define EConsoleVariableFlags_ReadOnly      ECVF_ReadOnly
  #define EConsoleVariableFlags_Unregistered  ECVF_Unregistered
} EConsoleVariableFlags;
#define EConsoleVariableFlags  EConsoleVariableFlags

/* ---------------------------------------------------------- AActor ! ---------------------------------------------------------- */

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
  #define PHYS_None                PHYS_None
  #define PHYS_Walking             PHYS_Walking
  #define PHYS_Falling             PHYS_Falling
  #define PHYS_Swimming            PHYS_Swimming
  #define PHYS_Flying              PHYS_Flying
  #define PHYS_Rotating            PHYS_Rotating
  #define PHYS_Projectile          PHYS_Projectile
  #define PHYS_Interpolating       PHYS_Interpolating
  #define PHYS_Spider              PHYS_Spider
  #define PHYS_Ladder              PHYS_Ladder
  #define PHYS_RigidBody           PHYS_RigidBody
  #define PHYS_SoftBody            PHYS_SoftBody
  #define PHYS_NavMeshWalking      PHYS_NavMeshWalking
  #define PHYS_Unused              PHYS_Unused
  #define PHYS_Custom              PHYS_Custom
  #define PHYS_MAX                 PHYS_MAX
  #define EPhysics_None            PHYS_None
  #define EPhysics_Walking         PHYS_Walking
  #define EPhysics_Falling         PHYS_Falling
  #define EPhysics_Swimming        PHYS_Swimming
  #define EPhysics_Flying          PHYS_Flying
  #define EPhysics_Rotating        PHYS_Rotating
  #define EPhysics_Projectile      PHYS_Projectile
  #define EPhysics_Interpolating   PHYS_Interpolating
  #define EPhysics_Spider          PHYS_Spider
  #define EPhysics_Ladder          PHYS_Ladder
  #define EPhysics_RigidBody       PHYS_RigidBody
  #define EPhysics_SoftBody        PHYS_SoftBody
  #define EPhysics_NavMeshWalking  PHYS_NavMeshWalking
  #define EPhysics_Unused          PHYS_Unused
  #define EPhysics_Custom          PHYS_Custom
  #define EPhysics_MAX             PHYS_MAX
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
  #define MD_Stationary        MD_Stationary
  #define MD_Forward           MD_Forward
  #define MD_Backward          MD_Backward
  #define MD_Left              MD_Left
  #define MD_Right             MD_Right
  #define MD_Up                MD_Up
  #define MD_Down              MD_Down
  #define MD_MAX               MD_MAX
  #define EMoveDir_Stationary  MD_Stationary
  #define EMoveDir_Forward     MD_Forward
  #define EMoveDir_Backward    MD_Backward
  #define EMoveDir_Left        MD_Left
  #define EMoveDir_Right       MD_Right
  #define EMoveDir_Up          MD_Up
  #define EMoveDir_Down        MD_Down
  #define EMoveDir_MAX         MD_MAX
} EMoveDir;
typedef enum EActorMetricsType : unsigned char {
  METRICS_VERTS,                  // 0
  METRICS_TRIS,                   // 1
  METRICS_SECTIONS,               // 2
  METRICS_MAX                     // 3
  #define METRICS_VERTS               METRICS_VERTS
  #define METRICS_TRIS                METRICS_TRIS
  #define METRICS_SECTIONS            METRICS_SECTIONS
  #define METRICS_MAX                 METRICS_MAX
  #define EActorMetricsType_VERTS     METRICS_VERTS
  #define EActorMetricsType_TRIS      METRICS_TRIS
  #define EActorMetricsType_SECTIONS  METRICS_SECTIONS
  #define EActorMetricsType_MAX       METRICS_MAX
} EActorMetricsType;
typedef enum ENetRole          : unsigned char {
  ROLE_None,                      // 0
  ROLE_SimulatedProxy,            // 1
  ROLE_AutonomousProxy,           // 2
  ROLE_Authority,                 // 3
  ROLE_MAX                        // 4
  #define ROLE_None                 ROLE_None
  #define ROLE_SimulatedProxy       ROLE_SimulatedProxy
  #define ROLE_AutonomousProxy      ROLE_AutonomousProxy
  #define ROLE_Authority            ROLE_Authority
  #define ROLE_MAX                  ROLE_MAX
  #define ENetRole_None             ROLE_None
  #define ENetRole_SimulatedProxy   ROLE_SimulatedProxy
  #define ENetRole_AutonomousProxy  ROLE_AutonomousProxy
  #define ENetRole_Authority        ROLE_Authority
  #define ENetRole_MAX              ROLE_MAX
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
  #define COLLIDE_CustomDefault                COLLIDE_CustomDefault
  #define COLLIDE_NoCollision                  COLLIDE_NoCollision
  #define COLLIDE_BlockAll                     COLLIDE_BlockAll
  #define COLLIDE_BlockWeapons                 COLLIDE_BlockWeapons
  #define COLLIDE_TouchAll                     COLLIDE_TouchAll
  #define COLLIDE_TouchWeapons                 COLLIDE_TouchWeapons
  #define COLLIDE_BlockAllButWeapons           COLLIDE_BlockAllButWeapons
  #define COLLIDE_TouchAllButWeapons           COLLIDE_TouchAllButWeapons
  #define COLLIDE_BlockWeaponsKickable         COLLIDE_BlockWeaponsKickable
  #define COLLIDE_BlockAllButVehicles          COLLIDE_BlockAllButVehicles
  #define COLLIDE_MAX                          COLLIDE_MAX
  #define ECollisionType_CustomDefault         COLLIDE_CustomDefault
  #define ECollisionType_NoCollision           COLLIDE_NoCollision
  #define ECollisionType_BlockAll              COLLIDE_BlockAll
  #define ECollisionType_BlockWeapons          COLLIDE_BlockWeapons
  #define ECollisionType_TouchAll              COLLIDE_TouchAll
  #define ECollisionType_TouchWeapons          COLLIDE_TouchWeapons
  #define ECollisionType_BlockAllButWeapons    COLLIDE_BlockAllButWeapons
  #define ECollisionType_TouchAllButWeapons    COLLIDE_TouchAllButWeapons
  #define ECollisionType_BlockWeaponsKickable  COLLIDE_BlockWeaponsKickable
  #define ECollisionType_BlockAllButVehicles   COLLIDE_BlockAllButVehicles
  #define ECollisionType_MAX                   COLLIDE_MAX
} ECollisionType;
typedef enum ETravelType       : unsigned char {
  TRAVEL_Absolute,                // 0
  TRAVEL_Partial,                 // 1
  TRAVEL_Relative,                // 2
  TRAVEL_MAX                      // 3
  #define TRAVEL_Absolute       TRAVEL_Absolute
  #define TRAVEL_Partial        TRAVEL_Partial
  #define TRAVEL_Relative       TRAVEL_Relative
  #define TRAVEL_MAX            TRAVEL_MAX
  #define ETravelType_Absolute  TRAVEL_Absolute
  #define ETravelType_Partial   TRAVEL_Partial
  #define ETravelType_Relative  TRAVEL_Relative
  #define ETravelType_MAX       TRAVEL_MAX
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
  #define DCLICK_None              DCLICK_None
  #define DCLICK_Left              DCLICK_Left
  #define DCLICK_Right             DCLICK_Right
  #define DCLICK_Forward           DCLICK_Forward
  #define DCLICK_Back              DCLICK_Back
  #define DCLICK_Active            DCLICK_Active
  #define DCLICK_Done              DCLICK_Done
  #define DCLICK_MAX               DCLICK_MAX
  #define EDoubleClickDir_None     DCLICK_None
  #define EDoubleClickDir_Left     DCLICK_Left
  #define EDoubleClickDir_Right    DCLICK_Right
  #define EDoubleClickDir_Forward  DCLICK_Forward
  #define EDoubleClickDir_Back     DCLICK_Back
  #define EDoubleClickDir_Active   DCLICK_Active
  #define EDoubleClickDir_Done     DCLICK_Done
  #define EDoubleClickDir_MAX      DCLICK_MAX
} EDoubleClickDir;
#define EPhysics           EPhysics
#define EMoveDir           EMoveDir
#define EActorMetricsType  EActorMetricsType
#define ENetRole           ENetRole
#define ECollisionType     ECollisionType
#define ETravelType        ETravelType
#define EDoubleClickDir    EDoubleClickDir

/* ---------------------------------------------------------- ABrush ! ---------------------------------------------------------- */

typedef enum ECsgOper : unsigned char {
  CSG_Active      = 0,
  CSG_Add         = 1,
  CSG_Subtract    = 2,
  CSG_Intersect   = 3,
  CSG_Deintersect = 4,
  CSG_MAX         = 5
  #define CSG_Active            CSG_Active
  #define CSG_Add               CSG_Add
  #define CSG_Subtract          CSG_Subtract
  #define CSG_Intersect         CSG_Intersect
  #define CSG_Deintersect       CSG_Deintersect
  #define CSG_MAX               CSG_MAX
  #define ECsgOper_Active       CSG_Active
  #define ECsgOper_Add          CSG_Add
  #define ECsgOper_Subtract     CSG_Subtract
  #define ECsgOper_Intersect    CSG_Intersect
  #define ECsgOper_Deintersect  CSG_Deintersect
  #define ECsgOper_MAX          CSG_MAX
} ECsgOper;
#define ECsgOper  ECsgOper

/* ---------------------------------------------------------- ACamera ! ---------------------------------------------------------- */

typedef enum EViewTargetBlendFunction : unsigned char {
  VTBlend_Linear,                 // 0
  VTBlend_Cubic,                  // 1
  VTBlend_EaseIn,                 // 2
  VTBlend_EaseOut,                // 3
  VTBlend_EaseInOut,              // 4
  VTBlend_MAX                     // 5
  #define VTBlend_Linear                      VTBlend_Linear
  #define VTBlend_Cubic                       VTBlend_Cubic
  #define VTBlend_EaseIn                      VTBlend_EaseIn
  #define VTBlend_EaseOut                     VTBlend_EaseOut
  #define VTBlend_EaseInOut                   VTBlend_EaseInOut
  #define VTBlend_MAX                         VTBlend_MAX
  #define EViewTargetBlendFunction_Linear     VTBlend_Linear
  #define EViewTargetBlendFunction_Cubic      VTBlend_Cubic
  #define EViewTargetBlendFunction_EaseIn     VTBlend_EaseIn
  #define EViewTargetBlendFunction_EaseOut    VTBlend_EaseOut
  #define EViewTargetBlendFunction_EaseInOut  VTBlend_EaseInOut
  #define EViewTargetBlendFunction_MAX        VTBlend_MAX
} EViewTargetBlendFunction;
typedef enum ECameraAnimPlaySpace     : unsigned char {
  CAPS_CameraLocal,               // 0
  CAPS_World,                     // 1
  CAPS_UserDefined,               // 2
  CAPS_MAX                        // 3
  #define CAPS_CameraLocal                  CAPS_CameraLocal
  #define CAPS_World                        CAPS_World
  #define CAPS_UserDefined                  CAPS_UserDefined
  #define CAPS_MAX                          CAPS_MAX
  #define ECameraAnimPlaySpace_CameraLocal  CAPS_CameraLocal
  #define ECameraAnimPlaySpace_World        CAPS_World
  #define ECameraAnimPlaySpace_UserDefined  CAPS_UserDefined
  #define ECameraAnimPlaySpace_MAX          CAPS_MAX
} ECameraAnimPlaySpace;
#define EViewTargetBlendFunction  EViewTargetBlendFunction
#define ECameraAnimPlaySpace      ECameraAnimPlaySpace

/* ---------------------------------------------------------- UPrimitiveComponent ! ---------------------------------------------------------- */

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
  #define RBCC_Default                                              RBCC_Default
  #define RBCC_Nothing                                              RBCC_Nothing
  #define RBCC_Pawn                                                 RBCC_Pawn
  #define RBCC_Vehicle                                              RBCC_Vehicle
  #define RBCC_Water                                                RBCC_Water
  #define RBCC_GameplayPhysics                                      RBCC_GameplayPhysics
  #define RBCC_EffectPhysics                                        RBCC_EffectPhysics
  #define RBCC_Untitled1                                            RBCC_Untitled1
  #define RBCC_Untitled2                                            RBCC_Untitled2
  #define RBCC_TossedItems                                          RBCC_TossedItems
  #define RBCC_TossedItemsPlayerVehicle                             RBCC_TossedItemsPlayerVehicle
  #define RBCC_Cloth                                                RBCC_Cloth
  #define RBCC_FluidDrain                                           RBCC_FluidDrain
  #define RBCC_SoftBody                                             RBCC_SoftBody
  #define RBCC_FracturedMeshPart                                    RBCC_FracturedMeshPart
  #define RBCC_BlockingVolume                                       RBCC_BlockingVolume
  #define RBCC_DeadPawn                                             RBCC_DeadPawn
  #define RBCC_Clothing                                             RBCC_Clothing
  #define RBCC_ClothingCollision                                    RBCC_ClothingCollision
  #define RBCC_TossedItemsEnemyVehicle                              RBCC_TossedItemsEnemyVehicle
  #define RBCC_PlayerVehicle                                        RBCC_PlayerVehicle
  #define RBCC_EnemyVehicle                                         RBCC_EnemyVehicle
  #define RBCC_PlayerVehicleEnemyVehicle                            RBCC_PlayerVehicleEnemyVehicle
  #define RBCC_TossedItemsPlayerVehicleEnemyVehicle                 RBCC_TossedItemsPlayerVehicleEnemyVehicle
  #define RBCC_WillowPickup                                         RBCC_WillowPickup
  #define RBCC_MAX                                                  RBCC_MAX
  #define ERBCollisionChannel_Default                               RBCC_Default
  #define ERBCollisionChannel_Nothing                               RBCC_Nothing
  #define ERBCollisionChannel_Pawn                                  RBCC_Pawn
  #define ERBCollisionChannel_Vehicle                               RBCC_Vehicle
  #define ERBCollisionChannel_Water                                 RBCC_Water
  #define ERBCollisionChannel_GameplayPhysics                       RBCC_GameplayPhysics
  #define ERBCollisionChannel_EffectPhysics                         RBCC_EffectPhysics
  #define ERBCollisionChannel_Untitled1                             RBCC_Untitled1
  #define ERBCollisionChannel_Untitled2                             RBCC_Untitled2
  #define ERBCollisionChannel_TossedItems                           RBCC_TossedItems
  #define ERBCollisionChannel_TossedItemsPlayerVehicle              RBCC_TossedItemsPlayerVehicle
  #define ERBCollisionChannel_Cloth                                 RBCC_Cloth
  #define ERBCollisionChannel_FluidDrain                            RBCC_FluidDrain
  #define ERBCollisionChannel_SoftBody                              RBCC_SoftBody
  #define ERBCollisionChannel_FracturedMeshPart                     RBCC_FracturedMeshPart
  #define ERBCollisionChannel_BlockingVolume                        RBCC_BlockingVolume
  #define ERBCollisionChannel_DeadPawn                              RBCC_DeadPawn
  #define ERBCollisionChannel_Clothing                              RBCC_Clothing
  #define ERBCollisionChannel_ClothingCollision                     RBCC_ClothingCollision
  #define ERBCollisionChannel_TossedItemsEnemyVehicle               RBCC_TossedItemsEnemyVehicle
  #define ERBCollisionChannel_PlayerVehicle                         RBCC_PlayerVehicle
  #define ERBCollisionChannel_EnemyVehicle                          RBCC_EnemyVehicle
  #define ERBCollisionChannel_PlayerVehicleEnemyVehicle             RBCC_PlayerVehicleEnemyVehicle
  #define ERBCollisionChannel_TossedItemsPlayerVehicleEnemyVehicle  RBCC_TossedItemsPlayerVehicleEnemyVehicle
  #define ERBCollisionChannel_WillowPickup                          RBCC_WillowPickup
  #define ERBCollisionChannel_MAX                                   RBCC_MAX
} ERBCollisionChannel;
typedef enum EDynamicShadowCastRelevance : unsigned char {
  SHADOWCAST_Uninitialized,       // 0
  SHADOWCAST_Always,              // 1
  ShadowCast_Far,                 // 2
  ShadowCast_Near,                // 3
  SHADOWCAST_Never,               // 4
  EDynamicShadowCastRelevance_MAX // 5
  #define SHADOWCAST_Uninitialized                   SHADOWCAST_Uninitialized
  #define SHADOWCAST_Always                          SHADOWCAST_Always
  #define ShadowCast_Far                             ShadowCast_Far
  #define ShadowCast_Near                            ShadowCast_Near
  #define SHADOWCAST_Never                           SHADOWCAST_Never
  #define EDynamicShadowCastRelevance_Uninitialized  SHADOWCAST_Uninitialized
  #define EDynamicShadowCastRelevance_Always         SHADOWCAST_Always
  #define EDynamicShadowCastRelevance_Far            ShadowCast_Far
  #define EDynamicShadowCastRelevance_Near           ShadowCast_Near
  #define EDynamicShadowCastRelevance_Never          SHADOWCAST_Never
  #define EDynamicShadowCastRelevance_MAX            EDynamicShadowCastRelevance_MAX
} EDynamicShadowCastRelevance;
typedef enum EOverrideStaticShadow       : unsigned char {
  OSS_NoOverride,                 // 0
  OSS_CastButDontReceiveStatic,   // 1
  OSS_CastAndReceiveStatic,       // 2
  EOverrideStaticShadow_MAX       // 3
  #define OSS_NoOverride                                  OSS_NoOverride
  #define OSS_CastButDontReceiveStatic                    OSS_CastButDontReceiveStatic
  #define OSS_CastAndReceiveStatic                        OSS_CastAndReceiveStatic
  #define EOverrideStaticShadow_NoOverride                OSS_NoOverride
  #define EOverrideStaticShadow_CastButDontReceiveStatic  OSS_CastButDontReceiveStatic
  #define EOverrideStaticShadow_CastAndReceiveStatic      OSS_CastAndReceiveStatic
  #define EOverrideStaticShadow_MAX                       EOverrideStaticShadow_MAX
} EOverrideStaticShadow;
typedef enum GJKResult                   : unsigned char {
  GJK_Intersect,                  // 0
  GJK_NoIntersection,             // 1
  GJK_Fail,                       // 2
  GJK_MAX                         // 3
  #define GJK_Intersect             GJK_Intersect
  #define GJK_NoIntersection        GJK_NoIntersection
  #define GJK_Fail                  GJK_Fail
  #define GJK_MAX                   GJK_MAX
  #define GJKResult_Intersect       GJK_Intersect
  #define GJKResult_NoIntersection  GJK_NoIntersection
  #define GJKResult_Fail            GJK_Fail
  #define GJKResult_MAX             GJK_MAX
} GJKResult;
typedef enum ERadialImpulseFalloff       : unsigned char {
  RIF_Constant,                   // 0
  RIF_Linear,                     // 1
  RIF_MAX                         // 2
  #define RIF_Constant                    RIF_Constant
  #define RIF_Linear                      RIF_Linear
  #define RIF_MAX                         RIF_MAX
  #define ERadialImpulseFalloff_Constant  RIF_Constant
  #define ERadialImpulseFalloff_Linear    RIF_Linear
  #define ERadialImpulseFalloff_MAX       RIF_MAX
} ERadialImpulseFalloff;
#define ERBCollisionChannel          ERBCollisionChannel
#define EDynamicShadowCastRelevance  EDynamicShadowCastRelevance
#define EOverrideStaticShadow        EOverrideStaticShadow
#define GJKResult                    GJKResult
#define ERadialImpulseFalloff        ERadialImpulseFalloff

/* ---------------------------------------------------------- AWillowHUD ! ---------------------------------------------------------- */

typedef enum EHUDPickupCardType   : unsigned char {
  HUDPickupCard_Weapon,           // 0
  HUDPickupCard_Shield,           // 1
  HUDPickupCard_GrenadeMod,       // 2
  HUDPickupCard_ClassMod,         // 3
  HUDPickupCard_Artifact,         // 4
  HUDPickupCard_Item,             // 5
  HUDPickupCard_MAX               // 6
  #define HUDPickupCard_Weapon           HUDPickupCard_Weapon
  #define HUDPickupCard_Shield           HUDPickupCard_Shield
  #define HUDPickupCard_GrenadeMod       HUDPickupCard_GrenadeMod
  #define HUDPickupCard_ClassMod         HUDPickupCard_ClassMod
  #define HUDPickupCard_Artifact         HUDPickupCard_Artifact
  #define HUDPickupCard_Item             HUDPickupCard_Item
  #define HUDPickupCard_MAX              HUDPickupCard_MAX
  #define EHUDPickupCardType_Weapon      HUDPickupCard_Weapon
  #define EHUDPickupCardType_Shield      HUDPickupCard_Shield
  #define EHUDPickupCardType_GrenadeMod  HUDPickupCard_GrenadeMod
  #define EHUDPickupCardType_ClassMod    HUDPickupCard_ClassMod
  #define EHUDPickupCardType_Artifact    HUDPickupCard_Artifact
  #define EHUDPickupCardType_Item        HUDPickupCard_Item
  #define EHUDPickupCardType_MAX         HUDPickupCard_MAX
} EHUDPickupCardType;
typedef enum EHUDEquippedCardType : unsigned char {
  HUDEquippedCard_Weapon,         // 0
  HUDEquippedCard_Shield,         // 1
  HUDEquippedCard_GrenadeMod,     // 2
  HUDEquippedCard_ClassMod,       // 3
  HUDEquippedCard_Artifact,       // 4
  HUDEquippedCard_MAX             // 5
  #define HUDEquippedCard_Weapon           HUDEquippedCard_Weapon
  #define HUDEquippedCard_Shield           HUDEquippedCard_Shield
  #define HUDEquippedCard_GrenadeMod       HUDEquippedCard_GrenadeMod
  #define HUDEquippedCard_ClassMod         HUDEquippedCard_ClassMod
  #define HUDEquippedCard_Artifact         HUDEquippedCard_Artifact
  #define HUDEquippedCard_MAX              HUDEquippedCard_MAX
  #define EHUDEquippedCardType_Weapon      HUDEquippedCard_Weapon
  #define EHUDEquippedCardType_Shield      HUDEquippedCard_Shield
  #define EHUDEquippedCardType_GrenadeMod  HUDEquippedCard_GrenadeMod
  #define EHUDEquippedCardType_ClassMod    HUDEquippedCard_ClassMod
  #define EHUDEquippedCardType_Artifact    HUDEquippedCard_Artifact
  #define EHUDEquippedCardType_MAX         HUDEquippedCard_MAX
} EHUDEquippedCardType;
typedef enum EColiseumUpdateMode  : unsigned char {
  E_Toggle,                       // 0
  E_TurnOff,                      // 1
  E_TurnOn,                       // 2
  E_MAX                           // 3
  #define E_Toggle                     E_Toggle
  #define E_TurnOff                    E_TurnOff
  #define E_TurnOn                     E_TurnOn
  #define E_MAX                        E_MAX
  #define EColiseumUpdateMode_Toggle   E_Toggle
  #define EColiseumUpdateMode_TurnOff  E_TurnOff
  #define EColiseumUpdateMode_TurnOn   E_TurnOn
  #define EColiseumUpdateMode_MAX      E_MAX
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
  #define ECDL_Ten                ECDL_Ten
  #define ECDL_Five               ECDL_Five
  #define ECDL_Four               ECDL_Four
  #define ECDL_Three              ECDL_Three
  #define ECDL_Two                ECDL_Two
  #define ECDL_One                ECDL_One
  #define ECDL_None               ECDL_None
  #define ECDL_MAX                ECDL_MAX
  #define ECountDownLength_Ten    ECDL_Ten
  #define ECountDownLength_Five   ECDL_Five
  #define ECountDownLength_Four   ECDL_Four
  #define ECountDownLength_Three  ECDL_Three
  #define ECountDownLength_Two    ECDL_Two
  #define ECountDownLength_One    ECDL_One
  #define ECountDownLength_None   ECDL_None
  #define ECountDownLength_MAX    ECDL_MAX
} ECountDownLength;
typedef enum EColiseumNotifyType  : unsigned char {
  ECNT_Resupply,                  // 0
  ECNT_Refill,                    // 1
  ECNT_WaveEnded,                 // 2
  ECNT_MAX                        // 3
  #define ECNT_Resupply                  ECNT_Resupply
  #define ECNT_Refill                    ECNT_Refill
  #define ECNT_WaveEnded                 ECNT_WaveEnded
  #define ECNT_MAX                       ECNT_MAX
  #define EColiseumNotifyType_Resupply   ECNT_Resupply
  #define EColiseumNotifyType_Refill     ECNT_Refill
  #define EColiseumNotifyType_WaveEnded  ECNT_WaveEnded
  #define EColiseumNotifyType_MAX        ECNT_MAX
} EColiseumNotifyType;
#define EHUDPickupCardType    EHUDPickupCardType
#define EHUDEquippedCardType  EHUDEquippedCardType
#define EColiseumUpdateMode   EColiseumUpdateMode
#define ECountDownLength      ECountDownLength
#define EColiseumNotifyType   EColiseumNotifyType

/* ---------------------------------------------------------- APlayerController ! ---------------------------------------------------------- */

typedef enum EInputTypes          : unsigned char {
  IT_XAxis,                       // 0
  IT_YAxis,                       // 1
  IT_MAX                          // 2
  #define IT_XAxis           IT_XAxis
  #define IT_YAxis           IT_YAxis
  #define IT_MAX             IT_MAX
  #define EInputTypes_XAxis  IT_XAxis
  #define EInputTypes_YAxis  IT_YAxis
  #define EInputTypes_MAX    IT_MAX
} EInputTypes;
typedef enum EInputMatchAction    : unsigned char {
  IMA_GreaterThan,                // 0
  IMA_LessThan,                   // 1
  IMA_MAX                         // 2
  #define IMA_GreaterThan                IMA_GreaterThan
  #define IMA_LessThan                   IMA_LessThan
  #define IMA_MAX                        IMA_MAX
  #define EInputMatchAction_GreaterThan  IMA_GreaterThan
  #define EInputMatchAction_LessThan     IMA_LessThan
  #define EInputMatchAction_MAX          IMA_MAX
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
  #define PMT_Clear                                      PMT_Clear
  #define PMT_Information                                PMT_Information
  #define PMT_AdminMessage                               PMT_AdminMessage
  #define PMT_DownloadProgress                           PMT_DownloadProgress
  #define PMT_ConnectionFailure                          PMT_ConnectionFailure
  #define PMT_PeerConnectionFailure                      PMT_PeerConnectionFailure
  #define PMT_PeerHostMigrationFailure                   PMT_PeerHostMigrationFailure
  #define PMT_SocketFailure                              PMT_SocketFailure
  #define PMT_MAX                                        PMT_MAX
  #define EProgressMessageType_Clear                     PMT_Clear
  #define EProgressMessageType_Information               PMT_Information
  #define EProgressMessageType_AdminMessage              PMT_AdminMessage
  #define EProgressMessageType_DownloadProgress          PMT_DownloadProgress
  #define EProgressMessageType_ConnectionFailure         PMT_ConnectionFailure
  #define EProgressMessageType_PeerConnectionFailure     PMT_PeerConnectionFailure
  #define EProgressMessageType_PeerHostMigrationFailure  PMT_PeerHostMigrationFailure
  #define EProgressMessageType_SocketFailure             PMT_SocketFailure
  #define EProgressMessageType_MAX                       PMT_MAX
} EProgressMessageType;
#define EInputTypes           EInputTypes
#define EInputMatchAction     EInputMatchAction
#define EProgressMessageType  EProgressMessageType

/* ---------------------------------------------------------- UInteractionIconDefinition ! ---------------------------------------------------------- */

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
  #define INTERACTION_ICON_None                     INTERACTION_ICON_None
  #define INTERACTION_ICON_Use                      INTERACTION_ICON_Use
  #define INTERACTION_ICON_Talk                     INTERACTION_ICON_Talk
  #define INTERACTION_ICON_Heal                     INTERACTION_ICON_Heal
  #define INTERACTION_ICON_Shop                     INTERACTION_ICON_Shop
  #define INTERACTION_ICON_Computer                 INTERACTION_ICON_Computer
  #define INTERACTION_ICON_Driver                   INTERACTION_ICON_Driver
  #define INTERACTION_ICON_Gunner                   INTERACTION_ICON_Gunner
  #define INTERACTION_ICON_Smash                    INTERACTION_ICON_Smash
  #define INTERACTION_ICON_CannotUse                INTERACTION_ICON_CannotUse
  #define INTERACTION_ICON_FlipVehicle              INTERACTION_ICON_FlipVehicle
  #define INTERACTION_ICON_VehicleMiddleLeftSeat    INTERACTION_ICON_VehicleMiddleLeftSeat
  #define INTERACTION_ICON_VehicleMiddleRightSeat   INTERACTION_ICON_VehicleMiddleRightSeat
  #define INTERACTION_ICON_Open                     INTERACTION_ICON_Open
  #define INTERACTION_ICON_Trade                    INTERACTION_ICON_Trade
  #define INTERACTION_ICON_Objective                INTERACTION_ICON_Objective
  #define INTERACTION_ICON_PickUp                   INTERACTION_ICON_PickUp
  #define INTERACTION_ICON_Full                     INTERACTION_ICON_Full
  #define INTERACTION_ICON_FullFadeOut              INTERACTION_ICON_FullFadeOut
  #define INTERACTION_ICON_MAX                      INTERACTION_ICON_MAX
  #define EInteractionIcons_None                    INTERACTION_ICON_None
  #define EInteractionIcons_Use                     INTERACTION_ICON_Use
  #define EInteractionIcons_Talk                    INTERACTION_ICON_Talk
  #define EInteractionIcons_Heal                    INTERACTION_ICON_Heal
  #define EInteractionIcons_Shop                    INTERACTION_ICON_Shop
  #define EInteractionIcons_Computer                INTERACTION_ICON_Computer
  #define EInteractionIcons_Driver                  INTERACTION_ICON_Driver
  #define EInteractionIcons_Gunner                  INTERACTION_ICON_Gunner
  #define EInteractionIcons_Smash                   INTERACTION_ICON_Smash
  #define EInteractionIcons_CannotUse               INTERACTION_ICON_CannotUse
  #define EInteractionIcons_FlipVehicle             INTERACTION_ICON_FlipVehicle
  #define EInteractionIcons_VehicleMiddleLeftSeat   INTERACTION_ICON_VehicleMiddleLeftSeat
  #define EInteractionIcons_VehicleMiddleRightSeat  INTERACTION_ICON_VehicleMiddleRightSeat
  #define EInteractionIcons_Open                    INTERACTION_ICON_Open
  #define EInteractionIcons_Trade                   INTERACTION_ICON_Trade
  #define EInteractionIcons_Objective               INTERACTION_ICON_Objective
  #define EInteractionIcons_PickUp                  INTERACTION_ICON_PickUp
  #define EInteractionIcons_Full                    INTERACTION_ICON_Full
  #define EInteractionIcons_FullFadeOut             INTERACTION_ICON_FullFadeOut
  #define EInteractionIcons_MAX                     INTERACTION_ICON_MAX
} EInteractionIcons;
#define EInteractionIcons  EInteractionIcons

/* ---------------------------------------------------------- AWorldInfo ! ---------------------------------------------------------- */

typedef enum ENetMode                  : unsigned char {
  NM_Standalone,                  // 0
  NM_DedicatedServer,             // 1
  NM_ListenServer,                // 2
  NM_Client,                      // 3
  NM_MAX                          // 4
  #define NM_Standalone             NM_Standalone
  #define NM_DedicatedServer        NM_DedicatedServer
  #define NM_ListenServer           NM_ListenServer
  #define NM_Client                 NM_Client
  #define NM_MAX                    NM_MAX
  #define ENetMode_Standalone       NM_Standalone
  #define ENetMode_DedicatedServer  NM_DedicatedServer
  #define ENetMode_ListenServer     NM_ListenServer
  #define ENetMode_Client           NM_Client
  #define ENetMode_MAX              NM_MAX
} ENetMode;
typedef enum EConsoleType              : unsigned char {
  CONSOLE_Any,                    // 0
  CONSOLE_Xbox360,                // 1
  CONSOLE_PS3,                    // 2
  CONSOLE_Mobile,                 // 3
  CONSOLE_IPhone,                 // 4
  CONSOLE_Android,                // 5
  CONSOLE_MAX                     // 6
  #define CONSOLE_Any           CONSOLE_Any
  #define CONSOLE_Xbox360       CONSOLE_Xbox360
  #define CONSOLE_PS3           CONSOLE_PS3
  #define CONSOLE_Mobile        CONSOLE_Mobile
  #define CONSOLE_IPhone        CONSOLE_IPhone
  #define CONSOLE_Android       CONSOLE_Android
  #define CONSOLE_MAX           CONSOLE_MAX
  #define EConsoleType_Any      CONSOLE_Any
  #define EConsoleType_Xbox360  CONSOLE_Xbox360
  #define EConsoleType_PS3      CONSOLE_PS3
  #define EConsoleType_Mobile   CONSOLE_Mobile
  #define EConsoleType_IPhone   CONSOLE_IPhone
  #define EConsoleType_Android  CONSOLE_Android
  #define EConsoleType_MAX      CONSOLE_MAX
} EConsoleType;
typedef enum EVisibilityAggressiveness : unsigned char {
  VIS_LeastAggressive,            // 0
  VIS_ModeratelyAggressive,       // 1
  VIS_MostAggressive,             // 2
  VIS_Max                         // 3
  #define VIS_LeastAggressive                             VIS_LeastAggressive
  #define VIS_ModeratelyAggressive                        VIS_ModeratelyAggressive
  #define VIS_MostAggressive                              VIS_MostAggressive
  #define VIS_Max                                         VIS_Max
  #define EVisibilityAggressiveness_LeastAggressive       VIS_LeastAggressive
  #define EVisibilityAggressiveness_ModeratelyAggressive  VIS_ModeratelyAggressive
  #define EVisibilityAggressiveness_MostAggressive        VIS_MostAggressive
  #define EVisibilityAggressiveness_Max                   VIS_Max
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
  #define HostMigration_None                        HostMigration_None
  #define HostMigration_FindingNewHost              HostMigration_FindingNewHost
  #define HostMigration_MigratingAsHost             HostMigration_MigratingAsHost
  #define HostMigration_MigratingAsClient           HostMigration_MigratingAsClient
  #define HostMigration_ClientTravel                HostMigration_ClientTravel
  #define HostMigration_HostReadyToTravel           HostMigration_HostReadyToTravel
  #define HostMigration_Failed                      HostMigration_Failed
  #define HostMigration_MAX                         HostMigration_MAX
  #define EHostMigrationProgress_None               HostMigration_None
  #define EHostMigrationProgress_FindingNewHost     HostMigration_FindingNewHost
  #define EHostMigrationProgress_MigratingAsHost    HostMigration_MigratingAsHost
  #define EHostMigrationProgress_MigratingAsClient  HostMigration_MigratingAsClient
  #define EHostMigrationProgress_ClientTravel       HostMigration_ClientTravel
  #define EHostMigrationProgress_HostReadyToTravel  HostMigration_HostReadyToTravel
  #define EHostMigrationProgress_Failed             HostMigration_Failed
  #define EHostMigrationProgress_MAX                HostMigration_MAX
} EHostMigrationProgress;
#define ENetMode                   ENetMode
#define EConsoleType               EConsoleType
#define EVisibilityAggressiveness  EVisibilityAggressiveness
#define EHostMigrationProgress     EHostMigrationProgress

/* ---------------------------------------------------------- ReverbVolume ! ---------------------------------------------------------- */

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
  #define REVERB_Default              REVERB_Default
  #define REVERB_Bathroom             REVERB_Bathroom
  #define REVERB_StoneRoom            REVERB_StoneRoom
  #define REVERB_Auditorium           REVERB_Auditorium
  #define REVERB_ConcertHall          REVERB_ConcertHall
  #define REVERB_Cave                 REVERB_Cave
  #define REVERB_Hallway              REVERB_Hallway
  #define REVERB_StoneCorridor        REVERB_StoneCorridor
  #define REVERB_Alley                REVERB_Alley
  #define REVERB_Forest               REVERB_Forest
  #define REVERB_City                 REVERB_City
  #define REVERB_Mountains            REVERB_Mountains
  #define REVERB_Quarry               REVERB_Quarry
  #define REVERB_Plain                REVERB_Plain
  #define REVERB_ParkingLot           REVERB_ParkingLot
  #define REVERB_SewerPipe            REVERB_SewerPipe
  #define REVERB_Underwater           REVERB_Underwater
  #define REVERB_SmallRoom            REVERB_SmallRoom
  #define REVERB_MediumRoom           REVERB_MediumRoom
  #define REVERB_LargeRoom            REVERB_LargeRoom
  #define REVERB_MediumHall           REVERB_MediumHall
  #define REVERB_LargeHall            REVERB_LargeHall
  #define REVERB_Plate                REVERB_Plate
  #define REVERB_MAX                  REVERB_MAX
  #define ReverbPreset_Default        REVERB_Default
  #define ReverbPreset_Bathroom       REVERB_Bathroom
  #define ReverbPreset_StoneRoom      REVERB_StoneRoom
  #define ReverbPreset_Auditorium     REVERB_Auditorium
  #define ReverbPreset_ConcertHall    REVERB_ConcertHall
  #define ReverbPreset_Cave           REVERB_Cave
  #define ReverbPreset_Hallway        REVERB_Hallway
  #define ReverbPreset_StoneCorridor  REVERB_StoneCorridor
  #define ReverbPreset_Alley          REVERB_Alley
  #define ReverbPreset_Forest         REVERB_Forest
  #define ReverbPreset_City           REVERB_City
  #define ReverbPreset_Mountains      REVERB_Mountains
  #define ReverbPreset_Quarry         REVERB_Quarry
  #define ReverbPreset_Plain          REVERB_Plain
  #define ReverbPreset_ParkingLot     REVERB_ParkingLot
  #define ReverbPreset_SewerPipe      REVERB_SewerPipe
  #define ReverbPreset_Underwater     REVERB_Underwater
  #define ReverbPreset_SmallRoom      REVERB_SmallRoom
  #define ReverbPreset_MediumRoom     REVERB_MediumRoom
  #define ReverbPreset_LargeRoom      REVERB_LargeRoom
  #define ReverbPreset_MediumHall     REVERB_MediumHall
  #define ReverbPreset_LargeHall      REVERB_LargeHall
  #define ReverbPreset_Plate          REVERB_Plate
  #define ReverbPreset_MAX            REVERB_MAX
} ReverbPreset;
#define ReverbPreset  ReverbPreset

/* ---------------------------------------------------------- UMaterialInterface ! ---------------------------------------------------------- */

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
  #define MATUSAGE_SkeletalMesh                  MATUSAGE_SkeletalMesh
  #define MATUSAGE_FracturedMeshes               MATUSAGE_FracturedMeshes
  #define MATUSAGE_ParticleSprites               MATUSAGE_ParticleSprites
  #define MATUSAGE_BeamTrails                    MATUSAGE_BeamTrails
  #define MATUSAGE_ParticleSubUV                 MATUSAGE_ParticleSubUV
  #define MATUSAGE_Foliage                       MATUSAGE_Foliage
  #define MATUSAGE_SpeedTree                     MATUSAGE_SpeedTree
  #define MATUSAGE_StaticLighting                MATUSAGE_StaticLighting
  #define MATUSAGE_GammaCorrection               MATUSAGE_GammaCorrection
  #define MATUSAGE_LensFlare                     MATUSAGE_LensFlare
  #define MATUSAGE_InstancedMeshParticles        MATUSAGE_InstancedMeshParticles
  #define MATUSAGE_FluidSurface                  MATUSAGE_FluidSurface
  #define MATUSAGE_Decals                        MATUSAGE_Decals
  #define MATUSAGE_MaterialEffect                MATUSAGE_MaterialEffect
  #define MATUSAGE_MorphTargets                  MATUSAGE_MorphTargets
  #define MATUSAGE_FogVolumes                    MATUSAGE_FogVolumes
  #define MATUSAGE_RadialBlur                    MATUSAGE_RadialBlur
  #define MATUSAGE_InstancedMeshes               MATUSAGE_InstancedMeshes
  #define MATUSAGE_SplineMesh                    MATUSAGE_SplineMesh
  #define MATUSAGE_ScreenDoorFade                MATUSAGE_ScreenDoorFade
  #define MATUSAGE_APEXMesh                      MATUSAGE_APEXMesh
  #define MATUSAGE_Terrain                       MATUSAGE_Terrain
  #define MATUSAGE_Landscape                     MATUSAGE_Landscape
  #define MATUSAGE_SPHFluid                      MATUSAGE_SPHFluid
  #define MATUSAGE_MAX                           MATUSAGE_MAX
  #define EMaterialUsage_SkeletalMesh            MATUSAGE_SkeletalMesh
  #define EMaterialUsage_FracturedMeshes         MATUSAGE_FracturedMeshes
  #define EMaterialUsage_ParticleSprites         MATUSAGE_ParticleSprites
  #define EMaterialUsage_BeamTrails              MATUSAGE_BeamTrails
  #define EMaterialUsage_ParticleSubUV           MATUSAGE_ParticleSubUV
  #define EMaterialUsage_Foliage                 MATUSAGE_Foliage
  #define EMaterialUsage_SpeedTree               MATUSAGE_SpeedTree
  #define EMaterialUsage_StaticLighting          MATUSAGE_StaticLighting
  #define EMaterialUsage_GammaCorrection         MATUSAGE_GammaCorrection
  #define EMaterialUsage_LensFlare               MATUSAGE_LensFlare
  #define EMaterialUsage_InstancedMeshParticles  MATUSAGE_InstancedMeshParticles
  #define EMaterialUsage_FluidSurface            MATUSAGE_FluidSurface
  #define EMaterialUsage_Decals                  MATUSAGE_Decals
  #define EMaterialUsage_MaterialEffect          MATUSAGE_MaterialEffect
  #define EMaterialUsage_MorphTargets            MATUSAGE_MorphTargets
  #define EMaterialUsage_FogVolumes              MATUSAGE_FogVolumes
  #define EMaterialUsage_RadialBlur              MATUSAGE_RadialBlur
  #define EMaterialUsage_InstancedMeshes         MATUSAGE_InstancedMeshes
  #define EMaterialUsage_SplineMesh              MATUSAGE_SplineMesh
  #define EMaterialUsage_ScreenDoorFade          MATUSAGE_ScreenDoorFade
  #define EMaterialUsage_APEXMesh                MATUSAGE_APEXMesh
  #define EMaterialUsage_Terrain                 MATUSAGE_Terrain
  #define EMaterialUsage_Landscape               MATUSAGE_Landscape
  #define EMaterialUsage_SPHFluid                MATUSAGE_SPHFluid
  #define EMaterialUsage_MAX                     MATUSAGE_MAX
} EMaterialUsage;
typedef enum ECustomSkinType : unsigned char {
  CUSTSKIN_None,                  // 0
  CUSTSKIN_Body,                  // 1
  CUSTSKIN_Head,                  // 2
  CUSTSKIN_MAX                    // 3
  #define CUSTSKIN_None         CUSTSKIN_None
  #define CUSTSKIN_Body         CUSTSKIN_Body
  #define CUSTSKIN_Head         CUSTSKIN_Head
  #define CUSTSKIN_MAX          CUSTSKIN_MAX
  #define ECustomSkinType_None  CUSTSKIN_None
  #define ECustomSkinType_Body  CUSTSKIN_Body
  #define ECustomSkinType_Head  CUSTSKIN_Head
  #define ECustomSkinType_MAX   CUSTSKIN_MAX
} ECustomSkinType;
#define EMaterialUsage   EMaterialUsage
#define ECustomSkinType  ECustomSkinType

/* ---------------------------------------------------------- ULightComponent ! ---------------------------------------------------------- */

typedef enum ELightAffectsClassification : unsigned char {
  LAC_USER_SELECTED,              // 0
  LAC_DYNAMIC_AFFECTING,          // 1
  LAC_STATIC_AFFECTING,           // 2
  LAC_DYNAMIC_AND_STATIC_AFFECTING,// 3
  LAC_MAX                         // 4
  #define LAC_USER_SELECTED                                         LAC_USER_SELECTED
  #define LAC_DYNAMIC_AFFECTING                                     LAC_DYNAMIC_AFFECTING
  #define LAC_STATIC_AFFECTING                                      LAC_STATIC_AFFECTING
  #define LAC_DYNAMIC_AND_STATIC_AFFECTING                          LAC_DYNAMIC_AND_STATIC_AFFECTING
  #define LAC_MAX                                                   LAC_MAX
  #define ELightAffectsClassification_USER_SELECTED                 LAC_USER_SELECTED
  #define ELightAffectsClassification_DYNAMIC_AFFECTING             LAC_DYNAMIC_AFFECTING
  #define ELightAffectsClassification_STATIC_AFFECTING              LAC_STATIC_AFFECTING
  #define ELightAffectsClassification_DYNAMIC_AND_STATIC_AFFECTING  LAC_DYNAMIC_AND_STATIC_AFFECTING
  #define ELightAffectsClassification_MAX                           LAC_MAX
} ELightAffectsClassification;
typedef enum ELightShadowMode            : unsigned char {
  LightShadow_Normal,             // 0
  LightShadow_Modulate,           // 1
  LightShadow_ModulateBetter,     // 2
  LightShadow_MAX                 // 3
  #define LightShadow_Normal               LightShadow_Normal
  #define LightShadow_Modulate             LightShadow_Modulate
  #define LightShadow_ModulateBetter       LightShadow_ModulateBetter
  #define LightShadow_MAX                  LightShadow_MAX
  #define ELightShadowMode_Normal          LightShadow_Normal
  #define ELightShadowMode_Modulate        LightShadow_Modulate
  #define ELightShadowMode_ModulateBetter  LightShadow_ModulateBetter
  #define ELightShadowMode_MAX             LightShadow_MAX
} ELightShadowMode;
typedef enum EShadowProjectionTechnique  : unsigned char {
  ShadowProjTech_Default,         // 0
  ShadowProjTech_PCF,             // 1
  ShadowProjTech_VSM,             // 2
  ShadowProjTech_BPCF_Low,        // 3
  ShadowProjTech_BPCF_Medium,     // 4
  ShadowProjTech_BPCF_High,       // 5
  ShadowProjTech_MAX              // 6
  #define ShadowProjTech_Default                  ShadowProjTech_Default
  #define ShadowProjTech_PCF                      ShadowProjTech_PCF
  #define ShadowProjTech_VSM                      ShadowProjTech_VSM
  #define ShadowProjTech_BPCF_Low                 ShadowProjTech_BPCF_Low
  #define ShadowProjTech_BPCF_Medium              ShadowProjTech_BPCF_Medium
  #define ShadowProjTech_BPCF_High                ShadowProjTech_BPCF_High
  #define ShadowProjTech_MAX                      ShadowProjTech_MAX
  #define EShadowProjectionTechnique_Default      ShadowProjTech_Default
  #define EShadowProjectionTechnique_PCF          ShadowProjTech_PCF
  #define EShadowProjectionTechnique_VSM          ShadowProjTech_VSM
  #define EShadowProjectionTechnique_BPCF_Low     ShadowProjTech_BPCF_Low
  #define EShadowProjectionTechnique_BPCF_Medium  ShadowProjTech_BPCF_Medium
  #define EShadowProjectionTechnique_BPCF_High    ShadowProjTech_BPCF_High
  #define EShadowProjectionTechnique_MAX          ShadowProjTech_MAX
} EShadowProjectionTechnique;
typedef enum EShadowFilterQuality        : unsigned char {
  SFQ_Low,                        // 0
  SFQ_Medium,                     // 1
  SFQ_High,                       // 2
  SFQ_MAX                         // 3
  #define SFQ_Low                      SFQ_Low
  #define SFQ_Medium                   SFQ_Medium
  #define SFQ_High                     SFQ_High
  #define SFQ_MAX                      SFQ_MAX
  #define EShadowFilterQuality_Low     SFQ_Low
  #define EShadowFilterQuality_Medium  SFQ_Medium
  #define EShadowFilterQuality_High    SFQ_High
  #define EShadowFilterQuality_MAX     SFQ_MAX
} EShadowFilterQuality;
#define ELightAffectsClassification  ELightAffectsClassification
#define ELightShadowMode             ELightShadowMode
#define EShadowProjectionTechnique   EShadowProjectionTechnique
#define EShadowFilterQuality         EShadowFilterQuality

/* ---------------------------------------------------------- UObject ! ---------------------------------------------------------- */

typedef enum AlphaBlendType             : unsigned char {
  ABT_Linear,                     // 0
  ABT_Cubic,                      // 1
  ABT_Sinusoidal,                 // 2
  ABT_EaseInOutExponent2,         // 3
  ABT_EaseInOutExponent3,         // 4
  ABT_EaseInOutExponent4,         // 5
  ABT_EaseInOutExponent5,         // 6
  ABT_MAX                         // 7
  #define ABT_Linear                         ABT_Linear
  #define ABT_Cubic                          ABT_Cubic
  #define ABT_Sinusoidal                     ABT_Sinusoidal
  #define ABT_EaseInOutExponent2             ABT_EaseInOutExponent2
  #define ABT_EaseInOutExponent3             ABT_EaseInOutExponent3
  #define ABT_EaseInOutExponent4             ABT_EaseInOutExponent4
  #define ABT_EaseInOutExponent5             ABT_EaseInOutExponent5
  #define ABT_MAX                            ABT_MAX
  #define AlphaBlendType_Linear              ABT_Linear
  #define AlphaBlendType_Cubic               ABT_Cubic
  #define AlphaBlendType_Sinusoidal          ABT_Sinusoidal
  #define AlphaBlendType_EaseInOutExponent2  ABT_EaseInOutExponent2
  #define AlphaBlendType_EaseInOutExponent3  ABT_EaseInOutExponent3
  #define AlphaBlendType_EaseInOutExponent4  ABT_EaseInOutExponent4
  #define AlphaBlendType_EaseInOutExponent5  ABT_EaseInOutExponent5
  #define AlphaBlendType_MAX                 ABT_MAX
} AlphaBlendType;
typedef enum EAxis                      : unsigned char {
  AXIS_NONE,                      // 0
  AXIS_X,                         // 1
  AXIS_Y,                         // 2
  AXIS_BLANK,                     // 3
  AXIS_Z,                         // 4
  AXIS_MAX                        // 5
  #define AXIS_NONE    AXIS_NONE
  #define AXIS_X       AXIS_X
  #define AXIS_Y       AXIS_Y
  #define AXIS_BLANK   AXIS_BLANK
  #define AXIS_Z       AXIS_Z
  #define AXIS_MAX     AXIS_MAX
  #define EAxis_NONE   AXIS_NONE
  #define EAxis_X      AXIS_X
  #define EAxis_Y      AXIS_Y
  #define EAxis_BLANK  AXIS_BLANK
  #define EAxis_Z      AXIS_Z
  #define EAxis_MAX    AXIS_MAX
} EAxis;
typedef enum EInputEvent                : unsigned char {
  IE_Pressed,                     // 0
  IE_Released,                    // 1
  IE_Repeat,                      // 2
  IE_DoubleClick,                 // 3
  IE_Axis,                        // 4
  IE_MAX                          // 5
  #define IE_Pressed               IE_Pressed
  #define IE_Released              IE_Released
  #define IE_Repeat                IE_Repeat
  #define IE_DoubleClick           IE_DoubleClick
  #define IE_Axis                  IE_Axis
  #define IE_MAX                   IE_MAX
  #define EInputEvent_Pressed      IE_Pressed
  #define EInputEvent_Released     IE_Released
  #define EInputEvent_Repeat       IE_Repeat
  #define EInputEvent_DoubleClick  IE_DoubleClick
  #define EInputEvent_Axis         IE_Axis
  #define EInputEvent_MAX          IE_MAX
} EInputEvent;
typedef enum EAspectRatioAxisConstraint : unsigned char {
  AspectRatio_MaintainYFOV,       // 0
  AspectRatio_MaintainXFOV,       // 1
  AspectRatio_MajorAxisFOV,       // 2
  AspectRatio_MAX                 // 3
  #define AspectRatio_MaintainYFOV                 AspectRatio_MaintainYFOV
  #define AspectRatio_MaintainXFOV                 AspectRatio_MaintainXFOV
  #define AspectRatio_MajorAxisFOV                 AspectRatio_MajorAxisFOV
  #define AspectRatio_MAX                          AspectRatio_MAX
  #define EAspectRatioAxisConstraint_MaintainYFOV  AspectRatio_MaintainYFOV
  #define EAspectRatioAxisConstraint_MaintainXFOV  AspectRatio_MaintainXFOV
  #define EAspectRatioAxisConstraint_MajorAxisFOV  AspectRatio_MajorAxisFOV
  #define EAspectRatioAxisConstraint_MAX           AspectRatio_MAX
} EAspectRatioAxisConstraint;
typedef enum EInterpCurveMode           : unsigned char {
  CIM_Linear,                     // 0
  CIM_CurveAuto,                  // 1
  CIM_Constant,                   // 2
  CIM_CurveUser,                  // 3
  CIM_CurveBreak,                 // 4
  CIM_CurveAutoClamped,           // 5
  CIM_MAX                         // 6
  #define CIM_Linear                         CIM_Linear
  #define CIM_CurveAuto                      CIM_CurveAuto
  #define CIM_Constant                       CIM_Constant
  #define CIM_CurveUser                      CIM_CurveUser
  #define CIM_CurveBreak                     CIM_CurveBreak
  #define CIM_CurveAutoClamped               CIM_CurveAutoClamped
  #define CIM_MAX                            CIM_MAX
  #define EInterpCurveMode_Linear            CIM_Linear
  #define EInterpCurveMode_CurveAuto         CIM_CurveAuto
  #define EInterpCurveMode_Constant          CIM_Constant
  #define EInterpCurveMode_CurveUser         CIM_CurveUser
  #define EInterpCurveMode_CurveBreak        CIM_CurveBreak
  #define EInterpCurveMode_CurveAutoClamped  CIM_CurveAutoClamped
  #define EInterpCurveMode_MAX               CIM_MAX
} EInterpCurveMode;
/** Which interpolation method to use, needed for backwards compatibility. */
typedef enum EInterpMethodType          : unsigned char {
  IMT_UseFixedTangentEvalAndNewAutoTangents,// 0
  IMT_UseFixedTangentEval,        // 1
  IMT_UseBrokenTangentEval,       // 2
  IMT_MAX                         // 3
  #define IMT_UseFixedTangentEvalAndNewAutoTangents                IMT_UseFixedTangentEvalAndNewAutoTangents
  #define IMT_UseFixedTangentEval                                  IMT_UseFixedTangentEval
  #define IMT_UseBrokenTangentEval                                 IMT_UseBrokenTangentEval
  #define IMT_MAX                                                  IMT_MAX
  #define EInterpMethodType_UseFixedTangentEvalAndNewAutoTangents  IMT_UseFixedTangentEvalAndNewAutoTangents
  #define EInterpMethodType_UseFixedTangentEval                    IMT_UseFixedTangentEval
  #define EInterpMethodType_UseBrokenTangentEval                   IMT_UseBrokenTangentEval
  #define EInterpMethodType_MAX                                    IMT_MAX
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
  #define TG_PreAsyncWork                  TG_PreAsyncWork
  #define TG_DuringAsyncWork               TG_DuringAsyncWork
  #define TG_PostAsyncWork                 TG_PostAsyncWork
  #define TG_PostUpdateWork                TG_PostUpdateWork
  #define TG_EffectsUpdateWork             TG_EffectsUpdateWork
  #define TG_MAX                           TG_MAX
  #define ETickingGroup_PreAsyncWork       TG_PreAsyncWork
  #define ETickingGroup_DuringAsyncWork    TG_DuringAsyncWork
  #define ETickingGroup_PostAsyncWork      TG_PostAsyncWork
  #define ETickingGroup_PostUpdateWork     TG_PostUpdateWork
  #define ETickingGroup_EffectsUpdateWork  TG_EffectsUpdateWork
  #define ETickingGroup_MAX                TG_MAX
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
  #define ARR_Unknown                  ARR_Unknown
  #define ARR_OOM                      ARR_OOM
  #define ARR_Passed                   ARR_Passed
  #define ARR_MAX                      ARR_MAX
  #define EAutomatedRunResult_Unknown  ARR_Unknown
  #define EAutomatedRunResult_OOM      ARR_OOM
  #define EAutomatedRunResult_Passed   ARR_Passed
  #define EAutomatedRunResult_MAX      ARR_MAX
} EAutomatedRunResult;
typedef enum EDebugBreakType            : unsigned char {
  DEBUGGER_NativeOnly,            // 0
  DEBUGGER_ScriptOnly,            // 1
  DEBUGGER_Both,                  // 2
  DEBUGGER_MAX                    // 3
  #define DEBUGGER_NativeOnly         DEBUGGER_NativeOnly
  #define DEBUGGER_ScriptOnly         DEBUGGER_ScriptOnly
  #define DEBUGGER_Both               DEBUGGER_Both
  #define DEBUGGER_MAX                DEBUGGER_MAX
  #define EDebugBreakType_NativeOnly  DEBUGGER_NativeOnly
  #define EDebugBreakType_ScriptOnly  DEBUGGER_ScriptOnly
  #define EDebugBreakType_Both        DEBUGGER_Both
  #define EDebugBreakType_MAX         DEBUGGER_MAX
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

/* ---------------------------------------------------------- UAttributeExpression ! ---------------------------------------------------------- */

typedef enum EComparisonOperator       : unsigned char {
  OPERATOR_EqualTo,               // 0
  OPERATOR_NotEqualTo,            // 1
  OPERATOR_LessThan,              // 2
  OPERATOR_LessThanOrEqual,       // 3
  OPERATOR_GreaterThan,           // 4
  OPERATOR_GreaterThanOrEqual,    // 5
  OPERATOR_MAX                    // 6
  #define OPERATOR_EqualTo                        OPERATOR_EqualTo
  #define OPERATOR_NotEqualTo                     OPERATOR_NotEqualTo
  #define OPERATOR_LessThan                       OPERATOR_LessThan
  #define OPERATOR_LessThanOrEqual                OPERATOR_LessThanOrEqual
  #define OPERATOR_GreaterThan                    OPERATOR_GreaterThan
  #define OPERATOR_GreaterThanOrEqual             OPERATOR_GreaterThanOrEqual
  #define OPERATOR_MAX                            OPERATOR_MAX
  #define EComparisonOperator_EqualTo             OPERATOR_EqualTo
  #define EComparisonOperator_NotEqualTo          OPERATOR_NotEqualTo
  #define EComparisonOperator_LessThan            OPERATOR_LessThan
  #define EComparisonOperator_LessThanOrEqual     OPERATOR_LessThanOrEqual
  #define EComparisonOperator_GreaterThan         OPERATOR_GreaterThan
  #define EComparisonOperator_GreaterThanOrEqual  OPERATOR_GreaterThanOrEqual
  #define EComparisonOperator_MAX                 OPERATOR_MAX
} EComparisonOperator;
typedef enum EOperandUsage             : unsigned char {
  OPERAND_PreferAttribute,        // 0
  OPERAND_Multiply,               // 1
  OPERAND_MAX                     // 2
  #define OPERAND_PreferAttribute        OPERAND_PreferAttribute
  #define OPERAND_Multiply               OPERAND_Multiply
  #define OPERAND_MAX                    OPERAND_MAX
  #define EOperandUsage_PreferAttribute  OPERAND_PreferAttribute
  #define EOperandUsage_Multiply         OPERAND_Multiply
  #define EOperandUsage_MAX              OPERAND_MAX
} EOperandUsage;
typedef enum EExpressionEvaluationMode : unsigned char {
  EXPRMODE_And,                   // 0
  EXPRMODE_Or,                    // 1
  EXPRMODE_MAX                    // 2
  #define EXPRMODE_And                   EXPRMODE_And
  #define EXPRMODE_Or                    EXPRMODE_Or
  #define EXPRMODE_MAX                   EXPRMODE_MAX
  #define EExpressionEvaluationMode_And  EXPRMODE_And
  #define EExpressionEvaluationMode_Or   EXPRMODE_Or
  #define EExpressionEvaluationMode_MAX  EXPRMODE_MAX
} EExpressionEvaluationMode;
#define EComparisonOperator        EComparisonOperator
#define EOperandUsage              EOperandUsage
#define EExpressionEvaluationMode  EExpressionEvaluationMode

/* ---------------------------------------------------------- UAttributeInitializationDefinition ! ---------------------------------------------------------- */

typedef enum EBaseValueMode                   : unsigned char {
  BASEVALUE_InitializationDefSetsBaseValue,// 0
  BASEVALUE_InitializationDefAddsToBaseValue,// 1
  BASEVALUE_InitializationDefScalesBaseValue,// 2
  BASEVALUE_InitializationDefOffsetByBaseValue,// 3
  BASEVALUE_MAX                   // 4
  #define BASEVALUE_InitializationDefSetsBaseValue           BASEVALUE_InitializationDefSetsBaseValue
  #define BASEVALUE_InitializationDefAddsToBaseValue         BASEVALUE_InitializationDefAddsToBaseValue
  #define BASEVALUE_InitializationDefScalesBaseValue         BASEVALUE_InitializationDefScalesBaseValue
  #define BASEVALUE_InitializationDefOffsetByBaseValue       BASEVALUE_InitializationDefOffsetByBaseValue
  #define BASEVALUE_MAX                                      BASEVALUE_MAX
  #define EBaseValueMode_InitializationDefSetsBaseValue      BASEVALUE_InitializationDefSetsBaseValue
  #define EBaseValueMode_InitializationDefAddsToBaseValue    BASEVALUE_InitializationDefAddsToBaseValue
  #define EBaseValueMode_InitializationDefScalesBaseValue    BASEVALUE_InitializationDefScalesBaseValue
  #define EBaseValueMode_InitializationDefOffsetByBaseValue  BASEVALUE_InitializationDefOffsetByBaseValue
  #define EBaseValueMode_MAX                                 BASEVALUE_MAX
} EBaseValueMode;
typedef enum EAttributeInitializationRounding : unsigned char {
  ATTRROUNDING_Float,             // 0
  ATTRROUNDING_IntRound,          // 1
  ATTRROUNDING_IntFloor,          // 2
  ATTRROUNDING_IntCeil,           // 3
  ATTRROUNDING_MAX                // 4
  #define ATTRROUNDING_Float                         ATTRROUNDING_Float
  #define ATTRROUNDING_IntRound                      ATTRROUNDING_IntRound
  #define ATTRROUNDING_IntFloor                      ATTRROUNDING_IntFloor
  #define ATTRROUNDING_IntCeil                       ATTRROUNDING_IntCeil
  #define ATTRROUNDING_MAX                           ATTRROUNDING_MAX
  #define EAttributeInitializationRounding_Float     ATTRROUNDING_Float
  #define EAttributeInitializationRounding_IntRound  ATTRROUNDING_IntRound
  #define EAttributeInitializationRounding_IntFloor  ATTRROUNDING_IntFloor
  #define EAttributeInitializationRounding_IntCeil   ATTRROUNDING_IntCeil
  #define EAttributeInitializationRounding_MAX       ATTRROUNDING_MAX
} EAttributeInitializationRounding;
#define EBaseValueMode                    EBaseValueMode
#define EAttributeInitializationRounding  EAttributeInitializationRounding

/* ---------------------------------------------------------- UAttributeModifier ! ---------------------------------------------------------- */

typedef enum EModifierType : unsigned char {
  MT_Scale,                       // 0
  MT_PreAdd,                      // 1
  MT_PostAdd,                     // 2
  MT_MAX                          // 3
  #define MT_Scale               MT_Scale
  #define MT_PreAdd              MT_PreAdd
  #define MT_PostAdd             MT_PostAdd
  #define MT_MAX                 MT_MAX
  #define EModifierType_Scale    MT_Scale
  #define EModifierType_PreAdd   MT_PreAdd
  #define EModifierType_PostAdd  MT_PostAdd
  #define EModifierType_MAX      MT_MAX
} EModifierType;
#define EModifierType  EModifierType

/* ---------------------------------------------------------- UAttributeDefinitionBase ! ---------------------------------------------------------- */

typedef enum EAttributeDataType : unsigned char {
  ADT_Float,                      // 0
  ADT_Int,                        // 1
  ADT_Bool,                       // 2
  ADT_MAX                         // 3
  #define ADT_Float                 ADT_Float
  #define ADT_Int                   ADT_Int
  #define ADT_Bool                  ADT_Bool
  #define ADT_MAX                   ADT_MAX
  #define EAttributeDataType_Float  ADT_Float
  #define EAttributeDataType_Int    ADT_Int
  #define EAttributeDataType_Bool   ADT_Bool
  #define EAttributeDataType_MAX    ADT_MAX
} EAttributeDataType;
#define EAttributeDataType  EAttributeDataType

/* ---------------------------------------------------------- AWillowInventory ! ---------------------------------------------------------- */

typedef enum PlayerMark        : unsigned char {
  PM_Trash,                       // 0
  PM_Standard,                    // 1
  PM_Favorite,                    // 2
  PM_MAX                          // 3
  #define PM_Trash             PM_Trash
  #define PM_Standard          PM_Standard
  #define PM_Favorite          PM_Favorite
  #define PM_MAX               PM_MAX
  #define PlayerMark_Trash     PM_Trash
  #define PlayerMark_Standard  PM_Standard
  #define PlayerMark_Favorite  PM_Favorite
  #define PlayerMark_MAX       PM_MAX
} PlayerMark;
typedef enum SerialNumberState : unsigned char {
  SNS_Empty,                      // 0
  SNS_Writing,                    // 1
  SNS_Full,                       // 2
  SNS_Reading,                    // 3
  SNS_Encrypted,                  // 4
  SNS_MAX                         // 5
  #define SNS_Empty                    SNS_Empty
  #define SNS_Writing                  SNS_Writing
  #define SNS_Full                     SNS_Full
  #define SNS_Reading                  SNS_Reading
  #define SNS_Encrypted                SNS_Encrypted
  #define SNS_MAX                      SNS_MAX
  #define SerialNumberState_Empty      SNS_Empty
  #define SerialNumberState_Writing    SNS_Writing
  #define SerialNumberState_Full       SNS_Full
  #define SerialNumberState_Reading    SNS_Reading
  #define SerialNumberState_Encrypted  SNS_Encrypted
  #define SerialNumberState_MAX        SNS_MAX
} SerialNumberState;
typedef enum EncryptedSerial   : unsigned char {
  ES_Encrypted,                   // 0
  ES_MAX                          // 1
  #define ES_Encrypted               ES_Encrypted
  #define ES_MAX                     ES_MAX
  #define EncryptedSerial_Encrypted  ES_Encrypted
  #define EncryptedSerial_MAX        ES_MAX
} EncryptedSerial;
#define PlayerMark         PlayerMark
#define SerialNumberState  SerialNumberState
#define EncryptedSerial    EncryptedSerial

/* ---------------------------------------------------------- AWeapon ! ---------------------------------------------------------- */

typedef enum EWeaponFireType : unsigned char {
  EWFT_InstantHit,                // 0
  EWFT_Projectile,                // 1
  EWFT_Beam,                      // 2
  EWFT_Custom,                    // 3
  EWFT_None,                      // 4
  EWFT_MAX                        // 5
  #define EWFT_InstantHit             EWFT_InstantHit
  #define EWFT_Projectile             EWFT_Projectile
  #define EWFT_Beam                   EWFT_Beam
  #define EWFT_Custom                 EWFT_Custom
  #define EWFT_None                   EWFT_None
  #define EWFT_MAX                    EWFT_MAX
  #define EWeaponFireType_InstantHit  EWFT_InstantHit
  #define EWeaponFireType_Projectile  EWFT_Projectile
  #define EWeaponFireType_Beam        EWFT_Beam
  #define EWeaponFireType_Custom      EWFT_Custom
  #define EWeaponFireType_None        EWFT_None
  #define EWeaponFireType_MAX         EWFT_MAX
} EWeaponFireType;
#define EWeaponFireType  EWeaponFireType
_DECL_TARRAY(EWeaponFireType);

/* ---------------------------------------------------------- UFontImportOptions ! ---------------------------------------------------------- */

typedef enum EFontImportCharacterSet : unsigned char {
  FontICS_Default,  /* 0 */
  FontICS_Ansi,     /* 1 */
  FontICS_Symbol,   /* 2 */
  FontICS_MAX       /* 3 */
  #define FontICS_Default                 FontICS_Default
  #define FontICS_Ansi                    FontICS_Ansi
  #define FontICS_Symbol                  FontICS_Symbol
  #define FontICS_MAX                     FontICS_MAX
  #define EFontImportCharacterSet_Default FontICS_Default
  #define EFontImportCharacterSet_Ansi    FontICS_Ansi
  #define EFontImportCharacterSet_Symbol  FontICS_Symbol
  #define EFontImportCharacterSet_MAX     FontICS_MAX
} EFontImportCharacterSet;
#define EFontImportCharacterSet  EFontImportCharacterSet

/* ---------------------------------------------------------- AWillowWeapon ! ---------------------------------------------------------- */

typedef enum EWeaponReloadState      : unsigned char {
  RELOADSTATE_None,               // 0
  RELOADSTATE_Reloading,          // 1
  RELOADSTATE_Aborted,            // 2
  RELOADSTATE_MAX                 // 3
  #define RELOADSTATE_None              RELOADSTATE_None
  #define RELOADSTATE_Reloading         RELOADSTATE_Reloading
  #define RELOADSTATE_Aborted           RELOADSTATE_Aborted
  #define RELOADSTATE_MAX               RELOADSTATE_MAX
  #define EWeaponReloadState_None       RELOADSTATE_None
  #define EWeaponReloadState_Reloading  RELOADSTATE_Reloading
  #define EWeaponReloadState_Aborted    RELOADSTATE_Aborted
  #define EWeaponReloadState_MAX        RELOADSTATE_MAX
} EWeaponReloadState;
typedef enum EZoomState              : unsigned char {
  ZST_NotZoomed,                  // 0
  ZST_ZoomingIn,                  // 1
  ZST_Zoomed,                     // 2
  ZST_ZoomingOut,                 // 3
  ZST_MAX                         // 4
  #define ZST_NotZoomed          ZST_NotZoomed
  #define ZST_ZoomingIn          ZST_ZoomingIn
  #define ZST_Zoomed             ZST_Zoomed
  #define ZST_ZoomingOut         ZST_ZoomingOut
  #define ZST_MAX                ZST_MAX
  #define EZoomState_NotZoomed   ZST_NotZoomed
  #define EZoomState_ZoomingIn   ZST_ZoomingIn
  #define EZoomState_Zoomed      ZST_Zoomed
  #define EZoomState_ZoomingOut  ZST_ZoomingOut
  #define EZoomState_MAX         ZST_MAX
} EZoomState;
typedef enum EWeaponSpinState        : unsigned char {
  SPIN_STATE_None,                // 0
  SPIN_STATE_SpinningUp,          // 1
  SPIN_STATE_FullySpunUp,         // 2
  SPIN_STATE_MAX                  // 3
  #define SPIN_STATE_None               SPIN_STATE_None
  #define SPIN_STATE_SpinningUp         SPIN_STATE_SpinningUp
  #define SPIN_STATE_FullySpunUp        SPIN_STATE_FullySpunUp
  #define SPIN_STATE_MAX                SPIN_STATE_MAX
  #define EWeaponSpinState_None         SPIN_STATE_None
  #define EWeaponSpinState_SpinningUp   SPIN_STATE_SpinningUp
  #define EWeaponSpinState_FullySpunUp  SPIN_STATE_FullySpunUp
  #define EWeaponSpinState_MAX          SPIN_STATE_MAX
} EWeaponSpinState;
typedef enum EWeaponAnimation        : unsigned char {
  WEAPON_ANIM_Weapon,             // 0
  WEAPON_ANIM_Arm,                // 1
  WEAPON_ANIM_MAX                 // 2
  #define WEAPON_ANIM_Weapon       WEAPON_ANIM_Weapon
  #define WEAPON_ANIM_Arm          WEAPON_ANIM_Arm
  #define WEAPON_ANIM_MAX          WEAPON_ANIM_MAX
  #define EWeaponAnimation_Weapon  WEAPON_ANIM_Weapon
  #define EWeaponAnimation_Arm     WEAPON_ANIM_Arm
  #define EWeaponAnimation_MAX     WEAPON_ANIM_MAX
} EWeaponAnimation;
typedef enum EWeaponAnimPutDownState : unsigned char {
  WAPDS_None,                     // 0
  WAPDS_PutDown,                  // 1
  WAPDS_PutDownSwap,              // 2
  WAPDS_PutDownInterrupted,       // 3
  WAPDS_MAX                       // 4
  #define WAPDS_None                                  WAPDS_None
  #define WAPDS_PutDown                               WAPDS_PutDown
  #define WAPDS_PutDownSwap                           WAPDS_PutDownSwap
  #define WAPDS_PutDownInterrupted                    WAPDS_PutDownInterrupted
  #define WAPDS_MAX                                   WAPDS_MAX
  #define EWeaponAnimPutDownState_None                WAPDS_None
  #define EWeaponAnimPutDownState_PutDown             WAPDS_PutDown
  #define EWeaponAnimPutDownState_PutDownSwap         WAPDS_PutDownSwap
  #define EWeaponAnimPutDownState_PutDownInterrupted  WAPDS_PutDownInterrupted
  #define EWeaponAnimPutDownState_MAX                 WAPDS_MAX
} EWeaponAnimPutDownState;
#define EWeaponReloadState  		 EWeaponReloadState
#define EZoomState 				  		 EZoomState
#define EWeaponSpinState 	  		 EWeaponSpinState
#define EWeaponAnimation 	  		 EWeaponAnimation
#define EWeaponAnimPutDownState  EWeaponAnimPutDownState

/* ---------------------------------------------------------- UWillowWeaponTypes ! ---------------------------------------------------------- */

typedef enum EWeaponType               : unsigned char {
  WT_Pistol,                      // 0
  WT_Shotgun,                     // 1
  WT_SMG,                         // 2
  WT_SniperRifle,                 // 3
  WT_AssaultRifle,                // 4
  WT_RocketLauncher,              // 5
  WT_MAX                          // 6
  #define WT_Pistol                   WT_Pistol
  #define WT_Shotgun                  WT_Shotgun
  #define WT_SMG                      WT_SMG
  #define WT_SniperRifle              WT_SniperRifle
  #define WT_AssaultRifle             WT_AssaultRifle
  #define WT_RocketLauncher           WT_RocketLauncher
  #define WT_MAX                      WT_MAX
  #define EWeaponType_Pistol          WT_Pistol
  #define EWeaponType_Shotgun         WT_Shotgun
  #define EWeaponType_SMG             WT_SMG
  #define EWeaponType_SniperRifle     WT_SniperRifle
  #define EWeaponType_AssaultRifle    WT_AssaultRifle
  #define EWeaponType_RocketLauncher  WT_RocketLauncher
  #define EWeaponType_MAX             WT_MAX
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
  #define WP_Body                     WP_Body
  #define WP_Grip                     WP_Grip
  #define WP_Barrel                   WP_Barrel
  #define WP_Sight                    WP_Sight
  #define WP_Stock                    WP_Stock
  #define WP_Elemental                WP_Elemental
  #define WP_Accessory1               WP_Accessory1
  #define WP_Accessory2               WP_Accessory2
  #define WP_Material                 WP_Material
  #define WP_Prefix                   WP_Prefix
  #define WP_Title                    WP_Title
  #define WP_MAX                      WP_MAX
  #define EWeaponPartType_Body        WP_Body
  #define EWeaponPartType_Grip        WP_Grip
  #define EWeaponPartType_Barrel      WP_Barrel
  #define EWeaponPartType_Sight       WP_Sight
  #define EWeaponPartType_Stock       WP_Stock
  #define EWeaponPartType_Elemental   WP_Elemental
  #define EWeaponPartType_Accessory1  WP_Accessory1
  #define EWeaponPartType_Accessory2  WP_Accessory2
  #define EWeaponPartType_Material    WP_Material
  #define EWeaponPartType_Prefix      WP_Prefix
  #define EWeaponPartType_Title       WP_Title
  #define EWeaponPartType_MAX         WP_MAX
} EWeaponPartType;
typedef enum EWeaponPartVariation      : unsigned char {
  WeaponPartVar_Default,          // 0
  WeaponPartVar_One,              // 1
  WeaponPartVar_Two,              // 2
  WeaponPartVar_Three,            // 3
  WeaponPartVar_MAX               // 4
  #define WeaponPartVar_Default         WeaponPartVar_Default
  #define WeaponPartVar_One             WeaponPartVar_One
  #define WeaponPartVar_Two             WeaponPartVar_Two
  #define WeaponPartVar_Three           WeaponPartVar_Three
  #define WeaponPartVar_MAX             WeaponPartVar_MAX
  #define EWeaponPartVariation_Default  WeaponPartVar_Default
  #define EWeaponPartVariation_One      WeaponPartVar_One
  #define EWeaponPartVariation_Two      WeaponPartVar_Two
  #define EWeaponPartVariation_Three    WeaponPartVar_Three
  #define EWeaponPartVariation_MAX      WeaponPartVar_MAX
} EWeaponPartVariation;
typedef enum EWeaponEventType          : unsigned char {
  WEAPONEVENT_Advance,            // 0
  WEAPONEVENT_Stop,               // 1
  WEAPONEVENT_Pause,              // 2
  WEAPONEVENT_UnPause,            // 3
  WEAPONEVENT_MAX                 // 4
  #define WEAPONEVENT_Advance       WEAPONEVENT_Advance
  #define WEAPONEVENT_Stop          WEAPONEVENT_Stop
  #define WEAPONEVENT_Pause         WEAPONEVENT_Pause
  #define WEAPONEVENT_UnPause       WEAPONEVENT_UnPause
  #define WEAPONEVENT_MAX           WEAPONEVENT_MAX
  #define EWeaponEventType_Advance  WEAPONEVENT_Advance
  #define EWeaponEventType_Stop     WEAPONEVENT_Stop
  #define EWeaponEventType_Pause    WEAPONEVENT_Pause
  #define EWeaponEventType_UnPause  WEAPONEVENT_UnPause
  #define EWeaponEventType_MAX      WEAPONEVENT_MAX
} EWeaponEventType;
typedef enum EWeaponBoneControllerType : unsigned char {
  WEAP_BONE_CONTROL_General,      // 0
  WEAP_BONE_CONTROL_BarrelSpinner,// 1
  WEAP_BONE_CONTROL_MagazineSpinner,// 2
  WEAP_BONE_CONTROL_Flap,         // 3
  WEAP_BONE_CONTROL_MAX           // 4
  #define WEAP_BONE_CONTROL_General                  WEAP_BONE_CONTROL_General
  #define WEAP_BONE_CONTROL_BarrelSpinner            WEAP_BONE_CONTROL_BarrelSpinner
  #define WEAP_BONE_CONTROL_MagazineSpinner          WEAP_BONE_CONTROL_MagazineSpinner
  #define WEAP_BONE_CONTROL_Flap                     WEAP_BONE_CONTROL_Flap
  #define WEAP_BONE_CONTROL_MAX                      WEAP_BONE_CONTROL_MAX
  #define EWeaponBoneControllerType_General          WEAP_BONE_CONTROL_General
  #define EWeaponBoneControllerType_BarrelSpinner    WEAP_BONE_CONTROL_BarrelSpinner
  #define EWeaponBoneControllerType_MagazineSpinner  WEAP_BONE_CONTROL_MagazineSpinner
  #define EWeaponBoneControllerType_Flap             WEAP_BONE_CONTROL_Flap
  #define EWeaponBoneControllerType_MAX              WEAP_BONE_CONTROL_MAX
} EWeaponBoneControllerType;
typedef enum EWeaponHand               : unsigned char {
  HAND_Right,                     // 0
  HAND_Left,                      // 1
  HAND_Centered,                  // 2
  HAND_Hidden,                    // 3
  HAND_MAX                        // 4
  #define HAND_Right            HAND_Right
  #define HAND_Left             HAND_Left
  #define HAND_Centered         HAND_Centered
  #define HAND_Hidden           HAND_Hidden
  #define HAND_MAX              HAND_MAX
  #define EWeaponHand_Right     HAND_Right
  #define EWeaponHand_Left      HAND_Left
  #define EWeaponHand_Centered  HAND_Centered
  #define EWeaponHand_Hidden    HAND_Hidden
  #define EWeaponHand_MAX       HAND_MAX
} EWeaponHand;
typedef enum EWeaponVisibleAmmoState   : unsigned char {
  VISIBLE_AMMO_STATE_Default,     // 0
  VISIBLE_AMMO_STATE_PendingReload,// 1
  VISIBLE_AMMO_STATE_MAX          // 2
  #define VISIBLE_AMMO_STATE_Default             VISIBLE_AMMO_STATE_Default
  #define VISIBLE_AMMO_STATE_PendingReload       VISIBLE_AMMO_STATE_PendingReload
  #define VISIBLE_AMMO_STATE_MAX                 VISIBLE_AMMO_STATE_MAX
  #define EWeaponVisibleAmmoState_Default        VISIBLE_AMMO_STATE_Default
  #define EWeaponVisibleAmmoState_PendingReload  VISIBLE_AMMO_STATE_PendingReload
  #define EWeaponVisibleAmmoState_MAX            VISIBLE_AMMO_STATE_MAX
} EWeaponVisibleAmmoState;
#define EWeaponType                EWeaponType
#define EWeaponPartType            EWeaponPartType
#define EWeaponPartVariation       EWeaponPartVariation
#define EWeaponEventType           EWeaponEventType
#define EWeaponBoneControllerType  EWeaponBoneControllerType
#define EWeaponHand                EWeaponHand
#define EWeaponVisibleAmmoState    EWeaponVisibleAmmoState

/* ---------------------------------------------------------- UWillowInventoryDefinition ! ---------------------------------------------------------- */

typedef enum EPlayerDroppability      : unsigned char {
  EPD_Droppable,                  // 0
  EPD_Sellable,                   // 1
  EPD_CannotDropOrSell,           // 2
  EPD_MAX                         // 3
  #define EPD_Droppable                         EPD_Droppable
  #define EPD_Sellable                          EPD_Sellable
  #define EPD_CannotDropOrSell                  EPD_CannotDropOrSell
  #define EPD_MAX                               EPD_MAX
  #define EPlayerDroppability_Droppable         EPD_Droppable
  #define EPlayerDroppability_Sellable          EPD_Sellable
  #define EPlayerDroppability_CannotDropOrSell  EPD_CannotDropOrSell
  #define EPlayerDroppability_MAX               EPD_MAX
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
  #define CURRENCY_Credits              CURRENCY_Credits
  #define CURRENCY_Eridium              CURRENCY_Eridium
  #define CURRENCY_SeraphCrystals       CURRENCY_SeraphCrystals
  #define CURRENCY_Reserved_A           CURRENCY_Reserved_A
  #define CURRENCY_Reserved_B           CURRENCY_Reserved_B
  #define CURRENCY_Reserved_C           CURRENCY_Reserved_C
  #define CURRENCY_Reserved_D           CURRENCY_Reserved_D
  #define CURRENCY_Reserved_E           CURRENCY_Reserved_E
  #define CURRENCY_Reserved_F           CURRENCY_Reserved_F
  #define CURRENCY_Reserved_G           CURRENCY_Reserved_G
  #define CURRENCY_Reserved_H           CURRENCY_Reserved_H
  #define CURRENCY_Reserved_I           CURRENCY_Reserved_I
  #define CURRENCY_Reserved_J           CURRENCY_Reserved_J
  #define CURRENCY_MAX                  CURRENCY_MAX
  #define ECurrencyType_Credits         CURRENCY_Credits
  #define ECurrencyType_Eridium         CURRENCY_Eridium
  #define ECurrencyType_SeraphCrystals  CURRENCY_SeraphCrystals
  #define ECurrencyType_Reserved_A      CURRENCY_Reserved_A
  #define ECurrencyType_Reserved_B      CURRENCY_Reserved_B
  #define ECurrencyType_Reserved_C      CURRENCY_Reserved_C
  #define ECurrencyType_Reserved_D      CURRENCY_Reserved_D
  #define ECurrencyType_Reserved_E      CURRENCY_Reserved_E
  #define ECurrencyType_Reserved_F      CURRENCY_Reserved_F
  #define ECurrencyType_Reserved_G      CURRENCY_Reserved_G
  #define ECurrencyType_Reserved_H      CURRENCY_Reserved_H
  #define ECurrencyType_Reserved_I      CURRENCY_Reserved_I
  #define ECurrencyType_Reserved_J      CURRENCY_Reserved_J
  #define ECurrencyType_MAX             CURRENCY_MAX
} ECurrencyType;
typedef enum EStatCombinationMethod   : unsigned char {
  SCM_Multiply,                   // 0
  SCM_Divide,                     // 1
  SCM_Add,                        // 2
  SCM_Subtract,                   // 3
  SCM_DontCombine,                // 4
  SCM_MAX                         // 5
  #define SCM_Multiply                        SCM_Multiply
  #define SCM_Divide                          SCM_Divide
  #define SCM_Add                             SCM_Add
  #define SCM_Subtract                        SCM_Subtract
  #define SCM_DontCombine                     SCM_DontCombine
  #define SCM_MAX                             SCM_MAX
  #define EStatCombinationMethod_Multiply     SCM_Multiply
  #define EStatCombinationMethod_Divide       SCM_Divide
  #define EStatCombinationMethod_Add          SCM_Add
  #define EStatCombinationMethod_Subtract     SCM_Subtract
  #define EStatCombinationMethod_DontCombine  SCM_DontCombine
  #define EStatCombinationMethod_MAX          SCM_MAX
} EStatCombinationMethod;
typedef enum EAttributeSlotEffectMode : unsigned char {
  ATTRSLOTEFFECTMODE_Default,     // 0
  ATTRSLOTEFFECTMODE_Timed,       // 1
  ATTRSLOTEFFECTMODE_Custom,      // 2
  ATTRSLOTEFFECTMODE_MAX          // 3
  #define ATTRSLOTEFFECTMODE_Default        ATTRSLOTEFFECTMODE_Default
  #define ATTRSLOTEFFECTMODE_Timed          ATTRSLOTEFFECTMODE_Timed
  #define ATTRSLOTEFFECTMODE_Custom         ATTRSLOTEFFECTMODE_Custom
  #define ATTRSLOTEFFECTMODE_MAX            ATTRSLOTEFFECTMODE_MAX
  #define EAttributeSlotEffectMode_Default  ATTRSLOTEFFECTMODE_Default
  #define EAttributeSlotEffectMode_Timed    ATTRSLOTEFFECTMODE_Timed
  #define EAttributeSlotEffectMode_Custom   ATTRSLOTEFFECTMODE_Custom
  #define EAttributeSlotEffectMode_MAX      ATTRSLOTEFFECTMODE_MAX
} EAttributeSlotEffectMode;
#define EPlayerDroppability       EPlayerDroppability
#define ECurrencyType             ECurrencyType
#define EStatCombinationMethod    EStatCombinationMethod
#define EAttributeSlotEffectMode  EAttributeSlotEffectMode

/* ---------------------------------------------------------- UWeaponTypeDefinition ! ---------------------------------------------------------- */

typedef enum EBarrelSpinMode : unsigned char {
  BSM_None,                       // 0
  BSM_SpinUpToFullFireRate,       // 1
  BSM_SpinBarrelWithEachShot,     // 2
  BSM_MAX                         // 3
  #define BSM_None                                BSM_None
  #define BSM_SpinUpToFullFireRate                BSM_SpinUpToFullFireRate
  #define BSM_SpinBarrelWithEachShot              BSM_SpinBarrelWithEachShot
  #define BSM_MAX                                 BSM_MAX
  #define EBarrelSpinMode_None                    BSM_None
  #define EBarrelSpinMode_SpinUpToFullFireRate    BSM_SpinUpToFullFireRate
  #define EBarrelSpinMode_SpinBarrelWithEachShot  BSM_SpinBarrelWithEachShot
  #define EBarrelSpinMode_MAX                     BSM_MAX
} EBarrelSpinMode;
typedef enum EGbxWeaponLock  : unsigned char {
  GBXWEAPLOCK_None,               // 0
  GBXWEAPLOCK_PaintAndHold,       // 1
  GBXWEAPLOCK_MAX                 // 2
  #define GBXWEAPLOCK_None             GBXWEAPLOCK_None
  #define GBXWEAPLOCK_PaintAndHold     GBXWEAPLOCK_PaintAndHold
  #define GBXWEAPLOCK_MAX              GBXWEAPLOCK_MAX
  #define EGbxWeaponLock_None          GBXWEAPLOCK_None
  #define EGbxWeaponLock_PaintAndHold  GBXWEAPLOCK_PaintAndHold
  #define EGbxWeaponLock_MAX           GBXWEAPLOCK_MAX
} EGbxWeaponLock;
#define EBarrelSpinMode  EBarrelSpinMode
#define EGbxWeaponLock   EGbxWeaponLock

/* ---------------------------------------------------------- UAttributeDefinition ! ---------------------------------------------------------- */

typedef enum EAttributeTranslationStyle : unsigned char {
  ATTRSTYLE_JustNumber,           // 0
  ATTRSTYLE_ModifierText,         // 1
  ATTRSTYLE_Debug,                // 2
  ATTRSTYLE_LeaveBlank,           // 3
  ATTRSTYLE_MAX                   // 4
  #define ATTRSTYLE_JustNumber                     ATTRSTYLE_JustNumber
  #define ATTRSTYLE_ModifierText                   ATTRSTYLE_ModifierText
  #define ATTRSTYLE_Debug                          ATTRSTYLE_Debug
  #define ATTRSTYLE_LeaveBlank                     ATTRSTYLE_LeaveBlank
  #define ATTRSTYLE_MAX                            ATTRSTYLE_MAX
  #define EAttributeTranslationStyle_JustNumber    ATTRSTYLE_JustNumber
  #define EAttributeTranslationStyle_ModifierText  ATTRSTYLE_ModifierText
  #define EAttributeTranslationStyle_Debug         ATTRSTYLE_Debug
  #define EAttributeTranslationStyle_LeaveBlank    ATTRSTYLE_LeaveBlank
  #define EAttributeTranslationStyle_MAX           ATTRSTYLE_MAX
} EAttributeTranslationStyle;
#define EAttributeTranslationStyle  EAttributeTranslationStyle

/* ---------------------------------------------------------- URB_BodySetup ! ---------------------------------------------------------- */

typedef enum ESleepFamily : unsigned char {
  SF_Normal,                      // 0
  SF_Sensitive,                   // 1
  SF_MAX                          // 2
  #define SF_Normal               SF_Normal
  #define SF_Sensitive            SF_Sensitive
  #define SF_MAX                  SF_MAX
  #define ESleepFamily_Normal     SF_Normal
  #define ESleepFamily_Sensitive  SF_Sensitive
  #define ESleepFamily_MAX        SF_MAX
} ESleepFamily;
#define ESleepFamily  ESleepFamily

/* ---------------------------------------------------------- UInterpTrack ! ---------------------------------------------------------- */

typedef enum ETrackActiveCondition : unsigned char {
  ETAC_Always,                    // 0
  ETAC_GoreEnabled,               // 1
  ETAC_GoreDisabled,              // 2
  ETAC_MAX                        // 3
  #define ETAC_Always                         ETAC_Always
  #define ETAC_GoreEnabled                    ETAC_GoreEnabled
  #define ETAC_GoreDisabled                   ETAC_GoreDisabled
  #define ETAC_MAX                            ETAC_MAX
  #define ETrackActiveCondition_Always        ETAC_Always
  #define ETrackActiveCondition_GoreEnabled   ETAC_GoreEnabled
  #define ETrackActiveCondition_GoreDisabled  ETAC_GoreDisabled
  #define ETrackActiveCondition_MAX           ETAC_MAX
} ETrackActiveCondition;
typedef enum ETrackPlayDirection   : unsigned char {
  ETPD_PlayBoth,                  // 0
  ETPD_PlayOnlyForward,           // 1
  ETPD_PlayOnlyReverse,           // 2
  ETPD_MAX                        // 3
  #define ETPD_PlayBoth                        ETPD_PlayBoth
  #define ETPD_PlayOnlyForward                 ETPD_PlayOnlyForward
  #define ETPD_PlayOnlyReverse                 ETPD_PlayOnlyReverse
  #define ETPD_MAX                             ETPD_MAX
  #define ETrackPlayDirection_PlayBoth         ETPD_PlayBoth
  #define ETrackPlayDirection_PlayOnlyForward  ETPD_PlayOnlyForward
  #define ETrackPlayDirection_PlayOnlyReverse  ETPD_PlayOnlyReverse
  #define ETrackPlayDirection_MAX              ETPD_MAX
} ETrackPlayDirection;
#define ETrackActiveCondition  ETrackActiveCondition
#define ETrackPlayDirection    ETrackPlayDirection

/* ---------------------------------------------------------- UAnimSequence ! ---------------------------------------------------------- */

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
  #define ACF_None                                       ACF_None
  #define ACF_Float96NoW                                 ACF_Float96NoW
  #define ACF_Fixed48NoW                                 ACF_Fixed48NoW
  #define ACF_IntervalFixed32NoW                         ACF_IntervalFixed32NoW
  #define ACF_Fixed32NoW                                 ACF_Fixed32NoW
  #define ACF_Float32NoW                                 ACF_Float32NoW
  #define ACF_Delta40NoW                                 ACF_Delta40NoW
  #define ACF_Delta48NoW                                 ACF_Delta48NoW
  #define ACF_Identity                                   ACF_Identity
  #define ACF_PolarEncoded32                             ACF_PolarEncoded32
  #define ACF_PolarEncoded48                             ACF_PolarEncoded48
  #define ACF_MAX                                        ACF_MAX
  #define AnimationCompressionFormat_None                ACF_None
  #define AnimationCompressionFormat_Float96NoW          ACF_Float96NoW
  #define AnimationCompressionFormat_Fixed48NoW          ACF_Fixed48NoW
  #define AnimationCompressionFormat_IntervalFixed32NoW  ACF_IntervalFixed32NoW
  #define AnimationCompressionFormat_Fixed32NoW          ACF_Fixed32NoW
  #define AnimationCompressionFormat_Float32NoW          ACF_Float32NoW
  #define AnimationCompressionFormat_Delta40NoW          ACF_Delta40NoW
  #define AnimationCompressionFormat_Delta48NoW          ACF_Delta48NoW
  #define AnimationCompressionFormat_Identity            ACF_Identity
  #define AnimationCompressionFormat_PolarEncoded32      ACF_PolarEncoded32
  #define AnimationCompressionFormat_PolarEncoded48      ACF_PolarEncoded48
  #define AnimationCompressionFormat_MAX                 ACF_MAX
} AnimationCompressionFormat;
typedef enum AnimationKeyFormat         : unsigned char {
  AKF_ConstantKeyLerp,            // 0
  AKF_VariableKeyLerp,            // 1
  AKF_PerTrackCompression,        // 2
  AKF_MAX                         // 3
  #define AKF_ConstantKeyLerp                     AKF_ConstantKeyLerp
  #define AKF_VariableKeyLerp                     AKF_VariableKeyLerp
  #define AKF_PerTrackCompression                 AKF_PerTrackCompression
  #define AKF_MAX                                 AKF_MAX
  #define AnimationKeyFormat_ConstantKeyLerp      AKF_ConstantKeyLerp
  #define AnimationKeyFormat_VariableKeyLerp      AKF_VariableKeyLerp
  #define AnimationKeyFormat_PerTrackCompression  AKF_PerTrackCompression
  #define AnimationKeyFormat_MAX                  AKF_MAX
} AnimationKeyFormat;
#define AnimationCompressionFormat  AnimationCompressionFormat
#define AnimationKeyFormat          AnimationKeyFormat

/* ---------------------------------------------------------- UEngine ! ---------------------------------------------------------- */

typedef enum ETransitionType : unsigned char {
  TT_None,                        // 0
  TT_Paused,                      // 1
  TT_Loading,                     // 2
  TT_Saving,                      // 3
  TT_Connecting,                  // 4
  TT_Precaching,                  // 5
  TT_MAX                          // 6
  #define TT_None                     TT_None
  #define TT_Paused                   TT_Paused
  #define TT_Loading                  TT_Loading
  #define TT_Saving                   TT_Saving
  #define TT_Connecting               TT_Connecting
  #define TT_Precaching               TT_Precaching
  #define TT_MAX                      TT_MAX
  #define ETransitionType_None        TT_None
  #define ETransitionType_Paused      TT_Paused
  #define ETransitionType_Loading     TT_Loading
  #define ETransitionType_Saving      TT_Saving
  #define ETransitionType_Connecting  TT_Connecting
  #define ETransitionType_Precaching  TT_Precaching
  #define ETransitionType_MAX         TT_MAX
} ETransitionType;
#define ETransitionType  ETransitionType

/* ---------------------------------------------------------- UGameEngine ! ---------------------------------------------------------- */

typedef enum EFullyLoadPackageType : unsigned char {
  FULLYLOAD_Map,                  // 0
  FULLYLOAD_Game_PreLoadClass,    // 1
  FULLYLOAD_Game_PostLoadClass,   // 2
  FULLYLOAD_Always,               // 3
  FULLYLOAD_Mutator,              // 4
  FULLYLOAD_MAX                   // 5
  #define FULLYLOAD_Map                             FULLYLOAD_Map
  #define FULLYLOAD_Game_PreLoadClass               FULLYLOAD_Game_PreLoadClass
  #define FULLYLOAD_Game_PostLoadClass              FULLYLOAD_Game_PostLoadClass
  #define FULLYLOAD_Always                          FULLYLOAD_Always
  #define FULLYLOAD_Mutator                         FULLYLOAD_Mutator
  #define FULLYLOAD_MAX                             FULLYLOAD_MAX
  #define EFullyLoadPackageType_Map                 FULLYLOAD_Map
  #define EFullyLoadPackageType_Game_PreLoadClass   FULLYLOAD_Game_PreLoadClass
  #define EFullyLoadPackageType_Game_PostLoadClass  FULLYLOAD_Game_PostLoadClass
  #define EFullyLoadPackageType_Always              FULLYLOAD_Always
  #define EFullyLoadPackageType_Mutator             FULLYLOAD_Mutator
  #define EFullyLoadPackageType_MAX                 FULLYLOAD_MAX
} EFullyLoadPackageType;
#define EFullyLoadPackageType  EFullyLoadPackageType

/* ---------------------------------------------------------- UGFxMoviePlayer ! ---------------------------------------------------------- */

typedef enum GFxTimingMode        : unsigned char {
  TM_Game,                        // 0
  TM_Real,                        // 1
  TM_MAX                          // 2
  #define TM_Game             TM_Game
  #define TM_Real             TM_Real
  #define TM_MAX              TM_MAX
  #define GFxTimingMode_Game  TM_Game
  #define GFxTimingMode_Real  TM_Real
  #define GFxTimingMode_MAX   TM_MAX
} GFxTimingMode;
typedef enum GFxRenderTextureMode : unsigned char {
  RTM_Opaque,                     // 0
  RTM_Alpha,                      // 1
  RTM_AlphaComposite,             // 2
  RTM_MAX                         // 3
  #define RTM_Opaque                           RTM_Opaque
  #define RTM_Alpha                            RTM_Alpha
  #define RTM_AlphaComposite                   RTM_AlphaComposite
  #define RTM_MAX                              RTM_MAX
  #define GFxRenderTextureMode_Opaque          RTM_Opaque
  #define GFxRenderTextureMode_Alpha           RTM_Alpha
  #define GFxRenderTextureMode_AlphaComposite  RTM_AlphaComposite
  #define GFxRenderTextureMode_MAX             RTM_MAX
} GFxRenderTextureMode;
typedef enum ASType               : unsigned char {
  AS_Undefined,                   // 0
  AS_Null,                        // 1
  AS_Number,                      // 2
  AS_String,                      // 3
  AS_Boolean,                     // 4
  AS_MAX                          // 5
  #define AS_Undefined      AS_Undefined
  #define AS_Null           AS_Null
  #define AS_Number         AS_Number
  #define AS_String         AS_String
  #define AS_Boolean        AS_Boolean
  #define AS_MAX            AS_MAX
  #define ASType_Undefined  AS_Undefined
  #define ASType_Null       AS_Null
  #define ASType_Number     AS_Number
  #define ASType_String     AS_String
  #define ASType_Boolean    AS_Boolean
  #define ASType_MAX        AS_MAX
} ASType;
typedef enum GFxScaleMode         : unsigned char {
  SM_NoScale,                     // 0
  SM_ShowAll,                     // 1
  SM_ExactFit,                    // 2
  SM_NoBorder,                    // 3
  SM_FitVertical,                 // 4
  SM_FitHorizontal,               // 5
  SM_MAX                          // 6
  #define SM_NoScale                  SM_NoScale
  #define SM_ShowAll                  SM_ShowAll
  #define SM_ExactFit                 SM_ExactFit
  #define SM_NoBorder                 SM_NoBorder
  #define SM_FitVertical              SM_FitVertical
  #define SM_FitHorizontal            SM_FitHorizontal
  #define SM_MAX                      SM_MAX
  #define GFxScaleMode_NoScale        SM_NoScale
  #define GFxScaleMode_ShowAll        SM_ShowAll
  #define GFxScaleMode_ExactFit       SM_ExactFit
  #define GFxScaleMode_NoBorder       SM_NoBorder
  #define GFxScaleMode_FitVertical    SM_FitVertical
  #define GFxScaleMode_FitHorizontal  SM_FitHorizontal
  #define GFxScaleMode_MAX            SM_MAX
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
  #define Align_Center           Align_Center
  #define Align_TopCenter        Align_TopCenter
  #define Align_BottomCenter     Align_BottomCenter
  #define Align_CenterLeft       Align_CenterLeft
  #define Align_CenterRight      Align_CenterRight
  #define Align_TopLeft          Align_TopLeft
  #define Align_TopRight         Align_TopRight
  #define Align_BottomLeft       Align_BottomLeft
  #define Align_BottomRight      Align_BottomRight
  #define Align_MAX              Align_MAX
  #define GFxAlign_Center        Align_Center
  #define GFxAlign_TopCenter     Align_TopCenter
  #define GFxAlign_BottomCenter  Align_BottomCenter
  #define GFxAlign_CenterLeft    Align_CenterLeft
  #define GFxAlign_CenterRight   Align_CenterRight
  #define GFxAlign_TopLeft       Align_TopLeft
  #define GFxAlign_TopRight      Align_TopRight
  #define GFxAlign_BottomLeft    Align_BottomLeft
  #define GFxAlign_BottomRight   Align_BottomRight
  #define GFxAlign_MAX           Align_MAX
} GFxAlign;
#define GFxTimingMode         GFxTimingMode
#define GFxRenderTextureMode  GFxRenderTextureMode
#define ASType                ASType
#define GFxScaleMode          GFxScaleMode
#define GFxAlign              GFxAlign

/* ---------------------------------------------------------- UAudioDevice ! ---------------------------------------------------------- */

typedef enum ESoundClassName : unsigned char {
  Master,                         // 0
  ESoundClassName_MAX             // 1
  #define Master                  Master
  #define ESoundClassName_Master  Master
  #define ESoundClassName_MAX     ESoundClassName_MAX
} ESoundClassName;
typedef enum EDebugState     : unsigned char {
  DEBUGSTATE_None,                // 0
  DEBUGSTATE_IsolateDryAudio,     // 1
  DEBUGSTATE_IsolateReverb,       // 2
  DEBUGSTATE_TestLPF,             // 3
  DEBUGSTATE_TestStereoBleed,     // 4
  DEBUGSTATE_TestLFEBleed,        // 5
  DEBUGSTATE_DisableLPF,          // 6
  DEBUGSTATE_DisableRadio,        // 7
  DEBUGSTATE_MAX                  // 8
  #define DEBUGSTATE_None              DEBUGSTATE_None
  #define DEBUGSTATE_IsolateDryAudio   DEBUGSTATE_IsolateDryAudio
  #define DEBUGSTATE_IsolateReverb     DEBUGSTATE_IsolateReverb
  #define DEBUGSTATE_TestLPF           DEBUGSTATE_TestLPF
  #define DEBUGSTATE_TestStereoBleed   DEBUGSTATE_TestStereoBleed
  #define DEBUGSTATE_TestLFEBleed      DEBUGSTATE_TestLFEBleed
  #define DEBUGSTATE_DisableLPF        DEBUGSTATE_DisableLPF
  #define DEBUGSTATE_DisableRadio      DEBUGSTATE_DisableRadio
  #define DEBUGSTATE_MAX               DEBUGSTATE_MAX
  #define EDebugState_None             DEBUGSTATE_None
  #define EDebugState_IsolateDryAudio  DEBUGSTATE_IsolateDryAudio
  #define EDebugState_IsolateReverb    DEBUGSTATE_IsolateReverb
  #define EDebugState_TestLPF          DEBUGSTATE_TestLPF
  #define EDebugState_TestStereoBleed  DEBUGSTATE_TestStereoBleed
  #define EDebugState_TestLFEBleed     DEBUGSTATE_TestLFEBleed
  #define EDebugState_DisableLPF       DEBUGSTATE_DisableLPF
  #define EDebugState_DisableRadio     DEBUGSTATE_DisableRadio
  #define EDebugState_MAX              DEBUGSTATE_MAX
} EDebugState;
typedef enum ETTSSpeaker     : unsigned char {
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
  #define TTSSPEAKER_Paul     TTSSPEAKER_Paul
  #define TTSSPEAKER_Harry    TTSSPEAKER_Harry
  #define TTSSPEAKER_Frank    TTSSPEAKER_Frank
  #define TTSSPEAKER_Dennis   TTSSPEAKER_Dennis
  #define TTSSPEAKER_Kit      TTSSPEAKER_Kit
  #define TTSSPEAKER_Betty    TTSSPEAKER_Betty
  #define TTSSPEAKER_Ursula   TTSSPEAKER_Ursula
  #define TTSSPEAKER_Rita     TTSSPEAKER_Rita
  #define TTSSPEAKER_Wendy    TTSSPEAKER_Wendy
  #define TTSSPEAKER_MAX      TTSSPEAKER_MAX
  #define ETTSSpeaker_Paul    TTSSPEAKER_Paul
  #define ETTSSpeaker_Harry   TTSSPEAKER_Harry
  #define ETTSSpeaker_Frank   TTSSPEAKER_Frank
  #define ETTSSpeaker_Dennis  TTSSPEAKER_Dennis
  #define ETTSSpeaker_Kit     TTSSPEAKER_Kit
  #define ETTSSpeaker_Betty   TTSSPEAKER_Betty
  #define ETTSSpeaker_Ursula  TTSSPEAKER_Ursula
  #define ETTSSpeaker_Rita    TTSSPEAKER_Rita
  #define ETTSSpeaker_Wendy   TTSSPEAKER_Wendy
  #define ETTSSpeaker_MAX     TTSSPEAKER_MAX
} ETTSSpeaker;
#define ESoundClassName  ESoundClassName
#define EDebugState      EDebugState
#define ETTSSpeaker      ETTSSpeaker

/* ---------------------------------------------------------- APawn ! ---------------------------------------------------------- */

typedef enum EPathSearchType : unsigned char {
  PST_Default,                    // 0
  PST_Breadth,                    // 1
  PST_NewBestPathTo,              // 2
  PST_Constraint,                 // 3
  PST_MAX                         // 4
  #define PST_Default                    PST_Default
  #define PST_Breadth                    PST_Breadth
  #define PST_NewBestPathTo              PST_NewBestPathTo
  #define PST_Constraint                 PST_Constraint
  #define PST_MAX                        PST_MAX
  #define EPathSearchType_Default        PST_Default
  #define EPathSearchType_Breadth        PST_Breadth
  #define EPathSearchType_NewBestPathTo  PST_NewBestPathTo
  #define EPathSearchType_Constraint     PST_Constraint
  #define EPathSearchType_MAX            PST_MAX
} EPathSearchType;
#define EPathSearchType  EPathSearchType

/* ---------------------------------------------------------- UGameViewportClient ! ---------------------------------------------------------- */

typedef enum ESplitScreenType : unsigned char {
  eSST_NONE,                      // 0
  eSST_2P_HORIZONTAL,             // 1
  eSST_2P_VERTICAL,               // 2
  eSST_3P_FAVOR_TOP,              // 3
  eSST_3P_FAVOR_BOTTOM,           // 4
  eSST_4P,                        // 5
  eSST_MAX                        // 6
  #define eSST_NONE                         eSST_NONE
  #define eSST_2P_HORIZONTAL                eSST_2P_HORIZONTAL
  #define eSST_2P_VERTICAL                  eSST_2P_VERTICAL
  #define eSST_3P_FAVOR_TOP                 eSST_3P_FAVOR_TOP
  #define eSST_3P_FAVOR_BOTTOM              eSST_3P_FAVOR_BOTTOM
  #define eSST_4P                           eSST_4P
  #define eSST_MAX                          eSST_MAX
  #define ESplitScreenType_NONE             eSST_NONE
  #define ESplitScreenType_2P_HORIZONTAL    eSST_2P_HORIZONTAL
  #define ESplitScreenType_2P_VERTICAL      eSST_2P_VERTICAL
  #define ESplitScreenType_3P_FAVOR_TOP     eSST_3P_FAVOR_TOP
  #define ESplitScreenType_3P_FAVOR_BOTTOM  eSST_3P_FAVOR_BOTTOM
  #define ESplitScreenType_4P               eSST_4P
  #define ESplitScreenType_MAX              eSST_MAX
} ESplitScreenType;
typedef enum ESafeZoneType    : unsigned char {
  eSZ_TOP,                        // 0
  eSZ_BOTTOM,                     // 1
  eSZ_LEFT,                       // 2
  eSZ_RIGHT,                      // 3
  eSZ_MAX                         // 4
  #define eSZ_TOP               eSZ_TOP
  #define eSZ_BOTTOM            eSZ_BOTTOM
  #define eSZ_LEFT              eSZ_LEFT
  #define eSZ_RIGHT             eSZ_RIGHT
  #define eSZ_MAX               eSZ_MAX
  #define ESafeZoneType_TOP     eSZ_TOP
  #define ESafeZoneType_BOTTOM  eSZ_BOTTOM
  #define ESafeZoneType_LEFT    eSZ_LEFT
  #define ESafeZoneType_RIGHT   eSZ_RIGHT
  #define ESafeZoneType_MAX     eSZ_MAX
} ESafeZoneType;
typedef enum EShowPathsOutput : unsigned char {
  eShowPaths_Off,                 // 0
  eAllReachSpecs,                 // 1
  eSpecialMovementsOnly,          // 2
  eNoSpecialMovements,            // 3
  EShowPathsOutput_MAX            // 4
  #define eShowPaths_Off                         eShowPaths_Off
  #define eAllReachSpecs                         eAllReachSpecs
  #define eSpecialMovementsOnly                  eSpecialMovementsOnly
  #define eNoSpecialMovements                    eNoSpecialMovements
  #define EShowPathsOutput_ShowPaths_Off         eShowPaths_Off
  #define EShowPathsOutput_AllReachSpecs         eAllReachSpecs
  #define EShowPathsOutput_SpecialMovementsOnly  eSpecialMovementsOnly
  #define EShowPathsOutput_NoSpecialMovements    eNoSpecialMovements
  #define EShowPathsOutput_MAX                   EShowPathsOutput_MAX
} EShowPathsOutput;
#define ESplitScreenType  ESplitScreenType
#define ESafeZoneType     ESafeZoneType
#define EShowPathsOutput  EShowPathsOutput

/* ---------------------------------------------------------- UEngineTypes ! ---------------------------------------------------------- */

typedef enum EPathFindingError               : unsigned char {
  PATHERROR_STARTPOLYNOTFOUND,    // 0
  PATHERROR_GOALPOLYNOTFOUND,     // 1
  PATHERROR_ANCHORPYLONNOTFOUND,  // 2
  PATHERROR_NOPATHFOUND,          // 3
  PATHERROR_COMPUTEVALIDFINALDEST_FAIL,// 4
  PATHERROR_GETNEXTMOVELOCATION_FAIL,// 5
  PATHERROR_MAX                   // 6
  #define PATHERROR_STARTPOLYNOTFOUND                   PATHERROR_STARTPOLYNOTFOUND
  #define PATHERROR_GOALPOLYNOTFOUND                    PATHERROR_GOALPOLYNOTFOUND
  #define PATHERROR_ANCHORPYLONNOTFOUND                 PATHERROR_ANCHORPYLONNOTFOUND
  #define PATHERROR_NOPATHFOUND                         PATHERROR_NOPATHFOUND
  #define PATHERROR_COMPUTEVALIDFINALDEST_FAIL          PATHERROR_COMPUTEVALIDFINALDEST_FAIL
  #define PATHERROR_GETNEXTMOVELOCATION_FAIL            PATHERROR_GETNEXTMOVELOCATION_FAIL
  #define PATHERROR_MAX                                 PATHERROR_MAX
  #define EPathFindingError_STARTPOLYNOTFOUND           PATHERROR_STARTPOLYNOTFOUND
  #define EPathFindingError_GOALPOLYNOTFOUND            PATHERROR_GOALPOLYNOTFOUND
  #define EPathFindingError_ANCHORPYLONNOTFOUND         PATHERROR_ANCHORPYLONNOTFOUND
  #define EPathFindingError_NOPATHFOUND                 PATHERROR_NOPATHFOUND
  #define EPathFindingError_COMPUTEVALIDFINALDEST_FAIL  PATHERROR_COMPUTEVALIDFINALDEST_FAIL
  #define EPathFindingError_GETNEXTMOVELOCATION_FAIL    PATHERROR_GETNEXTMOVELOCATION_FAIL
  #define EPathFindingError_MAX                         PATHERROR_MAX
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
  #define BLEND_Opaque                    BLEND_Opaque
  #define BLEND_Masked                    BLEND_Masked
  #define BLEND_Translucent               BLEND_Translucent
  #define BLEND_Additive                  BLEND_Additive
  #define BLEND_Modulate                  BLEND_Modulate
  #define BLEND_SoftMasked                BLEND_SoftMasked
  #define BLEND_AlphaComposite            BLEND_AlphaComposite
  #define BLEND_DitheredTranslucent       BLEND_DitheredTranslucent
  #define BLEND_MAX                       BLEND_MAX
  #define EBlendMode_Opaque               BLEND_Opaque
  #define EBlendMode_Masked               BLEND_Masked
  #define EBlendMode_Translucent          BLEND_Translucent
  #define EBlendMode_Additive             BLEND_Additive
  #define EBlendMode_Modulate             BLEND_Modulate
  #define EBlendMode_SoftMasked           BLEND_SoftMasked
  #define EBlendMode_AlphaComposite       BLEND_AlphaComposite
  #define EBlendMode_DitheredTranslucent  BLEND_DitheredTranslucent
  #define EBlendMode_MAX                  BLEND_MAX
} EBlendMode;
typedef enum EMaterialLightingModel          : unsigned char {
  MLM_Phong,                      // 0
  MLM_NonDirectional,             // 1
  MLM_Unlit,                      // 2
  MLM_SHPRT,                      // 3
  MLM_Custom,                     // 4
  MLM_Anisotropic,                // 5
  MLM_MAX                         // 6
  #define MLM_Phong                              MLM_Phong
  #define MLM_NonDirectional                     MLM_NonDirectional
  #define MLM_Unlit                              MLM_Unlit
  #define MLM_SHPRT                              MLM_SHPRT
  #define MLM_Custom                             MLM_Custom
  #define MLM_Anisotropic                        MLM_Anisotropic
  #define MLM_MAX                                MLM_MAX
  #define EMaterialLightingModel_Phong           MLM_Phong
  #define EMaterialLightingModel_NonDirectional  MLM_NonDirectional
  #define EMaterialLightingModel_Unlit           MLM_Unlit
  #define EMaterialLightingModel_SHPRT           MLM_SHPRT
  #define EMaterialLightingModel_Custom          MLM_Custom
  #define EMaterialLightingModel_Anisotropic     MLM_Anisotropic
  #define EMaterialLightingModel_MAX             MLM_MAX
} EMaterialLightingModel;
typedef enum EMaterialTessellationMode       : unsigned char {
  MTM_NoTessellation,             // 0
  MTM_FlatTessellation,           // 1
  MTM_PNTriangles,                // 2
  MTM_MAX                         // 3
  #define MTM_NoTessellation                          MTM_NoTessellation
  #define MTM_FlatTessellation                        MTM_FlatTessellation
  #define MTM_PNTriangles                             MTM_PNTriangles
  #define MTM_MAX                                     MTM_MAX
  #define EMaterialTessellationMode_NoTessellation    MTM_NoTessellation
  #define EMaterialTessellationMode_FlatTessellation  MTM_FlatTessellation
  #define EMaterialTessellationMode_PNTriangles       MTM_PNTriangles
  #define EMaterialTessellationMode_MAX               MTM_MAX
} EMaterialTessellationMode;
typedef enum EMobileTextureTransformTarget   : unsigned char {
  MTTT_BaseTexture,               // 0
  MTTT_DetailTexture,             // 1
  MTTT_MAX                        // 2
  #define MTTT_BaseTexture                             MTTT_BaseTexture
  #define MTTT_DetailTexture                           MTTT_DetailTexture
  #define MTTT_MAX                                     MTTT_MAX
  #define EMobileTextureTransformTarget_BaseTexture    MTTT_BaseTexture
  #define EMobileTextureTransformTarget_DetailTexture  MTTT_DetailTexture
  #define EMobileTextureTransformTarget_MAX            MTTT_MAX
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
  #define MVS_Constant                           MVS_Constant
  #define MVS_VertexColorRed                     MVS_VertexColorRed
  #define MVS_VertexColorGreen                   MVS_VertexColorGreen
  #define MVS_VertexColorBlue                    MVS_VertexColorBlue
  #define MVS_VertexColorAlpha                   MVS_VertexColorAlpha
  #define MVS_BaseTextureRed                     MVS_BaseTextureRed
  #define MVS_BaseTextureGreen                   MVS_BaseTextureGreen
  #define MVS_BaseTextureBlue                    MVS_BaseTextureBlue
  #define MVS_BaseTextureAlpha                   MVS_BaseTextureAlpha
  #define MVS_MaskTextureRed                     MVS_MaskTextureRed
  #define MVS_MaskTextureGreen                   MVS_MaskTextureGreen
  #define MVS_MaskTextureBlue                    MVS_MaskTextureBlue
  #define MVS_MaskTextureAlpha                   MVS_MaskTextureAlpha
  #define MVS_NormalTextureAlpha                 MVS_NormalTextureAlpha
  #define MVS_MAX                                MVS_MAX
  #define EMobileValueSource_Constant            MVS_Constant
  #define EMobileValueSource_VertexColorRed      MVS_VertexColorRed
  #define EMobileValueSource_VertexColorGreen    MVS_VertexColorGreen
  #define EMobileValueSource_VertexColorBlue     MVS_VertexColorBlue
  #define EMobileValueSource_VertexColorAlpha    MVS_VertexColorAlpha
  #define EMobileValueSource_BaseTextureRed      MVS_BaseTextureRed
  #define EMobileValueSource_BaseTextureGreen    MVS_BaseTextureGreen
  #define EMobileValueSource_BaseTextureBlue     MVS_BaseTextureBlue
  #define EMobileValueSource_BaseTextureAlpha    MVS_BaseTextureAlpha
  #define EMobileValueSource_MaskTextureRed      MVS_MaskTextureRed
  #define EMobileValueSource_MaskTextureGreen    MVS_MaskTextureGreen
  #define EMobileValueSource_MaskTextureBlue     MVS_MaskTextureBlue
  #define EMobileValueSource_MaskTextureAlpha    MVS_MaskTextureAlpha
  #define EMobileValueSource_NormalTextureAlpha  MVS_NormalTextureAlpha
  #define EMobileValueSource_MAX                 MVS_MAX
} EMobileValueSource;
typedef enum EMobileTextureBlendFactorSource : unsigned char {
  MTBFS_VertexColor,              // 0
  MTBFS_MaskTexture,              // 1
  MTBFS_MAX                       // 2
  #define MTBFS_VertexColor                            MTBFS_VertexColor
  #define MTBFS_MaskTexture                            MTBFS_MaskTexture
  #define MTBFS_MAX                                    MTBFS_MAX
  #define EMobileTextureBlendFactorSource_VertexColor  MTBFS_VertexColor
  #define EMobileTextureBlendFactorSource_MaskTexture  MTBFS_MaskTexture
  #define EMobileTextureBlendFactorSource_MAX          MTBFS_MAX
} EMobileTextureBlendFactorSource;
typedef enum EMobileTexCoordsSource          : unsigned char {
  MTCS_TexCoords0,                // 0
  MTCS_TexCoords1,                // 1
  MTCS_TexCoords2,                // 2
  MTCS_TexCoords3,                // 3
  MTCS_MAX                        // 4
  #define MTCS_TexCoords0                    MTCS_TexCoords0
  #define MTCS_TexCoords1                    MTCS_TexCoords1
  #define MTCS_TexCoords2                    MTCS_TexCoords2
  #define MTCS_TexCoords3                    MTCS_TexCoords3
  #define MTCS_MAX                           MTCS_MAX
  #define EMobileTexCoordsSource_TexCoords0  MTCS_TexCoords0
  #define EMobileTexCoordsSource_TexCoords1  MTCS_TexCoords1
  #define EMobileTexCoordsSource_TexCoords2  MTCS_TexCoords2
  #define EMobileTexCoordsSource_TexCoords3  MTCS_TexCoords3
  #define EMobileTexCoordsSource_MAX         MTCS_MAX
} EMobileTexCoordsSource;
typedef enum EMobileEmissiveColorSource      : unsigned char {
  MECS_EmissiveTexture,           // 0
  MECS_BaseTexture,               // 1
  MECS_Constant,                  // 2
  MECS_MAX                        // 3
  #define MECS_EmissiveTexture                        MECS_EmissiveTexture
  #define MECS_BaseTexture                            MECS_BaseTexture
  #define MECS_Constant                               MECS_Constant
  #define MECS_MAX                                    MECS_MAX
  #define EMobileEmissiveColorSource_EmissiveTexture  MECS_EmissiveTexture
  #define EMobileEmissiveColorSource_BaseTexture      MECS_BaseTexture
  #define EMobileEmissiveColorSource_Constant         MECS_Constant
  #define EMobileEmissiveColorSource_MAX              MECS_MAX
} EMobileEmissiveColorSource;
typedef enum EMobileEnvironmentBlendMode     : unsigned char {
  MEBM_Add,                       // 0
  MEBM_Lerp,                      // 1
  MEBM_MAX                        // 2
  #define MEBM_Add                          MEBM_Add
  #define MEBM_Lerp                         MEBM_Lerp
  #define MEBM_MAX                          MEBM_MAX
  #define EMobileEnvironmentBlendMode_Add   MEBM_Add
  #define EMobileEnvironmentBlendMode_Lerp  MEBM_Lerp
  #define EMobileEnvironmentBlendMode_MAX   MEBM_MAX
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
  #define MSM_Constant                        MSM_Constant
  #define MSM_Luminance                       MSM_Luminance
  #define MSM_DiffuseRed                      MSM_DiffuseRed
  #define MSM_DiffuseGreen                    MSM_DiffuseGreen
  #define MSM_DiffuseBlue                     MSM_DiffuseBlue
  #define MSM_DiffuseAlpha                    MSM_DiffuseAlpha
  #define MSM_MaskTextureRGB                  MSM_MaskTextureRGB
  #define MSM_MAX                             MSM_MAX
  #define EMobileSpecularMask_Constant        MSM_Constant
  #define EMobileSpecularMask_Luminance       MSM_Luminance
  #define EMobileSpecularMask_DiffuseRed      MSM_DiffuseRed
  #define EMobileSpecularMask_DiffuseGreen    MSM_DiffuseGreen
  #define EMobileSpecularMask_DiffuseBlue     MSM_DiffuseBlue
  #define EMobileSpecularMask_DiffuseAlpha    MSM_DiffuseAlpha
  #define EMobileSpecularMask_MaskTextureRGB  MSM_MaskTextureRGB
  #define EMobileSpecularMask_MAX             MSM_MAX
} EMobileSpecularMask;
typedef enum EMobileAmbientOcclusionSource   : unsigned char {
  MAOS_Disabled,                  // 0
  MAOS_VertexColorRed,            // 1
  MAOS_VertexColorGreen,          // 2
  MAOS_VertexColorBlue,           // 3
  MAOS_VertexColorAlpha,          // 4
  MAOS_MAX                        // 5
  #define MAOS_Disabled                                   MAOS_Disabled
  #define MAOS_VertexColorRed                             MAOS_VertexColorRed
  #define MAOS_VertexColorGreen                           MAOS_VertexColorGreen
  #define MAOS_VertexColorBlue                            MAOS_VertexColorBlue
  #define MAOS_VertexColorAlpha                           MAOS_VertexColorAlpha
  #define MAOS_MAX                                        MAOS_MAX
  #define EMobileAmbientOcclusionSource_Disabled          MAOS_Disabled
  #define EMobileAmbientOcclusionSource_VertexColorRed    MAOS_VertexColorRed
  #define EMobileAmbientOcclusionSource_VertexColorGreen  MAOS_VertexColorGreen
  #define EMobileAmbientOcclusionSource_VertexColorBlue   MAOS_VertexColorBlue
  #define EMobileAmbientOcclusionSource_VertexColorAlpha  MAOS_VertexColorAlpha
  #define EMobileAmbientOcclusionSource_MAX               MAOS_MAX
} EMobileAmbientOcclusionSource;
typedef enum ELightingBuildQuality           : unsigned char {
  Quality_Preview,                // 0
  Quality_Medium,                 // 1
  Quality_High,                   // 2
  Quality_Production,             // 3
  Quality_NoGlobalIllumination,   // 4
  Quality_MAX                     // 5
  #define Quality_Preview                             Quality_Preview
  #define Quality_Medium                              Quality_Medium
  #define Quality_High                                Quality_High
  #define Quality_Production                          Quality_Production
  #define Quality_NoGlobalIllumination                Quality_NoGlobalIllumination
  #define Quality_MAX                                 Quality_MAX
  #define ELightingBuildQuality_Preview               Quality_Preview
  #define ELightingBuildQuality_Medium                Quality_Medium
  #define ELightingBuildQuality_High                  Quality_High
  #define ELightingBuildQuality_Production            Quality_Production
  #define ELightingBuildQuality_NoGlobalIllumination  Quality_NoGlobalIllumination
  #define ELightingBuildQuality_MAX                   Quality_MAX
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

/* ---------------------------------------------------------- UResourcePool ! ---------------------------------------------------------- */

typedef enum EResourcePoolState : unsigned char {
  RPS_Depleted,                   // 0
  RPS_Filled,                     // 1
  RPS_Regenerating,               // 2
  RPS_MAX                         // 3
  #define RPS_Depleted                     RPS_Depleted
  #define RPS_Filled                       RPS_Filled
  #define RPS_Regenerating                 RPS_Regenerating
  #define RPS_MAX                          RPS_MAX
  #define EResourcePoolState_Depleted      RPS_Depleted
  #define EResourcePoolState_Filled        RPS_Filled
  #define EResourcePoolState_Regenerating  RPS_Regenerating
  #define EResourcePoolState_MAX           RPS_MAX
} EResourcePoolState;
#define EResourcePoolState  EResourcePoolState

/* ---------------------------------------------------------- UResourcePoolDefinition ! ---------------------------------------------------------- */

typedef enum ENetRelevantFor : unsigned char {
  NETRELEVANT_Everyone,           // 0
  NETRELEVANT_Owner,              // 1
  NETRELEVANT_Server,             // 2
  NETRELEVANT_MAX                 // 3
  #define NETRELEVANT_Everyone      NETRELEVANT_Everyone
  #define NETRELEVANT_Owner         NETRELEVANT_Owner
  #define NETRELEVANT_Server        NETRELEVANT_Server
  #define NETRELEVANT_MAX           NETRELEVANT_MAX
  #define ENetRelevantFor_Everyone  NETRELEVANT_Everyone
  #define ENetRelevantFor_Owner     NETRELEVANT_Owner
  #define ENetRelevantFor_Server    NETRELEVANT_Server
  #define ENetRelevantFor_MAX       NETRELEVANT_MAX
} ENetRelevantFor;
#define ENetRelevantFor  ENetRelevantFor

/* ---------------------------------------------------------- UMusicTrackDataStructures ! ---------------------------------------------------------- */

typedef enum EMusicState : unsigned char {
  MUSIC_PlayingAmbientMusic,      // 0
  MUSIC_PlayingCustomAmbientMusic,// 1
  MUSIC_PlayingCombatMusicFull,   // 2
  MUSIC_PlayingCombatMusicMid,    // 3
  MUSIC_PlayingBossMusic,         // 4
  MUSIC_PlayingCustomCombatMusic, // 5
  MUSIC_MAX                       // 6
  #define MUSIC_PlayingAmbientMusic              MUSIC_PlayingAmbientMusic
  #define MUSIC_PlayingCustomAmbientMusic        MUSIC_PlayingCustomAmbientMusic
  #define MUSIC_PlayingCombatMusicFull           MUSIC_PlayingCombatMusicFull
  #define MUSIC_PlayingCombatMusicMid            MUSIC_PlayingCombatMusicMid
  #define MUSIC_PlayingBossMusic                 MUSIC_PlayingBossMusic
  #define MUSIC_PlayingCustomCombatMusic         MUSIC_PlayingCustomCombatMusic
  #define MUSIC_MAX                              MUSIC_MAX
  #define EMusicState_PlayingAmbientMusic        MUSIC_PlayingAmbientMusic
  #define EMusicState_PlayingCustomAmbientMusic  MUSIC_PlayingCustomAmbientMusic
  #define EMusicState_PlayingCombatMusicFull     MUSIC_PlayingCombatMusicFull
  #define EMusicState_PlayingCombatMusicMid      MUSIC_PlayingCombatMusicMid
  #define EMusicState_PlayingBossMusic           MUSIC_PlayingBossMusic
  #define EMusicState_PlayingCustomCombatMusic   MUSIC_PlayingCustomCombatMusic
  #define EMusicState_MAX                        MUSIC_MAX
} EMusicState;
#define EMusicState  EMusicState

/* ---------------------------------------------------------- FPacketSimulationSettings ! ---------------------------------------------------------- */

/* Types of channels. */
typedef enum EChannelType : unsigned char {
	CHTYPE_None    = 0,  /** Invalid type. */
	CHTYPE_Control = 1,  /** Connection control. */
	CHTYPE_Actor   = 2,  /** Actor-update channel. */
	CHTYPE_File    = 3,  /** Binary file transfer. */
	CHTYPE_Voice   = 4,  /** VoIP data channel */
	CHTYPE_MAX     = 8,  /** Maximum. */
  #define CHTYPE_None           CHTYPE_None
  #define CHTYPE_Control        CHTYPE_Control
  #define CHTYPE_Actor          CHTYPE_Actor
  #define CHTYPE_File           CHTYPE_File
  #define CHTYPE_Voice          CHTYPE_Voice
  #define CHTYPE_MAX            CHTYPE_MAX
  #define EChannelType_None     CHTYPE_None
  #define EChannelType_Control  CHTYPE_Control
  #define EChannelType_Actor    CHTYPE_Actor
  #define EChannelType_File     CHTYPE_File
  #define EChannelType_Voice    CHTYPE_Voice
  #define EChannelType_MAX      CHTYPE_MAX
} EChannelType;
#define EChannelType  EChannelType

/* ---------------------------------------------------------- UWillowDamageTypeDefinition ! ---------------------------------------------------------- */

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
  #define DAMAGE_TYPE_Unknown     DAMAGE_TYPE_Unknown
  #define DAMAGE_TYPE_Incindiary  DAMAGE_TYPE_Incindiary
  #define DAMAGE_TYPE_Shock       DAMAGE_TYPE_Shock
  #define DAMAGE_TYPE_Explosive   DAMAGE_TYPE_Explosive
  #define DAMAGE_TYPE_Corrosive   DAMAGE_TYPE_Corrosive
  #define DAMAGE_TYPE_Impact      DAMAGE_TYPE_Impact
  #define DAMAGE_TYPE_Healing     DAMAGE_TYPE_Healing
  #define DAMAGE_TYPE_Amp         DAMAGE_TYPE_Amp
  #define DAMAGE_TYPE_MAX         DAMAGE_TYPE_MAX
  #define EDamageType_Unknown     DAMAGE_TYPE_Unknown
  #define EDamageType_Incindiary  DAMAGE_TYPE_Incindiary
  #define EDamageType_Shock       DAMAGE_TYPE_Shock
  #define EDamageType_Explosive   DAMAGE_TYPE_Explosive
  #define EDamageType_Corrosive   DAMAGE_TYPE_Corrosive
  #define EDamageType_Impact      DAMAGE_TYPE_Impact
  #define EDamageType_Healing     DAMAGE_TYPE_Healing
  #define EDamageType_Amp         DAMAGE_TYPE_Amp
  #define EDamageType_MAX         DAMAGE_TYPE_MAX
} EDamageType;
#define EDamageType  EDamageType
_DECL_TARRAY(EDamageType);

/* ---------------------------------------------------------- UBehaviorBase ! ---------------------------------------------------------- */

typedef enum EBehaviorContext : unsigned char {
  BCONTEXT_Self,                  // 0
  BCONTEXT_MyInstigator,          // 1
  BCONTEXT_OtherEventParticipant, // 2
  BCONTEXT_EventData,             // 3
  BCONTEXT_UseContextObject,      // 4
  BCONTEXT_MAX                    // 5
  #define BCONTEXT_Self                           BCONTEXT_Self
  #define BCONTEXT_MyInstigator                   BCONTEXT_MyInstigator
  #define BCONTEXT_OtherEventParticipant          BCONTEXT_OtherEventParticipant
  #define BCONTEXT_EventData                      BCONTEXT_EventData
  #define BCONTEXT_UseContextObject               BCONTEXT_UseContextObject
  #define BCONTEXT_MAX                            BCONTEXT_MAX
  #define EBehaviorContext_Self                   BCONTEXT_Self
  #define EBehaviorContext_MyInstigator           BCONTEXT_MyInstigator
  #define EBehaviorContext_OtherEventParticipant  BCONTEXT_OtherEventParticipant
  #define EBehaviorContext_EventData              BCONTEXT_EventData
  #define EBehaviorContext_UseContextObject       BCONTEXT_UseContextObject
  #define EBehaviorContext_MAX                    BCONTEXT_MAX
} EBehaviorContext;
#define EBehaviorContext  EBehaviorContext

/* ---------------------------------------------------------- UStatusEffectDefinition ! ---------------------------------------------------------- */

typedef enum EStatusEffectType : unsigned char {
  STATUS_EFFECT_Unknown,          // 0
  STATUS_EFFECT_Ignite,           // 1
  STATUS_EFFECT_Corrosive,        // 2
  STATUS_EFFECT_Shock,            // 3
  STATUS_EFFECT_Amp,              // 4
  STATUS_EFFECT_Slow,             // 5
  STATUS_EFFECT_Healing,          // 6
  STATUS_EFFECT_MAX               // 7
  #define STATUS_EFFECT_Unknown        STATUS_EFFECT_Unknown
  #define STATUS_EFFECT_Ignite         STATUS_EFFECT_Ignite
  #define STATUS_EFFECT_Corrosive      STATUS_EFFECT_Corrosive
  #define STATUS_EFFECT_Shock          STATUS_EFFECT_Shock
  #define STATUS_EFFECT_Amp            STATUS_EFFECT_Amp
  #define STATUS_EFFECT_Slow           STATUS_EFFECT_Slow
  #define STATUS_EFFECT_Healing        STATUS_EFFECT_Healing
  #define STATUS_EFFECT_MAX            STATUS_EFFECT_MAX
  #define EStatusEffectType_Unknown    STATUS_EFFECT_Unknown
  #define EStatusEffectType_Ignite     STATUS_EFFECT_Ignite
  #define EStatusEffectType_Corrosive  STATUS_EFFECT_Corrosive
  #define EStatusEffectType_Shock      STATUS_EFFECT_Shock
  #define EStatusEffectType_Amp        STATUS_EFFECT_Amp
  #define EStatusEffectType_Slow       STATUS_EFFECT_Slow
  #define EStatusEffectType_Healing    STATUS_EFFECT_Healing
  #define EStatusEffectType_MAX        STATUS_EFFECT_MAX
} EStatusEffectType;
#define EStatusEffectType  EStatusEffectType
_DECL_TARRAY(EStatusEffectType);

/* ---------------------------------------------------------- UWillowPhysicalMaterialProperty ! ---------------------------------------------------------- */

typedef enum EImpactUsage       : unsigned char {
  IU_None,                        // 0
  IU_Footstep,                    // 1
  IU_Bullet,                      // 2
  IU_MAX                          // 3
  #define IU_None                IU_None
  #define IU_Footstep            IU_Footstep
  #define IU_Bullet              IU_Bullet
  #define IU_MAX                 IU_MAX
  #define EImpactUsage_None      IU_None
  #define EImpactUsage_Footstep  IU_Footstep
  #define EImpactUsage_Bullet    IU_Bullet
  #define EImpactUsage_MAX       IU_MAX
} EImpactUsage;
typedef enum EDamageSurfaceType : unsigned char {
  DMGSURFACE_Generic,             // 0
  DMGSURFACE_Flesh,               // 1
  DMGSURFACE_Armor,               // 2
  DMGSURFACE_Shield,              // 3
  DMGSURFACE_MAX                  // 4
  #define DMGSURFACE_Generic          DMGSURFACE_Generic
  #define DMGSURFACE_Flesh            DMGSURFACE_Flesh
  #define DMGSURFACE_Armor            DMGSURFACE_Armor
  #define DMGSURFACE_Shield           DMGSURFACE_Shield
  #define DMGSURFACE_MAX              DMGSURFACE_MAX
  #define EDamageSurfaceType_Generic  DMGSURFACE_Generic
  #define EDamageSurfaceType_Flesh    DMGSURFACE_Flesh
  #define EDamageSurfaceType_Armor    DMGSURFACE_Armor
  #define EDamageSurfaceType_Shield   DMGSURFACE_Shield
  #define EDamageSurfaceType_MAX      DMGSURFACE_MAX
} EDamageSurfaceType;
#define EImpactUsage        EImpactUsage
#define EDamageSurfaceType  EDamageSurfaceType

/* ---------------------------------------------------------- UIScreenParticle ! ---------------------------------------------------------- */

typedef enum ScreenParticleScalingMode : unsigned char {
  ESPSM_FitToHorizontal,          // 0
  ESPSM_FitToVertical,            // 1
  ESPSM_FitToExterior,            // 2
  ESPSM_FitToInterior,            // 3
  ESPSM_FitToViewport,            // 4
  ESPSM_MAX                       // 5
  #define ESPSM_FitToHorizontal                      ESPSM_FitToHorizontal
  #define ESPSM_FitToVertical                        ESPSM_FitToVertical
  #define ESPSM_FitToExterior                        ESPSM_FitToExterior
  #define ESPSM_FitToInterior                        ESPSM_FitToInterior
  #define ESPSM_FitToViewport                        ESPSM_FitToViewport
  #define ESPSM_MAX                                  ESPSM_MAX
  #define ScreenParticleScalingMode_FitToHorizontal  ESPSM_FitToHorizontal
  #define ScreenParticleScalingMode_FitToVertical    ESPSM_FitToVertical
  #define ScreenParticleScalingMode_FitToExterior    ESPSM_FitToExterior
  #define ScreenParticleScalingMode_FitToInterior    ESPSM_FitToInterior
  #define ScreenParticleScalingMode_FitToViewport    ESPSM_FitToViewport
  #define ScreenParticleScalingMode_MAX              ESPSM_MAX
} ScreenParticleScalingMode;
#define ScreenParticleScalingMode  ScreenParticleScalingMode

/* ---------------------------------------------------------- UIUpdatePostProcessOverride ! ---------------------------------------------------------- */

typedef enum EPostProcessOverrideUpdatePhase : unsigned char {
  PPUPDATEPHASE_None,             // 0
  PPUPDATEPHASE_TransitionIn,     // 1
  PPUPDATEPHASE_TransitionHold,   // 2
  PPUPDATEPHASE_TransitionOut,    // 3
  PPUPDATEPHASE_MAX               // 4
  #define PPUPDATEPHASE_None                              PPUPDATEPHASE_None
  #define PPUPDATEPHASE_TransitionIn                      PPUPDATEPHASE_TransitionIn
  #define PPUPDATEPHASE_TransitionHold                    PPUPDATEPHASE_TransitionHold
  #define PPUPDATEPHASE_TransitionOut                     PPUPDATEPHASE_TransitionOut
  #define PPUPDATEPHASE_MAX                               PPUPDATEPHASE_MAX
  #define EPostProcessOverrideUpdatePhase_None            PPUPDATEPHASE_None
  #define EPostProcessOverrideUpdatePhase_TransitionIn    PPUPDATEPHASE_TransitionIn
  #define EPostProcessOverrideUpdatePhase_TransitionHold  PPUPDATEPHASE_TransitionHold
  #define EPostProcessOverrideUpdatePhase_TransitionOut   PPUPDATEPHASE_TransitionOut
  #define EPostProcessOverrideUpdatePhase_MAX             PPUPDATEPHASE_MAX
} EPostProcessOverrideUpdatePhase;
typedef enum EAttributeScalarParamOperand    : unsigned char {
  ASPO_None,                      // 0
  ASPO_Add,                       // 1
  ASPO_Subtract,                  // 2
  ASPO_MAX                        // 3
  #define ASPO_None                              ASPO_None
  #define ASPO_Add                               ASPO_Add
  #define ASPO_Subtract                          ASPO_Subtract
  #define ASPO_MAX                               ASPO_MAX
  #define EAttributeScalarParamOperand_None      ASPO_None
  #define EAttributeScalarParamOperand_Add       ASPO_Add
  #define EAttributeScalarParamOperand_Subtract  ASPO_Subtract
  #define EAttributeScalarParamOperand_MAX       ASPO_MAX
} EAttributeScalarParamOperand;
#define EPostProcessOverrideUpdatePhase  EPostProcessOverrideUpdatePhase
#define EAttributeScalarParamOperand     EAttributeScalarParamOperand

/* ---------------------------------------------------------- UDOFEffect ! ---------------------------------------------------------- */

typedef enum EFocusType : unsigned char {
  FOCUS_Distance,                 // 0
  FOCUS_Position,                 // 1
  FOCUS_MAX                       // 2
  #define FOCUS_Distance       FOCUS_Distance
  #define FOCUS_Position       FOCUS_Position
  #define FOCUS_MAX            FOCUS_MAX
  #define EFocusType_Distance  FOCUS_Distance
  #define EFocusType_Position  FOCUS_Position
  #define EFocusType_MAX       FOCUS_MAX
} EFocusType;
#define EFocusType  EFocusType

/* ---------------------------------------------------------- FRawDistribution ! ---------------------------------------------------------- */

typedef enum ERawDistributionType      : unsigned char {
	RDT_Float_Constant,
	DT_Vector_Constant,
  #define RDT_Float_Constant                    RDT_Float_Constant
  #define DT_Vector_Constant                    DT_Vector_Constant
  #define ERawDistributionType_Float_Constant   RDT_Float_Constant
  #define ERawDistributionType_Vector_Constant  DT_Vector_Constant
} ERawDistributionType;
typedef enum ERawDistributionOperation : unsigned char {
	RDO_Uninitialized,
	RDO_None,
	RDO_Random,
	RDO_Extreme,
  #define RDO_Uninitialized                        RDO_Uninitialized
  #define RDO_None                                 RDO_None
  #define RDO_Random                               RDO_Random
  #define RDO_Extreme                              RDO_Extreme
  #define ERawDistributionOperation_Uninitialized  RDO_Uninitialized
  #define ERawDistributionOperation_None           RDO_None
  #define ERawDistributionOperation_Random         RDO_Random
  #define ERawDistributionOperation_Extreme        RDO_Extreme
} ERawDistributionOperation;
typedef enum ERawDistributionLockFlags : unsigned char {
	RDL_None,
	RDL_XY,
	RDL_XZ,
	RDL_YZ,
	RDL_XYZ,
  #define RDL_None                        RDL_None
  #define RDL_XY                          RDL_XY
  #define RDL_XZ                          RDL_XZ
  #define RDL_YZ                          RDL_YZ
  #define RDL_XYZ                         RDL_XYZ
  #define ERawDistributionLockFlags_None  RDL_None
  #define ERawDistributionLockFlags_XY    RDL_XY
  #define ERawDistributionLockFlags_XZ    RDL_XZ
  #define ERawDistributionLockFlags_YZ    RDL_YZ
  #define ERawDistributionLockFlags_XYZ   RDL_XYZ
} ERawDistributionLockFlags;
#define ERawDistributionType       ERawDistributionType
#define ERawDistributionOperation  ERawDistributionOperation
#define ERawDistributionLockFlags  ERawDistributionLockFlags

/* ---------------------------------------------------------- FRunnableThread ! ---------------------------------------------------------- */

/* The list of enumerated thread priorities we support. */
typedef enum EThreadPriority : unsigned char {
	TPri_Normal,
	TPri_AboveNormal,
	TPri_BelowNormal
  #define TPri_Normal                  TPri_Normal
  #define TPri_AboveNormal             TPri_AboveNormal
  #define TPri_BelowNormal             TPri_BelowNormal
  #define EThreadPriority_Normal       TPri_Normal
  #define EThreadPriority_AboveNormal  TPri_AboveNormal
  #define EThreadPriority_BelowNormal  TPri_BelowNormal
} EThreadPriority;
#define EThreadPriority  EThreadPriority

/**
 * Some standard IDs for special queued work types
 * These are just setup for future use, these aren't supported yet
 */
enum EWorkID {
	WORK_None,
	WORK_DMARequest,
	WORK_Skin,
	WORK_ShadowExtrusion,
	WORK_Decompress,
	WORK_Stream,
	WORK_GenerateParticles,
	WORK_MAX
};

/* ---------------------------------------------------------- Shader PLACEHOLDER ! ---------------------------------------------------------- */

/**
 * Material shader platforms represent the different versions of FMaterialResources 
 * that will have to be stored for a single UMaterial.  Note that multiple shader platforms 
 * can map to a single material platform.
 */
typedef enum EMaterialShaderPlatform : unsigned char {
	MSP_BASE = 0,
	MSP_SM3  = 0,
	MSP_MAX  = 1
  #define MSP_BASE                      MSP_BASE
  #define MSP_SM3                       MSP_SM3
  #define MSP_MAX                       MSP_MAX
  #define EMaterialShaderPlatform_BASE  MSP_BASE
  #define EMaterialShaderPlatform_SM3   MSP_SM3
  #define EMaterialShaderPlatform_MAX   MSP_MAX
} EMaterialShaderPlatform;
typedef enum EShaderFrequency        : unsigned char {
	SF_Vertex         = 0,
	SF_Hull           = 1,
	SF_Domain         = 2,
	SF_Pixel          = 3,
	SF_Geometry       = 4,
	SF_Compute        = 5,
	SF_NumFrequencies = 6,
	SF_NumBits        = 3,
  #define SF_Vertex                        SF_Vertex
  #define SF_Hull                          SF_Hull
  #define SF_Domain                        SF_Domain
  #define SF_Pixel                         SF_Pixel
  #define SF_Geometry                      SF_Geometry
  #define SF_Compute                       SF_Compute
  #define SF_NumFrequencies                SF_NumFrequencies
  #define SF_NumBits                       SF_NumBits
  #define EShaderFrequency_Vertex          SF_Vertex
  #define EShaderFrequency_Hull            SF_Hull
  #define EShaderFrequency_Domain          SF_Domain
  #define EShaderFrequency_Pixel           SF_Pixel
  #define EShaderFrequency_Geometry        SF_Geometry
  #define EShaderFrequency_Compute         SF_Compute
  #define EShaderFrequency_NumFrequencies  SF_NumFrequencies
  #define EShaderFrequency_NumBits         SF_NumBits
} EShaderFrequency;
/** @warning: update ShaderPlatformToText and GetMaterialPlatform when the below changes */
typedef enum EShaderPlatform         : unsigned char {
	SP_PCD3D_SM3    = 0,
	SP_PS3          = 1,
	SP_XBOXD3D      = 2,
	SP_PCD3D_SM4    = 3,
	SP_PCD3D_SM5    = 4,
	SP_NGP          = 5,
	SP_PCOGL        = 6,
	SP_NumPlatforms = 7,
	SP_NumBits      = 3,
  #define SP_PCD3D_SM3                  SP_PCD3D_SM3
  #define SP_PS3                        SP_PS3
  #define SP_XBOXD3D                    SP_XBOXD3D
  #define SP_PCD3D_SM4                  SP_PCD3D_SM4
  #define SP_PCD3D_SM5                  SP_PCD3D_SM5
  #define SP_NGP                        SP_NGP
  #define SP_PCOGL                      SP_PCOGL
  #define SP_NumPlatforms               SP_NumPlatforms
  #define SP_NumBits                    SP_NumBits
  #define EShaderPlatform_PCD3D_SM3     SP_PCD3D_SM3
  #define EShaderPlatform_PS3           SP_PS3
  #define EShaderPlatform_XBOXD3D       SP_XBOXD3D
  #define EShaderPlatform_PCD3D_SM4     SP_PCD3D_SM4
  #define EShaderPlatform_PCD3D_SM5     SP_PCD3D_SM5
  #define EShaderPlatform_NGP           SP_NGP
  #define EShaderPlatform_PCOGL         SP_PCOGL
  #define EShaderPlatform_NumPlatforms  SP_NumPlatforms
  #define EShaderPlatform_NumBits       SP_NumBits
} EShaderPlatform;
typedef enum ECompilerFlags          : unsigned char {
	CFLAG_PreferFlowControl = 0,
	CFLAG_Debug,
	CFLAG_AvoidFlowControl,
	CFLAG_SkipValidation  /** Disable shader validation */
  #define CFLAG_PreferFlowControl           CFLAG_PreferFlowControl
  #define CFLAG_Debug                       CFLAG_Debug
  #define CFLAG_AvoidFlowControl            CFLAG_AvoidFlowControl
  #define CFLAG_SkipValidation              CFLAG_SkipValidation
  #define ECompilerFlags_PreferFlowControl  CFLAG_PreferFlowControl
  #define ECompilerFlags_Debug              CFLAG_Debug
  #define ECompilerFlags_AvoidFlowControl   CFLAG_AvoidFlowControl
  #define ECompilerFlags_SkipValidation     CFLAG_SkipValidation
} ECompilerFlags;
typedef enum EWorkerJobType          : unsigned char {
	WJT_D3D9Shader = 0,
	WJT_D3D11Shader,
	WJT_XenonShader,
	WJT_PS3Shader,
	WJT_WorkerError,
	WJT_JobTypeMax
  #define WJT_D3D9Shader              WJT_D3D9Shader
  #define WJT_D3D11Shader             WJT_D3D11Shader
  #define WJT_XenonShader             WJT_XenonShader
  #define WJT_PS3Shader               WJT_PS3Shader
  #define WJT_WorkerError             WJT_WorkerError
  #define WJT_JobTypeMax              WJT_JobTypeMax
  #define EWorkerJobType_D3D9Shader   WJT_D3D9Shader
  #define EWorkerJobType_D3D11Shader  WJT_D3D11Shader
  #define EWorkerJobType_XenonShader  WJT_XenonShader
  #define EWorkerJobType_PS3Shader    WJT_PS3Shader
  #define EWorkerJobType_WorkerError  WJT_WorkerError
  #define EWorkerJobType_JobTypeMax   WJT_JobTypeMax
} EWorkerJobType;
#define ECompilerFlags           ECompilerFlags
#define EMaterialShaderPlatform  EMaterialShaderPlatform
#define EShaderFrequency         EShaderFrequency
#define EShaderPlatform          EShaderPlatform
#define EWorkerJobType           EWorkerJobType

/* ---------------------------------------------------------- UDebugger ! ---------------------------------------------------------- */

/*-----------------------------------------------------------------------------
	UDebugger Opcodes.
-----------------------------------------------------------------------------*/
typedef enum EDebugInfo  : unsigned char {
	DI_Let              = 0x00,
	DI_SimpleIf         = 0x01,
	DI_Switch           = 0x02,
	DI_While            = 0x03,
	DI_Assert           = 0x04,
	DI_Return           = 0x10,
	DI_ReturnNothing    = 0x11,
	DI_NewStack         = 0x20,
	DI_NewStackLatent   = 0x21,
	DI_NewStackLabel    = 0x22,
	DI_NewStackState    = 0x23,
	DI_PrevStack        = 0x30,
	DI_PrevStackLatent  = 0x31,
	DI_PrevStackLabel   = 0x32,
	DI_PrevStackState   = 0x33,
	DI_EFP              = 0x40,
	DI_EFPOper          = 0x41,
	DI_EFPIter          = 0x42,
	DI_ForInit          = 0x50,
	DI_ForEval          = 0x51,
	DI_ForInc           = 0x52,
	DI_BreakLoop        = 0x60,
	DI_BreakFor         = 0x61,
	DI_BreakForEach     = 0x62,
	DI_BreakSwitch      = 0x63,
	DI_ContinueLoop     = 0x70,
	DI_ContinueForeach  = 0x71,
	DI_ContinueFor      = 0x72,
	DI_MAX              = 0xFF,
  #define DI_Let                      DI_Let
  #define DI_SimpleIf                 DI_SimpleIf
  #define DI_Switch                   DI_Switch
  #define DI_While                    DI_While
  #define DI_Assert                   DI_Assert
  #define DI_Return                   DI_Return
  #define DI_ReturnNothing            DI_ReturnNothing
  #define DI_NewStack                 DI_NewStack
  #define DI_NewStackLatent           DI_NewStackLatent
  #define DI_NewStackLabel            DI_NewStackLabel
  #define DI_NewStackState            DI_NewStackState
  #define DI_PrevStack                DI_PrevStack
  #define DI_PrevStackLatent          DI_PrevStackLatent
  #define DI_PrevStackLabel           DI_PrevStackLabel
  #define DI_PrevStackState           DI_PrevStackState
  #define DI_EFP                      DI_EFP
  #define DI_EFPOper                  DI_EFPOper
  #define DI_EFPIter                  DI_EFPIter
  #define DI_ForInit                  DI_ForInit
  #define DI_ForEval                  DI_ForEval
  #define DI_ForInc                   DI_ForInc
  #define DI_BreakLoop                DI_BreakLoop
  #define DI_BreakFor                 DI_BreakFor
  #define DI_BreakForEach             DI_BreakForEach
  #define DI_BreakSwitch              DI_BreakSwitch
  #define DI_ContinueLoop             DI_ContinueLoop
  #define DI_ContinueForeach          DI_ContinueForeach
  #define DI_ContinueFor              DI_ContinueFor
  #define DI_MAX                      DI_MAX
  #define EDebugInfo_Let              DI_Let
  #define EDebugInfo_SimpleIf         DI_SimpleIf
  #define EDebugInfo_Switch           DI_Switch
  #define EDebugInfo_While            DI_While
  #define EDebugInfo_Assert           DI_Assert
  #define EDebugInfo_Return           DI_Return
  #define EDebugInfo_ReturnNothing    DI_ReturnNothing
  #define EDebugInfo_NewStack         DI_NewStack
  #define EDebugInfo_NewStackLatent   DI_NewStackLatent
  #define EDebugInfo_NewStackLabel    DI_NewStackLabel
  #define EDebugInfo_NewStackState    DI_NewStackState
  #define EDebugInfo_PrevStack        DI_PrevStack
  #define EDebugInfo_PrevStackLatent  DI_PrevStackLatent
  #define EDebugInfo_PrevStackLabel   DI_PrevStackLabel
  #define EDebugInfo_PrevStackState   DI_PrevStackState
  #define EDebugInfo_EFP              DI_EFP
  #define EDebugInfo_EFPOper          DI_EFPOper
  #define EDebugInfo_EFPIter          DI_EFPIter
  #define EDebugInfo_ForInit          DI_ForInit
  #define EDebugInfo_ForEval          DI_ForEval
  #define EDebugInfo_ForInc           DI_ForInc
  #define EDebugInfo_BreakLoop        DI_BreakLoop
  #define EDebugInfo_BreakFor         DI_BreakFor
  #define EDebugInfo_BreakForEach     DI_BreakForEach
  #define EDebugInfo_BreakSwitch      DI_BreakSwitch
  #define EDebugInfo_ContinueLoop     DI_ContinueLoop
  #define EDebugInfo_ContinueForeach  DI_ContinueForeach
  #define EDebugInfo_ContinueFor      DI_ContinueFor
  #define EDebugInfo_MAX              DI_MAX
} EDebugInfo;
/* The types of user commands that the debugger engine responds to. */
typedef enum EUserAction : unsigned char {
	UA_None,
	UA_Exit,           /** end the current game session */
	UA_StepInto,       /** step into the current line; if the current line is a function call, steps into that function */
	UA_StepOver,       /** step over the next instruction (i.e. for stepping into different parts of a for loop); not yet implemented */
	UA_StepOverStack,  /** step over the next line of code, skipping all instructions on the current line */
	UA_StepOut,        /** step out of the current function */
	UA_RunToCursor,    /** continue execution until the code reaches the specified line/instruction; not yet implemented */
	UA_Go,             /** continue execution and return control to the debugger engine */
	UA_MAX,
  #define UA_None                    UA_None
  #define UA_Exit                    UA_Exit
  #define UA_StepInto                UA_StepInto
  #define UA_StepOver                UA_StepOver
  #define UA_StepOverStack           UA_StepOverStack
  #define UA_StepOut                 UA_StepOut
  #define UA_RunToCursor             UA_RunToCursor
  #define UA_Go                      UA_Go
  #define UA_MAX                     UA_MAX
  #define EUserAction_None           UA_None
  #define EUserAction_Exit           UA_Exit
  #define EUserAction_StepInto       UA_StepInto
  #define EUserAction_StepOver       UA_StepOver
  #define EUserAction_StepOverStack  UA_StepOverStack
  #define EUserAction_StepOut        UA_StepOut
  #define EUserAction_RunToCursor    UA_RunToCursor
  #define EUserAction_Go             UA_Go
  #define EUserAction_MAX            UA_MAX
} EUserAction;
#define EDebugInfo   EDebugInfo
#define EUserAction  EUserAction

/* ---------------------------------------------------------- FIOManager ! ---------------------------------------------------------- */

typedef enum EIOSystemTag     : unsigned char {
	IOSYSTEM_GenericAsync,
	IOSYSTEM_LastEpicEntry,
  #define IOSYSTEM_GenericAsync       IOSYSTEM_GenericAsync
  #define IOSYSTEM_LastEpicEntry      IOSYSTEM_LastEpicEntry
  #define EIOSystemTag_GenericAsync   IOSYSTEM_GenericAsync
  #define EIOSystemTag_LastEpicEntry  IOSYSTEM_LastEpicEntry
} EIOSystemTag;
/* Enum for async IO priorities. */
typedef enum EAsyncIOPriority : unsigned char {
	AIOP_MIN	= 0,
	AIOP_Low,
	AIOP_BelowNormal,
	AIOP_Normal,
	AIOP_High,
	AIOP_MAX
  #define AIOP_MIN                      AIOP_MIN
  #define AIOP_Low                      AIOP_Low
  #define AIOP_BelowNormal              AIOP_BelowNormal
  #define AIOP_Normal                   AIOP_Normal
  #define AIOP_High                     AIOP_High
  #define AIOP_MAX                      AIOP_MAX
  #define EAsyncIOPriority_MIN          AIOP_MIN
  #define EAsyncIOPriority_Low          AIOP_Low
  #define EAsyncIOPriority_BelowNormal  AIOP_BelowNormal
  #define EAsyncIOPriority_Normal       AIOP_Normal
  #define EAsyncIOPriority_High         AIOP_High
  #define EAsyncIOPriority_MAX          AIOP_MAX
} EAsyncIOPriority;
#define EIOSystemTag      EIOSystemTag
#define EAsyncIOPriority  EAsyncIOPriority

/* ---------------------------------------------------------- USparkInterface ! ---------------------------------------------------------- */

typedef enum HttpMimeType : unsigned char {
  HMT_Default,                    // 0
  HMT_TEXT_PLAIN,                 // 1
  HMT_JSON,                       // 2
  HMT_PROTOBUF,                   // 3
  HMT_CUSTOM,                     // 4
  HMT_MAX                         // 5
  #define HMT_Default              HMT_Default
  #define HMT_TEXT_PLAIN           HMT_TEXT_PLAIN
  #define HMT_JSON                 HMT_JSON
  #define HMT_PROTOBUF             HMT_PROTOBUF
  #define HMT_CUSTOM               HMT_CUSTOM
  #define HMT_MAX                  HMT_MAX
  #define HttpMimeType_Default     HMT_Default
  #define HttpMimeType_TEXT_PLAIN  HMT_TEXT_PLAIN
  #define HttpMimeType_JSON        HMT_JSON
  #define HttpMimeType_PROTOBUF    HMT_PROTOBUF
  #define HttpMimeType_CUSTOM      HMT_CUSTOM
  #define HttpMimeType_MAX         HMT_MAX
} HttpMimeType;
typedef enum HttpMethod   : unsigned char {
  HM_POST,                        // 0
  HM_GET,                         // 1
  HM_PUT,                         // 2
  HM_MAX                          // 3
  #define HM_POST          HM_POST
  #define HM_GET           HM_GET
  #define HM_PUT           HM_PUT
  #define HM_MAX           HM_MAX
  #define HttpMethod_POST  HM_POST
  #define HttpMethod_GET   HM_GET
  #define HttpMethod_PUT   HM_PUT
  #define HttpMethod_MAX   HM_MAX
} HttpMethod;
#define HttpMimeType  HttpMimeType
#define HttpMethod    HttpMethod

/* ---------------------------------------------------------- UWillowGameEngine ! ---------------------------------------------------------- */

typedef enum ELevelChangeState : unsigned char {
  LCS_None,                       // 0
  LCS_SyncingCommit,              // 1
  LCS_SyncingUnPause,             // 2
  LCS_MAX                         // 3
  #define LCS_None                          LCS_None
  #define LCS_SyncingCommit                 LCS_SyncingCommit
  #define LCS_SyncingUnPause                LCS_SyncingUnPause
  #define LCS_MAX                           LCS_MAX
  #define ELevelChangeState_None            LCS_None
  #define ELevelChangeState_SyncingCommit   LCS_SyncingCommit
  #define ELevelChangeState_SyncingUnPause  LCS_SyncingUnPause
  #define ELevelChangeState_MAX             LCS_MAX
} ELevelChangeState;
#define ELevelChangeState  ELevelChangeState

/* ---------------------------------------------------------- UAIComponent ! ---------------------------------------------------------- */

typedef enum AINodeType   : unsigned char {
  NodeType_Blank,                 // 0
  NodeType_Action,                // 1
  NodeType_Random,                // 2
  NodeType_Priority,              // 3
  NodeType_Sequential,            // 4
  NodeType_MAX                    // 5
  #define NodeType_Blank         NodeType_Blank
  #define NodeType_Action        NodeType_Action
  #define NodeType_Random        NodeType_Random
  #define NodeType_Priority      NodeType_Priority
  #define NodeType_Sequential    NodeType_Sequential
  #define NodeType_MAX           NodeType_MAX
  #define AINodeType_Blank       NodeType_Blank
  #define AINodeType_Action      NodeType_Action
  #define AINodeType_Random      NodeType_Random
  #define AINodeType_Priority    NodeType_Priority
  #define AINodeType_Sequential  NodeType_Sequential
  #define AINodeType_MAX         NodeType_MAX
} AINodeType;
typedef enum AIFailReason : unsigned char {
  AIFail_None,                    // 0
  AIFail_Timer,                   // 1
  AIFail_Failed,                  // 2
  AIFail_Action,                  // 3
  AIFail_Resource,                // 4
  AIFail_Conditional,             // 5
  AIFail_MAX                      // 6
  #define AIFail_None               AIFail_None
  #define AIFail_Timer              AIFail_Timer
  #define AIFail_Failed             AIFail_Failed
  #define AIFail_Action             AIFail_Action
  #define AIFail_Resource           AIFail_Resource
  #define AIFail_Conditional        AIFail_Conditional
  #define AIFail_MAX                AIFail_MAX
  #define AIFailReason_None         AIFail_None
  #define AIFailReason_Timer        AIFail_Timer
  #define AIFailReason_Failed       AIFail_Failed
  #define AIFailReason_Action       AIFail_Action
  #define AIFailReason_Resource     AIFail_Resource
  #define AIFailReason_Conditional  AIFail_Conditional
  #define AIFailReason_MAX          AIFail_MAX
} AIFailReason;
#define AINodeType    AINodeType
#define AIFailReason  AIFailReason

/*-----------------------------------------------------------------------------
	Level updating. Moved out here from UnLevel.h so that AActor.h can use it (needed for gcc)
-----------------------------------------------------------------------------*/

/* ! */

typedef enum ELevelTick : unsigned char {
	LEVELTICK_TimeOnly      = 0,  /** Update the level time only. */
	LEVELTICK_ViewportsOnly = 1,  /** Update time and viewports. */
	LEVELTICK_All           = 2,  /** Update all. */
  #define LEVELTICK_TimeOnly        LEVELTICK_TimeOnly
  #define LEVELTICK_ViewportsOnly   LEVELTICK_ViewportsOnly
  #define LEVELTICK_All             LEVELTICK_All
  #define ELevelTick_TimeOnly       LEVELTICK_TimeOnly
  #define ELevelTick_ViewportsOnly  LEVELTICK_ViewportsOnly
  #define ELevelTick_All            LEVELTICK_All
} ELevelTick;
#define ELevelTick  ELevelTick

/* ---------------------------------------------------------- UITargetable ! ---------------------------------------------------------- */

typedef enum EAutoAimProfile : unsigned char {
  AAP_Heavy,                      // 0
  AAP_Medium,                     // 1
  AAP_Light,                      // 2
  AAP_None,                       // 3
  AAP_MAX                         // 4
  #define AAP_Heavy               AAP_Heavy
  #define AAP_Medium              AAP_Medium
  #define AAP_Light               AAP_Light
  #define AAP_None                AAP_None
  #define AAP_MAX                 AAP_MAX
  #define EAutoAimProfile_Heavy   AAP_Heavy
  #define EAutoAimProfile_Medium  AAP_Medium
  #define EAutoAimProfile_Light   AAP_Light
  #define EAutoAimProfile_None    AAP_None
  #define EAutoAimProfile_MAX     AAP_MAX
} EAutoAimProfile;
typedef enum EInfoBarType    : unsigned char {
  EIBT_Shield,                    // 0
  EIBT_Health,                    // 1
  EIBT_Vehicle,                   // 2
  EIBT_Minibar,                   // 3
  EIBT_MAX                        // 4
  #define EIBT_Shield           EIBT_Shield
  #define EIBT_Health           EIBT_Health
  #define EIBT_Vehicle          EIBT_Vehicle
  #define EIBT_Minibar          EIBT_Minibar
  #define EIBT_MAX              EIBT_MAX
  #define EInfoBarType_Shield   EIBT_Shield
  #define EInfoBarType_Health   EIBT_Health
  #define EInfoBarType_Vehicle  EIBT_Vehicle
  #define EInfoBarType_Minibar  EIBT_Minibar
  #define EInfoBarType_MAX      EIBT_MAX
} EInfoBarType;
typedef enum EChangeStatus   : unsigned char {
  CHANGE_Toggle,                  // 0
  CHANGE_Enable,                  // 1
  CHANGE_Disable,                 // 2
  CHANGE_MAX                      // 3
  #define CHANGE_Toggle          CHANGE_Toggle
  #define CHANGE_Enable          CHANGE_Enable
  #define CHANGE_Disable         CHANGE_Disable
  #define CHANGE_MAX             CHANGE_MAX
  #define EChangeStatus_Toggle   CHANGE_Toggle
  #define EChangeStatus_Enable   CHANGE_Enable
  #define EChangeStatus_Disable  CHANGE_Disable
  #define EChangeStatus_MAX      CHANGE_MAX
} EChangeStatus;
#define EAutoAimProfile  EAutoAimProfile
#define EInfoBarType     EInfoBarType
#define EChangeStatus    EChangeStatus

/* ---------------------------------------------------------- UDamagePipeline ! ---------------------------------------------------------- */

typedef enum EReflectionType       : unsigned char {
  REFLT_None,                     // 0
  REFLT_Instigator,               // 1
  REFLT_Self,                     // 2
  REFLT_MAX                       // 3
  #define REFLT_None                  REFLT_None
  #define REFLT_Instigator            REFLT_Instigator
  #define REFLT_Self                  REFLT_Self
  #define REFLT_MAX                   REFLT_MAX
  #define EReflectionType_None        REFLT_None
  #define EReflectionType_Instigator  REFLT_Instigator
  #define EReflectionType_Self        REFLT_Self
  #define EReflectionType_MAX         REFLT_MAX
} EReflectionType;
typedef enum EDamageSkillEventType : unsigned char {
  DSET_DamageTaken,               // 0
  DSET_DamageDealt,               // 1
  DSET_MAX                        // 2
  #define DSET_DamageTaken                   DSET_DamageTaken
  #define DSET_DamageDealt                   DSET_DamageDealt
  #define DSET_MAX                           DSET_MAX
  #define EDamageSkillEventType_DamageTaken  DSET_DamageTaken
  #define EDamageSkillEventType_DamageDealt  DSET_DamageDealt
  #define EDamageSkillEventType_MAX          DSET_MAX
} EDamageSkillEventType;
#define EReflectionType        EReflectionType
#define EDamageSkillEventType  EDamageSkillEventType

/** !
 * The priority a hit proxy has when choosing between several hit proxies near the point the user clicked.
 * HPP_World - this is the default priority
 * HPP_Wireframe - the priority of items that are drawn in wireframe, such as volumes
 * HPP_UI - the priority of the UI components such as the translation widget
 */
typedef enum EHitProxyPriority : unsigned char {
	HPP_World     = 0,
	HPP_Wireframe = 1,
	HPP_UI        = 2
  #define HPP_World                    HPP_World
  #define HPP_Wireframe                HPP_Wireframe
  #define HPP_UI                       HPP_UI
  #define EHitProxyPriority_World      HPP_World
  #define EHitProxyPriority_Wireframe  HPP_Wireframe
  #define EHitProxyPriority_UI         HPP_UI
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
  #define MC_None                           MC_None
  #define MC_NoChange                       MC_NoChange
  #define MC_Arrow                          MC_Arrow
  #define MC_Cross                          MC_Cross
  #define MC_SizeAll                        MC_SizeAll
  #define MC_SizeUpRightDownLeft            MC_SizeUpRightDownLeft
  #define MC_SizeUpLeftDownRight            MC_SizeUpLeftDownRight
  #define MC_SizeLeftRight                  MC_SizeLeftRight
  #define MC_SizeUpDown                     MC_SizeUpDown
  #define MC_Hand                           MC_Hand
  #define MC_GrabHand                       MC_GrabHand
  #define EMouseCursor_None                 MC_None
  #define EMouseCursor_NoChange             MC_NoChange
  #define EMouseCursor_Arrow                MC_Arrow
  #define EMouseCursor_Cross                MC_Cross
  #define EMouseCursor_SizeAll              MC_SizeAll
  #define EMouseCursor_SizeUpRightDownLeft  MC_SizeUpRightDownLeft
  #define EMouseCursor_SizeUpLeftDownRight  MC_SizeUpLeftDownRight
  #define EMouseCursor_SizeLeftRight        MC_SizeLeftRight
  #define EMouseCursor_SizeUpDown           MC_SizeUpDown
  #define EMouseCursor_Hand                 MC_Hand
  #define EMouseCursor_GrabHand             MC_GrabHand
} EMouseCursor;
#define EHitProxyPriority  EHitProxyPriority
#define EMouseCursor       EMouseCursor

/* ---------------------------------------------------------- AWillowPlayerPawn ! ---------------------------------------------------------- */

typedef enum ERegionList           : unsigned char {
  ERL_Firestone,                  // 0
  ERL_NewHaven,                   // 1
  ERL_MAX                         // 2
  #define ERL_Firestone          ERL_Firestone
  #define ERL_NewHaven           ERL_NewHaven
  #define ERL_MAX                ERL_MAX
  #define ERegionList_Firestone  ERL_Firestone
  #define ERegionList_NewHaven   ERL_NewHaven
  #define ERegionList_MAX        ERL_MAX
} ERegionList;
typedef enum EInjuredPreDeathState : unsigned char {
  INJUREDPREDEATH_None,           // 0
  INJUREDPREDEATH_Start,          // 1
  INJUREDPREDEATH_Stop,           // 2
  INJUREDPREDEATH_MAX             // 3
  #define INJUREDPREDEATH_None         INJUREDPREDEATH_None
  #define INJUREDPREDEATH_Start        INJUREDPREDEATH_Start
  #define INJUREDPREDEATH_Stop         INJUREDPREDEATH_Stop
  #define INJUREDPREDEATH_MAX          INJUREDPREDEATH_MAX
  #define EInjuredPreDeathState_None   INJUREDPREDEATH_None
  #define EInjuredPreDeathState_Start  INJUREDPREDEATH_Start
  #define EInjuredPreDeathState_Stop   INJUREDPREDEATH_Stop
  #define EInjuredPreDeathState_MAX    INJUREDPREDEATH_MAX
} EInjuredPreDeathState;
#define ERegionList            ERegionList
#define EInjuredPreDeathState  EInjuredPreDeathState

/* ---------------------------------------------------------- UIInstanceData ! ---------------------------------------------------------- */

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
  #define IDT_Bool                          IDT_Bool
  #define IDT_Int                           IDT_Int
  #define IDT_Float                         IDT_Float
  #define IDT_Vector                        IDT_Vector
  #define IDT_Object                        IDT_Object
  #define IDT_ActorComponent                IDT_ActorComponent
  #define IDT_Actor                         IDT_Actor
  #define IDT_ActorTemplate                 IDT_ActorTemplate
  #define IDT_String                        IDT_String
  #define IDT_Switch                        IDT_Switch
  #define IDT_PickupTemplate                IDT_PickupTemplate
  #define IDT_CustomHead                    IDT_CustomHead
  #define IDT_CustomSkin                    IDT_CustomSkin
  #define IDT_MAX                           IDT_MAX
  #define EInstanceDataType_Bool            IDT_Bool
  #define EInstanceDataType_Int             IDT_Int
  #define EInstanceDataType_Float           IDT_Float
  #define EInstanceDataType_Vector          IDT_Vector
  #define EInstanceDataType_Object          IDT_Object
  #define EInstanceDataType_ActorComponent  IDT_ActorComponent
  #define EInstanceDataType_Actor           IDT_Actor
  #define EInstanceDataType_ActorTemplate   IDT_ActorTemplate
  #define EInstanceDataType_String          IDT_String
  #define EInstanceDataType_Switch          IDT_Switch
  #define EInstanceDataType_PickupTemplate  IDT_PickupTemplate
  #define EInstanceDataType_CustomHead      IDT_CustomHead
  #define EInstanceDataType_CustomSkin      IDT_CustomSkin
  #define EInstanceDataType_MAX             IDT_MAX
} EInstanceDataType;
typedef enum EReplicationType  : unsigned char {
  IDR_Server,                     // 0
  IDR_Client,                     // 1
  IDR_Local,                      // 2
  IDR_MAX                         // 3
  #define IDR_Server               IDR_Server
  #define IDR_Client               IDR_Client
  #define IDR_Local                IDR_Local
  #define IDR_MAX                  IDR_MAX
  #define EReplicationType_Server  IDR_Server
  #define EReplicationType_Client  IDR_Client
  #define EReplicationType_Local   IDR_Local
  #define EReplicationType_MAX     IDR_MAX
} EReplicationType;
#define EInstanceDataType  EInstanceDataType
#define EReplicationType   EReplicationType

/* ---------------------------------------------------------- UInventoryListPanelGFxObject ! ---------------------------------------------------------- */

typedef enum EInventoryListType : unsigned char {
  ELT_Weapon,                     // 0
  ELT_Shield,                     // 1
  ELT_GrenadeMod,                 // 2
  ELT_ClassMod,                   // 3
  ELT_Artifact,                   // 4
  ELT_None,                       // 5
  ELT_MAX                         // 6
  #define ELT_Weapon                     ELT_Weapon
  #define ELT_Shield                     ELT_Shield
  #define ELT_GrenadeMod                 ELT_GrenadeMod
  #define ELT_ClassMod                   ELT_ClassMod
  #define ELT_Artifact                   ELT_Artifact
  #define ELT_None                       ELT_None
  #define ELT_MAX                        ELT_MAX
  #define EInventoryListType_Weapon      ELT_Weapon
  #define EInventoryListType_Shield      ELT_Shield
  #define EInventoryListType_GrenadeMod  ELT_GrenadeMod
  #define EInventoryListType_ClassMod    ELT_ClassMod
  #define EInventoryListType_Artifact    ELT_Artifact
  #define EInventoryListType_None        ELT_None
  #define EInventoryListType_MAX         ELT_MAX
} EInventoryListType;
#define EInventoryListType  EInventoryListType

/* ---------------------------------------------------------- UInventoryDataProviderGFxObject ! ---------------------------------------------------------- */

typedef enum EInventorySortType      : unsigned char {
  IST_EquippedThenMajorTypeThenRarityThenSubtype,// 0
  IST_MajorTypeThenSubtypeThenRarity,// 1
  IST_MajorTypeThenRarityThenSubtype,// 2
  IST_Manufacturer,               // 3
  IST_ClassRequirementThenRarity, // 4
  IST_Value,                      // 5
  IST_MAX                         // 6
  #define IST_EquippedThenMajorTypeThenRarityThenSubtype                 IST_EquippedThenMajorTypeThenRarityThenSubtype
  #define IST_MajorTypeThenSubtypeThenRarity                             IST_MajorTypeThenSubtypeThenRarity
  #define IST_MajorTypeThenRarityThenSubtype                             IST_MajorTypeThenRarityThenSubtype
  #define IST_Manufacturer                                               IST_Manufacturer
  #define IST_ClassRequirementThenRarity                                 IST_ClassRequirementThenRarity
  #define IST_Value                                                      IST_Value
  #define IST_MAX                                                        IST_MAX
  #define EInventorySortType_EquippedThenMajorTypeThenRarityThenSubtype  IST_EquippedThenMajorTypeThenRarityThenSubtype
  #define EInventorySortType_MajorTypeThenSubtypeThenRarity              IST_MajorTypeThenSubtypeThenRarity
  #define EInventorySortType_MajorTypeThenRarityThenSubtype              IST_MajorTypeThenRarityThenSubtype
  #define EInventorySortType_Manufacturer                                IST_Manufacturer
  #define EInventorySortType_ClassRequirementThenRarity                  IST_ClassRequirementThenRarity
  #define EInventorySortType_Value                                       IST_Value
  #define EInventorySortType_MAX                                         IST_MAX
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
  #define IFT_NoFilter                               IFT_NoFilter
  #define IFT_FilterUncomparable                     IFT_FilterUncomparable
  #define IFT_FilterWeapons                          IFT_FilterWeapons
  #define IFT_FilterNonWeapons                       IFT_FilterNonWeapons
  #define IFT_FilterNonShields                       IFT_FilterNonShields
  #define IFT_FilterNonGrenadeMods                   IFT_FilterNonGrenadeMods
  #define IFT_FilterNonClassMods                     IFT_FilterNonClassMods
  #define IFT_FilterNonUpgrades                      IFT_FilterNonUpgrades
  #define IFT_FilterNonHealth                        IFT_FilterNonHealth
  #define IFT_FilterNonGenerics                      IFT_FilterNonGenerics
  #define IFT_MAX                                    IFT_MAX
  #define EInventoryFilterType_NoFilter              IFT_NoFilter
  #define EInventoryFilterType_FilterUncomparable    IFT_FilterUncomparable
  #define EInventoryFilterType_FilterWeapons         IFT_FilterWeapons
  #define EInventoryFilterType_FilterNonWeapons      IFT_FilterNonWeapons
  #define EInventoryFilterType_FilterNonShields      IFT_FilterNonShields
  #define EInventoryFilterType_FilterNonGrenadeMods  IFT_FilterNonGrenadeMods
  #define EInventoryFilterType_FilterNonClassMods    IFT_FilterNonClassMods
  #define EInventoryFilterType_FilterNonUpgrades     IFT_FilterNonUpgrades
  #define EInventoryFilterType_FilterNonHealth       IFT_FilterNonHealth
  #define EInventoryFilterType_FilterNonGenerics     IFT_FilterNonGenerics
  #define EInventoryFilterType_MAX                   IFT_MAX
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
  #define CAType_None                               CAType_None
  #define CAType_InventoryType                      CAType_InventoryType
  #define CAType_Manufacturers                      CAType_Manufacturers
  #define CAType_WeaponType                         CAType_WeaponType
  #define CAType_ClassRequirement                   CAType_ClassRequirement
  #define CAType_PersonalOrShop                     CAType_PersonalOrShop
  #define CAType_Equipped                           CAType_Equipped
  #define CAType_MAX                                CAType_MAX
  #define ECategoryAssignmentType_None              CAType_None
  #define ECategoryAssignmentType_InventoryType     CAType_InventoryType
  #define ECategoryAssignmentType_Manufacturers     CAType_Manufacturers
  #define ECategoryAssignmentType_WeaponType        CAType_WeaponType
  #define ECategoryAssignmentType_ClassRequirement  CAType_ClassRequirement
  #define ECategoryAssignmentType_PersonalOrShop    CAType_PersonalOrShop
  #define ECategoryAssignmentType_Equipped          CAType_Equipped
  #define ECategoryAssignmentType_MAX               CAType_MAX
} ECategoryAssignmentType;
#define EInventorySortType       EInventorySortType
#define EInventoryFilterType     EInventoryFilterType
#define ECategoryAssignmentType  ECategoryAssignmentType

/* ---------------------------------------------------------- AWillowPlayerController ! ---------------------------------------------------------- */

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
  #define ISA_Targeting                                  ISA_Targeting
  #define ISA_Targeted                                   ISA_Targeted
  #define ISA_KilledEnemy                                ISA_KilledEnemy
  #define ISA_AppliedStatusEffect                        ISA_AppliedStatusEffect
  #define ISA_CriticalHit                                ISA_CriticalHit
  #define ISA_TookPhysicalDamage                         ISA_TookPhysicalDamage
  #define ISA_GaveDamage                                 ISA_GaveDamage
  #define ISA_TookStatusEffectDamage                     ISA_TookStatusEffectDamage
  #define ISA_ScoredHit                                  ISA_ScoredHit
  #define ISA_DealtExplosiveDamage                       ISA_DealtExplosiveDamage
  #define ISA_FriendWentDown                             ISA_FriendWentDown
  #define ISA_DealtStatusEffectDamage                    ISA_DealtStatusEffectDamage
  #define ISA_TookShieldDamage                           ISA_TookShieldDamage
  #define ISA_MAX                                        ISA_MAX
  #define EInstinctSkillActions_Targeting                ISA_Targeting
  #define EInstinctSkillActions_Targeted                 ISA_Targeted
  #define EInstinctSkillActions_KilledEnemy              ISA_KilledEnemy
  #define EInstinctSkillActions_AppliedStatusEffect      ISA_AppliedStatusEffect
  #define EInstinctSkillActions_CriticalHit              ISA_CriticalHit
  #define EInstinctSkillActions_TookPhysicalDamage       ISA_TookPhysicalDamage
  #define EInstinctSkillActions_GaveDamage               ISA_GaveDamage
  #define EInstinctSkillActions_TookStatusEffectDamage   ISA_TookStatusEffectDamage
  #define EInstinctSkillActions_ScoredHit                ISA_ScoredHit
  #define EInstinctSkillActions_DealtExplosiveDamage     ISA_DealtExplosiveDamage
  #define EInstinctSkillActions_FriendWentDown           ISA_FriendWentDown
  #define EInstinctSkillActions_DealtStatusEffectDamage  ISA_DealtStatusEffectDamage
  #define EInstinctSkillActions_TookShieldDamage         ISA_TookShieldDamage
  #define EInstinctSkillActions_MAX                      ISA_MAX
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
  #define EMFT_NewMissionAccepted                   EMFT_NewMissionAccepted
  #define EMFT_NewMissionActive                     EMFT_NewMissionActive
  #define EMFT_NewPlotMissionActive                 EMFT_NewPlotMissionActive
  #define EMFT_ObjectiveIncremented                 EMFT_ObjectiveIncremented
  #define EMFT_ObjectiveComplete                    EMFT_ObjectiveComplete
  #define EMFT_ObjectiveCleared                     EMFT_ObjectiveCleared
  #define EMFT_MissionReadyToTurnIn                 EMFT_MissionReadyToTurnIn
  #define EMFT_MissionCompleted                     EMFT_MissionCompleted
  #define EMFT_PingNonTrackedOnly                   EMFT_PingNonTrackedOnly
  #define EMFT_MAX                                  EMFT_MAX
  #define EMissionFanfareType_NewMissionAccepted    EMFT_NewMissionAccepted
  #define EMissionFanfareType_NewMissionActive      EMFT_NewMissionActive
  #define EMissionFanfareType_NewPlotMissionActive  EMFT_NewPlotMissionActive
  #define EMissionFanfareType_ObjectiveIncremented  EMFT_ObjectiveIncremented
  #define EMissionFanfareType_ObjectiveComplete     EMFT_ObjectiveComplete
  #define EMissionFanfareType_ObjectiveCleared      EMFT_ObjectiveCleared
  #define EMissionFanfareType_MissionReadyToTurnIn  EMFT_MissionReadyToTurnIn
  #define EMissionFanfareType_MissionCompleted      EMFT_MissionCompleted
  #define EMissionFanfareType_PingNonTrackedOnly    EMFT_PingNonTrackedOnly
  #define EMissionFanfareType_MAX                   EMFT_MAX
} EMissionFanfareType;
typedef enum EPresenceModeContext     : unsigned char {
  EPMC_Any,                       // 0
  EPMC_OnFoot,                    // 1
  EPMC_Driving,                   // 2
  EPMC_Dueling,                   // 3
  EPMC_OpenSlots,                 // 4
  EPMC_MAX                        // 5
  #define EPMC_Any                        EPMC_Any
  #define EPMC_OnFoot                     EPMC_OnFoot
  #define EPMC_Driving                    EPMC_Driving
  #define EPMC_Dueling                    EPMC_Dueling
  #define EPMC_OpenSlots                  EPMC_OpenSlots
  #define EPMC_MAX                        EPMC_MAX
  #define EPresenceModeContext_Any        EPMC_Any
  #define EPresenceModeContext_OnFoot     EPMC_OnFoot
  #define EPresenceModeContext_Driving    EPMC_Driving
  #define EPresenceModeContext_Dueling    EPMC_Dueling
  #define EPresenceModeContext_OpenSlots  EPMC_OpenSlots
  #define EPresenceModeContext_MAX        EPMC_MAX
} EPresenceModeContext;
typedef enum EQuickSelectSlotStatus   : unsigned char {
  QSSS_Available,                 // 0
  QSSS_Locked,                    // 1
  QSSS_Selected,                  // 2
  QSSS_MAX                        // 3
  #define QSSS_Available                    QSSS_Available
  #define QSSS_Locked                       QSSS_Locked
  #define QSSS_Selected                     QSSS_Selected
  #define QSSS_MAX                          QSSS_MAX
  #define EQuickSelectSlotStatus_Available  QSSS_Available
  #define EQuickSelectSlotStatus_Locked     QSSS_Locked
  #define EQuickSelectSlotStatus_Selected   QSSS_Selected
  #define EQuickSelectSlotStatus_MAX        QSSS_MAX
} EQuickSelectSlotStatus;
typedef enum EBackButtonScreen        : unsigned char {
  CS_None,                        // 0
  CS_MissionLog,                  // 1
  CS_Map,                         // 2
  CS_Inventory,                   // 3
  CS_Skills,                      // 4
  CS_Challenges,                  // 5
  CS_MAX                          // 6
  #define CS_None                       CS_None
  #define CS_MissionLog                 CS_MissionLog
  #define CS_Map                        CS_Map
  #define CS_Inventory                  CS_Inventory
  #define CS_Skills                     CS_Skills
  #define CS_Challenges                 CS_Challenges
  #define CS_MAX                        CS_MAX
  #define EBackButtonScreen_None        CS_None
  #define EBackButtonScreen_MissionLog  CS_MissionLog
  #define EBackButtonScreen_Map         CS_Map
  #define EBackButtonScreen_Inventory   CS_Inventory
  #define EBackButtonScreen_Skills      CS_Skills
  #define EBackButtonScreen_Challenges  CS_Challenges
  #define EBackButtonScreen_MAX         CS_MAX
} EBackButtonScreen;
typedef enum EMissionSortType         : unsigned char {
  MSORT_Region,                   // 0
  MSORT_Status,                   // 1
  MSORT_Difficulty,               // 2
  MSORT_Chronological,            // 3
  MSORT_Expansion,                // 4
  MSORT_MAX                       // 5
  #define MSORT_Region                    MSORT_Region
  #define MSORT_Status                    MSORT_Status
  #define MSORT_Difficulty                MSORT_Difficulty
  #define MSORT_Chronological             MSORT_Chronological
  #define MSORT_Expansion                 MSORT_Expansion
  #define MSORT_MAX                       MSORT_MAX
  #define EMissionSortType_Region         MSORT_Region
  #define EMissionSortType_Status         MSORT_Status
  #define EMissionSortType_Difficulty     MSORT_Difficulty
  #define EMissionSortType_Chronological  MSORT_Chronological
  #define EMissionSortType_Expansion      MSORT_Expansion
  #define EMissionSortType_MAX            MSORT_MAX
} EMissionSortType;
typedef enum EColiseumGameOver        : unsigned char {
  ECGM_TryAgain,                  // 0
  ECGM_Lobby,                     // 1
  ECGM_MAX                        // 2
  #define ECGM_TryAgain               ECGM_TryAgain
  #define ECGM_Lobby                  ECGM_Lobby
  #define ECGM_MAX                    ECGM_MAX
  #define EColiseumGameOver_TryAgain  ECGM_TryAgain
  #define EColiseumGameOver_Lobby     ECGM_Lobby
  #define EColiseumGameOver_MAX       ECGM_MAX
} EColiseumGameOver;
typedef enum EColiseumStatType        : unsigned char {
  ECSTAT_Kills,                   // 0
  ECSTAT_MAX                      // 1
  #define ECSTAT_Kills             ECSTAT_Kills
  #define ECSTAT_MAX               ECSTAT_MAX
  #define EColiseumStatType_Kills  ECSTAT_Kills
  #define EColiseumStatType_MAX    ECSTAT_MAX
} EColiseumStatType;
typedef enum EConnectionAttemptStatus : unsigned char {
  COAS_ServerFull,                // 0
  COAS_ServerUnavailable,         // 1
  COAS_DLCMismatch,               // 2
  COAS_ClientOutdated,            // 3
  COAS_ServerOutdated,            // 4
  COAS_MAX                        // 5
  #define COAS_ServerFull                             COAS_ServerFull
  #define COAS_ServerUnavailable                      COAS_ServerUnavailable
  #define COAS_DLCMismatch                            COAS_DLCMismatch
  #define COAS_ClientOutdated                         COAS_ClientOutdated
  #define COAS_ServerOutdated                         COAS_ServerOutdated
  #define COAS_MAX                                    COAS_MAX
  #define EConnectionAttemptStatus_ServerFull         COAS_ServerFull
  #define EConnectionAttemptStatus_ServerUnavailable  COAS_ServerUnavailable
  #define EConnectionAttemptStatus_DLCMismatch        COAS_DLCMismatch
  #define EConnectionAttemptStatus_ClientOutdated     COAS_ClientOutdated
  #define EConnectionAttemptStatus_ServerOutdated     COAS_ServerOutdated
  #define EConnectionAttemptStatus_MAX                COAS_MAX
} EConnectionAttemptStatus;
typedef enum ELoadGameResult          : unsigned char {
  LGR_Failure,                    // 0
  LGR_Success,                    // 1
  LGR_Pending,                    // 2
  LGR_CorruptedFailure,           // 3
  LGR_UnloadedDLCFailure,         // 4
  LGR_DuplicateFailure,           // 5
  LGR_MAX                         // 6
  #define LGR_Failure                         LGR_Failure
  #define LGR_Success                         LGR_Success
  #define LGR_Pending                         LGR_Pending
  #define LGR_CorruptedFailure                LGR_CorruptedFailure
  #define LGR_UnloadedDLCFailure              LGR_UnloadedDLCFailure
  #define LGR_DuplicateFailure                LGR_DuplicateFailure
  #define LGR_MAX                             LGR_MAX
  #define ELoadGameResult_Failure             LGR_Failure
  #define ELoadGameResult_Success             LGR_Success
  #define ELoadGameResult_Pending             LGR_Pending
  #define ELoadGameResult_CorruptedFailure    LGR_CorruptedFailure
  #define ELoadGameResult_UnloadedDLCFailure  LGR_UnloadedDLCFailure
  #define ELoadGameResult_DuplicateFailure    LGR_DuplicateFailure
  #define ELoadGameResult_MAX                 LGR_MAX
} ELoadGameResult;
typedef enum EWillowNetworkType       : unsigned char {
  WNT_Internet,                   // 0
  WNT_SystemLink,                 // 1
  WNT_Offline,                    // 2
  WNT_MAX                         // 3
  #define WNT_Internet                   WNT_Internet
  #define WNT_SystemLink                 WNT_SystemLink
  #define WNT_Offline                    WNT_Offline
  #define WNT_MAX                        WNT_MAX
  #define EWillowNetworkType_Internet    WNT_Internet
  #define EWillowNetworkType_SystemLink  WNT_SystemLink
  #define EWillowNetworkType_Offline     WNT_Offline
  #define EWillowNetworkType_MAX         WNT_MAX
} EWillowNetworkType;
typedef enum EWillowInviteType        : unsigned char {
  WIT_InviteRequired,             // 0
  WIT_FriendsOnly,                // 1
  WIT_Public,                     // 2
  WIT_MAX                         // 3
  #define WIT_InviteRequired                WIT_InviteRequired
  #define WIT_FriendsOnly                   WIT_FriendsOnly
  #define WIT_Public                        WIT_Public
  #define WIT_MAX                           WIT_MAX
  #define EWillowInviteType_InviteRequired  WIT_InviteRequired
  #define EWillowInviteType_FriendsOnly     WIT_FriendsOnly
  #define EWillowInviteType_Public          WIT_Public
  #define EWillowInviteType_MAX             WIT_MAX
} EWillowInviteType;
typedef enum EOnlineMessageType       : unsigned char {
  OMT_None,                       // 0
  OMT_Network,                    // 1
  OMT_Dlc,                        // 2
  OMT_Mission,                    // 3
  OMT_Travel,                     // 4
  OMT_Misc,                       // 5
  OMT_MAX                         // 6
  #define OMT_None                    OMT_None
  #define OMT_Network                 OMT_Network
  #define OMT_Dlc                     OMT_Dlc
  #define OMT_Mission                 OMT_Mission
  #define OMT_Travel                  OMT_Travel
  #define OMT_Misc                    OMT_Misc
  #define OMT_MAX                     OMT_MAX
  #define EOnlineMessageType_None     OMT_None
  #define EOnlineMessageType_Network  OMT_Network
  #define EOnlineMessageType_Dlc      OMT_Dlc
  #define EOnlineMessageType_Mission  OMT_Mission
  #define EOnlineMessageType_Travel   OMT_Travel
  #define EOnlineMessageType_Misc     OMT_Misc
  #define EOnlineMessageType_MAX      OMT_MAX
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

/* ---------------------------------------------------------- FStreamingManagerBase ! ---------------------------------------------------------- */

typedef enum EDynamicPrimitiveType : unsigned char {
	DPT_Level,
	DPT_Spawned,
	DPT_MAX
  #define DPT_Level                      DPT_Level
  #define DPT_Spawned                    DPT_Spawned
  #define DPT_MAX                        DPT_MAX
  #define EDynamicPrimitiveType_Level    DPT_Level
  #define EDynamicPrimitiveType_Spawned  DPT_Spawned
  #define EDynamicPrimitiveType_MAX      DPT_MAX
} EDynamicPrimitiveType;
#define EDynamicPrimitiveType  EDynamicPrimitiveType

/* ---------------------------------------------------------- UInstanceDataHelper ! ---------------------------------------------------------- */

typedef enum EBodyCompositionApplicationMode : unsigned char {
  EBCAM_Game,                     // 0
  EBCAM_BackMenu,                 // 1
  EBCAM_BackMenuInspection,       // 2
  EBCAM_EditorPreview,            // 3
  EBCAM_Frontend,                 // 4
  EBCAM_Foreground,               // 5
  EBCAM_MAX                       // 6
  #define EBCAM_Game                                          EBCAM_Game
  #define EBCAM_BackMenu                                      EBCAM_BackMenu
  #define EBCAM_BackMenuInspection                            EBCAM_BackMenuInspection
  #define EBCAM_EditorPreview                                 EBCAM_EditorPreview
  #define EBCAM_Frontend                                      EBCAM_Frontend
  #define EBCAM_Foreground                                    EBCAM_Foreground
  #define EBCAM_MAX                                           EBCAM_MAX
  #define EBodyCompositionApplicationMode_Game                EBCAM_Game
  #define EBodyCompositionApplicationMode_BackMenu            EBCAM_BackMenu
  #define EBodyCompositionApplicationMode_BackMenuInspection  EBCAM_BackMenuInspection
  #define EBodyCompositionApplicationMode_EditorPreview       EBCAM_EditorPreview
  #define EBodyCompositionApplicationMode_Frontend            EBCAM_Frontend
  #define EBodyCompositionApplicationMode_Foreground          EBCAM_Foreground
  #define EBodyCompositionApplicationMode_MAX                 EBCAM_MAX
} EBodyCompositionApplicationMode;
#define EBodyCompositionApplicationMode  EBodyCompositionApplicationMode

/* ---------------------------------------------------------- UProjectileDefinition ! ---------------------------------------------------------- */

typedef enum EProjectileType         : unsigned char {
  PROJECTILE_TYPE_Unknown,        // 0
  PROJECTILE_TYPE_Frag_Grenade,   // 1
  PROJECTILE_TYPE_Protean_Grenade,// 2
  PROJECTILE_TYPE_Rocket,         // 3
  PROJECTILE_TYPE_MAX             // 4
  #define PROJECTILE_TYPE_Unknown          PROJECTILE_TYPE_Unknown
  #define PROJECTILE_TYPE_Frag_Grenade     PROJECTILE_TYPE_Frag_Grenade
  #define PROJECTILE_TYPE_Protean_Grenade  PROJECTILE_TYPE_Protean_Grenade
  #define PROJECTILE_TYPE_Rocket           PROJECTILE_TYPE_Rocket
  #define PROJECTILE_TYPE_MAX              PROJECTILE_TYPE_MAX
  #define EProjectileType_Unknown          PROJECTILE_TYPE_Unknown
  #define EProjectileType_Frag_Grenade     PROJECTILE_TYPE_Frag_Grenade
  #define EProjectileType_Protean_Grenade  PROJECTILE_TYPE_Protean_Grenade
  #define EProjectileType_Rocket           PROJECTILE_TYPE_Rocket
  #define EProjectileType_MAX              PROJECTILE_TYPE_MAX
} EProjectileType;
typedef enum EHomingTargetChangeType : unsigned char {
  HTC_AnyTarget,                  // 0
  HTC_NewTarget,                  // 1
  HTC_LostTarget,                 // 2
  HTC_MAX                         // 3
  #define HTC_AnyTarget                       HTC_AnyTarget
  #define HTC_NewTarget                       HTC_NewTarget
  #define HTC_LostTarget                      HTC_LostTarget
  #define HTC_MAX                             HTC_MAX
  #define EHomingTargetChangeType_AnyTarget   HTC_AnyTarget
  #define EHomingTargetChangeType_NewTarget   HTC_NewTarget
  #define EHomingTargetChangeType_LostTarget  HTC_LostTarget
  #define EHomingTargetChangeType_MAX         HTC_MAX
} EHomingTargetChangeType;
typedef enum EProjectileOnHitOutputs : unsigned char {
  ProjectileOnHit_All,            // 0
  ProjectileOnHit_Enemy,          // 1
  ProjectileOnHit_Friendly,       // 2
  ProjectileOnHit_Neutral,        // 3
  ProjectileOnHit_MAX             // 4
  #define ProjectileOnHit_All               ProjectileOnHit_All
  #define ProjectileOnHit_Enemy             ProjectileOnHit_Enemy
  #define ProjectileOnHit_Friendly          ProjectileOnHit_Friendly
  #define ProjectileOnHit_Neutral           ProjectileOnHit_Neutral
  #define ProjectileOnHit_MAX               ProjectileOnHit_MAX
  #define EProjectileOnHitOutputs_All       ProjectileOnHit_All
  #define EProjectileOnHitOutputs_Enemy     ProjectileOnHit_Enemy
  #define EProjectileOnHitOutputs_Friendly  ProjectileOnHit_Friendly
  #define EProjectileOnHitOutputs_Neutral   ProjectileOnHit_Neutral
  #define EProjectileOnHitOutputs_MAX       ProjectileOnHit_MAX
} EProjectileOnHitOutputs;
#define EProjectileType          EProjectileType
#define EHomingTargetChangeType  EHomingTargetChangeType
#define EProjectileOnHitOutputs  EProjectileOnHitOutputs

/* ---------------------------------------------------------- UParticleSystemComponent ! ---------------------------------------------------------- */

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
  #define PSPT_None                         PSPT_None
  #define PSPT_Scalar                       PSPT_Scalar
  #define PSPT_ScalarRand                   PSPT_ScalarRand
  #define PSPT_Vector                       PSPT_Vector
  #define PSPT_VectorRand                   PSPT_VectorRand
  #define PSPT_Color                        PSPT_Color
  #define PSPT_Actor                        PSPT_Actor
  #define PSPT_Material                     PSPT_Material
  #define PSPT_MAX                          PSPT_MAX
  #define EParticleSysParamType_None        PSPT_None
  #define EParticleSysParamType_Scalar      PSPT_Scalar
  #define EParticleSysParamType_ScalarRand  PSPT_ScalarRand
  #define EParticleSysParamType_Vector      PSPT_Vector
  #define EParticleSysParamType_VectorRand  PSPT_VectorRand
  #define EParticleSysParamType_Color       PSPT_Color
  #define EParticleSysParamType_Actor       PSPT_Actor
  #define EParticleSysParamType_Material    PSPT_Material
  #define EParticleSysParamType_MAX         PSPT_MAX
} EParticleSysParamType;
typedef enum ParticleReplayState   : unsigned char {
  PRS_Disabled,                   // 0
  PRS_Capturing,                  // 1
  PRS_Replaying,                  // 2
  PRS_MAX                         // 3
  #define PRS_Disabled                   PRS_Disabled
  #define PRS_Capturing                  PRS_Capturing
  #define PRS_Replaying                  PRS_Replaying
  #define PRS_MAX                        PRS_MAX
  #define ParticleReplayState_Disabled   PRS_Disabled
  #define ParticleReplayState_Capturing  PRS_Capturing
  #define ParticleReplayState_Replaying  PRS_Replaying
  #define ParticleReplayState_MAX        PRS_MAX
} ParticleReplayState;
typedef enum EParticleEventType    : unsigned char {
  EPET_Any,                       // 0
  EPET_Spawn,                     // 1
  EPET_Death,                     // 2
  EPET_Collision,                 // 3
  EPET_Kismet,                    // 4
  EPET_Trace,                     // 5
  EPET_MAX                        // 6
  #define EPET_Any                      EPET_Any
  #define EPET_Spawn                    EPET_Spawn
  #define EPET_Death                    EPET_Death
  #define EPET_Collision                EPET_Collision
  #define EPET_Kismet                   EPET_Kismet
  #define EPET_Trace                    EPET_Trace
  #define EPET_MAX                      EPET_MAX
  #define EParticleEventType_Any        EPET_Any
  #define EParticleEventType_Spawn      EPET_Spawn
  #define EParticleEventType_Death      EPET_Death
  #define EParticleEventType_Collision  EPET_Collision
  #define EParticleEventType_Kismet     EPET_Kismet
  #define EParticleEventType_Trace      EPET_Trace
  #define EParticleEventType_MAX        EPET_MAX
} EParticleEventType;
#define EParticleSysParamType  EParticleSysParamType
#define ParticleReplayState    ParticleReplayState
#define EParticleEventType     EParticleEventType

/* ---------------------------------------------------------- UParticleSystem ! ---------------------------------------------------------- */

typedef enum EParticleSystemUpdateMode            : unsigned char {
  EPSUM_RealTime,                 // 0
  EPSUM_FixedTime,                // 1
  EPSUM_MAX                       // 2
  #define EPSUM_RealTime                       EPSUM_RealTime
  #define EPSUM_FixedTime                      EPSUM_FixedTime
  #define EPSUM_MAX                            EPSUM_MAX
  #define EParticleSystemUpdateMode_RealTime   EPSUM_RealTime
  #define EParticleSystemUpdateMode_FixedTime  EPSUM_FixedTime
  #define EParticleSystemUpdateMode_MAX        EPSUM_MAX
} EParticleSystemUpdateMode;
typedef enum ParticleSystemLODMethod              : unsigned char {
  PARTICLESYSTEMLODMETHOD_Automatic,// 0
  PARTICLESYSTEMLODMETHOD_DirectSet,// 1
  PARTICLESYSTEMLODMETHOD_ActivateAutomatic,// 2
  PARTICLESYSTEMLODMETHOD_MAX     // 3
  #define PARTICLESYSTEMLODMETHOD_Automatic          PARTICLESYSTEMLODMETHOD_Automatic
  #define PARTICLESYSTEMLODMETHOD_DirectSet          PARTICLESYSTEMLODMETHOD_DirectSet
  #define PARTICLESYSTEMLODMETHOD_ActivateAutomatic  PARTICLESYSTEMLODMETHOD_ActivateAutomatic
  #define PARTICLESYSTEMLODMETHOD_MAX                PARTICLESYSTEMLODMETHOD_MAX
  #define ParticleSystemLODMethod_Automatic          PARTICLESYSTEMLODMETHOD_Automatic
  #define ParticleSystemLODMethod_DirectSet          PARTICLESYSTEMLODMETHOD_DirectSet
  #define ParticleSystemLODMethod_ActivateAutomatic  PARTICLESYSTEMLODMETHOD_ActivateAutomatic
  #define ParticleSystemLODMethod_MAX                PARTICLESYSTEMLODMETHOD_MAX
} ParticleSystemLODMethod;
typedef enum EParticleSystemOcclusionBoundsMethod : unsigned char {
  EPSOBM_None,                    // 0
  EPSOBM_ParticleBounds,          // 1
  EPSOBM_CustomBounds,            // 2
  EPSOBM_MAX                      // 3
  #define EPSOBM_None                                          EPSOBM_None
  #define EPSOBM_ParticleBounds                                EPSOBM_ParticleBounds
  #define EPSOBM_CustomBounds                                  EPSOBM_CustomBounds
  #define EPSOBM_MAX                                           EPSOBM_MAX
  #define EParticleSystemOcclusionBoundsMethod_None            EPSOBM_None
  #define EParticleSystemOcclusionBoundsMethod_ParticleBounds  EPSOBM_ParticleBounds
  #define EParticleSystemOcclusionBoundsMethod_CustomBounds    EPSOBM_CustomBounds
  #define EParticleSystemOcclusionBoundsMethod_MAX             EPSOBM_MAX
} EParticleSystemOcclusionBoundsMethod;
#define EParticleSystemUpdateMode             EParticleSystemUpdateMode
#define ParticleSystemLODMethod               ParticleSystemLODMethod
#define EParticleSystemOcclusionBoundsMethod  EParticleSystemOcclusionBoundsMethod

/* ---------------------------------------------------------- UShieldDefinition ! ---------------------------------------------------------- */

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
  #define SHT_Absorption          SHT_Absorption
  #define SHT_Booster             SHT_Booster
  #define SHT_Chimera             SHT_Chimera
  #define SHT_Impact              SHT_Impact
  #define SHT_Juggernaut          SHT_Juggernaut
  #define SHT_Nova                SHT_Nova
  #define SHT_Roid                SHT_Roid
  #define SHT_Spike               SHT_Spike
  #define SHT_Standard            SHT_Standard
  #define SHT_Custom1             SHT_Custom1
  #define SHT_Custom2             SHT_Custom2
  #define SHT_Custom3             SHT_Custom3
  #define SHT_Custom4             SHT_Custom4
  #define SHT_Custom5             SHT_Custom5
  #define SHT_MAX                 SHT_MAX
  #define EShieldType_Absorption  SHT_Absorption
  #define EShieldType_Booster     SHT_Booster
  #define EShieldType_Chimera     SHT_Chimera
  #define EShieldType_Impact      SHT_Impact
  #define EShieldType_Juggernaut  SHT_Juggernaut
  #define EShieldType_Nova        SHT_Nova
  #define EShieldType_Roid        SHT_Roid
  #define EShieldType_Spike       SHT_Spike
  #define EShieldType_Standard    SHT_Standard
  #define EShieldType_Custom1     SHT_Custom1
  #define EShieldType_Custom2     SHT_Custom2
  #define EShieldType_Custom3     SHT_Custom3
  #define EShieldType_Custom4     SHT_Custom4
  #define EShieldType_Custom5     SHT_Custom5
  #define EShieldType_MAX         SHT_MAX
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
  #define SPM_NoPrime                                                SPM_NoPrime
  #define SPM_PrimeOnFull                                            SPM_PrimeOnFull
  #define SPM_PrimeOnEmptyAfterFullRecharge                          SPM_PrimeOnEmptyAfterFullRecharge
  #define SPM_PrimeOnEmpty                                           SPM_PrimeOnEmpty
  #define SPM_AlwaysPrimed                                           SPM_AlwaysPrimed
  #define SPM_PrimedWhenNotEmpty                                     SPM_PrimedWhenNotEmpty
  #define SPM_PrimedWhenNotEmptyAfterFullRecharge                    SPM_PrimedWhenNotEmptyAfterFullRecharge
  #define SPM_MAX                                                    SPM_MAX
  #define EShieldPrimeMechanism_NoPrime                              SPM_NoPrime
  #define EShieldPrimeMechanism_PrimeOnFull                          SPM_PrimeOnFull
  #define EShieldPrimeMechanism_PrimeOnEmptyAfterFullRecharge        SPM_PrimeOnEmptyAfterFullRecharge
  #define EShieldPrimeMechanism_PrimeOnEmpty                         SPM_PrimeOnEmpty
  #define EShieldPrimeMechanism_AlwaysPrimed                         SPM_AlwaysPrimed
  #define EShieldPrimeMechanism_PrimedWhenNotEmpty                   SPM_PrimedWhenNotEmpty
  #define EShieldPrimeMechanism_PrimedWhenNotEmptyAfterFullRecharge  SPM_PrimedWhenNotEmptyAfterFullRecharge
  #define EShieldPrimeMechanism_MAX                                  SPM_MAX
} EShieldPrimeMechanism;
#define EShieldType            EShieldType
#define EShieldPrimeMechanism  EShieldPrimeMechanism

/* ---------------------------------------------------------- UAIDefinition ! ---------------------------------------------------------- */

typedef enum ENPCOnUsedOutputs : unsigned char {
  USEDNPC_HasMissions,            // 0
  USEDNPC_NoMissions,             // 1
  USEDNPC_Generic,                // 2
  USEDNPC_MAX                     // 3
  #define USEDNPC_HasMissions            USEDNPC_HasMissions
  #define USEDNPC_NoMissions             USEDNPC_NoMissions
  #define USEDNPC_Generic                USEDNPC_Generic
  #define USEDNPC_MAX                    USEDNPC_MAX
  #define ENPCOnUsedOutputs_HasMissions  USEDNPC_HasMissions
  #define ENPCOnUsedOutputs_NoMissions   USEDNPC_NoMissions
  #define ENPCOnUsedOutputs_Generic      USEDNPC_Generic
  #define ENPCOnUsedOutputs_MAX          USEDNPC_MAX
} ENPCOnUsedOutputs;
#define ENPCOnUsedOutputs  ENPCOnUsedOutputs

/* ---------------------------------------------------------- AWillowGameInfo ! ---------------------------------------------------------- */

typedef enum EStartGameState : unsigned char {
  SGS_None,                       // 0
  SGS_IntroMovie,                 // 1
  SGS_CharacterSelect,            // 2
  SGS_WaitingForPlayerPawns,      // 3
  SGS_Started,                    // 4
  SGS_MAX                         // 5
  #define SGS_None                               SGS_None
  #define SGS_IntroMovie                         SGS_IntroMovie
  #define SGS_CharacterSelect                    SGS_CharacterSelect
  #define SGS_WaitingForPlayerPawns              SGS_WaitingForPlayerPawns
  #define SGS_Started                            SGS_Started
  #define SGS_MAX                                SGS_MAX
  #define EStartGameState_None                   SGS_None
  #define EStartGameState_IntroMovie             SGS_IntroMovie
  #define EStartGameState_CharacterSelect        SGS_CharacterSelect
  #define EStartGameState_WaitingForPlayerPawns  SGS_WaitingForPlayerPawns
  #define EStartGameState_Started                SGS_Started
  #define EStartGameState_MAX                    SGS_MAX
} EStartGameState;
#define EStartGameState  EStartGameState

/* ---------------------------------------------------------- USettings ! ---------------------------------------------------------- */

typedef enum EOnlineDataAdvertisementType : unsigned char {
  ODAT_DontAdvertise,             // 0
  ODAT_OnlineService,             // 1
  ODAT_QoS,                       // 2
  ODAT_OnlineServiceAndQoS,       // 3
  ODAT_MAX                        // 4
  #define ODAT_DontAdvertise                                ODAT_DontAdvertise
  #define ODAT_OnlineService                                ODAT_OnlineService
  #define ODAT_QoS                                          ODAT_QoS
  #define ODAT_OnlineServiceAndQoS                          ODAT_OnlineServiceAndQoS
  #define ODAT_MAX                                          ODAT_MAX
  #define EOnlineDataAdvertisementType_DontAdvertise        ODAT_DontAdvertise
  #define EOnlineDataAdvertisementType_OnlineService        ODAT_OnlineService
  #define EOnlineDataAdvertisementType_QoS                  ODAT_QoS
  #define EOnlineDataAdvertisementType_OnlineServiceAndQoS  ODAT_OnlineServiceAndQoS
  #define EOnlineDataAdvertisementType_MAX                  ODAT_MAX
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
  #define SDT_Empty                   SDT_Empty
  #define SDT_Int32                   SDT_Int32
  #define SDT_Int64                   SDT_Int64
  #define SDT_Double                  SDT_Double
  #define SDT_String                  SDT_String
  #define SDT_Float                   SDT_Float
  #define SDT_Blob                    SDT_Blob
  #define SDT_DateTime                SDT_DateTime
  #define SDT_Byte                    SDT_Byte
  #define SDT_MAX                     SDT_MAX
  #define ESettingsDataType_Empty     SDT_Empty
  #define ESettingsDataType_Int32     SDT_Int32
  #define ESettingsDataType_Int64     SDT_Int64
  #define ESettingsDataType_Double    SDT_Double
  #define ESettingsDataType_String    SDT_String
  #define ESettingsDataType_Float     SDT_Float
  #define ESettingsDataType_Blob      SDT_Blob
  #define ESettingsDataType_DateTime  SDT_DateTime
  #define ESettingsDataType_Byte      SDT_Byte
  #define ESettingsDataType_MAX       SDT_MAX
} ESettingsDataType;
typedef enum EPropertyValueMappingType    : unsigned char {
  PVMT_RawValue,                  // 0
  PVMT_PredefinedValues,          // 1
  PVMT_Ranged,                    // 2
  PVMT_IdMapped,                  // 3
  PVMT_MAX                        // 4
  #define PVMT_RawValue                               PVMT_RawValue
  #define PVMT_PredefinedValues                       PVMT_PredefinedValues
  #define PVMT_Ranged                                 PVMT_Ranged
  #define PVMT_IdMapped                               PVMT_IdMapped
  #define PVMT_MAX                                    PVMT_MAX
  #define EPropertyValueMappingType_RawValue          PVMT_RawValue
  #define EPropertyValueMappingType_PredefinedValues  PVMT_PredefinedValues
  #define EPropertyValueMappingType_Ranged            PVMT_Ranged
  #define EPropertyValueMappingType_IdMapped          PVMT_IdMapped
  #define EPropertyValueMappingType_MAX               PVMT_MAX
} EPropertyValueMappingType;
#define EOnlineDataAdvertisementType  EOnlineDataAdvertisementType
#define ESettingsDataType             ESettingsDataType
#define EPropertyValueMappingType     EPropertyValueMappingType

/* ---------------------------------------------------------- AWillowPlayerStats ! ---------------------------------------------------------- */

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
  #define DAMAGE_CAUSER_TYPE_Unknown          DAMAGE_CAUSER_TYPE_Unknown
  #define DAMAGE_CAUSER_TYPE_Pistol           DAMAGE_CAUSER_TYPE_Pistol
  #define DAMAGE_CAUSER_TYPE_Shotgun          DAMAGE_CAUSER_TYPE_Shotgun
  #define DAMAGE_CAUSER_TYPE_AssaultRifle     DAMAGE_CAUSER_TYPE_AssaultRifle
  #define DAMAGE_CAUSER_TYPE_SniperRifle      DAMAGE_CAUSER_TYPE_SniperRifle
  #define DAMAGE_CAUSER_TYPE_SMG              DAMAGE_CAUSER_TYPE_SMG
  #define DAMAGE_CAUSER_TYPE_Frag_Grenade     DAMAGE_CAUSER_TYPE_Frag_Grenade
  #define DAMAGE_CAUSER_TYPE_Protean_Grenade  DAMAGE_CAUSER_TYPE_Protean_Grenade
  #define DAMAGE_CAUSER_TYPE_Vehicle          DAMAGE_CAUSER_TYPE_Vehicle
  #define DAMAGE_CAUSER_TYPE_VehicleWeapon    DAMAGE_CAUSER_TYPE_VehicleWeapon
  #define DAMAGE_CAUSER_TYPE_Melee            DAMAGE_CAUSER_TYPE_Melee
  #define DAMAGE_CAUSER_TYPE_Turret           DAMAGE_CAUSER_TYPE_Turret
  #define DAMAGE_CAUSER_TYPE_Launcher         DAMAGE_CAUSER_TYPE_Launcher
  #define DAMAGE_CAUSER_TYPE_ExtraWeapon1     DAMAGE_CAUSER_TYPE_ExtraWeapon1
  #define DAMAGE_CAUSER_TYPE_ExtraWeapon2     DAMAGE_CAUSER_TYPE_ExtraWeapon2
  #define DAMAGE_CAUSER_TYPE_ExtraWeapon3     DAMAGE_CAUSER_TYPE_ExtraWeapon3
  #define DAMAGE_CAUSER_TYPE_ExtraWeapon4     DAMAGE_CAUSER_TYPE_ExtraWeapon4
  #define DAMAGE_CAUSER_TYPE_MAX              DAMAGE_CAUSER_TYPE_MAX
  #define EDamageCauserType_Unknown           DAMAGE_CAUSER_TYPE_Unknown
  #define EDamageCauserType_Pistol            DAMAGE_CAUSER_TYPE_Pistol
  #define EDamageCauserType_Shotgun           DAMAGE_CAUSER_TYPE_Shotgun
  #define EDamageCauserType_AssaultRifle      DAMAGE_CAUSER_TYPE_AssaultRifle
  #define EDamageCauserType_SniperRifle       DAMAGE_CAUSER_TYPE_SniperRifle
  #define EDamageCauserType_SMG               DAMAGE_CAUSER_TYPE_SMG
  #define EDamageCauserType_Frag_Grenade      DAMAGE_CAUSER_TYPE_Frag_Grenade
  #define EDamageCauserType_Protean_Grenade   DAMAGE_CAUSER_TYPE_Protean_Grenade
  #define EDamageCauserType_Vehicle           DAMAGE_CAUSER_TYPE_Vehicle
  #define EDamageCauserType_VehicleWeapon     DAMAGE_CAUSER_TYPE_VehicleWeapon
  #define EDamageCauserType_Melee             DAMAGE_CAUSER_TYPE_Melee
  #define EDamageCauserType_Turret            DAMAGE_CAUSER_TYPE_Turret
  #define EDamageCauserType_Launcher          DAMAGE_CAUSER_TYPE_Launcher
  #define EDamageCauserType_ExtraWeapon1      DAMAGE_CAUSER_TYPE_ExtraWeapon1
  #define EDamageCauserType_ExtraWeapon2      DAMAGE_CAUSER_TYPE_ExtraWeapon2
  #define EDamageCauserType_ExtraWeapon3      DAMAGE_CAUSER_TYPE_ExtraWeapon3
  #define EDamageCauserType_ExtraWeapon4      DAMAGE_CAUSER_TYPE_ExtraWeapon4
  #define EDamageCauserType_MAX               DAMAGE_CAUSER_TYPE_MAX
} EDamageCauserType;
#define EDamageCauserType  EDamageCauserType

/* ---------------------------------------------------------- UOnlinePlayerStorage ! ---------------------------------------------------------- */

typedef enum EOnlineProfilePropertyOwner    : unsigned char {
  OPPO_None,                      // 0
  OPPO_OnlineService,             // 1
  OPPO_Game,                      // 2
  OPPO_MAX                        // 3
  #define OPPO_None                                  OPPO_None
  #define OPPO_OnlineService                         OPPO_OnlineService
  #define OPPO_Game                                  OPPO_Game
  #define OPPO_MAX                                   OPPO_MAX
  #define EOnlineProfilePropertyOwner_None           OPPO_None
  #define EOnlineProfilePropertyOwner_OnlineService  OPPO_OnlineService
  #define EOnlineProfilePropertyOwner_Game           OPPO_Game
  #define EOnlineProfilePropertyOwner_MAX            OPPO_MAX
} EOnlineProfilePropertyOwner;
typedef enum EOnlinePlayerStorageAsyncState : unsigned char {
  OPAS_NotStarted,                // 0
  OPAS_Read,                      // 1
  OPAS_Write,                     // 2
  OPAS_Finished,                  // 3
  OPAS_MAX                        // 4
  #define OPAS_NotStarted                            OPAS_NotStarted
  #define OPAS_Read                                  OPAS_Read
  #define OPAS_Write                                 OPAS_Write
  #define OPAS_Finished                              OPAS_Finished
  #define OPAS_MAX                                   OPAS_MAX
  #define EOnlinePlayerStorageAsyncState_NotStarted  OPAS_NotStarted
  #define EOnlinePlayerStorageAsyncState_Read        OPAS_Read
  #define EOnlinePlayerStorageAsyncState_Write       OPAS_Write
  #define EOnlinePlayerStorageAsyncState_Finished    OPAS_Finished
  #define EOnlinePlayerStorageAsyncState_MAX         OPAS_MAX
} EOnlinePlayerStorageAsyncState;
#define EOnlineProfilePropertyOwner     EOnlineProfilePropertyOwner
#define EOnlinePlayerStorageAsyncState  EOnlinePlayerStorageAsyncState

/* ---------------------------------------------------------- UOnlineProfileSettings ! ---------------------------------------------------------- */

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
  #define PSI_Unknown                                PSI_Unknown
  #define PSI_ControllerVibration                    PSI_ControllerVibration
  #define PSI_YInversion                             PSI_YInversion
  #define PSI_GamerCred                              PSI_GamerCred
  #define PSI_GamerRep                               PSI_GamerRep
  #define PSI_VoiceMuted                             PSI_VoiceMuted
  #define PSI_VoiceThruSpeakers                      PSI_VoiceThruSpeakers
  #define PSI_VoiceVolume                            PSI_VoiceVolume
  #define PSI_GamerPictureKey                        PSI_GamerPictureKey
  #define PSI_GamerMotto                             PSI_GamerMotto
  #define PSI_GamerTitlesPlayed                      PSI_GamerTitlesPlayed
  #define PSI_GamerAchievementsEarned                PSI_GamerAchievementsEarned
  #define PSI_GameDifficulty                         PSI_GameDifficulty
  #define PSI_ControllerSensitivity                  PSI_ControllerSensitivity
  #define PSI_PreferredColor1                        PSI_PreferredColor1
  #define PSI_PreferredColor2                        PSI_PreferredColor2
  #define PSI_AutoAim                                PSI_AutoAim
  #define PSI_AutoCenter                             PSI_AutoCenter
  #define PSI_MovementControl                        PSI_MovementControl
  #define PSI_RaceTransmission                       PSI_RaceTransmission
  #define PSI_RaceCameraLocation                     PSI_RaceCameraLocation
  #define PSI_RaceBrakeControl                       PSI_RaceBrakeControl
  #define PSI_RaceAcceleratorControl                 PSI_RaceAcceleratorControl
  #define PSI_GameCredEarned                         PSI_GameCredEarned
  #define PSI_GameAchievementsEarned                 PSI_GameAchievementsEarned
  #define PSI_EndLiveIds                             PSI_EndLiveIds
  #define PSI_ProfileVersionNum                      PSI_ProfileVersionNum
  #define PSI_ProfileSaveCount                       PSI_ProfileSaveCount
  #define PSI_MAX                                    PSI_MAX
  #define EProfileSettingID_Unknown                  PSI_Unknown
  #define EProfileSettingID_ControllerVibration      PSI_ControllerVibration
  #define EProfileSettingID_YInversion               PSI_YInversion
  #define EProfileSettingID_GamerCred                PSI_GamerCred
  #define EProfileSettingID_GamerRep                 PSI_GamerRep
  #define EProfileSettingID_VoiceMuted               PSI_VoiceMuted
  #define EProfileSettingID_VoiceThruSpeakers        PSI_VoiceThruSpeakers
  #define EProfileSettingID_VoiceVolume              PSI_VoiceVolume
  #define EProfileSettingID_GamerPictureKey          PSI_GamerPictureKey
  #define EProfileSettingID_GamerMotto               PSI_GamerMotto
  #define EProfileSettingID_GamerTitlesPlayed        PSI_GamerTitlesPlayed
  #define EProfileSettingID_GamerAchievementsEarned  PSI_GamerAchievementsEarned
  #define EProfileSettingID_GameDifficulty           PSI_GameDifficulty
  #define EProfileSettingID_ControllerSensitivity    PSI_ControllerSensitivity
  #define EProfileSettingID_PreferredColor1          PSI_PreferredColor1
  #define EProfileSettingID_PreferredColor2          PSI_PreferredColor2
  #define EProfileSettingID_AutoAim                  PSI_AutoAim
  #define EProfileSettingID_AutoCenter               PSI_AutoCenter
  #define EProfileSettingID_MovementControl          PSI_MovementControl
  #define EProfileSettingID_RaceTransmission         PSI_RaceTransmission
  #define EProfileSettingID_RaceCameraLocation       PSI_RaceCameraLocation
  #define EProfileSettingID_RaceBrakeControl         PSI_RaceBrakeControl
  #define EProfileSettingID_RaceAcceleratorControl   PSI_RaceAcceleratorControl
  #define EProfileSettingID_GameCredEarned           PSI_GameCredEarned
  #define EProfileSettingID_GameAchievementsEarned   PSI_GameAchievementsEarned
  #define EProfileSettingID_EndLiveIds               PSI_EndLiveIds
  #define EProfileSettingID_ProfileVersionNum        PSI_ProfileVersionNum
  #define EProfileSettingID_ProfileSaveCount         PSI_ProfileSaveCount
  #define EProfileSettingID_MAX                      PSI_MAX
} EProfileSettingID;
typedef enum EProfileDifficultyOptions                : unsigned char {
  PDO_Normal,                     // 0
  PDO_Easy,                       // 1
  PDO_Hard,                       // 2
  PDO_MAX                         // 3
  #define PDO_Normal                        PDO_Normal
  #define PDO_Easy                          PDO_Easy
  #define PDO_Hard                          PDO_Hard
  #define PDO_MAX                           PDO_MAX
  #define EProfileDifficultyOptions_Normal  PDO_Normal
  #define EProfileDifficultyOptions_Easy    PDO_Easy
  #define EProfileDifficultyOptions_Hard    PDO_Hard
  #define EProfileDifficultyOptions_MAX     PDO_MAX
} EProfileDifficultyOptions;
typedef enum EProfileControllerSensitivityOptions     : unsigned char {
  PCSO_Medium,                    // 0
  PCSO_Low,                       // 1
  PCSO_High,                      // 2
  PCSO_MAX                        // 3
  #define PCSO_Medium                                  PCSO_Medium
  #define PCSO_Low                                     PCSO_Low
  #define PCSO_High                                    PCSO_High
  #define PCSO_MAX                                     PCSO_MAX
  #define EProfileControllerSensitivityOptions_Medium  PCSO_Medium
  #define EProfileControllerSensitivityOptions_Low     PCSO_Low
  #define EProfileControllerSensitivityOptions_High    PCSO_High
  #define EProfileControllerSensitivityOptions_MAX     PCSO_MAX
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
  #define PPCO_None                             PPCO_None
  #define PPCO_Black                            PPCO_Black
  #define PPCO_White                            PPCO_White
  #define PPCO_Yellow                           PPCO_Yellow
  #define PPCO_Orange                           PPCO_Orange
  #define PPCO_Pink                             PPCO_Pink
  #define PPCO_Red                              PPCO_Red
  #define PPCO_Purple                           PPCO_Purple
  #define PPCO_Blue                             PPCO_Blue
  #define PPCO_Green                            PPCO_Green
  #define PPCO_Brown                            PPCO_Brown
  #define PPCO_Silver                           PPCO_Silver
  #define PPCO_MAX                              PPCO_MAX
  #define EProfilePreferredColorOptions_None    PPCO_None
  #define EProfilePreferredColorOptions_Black   PPCO_Black
  #define EProfilePreferredColorOptions_White   PPCO_White
  #define EProfilePreferredColorOptions_Yellow  PPCO_Yellow
  #define EProfilePreferredColorOptions_Orange  PPCO_Orange
  #define EProfilePreferredColorOptions_Pink    PPCO_Pink
  #define EProfilePreferredColorOptions_Red     PPCO_Red
  #define EProfilePreferredColorOptions_Purple  PPCO_Purple
  #define EProfilePreferredColorOptions_Blue    PPCO_Blue
  #define EProfilePreferredColorOptions_Green   PPCO_Green
  #define EProfilePreferredColorOptions_Brown   PPCO_Brown
  #define EProfilePreferredColorOptions_Silver  PPCO_Silver
  #define EProfilePreferredColorOptions_MAX     PPCO_MAX
} EProfilePreferredColorOptions;
typedef enum EProfileAutoAimOptions                   : unsigned char {
  PAAO_Off,                       // 0
  PAAO_On,                        // 1
  PAAO_MAX                        // 2
  #define PAAO_Off                    PAAO_Off
  #define PAAO_On                     PAAO_On
  #define PAAO_MAX                    PAAO_MAX
  #define EProfileAutoAimOptions_Off  PAAO_Off
  #define EProfileAutoAimOptions_On   PAAO_On
  #define EProfileAutoAimOptions_MAX  PAAO_MAX
} EProfileAutoAimOptions;
typedef enum EProfileAutoCenterOptions                : unsigned char {
  PACO_Off,                       // 0
  PACO_On,                        // 1
  PACO_MAX                        // 2
  #define PACO_Off                       PACO_Off
  #define PACO_On                        PACO_On
  #define PACO_MAX                       PACO_MAX
  #define EProfileAutoCenterOptions_Off  PACO_Off
  #define EProfileAutoCenterOptions_On   PACO_On
  #define EProfileAutoCenterOptions_MAX  PACO_MAX
} EProfileAutoCenterOptions;
typedef enum EProfileMovementControlOptions           : unsigned char {
  PMCO_L_Thumbstick,              // 0
  PMCO_R_Thumbstick,              // 1
  PMCO_MAX                        // 2
  #define PMCO_L_Thumbstick                            PMCO_L_Thumbstick
  #define PMCO_R_Thumbstick                            PMCO_R_Thumbstick
  #define PMCO_MAX                                     PMCO_MAX
  #define EProfileMovementControlOptions_L_Thumbstick  PMCO_L_Thumbstick
  #define EProfileMovementControlOptions_R_Thumbstick  PMCO_R_Thumbstick
  #define EProfileMovementControlOptions_MAX           PMCO_MAX
} EProfileMovementControlOptions;
typedef enum EProfileRaceTransmissionOptions          : unsigned char {
  PRTO_Auto,                      // 0
  PRTO_Manual,                    // 1
  PRTO_MAX                        // 2
  #define PRTO_Auto                               PRTO_Auto
  #define PRTO_Manual                             PRTO_Manual
  #define PRTO_MAX                                PRTO_MAX
  #define EProfileRaceTransmissionOptions_Auto    PRTO_Auto
  #define EProfileRaceTransmissionOptions_Manual  PRTO_Manual
  #define EProfileRaceTransmissionOptions_MAX     PRTO_MAX
} EProfileRaceTransmissionOptions;
typedef enum EProfileRaceCameraLocationOptions        : unsigned char {
  PRCLO_Behind,                   // 0
  PRCLO_Front,                    // 1
  PRCLO_Inside,                   // 2
  PRCLO_MAX                       // 3
  #define PRCLO_Behind                              PRCLO_Behind
  #define PRCLO_Front                               PRCLO_Front
  #define PRCLO_Inside                              PRCLO_Inside
  #define PRCLO_MAX                                 PRCLO_MAX
  #define EProfileRaceCameraLocationOptions_Behind  PRCLO_Behind
  #define EProfileRaceCameraLocationOptions_Front   PRCLO_Front
  #define EProfileRaceCameraLocationOptions_Inside  PRCLO_Inside
  #define EProfileRaceCameraLocationOptions_MAX     PRCLO_MAX
} EProfileRaceCameraLocationOptions;
typedef enum EProfileRaceBrakeControlOptions          : unsigned char {
  PRBCO_Trigger,                  // 0
  PRBCO_Button,                   // 1
  PRBCO_MAX                       // 2
  #define PRBCO_Trigger                            PRBCO_Trigger
  #define PRBCO_Button                             PRBCO_Button
  #define PRBCO_MAX                                PRBCO_MAX
  #define EProfileRaceBrakeControlOptions_Trigger  PRBCO_Trigger
  #define EProfileRaceBrakeControlOptions_Button   PRBCO_Button
  #define EProfileRaceBrakeControlOptions_MAX      PRBCO_MAX
} EProfileRaceBrakeControlOptions;
typedef enum EProfileRaceAcceleratorControlOptions    : unsigned char {
  PRACO_Trigger,                  // 0
  PRACO_Button,                   // 1
  PRACO_MAX                       // 2
  #define PRACO_Trigger                                  PRACO_Trigger
  #define PRACO_Button                                   PRACO_Button
  #define PRACO_MAX                                      PRACO_MAX
  #define EProfileRaceAcceleratorControlOptions_Trigger  PRACO_Trigger
  #define EProfileRaceAcceleratorControlOptions_Button   PRACO_Button
  #define EProfileRaceAcceleratorControlOptions_MAX      PRACO_MAX
} EProfileRaceAcceleratorControlOptions;
typedef enum EProfileYInversionOptions                : unsigned char {
  PYIO_Off,                       // 0
  PYIO_On,                        // 1
  PYIO_MAX                        // 2
  #define PYIO_Off                       PYIO_Off
  #define PYIO_On                        PYIO_On
  #define PYIO_MAX                       PYIO_MAX
  #define EProfileYInversionOptions_Off  PYIO_Off
  #define EProfileYInversionOptions_On   PYIO_On
  #define EProfileYInversionOptions_MAX  PYIO_MAX
} EProfileYInversionOptions;
typedef enum EProfileXInversionOptions                : unsigned char {
  PXIO_Off,                       // 0
  PXIO_On,                        // 1
  PXIO_MAX                        // 2
  #define PXIO_Off                       PXIO_Off
  #define PXIO_On                        PXIO_On
  #define PXIO_MAX                       PXIO_MAX
  #define EProfileXInversionOptions_Off  PXIO_Off
  #define EProfileXInversionOptions_On   PXIO_On
  #define EProfileXInversionOptions_MAX  PXIO_MAX
} EProfileXInversionOptions;
typedef enum EProfileOmniDirEvadeOptions              : unsigned char {
  PODI_Off,                       // 0
  PODI_On,                        // 1
  PODI_MAX                        // 2
  #define PODI_Off                         PODI_Off
  #define PODI_On                          PODI_On
  #define PODI_MAX                         PODI_MAX
  #define EProfileOmniDirEvadeOptions_Off  PODI_Off
  #define EProfileOmniDirEvadeOptions_On   PODI_On
  #define EProfileOmniDirEvadeOptions_MAX  PODI_MAX
} EProfileOmniDirEvadeOptions;
typedef enum EProfileControllerVibrationToggleOptions : unsigned char {
  PCVTO_Off,                      // 0
  PCVTO_IgnoreThis,               // 1
  PCVTO_IgnoreThis2,              // 2
  PCVTO_On,                       // 3
  PCVTO_MAX                       // 4
  #define PCVTO_Off                                             PCVTO_Off
  #define PCVTO_IgnoreThis                                      PCVTO_IgnoreThis
  #define PCVTO_IgnoreThis2                                     PCVTO_IgnoreThis2
  #define PCVTO_On                                              PCVTO_On
  #define PCVTO_MAX                                             PCVTO_MAX
  #define EProfileControllerVibrationToggleOptions_Off          PCVTO_Off
  #define EProfileControllerVibrationToggleOptions_IgnoreThis   PCVTO_IgnoreThis
  #define EProfileControllerVibrationToggleOptions_IgnoreThis2  PCVTO_IgnoreThis2
  #define EProfileControllerVibrationToggleOptions_On           PCVTO_On
  #define EProfileControllerVibrationToggleOptions_MAX          PCVTO_MAX
} EProfileControllerVibrationToggleOptions;
typedef enum EProfileVoiceThruSpeakersOptions         : unsigned char {
  PVTSO_Off,                      // 0
  PVTSO_On,                       // 1
  PVTSO_Both,                     // 2
  PVTSO_MAX                       // 3
  #define PVTSO_Off                              PVTSO_Off
  #define PVTSO_On                               PVTSO_On
  #define PVTSO_Both                             PVTSO_Both
  #define PVTSO_MAX                              PVTSO_MAX
  #define EProfileVoiceThruSpeakersOptions_Off   PVTSO_Off
  #define EProfileVoiceThruSpeakersOptions_On    PVTSO_On
  #define EProfileVoiceThruSpeakersOptions_Both  PVTSO_Both
  #define EProfileVoiceThruSpeakersOptions_MAX   PVTSO_MAX
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

/* ---------------------------------------------------------- UGearboxProfileSettings ! ---------------------------------------------------------- */

typedef enum EGenericYesOrNo : unsigned char {
  GPID_VALUE_NO,                  // 0
  GPID_VALUE_YES,                 // 1
  GPID_VALUE_MAX                  // 2
  #define GPID_VALUE_NO        GPID_VALUE_NO
  #define GPID_VALUE_YES       GPID_VALUE_YES
  #define GPID_VALUE_MAX       GPID_VALUE_MAX
  #define EGenericYesOrNo_NO   GPID_VALUE_NO
  #define EGenericYesOrNo_YES  GPID_VALUE_YES
  #define EGenericYesOrNo_MAX  GPID_VALUE_MAX
} EGenericYesOrNo;
#define EGenericYesOrNo  EGenericYesOrNo

/* ---------------------------------------------------------- UOnlineSubsystem ! ---------------------------------------------------------- */

typedef enum ELoginStatus                  : unsigned char {
  LS_NotLoggedIn,                 // 0
  LS_UsingLocalProfile,           // 1
  LS_LoggedIn,                    // 2
  LS_MAX                          // 3
  #define LS_NotLoggedIn                  LS_NotLoggedIn
  #define LS_UsingLocalProfile            LS_UsingLocalProfile
  #define LS_LoggedIn                     LS_LoggedIn
  #define LS_MAX                          LS_MAX
  #define ELoginStatus_NotLoggedIn        LS_NotLoggedIn
  #define ELoginStatus_UsingLocalProfile  LS_UsingLocalProfile
  #define ELoginStatus_LoggedIn           LS_LoggedIn
  #define ELoginStatus_MAX                LS_MAX
} ELoginStatus;
typedef enum EUserAgeGroup                 : unsigned char {
  UAG_Unknown,                    // 0
  UAG_Child,                      // 1
  UAG_Teen,                       // 2
  UAG_Adult,                      // 3
  UAG_MAX                         // 4
  #define UAG_Unknown            UAG_Unknown
  #define UAG_Child              UAG_Child
  #define UAG_Teen               UAG_Teen
  #define UAG_Adult              UAG_Adult
  #define UAG_MAX                UAG_MAX
  #define EUserAgeGroup_Unknown  UAG_Unknown
  #define EUserAgeGroup_Child    UAG_Child
  #define EUserAgeGroup_Teen     UAG_Teen
  #define EUserAgeGroup_Adult    UAG_Adult
  #define EUserAgeGroup_MAX      UAG_MAX
} EUserAgeGroup;
typedef enum EFeaturePrivilegeLevel        : unsigned char {
  FPL_Disabled,                   // 0
  FPL_EnabledFriendsOnly,         // 1
  FPL_Enabled,                    // 2
  FPL_MAX                         // 3
  #define FPL_Disabled                               FPL_Disabled
  #define FPL_EnabledFriendsOnly                     FPL_EnabledFriendsOnly
  #define FPL_Enabled                                FPL_Enabled
  #define FPL_MAX                                    FPL_MAX
  #define EFeaturePrivilegeLevel_Disabled            FPL_Disabled
  #define EFeaturePrivilegeLevel_EnabledFriendsOnly  FPL_EnabledFriendsOnly
  #define EFeaturePrivilegeLevel_Enabled             FPL_Enabled
  #define EFeaturePrivilegeLevel_MAX                 FPL_MAX
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
  #define NNP_TopLeft                                NNP_TopLeft
  #define NNP_TopCenter                              NNP_TopCenter
  #define NNP_TopRight                               NNP_TopRight
  #define NNP_CenterLeft                             NNP_CenterLeft
  #define NNP_Center                                 NNP_Center
  #define NNP_CenterRight                            NNP_CenterRight
  #define NNP_BottomLeft                             NNP_BottomLeft
  #define NNP_BottomCenter                           NNP_BottomCenter
  #define NNP_BottomRight                            NNP_BottomRight
  #define NNP_MAX                                    NNP_MAX
  #define ENetworkNotificationPosition_TopLeft       NNP_TopLeft
  #define ENetworkNotificationPosition_TopCenter     NNP_TopCenter
  #define ENetworkNotificationPosition_TopRight      NNP_TopRight
  #define ENetworkNotificationPosition_CenterLeft    NNP_CenterLeft
  #define ENetworkNotificationPosition_Center        NNP_Center
  #define ENetworkNotificationPosition_CenterRight   NNP_CenterRight
  #define ENetworkNotificationPosition_BottomLeft    NNP_BottomLeft
  #define ENetworkNotificationPosition_BottomCenter  NNP_BottomCenter
  #define ENetworkNotificationPosition_BottomRight   NNP_BottomRight
  #define ENetworkNotificationPosition_MAX           NNP_MAX
} ENetworkNotificationPosition;
typedef enum EOnlineGameState              : unsigned char {
  OGS_NoSession,                  // 0
  OGS_Pending,                    // 1
  OGS_Starting,                   // 2
  OGS_InProgress,                 // 3
  OGS_Ending,                     // 4
  OGS_Ended,                      // 5
  OGS_MAX                         // 6
  #define OGS_NoSession                OGS_NoSession
  #define OGS_Pending                  OGS_Pending
  #define OGS_Starting                 OGS_Starting
  #define OGS_InProgress               OGS_InProgress
  #define OGS_Ending                   OGS_Ending
  #define OGS_Ended                    OGS_Ended
  #define OGS_MAX                      OGS_MAX
  #define EOnlineGameState_NoSession   OGS_NoSession
  #define EOnlineGameState_Pending     OGS_Pending
  #define EOnlineGameState_Starting    OGS_Starting
  #define EOnlineGameState_InProgress  OGS_InProgress
  #define EOnlineGameState_Ending      OGS_Ending
  #define EOnlineGameState_Ended       OGS_Ended
  #define EOnlineGameState_MAX         OGS_MAX
} EOnlineGameState;
typedef enum EOnlineEnumerationReadState   : unsigned char {
  OERS_NotStarted,                // 0
  OERS_InProgress,                // 1
  OERS_Done,                      // 2
  OERS_Failed,                    // 3
  OERS_MAX                        // 4
  #define OERS_NotStarted                         OERS_NotStarted
  #define OERS_InProgress                         OERS_InProgress
  #define OERS_Done                               OERS_Done
  #define OERS_Failed                             OERS_Failed
  #define OERS_MAX                                OERS_MAX
  #define EOnlineEnumerationReadState_NotStarted  OERS_NotStarted
  #define EOnlineEnumerationReadState_InProgress  OERS_InProgress
  #define EOnlineEnumerationReadState_Done        OERS_Done
  #define EOnlineEnumerationReadState_Failed      OERS_Failed
  #define EOnlineEnumerationReadState_MAX         OERS_MAX
} EOnlineEnumerationReadState;
typedef enum EOnlineFriendState            : unsigned char {
  OFS_Offline,                    // 0
  OFS_Online,                     // 1
  OFS_Away,                       // 2
  OFS_Busy,                       // 3
  OFS_MAX                         // 4
  #define OFS_Offline                 OFS_Offline
  #define OFS_Online                  OFS_Online
  #define OFS_Away                    OFS_Away
  #define OFS_Busy                    OFS_Busy
  #define OFS_MAX                     OFS_MAX
  #define EOnlineFriendState_Offline  OFS_Offline
  #define EOnlineFriendState_Online   OFS_Online
  #define EOnlineFriendState_Away     OFS_Away
  #define EOnlineFriendState_Busy     OFS_Busy
  #define EOnlineFriendState_MAX      OFS_MAX
} EOnlineFriendState;
typedef enum EVoiceVolumeType              : unsigned char {
  VVT_Capture,                    // 0
  VVT_Playback,                   // 1
  VVT_CaptureAndPlayback,         // 2
  VVT_MAX                         // 3
  #define VVT_Capture                          VVT_Capture
  #define VVT_Playback                         VVT_Playback
  #define VVT_CaptureAndPlayback               VVT_CaptureAndPlayback
  #define VVT_MAX                              VVT_MAX
  #define EVoiceVolumeType_Capture             VVT_Capture
  #define EVoiceVolumeType_Playback            VVT_Playback
  #define EVoiceVolumeType_CaptureAndPlayback  VVT_CaptureAndPlayback
  #define EVoiceVolumeType_MAX                 VVT_MAX
} EVoiceVolumeType;
typedef enum EOakStoreStatus               : unsigned char {
  OSS_Preorder,                   // 0
  OSS_Released,                   // 1
  OSS_Unavailable,                // 2
  OSS_MAX                         // 3
  #define OSS_Preorder                 OSS_Preorder
  #define OSS_Released                 OSS_Released
  #define OSS_Unavailable              OSS_Unavailable
  #define OSS_MAX                      OSS_MAX
  #define EOakStoreStatus_Preorder     OSS_Preorder
  #define EOakStoreStatus_Released     OSS_Released
  #define EOakStoreStatus_Unavailable  OSS_Unavailable
  #define EOakStoreStatus_MAX          OSS_MAX
} EOakStoreStatus;
typedef enum EOakProduct                   : unsigned char {
  OP_Standard,                    // 0
  OP_Deluxe,                      // 1
  OP_SuperDeluxe,                 // 2
  OP_MAX                          // 3
  #define OP_Standard              OP_Standard
  #define OP_Deluxe                OP_Deluxe
  #define OP_SuperDeluxe           OP_SuperDeluxe
  #define OP_MAX                   OP_MAX
  #define EOakProduct_Standard     OP_Standard
  #define EOakProduct_Deluxe       OP_Deluxe
  #define EOakProduct_SuperDeluxe  OP_SuperDeluxe
  #define EOakProduct_MAX          OP_MAX
} EOakProduct;
typedef enum EFriendPlatform               : unsigned char {
  FP_Bifrost,                     // 0
  FP_Epic,                        // 1
  FP_Steam,                       // 2
  FP_MAX                          // 3
  #define FP_Bifrost               FP_Bifrost
  #define FP_Epic                  FP_Epic
  #define FP_Steam                 FP_Steam
  #define FP_MAX                   FP_MAX
  #define EFriendPlatform_Bifrost  FP_Bifrost
  #define EFriendPlatform_Epic     FP_Epic
  #define EFriendPlatform_Steam    FP_Steam
  #define EFriendPlatform_MAX      FP_MAX
} EFriendPlatform;
typedef enum EOnlineContentType            : unsigned char {
  OCT_Downloaded,                 // 0
  OCT_SaveGame,                   // 1
  OCT_MAX                         // 2
  #define OCT_Downloaded                 OCT_Downloaded
  #define OCT_SaveGame                   OCT_SaveGame
  #define OCT_MAX                        OCT_MAX
  #define EOnlineContentType_Downloaded  OCT_Downloaded
  #define EOnlineContentType_SaveGame    OCT_SaveGame
  #define EOnlineContentType_MAX         OCT_MAX
} EOnlineContentType;
typedef enum ENamedOnlineContentType       : unsigned char {
  NOCT_Content,                   // 0
  NOCT_SeasonPass,                // 1
  NOCT_PreorderBonus,             // 2
  NOCT_CompatibilityPack,         // 3
  NOCT_MAX                        // 4
  #define NOCT_Content                               NOCT_Content
  #define NOCT_SeasonPass                            NOCT_SeasonPass
  #define NOCT_PreorderBonus                         NOCT_PreorderBonus
  #define NOCT_CompatibilityPack                     NOCT_CompatibilityPack
  #define NOCT_MAX                                   NOCT_MAX
  #define ENamedOnlineContentType_Content            NOCT_Content
  #define ENamedOnlineContentType_SeasonPass         NOCT_SeasonPass
  #define ENamedOnlineContentType_PreorderBonus      NOCT_PreorderBonus
  #define ENamedOnlineContentType_CompatibilityPack  NOCT_CompatibilityPack
  #define ENamedOnlineContentType_MAX                NOCT_MAX
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
  #define OSCS_NotConnected                                     OSCS_NotConnected
  #define OSCS_Connected                                        OSCS_Connected
  #define OSCS_ConnectionDropped                                OSCS_ConnectionDropped
  #define OSCS_NoNetworkConnection                              OSCS_NoNetworkConnection
  #define OSCS_ServiceUnavailable                               OSCS_ServiceUnavailable
  #define OSCS_UpdateRequired                                   OSCS_UpdateRequired
  #define OSCS_ServersTooBusy                                   OSCS_ServersTooBusy
  #define OSCS_DuplicateLoginDetected                           OSCS_DuplicateLoginDetected
  #define OSCS_InvalidUser                                      OSCS_InvalidUser
  #define OSCS_MAX                                              OSCS_MAX
  #define EOnlineServerConnectionStatus_NotConnected            OSCS_NotConnected
  #define EOnlineServerConnectionStatus_Connected               OSCS_Connected
  #define EOnlineServerConnectionStatus_ConnectionDropped       OSCS_ConnectionDropped
  #define EOnlineServerConnectionStatus_NoNetworkConnection     OSCS_NoNetworkConnection
  #define EOnlineServerConnectionStatus_ServiceUnavailable      OSCS_ServiceUnavailable
  #define EOnlineServerConnectionStatus_UpdateRequired          OSCS_UpdateRequired
  #define EOnlineServerConnectionStatus_ServersTooBusy          OSCS_ServersTooBusy
  #define EOnlineServerConnectionStatus_DuplicateLoginDetected  OSCS_DuplicateLoginDetected
  #define EOnlineServerConnectionStatus_InvalidUser             OSCS_InvalidUser
  #define EOnlineServerConnectionStatus_MAX                     OSCS_MAX
} EOnlineServerConnectionStatus;
typedef enum ENATType                      : unsigned char {
  NAT_Unknown,                    // 0
  NAT_Open,                       // 1
  NAT_Moderate,                   // 2
  NAT_Strict,                     // 3
  NAT_MAX                         // 4
  #define NAT_Unknown        NAT_Unknown
  #define NAT_Open           NAT_Open
  #define NAT_Moderate       NAT_Moderate
  #define NAT_Strict         NAT_Strict
  #define NAT_MAX            NAT_MAX
  #define ENATType_Unknown   NAT_Unknown
  #define ENATType_Open      NAT_Open
  #define ENATType_Moderate  NAT_Moderate
  #define ENATType_Strict    NAT_Strict
  #define ENATType_MAX       NAT_MAX
} ENATType;
typedef enum ELanBeaconState               : unsigned char {
  LANB_NotUsingLanBeacon,         // 0
  LANB_Hosting,                   // 1
  LANB_Searching,                 // 2
  LANB_MAX                        // 3
  #define LANB_NotUsingLanBeacon             LANB_NotUsingLanBeacon
  #define LANB_Hosting                       LANB_Hosting
  #define LANB_Searching                     LANB_Searching
  #define LANB_MAX                           LANB_MAX
  #define ELanBeaconState_NotUsingLanBeacon  LANB_NotUsingLanBeacon
  #define ELanBeaconState_Hosting            LANB_Hosting
  #define ELanBeaconState_Searching          LANB_Searching
  #define ELanBeaconState_MAX                LANB_MAX
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
  #define OACS_CreateSuccessful                             OACS_CreateSuccessful
  #define OACS_UnknownError                                 OACS_UnknownError
  #define OACS_InvalidUserName                              OACS_InvalidUserName
  #define OACS_InvalidPassword                              OACS_InvalidPassword
  #define OACS_InvalidUniqueUserName                        OACS_InvalidUniqueUserName
  #define OACS_UniqueUserNameInUse                          OACS_UniqueUserNameInUse
  #define OACS_ServiceUnavailable                           OACS_ServiceUnavailable
  #define OACS_MAX                                          OACS_MAX
  #define EOnlineAccountCreateStatus_CreateSuccessful       OACS_CreateSuccessful
  #define EOnlineAccountCreateStatus_UnknownError           OACS_UnknownError
  #define EOnlineAccountCreateStatus_InvalidUserName        OACS_InvalidUserName
  #define EOnlineAccountCreateStatus_InvalidPassword        OACS_InvalidPassword
  #define EOnlineAccountCreateStatus_InvalidUniqueUserName  OACS_InvalidUniqueUserName
  #define EOnlineAccountCreateStatus_UniqueUserNameInUse    OACS_UniqueUserNameInUse
  #define EOnlineAccountCreateStatus_ServiceUnavailable     OACS_ServiceUnavailable
  #define EOnlineAccountCreateStatus_MAX                    OACS_MAX
} EOnlineAccountCreateStatus;
typedef enum EOnlineNewsType               : unsigned char {
  ONT_Unknown,                    // 0
  ONT_GameNews,                   // 1
  ONT_ContentAnnouncements,       // 2
  ONT_Misc,                       // 3
  ONT_MAX                         // 4
  #define ONT_Unknown                           ONT_Unknown
  #define ONT_GameNews                          ONT_GameNews
  #define ONT_ContentAnnouncements              ONT_ContentAnnouncements
  #define ONT_Misc                              ONT_Misc
  #define ONT_MAX                               ONT_MAX
  #define EOnlineNewsType_Unknown               ONT_Unknown
  #define EOnlineNewsType_GameNews              ONT_GameNews
  #define EOnlineNewsType_ContentAnnouncements  ONT_ContentAnnouncements
  #define EOnlineNewsType_Misc                  ONT_Misc
  #define EOnlineNewsType_MAX                   ONT_MAX
} EOnlineNewsType;
typedef enum EShowKeyboardType             : unsigned char {
  SKT_Standard,                   // 0
  SKT_Password,                   // 1
  SKT_Email,                      // 2
  SKT_MAX                         // 3
  #define SKT_Standard                SKT_Standard
  #define SKT_Password                SKT_Password
  #define SKT_Email                   SKT_Email
  #define SKT_MAX                     SKT_MAX
  #define EShowKeyboardType_Standard  SKT_Standard
  #define EShowKeyboardType_Password  SKT_Password
  #define EShowKeyboardType_Email     SKT_Email
  #define EShowKeyboardType_MAX       SKT_MAX
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

/* ---------------------------------------------------------- UWillowProfileSettings ! ---------------------------------------------------------- */

typedef enum EProfileViewDistanceOptions   : unsigned char {
  PVDO_Low,                       // 0
  PVDO_Medium,                    // 1
  PVDO_High,                      // 2
  PVDO_UltraHigh,                 // 3
  PVDO_MAX                        // 4
  #define PVDO_Low                               PVDO_Low
  #define PVDO_Medium                            PVDO_Medium
  #define PVDO_High                              PVDO_High
  #define PVDO_UltraHigh                         PVDO_UltraHigh
  #define PVDO_MAX                               PVDO_MAX
  #define EProfileViewDistanceOptions_Low        PVDO_Low
  #define EProfileViewDistanceOptions_Medium     PVDO_Medium
  #define EProfileViewDistanceOptions_High       PVDO_High
  #define EProfileViewDistanceOptions_UltraHigh  PVDO_UltraHigh
  #define EProfileViewDistanceOptions_MAX        PVDO_MAX
} EProfileViewDistanceOptions;
typedef enum EDecalSettingOptions          : unsigned char {
  DSO_Normal,                     // 0
  DSO_High,                       // 1
  DSO_MAX                         // 2
  #define DSO_Normal                   DSO_Normal
  #define DSO_High                     DSO_High
  #define DSO_MAX                      DSO_MAX
  #define EDecalSettingOptions_Normal  DSO_Normal
  #define EDecalSettingOptions_High    DSO_High
  #define EDecalSettingOptions_MAX     DSO_MAX
} EDecalSettingOptions;
typedef enum ESplitDirectionOptions        : unsigned char {
  SDO_Horizontal,                 // 0
  SDO_Vertical,                   // 1
  SDO_MAX                         // 2
  #define SDO_Horizontal                     SDO_Horizontal
  #define SDO_Vertical                       SDO_Vertical
  #define SDO_MAX                            SDO_MAX
  #define ESplitDirectionOptions_Horizontal  SDO_Horizontal
  #define ESplitDirectionOptions_Vertical    SDO_Vertical
  #define ESplitDirectionOptions_MAX         SDO_MAX
} ESplitDirectionOptions;
typedef enum EProfileColorBlindModeOptions : unsigned char {
  PCBMO_Invalid,                  // 0
  PCBMO_Off,                      // 1
  PCBMO_Deuteranopia,             // 2
  PCBMO_Protanopia,               // 3
  PCBMO_Tritanopia,               // 4
  PCBMO_MAX                       // 5
  #define PCBMO_Invalid                               PCBMO_Invalid
  #define PCBMO_Off                                   PCBMO_Off
  #define PCBMO_Deuteranopia                          PCBMO_Deuteranopia
  #define PCBMO_Protanopia                            PCBMO_Protanopia
  #define PCBMO_Tritanopia                            PCBMO_Tritanopia
  #define PCBMO_MAX                                   PCBMO_MAX
  #define EProfileColorBlindModeOptions_Invalid       PCBMO_Invalid
  #define EProfileColorBlindModeOptions_Off           PCBMO_Off
  #define EProfileColorBlindModeOptions_Deuteranopia  PCBMO_Deuteranopia
  #define EProfileColorBlindModeOptions_Protanopia    PCBMO_Protanopia
  #define EProfileColorBlindModeOptions_Tritanopia    PCBMO_Tritanopia
  #define EProfileColorBlindModeOptions_MAX           PCBMO_MAX
} EProfileColorBlindModeOptions;
#define EProfileViewDistanceOptions    EProfileViewDistanceOptions
#define EDecalSettingOptions           EDecalSettingOptions
#define ESplitDirectionOptions         ESplitDirectionOptions
#define EProfileColorBlindModeOptions  EProfileColorBlindModeOptions

/* ---------------------------------------------------------- UHUDWidget_Crosshairs ! ---------------------------------------------------------- */

typedef enum ECrosshairColor : unsigned char {
  ECC_None,                       // 0
  ECC_White,                      // 1
  ECC_Red,                        // 2
  ECC_Green,                      // 3
  ECC_MAX                         // 4
  #define ECC_None               ECC_None
  #define ECC_White              ECC_White
  #define ECC_Red                ECC_Red
  #define ECC_Green              ECC_Green
  #define ECC_MAX                ECC_MAX
  #define ECrosshairColor_None   ECC_None
  #define ECrosshairColor_White  ECC_White
  #define ECrosshairColor_Red    ECC_Red
  #define ECrosshairColor_Green  ECC_Green
  #define ECrosshairColor_MAX    ECC_MAX
} ECrosshairColor;
#define ECrosshairColor  ECrosshairColor

/* ---------------------------------------------------------- UUIRoot ! ---------------------------------------------------------- */

typedef enum EUIDataProviderFieldType : unsigned char {
  DATATYPE_Property,              // 0
  DATATYPE_Provider,              // 1
  DATATYPE_RangeProperty,         // 2
  DATATYPE_NetIdProperty,         // 3
  DATATYPE_Collection,            // 4
  DATATYPE_ProviderCollection,    // 5
  DATATYPE_MAX                    // 6
  #define DATATYPE_Property                            DATATYPE_Property
  #define DATATYPE_Provider                            DATATYPE_Provider
  #define DATATYPE_RangeProperty                       DATATYPE_RangeProperty
  #define DATATYPE_NetIdProperty                       DATATYPE_NetIdProperty
  #define DATATYPE_Collection                          DATATYPE_Collection
  #define DATATYPE_ProviderCollection                  DATATYPE_ProviderCollection
  #define DATATYPE_MAX                                 DATATYPE_MAX
  #define EUIDataProviderFieldType_Property            DATATYPE_Property
  #define EUIDataProviderFieldType_Provider            DATATYPE_Provider
  #define EUIDataProviderFieldType_RangeProperty       DATATYPE_RangeProperty
  #define EUIDataProviderFieldType_NetIdProperty       DATATYPE_NetIdProperty
  #define EUIDataProviderFieldType_Collection          DATATYPE_Collection
  #define EUIDataProviderFieldType_ProviderCollection  DATATYPE_ProviderCollection
  #define EUIDataProviderFieldType_MAX                 DATATYPE_MAX
} EUIDataProviderFieldType;
typedef enum EInputPlatformType       : unsigned char {
  IPT_PC,                         // 0
  IPT_360,                        // 1
  IPT_PS3,                        // 2
  IPT_MAX                         // 3
  #define IPT_PC                  IPT_PC
  #define IPT_360                 IPT_360
  #define IPT_PS3                 IPT_PS3
  #define IPT_MAX                 IPT_MAX
  #define EInputPlatformType_PC   IPT_PC
  #define EInputPlatformType_360  IPT_360
  #define EInputPlatformType_PS3  IPT_PS3
  #define EInputPlatformType_MAX  IPT_MAX
} EInputPlatformType;
#define EUIDataProviderFieldType  EUIDataProviderFieldType
#define EInputPlatformType        EInputPlatformType

/* ---------------------------------------------------------- UGFxMovieState ! ---------------------------------------------------------- */

typedef enum EMovieStateMode : unsigned char {
  MOVIESTATE_Any,                 // 0
  MOVIESTATE_StateMachine,        // 1
  MOVIESTATE_Flags,               // 2
  MOVIESTATE_Custom,              // 3
  MOVIESTATE_MAX                  // 4
  #define MOVIESTATE_Any                MOVIESTATE_Any
  #define MOVIESTATE_StateMachine       MOVIESTATE_StateMachine
  #define MOVIESTATE_Flags              MOVIESTATE_Flags
  #define MOVIESTATE_Custom             MOVIESTATE_Custom
  #define MOVIESTATE_MAX                MOVIESTATE_MAX
  #define EMovieStateMode_Any           MOVIESTATE_Any
  #define EMovieStateMode_StateMachine  MOVIESTATE_StateMachine
  #define EMovieStateMode_Flags         MOVIESTATE_Flags
  #define EMovieStateMode_Custom        MOVIESTATE_Custom
  #define EMovieStateMode_MAX           MOVIESTATE_MAX
} EMovieStateMode;
typedef enum EStateApplyMode : unsigned char {
  SAM_None,                       // 0
  SAM_GotoAndStop,                // 1
  SAM_GotoAndPlay,                // 2
  SAM_ActionScript,               // 3
  SAM_MAX                         // 4
  #define SAM_None                      SAM_None
  #define SAM_GotoAndStop               SAM_GotoAndStop
  #define SAM_GotoAndPlay               SAM_GotoAndPlay
  #define SAM_ActionScript              SAM_ActionScript
  #define SAM_MAX                       SAM_MAX
  #define EStateApplyMode_None          SAM_None
  #define EStateApplyMode_GotoAndStop   SAM_GotoAndStop
  #define EStateApplyMode_GotoAndPlay   SAM_GotoAndPlay
  #define EStateApplyMode_ActionScript  SAM_ActionScript
  #define EStateApplyMode_MAX           SAM_MAX
} EStateApplyMode;
#define EMovieStateMode  EMovieStateMode
#define EStateApplyMode  EStateApplyMode

/* ---------------------------------------------------------- UWillowGFxMovie ! ---------------------------------------------------------- */

typedef enum ERTTType : unsigned char {
  RTTT_Cell,                      // 0
  RTTT_HalfCell,                  // 1
  RTTT_Card,                      // 2
  RTTT_QuickSlot,                 // 3
  RTTT_MAX                        // 4
  #define RTTT_Cell           RTTT_Cell
  #define RTTT_HalfCell       RTTT_HalfCell
  #define RTTT_Card           RTTT_Card
  #define RTTT_QuickSlot      RTTT_QuickSlot
  #define RTTT_MAX            RTTT_MAX
  #define ERTTType_Cell       RTTT_Cell
  #define ERTTType_HalfCell   RTTT_HalfCell
  #define ERTTType_Card       RTTT_Card
  #define ERTTType_QuickSlot  RTTT_QuickSlot
  #define ERTTType_MAX        RTTT_MAX
} ERTTType;
#define ERTTType  ERTTType

/* ---------------------------------------------------------- UWillowGFxMovie3D ! ---------------------------------------------------------- */

typedef enum MovieFittingStyle : unsigned char {
  MFS_FitWithoutCropping,         // 0
  MFS_FitWithCropping,            // 1
  MFS_FitHorizontal,              // 2
  MFS_FitVertical,                // 3
  MFS_MAX                         // 4
  #define MFS_FitWithoutCropping                MFS_FitWithoutCropping
  #define MFS_FitWithCropping                   MFS_FitWithCropping
  #define MFS_FitHorizontal                     MFS_FitHorizontal
  #define MFS_FitVertical                       MFS_FitVertical
  #define MFS_MAX                               MFS_MAX
  #define MovieFittingStyle_FitWithoutCropping  MFS_FitWithoutCropping
  #define MovieFittingStyle_FitWithCropping     MFS_FitWithCropping
  #define MovieFittingStyle_FitHorizontal       MFS_FitHorizontal
  #define MovieFittingStyle_FitVertical         MFS_FitVertical
  #define MovieFittingStyle_MAX                 MFS_MAX
} MovieFittingStyle;
#define MovieFittingStyle  MovieFittingStyle

/* ---------------------------------------------------------- UWillowHUDGFxMovie ! ---------------------------------------------------------- */

typedef enum EAmmoBar : unsigned char {
  EAB_Default,                    // 0
  EAB_DualWieldLeft,              // 1
  EAB_DualWieldRight,             // 2
  EAB_MAX                         // 3
  #define EAB_Default              EAB_Default
  #define EAB_DualWieldLeft        EAB_DualWieldLeft
  #define EAB_DualWieldRight       EAB_DualWieldRight
  #define EAB_MAX                  EAB_MAX
  #define EAmmoBar_Default         EAB_Default
  #define EAmmoBar_DualWieldLeft   EAB_DualWieldLeft
  #define EAmmoBar_DualWieldRight  EAB_DualWieldRight
  #define EAmmoBar_MAX             EAB_MAX
} EAmmoBar;
#define EAmmoBar  EAmmoBar

/* ---------------------------------------------------------- UFiringModeDefinition ! ---------------------------------------------------------- */

typedef enum EWillowWeaponFireType : unsigned char {
  EWWFT_Bullet,                   // 0
  EWWFT_Beam,                     // 1
  EWWFT_Rocket,                   // 2
  EWWFT_HitScan,                  // 3
  EWWFT_MAX                       // 4
  #define EWWFT_Bullet                   EWWFT_Bullet
  #define EWWFT_Beam                     EWWFT_Beam
  #define EWWFT_Rocket                   EWWFT_Rocket
  #define EWWFT_HitScan                  EWWFT_HitScan
  #define EWWFT_MAX                      EWWFT_MAX
  #define EWillowWeaponFireType_Bullet   EWWFT_Bullet
  #define EWillowWeaponFireType_Beam     EWWFT_Beam
  #define EWillowWeaponFireType_Rocket   EWWFT_Rocket
  #define EWillowWeaponFireType_HitScan  EWWFT_HitScan
  #define EWillowWeaponFireType_MAX      EWWFT_MAX
} EWillowWeaponFireType;
typedef enum ELightBeamLock        : unsigned char {
  LBL_Never,                      // 0
  LBL_Always,                     // 1
  LBL_LockOn,                     // 2
  LBL_MAX                         // 3
  #define LBL_Never              LBL_Never
  #define LBL_Always             LBL_Always
  #define LBL_LockOn             LBL_LockOn
  #define LBL_MAX                LBL_MAX
  #define ELightBeamLock_Never   LBL_Never
  #define ELightBeamLock_Always  LBL_Always
  #define ELightBeamLock_LockOn  LBL_LockOn
  #define ELightBeamLock_MAX     LBL_MAX
} ELightBeamLock;
#define EWillowWeaponFireType  EWillowWeaponFireType
#define ELightBeamLock         ELightBeamLock

/* ---------------------------------------------------------- UITimerBehavior ! ---------------------------------------------------------- */

typedef enum EBehaviorTimerID    : unsigned char {
  BTIMER_1,                       // 0
  BTIMER_2,                       // 1
  BTIMER_3,                       // 2
  BTIMER_MAX                      // 3
  #define BTIMER_1              BTIMER_1
  #define BTIMER_2              BTIMER_2
  #define BTIMER_3              BTIMER_3
  #define BTIMER_MAX            BTIMER_MAX
  #define EBehaviorTimerID_1    BTIMER_1
  #define EBehaviorTimerID_2    BTIMER_2
  #define EBehaviorTimerID_3    BTIMER_3
  #define EBehaviorTimerID_MAX  BTIMER_MAX
} EBehaviorTimerID;
typedef enum EBehaviorTimerEvent : unsigned char {
  TIMEREVENT_Timer1Elapsed,       // 0
  TIMEREVENT_Timer2Elapsed,       // 1
  TIMEREVENT_Timer3Elapsed,       // 2
  TIMEREVENT_MAX                  // 3
  #define TIMEREVENT_Timer1Elapsed           TIMEREVENT_Timer1Elapsed
  #define TIMEREVENT_Timer2Elapsed           TIMEREVENT_Timer2Elapsed
  #define TIMEREVENT_Timer3Elapsed           TIMEREVENT_Timer3Elapsed
  #define TIMEREVENT_MAX                     TIMEREVENT_MAX
  #define EBehaviorTimerEvent_Timer1Elapsed  TIMEREVENT_Timer1Elapsed
  #define EBehaviorTimerEvent_Timer2Elapsed  TIMEREVENT_Timer2Elapsed
  #define EBehaviorTimerEvent_Timer3Elapsed  TIMEREVENT_Timer3Elapsed
  #define EBehaviorTimerEvent_MAX            TIMEREVENT_MAX
} EBehaviorTimerEvent;
#define EBehaviorTimerID     EBehaviorTimerID
#define EBehaviorTimerEvent  EBehaviorTimerEvent

/* ---------------------------------------------------------- UForceFeedbackWaveform ! ---------------------------------------------------------- */

typedef enum EWaveformFunction : unsigned char {
  WF_Constant,                    // 0
  WF_LinearIncreasing,            // 1
  WF_LinearDecreasing,            // 2
  WF_Sin0to90,                    // 3
  WF_Sin90to180,                  // 4
  WF_Sin0to180,                   // 5
  WF_Noise,                       // 6
  WF_MAX                          // 7
  #define WF_Constant                         WF_Constant
  #define WF_LinearIncreasing                 WF_LinearIncreasing
  #define WF_LinearDecreasing                 WF_LinearDecreasing
  #define WF_Sin0to90                         WF_Sin0to90
  #define WF_Sin90to180                       WF_Sin90to180
  #define WF_Sin0to180                        WF_Sin0to180
  #define WF_Noise                            WF_Noise
  #define WF_MAX                              WF_MAX
  #define EWaveformFunction_Constant          WF_Constant
  #define EWaveformFunction_LinearIncreasing  WF_LinearIncreasing
  #define EWaveformFunction_LinearDecreasing  WF_LinearDecreasing
  #define EWaveformFunction_Sin0to90          WF_Sin0to90
  #define EWaveformFunction_Sin90to180        WF_Sin90to180
  #define EWaveformFunction_Sin0to180         WF_Sin0to180
  #define EWaveformFunction_Noise             WF_Noise
  #define EWaveformFunction_MAX               WF_MAX
} EWaveformFunction;
#define EWaveformFunction  EWaveformFunction

/* ---------------------------------------------------------- UWillowGameViewportClient ! ---------------------------------------------------------- */

typedef enum EDeviceSelectionState : unsigned char {
  EDSS_None,                      // 0
  EDSS_Pending,                   // 1
  EDSS_Succeeded,                 // 2
  EDSS_Failed,                    // 3
  EDSS_MAX                        // 4
  #define EDSS_None                        EDSS_None
  #define EDSS_Pending                     EDSS_Pending
  #define EDSS_Succeeded                   EDSS_Succeeded
  #define EDSS_Failed                      EDSS_Failed
  #define EDSS_MAX                         EDSS_MAX
  #define EDeviceSelectionState_None       EDSS_None
  #define EDeviceSelectionState_Pending    EDSS_Pending
  #define EDeviceSelectionState_Succeeded  EDSS_Succeeded
  #define EDeviceSelectionState_Failed     EDSS_Failed
  #define EDeviceSelectionState_MAX        EDSS_MAX
} EDeviceSelectionState;
#define EDeviceSelectionState  EDeviceSelectionState

/* ---------------------------------------------------------- UBehaviorProviderDefinition ! ---------------------------------------------------------- */

typedef enum EBehaviorVariableLinkType : unsigned char {
  BVARLINK_Unknown,               // 0
  BVARLINK_Context,               // 1
  BVARLINK_Input,                 // 2
  BVARLINK_Output,                // 3
  BVARLINK_MAX                    // 4
  #define BVARLINK_Unknown                   BVARLINK_Unknown
  #define BVARLINK_Context                   BVARLINK_Context
  #define BVARLINK_Input                     BVARLINK_Input
  #define BVARLINK_Output                    BVARLINK_Output
  #define BVARLINK_MAX                       BVARLINK_MAX
  #define EBehaviorVariableLinkType_Unknown  BVARLINK_Unknown
  #define EBehaviorVariableLinkType_Context  BVARLINK_Context
  #define EBehaviorVariableLinkType_Input    BVARLINK_Input
  #define EBehaviorVariableLinkType_Output   BVARLINK_Output
  #define EBehaviorVariableLinkType_MAX      BVARLINK_MAX
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
  #define BVAR_None                                  BVAR_None
  #define BVAR_Bool                                  BVAR_Bool
  #define BVAR_Int                                   BVAR_Int
  #define BVAR_Float                                 BVAR_Float
  #define BVAR_Vector                                BVAR_Vector
  #define BVAR_Object                                BVAR_Object
  #define BVAR_AllPlayers                            BVAR_AllPlayers
  #define BVAR_Attribute                             BVAR_Attribute
  #define BVAR_InstanceData                          BVAR_InstanceData
  #define BVAR_NamedVariable                         BVAR_NamedVariable
  #define BVAR_NamedKismetVariable                   BVAR_NamedKismetVariable
  #define BVAR_DirectionVector                       BVAR_DirectionVector
  #define BVAR_AttachmentLocation                    BVAR_AttachmentLocation
  #define BVAR_UnaryMath                             BVAR_UnaryMath
  #define BVAR_BinaryMath                            BVAR_BinaryMath
  #define BVAR_Flag                                  BVAR_Flag
  #define BVAR_MAX                                   BVAR_MAX
  #define EBehaviorVariableType_None                 BVAR_None
  #define EBehaviorVariableType_Bool                 BVAR_Bool
  #define EBehaviorVariableType_Int                  BVAR_Int
  #define EBehaviorVariableType_Float                BVAR_Float
  #define EBehaviorVariableType_Vector               BVAR_Vector
  #define EBehaviorVariableType_Object               BVAR_Object
  #define EBehaviorVariableType_AllPlayers           BVAR_AllPlayers
  #define EBehaviorVariableType_Attribute            BVAR_Attribute
  #define EBehaviorVariableType_InstanceData         BVAR_InstanceData
  #define EBehaviorVariableType_NamedVariable        BVAR_NamedVariable
  #define EBehaviorVariableType_NamedKismetVariable  BVAR_NamedKismetVariable
  #define EBehaviorVariableType_DirectionVector      BVAR_DirectionVector
  #define EBehaviorVariableType_AttachmentLocation   BVAR_AttachmentLocation
  #define EBehaviorVariableType_UnaryMath            BVAR_UnaryMath
  #define EBehaviorVariableType_BinaryMath           BVAR_BinaryMath
  #define EBehaviorVariableType_Flag                 BVAR_Flag
  #define EBehaviorVariableType_MAX                  BVAR_MAX
} EBehaviorVariableType;
#define EBehaviorVariableLinkType  EBehaviorVariableLinkType
#define EBehaviorVariableType      EBehaviorVariableType

/* ---------------------------------------------------------- UAttributePresentationDefinition ! ---------------------------------------------------------- */

typedef enum EAttributeValueSignStyle : unsigned char {
  SIGNSTYLE_AsIs,                 // 0
  SIGNSTYLE_Positive,             // 1
  SIGNSTYLE_Negative,             // 2
  SIGNSTYLE_AsIsAnyStyle,         // 3
  SIGNSTYLE_OppositeSign,         // 4
  SIGNSTYLE_MAX                   // 5
  #define SIGNSTYLE_AsIs                         SIGNSTYLE_AsIs
  #define SIGNSTYLE_Positive                     SIGNSTYLE_Positive
  #define SIGNSTYLE_Negative                     SIGNSTYLE_Negative
  #define SIGNSTYLE_AsIsAnyStyle                 SIGNSTYLE_AsIsAnyStyle
  #define SIGNSTYLE_OppositeSign                 SIGNSTYLE_OppositeSign
  #define SIGNSTYLE_MAX                          SIGNSTYLE_MAX
  #define EAttributeValueSignStyle_AsIs          SIGNSTYLE_AsIs
  #define EAttributeValueSignStyle_Positive      SIGNSTYLE_Positive
  #define EAttributeValueSignStyle_Negative      SIGNSTYLE_Negative
  #define EAttributeValueSignStyle_AsIsAnyStyle  SIGNSTYLE_AsIsAnyStyle
  #define EAttributeValueSignStyle_OppositeSign  SIGNSTYLE_OppositeSign
  #define EAttributeValueSignStyle_MAX           SIGNSTYLE_MAX
} EAttributeValueSignStyle;
#define EAttributeValueSignStyle  EAttributeValueSignStyle

/* ---------------------------------------------------------- UWillowItemTypes ! ---------------------------------------------------------- */

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
  #define IP_Alpha                IP_Alpha
  #define IP_Beta                 IP_Beta
  #define IP_Gamma                IP_Gamma
  #define IP_Delta                IP_Delta
  #define IP_Epsilon              IP_Epsilon
  #define IP_Zeta                 IP_Zeta
  #define IP_Eta                  IP_Eta
  #define IP_Theta                IP_Theta
  #define IP_Material             IP_Material
  #define IP_Prefix               IP_Prefix
  #define IP_Title                IP_Title
  #define IP_MAX                  IP_MAX
  #define EItemPartType_Alpha     IP_Alpha
  #define EItemPartType_Beta      IP_Beta
  #define EItemPartType_Gamma     IP_Gamma
  #define EItemPartType_Delta     IP_Delta
  #define EItemPartType_Epsilon   IP_Epsilon
  #define EItemPartType_Zeta      IP_Zeta
  #define EItemPartType_Eta       IP_Eta
  #define EItemPartType_Theta     IP_Theta
  #define EItemPartType_Material  IP_Material
  #define EItemPartType_Prefix    IP_Prefix
  #define EItemPartType_Title     IP_Title
  #define EItemPartType_MAX       IP_MAX
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
  #define FCI_None                     FCI_None
  #define FCI_Weapon                   FCI_Weapon
  #define FCI_Shield                   FCI_Shield
  #define FCI_GrenadeMod               FCI_GrenadeMod
  #define FCI_ClassMod                 FCI_ClassMod
  #define FCI_Item                     FCI_Item
  #define FCI_Blank                    FCI_Blank
  #define FCI_Artifact                 FCI_Artifact
  #define FCI_MissionItem              FCI_MissionItem
  #define FCI_MAX                      FCI_MAX
  #define EFlashCardIndex_None         FCI_None
  #define EFlashCardIndex_Weapon       FCI_Weapon
  #define EFlashCardIndex_Shield       FCI_Shield
  #define EFlashCardIndex_GrenadeMod   FCI_GrenadeMod
  #define EFlashCardIndex_ClassMod     FCI_ClassMod
  #define EFlashCardIndex_Item         FCI_Item
  #define EFlashCardIndex_Blank        FCI_Blank
  #define EFlashCardIndex_Artifact     FCI_Artifact
  #define EFlashCardIndex_MissionItem  FCI_MissionItem
  #define EFlashCardIndex_MAX          FCI_MAX
} EFlashCardIndex;
#define EItemPartType    EItemPartType
#define EFlashCardIndex  EFlashCardIndex

/* ---------------------------------------------------------- UStatusMenuExGFxMovie ! ---------------------------------------------------------- */

typedef enum ECellState : unsigned char {
  CELL_Selected,                  // 0
  CELL_Both,                      // 1
  CELL_Normal,                    // 2
  CELL_Highlight,                 // 3
  CELL_Locked,                    // 4
  CELL_MAX                        // 5
  #define CELL_Selected         CELL_Selected
  #define CELL_Both             CELL_Both
  #define CELL_Normal           CELL_Normal
  #define CELL_Highlight        CELL_Highlight
  #define CELL_Locked           CELL_Locked
  #define CELL_MAX              CELL_MAX
  #define ECellState_Selected   CELL_Selected
  #define ECellState_Both       CELL_Both
  #define ECellState_Normal     CELL_Normal
  #define ECellState_Highlight  CELL_Highlight
  #define ECellState_Locked     CELL_Locked
  #define ECellState_MAX        CELL_MAX
} ECellState;
#define ECellState  ECellState

/* ---------------------------------------------------------- UWillowDeclarations ! ---------------------------------------------------------- */

typedef enum EQuickWeaponSlot        : unsigned char {
  QuickSelectNone,                // 0
  QuickSelectUp,                  // 1
  QuickSelectDown,                // 2
  QuickSelectLeft,                // 3
  QuickSelectRight,               // 4
  EQuickWeaponSlot_MAX            // 5
  #define QuickSelectNone         QuickSelectNone
  #define QuickSelectUp           QuickSelectUp
  #define QuickSelectDown         QuickSelectDown
  #define QuickSelectLeft         QuickSelectLeft
  #define QuickSelectRight        QuickSelectRight
  #define EQuickWeaponSlot_None   QuickSelectNone
  #define EQuickWeaponSlot_Up     QuickSelectUp
  #define EQuickWeaponSlot_Down   QuickSelectDown
  #define EQuickWeaponSlot_Left   QuickSelectLeft
  #define EQuickWeaponSlot_Right  QuickSelectRight
  #define EQuickWeaponSlot_MAX    EQuickWeaponSlot_MAX
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
  #define ESPB_Inventory                       ESPB_Inventory
  #define ESPB_Health                          ESPB_Health
  #define ESPB_Weapons                         ESPB_Weapons
  #define ESPB_Ammo                            ESPB_Ammo
  #define ESPB_Bank                            ESPB_Bank
  #define ESPB_Stash                           ESPB_Stash
  #define EPSB_Blackmarket                     EPSB_Blackmarket
  #define EPSB_Custom                          EPSB_Custom
  #define EStoragePanelBackground_Inventory    ESPB_Inventory
  #define EStoragePanelBackground_Health       ESPB_Health
  #define EStoragePanelBackground_Weapons      ESPB_Weapons
  #define EStoragePanelBackground_Ammo         ESPB_Ammo
  #define EStoragePanelBackground_Bank         ESPB_Bank
  #define EStoragePanelBackground_Stash        ESPB_Stash
  #define EStoragePanelBackground_Blackmarket  EPSB_Blackmarket
  #define EStoragePanelBackground_Custom       EPSB_Custom
  #define EStoragePanelBackground_MAX          EStoragePanelBackground_MAX
} EStoragePanelBackground;
typedef enum EEquipmentLoc           : unsigned char {
  EQUIPLOC_Shield,                // 0
  EQUIPLOC_GrenadeMod,            // 1
  EQUIPLOC_ClassMod,              // 2
  EQUIPLOC_Artifact,              // 3
  EQUIPLOC_None,                  // 4
  EQUIPLOC_MAX                    // 5
  #define EQUIPLOC_Shield           EQUIPLOC_Shield
  #define EQUIPLOC_GrenadeMod       EQUIPLOC_GrenadeMod
  #define EQUIPLOC_ClassMod         EQUIPLOC_ClassMod
  #define EQUIPLOC_Artifact         EQUIPLOC_Artifact
  #define EQUIPLOC_None             EQUIPLOC_None
  #define EQUIPLOC_MAX              EQUIPLOC_MAX
  #define EEquipmentLoc_Shield      EQUIPLOC_Shield
  #define EEquipmentLoc_GrenadeMod  EQUIPLOC_GrenadeMod
  #define EEquipmentLoc_ClassMod    EQUIPLOC_ClassMod
  #define EEquipmentLoc_Artifact    EQUIPLOC_Artifact
  #define EEquipmentLoc_None        EQUIPLOC_None
  #define EEquipmentLoc_MAX         EQUIPLOC_MAX
} EEquipmentLoc;
typedef enum ERewardPopup            : unsigned char {
  ERP_BadassToken,                // 0
  ERP_CharacterHead,              // 1
  ERP_CharacterSkin,              // 2
  ERP_VehicleSkin,                // 3
  ERP_MAX                         // 4
  #define ERP_BadassToken             ERP_BadassToken
  #define ERP_CharacterHead           ERP_CharacterHead
  #define ERP_CharacterSkin           ERP_CharacterSkin
  #define ERP_VehicleSkin             ERP_VehicleSkin
  #define ERP_MAX                     ERP_MAX
  #define ERewardPopup_BadassToken    ERP_BadassToken
  #define ERewardPopup_CharacterHead  ERP_CharacterHead
  #define ERewardPopup_CharacterSkin  ERP_CharacterSkin
  #define ERewardPopup_VehicleSkin    ERP_VehicleSkin
  #define ERewardPopup_MAX            ERP_MAX
} ERewardPopup;
#define EQuickWeaponSlot         EQuickWeaponSlot
#define EStoragePanelBackground  EStoragePanelBackground
#define EEquipmentLoc            EEquipmentLoc
#define ERewardPopup             ERewardPopup

/* ---------------------------------------------------------- UBaseTopLevelPanelGFxObject ! ---------------------------------------------------------- */

typedef enum PanelPosition : unsigned char {
  PP_Focused,                     // 0
  PP_Unfocused,                   // 1
  PP_Compare,                     // 2
  PP_MAX                          // 3
  #define PP_Focused               PP_Focused
  #define PP_Unfocused             PP_Unfocused
  #define PP_Compare               PP_Compare
  #define PP_MAX                   PP_MAX
  #define PanelPosition_Focused    PP_Focused
  #define PanelPosition_Unfocused  PP_Unfocused
  #define PanelPosition_Compare    PP_Compare
  #define PanelPosition_MAX        PP_MAX
} PanelPosition;
#define PanelPosition  PanelPosition

/* ---------------------------------------------------------- UStatusMenuInventoryPanelGFxObject ! ---------------------------------------------------------- */

typedef enum EInventoryPanel : unsigned char {
  EIP_Backpack,                   // 0
  EIP_Equipped,                   // 1
  EIP_MAX                         // 2
  #define EIP_Backpack              EIP_Backpack
  #define EIP_Equipped              EIP_Equipped
  #define EIP_MAX                   EIP_MAX
  #define EInventoryPanel_Backpack  EIP_Backpack
  #define EInventoryPanel_Equipped  EIP_Equipped
  #define EInventoryPanel_MAX       EIP_MAX
} EInventoryPanel;
#define EInventoryPanel  EInventoryPanel

/* ---------------------------------------------------------- UGearboxGlobals ! ---------------------------------------------------------- */

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
  #define MOVEFINISHED_None                                  MOVEFINISHED_None
  #define MOVEFINISHED_FailedToFindCover                     MOVEFINISHED_FailedToFindCover
  #define MOVEFINISHED_FailedFindSearchOrigin                MOVEFINISHED_FailedFindSearchOrigin
  #define MOVEFINISHED_FailedFindSearchDirection             MOVEFINISHED_FailedFindSearchDirection
  #define MOVEFINISHED_FailedFindNavMeshSpot                 MOVEFINISHED_FailedFindNavMeshSpot
  #define MOVEFINISHED_FailedToGeneratePath                  MOVEFINISHED_FailedToGeneratePath
  #define MOVEFINISHED_FailedToCompleteNavigation            MOVEFINISHED_FailedToCompleteNavigation
  #define MOVEFINISHED_Repath                                MOVEFINISHED_Repath
  #define MOVEFINISHED_MovementInterrupted                   MOVEFINISHED_MovementInterrupted
  #define MOVEFINISHED_MoveSuccessfullyEnded                 MOVEFINISHED_MoveSuccessfullyEnded
  #define MOVEFINISHED_MAX                                   MOVEFINISHED_MAX
  #define EMovementFinishedCause_None                        MOVEFINISHED_None
  #define EMovementFinishedCause_FailedToFindCover           MOVEFINISHED_FailedToFindCover
  #define EMovementFinishedCause_FailedFindSearchOrigin      MOVEFINISHED_FailedFindSearchOrigin
  #define EMovementFinishedCause_FailedFindSearchDirection   MOVEFINISHED_FailedFindSearchDirection
  #define EMovementFinishedCause_FailedFindNavMeshSpot       MOVEFINISHED_FailedFindNavMeshSpot
  #define EMovementFinishedCause_FailedToGeneratePath        MOVEFINISHED_FailedToGeneratePath
  #define EMovementFinishedCause_FailedToCompleteNavigation  MOVEFINISHED_FailedToCompleteNavigation
  #define EMovementFinishedCause_Repath                      MOVEFINISHED_Repath
  #define EMovementFinishedCause_MovementInterrupted         MOVEFINISHED_MovementInterrupted
  #define EMovementFinishedCause_MoveSuccessfullyEnded       MOVEFINISHED_MoveSuccessfullyEnded
  #define EMovementFinishedCause_MAX                         MOVEFINISHED_MAX
} EMovementFinishedCause;
typedef enum EMovementSpeed             : unsigned char {
  MOVESPEED_Stationary,           // 0
  MOVESPEED_Walking,              // 1
  MOVESPEED_Running,              // 2
  MOVESPEED_Sprinting,            // 3
  MOVESPEED_FastSprinting,        // 4
  MOVESPEED_MAX                   // 5
  #define MOVESPEED_Stationary          MOVESPEED_Stationary
  #define MOVESPEED_Walking             MOVESPEED_Walking
  #define MOVESPEED_Running             MOVESPEED_Running
  #define MOVESPEED_Sprinting           MOVESPEED_Sprinting
  #define MOVESPEED_FastSprinting       MOVESPEED_FastSprinting
  #define MOVESPEED_MAX                 MOVESPEED_MAX
  #define EMovementSpeed_Stationary     MOVESPEED_Stationary
  #define EMovementSpeed_Walking        MOVESPEED_Walking
  #define EMovementSpeed_Running        MOVESPEED_Running
  #define EMovementSpeed_Sprinting      MOVESPEED_Sprinting
  #define EMovementSpeed_FastSprinting  MOVESPEED_FastSprinting
  #define EMovementSpeed_MAX            MOVESPEED_MAX
} EMovementSpeed;
typedef enum EFacingPolicy              : unsigned char {
  FACE_Unknown,                   // 0
  FACE_NoChange,                  // 1
  FACE_Actor,                     // 2
  FACE_Vector,                    // 3
  FACE_Destination,               // 4
  FACE_CoverRegionIdle,           // 5
  FACE_MAX                        // 6
  #define FACE_Unknown                   FACE_Unknown
  #define FACE_NoChange                  FACE_NoChange
  #define FACE_Actor                     FACE_Actor
  #define FACE_Vector                    FACE_Vector
  #define FACE_Destination               FACE_Destination
  #define FACE_CoverRegionIdle           FACE_CoverRegionIdle
  #define FACE_MAX                       FACE_MAX
  #define EFacingPolicy_Unknown          FACE_Unknown
  #define EFacingPolicy_NoChange         FACE_NoChange
  #define EFacingPolicy_Actor            FACE_Actor
  #define EFacingPolicy_Vector           FACE_Vector
  #define EFacingPolicy_Destination      FACE_Destination
  #define EFacingPolicy_CoverRegionIdle  FACE_CoverRegionIdle
  #define EFacingPolicy_MAX              FACE_MAX
} EFacingPolicy;
typedef enum ECameraInterpolationMode   : unsigned char {
  IM_Logarithmic,                 // 0
  IM_Linear,                      // 1
  IM_SineCurve,                   // 2
  IM_MAX                          // 3
  #define IM_Logarithmic                        IM_Logarithmic
  #define IM_Linear                             IM_Linear
  #define IM_SineCurve                          IM_SineCurve
  #define IM_MAX                                IM_MAX
  #define IM_Logarithmic                        IM_Logarithmic
  #define IM_Linear                             IM_Linear
  #define IM_SineCurve                          IM_SineCurve
  #define IM_MAX                                IM_MAX
  #define ECameraInterpolationMode_Logarithmic  IM_Logarithmic
  #define ECameraInterpolationMode_Linear       IM_Linear
  #define ECameraInterpolationMode_SineCurve    IM_SineCurve
  #define ECameraInterpolationMode_MAX          IM_MAX
  #define ECameraInterpolationMode_Logarithmic  IM_Logarithmic
  #define ECameraInterpolationMode_Linear       IM_Linear
  #define ECameraInterpolationMode_SineCurve    IM_SineCurve
  #define ECameraInterpolationMode_MAX          IM_MAX
} ECameraInterpolationMode;
typedef enum ECameraZoomScale           : unsigned char {
  EZOOM_NoChange,                 // 0
  EZOOM_UltraClose,               // 1
  EZOOM_Close,                    // 2
  EZOOM_MidRange,                 // 3
  EZOOM_Wide,                     // 4
  EZOOM_MAX                       // 5
  #define EZOOM_NoChange               EZOOM_NoChange
  #define EZOOM_UltraClose             EZOOM_UltraClose
  #define EZOOM_Close                  EZOOM_Close
  #define EZOOM_MidRange               EZOOM_MidRange
  #define EZOOM_Wide                   EZOOM_Wide
  #define EZOOM_MAX                    EZOOM_MAX
  #define ECameraZoomScale_NoChange    EZOOM_NoChange
  #define ECameraZoomScale_UltraClose  EZOOM_UltraClose
  #define ECameraZoomScale_Close       EZOOM_Close
  #define ECameraZoomScale_MidRange    EZOOM_MidRange
  #define ECameraZoomScale_Wide        EZOOM_Wide
  #define ECameraZoomScale_MAX         EZOOM_MAX
} ECameraZoomScale;
typedef enum EMaterialParamType         : unsigned char {
  MatParmType_None,               // 0
  MatParmType_Color,              // 1
  MatParmType_Font,               // 2
  MatParmType_Scalar,             // 3
  MatParmType_Texture,            // 4
  MatParmType_Vector,             // 5
  MatParmType_MAX                 // 6
  #define MatParmType_None            MatParmType_None
  #define MatParmType_Color           MatParmType_Color
  #define MatParmType_Font            MatParmType_Font
  #define MatParmType_Scalar          MatParmType_Scalar
  #define MatParmType_Texture         MatParmType_Texture
  #define MatParmType_Vector          MatParmType_Vector
  #define MatParmType_MAX             MatParmType_MAX
  #define EMaterialParamType_None     MatParmType_None
  #define EMaterialParamType_Color    MatParmType_Color
  #define EMaterialParamType_Font     MatParmType_Font
  #define EMaterialParamType_Scalar   MatParmType_Scalar
  #define EMaterialParamType_Texture  MatParmType_Texture
  #define EMaterialParamType_Vector   MatParmType_Vector
  #define EMaterialParamType_MAX      MatParmType_MAX
} EMaterialParamType;
typedef enum EDifficultyLevel           : unsigned char {
  DL_Casual,                      // 0
  DL_Normal,                      // 1
  DL_Hardcore,                    // 2
  DL_Insane,                      // 3
  DL_MAX                          // 4
  #define DL_Casual                  DL_Casual
  #define DL_Normal                  DL_Normal
  #define DL_Hardcore                DL_Hardcore
  #define DL_Insane                  DL_Insane
  #define DL_MAX                     DL_MAX
  #define EDifficultyLevel_Casual    DL_Casual
  #define EDifficultyLevel_Normal    DL_Normal
  #define EDifficultyLevel_Hardcore  DL_Hardcore
  #define EDifficultyLevel_Insane    DL_Insane
  #define EDifficultyLevel_MAX       DL_MAX
} EDifficultyLevel;
typedef enum EGBXPlatform               : unsigned char {
  GBXPlatform_PC,                 // 0
  GBXPlatform_360,                // 1
  GBXPlatform_PS3,                // 2
  GBXPlatform_MAX                 // 3
  #define GBXPlatform_PC    GBXPlatform_PC
  #define GBXPlatform_360   GBXPlatform_360
  #define GBXPlatform_PS3   GBXPlatform_PS3
  #define GBXPlatform_MAX   GBXPlatform_MAX
  #define EGBXPlatform_PC   GBXPlatform_PC
  #define EGBXPlatform_360  GBXPlatform_360
  #define EGBXPlatform_PS3  GBXPlatform_PS3
  #define EGBXPlatform_MAX  GBXPlatform_MAX
} EGBXPlatform;
typedef enum EVantageType               : unsigned char {
  VTYPE_Normal,                   // 0
  VTYPE_StandingUp,               // 1
  VTYPE_OverWall,                 // 2
  VTYPE_AroundCorner,             // 3
  VTYPE_MAX                       // 4
  #define VTYPE_Normal               VTYPE_Normal
  #define VTYPE_StandingUp           VTYPE_StandingUp
  #define VTYPE_OverWall             VTYPE_OverWall
  #define VTYPE_AroundCorner         VTYPE_AroundCorner
  #define VTYPE_MAX                  VTYPE_MAX
  #define EVantageType_Normal        VTYPE_Normal
  #define EVantageType_StandingUp    VTYPE_StandingUp
  #define EVantageType_OverWall      VTYPE_OverWall
  #define EVantageType_AroundCorner  VTYPE_AroundCorner
  #define EVantageType_MAX           VTYPE_MAX
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
  #define AWAREREASON_SawEnemy                 AWAREREASON_SawEnemy
  #define AWAREREASON_HeardEnemy               AWAREREASON_HeardEnemy
  #define AWAREREASON_HeardWeaponNoise         AWAREREASON_HeardWeaponNoise
  #define AWAREREASON_NotifiedByFireTeam       AWAREREASON_NotifiedByFireTeam
  #define AWAREREASON_NotifiedByPlayer         AWAREREASON_NotifiedByPlayer
  #define AWAREREASON_SuppressOrderGiven       AWAREREASON_SuppressOrderGiven
  #define AWAREREASON_AttackedByEnemy          AWAREREASON_AttackedByEnemy
  #define AWAREREASON_BulletImpactOrWhiz       AWAREREASON_BulletImpactOrWhiz
  #define AWAREREASON_GrenadeFromEnemy         AWAREREASON_GrenadeFromEnemy
  #define AWAREREASON_LevelDesignForceSee      AWAREREASON_LevelDesignForceSee
  #define AWAREREASON_FriendlyKilled           AWAREREASON_FriendlyKilled
  #define AWAREREASON_MAX                      AWAREREASON_MAX
  #define AwarenessReason_SawEnemy             AWAREREASON_SawEnemy
  #define AwarenessReason_HeardEnemy           AWAREREASON_HeardEnemy
  #define AwarenessReason_HeardWeaponNoise     AWAREREASON_HeardWeaponNoise
  #define AwarenessReason_NotifiedByFireTeam   AWAREREASON_NotifiedByFireTeam
  #define AwarenessReason_NotifiedByPlayer     AWAREREASON_NotifiedByPlayer
  #define AwarenessReason_SuppressOrderGiven   AWAREREASON_SuppressOrderGiven
  #define AwarenessReason_AttackedByEnemy      AWAREREASON_AttackedByEnemy
  #define AwarenessReason_BulletImpactOrWhiz   AWAREREASON_BulletImpactOrWhiz
  #define AwarenessReason_GrenadeFromEnemy     AWAREREASON_GrenadeFromEnemy
  #define AwarenessReason_LevelDesignForceSee  AWAREREASON_LevelDesignForceSee
  #define AwarenessReason_FriendlyKilled       AWAREREASON_FriendlyKilled
  #define AwarenessReason_MAX                  AWAREREASON_MAX
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
  #define GBXCOVERSTATE_Uncovered          GBXCOVERSTATE_Uncovered
  #define GBXCOVERSTATE_Covered            GBXCOVERSTATE_Covered
  #define GBXCOVERSTATE_PoppedUp           GBXCOVERSTATE_PoppedUp
  #define GBXCOVERSTATE_LeanedOut          GBXCOVERSTATE_LeanedOut
  #define GBXCOVERSTATE_Peeking            GBXCOVERSTATE_Peeking
  #define GBXCOVERSTATE_BlindFiring        GBXCOVERSTATE_BlindFiring
  #define GBXCOVERSTATE_Mantling           GBXCOVERSTATE_Mantling
  #define GBXCOVERSTATE_GameSpecific       GBXCOVERSTATE_GameSpecific
  #define GBXCOVERSTATE_Reserved1          GBXCOVERSTATE_Reserved1
  #define GBXCOVERSTATE_Reserved2          GBXCOVERSTATE_Reserved2
  #define GBXCOVERSTATE_Reserved3          GBXCOVERSTATE_Reserved3
  #define GBXCOVERSTATE_Reserved4          GBXCOVERSTATE_Reserved4
  #define GBXCOVERSTATE_Reserved5          GBXCOVERSTATE_Reserved5
  #define GBXCOVERSTATE_Reserved6          GBXCOVERSTATE_Reserved6
  #define GBXCOVERSTATE_Reserved7          GBXCOVERSTATE_Reserved7
  #define GBXCOVERSTATE_Reserved8          GBXCOVERSTATE_Reserved8
  #define GBXCOVERSTATE_Reserved9          GBXCOVERSTATE_Reserved9
  #define GBXCOVERSTATE_MAX                GBXCOVERSTATE_MAX
  #define EGearboxCoverState_Uncovered     GBXCOVERSTATE_Uncovered
  #define EGearboxCoverState_Covered       GBXCOVERSTATE_Covered
  #define EGearboxCoverState_PoppedUp      GBXCOVERSTATE_PoppedUp
  #define EGearboxCoverState_LeanedOut     GBXCOVERSTATE_LeanedOut
  #define EGearboxCoverState_Peeking       GBXCOVERSTATE_Peeking
  #define EGearboxCoverState_BlindFiring   GBXCOVERSTATE_BlindFiring
  #define EGearboxCoverState_Mantling      GBXCOVERSTATE_Mantling
  #define EGearboxCoverState_GameSpecific  GBXCOVERSTATE_GameSpecific
  #define EGearboxCoverState_Reserved1     GBXCOVERSTATE_Reserved1
  #define EGearboxCoverState_Reserved2     GBXCOVERSTATE_Reserved2
  #define EGearboxCoverState_Reserved3     GBXCOVERSTATE_Reserved3
  #define EGearboxCoverState_Reserved4     GBXCOVERSTATE_Reserved4
  #define EGearboxCoverState_Reserved5     GBXCOVERSTATE_Reserved5
  #define EGearboxCoverState_Reserved6     GBXCOVERSTATE_Reserved6
  #define EGearboxCoverState_Reserved7     GBXCOVERSTATE_Reserved7
  #define EGearboxCoverState_Reserved8     GBXCOVERSTATE_Reserved8
  #define EGearboxCoverState_Reserved9     GBXCOVERSTATE_Reserved9
  #define EGearboxCoverState_MAX           GBXCOVERSTATE_MAX
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
  #define GBXCOVERMETA_None                                        GBXCOVERMETA_None
  #define GBXCOVERMETA_Detach                                      GBXCOVERMETA_Detach
  #define GBXCOVERMETA_Left                                        GBXCOVERMETA_Left
  #define GBXCOVERMETA_Right                                       GBXCOVERMETA_Right
  #define GBXCOVERMETA_Interior                                    GBXCOVERMETA_Interior
  #define GBXCOVERMETA_Dismount_SurpriseLeft                       GBXCOVERMETA_Dismount_SurpriseLeft
  #define GBXCOVERMETA_Dismount_SurpriseRight                      GBXCOVERMETA_Dismount_SurpriseRight
  #define GBXCOVERMETA_Dismount_SurpriseTowardCover                GBXCOVERMETA_Dismount_SurpriseTowardCover
  #define GBXCOVERMETA_Dismount_SurpriseWith180Turn                GBXCOVERMETA_Dismount_SurpriseWith180Turn
  #define GBXCOVERMETA_Dismount_Wallhop                            GBXCOVERMETA_Dismount_Wallhop
  #define GBXCOVERMETA_Dismount_TowardCover                        GBXCOVERMETA_Dismount_TowardCover
  #define GBXCOVERMETA_Dismount_With180Turn                        GBXCOVERMETA_Dismount_With180Turn
  #define GBXCOVERMETA_GameSpecific                                GBXCOVERMETA_GameSpecific
  #define GBXCOVERMETA_Reserved1                                   GBXCOVERMETA_Reserved1
  #define GBXCOVERMETA_Reserved2                                   GBXCOVERMETA_Reserved2
  #define GBXCOVERMETA_Reserved3                                   GBXCOVERMETA_Reserved3
  #define GBXCOVERMETA_Reserved4                                   GBXCOVERMETA_Reserved4
  #define GBXCOVERMETA_Reserved5                                   GBXCOVERMETA_Reserved5
  #define GBXCOVERMETA_Reserved6                                   GBXCOVERMETA_Reserved6
  #define GBXCOVERMETA_Reserved7                                   GBXCOVERMETA_Reserved7
  #define GBXCOVERMETA_Reserved8                                   GBXCOVERMETA_Reserved8
  #define GBXCOVERMETA_Reserved9                                   GBXCOVERMETA_Reserved9
  #define GBXCOVERMETA_MAX                                         GBXCOVERMETA_MAX
  #define EGearboxCoverStateMetaData_None                          GBXCOVERMETA_None
  #define EGearboxCoverStateMetaData_Detach                        GBXCOVERMETA_Detach
  #define EGearboxCoverStateMetaData_Left                          GBXCOVERMETA_Left
  #define EGearboxCoverStateMetaData_Right                         GBXCOVERMETA_Right
  #define EGearboxCoverStateMetaData_Interior                      GBXCOVERMETA_Interior
  #define EGearboxCoverStateMetaData_Dismount_SurpriseLeft         GBXCOVERMETA_Dismount_SurpriseLeft
  #define EGearboxCoverStateMetaData_Dismount_SurpriseRight        GBXCOVERMETA_Dismount_SurpriseRight
  #define EGearboxCoverStateMetaData_Dismount_SurpriseTowardCover  GBXCOVERMETA_Dismount_SurpriseTowardCover
  #define EGearboxCoverStateMetaData_Dismount_SurpriseWith180Turn  GBXCOVERMETA_Dismount_SurpriseWith180Turn
  #define EGearboxCoverStateMetaData_Dismount_Wallhop              GBXCOVERMETA_Dismount_Wallhop
  #define EGearboxCoverStateMetaData_Dismount_TowardCover          GBXCOVERMETA_Dismount_TowardCover
  #define EGearboxCoverStateMetaData_Dismount_With180Turn          GBXCOVERMETA_Dismount_With180Turn
  #define EGearboxCoverStateMetaData_GameSpecific                  GBXCOVERMETA_GameSpecific
  #define EGearboxCoverStateMetaData_Reserved1                     GBXCOVERMETA_Reserved1
  #define EGearboxCoverStateMetaData_Reserved2                     GBXCOVERMETA_Reserved2
  #define EGearboxCoverStateMetaData_Reserved3                     GBXCOVERMETA_Reserved3
  #define EGearboxCoverStateMetaData_Reserved4                     GBXCOVERMETA_Reserved4
  #define EGearboxCoverStateMetaData_Reserved5                     GBXCOVERMETA_Reserved5
  #define EGearboxCoverStateMetaData_Reserved6                     GBXCOVERMETA_Reserved6
  #define EGearboxCoverStateMetaData_Reserved7                     GBXCOVERMETA_Reserved7
  #define EGearboxCoverStateMetaData_Reserved8                     GBXCOVERMETA_Reserved8
  #define EGearboxCoverStateMetaData_Reserved9                     GBXCOVERMETA_Reserved9
  #define EGearboxCoverStateMetaData_MAX                           GBXCOVERMETA_MAX
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
  #define GBXCOVERTRANS_None                         GBXCOVERTRANS_None
  #define GBXCOVERTRANS_Detach                       GBXCOVERTRANS_Detach
  #define GBXCOVERTRANS_PoppingUp                    GBXCOVERTRANS_PoppingUp
  #define GBXCOVERTRANS_LeaningOut                   GBXCOVERTRANS_LeaningOut
  #define GBXCOVERTRANS_PeekingUp                    GBXCOVERTRANS_PeekingUp
  #define GBXCOVERTRANS_BlindFiringUp                GBXCOVERTRANS_BlindFiringUp
  #define GBXCOVERTRANS_ReturnToCover                GBXCOVERTRANS_ReturnToCover
  #define GBXCOVERTRANS_Mounting                     GBXCOVERTRANS_Mounting
  #define GBXCOVERTRANS_Dismounting                  GBXCOVERTRANS_Dismounting
  #define GBXCOVERTRANS_Mantling                     GBXCOVERTRANS_Mantling
  #define GBXCOVERTRANS_ChangingDirection            GBXCOVERTRANS_ChangingDirection
  #define GBXCOVERTRANS_GameSpecific                 GBXCOVERTRANS_GameSpecific
  #define GBXCOVERTRANS_Reserved1                    GBXCOVERTRANS_Reserved1
  #define GBXCOVERTRANS_Reserved2                    GBXCOVERTRANS_Reserved2
  #define GBXCOVERTRANS_Reserved3                    GBXCOVERTRANS_Reserved3
  #define GBXCOVERTRANS_Reserved4                    GBXCOVERTRANS_Reserved4
  #define GBXCOVERTRANS_Reserved5                    GBXCOVERTRANS_Reserved5
  #define GBXCOVERTRANS_Reserved6                    GBXCOVERTRANS_Reserved6
  #define GBXCOVERTRANS_Reserved7                    GBXCOVERTRANS_Reserved7
  #define GBXCOVERTRANS_Reserved8                    GBXCOVERTRANS_Reserved8
  #define GBXCOVERTRANS_Reserved9                    GBXCOVERTRANS_Reserved9
  #define GBXCOVERTRANS_MAX                          GBXCOVERTRANS_MAX
  #define EGearboxCoverTransition_None               GBXCOVERTRANS_None
  #define EGearboxCoverTransition_Detach             GBXCOVERTRANS_Detach
  #define EGearboxCoverTransition_PoppingUp          GBXCOVERTRANS_PoppingUp
  #define EGearboxCoverTransition_LeaningOut         GBXCOVERTRANS_LeaningOut
  #define EGearboxCoverTransition_PeekingUp          GBXCOVERTRANS_PeekingUp
  #define EGearboxCoverTransition_BlindFiringUp      GBXCOVERTRANS_BlindFiringUp
  #define EGearboxCoverTransition_ReturnToCover      GBXCOVERTRANS_ReturnToCover
  #define EGearboxCoverTransition_Mounting           GBXCOVERTRANS_Mounting
  #define EGearboxCoverTransition_Dismounting        GBXCOVERTRANS_Dismounting
  #define EGearboxCoverTransition_Mantling           GBXCOVERTRANS_Mantling
  #define EGearboxCoverTransition_ChangingDirection  GBXCOVERTRANS_ChangingDirection
  #define EGearboxCoverTransition_GameSpecific       GBXCOVERTRANS_GameSpecific
  #define EGearboxCoverTransition_Reserved1          GBXCOVERTRANS_Reserved1
  #define EGearboxCoverTransition_Reserved2          GBXCOVERTRANS_Reserved2
  #define EGearboxCoverTransition_Reserved3          GBXCOVERTRANS_Reserved3
  #define EGearboxCoverTransition_Reserved4          GBXCOVERTRANS_Reserved4
  #define EGearboxCoverTransition_Reserved5          GBXCOVERTRANS_Reserved5
  #define EGearboxCoverTransition_Reserved6          GBXCOVERTRANS_Reserved6
  #define EGearboxCoverTransition_Reserved7          GBXCOVERTRANS_Reserved7
  #define EGearboxCoverTransition_Reserved8          GBXCOVERTRANS_Reserved8
  #define EGearboxCoverTransition_Reserved9          GBXCOVERTRANS_Reserved9
  #define EGearboxCoverTransition_MAX                GBXCOVERTRANS_MAX
} EGearboxCoverTransition;
typedef enum ELocationSearchRandomness  : unsigned char {
  ELOCRAND_PreferIdealDirection,  // 0
  ELOCRAND_PreferRandomLight,     // 1
  ELOCRAND_PreferRandomHeavy,     // 2
  ELOCRAND_MAX                    // 3
  #define ELOCRAND_PreferIdealDirection                   ELOCRAND_PreferIdealDirection
  #define ELOCRAND_PreferRandomLight                      ELOCRAND_PreferRandomLight
  #define ELOCRAND_PreferRandomHeavy                      ELOCRAND_PreferRandomHeavy
  #define ELOCRAND_MAX                                    ELOCRAND_MAX
  #define ELocationSearchRandomness_PreferIdealDirection  ELOCRAND_PreferIdealDirection
  #define ELocationSearchRandomness_PreferRandomLight     ELOCRAND_PreferRandomLight
  #define ELocationSearchRandomness_PreferRandomHeavy     ELOCRAND_PreferRandomHeavy
  #define ELocationSearchRandomness_MAX                   ELOCRAND_MAX
} ELocationSearchRandomness;
typedef enum ERepathBehavior            : unsigned char {
  REPATH_None,                    // 0
  REPATH_IfOriginMoves,           // 1
  REPATH_IfCoverBecomesInvalid,   // 2
  REPATH_MAX                      // 3
  #define REPATH_None                            REPATH_None
  #define REPATH_IfOriginMoves                   REPATH_IfOriginMoves
  #define REPATH_IfCoverBecomesInvalid           REPATH_IfCoverBecomesInvalid
  #define REPATH_MAX                             REPATH_MAX
  #define ERepathBehavior_None                   REPATH_None
  #define ERepathBehavior_IfOriginMoves          REPATH_IfOriginMoves
  #define ERepathBehavior_IfCoverBecomesInvalid  REPATH_IfCoverBecomesInvalid
  #define ERepathBehavior_MAX                    REPATH_MAX
} ERepathBehavior;
typedef enum ECoverFailureBehavior      : unsigned char {
  COVERFAIL_TryToFindNonCoverSpot,// 0
  COVERFAIL_StopSearch,           // 1
  COVERFAIL_MAX                   // 2
  #define COVERFAIL_TryToFindNonCoverSpot              COVERFAIL_TryToFindNonCoverSpot
  #define COVERFAIL_StopSearch                         COVERFAIL_StopSearch
  #define COVERFAIL_MAX                                COVERFAIL_MAX
  #define ECoverFailureBehavior_TryToFindNonCoverSpot  COVERFAIL_TryToFindNonCoverSpot
  #define ECoverFailureBehavior_StopSearch             COVERFAIL_StopSearch
  #define ECoverFailureBehavior_MAX                    COVERFAIL_MAX
} ECoverFailureBehavior;
typedef enum ECoverSearchFilter         : unsigned char {
  COVERSEARCH_Normal,             // 0
  COVERSEARCH_IgnoreCurrentCover, // 1
  COVERSEARCH_MAX                 // 2
  #define COVERSEARCH_Normal                     COVERSEARCH_Normal
  #define COVERSEARCH_IgnoreCurrentCover         COVERSEARCH_IgnoreCurrentCover
  #define COVERSEARCH_MAX                        COVERSEARCH_MAX
  #define ECoverSearchFilter_Normal              COVERSEARCH_Normal
  #define ECoverSearchFilter_IgnoreCurrentCover  COVERSEARCH_IgnoreCurrentCover
  #define ECoverSearchFilter_MAX                 COVERSEARCH_MAX
} ECoverSearchFilter;
typedef enum EDestinationAdditionalTest : unsigned char {
  DESTTEST_None,                  // 0
  DESTTEST_HasLOSToTarget,        // 1
  DESTTEST_BlockedLOSToTarget,    // 2
  DESTTEST_MAX                    // 3
  #define DESTTEST_None                                  DESTTEST_None
  #define DESTTEST_HasLOSToTarget                        DESTTEST_HasLOSToTarget
  #define DESTTEST_BlockedLOSToTarget                    DESTTEST_BlockedLOSToTarget
  #define DESTTEST_MAX                                   DESTTEST_MAX
  #define EDestinationAdditionalTest_None                DESTTEST_None
  #define EDestinationAdditionalTest_HasLOSToTarget      DESTTEST_HasLOSToTarget
  #define EDestinationAdditionalTest_BlockedLOSToTarget  DESTTEST_BlockedLOSToTarget
  #define EDestinationAdditionalTest_MAX                 DESTTEST_MAX
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

/* ---------------------------------------------------------- AWillowPawn ! ---------------------------------------------------------- */

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
  #define ERR_Unknown                          ERR_Unknown
  #define ERR_IDied                            ERR_IDied
  #define ERR_OtherDied                        ERR_OtherDied
  #define ERR_FellOutOfWorld                   ERR_FellOutOfWorld
  #define ERR_LDRes                            ERR_LDRes
  #define ERR_Gibbed                           ERR_Gibbed
  #define ERR_OutsideWorldBounds               ERR_OutsideWorldBounds
  #define ERR_LevelTravel                      ERR_LevelTravel
  #define ERR_MAX                              ERR_MAX
  #define EResurrectReason_Unknown             ERR_Unknown
  #define EResurrectReason_IDied               ERR_IDied
  #define EResurrectReason_OtherDied           ERR_OtherDied
  #define EResurrectReason_FellOutOfWorld      ERR_FellOutOfWorld
  #define EResurrectReason_LDRes               ERR_LDRes
  #define EResurrectReason_Gibbed              ERR_Gibbed
  #define EResurrectReason_OutsideWorldBounds  ERR_OutsideWorldBounds
  #define EResurrectReason_LevelTravel         ERR_LevelTravel
  #define EResurrectReason_MAX                 ERR_MAX
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
  #define ESECONDWIND_None                     ESECONDWIND_None
  #define ESECONDWIND_KilledEnemy              ESECONDWIND_KilledEnemy
  #define ESECONDWIND_LeveledUp                ESECONDWIND_LeveledUp
  #define ESECONDWIND_PartnerRevived           ESECONDWIND_PartnerRevived
  #define ESECONDWIND_Skill_Res                ESECONDWIND_Skill_Res
  #define ESECONDWIND_AutoRevive               ESECONDWIND_AutoRevive
  #define ESECONDWIND_UNUSED_6                 ESECONDWIND_UNUSED_6
  #define ESECONDWIND_UNUSED_7                 ESECONDWIND_UNUSED_7
  #define ESECONDWIND_UNUSED_8                 ESECONDWIND_UNUSED_8
  #define ESECONDWIND_UNUSED_9                 ESECONDWIND_UNUSED_9
  #define ESECONDWIND_UNUSED_10                ESECONDWIND_UNUSED_10
  #define ESECONDWIND_ReasonExtension_1        ESECONDWIND_ReasonExtension_1
  #define ESECONDWIND_ReasonExtension_2        ESECONDWIND_ReasonExtension_2
  #define ESECONDWIND_ReasonExtension_3        ESECONDWIND_ReasonExtension_3
  #define ESECONDWIND_ReasonExtension_4        ESECONDWIND_ReasonExtension_4
  #define ESECONDWIND_ReasonExtension_5        ESECONDWIND_ReasonExtension_5
  #define ESECONDWIND_MAX                      ESECONDWIND_MAX
  #define ESecondWindReason_None               ESECONDWIND_None
  #define ESecondWindReason_KilledEnemy        ESECONDWIND_KilledEnemy
  #define ESecondWindReason_LeveledUp          ESECONDWIND_LeveledUp
  #define ESecondWindReason_PartnerRevived     ESECONDWIND_PartnerRevived
  #define ESecondWindReason_Skill_Res          ESECONDWIND_Skill_Res
  #define ESecondWindReason_AutoRevive         ESECONDWIND_AutoRevive
  #define ESecondWindReason_UNUSED_6           ESECONDWIND_UNUSED_6
  #define ESecondWindReason_UNUSED_7           ESECONDWIND_UNUSED_7
  #define ESecondWindReason_UNUSED_8           ESECONDWIND_UNUSED_8
  #define ESecondWindReason_UNUSED_9           ESECONDWIND_UNUSED_9
  #define ESecondWindReason_UNUSED_10          ESECONDWIND_UNUSED_10
  #define ESecondWindReason_ReasonExtension_1  ESECONDWIND_ReasonExtension_1
  #define ESecondWindReason_ReasonExtension_2  ESECONDWIND_ReasonExtension_2
  #define ESecondWindReason_ReasonExtension_3  ESECONDWIND_ReasonExtension_3
  #define ESecondWindReason_ReasonExtension_4  ESECONDWIND_ReasonExtension_4
  #define ESecondWindReason_ReasonExtension_5  ESECONDWIND_ReasonExtension_5
  #define ESecondWindReason_MAX                ESECONDWIND_MAX
} ESecondWindReason;
typedef enum EHolsteredGearState : unsigned char {
  HGS_None,                       // 0
  HGS_PendingFadeIn,              // 1
  HGS_FadingIn,                   // 2
  HGS_FadingOut,                  // 3
  HGS_MAX                         // 4
  #define HGS_None                           HGS_None
  #define HGS_PendingFadeIn                  HGS_PendingFadeIn
  #define HGS_FadingIn                       HGS_FadingIn
  #define HGS_FadingOut                      HGS_FadingOut
  #define HGS_MAX                            HGS_MAX
  #define EHolsteredGearState_None           HGS_None
  #define EHolsteredGearState_PendingFadeIn  HGS_PendingFadeIn
  #define EHolsteredGearState_FadingIn       HGS_FadingIn
  #define EHolsteredGearState_FadingOut      HGS_FadingOut
  #define EHolsteredGearState_MAX            HGS_MAX
} EHolsteredGearState;
typedef enum EInjuredStage       : unsigned char {
  INJURED_Not,                    // 0
  INJURED_Injured,                // 1
  INJURED_Targeted,               // 2
  INJURED_MostlyDead,             // 3
  INJURED_MAX                     // 4
  #define INJURED_Not               INJURED_Not
  #define INJURED_Injured           INJURED_Injured
  #define INJURED_Targeted          INJURED_Targeted
  #define INJURED_MostlyDead        INJURED_MostlyDead
  #define INJURED_MAX               INJURED_MAX
  #define EInjuredStage_Not         INJURED_Not
  #define EInjuredStage_Injured     INJURED_Injured
  #define EInjuredStage_Targeted    INJURED_Targeted
  #define EInjuredStage_MostlyDead  INJURED_MostlyDead
  #define EInjuredStage_MAX         INJURED_MAX
} EInjuredStage;
typedef enum EInjuredDeadState   : unsigned char {
  INJUREDDEAD_None,               // 0
  INJUREDDEAD_Start,              // 1
  INJUREDDEAD_StartCausePlayerDeath,// 2
  INJUREDDEAD_StartKillVolume,    // 3
  INJUREDDEAD_InitRagdoll,        // 4
  INJUREDDEAD_MAX                 // 5
  #define INJUREDDEAD_None                         INJUREDDEAD_None
  #define INJUREDDEAD_Start                        INJUREDDEAD_Start
  #define INJUREDDEAD_StartCausePlayerDeath        INJUREDDEAD_StartCausePlayerDeath
  #define INJUREDDEAD_StartKillVolume              INJUREDDEAD_StartKillVolume
  #define INJUREDDEAD_InitRagdoll                  INJUREDDEAD_InitRagdoll
  #define INJUREDDEAD_MAX                          INJUREDDEAD_MAX
  #define EInjuredDeadState_None                   INJUREDDEAD_None
  #define EInjuredDeadState_Start                  INJUREDDEAD_Start
  #define EInjuredDeadState_StartCausePlayerDeath  INJUREDDEAD_StartCausePlayerDeath
  #define EInjuredDeadState_StartKillVolume        INJUREDDEAD_StartKillVolume
  #define EInjuredDeadState_InitRagdoll            INJUREDDEAD_InitRagdoll
  #define EInjuredDeadState_MAX                    INJUREDDEAD_MAX
} EInjuredDeadState;
typedef enum EInterpMode         : unsigned char {
  EIM_None,                       // 0
  EIM_Linear,                     // 1
  EIM_NonLinear,                  // 2
  EIM_MAX                         // 3
  #define EIM_None               EIM_None
  #define EIM_Linear             EIM_Linear
  #define EIM_NonLinear          EIM_NonLinear
  #define EIM_MAX                EIM_MAX
  #define EInterpMode_None       EIM_None
  #define EInterpMode_Linear     EIM_Linear
  #define EInterpMode_NonLinear  EIM_NonLinear
  #define EInterpMode_MAX        EIM_MAX
} EInterpMode;
#define EResurrectReason     EResurrectReason
#define ESecondWindReason    ESecondWindReason
#define EHolsteredGearState  EHolsteredGearState
#define EInjuredStage        EInjuredStage
#define EInjuredDeadState    EInjuredDeadState
#define EInterpMode          EInterpMode

/* ---------------------------------------------------------- UINounAttributeProvider ! ---------------------------------------------------------- */

typedef enum ENounReplicationStrategy : unsigned char {
  NOUNREP_NoReplication,          // 0
  NOUNREP_RepToOwnerOnly,         // 1
  NOUNREP_RepToEveryone,          // 2
  NOUNREP_MAX                     // 3
  #define NOUNREP_NoReplication                    NOUNREP_NoReplication
  #define NOUNREP_RepToOwnerOnly                   NOUNREP_RepToOwnerOnly
  #define NOUNREP_RepToEveryone                    NOUNREP_RepToEveryone
  #define NOUNREP_MAX                              NOUNREP_MAX
  #define ENounReplicationStrategy_NoReplication   NOUNREP_NoReplication
  #define ENounReplicationStrategy_RepToOwnerOnly  NOUNREP_RepToOwnerOnly
  #define ENounReplicationStrategy_RepToEveryone   NOUNREP_RepToEveryone
  #define ENounReplicationStrategy_MAX             NOUNREP_MAX
} ENounReplicationStrategy;
#define ENounReplicationStrategy  ENounReplicationStrategy

/* ---------------------------------------------------------- USkeletalMeshComponent ! ---------------------------------------------------------- */

typedef enum EMaxDistanceScaleMode   : unsigned char {
  MDSM_Multiply,                  // 0
  MDSM_Substract,                 // 1
  MDSM_MAX                        // 2
  #define MDSM_Multiply                    MDSM_Multiply
  #define MDSM_Substract                   MDSM_Substract
  #define MDSM_MAX                         MDSM_MAX
  #define EMaxDistanceScaleMode_Multiply   MDSM_Multiply
  #define EMaxDistanceScaleMode_Substract  MDSM_Substract
  #define EMaxDistanceScaleMode_MAX        MDSM_MAX
} EMaxDistanceScaleMode;
typedef enum EInstanceWeightUsage    : unsigned char {
  IWU_PartialSwap,                // 0
  IWU_FullSwap,                   // 1
  IWU_MAX                         // 2
  #define IWU_PartialSwap                   IWU_PartialSwap
  #define IWU_FullSwap                      IWU_FullSwap
  #define IWU_MAX                           IWU_MAX
  #define EInstanceWeightUsage_PartialSwap  IWU_PartialSwap
  #define EInstanceWeightUsage_FullSwap     IWU_FullSwap
  #define EInstanceWeightUsage_MAX          IWU_MAX
} EInstanceWeightUsage;
typedef enum ERootMotionMode         : unsigned char {
  RMM_Translate,                  // 0
  RMM_Velocity,                   // 1
  RMM_Ignore,                     // 2
  RMM_Accel,                      // 3
  RMM_Relative,                   // 4
  RMM_TranslateWithGravity,       // 5
  RMM_MAX                         // 6
  #define RMM_Translate                         RMM_Translate
  #define RMM_Velocity                          RMM_Velocity
  #define RMM_Ignore                            RMM_Ignore
  #define RMM_Accel                             RMM_Accel
  #define RMM_Relative                          RMM_Relative
  #define RMM_TranslateWithGravity              RMM_TranslateWithGravity
  #define RMM_MAX                               RMM_MAX
  #define ERootMotionMode_Translate             RMM_Translate
  #define ERootMotionMode_Velocity              RMM_Velocity
  #define ERootMotionMode_Ignore                RMM_Ignore
  #define ERootMotionMode_Accel                 RMM_Accel
  #define ERootMotionMode_Relative              RMM_Relative
  #define ERootMotionMode_TranslateWithGravity  RMM_TranslateWithGravity
  #define ERootMotionMode_MAX                   RMM_MAX
} ERootMotionMode;
typedef enum ERootMotionRotationMode : unsigned char {
  RMRM_Ignore,                    // 0
  RMRM_RotateActor,               // 1
  RMRM_MAX                        // 2
  #define RMRM_Ignore                          RMRM_Ignore
  #define RMRM_RotateActor                     RMRM_RotateActor
  #define RMRM_MAX                             RMRM_MAX
  #define ERootMotionRotationMode_Ignore       RMRM_Ignore
  #define ERootMotionRotationMode_RotateActor  RMRM_RotateActor
  #define ERootMotionRotationMode_MAX          RMRM_MAX
} ERootMotionRotationMode;
typedef enum EAnimRotationOnly       : unsigned char {
  EARO_AnimSet,                   // 0
  EARO_ForceEnabled,              // 1
  EARO_ForceDisabled,             // 2
  EARO_MAX                        // 3
  #define EARO_AnimSet                     EARO_AnimSet
  #define EARO_ForceEnabled                EARO_ForceEnabled
  #define EARO_ForceDisabled               EARO_ForceDisabled
  #define EARO_MAX                         EARO_MAX
  #define EAnimRotationOnly_AnimSet        EARO_AnimSet
  #define EAnimRotationOnly_ForceEnabled   EARO_ForceEnabled
  #define EAnimRotationOnly_ForceDisabled  EARO_ForceDisabled
  #define EAnimRotationOnly_MAX            EARO_MAX
} EAnimRotationOnly;
typedef enum EFaceFXBlendMode        : unsigned char {
  FXBM_Overwrite,                 // 0
  FXBM_Additive,                  // 1
  FXBM_MAX                        // 2
  #define FXBM_Overwrite              FXBM_Overwrite
  #define FXBM_Additive               FXBM_Additive
  #define FXBM_MAX                    FXBM_MAX
  #define EFaceFXBlendMode_Overwrite  FXBM_Overwrite
  #define EFaceFXBlendMode_Additive   FXBM_Additive
  #define EFaceFXBlendMode_MAX        FXBM_MAX
} EFaceFXBlendMode;
typedef enum EFaceFXRegOp            : unsigned char {
  FXRO_Add,                       // 0
  FXRO_Multiply,                  // 1
  FXRO_Replace,                   // 2
  FXRO_MAX                        // 3
  #define FXRO_Add               FXRO_Add
  #define FXRO_Multiply          FXRO_Multiply
  #define FXRO_Replace           FXRO_Replace
  #define FXRO_MAX               FXRO_MAX
  #define EFaceFXRegOp_Add       FXRO_Add
  #define EFaceFXRegOp_Multiply  FXRO_Multiply
  #define EFaceFXRegOp_Replace   FXRO_Replace
  #define EFaceFXRegOp_MAX       FXRO_MAX
} EFaceFXRegOp;
typedef enum EBoneVisibilityStatus   : unsigned char {
  BVS_HiddenByParent,             // 0
  BVS_Visible,                    // 1
  BVS_ExplicitlyHidden,           // 2
  BVS_MAX                         // 3
  #define BVS_HiddenByParent                      BVS_HiddenByParent
  #define BVS_Visible                             BVS_Visible
  #define BVS_ExplicitlyHidden                    BVS_ExplicitlyHidden
  #define BVS_MAX                                 BVS_MAX
  #define EBoneVisibilityStatus_HiddenByParent    BVS_HiddenByParent
  #define EBoneVisibilityStatus_Visible           BVS_Visible
  #define EBoneVisibilityStatus_ExplicitlyHidden  BVS_ExplicitlyHidden
  #define EBoneVisibilityStatus_MAX               BVS_MAX
} EBoneVisibilityStatus;
typedef enum EPhysBodyOp             : unsigned char {
  PBO_None,                       // 0
  PBO_Term,                       // 1
  PBO_Disable,                    // 2
  PBO_MAX                         // 3
  #define PBO_None             PBO_None
  #define PBO_Term             PBO_Term
  #define PBO_Disable          PBO_Disable
  #define PBO_MAX              PBO_MAX
  #define EPhysBodyOp_None     PBO_None
  #define EPhysBodyOp_Term     PBO_Term
  #define EPhysBodyOp_Disable  PBO_Disable
  #define EPhysBodyOp_MAX      PBO_MAX
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

/* ---------------------------------------------------------- UStaticMeshComponent ! ---------------------------------------------------------- */

typedef enum ELightmapModificationFunction : unsigned char {
  MLMF_Modulate,                  // 0
  MLMF_ModulateAlpha,             // 1
  MLMF_MAX                        // 2
  #define MLMF_Modulate                                MLMF_Modulate
  #define MLMF_ModulateAlpha                           MLMF_ModulateAlpha
  #define MLMF_MAX                                     MLMF_MAX
  #define ELightmapModificationFunction_Modulate       MLMF_Modulate
  #define ELightmapModificationFunction_ModulateAlpha  MLMF_ModulateAlpha
  #define ELightmapModificationFunction_MAX            MLMF_MAX
} ELightmapModificationFunction;
#define ELightmapModificationFunction  ELightmapModificationFunction

/* ---------------------------------------------------------- UInventoryCardGFx ! ---------------------------------------------------------- */

typedef enum ETopStatArrow : unsigned char {
  ETSA_Blank,                     // 0
  ETSA_Up,                        // 1
  ETSA_Down,                      // 2
  ETSA_Same,                      // 3
  ETSA_MAX                        // 4
  #define ETSA_Blank           ETSA_Blank
  #define ETSA_Up              ETSA_Up
  #define ETSA_Down            ETSA_Down
  #define ETSA_Same            ETSA_Same
  #define ETSA_MAX             ETSA_MAX
  #define ETopStatArrow_Blank  ETSA_Blank
  #define ETopStatArrow_Up     ETSA_Up
  #define ETopStatArrow_Down   ETSA_Down
  #define ETopStatArrow_Same   ETSA_Same
  #define ETopStatArrow_MAX    ETSA_MAX
} ETopStatArrow;
#define ETopStatArrow  ETopStatArrow

/* ---------------------------------------------------------- USwfMovie ! ---------------------------------------------------------- */

typedef enum FlashTextureRescale : unsigned char {
  FlashTextureScale_High,         // 0
  FlashTextureScale_Low,          // 1
  FlashTextureScale_NextLow,      // 2
  FlashTextureScale_Mult4,        // 3
  FlashTextureScale_None,         // 4
  FlashTextureScale_MAX           // 5
  #define FlashTextureScale_High       FlashTextureScale_High
  #define FlashTextureScale_Low        FlashTextureScale_Low
  #define FlashTextureScale_NextLow    FlashTextureScale_NextLow
  #define FlashTextureScale_Mult4      FlashTextureScale_Mult4
  #define FlashTextureScale_None       FlashTextureScale_None
  #define FlashTextureScale_MAX        FlashTextureScale_MAX
  #define FlashTextureRescale_High     FlashTextureScale_High
  #define FlashTextureRescale_Low      FlashTextureScale_Low
  #define FlashTextureRescale_NextLow  FlashTextureScale_NextLow
  #define FlashTextureRescale_Mult4    FlashTextureScale_Mult4
  #define FlashTextureRescale_None     FlashTextureScale_None
  #define FlashTextureRescale_MAX      FlashTextureScale_MAX
} FlashTextureRescale;
typedef enum SwfMovieArenas      : unsigned char {
  SWFARENA_Global,                // 0
  SWFARENA_Default,               // 1
  SWFARENA_HUD,                   // 2
  SWFARENA_StatusMenu,            // 3
  SWFARENA_Menu,                  // 4
  SWFARENA_MAX                    // 5
  #define SWFARENA_Global            SWFARENA_Global
  #define SWFARENA_Default           SWFARENA_Default
  #define SWFARENA_HUD               SWFARENA_HUD
  #define SWFARENA_StatusMenu        SWFARENA_StatusMenu
  #define SWFARENA_Menu              SWFARENA_Menu
  #define SWFARENA_MAX               SWFARENA_MAX
  #define SwfMovieArenas_Global      SWFARENA_Global
  #define SwfMovieArenas_Default     SWFARENA_Default
  #define SwfMovieArenas_HUD         SWFARENA_HUD
  #define SwfMovieArenas_StatusMenu  SWFARENA_StatusMenu
  #define SwfMovieArenas_Menu        SWFARENA_Menu
  #define SwfMovieArenas_MAX         SWFARENA_MAX
} SwfMovieArenas;
#define FlashTextureRescale  FlashTextureRescale
#define SwfMovieArenas       SwfMovieArenas

/* ---------------------------------------------------------- AWillowLightProjectileManager ! ---------------------------------------------------------- */

typedef enum EBulletFromClip : unsigned char {
  BFC_Other,                      // 0
  BFC_First,                      // 1
  BFC_Last,                       // 2
  BFC_MAX                         // 3
  #define BFC_Other              BFC_Other
  #define BFC_First              BFC_First
  #define BFC_Last               BFC_Last
  #define BFC_MAX                BFC_MAX
  #define EBulletFromClip_Other  BFC_Other
  #define EBulletFromClip_First  BFC_First
  #define EBulletFromClip_Last   BFC_Last
  #define EBulletFromClip_MAX    BFC_MAX
} EBulletFromClip;
typedef enum EBeamSource     : unsigned char {
  EBS_Weapon,                     // 0
  EBS_Pawn,                       // 1
  EBS_WorldBody,                  // 2
  EBS_MAX                         // 3
  #define EBS_Weapon             EBS_Weapon
  #define EBS_Pawn               EBS_Pawn
  #define EBS_WorldBody          EBS_WorldBody
  #define EBS_MAX                EBS_MAX
  #define EBeamSource_Weapon     EBS_Weapon
  #define EBeamSource_Pawn       EBS_Pawn
  #define EBeamSource_WorldBody  EBS_WorldBody
  #define EBeamSource_MAX        EBS_MAX
} EBeamSource;
#define EBulletFromClip  EBulletFromClip
#define EBeamSource      EBeamSource

/* ---------------------------------------------------------- UInventoryPartListCollectionDefinition ! ---------------------------------------------------------- */

typedef enum EPartReplacementMode : unsigned char {
  EPRM_Additive,                  // 0
  EPRM_Selective,                 // 1
  EPRM_Complete,                  // 2
  EPRM_MAX                        // 3
  #define EPRM_Additive                   EPRM_Additive
  #define EPRM_Selective                  EPRM_Selective
  #define EPRM_Complete                   EPRM_Complete
  #define EPRM_MAX                        EPRM_MAX
  #define EPartReplacementMode_Additive   EPRM_Additive
  #define EPartReplacementMode_Selective  EPRM_Selective
  #define EPartReplacementMode_Complete   EPRM_Complete
  #define EPartReplacementMode_MAX        EPRM_MAX
} EPartReplacementMode;
#define EPartReplacementMode  EPartReplacementMode

/* ---------------------------------------------------------- UBodyClassDefinition ! ---------------------------------------------------------- */

typedef enum EFlinchSeverity : unsigned char {
  EF_NoFlinch,                    // 0
  EF_SmallFlinch,                 // 1
  EF_MediumFlinch,                // 2
  EF_LargeFlinch,                 // 3
  EF_CriticalFlinch,              // 4
  EF_MAX                          // 5
  #define EF_NoFlinch                     EF_NoFlinch
  #define EF_SmallFlinch                  EF_SmallFlinch
  #define EF_MediumFlinch                 EF_MediumFlinch
  #define EF_LargeFlinch                  EF_LargeFlinch
  #define EF_CriticalFlinch               EF_CriticalFlinch
  #define EF_MAX                          EF_MAX
  #define EFlinchSeverity_NoFlinch        EF_NoFlinch
  #define EFlinchSeverity_SmallFlinch     EF_SmallFlinch
  #define EFlinchSeverity_MediumFlinch    EF_MediumFlinch
  #define EFlinchSeverity_LargeFlinch     EF_LargeFlinch
  #define EFlinchSeverity_CriticalFlinch  EF_CriticalFlinch
  #define EFlinchSeverity_MAX             EF_MAX
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
  #define CLOAK_Spawn              CLOAK_Spawn
  #define CLOAK_AttackMove         CLOAK_AttackMove
  #define CLOAK_AttackAnim         CLOAK_AttackAnim
  #define CLOAK_PatrolPath         CLOAK_PatrolPath
  #define CLOAK_PatrolPerch        CLOAK_PatrolPerch
  #define CLOAK_PatrolRandom       CLOAK_PatrolRandom
  #define CLOAK_RunHome            CLOAK_RunHome
  #define CLOAK_Unprovoked         CLOAK_Unprovoked
  #define CLOAK_ScriptedMove       CLOAK_ScriptedMove
  #define CLOAK_SpawnAnim          CLOAK_SpawnAnim
  #define CLOAK_PhysicsJump        CLOAK_PhysicsJump
  #define CLOAK_MAX                CLOAK_MAX
  #define ECloakType_Spawn         CLOAK_Spawn
  #define ECloakType_AttackMove    CLOAK_AttackMove
  #define ECloakType_AttackAnim    CLOAK_AttackAnim
  #define ECloakType_PatrolPath    CLOAK_PatrolPath
  #define ECloakType_PatrolPerch   CLOAK_PatrolPerch
  #define ECloakType_PatrolRandom  CLOAK_PatrolRandom
  #define ECloakType_RunHome       CLOAK_RunHome
  #define ECloakType_Unprovoked    CLOAK_Unprovoked
  #define ECloakType_ScriptedMove  CLOAK_ScriptedMove
  #define ECloakType_SpawnAnim     CLOAK_SpawnAnim
  #define ECloakType_PhysicsJump   CLOAK_PhysicsJump
  #define ECloakType_MAX           CLOAK_MAX
} ECloakType;
typedef enum ECloakStyle     : unsigned char {
  CLOAKSTYLE_None,                // 0
  CLOAKSTYLE_Hide,                // 1
  CLOAKSTYLE_Visible,             // 2
  CLOAKSTYLE_VisibleHUD,          // 3
  CLOAKSTYLE_MAX                  // 4
  #define CLOAKSTYLE_None         CLOAKSTYLE_None
  #define CLOAKSTYLE_Hide         CLOAKSTYLE_Hide
  #define CLOAKSTYLE_Visible      CLOAKSTYLE_Visible
  #define CLOAKSTYLE_VisibleHUD   CLOAKSTYLE_VisibleHUD
  #define CLOAKSTYLE_MAX          CLOAKSTYLE_MAX
  #define ECloakStyle_None        CLOAKSTYLE_None
  #define ECloakStyle_Hide        CLOAKSTYLE_Hide
  #define ECloakStyle_Visible     CLOAKSTYLE_Visible
  #define ECloakStyle_VisibleHUD  CLOAKSTYLE_VisibleHUD
  #define ECloakStyle_MAX         CLOAKSTYLE_MAX
} ECloakStyle;
#define EFlinchSeverity  EFlinchSeverity
#define ECloakType       ECloakType
#define ECloakStyle      ECloakStyle
_DECL_TARRAY(ECloakType);

/* ---------------------------------------------------------- UBodyHitRegionDefinition ! ---------------------------------------------------------- */

typedef enum EGoreMode : unsigned char {
  GORE_Full,                      // 0
  GORE_None,                      // 1
  GORE_MAX                        // 2
  #define GORE_Full       GORE_Full
  #define GORE_None       GORE_None
  #define GORE_MAX        GORE_MAX
  #define EGoreMode_Full  GORE_Full
  #define EGoreMode_None  GORE_None
  #define EGoreMode_MAX   GORE_MAX
} EGoreMode;
#define EGoreMode  EGoreMode

/* ---------------------------------------------------------- UDownloadableContentEnumerator ! ---------------------------------------------------------- */

typedef enum EDlcEnumerationState : unsigned char {
  DLC_ENUM_None,                  // 0
  DLC_ENUM_EnumeratingFiles,      // 1
  DLC_ENUM_EnumerationComplete,   // 2
  DLC_ENUM_MAX                    // 3
  #define DLC_ENUM_None                             DLC_ENUM_None
  #define DLC_ENUM_EnumeratingFiles                 DLC_ENUM_EnumeratingFiles
  #define DLC_ENUM_EnumerationComplete              DLC_ENUM_EnumerationComplete
  #define DLC_ENUM_MAX                              DLC_ENUM_MAX
  #define EDlcEnumerationState_None                 DLC_ENUM_None
  #define EDlcEnumerationState_EnumeratingFiles     DLC_ENUM_EnumeratingFiles
  #define EDlcEnumerationState_EnumerationComplete  DLC_ENUM_EnumerationComplete
  #define EDlcEnumerationState_MAX                  DLC_ENUM_MAX
} EDlcEnumerationState;
#define EDlcEnumerationState  EDlcEnumerationState

/* ---------------------------------------------------------- UDownloadableContentManager ! ---------------------------------------------------------- */

typedef enum EInstalledContentType : unsigned char {
  INSTALLED_CONTENT_TYPE_UnNamed, // 0
  INSTALLED_CONTENT_TYPE_Named,   // 1
  INSTALLED_CONTENT_TYPE_Compatibility,// 2
  INSTALLED_CONTENT_TYPE_SeasonPass,// 3
  INSTALLED_CONTENT_TYPE_PreorderBonus,// 4
  INSTALLED_CONTENT_TYPE_CompatibilityPackContainer,// 5
  INSTALLED_CONTENT_TYPE_MAX      // 6
  #define INSTALLED_CONTENT_TYPE_UnNamed                     INSTALLED_CONTENT_TYPE_UnNamed
  #define INSTALLED_CONTENT_TYPE_Named                       INSTALLED_CONTENT_TYPE_Named
  #define INSTALLED_CONTENT_TYPE_Compatibility               INSTALLED_CONTENT_TYPE_Compatibility
  #define INSTALLED_CONTENT_TYPE_SeasonPass                  INSTALLED_CONTENT_TYPE_SeasonPass
  #define INSTALLED_CONTENT_TYPE_PreorderBonus               INSTALLED_CONTENT_TYPE_PreorderBonus
  #define INSTALLED_CONTENT_TYPE_CompatibilityPackContainer  INSTALLED_CONTENT_TYPE_CompatibilityPackContainer
  #define INSTALLED_CONTENT_TYPE_MAX                         INSTALLED_CONTENT_TYPE_MAX
  #define EInstalledContentType_UnNamed                      INSTALLED_CONTENT_TYPE_UnNamed
  #define EInstalledContentType_Named                        INSTALLED_CONTENT_TYPE_Named
  #define EInstalledContentType_Compatibility                INSTALLED_CONTENT_TYPE_Compatibility
  #define EInstalledContentType_SeasonPass                   INSTALLED_CONTENT_TYPE_SeasonPass
  #define EInstalledContentType_PreorderBonus                INSTALLED_CONTENT_TYPE_PreorderBonus
  #define EInstalledContentType_CompatibilityPackContainer   INSTALLED_CONTENT_TYPE_CompatibilityPackContainer
  #define EInstalledContentType_MAX                          INSTALLED_CONTENT_TYPE_MAX
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
  #define INSTALLDLC_RES_Success                              INSTALLDLC_RES_Success
  #define INSTALLDLC_RES_InvalidNameInfo                      INSTALLDLC_RES_InvalidNameInfo
  #define INSTALLDLC_RES_InvalidEngineVersion                 INSTALLDLC_RES_InvalidEngineVersion
  #define INSTALLDLC_RES_CookedGuidMismatch                   INSTALLDLC_RES_CookedGuidMismatch
  #define INSTALLDLC_RES_CorruptContent                       INSTALLDLC_RES_CorruptContent
  #define INSTALLDLC_RES_UnknownFailure                       INSTALLDLC_RES_UnknownFailure
  #define INSTALLDLC_RES_CannotInstallCompatibility           INSTALLDLC_RES_CannotInstallCompatibility
  #define INSTALLDLC_RES_CompabitilityContentNotInstalled     INSTALLDLC_RES_CompabitilityContentNotInstalled
  #define INSTALLDLC_RES_UnlicensedNamedContent               INSTALLDLC_RES_UnlicensedNamedContent
  #define INSTALLDLC_RES_MAX                                  INSTALLDLC_RES_MAX
  #define EInstallDLCResult_Success                           INSTALLDLC_RES_Success
  #define EInstallDLCResult_InvalidNameInfo                   INSTALLDLC_RES_InvalidNameInfo
  #define EInstallDLCResult_InvalidEngineVersion              INSTALLDLC_RES_InvalidEngineVersion
  #define EInstallDLCResult_CookedGuidMismatch                INSTALLDLC_RES_CookedGuidMismatch
  #define EInstallDLCResult_CorruptContent                    INSTALLDLC_RES_CorruptContent
  #define EInstallDLCResult_UnknownFailure                    INSTALLDLC_RES_UnknownFailure
  #define EInstallDLCResult_CannotInstallCompatibility        INSTALLDLC_RES_CannotInstallCompatibility
  #define EInstallDLCResult_CompabitilityContentNotInstalled  INSTALLDLC_RES_CompabitilityContentNotInstalled
  #define EInstallDLCResult_UnlicensedNamedContent            INSTALLDLC_RES_UnlicensedNamedContent
  #define EInstallDLCResult_MAX                               INSTALLDLC_RES_MAX
} EInstallDLCResult;
#define EInstalledContentType  EInstalledContentType
#define EInstallDLCResult      EInstallDLCResult

/* ---------------------------------------------------------- UDownloadableContentOfferEnumerator ! ---------------------------------------------------------- */

typedef enum EDlcOfferEnumerationState : unsigned char {
  DLC_OFFER_ENUM_None,            // 0
  DLC_OFFER_ENUM_EnumeratingOffers,// 1
  DLC_OFFER_ENUM_EnumerationComplete,// 2
  DLC_OFFER_ENUM_MAX              // 3
  #define DLC_OFFER_ENUM_None                            DLC_OFFER_ENUM_None
  #define DLC_OFFER_ENUM_EnumeratingOffers               DLC_OFFER_ENUM_EnumeratingOffers
  #define DLC_OFFER_ENUM_EnumerationComplete             DLC_OFFER_ENUM_EnumerationComplete
  #define DLC_OFFER_ENUM_MAX                             DLC_OFFER_ENUM_MAX
  #define EDlcOfferEnumerationState_None                 DLC_OFFER_ENUM_None
  #define EDlcOfferEnumerationState_EnumeratingOffers    DLC_OFFER_ENUM_EnumeratingOffers
  #define EDlcOfferEnumerationState_EnumerationComplete  DLC_OFFER_ENUM_EnumerationComplete
  #define EDlcOfferEnumerationState_MAX                  DLC_OFFER_ENUM_MAX
} EDlcOfferEnumerationState;
#define EDlcOfferEnumerationState  EDlcOfferEnumerationState

/* ---------------------------------------------------------- UWillowDownloadableContentManager ! ---------------------------------------------------------- */

typedef enum EDlcInstallState      : unsigned char {
  DLC_INSTALL_None,               // 0
  DLC_INSTALL_InstallingBundles,  // 1
  DLC_INSTALL_LoadingAsyncPackages,// 2
  DLC_INSTALL_InstallingContent,  // 3
  DLC_INSTALL_InstallingOfferContent,// 4
  DLC_INSTALL_InstallComplete,    // 5
  DLC_INSTALL_MAX                 // 6
  #define DLC_INSTALL_None                         DLC_INSTALL_None
  #define DLC_INSTALL_InstallingBundles            DLC_INSTALL_InstallingBundles
  #define DLC_INSTALL_LoadingAsyncPackages         DLC_INSTALL_LoadingAsyncPackages
  #define DLC_INSTALL_InstallingContent            DLC_INSTALL_InstallingContent
  #define DLC_INSTALL_InstallingOfferContent       DLC_INSTALL_InstallingOfferContent
  #define DLC_INSTALL_InstallComplete              DLC_INSTALL_InstallComplete
  #define DLC_INSTALL_MAX                          DLC_INSTALL_MAX
  #define EDlcInstallState_None                    DLC_INSTALL_None
  #define EDlcInstallState_InstallingBundles       DLC_INSTALL_InstallingBundles
  #define EDlcInstallState_LoadingAsyncPackages    DLC_INSTALL_LoadingAsyncPackages
  #define EDlcInstallState_InstallingContent       DLC_INSTALL_InstallingContent
  #define EDlcInstallState_InstallingOfferContent  DLC_INSTALL_InstallingOfferContent
  #define EDlcInstallState_InstallComplete         DLC_INSTALL_InstallComplete
  #define EDlcInstallState_MAX                     DLC_INSTALL_MAX
} EDlcInstallState;
typedef enum EMarketplaceOfferType : unsigned char {
  OFFER_CATEGORY_SeasonPass,      // 0
  OFFER_CATEGORY_CompatibilityPack,// 1
  OFFER_CATEGORY_AddOn,           // 2
  OFFER_CATEGORY_Misc,            // 3
  OFFER_CATEGORY_MAX              // 4
  #define OFFER_CATEGORY_SeasonPass                OFFER_CATEGORY_SeasonPass
  #define OFFER_CATEGORY_CompatibilityPack         OFFER_CATEGORY_CompatibilityPack
  #define OFFER_CATEGORY_AddOn                     OFFER_CATEGORY_AddOn
  #define OFFER_CATEGORY_Misc                      OFFER_CATEGORY_Misc
  #define OFFER_CATEGORY_MAX                       OFFER_CATEGORY_MAX
  #define EMarketplaceOfferType_SeasonPass         OFFER_CATEGORY_SeasonPass
  #define EMarketplaceOfferType_CompatibilityPack  OFFER_CATEGORY_CompatibilityPack
  #define EMarketplaceOfferType_AddOn              OFFER_CATEGORY_AddOn
  #define EMarketplaceOfferType_Misc               OFFER_CATEGORY_Misc
  #define EMarketplaceOfferType_MAX                OFFER_CATEGORY_MAX
} EMarketplaceOfferType;
#define EDlcInstallState       EDlcInstallState
#define EMarketplaceOfferType  EMarketplaceOfferType

/* ---------------------------------------------------------- UMaterialInterface ! ---------------------------------------------------------- */

typedef enum EParticleDownsampling : unsigned char {
  PDS_Full,                       // 0
  PDS_Half,                       // 1
  PDS_Quarter,                    // 2
  PDS_MAX                         // 3
  #define PDS_Full                       PDS_Full
  #define PDS_Half                       PDS_Half
  #define PDS_Quarter                    PDS_Quarter
  #define PDS_MAX                        PDS_MAX
  #define EParticleDownsampling_Full     PDS_Full
  #define EParticleDownsampling_Half     PDS_Half
  #define EParticleDownsampling_Quarter  PDS_Quarter
  #define EParticleDownsampling_MAX      PDS_MAX
} EParticleDownsampling;
#define EParticleDownsampling  EParticleDownsampling

/* ---------------------------------------------------------- UAnimNode ! ---------------------------------------------------------- */

typedef enum ESliderType : unsigned char {
  ST_1D,                          // 0
  ST_2D,                          // 1
  ST_MAX                          // 2
  #define ST_1D            ST_1D
  #define ST_2D            ST_2D
  #define ST_MAX           ST_MAX
  #define ESliderType_1D   ST_1D
  #define ESliderType_2D   ST_2D
  #define ESliderType_MAX  ST_MAX
} ESliderType;
#define ESliderType  ESliderType

/* ---------------------------------------------------------- UAnimNodeAimOffset ! ---------------------------------------------------------- */

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
  #define ANIMAIM_LEFTUP            ANIMAIM_LEFTUP
  #define ANIMAIM_CENTERUP          ANIMAIM_CENTERUP
  #define ANIMAIM_RIGHTUP           ANIMAIM_RIGHTUP
  #define ANIMAIM_LEFTCENTER        ANIMAIM_LEFTCENTER
  #define ANIMAIM_CENTERCENTER      ANIMAIM_CENTERCENTER
  #define ANIMAIM_RIGHTCENTER       ANIMAIM_RIGHTCENTER
  #define ANIMAIM_LEFTDOWN          ANIMAIM_LEFTDOWN
  #define ANIMAIM_CENTERDOWN        ANIMAIM_CENTERDOWN
  #define ANIMAIM_RIGHTDOWN         ANIMAIM_RIGHTDOWN
  #define ANIMAIM_MAX               ANIMAIM_MAX
  #define EAnimAimDir_LEFTUP        ANIMAIM_LEFTUP
  #define EAnimAimDir_CENTERUP      ANIMAIM_CENTERUP
  #define EAnimAimDir_RIGHTUP       ANIMAIM_RIGHTUP
  #define EAnimAimDir_LEFTCENTER    ANIMAIM_LEFTCENTER
  #define EAnimAimDir_CENTERCENTER  ANIMAIM_CENTERCENTER
  #define EAnimAimDir_RIGHTCENTER   ANIMAIM_RIGHTCENTER
  #define EAnimAimDir_LEFTDOWN      ANIMAIM_LEFTDOWN
  #define EAnimAimDir_CENTERDOWN    ANIMAIM_CENTERDOWN
  #define EAnimAimDir_RIGHTDOWN     ANIMAIM_RIGHTDOWN
  #define EAnimAimDir_MAX           ANIMAIM_MAX
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
  #define EAID_LeftUp       EAID_LeftUp
  #define EAID_LeftDown     EAID_LeftDown
  #define EAID_RightUp      EAID_RightUp
  #define EAID_RightDown    EAID_RightDown
  #define EAID_ZeroUp       EAID_ZeroUp
  #define EAID_ZeroDown     EAID_ZeroDown
  #define EAID_ZeroLeft     EAID_ZeroLeft
  #define EAID_ZeroRight    EAID_ZeroRight
  #define EAID_CellLU       EAID_CellLU
  #define EAID_CellCU       EAID_CellCU
  #define EAID_CellRU       EAID_CellRU
  #define EAID_CellLC       EAID_CellLC
  #define EAID_CellCC       EAID_CellCC
  #define EAID_CellRC       EAID_CellRC
  #define EAID_CellLD       EAID_CellLD
  #define EAID_CellCD       EAID_CellCD
  #define EAID_CellRD       EAID_CellRD
  #define EAID_MAX          EAID_MAX
  #define EAimID_LeftUp     EAID_LeftUp
  #define EAimID_LeftDown   EAID_LeftDown
  #define EAimID_RightUp    EAID_RightUp
  #define EAimID_RightDown  EAID_RightDown
  #define EAimID_ZeroUp     EAID_ZeroUp
  #define EAimID_ZeroDown   EAID_ZeroDown
  #define EAimID_ZeroLeft   EAID_ZeroLeft
  #define EAimID_ZeroRight  EAID_ZeroRight
  #define EAimID_CellLU     EAID_CellLU
  #define EAimID_CellCU     EAID_CellCU
  #define EAimID_CellRU     EAID_CellRU
  #define EAimID_CellLC     EAID_CellLC
  #define EAimID_CellCC     EAID_CellCC
  #define EAimID_CellRC     EAID_CellRC
  #define EAimID_CellLD     EAID_CellLD
  #define EAimID_CellCD     EAID_CellCD
  #define EAimID_CellRD     EAID_CellRD
  #define EAimID_MAX        EAID_MAX
} EAimID;
#define EAnimAimDir  EAnimAimDir
#define EAimID       EAimID

/* ---------------------------------------------------------- UDecalComponent ! ---------------------------------------------------------- */

typedef enum EDecalTransform : unsigned char {
  DecalTransform_OwnerAbsolute,   // 0
  DecalTransform_OwnerRelative,   // 1
  DecalTransform_SpawnRelative,   // 2
  DecalTransform_MAX              // 3
  #define DecalTransform_OwnerAbsolute   DecalTransform_OwnerAbsolute
  #define DecalTransform_OwnerRelative   DecalTransform_OwnerRelative
  #define DecalTransform_SpawnRelative   DecalTransform_SpawnRelative
  #define DecalTransform_MAX             DecalTransform_MAX
  #define EDecalTransform_OwnerAbsolute  DecalTransform_OwnerAbsolute
  #define EDecalTransform_OwnerRelative  DecalTransform_OwnerRelative
  #define EDecalTransform_SpawnRelative  DecalTransform_SpawnRelative
  #define EDecalTransform_MAX            DecalTransform_MAX
} EDecalTransform;
typedef enum EFilterMode     : unsigned char {
  FM_None,                        // 0
  FM_Ignore,                      // 1
  FM_Affect,                      // 2
  FM_MAX                          // 3
  #define FM_None             FM_None
  #define FM_Ignore           FM_Ignore
  #define FM_Affect           FM_Affect
  #define FM_MAX              FM_MAX
  #define EFilterMode_None    FM_None
  #define EFilterMode_Ignore  FM_Ignore
  #define EFilterMode_Affect  FM_Affect
  #define EFilterMode_MAX     FM_MAX
} EFilterMode;
#define EDecalTransform  EDecalTransform
#define EFilterMode      EFilterMode

/* ---------------------------------------------------------- UInteractiveObjectDefinition ! ---------------------------------------------------------- */

typedef enum ERelevanceDistance   : unsigned char {
  RELEVANCE_Lootable,             // 0
  RELEVANCE_Outpost,              // 1
  RELEVANCE_Huge,                 // 2
  RELEVANCE_MAX                   // 3
  #define RELEVANCE_Lootable           RELEVANCE_Lootable
  #define RELEVANCE_Outpost            RELEVANCE_Outpost
  #define RELEVANCE_Huge               RELEVANCE_Huge
  #define RELEVANCE_MAX                RELEVANCE_MAX
  #define ERelevanceDistance_Lootable  RELEVANCE_Lootable
  #define ERelevanceDistance_Outpost   RELEVANCE_Outpost
  #define ERelevanceDistance_Huge      RELEVANCE_Huge
  #define ERelevanceDistance_MAX       RELEVANCE_MAX
} ERelevanceDistance;
typedef enum EOnTouchEventOutputs : unsigned char {
  EONTOUCH_Player,                // 0
  EONTOUCH_NotPlayer,             // 1
  EONTOUCH_MAX                    // 2
  #define EONTOUCH_Player                 EONTOUCH_Player
  #define EONTOUCH_NotPlayer              EONTOUCH_NotPlayer
  #define EONTOUCH_MAX                    EONTOUCH_MAX
  #define EOnTouchEventOutputs_Player     EONTOUCH_Player
  #define EOnTouchEventOutputs_NotPlayer  EONTOUCH_NotPlayer
  #define EOnTouchEventOutputs_MAX        EONTOUCH_MAX
} EOnTouchEventOutputs;
#define ERelevanceDistance    ERelevanceDistance
#define EOnTouchEventOutputs  EOnTouchEventOutputs

/* ---------------------------------------------------------- AWillowMind ! ---------------------------------------------------------- */

typedef enum EScriptFocus  : unsigned char {
  ESF_Path,                       // 0
  ESF_Target,                     // 1
  ESF_MAX                         // 2
  #define ESF_Path             ESF_Path
  #define ESF_Target           ESF_Target
  #define ESF_MAX              ESF_MAX
  #define EScriptFocus_Path    ESF_Path
  #define EScriptFocus_Target  ESF_Target
  #define EScriptFocus_MAX     ESF_MAX
} EScriptFocus;
typedef enum AIWeaponState : unsigned char {
  AIWeaponState_Firing,           // 0
  AIWeaponState_NotFiring,        // 1
  AIWeaponState_FiringPaused,     // 2
  AIWeaponState_MAX               // 3
  #define AIWeaponState_Firing        AIWeaponState_Firing
  #define AIWeaponState_NotFiring     AIWeaponState_NotFiring
  #define AIWeaponState_FiringPaused  AIWeaponState_FiringPaused
  #define AIWeaponState_MAX           AIWeaponState_MAX
} AIWeaponState;
#define EScriptFocus   EScriptFocus
#define AIWeaponState  AIWeaponState

/* ---------------------------------------------------------- AWillowAIPawn ! ---------------------------------------------------------- */

typedef enum EStaggerState : unsigned char {
  ESTAGGER_Staggered,             // 0
  ESTAGGER_Unstaggering,          // 1
  ESTAGGER_BlendAnimStart,        // 2
  ESTAGGER_BlendAnimEnd,          // 3
  ESTAGGER_MAX                    // 4
  #define ESTAGGER_Staggered            ESTAGGER_Staggered
  #define ESTAGGER_Unstaggering         ESTAGGER_Unstaggering
  #define ESTAGGER_BlendAnimStart       ESTAGGER_BlendAnimStart
  #define ESTAGGER_BlendAnimEnd         ESTAGGER_BlendAnimEnd
  #define ESTAGGER_MAX                  ESTAGGER_MAX
  #define EStaggerState_Staggered       ESTAGGER_Staggered
  #define EStaggerState_Unstaggering    ESTAGGER_Unstaggering
  #define EStaggerState_BlendAnimStart  ESTAGGER_BlendAnimStart
  #define EStaggerState_BlendAnimEnd    ESTAGGER_BlendAnimEnd
  #define EStaggerState_MAX             ESTAGGER_MAX
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
  #define DenStat_None        DenStat_None
  #define DenStat_Injured     DenStat_Injured
  #define DenStat_OnFire      DenStat_OnFire
  #define DenStat_Corrosive   DenStat_Corrosive
  #define DenStat_Shocked     DenStat_Shocked
  #define DenStat_Slagged     DenStat_Slagged
  #define DenStat_Slowed      DenStat_Slowed
  #define DenStat_Healing     DenStat_Healing
  #define DenStat_MAX         DenStat_MAX
  #define EDenStat_None       DenStat_None
  #define EDenStat_Injured    DenStat_Injured
  #define EDenStat_OnFire     DenStat_OnFire
  #define EDenStat_Corrosive  DenStat_Corrosive
  #define EDenStat_Shocked    DenStat_Shocked
  #define EDenStat_Slagged    DenStat_Slagged
  #define EDenStat_Slowed     DenStat_Slowed
  #define EDenStat_Healing    DenStat_Healing
  #define EDenStat_MAX        DenStat_MAX
} EDenStat;
#define EStaggerState  EStaggerState
#define EDenStat       EDenStat

/* ---------------------------------------------------------- ACoverLink ! ---------------------------------------------------------- */

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
  #define CA_Default               CA_Default
  #define CA_BlindLeft             CA_BlindLeft
  #define CA_BlindRight            CA_BlindRight
  #define CA_LeanLeft              CA_LeanLeft
  #define CA_LeanRight             CA_LeanRight
  #define CA_StepLeft              CA_StepLeft
  #define CA_StepRight             CA_StepRight
  #define CA_PopUp                 CA_PopUp
  #define CA_BlindUp               CA_BlindUp
  #define CA_PeekLeft              CA_PeekLeft
  #define CA_PeekRight             CA_PeekRight
  #define CA_PeekUp                CA_PeekUp
  #define CA_MAX                   CA_MAX
  #define ECoverAction_Default     CA_Default
  #define ECoverAction_BlindLeft   CA_BlindLeft
  #define ECoverAction_BlindRight  CA_BlindRight
  #define ECoverAction_LeanLeft    CA_LeanLeft
  #define ECoverAction_LeanRight   CA_LeanRight
  #define ECoverAction_StepLeft    CA_StepLeft
  #define ECoverAction_StepRight   CA_StepRight
  #define ECoverAction_PopUp       CA_PopUp
  #define ECoverAction_BlindUp     CA_BlindUp
  #define ECoverAction_PeekLeft    CA_PeekLeft
  #define ECoverAction_PeekRight   CA_PeekRight
  #define ECoverAction_PeekUp      CA_PeekUp
  #define ECoverAction_MAX         CA_MAX
} ECoverAction;
typedef enum ECoverDirection           : unsigned char {
  CD_Default,                     // 0
  CD_Left,                        // 1
  CD_Right,                       // 2
  CD_Up,                          // 3
  CD_MAX                          // 4
  #define CD_Default               CD_Default
  #define CD_Left                  CD_Left
  #define CD_Right                 CD_Right
  #define CD_Up                    CD_Up
  #define CD_MAX                   CD_MAX
  #define ECoverDirection_Default  CD_Default
  #define ECoverDirection_Left     CD_Left
  #define ECoverDirection_Right    CD_Right
  #define ECoverDirection_Up       CD_Up
  #define ECoverDirection_MAX      CD_MAX
} ECoverDirection;
typedef enum ECoverType                : unsigned char {
  CT_None,                        // 0
  CT_Standing,                    // 1
  CT_MidLevel,                    // 2
  CT_MAX                          // 3
  #define CT_None              CT_None
  #define CT_Standing          CT_Standing
  #define CT_MidLevel          CT_MidLevel
  #define CT_MAX               CT_MAX
  #define ECoverType_None      CT_None
  #define ECoverType_Standing  CT_Standing
  #define ECoverType_MidLevel  CT_MidLevel
  #define ECoverType_MAX       CT_MAX
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
  #define CoverDesc_None                            CoverDesc_None
  #define CoverDesc_InWindow                        CoverDesc_InWindow
  #define CoverDesc_InDoorway                       CoverDesc_InDoorway
  #define CoverDesc_BehindCar                       CoverDesc_BehindCar
  #define CoverDesc_BehindTruck                     CoverDesc_BehindTruck
  #define CoverDesc_OnTruck                         CoverDesc_OnTruck
  #define CoverDesc_BehindBarrier                   CoverDesc_BehindBarrier
  #define CoverDesc_BehindColumn                    CoverDesc_BehindColumn
  #define CoverDesc_BehindCrate                     CoverDesc_BehindCrate
  #define CoverDesc_BehindWall                      CoverDesc_BehindWall
  #define CoverDesc_BehindStatue                    CoverDesc_BehindStatue
  #define CoverDesc_BehindSandbags                  CoverDesc_BehindSandbags
  #define CoverDesc_MAX                             CoverDesc_MAX
  #define ECoverLocationDescription_None            CoverDesc_None
  #define ECoverLocationDescription_InWindow        CoverDesc_InWindow
  #define ECoverLocationDescription_InDoorway       CoverDesc_InDoorway
  #define ECoverLocationDescription_BehindCar       CoverDesc_BehindCar
  #define ECoverLocationDescription_BehindTruck     CoverDesc_BehindTruck
  #define ECoverLocationDescription_OnTruck         CoverDesc_OnTruck
  #define ECoverLocationDescription_BehindBarrier   CoverDesc_BehindBarrier
  #define ECoverLocationDescription_BehindColumn    CoverDesc_BehindColumn
  #define ECoverLocationDescription_BehindCrate     CoverDesc_BehindCrate
  #define ECoverLocationDescription_BehindWall      CoverDesc_BehindWall
  #define ECoverLocationDescription_BehindStatue    CoverDesc_BehindStatue
  #define ECoverLocationDescription_BehindSandbags  CoverDesc_BehindSandbags
  #define ECoverLocationDescription_MAX             CoverDesc_MAX
} ECoverLocationDescription;
typedef enum EFireLinkID               : unsigned char {
  FLI_FireLink,                   // 0
  FLI_RejectedFireLink,           // 1
  FLI_MAX                         // 2
  #define FLI_FireLink                  FLI_FireLink
  #define FLI_RejectedFireLink          FLI_RejectedFireLink
  #define FLI_MAX                       FLI_MAX
  #define EFireLinkID_FireLink          FLI_FireLink
  #define EFireLinkID_RejectedFireLink  FLI_RejectedFireLink
  #define EFireLinkID_MAX               FLI_MAX
} EFireLinkID;
#define ECoverAction               ECoverAction
#define ECoverDirection            ECoverDirection
#define ECoverType                 ECoverType
#define ECoverLocationDescription  ECoverLocationDescription
#define EFireLinkID                EFireLinkID
_DECL_TARRAY(ECoverAction);

/* ---------------------------------------------------------- ANavigationPoint ! ---------------------------------------------------------- */

typedef enum ENodeSearchType  : unsigned char {
  NODE_Ambush,                    // 0
  NODE_PointOfInterest,           // 1
  NODE_MAX                        // 2
  #define NODE_Ambush                      NODE_Ambush
  #define NODE_PointOfInterest             NODE_PointOfInterest
  #define NODE_MAX                         NODE_MAX
  #define ENodeSearchType_Ambush           NODE_Ambush
  #define ENodeSearchType_PointOfInterest  NODE_PointOfInterest
  #define ENodeSearchType_MAX              NODE_MAX
} ENodeSearchType;
#define ENodeSearchType  ENodeSearchType

/* ---------------------------------------------------------- UDynamicLightEnvironmentComponent ! ---------------------------------------------------------- */

typedef enum EDynamicLightEnvironmentBoundsMethod : unsigned char {
  DLEB_OwnerComponents,           // 0
  DLEB_ManualOverride,            // 1
  DLEB_ActiveComponents,          // 2
  DLEB_MAX                        // 3
  #define DLEB_OwnerComponents                                   DLEB_OwnerComponents
  #define DLEB_ManualOverride                                    DLEB_ManualOverride
  #define DLEB_ActiveComponents                                  DLEB_ActiveComponents
  #define DLEB_MAX                                               DLEB_MAX
  #define EDynamicLightEnvironmentBoundsMethod_OwnerComponents   DLEB_OwnerComponents
  #define EDynamicLightEnvironmentBoundsMethod_ManualOverride    DLEB_ManualOverride
  #define EDynamicLightEnvironmentBoundsMethod_ActiveComponents  DLEB_ActiveComponents
  #define EDynamicLightEnvironmentBoundsMethod_MAX               DLEB_MAX
} EDynamicLightEnvironmentBoundsMethod;
#define EDynamicLightEnvironmentBoundsMethod  EDynamicLightEnvironmentBoundsMethod

/* ---------------------------------------------------------- UICounterBehavior ! ---------------------------------------------------------- */

typedef enum EBehaviorCounterID    : unsigned char {
  BCOUNTER_1,                     // 0
  BCOUNTER_2,                     // 1
  BCOUNTER_MAX                    // 2
  #define BCOUNTER_1              BCOUNTER_1
  #define BCOUNTER_2              BCOUNTER_2
  #define BCOUNTER_MAX            BCOUNTER_MAX
  #define EBehaviorCounterID_1    BCOUNTER_1
  #define EBehaviorCounterID_2    BCOUNTER_2
  #define EBehaviorCounterID_MAX  BCOUNTER_MAX
} EBehaviorCounterID;
typedef enum EBehaviorCounterEvent : unsigned char {
  COUNTEREVENT_Counter1AtTarget,  // 0
  COUNTEREVENT_Counter2AtTarget,  // 1
  COUNTEREVENT_MAX                // 2
  #define COUNTEREVENT_Counter1AtTarget           COUNTEREVENT_Counter1AtTarget
  #define COUNTEREVENT_Counter2AtTarget           COUNTEREVENT_Counter2AtTarget
  #define COUNTEREVENT_MAX                        COUNTEREVENT_MAX
  #define EBehaviorCounterEvent_Counter1AtTarget  COUNTEREVENT_Counter1AtTarget
  #define EBehaviorCounterEvent_Counter2AtTarget  COUNTEREVENT_Counter2AtTarget
  #define EBehaviorCounterEvent_MAX               COUNTEREVENT_MAX
} EBehaviorCounterEvent;
#define EBehaviorCounterID     EBehaviorCounterID
#define EBehaviorCounterEvent  EBehaviorCounterEvent

/* ---------------------------------------------------------- UPawnAllegiance ! ---------------------------------------------------------- */

typedef enum EOpinion : unsigned char {
  OPINION_Enemy,                  // 0
  OPINION_Neutral,                // 1
  OPINION_Friendly,               // 2
  OPINION_MAX                     // 3
  #define OPINION_Enemy      OPINION_Enemy
  #define OPINION_Neutral    OPINION_Neutral
  #define OPINION_Friendly   OPINION_Friendly
  #define OPINION_MAX        OPINION_MAX
  #define EOpinion_Enemy     OPINION_Enemy
  #define EOpinion_Neutral   OPINION_Neutral
  #define EOpinion_Friendly  OPINION_Friendly
  #define EOpinion_MAX       OPINION_MAX
} EOpinion;
#define EOpinion  EOpinion

/* ---------------------------------------------------------- UInterpTrackMove ! ---------------------------------------------------------- */

typedef enum EInterpTrackMoveFrame   : unsigned char {
  IMF_World,                      // 0
  IMF_RelativeToInitial,          // 1
  IMF_MAX                         // 2
  #define IMF_World                               IMF_World
  #define IMF_RelativeToInitial                   IMF_RelativeToInitial
  #define IMF_MAX                                 IMF_MAX
  #define EInterpTrackMoveFrame_World             IMF_World
  #define EInterpTrackMoveFrame_RelativeToInitial IMF_RelativeToInitial
  #define EInterpTrackMoveFrame_MAX               IMF_MAX
} EInterpTrackMoveFrame;
typedef enum EInterpTrackMoveRotMode : unsigned char {
  IMR_Keyframed,                  // 0
  IMR_LookAtGroup,                // 1
  IMR_Ignore,                     // 2
  IMR_MAX                         // 3
  #define IMR_Keyframed                        IMR_Keyframed
  #define IMR_LookAtGroup                      IMR_LookAtGroup
  #define IMR_Ignore                           IMR_Ignore
  #define IMR_MAX                              IMR_MAX
  #define EInterpTrackMoveRotMode_Keyframed    IMR_Keyframed
  #define EInterpTrackMoveRotMode_LookAtGroup  IMR_LookAtGroup
  #define EInterpTrackMoveRotMode_Ignore       IMR_Ignore
  #define EInterpTrackMoveRotMode_MAX          IMR_MAX
} EInterpTrackMoveRotMode;
#define EInterpTrackMoveFrame    EInterpTrackMoveFrame
#define EInterpTrackMoveRotMode  EInterpTrackMoveRotMode

/* ---------------------------------------------------------- UAnimNodeSequence ! ---------------------------------------------------------- */

typedef enum ERootBoneAxis       : unsigned char {
  RBA_Default,                    // 0
  RBA_Discard,                    // 1
  RBA_Translate,                  // 2
  RBA_MAX                         // 3
  #define RBA_Default              RBA_Default
  #define RBA_Discard              RBA_Discard
  #define RBA_Translate            RBA_Translate
  #define RBA_MAX                  RBA_MAX
  #define ERootBoneAxis_Default    RBA_Default
  #define ERootBoneAxis_Discard    RBA_Discard
  #define ERootBoneAxis_Translate  RBA_Translate
  #define ERootBoneAxis_MAX        RBA_MAX
} ERootBoneAxis;
typedef enum ERootRotationOption : unsigned char {
  RRO_Default,                    // 0
  RRO_Discard,                    // 1
  RRO_Extract,                    // 2
  RRO_MAX                         // 3
  #define RRO_Default                  RRO_Default
  #define RRO_Discard                  RRO_Discard
  #define RRO_Extract                  RRO_Extract
  #define RRO_MAX                      RRO_MAX
  #define ERootRotationOption_Default  RRO_Default
  #define ERootRotationOption_Discard  RRO_Discard
  #define ERootRotationOption_Extract  RRO_Extract
  #define ERootRotationOption_MAX      RRO_MAX
} ERootRotationOption;
#define ERootBoneAxis        ERootBoneAxis
#define ERootRotationOption  ERootRotationOption

/* ---------------------------------------------------------- UModel ! ---------------------------------------------------------- */

enum { MAX_NODES         = 65536  };
enum { MAX_POINTS        = 128000 };
enum { MAX_NODE_VERTICES = 255    };  /** Max vertices in a Bsp node. */
enum { MAX_ZONES         = 64     };  /** Max zones per level. */

/* Flags associated with a Bsp node. */
typedef enum EBspNodeFlags : unsigned char {
	NF_NotCsg         = 0x01,  /* Node is not a Csg splitter, i.e. is a transparent poly. */
	NF_NotVisBlocking = 0x04,  /* Node does not block visibility, i.e. is an invisible collision hull. */
	NF_BrightCorners  = 0x10,  /* Temporary. */
	NF_IsNew          = 0x20,  /* Editor: Node was newly-added. */
	NF_IsFront        = 0x40,  /* Filter operation bounding-sphere precomputed and guaranteed to be front. */
	NF_IsBack         = 0x80,  /* Guaranteed back. */
  #define NF_NotCsg                     NF_NotCsg
  #define NF_NotVisBlocking             NF_NotVisBlocking
  #define NF_BrightCorners              NF_BrightCorners
  #define NF_IsNew                      NF_IsNew
  #define NF_IsFront                    NF_IsFront
  #define NF_IsBack                     NF_IsBack
  #define EBspNodeFlags_NotCsg          NF_NotCsg
  #define EBspNodeFlags_NotVisBlocking  NF_NotVisBlocking
  #define EBspNodeFlags_BrightCorners   NF_BrightCorners
  #define EBspNodeFlags_IsNew           NF_IsNew
  #define EBspNodeFlags_IsFront         NF_IsFront
  #define EBspNodeFlags_IsBack          NF_IsBack
} EBspNodeFlags;
#define EBspNodeFlags  EBspNodeFlags

/* ---------------------------------------------------------- UGameplayEvents ! ---------------------------------------------------------- */

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
  #define GSG_EngineStats               GSG_EngineStats
  #define GSG_Game                      GSG_Game
  #define GSG_Team                      GSG_Team
  #define GSG_Player                    GSG_Player
  #define GSG_Weapon                    GSG_Weapon
  #define GSG_Damage                    GSG_Damage
  #define GSG_Projectile                GSG_Projectile
  #define GSG_Pawn                      GSG_Pawn
  #define GSG_GameSpecific              GSG_GameSpecific
  #define GSG_Aggregate                 GSG_Aggregate
  #define GSG_MAX                       GSG_MAX
  #define EGameStatGroups_EngineStats   GSG_EngineStats
  #define EGameStatGroups_Game          GSG_Game
  #define EGameStatGroups_Team          GSG_Team
  #define EGameStatGroups_Player        GSG_Player
  #define EGameStatGroups_Weapon        GSG_Weapon
  #define EGameStatGroups_Damage        GSG_Damage
  #define EGameStatGroups_Projectile    GSG_Projectile
  #define EGameStatGroups_Pawn          GSG_Pawn
  #define EGameStatGroups_GameSpecific  GSG_GameSpecific
  #define EGameStatGroups_Aggregate     GSG_Aggregate
  #define EGameStatGroups_MAX           GSG_MAX
} EGameStatGroups;
#define EGameStatGroups  EGameStatGroups

/* ---------------------------------------------------------- FGameEventType ! ---------------------------------------------------------- */

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
  #define GET_GameString                          GET_GameString
  #define GET_GameInt                             GET_GameInt
  #define GET_TeamInt                             GET_TeamInt
  #define GET_PlayerInt                           GET_PlayerInt
  #define GET_PlayerFloat                         GET_PlayerFloat
  #define GET_PlayerString                        GET_PlayerString
  #define GET_PlayerSpawn                         GET_PlayerSpawn
  #define GET_PlayerLogin                         GET_PlayerLogin
  #define GET_PlayerLocationPoll                  GET_PlayerLocationPoll
  #define GET_PlayerKillDeath                     GET_PlayerKillDeath
  #define GET_PlayerPlayer                        GET_PlayerPlayer
  #define GET_WeaponInt                           GET_WeaponInt
  #define GET_DamageInt                           GET_DamageInt
  #define GET_ProjectileInt                       GET_ProjectileInt
  #define GET_GenericParamList                    GET_GenericParamList
  #define GET_GameFloat                           GET_GameFloat
  #define GET_TeamString                          GET_TeamString
  #define GET_TeamFloat                           GET_TeamFloat
  #define GET_GamePosition                        GET_GamePosition
  #define GET_GameAggregate                       GET_GameAggregate
  #define GET_TeamAggregate                       GET_TeamAggregate
  #define GET_PlayerAggregate                     GET_PlayerAggregate
  #define GET_WeaponAggregate                     GET_WeaponAggregate
  #define GET_DamageAggregate                     GET_DamageAggregate
  #define GET_ProjectileAggregate                 GET_ProjectileAggregate
  #define GET_PawnAggregate                       GET_PawnAggregate
  #define GET_GameType                            GET_GameType
  #define EGameplayEventType_GameString           GET_GameString
  #define EGameplayEventType_GameInt              GET_GameInt
  #define EGameplayEventType_TeamInt              GET_TeamInt
  #define EGameplayEventType_PlayerInt            GET_PlayerInt
  #define EGameplayEventType_PlayerFloat          GET_PlayerFloat
  #define EGameplayEventType_PlayerString         GET_PlayerString
  #define EGameplayEventType_PlayerSpawn          GET_PlayerSpawn
  #define EGameplayEventType_PlayerLogin          GET_PlayerLogin
  #define EGameplayEventType_PlayerLocationPoll   GET_PlayerLocationPoll
  #define EGameplayEventType_PlayerKillDeath      GET_PlayerKillDeath
  #define EGameplayEventType_PlayerPlayer         GET_PlayerPlayer
  #define EGameplayEventType_WeaponInt            GET_WeaponInt
  #define EGameplayEventType_DamageInt            GET_DamageInt
  #define EGameplayEventType_ProjectileInt        GET_ProjectileInt
  #define EGameplayEventType_GenericParamList     GET_GenericParamList
  #define EGameplayEventType_GameFloat            GET_GameFloat
  #define EGameplayEventType_TeamString           GET_TeamString
  #define EGameplayEventType_TeamFloat            GET_TeamFloat
  #define EGameplayEventType_GamePosition         GET_GamePosition
  #define EGameplayEventType_GameAggregate        GET_GameAggregate
  #define EGameplayEventType_TeamAggregate        GET_TeamAggregate
  #define EGameplayEventType_PlayerAggregate      GET_PlayerAggregate
  #define EGameplayEventType_WeaponAggregate      GET_WeaponAggregate
  #define EGameplayEventType_DamageAggregate      GET_DamageAggregate
  #define EGameplayEventType_ProjectileAggregate  GET_ProjectileAggregate
  #define EGameplayEventType_PawnAggregate        GET_PawnAggregate
  #define EGameplayEventType_GameType             GET_GameType
} EGameplayEventType;
#define EGameplayEventType  EGameplayEventType

/* ---------------------------------------------------------- ULocalMessage ! ---------------------------------------------------------- */

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
  #define LMT_Training                    LMT_Training
  #define LMT_ContextHint                 LMT_ContextHint
  #define LMT_XP                          LMT_XP
  #define LMT_Player                      LMT_Player
  #define LMT_System                      LMT_System
  #define LMT_ReceivedLoot                LMT_ReceivedLoot
  #define LMT_OpenedChest                 LMT_OpenedChest
  #define LMT_Chat                        LMT_Chat
  #define LMT_MAX                         LMT_MAX
  #define ELocalMessageType_Training      LMT_Training
  #define ELocalMessageType_ContextHint   LMT_ContextHint
  #define ELocalMessageType_XP            LMT_XP
  #define ELocalMessageType_Player        LMT_Player
  #define ELocalMessageType_System        LMT_System
  #define ELocalMessageType_ReceivedLoot  LMT_ReceivedLoot
  #define ELocalMessageType_OpenedChest   LMT_OpenedChest
  #define ELocalMessageType_Chat          LMT_Chat
  #define ELocalMessageType_MAX           LMT_MAX
} ELocalMessageType;
#define ELocalMessageType  ELocalMessageType

/* ---------------------------------------------------------- UReceivedAmmoMessage ! ---------------------------------------------------------- */

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
  #define RECEIVEDAMMO_CombatRifle        RECEIVEDAMMO_CombatRifle
  #define RECEIVEDAMMO_SMG                RECEIVEDAMMO_SMG
  #define RECEIVEDAMMO_Revolver           RECEIVEDAMMO_Revolver
  #define RECEIVEDAMMO_Repeater           RECEIVEDAMMO_Repeater
  #define RECEIVEDAMMO_Shotgun            RECEIVEDAMMO_Shotgun
  #define RECEIVEDAMMO_SniperRifle        RECEIVEDAMMO_SniperRifle
  #define RECEIVEDAMMO_Rocket             RECEIVEDAMMO_Rocket
  #define RECEIVEDAMMO_Grenade            RECEIVEDAMMO_Grenade
  #define RECEIVEDAMMO_MAX                RECEIVEDAMMO_MAX
  #define EAmmoMessageSwitch_CombatRifle  RECEIVEDAMMO_CombatRifle
  #define EAmmoMessageSwitch_SMG          RECEIVEDAMMO_SMG
  #define EAmmoMessageSwitch_Revolver     RECEIVEDAMMO_Revolver
  #define EAmmoMessageSwitch_Repeater     RECEIVEDAMMO_Repeater
  #define EAmmoMessageSwitch_Shotgun      RECEIVEDAMMO_Shotgun
  #define EAmmoMessageSwitch_SniperRifle  RECEIVEDAMMO_SniperRifle
  #define EAmmoMessageSwitch_Rocket       RECEIVEDAMMO_Rocket
  #define EAmmoMessageSwitch_Grenade      RECEIVEDAMMO_Grenade
  #define EAmmoMessageSwitch_MAX          RECEIVEDAMMO_MAX
} EAmmoMessageSwitch;
#define EAmmoMessageSwitch  EAmmoMessageSwitch

/* ---------------------------------------------------------- UParticleModule ! ---------------------------------------------------------- */

typedef enum EModuleType : unsigned char {
  EPMT_General,                   // 0
  EPMT_TypeData,                  // 1
  EPMT_Beam,                      // 2
  EPMT_Trail,                     // 3
  EPMT_Spawn,                     // 4
  EPMT_Required,                  // 5
  EPMT_Event,                     // 6
  EPMT_MAX                        // 7
  #define EPMT_General          EPMT_General
  #define EPMT_TypeData         EPMT_TypeData
  #define EPMT_Beam             EPMT_Beam
  #define EPMT_Trail            EPMT_Trail
  #define EPMT_Spawn            EPMT_Spawn
  #define EPMT_Required         EPMT_Required
  #define EPMT_Event            EPMT_Event
  #define EPMT_MAX              EPMT_MAX
  #define EModuleType_General   EPMT_General
  #define EModuleType_TypeData  EPMT_TypeData
  #define EModuleType_Beam      EPMT_Beam
  #define EModuleType_Trail     EPMT_Trail
  #define EModuleType_Spawn     EPMT_Spawn
  #define EModuleType_Required  EPMT_Required
  #define EModuleType_Event     EPMT_Event
  #define EModuleType_MAX       EPMT_MAX
} EModuleType;
typedef enum EParticleSourceSelectionMethod : unsigned char {
  EPSSM_Random,                   // 0
  EPSSM_Sequential,               // 1
  EPSSM_MAX                       // 2
  #define EPSSM_Random                               EPSSM_Random
  #define EPSSM_Sequential                           EPSSM_Sequential
  #define EPSSM_MAX                                  EPSSM_MAX
  #define EParticleSourceSelectionMethod_Random      EPSSM_Random
  #define EParticleSourceSelectionMethod_Sequential  EPSSM_Sequential
  #define EParticleSourceSelectionMethod_MAX         EPSSM_MAX
} EParticleSourceSelectionMethod;
#define EModuleType                     EModuleType
#define EParticleSourceSelectionMethod  EParticleSourceSelectionMethod

/* ---------------------------------------------------------- UParticleEmitter ! ---------------------------------------------------------- */

typedef enum EParticleBurstMethod       : unsigned char {
  EPBM_Instant,                   // 0
  EPBM_Interpolated,              // 1
  EPBM_MAX                        // 2
  #define EPBM_Instant                       EPBM_Instant
  #define EPBM_Interpolated                  EPBM_Interpolated
  #define EPBM_MAX                           EPBM_MAX
  #define EParticleBurstMethod_Instant       EPBM_Instant
  #define EParticleBurstMethod_Interpolated  EPBM_Interpolated
  #define EParticleBurstMethod_MAX           EPBM_MAX
} EParticleBurstMethod;
typedef enum EParticleSubUVInterpMethod : unsigned char {
  PSUVIM_None,                    // 0
  PSUVIM_Linear,                  // 1
  PSUVIM_Linear_Blend,            // 2
  PSUVIM_Random,                  // 3
  PSUVIM_Random_Blend,            // 4
  PSUVIM_MAX                      // 5
  #define PSUVIM_None                              PSUVIM_None
  #define PSUVIM_Linear                            PSUVIM_Linear
  #define PSUVIM_Linear_Blend                      PSUVIM_Linear_Blend
  #define PSUVIM_Random                            PSUVIM_Random
  #define PSUVIM_Random_Blend                      PSUVIM_Random_Blend
  #define PSUVIM_MAX                               PSUVIM_MAX
  #define EParticleSubUVInterpMethod_None          PSUVIM_None
  #define EParticleSubUVInterpMethod_Linear        PSUVIM_Linear
  #define EParticleSubUVInterpMethod_Linear_Blend  PSUVIM_Linear_Blend
  #define EParticleSubUVInterpMethod_Random        PSUVIM_Random
  #define EParticleSubUVInterpMethod_Random_Blend  PSUVIM_Random_Blend
  #define EParticleSubUVInterpMethod_MAX           PSUVIM_MAX
} EParticleSubUVInterpMethod;
typedef enum EEmitterRenderMode         : unsigned char {
  ERM_Normal,                     // 0
  ERM_Point,                      // 1
  ERM_Cross,                      // 2
  ERM_None,                       // 3
  ERM_MAX                         // 4
  #define ERM_Normal                 ERM_Normal
  #define ERM_Point                  ERM_Point
  #define ERM_Cross                  ERM_Cross
  #define ERM_None                   ERM_None
  #define ERM_MAX                    ERM_MAX
  #define EEmitterRenderMode_Normal  ERM_Normal
  #define EEmitterRenderMode_Point   ERM_Point
  #define EEmitterRenderMode_Cross   ERM_Cross
  #define EEmitterRenderMode_None    ERM_None
  #define EEmitterRenderMode_MAX     ERM_MAX
} EEmitterRenderMode;
#define EParticleBurstMethod        EParticleBurstMethod
#define EParticleSubUVInterpMethod  EParticleSubUVInterpMethod
#define EEmitterRenderMode          EEmitterRenderMode

/* ---------------------------------------------------------- FSimpleElementVertex ! ---------------------------------------------------------- */

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
  #define SE_BLEND_Opaque                                           SE_BLEND_Opaque
  #define SE_BLEND_Masked                                           SE_BLEND_Masked
  #define SE_BLEND_Translucent                                      SE_BLEND_Translucent
  #define SE_BLEND_Additive                                         SE_BLEND_Additive
  #define SE_BLEND_Modulate                                         SE_BLEND_Modulate
  #define SE_BLEND_MaskedDistanceField                              SE_BLEND_MaskedDistanceField
  #define SE_BLEND_MaskedDistanceFieldShadowed                      SE_BLEND_MaskedDistanceFieldShadowed
  #define SE_BLEND_TranslucentDistanceField                         SE_BLEND_TranslucentDistanceField
  #define SE_BLEND_TranslucentDistanceFieldShadowed                 SE_BLEND_TranslucentDistanceFieldShadowed
  #define SE_BLEND_AlphaComposite                                   SE_BLEND_AlphaComposite
  #define SE_BLEND_RGBA_MASK_START                                  SE_BLEND_RGBA_MASK_START
  #define SE_BLEND_RGBA_MASK_END                                    SE_BLEND_RGBA_MASK_END
  #define SE_BLEND_MAX                                              SE_BLEND_MAX
  #define ESimpleElementBlendMode_Opaque                            SE_BLEND_Opaque
  #define ESimpleElementBlendMode_Masked                            SE_BLEND_Masked
  #define ESimpleElementBlendMode_Translucent                       SE_BLEND_Translucent
  #define ESimpleElementBlendMode_Additive                          SE_BLEND_Additive
  #define ESimpleElementBlendMode_Modulate                          SE_BLEND_Modulate
  #define ESimpleElementBlendMode_MaskedDistanceField               SE_BLEND_MaskedDistanceField
  #define ESimpleElementBlendMode_MaskedDistanceFieldShadowed       SE_BLEND_MaskedDistanceFieldShadowed
  #define ESimpleElementBlendMode_TranslucentDistanceField          SE_BLEND_TranslucentDistanceField
  #define ESimpleElementBlendMode_TranslucentDistanceFieldShadowed  SE_BLEND_TranslucentDistanceFieldShadowed
  #define ESimpleElementBlendMode_AlphaComposite                    SE_BLEND_AlphaComposite
  #define ESimpleElementBlendMode_RGBA_MASK_START                   SE_BLEND_RGBA_MASK_START
  #define ESimpleElementBlendMode_RGBA_MASK_END                     SE_BLEND_RGBA_MASK_END
  #define ESimpleElementBlendMode_MAX                               SE_BLEND_MAX
} ESimpleElementBlendMode;
#define ESimpleElementBlendMode  ESimpleElementBlendMode

/* ---------------------------------------------------------- FCanvas ! ---------------------------------------------------------- */

/** Enum that describes what type of element we are currently batching. */
typedef enum EElementType      : unsigned char {
  ET_Line,
  ET_Triangle,
  ET_MAX
  #define ET_Line                ET_Line
  #define ET_Triangle            ET_Triangle
  #define ET_MAX                 ET_MAX
  #define EElementType_Line      ET_Line
  #define EElementType_Triangle  ET_Triangle
  #define EElementType_MAX       ET_MAX
} EElementType;
/** Enum for canvas features that are allowed. */
typedef enum ECanvasAllowModes : unsigned char {
  Allow_MaskedRegions  = (1 << 0),  /** Stencil masked regions. */
  Allow_DepthTest      = (1 << 1),  /** Depth testing. */
  Allow_Flush          = (1 << 2),  /** Flushing and rendering. */
  Allow_DeleteOnRender = (1 << 3)   /** Delete the render batches when rendering. */
  #define Allow_MaskedRegions               Allow_MaskedRegions
  #define Allow_DepthTest                   Allow_DepthTest
  #define Allow_Flush                       Allow_Flush
  #define Allow_DeleteOnRender              Allow_DeleteOnRender
  #define ECanvasAllowModes_MaskedRegions   Allow_MaskedRegions
  #define ECanvasAllowModes_DepthTest       Allow_DepthTest
  #define ECanvasAllowModes_Flush           Allow_Flush
  #define ECanvasAllowModes_DeleteOnRender  Allow_DeleteOnRender
} ECanvasAllowModes;
#define EElementType       EElementType
#define ECanvasAllowModes  ECanvasAllowModes

/* ---------------------------------------------------------- UPhysicalMaterial ! ---------------------------------------------------------- */

typedef enum EPhysEffectType : unsigned char {
  EPMET_Impact,                   // 0
  EPMET_Slide,                    // 1
  EPMET_MAX                       // 2
  #define EPMET_Impact            EPMET_Impact
  #define EPMET_Slide             EPMET_Slide
  #define EPMET_MAX               EPMET_MAX
  #define EPhysEffectType_Impact  EPMET_Impact
  #define EPhysEffectType_Slide   EPMET_Slide
  #define EPhysEffectType_MAX     EPMET_MAX
} EPhysEffectType;
#define EPhysEffectType  EPhysEffectType

/* ---------------------------------------------------------- USkillDefinition ! ---------------------------------------------------------- */

typedef enum EEffectDurationType       : unsigned char {
  DURATION_Infinite,              // 0
  DURATION_Timed,                 // 1
  DURATION_MAX                    // 2
  #define DURATION_Infinite             DURATION_Infinite
  #define DURATION_Timed                DURATION_Timed
  #define DURATION_MAX                  DURATION_MAX
  #define EEffectDurationType_Infinite  DURATION_Infinite
  #define EEffectDurationType_Timed     DURATION_Timed
  #define EEffectDurationType_MAX       DURATION_MAX
} EEffectDurationType;
typedef enum EEffectTarget             : unsigned char {
  TARGET_None,                    // 0
  TARGET_Self,                    // 1
  TARGET_Allies,                  // 2
  TARGET_Enemies,                 // 3
  TARGET_All,                     // 4
  TARGET_Pets,                    // 5
  TARGET_MAX                      // 6
  #define TARGET_None            TARGET_None
  #define TARGET_Self            TARGET_Self
  #define TARGET_Allies          TARGET_Allies
  #define TARGET_Enemies         TARGET_Enemies
  #define TARGET_All             TARGET_All
  #define TARGET_Pets            TARGET_Pets
  #define TARGET_MAX             TARGET_MAX
  #define EEffectTarget_None     TARGET_None
  #define EEffectTarget_Self     TARGET_Self
  #define EEffectTarget_Allies   TARGET_Allies
  #define EEffectTarget_Enemies  TARGET_Enemies
  #define EEffectTarget_All      TARGET_All
  #define EEffectTarget_Pets     TARGET_Pets
  #define EEffectTarget_MAX      TARGET_MAX
} EEffectTarget;
typedef enum ETargetCriteria           : unsigned char {
  CRITERIA_None,                  // 0
  CRITERIA_Nearest,               // 1
  CRITERIA_MAX                    // 2
  #define CRITERIA_None            CRITERIA_None
  #define CRITERIA_Nearest         CRITERIA_Nearest
  #define CRITERIA_MAX             CRITERIA_MAX
  #define ETargetCriteria_None     CRITERIA_None
  #define ETargetCriteria_Nearest  CRITERIA_Nearest
  #define ETargetCriteria_MAX      CRITERIA_MAX
} ETargetCriteria;
typedef enum ESkillState               : unsigned char {
  SKILL_Deactivated,              // 0
  SKILL_Active,                   // 1
  SKILL_Paused,                   // 2
  SKILL_MAX                       // 3
  #define SKILL_Deactivated        SKILL_Deactivated
  #define SKILL_Active             SKILL_Active
  #define SKILL_Paused             SKILL_Paused
  #define SKILL_MAX                SKILL_MAX
  #define ESkillState_Deactivated  SKILL_Deactivated
  #define ESkillState_Active       SKILL_Active
  #define ESkillState_Paused       SKILL_Paused
  #define ESkillState_MAX          SKILL_MAX
} ESkillState;
typedef enum ESkillType                : unsigned char {
  SKILL_TYPE_Passive,             // 0
  SKILL_TYPE_Action,              // 1
  SKILL_TYPE_ActionAugment,       // 2
  SKILL_TYPE_Kill,                // 3
  SKILL_TYPE_Proficiency,         // 4
  SKILL_TYPE_MAX                  // 5
  #define SKILL_TYPE_Passive        SKILL_TYPE_Passive
  #define SKILL_TYPE_Action         SKILL_TYPE_Action
  #define SKILL_TYPE_ActionAugment  SKILL_TYPE_ActionAugment
  #define SKILL_TYPE_Kill           SKILL_TYPE_Kill
  #define SKILL_TYPE_Proficiency    SKILL_TYPE_Proficiency
  #define SKILL_TYPE_MAX            SKILL_TYPE_MAX
  #define ESkillType_Passive        SKILL_TYPE_Passive
  #define ESkillType_Action         SKILL_TYPE_Action
  #define ESkillType_ActionAugment  SKILL_TYPE_ActionAugment
  #define ESkillType_Kill           SKILL_TYPE_Kill
  #define ESkillType_Proficiency    SKILL_TYPE_Proficiency
  #define ESkillType_MAX                               SKILL_TYPE_MAX
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
  #define SEVT_SkillActivated                                  SEVT_SkillActivated
  #define SEVT_SkillDeactivated                                SEVT_SkillDeactivated
  #define SEVT_SkillPaused                                     SEVT_SkillPaused
  #define SEVT_SkillResumed                                    SEVT_SkillResumed
  #define SEVT_DamagedEnemy                                    SEVT_DamagedEnemy
  #define SEVT_DamagedFriendly                                 SEVT_DamagedFriendly
  #define SEVT_DamagedNeutral                                  SEVT_DamagedNeutral
  #define SEVT_DamagedByEnemy                                  SEVT_DamagedByEnemy
  #define SEVT_DamagedByFriendly                               SEVT_DamagedByFriendly
  #define SEVT_DamagedByNeutral                                SEVT_DamagedByNeutral
  #define SEVT_ShieldDepletedAfterBeingFull                    SEVT_ShieldDepletedAfterBeingFull
  #define SEVT_KilledEnemy                                     SEVT_KilledEnemy
  #define SEVT_KilledFriendly                                  SEVT_KilledFriendly
  #define SEVT_KilledNeutral                                   SEVT_KilledNeutral
  #define SEVT_KilledByEnemy                                   SEVT_KilledByEnemy
  #define SEVT_KilledByFriendly                                SEVT_KilledByFriendly
  #define SEVT_KilledByNeutral                                 SEVT_KilledByNeutral
  #define SEVT_WeaponZoomed                                    SEVT_WeaponZoomed
  #define SEVT_WeaponUnzoomed                                  SEVT_WeaponUnzoomed
  #define SEVT_WeaponShotMissed                                SEVT_WeaponShotMissed
  #define SEVT_WeaponFired                                     SEVT_WeaponFired
  #define SEVT_WeaponReloaded                                  SEVT_WeaponReloaded
  #define SEVT_PlayerDeathAverted                              SEVT_PlayerDeathAverted
  #define SEVT_ActionSkillCooldownAbilityActivated             SEVT_ActionSkillCooldownAbilityActivated
  #define SEVT_ActionSkillActiveAbilityActivated               SEVT_ActionSkillActiveAbilityActivated
  #define SEVT_DamagedUnawareEnemy                             SEVT_DamagedUnawareEnemy
  #define SEVT_DamagedEnemyWithMeleeFromBehind                 SEVT_DamagedEnemyWithMeleeFromBehind
  #define SEVT_MeleeOverrideSkillActivated                     SEVT_MeleeOverrideSkillActivated
  #define SEVT_ThrowGrenadeOverrideSkillActivated              SEVT_ThrowGrenadeOverrideSkillActivated
  #define SEVT_WeaponSwapped                                   SEVT_WeaponSwapped
  #define SEVT_PlayerRecoveredFromDownState                    SEVT_PlayerRecoveredFromDownState
  #define SEVT_ShieldDepleted                                  SEVT_ShieldDepleted
  #define SEVT_ShieldFull                                      SEVT_ShieldFull
  #define SEVT_WeaponStartReload                               SEVT_WeaponStartReload
  #define SEVT_PlayerResurrected                               SEVT_PlayerResurrected
  #define SEVT_WeaponManuallyReloaded                          SEVT_WeaponManuallyReloaded
  #define SEVT_AppliedStatusEffectToEnemy                      SEVT_AppliedStatusEffectToEnemy
  #define SEVT_DownStateBegin                                  SEVT_DownStateBegin
  #define SEVT_DownStateEnd                                    SEVT_DownStateEnd
  #define SEVT_BledOut                                         SEVT_BledOut
  #define SEVT_OnStatusEffectTypeBegin                         SEVT_OnStatusEffectTypeBegin
  #define SEVT_OnStatusEffectTypeEnd                           SEVT_OnStatusEffectTypeEnd
  #define SEVT_MeleeAttack                                     SEVT_MeleeAttack
  #define SEVT_MAX                                             SEVT_MAX
  #define ESkillEventType_SkillActivated                       SEVT_SkillActivated
  #define ESkillEventType_SkillDeactivated                     SEVT_SkillDeactivated
  #define ESkillEventType_SkillPaused                          SEVT_SkillPaused
  #define ESkillEventType_SkillResumed                         SEVT_SkillResumed
  #define ESkillEventType_DamagedEnemy                         SEVT_DamagedEnemy
  #define ESkillEventType_DamagedFriendly                      SEVT_DamagedFriendly
  #define ESkillEventType_DamagedNeutral                       SEVT_DamagedNeutral
  #define ESkillEventType_DamagedByEnemy                       SEVT_DamagedByEnemy
  #define ESkillEventType_DamagedByFriendly                    SEVT_DamagedByFriendly
  #define ESkillEventType_DamagedByNeutral                     SEVT_DamagedByNeutral
  #define ESkillEventType_ShieldDepletedAfterBeingFull         SEVT_ShieldDepletedAfterBeingFull
  #define ESkillEventType_KilledEnemy                          SEVT_KilledEnemy
  #define ESkillEventType_KilledFriendly                       SEVT_KilledFriendly
  #define ESkillEventType_KilledNeutral                        SEVT_KilledNeutral
  #define ESkillEventType_KilledByEnemy                        SEVT_KilledByEnemy
  #define ESkillEventType_KilledByFriendly                     SEVT_KilledByFriendly
  #define ESkillEventType_KilledByNeutral                      SEVT_KilledByNeutral
  #define ESkillEventType_WeaponZoomed                         SEVT_WeaponZoomed
  #define ESkillEventType_WeaponUnzoomed                       SEVT_WeaponUnzoomed
  #define ESkillEventType_WeaponShotMissed                     SEVT_WeaponShotMissed
  #define ESkillEventType_WeaponFired                          SEVT_WeaponFired
  #define ESkillEventType_WeaponReloaded                       SEVT_WeaponReloaded
  #define ESkillEventType_PlayerDeathAverted                   SEVT_PlayerDeathAverted
  #define ESkillEventType_ActionSkillCooldownAbilityActivated  SEVT_ActionSkillCooldownAbilityActivated
  #define ESkillEventType_ActionSkillActiveAbilityActivated    SEVT_ActionSkillActiveAbilityActivated
  #define ESkillEventType_DamagedUnawareEnemy                  SEVT_DamagedUnawareEnemy
  #define ESkillEventType_DamagedEnemyWithMeleeFromBehind      SEVT_DamagedEnemyWithMeleeFromBehind
  #define ESkillEventType_MeleeOverrideSkillActivated          SEVT_MeleeOverrideSkillActivated
  #define ESkillEventType_ThrowGrenadeOverrideSkillActivated   SEVT_ThrowGrenadeOverrideSkillActivated
  #define ESkillEventType_WeaponSwapped                        SEVT_WeaponSwapped
  #define ESkillEventType_PlayerRecoveredFromDownState         SEVT_PlayerRecoveredFromDownState
  #define ESkillEventType_ShieldDepleted                       SEVT_ShieldDepleted
  #define ESkillEventType_ShieldFull                           SEVT_ShieldFull
  #define ESkillEventType_WeaponStartReload                    SEVT_WeaponStartReload
  #define ESkillEventType_PlayerResurrected                    SEVT_PlayerResurrected
  #define ESkillEventType_WeaponManuallyReloaded               SEVT_WeaponManuallyReloaded
  #define ESkillEventType_AppliedStatusEffectToEnemy           SEVT_AppliedStatusEffectToEnemy
  #define ESkillEventType_DownStateBegin                       SEVT_DownStateBegin
  #define ESkillEventType_DownStateEnd                         SEVT_DownStateEnd
  #define ESkillEventType_BledOut                              SEVT_BledOut
  #define ESkillEventType_OnStatusEffectTypeBegin              SEVT_OnStatusEffectTypeBegin
  #define ESkillEventType_OnStatusEffectTypeEnd                SEVT_OnStatusEffectTypeEnd
  #define ESkillEventType_MeleeAttack                          SEVT_MeleeAttack
  #define ESkillEventType_MAX                                  SEVT_MAX
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
  #define SDEVT_DamagedEnemy                                   SDEVT_DamagedEnemy
  #define SDEVT_DamagedFriendly                                SDEVT_DamagedFriendly
  #define SDEVT_DamagedNeutral                                 SDEVT_DamagedNeutral
  #define SDEVT_DamagedByEnemy                                 SDEVT_DamagedByEnemy
  #define SDEVT_DamagedByFriendly                              SDEVT_DamagedByFriendly
  #define SDEVT_DamagedByNeutral                               SDEVT_DamagedByNeutral
  #define SDEVT_ShieldDepletedAfterBeingFull                   SDEVT_ShieldDepletedAfterBeingFull
  #define SDEVT_MAX                                            SDEVT_MAX
  #define ESkillDamagedEventType_DamagedEnemy                  SDEVT_DamagedEnemy
  #define ESkillDamagedEventType_DamagedFriendly               SDEVT_DamagedFriendly
  #define ESkillDamagedEventType_DamagedNeutral                SDEVT_DamagedNeutral
  #define ESkillDamagedEventType_DamagedByEnemy                SDEVT_DamagedByEnemy
  #define ESkillDamagedEventType_DamagedByFriendly             SDEVT_DamagedByFriendly
  #define ESkillDamagedEventType_DamagedByNeutral              SDEVT_DamagedByNeutral
  #define ESkillDamagedEventType_ShieldDepletedAfterBeingFull  SDEVT_ShieldDepletedAfterBeingFull
  #define ESkillDamagedEventType_MAX                           SDEVT_MAX
} ESkillDamagedEventType;
typedef enum ESkillKilledEventType     : unsigned char {
  SKEVT_KilledEnemy,              // 0
  SKEVT_KilledFriendly,           // 1
  SKEVT_KilledNeutral,            // 2
  SKEVT_KilledByEnemy,            // 3
  SKEVT_KilledByFriendly,         // 4
  SKEVT_KilledByNeutral,          // 5
  SKEVT_MAX                       // 6
  #define SKEVT_KilledEnemy                       SKEVT_KilledEnemy
  #define SKEVT_KilledFriendly                    SKEVT_KilledFriendly
  #define SKEVT_KilledNeutral                     SKEVT_KilledNeutral
  #define SKEVT_KilledByEnemy                     SKEVT_KilledByEnemy
  #define SKEVT_KilledByFriendly                  SKEVT_KilledByFriendly
  #define SKEVT_KilledByNeutral                   SKEVT_KilledByNeutral
  #define SKEVT_MAX                               SKEVT_MAX
  #define ESkillKilledEventType_KilledEnemy       SKEVT_KilledEnemy
  #define ESkillKilledEventType_KilledFriendly    SKEVT_KilledFriendly
  #define ESkillKilledEventType_KilledNeutral     SKEVT_KilledNeutral
  #define ESkillKilledEventType_KilledByEnemy     SKEVT_KilledByEnemy
  #define ESkillKilledEventType_KilledByFriendly  SKEVT_KilledByFriendly
  #define ESkillKilledEventType_KilledByNeutral   SKEVT_KilledByNeutral
  #define ESkillKilledEventType_MAX               SKEVT_MAX
} ESkillKilledEventType;
typedef enum ESkillEventGradeType      : unsigned char {
  SEVG_PlayerSkillGrade,          // 0
  SEVG_HardcodedGrade,            // 1
  SEVG_SameAsThisSkillGrade,      // 2
  SEVG_MAX                        // 3
  #define SEVG_PlayerSkillGrade                      SEVG_PlayerSkillGrade
  #define SEVG_HardcodedGrade                        SEVG_HardcodedGrade
  #define SEVG_SameAsThisSkillGrade                  SEVG_SameAsThisSkillGrade
  #define SEVG_MAX                                   SEVG_MAX
  #define ESkillEventGradeType_PlayerSkillGrade      SEVG_PlayerSkillGrade
  #define ESkillEventGradeType_HardcodedGrade        SEVG_HardcodedGrade
  #define ESkillEventGradeType_SameAsThisSkillGrade  SEVG_SameAsThisSkillGrade
  #define ESkillEventGradeType_MAX                   SEVG_MAX
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
  #define TRACKEDSKILL_Untracked                   TRACKEDSKILL_Untracked
  #define TRACKEDSKILL_Kill                        TRACKEDSKILL_Kill
  #define TRACKEDSKILL_Triggered                   TRACKEDSKILL_Triggered
  #define TRACKEDSKILL_Respond                     TRACKEDSKILL_Respond
  #define TRACKEDSKILL_ConsumableBuff              TRACKEDSKILL_ConsumableBuff
  #define TRACKEDSKILL_MeleeOverride               TRACKEDSKILL_MeleeOverride
  #define TRACKEDSKILL_TriggeredNotSkillTree       TRACKEDSKILL_TriggeredNotSkillTree
  #define TRACKEDSKILL_MAX                         TRACKEDSKILL_MAX
  #define ETrackedSkillType_Untracked              TRACKEDSKILL_Untracked
  #define ETrackedSkillType_Kill                   TRACKEDSKILL_Kill
  #define ETrackedSkillType_Triggered              TRACKEDSKILL_Triggered
  #define ETrackedSkillType_Respond                TRACKEDSKILL_Respond
  #define ETrackedSkillType_ConsumableBuff         TRACKEDSKILL_ConsumableBuff
  #define ETrackedSkillType_MeleeOverride          TRACKEDSKILL_MeleeOverride
  #define ETrackedSkillType_TriggeredNotSkillTree  TRACKEDSKILL_TriggeredNotSkillTree
  #define ETrackedSkillType_MAX                    TRACKEDSKILL_MAX
} ETrackedSkillType;
typedef enum ERequiredActionSkillState : unsigned char {
  ERASS_Ignore,                   // 0
  ERASS_MustBeRunning,            // 1
  ERASS_MustNotBeRunning,         // 2
  ERASS_MAX                       // 3
  #define ERASS_Ignore                                ERASS_Ignore
  #define ERASS_MustBeRunning                         ERASS_MustBeRunning
  #define ERASS_MustNotBeRunning                      ERASS_MustNotBeRunning
  #define ERASS_MAX                                   ERASS_MAX
  #define ERequiredActionSkillState_Ignore            ERASS_Ignore
  #define ERequiredActionSkillState_MustBeRunning     ERASS_MustBeRunning
  #define ERequiredActionSkillState_MustNotBeRunning  ERASS_MustNotBeRunning
  #define ERequiredActionSkillState_MAX               ERASS_MAX
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
  #define SDE_DamagedEnemy                                        SDE_DamagedEnemy
  #define SDE_DamagedFriendly                                     SDE_DamagedFriendly
  #define SDE_DamagedByEnemy                                      SDE_DamagedByEnemy
  #define SDE_DamagedByFriendly                                   SDE_DamagedByFriendly
  #define SDE_DamagedNeutral_Deprecated                           SDE_DamagedNeutral_Deprecated
  #define SDE_DamagedByNeutral_Deprecated                         SDE_DamagedByNeutral_Deprecated
  #define SDE_DamagedUnawareEnemy                                 SDE_DamagedUnawareEnemy
  #define SDE_DamagedEnemyWithMeleeFromBehind                     SDE_DamagedEnemyWithMeleeFromBehind
  #define SDE_DamagedEnemyExposeDamageSurfaceType                 SDE_DamagedEnemyExposeDamageSurfaceType
  #define SDE_MAX                                                 SDE_MAX
  #define ESkillDamageEvents_DamagedEnemy                         SDE_DamagedEnemy
  #define ESkillDamageEvents_DamagedFriendly                      SDE_DamagedFriendly
  #define ESkillDamageEvents_DamagedByEnemy                       SDE_DamagedByEnemy
  #define ESkillDamageEvents_DamagedByFriendly                    SDE_DamagedByFriendly
  #define ESkillDamageEvents_DamagedNeutral_Deprecated            SDE_DamagedNeutral_Deprecated
  #define ESkillDamageEvents_DamagedByNeutral_Deprecated          SDE_DamagedByNeutral_Deprecated
  #define ESkillDamageEvents_DamagedUnawareEnemy                  SDE_DamagedUnawareEnemy
  #define ESkillDamageEvents_DamagedEnemyWithMeleeFromBehind      SDE_DamagedEnemyWithMeleeFromBehind
  #define ESkillDamageEvents_DamagedEnemyExposeDamageSurfaceType  SDE_DamagedEnemyExposeDamageSurfaceType
  #define ESkillDamageEvents_MAX                                  SDE_MAX
} ESkillDamageEvents;
typedef enum ESkillKillEvents          : unsigned char {
  SKE_KilledEnemy,                // 0
  SKE_KilledByEnemy,              // 1
  SKE_MAX                         // 2
  #define SKE_KilledEnemy                 SKE_KilledEnemy
  #define SKE_KilledByEnemy               SKE_KilledByEnemy
  #define SKE_MAX                         SKE_MAX
  #define ESkillKillEvents_KilledEnemy    SKE_KilledEnemy
  #define ESkillKillEvents_KilledByEnemy  SKE_KilledByEnemy
  #define ESkillKillEvents_MAX            SKE_MAX
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

/* ---------------------------------------------------------- UAchievementUtility ! ---------------------------------------------------------- */

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
  #define WA_Invalid                                         WA_Invalid
  #define WA_PlotMission1                                    WA_PlotMission1
  #define WA_PlotMission2                                    WA_PlotMission2
  #define WA_PlotMission3                                    WA_PlotMission3
  #define WA_PlotMission4                                    WA_PlotMission4
  #define WA_PlotMission5                                    WA_PlotMission5
  #define WA_PlotMission6                                    WA_PlotMission6
  #define WA_PlotMission7                                    WA_PlotMission7
  #define WA_PlotMission8                                    WA_PlotMission8
  #define WA_PlotMission9                                    WA_PlotMission9
  #define WA_PlotMission10                                   WA_PlotMission10
  #define WA_PlotMission11                                   WA_PlotMission11
  #define WA_PlotMission12                                   WA_PlotMission12
  #define WA_PlotMission13                                   WA_PlotMission13
  #define WA_PlotMission14                                   WA_PlotMission14
  #define WA_PlotMission15                                   WA_PlotMission15
  #define WA_PlotMission16                                   WA_PlotMission16
  #define WA_ChallengeAccepted                               WA_ChallengeAccepted
  #define WA_GoliathMeetDavid                                WA_GoliathMeetDavid
  #define WA_WentFiveRounds                                  WA_WentFiveRounds
  #define WA_NotQuiteDead                                    WA_NotQuiteDead
  #define WA_BetterThanYouWere                               WA_BetterThanYouWere
  #define WA_AlwaysImproving                                 WA_AlwaysImproving
  #define WA_CappedOutForNow                                 WA_CappedOutForNow
  #define WA_ArcticExplorer                                  WA_ArcticExplorer
  #define WA_UrbanExplorer                                   WA_UrbanExplorer
  #define WA_HighlandsExplorer                               WA_HighlandsExplorer
  #define WA_BlightExplorer                                  WA_BlightExplorer
  #define WA_WorldTraveler                                   WA_WorldTraveler
  #define WA_SugarDaddy                                      WA_SugarDaddy
  #define WA_DeckedOut                                       WA_DeckedOut
  #define WA_SabreRattler                                    WA_SabreRattler
  #define WA_PhasedAndConfused                               WA_PhasedAndConfused
  #define WA_SoMuchBlood                                     WA_SoMuchBlood
  #define WA_CuteLoot                                        WA_CuteLoot
  #define WA_TributeToAVaultHunter                           WA_TributeToAVaultHunter
  #define WA_DefinitelyAnItalianPlumber                      WA_DefinitelyAnItalianPlumber
  #define WA_HighFlyingHurler                                WA_HighFlyingHurler
  #define WA_TokenGesture                                    WA_TokenGesture
  #define WA_WhatDoesItMean                                  WA_WhatDoesItMean
  #define WA_UnseenPredator                                  WA_UnseenPredator
  #define WA_BuildBuster                                     WA_BuildBuster
  #define WA_WellThatWasEasy                                 WA_WellThatWasEasy
  #define WA_HowDoILook                                      WA_HowDoILook
  #define WA_ThresherThrashed                                WA_ThresherThrashed
  #define WA_FriendshipRules                                 WA_FriendshipRules
  #define WA_BetterThanMoney                                 WA_BetterThanMoney
  #define WA_UpHighDownLow                                   WA_UpHighDownLow
  #define WA_BountyHunter                                    WA_BountyHunter
  #define WA_DidItAll                                        WA_DidItAll
  #define WA_FeelsLikeTheFirstTime                           WA_FeelsLikeTheFirstTime
  #define WA_DLC1_Achievement1                               WA_DLC1_Achievement1
  #define WA_DLC1_Achievement2                               WA_DLC1_Achievement2
  #define WA_DLC1_Achievement3                               WA_DLC1_Achievement3
  #define WA_Iris_CompleteMainCampaign                       WA_Iris_CompleteMainCampaign
  #define WA_Iris_CompleteSideMissions                       WA_Iris_CompleteSideMissions
  #define WA_Iris_CollectItems                               WA_Iris_CollectItems
  #define WA_Sage_CompleteMainCampaign                       WA_Sage_CompleteMainCampaign
  #define WA_Sage_CompleteSideMissions                       WA_Sage_CompleteSideMissions
  #define WA_Sage_DiscoverAllAreas                           WA_Sage_DiscoverAllAreas
  #define WA_DLCReserved_10                                  WA_DLCReserved_10
  #define WA_DLCReserved_11                                  WA_DLCReserved_11
  #define WA_DLCReserved_12                                  WA_DLCReserved_12
  #define WA_DLCReserved_13                                  WA_DLCReserved_13
  #define WA_DLCReserved_14                                  WA_DLCReserved_14
  #define WA_DLCReserved_15                                  WA_DLCReserved_15
  #define WA_DLCReserved_16                                  WA_DLCReserved_16
  #define WA_DLCReserved_17                                  WA_DLCReserved_17
  #define WA_DLCReserved_18                                  WA_DLCReserved_18
  #define WA_DLCReserved_19                                  WA_DLCReserved_19
  #define WA_DLCReserved_20                                  WA_DLCReserved_20
  #define WA_DLCReserved_21                                  WA_DLCReserved_21
  #define WA_DLCReserved_22                                  WA_DLCReserved_22
  #define WA_DLCReserved_23                                  WA_DLCReserved_23
  #define WA_DLCReserved_24                                  WA_DLCReserved_24
  #define WA_DLCReserved_25                                  WA_DLCReserved_25
  #define WA_DLCReserved_26                                  WA_DLCReserved_26
  #define WA_DLCReserved_27                                  WA_DLCReserved_27
  #define WA_DLCReserved_28                                  WA_DLCReserved_28
  #define WA_DLCReserved_29                                  WA_DLCReserved_29
  #define WA_DLCReserved_30                                  WA_DLCReserved_30
  #define WA_DLCReserved_31                                  WA_DLCReserved_31
  #define WA_DLCReserved_32                                  WA_DLCReserved_32
  #define WA_DLCReserved_33                                  WA_DLCReserved_33
  #define WA_DLCReserved_34                                  WA_DLCReserved_34
  #define WA_DLCReserved_35                                  WA_DLCReserved_35
  #define WA_DLCReserved_36                                  WA_DLCReserved_36
  #define WA_DLCReserved_37                                  WA_DLCReserved_37
  #define WA_DLCReserved_38                                  WA_DLCReserved_38
  #define WA_DLCReserved_39                                  WA_DLCReserved_39
  #define WA_DLCReserved_40                                  WA_DLCReserved_40
  #define WA_DLCReserved_41                                  WA_DLCReserved_41
  #define WA_DLCReserved_42                                  WA_DLCReserved_42
  #define WA_DLCReserved_43                                  WA_DLCReserved_43
  #define WA_DLCReserved_44                                  WA_DLCReserved_44
  #define WA_DLCReserved_45                                  WA_DLCReserved_45
  #define WA_DLCReserved_46                                  WA_DLCReserved_46
  #define WA_DLCReserved_47                                  WA_DLCReserved_47
  #define WA_DLCReserved_48                                  WA_DLCReserved_48
  #define WA_DLCReserved_49                                  WA_DLCReserved_49
  #define WA_MAX                                             WA_MAX
  #define EWillowAchievementList_Invalid                     WA_Invalid
  #define EWillowAchievementList_PlotMission1                WA_PlotMission1
  #define EWillowAchievementList_PlotMission2                WA_PlotMission2
  #define EWillowAchievementList_PlotMission3                WA_PlotMission3
  #define EWillowAchievementList_PlotMission4                WA_PlotMission4
  #define EWillowAchievementList_PlotMission5                WA_PlotMission5
  #define EWillowAchievementList_PlotMission6                WA_PlotMission6
  #define EWillowAchievementList_PlotMission7                WA_PlotMission7
  #define EWillowAchievementList_PlotMission8                WA_PlotMission8
  #define EWillowAchievementList_PlotMission9                WA_PlotMission9
  #define EWillowAchievementList_PlotMission10               WA_PlotMission10
  #define EWillowAchievementList_PlotMission11               WA_PlotMission11
  #define EWillowAchievementList_PlotMission12               WA_PlotMission12
  #define EWillowAchievementList_PlotMission13               WA_PlotMission13
  #define EWillowAchievementList_PlotMission14               WA_PlotMission14
  #define EWillowAchievementList_PlotMission15               WA_PlotMission15
  #define EWillowAchievementList_PlotMission16               WA_PlotMission16
  #define EWillowAchievementList_ChallengeAccepted           WA_ChallengeAccepted
  #define EWillowAchievementList_GoliathMeetDavid            WA_GoliathMeetDavid
  #define EWillowAchievementList_WentFiveRounds              WA_WentFiveRounds
  #define EWillowAchievementList_NotQuiteDead                WA_NotQuiteDead
  #define EWillowAchievementList_BetterThanYouWere           WA_BetterThanYouWere
  #define EWillowAchievementList_AlwaysImproving             WA_AlwaysImproving
  #define EWillowAchievementList_CappedOutForNow             WA_CappedOutForNow
  #define EWillowAchievementList_ArcticExplorer              WA_ArcticExplorer
  #define EWillowAchievementList_UrbanExplorer               WA_UrbanExplorer
  #define EWillowAchievementList_HighlandsExplorer           WA_HighlandsExplorer
  #define EWillowAchievementList_BlightExplorer              WA_BlightExplorer
  #define EWillowAchievementList_WorldTraveler               WA_WorldTraveler
  #define EWillowAchievementList_SugarDaddy                  WA_SugarDaddy
  #define EWillowAchievementList_DeckedOut                   WA_DeckedOut
  #define EWillowAchievementList_SabreRattler                WA_SabreRattler
  #define EWillowAchievementList_PhasedAndConfused           WA_PhasedAndConfused
  #define EWillowAchievementList_SoMuchBlood                 WA_SoMuchBlood
  #define EWillowAchievementList_CuteLoot                    WA_CuteLoot
  #define EWillowAchievementList_TributeToAVaultHunter       WA_TributeToAVaultHunter
  #define EWillowAchievementList_DefinitelyAnItalianPlumber  WA_DefinitelyAnItalianPlumber
  #define EWillowAchievementList_HighFlyingHurler            WA_HighFlyingHurler
  #define EWillowAchievementList_TokenGesture                WA_TokenGesture
  #define EWillowAchievementList_WhatDoesItMean              WA_WhatDoesItMean
  #define EWillowAchievementList_UnseenPredator              WA_UnseenPredator
  #define EWillowAchievementList_BuildBuster                 WA_BuildBuster
  #define EWillowAchievementList_WellThatWasEasy             WA_WellThatWasEasy
  #define EWillowAchievementList_HowDoILook                  WA_HowDoILook
  #define EWillowAchievementList_ThresherThrashed            WA_ThresherThrashed
  #define EWillowAchievementList_FriendshipRules             WA_FriendshipRules
  #define EWillowAchievementList_BetterThanMoney             WA_BetterThanMoney
  #define EWillowAchievementList_UpHighDownLow               WA_UpHighDownLow
  #define EWillowAchievementList_BountyHunter                WA_BountyHunter
  #define EWillowAchievementList_DidItAll                    WA_DidItAll
  #define EWillowAchievementList_FeelsLikeTheFirstTime       WA_FeelsLikeTheFirstTime
  #define EWillowAchievementList_DLC1_Achievement1           WA_DLC1_Achievement1
  #define EWillowAchievementList_DLC1_Achievement2           WA_DLC1_Achievement2
  #define EWillowAchievementList_DLC1_Achievement3           WA_DLC1_Achievement3
  #define EWillowAchievementList_Iris_CompleteMainCampaign   WA_Iris_CompleteMainCampaign
  #define EWillowAchievementList_Iris_CompleteSideMissions   WA_Iris_CompleteSideMissions
  #define EWillowAchievementList_Iris_CollectItems           WA_Iris_CollectItems
  #define EWillowAchievementList_Sage_CompleteMainCampaign   WA_Sage_CompleteMainCampaign
  #define EWillowAchievementList_Sage_CompleteSideMissions   WA_Sage_CompleteSideMissions
  #define EWillowAchievementList_Sage_DiscoverAllAreas       WA_Sage_DiscoverAllAreas
  #define EWillowAchievementList_DLCReserved_10              WA_DLCReserved_10
  #define EWillowAchievementList_DLCReserved_11              WA_DLCReserved_11
  #define EWillowAchievementList_DLCReserved_12              WA_DLCReserved_12
  #define EWillowAchievementList_DLCReserved_13              WA_DLCReserved_13
  #define EWillowAchievementList_DLCReserved_14              WA_DLCReserved_14
  #define EWillowAchievementList_DLCReserved_15              WA_DLCReserved_15
  #define EWillowAchievementList_DLCReserved_16              WA_DLCReserved_16
  #define EWillowAchievementList_DLCReserved_17              WA_DLCReserved_17
  #define EWillowAchievementList_DLCReserved_18              WA_DLCReserved_18
  #define EWillowAchievementList_DLCReserved_19              WA_DLCReserved_19
  #define EWillowAchievementList_DLCReserved_20              WA_DLCReserved_20
  #define EWillowAchievementList_DLCReserved_21              WA_DLCReserved_21
  #define EWillowAchievementList_DLCReserved_22              WA_DLCReserved_22
  #define EWillowAchievementList_DLCReserved_23              WA_DLCReserved_23
  #define EWillowAchievementList_DLCReserved_24              WA_DLCReserved_24
  #define EWillowAchievementList_DLCReserved_25              WA_DLCReserved_25
  #define EWillowAchievementList_DLCReserved_26              WA_DLCReserved_26
  #define EWillowAchievementList_DLCReserved_27              WA_DLCReserved_27
  #define EWillowAchievementList_DLCReserved_28              WA_DLCReserved_28
  #define EWillowAchievementList_DLCReserved_29              WA_DLCReserved_29
  #define EWillowAchievementList_DLCReserved_30              WA_DLCReserved_30
  #define EWillowAchievementList_DLCReserved_31              WA_DLCReserved_31
  #define EWillowAchievementList_DLCReserved_32              WA_DLCReserved_32
  #define EWillowAchievementList_DLCReserved_33              WA_DLCReserved_33
  #define EWillowAchievementList_DLCReserved_34              WA_DLCReserved_34
  #define EWillowAchievementList_DLCReserved_35              WA_DLCReserved_35
  #define EWillowAchievementList_DLCReserved_36              WA_DLCReserved_36
  #define EWillowAchievementList_DLCReserved_37              WA_DLCReserved_37
  #define EWillowAchievementList_DLCReserved_38              WA_DLCReserved_38
  #define EWillowAchievementList_DLCReserved_39              WA_DLCReserved_39
  #define EWillowAchievementList_DLCReserved_40              WA_DLCReserved_40
  #define EWillowAchievementList_DLCReserved_41              WA_DLCReserved_41
  #define EWillowAchievementList_DLCReserved_42              WA_DLCReserved_42
  #define EWillowAchievementList_DLCReserved_43              WA_DLCReserved_43
  #define EWillowAchievementList_DLCReserved_44              WA_DLCReserved_44
  #define EWillowAchievementList_DLCReserved_45              WA_DLCReserved_45
  #define EWillowAchievementList_DLCReserved_46              WA_DLCReserved_46
  #define EWillowAchievementList_DLCReserved_47              WA_DLCReserved_47
  #define EWillowAchievementList_DLCReserved_48              WA_DLCReserved_48
  #define EWillowAchievementList_DLCReserved_49              WA_DLCReserved_49
  #define EWillowAchievementList_MAX                         WA_MAX
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
  #define AUT_ZoneIn                                       AUT_ZoneIn
  #define AUT_EarnMoney                                    AUT_EarnMoney
  #define AUT_LeveledUp                                    AUT_LeveledUp
  #define AUT_InstinctUp                                   AUT_InstinctUp
  #define AUT_FallHeight                                   AUT_FallHeight
  #define AUT_HangTime                                     AUT_HangTime
  #define AUT_QuestCompleted                               AUT_QuestCompleted
  #define AUT_ActionSkillKill                              AUT_ActionSkillKill
  #define AUT_QuestCompletedCoOp                           AUT_QuestCompletedCoOp
  #define AUT_SpeedyTravel                                 AUT_SpeedyTravel
  #define AUT_SpeedyKills                                  AUT_SpeedyKills
  #define AUT_RushTime                                     AUT_RushTime
  #define AUT_InventorySlotChange                          AUT_InventorySlotChange
  #define AUT_KilledLeveledUpPawn                          AUT_KilledLeveledUpPawn
  #define AUT_TokensSpent                                  AUT_TokensSpent
  #define AUT_CustomizationsUnlocks                        AUT_CustomizationsUnlocks
  #define AUT_SideMissionsCompleted                        AUT_SideMissionsCompleted
  #define AUT_PurchasedBlackMarketItem                     AUT_PurchasedBlackMarketItem
  #define AUT_MAX                                          AUT_MAX
  #define EAchievementUnlockType_ZoneIn                    AUT_ZoneIn
  #define EAchievementUnlockType_EarnMoney                 AUT_EarnMoney
  #define EAchievementUnlockType_LeveledUp                 AUT_LeveledUp
  #define EAchievementUnlockType_InstinctUp                AUT_InstinctUp
  #define EAchievementUnlockType_FallHeight                AUT_FallHeight
  #define EAchievementUnlockType_HangTime                  AUT_HangTime
  #define EAchievementUnlockType_QuestCompleted            AUT_QuestCompleted
  #define EAchievementUnlockType_ActionSkillKill           AUT_ActionSkillKill
  #define EAchievementUnlockType_QuestCompletedCoOp        AUT_QuestCompletedCoOp
  #define EAchievementUnlockType_SpeedyTravel              AUT_SpeedyTravel
  #define EAchievementUnlockType_SpeedyKills               AUT_SpeedyKills
  #define EAchievementUnlockType_RushTime                  AUT_RushTime
  #define EAchievementUnlockType_InventorySlotChange       AUT_InventorySlotChange
  #define EAchievementUnlockType_KilledLeveledUpPawn       AUT_KilledLeveledUpPawn
  #define EAchievementUnlockType_TokensSpent               AUT_TokensSpent
  #define EAchievementUnlockType_CustomizationsUnlocks     AUT_CustomizationsUnlocks
  #define EAchievementUnlockType_SideMissionsCompleted     AUT_SideMissionsCompleted
  #define EAchievementUnlockType_PurchasedBlackMarketItem  AUT_PurchasedBlackMarketItem
  #define EAchievementUnlockType_MAX                       AUT_MAX
} EAchievementUnlockType;
#define EWillowAchievementList  EWillowAchievementList
#define EAchievementUnlockType  EAchievementUnlockType
_DECL_TARRAY(EWillowAchievementList);

/* ---------------------------------------------------------- USkeletalMesh ! ---------------------------------------------------------- */

typedef enum BoneBreakOption       : unsigned char {
  BONEBREAK_SoftPreferred,        // 0
  BONEBREAK_AutoDetect,           // 1
  BONEBREAK_RigidPreferred,       // 2
  BONEBREAK_MAX                   // 3
  #define BONEBREAK_SoftPreferred         BONEBREAK_SoftPreferred
  #define BONEBREAK_AutoDetect            BONEBREAK_AutoDetect
  #define BONEBREAK_RigidPreferred        BONEBREAK_RigidPreferred
  #define BONEBREAK_MAX                   BONEBREAK_MAX
  #define BoneBreakOption_SoftPreferred   BONEBREAK_SoftPreferred
  #define BoneBreakOption_AutoDetect      BONEBREAK_AutoDetect
  #define BoneBreakOption_RigidPreferred  BONEBREAK_RigidPreferred
  #define BoneBreakOption_MAX             BONEBREAK_MAX
} BoneBreakOption;
typedef enum TriangleSortOption    : unsigned char {
  TRISORT_None,                   // 0
  TRISORT_CenterRadialDistance,   // 1
  TRISORT_Random,                 // 2
  TRISORT_MergeContiguous,        // 3
  TRISORT_Custom,                 // 4
  TRISORT_CustomLeftRight,        // 5
  TRISORT_MAX                     // 6
  #define TRISORT_None                             TRISORT_None
  #define TRISORT_CenterRadialDistance             TRISORT_CenterRadialDistance
  #define TRISORT_Random                           TRISORT_Random
  #define TRISORT_MergeContiguous                  TRISORT_MergeContiguous
  #define TRISORT_Custom                           TRISORT_Custom
  #define TRISORT_CustomLeftRight                  TRISORT_CustomLeftRight
  #define TRISORT_MAX                              TRISORT_MAX
  #define TriangleSortOption_None                  TRISORT_None
  #define TriangleSortOption_CenterRadialDistance  TRISORT_CenterRadialDistance
  #define TriangleSortOption_Random                TRISORT_Random
  #define TriangleSortOption_MergeContiguous       TRISORT_MergeContiguous
  #define TriangleSortOption_Custom                TRISORT_Custom
  #define TriangleSortOption_CustomLeftRight       TRISORT_CustomLeftRight
  #define TriangleSortOption_MAX                   TRISORT_MAX
} TriangleSortOption;
typedef enum ClothMovementScaleGen : unsigned char {
  ECMDM_DistToFixedVert,          // 0
  ECMDM_VertexBoneWeight,         // 1
  ECMDM_Empty,                    // 2
  ECMDM_MAX                       // 3
  #define ECMDM_DistToFixedVert                   ECMDM_DistToFixedVert
  #define ECMDM_VertexBoneWeight                  ECMDM_VertexBoneWeight
  #define ECMDM_Empty                             ECMDM_Empty
  #define ECMDM_MAX                               ECMDM_MAX
  #define ClothMovementScaleGen_DistToFixedVert   ECMDM_DistToFixedVert
  #define ClothMovementScaleGen_VertexBoneWeight  ECMDM_VertexBoneWeight
  #define ClothMovementScaleGen_Empty             ECMDM_Empty
  #define ClothMovementScaleGen_MAX               ECMDM_MAX
} ClothMovementScaleGen;
typedef enum TriangleSortAxis      : unsigned char {
  TSA_X_Axis,                     // 0
  TSA_Y_Axis,                     // 1
  TSA_Z_Axis,                     // 2
  TSA_MAX                         // 3
  #define TSA_X_Axis               TSA_X_Axis
  #define TSA_Y_Axis               TSA_Y_Axis
  #define TSA_Z_Axis               TSA_Z_Axis
  #define TSA_MAX                  TSA_MAX
  #define TriangleSortAxis_X_Axis  TSA_X_Axis
  #define TriangleSortAxis_Y_Axis  TSA_Y_Axis
  #define TriangleSortAxis_Z_Axis  TSA_Z_Axis
  #define TriangleSortAxis_MAX     TSA_MAX
} TriangleSortAxis;
typedef enum ClothBoneType         : unsigned char {
  CLOTHBONE_Fixed,                // 0
  CLOTHBONE_BreakableAttachment,  // 1
  CLOTHBONE_TearLine,             // 2
  CLOTHBONE_MAX                   // 3
  #define CLOTHBONE_Fixed                    CLOTHBONE_Fixed
  #define CLOTHBONE_BreakableAttachment      CLOTHBONE_BreakableAttachment
  #define CLOTHBONE_TearLine                 CLOTHBONE_TearLine
  #define CLOTHBONE_MAX                      CLOTHBONE_MAX
  #define ClothBoneType_Fixed                CLOTHBONE_Fixed
  #define ClothBoneType_BreakableAttachment  CLOTHBONE_BreakableAttachment
  #define ClothBoneType_TearLine             CLOTHBONE_TearLine
  #define ClothBoneType_MAX                  CLOTHBONE_MAX
} ClothBoneType;
typedef enum SoftBodyBoneType      : unsigned char {
  SOFTBODYBONE_Fixed,             // 0
  SOFTBODYBONE_BreakableAttachment,// 1
  SOFTBODYBONE_TwoWayAttachment,  // 2
  SOFTBODYBONE_MAX                // 3
  #define SOFTBODYBONE_Fixed                    SOFTBODYBONE_Fixed
  #define SOFTBODYBONE_BreakableAttachment      SOFTBODYBONE_BreakableAttachment
  #define SOFTBODYBONE_TwoWayAttachment         SOFTBODYBONE_TwoWayAttachment
  #define SOFTBODYBONE_MAX                      SOFTBODYBONE_MAX
  #define SoftBodyBoneType_Fixed                SOFTBODYBONE_Fixed
  #define SoftBodyBoneType_BreakableAttachment  SOFTBODYBONE_BreakableAttachment
  #define SoftBodyBoneType_TwoWayAttachment     SOFTBODYBONE_TwoWayAttachment
  #define SoftBodyBoneType_MAX                  SOFTBODYBONE_MAX
} SoftBodyBoneType;
#define BoneBreakOption        BoneBreakOption
#define TriangleSortOption     TriangleSortOption
#define ClothMovementScaleGen  ClothMovementScaleGen
#define TriangleSortAxis       TriangleSortAxis
#define ClothBoneType          ClothBoneType
#define SoftBodyBoneType       SoftBodyBoneType
_DECL_TARRAY(BoneBreakOption);
_DECL_TARRAY(TriangleSortOption);

/* ---------------------------------------------------------- UTexture ! ---------------------------------------------------------- */

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
  #define TC_Default                                             TC_Default
  #define TC_Normalmap                                           TC_Normalmap
  #define TC_Displacementmap                                     TC_Displacementmap
  #define TC_NormalmapAlpha                                      TC_NormalmapAlpha
  #define TC_Grayscale                                           TC_Grayscale
  #define TC_HighDynamicRange                                    TC_HighDynamicRange
  #define TC_OneBitAlpha                                         TC_OneBitAlpha
  #define TC_NormalmapUncompressed                               TC_NormalmapUncompressed
  #define TC_NormalmapBC5                                        TC_NormalmapBC5
  #define TC_OneBitMonochrome                                    TC_OneBitMonochrome
  #define TC_SimpleLightmapModification                          TC_SimpleLightmapModification
  #define TC_VectorDisplacementmap                               TC_VectorDisplacementmap
  #define TC_MAX                                                 TC_MAX
  #define TextureCompressionSettings_Default                     TC_Default
  #define TextureCompressionSettings_Normalmap                   TC_Normalmap
  #define TextureCompressionSettings_Displacementmap             TC_Displacementmap
  #define TextureCompressionSettings_NormalmapAlpha              TC_NormalmapAlpha
  #define TextureCompressionSettings_Grayscale                   TC_Grayscale
  #define TextureCompressionSettings_HighDynamicRange            TC_HighDynamicRange
  #define TextureCompressionSettings_OneBitAlpha                 TC_OneBitAlpha
  #define TextureCompressionSettings_NormalmapUncompressed       TC_NormalmapUncompressed
  #define TextureCompressionSettings_NormalmapBC5                TC_NormalmapBC5
  #define TextureCompressionSettings_OneBitMonochrome            TC_OneBitMonochrome
  #define TextureCompressionSettings_SimpleLightmapModification  TC_SimpleLightmapModification
  #define TextureCompressionSettings_VectorDisplacementmap       TC_VectorDisplacementmap
  #define TextureCompressionSettings_MAX                         TC_MAX
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
  #define PF_Unknown                        PF_Unknown
  #define PF_A32B32G32R32F                  PF_A32B32G32R32F
  #define PF_A8R8G8B8                       PF_A8R8G8B8
  #define PF_G8                             PF_G8
  #define PF_G16                            PF_G16
  #define PF_DXT1                           PF_DXT1
  #define PF_DXT3                           PF_DXT3
  #define PF_DXT5                           PF_DXT5
  #define PF_UYVY                           PF_UYVY
  #define PF_FloatRGB                       PF_FloatRGB
  #define PF_FloatRGBA                      PF_FloatRGBA
  #define PF_DepthStencil                   PF_DepthStencil
  #define PF_ShadowDepth                    PF_ShadowDepth
  #define PF_FilteredShadowDepth            PF_FilteredShadowDepth
  #define PF_R32F                           PF_R32F
  #define PF_G16R16                         PF_G16R16
  #define PF_G16R16F                        PF_G16R16F
  #define PF_G16R16F_FILTER                 PF_G16R16F_FILTER
  #define PF_G32R32F                        PF_G32R32F
  #define PF_A2B10G10R10                    PF_A2B10G10R10
  #define PF_A16B16G16R16                   PF_A16B16G16R16
  #define PF_D24                            PF_D24
  #define PF_R16F                           PF_R16F
  #define PF_R16F_FILTER                    PF_R16F_FILTER
  #define PF_BC5                            PF_BC5
  #define PF_V8U8                           PF_V8U8
  #define PF_A1                             PF_A1
  #define PF_FloatR11G11B10                 PF_FloatR11G11B10
  #define PF_MAX                            PF_MAX
  #define EPixelFormat_Unknown              PF_Unknown
  #define EPixelFormat_A32B32G32R32F        PF_A32B32G32R32F
  #define EPixelFormat_A8R8G8B8             PF_A8R8G8B8
  #define EPixelFormat_G8                   PF_G8
  #define EPixelFormat_G16                  PF_G16
  #define EPixelFormat_DXT1                 PF_DXT1
  #define EPixelFormat_DXT3                 PF_DXT3
  #define EPixelFormat_DXT5                 PF_DXT5
  #define EPixelFormat_UYVY                 PF_UYVY
  #define EPixelFormat_FloatRGB             PF_FloatRGB
  #define EPixelFormat_FloatRGBA            PF_FloatRGBA
  #define EPixelFormat_DepthStencil         PF_DepthStencil
  #define EPixelFormat_ShadowDepth          PF_ShadowDepth
  #define EPixelFormat_FilteredShadowDepth  PF_FilteredShadowDepth
  #define EPixelFormat_R32F                 PF_R32F
  #define EPixelFormat_G16R16               PF_G16R16
  #define EPixelFormat_G16R16F              PF_G16R16F
  #define EPixelFormat_G16R16F_FILTER       PF_G16R16F_FILTER
  #define EPixelFormat_G32R32F              PF_G32R32F
  #define EPixelFormat_A2B10G10R10          PF_A2B10G10R10
  #define EPixelFormat_A16B16G16R16         PF_A16B16G16R16
  #define EPixelFormat_D24                  PF_D24
  #define EPixelFormat_R16F                 PF_R16F
  #define EPixelFormat_R16F_FILTER          PF_R16F_FILTER
  #define EPixelFormat_BC5                  PF_BC5
  #define EPixelFormat_V8U8                 PF_V8U8
  #define EPixelFormat_A1                   PF_A1
  #define EPixelFormat_FloatR11G11B10       PF_FloatR11G11B10
  #define EPixelFormat_MAX                  PF_MAX
} EPixelFormat;
typedef enum TextureFilter              : unsigned char {
  TF_Nearest,                     // 0
  TF_Linear,                      // 1
  TF_MAX                          // 2
  #define TF_Nearest             TF_Nearest
  #define TF_Linear              TF_Linear
  #define TF_MAX                 TF_MAX
  #define TextureFilter_Nearest  TF_Nearest
  #define TextureFilter_Linear   TF_Linear
  #define TextureFilter_MAX      TF_MAX
} TextureFilter;
typedef enum TextureAddress             : unsigned char {
  TA_Wrap,                        // 0
  TA_Clamp,                       // 1
  TA_Mirror,                      // 2
  TA_MAX                          // 3
  #define TA_Wrap                TA_Wrap
  #define TA_Clamp               TA_Clamp
  #define TA_Mirror              TA_Mirror
  #define TA_MAX                 TA_MAX
  #define TextureAddress_Wrap    TA_Wrap
  #define TextureAddress_Clamp   TA_Clamp
  #define TextureAddress_Mirror  TA_Mirror
  #define TextureAddress_MAX     TA_MAX
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
  #define TEXTUREGROUP_World                  TEXTUREGROUP_World
  #define TEXTUREGROUP_WorldNormalMap         TEXTUREGROUP_WorldNormalMap
  #define TEXTUREGROUP_WorldSpecular          TEXTUREGROUP_WorldSpecular
  #define TEXTUREGROUP_Character              TEXTUREGROUP_Character
  #define TEXTUREGROUP_CharacterNormalMap     TEXTUREGROUP_CharacterNormalMap
  #define TEXTUREGROUP_CharacterSpecular      TEXTUREGROUP_CharacterSpecular
  #define TEXTUREGROUP_Weapon                 TEXTUREGROUP_Weapon
  #define TEXTUREGROUP_WeaponNormalMap        TEXTUREGROUP_WeaponNormalMap
  #define TEXTUREGROUP_WeaponSpecular         TEXTUREGROUP_WeaponSpecular
  #define TEXTUREGROUP_Vehicle                TEXTUREGROUP_Vehicle
  #define TEXTUREGROUP_VehicleNormalMap       TEXTUREGROUP_VehicleNormalMap
  #define TEXTUREGROUP_VehicleSpecular        TEXTUREGROUP_VehicleSpecular
  #define TEXTUREGROUP_Cinematic              TEXTUREGROUP_Cinematic
  #define TEXTUREGROUP_Effects                TEXTUREGROUP_Effects
  #define TEXTUREGROUP_EffectsNotFiltered     TEXTUREGROUP_EffectsNotFiltered
  #define TEXTUREGROUP_Skybox                 TEXTUREGROUP_Skybox
  #define TEXTUREGROUP_UI                     TEXTUREGROUP_UI
  #define TEXTUREGROUP_Lightmap               TEXTUREGROUP_Lightmap
  #define TEXTUREGROUP_RenderTarget           TEXTUREGROUP_RenderTarget
  #define TEXTUREGROUP_MobileFlattened        TEXTUREGROUP_MobileFlattened
  #define TEXTUREGROUP_ProcBuilding_Face      TEXTUREGROUP_ProcBuilding_Face
  #define TEXTUREGROUP_ProcBuilding_LightMap  TEXTUREGROUP_ProcBuilding_LightMap
  #define TEXTUREGROUP_Shadowmap              TEXTUREGROUP_Shadowmap
  #define TEXTUREGROUP_ColorLookupTable       TEXTUREGROUP_ColorLookupTable
  #define TEXTUREGROUP_Terrain_Heightmap      TEXTUREGROUP_Terrain_Heightmap
  #define TEXTUREGROUP_Terrain_Weightmap      TEXTUREGROUP_Terrain_Weightmap
  #define TEXTUREGROUP_ImageBasedReflection   TEXTUREGROUP_ImageBasedReflection
  #define TEXTUREGROUP_Bokeh                  TEXTUREGROUP_Bokeh
  #define TEXTUREGROUP_MAX                    TEXTUREGROUP_MAX
  #define TextureGroup_World                  TEXTUREGROUP_World
  #define TextureGroup_WorldNormalMap         TEXTUREGROUP_WorldNormalMap
  #define TextureGroup_WorldSpecular          TEXTUREGROUP_WorldSpecular
  #define TextureGroup_Character              TEXTUREGROUP_Character
  #define TextureGroup_CharacterNormalMap     TEXTUREGROUP_CharacterNormalMap
  #define TextureGroup_CharacterSpecular      TEXTUREGROUP_CharacterSpecular
  #define TextureGroup_Weapon                 TEXTUREGROUP_Weapon
  #define TextureGroup_WeaponNormalMap        TEXTUREGROUP_WeaponNormalMap
  #define TextureGroup_WeaponSpecular         TEXTUREGROUP_WeaponSpecular
  #define TextureGroup_Vehicle                TEXTUREGROUP_Vehicle
  #define TextureGroup_VehicleNormalMap       TEXTUREGROUP_VehicleNormalMap
  #define TextureGroup_VehicleSpecular        TEXTUREGROUP_VehicleSpecular
  #define TextureGroup_Cinematic              TEXTUREGROUP_Cinematic
  #define TextureGroup_Effects                TEXTUREGROUP_Effects
  #define TextureGroup_EffectsNotFiltered     TEXTUREGROUP_EffectsNotFiltered
  #define TextureGroup_Skybox                 TEXTUREGROUP_Skybox
  #define TextureGroup_UI                     TEXTUREGROUP_UI
  #define TextureGroup_Lightmap               TEXTUREGROUP_Lightmap
  #define TextureGroup_RenderTarget           TEXTUREGROUP_RenderTarget
  #define TextureGroup_MobileFlattened        TEXTUREGROUP_MobileFlattened
  #define TextureGroup_ProcBuilding_Face      TEXTUREGROUP_ProcBuilding_Face
  #define TextureGroup_ProcBuilding_LightMap  TEXTUREGROUP_ProcBuilding_LightMap
  #define TextureGroup_Shadowmap              TEXTUREGROUP_Shadowmap
  #define TextureGroup_ColorLookupTable       TEXTUREGROUP_ColorLookupTable
  #define TextureGroup_Terrain_Heightmap      TEXTUREGROUP_Terrain_Heightmap
  #define TextureGroup_Terrain_Weightmap      TEXTUREGROUP_Terrain_Weightmap
  #define TextureGroup_ImageBasedReflection   TEXTUREGROUP_ImageBasedReflection
  #define TextureGroup_Bokeh                  TEXTUREGROUP_Bokeh
  #define TextureGroup_MAX                    TEXTUREGROUP_MAX
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
  #define TMGS_FromTextureGroup                    TMGS_FromTextureGroup
  #define TMGS_SimpleAverage                       TMGS_SimpleAverage
  #define TMGS_Sharpen0                            TMGS_Sharpen0
  #define TMGS_Sharpen1                            TMGS_Sharpen1
  #define TMGS_Sharpen2                            TMGS_Sharpen2
  #define TMGS_Sharpen3                            TMGS_Sharpen3
  #define TMGS_Sharpen4                            TMGS_Sharpen4
  #define TMGS_Sharpen5                            TMGS_Sharpen5
  #define TMGS_Sharpen6                            TMGS_Sharpen6
  #define TMGS_Sharpen7                            TMGS_Sharpen7
  #define TMGS_Sharpen8                            TMGS_Sharpen8
  #define TMGS_Sharpen9                            TMGS_Sharpen9
  #define TMGS_Sharpen10                           TMGS_Sharpen10
  #define TMGS_NoMipmaps                           TMGS_NoMipmaps
  #define TMGS_LeaveExistingMips                   TMGS_LeaveExistingMips
  #define TMGS_Blur1                               TMGS_Blur1
  #define TMGS_Blur2                               TMGS_Blur2
  #define TMGS_Blur3                               TMGS_Blur3
  #define TMGS_Blur4                               TMGS_Blur4
  #define TMGS_Blur5                               TMGS_Blur5
  #define TMGS_MAX                                 TMGS_MAX
  #define TextureMipGenSettings_FromTextureGroup   TMGS_FromTextureGroup
  #define TextureMipGenSettings_SimpleAverage      TMGS_SimpleAverage
  #define TextureMipGenSettings_Sharpen0           TMGS_Sharpen0
  #define TextureMipGenSettings_Sharpen1           TMGS_Sharpen1
  #define TextureMipGenSettings_Sharpen2           TMGS_Sharpen2
  #define TextureMipGenSettings_Sharpen3           TMGS_Sharpen3
  #define TextureMipGenSettings_Sharpen4           TMGS_Sharpen4
  #define TextureMipGenSettings_Sharpen5           TMGS_Sharpen5
  #define TextureMipGenSettings_Sharpen6           TMGS_Sharpen6
  #define TextureMipGenSettings_Sharpen7           TMGS_Sharpen7
  #define TextureMipGenSettings_Sharpen8           TMGS_Sharpen8
  #define TextureMipGenSettings_Sharpen9           TMGS_Sharpen9
  #define TextureMipGenSettings_Sharpen10          TMGS_Sharpen10
  #define TextureMipGenSettings_NoMipmaps          TMGS_NoMipmaps
  #define TextureMipGenSettings_LeaveExistingMips  TMGS_LeaveExistingMips
  #define TextureMipGenSettings_Blur1              TMGS_Blur1
  #define TextureMipGenSettings_Blur2              TMGS_Blur2
  #define TextureMipGenSettings_Blur3              TMGS_Blur3
  #define TextureMipGenSettings_Blur4              TMGS_Blur4
  #define TextureMipGenSettings_Blur5              TMGS_Blur5
  #define TextureMipGenSettings_MAX                TMGS_MAX
} TextureMipGenSettings;
typedef enum ETextureMipCount           : unsigned char {
  TMC_ResidentMips,               // 0
  TMC_AllMips,                    // 1
  TMC_AllMipsBiased,              // 2
  TMC_MAX                         // 3
  #define TMC_ResidentMips                TMC_ResidentMips
  #define TMC_AllMips                     TMC_AllMips
  #define TMC_AllMipsBiased               TMC_AllMipsBiased
  #define TMC_MAX                         TMC_MAX
  #define ETextureMipCount_ResidentMips   TMC_ResidentMips
  #define ETextureMipCount_AllMips        TMC_AllMips
  #define ETextureMipCount_AllMipsBiased  TMC_AllMipsBiased
  #define ETextureMipCount_MAX            TMC_MAX
} ETextureMipCount;
#define TextureCompressionSettings  TextureCompressionSettings
#define EPixelFormat                EPixelFormat
#define TextureFilter               TextureFilter
#define TextureAddress              TextureAddress
#define TextureGroup                TextureGroup
#define TextureMipGenSettings       TextureMipGenSettings
#define ETextureMipCount            ETextureMipCount

/* ---------------------------------------------------------- UWillowGameMessage ! ---------------------------------------------------------- */

typedef enum EWillowGameMessage : unsigned char {
  WGM_PlayerEnteredGame,          // 0
  WGM_PlayerLeftGame,             // 1
  WGM_CreaturesGrowStronger,      // 2
  WGM_CreaturesWeaken,            // 3
  WGM_MAX                         // 4
  #define WGM_PlayerEnteredGame                     WGM_PlayerEnteredGame
  #define WGM_PlayerLeftGame                        WGM_PlayerLeftGame
  #define WGM_CreaturesGrowStronger                 WGM_CreaturesGrowStronger
  #define WGM_CreaturesWeaken                       WGM_CreaturesWeaken
  #define WGM_MAX                                   WGM_MAX
  #define EWillowGameMessage_PlayerEnteredGame      WGM_PlayerEnteredGame
  #define EWillowGameMessage_PlayerLeftGame         WGM_PlayerLeftGame
  #define EWillowGameMessage_CreaturesGrowStronger  WGM_CreaturesGrowStronger
  #define EWillowGameMessage_CreaturesWeaken        WGM_CreaturesWeaken
  #define EWillowGameMessage_MAX                    WGM_MAX
} EWillowGameMessage;
#define EWillowGameMessage  EWillowGameMessage

/* ---------------------------------------------------------- UGFxManager ! ---------------------------------------------------------- */

typedef enum EInputResult : unsigned char {
  IR_None,                        // 0
  IR_Handled,                     // 1
  IR_Consumed,                    // 2
  IR_MAX                          // 3
  #define IR_None                IR_None
  #define IR_Handled             IR_Handled
  #define IR_Consumed            IR_Consumed
  #define IR_MAX                 IR_MAX
  #define EInputResult_None      IR_None
  #define EInputResult_Handled   IR_Handled
  #define EInputResult_Consumed  IR_Consumed
  #define EInputResult_MAX       IR_MAX
} EInputResult;
#define EInputResult  EInputResult

/* ---------------------------------------------------------- UUIDataProvider ! ---------------------------------------------------------- */

typedef enum EProviderAccessType : unsigned char {
  ACCESS_ReadOnly,                // 0
  ACCESS_PerField,                // 1
  ACCESS_WriteAll,                // 2
  ACCESS_MAX                      // 3
  #define ACCESS_ReadOnly               ACCESS_ReadOnly
  #define ACCESS_PerField               ACCESS_PerField
  #define ACCESS_WriteAll               ACCESS_WriteAll
  #define ACCESS_MAX                    ACCESS_MAX
  #define EProviderAccessType_ReadOnly  ACCESS_ReadOnly
  #define EProviderAccessType_PerField  ACCESS_PerField
  #define EProviderAccessType_WriteAll  ACCESS_WriteAll
  #define EProviderAccessType_MAX       ACCESS_MAX
} EProviderAccessType;
#define EProviderAccessType  EProviderAccessType

/* ---------------------------------------------------------- UGlobalsDefinition ! ---------------------------------------------------------- */

typedef enum EDropLifeSpanType : unsigned char {
  DROP_VeryShortLived,            // 0
  DROP_ShortLived,                // 1
  DROP_LongLived,                 // 2
  DROP_LiveForever,               // 3
  DROP_LiveAsLongAsLevel,         // 4
  DROP_MAX                        // 5
  #define DROP_VeryShortLived                  DROP_VeryShortLived
  #define DROP_ShortLived                      DROP_ShortLived
  #define DROP_LongLived                       DROP_LongLived
  #define DROP_LiveForever                     DROP_LiveForever
  #define DROP_LiveAsLongAsLevel               DROP_LiveAsLongAsLevel
  #define DROP_MAX                             DROP_MAX
  #define EDropLifeSpanType_VeryShortLived     DROP_VeryShortLived
  #define EDropLifeSpanType_ShortLived         DROP_ShortLived
  #define EDropLifeSpanType_LongLived          DROP_LongLived
  #define EDropLifeSpanType_LiveForever        DROP_LiveForever
  #define EDropLifeSpanType_LiveAsLongAsLevel  DROP_LiveAsLongAsLevel
  #define EDropLifeSpanType_MAX                DROP_MAX
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
  #define RARITY_Unknown         RARITY_Unknown
  #define RARITY_Common          RARITY_Common
  #define RARITY_Uncommon        RARITY_Uncommon
  #define RARITY_Rare            RARITY_Rare
  #define RARITY_VeryRare        RARITY_VeryRare
  #define RARITY_Legendary       RARITY_Legendary
  #define RARITY_Seraph          RARITY_Seraph
  #define RARITY_Rainbow         RARITY_Rainbow
  #define RARITY_MAX             RARITY_MAX
  #define EItemRarity_Unknown    RARITY_Unknown
  #define EItemRarity_Common     RARITY_Common
  #define EItemRarity_Uncommon   RARITY_Uncommon
  #define EItemRarity_Rare       RARITY_Rare
  #define EItemRarity_VeryRare   RARITY_VeryRare
  #define EItemRarity_Legendary  RARITY_Legendary
  #define EItemRarity_Seraph     RARITY_Seraph
  #define EItemRarity_Rainbow    RARITY_Rainbow
  #define EItemRarity_MAX        RARITY_MAX
} EItemRarity;
typedef enum ENumClassPlayers  : unsigned char {
  NCP_OnePlayer,                  // 0
  NCP_TwoPlayers,                 // 1
  NCP_ThreePlayers,               // 2
  NCP_FourPlayers,                // 3
  NCP_MAX                         // 4
  #define NCP_OnePlayer                  NCP_OnePlayer
  #define NCP_TwoPlayers                 NCP_TwoPlayers
  #define NCP_ThreePlayers               NCP_ThreePlayers
  #define NCP_FourPlayers                NCP_FourPlayers
  #define NCP_MAX                        NCP_MAX
  #define ENumClassPlayers_OnePlayer     NCP_OnePlayer
  #define ENumClassPlayers_TwoPlayers    NCP_TwoPlayers
  #define ENumClassPlayers_ThreePlayers  NCP_ThreePlayers
  #define ENumClassPlayers_FourPlayers   NCP_FourPlayers
  #define ENumClassPlayers_MAX           NCP_MAX
} ENumClassPlayers;
#define EDropLifeSpanType  EDropLifeSpanType
#define EItemRarity        EItemRarity
#define ENumClassPlayers   ENumClassPlayers

/* ---------------------------------------------------------- UAssetLibraryManager ! ---------------------------------------------------------- */

typedef enum EAssetLibrary : unsigned char {
  AL_WeaponTypes,                 // 0
  AL_WeaponParts,                 // 1
  AL_ItemTypes,                   // 2
  AL_ItemParts,                   // 3
  AL_Manufacturer,                // 4
  AL_Balance,                     // 5
  AL_MAX                          // 6
  #define AL_WeaponTypes              AL_WeaponTypes
  #define AL_WeaponParts              AL_WeaponParts
  #define AL_ItemTypes                AL_ItemTypes
  #define AL_ItemParts                AL_ItemParts
  #define AL_Manufacturer             AL_Manufacturer
  #define AL_Balance                  AL_Balance
  #define AL_MAX                      AL_MAX
  #define EAssetLibrary_WeaponTypes   AL_WeaponTypes
  #define EAssetLibrary_WeaponParts   AL_WeaponParts
  #define EAssetLibrary_ItemTypes     AL_ItemTypes
  #define EAssetLibrary_ItemParts     AL_ItemParts
  #define EAssetLibrary_Manufacturer  AL_Manufacturer
  #define EAssetLibrary_Balance       AL_Balance
  #define EAssetLibrary_MAX           AL_MAX
} EAssetLibrary;
#define EAssetLibrary  EAssetLibrary

/* ---------------------------------------------------------- UGFxMovieDrawStyleHUD ! ---------------------------------------------------------- */

typedef enum EHUDOrientation : unsigned char {
  HO_Horizontal,                  // 0
  HO_Vertical,                    // 1
  HO_MAX                          // 2
  #define HO_Horizontal               HO_Horizontal
  #define HO_Vertical                 HO_Vertical
  #define HO_MAX                      HO_MAX
  #define EHUDOrientation_Horizontal  HO_Horizontal
  #define EHUDOrientation_Vertical    HO_Vertical
  #define EHUDOrientation_MAX         HO_MAX
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
  #define HAP_None                         HAP_None
  #define HAP_Center                       HAP_Center
  #define HAP_TopLeft                      HAP_TopLeft
  #define HAP_TopRight                     HAP_TopRight
  #define HAP_BottomLeft                   HAP_BottomLeft
  #define HAP_BottomRight                  HAP_BottomRight
  #define HAP_Left                         HAP_Left
  #define HAP_Top                          HAP_Top
  #define HAP_Right                        HAP_Right
  #define HAP_Bottom                       HAP_Bottom
  #define HAP_Projected                    HAP_Projected
  #define HAP_ProjectedScaled              HAP_ProjectedScaled
  #define HAP_MAX                          HAP_MAX
  #define EHUDAnchorPoint_None             HAP_None
  #define EHUDAnchorPoint_Center           HAP_Center
  #define EHUDAnchorPoint_TopLeft          HAP_TopLeft
  #define EHUDAnchorPoint_TopRight         HAP_TopRight
  #define EHUDAnchorPoint_BottomLeft       HAP_BottomLeft
  #define EHUDAnchorPoint_BottomRight      HAP_BottomRight
  #define EHUDAnchorPoint_Left             HAP_Left
  #define EHUDAnchorPoint_Top              HAP_Top
  #define EHUDAnchorPoint_Right            HAP_Right
  #define EHUDAnchorPoint_Bottom           HAP_Bottom
  #define EHUDAnchorPoint_Projected        HAP_Projected
  #define EHUDAnchorPoint_ProjectedScaled  HAP_ProjectedScaled
  #define EHUDAnchorPoint_MAX              HAP_MAX
} EHUDAnchorPoint;
typedef enum EHUDCoordType   : unsigned char {
  HCT_Scaled,                     // 0
  HCT_Fixed,                      // 1
  HCT_MovieRelative,              // 2
  HCT_MAX                         // 3
  #define HCT_Scaled                   HCT_Scaled
  #define HCT_Fixed                    HCT_Fixed
  #define HCT_MovieRelative            HCT_MovieRelative
  #define HCT_MAX                      HCT_MAX
  #define EHUDCoordType_Scaled         HCT_Scaled
  #define EHUDCoordType_Fixed          HCT_Fixed
  #define EHUDCoordType_MovieRelative  HCT_MovieRelative
  #define EHUDCoordType_MAX            HCT_MAX
} EHUDCoordType;
#define EHUDOrientation  EHUDOrientation
#define EHUDAnchorPoint  EHUDAnchorPoint
#define EHUDCoordType    EHUDCoordType

/* ---------------------------------------------------------- UFastTravelStationGFxMovie ! ---------------------------------------------------------- */

typedef enum ELocationMissionStatus : unsigned char {
  LMS_ReadyToTurnIn,              // 0
  LMS_New,                        // 1
  LMS_InProgress,                 // 2
  LMS_InProgressStory,            // 3
  LMS_AndMuchMore,                // 4
  LMS_Invalid,                    // 5
  LMS_MAX                         // 6
  #define LMS_ReadyToTurnIn                       LMS_ReadyToTurnIn
  #define LMS_New                                 LMS_New
  #define LMS_InProgress                          LMS_InProgress
  #define LMS_InProgressStory                     LMS_InProgressStory
  #define LMS_AndMuchMore                         LMS_AndMuchMore
  #define LMS_Invalid                             LMS_Invalid
  #define LMS_MAX                                 LMS_MAX
  #define ELocationMissionStatus_ReadyToTurnIn    LMS_ReadyToTurnIn
  #define ELocationMissionStatus_New              LMS_New
  #define ELocationMissionStatus_InProgress       LMS_InProgress
  #define ELocationMissionStatus_InProgressStory  LMS_InProgressStory
  #define ELocationMissionStatus_AndMuchMore      LMS_AndMuchMore
  #define ELocationMissionStatus_Invalid          LMS_Invalid
  #define ELocationMissionStatus_MAX              LMS_MAX
} ELocationMissionStatus;
#define ELocationMissionStatus  ELocationMissionStatus

/* ---------------------------------------------------------- UFastTravelStationDefinition ! ---------------------------------------------------------- */

typedef enum EFastTravelAccessibilityTime : unsigned char {
  FTAT_Always,                    // 0
  FTAT_Halloween,                 // 1
  FTAT_Thanksgiving,              // 2
  FTAT_Christmas,                 // 3
  FTAT_MAX                        // 4
  #define FTAT_Always                                FTAT_Always
  #define FTAT_Halloween                             FTAT_Halloween
  #define FTAT_Thanksgiving                          FTAT_Thanksgiving
  #define FTAT_Christmas                             FTAT_Christmas
  #define FTAT_MAX                                   FTAT_MAX
  #define EFastTravelAccessibilityTime_Always        FTAT_Always
  #define EFastTravelAccessibilityTime_Halloween     FTAT_Halloween
  #define EFastTravelAccessibilityTime_Thanksgiving  FTAT_Thanksgiving
  #define EFastTravelAccessibilityTime_Christmas     FTAT_Christmas
  #define EFastTravelAccessibilityTime_MAX           FTAT_MAX
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

/* ---------------------------------------------------------- UWillowUIInteraction ! ---------------------------------------------------------- */

typedef enum ETextHAlignment               : unsigned char {
  HALIGN_FixedPos,                // 0
  HALIGN_Left,                    // 1
  HALIGN_Center,                  // 2
  HALIGN_MAX                      // 3
  #define HALIGN_FixedPos           HALIGN_FixedPos
  #define HALIGN_Left               HALIGN_Left
  #define HALIGN_Center             HALIGN_Center
  #define HALIGN_MAX                HALIGN_MAX
  #define ETextHAlignment_FixedPos  HALIGN_FixedPos
  #define ETextHAlignment_Left      HALIGN_Left
  #define ETextHAlignment_Center    HALIGN_Center
  #define ETextHAlignment_MAX       HALIGN_MAX
} ETextHAlignment;
typedef enum ETextVAlignment               : unsigned char {
  VALIGN_FixedPos,                // 0
  VALIGN_Center,                  // 1
  VALIGN_Bottom,                  // 2
  VALIGN_MAX                      // 3
  #define VALIGN_FixedPos           VALIGN_FixedPos
  #define VALIGN_Center             VALIGN_Center
  #define VALIGN_Bottom             VALIGN_Bottom
  #define VALIGN_MAX                VALIGN_MAX
  #define ETextVAlignment_FixedPos  VALIGN_FixedPos
  #define ETextVAlignment_Center    VALIGN_Center
  #define ETextVAlignment_Bottom    VALIGN_Bottom
  #define ETextVAlignment_MAX       VALIGN_MAX
} ETextVAlignment;
typedef enum EItemTypeForUI                : unsigned char {
  ITEMUI_Armor,                   // 0
  ITEMUI_Item,                    // 1
  ITEMUI_Ammo,                    // 2
  ITEMUI_MAX                      // 3
  #define ITEMUI_Armor          ITEMUI_Armor
  #define ITEMUI_Item           ITEMUI_Item
  #define ITEMUI_Ammo           ITEMUI_Ammo
  #define ITEMUI_MAX            ITEMUI_MAX
  #define EItemTypeForUI_Armor  ITEMUI_Armor
  #define EItemTypeForUI_Item   ITEMUI_Item
  #define EItemTypeForUI_Ammo   ITEMUI_Ammo
  #define EItemTypeForUI_MAX    ITEMUI_MAX
} EItemTypeForUI;
typedef enum EFontSize                     : unsigned char {
  FONT_Medium,                    // 0
  FONT_Tiny,                      // 1
  FONT_Small,                     // 2
  FONT_Large,                     // 3
  FONT_MAX                        // 4
  #define FONT_Medium       FONT_Medium
  #define FONT_Tiny         FONT_Tiny
  #define FONT_Small        FONT_Small
  #define FONT_Large        FONT_Large
  #define FONT_MAX          FONT_MAX
  #define EFontSize_Medium  FONT_Medium
  #define EFontSize_Tiny    FONT_Tiny
  #define EFontSize_Small   FONT_Small
  #define EFontSize_Large   FONT_Large
  #define EFontSize_MAX     FONT_MAX
} EFontSize;
typedef enum EAttributeDebugSort           : unsigned char {
  ATTDEBUGSORT_NameUp,            // 0
  ATTDEBUGSORT_NameDn,            // 1
  ATTDEBUGSORT_MAX                // 2
  #define ATTDEBUGSORT_NameUp         ATTDEBUGSORT_NameUp
  #define ATTDEBUGSORT_NameDn         ATTDEBUGSORT_NameDn
  #define ATTDEBUGSORT_MAX            ATTDEBUGSORT_MAX
  #define EAttributeDebugSort_NameUp  ATTDEBUGSORT_NameUp
  #define EAttributeDebugSort_NameDn  ATTDEBUGSORT_NameDn
  #define EAttributeDebugSort_MAX     ATTDEBUGSORT_MAX
} EAttributeDebugSort;
typedef enum EMemoryDetailsSortStyle       : unsigned char {
  MEMDETAILSORT_ResourceNameAToZ, // 0
  MEMDETAILSORT_ResourceNameZToA, // 1
  MEMDETAILSORT_SizeSmallToLarge, // 2
  MEMDETAILSORT_SizeLargeToSmall, // 3
  MEMDETAILSORT_CountHighToLow,   // 4
  MEMDETAILSORT_MAX               // 5
  #define MEMDETAILSORT_ResourceNameAToZ            MEMDETAILSORT_ResourceNameAToZ
  #define MEMDETAILSORT_ResourceNameZToA            MEMDETAILSORT_ResourceNameZToA
  #define MEMDETAILSORT_SizeSmallToLarge            MEMDETAILSORT_SizeSmallToLarge
  #define MEMDETAILSORT_SizeLargeToSmall            MEMDETAILSORT_SizeLargeToSmall
  #define MEMDETAILSORT_CountHighToLow              MEMDETAILSORT_CountHighToLow
  #define MEMDETAILSORT_MAX                         MEMDETAILSORT_MAX
  #define EMemoryDetailsSortStyle_ResourceNameAToZ  MEMDETAILSORT_ResourceNameAToZ
  #define EMemoryDetailsSortStyle_ResourceNameZToA  MEMDETAILSORT_ResourceNameZToA
  #define EMemoryDetailsSortStyle_SizeSmallToLarge  MEMDETAILSORT_SizeSmallToLarge
  #define EMemoryDetailsSortStyle_SizeLargeToSmall  MEMDETAILSORT_SizeLargeToSmall
  #define EMemoryDetailsSortStyle_CountHighToLow    MEMDETAILSORT_CountHighToLow
  #define EMemoryDetailsSortStyle_MAX               MEMDETAILSORT_MAX
} EMemoryDetailsSortStyle;
typedef enum ENetworkActorChannelSortStyle : unsigned char {
  NETACTORSORT_ActorNameAToZ,     // 0
  NETACTORSORT_ActornameZToA,     // 1
  NETACTORSORT_CountHighToLow,    // 2
  NETACTORSORT_CountLowToHigh,    // 3
  NETACTORSORT_MAX                // 4
  #define NETACTORSORT_ActorNameAToZ                    NETACTORSORT_ActorNameAToZ
  #define NETACTORSORT_ActornameZToA                    NETACTORSORT_ActornameZToA
  #define NETACTORSORT_CountHighToLow                   NETACTORSORT_CountHighToLow
  #define NETACTORSORT_CountLowToHigh                   NETACTORSORT_CountLowToHigh
  #define NETACTORSORT_MAX                              NETACTORSORT_MAX
  #define ENetworkActorChannelSortStyle_ActorNameAToZ   NETACTORSORT_ActorNameAToZ
  #define ENetworkActorChannelSortStyle_ActornameZToA   NETACTORSORT_ActornameZToA
  #define ENetworkActorChannelSortStyle_CountHighToLow  NETACTORSORT_CountHighToLow
  #define ENetworkActorChannelSortStyle_CountLowToHigh  NETACTORSORT_CountLowToHigh
  #define ENetworkActorChannelSortStyle_MAX             NETACTORSORT_MAX
} ENetworkActorChannelSortStyle;
typedef enum EGearBuilderSortMode          : unsigned char {
  GBSM_None,                      // 0
  GBSM_WeightHighToLow,           // 1
  GBSM_WeightLowToHigh,           // 2
  GBSM_Invalid,                   // 3
  GBSM_MAX                        // 4
  #define GBSM_None                             GBSM_None
  #define GBSM_WeightHighToLow                  GBSM_WeightHighToLow
  #define GBSM_WeightLowToHigh                  GBSM_WeightLowToHigh
  #define GBSM_Invalid                          GBSM_Invalid
  #define GBSM_MAX                              GBSM_MAX
  #define EGearBuilderSortMode_None             GBSM_None
  #define EGearBuilderSortMode_WeightHighToLow  GBSM_WeightHighToLow
  #define EGearBuilderSortMode_WeightLowToHigh  GBSM_WeightLowToHigh
  #define EGearBuilderSortMode_Invalid          GBSM_Invalid
  #define EGearBuilderSortMode_MAX              GBSM_MAX
} EGearBuilderSortMode;
#define ETextHAlignment                ETextHAlignment
#define ETextVAlignment                ETextVAlignment
#define EItemTypeForUI                 EItemTypeForUI
#define EFontSize                      EFontSize
#define EAttributeDebugSort            EAttributeDebugSort
#define EMemoryDetailsSortStyle        EMemoryDetailsSortStyle
#define ENetworkActorChannelSortStyle  ENetworkActorChannelSortStyle
#define EGearBuilderSortMode           EGearBuilderSortMode

/* ---------------------------------------------------------- UIUsable ! ---------------------------------------------------------- */

typedef enum EUsabilityType : unsigned char {
  UT_Primary,                     // 0
  UT_Secondary,                   // 1
  UT_MAX                          // 2
  #define UT_Primary                UT_Primary
  #define UT_Secondary              UT_Secondary
  #define UT_MAX                    UT_MAX
  #define EUsabilityType_Primary    UT_Primary
  #define EUsabilityType_Secondary  UT_Secondary
  #define EUsabilityType_MAX        UT_MAX
} EUsabilityType;
#define EUsabilityType  EUsabilityType

/* ---------------------------------------------------------- UChallengeDefinition ! ---------------------------------------------------------- */

typedef enum EChallengeType : unsigned char {
  ECT_Stat,                       // 0
  ECT_LevelObject,                // 1
  ECT_DesignerTriggered,          // 2
  ECT_MAX                         // 3
  #define ECT_Stat                         ECT_Stat
  #define ECT_LevelObject                  ECT_LevelObject
  #define ECT_DesignerTriggered            ECT_DesignerTriggered
  #define ECT_MAX                          ECT_MAX
  #define EChallengeType_Stat              ECT_Stat
  #define EChallengeType_LevelObject       ECT_LevelObject
  #define EChallengeType_DesignerTriggered ECT_DesignerTriggered
  #define EChallengeType_MAX               ECT_MAX
} EChallengeType;
#define EChallengeType  EChallengeType

/* ---------------------------------------------------------- UGearboxDialogEventTag ! ---------------------------------------------------------- */

typedef enum EDialogEventMatchQuality : unsigned char {
  MQ_NoMatch,                     // 0
  MQ_Match,                       // 1
  MQ_ForceMatch,                  // 2
  MQ_MAX                          // 3
  #define MQ_NoMatch                           MQ_NoMatch
  #define MQ_Match                             MQ_Match
  #define MQ_ForceMatch                        MQ_ForceMatch
  #define MQ_MAX                               MQ_MAX
  #define EDialogEventMatchQuality_NoMatch     MQ_NoMatch
  #define EDialogEventMatchQuality_Match       MQ_Match
  #define EDialogEventMatchQuality_ForceMatch  MQ_ForceMatch
  #define EDialogEventMatchQuality_MAX         MQ_MAX
} EDialogEventMatchQuality;
#define EDialogEventMatchQuality  EDialogEventMatchQuality

/* ---------------------------------------------------------- ULANServerBrowserGFxMovie ! ---------------------------------------------------------- */

typedef enum ESortType      : unsigned char {
  SORT_PlayerCount,               // 0
  SORT_Name,                      // 1
  SORT_Level,                     // 2
  SORT_Mission,                   // 3
  SORT_Ping,                      // 4
  SORT_MAX                        // 5
  #define SORT_PlayerCount       SORT_PlayerCount
  #define SORT_Name              SORT_Name
  #define SORT_Level             SORT_Level
  #define SORT_Mission           SORT_Mission
  #define SORT_Ping              SORT_Ping
  #define SORT_MAX               SORT_MAX
  #define ESortType_PlayerCount  SORT_PlayerCount
  #define ESortType_Name         SORT_Name
  #define ESortType_Level        SORT_Level
  #define ESortType_Mission      SORT_Mission
  #define ESortType_Ping         SORT_Ping
  #define ESortType_MAX          SORT_MAX
} ESortType;
typedef enum ESortDirection : unsigned char {
  SORTDIR_Ascending,              // 0
  SORTDIR_Descending,             // 1
  SORTDIR_MAX                     // 2
  #define SORTDIR_Ascending          SORTDIR_Ascending
  #define SORTDIR_Descending         SORTDIR_Descending
  #define SORTDIR_MAX                SORTDIR_MAX
  #define ESortDirection_Ascending   SORTDIR_Ascending
  #define ESortDirection_Descending  SORTDIR_Descending
  #define ESortDirection_MAX         SORTDIR_MAX
} ESortDirection;
#define ESortType       ESortType
#define ESortDirection  ESortDirection

/* ---------------------------------------------------------- UPlayerClassDefinition ! ---------------------------------------------------------- */

typedef enum EPlayerClassAchievementUnlockType : unsigned char {
  PCAUT_PetKills,                 // 0
  PCAUT_TimeSpentInActionSkill,   // 1
  PCAUT_TargetedActionSkillImpacts,// 2
  PCAUT_MAX                       // 3
  #define PCAUT_PetKills                                                PCAUT_PetKills
  #define PCAUT_TimeSpentInActionSkill                                  PCAUT_TimeSpentInActionSkill
  #define PCAUT_TargetedActionSkillImpacts                              PCAUT_TargetedActionSkillImpacts
  #define PCAUT_MAX                                                     PCAUT_MAX
  #define EPlayerClassAchievementUnlockType_PetKills                    PCAUT_PetKills
  #define EPlayerClassAchievementUnlockType_TimeSpentInActionSkill      PCAUT_TimeSpentInActionSkill
  #define EPlayerClassAchievementUnlockType_TargetedActionSkillImpacts  PCAUT_TargetedActionSkillImpacts
  #define EPlayerClassAchievementUnlockType_MAX                         PCAUT_MAX
} EPlayerClassAchievementUnlockType;
#define EPlayerClassAchievementUnlockType  EPlayerClassAchievementUnlockType

/* ---------------------------------------------------------- UPlayerEventProviderDefinition ! ---------------------------------------------------------- */

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
  #define PEM_KilledChampion                        PEM_KilledChampion
  #define PEM_SkillKill                             PEM_SkillKill
  #define PEM_KilledEnemy                           PEM_KilledEnemy
  #define PEM_KillStreak                            PEM_KillStreak
  #define PEM_ChallengeCompleted                    PEM_ChallengeCompleted
  #define PEM_JoinedGame                            PEM_JoinedGame
  #define PEM_SeatSwap                              PEM_SeatSwap
  #define PEM_VehicleCatchAir                       PEM_VehicleCatchAir
  #define PEM_KilledEnemyVehicle                    PEM_KilledEnemyVehicle
  #define PEM_VehicleLowHealth                      PEM_VehicleLowHealth
  #define PEM_VehicleFlipped                        PEM_VehicleFlipped
  #define PEM_RanOverEnemy                          PEM_RanOverEnemy
  #define PEM_VehicleSpawn                          PEM_VehicleSpawn
  #define PEM_CriticalHitKill                       PEM_CriticalHitKill
  #define PEM_CriticalHit                           PEM_CriticalHit
  #define PEM_OutOfAmmo                             PEM_OutOfAmmo
  #define PEM_Reloading                             PEM_Reloading
  #define PEM_RareWeaponEquipped                    PEM_RareWeaponEquipped
  #define PEM_PlayerIdle                            PEM_PlayerIdle
  #define PEM_PlayerDown                            PEM_PlayerDown
  #define PEM_Death                                 PEM_Death
  #define PEM_DeathByFire                           PEM_DeathByFire
  #define PEM_DeathByShock                          PEM_DeathByShock
  #define PEM_EnemyDamaged                          PEM_EnemyDamaged
  #define PEM_EnemyDamagedCritical                  PEM_EnemyDamagedCritical
  #define PEM_EnemyShieldDown                       PEM_EnemyShieldDown
  #define PEM_AchievedSecondWind                    PEM_AchievedSecondWind
  #define PEM_RevivingPlayer                        PEM_RevivingPlayer
  #define PEM_MissionTurnedIn                       PEM_MissionTurnedIn
  #define PEM_IncomingChampion                      PEM_IncomingChampion
  #define PEM_MapOpen                               PEM_MapOpen
  #define PEM_SkillPointToSpend                     PEM_SkillPointToSpend
  #define PEM_CompareItems                          PEM_CompareItems
  #define PEM_TravelBlocked                         PEM_TravelBlocked
  #define PEM_MAX                                   PEM_MAX
  #define EPlayerEventMessage_KilledChampion        PEM_KilledChampion
  #define EPlayerEventMessage_SkillKill             PEM_SkillKill
  #define EPlayerEventMessage_KilledEnemy           PEM_KilledEnemy
  #define EPlayerEventMessage_KillStreak            PEM_KillStreak
  #define EPlayerEventMessage_ChallengeCompleted    PEM_ChallengeCompleted
  #define EPlayerEventMessage_JoinedGame            PEM_JoinedGame
  #define EPlayerEventMessage_SeatSwap              PEM_SeatSwap
  #define EPlayerEventMessage_VehicleCatchAir       PEM_VehicleCatchAir
  #define EPlayerEventMessage_KilledEnemyVehicle    PEM_KilledEnemyVehicle
  #define EPlayerEventMessage_VehicleLowHealth      PEM_VehicleLowHealth
  #define EPlayerEventMessage_VehicleFlipped        PEM_VehicleFlipped
  #define EPlayerEventMessage_RanOverEnemy          PEM_RanOverEnemy
  #define EPlayerEventMessage_VehicleSpawn          PEM_VehicleSpawn
  #define EPlayerEventMessage_CriticalHitKill       PEM_CriticalHitKill
  #define EPlayerEventMessage_CriticalHit           PEM_CriticalHit
  #define EPlayerEventMessage_OutOfAmmo             PEM_OutOfAmmo
  #define EPlayerEventMessage_Reloading             PEM_Reloading
  #define EPlayerEventMessage_RareWeaponEquipped    PEM_RareWeaponEquipped
  #define EPlayerEventMessage_PlayerIdle            PEM_PlayerIdle
  #define EPlayerEventMessage_PlayerDown            PEM_PlayerDown
  #define EPlayerEventMessage_Death                 PEM_Death
  #define EPlayerEventMessage_DeathByFire           PEM_DeathByFire
  #define EPlayerEventMessage_DeathByShock          PEM_DeathByShock
  #define EPlayerEventMessage_EnemyDamaged          PEM_EnemyDamaged
  #define EPlayerEventMessage_EnemyDamagedCritical  PEM_EnemyDamagedCritical
  #define EPlayerEventMessage_EnemyShieldDown       PEM_EnemyShieldDown
  #define EPlayerEventMessage_AchievedSecondWind    PEM_AchievedSecondWind
  #define EPlayerEventMessage_RevivingPlayer        PEM_RevivingPlayer
  #define EPlayerEventMessage_MissionTurnedIn       PEM_MissionTurnedIn
  #define EPlayerEventMessage_IncomingChampion      PEM_IncomingChampion
  #define EPlayerEventMessage_MapOpen               PEM_MapOpen
  #define EPlayerEventMessage_SkillPointToSpend     PEM_SkillPointToSpend
  #define EPlayerEventMessage_CompareItems          PEM_CompareItems
  #define EPlayerEventMessage_TravelBlocked         PEM_TravelBlocked
  #define EPlayerEventMessage_MAX                   PEM_MAX
} EPlayerEventMessage;
#define EPlayerEventMessage  EPlayerEventMessage

/* ---------------------------------------------------------- UCoordinatedEffectDefinition ! ---------------------------------------------------------- */

typedef enum ECoordinatedParticleScaleMode : unsigned char {
  CPSM_None,                      // 0
  CPSM_LargestAxis,               // 1
  CPSM_SmallestAxis,              // 2
  CPSM_HorizontalAxis,            // 3
  CPSM_VerticalAxis,              // 4
  CPSM_EachAxis,                  // 5
  CPSM_MAX                        // 6
  #define CPSM_None                                     CPSM_None
  #define CPSM_LargestAxis                              CPSM_LargestAxis
  #define CPSM_SmallestAxis                             CPSM_SmallestAxis
  #define CPSM_HorizontalAxis                           CPSM_HorizontalAxis
  #define CPSM_VerticalAxis                             CPSM_VerticalAxis
  #define CPSM_EachAxis                                 CPSM_EachAxis
  #define CPSM_MAX                                      CPSM_MAX
  #define ECoordinatedParticleScaleMode_None            CPSM_None
  #define ECoordinatedParticleScaleMode_LargestAxis     CPSM_LargestAxis
  #define ECoordinatedParticleScaleMode_SmallestAxis    CPSM_SmallestAxis
  #define ECoordinatedParticleScaleMode_HorizontalAxis  CPSM_HorizontalAxis
  #define ECoordinatedParticleScaleMode_VerticalAxis    CPSM_VerticalAxis
  #define ECoordinatedParticleScaleMode_EachAxis        CPSM_EachAxis
  #define ECoordinatedParticleScaleMode_MAX             CPSM_MAX
} ECoordinatedParticleScaleMode;
#define ECoordinatedParticleScaleMode  ECoordinatedParticleScaleMode

/* ---------------------------------------------------------- UMissionDefinition ! ---------------------------------------------------------- */

typedef enum EDefendMission : unsigned char {
  EDM_None,                       // 0
  EDM_NoFail,                     // 1
  EDM_Failable,                   // 2
  EDM_MAX                         // 3
  #define EDM_None                 EDM_None
  #define EDM_NoFail               EDM_NoFail
  #define EDM_Failable             EDM_Failable
  #define EDM_MAX                  EDM_MAX
  #define EDefendMission_None      EDM_None
  #define EDefendMission_NoFail    EDM_NoFail
  #define EDefendMission_Failable  EDM_Failable
  #define EDefendMission_MAX       EDM_MAX
} EDefendMission;
#define EDefendMission  EDefendMission

/* ---------------------------------------------------------- UGFxTextListContainer ! ---------------------------------------------------------- */

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
  #define TLMD_Up                            TLMD_Up
  #define TLMD_Down                          TLMD_Down
  #define TLMD_PageUp                        TLMD_PageUp
  #define TLMD_PageDown                      TLMD_PageDown
  #define TLMD_First                         TLMD_First
  #define TLMD_Last                          TLMD_Last
  #define TLMD_PreviousCategory              TLMD_PreviousCategory
  #define TLMD_NextCategory                  TLMD_NextCategory
  #define TLMD_MAX                           TLMD_MAX
  #define ETextListMoveDir_Up                TLMD_Up
  #define ETextListMoveDir_Down              TLMD_Down
  #define ETextListMoveDir_PageUp            TLMD_PageUp
  #define ETextListMoveDir_PageDown          TLMD_PageDown
  #define ETextListMoveDir_First             TLMD_First
  #define ETextListMoveDir_Last              TLMD_Last
  #define ETextListMoveDir_PreviousCategory  TLMD_PreviousCategory
  #define ETextListMoveDir_NextCategory      TLMD_NextCategory
  #define ETextListMoveDir_MAX               TLMD_MAX
} ETextListMoveDir;
typedef enum EArrayKind       : unsigned char {
  EAK_Source,                     // 0
  EAK_Categories,                 // 1
  EAK_InvalidEntry,               // 2
  EAK_Unloadable,                 // 3
  EAK_MAX                         // 4
  #define EAK_Source               EAK_Source
  #define EAK_Categories           EAK_Categories
  #define EAK_InvalidEntry         EAK_InvalidEntry
  #define EAK_Unloadable           EAK_Unloadable
  #define EAK_MAX                  EAK_MAX
  #define EArrayKind_Source        EAK_Source
  #define EArrayKind_Categories    EAK_Categories
  #define EArrayKind_InvalidEntry  EAK_InvalidEntry
  #define EArrayKind_Unloadable    EAK_Unloadable
  #define EArrayKind_MAX           EAK_MAX
} EArrayKind;
#define ETextListMoveDir  ETextListMoveDir
#define EArrayKind        EArrayKind

/* ---------------------------------------------------------- UIMission ! ---------------------------------------------------------- */

typedef enum EMissionStatus             : unsigned char {
  MS_NotStarted,                  // 0
  MS_Active,                      // 1
  MS_RequiredObjectivesComplete,  // 2
  MS_ReadyToTurnIn,               // 3
  MS_Complete,                    // 4
  MS_Failed,                      // 5
  MS_MAX                          // 6
  #define MS_NotStarted                              MS_NotStarted
  #define MS_Active                                  MS_Active
  #define MS_RequiredObjectivesComplete              MS_RequiredObjectivesComplete
  #define MS_ReadyToTurnIn                           MS_ReadyToTurnIn
  #define MS_Complete                                MS_Complete
  #define MS_Failed                                  MS_Failed
  #define MS_MAX                                     MS_MAX
  #define EMissionStatus_NotStarted                  MS_NotStarted
  #define EMissionStatus_Active                      MS_Active
  #define EMissionStatus_RequiredObjectivesComplete  MS_RequiredObjectivesComplete
  #define EMissionStatus_ReadyToTurnIn               MS_ReadyToTurnIn
  #define EMissionStatus_Complete                    MS_Complete
  #define EMissionStatus_Failed                      MS_Failed
  #define EMissionStatus_MAX                         MS_MAX
} EMissionStatus;
typedef enum EMissionReaction           : unsigned char {
  MR_NotStarted,                  // 0
  MR_Active,                      // 1
  MR_ReadyToTurnIn,               // 2
  MR_Complete,                    // 3
  MR_MAX                          // 4
  #define MR_NotStarted                   MR_NotStarted
  #define MR_Active                       MR_Active
  #define MR_ReadyToTurnIn                MR_ReadyToTurnIn
  #define MR_Complete                     MR_Complete
  #define MR_MAX                          MR_MAX
  #define EMissionReaction_NotStarted     MR_NotStarted
  #define EMissionReaction_Active         MR_Active
  #define EMissionReaction_ReadyToTurnIn  MR_ReadyToTurnIn
  #define EMissionReaction_Complete       MR_Complete
  #define EMissionReaction_MAX            MR_MAX
} EMissionReaction;
typedef enum EObjectiveDependencyStatus : unsigned char {
  EODS_Complete,                  // 0
  EODS_Active,                    // 1
  EODS_MAX                        // 2
  #define EODS_Complete                        EODS_Complete
  #define EODS_Active                          EODS_Active
  #define EODS_MAX                             EODS_MAX
  #define EObjectiveDependencyStatus_Complete  EODS_Complete
  #define EObjectiveDependencyStatus_Active    EODS_Active
  #define EObjectiveDependencyStatus_MAX       EODS_MAX
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
  #define ME_LevelLoad                         ME_LevelLoad
  #define ME_StatusChanged                     ME_StatusChanged
  #define ME_ObjectiveSetChanged               ME_ObjectiveSetChanged
  #define ME_ObjectiveUpdated                  ME_ObjectiveUpdated
  #define ME_ObjectiveCleared                  ME_ObjectiveCleared
  #define ME_ObjectiveComplete                 ME_ObjectiveComplete
  #define ME_ActiveMission                     ME_ActiveMission
  #define ME_NoLongerActiveMission             ME_NoLongerActiveMission
  #define ME_MAX                               ME_MAX
  #define EMissionEvent_LevelLoad              ME_LevelLoad
  #define EMissionEvent_StatusChanged          ME_StatusChanged
  #define EMissionEvent_ObjectiveSetChanged    ME_ObjectiveSetChanged
  #define EMissionEvent_ObjectiveUpdated       ME_ObjectiveUpdated
  #define EMissionEvent_ObjectiveCleared       ME_ObjectiveCleared
  #define EMissionEvent_ObjectiveComplete      ME_ObjectiveComplete
  #define EMissionEvent_ActiveMission          ME_ActiveMission
  #define EMissionEvent_NoLongerActiveMission  ME_NoLongerActiveMission
  #define EMissionEvent_MAX                    ME_MAX
} EMissionEvent;
#define EMissionStatus              EMissionStatus
#define EMissionReaction            EMissionReaction
#define EObjectiveDependencyStatus  EObjectiveDependencyStatus
#define EMissionEvent               EMissionEvent

/* ---------------------------------------------------------- UIMissionDirector ! ---------------------------------------------------------- */

typedef enum EMissionBranchEnding : unsigned char {
  EMBE_None,                      // 0
  EMBE_PathA,                     // 1
  EMBE_PathB,                     // 2
  EMBE_MAX                        // 3
  #define EMBE_None                   EMBE_None
  #define EMBE_PathA                  EMBE_PathA
  #define EMBE_PathB                  EMBE_PathB
  #define EMBE_MAX                    EMBE_MAX
  #define EMissionBranchEnding_None   EMBE_None
  #define EMissionBranchEnding_PathA  EMBE_PathA
  #define EMissionBranchEnding_PathB  EMBE_PathB
  #define EMissionBranchEnding_MAX    EMBE_MAX
} EMissionBranchEnding;
#define EMissionBranchEnding  EMissionBranchEnding

/* ---------------------------------------------------------- UHUDWidget_WorldSpace ! ---------------------------------------------------------- */

typedef enum EPlayerIconState : unsigned char {
  EPIS_Normal,                    // 0
  EPIS_Injured,                   // 1
  EPIS_Reviving,                  // 2
  EPIS_MAX                        // 3
  #define EPIS_Normal                EPIS_Normal
  #define EPIS_Injured               EPIS_Injured
  #define EPIS_Reviving              EPIS_Reviving
  #define EPIS_MAX                   EPIS_MAX
  #define EPlayerIconState_Normal    EPIS_Normal
  #define EPlayerIconState_Injured   EPIS_Injured
  #define EPlayerIconState_Reviving  EPIS_Reviving
  #define EPlayerIconState_MAX       EPIS_MAX
} EPlayerIconState;
#define EPlayerIconState  EPlayerIconState

/* ---------------------------------------------------------- UHUDWidget_Missions ! ---------------------------------------------------------- */

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
  #define EMWT_None                                       EMWT_None
  #define EMWT_Init                                       EMWT_Init
  #define EMWT_SetMission                                 EMWT_SetMission
  #define EMWT_AddObjective                               EMWT_AddObjective
  #define EMWT_RemoveObjective                            EMWT_RemoveObjective
  #define EMWT_SwapInObjective                            EMWT_SwapInObjective
  #define EMWT_SwapOutObjective                           EMWT_SwapOutObjective
  #define EMWT_CompleteObjective                          EMWT_CompleteObjective
  #define EMWT_ClearObjective                             EMWT_ClearObjective
  #define EMWT_UpdateObjectiveCount                       EMWT_UpdateObjectiveCount
  #define EMWT_EnableTurnIn                               EMWT_EnableTurnIn
  #define EMWT_EnableOr                                   EMWT_EnableOr
  #define EMWT_EnableFailed                               EMWT_EnableFailed
  #define EMWT_EnableTimer                                EMWT_EnableTimer
  #define EMWT_TickTimer                                  EMWT_TickTimer
  #define EMWT_EnableDefense                              EMWT_EnableDefense
  #define EMWT_TickDefense                                EMWT_TickDefense
  #define EMWT_FlyingCheckmark                            EMWT_FlyingCheckmark
  #define EMWT_MAX                                        EMWT_MAX
  #define EMissionWidgetMessageType_None                  EMWT_None
  #define EMissionWidgetMessageType_Init                  EMWT_Init
  #define EMissionWidgetMessageType_SetMission            EMWT_SetMission
  #define EMissionWidgetMessageType_AddObjective          EMWT_AddObjective
  #define EMissionWidgetMessageType_RemoveObjective       EMWT_RemoveObjective
  #define EMissionWidgetMessageType_SwapInObjective       EMWT_SwapInObjective
  #define EMissionWidgetMessageType_SwapOutObjective      EMWT_SwapOutObjective
  #define EMissionWidgetMessageType_CompleteObjective     EMWT_CompleteObjective
  #define EMissionWidgetMessageType_ClearObjective        EMWT_ClearObjective
  #define EMissionWidgetMessageType_UpdateObjectiveCount  EMWT_UpdateObjectiveCount
  #define EMissionWidgetMessageType_EnableTurnIn          EMWT_EnableTurnIn
  #define EMissionWidgetMessageType_EnableOr              EMWT_EnableOr
  #define EMissionWidgetMessageType_EnableFailed          EMWT_EnableFailed
  #define EMissionWidgetMessageType_EnableTimer           EMWT_EnableTimer
  #define EMissionWidgetMessageType_TickTimer             EMWT_TickTimer
  #define EMissionWidgetMessageType_EnableDefense         EMWT_EnableDefense
  #define EMissionWidgetMessageType_TickDefense           EMWT_TickDefense
  #define EMissionWidgetMessageType_FlyingCheckmark       EMWT_FlyingCheckmark
  #define EMissionWidgetMessageType_MAX                   EMWT_MAX
} EMissionWidgetMessageType;
typedef enum EMissionWidgetMessageCategory : unsigned char {
  EMWC_None,                      // 0
  EMWC_Init,                      // 1
  EMWC_PreComplete,               // 2
  EMWC_Complete,                  // 3
  EMWC_Remove,                    // 4
  EMWC_Add,                       // 5
  EMWC_MAX                        // 6
  #define EMWC_None                                  EMWC_None
  #define EMWC_Init                                  EMWC_Init
  #define EMWC_PreComplete                           EMWC_PreComplete
  #define EMWC_Complete                              EMWC_Complete
  #define EMWC_Remove                                EMWC_Remove
  #define EMWC_Add                                   EMWC_Add
  #define EMWC_MAX                                   EMWC_MAX
  #define EMissionWidgetMessageCategory_None         EMWC_None
  #define EMissionWidgetMessageCategory_Init         EMWC_Init
  #define EMissionWidgetMessageCategory_PreComplete  EMWC_PreComplete
  #define EMissionWidgetMessageCategory_Complete     EMWC_Complete
  #define EMissionWidgetMessageCategory_Remove       EMWC_Remove
  #define EMissionWidgetMessageCategory_Add          EMWC_Add
  #define EMissionWidgetMessageCategory_MAX          EMWC_MAX
} EMissionWidgetMessageCategory;
#define EMissionWidgetMessageType      EMissionWidgetMessageType
#define EMissionWidgetMessageCategory  EMissionWidgetMessageCategory

/* ---------------------------------------------------------- UWillowDialogNameTag ! ---------------------------------------------------------- */

typedef enum EchoPortraitType : unsigned char {
  ECHO_PORTRAIT_Scaleform,        // 0
  ECHO_PORTRAIT_Video,            // 1
  ECHO_PORTRAIT_MAX               // 2
  #define ECHO_PORTRAIT_Scaleform     ECHO_PORTRAIT_Scaleform
  #define ECHO_PORTRAIT_Video         ECHO_PORTRAIT_Video
  #define ECHO_PORTRAIT_MAX           ECHO_PORTRAIT_MAX
  #define EchoPortraitType_Scaleform  ECHO_PORTRAIT_Scaleform
  #define EchoPortraitType_Video      ECHO_PORTRAIT_Video
  #define EchoPortraitType_MAX        ECHO_PORTRAIT_MAX
} EchoPortraitType;
#define EchoPortraitType  EchoPortraitType

/* ---------------------------------------------------------- UExperienceResourcePool ! ---------------------------------------------------------- */

typedef enum EExperienceType : unsigned char {
  EXPERIENCE_Generic,             // 0
  EXPERIENCE_Combat,              // 1
  EXPERIENCE_Mission,             // 2
  EXPERIENCE_MAX                  // 3
  #define EXPERIENCE_Generic       EXPERIENCE_Generic
  #define EXPERIENCE_Combat        EXPERIENCE_Combat
  #define EXPERIENCE_Mission       EXPERIENCE_Mission
  #define EXPERIENCE_MAX           EXPERIENCE_MAX
  #define EExperienceType_Generic  EXPERIENCE_Generic
  #define EExperienceType_Combat   EXPERIENCE_Combat
  #define EExperienceType_Mission  EXPERIENCE_Mission
  #define EExperienceType_MAX      EXPERIENCE_MAX
} EExperienceType;
#define EExperienceType  EExperienceType

/* ---------------------------------------------------------- AWillowGameReplicationInfo ! ---------------------------------------------------------- */

typedef enum EMatchmakingState : unsigned char {
  MMS_Inactive,                   // 0
  MMS_Searching1,                 // 1
  MMS_Searching2,                 // 2
  MMS_Searching3,                 // 3
  MMS_MatchFound,                 // 4
  MMS_NoMatchFound,               // 5
  MMS_MAX                         // 6
  #define MMS_Inactive                    MMS_Inactive
  #define MMS_Searching1                  MMS_Searching1
  #define MMS_Searching2                  MMS_Searching2
  #define MMS_Searching3                  MMS_Searching3
  #define MMS_MatchFound                  MMS_MatchFound
  #define MMS_NoMatchFound                MMS_NoMatchFound
  #define MMS_MAX                         MMS_MAX
  #define EMatchmakingState_Inactive      MMS_Inactive
  #define EMatchmakingState_Searching1    MMS_Searching1
  #define EMatchmakingState_Searching2    MMS_Searching2
  #define EMatchmakingState_Searching3    MMS_Searching3
  #define EMatchmakingState_MatchFound    MMS_MatchFound
  #define EMatchmakingState_NoMatchFound  MMS_NoMatchFound
  #define EMatchmakingState_MAX           MMS_MAX
} EMatchmakingState;
#define EMatchmakingState  EMatchmakingState

/* ---------------------------------------------------------- AMissionTracker ! ---------------------------------------------------------- */

typedef enum EAdvanceTrackedMissionResult : unsigned char {
  ATMR_Success,                   // 0
  ATMR_NothingToDo,               // 1
  ATMR_Error,                     // 2
  ATMR_DidNotAdvanceObjectiveSet, // 3
  ATMR_MAX                        // 4
  #define ATMR_Success                                            ATMR_Success
  #define ATMR_NothingToDo                                        ATMR_NothingToDo
  #define ATMR_Error                                              ATMR_Error
  #define ATMR_DidNotAdvanceObjectiveSet                          ATMR_DidNotAdvanceObjectiveSet
  #define ATMR_MAX                                                ATMR_MAX
  #define EAdvanceTrackedMissionResult_Success                    ATMR_Success
  #define EAdvanceTrackedMissionResult_NothingToDo                ATMR_NothingToDo
  #define EAdvanceTrackedMissionResult_Error                      ATMR_Error
  #define EAdvanceTrackedMissionResult_DidNotAdvanceObjectiveSet  ATMR_DidNotAdvanceObjectiveSet
  #define EAdvanceTrackedMissionResult_MAX                        ATMR_MAX
} EAdvanceTrackedMissionResult;
#define EAdvanceTrackedMissionResult  EAdvanceTrackedMissionResult

/* ---------------------------------------------------------- UWillowPlayerInput ! ---------------------------------------------------------- */

typedef enum EButtonState : unsigned char {
  BUTTON_STATE_Pressed,           // 0
  BUTTON_STATE_Held,              // 1
  BUTTON_STATE_Released,          // 2
  BUTTON_STATE_Cleared,           // 3
  BUTTON_STATE_MAX                // 4
  #define BUTTON_STATE_Pressed   BUTTON_STATE_Pressed
  #define BUTTON_STATE_Held      BUTTON_STATE_Held
  #define BUTTON_STATE_Released  BUTTON_STATE_Released
  #define BUTTON_STATE_Cleared   BUTTON_STATE_Cleared
  #define BUTTON_STATE_MAX       BUTTON_STATE_MAX
  #define EButtonState_Pressed   BUTTON_STATE_Pressed
  #define EButtonState_Held      BUTTON_STATE_Held
  #define EButtonState_Released  BUTTON_STATE_Released
  #define EButtonState_Cleared   BUTTON_STATE_Cleared
  #define EButtonState_MAX       BUTTON_STATE_MAX
} EButtonState;
#define EButtonState  EButtonState

/* ---------------------------------------------------------- UInputDeviceDefinition ! ---------------------------------------------------------- */

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
  #define AXIS_PARAM_aBaseX          AXIS_PARAM_aBaseX
  #define AXIS_PARAM_aBaseY          AXIS_PARAM_aBaseY
  #define AXIS_PARAM_aBaseZ          AXIS_PARAM_aBaseZ
  #define AXIS_PARAM_aMouseX         AXIS_PARAM_aMouseX
  #define AXIS_PARAM_aMouseY         AXIS_PARAM_aMouseY
  #define AXIS_PARAM_aForward        AXIS_PARAM_aForward
  #define AXIS_PARAM_aTurn           AXIS_PARAM_aTurn
  #define AXIS_PARAM_aStrafe         AXIS_PARAM_aStrafe
  #define AXIS_PARAM_aUp             AXIS_PARAM_aUp
  #define AXIS_PARAM_aLookUp         AXIS_PARAM_aLookUp
  #define AXIS_PARAM_aPS3AccelX      AXIS_PARAM_aPS3AccelX
  #define AXIS_PARAM_aPS3AccelY      AXIS_PARAM_aPS3AccelY
  #define AXIS_PARAM_aPS3AccelZ      AXIS_PARAM_aPS3AccelZ
  #define AXIS_PARAM_aPS3Gyro        AXIS_PARAM_aPS3Gyro
  #define AXIS_PARAM_MAX             AXIS_PARAM_MAX
  #define EAxisParameter_aBaseX      AXIS_PARAM_aBaseX
  #define EAxisParameter_aBaseY      AXIS_PARAM_aBaseY
  #define EAxisParameter_aBaseZ      AXIS_PARAM_aBaseZ
  #define EAxisParameter_aMouseX     AXIS_PARAM_aMouseX
  #define EAxisParameter_aMouseY     AXIS_PARAM_aMouseY
  #define EAxisParameter_aForward    AXIS_PARAM_aForward
  #define EAxisParameter_aTurn       AXIS_PARAM_aTurn
  #define EAxisParameter_aStrafe     AXIS_PARAM_aStrafe
  #define EAxisParameter_aUp         AXIS_PARAM_aUp
  #define EAxisParameter_aLookUp     AXIS_PARAM_aLookUp
  #define EAxisParameter_aPS3AccelX  AXIS_PARAM_aPS3AccelX
  #define EAxisParameter_aPS3AccelY  AXIS_PARAM_aPS3AccelY
  #define EAxisParameter_aPS3AccelZ  AXIS_PARAM_aPS3AccelZ
  #define EAxisParameter_aPS3Gyro    AXIS_PARAM_aPS3Gyro
  #define EAxisParameter_MAX         AXIS_PARAM_MAX
} EAxisParameter;
#define EAxisParameter  EAxisParameter

/* ---------------------------------------------------------- UInputActionDefinition ! ---------------------------------------------------------- */

typedef enum EInputActionEvent : unsigned char {
  INPUT_ACTION_Begin,             // 0
  INPUT_ACTION_End,               // 1
  INPUT_ACTION_MAX                // 2
  #define INPUT_ACTION_Begin       INPUT_ACTION_Begin
  #define INPUT_ACTION_End         INPUT_ACTION_End
  #define INPUT_ACTION_MAX         INPUT_ACTION_MAX
  #define EInputActionEvent_Begin  INPUT_ACTION_Begin
  #define EInputActionEvent_End    INPUT_ACTION_End
  #define EInputActionEvent_MAX    INPUT_ACTION_MAX
} EInputActionEvent;
#define EInputActionEvent  EInputActionEvent

/* ---------------------------------------------------------- UTextureMovie ! ---------------------------------------------------------- */

typedef enum EMovieStreamSource : unsigned char {
  MovieStream_File,               // 0
  MovieStream_Memory,             // 1
  MovieStream_MAX                 // 2
  #define MovieStream_File           MovieStream_File
  #define MovieStream_Memory         MovieStream_Memory
  #define MovieStream_MAX            MovieStream_MAX
  #define EMovieStreamSource_File    MovieStream_File
  #define EMovieStreamSource_Memory  MovieStream_Memory
  #define EMovieStreamSource_MAX     MovieStream_MAX
} EMovieStreamSource;
#define EMovieStreamSource  EMovieStreamSource

/* ---------------------------------------------------------- UAIDebugCamera ! ---------------------------------------------------------- */

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
  #define DEBUGITEM_String                          DEBUGITEM_String
  #define DEBUGITEM_StringSpacer                    DEBUGITEM_StringSpacer
  #define DEBUGITEM_ScreenIcon                      DEBUGITEM_ScreenIcon
  #define DEBUGITEM_WorldString                     DEBUGITEM_WorldString
  #define DEBUGITEM_Icon                            DEBUGITEM_Icon
  #define DEBUGITEM_Line                            DEBUGITEM_Line
  #define DEBUGITEM_Box                             DEBUGITEM_Box
  #define DEBUGITEM_Circle                          DEBUGITEM_Circle
  #define DEBUGITEM_Cone                            DEBUGITEM_Cone
  #define DEBUGITEM_BarGraphScreenTop               DEBUGITEM_BarGraphScreenTop
  #define DEBUGITEM_BarGraphScreenTopTitle          DEBUGITEM_BarGraphScreenTopTitle
  #define DEBUGITEM_BarGraphScreenCenter            DEBUGITEM_BarGraphScreenCenter
  #define DEBUGITEM_BarGraphScreenCenterTitle       DEBUGITEM_BarGraphScreenCenterTitle
  #define DEBUGITEM_MAX                             DEBUGITEM_MAX
  #define EDebugItemType_String                     DEBUGITEM_String
  #define EDebugItemType_StringSpacer               DEBUGITEM_StringSpacer
  #define EDebugItemType_ScreenIcon                 DEBUGITEM_ScreenIcon
  #define EDebugItemType_WorldString                DEBUGITEM_WorldString
  #define EDebugItemType_Icon                       DEBUGITEM_Icon
  #define EDebugItemType_Line                       DEBUGITEM_Line
  #define EDebugItemType_Box                        DEBUGITEM_Box
  #define EDebugItemType_Circle                     DEBUGITEM_Circle
  #define EDebugItemType_Cone                       DEBUGITEM_Cone
  #define EDebugItemType_BarGraphScreenTop          DEBUGITEM_BarGraphScreenTop
  #define EDebugItemType_BarGraphScreenTopTitle     DEBUGITEM_BarGraphScreenTopTitle
  #define EDebugItemType_BarGraphScreenCenter       DEBUGITEM_BarGraphScreenCenter
  #define EDebugItemType_BarGraphScreenCenterTitle  DEBUGITEM_BarGraphScreenCenterTitle
  #define EDebugItemType_MAX                        DEBUGITEM_MAX
} EDebugItemType;
typedef enum EDebugAlignment : unsigned char {
  DEBUGALIGN_Left,                // 0
  DEBUGALIGN_Center,              // 1
  DEBUGALIGN_Right,               // 2
  DEBUGALIGN_LeftNoWrap,          // 3
  DEBUGALIGN_LeftColumn2,         // 4
  DEBUGALIGN_LeftColumn2NoWrap,   // 5
  DEBUGALIGN_MAX                  // 6
  #define DEBUGALIGN_Left                    DEBUGALIGN_Left
  #define DEBUGALIGN_Center                  DEBUGALIGN_Center
  #define DEBUGALIGN_Right                   DEBUGALIGN_Right
  #define DEBUGALIGN_LeftNoWrap              DEBUGALIGN_LeftNoWrap
  #define DEBUGALIGN_LeftColumn2             DEBUGALIGN_LeftColumn2
  #define DEBUGALIGN_LeftColumn2NoWrap       DEBUGALIGN_LeftColumn2NoWrap
  #define DEBUGALIGN_MAX                     DEBUGALIGN_MAX
  #define EDebugAlignment_Left               DEBUGALIGN_Left
  #define EDebugAlignment_Center             DEBUGALIGN_Center
  #define EDebugAlignment_Right              DEBUGALIGN_Right
  #define EDebugAlignment_LeftNoWrap         DEBUGALIGN_LeftNoWrap
  #define EDebugAlignment_LeftColumn2        DEBUGALIGN_LeftColumn2
  #define EDebugAlignment_LeftColumn2NoWrap  DEBUGALIGN_LeftColumn2NoWrap
  #define EDebugAlignment_MAX                DEBUGALIGN_MAX
} EDebugAlignment;
#define EDebugItemType   EDebugItemType
#define EDebugAlignment  EDebugAlignment

/* ---------------------------------------------------------- APylon ! ---------------------------------------------------------- */

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
  #define NAVEDGE_Normal                 NAVEDGE_Normal
  #define NAVEDGE_Mantle                 NAVEDGE_Mantle
  #define NAVEDGE_Coverslip              NAVEDGE_Coverslip
  #define NAVEDGE_SwatTurn               NAVEDGE_SwatTurn
  #define NAVEDGE_DropDown               NAVEDGE_DropDown
  #define NAVEDGE_PathObject             NAVEDGE_PathObject
  #define NAVEDGE_BackRefDummy           NAVEDGE_BackRefDummy
  #define NAVEDGE_Jump                   NAVEDGE_Jump
  #define NAVEDGE_MAX                    NAVEDGE_MAX
  #define ENavMeshEdgeType_Normal        NAVEDGE_Normal
  #define ENavMeshEdgeType_Mantle        NAVEDGE_Mantle
  #define ENavMeshEdgeType_Coverslip     NAVEDGE_Coverslip
  #define ENavMeshEdgeType_SwatTurn      NAVEDGE_SwatTurn
  #define ENavMeshEdgeType_DropDown      NAVEDGE_DropDown
  #define ENavMeshEdgeType_PathObject    NAVEDGE_PathObject
  #define ENavMeshEdgeType_BackRefDummy  NAVEDGE_BackRefDummy
  #define ENavMeshEdgeType_Jump          NAVEDGE_Jump
  #define ENavMeshEdgeType_MAX           NAVEDGE_MAX
} ENavMeshEdgeType;
#define ENavMeshEdgeType  ENavMeshEdgeType

/* ---------------------------------------------------------- UTargetableList ! ---------------------------------------------------------- */

typedef enum ETargetableListSearchType : unsigned char {
  TL_Enemy,                       // 0
  TL_Friendly,                    // 1
  TL_Neutral,                     // 2
  TL_All,                         // 3
  TL_MAX                          // 4
  #define TL_Enemy                            TL_Enemy
  #define TL_Friendly                         TL_Friendly
  #define TL_Neutral                          TL_Neutral
  #define TL_All                              TL_All
  #define TL_MAX                              TL_MAX
  #define ETargetableListSearchType_Enemy     TL_Enemy
  #define ETargetableListSearchType_Friendly  TL_Friendly
  #define ETargetableListSearchType_Neutral   TL_Neutral
  #define ETargetableListSearchType_All       TL_All
  #define ETargetableListSearchType_MAX       TL_MAX
} ETargetableListSearchType;
#define ETargetableListSearchType  ETargetableListSearchType

/* ---------------------------------------------------------- UPersistentGameDataManager ! ---------------------------------------------------------- */

typedef enum EPersistentOperation : unsigned char {
  PO_Saving,                      // 0
  PO_Restoring,                   // 1
  PO_MAX                          // 2
  #define PO_Saving                       PO_Saving
  #define PO_Restoring                    PO_Restoring
  #define PO_MAX                          PO_MAX
  #define EPersistentOperation_Saving     PO_Saving
  #define EPersistentOperation_Restoring  PO_Restoring
  #define EPersistentOperation_MAX        PO_MAX
} EPersistentOperation;
#define EPersistentOperation  EPersistentOperation

/* ---------------------------------------------------------- UScene ! ---------------------------------------------------------- */

typedef enum ESceneDepthPriorityGroup : unsigned char {
  SDPG_UnrealEdBackground,        // 0
  SDPG_World,                     // 1
  SDPG_Foreground,                // 2
  SDPG_UnrealEdForeground,        // 3
  SDPG_PostProcess,               // 4
  SDPG_WorldPreAlphaPostProcess,  // 5
  SDPG_AfterPostProcess,          // 6
  SDPG_MAX                        // 7
  #define SDPG_UnrealEdBackground                            SDPG_UnrealEdBackground
  #define SDPG_World                                         SDPG_World
  #define SDPG_Foreground                                    SDPG_Foreground
  #define SDPG_UnrealEdForeground                            SDPG_UnrealEdForeground
  #define SDPG_PostProcess                                   SDPG_PostProcess
  #define SDPG_WorldPreAlphaPostProcess                      SDPG_WorldPreAlphaPostProcess
  #define SDPG_AfterPostProcess                              SDPG_AfterPostProcess
  #define SDPG_MAX                                           SDPG_MAX
  #define ESceneDepthPriorityGroup_UnrealEdBackground        SDPG_UnrealEdBackground
  #define ESceneDepthPriorityGroup_World                     SDPG_World
  #define ESceneDepthPriorityGroup_Foreground                SDPG_Foreground
  #define ESceneDepthPriorityGroup_UnrealEdForeground        SDPG_UnrealEdForeground
  #define ESceneDepthPriorityGroup_PostProcess               SDPG_PostProcess
  #define ESceneDepthPriorityGroup_WorldPreAlphaPostProcess  SDPG_WorldPreAlphaPostProcess
  #define ESceneDepthPriorityGroup_AfterPostProcess          SDPG_AfterPostProcess
  #define ESceneDepthPriorityGroup_MAX                       SDPG_MAX
} ESceneDepthPriorityGroup;
typedef enum EDetailMode              : unsigned char {
  DM_Low,                         // 0
  DM_Medium,                      // 1
  DM_High,                        // 2
  DM_MAX                          // 3
  #define DM_Low              DM_Low
  #define DM_Medium           DM_Medium
  #define DM_High             DM_High
  #define DM_MAX              DM_MAX
  #define EDetailMode_Low     DM_Low
  #define EDetailMode_Medium  DM_Medium
  #define EDetailMode_High    DM_High
  #define EDetailMode_MAX     DM_MAX
} EDetailMode;
#define ESceneDepthPriorityGroup  ESceneDepthPriorityGroup
#define EDetailMode               EDetailMode

/* ---------------------------------------------------------- URule ! ---------------------------------------------------------- */

typedef enum EFlagEvalType        : unsigned char {
  FLAG_IsTrue,                    // 0
  FLAG_IsFalse,                   // 1
  FLAG_HasBeenTrueForXSeconds,    // 2
  FLAG_HasBeenFalseForXSeconds,   // 3
  FLAG_MAX                        // 4
  #define FLAG_IsTrue                            FLAG_IsTrue
  #define FLAG_IsFalse                           FLAG_IsFalse
  #define FLAG_HasBeenTrueForXSeconds            FLAG_HasBeenTrueForXSeconds
  #define FLAG_HasBeenFalseForXSeconds           FLAG_HasBeenFalseForXSeconds
  #define FLAG_MAX                               FLAG_MAX
  #define EFlagEvalType_IsTrue                   FLAG_IsTrue
  #define EFlagEvalType_IsFalse                  FLAG_IsFalse
  #define EFlagEvalType_HasBeenTrueForXSeconds   FLAG_HasBeenTrueForXSeconds
  #define EFlagEvalType_HasBeenFalseForXSeconds  FLAG_HasBeenFalseForXSeconds
  #define EFlagEvalType_MAX                      FLAG_MAX
} EFlagEvalType;
typedef enum ExecutionPatternType : unsigned char {
  RULEEXEC_Normal,                // 0
  RULEEXEC_Limited,               // 1
  RULEEXEC_MAX                    // 2
  #define RULEEXEC_Normal               RULEEXEC_Normal
  #define RULEEXEC_Limited              RULEEXEC_Limited
  #define RULEEXEC_MAX                  RULEEXEC_MAX
  #define ExecutionPatternType_Normal   RULEEXEC_Normal
  #define ExecutionPatternType_Limited  RULEEXEC_Limited
  #define ExecutionPatternType_MAX      RULEEXEC_MAX
} ExecutionPatternType;
#define EFlagEvalType         EFlagEvalType
#define ExecutionPatternType  ExecutionPatternType

/* ---------------------------------------------------------- UGearboxEditorNode ! ---------------------------------------------------------- */

typedef enum NodeType : unsigned char {
  NT_Event,                       // 0
  NT_Action,                      // 1
  NT_Variable,                    // 2
  NT_MAX                          // 3
  #define NT_Event           NT_Event
  #define NT_Action          NT_Action
  #define NT_Variable        NT_Variable
  #define NT_MAX             NT_MAX
  #define NodeType_Event     NT_Event
  // #define NodeType_Action    NT_Action
  #define NodeType_Variable  NT_Variable
  // #define NodeType_MAX       NT_MAX
} NodeType;
#define NodeType  NodeType

/* ---------------------------------------------------------- AWillowRadarManager ! ---------------------------------------------------------- */

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
  #define RadarIconType_None                   RadarIconType_None
  #define RadarIconType_Gunfire                RadarIconType_Gunfire
  #define RadarIconType_Threat                 RadarIconType_Threat
  #define RadarIconType_BountyBoard            RadarIconType_BountyBoard
  #define RadarIconType_Shop                   RadarIconType_Shop
  #define RadarIconType_Health                 RadarIconType_Health
  #define RadarIconType_NewU                   RadarIconType_NewU
  #define RadarIconType_CatchARide             RadarIconType_CatchARide
  #define RadarIconType_Settlement             RadarIconType_Settlement
  #define RadarIconType_MissionNPC             RadarIconType_MissionNPC
  #define RadarIconType_NamedNPC               RadarIconType_NamedNPC
  #define RadarIconType_Loot                   RadarIconType_Loot
  #define RadarIconType_Objective              RadarIconType_Objective
  #define RadarIconType_Checkpoint             RadarIconType_Checkpoint
  #define RadarIconType_TravelStation          RadarIconType_TravelStation
  #define RadarIconType_CustomizationStation   RadarIconType_CustomizationStation
  #define RadarIconType_LevelTransition        RadarIconType_LevelTransition
  #define RadarIconType_MAX                    RadarIconType_MAX
  #define ERadarIconType_None                  RadarIconType_None
  #define ERadarIconType_Gunfire               RadarIconType_Gunfire
  #define ERadarIconType_Threat                RadarIconType_Threat
  #define ERadarIconType_BountyBoard           RadarIconType_BountyBoard
  #define ERadarIconType_Shop                  RadarIconType_Shop
  #define ERadarIconType_Health                RadarIconType_Health
  #define ERadarIconType_NewU                  RadarIconType_NewU
  #define ERadarIconType_CatchARide            RadarIconType_CatchARide
  #define ERadarIconType_Settlement            RadarIconType_Settlement
  #define ERadarIconType_MissionNPC            RadarIconType_MissionNPC
  #define ERadarIconType_NamedNPC              RadarIconType_NamedNPC
  #define ERadarIconType_Loot                  RadarIconType_Loot
  #define ERadarIconType_Objective             RadarIconType_Objective
  #define ERadarIconType_Checkpoint            RadarIconType_Checkpoint
  #define ERadarIconType_TravelStation         RadarIconType_TravelStation
  #define ERadarIconType_CustomizationStation  RadarIconType_CustomizationStation
  #define ERadarIconType_LevelTransition       RadarIconType_LevelTransition
  #define ERadarIconType_MAX                   RadarIconType_MAX
} ERadarIconType;
#define ERadarIconType  ERadarIconType

/* ---------------------------------------------------------- UUIDataProvider_MenuItem ! ---------------------------------------------------------- */

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
  #define MENUOT_ComboReadOnly                MENUOT_ComboReadOnly
  #define MENUOT_ComboNumeric                 MENUOT_ComboNumeric
  #define MENUOT_CheckBox                     MENUOT_CheckBox
  #define MENUOT_Slider                       MENUOT_Slider
  #define MENUOT_Spinner                      MENUOT_Spinner
  #define MENUOT_EditBox                      MENUOT_EditBox
  #define MENUOT_CollectionCheckBox           MENUOT_CollectionCheckBox
  #define MENUOT_CollapsingList               MENUOT_CollapsingList
  #define MENUOT_MAX                          MENUOT_MAX
  #define EMenuOptionType_ComboReadOnly       MENUOT_ComboReadOnly
  #define EMenuOptionType_ComboNumeric        MENUOT_ComboNumeric
  #define EMenuOptionType_CheckBox            MENUOT_CheckBox
  #define EMenuOptionType_Slider              MENUOT_Slider
  #define EMenuOptionType_Spinner             MENUOT_Spinner
  #define EMenuOptionType_EditBox             MENUOT_EditBox
  #define EMenuOptionType_CollectionCheckBox  MENUOT_CollectionCheckBox
  #define EMenuOptionType_CollapsingList      MENUOT_CollapsingList
  #define EMenuOptionType_MAX                 MENUOT_MAX
} EMenuOptionType;
#define EMenuOptionType  EMenuOptionType

/* ---------------------------------------------------------- UBehaviorKernel ! ---------------------------------------------------------- */

typedef enum EBehaviorProcessState : unsigned char {
  BPROCESS_Uninitialized,         // 0
  BPROCESS_Terminated,            // 1
  BPROCESS_Running,               // 2
  BPROCESS_Suspended,             // 3
  BPROCESS_MAX                    // 4
  #define BPROCESS_Uninitialized               BPROCESS_Uninitialized
  #define BPROCESS_Terminated                  BPROCESS_Terminated
  #define BPROCESS_Running                     BPROCESS_Running
  #define BPROCESS_Suspended                   BPROCESS_Suspended
  #define BPROCESS_MAX                         BPROCESS_MAX
  #define EBehaviorProcessState_Uninitialized  BPROCESS_Uninitialized
  #define EBehaviorProcessState_Terminated     BPROCESS_Terminated
  #define EBehaviorProcessState_Running        BPROCESS_Running
  #define EBehaviorProcessState_Suspended      BPROCESS_Suspended
  #define EBehaviorProcessState_MAX            BPROCESS_MAX
} EBehaviorProcessState;
typedef enum EBehaviorThreadState  : unsigned char {
  BTHREAD_Waiting,                // 0
  BTHREAD_Running,                // 1
  BTHREAD_Terminated,             // 2
  BTHREAD_Unknown,                // 3
  BTHREAD_MAX                     // 4
  #define BTHREAD_Waiting                  BTHREAD_Waiting
  #define BTHREAD_Running                  BTHREAD_Running
  #define BTHREAD_Terminated               BTHREAD_Terminated
  #define BTHREAD_Unknown                  BTHREAD_Unknown
  #define BTHREAD_MAX                      BTHREAD_MAX
  #define EBehaviorThreadState_Waiting     BTHREAD_Waiting
  #define EBehaviorThreadState_Running     BTHREAD_Running
  #define EBehaviorThreadState_Terminated  BTHREAD_Terminated
  #define EBehaviorThreadState_Unknown     BTHREAD_Unknown
  #define EBehaviorThreadState_MAX         BTHREAD_MAX
} EBehaviorThreadState;
#define EBehaviorProcessState  EBehaviorProcessState
#define EBehaviorThreadState   EBehaviorThreadState

/* ---------------------------------------------------------- UCombatMusicManager ! ---------------------------------------------------------- */

typedef enum ECombatMusicManagerState : unsigned char {
  CMMS_Playing,                   // 0
  CMMS_VolumeFading,              // 1
  CMMS_Idle,                      // 2
  CMMS_MAX                        // 3
  #define CMMS_Playing                           CMMS_Playing
  #define CMMS_VolumeFading                      CMMS_VolumeFading
  #define CMMS_Idle                              CMMS_Idle
  #define CMMS_MAX                               CMMS_MAX
  #define ECombatMusicManagerState_Playing       CMMS_Playing
  #define ECombatMusicManagerState_VolumeFading  CMMS_VolumeFading
  #define ECombatMusicManagerState_Idle          CMMS_Idle
  #define ECombatMusicManagerState_MAX           CMMS_MAX
} ECombatMusicManagerState;
#define ECombatMusicManagerState  ECombatMusicManagerState

/* ---------------------------------------------------------- UTargetIterator ! ---------------------------------------------------------- */

typedef enum ETargetIterator : unsigned char {
  TARGITER_UpdateState,           // 0
  TARGITER_PriorityCalc,          // 1
  TARGITER_ForgetTarget,          // 2
  TARGITER_RemoveTarget,          // 3
  TARGITER_PostProcess,           // 4
  TARGITER_MAX                    // 5
  #define TARGITER_UpdateState          TARGITER_UpdateState
  #define TARGITER_PriorityCalc         TARGITER_PriorityCalc
  #define TARGITER_ForgetTarget         TARGITER_ForgetTarget
  #define TARGITER_RemoveTarget         TARGITER_RemoveTarget
  #define TARGITER_PostProcess          TARGITER_PostProcess
  #define TARGITER_MAX                  TARGITER_MAX
  #define ETargetIterator_UpdateState   TARGITER_UpdateState
  #define ETargetIterator_PriorityCalc  TARGITER_PriorityCalc
  #define ETargetIterator_ForgetTarget  TARGITER_ForgetTarget
  #define ETargetIterator_RemoveTarget  TARGITER_RemoveTarget
  #define ETargetIterator_PostProcess   TARGITER_PostProcess
  #define ETargetIterator_MAX           TARGITER_MAX
} ETargetIterator;
#define ETargetIterator  ETargetIterator

/* ---------------------------------------------------------- UKnowledgeRecord ! ---------------------------------------------------------- */

typedef enum KDBCategory : unsigned char {
  KDB_None,                       // 0
  KDB_Standard,                   // 1
  KDB_MAX                         // 2
  #define KDB_None              KDB_None
  #define KDB_Standard          KDB_Standard
  #define KDB_MAX               KDB_MAX
  #define KDBCategory_None      KDB_None
  #define KDBCategory_Standard  KDB_Standard
  #define KDBCategory_MAX       KDB_MAX
} KDBCategory;
typedef enum KDBEvalType : unsigned char {
  Eval_Poll,                      // 0
  Eval_TargetIterator,            // 1
  Eval_MAX                        // 2
  #define Eval_Poll                   Eval_Poll
  #define Eval_TargetIterator         Eval_TargetIterator
  #define Eval_MAX                    Eval_MAX
  #define KDBEvalType_Poll            Eval_Poll
  #define KDBEvalType_TargetIterator  Eval_TargetIterator
  #define KDBEvalType_MAX             Eval_MAX
} KDBEvalType;
#define KDBCategory  KDBCategory
#define KDBEvalType  KDBEvalType

/* ---------------------------------------------------------- UAITracker ! ---------------------------------------------------------- */

typedef enum ESnapshotEventType : unsigned char {
  SNAP_NoEvent,                   // 0
  SNAP_ChildSequenceStart,        // 1
  SNAP_RuleStart,                 // 2
  SNAP_RuleEnd,                   // 3
  SNAP_RuleInterrupt,             // 4
  SNAP_SwitchRuleSet,             // 5
  SNAP_PreventNewRules,           // 6
  SNAP_MAX                        // 7
  #define SNAP_NoEvent                           SNAP_NoEvent
  #define SNAP_ChildSequenceStart                SNAP_ChildSequenceStart
  #define SNAP_RuleStart                         SNAP_RuleStart
  #define SNAP_RuleEnd                           SNAP_RuleEnd
  #define SNAP_RuleInterrupt                     SNAP_RuleInterrupt
  #define SNAP_SwitchRuleSet                     SNAP_SwitchRuleSet
  #define SNAP_PreventNewRules                   SNAP_PreventNewRules
  #define SNAP_MAX                               SNAP_MAX
  #define ESnapshotEventType_NoEvent             SNAP_NoEvent
  #define ESnapshotEventType_ChildSequenceStart  SNAP_ChildSequenceStart
  #define ESnapshotEventType_RuleStart           SNAP_RuleStart
  #define ESnapshotEventType_RuleEnd             SNAP_RuleEnd
  #define ESnapshotEventType_RuleInterrupt       SNAP_RuleInterrupt
  #define ESnapshotEventType_SwitchRuleSet       SNAP_SwitchRuleSet
  #define ESnapshotEventType_PreventNewRules     SNAP_PreventNewRules
  #define ESnapshotEventType_MAX                 SNAP_MAX
} ESnapshotEventType;
#define ESnapshotEventType  ESnapshotEventType

/* ---------------------------------------------------------- UAwarenessZoneDefinition ! ---------------------------------------------------------- */

typedef enum EViewConeStyle           : unsigned char {
  VIEWCONE_UseSightBone,          // 0
  VIEWCONE_UsePawnRotation,       // 1
  VIEWCONE_MAX                    // 2
  #define VIEWCONE_UseSightBone           VIEWCONE_UseSightBone
  #define VIEWCONE_UsePawnRotation        VIEWCONE_UsePawnRotation
  #define VIEWCONE_MAX                    VIEWCONE_MAX
  #define EViewConeStyle_UseSightBone     VIEWCONE_UseSightBone
  #define EViewConeStyle_UsePawnRotation  VIEWCONE_UsePawnRotation
  #define EViewConeStyle_MAX              VIEWCONE_MAX
} EViewConeStyle;
typedef enum ESpecialExposureBehavior : unsigned char {
  EXPOSUREBEHAVIOR_Normal,        // 0
  EXPOSUREBEHAVIOR_AlwaysSeeThreats,// 1
  EXPOSUREBEHAVIOR_NeverSeeThreats,// 2
  EXPOSUREBEHAVIOR_MAX            // 3
  #define EXPOSUREBEHAVIOR_Normal                    EXPOSUREBEHAVIOR_Normal
  #define EXPOSUREBEHAVIOR_AlwaysSeeThreats          EXPOSUREBEHAVIOR_AlwaysSeeThreats
  #define EXPOSUREBEHAVIOR_NeverSeeThreats           EXPOSUREBEHAVIOR_NeverSeeThreats
  #define EXPOSUREBEHAVIOR_MAX                       EXPOSUREBEHAVIOR_MAX
  #define ESpecialExposureBehavior_Normal            EXPOSUREBEHAVIOR_Normal
  #define ESpecialExposureBehavior_AlwaysSeeThreats  EXPOSUREBEHAVIOR_AlwaysSeeThreats
  #define ESpecialExposureBehavior_NeverSeeThreats   EXPOSUREBEHAVIOR_NeverSeeThreats
  #define ESpecialExposureBehavior_MAX               EXPOSUREBEHAVIOR_MAX
} ESpecialExposureBehavior;
typedef enum EHearingBehavior         : unsigned char {
  HEARINGBEHAVIOR_NeverHear,      // 0
  HEARINGBEHAVIOR_HearIfExposed,  // 1
  HEARINGBEHAVIOR_AlwaysHear,     // 2
  HEARINGBEHAVIOR_MAX             // 3
  #define HEARINGBEHAVIOR_NeverHear       HEARINGBEHAVIOR_NeverHear
  #define HEARINGBEHAVIOR_HearIfExposed   HEARINGBEHAVIOR_HearIfExposed
  #define HEARINGBEHAVIOR_AlwaysHear      HEARINGBEHAVIOR_AlwaysHear
  #define HEARINGBEHAVIOR_MAX             HEARINGBEHAVIOR_MAX
  #define EHearingBehavior_NeverHear      HEARINGBEHAVIOR_NeverHear
  #define EHearingBehavior_HearIfExposed  HEARINGBEHAVIOR_HearIfExposed
  #define EHearingBehavior_AlwaysHear     HEARINGBEHAVIOR_AlwaysHear
  #define EHearingBehavior_MAX            HEARINGBEHAVIOR_MAX
} EHearingBehavior;
#define EViewConeStyle            EViewConeStyle
#define ESpecialExposureBehavior  ESpecialExposureBehavior
#define EHearingBehavior          EHearingBehavior

/* ---------------------------------------------------------- UOnlineAuthInterfaceBaseImpl ! ---------------------------------------------------------- */

typedef enum EAuthStatus : unsigned char {
  AUS_NotStarted,                 // 0
  AUS_Pending,                    // 1
  AUS_Authenticated,              // 2
  AUS_Failed,                     // 3
  AUS_MAX                         // 4
  #define AUS_NotStarted             AUS_NotStarted
  #define AUS_Pending                AUS_Pending
  #define AUS_Authenticated          AUS_Authenticated
  #define AUS_Failed                 AUS_Failed
  #define AUS_MAX                    AUS_MAX
  #define EAuthStatus_NotStarted     AUS_NotStarted
  #define EAuthStatus_Pending        AUS_Pending
  #define EAuthStatus_Authenticated  AUS_Authenticated
  #define EAuthStatus_Failed         AUS_Failed
  #define EAuthStatus_MAX            AUS_MAX
} EAuthStatus;
#define EAuthStatus  EAuthStatus

/* ---------------------------------------------------------- UVendingMachineExGFxMovie ! ---------------------------------------------------------- */

typedef enum EShopMode : unsigned char {
  SHOPMODE_Sell,                  // 0
  SHOPMODE_Buy,                   // 1
  SHOPMODE_BuyBack,               // 2
  SHOPMODE_MAX                    // 3
  #define SHOPMODE_Sell      SHOPMODE_Sell
  #define SHOPMODE_Buy       SHOPMODE_Buy
  #define SHOPMODE_BuyBack   SHOPMODE_BuyBack
  #define SHOPMODE_MAX       SHOPMODE_MAX
  #define EShopMode_Sell     SHOPMODE_Sell
  #define EShopMode_Buy      SHOPMODE_Buy
  #define EShopMode_BuyBack  SHOPMODE_BuyBack
  #define EShopMode_MAX      SHOPMODE_MAX
} EShopMode;
#define EShopMode  EShopMode

/* ---------------------------------------------------------- UIShop ! ---------------------------------------------------------- */

typedef enum ETransactionStatus : unsigned char {
  TS_TransactionInProgress,       // 0
  TS_TransactionComplete,         // 1
  TS_TransactionFailed,           // 2
  TS_MAX                          // 3
  #define TS_TransactionInProgress                  TS_TransactionInProgress
  #define TS_TransactionComplete                    TS_TransactionComplete
  #define TS_TransactionFailed                      TS_TransactionFailed
  #define TS_MAX                                    TS_MAX
  #define ETransactionStatus_TransactionInProgress  TS_TransactionInProgress
  #define ETransactionStatus_TransactionComplete    TS_TransactionComplete
  #define ETransactionStatus_TransactionFailed      TS_TransactionFailed
  #define ETransactionStatus_MAX                    TS_MAX
} ETransactionStatus;
typedef enum EShopItemStatus    : unsigned char {
  SIS_ItemCanBePurchased,         // 0
  SIS_NotEnoughRoomForItem,       // 1
  SIS_PlayerCannotAffordItem,     // 2
  SIS_PlayerCannotUseItem,        // 3
  SIS_InvalidItem,                // 4
  SIS_MAX                         // 5
  #define SIS_ItemCanBePurchased                  SIS_ItemCanBePurchased
  #define SIS_NotEnoughRoomForItem                SIS_NotEnoughRoomForItem
  #define SIS_PlayerCannotAffordItem              SIS_PlayerCannotAffordItem
  #define SIS_PlayerCannotUseItem                 SIS_PlayerCannotUseItem
  #define SIS_InvalidItem                         SIS_InvalidItem
  #define SIS_MAX                                 SIS_MAX
  #define EShopItemStatus_ItemCanBePurchased      SIS_ItemCanBePurchased
  #define EShopItemStatus_NotEnoughRoomForItem    SIS_NotEnoughRoomForItem
  #define EShopItemStatus_PlayerCannotAffordItem  SIS_PlayerCannotAffordItem
  #define EShopItemStatus_PlayerCannotUseItem     SIS_PlayerCannotUseItem
  #define EShopItemStatus_InvalidItem             SIS_InvalidItem
  #define EShopItemStatus_MAX                     SIS_MAX
} EShopItemStatus;
typedef enum EShopType          : unsigned char {
  SType_Weapons,                  // 0
  SType_Items,                    // 1
  SType_Health,                   // 2
  SType_BlackMarket,              // 3
  SType_MAX                       // 4
  #define SType_Weapons          SType_Weapons
  #define SType_Items            SType_Items
  #define SType_Health           SType_Health
  #define SType_BlackMarket      SType_BlackMarket
  #define SType_MAX              SType_MAX
  #define EShopType_Weapons      SType_Weapons
  #define EShopType_Items        SType_Items
  #define EShopType_Health       SType_Health
  #define EShopType_BlackMarket  SType_BlackMarket
  #define EShopType_MAX          SType_MAX
} EShopType;
#define ETransactionStatus  ETransactionStatus
#define EShopItemStatus     EShopItemStatus
#define EShopType           EShopType

/* ---------------------------------------------------------- UGFxActorMoviePool ! ---------------------------------------------------------- */

typedef enum EGFxMoviePooling : unsigned char {
  GMP_Pooled,                     // 0
  GMP_Shared,                     // 1
  GMP_Instanced,                  // 2
  GMP_MAX                         // 3
  #define GMP_Pooled                  GMP_Pooled
  #define GMP_Shared                  GMP_Shared
  #define GMP_Instanced               GMP_Instanced
  #define GMP_MAX                     GMP_MAX
  #define EGFxMoviePooling_Pooled     GMP_Pooled
  #define EGFxMoviePooling_Shared     GMP_Shared
  #define EGFxMoviePooling_Instanced  GMP_Instanced
  #define EGFxMoviePooling_MAX        GMP_MAX
} EGFxMoviePooling;
#define EGFxMoviePooling  EGFxMoviePooling

/* ---------------------------------------------------------- UCameraShake ! ---------------------------------------------------------- */

typedef enum EInitialOscillatorOffset : unsigned char {
  EOO_OffsetRandom,               // 0
  EOO_OffsetZero,                 // 1
  EOO_MAX                         // 2
  #define EOO_OffsetRandom                       EOO_OffsetRandom
  #define EOO_OffsetZero                         EOO_OffsetZero
  #define EOO_MAX                                EOO_MAX
  #define EInitialOscillatorOffset_OffsetRandom  EOO_OffsetRandom
  #define EInitialOscillatorOffset_OffsetZero    EOO_OffsetZero
  #define EInitialOscillatorOffset_MAX           EOO_MAX
} EInitialOscillatorOffset;
#define EInitialOscillatorOffset  EInitialOscillatorOffset

/* ---------------------------------------------------------- UDeveloperPerksDefinition ! ---------------------------------------------------------- */

typedef enum EGamerPic                : unsigned char {
  GAMERPIC_Min,                   // 0
  GAMERPIC_MAX                    // 1
  #define GAMERPIC_Min   GAMERPIC_Min
  #define GAMERPIC_MAX   GAMERPIC_MAX
  #define EGamerPic_Min  GAMERPIC_Min
  #define EGamerPic_MAX  GAMERPIC_MAX
} EGamerPic;
typedef enum EDeveloperPerksPlatforms : unsigned char {
  DPP_PC,                         // 0
  DPP_360,                        // 1
  DPP_PS3,                        // 2
  DPP_Any,                        // 3
  DPP_MAX                         // 4
  #define DPP_PC                        DPP_PC
  #define DPP_360                       DPP_360
  #define DPP_PS3                       DPP_PS3
  #define DPP_Any                       DPP_Any
  #define DPP_MAX                       DPP_MAX
  #define EDeveloperPerksPlatforms_PC   DPP_PC
  #define EDeveloperPerksPlatforms_360  DPP_360
  #define EDeveloperPerksPlatforms_PS3  DPP_PS3
  #define EDeveloperPerksPlatforms_Any  DPP_Any
  #define EDeveloperPerksPlatforms_MAX  DPP_MAX
} EDeveloperPerksPlatforms;
#define EGamerPic                 EGamerPic
#define EDeveloperPerksPlatforms  EDeveloperPerksPlatforms
_DECL_TARRAY(EGamerPic);

/* ---------------------------------------------------------- UAnimNodeSpecialMoveBlend ! ---------------------------------------------------------- */

typedef enum EAnimState : unsigned char {
  EAnimState_None,                // 0
  EAnimState_Playing,             // 1
  EAnimState_Finished,            // 2
  EAnimState_BlendingOut,         // 3
  EAnimState_MAX                  // 4
  #define EAnimState_None         EAnimState_None
  #define EAnimState_Playing      EAnimState_Playing
  #define EAnimState_Finished     EAnimState_Finished
  #define EAnimState_BlendingOut  EAnimState_BlendingOut
  #define EAnimState_MAX          EAnimState_MAX
} EAnimState;
#define EAnimState  EAnimState

/* ---------------------------------------------------------- UChallengesPanelGFxObject ! ---------------------------------------------------------- */

typedef enum EChallengePanelSortMode : unsigned char {
  ECPSM_Category,                 // 0
  ECPSM_LevelCompletion,          // 1
  ECPSM_Max                       // 2
  #define ECPSM_Category                           ECPSM_Category
  #define ECPSM_LevelCompletion                    ECPSM_LevelCompletion
  #define ECPSM_Max                                ECPSM_Max
  #define EChallengePanelSortMode_Category         ECPSM_Category
  #define EChallengePanelSortMode_LevelCompletion  ECPSM_LevelCompletion
  #define EChallengePanelSortMode_Max              ECPSM_Max
} EChallengePanelSortMode;
#define EChallengePanelSortMode  EChallengePanelSortMode

/* ---------------------------------------------------------- UStanceTypeDefinition ! ---------------------------------------------------------- */

typedef enum EMoveStyle     : unsigned char {
  MOVE_Strafe,                    // 0
  MOVE_Forward,                   // 1
  MOVE_MAX                        // 2
  #define MOVE_Strafe         MOVE_Strafe
  #define MOVE_Forward        MOVE_Forward
  #define MOVE_MAX            MOVE_MAX
  #define EMoveStyle_Strafe   MOVE_Strafe
  #define EMoveStyle_Forward  MOVE_Forward
  #define EMoveStyle_MAX      MOVE_MAX
} EMoveStyle;
typedef enum EDefaultStance : unsigned char {
  STANCE_Patrol,                  // 0
  STANCE_Run,                     // 1
  STANCE_Sprint,                  // 2
  STANCE_Injured,                 // 3
  STANCE_None,                    // 4
  STANCE_Crouch,                  // 5
  STANCE_MAX                      // 6
  #define STANCE_Patrol           STANCE_Patrol
  #define STANCE_Run              STANCE_Run
  #define STANCE_Sprint           STANCE_Sprint
  #define STANCE_Injured          STANCE_Injured
  #define STANCE_None             STANCE_None
  #define STANCE_Crouch           STANCE_Crouch
  #define STANCE_MAX              STANCE_MAX
  #define EDefaultStance_Patrol   STANCE_Patrol
  #define EDefaultStance_Run      STANCE_Run
  #define EDefaultStance_Sprint   STANCE_Sprint
  #define EDefaultStance_Injured  STANCE_Injured
  #define EDefaultStance_None     STANCE_None
  #define EDefaultStance_Crouch   STANCE_Crouch
  #define EDefaultStance_MAX      STANCE_MAX
} EDefaultStance;
#define EMoveStyle      EMoveStyle
#define EDefaultStance  EDefaultStance

/* ---------------------------------------------------------- UGearboxAnimDefinition ! ---------------------------------------------------------- */

typedef enum EEndingCondition : unsigned char {
  EC_StopOnLastFrame,             // 0
  EC_OnAnimEnd,                   // 1
  EC_OnBlendOut,                  // 2
  EC_Loop,                        // 3
  EC_MAX                          // 4
  #define EC_StopOnLastFrame                EC_StopOnLastFrame
  #define EC_OnAnimEnd                      EC_OnAnimEnd
  #define EC_OnBlendOut                     EC_OnBlendOut
  #define EC_Loop                           EC_Loop
  #define EC_MAX                            EC_MAX
  #define EEndingCondition_StopOnLastFrame  EC_StopOnLastFrame
  #define EEndingCondition_OnAnimEnd        EC_OnAnimEnd
  #define EEndingCondition_OnBlendOut       EC_OnBlendOut
  #define EEndingCondition_Loop             EC_Loop
  #define EEndingCondition_MAX              EC_MAX
} EEndingCondition;
#define EEndingCondition  EEndingCondition

/* ---------------------------------------------------------- USkillTreeGFxObject ! ---------------------------------------------------------- */

typedef enum ESkillIconState         : unsigned char {
  eSIS_Disabled,                  // 0
  eSIS_Enabled,                   // 1
  eSIS_Partial,                   // 2
  eSIS_Maxed,                     // 3
  eSIS_MAX                        // 4
  #define eSIS_Disabled             eSIS_Disabled
  #define eSIS_Enabled              eSIS_Enabled
  #define eSIS_Partial              eSIS_Partial
  #define eSIS_Maxed                eSIS_Maxed
  #define eSIS_MAX                  eSIS_MAX
  #define ESkillIconState_Disabled  eSIS_Disabled
  #define ESkillIconState_Enabled   eSIS_Enabled
  #define ESkillIconState_Partial   eSIS_Partial
  #define ESkillIconState_Maxed     eSIS_Maxed
  #define ESkillIconState_MAX       eSIS_MAX
} ESkillIconState;
typedef enum ESkillTreeFailureReason : unsigned char {
  eFR_NoSkillPoints,              // 0
  eFR_SkillLocked,                // 1
  eFR_SkillMaxed,                 // 2
  eFR_DataIssue,                  // 3
  eFR_NoFailure,                  // 4
  eFR_MAX                         // 5
  #define eFR_NoSkillPoints                      eFR_NoSkillPoints
  #define eFR_SkillLocked                        eFR_SkillLocked
  #define eFR_SkillMaxed                         eFR_SkillMaxed
  #define eFR_DataIssue                          eFR_DataIssue
  #define eFR_NoFailure                          eFR_NoFailure
  #define eFR_MAX                                eFR_MAX
  #define ESkillTreeFailureReason_NoSkillPoints  eFR_NoSkillPoints
  #define ESkillTreeFailureReason_SkillLocked    eFR_SkillLocked
  #define ESkillTreeFailureReason_SkillMaxed     eFR_SkillMaxed
  #define ESkillTreeFailureReason_DataIssue      eFR_DataIssue
  #define ESkillTreeFailureReason_NoFailure      eFR_NoFailure
  #define ESkillTreeFailureReason_MAX            eFR_MAX
} ESkillTreeFailureReason;
typedef enum ENavDirection           : unsigned char {
  EN_Up,                          // 0
  EN_Down,                        // 1
  EN_Left,                        // 2
  EN_Right,                       // 3
  EN_None,                        // 4
  EN_MAX                          // 5
  #define EN_Up                EN_Up
  #define EN_Down              EN_Down
  #define EN_Left              EN_Left
  #define EN_Right             EN_Right
  #define EN_None              EN_None
  #define EN_MAX               EN_MAX
  #define ENavDirection_Up     EN_Up
  #define ENavDirection_Down   EN_Down
  #define ENavDirection_Left   EN_Left
  #define ENavDirection_Right  EN_Right
  #define ENavDirection_None   EN_None
  #define ENavDirection_MAX    EN_MAX
} ENavDirection;
#define ESkillIconState          ESkillIconState
#define ESkillTreeFailureReason  ESkillTreeFailureReason
#define ENavDirection            ENavDirection

/* ---------------------------------------------------------- UChallengesScreenGFxObject ! ---------------------------------------------------------- */

typedef enum EChallengePanel : unsigned char {
  ECP_Badass,                     // 0
  ECP_Challenges,                 // 1
  ECP_MAX                         // 2
  #define ECP_Badass                  ECP_Badass
  #define ECP_Challenges              ECP_Challenges
  #define ECP_MAX                     ECP_MAX
  #define EChallengePanel_Badass      ECP_Badass
  #define EChallengePanel_Challenges  ECP_Challenges
  #define EChallengePanel_MAX         ECP_MAX
} EChallengePanel;
#define EChallengePanel  EChallengePanel

/* ---------------------------------------------------------- UBodyWeaponHoldDefinition ! ---------------------------------------------------------- */

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
  #define BWA_Fire                        BWA_Fire
  #define BWA_FireRecoil                  BWA_FireRecoil
  #define BWA_Melee                       BWA_Melee
  #define BWA_Reload                      BWA_Reload
  #define BWA_Equip                       BWA_Equip
  #define BWA_PutDown                     BWA_PutDown
  #define BWA_PutDownSwap                 BWA_PutDownSwap
  #define BWA_ThrowGrenade                BWA_ThrowGrenade
  #define BWA_GrabEquip                   BWA_GrabEquip
  #define BWA_MeleeSelf                   BWA_MeleeSelf
  #define BWA_MAX                         BWA_MAX
  #define EBodyWeaponAction_Fire          BWA_Fire
  #define EBodyWeaponAction_FireRecoil    BWA_FireRecoil
  #define EBodyWeaponAction_Melee         BWA_Melee
  #define EBodyWeaponAction_Reload        BWA_Reload
  #define EBodyWeaponAction_Equip         BWA_Equip
  #define EBodyWeaponAction_PutDown       BWA_PutDown
  #define EBodyWeaponAction_PutDownSwap   BWA_PutDownSwap
  #define EBodyWeaponAction_ThrowGrenade  BWA_ThrowGrenade
  #define EBodyWeaponAction_GrabEquip     BWA_GrabEquip
  #define EBodyWeaponAction_MeleeSelf     BWA_MeleeSelf
  #define EBodyWeaponAction_MAX           BWA_MAX
} EBodyWeaponAction;
typedef enum EBodyWeaponActionPosture : unsigned char  {
  BWAP_All,                       // 0
  BWAP_Standing,                  // 1
  BWAP_Crouched,                  // 2
  BWAP_Injured,                   // 3
  BWAP_MAX                        // 4
  #define BWAP_All                           BWAP_All
  #define BWAP_Standing                      BWAP_Standing
  #define BWAP_Crouched                      BWAP_Crouched
  #define BWAP_Injured                       BWAP_Injured
  #define BWAP_MAX                           BWAP_MAX
  #define EBodyWeaponActionPosture_All       BWAP_All
  #define EBodyWeaponActionPosture_Standing  BWAP_Standing
  #define EBodyWeaponActionPosture_Crouched  BWAP_Crouched
  #define EBodyWeaponActionPosture_Injured   BWAP_Injured
  #define EBodyWeaponActionPosture_MAX       BWAP_MAX
} EBodyWeaponActionPosture;
#define EBodyWeaponAction         EBodyWeaponAction
#define EBodyWeaponActionPosture  EBodyWeaponActionPosture

/* ---------------------------------------------------------- UDOFAndBloomEffect ! ---------------------------------------------------------- */

typedef enum EDOFType    : unsigned char  {
  DOFType_SimpleDOF,              // 0
  DOFType_ReferenceDOF,           // 1
  DOFType_BokehDOF,               // 2
  DOFType_MAX                     // 3
  #define DOFType_SimpleDOF      DOFType_SimpleDOF
  #define DOFType_ReferenceDOF   DOFType_ReferenceDOF
  #define DOFType_BokehDOF       DOFType_BokehDOF
  #define DOFType_MAX            DOFType_MAX
  #define EDOFType_SimpleDOF     DOFType_SimpleDOF
  #define EDOFType_ReferenceDOF  DOFType_ReferenceDOF
  #define EDOFType_BokehDOF      DOFType_BokehDOF
  #define EDOFType_MAX           DOFType_MAX
} EDOFType;
typedef enum EDOFQuality : unsigned char  {
  DOFQuality_Low,                 // 0
  DOFQuality_Medium,              // 1
  DOFQuality_High,                // 2
  DOFQuality_MAX                  // 3
  #define DOFQuality_Low      DOFQuality_Low
  #define DOFQuality_Medium   DOFQuality_Medium
  #define DOFQuality_High     DOFQuality_High
  #define DOFQuality_MAX      DOFQuality_MAX
  #define EDOFQuality_Low     DOFQuality_Low
  #define EDOFQuality_Medium  DOFQuality_Medium
  #define EDOFQuality_High    DOFQuality_High
  #define EDOFQuality_MAX     DOFQuality_MAX
} EDOFQuality;
#define EDOFType     EDOFType
#define EDOFQuality  EDOFQuality

/* ---------------------------------------------------------- UUberPostProcessEffect ! ---------------------------------------------------------- */

typedef enum ETonemapperType : unsigned char {
  Tonemapper_Off,                 // 0
  Tonemapper_Filmic,              // 1
  Tonemapper_Customizable,        // 2
  Tonemapper_MAX                  // 3
  #define Tonemapper_Off                Tonemapper_Off
  #define Tonemapper_Filmic             Tonemapper_Filmic
  #define Tonemapper_Customizable       Tonemapper_Customizable
  #define Tonemapper_MAX                Tonemapper_MAX
  #define ETonemapperType_Off           Tonemapper_Off
  #define ETonemapperType_Filmic        Tonemapper_Filmic
  #define ETonemapperType_Customizable  Tonemapper_Customizable
  #define ETonemapperType_MAX           Tonemapper_MAX
} ETonemapperType;
#define ETonemapperType  ETonemapperType

/* ---------------------------------------------------------- AWillowTradeManager ! ---------------------------------------------------------- */

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
  #define TMS_Uninitialized                          TMS_Uninitialized
  #define TMS_OutgoingRequestPending                 TMS_OutgoingRequestPending
  #define TMS_IncomingRequestPending                 TMS_IncomingRequestPending
  #define TMS_Trading                                TMS_Trading
  #define TMS_Dueling                                TMS_Dueling
  #define TMS_ResolvingTrade                         TMS_ResolvingTrade
  #define TMS_ResolvingDuelWon                       TMS_ResolvingDuelWon
  #define TMS_ResolvingDuelLost                      TMS_ResolvingDuelLost
  #define TMS_MAX                                    TMS_MAX
  #define TradeManagerStatus_Uninitialized           TMS_Uninitialized
  #define TradeManagerStatus_OutgoingRequestPending  TMS_OutgoingRequestPending
  #define TradeManagerStatus_IncomingRequestPending  TMS_IncomingRequestPending
  #define TradeManagerStatus_Trading                 TMS_Trading
  #define TradeManagerStatus_Dueling                 TMS_Dueling
  #define TradeManagerStatus_ResolvingTrade          TMS_ResolvingTrade
  #define TradeManagerStatus_ResolvingDuelWon        TMS_ResolvingDuelWon
  #define TradeManagerStatus_ResolvingDuelLost       TMS_ResolvingDuelLost
  #define TradeManagerStatus_MAX                     TMS_MAX
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
  #define TMR_PlayerBusy                                    TMR_PlayerBusy
  #define TMR_PlayerOutOfRange                              TMR_PlayerOutOfRange
  #define TMR_PlayerRequestRefusedSelf                      TMR_PlayerRequestRefusedSelf
  #define TMR_PlayerRequestRefusedPartner                   TMR_PlayerRequestRefusedPartner
  #define TMR_PlayerRequestWithdrawnSelf                    TMR_PlayerRequestWithdrawnSelf
  #define TMR_PlayerRequestWithdrawnPartner                 TMR_PlayerRequestWithdrawnPartner
  #define TMR_RedundantRequest                              TMR_RedundantRequest
  #define TMR_TradingDisabled                               TMR_TradingDisabled
  #define TMR_CanceledBySelf                                TMR_CanceledBySelf
  #define TMR_CanceledByPartner                             TMR_CanceledByPartner
  #define TMR_TradeCompleteSuccessfully                     TMR_TradeCompleteSuccessfully
  #define TMR_DuelWon                                       TMR_DuelWon
  #define TMR_DuelLost                                      TMR_DuelLost
  #define TMR_DuelDraw                                      TMR_DuelDraw
  #define TMR_TradeCanceled                                 TMR_TradeCanceled
  #define TMR_MAX                                           TMR_MAX
  #define TradeManagerReason_PlayerBusy                     TMR_PlayerBusy
  #define TradeManagerReason_PlayerOutOfRange               TMR_PlayerOutOfRange
  #define TradeManagerReason_PlayerRequestRefusedSelf       TMR_PlayerRequestRefusedSelf
  #define TradeManagerReason_PlayerRequestRefusedPartner    TMR_PlayerRequestRefusedPartner
  #define TradeManagerReason_PlayerRequestWithdrawnSelf     TMR_PlayerRequestWithdrawnSelf
  #define TradeManagerReason_PlayerRequestWithdrawnPartner  TMR_PlayerRequestWithdrawnPartner
  #define TradeManagerReason_RedundantRequest               TMR_RedundantRequest
  #define TradeManagerReason_TradingDisabled                TMR_TradingDisabled
  #define TradeManagerReason_CanceledBySelf                 TMR_CanceledBySelf
  #define TradeManagerReason_CanceledByPartner              TMR_CanceledByPartner
  #define TradeManagerReason_TradeCompleteSuccessfully      TMR_TradeCompleteSuccessfully
  #define TradeManagerReason_DuelWon                        TMR_DuelWon
  #define TradeManagerReason_DuelLost                       TMR_DuelLost
  #define TradeManagerReason_DuelDraw                       TMR_DuelDraw
  #define TradeManagerReason_TradeCanceled                  TMR_TradeCanceled
  #define TradeManagerReason_MAX                            TMR_MAX
} TradeManagerReason;
typedef enum PlayerTradingStance : unsigned char {
  PTS_Deciding,                   // 0
  PTS_TradeReady,                 // 1
  PTS_DuelReady,                  // 2
  PTS_Disconnected,               // 3
  PTS_MAX                         // 4
  #define PTS_Deciding                      PTS_Deciding
  #define PTS_TradeReady                    PTS_TradeReady
  #define PTS_DuelReady                     PTS_DuelReady
  #define PTS_Disconnected                  PTS_Disconnected
  #define PTS_MAX                           PTS_MAX
  #define PlayerTradingStance_Deciding      PTS_Deciding
  #define PlayerTradingStance_TradeReady    PTS_TradeReady
  #define PlayerTradingStance_DuelReady     PTS_DuelReady
  #define PlayerTradingStance_Disconnected  PTS_Disconnected
  #define PlayerTradingStance_MAX           PTS_MAX
} PlayerTradingStance;
typedef enum TradeSlotStatus     : unsigned char {
  TSS_Empty,                      // 0
  TSS_Item,                       // 1
  TSS_Weapon,                     // 2
  TSS_MAX                         // 3
  #define TSS_Empty               TSS_Empty
  #define TSS_Item                TSS_Item
  #define TSS_Weapon              TSS_Weapon
  #define TSS_MAX                 TSS_MAX
  #define TradeSlotStatus_Empty   TSS_Empty
  #define TradeSlotStatus_Item    TSS_Item
  #define TradeSlotStatus_Weapon  TSS_Weapon
  #define TradeSlotStatus_MAX     TSS_MAX
} TradeSlotStatus;
#define TradeManagerStatus   TradeManagerStatus
#define TradeManagerReason   TradeManagerReason
#define PlayerTradingStance  PlayerTradingStance
#define TradeSlotStatus      TradeSlotStatus

/* ---------------------------------------------------------- USkelControlBase ! ---------------------------------------------------------- */

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
  #define BCS_WorldSpace                     BCS_WorldSpace
  #define BCS_ActorSpace                     BCS_ActorSpace
  #define BCS_ComponentSpace                 BCS_ComponentSpace
  #define BCS_ParentBoneSpace                BCS_ParentBoneSpace
  #define BCS_BoneSpace                      BCS_BoneSpace
  #define BCS_OtherBoneSpace                 BCS_OtherBoneSpace
  #define BCS_BaseMeshSpace                  BCS_BaseMeshSpace
  #define BCS_SocketSpace                    BCS_SocketSpace
  #define BCS_MAX                            BCS_MAX
  #define EBoneControlSpace_WorldSpace       BCS_WorldSpace
  #define EBoneControlSpace_ActorSpace       BCS_ActorSpace
  #define EBoneControlSpace_ComponentSpace   BCS_ComponentSpace
  #define EBoneControlSpace_ParentBoneSpace  BCS_ParentBoneSpace
  #define EBoneControlSpace_BoneSpace        BCS_BoneSpace
  #define EBoneControlSpace_OtherBoneSpace   BCS_OtherBoneSpace
  #define EBoneControlSpace_BaseMeshSpace    BCS_BaseMeshSpace
  #define EBoneControlSpace_SocketSpace      BCS_SocketSpace
  #define EBoneControlSpace_MAX              BCS_MAX
} EBoneControlSpace;
#define EBoneControlSpace  EBoneControlSpace

/* ---------------------------------------------------------- UGbxMessageDefinition ! ---------------------------------------------------------- */

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
  #define GBXMSGDUPE_SameSender                GBXMSGDUPE_SameSender
  #define GBXMSGDUPE_SameSubject               GBXMSGDUPE_SameSubject
  #define GBXMSGDUPE_SameNameData              GBXMSGDUPE_SameNameData
  #define GBXMSGDUPE_SameIntData               GBXMSGDUPE_SameIntData
  #define GBXMSGDUPE_SameFloatData             GBXMSGDUPE_SameFloatData
  #define GBXMSGDUPE_SameMetaData1             GBXMSGDUPE_SameMetaData1
  #define GBXMSGDUPE_SameMetaData2             GBXMSGDUPE_SameMetaData2
  #define GBXMSGDUPE_SameMetaData3             GBXMSGDUPE_SameMetaData3
  #define GBXMSGDUPE_SameMetaData4             GBXMSGDUPE_SameMetaData4
  #define GBXMSGDUPE_MAX                       GBXMSGDUPE_MAX
  #define EGbxMessageDupeStruct_SameSender     GBXMSGDUPE_SameSender
  #define EGbxMessageDupeStruct_SameSubject    GBXMSGDUPE_SameSubject
  #define EGbxMessageDupeStruct_SameNameData   GBXMSGDUPE_SameNameData
  #define EGbxMessageDupeStruct_SameIntData    GBXMSGDUPE_SameIntData
  #define EGbxMessageDupeStruct_SameFloatData  GBXMSGDUPE_SameFloatData
  #define EGbxMessageDupeStruct_SameMetaData1  GBXMSGDUPE_SameMetaData1
  #define EGbxMessageDupeStruct_SameMetaData2  GBXMSGDUPE_SameMetaData2
  #define EGbxMessageDupeStruct_SameMetaData3  GBXMSGDUPE_SameMetaData3
  #define EGbxMessageDupeStruct_SameMetaData4  GBXMSGDUPE_SameMetaData4
  #define EGbxMessageDupeStruct_MAX            GBXMSGDUPE_MAX
} EGbxMessageDupeStruct;
#define EGbxMessageDupeStruct  EGbxMessageDupeStruct
_DECL_TARRAY(EGbxMessageDupeStruct);

/* ---------------------------------------------------------- UShieldPartDefinition ! ---------------------------------------------------------- */

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
  #define SHIELD_PART_Body           SHIELD_PART_Body
  #define SHIELD_PART_Battery        SHIELD_PART_Battery
  #define SHIELD_PART_Capacitor      SHIELD_PART_Capacitor
  #define SHIELD_PART_Property1      SHIELD_PART_Property1
  #define SHIELD_PART_Property2      SHIELD_PART_Property2
  #define SHIELD_PART_Property3      SHIELD_PART_Property3
  #define SHIELD_PART_Property4      SHIELD_PART_Property4
  #define SHIELD_PART_Accessory      SHIELD_PART_Accessory
  #define SHIELD_PART_Material       SHIELD_PART_Material
  #define SHIELD_PART_Prefix         SHIELD_PART_Prefix
  #define SHIELD_PART_Title          SHIELD_PART_Title
  #define SHIELD_PART_MAX            SHIELD_PART_MAX
  #define EShieldPartType_Body       SHIELD_PART_Body
  #define EShieldPartType_Battery    SHIELD_PART_Battery
  #define EShieldPartType_Capacitor  SHIELD_PART_Capacitor
  #define EShieldPartType_Property1  SHIELD_PART_Property1
  #define EShieldPartType_Property2  SHIELD_PART_Property2
  #define EShieldPartType_Property3  SHIELD_PART_Property3
  #define EShieldPartType_Property4  SHIELD_PART_Property4
  #define EShieldPartType_Accessory  SHIELD_PART_Accessory
  #define EShieldPartType_Material   SHIELD_PART_Material
  #define EShieldPartType_Prefix     SHIELD_PART_Prefix
  #define EShieldPartType_Title      SHIELD_PART_Title
  #define EShieldPartType_MAX        SHIELD_PART_MAX
} EShieldPartType;
#define EShieldPartType  EShieldPartType

/* ---------------------------------------------------------- AWillowAIMoveNode ! ---------------------------------------------------------- */

typedef enum EVehicleNodeType : unsigned char {
  VEHNODE_Patrol,                 // 0
  VEHNODE_ScriptedPath,           // 1
  VEHNODE_MAX                     // 2
  #define VEHNODE_Patrol                 VEHNODE_Patrol
  #define VEHNODE_ScriptedPath           VEHNODE_ScriptedPath
  #define VEHNODE_MAX                    VEHNODE_MAX
  #define EVehicleNodeType_Patrol        VEHNODE_Patrol
  #define EVehicleNodeType_ScriptedPath  VEHNODE_ScriptedPath
  #define EVehicleNodeType_MAX           VEHNODE_MAX
} EVehicleNodeType;
#define EVehicleNodeType  EVehicleNodeType

/* ---------------------------------------------------------- APerch ! ---------------------------------------------------------- */

typedef enum EPerchAnimType : unsigned char {
  PAT_Start,                      // 0
  PAT_Idle,                       // 1
  PAT_Stop,                       // 2
  PAT_MAX                         // 3
  #define PAT_Start             PAT_Start
  #define PAT_Idle              PAT_Idle
  #define PAT_Stop              PAT_Stop
  #define PAT_MAX               PAT_MAX
  #define EPerchAnimType_Start  PAT_Start
  #define EPerchAnimType_Idle   PAT_Idle
  #define EPerchAnimType_Stop   PAT_Stop
  #define EPerchAnimType_MAX    PAT_MAX
} EPerchAnimType;
#define EPerchAnimType  EPerchAnimType

/* ---------------------------------------------------------- ULockoutDefinition ! ---------------------------------------------------------- */

typedef enum ELockoutStyle : unsigned char {
  LOCKOUT_Relative,               // 0
  LOCKOUT_NextDay,                // 1
  LOCKOUT_NextWeek,               // 2
  LOCKOUT_MAX                     // 3
  #define LOCKOUT_Relative        LOCKOUT_Relative
  #define LOCKOUT_NextDay         LOCKOUT_NextDay
  #define LOCKOUT_NextWeek        LOCKOUT_NextWeek
  #define LOCKOUT_MAX             LOCKOUT_MAX
  #define ELockoutStyle_Relative  LOCKOUT_Relative
  #define ELockoutStyle_NextDay   LOCKOUT_NextDay
  #define ELockoutStyle_NextWeek  LOCKOUT_NextWeek
  #define ELockoutStyle_MAX       LOCKOUT_MAX
} ELockoutStyle;
#define ELockoutStyle  ELockoutStyle

/* ---------------------------------------------------------- UBehavior_CauseDamage ! ---------------------------------------------------------- */

typedef enum EDamageTarget : unsigned char {
  DT_BehaviorContext,             // 0
  DT_OtherEventParticipant,       // 1
  DT_CustomTarget,                // 2
  DT_RadiusAroundContext,         // 3
  DT_MAX                          // 4
  #define DT_BehaviorContext                   DT_BehaviorContext
  #define DT_OtherEventParticipant             DT_OtherEventParticipant
  #define DT_CustomTarget                      DT_CustomTarget
  #define DT_RadiusAroundContext               DT_RadiusAroundContext
  #define DT_MAX                               DT_MAX
  #define EDamageTarget_BehaviorContext        DT_BehaviorContext
  #define EDamageTarget_OtherEventParticipant  DT_OtherEventParticipant
  #define EDamageTarget_CustomTarget           DT_CustomTarget
  #define EDamageTarget_RadiusAroundContext    DT_RadiusAroundContext
  #define EDamageTarget_MAX                    DT_MAX
} EDamageTarget;
#define EDamageTarget  EDamageTarget

/* ---------------------------------------------------------- UPopulationMaster ! ---------------------------------------------------------- */

typedef enum EPopulationStats : unsigned char {
  STATTYPE_SpawnActor,            // 0
  STATTYPE_PointSearch,           // 1
  STATTYPE_MAX                    // 2
  #define STATTYPE_SpawnActor           STATTYPE_SpawnActor
  #define STATTYPE_PointSearch          STATTYPE_PointSearch
  #define STATTYPE_MAX                  STATTYPE_MAX
  #define EPopulationStats_SpawnActor   STATTYPE_SpawnActor
  #define EPopulationStats_PointSearch  STATTYPE_PointSearch
  #define EPopulationStats_MAX          STATTYPE_MAX
} EPopulationStats;
#define EPopulationStats  EPopulationStats

/* ---------------------------------------------------------- APopulationEncounter ! ---------------------------------------------------------- */

typedef enum EEncounterConstraintType : unsigned char {
  ENCOUNTERCONSTAINT_All,         // 0
  ENCOUNTERCONSTAINT_Any,         // 1
  ENCOUNTERCONSTAINT_NotAll,      // 2
  ENCOUNTERCONSTAINT_NotAny,      // 3
  ENCOUNTERCONSTAINT_MAX          // 4
  #define ENCOUNTERCONSTAINT_All           ENCOUNTERCONSTAINT_All
  #define ENCOUNTERCONSTAINT_Any           ENCOUNTERCONSTAINT_Any
  #define ENCOUNTERCONSTAINT_NotAll        ENCOUNTERCONSTAINT_NotAll
  #define ENCOUNTERCONSTAINT_NotAny        ENCOUNTERCONSTAINT_NotAny
  #define ENCOUNTERCONSTAINT_MAX           ENCOUNTERCONSTAINT_MAX
  #define EEncounterConstraintType_All     ENCOUNTERCONSTAINT_All
  #define EEncounterConstraintType_Any     ENCOUNTERCONSTAINT_Any
  #define EEncounterConstraintType_NotAll  ENCOUNTERCONSTAINT_NotAll
  #define EEncounterConstraintType_NotAny  ENCOUNTERCONSTAINT_NotAny
  #define EEncounterConstraintType_MAX     ENCOUNTERCONSTAINT_MAX
} EEncounterConstraintType;
#define EEncounterConstraintType  EEncounterConstraintType

/* ---------------------------------------------------------- UDesignerAttributeDefinition ! ---------------------------------------------------------- */

typedef enum EDesignerAtttributeScope : unsigned char {
  DASCOPE_Global,                 // 0
  DASCOPE_Local,                  // 1
  DASCOPE_MAX                     // 2
  #define DASCOPE_Global                   DASCOPE_Global
  #define DASCOPE_Local                    DASCOPE_Local
  #define DASCOPE_MAX                      DASCOPE_MAX
  #define EDesignerAtttributeScope_Global  DASCOPE_Global
  #define EDesignerAtttributeScope_Local   DASCOPE_Local
  #define EDesignerAtttributeScope_MAX     DASCOPE_MAX
} EDesignerAtttributeScope;
#define EDesignerAtttributeScope  EDesignerAtttributeScope

/* ---------------------------------------------------------- UWillowVersusDuelGlobals ! ---------------------------------------------------------- */

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
  #define DMSG_DUELINGDISABLED        DMSG_DUELINGDISABLED
  #define DMSG_ALREADYDUELING         DMSG_ALREADYDUELING
  #define DMSG_ALREADYCHALLENGED      DMSG_ALREADYCHALLENGED
  #define DMSG_DUELTIMEOUT            DMSG_DUELTIMEOUT
  #define DMSG_ISSUEDCHALLENGE        DMSG_ISSUEDCHALLENGE
  #define DMSG_RECEIVEDCHALLENGE      DMSG_RECEIVEDCHALLENGE
  #define DMSG_ACCEPTEDCHALLENGE      DMSG_ACCEPTEDCHALLENGE
  #define DMSG_DUELSTART              DMSG_DUELSTART
  #define DMSG_ARENAWARNING           DMSG_ARENAWARNING
  #define DMSG_DUELDRAW               DMSG_DUELDRAW
  #define DMSG_DUELWIN                DMSG_DUELWIN
  #define DMSG_NOTRIGHTNOW            DMSG_NOTRIGHTNOW
  #define DMSG_MAX                    DMSG_MAX
  #define EDuelMsg_DUELINGDISABLED    DMSG_DUELINGDISABLED
  #define EDuelMsg_ALREADYDUELING     DMSG_ALREADYDUELING
  #define EDuelMsg_ALREADYCHALLENGED  DMSG_ALREADYCHALLENGED
  #define EDuelMsg_DUELTIMEOUT        DMSG_DUELTIMEOUT
  #define EDuelMsg_ISSUEDCHALLENGE    DMSG_ISSUEDCHALLENGE
  #define EDuelMsg_RECEIVEDCHALLENGE  DMSG_RECEIVEDCHALLENGE
  #define EDuelMsg_ACCEPTEDCHALLENGE  DMSG_ACCEPTEDCHALLENGE
  #define EDuelMsg_DUELSTART          DMSG_DUELSTART
  #define EDuelMsg_ARENAWARNING       DMSG_ARENAWARNING
  #define EDuelMsg_DUELDRAW           DMSG_DUELDRAW
  #define EDuelMsg_DUELWIN            DMSG_DUELWIN
  #define EDuelMsg_NOTRIGHTNOW        DMSG_NOTRIGHTNOW
  #define EDuelMsg_MAX                DMSG_MAX
} EDuelMsg;
#define EDuelMsg  EDuelMsg

/* ---------------------------------------------------------- UGameStateObject ! ---------------------------------------------------------- */

typedef enum GameSessionType : unsigned char {
  GT_SessionInvalid,              // 0
  GT_SinglePlayer,                // 1
  GT_Coop,                        // 2
  GT_Multiplayer,                 // 3
  GT_MAX                          // 4
  #define GT_SessionInvalid               GT_SessionInvalid
  #define GT_SinglePlayer                 GT_SinglePlayer
  #define GT_Coop                         GT_Coop
  #define GT_Multiplayer                  GT_Multiplayer
  #define GT_MAX                          GT_MAX
  #define GameSessionType_SessionInvalid  GT_SessionInvalid
  #define GameSessionType_SinglePlayer    GT_SinglePlayer
  #define GameSessionType_Coop            GT_Coop
  #define GameSessionType_Multiplayer     GT_Multiplayer
  #define GameSessionType_MAX             GT_MAX
} GameSessionType;
#define GameSessionType  GameSessionType

/* ---------------------------------------------------------- UMeshBeacon ! ---------------------------------------------------------- */

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
  #define MB_Packet_UnknownType                                 MB_Packet_UnknownType
  #define MB_Packet_ClientNewConnectionRequest                  MB_Packet_ClientNewConnectionRequest
  #define MB_Packet_ClientBeginBandwidthTest                    MB_Packet_ClientBeginBandwidthTest
  #define MB_Packet_ClientCreateNewSessionResponse              MB_Packet_ClientCreateNewSessionResponse
  #define MB_Packet_HostNewConnectionResponse                   MB_Packet_HostNewConnectionResponse
  #define MB_Packet_HostBandwidthTestRequest                    MB_Packet_HostBandwidthTestRequest
  #define MB_Packet_HostCompletedBandwidthTest                  MB_Packet_HostCompletedBandwidthTest
  #define MB_Packet_HostTravelRequest                           MB_Packet_HostTravelRequest
  #define MB_Packet_HostCreateNewSessionRequest                 MB_Packet_HostCreateNewSessionRequest
  #define MB_Packet_DummyData                                   MB_Packet_DummyData
  #define MB_Packet_Heartbeat                                   MB_Packet_Heartbeat
  #define MB_Packet_MAX                                         MB_Packet_MAX
  #define EMeshBeaconPacketType_UnknownType                     MB_Packet_UnknownType
  #define EMeshBeaconPacketType_ClientNewConnectionRequest      MB_Packet_ClientNewConnectionRequest
  #define EMeshBeaconPacketType_ClientBeginBandwidthTest        MB_Packet_ClientBeginBandwidthTest
  #define EMeshBeaconPacketType_ClientCreateNewSessionResponse  MB_Packet_ClientCreateNewSessionResponse
  #define EMeshBeaconPacketType_HostNewConnectionResponse       MB_Packet_HostNewConnectionResponse
  #define EMeshBeaconPacketType_HostBandwidthTestRequest        MB_Packet_HostBandwidthTestRequest
  #define EMeshBeaconPacketType_HostCompletedBandwidthTest      MB_Packet_HostCompletedBandwidthTest
  #define EMeshBeaconPacketType_HostTravelRequest               MB_Packet_HostTravelRequest
  #define EMeshBeaconPacketType_HostCreateNewSessionRequest     MB_Packet_HostCreateNewSessionRequest
  #define EMeshBeaconPacketType_DummyData                       MB_Packet_DummyData
  #define EMeshBeaconPacketType_Heartbeat                       MB_Packet_Heartbeat
  #define EMeshBeaconPacketType_MAX                             MB_Packet_MAX
} EMeshBeaconPacketType;
typedef enum EMeshBeaconConnectionResult    : unsigned char {
  MB_ConnectionResult_Succeeded,  // 0
  MB_ConnectionResult_Duplicate,  // 1
  MB_ConnectionResult_Timeout,    // 2
  MB_ConnectionResult_Error,      // 3
  MB_ConnectionResult_MAX         // 4
  #define MB_ConnectionResult_Succeeded          MB_ConnectionResult_Succeeded
  #define MB_ConnectionResult_Duplicate          MB_ConnectionResult_Duplicate
  #define MB_ConnectionResult_Timeout            MB_ConnectionResult_Timeout
  #define MB_ConnectionResult_Error              MB_ConnectionResult_Error
  #define MB_ConnectionResult_MAX                MB_ConnectionResult_MAX
  #define EMeshBeaconConnectionResult_Succeeded  MB_ConnectionResult_Succeeded
  #define EMeshBeaconConnectionResult_Duplicate  MB_ConnectionResult_Duplicate
  #define EMeshBeaconConnectionResult_Timeout    MB_ConnectionResult_Timeout
  #define EMeshBeaconConnectionResult_Error      MB_ConnectionResult_Error
  #define EMeshBeaconConnectionResult_MAX        MB_ConnectionResult_MAX
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
  #define MB_BandwidthTestState_NotStarted              MB_BandwidthTestState_NotStarted
  #define MB_BandwidthTestState_RequestPending          MB_BandwidthTestState_RequestPending
  #define MB_BandwidthTestState_StartPending            MB_BandwidthTestState_StartPending
  #define MB_BandwidthTestState_InProgress              MB_BandwidthTestState_InProgress
  #define MB_BandwidthTestState_Completed               MB_BandwidthTestState_Completed
  #define MB_BandwidthTestState_Incomplete              MB_BandwidthTestState_Incomplete
  #define MB_BandwidthTestState_Timeout                 MB_BandwidthTestState_Timeout
  #define MB_BandwidthTestState_Error                   MB_BandwidthTestState_Error
  #define MB_BandwidthTestState_MAX                     MB_BandwidthTestState_MAX
  #define EMeshBeaconBandwidthTestState_NotStarted      MB_BandwidthTestState_NotStarted
  #define EMeshBeaconBandwidthTestState_RequestPending  MB_BandwidthTestState_RequestPending
  #define EMeshBeaconBandwidthTestState_StartPending    MB_BandwidthTestState_StartPending
  #define EMeshBeaconBandwidthTestState_InProgress      MB_BandwidthTestState_InProgress
  #define EMeshBeaconBandwidthTestState_Completed       MB_BandwidthTestState_Completed
  #define EMeshBeaconBandwidthTestState_Incomplete      MB_BandwidthTestState_Incomplete
  #define EMeshBeaconBandwidthTestState_Timeout         MB_BandwidthTestState_Timeout
  #define EMeshBeaconBandwidthTestState_Error           MB_BandwidthTestState_Error
  #define EMeshBeaconBandwidthTestState_MAX             MB_BandwidthTestState_MAX
} EMeshBeaconBandwidthTestState;
typedef enum EMeshBeaconBandwidthTestResult : unsigned char {
  MB_BandwidthTestResult_Succeeded,// 0
  MB_BandwidthTestResult_Timeout, // 1
  MB_BandwidthTestResult_Error,   // 2
  MB_BandwidthTestResult_MAX      // 3
  #define MB_BandwidthTestResult_Succeeded          MB_BandwidthTestResult_Succeeded
  #define MB_BandwidthTestResult_Timeout            MB_BandwidthTestResult_Timeout
  #define MB_BandwidthTestResult_Error              MB_BandwidthTestResult_Error
  #define MB_BandwidthTestResult_MAX                MB_BandwidthTestResult_MAX
  #define EMeshBeaconBandwidthTestResult_Succeeded  MB_BandwidthTestResult_Succeeded
  #define EMeshBeaconBandwidthTestResult_Timeout    MB_BandwidthTestResult_Timeout
  #define EMeshBeaconBandwidthTestResult_Error      MB_BandwidthTestResult_Error
  #define EMeshBeaconBandwidthTestResult_MAX        MB_BandwidthTestResult_MAX
} EMeshBeaconBandwidthTestResult;
typedef enum EMeshBeaconBandwidthTestType   : unsigned char {
  MB_BandwidthTestType_Upstream,  // 0
  MB_BandwidthTestType_Downstream,// 1
  MB_BandwidthTestType_RoundtripLatency,// 2
  MB_BandwidthTestType_MAX        // 3
  #define MB_BandwidthTestType_Upstream                  MB_BandwidthTestType_Upstream
  #define MB_BandwidthTestType_Downstream                MB_BandwidthTestType_Downstream
  #define MB_BandwidthTestType_RoundtripLatency          MB_BandwidthTestType_RoundtripLatency
  #define MB_BandwidthTestType_MAX                       MB_BandwidthTestType_MAX
  #define EMeshBeaconBandwidthTestType_Upstream          MB_BandwidthTestType_Upstream
  #define EMeshBeaconBandwidthTestType_Downstream        MB_BandwidthTestType_Downstream
  #define EMeshBeaconBandwidthTestType_RoundtripLatency  MB_BandwidthTestType_RoundtripLatency
  #define EMeshBeaconBandwidthTestType_MAX               MB_BandwidthTestType_MAX
} EMeshBeaconBandwidthTestType;
#define EMeshBeaconPacketType           EMeshBeaconPacketType
#define EMeshBeaconConnectionResult     EMeshBeaconConnectionResult
#define EMeshBeaconBandwidthTestState   EMeshBeaconBandwidthTestState
#define EMeshBeaconBandwidthTestResult  EMeshBeaconBandwidthTestResult
#define EMeshBeaconBandwidthTestType    EMeshBeaconBandwidthTestType

/* ---------------------------------------------------------- UMeshBeaconClient ! ---------------------------------------------------------- */

typedef enum EMeshBeaconClientState : unsigned char {
  MBCS_None,                      // 0
  MBCS_Connecting,                // 1
  MBCS_Connected,                 // 2
  MBCS_ConnectionFailed,          // 3
  MBCS_AwaitingResponse,          // 4
  MBCS_Closed,                    // 5
  MBCS_MAX                        // 6
  #define MBCS_None                                MBCS_None
  #define MBCS_Connecting                          MBCS_Connecting
  #define MBCS_Connected                           MBCS_Connected
  #define MBCS_ConnectionFailed                    MBCS_ConnectionFailed
  #define MBCS_AwaitingResponse                    MBCS_AwaitingResponse
  #define MBCS_Closed                              MBCS_Closed
  #define MBCS_MAX                                 MBCS_MAX
  #define EMeshBeaconClientState_None              MBCS_None
  #define EMeshBeaconClientState_Connecting        MBCS_Connecting
  #define EMeshBeaconClientState_Connected         MBCS_Connected
  #define EMeshBeaconClientState_ConnectionFailed  MBCS_ConnectionFailed
  #define EMeshBeaconClientState_AwaitingResponse  MBCS_AwaitingResponse
  #define EMeshBeaconClientState_Closed            MBCS_Closed
  #define EMeshBeaconClientState_MAX               MBCS_MAX
} EMeshBeaconClientState;
#define EMeshBeaconClientState  EMeshBeaconClientState

/* ---------------------------------------------------------- ARoute ! ---------------------------------------------------------- */

typedef enum ERouteFillAction : unsigned char {
  RFA_Overwrite,                  // 0
  RFA_Add,                        // 1
  RFA_Remove,                     // 2
  RFA_Clear,                      // 3
  RFA_MAX                         // 4
  #define RFA_Overwrite               RFA_Overwrite
  #define RFA_Add                     RFA_Add
  #define RFA_Remove                  RFA_Remove
  #define RFA_Clear                   RFA_Clear
  #define RFA_MAX                     RFA_MAX
  #define ERouteFillAction_Overwrite  RFA_Overwrite
  #define ERouteFillAction_Add        RFA_Add
  #define ERouteFillAction_Remove     RFA_Remove
  #define ERouteFillAction_Clear      RFA_Clear
  #define ERouteFillAction_MAX        RFA_MAX
} ERouteFillAction;
typedef enum ERouteDirection  : unsigned char {
  ERD_Forward,                    // 0
  ERD_Reverse,                    // 1
  ERD_MAX                         // 2
  #define ERD_Forward              ERD_Forward
  #define ERD_Reverse              ERD_Reverse
  #define ERD_MAX                  ERD_MAX
  #define ERouteDirection_Forward  ERD_Forward
  #define ERouteDirection_Reverse  ERD_Reverse
  #define ERouteDirection_MAX      ERD_MAX
} ERouteDirection;
typedef enum ERouteType       : unsigned char {
  ERT_Linear,                     // 0
  ERT_Loop,                       // 1
  ERT_Circle,                     // 2
  ERT_MAX                         // 3
  #define ERT_Linear         ERT_Linear
  #define ERT_Loop           ERT_Loop
  #define ERT_Circle         ERT_Circle
  #define ERT_MAX            ERT_MAX
  #define ERouteType_Linear  ERT_Linear
  #define ERouteType_Loop    ERT_Loop
  #define ERouteType_Circle  ERT_Circle
  #define ERouteType_MAX     ERT_MAX
} ERouteType;
#define ERouteFillAction  ERouteFillAction
#define ERouteDirection   ERouteDirection
#define ERouteType        ERouteType

/* ---------------------------------------------------------- UOnlineSubsystemSteamworks ! ---------------------------------------------------------- */

typedef enum ELeaderboardRequestType : unsigned char {
  LRT_Global,                     // 0
  LRT_Player,                     // 1
  LRT_Friends,                    // 2
  LRT_MAX                         // 3
  #define LRT_Global                       LRT_Global
  #define LRT_Player                       LRT_Player
  #define LRT_Friends                      LRT_Friends
  #define LRT_MAX                          LRT_MAX
  #define ELeaderboardRequestType_Global   LRT_Global
  #define ELeaderboardRequestType_Player   LRT_Player
  #define ELeaderboardRequestType_Friends  LRT_Friends
  #define ELeaderboardRequestType_MAX      LRT_MAX
} ELeaderboardRequestType;
typedef enum ELeaderboardSortType    : unsigned char {
  LST_Ascending,                  // 0
  LST_Descending,                 // 1
  LST_MAX                         // 2
  #define LST_Ascending                    LST_Ascending
  #define LST_Descending                   LST_Descending
  #define LST_MAX                          LST_MAX
  #define ELeaderboardSortType_Ascending   LST_Ascending
  #define ELeaderboardSortType_Descending  LST_Descending
  #define ELeaderboardSortType_MAX         LST_MAX
} ELeaderboardSortType;
typedef enum ELeaderboardFormat      : unsigned char {
  LF_Number,                      // 0
  LF_Seconds,                     // 1
  LF_Milliseconds,                // 2
  LF_MAX                          // 3
  #define LF_Number                        LF_Number
  #define LF_Seconds                       LF_Seconds
  #define LF_Milliseconds                  LF_Milliseconds
  #define LF_MAX                           LF_MAX
  #define ELeaderboardFormat_Number        LF_Number
  #define ELeaderboardFormat_Seconds       LF_Seconds
  #define ELeaderboardFormat_Milliseconds  LF_Milliseconds
  #define ELeaderboardFormat_MAX           LF_MAX
} ELeaderboardFormat;
typedef enum ELeaderboardUpdateType  : unsigned char {
  LUT_KeepBest,                   // 0
  LUT_Force,                      // 1
  LUT_MAX                         // 2
  #define LUT_KeepBest                     LUT_KeepBest
  #define LUT_Force                        LUT_Force
  #define LUT_MAX                          LUT_MAX
  #define ELeaderboardUpdateType_KeepBest  LUT_KeepBest
  #define ELeaderboardUpdateType_Force     LUT_Force
  #define ELeaderboardUpdateType_MAX       LUT_MAX
} ELeaderboardUpdateType;
#define ELeaderboardRequestType  ELeaderboardRequestType
#define ELeaderboardSortType     ELeaderboardSortType
#define ELeaderboardFormat       ELeaderboardFormat
#define ELeaderboardUpdateType   ELeaderboardUpdateType

/* ---------------------------------------------------------- USparkTypes ! ---------------------------------------------------------- */

typedef enum EInitializedResult         : unsigned char {
  INITIALIZED_ValidWithAccount,   // 0
  INITIALIZED_ValidNoAccount,     // 1
  INITIALIZED_InProgress,         // 2
  INITIALIZED_NetworkFailure,     // 3
  INITIALIZED_PlatformFailure,    // 4
  INITIALIZED_NotValid,           // 5
  INITIALIZED_MAX                 // 6
  #define INITIALIZED_ValidWithAccount                                             INITIALIZED_ValidWithAccount
  #define INITIALIZED_ValidNoAccount                                             INITIALIZED_ValidNoAccount
  #define INITIALIZED_InProgress                                             INITIALIZED_InProgress
  #define INITIALIZED_NetworkFailure                                             INITIALIZED_NetworkFailure
  #define INITIALIZED_PlatformFailure                                            INITIALIZED_PlatformFailure
  #define INITIALIZED_NotValid                                             INITIALIZED_NotValid
  #define INITIALIZED_MAX                                            INITIALIZED_MAX
  #define EInitializedResult_ValidWithAccount                                            INITIALIZED_ValidWithAccount
  #define EInitializedResult_ValidNoAccount                                            INITIALIZED_ValidNoAccount
  #define EInitializedResult_InProgress                                            INITIALIZED_InProgress
  #define EInitializedResult_NetworkFailure                                            INITIALIZED_NetworkFailure
  #define EInitializedResult_PlatformFailure                                             INITIALIZED_PlatformFailure
  #define EInitializedResult_NotValid                                            INITIALIZED_NotValid
  #define EInitializedResult_MAX                                             INITIALIZED_MAX
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
  #define SPARKINIT_Uninitialized                           SPARKINIT_Uninitialized
  #define SPARKINIT_TMSDownloaded                           SPARKINIT_TMSDownloaded
  #define SPARKINIT_PendingAuthentication                   SPARKINIT_PendingAuthentication
  #define SPARKINIT_PendingVerification                     SPARKINIT_PendingVerification
  #define SPARKINIT_VerificationComplete                    SPARKINIT_VerificationComplete
  #define SPARKINIT_Initialized                             SPARKINIT_Initialized
  #define SPARKINIT_Disabled                                SPARKINIT_Disabled
  #define SPARKINIT_UnrecoverableError                      SPARKINIT_UnrecoverableError
  #define SPARKINIT_MAX                                     SPARKINIT_MAX
  #define ESparkInitializationStatus_Uninitialized          SPARKINIT_Uninitialized
  #define ESparkInitializationStatus_TMSDownloaded          SPARKINIT_TMSDownloaded
  #define ESparkInitializationStatus_PendingAuthentication  SPARKINIT_PendingAuthentication
  #define ESparkInitializationStatus_PendingVerification    SPARKINIT_PendingVerification
  #define ESparkInitializationStatus_VerificationComplete   SPARKINIT_VerificationComplete
  #define ESparkInitializationStatus_Initialized            SPARKINIT_Initialized
  #define ESparkInitializationStatus_Disabled               SPARKINIT_Disabled
  #define ESparkInitializationStatus_UnrecoverableError     SPARKINIT_UnrecoverableError
  #define ESparkInitializationStatus_MAX                    SPARKINIT_MAX
} ESparkInitializationStatus;
typedef enum ESparkStepResult           : unsigned char {
  STEP_Success,                   // 0
  STEP_Fail,                      // 1
  STEP_Async,                     // 2
  STEP_Disable,                   // 3
  STEP_Final,                     // 4
  STEP_MAX                        // 5
  #define STEP_Success              STEP_Success
  #define STEP_Fail                 STEP_Fail
  #define STEP_Async                STEP_Async
  #define STEP_Disable              STEP_Disable
  #define STEP_Final                STEP_Final
  #define STEP_MAX                  STEP_MAX
  #define ESparkStepResult_Success  STEP_Success
  #define ESparkStepResult_Fail     STEP_Fail
  #define ESparkStepResult_Async    STEP_Async
  #define ESparkStepResult_Disable  STEP_Disable
  #define ESparkStepResult_Final    STEP_Final
  #define ESparkStepResult_MAX      STEP_MAX
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
  #define HE_Success                    HE_Success
  #define HE_UnknownFailure             HE_UnknownFailure
  #define HE_Timeout                    HE_Timeout
  #define HE_BadUrl                     HE_BadUrl
  #define HE_Connect                    HE_Connect
  #define HE_SendRequest                HE_SendRequest
  #define HE_ReceiveResponse            HE_ReceiveResponse
  #define HE_ReadResponse               HE_ReadResponse
  #define HE_WriteData                  HE_WriteData
  #define HE_HttpStatus                 HE_HttpStatus
  #define HE_ServerCertificate          HE_ServerCertificate
  #define HE_MAX                        HE_MAX
  #define EHttpError_Success            HE_Success
  #define EHttpError_UnknownFailure     HE_UnknownFailure
  #define EHttpError_Timeout            HE_Timeout
  #define EHttpError_BadUrl             HE_BadUrl
  #define EHttpError_Connect            HE_Connect
  #define EHttpError_SendRequest        HE_SendRequest
  #define EHttpError_ReceiveResponse    HE_ReceiveResponse
  #define EHttpError_ReadResponse       HE_ReadResponse
  #define EHttpError_WriteData          HE_WriteData
  #define EHttpError_HttpStatus         HE_HttpStatus
  #define EHttpError_ServerCertificate  HE_ServerCertificate
  #define EHttpError_MAX                HE_MAX
} EHttpError;
typedef enum EAgreementsSigning         : unsigned char {
  AGREEMENTS_Undefined,           // 0
  AGREEMENTS_NoAgreementsToSign,  // 1
  AGREEMENTS_AgreementsToSignPending,// 2
  AGREEMENTS_AgreementsToSignDeclined,// 3
  AGREEMENTS_MAX                  // 4
  #define AGREEMENTS_Undefined                         AGREEMENTS_Undefined
  #define AGREEMENTS_NoAgreementsToSign                AGREEMENTS_NoAgreementsToSign
  #define AGREEMENTS_AgreementsToSignPending           AGREEMENTS_AgreementsToSignPending
  #define AGREEMENTS_AgreementsToSignDeclined          AGREEMENTS_AgreementsToSignDeclined
  #define AGREEMENTS_MAX                               AGREEMENTS_MAX
  #define EAgreementsSigning_Undefined                 AGREEMENTS_Undefined
  #define EAgreementsSigning_NoAgreementsToSign        AGREEMENTS_NoAgreementsToSign
  #define EAgreementsSigning_AgreementsToSignPending   AGREEMENTS_AgreementsToSignPending
  #define EAgreementsSigning_AgreementsToSignDeclined  AGREEMENTS_AgreementsToSignDeclined
  #define EAgreementsSigning_MAX                       AGREEMENTS_MAX
} EAgreementsSigning;
#define EInitializedResult          EInitializedResult
#define ESparkInitializationStatus  ESparkInitializationStatus
#define ESparkStepResult            ESparkStepResult
#define EHttpError                  EHttpError
#define EAgreementsSigning          EAgreementsSigning

/* ---------------------------------------------------------- UAIPawnBalanceDefinition ! ---------------------------------------------------------- */

typedef enum EAITransformed       : unsigned char {
  EAIT_None,                      // 0
  EAIT_Fire,                      // 1
  EAIT_Shock,                     // 2
  EAIT_Corrosive,                 // 3
  EAIT_Custom,                    // 4
  EAIT_Slagged,                   // 5
  EAIT_MAX                        // 6
  #define EAIT_None                 EAIT_None
  #define EAIT_Fire                 EAIT_Fire
  #define EAIT_Shock                EAIT_Shock
  #define EAIT_Corrosive            EAIT_Corrosive
  #define EAIT_Custom               EAIT_Custom
  #define EAIT_Slagged              EAIT_Slagged
  #define EAIT_MAX                  EAIT_MAX
  #define EAITransformed_None       EAIT_None
  #define EAITransformed_Fire       EAIT_Fire
  #define EAITransformed_Shock      EAIT_Shock
  #define EAITransformed_Corrosive  EAIT_Corrosive
  #define EAITransformed_Custom     EAIT_Custom
  #define EAITransformed_Slagged    EAIT_Slagged
  #define EAITransformed_MAX        EAIT_MAX
} EAITransformed;
typedef enum EItemGameStageSource : unsigned char {
  IGSS_ExpLevelOfBalancedActor,   // 0
  IGSS_GameStageOfBalancedActor,  // 1
  IGSS_MAX                        // 2
  #define IGSS_ExpLevelOfBalancedActor                   IGSS_ExpLevelOfBalancedActor
  #define IGSS_GameStageOfBalancedActor                  IGSS_GameStageOfBalancedActor
  #define IGSS_MAX                                       IGSS_MAX
  #define EItemGameStageSource_ExpLevelOfBalancedActor   IGSS_ExpLevelOfBalancedActor
  #define EItemGameStageSource_GameStageOfBalancedActor  IGSS_GameStageOfBalancedActor
  #define EItemGameStageSource_MAX                       IGSS_MAX
} EItemGameStageSource;
#define EAITransformed        EAITransformed
#define EItemGameStageSource  EItemGameStageSource

/* ---------------------------------------------------------- APopulationPoint ! ---------------------------------------------------------- */

typedef enum EPopulationPointType   : unsigned char {
  POINT_Ambush,                   // 0
  POINT_PointOfInterest,          // 1
  POINT_Vehicle,                  // 2
  POINT_MAX                       // 3
  #define POINT_Ambush                          POINT_Ambush
  #define POINT_PointOfInterest                 POINT_PointOfInterest
  #define POINT_Vehicle                         POINT_Vehicle
  #define POINT_MAX                             POINT_MAX
  #define EPopulationPointType_Ambush           POINT_Ambush
  #define EPopulationPointType_PointOfInterest  POINT_PointOfInterest
  #define EPopulationPointType_Vehicle          POINT_Vehicle
  #define EPopulationPointType_MAX              POINT_MAX
} EPopulationPointType;
typedef enum EPopPointContraintType : unsigned char {
  POPOINTCONSTRAINT_None,         // 0
  POPOINTCONSTRAINT_Inclusion,    // 1
  POPOINTCONSTRAINT_Exclusion,    // 2
  POPOINTCONSTRAINT_InclusionOr,  // 3
  POPOINTCONSTRAINT_ExclusionOr,  // 4
  POPOINTCONSTRAINT_MAX           // 5
  #define POPOINTCONSTRAINT_None              POPOINTCONSTRAINT_None
  #define POPOINTCONSTRAINT_Inclusion         POPOINTCONSTRAINT_Inclusion
  #define POPOINTCONSTRAINT_Exclusion         POPOINTCONSTRAINT_Exclusion
  #define POPOINTCONSTRAINT_InclusionOr       POPOINTCONSTRAINT_InclusionOr
  #define POPOINTCONSTRAINT_ExclusionOr       POPOINTCONSTRAINT_ExclusionOr
  #define POPOINTCONSTRAINT_MAX               POPOINTCONSTRAINT_MAX
  #define EPopPointContraintType_None         POPOINTCONSTRAINT_None
  #define EPopPointContraintType_Inclusion    POPOINTCONSTRAINT_Inclusion
  #define EPopPointContraintType_Exclusion    POPOINTCONSTRAINT_Exclusion
  #define EPopPointContraintType_InclusionOr  POPOINTCONSTRAINT_InclusionOr
  #define EPopPointContraintType_ExclusionOr  POPOINTCONSTRAINT_ExclusionOr
  #define EPopPointContraintType_MAX          POPOINTCONSTRAINT_MAX
} EPopPointContraintType;
#define EPopulationPointType    EPopulationPointType 
#define EPopPointContraintType  EPopPointContraintType 

/* ---------------------------------------------------------- USoundNodeWave ! ---------------------------------------------------------- */

typedef enum EDecompressionType : unsigned char {
  DTYPE_Setup,                    // 0
  DTYPE_Invalid,                  // 1
  DTYPE_Preview,                  // 2
  DTYPE_Native,                   // 3
  DTYPE_RealTime,                 // 4
  DTYPE_Procedural,               // 5
  DTYPE_Xenon,                    // 6
  DTYPE_MAX                       // 7
  #define DTYPE_Setup                    DTYPE_Setup
  #define DTYPE_Invalid                  DTYPE_Invalid
  #define DTYPE_Preview                  DTYPE_Preview
  #define DTYPE_Native                   DTYPE_Native
  #define DTYPE_RealTime                 DTYPE_RealTime
  #define DTYPE_Procedural               DTYPE_Procedural
  #define DTYPE_Xenon                    DTYPE_Xenon
  #define DTYPE_MAX                      DTYPE_MAX
  #define EDecompressionType_Setup       DTYPE_Setup
  #define EDecompressionType_Invalid     DTYPE_Invalid
  #define EDecompressionType_Preview     DTYPE_Preview
  #define EDecompressionType_Native      DTYPE_Native
  #define EDecompressionType_RealTime    DTYPE_RealTime
  #define EDecompressionType_Procedural  DTYPE_Procedural
  #define EDecompressionType_Xenon       DTYPE_Xenon
  #define EDecompressionType_MAX         DTYPE_MAX
} EDecompressionType;
#define EDecompressionType  EDecompressionType

/* ---------------------------------------------------------- USkill ! ---------------------------------------------------------- */

typedef enum EAdjustModifierMode : unsigned char {
  WILLOW_ADJUST_InitialAddModifer,// 0
  WILLOW_ADJUST_AddModifer,       // 1
  WILLOW_ADJUST_RemoveModifer,    // 2
  WILLOW_ADJUST_MAX               // 3
  #define WILLOW_ADJUST_InitialAddModifer        WILLOW_ADJUST_InitialAddModifer
  #define WILLOW_ADJUST_AddModifer               WILLOW_ADJUST_AddModifer
  #define WILLOW_ADJUST_RemoveModifer            WILLOW_ADJUST_RemoveModifer
  #define WILLOW_ADJUST_MAX                      WILLOW_ADJUST_MAX
  #define EAdjustModifierMode_InitialAddModifer  WILLOW_ADJUST_InitialAddModifer
  #define EAdjustModifierMode_AddModifer         WILLOW_ADJUST_AddModifer
  #define EAdjustModifierMode_RemoveModifer      WILLOW_ADJUST_RemoveModifer
  #define EAdjustModifierMode_MAX                WILLOW_ADJUST_MAX
} EAdjustModifierMode;
typedef enum PawnListSource      : unsigned char {
  PAWN_Teammate,                  // 0
  PAWN_Enemy,                     // 1
  PAWN_MAX                        // 2
  #define PAWN_Teammate            PAWN_Teammate
  #define PAWN_Enemy               PAWN_Enemy
  #define PAWN_MAX                 PAWN_MAX
  #define PawnListSource_Teammate  PAWN_Teammate
  #define PawnListSource_Enemy     PAWN_Enemy
  #define PawnListSource_MAX       PAWN_MAX
} PawnListSource;
#define EAdjustModifierMode  EAdjustModifierMode
#define PawnListSource       PawnListSource

/* ---------------------------------------------------------- ACoverGroup ! ---------------------------------------------------------- */

typedef enum ECoverGroupFillAction : unsigned char {
  CGFA_Overwrite,                 // 0
  CGFA_Add,                       // 1
  CGFA_Remove,                    // 2
  CGFA_Clear,                     // 3
  CGFA_Cylinder,                  // 4
  CGFA_MAX                        // 5
  #define CGFA_Overwrite                   CGFA_Overwrite
  #define CGFA_Add                         CGFA_Add
  #define CGFA_Remove                      CGFA_Remove
  #define CGFA_Clear                       CGFA_Clear
  #define CGFA_Cylinder                    CGFA_Cylinder
  #define CGFA_MAX                         CGFA_MAX
  #define ECoverGroupFillAction_Overwrite  CGFA_Overwrite
  #define ECoverGroupFillAction_Add        CGFA_Add
  #define ECoverGroupFillAction_Remove     CGFA_Remove
  #define ECoverGroupFillAction_Clear      CGFA_Clear
  #define ECoverGroupFillAction_Cylinder   CGFA_Cylinder
  #define ECoverGroupFillAction_MAX        CGFA_MAX
} ECoverGroupFillAction;
#define ECoverGroupFillAction  ECoverGroupFillAction

/* ---------------------------------------------------------- NamedParameter ! ---------------------------------------------------------- */

/** A generic container for an event containing a named parameter list */
typedef enum ESupportedParamTypes {
	ESPT_FLOAT,
  ESPT_INT,
  ESPT_FVector,
  ESPT_FString,
  ESPT_NIL
  #define ESPT_FLOAT                    ESPT_FLOAT
  #define ESPT_INT                      ESPT_INT
  #define ESPT_FVector                  ESPT_FVector
  #define ESPT_FString                  ESPT_FString
  #define ESPT_NIL                      ESPT_NIL
  #define ESupportedParamTypes_FLOAT    ESPT_FLOAT
  #define ESupportedParamTypes_INT      ESPT_INT
  #define ESupportedParamTypes_FVector  ESPT_FVector
  #define ESupportedParamTypes_FString  ESPT_FString
  #define ESupportedParamTypes_NIL      ESPT_NIL
} ESupportedParamTypes;
#define ESupportedParamTypes  ESupportedParamTypes

/* ---------------------------------------------------------- UPopulationDefinition ! ---------------------------------------------------------- */

typedef enum EPopulationRespawnOptions : unsigned char {
  POPRESPAWN_Never,               // 0
  POPRESPAWN_OnTimeDelay,         // 1
  POPRESPAWN_OnlyOnLevelLoad,     // 2
  POPRESPAWN_MAX                  // 3
  #define POPRESPAWN_Never                           POPRESPAWN_Never
  #define POPRESPAWN_OnTimeDelay                     POPRESPAWN_OnTimeDelay
  #define POPRESPAWN_OnlyOnLevelLoad                 POPRESPAWN_OnlyOnLevelLoad
  #define POPRESPAWN_MAX                             POPRESPAWN_MAX
  #define EPopulationRespawnOptions_Never            POPRESPAWN_Never
  #define EPopulationRespawnOptions_OnTimeDelay      POPRESPAWN_OnTimeDelay
  #define EPopulationRespawnOptions_OnlyOnLevelLoad  POPRESPAWN_OnlyOnLevelLoad
  #define EPopulationRespawnOptions_MAX              POPRESPAWN_MAX
} EPopulationRespawnOptions;
#define EPopulationRespawnOptions  EPopulationRespawnOptions

/* ---------------------------------------------------------- UIProjectileBehavior ! ---------------------------------------------------------- */

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
  #define HTARGET_None                                  HTARGET_None
  #define HTARGET_Instigator                            HTARGET_Instigator
  #define HTARGET_ViewGuidePawn                         HTARGET_ViewGuidePawn
  #define HTARGET_ViewGuideLocation                     HTARGET_ViewGuideLocation
  #define HTARGET_NearestActor                          HTARGET_NearestActor
  #define HTARGET_NearestFriend                         HTARGET_NearestFriend
  #define HTARGET_NearestFoe                            HTARGET_NearestFoe
  #define HTARGET_NearestFriendNotInstigator            HTARGET_NearestFriendNotInstigator
  #define HTARGET_MAX                                   HTARGET_MAX
  #define EHomingTargetType_None                        HTARGET_None
  #define EHomingTargetType_Instigator                  HTARGET_Instigator
  #define EHomingTargetType_ViewGuidePawn               HTARGET_ViewGuidePawn
  #define EHomingTargetType_ViewGuideLocation           HTARGET_ViewGuideLocation
  #define EHomingTargetType_NearestActor                HTARGET_NearestActor
  #define EHomingTargetType_NearestFriend               HTARGET_NearestFriend
  #define EHomingTargetType_NearestFoe                  HTARGET_NearestFoe
  #define EHomingTargetType_NearestFriendNotInstigator  HTARGET_NearestFriendNotInstigator
  #define EHomingTargetType_MAX                         HTARGET_MAX
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
  #define PPT_Standard                          PPT_Standard
  #define PPT_AreaEffect                        PPT_AreaEffect
  #define PPT_BouncingBetty                     PPT_BouncingBetty
  #define PPT_MIRV                              PPT_MIRV
  #define PPT_Singularity                       PPT_Singularity
  #define PPT_TedioreReload                     PPT_TedioreReload
  #define PPT_Transfusion                       PPT_Transfusion
  #define PPT_MAX                               PPT_MAX
  #define EProjectilePayloadType_Standard       PPT_Standard
  #define EProjectilePayloadType_AreaEffect     PPT_AreaEffect
  #define EProjectilePayloadType_BouncingBetty  PPT_BouncingBetty
  #define EProjectilePayloadType_MIRV           PPT_MIRV
  #define EProjectilePayloadType_Singularity    PPT_Singularity
  #define EProjectilePayloadType_TedioreReload  PPT_TedioreReload
  #define EProjectilePayloadType_Transfusion    PPT_Transfusion
  #define EProjectilePayloadType_MAX            PPT_MAX
} EProjectilePayloadType;
#define EHomingTargetType       EHomingTargetType
#define EProjectilePayloadType  EProjectilePayloadType

/* ---------------------------------------------------------- UGearboxRenderTextureManager ! ---------------------------------------------------------- */

typedef enum EThumbnailUpdate : unsigned char {
  Thumbnail_Static,               // 0
  Thumbnail_Update,               // 1
  Thumbnail_StreamTextures,       // 2
  Thumbnail_Dynamic,              // 3
  Thumbnail_MAX                   // 4
  #define Thumbnail_Static                 Thumbnail_Static
  #define Thumbnail_Update                 Thumbnail_Update
  #define Thumbnail_StreamTextures         Thumbnail_StreamTextures
  #define Thumbnail_Dynamic                Thumbnail_Dynamic
  #define Thumbnail_MAX                    Thumbnail_MAX
  #define EThumbnailUpdate_Static          Thumbnail_Static
  #define EThumbnailUpdate_Update          Thumbnail_Update
  #define EThumbnailUpdate_StreamTextures  Thumbnail_StreamTextures
  #define EThumbnailUpdate_Dynamic         Thumbnail_Dynamic
  #define EThumbnailUpdate_MAX             Thumbnail_MAX
} EThumbnailUpdate;
#define EThumbnailUpdate  EThumbnailUpdate

/* ---------------------------------------------------------- UOnlineGameSearch ! ---------------------------------------------------------- */

typedef enum EOnlineGameSearchEntryType      : unsigned char {
  OGSET_Property,                 // 0
  OGSET_LocalizedSetting,         // 1
  OGSET_ObjectProperty,           // 2
  OGSET_MAX                       // 3
  #define OGSET_Property                               OGSET_Property
  #define OGSET_LocalizedSetting                       OGSET_LocalizedSetting
  #define OGSET_ObjectProperty                         OGSET_ObjectProperty
  #define OGSET_MAX                                    OGSET_MAX
  #define EOnlineGameSearchEntryType_Property          OGSET_Property
  #define EOnlineGameSearchEntryType_LocalizedSetting  OGSET_LocalizedSetting
  #define EOnlineGameSearchEntryType_ObjectProperty    OGSET_ObjectProperty
  #define EOnlineGameSearchEntryType_MAX               OGSET_MAX
} EOnlineGameSearchEntryType;
typedef enum EOnlineGameSearchComparisonType : unsigned char {
  OGSCT_Equals,                   // 0
  OGSCT_NotEquals,                // 1
  OGSCT_GreaterThan,              // 2
  OGSCT_GreaterThanEquals,        // 3
  OGSCT_LessThan,                 // 4
  OGSCT_LessThanEquals,           // 5
  OGSCT_MAX                       // 6
  #define OGSCT_Equals                                       OGSCT_Equals
  #define OGSCT_NotEquals                                    OGSCT_NotEquals
  #define OGSCT_GreaterThan                                  OGSCT_GreaterThan
  #define OGSCT_GreaterThanEquals                            OGSCT_GreaterThanEquals
  #define OGSCT_LessThan                                     OGSCT_LessThan
  #define OGSCT_LessThanEquals                               OGSCT_LessThanEquals
  #define OGSCT_MAX                                          OGSCT_MAX
  #define EOnlineGameSearchComparisonType_Equals             OGSCT_Equals
  #define EOnlineGameSearchComparisonType_NotEquals          OGSCT_NotEquals
  #define EOnlineGameSearchComparisonType_GreaterThan        OGSCT_GreaterThan
  #define EOnlineGameSearchComparisonType_GreaterThanEquals  OGSCT_GreaterThanEquals
  #define EOnlineGameSearchComparisonType_LessThan           OGSCT_LessThan
  #define EOnlineGameSearchComparisonType_LessThanEquals     OGSCT_LessThanEquals
  #define EOnlineGameSearchComparisonType_MAX                OGSCT_MAX
} EOnlineGameSearchComparisonType;
typedef enum EOnlineGameSearchSortType       : unsigned char {
  OGSSO_Ascending,                // 0
  OGSSO_Descending,               // 1
  OGSSO_MAX                       // 2
  #define OGSSO_Ascending                       OGSSO_Ascending
  #define OGSSO_Descending                      OGSSO_Descending
  #define OGSSO_MAX                             OGSSO_MAX
  #define EOnlineGameSearchSortType_Ascending   OGSSO_Ascending
  #define EOnlineGameSearchSortType_Descending  OGSSO_Descending
  #define EOnlineGameSearchSortType_MAX         OGSSO_MAX
} EOnlineGameSearchSortType;
#define EOnlineGameSearchEntryType       EOnlineGameSearchEntryType
#define EOnlineGameSearchComparisonType  EOnlineGameSearchComparisonType
#define EOnlineGameSearchSortType        EOnlineGameSearchSortType

/* ---------------------------------------------------------- UWillowPlayerPawnDataManager ! ---------------------------------------------------------- */

typedef enum DataRequestType : unsigned char {
  DRT_PlayerPawn,                 // 0
  DRT_SkillTreeDef,               // 1
  DRT_VehicleDef,                 // 2
  DRT_MAX                         // 3
  #define DRT_PlayerPawn                DRT_PlayerPawn
  #define DRT_SkillTreeDef              DRT_SkillTreeDef
  #define DRT_VehicleDef                DRT_VehicleDef
  #define DRT_MAX                       DRT_MAX
  #define DataRequestType_PlayerPawn    DRT_PlayerPawn
  #define DataRequestType_SkillTreeDef  DRT_SkillTreeDef
  #define DataRequestType_VehicleDef    DRT_VehicleDef
  #define DataRequestType_MAX           DRT_MAX
} DataRequestType;
#define DataRequestType  DataRequestType

/* ---------------------------------------------------------- UGearLikenessMeshComponent ! ---------------------------------------------------------- */

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
  #define LOOKLIKE_Source                                LOOKLIKE_Source
  #define LOOKLIKE_MainWeapon                            LOOKLIKE_MainWeapon
  #define LOOKLIKE_OffhandWeapon                         LOOKLIKE_OffhandWeapon
  #define LOOKLIKE_EquippedShield                        LOOKLIKE_EquippedShield
  #define LOOKLIKE_EquippedGrenadeMod                    LOOKLIKE_EquippedGrenadeMod
  #define LOOKLIKE_EquippedClassMod                      LOOKLIKE_EquippedClassMod
  #define LOOKLIKE_HolsteredSmallWeapon                  LOOKLIKE_HolsteredSmallWeapon
  #define LOOKLIKE_HolsteredMediumWeapon                 LOOKLIKE_HolsteredMediumWeapon
  #define LOOKLIKE_HolsteredLargeWeapon                  LOOKLIKE_HolsteredLargeWeapon
  #define LOOKLIKE_HolsteredExtraLargeWeapon             LOOKLIKE_HolsteredExtraLargeWeapon
  #define LOOKLIKE_MAX                                   LOOKLIKE_MAX
  #define EGearLikenessSource_Source                     LOOKLIKE_Source
  #define EGearLikenessSource_MainWeapon                 LOOKLIKE_MainWeapon
  #define EGearLikenessSource_OffhandWeapon              LOOKLIKE_OffhandWeapon
  #define EGearLikenessSource_EquippedShield             LOOKLIKE_EquippedShield
  #define EGearLikenessSource_EquippedGrenadeMod         LOOKLIKE_EquippedGrenadeMod
  #define EGearLikenessSource_EquippedClassMod           LOOKLIKE_EquippedClassMod
  #define EGearLikenessSource_HolsteredSmallWeapon       LOOKLIKE_HolsteredSmallWeapon
  #define EGearLikenessSource_HolsteredMediumWeapon      LOOKLIKE_HolsteredMediumWeapon
  #define EGearLikenessSource_HolsteredLargeWeapon       LOOKLIKE_HolsteredLargeWeapon
  #define EGearLikenessSource_HolsteredExtraLargeWeapon  LOOKLIKE_HolsteredExtraLargeWeapon
  #define EGearLikenessSource_MAX                        LOOKLIKE_MAX
} EGearLikenessSource;
#define EGearLikenessSource  EGearLikenessSource

/* ---------------------------------------------------------- UIKilledBehavior ! ---------------------------------------------------------- */

typedef enum EScriptedKillType : unsigned char {
  KILL_Normal,                    // 0
  KILL_GibOnly,                   // 1
  KILL_TechOnly,                  // 2
  KILL_PreferTech,                // 3
  KILL_SpecialDeath1,             // 4
  KILL_SpecialDeath2,             // 5
  KILL_SpecialDeath3,             // 6
  KILL_MAX                        // 7
  #define KILL_Normal                      KILL_Normal
  #define KILL_GibOnly                     KILL_GibOnly
  #define KILL_TechOnly                    KILL_TechOnly
  #define KILL_PreferTech                  KILL_PreferTech
  #define KILL_SpecialDeath1               KILL_SpecialDeath1
  #define KILL_SpecialDeath2               KILL_SpecialDeath2
  #define KILL_SpecialDeath3               KILL_SpecialDeath3
  #define KILL_MAX                         KILL_MAX
  #define EScriptedKillType_Normal         KILL_Normal
  #define EScriptedKillType_GibOnly        KILL_GibOnly
  #define EScriptedKillType_TechOnly       KILL_TechOnly
  #define EScriptedKillType_PreferTech     KILL_PreferTech
  #define EScriptedKillType_SpecialDeath1  KILL_SpecialDeath1
  #define EScriptedKillType_SpecialDeath2  KILL_SpecialDeath2
  #define EScriptedKillType_SpecialDeath3  KILL_SpecialDeath3
  #define EScriptedKillType_MAX            KILL_MAX
} EScriptedKillType;
#define EScriptedKillType  EScriptedKillType

/* ---------------------------------------------------------- UGlobalAttributeValueResolver ! ---------------------------------------------------------- */

typedef enum EGlobalAttributes : unsigned char {
  GATTR_ExperiencePointTestLevel, // 0
  GATTR_BadassTokenTestRank,      // 1
  GATTR_MAX                       // 2
  #define GATTR_ExperiencePointTestLevel              GATTR_ExperiencePointTestLevel
  #define GATTR_BadassTokenTestRank                   GATTR_BadassTokenTestRank
  #define GATTR_MAX                                   GATTR_MAX
  #define EGlobalAttributes_ExperiencePointTestLevel  GATTR_ExperiencePointTestLevel
  #define EGlobalAttributes_BadassTokenTestRank       GATTR_BadassTokenTestRank
  #define EGlobalAttributes_MAX                       GATTR_MAX
} EGlobalAttributes;
#define EGlobalAttributes  EGlobalAttributes

/* ---------------------------------------------------------- UWillowSaveGameManager ! ---------------------------------------------------------- */

typedef enum ESaveVersionType      : unsigned char {
  ESVT_File,                      // 0
  ESVT_Player,                    // 1
  ESVT_Graveyard,                 // 2
  ESVT_MAX                        // 3
  #define ESVT_File                   ESVT_File
  #define ESVT_Player                 ESVT_Player
  #define ESVT_Graveyard              ESVT_Graveyard
  #define ESVT_MAX                    ESVT_MAX
  #define ESaveVersionType_File       ESVT_File
  #define ESaveVersionType_Player     ESVT_Player
  #define ESaveVersionType_Graveyard  ESVT_Graveyard
  #define ESaveVersionType_MAX        ESVT_MAX
} ESaveVersionType;
typedef enum CPAsync               : unsigned char {
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
  #define CPAsync_NONE             WORKRESULT_NONE
  #define CPAsync_PENDING          WORKRESULT_PENDING
  #define CPAsync_SUCCESS          WORKRESULT_SUCCESS
  #define CPAsync_FAIL             WORKRESULT_FAIL
  #define CPAsync_FILENOTFOUND     WORKRESULT_FILENOTFOUND
  #define CPAsync_MAX              WORKRESULT_MAX
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
  #define ESGMS_Idle                                         ESGMS_Idle
  #define ESGMS_Saving                                       ESGMS_Saving
  #define ESGMS_Deleting                                     ESGMS_Deleting
  #define ESGMS_Loading                                      ESGMS_Loading
  #define ESGMS_ListLoading                                  ESGMS_ListLoading
  #define ESGMS_LoadingWillowOneSave                         ESGMS_LoadingWillowOneSave
  #define ESGMS_SavingProfile                                ESGMS_SavingProfile
  #define ESGMS_CountingCrossTitleSaveGames                  ESGMS_CountingCrossTitleSaveGames
  #define ESGMS_MAX                                          ESGMS_MAX
  #define ESaveGameManagerState_Idle                         ESGMS_Idle
  #define ESaveGameManagerState_Saving                       ESGMS_Saving
  #define ESaveGameManagerState_Deleting                     ESGMS_Deleting
  #define ESaveGameManagerState_Loading                      ESGMS_Loading
  #define ESaveGameManagerState_ListLoading                  ESGMS_ListLoading
  #define ESaveGameManagerState_LoadingWillowOneSave         ESGMS_LoadingWillowOneSave
  #define ESaveGameManagerState_SavingProfile                ESGMS_SavingProfile
  #define ESaveGameManagerState_CountingCrossTitleSaveGames  ESGMS_CountingCrossTitleSaveGames
  #define ESaveGameManagerState_MAX                          ESGMS_MAX
} ESaveGameManagerState;
typedef enum ELoadPlayerBehavior   : unsigned char {
  ELPB_LoadOnly,                  // 0
  ELPB_LoadAndCache,              // 1
  ELPB_MAX                        // 2
  #define ELPB_LoadOnly                     ELPB_LoadOnly
  #define ELPB_LoadAndCache                 ELPB_LoadAndCache
  #define ELPB_MAX                          ELPB_MAX
  #define ELoadPlayerBehavior_LoadOnly      ELPB_LoadOnly
  #define ELoadPlayerBehavior_LoadAndCache  ELPB_LoadAndCache
  #define ELoadPlayerBehavior_MAX           ELPB_MAX
} ELoadPlayerBehavior;
#define ESaveVersionType       ESaveVersionType
#define CPAsync                CPAsync
#define ESaveGameManagerState  ESaveGameManagerState
#define ELoadPlayerBehavior    ELoadPlayerBehavior

/* ---------------------------------------------------------- UWillowGFxMoviePressStart ! ---------------------------------------------------------- */

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
  #define STARTUP_NotStarted                STARTUP_NotStarted
  #define STARTUP_DlcEnumeration            STARTUP_DlcEnumeration
  #define STARTUP_PatcherDownload           STARTUP_PatcherDownload
  #define STARTUP_SparkAuthentication       STARTUP_SparkAuthentication
  #define STARTUP_DeviceSelection           STARTUP_DeviceSelection
  #define STARTUP_CreateSession             STARTUP_CreateSession
  #define STARTUP_UpdateUpsell              STARTUP_UpdateUpsell
  #define STARTUP_Complete                  STARTUP_Complete
  #define STARTUP_MAX                       STARTUP_MAX
  #define EStartupStep_NotStarted           STARTUP_NotStarted
  #define EStartupStep_DlcEnumeration       STARTUP_DlcEnumeration
  #define EStartupStep_PatcherDownload      STARTUP_PatcherDownload
  #define EStartupStep_SparkAuthentication  STARTUP_SparkAuthentication
  #define EStartupStep_DeviceSelection      STARTUP_DeviceSelection
  #define EStartupStep_CreateSession        STARTUP_CreateSession
  #define EStartupStep_UpdateUpsell         STARTUP_UpdateUpsell
  #define EStartupStep_Complete             STARTUP_Complete
  #define EStartupStep_MAX                  STARTUP_MAX
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
  #define EGG_None           EGG_None
  #define EGG_Up             EGG_Up
  #define EGG_Down           EGG_Down
  #define EGG_Left           EGG_Left
  #define EGG_Right          EGG_Right
  #define EGG_B              EGG_B
  #define EGG_A              EGG_A
  #define EGG_MAX            EGG_MAX
  #define EEggCodeKey_None   EGG_None
  #define EEggCodeKey_Up     EGG_Up
  #define EEggCodeKey_Down   EGG_Down
  #define EEggCodeKey_Left   EGG_Left
  #define EEggCodeKey_Right  EGG_Right
  #define EEggCodeKey_B      EGG_B
  #define EEggCodeKey_A      EGG_A
  #define EEggCodeKey_MAX    EGG_MAX
} EEggCodeKey;
#define EStartupStep  EStartupStep
#define EEggCodeKey   EEggCodeKey

/* ---------------------------------------------------------- ALevelLandmark ! ---------------------------------------------------------- */

typedef enum ELandmarkType : unsigned char {
  LANDMARK_Custom,                // 0
  LANDMARK_Transition,            // 1
  LANDMARK_MAX                    // 2
  #define LANDMARK_Custom           LANDMARK_Custom
  #define LANDMARK_Transition       LANDMARK_Transition
  #define LANDMARK_MAX              LANDMARK_MAX
  #define ELandmarkType_Custom      LANDMARK_Custom
  #define ELandmarkType_Transition  LANDMARK_Transition
  #define ELandmarkType_MAX         LANDMARK_MAX
} ELandmarkType;
#define ELandmarkType  ELandmarkType

/* ---------------------------------------------------------- AInternetLink ! ---------------------------------------------------------- */

typedef enum ELinkMode    : unsigned char {
  MODE_Text,                      // 0
  MODE_Line,                      // 1
  MODE_Binary,                    // 2
  MODE_MAX                        // 3
  #define MODE_Text         MODE_Text
  #define MODE_Line         MODE_Line
  #define MODE_Binary       MODE_Binary
  #define MODE_MAX          MODE_MAX
  #define ELinkMode_Text    MODE_Text
  #define ELinkMode_Line    MODE_Line
  #define ELinkMode_Binary  MODE_Binary
  #define ELinkMode_MAX     MODE_MAX
} ELinkMode;
typedef enum ELineMode    : unsigned char {
  LMODE_auto,                     // 0
  LMODE_DOS,                      // 1
  LMODE_UNIX,                     // 2
  LMODE_MAC,                      // 3
  LMODE_MAX                       // 4
  #define LMODE_auto      LMODE_auto
  #define LMODE_DOS       LMODE_DOS
  #define LMODE_UNIX      LMODE_UNIX
  #define LMODE_MAC       LMODE_MAC
  #define LMODE_MAX       LMODE_MAX
  #define ELineMode_auto  LMODE_auto
  #define ELineMode_DOS   LMODE_DOS
  #define ELineMode_UNIX  LMODE_UNIX
  #define ELineMode_MAC   LMODE_MAC
  #define ELineMode_MAX   LMODE_MAX
} ELineMode;
typedef enum EReceiveMode : unsigned char {
  RMODE_Manual,                   // 0
  RMODE_Event,                    // 1
  RMODE_MAX                       // 2
  #define RMODE_Manual         RMODE_Manual
  #define RMODE_Event          RMODE_Event
  #define RMODE_MAX            RMODE_MAX
  #define EReceiveMode_Manual  RMODE_Manual
  #define EReceiveMode_Event   RMODE_Event
  #define EReceiveMode_MAX     RMODE_MAX
} EReceiveMode;
#define ELinkMode     ELinkMode
#define ELineMode     ELineMode
#define EReceiveMode  EReceiveMode

/* ---------------------------------------------------------- UWillowAIComponent ! ---------------------------------------------------------- */

typedef enum TargetExposure  : unsigned char {
  Exposure_None,                  // 0
  Exposure_Half,                  // 1
  Exposure_Full,                  // 2
  Exposure_MAX                    // 3
  #define Exposure_None        Exposure_None
  #define Exposure_Half        Exposure_Half
  #define Exposure_Full        Exposure_Full
  #define Exposure_MAX         Exposure_MAX
  #define TargetExposure_None  Exposure_None
  #define TargetExposure_Half  Exposure_Half
  #define TargetExposure_Full  Exposure_Full
  #define TargetExposure_MAX   Exposure_MAX
} TargetExposure;
typedef enum EThreatLevel    : unsigned char {
  ETL_NoThreat,                   // 0
  ETL_InThreatRadius,             // 1
  ETL_SeenInThreatRadius,         // 2
  ETL_Provoked,                   // 3
  ETL_MAX                         // 4
  #define ETL_NoThreat                     ETL_NoThreat
  #define ETL_InThreatRadius               ETL_InThreatRadius
  #define ETL_SeenInThreatRadius           ETL_SeenInThreatRadius
  #define ETL_Provoked                     ETL_Provoked
  #define ETL_MAX                          ETL_MAX
  #define EThreatLevel_NoThreat            ETL_NoThreat
  #define EThreatLevel_InThreatRadius      ETL_InThreatRadius
  #define EThreatLevel_SeenInThreatRadius  ETL_SeenInThreatRadius
  #define EThreatLevel_Provoked            ETL_Provoked
  #define EThreatLevel_MAX                 ETL_MAX
} EThreatLevel;
typedef enum ECombatPointLOS : unsigned char {
  CPLOS_Ignore,                   // 0
  CPLOS_UseLOS,                   // 1
  CPLOS_AvoidLOS,                 // 2
  CPLOS_MAX                       // 3
  #define CPLOS_Ignore              CPLOS_Ignore
  #define CPLOS_UseLOS              CPLOS_UseLOS
  #define CPLOS_AvoidLOS            CPLOS_AvoidLOS
  #define CPLOS_MAX                 CPLOS_MAX
  #define ECombatPointLOS_Ignore    CPLOS_Ignore
  #define ECombatPointLOS_UseLOS    CPLOS_UseLOS
  #define ECombatPointLOS_AvoidLOS  CPLOS_AvoidLOS
  #define ECombatPointLOS_MAX       CPLOS_MAX
} ECombatPointLOS;
#define TargetExposure   TargetExposure
#define EThreatLevel     EThreatLevel
#define ECombatPointLOS  ECombatPointLOS

/* ---------------------------------------------------------- UGrenadeModPartDefinition ! ---------------------------------------------------------- */

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
  #define GRENADEMOD_PART_Body           GRENADEMOD_PART_Body
  #define GRENADEMOD_PART_Delivery       GRENADEMOD_PART_Delivery
  #define GRENADEMOD_PART_Trigger        GRENADEMOD_PART_Trigger
  #define GRENADEMOD_PART_Accessory      GRENADEMOD_PART_Accessory
  #define GRENADEMOD_PART_Material       GRENADEMOD_PART_Material
  #define GRENADEMOD_PART_Prefix         GRENADEMOD_PART_Prefix
  #define GRENADEMOD_PART_Title          GRENADEMOD_PART_Title
  #define GRENADEMOD_PART_Property1      GRENADEMOD_PART_Property1
  #define GRENADEMOD_PART_Property2      GRENADEMOD_PART_Property2
  #define GRENADEMOD_PART_Property3      GRENADEMOD_PART_Property3
  #define GRENADEMOD_PART_Property4      GRENADEMOD_PART_Property4
  #define GRENADEMOD_PART_MAX            GRENADEMOD_PART_MAX
  #define EGrenadeModPartType_Body       GRENADEMOD_PART_Body
  #define EGrenadeModPartType_Delivery   GRENADEMOD_PART_Delivery
  #define EGrenadeModPartType_Trigger    GRENADEMOD_PART_Trigger
  #define EGrenadeModPartType_Accessory  GRENADEMOD_PART_Accessory
  #define EGrenadeModPartType_Material   GRENADEMOD_PART_Material
  #define EGrenadeModPartType_Prefix     GRENADEMOD_PART_Prefix
  #define EGrenadeModPartType_Title      GRENADEMOD_PART_Title
  #define EGrenadeModPartType_Property1  GRENADEMOD_PART_Property1
  #define EGrenadeModPartType_Property2  GRENADEMOD_PART_Property2
  #define EGrenadeModPartType_Property3  GRENADEMOD_PART_Property3
  #define EGrenadeModPartType_Property4  GRENADEMOD_PART_Property4
  #define EGrenadeModPartType_MAX        GRENADEMOD_PART_MAX
} EGrenadeModPartType;
#define EGrenadeModPartType  EGrenadeModPartType

/* ---------------------------------------------------------- AWillowPopulationPoint ! ---------------------------------------------------------- */

typedef enum EStretchyType : unsigned char {
  Stretchy_Linear,                // 0
  Stretchy_Parabola,              // 1
  Stretchy_MAX                    // 2
  #define Stretchy_Linear         Stretchy_Linear
  #define Stretchy_Parabola       Stretchy_Parabola
  #define Stretchy_MAX            Stretchy_MAX
  #define EStretchyType_Linear    Stretchy_Linear
  #define EStretchyType_Parabola  Stretchy_Parabola
  #define EStretchyType_MAX       Stretchy_MAX
} EStretchyType;
#define EStretchyType  EStretchyType

/* ---------------------------------------------------------- USparkInterfaceImpl ! ---------------------------------------------------------- */

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
  #define SRS_IDLE                                 SRS_IDLE
  #define SRS_AWAITING_RETRY                       SRS_AWAITING_RETRY
  #define SRS_IN_FLIGHT                            SRS_IN_FLIGHT
  #define SRS_AWAITING_AUTHENTICATE                SRS_AWAITING_AUTHENTICATE
  #define SRS_START                                SRS_START
  #define SRS_FAIL                                 SRS_FAIL
  #define SRS_QUEUED                               SRS_QUEUED
  #define SRS_CLEANUP                              SRS_CLEANUP
  #define SRS_MAX                                  SRS_MAX
  #define SparkRequestState_IDLE                   SRS_IDLE
  #define SparkRequestState_AWAITING_RETRY         SRS_AWAITING_RETRY
  #define SparkRequestState_IN_FLIGHT              SRS_IN_FLIGHT
  #define SparkRequestState_AWAITING_AUTHENTICATE  SRS_AWAITING_AUTHENTICATE
  #define SparkRequestState_START                  SRS_START
  #define SparkRequestState_FAIL                   SRS_FAIL
  #define SparkRequestState_QUEUED                 SRS_QUEUED
  #define SparkRequestState_CLEANUP                SRS_CLEANUP
  #define SparkRequestState_MAX                    SRS_MAX
} SparkRequestState;
#define SparkRequestState  SparkRequestState

/* ---------------------------------------------------------- FFrame ! ---------------------------------------------------------- */

/* Evaluatable expression item types. */
typedef enum EExprToken {
	/* Variable references. */
	EX_LocalVariable       = 0x00,  /** A local variable. */
	EX_InstanceVariable    = 0x01,  /** An object variable. */
	EX_DefaultVariable     = 0x02,  /** Default variable for a concrete object. */
	/* Tokens. */
	EX_Return              = 0x04,  /** Return from function. */
	EX_Switch              = 0x05,  /** Switch. */
	EX_Jump                = 0x06,  /** Goto a local address in code. */
	EX_JumpIfNot           = 0x07,  /** Goto if not expression. */
	EX_Stop                = 0x08,  /** Stop executing state code. */
	EX_Assert              = 0x09,  /** Assertion. */
	EX_Case                = 0x0A,  /** Case. */
	EX_Nothing             = 0x0B,  /** No operation. */
	EX_LabelTable          = 0x0C,  /** Table of labels. */
	EX_GotoLabel           = 0x0D,  /** Goto a label. */
	EX_EatReturnValue      = 0x0E,  /** destroy an unused return value */
	EX_Let                 = 0x0F,  /** Assign an arbitrary size value to a variable. */
	EX_DynArrayElement     = 0x10,  /** Dynamic array element.!! */
	EX_New                 = 0x11,  /** New object allocation. */
	EX_ClassContext        = 0x12,  /** Class default metaobject context. */
	EX_MetaCast            = 0x13,  /** Metaclass cast. */
	EX_LetBool             = 0x14,  /** Let boolean variable. */
	EX_EndParmValue        = 0x15,  /** end of default value for optional function parameter */
	EX_EndFunctionParms    = 0x16,  /** End of function call parameters. */
	EX_Self                = 0x17,  /** Self object. */
	EX_Skip                = 0x18,  /** Skippable expression. */
	EX_Context             = 0x19,  /** Call a function through an object context. */
	EX_ArrayElement        = 0x1A,  /** Array element. */
	EX_VirtualFunction     = 0x1B,  /** A function call with parameters. */
	EX_FinalFunction       = 0x1C,  /** A prebound function call with parameters. */
	EX_IntConst            = 0x1D,  /** Int constant. */
	EX_FloatConst          = 0x1E,  /** Floating point constant. */
	EX_StringConst         = 0x1F,  /** String constant. */
	EX_ObjectConst         = 0x20,  /** An object constant. */
	EX_NameConst           = 0x21,  /** A name constant. */
	EX_RotationConst       = 0x22,  /** A rotation constant. */
	EX_VectorConst         = 0x23,  /** A vector constant. */
	EX_ByteConst           = 0x24,  /** A byte constant. */
	EX_IntZero             = 0x25,  /** Zero. */
	EX_IntOne              = 0x26,  /** One. */
	EX_True                = 0x27,  /** Bool True. */
	EX_False               = 0x28,  /** Bool False. */
	EX_NativeParm          = 0x29,  /** Native function parameter offset. */
	EX_NoObject            = 0x2A,  /** NoObject. */
	EX_IntConstByte			   = 0x2C,  /** Int constant that requires 1 byte. */
	EX_BoolVariable			   = 0x2D,  /** A bool variable which requires a bitmask. */
	EX_DynamicCast			   = 0x2E,  /** Safe dynamic class casting. */
	EX_Iterator            = 0x2F,  /** Begin an iterator operation. */
	EX_IteratorPop         = 0x30,  /** Pop an iterator level. */
	EX_IteratorNext        = 0x31,  /** Go to next iteration. */
	EX_StructCmpEq         = 0x32,  /** Struct binary compare-for-equal. */
	EX_StructCmpNe         = 0x33,  /** Struct binary compare-for-unequal. */
	EX_UnicodeStringConst  = 0x34,  /** Unicode string constant. */
	EX_StructMember        = 0x35,  /** Struct member. */
	EX_DynArrayLength      = 0x36,  /** A dynamic array length for setting/getting */
	EX_GlobalFunction      = 0x37,  /** Call non-state version of a function. */
	EX_PrimitiveCast       = 0x38,  /** A casting operator for primitives which reads the type as the subsequent byte */
	EX_DynArrayInsert      = 0x39,  /** Inserts into a dynamic array */
	EX_ReturnNothing       = 0x3A,  /** failsafe for functions that return a value - returns the zero value for a property and logs that control reached the end of a non-void function */
	EX_EqualEqual_DelDel   = 0x3B,  /** delegate comparison for equality */
	EX_NotEqual_DelDel     = 0x3C,  /** delegate comparison for inequality */
	EX_EqualEqual_DelFunc  = 0x3D,  /** delegate comparison for equality against a function */
	EX_NotEqual_DelFunc    = 0x3E,  /** delegate comparison for inequality against a function */
	EX_EmptyDelegate       = 0x3F,  /** delegate 'None' */
	EX_DynArrayRemove      = 0x40,  /** Removes from a dynamic array */
	EX_DebugInfo           = 0x41,  /** DEBUGGER Debug information */
	EX_DelegateFunction    = 0x42,  /** Call to a delegate function */
	EX_DelegateProperty    = 0x43,  /** Delegate expression */
	EX_LetDelegate         = 0x44,  /** Assignment to a delegate */
	EX_Conditional         = 0x45,  /** tertiary operator support */
	EX_DynArrayFind        = 0x46,  /** dynarray search for item index */
	EX_DynArrayFindStruct  = 0x47,  /** dynarray<struct> search for item index */
	EX_LocalOutVariable    = 0x48,  /** local out (pass by reference) function parameter */
	EX_DefaultParmValue    = 0x49,  /** default value of optional function parameter */
	EX_EmptyParmValue      = 0x4A,  /** unspecified value for optional function parameter */
	EX_InstanceDelegate    = 0x4B,  /** const reference to a delegate or normal function object */
	EX_InterfaceContext    = 0x51,  /** Call a function through a native interface variable */
	EX_InterfaceCast       = 0x52,  /** Converting an object reference to native interface variable */
	EX_EndOfScript         = 0x53,  /** Last byte in script code */
	EX_DynArrayAdd         = 0x54,  /** Add to a dynamic array */
	EX_DynArrayAddItem     = 0x55,  /** Add an item to a dynamic array */
	EX_DynArrayRemoveItem  = 0x56,  /** Remove an item from a dynamic array */
	EX_DynArrayInsertItem  = 0x57,  /** Insert an item into a dynamic array */
	EX_DynArrayIterator    = 0x58,  /** Iterate through a dynamic array */
	EX_DynArraySort        = 0x59,  /** Sort a list in place */
	/* Natives. */
	EX_ExtendedNative      = 0x60,
	EX_FirstNative         = 0x70,
	EX_Max                 = 0x1000,
  #define EX_LocalVariable               EX_LocalVariable
  #define EX_InstanceVariable            EX_InstanceVariable
  #define EX_DefaultVariable             EX_DefaultVariable
  #define EX_Return                      EX_Return
  #define EX_Switch                      EX_Switch
  #define EX_Jump                        EX_Jump
  #define EX_JumpIfNot                   EX_JumpIfNot
  #define EX_Stop                        EX_Stop
  #define EX_Assert                      EX_Assert
  #define EX_Case                        EX_Case
  #define EX_Nothing                     EX_Nothing
  #define EX_LabelTable                  EX_LabelTable
  #define EX_GotoLabel                   EX_GotoLabel
  #define EX_EatReturnValue              EX_EatReturnValue
  #define EX_Let                         EX_Let
  #define EX_DynArrayElement             EX_DynArrayElement
  #define EX_New                         EX_New
  #define EX_ClassContext                EX_ClassContext
  #define EX_MetaCast                    EX_MetaCast
  #define EX_LetBool                     EX_LetBool
  #define EX_EndParmValue                EX_EndParmValue
  #define EX_EndFunctionParms            EX_EndFunctionParms
  #define EX_Self                        EX_Self
  #define EX_Skip                        EX_Skip
  #define EX_Context                     EX_Context
  #define EX_ArrayElement                EX_ArrayElement
  #define EX_VirtualFunction             EX_VirtualFunction
  #define EX_FinalFunction               EX_FinalFunction
  #define EX_IntConst                    EX_IntConst
  #define EX_FloatConst                  EX_FloatConst
  #define EX_StringConst                 EX_StringConst
  #define EX_ObjectConst                 EX_ObjectConst
  #define EX_NameConst                   EX_NameConst
  #define EX_RotationConst               EX_RotationConst
  #define EX_VectorConst                 EX_VectorConst
  #define EX_ByteConst                   EX_ByteConst
  #define EX_IntZero                     EX_IntZero
  #define EX_IntOne                      EX_IntOne
  #define EX_True                        EX_True
  #define EX_False                       EX_False
  #define EX_NativeParm                  EX_NativeParm
  #define EX_NoObject                    EX_NoObject
  #define EX_IntConstByte                EX_IntConstByte
  #define EX_BoolVariable                EX_BoolVariable
  #define EX_DynamicCast                 EX_DynamicCast
  #define EX_Iterator                    EX_Iterator
  #define EX_IteratorPop                 EX_IteratorPop
  #define EX_IteratorNext                EX_IteratorNext
  #define EX_StructCmpEq                 EX_StructCmpEq
  #define EX_StructCmpNe                 EX_StructCmpNe
  #define EX_UnicodeStringConst          EX_UnicodeStringConst
  #define EX_StructMember                EX_StructMember
  #define EX_DynArrayLength              EX_DynArrayLength
  #define EX_GlobalFunction              EX_GlobalFunction
  #define EX_PrimitiveCast               EX_PrimitiveCast
  #define EX_DynArrayInsert              EX_DynArrayInsert
  #define EX_ReturnNothing               EX_ReturnNothing
  #define EX_EqualEqual_DelDel           EX_EqualEqual_DelDel
  #define EX_NotEqual_DelDel             EX_NotEqual_DelDel
  #define EX_EqualEqual_DelFunc          EX_EqualEqual_DelFunc
  #define EX_NotEqual_DelFunc            EX_NotEqual_DelFunc
  #define EX_EmptyDelegate               EX_EmptyDelegate
  #define EX_DynArrayRemove              EX_DynArrayRemove
  #define EX_DebugInfo                   EX_DebugInfo
  #define EX_DelegateFunction            EX_DelegateFunction
  #define EX_DelegateProperty            EX_DelegateProperty
  #define EX_LetDelegate                 EX_LetDelegate
  #define EX_Conditional                 EX_Conditional
  #define EX_DynArrayFind                EX_DynArrayFind
  #define EX_DynArrayFindStruct          EX_DynArrayFindStruct
  #define EX_LocalOutVariable            EX_LocalOutVariable
  #define EX_DefaultParmValue            EX_DefaultParmValue
  #define EX_EmptyParmValue              EX_EmptyParmValue
  #define EX_InstanceDelegate            EX_InstanceDelegate
  #define EX_InterfaceContext            EX_InterfaceContext
  #define EX_InterfaceCast               EX_InterfaceCast
  #define EX_EndOfScript                 EX_EndOfScript
  #define EX_DynArrayAdd                 EX_DynArrayAdd
  #define EX_DynArrayAddItem             EX_DynArrayAddItem
  #define EX_DynArrayRemoveItem          EX_DynArrayRemoveItem
  #define EX_DynArrayInsertItem          EX_DynArrayInsertItem
  #define EX_DynArrayIterator            EX_DynArrayIterator
  #define EX_DynArraySort                EX_DynArraySort
  #define EX_ExtendedNative              EX_ExtendedNative
  #define EX_FirstNative                 EX_FirstNative
  #define EX_Max                         EX_Max
  #define EExprToken_LocalVariable       EX_LocalVariable
  #define EExprToken_InstanceVariable    EX_InstanceVariable
  #define EExprToken_DefaultVariable     EX_DefaultVariable
  #define EExprToken_Return              EX_Return
  #define EExprToken_Switch              EX_Switch
  #define EExprToken_Jump                EX_Jump
  #define EExprToken_JumpIfNot           EX_JumpIfNot
  #define EExprToken_Stop                EX_Stop
  #define EExprToken_Assert              EX_Assert
  #define EExprToken_Case                EX_Case
  #define EExprToken_Nothing             EX_Nothing
  #define EExprToken_LabelTable          EX_LabelTable
  #define EExprToken_GotoLabel           EX_GotoLabel
  #define EExprToken_EatReturnValue      EX_EatReturnValue
  #define EExprToken_Let                 EX_Let
  #define EExprToken_DynArrayElement     EX_DynArrayElement
  #define EExprToken_New                 EX_New
  #define EExprToken_ClassContext        EX_ClassContext
  #define EExprToken_MetaCast            EX_MetaCast
  #define EExprToken_LetBool             EX_LetBool
  #define EExprToken_EndParmValue        EX_EndParmValue
  #define EExprToken_EndFunctionParms    EX_EndFunctionParms
  #define EExprToken_Self                EX_Self
  #define EExprToken_Skip                EX_Skip
  #define EExprToken_Context             EX_Context
  #define EExprToken_ArrayElement        EX_ArrayElement
  #define EExprToken_VirtualFunction     EX_VirtualFunction
  #define EExprToken_FinalFunction       EX_FinalFunction
  #define EExprToken_IntConst            EX_IntConst
  #define EExprToken_FloatConst          EX_FloatConst
  #define EExprToken_StringConst         EX_StringConst
  #define EExprToken_ObjectConst         EX_ObjectConst
  #define EExprToken_NameConst           EX_NameConst
  #define EExprToken_RotationConst       EX_RotationConst
  #define EExprToken_VectorConst         EX_VectorConst
  #define EExprToken_ByteConst           EX_ByteConst
  #define EExprToken_IntZero             EX_IntZero
  #define EExprToken_IntOne              EX_IntOne
  #define EExprToken_True                EX_True
  #define EExprToken_False               EX_False
  #define EExprToken_NativeParm          EX_NativeParm
  #define EExprToken_NoObject            EX_NoObject
  #define EExprToken_IntConstByte        EX_IntConstByte
  #define EExprToken_BoolVariable        EX_BoolVariable
  #define EExprToken_DynamicCast         EX_DynamicCast
  #define EExprToken_Iterator            EX_Iterator
  #define EExprToken_IteratorPop         EX_IteratorPop
  #define EExprToken_IteratorNext        EX_IteratorNext
  #define EExprToken_StructCmpEq         EX_StructCmpEq
  #define EExprToken_StructCmpNe         EX_StructCmpNe
  #define EExprToken_UnicodeStringConst  EX_UnicodeStringConst
  #define EExprToken_StructMember        EX_StructMember
  #define EExprToken_DynArrayLength      EX_DynArrayLength
  #define EExprToken_GlobalFunction      EX_GlobalFunction
  #define EExprToken_PrimitiveCast       EX_PrimitiveCast
  #define EExprToken_DynArrayInsert      EX_DynArrayInsert
  #define EExprToken_ReturnNothing       EX_ReturnNothing
  #define EExprToken_EqualEqual_DelDel   EX_EqualEqual_DelDel
  #define EExprToken_NotEqual_DelDel     EX_NotEqual_DelDel
  #define EExprToken_EqualEqual_DelFunc  EX_EqualEqual_DelFunc
  #define EExprToken_NotEqual_DelFunc    EX_NotEqual_DelFunc
  #define EExprToken_EmptyDelegate       EX_EmptyDelegate
  #define EExprToken_DynArrayRemove      EX_DynArrayRemove
  #define EExprToken_DebugInfo           EX_DebugInfo
  #define EExprToken_DelegateFunction    EX_DelegateFunction
  #define EExprToken_DelegateProperty    EX_DelegateProperty
  #define EExprToken_LetDelegate         EX_LetDelegate
  #define EExprToken_Conditional         EX_Conditional
  #define EExprToken_DynArrayFind        EX_DynArrayFind
  #define EExprToken_DynArrayFindStruct  EX_DynArrayFindStruct
  #define EExprToken_LocalOutVariable    EX_LocalOutVariable
  #define EExprToken_DefaultParmValue    EX_DefaultParmValue
  #define EExprToken_EmptyParmValue      EX_EmptyParmValue
  #define EExprToken_InstanceDelegate    EX_InstanceDelegate
  #define EExprToken_InterfaceContext    EX_InterfaceContext
  #define EExprToken_InterfaceCast       EX_InterfaceCast
  #define EExprToken_EndOfScript         EX_EndOfScript
  #define EExprToken_DynArrayAdd         EX_DynArrayAdd
  #define EExprToken_DynArrayAddItem     EX_DynArrayAddItem
  #define EExprToken_DynArrayRemoveItem  EX_DynArrayRemoveItem
  #define EExprToken_DynArrayInsertItem  EX_DynArrayInsertItem
  #define EExprToken_DynArrayIterator    EX_DynArrayIterator
  #define EExprToken_DynArraySort        EX_DynArraySort
  #define EExprToken_ExtendedNative      EX_ExtendedNative
  #define EExprToken_FirstNative         EX_FirstNative
  #define EExprToken_Max                 EX_Max
} EExprToken;
#define EExprToken  EExprToken

/* ---------------------------------------------------------- UTradingPanelGFxObject ! ---------------------------------------------------------- */

typedef enum ETradingPanel : unsigned char {
  ETP_Backpack,                   // 0
  ETP_Offers,                     // 1
  ETP_MAX                         // 2
  #define ETP_Backpack            ETP_Backpack
  #define ETP_Offers              ETP_Offers
  #define ETP_MAX                 ETP_MAX
  #define ETradingPanel_Backpack  ETP_Backpack
  #define ETradingPanel_Offers    ETP_Offers
  #define ETradingPanel_MAX       ETP_MAX
} ETradingPanel;
#define ETradingPanel  ETradingPanel

/* ---------------------------------------------------------- USparkNews ! ---------------------------------------------------------- */

typedef enum ENewsRetrievalResult : unsigned char {
  NEWSRETRIEVE_Success,           // 0
  NEWSRETRIEVE_GeneralFailure,    // 1
  NEWSRETRIEVE_NetworkFailure,    // 2
  NEWSRETRIEVE_Timeout,           // 3
  NEWSRETRIEVE_MAX                // 4
  #define NEWSRETRIEVE_Success                 NEWSRETRIEVE_Success
  #define NEWSRETRIEVE_GeneralFailure          NEWSRETRIEVE_GeneralFailure
  #define NEWSRETRIEVE_NetworkFailure          NEWSRETRIEVE_NetworkFailure
  #define NEWSRETRIEVE_Timeout                 NEWSRETRIEVE_Timeout
  #define NEWSRETRIEVE_MAX                     NEWSRETRIEVE_MAX
  #define ENewsRetrievalResult_Success         NEWSRETRIEVE_Success
  #define ENewsRetrievalResult_GeneralFailure  NEWSRETRIEVE_GeneralFailure
  #define ENewsRetrievalResult_NetworkFailure  NEWSRETRIEVE_NetworkFailure
  #define ENewsRetrievalResult_Timeout         NEWSRETRIEVE_Timeout
  #define ENewsRetrievalResult_MAX             NEWSRETRIEVE_MAX
} ENewsRetrievalResult;
#define ENewsRetrievalResult  ENewsRetrievalResult

/* ---------------------------------------------------------- UParticleModuleRequired ! ---------------------------------------------------------- */

typedef enum EParticleSortMode   : unsigned char {
  PSORTMODE_None,                 // 0
  PSORTMODE_ViewProjDepth,        // 1
  PSORTMODE_DistanceToView,       // 2
  PSORTMODE_Age_OldestFirst,      // 3
  PSORTMODE_Age_NewestFirst,      // 4
  PSORTMODE_MAX                   // 5
  #define PSORTMODE_None                     PSORTMODE_None
  #define PSORTMODE_ViewProjDepth            PSORTMODE_ViewProjDepth
  #define PSORTMODE_DistanceToView           PSORTMODE_DistanceToView
  #define PSORTMODE_Age_OldestFirst          PSORTMODE_Age_OldestFirst
  #define PSORTMODE_Age_NewestFirst          PSORTMODE_Age_NewestFirst
  #define PSORTMODE_MAX                      PSORTMODE_MAX
  #define EParticleSortMode_None             PSORTMODE_None
  #define EParticleSortMode_ViewProjDepth    PSORTMODE_ViewProjDepth
  #define EParticleSortMode_DistanceToView   PSORTMODE_DistanceToView
  #define EParticleSortMode_Age_OldestFirst  PSORTMODE_Age_OldestFirst
  #define EParticleSortMode_Age_NewestFirst  PSORTMODE_Age_NewestFirst
  #define EParticleSortMode_MAX              PSORTMODE_MAX
} EParticleSortMode;
typedef enum EEmitterNormalsMode : unsigned char {
  ENM_CameraFacing,               // 0
  ENM_Spherical,                  // 1
  ENM_Cylindrical,                // 2
  ENM_MAX                         // 3
  #define ENM_CameraFacing                  ENM_CameraFacing
  #define ENM_Spherical                     ENM_Spherical
  #define ENM_Cylindrical                   ENM_Cylindrical
  #define ENM_MAX                           ENM_MAX
  #define EEmitterNormalsMode_CameraFacing  ENM_CameraFacing
  #define EEmitterNormalsMode_Spherical     ENM_Spherical
  #define EEmitterNormalsMode_Cylindrical   ENM_Cylindrical
  #define EEmitterNormalsMode_MAX           ENM_MAX
} EEmitterNormalsMode;
#define EParticleSortMode    EParticleSortMode
#define EEmitterNormalsMode  EEmitterNormalsMode

/* ---------------------------------------------------------- UParticleSpriteEmitter ! ---------------------------------------------------------- */

typedef enum EParticleScreenAlignment : unsigned char {
  PSA_Square,                     // 0
  PSA_Rectangle,                  // 1
  PSA_Velocity,                   // 2
  PSA_TypeSpecific,               // 3
  PSA_MAX                         // 4
  #define PSA_Square                             PSA_Square
  #define PSA_Rectangle                          PSA_Rectangle
  #define PSA_Velocity                           PSA_Velocity
  #define PSA_TypeSpecific                       PSA_TypeSpecific
  #define PSA_MAX                                PSA_MAX
  #define EParticleScreenAlignment_Square        PSA_Square
  #define EParticleScreenAlignment_Rectangle     PSA_Rectangle
  #define EParticleScreenAlignment_Velocity      PSA_Velocity
  #define EParticleScreenAlignment_TypeSpecific  PSA_TypeSpecific
  #define EParticleScreenAlignment_MAX           PSA_MAX
} EParticleScreenAlignment;
#define EParticleScreenAlignment  EParticleScreenAlignment

/* ---------------------------------------------------------- USeqAct_ExecuteSkill ! ---------------------------------------------------------- */

typedef enum EExecuteSkillSequenceInput : unsigned char {
  SEQUENCE_ActivateSkill,         // 0
  SEQUENCE_DeactivateSkill,       // 1
  SEQUENCE_ToggleSkill,           // 2
  SEQUENCE_MAX                    // 3
  #define SEQUENCE_ActivateSkill                      SEQUENCE_ActivateSkill
  #define SEQUENCE_DeactivateSkill                    SEQUENCE_DeactivateSkill
  #define SEQUENCE_ToggleSkill                        SEQUENCE_ToggleSkill
  #define SEQUENCE_MAX                                SEQUENCE_MAX
  #define EExecuteSkillSequenceInput_ActivateSkill    SEQUENCE_ActivateSkill
  #define EExecuteSkillSequenceInput_DeactivateSkill  SEQUENCE_DeactivateSkill
  #define EExecuteSkillSequenceInput_ToggleSkill      SEQUENCE_ToggleSkill
  #define EExecuteSkillSequenceInput_MAX              SEQUENCE_MAX
} EExecuteSkillSequenceInput;
#define EExecuteSkillSequenceInput  EExecuteSkillSequenceInput

/* ---------------------------------------------------------- UParticleModuleOrbit ! ---------------------------------------------------------- */

typedef enum EOrbitChainMode : unsigned char {
  EOChainMode_Add,                // 0
  EOChainMode_Scale,              // 1
  EOChainMode_Link,               // 2
  EOChainMode_MAX                 // 3
  #define EOChainMode_Add        EOChainMode_Add
  #define EOChainMode_Scale      EOChainMode_Scale
  #define EOChainMode_Link       EOChainMode_Link
  #define EOChainMode_MAX        EOChainMode_MAX
  #define EOrbitChainMode_Add    EOChainMode_Add
  #define EOrbitChainMode_Scale  EOChainMode_Scale
  #define EOrbitChainMode_Link   EOChainMode_Link
  #define EOrbitChainMode_MAX    EOChainMode_MAX
} EOrbitChainMode;
#define EOrbitChainMode  EOrbitChainMode

/* ---------------------------------------------------------- ADeathtrapActionSkill ! ---------------------------------------------------------- */

typedef enum EMedicBeamState : unsigned char {
  MedicBeam_Inactive,             // 0
  MedicBeam_Active,               // 1
  MedicBeam_Blocked,              // 2
  MedicBeam_MAX                   // 3
  #define MedicBeam_Inactive        MedicBeam_Inactive
  #define MedicBeam_Active          MedicBeam_Active
  #define MedicBeam_Blocked         MedicBeam_Blocked
  #define MedicBeam_MAX             MedicBeam_MAX
  #define EMedicBeamState_Inactive  MedicBeam_Inactive
  #define EMedicBeamState_Active    MedicBeam_Active
  #define EMedicBeamState_Blocked   MedicBeam_Blocked
  #define EMedicBeamState_MAX       MedicBeam_MAX
} EMedicBeamState;
#define EMedicBeamState  EMedicBeamState

/* ---------------------------------------------------------- UBehavior_StatusEffectSwitch ! ---------------------------------------------------------- */

typedef enum EStatusEffectSwitchValues : unsigned char {
  OUTPUT_None,                    // 0
  OUTPUT_Ignite,                  // 1
  OUTPUT_Corrosive,               // 2
  OUTPUT_Shock,                   // 3
  OUTPUT_Amp,                     // 4
  OUTPUT_Slow,                    // 5
  OUTPUT_Healing,                 // 6
  OUTPUT_MAX                      // 7
  #define OUTPUT_None                          OUTPUT_None
  #define OUTPUT_Ignite                        OUTPUT_Ignite
  #define OUTPUT_Corrosive                     OUTPUT_Corrosive
  #define OUTPUT_Shock                         OUTPUT_Shock
  #define OUTPUT_Amp                           OUTPUT_Amp
  #define OUTPUT_Slow                          OUTPUT_Slow
  #define OUTPUT_Healing                       OUTPUT_Healing
  #define OUTPUT_MAX                           OUTPUT_MAX
  #define EStatusEffectSwitchValues_None       OUTPUT_None
  #define EStatusEffectSwitchValues_Ignite     OUTPUT_Ignite
  #define EStatusEffectSwitchValues_Corrosive  OUTPUT_Corrosive
  #define EStatusEffectSwitchValues_Shock      OUTPUT_Shock
  #define EStatusEffectSwitchValues_Amp        OUTPUT_Amp
  #define EStatusEffectSwitchValues_Slow       OUTPUT_Slow
  #define EStatusEffectSwitchValues_Healing    OUTPUT_Healing
  #define EStatusEffectSwitchValues_MAX        OUTPUT_MAX
} EStatusEffectSwitchValues;
#define EStatusEffectSwitchValues  EStatusEffectSwitchValues

/* ---------------------------------------------------------- UWillowPreviewComponent ! ---------------------------------------------------------- */

typedef enum EPreviewStyle : unsigned char {
  EPS_None,                       // 0
  EPS_Still,                      // 1
  EPS_Playing,                    // 2
  EPS_MAX                         // 3
  #define EPS_None               EPS_None
  #define EPS_Still              EPS_Still
  #define EPS_Playing            EPS_Playing
  #define EPS_MAX                EPS_MAX
  #define EPreviewStyle_None     EPS_None
  #define EPreviewStyle_Still    EPS_Still
  #define EPreviewStyle_Playing  EPS_Playing
  #define EPreviewStyle_MAX      EPS_MAX
} EPreviewStyle;
#define EPreviewStyle  EPreviewStyle

/* ---------------------------------------------------------- UAnimNotify_UseBehavior ! ---------------------------------------------------------- */

typedef enum EUseBehaviorContext : unsigned char {
  EUBC_ActorSkelMeshIsAttachedTo, // 0
  EUBC_ObjectSkelMeshWasCreatedBy,// 1
  EUBC_MAX                        // 2
  #define EUBC_ActorSkelMeshIsAttachedTo                  EUBC_ActorSkelMeshIsAttachedTo
  #define EUBC_ObjectSkelMeshWasCreatedBy                 EUBC_ObjectSkelMeshWasCreatedBy
  #define EUBC_MAX                                        EUBC_MAX
  #define EUseBehaviorContext_ActorSkelMeshIsAttachedTo   EUBC_ActorSkelMeshIsAttachedTo
  #define EUseBehaviorContext_ObjectSkelMeshWasCreatedBy  EUBC_ObjectSkelMeshWasCreatedBy
  #define EUseBehaviorContext_MAX                         EUBC_MAX
} EUseBehaviorContext;
#define EUseBehaviorContext  EUseBehaviorContext

/* ---------------------------------------------------------- UArtifactPartDefinition ! ---------------------------------------------------------- */

typedef enum EArtifactPartType {
  ARTIFACT_PART_EnableFirstEffect,// 0
  ARTIFACT_PART_EnableSecondEffect,// 1
  ARTIFACT_PART_EnableThirdEffect,// 2
  ARTIFACT_PART_EnableFourthEffect,// 3
  ARTIFACT_PART_UpgradeEffect,    // 4
  ARTIFACT_PART_Body,             // 5
  ARTIFACT_PART_MAX               // 6
  #define ARTIFACT_PART_EnableFirstEffect       ARTIFACT_PART_EnableFirstEffect
  #define ARTIFACT_PART_EnableSecondEffect      ARTIFACT_PART_EnableSecondEffect
  #define ARTIFACT_PART_EnableThirdEffect       ARTIFACT_PART_EnableThirdEffect
  #define ARTIFACT_PART_EnableFourthEffect      ARTIFACT_PART_EnableFourthEffect
  #define ARTIFACT_PART_UpgradeEffect           ARTIFACT_PART_UpgradeEffect
  #define ARTIFACT_PART_Body                    ARTIFACT_PART_Body
  #define ARTIFACT_PART_MAX                     ARTIFACT_PART_MAX
  #define EArtifactPartType_EnableFirstEffect   ARTIFACT_PART_EnableFirstEffect
  #define EArtifactPartType_EnableSecondEffect  ARTIFACT_PART_EnableSecondEffect
  #define EArtifactPartType_EnableThirdEffect   ARTIFACT_PART_EnableThirdEffect
  #define EArtifactPartType_EnableFourthEffect  ARTIFACT_PART_EnableFourthEffect
  #define EArtifactPartType_UpgradeEffect       ARTIFACT_PART_UpgradeEffect
  #define EArtifactPartType_Body                ARTIFACT_PART_Body
  #define EArtifactPartType_MAX                 ARTIFACT_PART_MAX
} EArtifactPartType;
#define EArtifactPartType  EArtifactPartType

/* ---------------------------------------------------------- UIPopulationSpawnPoint ! ---------------------------------------------------------- */

typedef enum ESpawnStyleType    : unsigned char {
  ENTRANCE_None,                  // 0
  ENTRANCE_WalkOut,               // 1
  ENTRANCE_CrawlOut,              // 2
  ENTRANCE_ClimbOver1,            // 3
  ENTRANCE_ClimbOver2,            // 4
  ENTRANCE_PushTarpAside1,        // 5
  ENTRANCE_PushTarpAside2,        // 6
  ENTRANCE_PhaseIn,               // 7
  ENTRANCE_PerchedLeft,           // 8
  ENTRANCE_PerchedRight,          // 9
  ENTRANCE_MAX                    // 10
  #define ENTRANCE_None                   ENTRANCE_None
  #define ENTRANCE_WalkOut                ENTRANCE_WalkOut
  #define ENTRANCE_CrawlOut               ENTRANCE_CrawlOut
  #define ENTRANCE_ClimbOver1             ENTRANCE_ClimbOver1
  #define ENTRANCE_ClimbOver2             ENTRANCE_ClimbOver2
  #define ENTRANCE_PushTarpAside1         ENTRANCE_PushTarpAside1
  #define ENTRANCE_PushTarpAside2         ENTRANCE_PushTarpAside2
  #define ENTRANCE_PhaseIn                ENTRANCE_PhaseIn
  #define ENTRANCE_PerchedLeft            ENTRANCE_PerchedLeft
  #define ENTRANCE_PerchedRight           ENTRANCE_PerchedRight
  #define ENTRANCE_MAX                    ENTRANCE_MAX
  #define ESpawnStyleType_None            ENTRANCE_None
  #define ESpawnStyleType_WalkOut         ENTRANCE_WalkOut
  #define ESpawnStyleType_CrawlOut        ENTRANCE_CrawlOut
  #define ESpawnStyleType_ClimbOver1      ENTRANCE_ClimbOver1
  #define ESpawnStyleType_ClimbOver2      ENTRANCE_ClimbOver2
  #define ESpawnStyleType_PushTarpAside1  ENTRANCE_PushTarpAside1
  #define ESpawnStyleType_PushTarpAside2  ENTRANCE_PushTarpAside2
  #define ESpawnStyleType_PhaseIn         ENTRANCE_PhaseIn
  #define ESpawnStyleType_PerchedLeft     ENTRANCE_PerchedLeft
  #define ESpawnStyleType_PerchedRight    ENTRANCE_PerchedRight
  #define ESpawnStyleType_MAX             ENTRANCE_MAX
} ESpawnStyleType;
typedef enum EInitialActionType : unsigned char {
  INITIALACTION_None,             // 0
  INITIALACTION_MoveForward,      // 1
  INITIALACTION_MoveToActor,      // 2
  INITIALACTION_MoveToCover,      // 3
  INITIALACTION_Burrow,           // 4
  INITIALACTION_MAX               // 5
  #define INITIALACTION_None              INITIALACTION_None
  #define INITIALACTION_MoveForward       INITIALACTION_MoveForward
  #define INITIALACTION_MoveToActor       INITIALACTION_MoveToActor
  #define INITIALACTION_MoveToCover       INITIALACTION_MoveToCover
  #define INITIALACTION_Burrow            INITIALACTION_Burrow
  #define INITIALACTION_MAX               INITIALACTION_MAX
  #define EInitialActionType_None         INITIALACTION_None
  #define EInitialActionType_MoveForward  INITIALACTION_MoveForward
  #define EInitialActionType_MoveToActor  INITIALACTION_MoveToActor
  #define EInitialActionType_MoveToCover  INITIALACTION_MoveToCover
  #define EInitialActionType_Burrow       INITIALACTION_Burrow
  #define EInitialActionType_MAX          INITIALACTION_MAX
} EInitialActionType;
#define ESpawnStyleType     ESpawnStyleType
#define EInitialActionType  EInitialActionType

/* ---------------------------------------------------------- AWillowDamageArea ! ---------------------------------------------------------- */

typedef enum ECollisionPrimitive {
  CP_StaticMesh,                  // 0
  CP_Cylinder,                    // 1
  CP_Sphere,                      // 2
  CP_MAX                          // 3
  #define CP_StaticMesh                   CP_StaticMesh
  #define CP_Cylinder                     CP_Cylinder
  #define CP_Sphere                       CP_Sphere
  #define CP_MAX                          CP_MAX
  #define ECollisionPrimitive_StaticMesh  CP_StaticMesh
  #define ECollisionPrimitive_Cylinder    CP_Cylinder
  #define ECollisionPrimitive_Sphere      CP_Sphere
  #define ECollisionPrimitive_MAX         CP_MAX
} ECollisionPrimitive;
#define ECollisionPrimitive  ECollisionPrimitive

/* ---------------------------------------------------------- UBehavior_AICloak ! ---------------------------------------------------------- */

typedef enum ECloakOverride : unsigned char {
  CLOAKOVERRIDE_None,             // 0
  CLOAKOVERRIDE_Cloak,            // 1
  CLOAKOVERRIDE_Uncloak,          // 2
  CLOAKOVERRIDE_MAX               // 3
  #define CLOAKOVERRIDE_None      CLOAKOVERRIDE_None
  #define CLOAKOVERRIDE_Cloak     CLOAKOVERRIDE_Cloak
  #define CLOAKOVERRIDE_Uncloak   CLOAKOVERRIDE_Uncloak
  #define CLOAKOVERRIDE_MAX       CLOAKOVERRIDE_MAX
  #define ECloakOverride_None     CLOAKOVERRIDE_None
  #define ECloakOverride_Cloak    CLOAKOVERRIDE_Cloak
  #define ECloakOverride_Uncloak  CLOAKOVERRIDE_Uncloak
  #define ECloakOverride_MAX      CLOAKOVERRIDE_MAX
} ECloakOverride;
#define ECloakOverride  ECloakOverride

/* ---------------------------------------------------------- ALevelStreamingVolume ! ---------------------------------------------------------- */

typedef enum EStreamingVolumeUsage : unsigned char {
  SVB_Loading,                    // 0
  SVB_LoadingAndVisibility,       // 1
  SVB_VisibilityBlockingOnLoad,   // 2
  SVB_BlockingOnLoad,             // 3
  SVB_LoadingNotVisible,          // 4
  SVB_MAX                         // 5
  #define SVB_Loading                                     SVB_Loading
  #define SVB_LoadingAndVisibility                        SVB_LoadingAndVisibility
  #define SVB_VisibilityBlockingOnLoad                    SVB_VisibilityBlockingOnLoad
  #define SVB_BlockingOnLoad                              SVB_BlockingOnLoad
  #define SVB_LoadingNotVisible                           SVB_LoadingNotVisible
  #define SVB_MAX                                         SVB_MAX
  #define EStreamingVolumeUsage_Loading                   SVB_Loading
  #define EStreamingVolumeUsage_LoadingAndVisibility      SVB_LoadingAndVisibility
  #define EStreamingVolumeUsage_VisibilityBlockingOnLoad  SVB_VisibilityBlockingOnLoad
  #define EStreamingVolumeUsage_BlockingOnLoad            SVB_BlockingOnLoad
  #define EStreamingVolumeUsage_LoadingNotVisible         SVB_LoadingNotVisible
  #define EStreamingVolumeUsage_MAX                       SVB_MAX
} EStreamingVolumeUsage;
typedef enum ECurrentVisibility    : unsigned char {
  ECV_NotUpdated,                 // 0
  ECV_Encompasses,                // 1
  ECV_NotEncompasses,             // 2
  ECV_Disabled,                   // 3
  ECV_MAX                         // 4
  #define ECV_NotUpdated                     ECV_NotUpdated
  #define ECV_Encompasses                    ECV_Encompasses
  #define ECV_NotEncompasses                 ECV_NotEncompasses
  #define ECV_Disabled                       ECV_Disabled
  #define ECV_MAX                            ECV_MAX
  #define ECurrentVisibility_NotUpdated      ECV_NotUpdated
  #define ECurrentVisibility_Encompasses     ECV_Encompasses
  #define ECurrentVisibility_NotEncompasses  ECV_NotEncompasses
  #define ECurrentVisibility_Disabled        ECV_Disabled
  #define ECurrentVisibility_MAX             ECV_MAX
} ECurrentVisibility;
#define EStreamingVolumeUsage  EStreamingVolumeUsage
#define ECurrentVisibility     ECurrentVisibility

/* ---------------------------------------------------------- ALevelGridVolume ! ---------------------------------------------------------- */

typedef enum LevelGridCellShape : unsigned char {
  LGCS_Box,                       // 0
  LGCS_Hex,                       // 1
  LGCS_MAX                        // 2
  #define LGCS_Box                LGCS_Box
  #define LGCS_Hex                LGCS_Hex
  #define LGCS_MAX                LGCS_MAX
  #define LevelGridCellShape_Box  LGCS_Box
  #define LevelGridCellShape_Hex  LGCS_Hex
  #define LevelGridCellShape_MAX  LGCS_MAX
} LevelGridCellShape;
#define LevelGridCellShape  LevelGridCellShape

/* ---------------------------------------------------------- URB_ConstraintInstance ! ---------------------------------------------------------- */

typedef enum EConstraintDriveChange {
  CONST_DRIVE_Unchanged,          // 0
  CONST_DRIVE_Enabled,            // 1
  CONST_DRIVE_Disabled,           // 2
  CONST_DRIVE_MAX                 // 3
  #define CONST_DRIVE_Unchanged             CONST_DRIVE_Unchanged
  #define CONST_DRIVE_Enabled               CONST_DRIVE_Enabled
  #define CONST_DRIVE_Disabled              CONST_DRIVE_Disabled
  #define CONST_DRIVE_MAX                   CONST_DRIVE_MAX
  #define EConstraintDriveChange_Unchanged  CONST_DRIVE_Unchanged
  #define EConstraintDriveChange_Enabled    CONST_DRIVE_Enabled
  #define EConstraintDriveChange_Disabled   CONST_DRIVE_Disabled
  #define EConstraintDriveChange_MAX        CONST_DRIVE_MAX
} EConstraintDriveChange;
#define EConstraintDriveChange  EConstraintDriveChange

/* ---------------------------------------------------------- ALiftActionSkill ! ---------------------------------------------------------- */

typedef enum EPhaselockState : unsigned char {
  EPLS_None,                      // 0
  EPLS_Intro,                     // 1
  EPLS_Outro,                     // 2
  EPLS_Locked,                    // 3
  EPLS_Ruin,                      // 4
  EPLS_Subsequence,               // 5
  EPLS_MAX                        // 6
  #define EPLS_None                    EPLS_None
  #define EPLS_Intro                   EPLS_Intro
  #define EPLS_Outro                   EPLS_Outro
  #define EPLS_Locked                  EPLS_Locked
  #define EPLS_Ruin                    EPLS_Ruin
  #define EPLS_Subsequence             EPLS_Subsequence
  #define EPLS_MAX                     EPLS_MAX
  #define EPhaselockState_None         EPLS_None
  #define EPhaselockState_Intro        EPLS_Intro
  #define EPhaselockState_Outro        EPLS_Outro
  #define EPhaselockState_Locked       EPLS_Locked
  #define EPhaselockState_Ruin         EPLS_Ruin
  #define EPhaselockState_Subsequence  EPLS_Subsequence
  #define EPhaselockState_MAX          EPLS_MAX
} EPhaselockState;
#define EPhaselockState  EPhaselockState

/* ---------------------------------------------------------- AWwiseSoundGroup ! ---------------------------------------------------------- */

typedef enum ESoundGroupState : unsigned char {
  SG_NoChange,                    // 0
  SG_Enabled,                     // 1
  SG_Disabled,                    // 2
  SG_MAX                          // 3
  #define SG_NoChange                SG_NoChange
  #define SG_Enabled                 SG_Enabled
  #define SG_Disabled                SG_Disabled
  #define SG_MAX                     SG_MAX
  #define ESoundGroupState_NoChange  SG_NoChange
  #define ESoundGroupState_Enabled   SG_Enabled
  #define ESoundGroupState_Disabled  SG_Disabled
  #define ESoundGroupState_MAX       SG_MAX
} ESoundGroupState;

/* ---------------------------------------------------------- UBehavior_SpawnProjectile ! ---------------------------------------------------------- */

typedef enum ESpawnProjectileOutputLinks  : unsigned char {
  SPOL_Complete,                  // 0
  SPOL_SpawnedProjectile,         // 1
  SPOL_MAX                        // 2
  #define SPOL_Complete                                  SPOL_Complete
  #define SPOL_SpawnedProjectile                         SPOL_SpawnedProjectile
  #define SPOL_MAX                                       SPOL_MAX
  #define ESpawnProjectileOutputLinks_Complete           SPOL_Complete
  #define ESpawnProjectileOutputLinks_SpawnedProjectile  SPOL_SpawnedProjectile
  #define ESpawnProjectileOutputLinks_MAX                SPOL_MAX
} ESpawnProjectileOutputLinks;
typedef enum ESpawnDistributionType       : unsigned char {
  SPSDT_Cone,                     // 0
  SPSDT_Arc,                      // 1
  SPSDT_VerticalArc,              // 2
  SPSDT_MAX                       // 3
  #define SPSDT_Cone                          SPSDT_Cone
  #define SPSDT_Arc                           SPSDT_Arc
  #define SPSDT_VerticalArc                   SPSDT_VerticalArc
  #define SPSDT_MAX                           SPSDT_MAX
  #define ESpawnDistributionType_Cone         SPSDT_Cone
  #define ESpawnDistributionType_Arc          SPSDT_Arc
  #define ESpawnDistributionType_VerticalArc  SPSDT_VerticalArc
  #define ESpawnDistributionType_MAX          SPSDT_MAX
} ESpawnDistributionType;
typedef enum EProjectileSelectionBehavior : unsigned char {
  PROJECTILESELECT_UseSpecified,  // 0
  PROJECTILESELECT_UseCurrent,    // 1
  PROJECTILESELECT_MAX            // 2
  #define PROJECTILESELECT_UseSpecified              PROJECTILESELECT_UseSpecified
  #define PROJECTILESELECT_UseCurrent                PROJECTILESELECT_UseCurrent
  #define PROJECTILESELECT_MAX                       PROJECTILESELECT_MAX
  #define EProjectileSelectionBehavior_UseSpecified  PROJECTILESELECT_UseSpecified
  #define EProjectileSelectionBehavior_UseCurrent    PROJECTILESELECT_UseCurrent
  #define EProjectileSelectionBehavior_MAX           PROJECTILESELECT_MAX
} EProjectileSelectionBehavior;
#define ESpawnProjectileOutputLinks   ESpawnProjectileOutputLinks
#define ESpawnDistributionType        ESpawnDistributionType
#define EProjectileSelectionBehavior  EProjectileSelectionBehavior

/* ---------------------------------------------------------- UBehaviorHelpers ! ---------------------------------------------------------- */

typedef enum EDirectionRelativeToParent : unsigned char {
  DIRECTION_Default,              // 0
  DIRECTION_ParentOrientation,    // 1
  DIRECTION_InverseParentOrientation,// 2
  DIRECTION_ParentVelocity,       // 3
  DIRECTION_InverseParentVelocity,// 4
  DIRECTION_Random,               // 5
  DIRECTION_RandomUpwards,        // 6
  DIRECTION_RandomDownwards,      // 7
  DIRECTION_RandomOnHorizontalPlane,// 8
  DIRECTION_StraightUp,           // 9
  DIRECTION_StraightDown,         // 10
  DIRECTION_StraightTowardTarget, // 11
  DIRECTION_ParentAimDirection,   // 12
  DIRECTION_InverseParentAimDirection,// 13
  DIRECTION_InverseTearOffMomentum,// 14
  DIRECTION_MAX                   // 15
  #define DIRECTION_Default                                     DIRECTION_Default
  #define DIRECTION_ParentOrientation                           DIRECTION_ParentOrientation
  #define DIRECTION_InverseParentOrientation                    DIRECTION_InverseParentOrientation
  #define DIRECTION_ParentVelocity                              DIRECTION_ParentVelocity
  #define DIRECTION_InverseParentVelocity                       DIRECTION_InverseParentVelocity
  #define DIRECTION_Random                                      DIRECTION_Random
  #define DIRECTION_RandomUpwards                               DIRECTION_RandomUpwards
  #define DIRECTION_RandomDownwards                             DIRECTION_RandomDownwards
  #define DIRECTION_RandomOnHorizontalPlane                     DIRECTION_RandomOnHorizontalPlane
  #define DIRECTION_StraightUp                                  DIRECTION_StraightUp
  #define DIRECTION_StraightDown                                DIRECTION_StraightDown
  #define DIRECTION_StraightTowardTarget                        DIRECTION_StraightTowardTarget
  #define DIRECTION_ParentAimDirection                          DIRECTION_ParentAimDirection
  #define DIRECTION_InverseParentAimDirection                   DIRECTION_InverseParentAimDirection
  #define DIRECTION_InverseTearOffMomentum                      DIRECTION_InverseTearOffMomentum
  #define DIRECTION_MAX                                         DIRECTION_MAX
  #define EDirectionRelativeToParent_Default                    DIRECTION_Default
  #define EDirectionRelativeToParent_ParentOrientation          DIRECTION_ParentOrientation
  #define EDirectionRelativeToParent_InverseParentOrientation   DIRECTION_InverseParentOrientation
  #define EDirectionRelativeToParent_ParentVelocity             DIRECTION_ParentVelocity
  #define EDirectionRelativeToParent_InverseParentVelocity      DIRECTION_InverseParentVelocity
  #define EDirectionRelativeToParent_Random                     DIRECTION_Random
  #define EDirectionRelativeToParent_RandomUpwards              DIRECTION_RandomUpwards
  #define EDirectionRelativeToParent_RandomDownwards            DIRECTION_RandomDownwards
  #define EDirectionRelativeToParent_RandomOnHorizontalPlane    DIRECTION_RandomOnHorizontalPlane
  #define EDirectionRelativeToParent_StraightUp                 DIRECTION_StraightUp
  #define EDirectionRelativeToParent_StraightDown               DIRECTION_StraightDown
  #define EDirectionRelativeToParent_StraightTowardTarget       DIRECTION_StraightTowardTarget
  #define EDirectionRelativeToParent_ParentAimDirection         DIRECTION_ParentAimDirection
  #define EDirectionRelativeToParent_InverseParentAimDirection  DIRECTION_InverseParentAimDirection
  #define EDirectionRelativeToParent_InverseTearOffMomentum     DIRECTION_InverseTearOffMomentum
  #define EDirectionRelativeToParent_MAX                        DIRECTION_MAX
} EDirectionRelativeToParent;
typedef enum EFireSocketSelectionMethod : unsigned char {
  FSSM_Increment,                 // 0
  FSSM_Random,                    // 1
  FSSM_RandomLooping,             // 2
  FSSM_MAX                        // 3
  #define FSSM_Increment                            FSSM_Increment
  #define FSSM_Random                               FSSM_Random
  #define FSSM_RandomLooping                        FSSM_RandomLooping
  #define FSSM_MAX                                  FSSM_MAX
  #define EFireSocketSelectionMethod_Increment      FSSM_Increment
  #define EFireSocketSelectionMethod_Random         FSSM_Random
  #define EFireSocketSelectionMethod_RandomLooping  FSSM_RandomLooping
  #define EFireSocketSelectionMethod_MAX            FSSM_MAX
} EFireSocketSelectionMethod;
#define EDirectionRelativeToParent  EDirectionRelativeToParent
#define EFireSocketSelectionMethod  EFireSocketSelectionMethod

/* ---------------------------------------------------------- AGameInfo ! ---------------------------------------------------------- */

typedef enum EStandbyType : unsigned char {
  STDBY_Rx,                       // 0
  STDBY_Tx,                       // 1
  STDBY_BadPing,                  // 2
  STDBY_MAX                       // 3
  #define STDBY_Rx              STDBY_Rx
  #define STDBY_Tx              STDBY_Tx
  #define STDBY_BadPing         STDBY_BadPing
  #define STDBY_MAX             STDBY_MAX
  #define EStandbyType_Rx       STDBY_Rx
  #define EStandbyType_Tx       STDBY_Tx
  #define EStandbyType_BadPing  STDBY_BadPing
  #define EStandbyType_MAX      STDBY_MAX
} EStandbyType;
#define EStandbyType  EStandbyType

/* ---------------------------------------------------------- UWillowStaggerAnimNodeBlend ! ---------------------------------------------------------- */

typedef enum EReferencePointType : unsigned char {
  REFPOINT_TYPE_Bone,             // 0
  REFPOINT_TYPE_Socket,           // 1
  REFPOINT_TYPE_MAX               // 2
  #define REFPOINT_TYPE_Bone          REFPOINT_TYPE_Bone
  #define REFPOINT_TYPE_Socket        REFPOINT_TYPE_Socket
  #define REFPOINT_TYPE_MAX           REFPOINT_TYPE_MAX
  #define EReferencePointType_Bone    REFPOINT_TYPE_Bone
  #define EReferencePointType_Socket  REFPOINT_TYPE_Socket
  #define EReferencePointType_MAX     REFPOINT_TYPE_MAX
} EReferencePointType;
#define EReferencePointType  EReferencePointType

/* ---------------------------------------------------------- UAction_PawnMovementBase ! ---------------------------------------------------------- */

typedef enum EAttributeEvaluationStyle : unsigned char {
  ATTREVALSTYLE_Once,             // 0
  ATTREVALSTYLE_EveryFrame,       // 1
  ATTREVALSTYLE_MAX               // 2
  #define ATTREVALSTYLE_Once                    ATTREVALSTYLE_Once
  #define ATTREVALSTYLE_EveryFrame              ATTREVALSTYLE_EveryFrame
  #define ATTREVALSTYLE_MAX                     ATTREVALSTYLE_MAX
  #define EAttributeEvaluationStyle_Once        ATTREVALSTYLE_Once
  #define EAttributeEvaluationStyle_EveryFrame  ATTREVALSTYLE_EveryFrame
  #define EAttributeEvaluationStyle_MAX         ATTREVALSTYLE_MAX
} EAttributeEvaluationStyle;
#define EAttributeEvaluationStyle  EAttributeEvaluationStyle

/* ---------------------------------------------------------- UWillowLeviathanService ! ---------------------------------------------------------- */

typedef enum EEventId                  : unsigned char {
  EI_PerformanceSample,           // 0
  EI_AdjustResource,              // 1
  EI_AdjustResourceLimit,         // 2
  EI_EnemyKilled,                 // 3
  EI_BulletFired,                 // 4
  EI_LocationPulse,               // 5
  EI_ExperienceGained,            // 6
  EI_Attack,                      // 7
  EI_CharacterCreated,            // 8
  EI_CharacterLoaded,             // 9
  EI_CharacterDeleted,            // 10
  EI_GameplayStart,               // 11
  EI_ExitedGameplay,              // 12
  EI_ChangePlaythrough,           // 13
  EI_NewExcursion,                // 14
  EI_ItemSpawned,                 // 15
  EI_ItemToInventory,             // 16
  EI_ItemFromInventory,           // 17
  EI_ItemMovedInInventory,        // 18
  EI_BlackMarketUpgradePurchased, // 19
  EI_PointsEarned,                // 20
  EI_PointsSpent,                 // 21
  EI_PointsReset,                 // 22
  EI_PlayerCharacterGainedLevel,  // 23
  EI_MinorAction,                 // 24
  EI_RenameCharacter,             // 25
  EI_PartnerJoinedGame,           // 26
  EI_PartnerLeftGame,             // 27
  EI_ResourceDepleted,            // 28
  EI_CharacterDown,               // 29
  EI_CharacterKilled,             // 30
  EI_CharacterRevived,            // 31
  EI_MissionStatusChanged,        // 32
  EI_MissionObjectiveSetActivated,// 33
  EI_MissionObjectiveChanged,     // 34
  EI_DuelStarted,                 // 35
  EI_DeclinedDuel,                // 36
  EI_DuelEnded,                   // 37
  EI_SpawnVehicle,                // 38
  EI_DestroyVehicle,              // 39
  EI_CustomizeCharacter,          // 40
  EI_ChallengeLevelCompleted,     // 41
  EI_DiscoverLocation,            // 42
  EI_TeleportedToVehicle,         // 43
  EI_WieldedWeaponChanged,        // 44
  EI_BeginPlaySession,            // 45
  EI_MissionFastForward,          // 46
  EI_Diagnostic,                  // 47
  EI_MAX                          // 48
  #define EI_PerformanceSample                   EI_PerformanceSample
  #define EI_AdjustResource                      EI_AdjustResource
  #define EI_AdjustResourceLimit                 EI_AdjustResourceLimit
  #define EI_EnemyKilled                         EI_EnemyKilled
  #define EI_BulletFired                         EI_BulletFired
  #define EI_LocationPulse                       EI_LocationPulse
  #define EI_ExperienceGained                    EI_ExperienceGained
  #define EI_Attack                              EI_Attack
  #define EI_CharacterCreated                    EI_CharacterCreated
  #define EI_CharacterLoaded                     EI_CharacterLoaded
  #define EI_CharacterDeleted                    EI_CharacterDeleted
  #define EI_GameplayStart                       EI_GameplayStart
  #define EI_ExitedGameplay                      EI_ExitedGameplay
  #define EI_ChangePlaythrough                   EI_ChangePlaythrough
  #define EI_NewExcursion                        EI_NewExcursion
  #define EI_ItemSpawned                         EI_ItemSpawned
  #define EI_ItemToInventory                     EI_ItemToInventory
  #define EI_ItemFromInventory                   EI_ItemFromInventory
  #define EI_ItemMovedInInventory                EI_ItemMovedInInventory
  #define EI_BlackMarketUpgradePurchased         EI_BlackMarketUpgradePurchased
  #define EI_PointsEarned                        EI_PointsEarned
  #define EI_PointsSpent                         EI_PointsSpent
  #define EI_PointsReset                         EI_PointsReset
  #define EI_PlayerCharacterGainedLevel          EI_PlayerCharacterGainedLevel
  #define EI_MinorAction                         EI_MinorAction
  #define EI_RenameCharacter                     EI_RenameCharacter
  #define EI_PartnerJoinedGame                   EI_PartnerJoinedGame
  #define EI_PartnerLeftGame                     EI_PartnerLeftGame
  #define EI_ResourceDepleted                    EI_ResourceDepleted
  #define EI_CharacterDown                       EI_CharacterDown
  #define EI_CharacterKilled                     EI_CharacterKilled
  #define EI_CharacterRevived                    EI_CharacterRevived
  #define EI_MissionStatusChanged                EI_MissionStatusChanged
  #define EI_MissionObjectiveSetActivated        EI_MissionObjectiveSetActivated
  #define EI_MissionObjectiveChanged             EI_MissionObjectiveChanged
  #define EI_DuelStarted                         EI_DuelStarted
  #define EI_DeclinedDuel                        EI_DeclinedDuel
  #define EI_DuelEnded                           EI_DuelEnded
  #define EI_SpawnVehicle                        EI_SpawnVehicle
  #define EI_DestroyVehicle                      EI_DestroyVehicle
  #define EI_CustomizeCharacter                  EI_CustomizeCharacter
  #define EI_ChallengeLevelCompleted             EI_ChallengeLevelCompleted
  #define EI_DiscoverLocation                    EI_DiscoverLocation
  #define EI_TeleportedToVehicle                 EI_TeleportedToVehicle
  #define EI_WieldedWeaponChanged                EI_WieldedWeaponChanged
  #define EI_BeginPlaySession                    EI_BeginPlaySession
  #define EI_MissionFastForward                  EI_MissionFastForward
  #define EI_Diagnostic                          EI_Diagnostic
  #define EI_MAX                                 EI_MAX
  #define EEventId_PerformanceSample             EI_PerformanceSample
  #define EEventId_AdjustResource                EI_AdjustResource
  #define EEventId_AdjustResourceLimit           EI_AdjustResourceLimit
  #define EEventId_EnemyKilled                   EI_EnemyKilled
  #define EEventId_BulletFired                   EI_BulletFired
  #define EEventId_LocationPulse                 EI_LocationPulse
  #define EEventId_ExperienceGained              EI_ExperienceGained
  #define EEventId_Attack                        EI_Attack
  #define EEventId_CharacterCreated              EI_CharacterCreated
  #define EEventId_CharacterLoaded               EI_CharacterLoaded
  #define EEventId_CharacterDeleted              EI_CharacterDeleted
  #define EEventId_GameplayStart                 EI_GameplayStart
  #define EEventId_ExitedGameplay                EI_ExitedGameplay
  #define EEventId_ChangePlaythrough             EI_ChangePlaythrough
  #define EEventId_NewExcursion                  EI_NewExcursion
  #define EEventId_ItemSpawned                   EI_ItemSpawned
  #define EEventId_ItemToInventory               EI_ItemToInventory
  #define EEventId_ItemFromInventory             EI_ItemFromInventory
  #define EEventId_ItemMovedInInventory          EI_ItemMovedInInventory
  #define EEventId_BlackMarketUpgradePurchased   EI_BlackMarketUpgradePurchased
  #define EEventId_PointsEarned                  EI_PointsEarned
  #define EEventId_PointsSpent                   EI_PointsSpent
  #define EEventId_PointsReset                   EI_PointsReset
  #define EEventId_PlayerCharacterGainedLevel    EI_PlayerCharacterGainedLevel
  #define EEventId_MinorAction                   EI_MinorAction
  #define EEventId_RenameCharacter               EI_RenameCharacter
  #define EEventId_PartnerJoinedGame             EI_PartnerJoinedGame
  #define EEventId_PartnerLeftGame               EI_PartnerLeftGame
  #define EEventId_ResourceDepleted              EI_ResourceDepleted
  #define EEventId_CharacterDown                 EI_CharacterDown
  #define EEventId_CharacterKilled               EI_CharacterKilled
  #define EEventId_CharacterRevived              EI_CharacterRevived
  #define EEventId_MissionStatusChanged          EI_MissionStatusChanged
  #define EEventId_MissionObjectiveSetActivated  EI_MissionObjectiveSetActivated
  #define EEventId_MissionObjectiveChanged       EI_MissionObjectiveChanged
  #define EEventId_DuelStarted                   EI_DuelStarted
  #define EEventId_DeclinedDuel                  EI_DeclinedDuel
  #define EEventId_DuelEnded                     EI_DuelEnded
  #define EEventId_SpawnVehicle                  EI_SpawnVehicle
  #define EEventId_DestroyVehicle                EI_DestroyVehicle
  #define EEventId_CustomizeCharacter            EI_CustomizeCharacter
  #define EEventId_ChallengeLevelCompleted       EI_ChallengeLevelCompleted
  #define EEventId_DiscoverLocation              EI_DiscoverLocation
  #define EEventId_TeleportedToVehicle           EI_TeleportedToVehicle
  #define EEventId_WieldedWeaponChanged          EI_WieldedWeaponChanged
  #define EEventId_BeginPlaySession              EI_BeginPlaySession
  #define EEventId_MissionFastForward            EI_MissionFastForward
  #define EEventId_Diagnostic                    EI_Diagnostic
  #define EEventId_MAX                           EI_MAX
} EEventId;
typedef enum ECharacterKilledReason    : unsigned char {
  ECKR_BledOut,                   // 0
  ECKR_GaveUp,                    // 1
  ECKR_KillVolume,                // 2
  ECKR_OutOfBounds,               // 3
  ECKR_UNUSED_4,                  // 4
  ECKR_UNUSED_5,                  // 5
  ECKR_UNUSED_6,                  // 6
  ECKR_UNUSED_7,                  // 7
  ECKR_UNUSED_8,                  // 8
  ECKR_UNUSED_9,                  // 9
  ECKR_UNUSED_10,                 // 10
  ECKR_CharKillExtension_1,       // 11
  ECKR_CharKillExtension_2,       // 12
  ECKR_CharKillExtension_3,       // 13
  ECKR_CharKillExtension_4,       // 14
  ECKR_CharKillExtension_5,       // 15
  ECKR_MAX                        // 16
  #define ECKR_BledOut                                ECKR_BledOut
  #define ECKR_GaveUp                                 ECKR_GaveUp
  #define ECKR_KillVolume                             ECKR_KillVolume
  #define ECKR_OutOfBounds                            ECKR_OutOfBounds
  #define ECKR_UNUSED_4                               ECKR_UNUSED_4
  #define ECKR_UNUSED_5                               ECKR_UNUSED_5
  #define ECKR_UNUSED_6                               ECKR_UNUSED_6
  #define ECKR_UNUSED_7                               ECKR_UNUSED_7
  #define ECKR_UNUSED_8                               ECKR_UNUSED_8
  #define ECKR_UNUSED_9                               ECKR_UNUSED_9
  #define ECKR_UNUSED_10                              ECKR_UNUSED_10
  #define ECKR_CharKillExtension_1                    ECKR_CharKillExtension_1
  #define ECKR_CharKillExtension_2                    ECKR_CharKillExtension_2
  #define ECKR_CharKillExtension_3                    ECKR_CharKillExtension_3
  #define ECKR_CharKillExtension_4                    ECKR_CharKillExtension_4
  #define ECKR_CharKillExtension_5                    ECKR_CharKillExtension_5
  #define ECKR_MAX                                    ECKR_MAX
  #define ECharacterKilledReason_BledOut              ECKR_BledOut
  #define ECharacterKilledReason_GaveUp               ECKR_GaveUp
  #define ECharacterKilledReason_KillVolume           ECKR_KillVolume
  #define ECharacterKilledReason_OutOfBounds          ECKR_OutOfBounds
  #define ECharacterKilledReason_UNUSED_4             ECKR_UNUSED_4
  #define ECharacterKilledReason_UNUSED_5             ECKR_UNUSED_5
  #define ECharacterKilledReason_UNUSED_6             ECKR_UNUSED_6
  #define ECharacterKilledReason_UNUSED_7             ECKR_UNUSED_7
  #define ECharacterKilledReason_UNUSED_8             ECKR_UNUSED_8
  #define ECharacterKilledReason_UNUSED_9             ECKR_UNUSED_9
  #define ECharacterKilledReason_UNUSED_10            ECKR_UNUSED_10
  #define ECharacterKilledReason_CharKillExtension_1  ECKR_CharKillExtension_1
  #define ECharacterKilledReason_CharKillExtension_2  ECKR_CharKillExtension_2
  #define ECharacterKilledReason_CharKillExtension_3  ECKR_CharKillExtension_3
  #define ECharacterKilledReason_CharKillExtension_4  ECKR_CharKillExtension_4
  #define ECharacterKilledReason_CharKillExtension_5  ECKR_CharKillExtension_5
  #define ECharacterKilledReason_MAX                  ECKR_MAX
} ECharacterKilledReason;
typedef enum EExperienceSource         : unsigned char {
  EES_XPUnknown,                  // 0
  EES_XPCombat,                   // 1
  EES_PlotMissionAward,           // 2
  EES_Discovery,                  // 3
  EES_SideMissionAward,           // 4
  EES_UNUSED_5,                   // 5
  EES_UNUSED_6,                   // 6
  EES_UNUSED_7,                   // 7
  EES_UNUSED_8,                   // 8
  EES_UNUSED_9,                   // 9
  EES_UNUSED_10,                  // 10
  EES_XPExtension_1,              // 11
  EES_XPExtension_2,              // 12
  EES_XPExtension_3,              // 13
  EES_XPExtension_4,              // 14
  EES_XPExtension_5,              // 15
  EES_MAX                         // 16
  #define EES_XPUnknown                       EES_XPUnknown
  #define EES_XPCombat                        EES_XPCombat
  #define EES_PlotMissionAward                EES_PlotMissionAward
  #define EES_Discovery                       EES_Discovery
  #define EES_SideMissionAward                EES_SideMissionAward
  #define EES_UNUSED_5                        EES_UNUSED_5
  #define EES_UNUSED_6                        EES_UNUSED_6
  #define EES_UNUSED_7                        EES_UNUSED_7
  #define EES_UNUSED_8                        EES_UNUSED_8
  #define EES_UNUSED_9                        EES_UNUSED_9
  #define EES_UNUSED_10                       EES_UNUSED_10
  #define EES_XPExtension_1                   EES_XPExtension_1
  #define EES_XPExtension_2                   EES_XPExtension_2
  #define EES_XPExtension_3                   EES_XPExtension_3
  #define EES_XPExtension_4                   EES_XPExtension_4
  #define EES_XPExtension_5                   EES_XPExtension_5
  #define EES_MAX                             EES_MAX
  #define EExperienceSource_XPUnknown         EES_XPUnknown
  #define EExperienceSource_XPCombat          EES_XPCombat
  #define EExperienceSource_PlotMissionAward  EES_PlotMissionAward
  #define EExperienceSource_Discovery         EES_Discovery
  #define EExperienceSource_SideMissionAward  EES_SideMissionAward
  #define EExperienceSource_UNUSED_5          EES_UNUSED_5
  #define EExperienceSource_UNUSED_6          EES_UNUSED_6
  #define EExperienceSource_UNUSED_7          EES_UNUSED_7
  #define EExperienceSource_UNUSED_8          EES_UNUSED_8
  #define EExperienceSource_UNUSED_9          EES_UNUSED_9
  #define EExperienceSource_UNUSED_10         EES_UNUSED_10
  #define EExperienceSource_XPExtension_1     EES_XPExtension_1
  #define EExperienceSource_XPExtension_2     EES_XPExtension_2
  #define EExperienceSource_XPExtension_3     EES_XPExtension_3
  #define EExperienceSource_XPExtension_4     EES_XPExtension_4
  #define EExperienceSource_XPExtension_5     EES_XPExtension_5
  #define EExperienceSource_MAX               EES_MAX
} EExperienceSource;
typedef enum EInventorySlot            : unsigned char {
  EIS_EquippedItem,               // 0
  EIS_QuickSelectUp,              // 1
  EIS_QuickSelectDown,            // 2
  EIS_QuickSelectLeft,            // 3
  EIS_QuickSelectRight,           // 4
  EIS_Backpack,                   // 5
  EIS_UNUSED_6,                   // 6
  EIS_UNUSED_7,                   // 7
  EIS_UNUSED_8,                   // 8
  EIS_UNUSED_9,                   // 9
  EIS_UNUSED_10,                  // 10
  EIS_InvSlotExtension_1,         // 11
  EIS_InvSlotExtension_2,         // 12
  EIS_InvSlotExtension_3,         // 13
  EIS_InvSlotExtension_4,         // 14
  EIS_InvSlotExtension_5,         // 15
  EIS_MAX                         // 16
  #define EIS_EquippedItem                   EIS_EquippedItem
  #define EIS_QuickSelectUp                  EIS_QuickSelectUp
  #define EIS_QuickSelectDown                EIS_QuickSelectDown
  #define EIS_QuickSelectLeft                EIS_QuickSelectLeft
  #define EIS_QuickSelectRight               EIS_QuickSelectRight
  #define EIS_Backpack                       EIS_Backpack
  #define EIS_UNUSED_6                       EIS_UNUSED_6
  #define EIS_UNUSED_7                       EIS_UNUSED_7
  #define EIS_UNUSED_8                       EIS_UNUSED_8
  #define EIS_UNUSED_9                       EIS_UNUSED_9
  #define EIS_UNUSED_10                      EIS_UNUSED_10
  #define EIS_InvSlotExtension_1             EIS_InvSlotExtension_1
  #define EIS_InvSlotExtension_2             EIS_InvSlotExtension_2
  #define EIS_InvSlotExtension_3             EIS_InvSlotExtension_3
  #define EIS_InvSlotExtension_4             EIS_InvSlotExtension_4
  #define EIS_InvSlotExtension_5             EIS_InvSlotExtension_5
  #define EIS_MAX                            EIS_MAX
  #define EInventorySlot_EquippedItem        EIS_EquippedItem
  #define EInventorySlot_QuickSelectUp       EIS_QuickSelectUp
  #define EInventorySlot_QuickSelectDown     EIS_QuickSelectDown
  #define EInventorySlot_QuickSelectLeft     EIS_QuickSelectLeft
  #define EInventorySlot_QuickSelectRight    EIS_QuickSelectRight
  #define EInventorySlot_Backpack            EIS_Backpack
  #define EInventorySlot_UNUSED_6            EIS_UNUSED_6
  #define EInventorySlot_UNUSED_7            EIS_UNUSED_7
  #define EInventorySlot_UNUSED_8            EIS_UNUSED_8
  #define EInventorySlot_UNUSED_9            EIS_UNUSED_9
  #define EInventorySlot_UNUSED_10           EIS_UNUSED_10
  #define EInventorySlot_InvSlotExtension_1  EIS_InvSlotExtension_1
  #define EInventorySlot_InvSlotExtension_2  EIS_InvSlotExtension_2
  #define EInventorySlot_InvSlotExtension_3  EIS_InvSlotExtension_3
  #define EInventorySlot_InvSlotExtension_4  EIS_InvSlotExtension_4
  #define EInventorySlot_InvSlotExtension_5  EIS_InvSlotExtension_5
  #define EInventorySlot_MAX                 EIS_MAX
} EInventorySlot;
typedef enum EItemLocation             : unsigned char {
  EIL_ItemLocUnknown,             // 0
  EIL_Store,                      // 1
  EIL_Ground,                     // 2
  EIL_Award,                      // 3
  EIL_Consumed,                   // 4
  EIL_PlayerDrop,                 // 5
  EIL_Container,                  // 6
  EIL_Bank,                       // 7
  EIL_Stash,                      // 8
  EIL_TradePartner,               // 9
  EIL_Cheat,                      // 10
  EIL_MarketingAward,             // 11
  EIL_BackpackInventory,          // 12
  EIL_Buyback,                    // 13
  EIL_SaveGame,                   // 14
  EIL_Destroyed,                  // 15
  EIL_MAX                         // 16
  #define EIL_ItemLocUnknown               EIL_ItemLocUnknown
  #define EIL_Store                        EIL_Store
  #define EIL_Ground                       EIL_Ground
  #define EIL_Award                        EIL_Award
  #define EIL_Consumed                     EIL_Consumed
  #define EIL_PlayerDrop                   EIL_PlayerDrop
  #define EIL_Container                    EIL_Container
  #define EIL_Bank                         EIL_Bank
  #define EIL_Stash                        EIL_Stash
  #define EIL_TradePartner                 EIL_TradePartner
  #define EIL_Cheat                        EIL_Cheat
  #define EIL_MarketingAward               EIL_MarketingAward
  #define EIL_BackpackInventory            EIL_BackpackInventory
  #define EIL_Buyback                      EIL_Buyback
  #define EIL_SaveGame                     EIL_SaveGame
  #define EIL_Destroyed                    EIL_Destroyed
  #define EIL_MAX                          EIL_MAX
  #define EItemLocation_ItemLocUnknown     EIL_ItemLocUnknown
  #define EItemLocation_Store              EIL_Store
  #define EItemLocation_Ground             EIL_Ground
  #define EItemLocation_Award              EIL_Award
  #define EItemLocation_Consumed           EIL_Consumed
  #define EItemLocation_PlayerDrop         EIL_PlayerDrop
  #define EItemLocation_Container          EIL_Container
  #define EItemLocation_Bank               EIL_Bank
  #define EItemLocation_Stash              EIL_Stash
  #define EItemLocation_TradePartner       EIL_TradePartner
  #define EItemLocation_Cheat              EIL_Cheat
  #define EItemLocation_MarketingAward     EIL_MarketingAward
  #define EItemLocation_BackpackInventory  EIL_BackpackInventory
  #define EItemLocation_Buyback            EIL_Buyback
  #define EItemLocation_SaveGame           EIL_SaveGame
  #define EItemLocation_Destroyed          EIL_Destroyed
  #define EItemLocation_MAX                EIL_MAX
} EItemLocation;
typedef enum EReadiedWeaponState       : unsigned char {
  ERWS_NotReadied,                // 0
  ERWS_MainHand,                  // 1
  ERWS_OffHand,                   // 2
  ERWS_NotWielded,                // 3
  ERWS_MAX                        // 4
  #define ERWS_NotReadied                 ERWS_NotReadied
  #define ERWS_MainHand                   ERWS_MainHand
  #define ERWS_OffHand                    ERWS_OffHand
  #define ERWS_NotWielded                 ERWS_NotWielded
  #define ERWS_MAX                        ERWS_MAX
  #define EReadiedWeaponState_NotReadied  ERWS_NotReadied
  #define EReadiedWeaponState_MainHand    ERWS_MainHand
  #define EReadiedWeaponState_OffHand     ERWS_OffHand
  #define EReadiedWeaponState_NotWielded  ERWS_NotWielded
  #define EReadiedWeaponState_MAX         ERWS_MAX
} EReadiedWeaponState;
typedef enum EMinorActionType          : unsigned char {
  EMAT_DisableTraining,           // 0
  EMAT_UseMouseKeyboard,          // 1
  EMAT_UseController,             // 2
  EMAT_SplitScreenBegin,          // 3
  EMAT_SplitScreenEnd,            // 4
  EMAT_UseVending,                // 5
  EMAT_StoreCompare,              // 6
  EMAT_UNUSED_7,                  // 7
  EMAT_UNUSED_8,                  // 8
  EMAT_UNUSED_9,                  // 9
  EMAT_UNUSED_10,                 // 10
  EMAT_MAExtension_1,             // 11
  EMAT_MAExtension_2,             // 12
  EMAT_MAExtension_3,             // 13
  EMAT_MAExtension_4,             // 14
  EMAT_MAExtension_5,             // 15
  EMAT_MAExtension_6,             // 16
  EMAT_MAExtension_7,             // 17
  EMAT_MAExtension_8,             // 18
  EMAT_MAExtension_9,             // 19
  EMAT_MAExtension_10,            // 20
  EMAT_MAX                        // 21
  #define EMAT_DisableTraining               EMAT_DisableTraining
  #define EMAT_UseMouseKeyboard              EMAT_UseMouseKeyboard
  #define EMAT_UseController                 EMAT_UseController
  #define EMAT_SplitScreenBegin              EMAT_SplitScreenBegin
  #define EMAT_SplitScreenEnd                EMAT_SplitScreenEnd
  #define EMAT_UseVending                    EMAT_UseVending
  #define EMAT_StoreCompare                  EMAT_StoreCompare
  #define EMAT_UNUSED_7                      EMAT_UNUSED_7
  #define EMAT_UNUSED_8                      EMAT_UNUSED_8
  #define EMAT_UNUSED_9                      EMAT_UNUSED_9
  #define EMAT_UNUSED_10                     EMAT_UNUSED_10
  #define EMAT_MAExtension_1                 EMAT_MAExtension_1
  #define EMAT_MAExtension_2                 EMAT_MAExtension_2
  #define EMAT_MAExtension_3                 EMAT_MAExtension_3
  #define EMAT_MAExtension_4                 EMAT_MAExtension_4
  #define EMAT_MAExtension_5                 EMAT_MAExtension_5
  #define EMAT_MAExtension_6                 EMAT_MAExtension_6
  #define EMAT_MAExtension_7                 EMAT_MAExtension_7
  #define EMAT_MAExtension_8                 EMAT_MAExtension_8
  #define EMAT_MAExtension_9                 EMAT_MAExtension_9
  #define EMAT_MAExtension_10                EMAT_MAExtension_10
  #define EMAT_MAX                           EMAT_MAX
  #define EMinorActionType_DisableTraining   EMAT_DisableTraining
  #define EMinorActionType_UseMouseKeyboard  EMAT_UseMouseKeyboard
  #define EMinorActionType_UseController     EMAT_UseController
  #define EMinorActionType_SplitScreenBegin  EMAT_SplitScreenBegin
  #define EMinorActionType_SplitScreenEnd    EMAT_SplitScreenEnd
  #define EMinorActionType_UseVending        EMAT_UseVending
  #define EMinorActionType_StoreCompare      EMAT_StoreCompare
  #define EMinorActionType_UNUSED_7          EMAT_UNUSED_7
  #define EMinorActionType_UNUSED_8          EMAT_UNUSED_8
  #define EMinorActionType_UNUSED_9          EMAT_UNUSED_9
  #define EMinorActionType_UNUSED_10         EMAT_UNUSED_10
  #define EMinorActionType_MAExtension_1     EMAT_MAExtension_1
  #define EMinorActionType_MAExtension_2     EMAT_MAExtension_2
  #define EMinorActionType_MAExtension_3     EMAT_MAExtension_3
  #define EMinorActionType_MAExtension_4     EMAT_MAExtension_4
  #define EMinorActionType_MAExtension_5     EMAT_MAExtension_5
  #define EMinorActionType_MAExtension_6     EMAT_MAExtension_6
  #define EMinorActionType_MAExtension_7     EMAT_MAExtension_7
  #define EMinorActionType_MAExtension_8     EMAT_MAExtension_8
  #define EMinorActionType_MAExtension_9     EMAT_MAExtension_9
  #define EMinorActionType_MAExtension_10    EMAT_MAExtension_10
  #define EMinorActionType_MAX               EMAT_MAX
} EMinorActionType;
typedef enum EMissionFastForwardResult : unsigned char {
  EMFFR_PlayerAccepted,           // 0
  EMFFR_PlayerDeclined,           // 1
  EMFFR_InvalidPrompt,            // 2
  EMFFR_MAX                       // 3
  #define EMFFR_PlayerAccepted                      EMFFR_PlayerAccepted
  #define EMFFR_PlayerDeclined                      EMFFR_PlayerDeclined
  #define EMFFR_InvalidPrompt                       EMFFR_InvalidPrompt
  #define EMFFR_MAX                                 EMFFR_MAX
  #define EMissionFastForwardResult_PlayerAccepted  EMFFR_PlayerAccepted
  #define EMissionFastForwardResult_PlayerDeclined  EMFFR_PlayerDeclined
  #define EMissionFastForwardResult_InvalidPrompt   EMFFR_InvalidPrompt
  #define EMissionFastForwardResult_MAX             EMFFR_MAX
} EMissionFastForwardResult;
typedef enum EPointType                : unsigned char {
  POINTTYPE_Skill,                // 0
  POINTTYPE_BadassToken,          // 1
  POINTTYPE_UNUSED_2,             // 2
  POINTTYPE_UNUSED_3,             // 3
  POINTTYPE_UNUSED_4,             // 4
  POINTTYPE_UNUSED_5,             // 5
  POINTTYPE_UNUSED_6,             // 6
  POINTTYPE_UNUSED_7,             // 7
  POINTTYPE_UNUSED_8,             // 8
  POINTTYPE_UNUSED_9,             // 9
  POINTTYPE_UNUSED_10,            // 10
  POINTTYPE_PTExtension_1,        // 11
  POINTTYPE_PTExtension_2,        // 12
  POINTTYPE_PTExtension_3,        // 13
  POINTTYPE_PTExtension_4,        // 14
  POINTTYPE_PTExtension_5,        // 15
  POINTTYPE_MAX                   // 16
  #define POINTTYPE_Skill           POINTTYPE_Skill
  #define POINTTYPE_BadassToken     POINTTYPE_BadassToken
  #define POINTTYPE_UNUSED_2        POINTTYPE_UNUSED_2
  #define POINTTYPE_UNUSED_3        POINTTYPE_UNUSED_3
  #define POINTTYPE_UNUSED_4        POINTTYPE_UNUSED_4
  #define POINTTYPE_UNUSED_5        POINTTYPE_UNUSED_5
  #define POINTTYPE_UNUSED_6        POINTTYPE_UNUSED_6
  #define POINTTYPE_UNUSED_7        POINTTYPE_UNUSED_7
  #define POINTTYPE_UNUSED_8        POINTTYPE_UNUSED_8
  #define POINTTYPE_UNUSED_9        POINTTYPE_UNUSED_9
  #define POINTTYPE_UNUSED_10       POINTTYPE_UNUSED_10
  #define POINTTYPE_PTExtension_1   POINTTYPE_PTExtension_1
  #define POINTTYPE_PTExtension_2   POINTTYPE_PTExtension_2
  #define POINTTYPE_PTExtension_3   POINTTYPE_PTExtension_3
  #define POINTTYPE_PTExtension_4   POINTTYPE_PTExtension_4
  #define POINTTYPE_PTExtension_5   POINTTYPE_PTExtension_5
  #define POINTTYPE_MAX             POINTTYPE_MAX
  #define EPointType_Skill          POINTTYPE_Skill
  #define EPointType_BadassToken    POINTTYPE_BadassToken
  #define EPointType_UNUSED_2       POINTTYPE_UNUSED_2
  #define EPointType_UNUSED_3       POINTTYPE_UNUSED_3
  #define EPointType_UNUSED_4       POINTTYPE_UNUSED_4
  #define EPointType_UNUSED_5       POINTTYPE_UNUSED_5
  #define EPointType_UNUSED_6       POINTTYPE_UNUSED_6
  #define EPointType_UNUSED_7       POINTTYPE_UNUSED_7
  #define EPointType_UNUSED_8       POINTTYPE_UNUSED_8
  #define EPointType_UNUSED_9       POINTTYPE_UNUSED_9
  #define EPointType_UNUSED_10      POINTTYPE_UNUSED_10
  #define EPointType_PTExtension_1  POINTTYPE_PTExtension_1
  #define EPointType_PTExtension_2  POINTTYPE_PTExtension_2
  #define EPointType_PTExtension_3  POINTTYPE_PTExtension_3
  #define EPointType_PTExtension_4  POINTTYPE_PTExtension_4
  #define EPointType_PTExtension_5  POINTTYPE_PTExtension_5
  #define EPointType_MAX            POINTTYPE_MAX
} EPointType;
typedef enum EReviveReason             : unsigned char {
  REVIVE_KilledEnemy,             // 0
  REVIVE_LeveledUp,               // 1
  REVIVE_PartnerRevived,          // 2
  REVIVE_Respawned,               // 3
  REVIVE_OtherRevived,            // 4
  REVIVE_AutoRevived,             // 5
  REVIVE_UNUSED_6,                // 6
  REVIVE_UNUSED_7,                // 7
  REVIVE_UNUSED_8,                // 8
  REVIVE_UNUSED_9,                // 9
  REVIVE_UNUSED_10,               // 10
  REVIVE_RevReasonExtension_1,    // 11
  REVIVE_RevReasonExtension_2,    // 12
  REVIVE_RevReasonExtension_3,    // 13
  REVIVE_RevReasonExtension_4,    // 14
  REVIVE_RevReasonExtension_5,    // 15
  REVIVE_MAX                      // 16
  #define REVIVE_KilledEnemy                  REVIVE_KilledEnemy
  #define REVIVE_LeveledUp                    REVIVE_LeveledUp
  #define REVIVE_PartnerRevived               REVIVE_PartnerRevived
  #define REVIVE_Respawned                    REVIVE_Respawned
  #define REVIVE_OtherRevived                 REVIVE_OtherRevived
  #define REVIVE_AutoRevived                  REVIVE_AutoRevived
  #define REVIVE_UNUSED_6                     REVIVE_UNUSED_6
  #define REVIVE_UNUSED_7                     REVIVE_UNUSED_7
  #define REVIVE_UNUSED_8                     REVIVE_UNUSED_8
  #define REVIVE_UNUSED_9                     REVIVE_UNUSED_9
  #define REVIVE_UNUSED_10                    REVIVE_UNUSED_10
  #define REVIVE_RevReasonExtension_1         REVIVE_RevReasonExtension_1
  #define REVIVE_RevReasonExtension_2         REVIVE_RevReasonExtension_2
  #define REVIVE_RevReasonExtension_3         REVIVE_RevReasonExtension_3
  #define REVIVE_RevReasonExtension_4         REVIVE_RevReasonExtension_4
  #define REVIVE_RevReasonExtension_5         REVIVE_RevReasonExtension_5
  #define REVIVE_MAX                          REVIVE_MAX
  #define EReviveReason_KilledEnemy           REVIVE_KilledEnemy
  #define EReviveReason_LeveledUp             REVIVE_LeveledUp
  #define EReviveReason_PartnerRevived        REVIVE_PartnerRevived
  #define EReviveReason_Respawned             REVIVE_Respawned
  #define EReviveReason_OtherRevived          REVIVE_OtherRevived
  #define EReviveReason_AutoRevived           REVIVE_AutoRevived
  #define EReviveReason_UNUSED_6              REVIVE_UNUSED_6
  #define EReviveReason_UNUSED_7              REVIVE_UNUSED_7
  #define EReviveReason_UNUSED_8              REVIVE_UNUSED_8
  #define EReviveReason_UNUSED_9              REVIVE_UNUSED_9
  #define EReviveReason_UNUSED_10             REVIVE_UNUSED_10
  #define EReviveReason_RevReasonExtension_1  REVIVE_RevReasonExtension_1
  #define EReviveReason_RevReasonExtension_2  REVIVE_RevReasonExtension_2
  #define EReviveReason_RevReasonExtension_3  REVIVE_RevReasonExtension_3
  #define EReviveReason_RevReasonExtension_4  REVIVE_RevReasonExtension_4
  #define EReviveReason_RevReasonExtension_5  REVIVE_RevReasonExtension_5
  #define EReviveReason_MAX                   REVIVE_MAX
} EReviveReason;
typedef enum EVehicleDestructionReason : unsigned char {
  EVDR_Damage,                    // 0
  EVDR_VehDestOutOfBounds,        // 1
  EVDR_VehDestRespawned,          // 2
  EVDR_UNUSED_3,                  // 3
  EVDR_UNUSED_4,                  // 4
  EVDR_UNUSED_5,                  // 5
  EVDR_UNUSED_6,                  // 6
  EVDR_UNUSED_7,                  // 7
  EVDR_UNUSED_8,                  // 8
  EVDR_UNUSED_9,                  // 9
  EVDR_UNUSED_10,                 // 10
  EVDR_VehDestExtension_1,        // 11
  EVDR_VehDestExtension_2,        // 12
  EVDR_VehDestExtension_3,        // 13
  EVDR_VehDestExtension_4,        // 14
  EVDR_VehDestExtension_5,        // 15
  EVDR_MAX                        // 16
  #define EVDR_Damage                                   EVDR_Damage
  #define EVDR_VehDestOutOfBounds                       EVDR_VehDestOutOfBounds
  #define EVDR_VehDestRespawned                         EVDR_VehDestRespawned
  #define EVDR_UNUSED_3                                 EVDR_UNUSED_3
  #define EVDR_UNUSED_4                                 EVDR_UNUSED_4
  #define EVDR_UNUSED_5                                 EVDR_UNUSED_5
  #define EVDR_UNUSED_6                                 EVDR_UNUSED_6
  #define EVDR_UNUSED_7                                 EVDR_UNUSED_7
  #define EVDR_UNUSED_8                                 EVDR_UNUSED_8
  #define EVDR_UNUSED_9                                 EVDR_UNUSED_9
  #define EVDR_UNUSED_10                                EVDR_UNUSED_10
  #define EVDR_VehDestExtension_1                       EVDR_VehDestExtension_1
  #define EVDR_VehDestExtension_2                       EVDR_VehDestExtension_2
  #define EVDR_VehDestExtension_3                       EVDR_VehDestExtension_3
  #define EVDR_VehDestExtension_4                       EVDR_VehDestExtension_4
  #define EVDR_VehDestExtension_5                       EVDR_VehDestExtension_5
  #define EVDR_MAX                                      EVDR_MAX
  #define EVehicleDestructionReason_Damage              EVDR_Damage
  #define EVehicleDestructionReason_VehDestOutOfBounds  EVDR_VehDestOutOfBounds
  #define EVehicleDestructionReason_VehDestRespawned    EVDR_VehDestRespawned
  #define EVehicleDestructionReason_UNUSED_3            EVDR_UNUSED_3
  #define EVehicleDestructionReason_UNUSED_4            EVDR_UNUSED_4
  #define EVehicleDestructionReason_UNUSED_5            EVDR_UNUSED_5
  #define EVehicleDestructionReason_UNUSED_6            EVDR_UNUSED_6
  #define EVehicleDestructionReason_UNUSED_7            EVDR_UNUSED_7
  #define EVehicleDestructionReason_UNUSED_8            EVDR_UNUSED_8
  #define EVehicleDestructionReason_UNUSED_9            EVDR_UNUSED_9
  #define EVehicleDestructionReason_UNUSED_10           EVDR_UNUSED_10
  #define EVehicleDestructionReason_VehDestExtension_1  EVDR_VehDestExtension_1
  #define EVehicleDestructionReason_VehDestExtension_2  EVDR_VehDestExtension_2
  #define EVehicleDestructionReason_VehDestExtension_3  EVDR_VehDestExtension_3
  #define EVehicleDestructionReason_VehDestExtension_4  EVDR_VehDestExtension_4
  #define EVehicleDestructionReason_VehDestExtension_5  EVDR_VehDestExtension_5
  #define EVehicleDestructionReason_MAX                 EVDR_MAX
} EVehicleDestructionReason;
typedef enum EDeclineDuelReason        : unsigned char {
  DDR_DuelingDisabled,            // 0
  DDR_DuelTimedOut,               // 1
  DDR_MAX                         // 2
  #define DDR_DuelingDisabled                 DDR_DuelingDisabled
  #define DDR_DuelTimedOut                    DDR_DuelTimedOut
  #define DDR_MAX                             DDR_MAX
  #define EDeclineDuelReason_DuelingDisabled  DDR_DuelingDisabled
  #define EDeclineDuelReason_DuelTimedOut     DDR_DuelTimedOut
  #define EDeclineDuelReason_MAX              DDR_MAX
} EDeclineDuelReason;
typedef enum EDuelResult               : unsigned char {
  DR_Won,                         // 0
  DR_Lost,                        // 1
  DR_Drew,                        // 2
  DR_MAX                          // 3
  #define DR_Won            DR_Won
  #define DR_Lost           DR_Lost
  #define DR_Drew           DR_Drew
  #define DR_MAX            DR_MAX
  #define EDuelResult_Won   DR_Won
  #define EDuelResult_Lost  DR_Lost
  #define EDuelResult_Drew  DR_Drew
  #define EDuelResult_MAX   DR_MAX
} EDuelResult;
typedef enum EPartnerJoinLeaveType     : unsigned char {
  PJLT_Host,                      // 0
  PJLT_Client,                    // 1
  PJLT_HostSplit,                 // 2
  PJLT_ClientSplit,               // 3
  PJLT_MAX                        // 4
  #define PJLT_Host                          PJLT_Host
  #define PJLT_Client                        PJLT_Client
  #define PJLT_HostSplit                     PJLT_HostSplit
  #define PJLT_ClientSplit                   PJLT_ClientSplit
  #define PJLT_MAX                           PJLT_MAX
  #define EPartnerJoinLeaveType_Host         PJLT_Host
  #define EPartnerJoinLeaveType_Client       PJLT_Client
  #define EPartnerJoinLeaveType_HostSplit    PJLT_HostSplit
  #define EPartnerJoinLeaveType_ClientSplit  PJLT_ClientSplit
  #define EPartnerJoinLeaveType_MAX          PJLT_MAX
} EPartnerJoinLeaveType;
typedef enum ECustomizationEventType   : unsigned char {
  ECET_CustomizationUnlocked,     // 0
  ECET_CustomizationSelectNewCharacter,// 1
  ECET_CustomizationSelectQuickChange,// 2
  ECET_MAX                        // 3
  #define ECET_CustomizationUnlocked                               ECET_CustomizationUnlocked
  #define ECET_CustomizationSelectNewCharacter                     ECET_CustomizationSelectNewCharacter
  #define ECET_CustomizationSelectQuickChange                      ECET_CustomizationSelectQuickChange
  #define ECET_MAX                                                 ECET_MAX
  #define ECustomizationEventType_CustomizationUnlocked            ECET_CustomizationUnlocked
  #define ECustomizationEventType_CustomizationSelectNewCharacter  ECET_CustomizationSelectNewCharacter
  #define ECustomizationEventType_CustomizationSelectQuickChange   ECET_CustomizationSelectQuickChange
  #define ECustomizationEventType_MAX                              ECET_MAX
} ECustomizationEventType;
typedef enum EDiagnosticEventType      : unsigned char {
  EDET_DetectedLostProfile,       // 0
  EDET_RestoredBadassPoints,      // 1
  EDET_RestoredCustomizations,    // 2
  EDET_ReattemptingProfileRead,   // 3
  EDET_SuccessfulProfileReRead,   // 4
  EDET_MAX                        // 5
  #define EDET_DetectedLostProfile                      EDET_DetectedLostProfile
  #define EDET_RestoredBadassPoints                     EDET_RestoredBadassPoints
  #define EDET_RestoredCustomizations                   EDET_RestoredCustomizations
  #define EDET_ReattemptingProfileRead                  EDET_ReattemptingProfileRead
  #define EDET_SuccessfulProfileReRead                  EDET_SuccessfulProfileReRead
  #define EDET_MAX                                      EDET_MAX
  #define EDiagnosticEventType_DetectedLostProfile      EDET_DetectedLostProfile
  #define EDiagnosticEventType_RestoredBadassPoints     EDET_RestoredBadassPoints
  #define EDiagnosticEventType_RestoredCustomizations   EDET_RestoredCustomizations
  #define EDiagnosticEventType_ReattemptingProfileRead  EDET_ReattemptingProfileRead
  #define EDiagnosticEventType_SuccessfulProfileReRead  EDET_SuccessfulProfileReRead
  #define EDiagnosticEventType_MAX                      EDET_MAX
} EDiagnosticEventType;
typedef enum ESplitScreenConfiguration : unsigned char {
  SSC_Single1P,                   // 0
  SSC_Vertical2P,                 // 1
  SSC_Horizontal2P,               // 2
  SSC_Vertical3P,                 // 3
  SSC_Horizontal3P,               // 4
  SSC_Quad4p,                     // 5
  SSC_MAX                         // 6
  #define SSC_Single1P                            SSC_Single1P
  #define SSC_Vertical2P                          SSC_Vertical2P
  #define SSC_Horizontal2P                        SSC_Horizontal2P
  #define SSC_Vertical3P                          SSC_Vertical3P
  #define SSC_Horizontal3P                        SSC_Horizontal3P
  #define SSC_Quad4p                              SSC_Quad4p
  #define SSC_MAX                                 SSC_MAX
  #define ESplitScreenConfiguration_Single1P      SSC_Single1P
  #define ESplitScreenConfiguration_Vertical2P    SSC_Vertical2P
  #define ESplitScreenConfiguration_Horizontal2P  SSC_Horizontal2P
  #define ESplitScreenConfiguration_Vertical3P    SSC_Vertical3P
  #define ESplitScreenConfiguration_Horizontal3P  SSC_Horizontal3P
  #define ESplitScreenConfiguration_Quad4p        SSC_Quad4p
  #define ESplitScreenConfiguration_MAX           SSC_MAX
} ESplitScreenConfiguration;
#define EEventId                   EEventId
#define ECharacterKilledReason     ECharacterKilledReason
#define EExperienceSource          EExperienceSource
#define EInventorySlot             EInventorySlot
#define EItemLocation              EItemLocation
#define EReadiedWeaponState        EReadiedWeaponState
#define EMinorActionType           EMinorActionType
#define EMissionFastForwardResult  EMissionFastForwardResult
#define EPointType                 EPointType
#define EReviveReason              EReviveReason
#define EVehicleDestructionReason  EVehicleDestructionReason
#define EDeclineDuelReason         EDeclineDuelReason
#define EDuelResult                EDuelResult
#define EPartnerJoinLeaveType      EPartnerJoinLeaveType
#define ECustomizationEventType    ECustomizationEventType
#define EDiagnosticEventType       EDiagnosticEventType
#define ESplitScreenConfiguration  ESplitScreenConfiguration

/* ---------------------------------------------------------- UTerrainMaterial ! ---------------------------------------------------------- */

typedef enum ETerrainMappingType : unsigned char {
  TMT_Auto,                       // 0
  TMT_XY,                         // 1
  TMT_XZ,                         // 2
  TMT_YZ,                         // 3
  TMT_MAX                         // 4
  #define TMT_Auto                  TMT_Auto
  #define TMT_XY                    TMT_XY
  #define TMT_XZ                    TMT_XZ
  #define TMT_YZ                    TMT_YZ
  #define TMT_MAX                   TMT_MAX
  #define ETerrainMappingType_Auto  TMT_Auto
  #define ETerrainMappingType_XY    TMT_XY
  #define ETerrainMappingType_XZ    TMT_XZ
  #define ETerrainMappingType_YZ    TMT_YZ
  #define ETerrainMappingType_MAX   TMT_MAX
} ETerrainMappingType;
#define ETerrainMappingType  ETerrainMappingType

/* ---------------------------------------------------------- ULineData ! ---------------------------------------------------------- */

typedef enum ELineEditMode : unsigned char {
  LEM_Cover,                      // 0
  LEM_SI,                         // 1
  LEM_MAX                         // 2
  #define LEM_Cover            LEM_Cover
  #define LEM_SI               LEM_SI
  #define LEM_MAX              LEM_MAX
  #define ELineEditMode_Cover  LEM_Cover
  #define ELineEditMode_SI     LEM_SI
  #define ELineEditMode_MAX    LEM_MAX
} ELineEditMode;
#define ELineEditMode  ELineEditMode

/* ---------------------------------------------------------- ULineSegment ! ---------------------------------------------------------- */

typedef enum ELineSegmentType     : unsigned char {
  LSTY_Cover,                     // 0
  LSTY_CoverLink,                 // 1
  LSTY_SIZone,                    // 2
  LSTY_SIRetreat,                 // 3
  LSTY_SICombatZone,              // 4
  LSTY_SIStealth,                 // 5
  LSTY_MAX                        // 6
  #define LSTY_Cover                     LSTY_Cover
  #define LSTY_CoverLink                 LSTY_CoverLink
  #define LSTY_SIZone                    LSTY_SIZone
  #define LSTY_SIRetreat                 LSTY_SIRetreat
  #define LSTY_SICombatZone              LSTY_SICombatZone
  #define LSTY_SIStealth                 LSTY_SIStealth
  #define LSTY_MAX                       LSTY_MAX
  #define ELineSegmentType_Cover         LSTY_Cover
  #define ELineSegmentType_CoverLink     LSTY_CoverLink
  #define ELineSegmentType_SIZone        LSTY_SIZone
  #define ELineSegmentType_SIRetreat     LSTY_SIRetreat
  #define ELineSegmentType_SICombatZone  LSTY_SICombatZone
  #define ELineSegmentType_SIStealth     LSTY_SIStealth
  #define ELineSegmentType_MAX           LSTY_MAX
} ELineSegmentType;
typedef enum ELineSegmentMaterial : unsigned char {
  LSM_Default,                    // 0
  LSM_Vulnerable,                 // 1
  LSM_Vantage,                    // 2
  LSM_MAX                         // 3
  #define LSM_Default                      LSM_Default
  #define LSM_Vulnerable                   LSM_Vulnerable
  #define LSM_Vantage                      LSM_Vantage
  #define LSM_MAX                          LSM_MAX
  #define ELineSegmentMaterial_Default     LSM_Default
  #define ELineSegmentMaterial_Vulnerable  LSM_Vulnerable
  #define ELineSegmentMaterial_Vantage     LSM_Vantage
  #define ELineSegmentMaterial_MAX         LSM_MAX
} ELineSegmentMaterial;
#define ELineSegmentType      ELineSegmentType
#define ELineSegmentMaterial  ELineSegmentMaterial

/* ---------------------------------------------------------- UAnimNode_MultiBlendPerBone ! ---------------------------------------------------------- */

typedef enum EWeightCheck : unsigned char {
  EWC_AnimNodeSlotNotPlaying,     // 0
  EWC_MAX                         // 1
  #define EWC_AnimNodeSlotNotPlaying           EWC_AnimNodeSlotNotPlaying
  #define EWC_MAX                              EWC_MAX
  #define EWeightCheck_AnimNodeSlotNotPlaying  EWC_AnimNodeSlotNotPlaying
  #define EWeightCheck_MAX                     EWC_MAX
} EWeightCheck;
typedef enum EBlendType   : unsigned char {
  EBT_ParentBoneSpace,            // 0
  EBT_MeshSpace,                  // 1
  EBT_MAX                         // 2
  #define EBT_ParentBoneSpace         EBT_ParentBoneSpace
  #define EBT_MeshSpace               EBT_MeshSpace
  #define EBT_MAX                     EBT_MAX
  #define EBlendType_ParentBoneSpace  EBT_ParentBoneSpace
  #define EBlendType_MeshSpace        EBT_MeshSpace
  #define EBlendType_MAX              EBT_MAX
} EBlendType;
#define EWeightCheck  EWeightCheck
#define EBlendType    EBlendType

/* ---------------------------------------------------------- UAnimNodeBlendByBase ! ---------------------------------------------------------- */

typedef enum EBaseBlendType : unsigned char {
  BBT_ByActorTag,                 // 0
  BBT_ByActorClass,               // 1
  BBT_MAX                         // 2
  #define BBT_ByActorTag               BBT_ByActorTag
  #define BBT_ByActorClass             BBT_ByActorClass
  #define BBT_MAX                      BBT_MAX
  #define EBaseBlendType_ByActorTag    BBT_ByActorTag
  #define EBaseBlendType_ByActorClass  BBT_ByActorClass
  #define EBaseBlendType_MAX           BBT_MAX
} EBaseBlendType;
#define EBaseBlendType  EBaseBlendType

/* ---------------------------------------------------------- UInterpTrackHeadTracking ! ---------------------------------------------------------- */

typedef enum EHeadTrackingAction : unsigned char {
  EHTA_DisableHeadTracking,       // 0
  EHTA_EnableHeadTracking,        // 1
  EHTA_MAX                        // 2
  #define EHTA_DisableHeadTracking                 EHTA_DisableHeadTracking
  #define EHTA_EnableHeadTracking                  EHTA_EnableHeadTracking
  #define EHTA_MAX                                 EHTA_MAX
  #define EHeadTrackingAction_DisableHeadTracking  EHTA_DisableHeadTracking
  #define EHeadTrackingAction_EnableHeadTracking   EHTA_EnableHeadTracking
  #define EHeadTrackingAction_MAX                  EHTA_MAX
} EHeadTrackingAction;
#define EHeadTrackingAction  EHeadTrackingAction

/* ---------------------------------------------------------- FMemStack ! ---------------------------------------------------------- */

// Enums for specifying memory allocation type.
typedef enum EMemZeroed { MEM_Zeroed = 1 } EMemZeroed;
typedef enum EMemOned   { MEM_Oned   = 1 } EMemOned;
#define MEM_Zeroed  MEM_Zeroed
#define MEM_Oned    MEM_Oned
#define EMemZeroed  EMemZeroed
#define EMemOned    EMemOned

/* ---------------------------------------------------------- UUIDataStore_OnlineStats ! ---------------------------------------------------------- */

typedef enum EStatsFetchType : unsigned char {
  SFT_Player,                     // 0
  SFT_CenteredOnPlayer,           // 1
  SFT_Friends,                    // 2
  SFT_TopRankings,                // 3
  SFT_MAX                         // 4
  #define SFT_Player                        SFT_Player
  #define SFT_CenteredOnPlayer              SFT_CenteredOnPlayer
  #define SFT_Friends                       SFT_Friends
  #define SFT_TopRankings                   SFT_TopRankings
  #define SFT_MAX                           SFT_MAX
  #define EStatsFetchType_Player            SFT_Player
  #define EStatsFetchType_CenteredOnPlayer  SFT_CenteredOnPlayer
  #define EStatsFetchType_Friends           SFT_Friends
  #define EStatsFetchType_TopRankings       SFT_TopRankings
  #define EStatsFetchType_MAX               SFT_MAX
} EStatsFetchType;
#define EStatsFetchType  EStatsFetchType

/* ---------------------------------------------------------- UWillowGFxColiseumOverlayMovie ! ---------------------------------------------------------- */

typedef enum EColiseumLatentScreen : unsigned char {
  ECLS_RoundDefeated,             // 0
  ECLS_RoundSurvived,             // 1
  ECLS_Certificate,               // 2
  ECLS_MAX                        // 3
  #define ECLS_RoundDefeated                   ECLS_RoundDefeated
  #define ECLS_RoundSurvived                   ECLS_RoundSurvived
  #define ECLS_Certificate                     ECLS_Certificate
  #define ECLS_MAX                             ECLS_MAX
  #define EColiseumLatentScreen_RoundDefeated  ECLS_RoundDefeated
  #define EColiseumLatentScreen_RoundSurvived  ECLS_RoundSurvived
  #define EColiseumLatentScreen_Certificate    ECLS_Certificate
  #define EColiseumLatentScreen_MAX            ECLS_MAX
} EColiseumLatentScreen;
#define EColiseumLatentScreen  EColiseumLatentScreen

/* ---------------------------------------------------------- UMissionPopulationAspect ! ---------------------------------------------------------- */

typedef enum EObjectivePopulationActivation  : unsigned char {
  OPA_External,                   // 0
  OPA_AlwaysActive,               // 1
  OPA_ActiveWhenObjectiveActive,  // 2
  OPA_ActiveWhenObjectiveNotComplete,// 3
  OPA_ActiveWhenObjectiveNotInactive,// 4
  OPA_ActiveWhenObjectiveComplete,// 5
  OPA_MAX                         // 6
  #define OPA_External                                                   OPA_External
  #define OPA_AlwaysActive                                               OPA_AlwaysActive
  #define OPA_ActiveWhenObjectiveActive                                  OPA_ActiveWhenObjectiveActive
  #define OPA_ActiveWhenObjectiveNotComplete                             OPA_ActiveWhenObjectiveNotComplete
  #define OPA_ActiveWhenObjectiveNotInactive                             OPA_ActiveWhenObjectiveNotInactive
  #define OPA_ActiveWhenObjectiveComplete                                OPA_ActiveWhenObjectiveComplete
  #define OPA_MAX                                                        OPA_MAX
  #define EObjectivePopulationActivation_External                        OPA_External
  #define EObjectivePopulationActivation_AlwaysActive                    OPA_AlwaysActive
  #define EObjectivePopulationActivation_ActiveWhenObjectiveActive       OPA_ActiveWhenObjectiveActive
  #define EObjectivePopulationActivation_ActiveWhenObjectiveNotComplete  OPA_ActiveWhenObjectiveNotComplete
  #define EObjectivePopulationActivation_ActiveWhenObjectiveNotInactive  OPA_ActiveWhenObjectiveNotInactive
  #define EObjectivePopulationActivation_ActiveWhenObjectiveComplete     OPA_ActiveWhenObjectiveComplete
  #define EObjectivePopulationActivation_MAX                             OPA_MAX
} EObjectivePopulationActivation;
typedef enum EPopulationWaypointSetting      : unsigned char {
  PWS_None,                       // 0
  PWS_MissionObjective,           // 1
  PWS_KillOverride,               // 2
  PWS_All,                        // 3
  PWS_MAX                         // 4
  #define PWS_None                                     PWS_None
  #define PWS_MissionObjective                         PWS_MissionObjective
  #define PWS_KillOverride                             PWS_KillOverride
  #define PWS_All                                      PWS_All
  #define PWS_MAX                                      PWS_MAX
  #define EPopulationWaypointSetting_None              PWS_None
  #define EPopulationWaypointSetting_MissionObjective  PWS_MissionObjective
  #define EPopulationWaypointSetting_KillOverride      PWS_KillOverride
  #define EPopulationWaypointSetting_All               PWS_All
  #define EPopulationWaypointSetting_MAX               PWS_MAX
} EPopulationWaypointSetting;
typedef enum EPopulationWaypointActorSetting : unsigned char {
  PWAS_ALL,                       // 0
  PWAS_SpawnedActors,             // 1
  PWAS_Opportunity,               // 2
  PWAS_OpportunityIfNoActors,     // 3
  PWAS_MAX                        // 4
  #define PWAS_ALL                                               PWAS_ALL
  #define PWAS_SpawnedActors                                     PWAS_SpawnedActors
  #define PWAS_Opportunity                                       PWAS_Opportunity
  #define PWAS_OpportunityIfNoActors                             PWAS_OpportunityIfNoActors
  #define PWAS_MAX                                               PWAS_MAX
  #define EPopulationWaypointActorSetting_ALL                    PWAS_ALL
  #define EPopulationWaypointActorSetting_SpawnedActors          PWAS_SpawnedActors
  #define EPopulationWaypointActorSetting_Opportunity            PWAS_Opportunity
  #define EPopulationWaypointActorSetting_OpportunityIfNoActors  PWAS_OpportunityIfNoActors
  #define EPopulationWaypointActorSetting_MAX                    PWAS_MAX
} EPopulationWaypointActorSetting;
typedef enum EObjectiveUpdateSetting         : unsigned char {
  OUS_None,                       // 0
  OUS_MissionObjectiveOnDeath,    // 1
  OUS_OverrideObjectiveOnDeath,   // 2
  OUS_MissionAndOverrideObjectiveOnDeath,// 3
  OUS_MissionObjectiveOnStatAdd,  // 4
  OUS_MissionObjectiveOnStatAddRemove,// 5
  OUS_OverrideObjectiveOnStatAdd, // 6
  OUS_OverrideObjectiveOnStatAddRemove,// 7
  OUS_MissionObjectiveOnAllDead,  // 8
  OUS_OverrideObjectiveOnAllDead, // 9
  OUS_MissionAndOverrideObjectiveOnAllDead,// 10
  OUS_MAX                         // 11
  #define OUS_None                                                      OUS_None
  #define OUS_MissionObjectiveOnDeath                                   OUS_MissionObjectiveOnDeath
  #define OUS_OverrideObjectiveOnDeath                                  OUS_OverrideObjectiveOnDeath
  #define OUS_MissionAndOverrideObjectiveOnDeath                        OUS_MissionAndOverrideObjectiveOnDeath
  #define OUS_MissionObjectiveOnStatAdd                                 OUS_MissionObjectiveOnStatAdd
  #define OUS_MissionObjectiveOnStatAddRemove                           OUS_MissionObjectiveOnStatAddRemove
  #define OUS_OverrideObjectiveOnStatAdd                                OUS_OverrideObjectiveOnStatAdd
  #define OUS_OverrideObjectiveOnStatAddRemove                          OUS_OverrideObjectiveOnStatAddRemove
  #define OUS_MissionObjectiveOnAllDead                                 OUS_MissionObjectiveOnAllDead
  #define OUS_OverrideObjectiveOnAllDead                                OUS_OverrideObjectiveOnAllDead
  #define OUS_MissionAndOverrideObjectiveOnAllDead                      OUS_MissionAndOverrideObjectiveOnAllDead
  #define OUS_MAX                                                       OUS_MAX
  #define EObjectiveUpdateSetting_None                                  OUS_None
  #define EObjectiveUpdateSetting_MissionObjectiveOnDeath               OUS_MissionObjectiveOnDeath
  #define EObjectiveUpdateSetting_OverrideObjectiveOnDeath              OUS_OverrideObjectiveOnDeath
  #define EObjectiveUpdateSetting_MissionAndOverrideObjectiveOnDeath    OUS_MissionAndOverrideObjectiveOnDeath
  #define EObjectiveUpdateSetting_MissionObjectiveOnStatAdd             OUS_MissionObjectiveOnStatAdd
  #define EObjectiveUpdateSetting_MissionObjectiveOnStatAddRemove       OUS_MissionObjectiveOnStatAddRemove
  #define EObjectiveUpdateSetting_OverrideObjectiveOnStatAdd            OUS_OverrideObjectiveOnStatAdd
  #define EObjectiveUpdateSetting_OverrideObjectiveOnStatAddRemove      OUS_OverrideObjectiveOnStatAddRemove
  #define EObjectiveUpdateSetting_MissionObjectiveOnAllDead             OUS_MissionObjectiveOnAllDead
  #define EObjectiveUpdateSetting_OverrideObjectiveOnAllDead            OUS_OverrideObjectiveOnAllDead
  #define EObjectiveUpdateSetting_MissionAndOverrideObjectiveOnAllDead  OUS_MissionAndOverrideObjectiveOnAllDead
  #define EObjectiveUpdateSetting_MAX                                   OUS_MAX
} EObjectiveUpdateSetting;
#define EObjectivePopulationActivation   EObjectivePopulationActivation
#define EPopulationWaypointSetting       EPopulationWaypointSetting
#define EPopulationWaypointActorSetting  EPopulationWaypointActorSetting
#define EObjectiveUpdateSetting          EObjectiveUpdateSetting

/* ---------------------------------------------------------- UCompoundExpressionEvaluator ! ---------------------------------------------------------- */

typedef enum ECExpressionOperatorType : unsigned char {
  CEOP_Or,                        // 0
  CEOP_And,                       // 1
  CEOP_MAX                        // 2
  #define CEOP_Or                       CEOP_Or
  #define CEOP_And                      CEOP_And
  #define CEOP_MAX                      CEOP_MAX
  #define ECExpressionOperatorType_Or   CEOP_Or
  #define ECExpressionOperatorType_And  CEOP_And
  #define ECExpressionOperatorType_MAX  CEOP_MAX
} ECExpressionOperatorType;
#define ECExpressionOperatorType  ECExpressionOperatorType

/* ---------------------------------------------------------- UAIResourceExpressionEvaluator ! ---------------------------------------------------------- */

typedef enum AIResourceOption : unsigned char {
  AIResourceOption_On,            // 0
  AIResourceOption_Off,           // 1
  AIResourceOption_MAX            // 2
  #define AIResourceOption_On   AIResourceOption_On
  #define AIResourceOption_Off  AIResourceOption_Off
  #define AIResourceOption_MAX  AIResourceOption_MAX
} AIResourceOption;
#define AIResourceOption  AIResourceOption

/* ---------------------------------------------------------- UWillowNavigationHandle ! ---------------------------------------------------------- */

typedef enum PathFixMode : unsigned char {
  PathFix_None,                   // 0
  PathFix_Waiting,                // 1
  PathFix_Moving,                 // 2
  PathFix_Lerping,                // 3
  PathFix_Failed,                 // 4
  PathFix_MAX                     // 5
  #define PathFix_None         PathFix_None
  #define PathFix_Waiting      PathFix_Waiting
  #define PathFix_Moving       PathFix_Moving
  #define PathFix_Lerping      PathFix_Lerping
  #define PathFix_Failed       PathFix_Failed
  #define PathFix_MAX          PathFix_MAX
  #define PathFixMode_None     PathFix_None
  #define PathFixMode_Waiting  PathFix_Waiting
  #define PathFixMode_Moving   PathFix_Moving
  #define PathFixMode_Lerping  PathFix_Lerping
  #define PathFixMode_Failed   PathFix_Failed
  #define PathFixMode_MAX      PathFix_MAX
} PathFixMode;
typedef enum EFlightMode : unsigned char {
  FlightMode_None,                // 0
  FlightMode_Flying,              // 1
  FlightMode_Stuck,               // 2
  FlightMode_Landing,             // 3
  FlightMode_Walking,             // 4
  FlightMode_MAX                  // 5
  #define FlightMode_None      FlightMode_None
  #define FlightMode_Flying    FlightMode_Flying
  #define FlightMode_Stuck     FlightMode_Stuck
  #define FlightMode_Landing   FlightMode_Landing
  #define FlightMode_Walking   FlightMode_Walking
  #define FlightMode_MAX       FlightMode_MAX
  #define EFlightMode_None     FlightMode_None
  #define EFlightMode_Flying   FlightMode_Flying
  #define EFlightMode_Stuck    FlightMode_Stuck
  #define EFlightMode_Landing  FlightMode_Landing
  #define EFlightMode_Walking  FlightMode_Walking
  #define EFlightMode_MAX      FlightMode_MAX
} EFlightMode;
#define PathFixMode  PathFixMode
#define EFlightMode  EFlightMode

/* ---------------------------------------------------------- UTextureFlipBook ! ---------------------------------------------------------- */

typedef enum TextureFlipBookMethod : unsigned char {
  TFBM_UL_ROW,                    // 0
  TFBM_UL_COL,                    // 1
  TFBM_UR_ROW,                    // 2
  TFBM_UR_COL,                    // 3
  TFBM_LL_ROW,                    // 4
  TFBM_LL_COL,                    // 5
  TFBM_LR_ROW,                    // 6
  TFBM_LR_COL,                    // 7
  TFBM_RANDOM,                    // 8
  TFBM_MAX                        // 9
  #define TFBM_UL_ROW                   TFBM_UL_ROW
  #define TFBM_UL_COL                   TFBM_UL_COL
  #define TFBM_UR_ROW                   TFBM_UR_ROW
  #define TFBM_UR_COL                   TFBM_UR_COL
  #define TFBM_LL_ROW                   TFBM_LL_ROW
  #define TFBM_LL_COL                   TFBM_LL_COL
  #define TFBM_LR_ROW                   TFBM_LR_ROW
  #define TFBM_LR_COL                   TFBM_LR_COL
  #define TFBM_RANDOM                   TFBM_RANDOM
  #define TFBM_MAX                      TFBM_MAX
  #define TextureFlipBookMethod_UL_ROW  TFBM_UL_ROW
  #define TextureFlipBookMethod_UL_COL  TFBM_UL_COL
  #define TextureFlipBookMethod_UR_ROW  TFBM_UR_ROW
  #define TextureFlipBookMethod_UR_COL  TFBM_UR_COL
  #define TextureFlipBookMethod_LL_ROW  TFBM_LL_ROW
  #define TextureFlipBookMethod_LL_COL  TFBM_LL_COL
  #define TextureFlipBookMethod_LR_ROW  TFBM_LR_ROW
  #define TextureFlipBookMethod_LR_COL  TFBM_LR_COL
  #define TextureFlipBookMethod_RANDOM  TFBM_RANDOM
  #define TextureFlipBookMethod_MAX     TFBM_MAX
} TextureFlipBookMethod;
#define TextureFlipBookMethod  TextureFlipBookMethod

/* ---------------------------------------------------------- UDistributionFloat ! ---------------------------------------------------------- */

typedef enum EDistributionVectorLockFlags   : unsigned char {
  EDVLF_None,                     // 0
  EDVLF_XY,                       // 1
  EDVLF_XZ,                       // 2
  EDVLF_YZ,                       // 3
  EDVLF_XYZ,                      // 4
  EDVLF_MAX                       // 5
  #define EDVLF_None                         EDVLF_None
  #define EDVLF_XY                           EDVLF_XY
  #define EDVLF_XZ                           EDVLF_XZ
  #define EDVLF_YZ                           EDVLF_YZ
  #define EDVLF_XYZ                          EDVLF_XYZ
  #define EDVLF_MAX                          EDVLF_MAX
  #define EDistributionVectorLockFlags_None  EDVLF_None
  #define EDistributionVectorLockFlags_XY    EDVLF_XY
  #define EDistributionVectorLockFlags_XZ    EDVLF_XZ
  #define EDistributionVectorLockFlags_YZ    EDVLF_YZ
  #define EDistributionVectorLockFlags_XYZ   EDVLF_XYZ
  #define EDistributionVectorLockFlags_MAX   EDVLF_MAX
} EDistributionVectorLockFlags;
typedef enum EDistributionVectorMirrorFlags : unsigned char {
  EDVMF_Same,                     // 0
  EDVMF_Different,                // 1
  EDVMF_Mirror,                   // 2
  EDVMF_MAX                       // 3
  #define EDVMF_Same                                EDVMF_Same
  #define EDVMF_Different                           EDVMF_Different
  #define EDVMF_Mirror                              EDVMF_Mirror
  #define EDVMF_MAX                                 EDVMF_MAX
  #define EDistributionVectorMirrorFlags_Same       EDVMF_Same
  #define EDistributionVectorMirrorFlags_Different  EDVMF_Different
  #define EDistributionVectorMirrorFlags_Mirror     EDVMF_Mirror
  #define EDistributionVectorMirrorFlags_MAX        EDVMF_MAX
} EDistributionVectorMirrorFlags;
#define EDistributionVectorLockFlags    EDistributionVectorLockFlags
#define EDistributionVectorMirrorFlags  EDistributionVectorMirrorFlags

/* ---------------------------------------------------------- UAkDialogueEvent ! ---------------------------------------------------------- */

typedef enum EDynamicDialogueArgument : unsigned char {
  DYNAMICDIALOGUEARGUMENT_None,   // 0
  DYNAMICDIALOGUEARGUMENT_SpeakerName,// 1
  DYNAMICDIALOGUEARGUMENT_Stance, // 2
  DYNAMICDIALOGUEARGUMENT_TargetName,// 3
  DYNAMICDIALOGUEARGUMENT_MAX     // 4
  #define DYNAMICDIALOGUEARGUMENT_None          DYNAMICDIALOGUEARGUMENT_None
  #define DYNAMICDIALOGUEARGUMENT_SpeakerName   DYNAMICDIALOGUEARGUMENT_SpeakerName
  #define DYNAMICDIALOGUEARGUMENT_Stance        DYNAMICDIALOGUEARGUMENT_Stance
  #define DYNAMICDIALOGUEARGUMENT_TargetName    DYNAMICDIALOGUEARGUMENT_TargetName
  #define DYNAMICDIALOGUEARGUMENT_MAX           DYNAMICDIALOGUEARGUMENT_MAX
  #define EDynamicDialogueArgument_None         DYNAMICDIALOGUEARGUMENT_None
  #define EDynamicDialogueArgument_SpeakerName  DYNAMICDIALOGUEARGUMENT_SpeakerName
  #define EDynamicDialogueArgument_Stance       DYNAMICDIALOGUEARGUMENT_Stance
  #define EDynamicDialogueArgument_TargetName   DYNAMICDIALOGUEARGUMENT_TargetName
  #define EDynamicDialogueArgument_MAX          DYNAMICDIALOGUEARGUMENT_MAX
} EDynamicDialogueArgument;
#define EDynamicDialogueArgument  EDynamicDialogueArgument

/* ---------------------------------------------------------- UAction_GenericAttack ! ---------------------------------------------------------- */

typedef enum EAttackType     : unsigned char {
  Attack_Far,                     // 0
  Attack_Close,                   // 1
  Attack_InPlace,                 // 2
  Attack_MAX                      // 3
  #define Attack_Far           Attack_Far
  #define Attack_Close         Attack_Close
  #define Attack_InPlace       Attack_InPlace
  #define Attack_MAX           Attack_MAX
  #define EAttackType_Far      Attack_Far
  #define EAttackType_Close    Attack_Close
  #define EAttackType_InPlace  Attack_InPlace
  #define EAttackType_MAX      Attack_MAX
} EAttackType;
typedef enum EAttackValidity : unsigned char {
  Validity_None,                  // 0
  Validity_Partial,               // 1
  Validity_Full,                  // 2
  Validity_MAX                    // 3
  #define Validity_None            Validity_None
  #define Validity_Partial         Validity_Partial
  #define Validity_Full            Validity_Full
  #define Validity_MAX             Validity_MAX
  #define EAttackValidity_None     Validity_None
  #define EAttackValidity_Partial  Validity_Partial
  #define EAttackValidity_Full     Validity_Full
  #define EAttackValidity_MAX      Validity_MAX
} EAttackValidity;
#define EAttackType      EAttackType
#define EAttackValidity  EAttackValidity

/* ---------------------------------------------------------- UAction_AnimAttack ! ---------------------------------------------------------- */

typedef enum EAimType : unsigned char {
  AimType_HoldStill,              // 0
  AimType_FollowTarget,           // 1
  AimType_AlignToTarget,          // 2
  AimType_MAX                     // 3
  #define AimType_HoldStill       AimType_HoldStill
  #define AimType_FollowTarget    AimType_FollowTarget
  #define AimType_AlignToTarget   AimType_AlignToTarget
  #define AimType_MAX             AimType_MAX
  #define EAimType_HoldStill      AimType_HoldStill
  #define EAimType_FollowTarget   AimType_FollowTarget
  #define EAimType_AlignToTarget  AimType_AlignToTarget
  #define EAimType_MAX            AimType_MAX
} EAimType;
#define EAimType  EAimType

/* ---------------------------------------------------------- UAction_BasicAttack ! ---------------------------------------------------------- */

typedef enum ERangeType : unsigned char {
  Range_None,                     // 0
  Range_Zone,                     // 1
  Range_Numbers,                  // 2
  Range_MAX                       // 3
  #define Range_None          Range_None
  #define Range_Zone          Range_Zone
  #define Range_Numbers       Range_Numbers
  #define Range_MAX           Range_MAX
  #define ERangeType_None     Range_None
  #define ERangeType_Zone     Range_Zone
  #define ERangeType_Numbers  Range_Numbers
  #define ERangeType_MAX      Range_MAX
} ERangeType;
#define ERangeType  ERangeType

/* ---------------------------------------------------------- UAction_SwoopAttack ! ---------------------------------------------------------- */

typedef enum ESwoopOffset : unsigned char {
  SwoopOffset_Left,               // 0
  SwoopOffset_Right,              // 1
  SwoopOffset_Random,             // 2
  SwoopOffset_MAX                 // 3
  #define SwoopOffset_Left     SwoopOffset_Left
  #define SwoopOffset_Right    SwoopOffset_Right
  #define SwoopOffset_Random   SwoopOffset_Random
  #define SwoopOffset_MAX      SwoopOffset_MAX
  #define ESwoopOffset_Left    SwoopOffset_Left
  #define ESwoopOffset_Right   SwoopOffset_Right
  #define ESwoopOffset_Random  SwoopOffset_Random
  #define ESwoopOffset_MAX     SwoopOffset_MAX
} ESwoopOffset;
#define ESwoopOffset  ESwoopOffset

/* ---------------------------------------------------------- ULightShaftComponent ! ---------------------------------------------------------- */

typedef enum ELightShaftType : unsigned char {
  LightShaft_Directional,         // 0
  LightShaft_Spot,                // 1
  LightShaft_Point,               // 2
  LightShaft_MAX                  // 3
  #define LightShaft_Directional       LightShaft_Directional
  #define LightShaft_Spot              LightShaft_Spot
  #define LightShaft_Point             LightShaft_Point
  #define LightShaft_MAX               LightShaft_MAX
  #define ELightShaftType_Directional  LightShaft_Directional
  #define ELightShaftType_Spot         LightShaft_Spot
  #define ELightShaftType_Point        LightShaft_Point
  #define ELightShaftType_MAX          LightShaft_MAX
} ELightShaftType;
#define ELightShaftType  ELightShaftType

/* ---------------------------------------------------------- UControlChannel ---------------------------------------------------------- */

/** maximum size of additional buffer if this is exceeded as well, we kill the connection */
enum { MAX_QUEUED_CONTROL_MESSAGES = 256 };

/* ---------------------------------------------------------- ABehaviorVolume ! ---------------------------------------------------------- */

typedef enum EBehaviorVolumeAction : unsigned char {
  EBVA_Entry,                     // 0
  EBVA_Exit,                      // 1
  EBVA_Shoot,                     // 2
  EBVA_MAX                        // 3
  #define EBVA_Entry                   EBVA_Entry
  #define EBVA_Exit                    EBVA_Exit
  #define EBVA_Shoot                   EBVA_Shoot
  #define EBVA_MAX                     EBVA_MAX
  #define EBehaviorVolumeAction_Entry  EBVA_Entry
  #define EBehaviorVolumeAction_Exit   EBVA_Exit
  #define EBehaviorVolumeAction_Shoot  EBVA_Shoot
  #define EBehaviorVolumeAction_MAX    EBVA_MAX
} EBehaviorVolumeAction;
#define EBehaviorVolumeAction  EBehaviorVolumeAction

/* ---------------------------------------------------------- UPopulationFactoryWillowVehicle ! ---------------------------------------------------------- */

typedef enum WillowVehicleRoles    : unsigned char {
  WILLOWVEHICLEROLE_Driver,       // 0
  WILLOWVEHICLEROLE_Gunner,       // 1
  WILLOWVEHICLEROLE_SideClinger,  // 2
  WILLOWVEHICLEROLE_MAX           // 3
  #define WILLOWVEHICLEROLE_Driver        WILLOWVEHICLEROLE_Driver
  #define WILLOWVEHICLEROLE_Gunner        WILLOWVEHICLEROLE_Gunner
  #define WILLOWVEHICLEROLE_SideClinger   WILLOWVEHICLEROLE_SideClinger
  #define WILLOWVEHICLEROLE_MAX           WILLOWVEHICLEROLE_MAX
  #define WillowVehicleRoles_Driver       WILLOWVEHICLEROLE_Driver
  #define WillowVehicleRoles_Gunner       WILLOWVEHICLEROLE_Gunner
  #define WillowVehicleRoles_SideClinger  WILLOWVEHICLEROLE_SideClinger
  #define WillowVehicleRoles_MAX          WILLOWVEHICLEROLE_MAX
} WillowVehicleRoles;
typedef enum EVehicleBalanceOption : unsigned char {
  VEHICLEBALANCE_ForPlayers,      // 0
  VEHICLEBALANCE_ForEnemyAI,      // 1
  VEHICLEBALANCE_MAX              // 2
  #define VEHICLEBALANCE_ForPlayers         VEHICLEBALANCE_ForPlayers
  #define VEHICLEBALANCE_ForEnemyAI         VEHICLEBALANCE_ForEnemyAI
  #define VEHICLEBALANCE_MAX                VEHICLEBALANCE_MAX
  #define EVehicleBalanceOption_ForPlayers  VEHICLEBALANCE_ForPlayers
  #define EVehicleBalanceOption_ForEnemyAI  VEHICLEBALANCE_ForEnemyAI
  #define EVehicleBalanceOption_MAX         VEHICLEBALANCE_MAX
} EVehicleBalanceOption;
#define WillowVehicleRoles     WillowVehicleRoles
#define EVehicleBalanceOption  EVehicleBalanceOption
