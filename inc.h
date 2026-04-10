#pragma once


#include "macro_helpers.h"
#include "enums.h"
#include "constants.h"


//
// UnrealScript intrinsic return value declaration.
//
#define RESULT_DECL void *const Result

typedef void *FPointer;

#define __int8  char
#define __int16 short
#define __int32 long
#define __int64 long long int

typedef unsigned __int8   BYTE;
typedef unsigned __int16  WORD;
typedef unsigned __int32  DWORD;
typedef unsigned __int64  QWORD;

/* 8-bit  signed. */
typedef	signed __int8	 SBYTE;  
/* 16-bit signed. */
typedef signed __int16 SWORD;  

typedef DWORD SIZE_T;

typedef void *HANDLE;

typedef __WCHAR_TYPE__  TCHAR;
#ifndef _WCHAR_T_DEFINED
typedef unsigned __int16 wchar_t;
#endif

typedef __int32  INT;
typedef DWORD    UINT;

/** Name index. */
typedef INT NAME_INDEX;

typedef DWORD  BITFIELD;

typedef INT  BOOL;
// typedef UINT UBOOL;

typedef float   FLOAT;
typedef double  DOUBLE;

typedef FLOAT LOOKUPVALUE;

/// Integer large enough to hold a pointer.
typedef INT  PTRINT;

/// Unsigned integer large enough to hold a pointer
typedef UINT  UPTRINT;

typedef QWORD  EObjectFlags;
typedef DWORD  EExportFlags;

/*-----------------------------------------------------------------------------
	ERenameFlags.

	Options to the UObject::Rename function, bit flag
-----------------------------------------------------------------------------*/
typedef DWORD  ERenameFlags;

#define REN_None				(0x0000)
#define REN_ForceNoResetLoaders	(0x0001) // Rename won't call ResetLoaders - most likely you should never specify this option (unless you are renaming a UPackage possibly)
#define REN_Test				(0x0002) // Just test to make sure that the rename is guaranteed to succeed if an non test rename immediately follows
#define REN_DoNotDirty			(0x0004) // Indicates that the object (and new outer) should not be dirtied.
#define REN_KeepNetIndex		(0x0008) // Don't clear the NetIndex of the renamed object and objects it contains when the Outer changes - not supported when GIsGame



// Aspect ratio constants
const FLOAT AspectRatio4x3 = 1.33333f;
const FLOAT AspectRatio5x4 = 1.25f;
const FLOAT AspectRatio16x9 = 1.77778f;
const FLOAT InvAspectRatio4x3 = 0.75f;
const FLOAT InvAspectRatio5x4 = 0.8f;
const FLOAT InvAspectRatio16x9 = 0.56249f;

#if CONSOLE
	// Use a modest bucket count on consoles
	static const UINT NameHashBucketCount = 4096;
#else
	// On PC platform we use a large number of name hash buckets to accommodate the editor's
	// use of FNames to store asset path and content tags
	static const UINT NameHashBucketCount = 65536;
#endif

/**
 * a typedef for the size of an UnrealScript variable; typedef'd because this value must be synchronized between the
 * script compiler and the script VM
 */
typedef WORD VariableSizeType;


/**
 * a typedef for the number of bytes to skip-over when certain expressions are evaluated by the VM (e.g. context expressions that resolve to NULL, etc.)
 * typedef'd because this type must be synchronized between the script compiler and the script VM
 */
typedef WORD CodeSkipSizeType;

/// /**
///  * Index into a ULnker's ImportMap or ExportMap.
///  * Values greater than zero indicate that this is an index into the ExportMap.  The
///  * actual array index will be (PACKAGE_INDEX - 1).
///  *
///  * Values less than zero indicate that this is an index into the ImportMap. The actual
///  * array index will be (-PACKAGE_INDEX - 1)
///  */
typedef INT PACKAGE_INDEX;

typedef char ANSICHAR;

typedef DWORD EShowFlags;

STRUCT(FSetElementId) {
  INT Index;
};
_DECL_FALIGNED_ELEMENTS(FSetElementId);
_DECL_FALIGNED_ELEMENTS(DWORD);

STRUCT(FScriptContainerElement)
{};

STRUCT(FHeapAllocator_ForAnyElement) {
  FScriptContainerElement *Data;
};

_DECL_TTYPE_COMPATIBILITY_BYTES(DWORD);
_DECL_TINLINE_ALLOCATOR(4, DWORD);
_DECL_TTYPE_COMPATIBILITY_BYTES(FSetElementId);
_DECL_TINLINE_ALLOCATOR(1, FSetElementId);

typedef struct TBitArray {
  TInlineAllocator_4_DWORD Super;
  INT NumBits;
	INT MaxBits;
} TBitArray;


/* ---------------------------------------------------------- UObject ---------------------------------------------------------- */

_(UObject);
_(FInterpCurvePointFloat);
_(FInterpCurvePointVector);
_(FInterpCurveFloat);
_(FInterpCurveVector);
_(FFlag);
_(FSmartVector);
_(FIntPoint);
_(FNameBasedObjectPath);
_(FQWord);
_(FDouble);
_(FOctreeElementId);
_(FChunkedList_Mirror);
_(FArray_Mirror);
_(FStableArray_Mirror);

_(FRenderCommandFence);

/* ---------------------------------------------------------- FLightingChannelContainer ---------------------------------------------------------- */

_(FLightingChannelContainer);

_(FPackedNormal);

/* ---------------------------------------------------------- FScriptDelegate ---------------------------------------------------------- */

_(FScriptDelegate);

/* ---------------------------------------------------------- FImplementedInterface ---------------------------------------------------------- */

_(FImplementedInterface);

/* ---------------------------------------------------------- UParticleSystemReplay ---------------------------------------------------------- */

_(FParticleEmitterReplayFrame);
_(FParticleSystemReplayFrame);
_(UParticleSystemReplay);

/* ---------------------------------------------------------- UParticleModuleEventSendToGame ---------------------------------------------------------- */

_(UParticleModuleEventSendToGame);

/* ---------------------------------------------------------- UActionResource ---------------------------------------------------------- */

_(UActionResource);

/* ---------------------------------------------------------- URES_Skill ---------------------------------------------------------- */

_(URES_Skill);

/* ---------------------------------------------------------- UActorFactory ---------------------------------------------------------- */

_(UActorFactory);

/* ---------------------------------------------------------- UFaceFXAnimSet ---------------------------------------------------------- */

_(UFaceFXAnimSet);

/* ---------------------------------------------------------- UPersistentSequenceData ---------------------------------------------------------- */

_(FPersistentData);
_(FPersistentSequenceEventData);
_(FPersistentSeqAct_InterpData);
_(UPersistentSequenceData);

/* ---------------------------------------------------------- USparkNews ---------------------------------------------------------- */

_(FNewsArticle);
_(USparkNews);

/* ---------------------------------------------------------- UWillowCustomizationManager ---------------------------------------------------------- */

_(FPendingCustomization);
_(FProductCustomizationInfo);
_(FCustomizationSizeMapping);
_(UWillowCustomizationManager);

/* ---------------------------------------------------------- ULcdHelper ---------------------------------------------------------- */

_(ULcdHelper);

/* ---------------------------------------------------------- UUIManager ---------------------------------------------------------- */

_(UUIManager);

/* ---------------------------------------------------------- UOnlineStats ---------------------------------------------------------- */

_(UOnlineStats);

/* ---------------------------------------------------------- UIniLocPatcher ---------------------------------------------------------- */

_(FIniLocFileEntry);
_(UIniLocPatcher);

/* ---------------------------------------------------------- UFaceFXAsset ---------------------------------------------------------- */

_(FGroupAnimationAndSoundIdentifier);
_(UFaceFXAsset);

/* ---------------------------------------------------------- USparkInterfaceImpl ---------------------------------------------------------- */

_(FSparkOutstandingRequest);
_(USparkInterfaceImpl);

/* ---------------------------------------------------------- UCodecMovie ---------------------------------------------------------- */

_(UCodecMovie);

/* ---------------------------------------------------------- UNavMeshPathGoalEvaluator ---------------------------------------------------------- */

_(UNavMeshPathGoalEvaluator);

/* ---------------------------------------------------------- UNavMeshPathConstraint ---------------------------------------------------------- */

_(UNavMeshPathConstraint);

/* ---------------------------------------------------------- UInputContextSelectorBase ---------------------------------------------------------- */

_(UInputContextSelectorBase);

/* ---------------------------------------------------------- UNPCLoadBalancer ---------------------------------------------------------- */

_(FNPCList);
_(UNPCLoadBalancer);

/* ---------------------------------------------------------- UWillowObstacleUtility ---------------------------------------------------------- */

_(FObstaclePoint);
_(FObstacleSegment);
_(FVelocityObstacle);
_(UWillowObstacleUtility);

/* ---------------------------------------------------------- URecentDropList ---------------------------------------------------------- */

_(URecentDropList);

/* ---------------------------------------------------------- UWillowSystemSettings ---------------------------------------------------------- */

_(FSystemOption);
_(FResolution);
_(UWillowSystemSettings);

/* ---------------------------------------------------------- UGBXCrossLevelReferenceContainer ---------------------------------------------------------- */

_(UGBXCrossLevelReferenceContainer);

/* ---------------------------------------------------------- UWillowSaveGameManager ---------------------------------------------------------- */

_(FPlayerSaveData);
_(FLoadInfo);
_(UWillowSaveGameManager);

/* ---------------------------------------------------------- UWillowGFxMenuHelperSaveGame ---------------------------------------------------------- */

_(FSaveResult);
_(UWillowGFxMenuHelperSaveGame);

/* ---------------------------------------------------------- UAttributeMultiContextResolver ---------------------------------------------------------- */

_(UAttributeMultiContextResolver);

/* ---------------------------------------------------------- UWeaponAttributeMultiContextResolver ---------------------------------------------------------- */

_(UWeaponAttributeMultiContextResolver);

/* ---------------------------------------------------------- UWillowPlayerPawnDataManager ---------------------------------------------------------- */

_(FAsyncDataRequest);
_(UWillowPlayerPawnDataManager);

/* ---------------------------------------------------------- USavedMove ---------------------------------------------------------- */

_(USavedMove);

/* ---------------------------------------------------------- UWillowSavedMove ---------------------------------------------------------- */

_(UWillowSavedMove);

/* ---------------------------------------------------------- UForceFeedbackManager ---------------------------------------------------------- */

_(UForceFeedbackManager);

/* ---------------------------------------------------------- UGearboxRenderTextureManager ---------------------------------------------------------- */

_(FThumbnailLightData);
_(FThumbnailRenderData);
_(UGearboxRenderTextureManager);

/* ---------------------------------------------------------- URB_BodyInstance ---------------------------------------------------------- */

_(URB_BodyInstance);

/* ---------------------------------------------------------- UMaterialExpression ---------------------------------------------------------- */

_(FExpressionInput);
_(UMaterialExpression);

/* ---------------------------------------------------------- UMaterialExpressionComment ---------------------------------------------------------- */

_(UMaterialExpressionComment);

/* ---------------------------------------------------------- UMaterialExpressionSwizzle ---------------------------------------------------------- */

_(UMaterialExpressionSwizzle);

/* ---------------------------------------------------------- UMaterialExpressionCompound ---------------------------------------------------------- */

_(UMaterialExpressionCompound);

/* ---------------------------------------------------------- UHitRegionHelper ---------------------------------------------------------- */

_(FHitRegionDamage);
_(UHitRegionHelper);

/* ---------------------------------------------------------- UGenericParamListStatEntry ---------------------------------------------------------- */

_(UGenericParamListStatEntry);

/* ---------------------------------------------------------- UMorphTargetSet ---------------------------------------------------------- */

_(UMorphTargetSet);

/* ---------------------------------------------------------- UMorphTarget ---------------------------------------------------------- */

_(UMorphTarget);

/* ---------------------------------------------------------- UPopulationAspect ---------------------------------------------------------- */

_(UPopulationAspect);

/* ---------------------------------------------------------- USparkTypes ---------------------------------------------------------- */

_(FSparkResult);
_(USparkTypes);

/* ---------------------------------------------------------- UGearboxAccountOffer ---------------------------------------------------------- */

_(UGearboxAccountOffer);

/* ---------------------------------------------------------- UGearboxAccountEntitlement ---------------------------------------------------------- */

_(UGearboxAccountEntitlement);

/* ---------------------------------------------------------- UPopUpDebugBarGraph ---------------------------------------------------------- */

_(FColumnDataStruct);
_(UPopUpDebugBarGraph);

/* ---------------------------------------------------------- USnapshotInterface ---------------------------------------------------------- */

_(USnapshotInterface);

/* ---------------------------------------------------------- USnapshotRecord ---------------------------------------------------------- */

_(FRuleInfo);
_(FIconData);
_(USnapshotRecord);

/* ---------------------------------------------------------- UPopulationFactory ---------------------------------------------------------- */

_(FDestructionParameters);
_(UPopulationFactory);

/* ---------------------------------------------------------- UPathGoalEvaluator ---------------------------------------------------------- */

_(UPathGoalEvaluator);

/* ---------------------------------------------------------- UPathConstraint ---------------------------------------------------------- */

_(UPathConstraint);

/* ---------------------------------------------------------- UWillowAutoAimStrategy ---------------------------------------------------------- */

_(FLockOnProfile);
_(FViewProfile);
_(UWillowAutoAimStrategy);

/* ---------------------------------------------------------- USoundMode ---------------------------------------------------------- */

_(FAudioEQEffect);
_(FSoundClassAdjuster);
_(USoundMode);

/* ---------------------------------------------------------- UExposureUtilityStrategy ---------------------------------------------------------- */

_(UExposureUtilityStrategy);

/* ---------------------------------------------------------- UGbxMessage ---------------------------------------------------------- */

_(FGbxMessageSimpleMetaData);
_(UGbxMessage);

/* ---------------------------------------------------------- UGbxMessageManager ---------------------------------------------------------- */

_(UGbxMessageManager);

/* ---------------------------------------------------------- URuleEngineLoadBalanceManager ---------------------------------------------------------- */

_(FRuleEngineLoadBalanceStruct);
_(FDebugLoadBalance);
_(FRELBManagerStats);
_(URuleEngineLoadBalanceManager);

/* ---------------------------------------------------------- UExposureUtilityBase ---------------------------------------------------------- */

_(UExposureUtilityBase);

/* ---------------------------------------------------------- UMindTargetInfo ---------------------------------------------------------- */

_(FHitTargetRecord);
_(FPriorityDebugStruct);
_(UMindTargetInfo);

/* ---------------------------------------------------------- UPlayerInteractionServer ---------------------------------------------------------- */

_(UPlayerInteractionServer);

/* ---------------------------------------------------------- UFastTravelStationsLookup ---------------------------------------------------------- */

_(UFastTravelStationsLookup);

/* ---------------------------------------------------------- UCameraShake ---------------------------------------------------------- */

_(FFOscillator);
_(FROscillator);
_(FVOscillator);
_(UCameraShake);

/* ---------------------------------------------------------- UIManager ---------------------------------------------------------- */

_(UIManager);

/* ---------------------------------------------------------- UGFxActorMoviePool ---------------------------------------------------------- */

_(FMovieInstanceArray);
_(UGFxActorMoviePool);

/* ---------------------------------------------------------- UInterpCurveEdSetup ---------------------------------------------------------- */

_(FCurveEdEntry);
_(FCurveEdTab);
_(UInterpCurveEdSetup);

/* ---------------------------------------------------------- UAITracker ---------------------------------------------------------- */

_(UAITracker);

/* ---------------------------------------------------------- UKnowledgeRecord ---------------------------------------------------------- */

_(UKnowledgeRecord);

/* ---------------------------------------------------------- UWillowExperiencePipeline ---------------------------------------------------------- */

_(FDamageTypeExpModifier);
_(UWillowExperiencePipeline);

/* ---------------------------------------------------------- UTargetIterator ---------------------------------------------------------- */

_(UTargetIterator);

/* ---------------------------------------------------------- UTI_Calc ---------------------------------------------------------- */

_(UTI_Calc);

/* ---------------------------------------------------------- UTI_Prioritize ---------------------------------------------------------- */

_(UTI_Prioritize);

/* ---------------------------------------------------------- UDownloadablePackageLicense ---------------------------------------------------------- */

_(UDownloadablePackageLicense);

/* ---------------------------------------------------------- UOnlinePlaylistManager ---------------------------------------------------------- */

_(FConfiguredGameSetting);
_(FInventorySwap);
_(FPlaylist);
_(FPlaylistPopulation);
_(UOnlinePlaylistManager);

/* ---------------------------------------------------------- UAIFactoryBase ---------------------------------------------------------- */

_(FTimeStampedRecord);
_(FKnowledgeRecordStruct);
_(FRuleSetRecord);
_(FRuleRecord);
_(FActionSequenceRecord);
_(FTargetInfoRecord);
_(FAIDefinitionRecord);
_(UAIFactoryBase);

/* ---------------------------------------------------------- UGearboxAIFactory ---------------------------------------------------------- */

_(UGearboxAIFactory);

/* ---------------------------------------------------------- UGBXActorList ---------------------------------------------------------- */

_(Fs_actorList);
_(UGBXActorList);

/* ---------------------------------------------------------- UCombatMusicManager ---------------------------------------------------------- */

_(FTargetedPlayerState);
_(UCombatMusicManager);

/* ---------------------------------------------------------- UGBXObjectList ---------------------------------------------------------- */

_(UGBXObjectList);

/* ---------------------------------------------------------- UScreenSpaceManager ---------------------------------------------------------- */

_(UScreenSpaceManager);

/* ---------------------------------------------------------- UGFxEngine ---------------------------------------------------------- */

_(FGCReference);
_(UGFxEngine);

/* ---------------------------------------------------------- UGameplayEventsHandler ---------------------------------------------------------- */

_(UGameplayEventsHandler);

/* ---------------------------------------------------------- UGameStatsAggregator ---------------------------------------------------------- */

_(FGameEvent);
_(FGameEvents);
_(FEventsBase);
_(FWeaponEvents);
_(FProjectileEvents);
_(FDamageEvents);
_(FPawnEvents);
_(FTeamEvents);
_(FPlayerEvents);
_(FAggregateEventMapping);
_(UGameStatsAggregator);

/* ---------------------------------------------------------- UGameStateObject ---------------------------------------------------------- */

_(FTeamState);
_(FPlayerState);
_(UGameStateObject);

/* ---------------------------------------------------------- UGearboxEditorNode ---------------------------------------------------------- */

_(FOutputLink);
_(FVariableLink);
_(UGearboxEditorNode);

/* ---------------------------------------------------------- UGearboxDialogNode ---------------------------------------------------------- */

_(UGearboxDialogNode);

/* ---------------------------------------------------------- UGearboxDialogAction ---------------------------------------------------------- */

_(UGearboxDialogAction);

/* ---------------------------------------------------------- UGearboxDialogNonTemplateAction ---------------------------------------------------------- */

_(UGearboxDialogNonTemplateAction);

/* ---------------------------------------------------------- UGearboxDialogAct_Talk ---------------------------------------------------------- */

_(UGearboxDialogAct_Talk);

/* ---------------------------------------------------------- UGearboxDialogAct_Trigger ---------------------------------------------------------- */

_(UGearboxDialogAct_Trigger);

/* ---------------------------------------------------------- UGearboxDialogVariable ---------------------------------------------------------- */

_(UGearboxDialogVariable);

/* ---------------------------------------------------------- UGearboxDialogEvent ---------------------------------------------------------- */

_(UGearboxDialogEvent);

/* ---------------------------------------------------------- UGearboxDialogGroup ---------------------------------------------------------- */

_(FDialogEventInfo);
_(FOutputLinkToStruct);
_(FDialogEventData);
_(FTalkActData);
_(UGearboxDialogGroup);

/* ---------------------------------------------------------- UGearboxDialogTemplateGroup ---------------------------------------------------------- */

_(UGearboxDialogTemplateGroup);

/* ---------------------------------------------------------- UFlagValueResolver ---------------------------------------------------------- */

_(UFlagValueResolver);

/* ---------------------------------------------------------- URuleSet ---------------------------------------------------------- */

_(URuleSet);

/* ---------------------------------------------------------- URuleEngine ---------------------------------------------------------- */

_(FEventRecord);
_(FDynamicFlagInstanceData);
_(FRuleSetReference);
_(URuleEngine);

/* ---------------------------------------------------------- UGearboxRuleEngine ---------------------------------------------------------- */

_(UGearboxRuleEngine);

/* ---------------------------------------------------------- UScene ---------------------------------------------------------- */

_(UScene);

/* ---------------------------------------------------------- UPersistentGameDataManager ---------------------------------------------------------- */

_(UPersistentGameDataManager);

/* ---------------------------------------------------------- UTargetableList ---------------------------------------------------------- */

_(FSearchState);
_(UTargetableList);

/* ---------------------------------------------------------- UGFxDataStoreSubscriber ---------------------------------------------------------- */

_(UGFxDataStoreSubscriber);

/* ---------------------------------------------------------- UPawnRelevanceUtility ---------------------------------------------------------- */

_(UPawnRelevanceUtility);

/* ---------------------------------------------------------- UAIDebugCamera ---------------------------------------------------------- */

_(FDebugListItem);
_(UAIDebugCamera);

/* ---------------------------------------------------------- UWillowAIDebugCamera ---------------------------------------------------------- */

_(UWillowAIDebugCamera);

/* ---------------------------------------------------------- UDamageOverTimeManager ---------------------------------------------------------- */

_(FSourceObjectData);
_(FDamageOnlyOnceData);
_(UDamageOverTimeManager);

/* ---------------------------------------------------------- UPlayerSkillTree ---------------------------------------------------------- */

_(FPlayerSkillTreeBranchData);
_(FPlayerSkillTreeTierData);
_(FPlayerSkillTreeSkillData);
_(FSkillTreeSkillStateData);
_(FSkillTreeTierStateData);
_(FSkillTreeBranchStateData);
_(FSkillTreeTierLayoutData);
_(UPlayerSkillTree);

/* ---------------------------------------------------------- UCheatManager ---------------------------------------------------------- */

_(UCheatManager);

/* ---------------------------------------------------------- UWillowDialogManager ---------------------------------------------------------- */

_(UGearboxDialogManager);

/* ---------------------------------------------------------- UWillowDialogManager ---------------------------------------------------------- */

_(FQueuedPersonalEchoLog);
_(UWillowDialogManager);

/* ---------------------------------------------------------- UGearboxAccountData ---------------------------------------------------------- */

_(FEntitlementResult);
_(FOfferResult);
_(FServiceParameterResult);
_(FServiceResult);
_(FArchwayResult);
_(UGearboxAccountData);

/* ---------------------------------------------------------- UGearboxProcess ---------------------------------------------------------- */

_(FStepConfiguration);
_(UGearboxProcess);

/* ---------------------------------------------------------- USparkInitializationProcess ---------------------------------------------------------- */

_(USparkInitializationProcess);

/* ---------------------------------------------------------- UDamageAdjuster ---------------------------------------------------------- */

_(FDamageInfo);
_(UDamageAdjuster);

/* ---------------------------------------------------------- UGFxTextListContainer ---------------------------------------------------------- */

_(FOneTimeDataElement);
_(FSortableDataElement);
_(FGFxTextEntry);
_(UGFxTextListContainer);

/* ---------------------------------------------------------- UWillowEffectCoordinator ---------------------------------------------------------- */

_(FCoordinatedEffectIndices);
_(FCoordinatedEffectThread);
_(FCoordinatedEffectProcess);
_(UWillowEffectCoordinator);

/* ---------------------------------------------------------- UPlayerInteractionManager ---------------------------------------------------------- */

_(FActiveInteraction);
_(UPlayerInteractionManager);

/* ---------------------------------------------------------- FUntypedBulkData ---------------------------------------------------------- */

_(FUntypedBulkData);

/* ---------------------------------------------------------- FByteBulkData ---------------------------------------------------------- */

_(FByteBulkData);

/* ---------------------------------------------------------- UStaticMesh ---------------------------------------------------------- */

_(FStaticMeshTriangle);
_(FStaticMeshTriangleBulkData);
_(FLegacyStaticMeshFullVertex);
_(FStaticMeshFullVertex);
_(FStaticMeshBuildVertex);
_(FFragmentRange);
_(FPlatformStaticMeshData);
_(FPS3StaticMeshData);
_(FStaticMeshElement);
_(FPositionVertex);
_(FStaticMeshLODElement);
_(FStaticMeshLODInfo);
_(FStaticMeshVertexDataInterface);
_(FStaticMeshVertexBuffer);
_(FPositionVertexBuffer);
_(FColorVertexBuffer);
_(FStaticMeshRenderData);
_(UStaticMesh);

/* ---------------------------------------------------------- UPlayerStatsNotifier ---------------------------------------------------------- */

_(UPlayerStatsNotifier);

/* ---------------------------------------------------------- UWillowGFxUIManager ---------------------------------------------------------- */

_(UWillowGFxUIManager);

/* ---------------------------------------------------------- UDownloadablePackageLicenseItem ---------------------------------------------------------- */

_(UDownloadablePackageLicenseItem);

/* ---------------------------------------------------------- UGoldenKeyLicenseItem ---------------------------------------------------------- */

_(UGoldenKeyLicenseItem);

/* ---------------------------------------------------------- UGFxMovieManager ---------------------------------------------------------- */

_(FGearboxGFxPlayParameters);
_(UGFxMovieManager);

/* ---------------------------------------------------------- UGFxMovieDrawStyle ---------------------------------------------------------- */

_(UGFxMovieDrawStyle);

/* ---------------------------------------------------------- UGFxMovieDrawStyleHUD ---------------------------------------------------------- */

_(FHUDCoordValue);
_(FHUDAnchorPoint);
_(UGFxMovieDrawStyleHUD);

/* ---------------------------------------------------------- UGFxMovieDrawStyleRTT ---------------------------------------------------------- */

_(UGFxMovieDrawStyleRTT);

/* ---------------------------------------------------------- UGFxMovieDrawStyleComponent ---------------------------------------------------------- */

_(UGFxMovieDrawStyleComponent);

/* ---------------------------------------------------------- UGFxMovieDrawStyleMesh ---------------------------------------------------------- */

_(UGFxMovieDrawStyleMesh);

/* ---------------------------------------------------------- UActionSequence ---------------------------------------------------------- */

_(UActionSequence);

/* ---------------------------------------------------------- UActionSequencePawn ---------------------------------------------------------- */

_(UActionSequencePawn);

/* ---------------------------------------------------------- UGFxManager ---------------------------------------------------------- */

_(UGFxManager);

/* ---------------------------------------------------------- UBehaviorEventFilterBase ---------------------------------------------------------- */

_(UBehaviorEventFilterBase);

/* ---------------------------------------------------------- UEventFilter_OnTakeDamage ---------------------------------------------------------- */

_(UEventFilter_OnTakeDamage);

/* ---------------------------------------------------------- USkeletalMesh ---------------------------------------------------------- */

_(FBoneMirrorInfo);
_(FBoneMirrorExport);
_(FTriangleSortSettings);
_(FSkeletalMeshLODInfo);
_(FClothSpecialBoneInfo);
_(FSoftBodyTetraLink);
_(FSoftBodySpecialBoneInfo);
_(USkeletalMesh);

/* ---------------------------------------------------------- UAchievementUtility ---------------------------------------------------------- */

_(FAchievementUnlockData);
_(UAchievementUtility);

/* ---------------------------------------------------------- UPhysicalMaterialPropertyBase ---------------------------------------------------------- */

_(UPhysicalMaterialPropertyBase);

/* ---------------------------------------------------------- UPhysicalMaterial ---------------------------------------------------------- */

_(UPhysicalMaterial);

/* ---------------------------------------------------------- UParticleLODLevel ---------------------------------------------------------- */

_(UParticleLODLevel);

/* ---------------------------------------------------------- UParticleEmitter ---------------------------------------------------------- */

_(FParticleBurst);
_(UParticleEmitter);

/* ---------------------------------------------------------- UParticleSpriteEmitter ---------------------------------------------------------- */

_(UParticleSpriteEmitter);

/* ---------------------------------------------------------- UParticleModule ---------------------------------------------------------- */

_(FParticleCurvePair);
_(FParticleRandomSeedInfo);
_(UParticleModule);

/* ---------------------------------------------------------- UParticleModuleOrbitBase ---------------------------------------------------------- */

_(UParticleModuleOrbitBase);

/* ---------------------------------------------------------- UParticleModuleOrbit ---------------------------------------------------------- */

_(FOrbitOptions);
_(UParticleModuleOrbit);

/* ---------------------------------------------------------- UParticleModuleEventBase ---------------------------------------------------------- */

_(UParticleModuleEventBase);

/* ---------------------------------------------------------- UParticleModuleEventReceiverBase ---------------------------------------------------------- */

_(UParticleModuleEventReceiverBase);

/* ---------------------------------------------------------- UParticleModuleEventGenerator ---------------------------------------------------------- */

_(FParticleEvent_GenerateInfo);
_(UParticleModuleEventGenerator);

/* ---------------------------------------------------------- UParticleModuleSpawnBase ---------------------------------------------------------- */

_(UParticleModuleSpawnBase);

/* ---------------------------------------------------------- UParticleModuleSpawn ---------------------------------------------------------- */

_(UParticleModuleSpawn);

/* ---------------------------------------------------------- UParticleModuleRequired ---------------------------------------------------------- */

_(UParticleModuleRequired);

/* ---------------------------------------------------------- UParticleModuleLocationBase ---------------------------------------------------------- */

_(UParticleModuleLocationBase);

/* ---------------------------------------------------------- UParticleModuleLocation ---------------------------------------------------------- */

_(UParticleModuleLocation);

/* ---------------------------------------------------------- ULocalMessage ---------------------------------------------------------- */

_(ULocalMessage);

/* ---------------------------------------------------------- UWillowLocalMessage ---------------------------------------------------------- */

_(UWillowLocalMessage);

/* ---------------------------------------------------------- UReceivedAmmoMessage ---------------------------------------------------------- */

_(UReceivedAmmoMessage);

/* ---------------------------------------------------------- USkeletalMeshSocket ---------------------------------------------------------- */

_(USkeletalMeshSocket);

/* ---------------------------------------------------------- UInterpGroupInst ---------------------------------------------------------- */

_(UInterpGroupInst);

/* ---------------------------------------------------------- UCameraAnim ---------------------------------------------------------- */

_(UCameraAnim);

/* ---------------------------------------------------------- UCameraAnimInst ---------------------------------------------------------- */

_(UCameraAnimInst);

/* ---------------------------------------------------------- UMapInfo ---------------------------------------------------------- */

_(UMapInfo);

/* ---------------------------------------------------------- UAnimObject ---------------------------------------------------------- */

_(UAnimObject);

/* ---------------------------------------------------------- UMorphNodeBase ---------------------------------------------------------- */

_(UMorphNodeBase);

/* ---------------------------------------------------------- UMorphNodeWeightBase ---------------------------------------------------------- */

_(FMorphNodeConn);
_(UMorphNodeWeightBase);

/* ---------------------------------------------------------- UMorphNodeWeight ---------------------------------------------------------- */

_(UMorphNodeWeight);

/* ---------------------------------------------------------- USkelControlBase ---------------------------------------------------------- */

_(USkelControlBase);

/* ---------------------------------------------------------- USkelControlLimb ---------------------------------------------------------- */

_(USkelControlLimb);

/* ---------------------------------------------------------- UWillowSkelControlHandPlacement ---------------------------------------------------------- */

_(UWillowSkelControlHandPlacement);

/* ---------------------------------------------------------- USkelControlLeftHandGripWeapon ---------------------------------------------------------- */

_(USkelControlLeftHandGripWeapon);

/* ---------------------------------------------------------- UAnimNode ---------------------------------------------------------- */

_(FCurveKey);
_(UAnimNode);

/* ---------------------------------------------------------- UAnimNodeSequence ---------------------------------------------------------- */

_(UAnimNodeSequence);

/* ---------------------------------------------------------- UAnimNodeBlendBase ---------------------------------------------------------- */

_(FAnimBlendChild);
_(UAnimNodeBlendBase);

/* ---------------------------------------------------------- UAnimNodeBlend ---------------------------------------------------------- */

_(UAnimNodeBlend);

/* ---------------------------------------------------------- UAnimNodeBlendPerBone ---------------------------------------------------------- */

_(UAnimNodeBlendPerBone);

/* ---------------------------------------------------------- UAnimTree ---------------------------------------------------------- */

_(FAnimGroup);
_(FSkelControlListHead);
_(FPreviewSkelMeshStruct);
_(FPreviewSocketStruct);
_(FPreviewAnimSetsStruct);
_(UAnimTree);

/* ---------------------------------------------------------- UWillowAnimTree ---------------------------------------------------------- */

_(UWillowAnimTree);

/* ---------------------------------------------------------- UAnimNodeSlot ---------------------------------------------------------- */

_(UAnimNodeSlot);

/* ---------------------------------------------------------- UWillowAnimNodeSlot ---------------------------------------------------------- */

_(UWillowAnimNodeSlot);

/* ---------------------------------------------------------- UAnimNodeAimOffset ---------------------------------------------------------- */

_(FAimTransform);
_(FAimComponent);
_(FAimOffsetProfile);
_(UAnimNodeAimOffset);

/* ---------------------------------------------------------- UWillowAnimNodeAimOffset ---------------------------------------------------------- */

_(UWillowAnimNodeAimOffset);

/* ---------------------------------------------------------- UInGameAdManager ---------------------------------------------------------- */

_(UInGameAdManager);

/* ---------------------------------------------------------- UGFxRawData ---------------------------------------------------------- */

_(UGFxRawData);

/* ---------------------------------------------------------- USwfMovie ---------------------------------------------------------- */

_(USwfMovie);

/* ---------------------------------------------------------- UFlashMovie ---------------------------------------------------------- */

_(UFlashMovie);

/* ---------------------------------------------------------- UInventoryCardGFx ---------------------------------------------------------- */

_(FTopStatData);
_(UInventoryCardGFx);

/* ---------------------------------------------------------- UAkObject ---------------------------------------------------------- */

_(UAkObject);

/* ---------------------------------------------------------- UAkBank ---------------------------------------------------------- */

_(UAkBank);

/* ---------------------------------------------------------- UAkStateGroup ---------------------------------------------------------- */

_(UAkStateGroup);

/* ---------------------------------------------------------- UAkSwitchGroup ---------------------------------------------------------- */

_(UAkSwitchGroup);

/* ---------------------------------------------------------- UAkSwitch ---------------------------------------------------------- */

_(UAkSwitch);

/* ---------------------------------------------------------- UAkRtpc ---------------------------------------------------------- */

_(UAkRtpc);

/* ---------------------------------------------------------- UAkState ---------------------------------------------------------- */

_(UAkState);

/* ---------------------------------------------------------- UAkEvent ---------------------------------------------------------- */

_(FAkPlayingInfo);
_(UAkEvent);

/* ---------------------------------------------------------- UGearboxDialogEventData ---------------------------------------------------------- */

_(UGearboxDialogEventData);

/* ---------------------------------------------------------- UGearboxEngineGlobals ---------------------------------------------------------- */

_(FPlayerOwnedComponent);
_(FAkCallBackGetRTPC);
_(UGearboxEngineGlobals);

/* ---------------------------------------------------------- LensFlare ---------------------------------------------------------- */

_(FLensFlareElementCurvePair);
_(FLensFlareElement);
_(ULensFlare);

/* ---------------------------------------------------------- UForceFeedbackWaveform ---------------------------------------------------------- */

_(FWaveformSample);
_(UForceFeedbackWaveform);

/* ---------------------------------------------------------- UOnlineSubsystem ---------------------------------------------------------- */

_(FUniqueNetId);
_(FFriendsQuery);
_(FOnlineFriend);
_(FAppIdLicenseInfo);
_(FTOCInfo);
_(FOnlineContent);
_(FOnlineCrossTitleContent);
_(FOnlineContentNameInfo);
_(FNamedOnlineContent);
_(FCompatibilityOnlineContent);
_(FMarketplaceContent);
_(FOnlineRegistrant);
_(FOnlineArbitrationRegistrant);
_(FSpeechRecognizedWord);
_(FOnlinePlayerScore);
_(FLocalTalker);
_(FRemoteTalker);
_(FOnlineFriendMessage);
_(FNamedInterface);
_(FNamedInterfaceDef);
_(FTitleFile);
_(FCommunityContentFile);
_(FCommunityContentMetadata);
_(FNamedSession);
_(FAchievementDetails);
_(FOnlinePartyMember);
_(UOnlineSubsystem);

/* ---------------------------------------------------------- UOnlineSubsystemCommonImpl ---------------------------------------------------------- */

_(UOnlineSubsystemCommonImpl);

/* ---------------------------------------------------------- UMeshBeacon ---------------------------------------------------------- */

_(FConnectionBandwidthStats);
_(FPlayerMember);
_(UMeshBeacon);

/* ---------------------------------------------------------- UOnlineAuthInterfaceBaseImpl ---------------------------------------------------------- */

_(FBaseAuthSession);
_(FLocalAuthSession);
_(FAuthSession);
_(UOnlineAuthInterfaceBaseImpl);

/* ---------------------------------------------------------- UGameplayEvents ---------------------------------------------------------- */

_(FGameStatGroup);
_(FGameplayEventsHeader);
_(FGameSessionInformation);
_(FTeamInformation);
_(FPlayerInformation);
_(FGameplayEventMetaData);
_(FWeaponClassEventData);
_(FDamageClassEventData);
_(FProjectileClassEventData);
_(FPawnClassEventData);
_(UGameplayEvents);

/* ---------------------------------------------------------- UGameplayEventsReader ---------------------------------------------------------- */

_(UGameplayEventsReader);

/* ---------------------------------------------------------- UGameplayEventsWriter ---------------------------------------------------------- */

_(UGameplayEventsWriter);

/* ---------------------------------------------------------- FGameEventType ---------------------------------------------------------- */

_(FGameEventType);

/* ---------------------------------------------------------- IGameEvent ---------------------------------------------------------- */

_(IGameEvent);

/* ---------------------------------------------------------- NamedParameter ---------------------------------------------------------- */

_(NamedParameter);

/* ---------------------------------------------------------- FGenericParamListEvent ---------------------------------------------------------- */

_(FGenericParamListEvent);

/* ---------------------------------------------------------- FProjectileIntEvent ---------------------------------------------------------- */

_(FProjectileIntEvent);

/* ---------------------------------------------------------- FGameEventHeader ---------------------------------------------------------- */

_(FGameEventHeader);

/* ---------------------------------------------------------- UDownloadableContentEnumerator ---------------------------------------------------------- */

_(UDownloadableContentEnumerator);

/* ---------------------------------------------------------- UDownloadableContentOfferEnumerator ---------------------------------------------------------- */

_(FMarketplaceOffer);
_(UDownloadableContentOfferEnumerator);

/* ---------------------------------------------------------- UDownloadableContentManager ---------------------------------------------------------- */

_(FDlcCompatibilityData);
_(FDlcCompatibilityDataEx);
_(FDlcContentId);
_(FDlcContentInfo);
_(FMarketplaceOfferDownloadState);
_(FInstalledContentInfo);
_(FRejectedContentInfo);
_(UDownloadableContentManager);

/* ---------------------------------------------------------- UWillowDownloadableContentManager ---------------------------------------------------------- */

_(FContentState);
_(FSeasonPassOfferUnion);
_(FSeasonPassPackageCount);
_(FDLCMissionData);
_(FCompatibilityVersionInfo);
_(FGoldenKeySource);
_(FTaggedMarketplaceContent);
_(UWillowDownloadableContentManager);

/* ---------------------------------------------------------- USettings ---------------------------------------------------------- */

_(FLocalizedStringSetting);
_(FSettingsData);
_(FSettingsProperty);
_(FStringIdToStringMapping);
_(FLocalizedStringSettingMetaData);
_(FIdToStringMapping);
_(FSettingsPropertyPropertyMetaData);
_(USettings);

/* ---------------------------------------------------------- UOnlineStatsRead ---------------------------------------------------------- */

_(FOnlineStatsColumn);
_(FOnlineStatsRow);
_(FColumnMetaData);
_(UOnlineStatsRead);

/* ---------------------------------------------------------- UOnlineSubsystemSteamworks ---------------------------------------------------------- */

_(FPlayerStat);
_(FPendingPlayerStats);
_(FPropertyToColumn);
_(FProfileSettingsCache);
_(FDeviceIdCache);
_(FOnlineStatusMapping);
_(FOnlineStatusPropertyMapping);
_(FOnlineStatusContextMapping);
_(FControllerConnectionState);
_(FTitleFileMapping);
_(FQueuedAvatarRequest);
_(FAchievementMappingInfo);
_(FAchievementProgressStat);
_(FLeaderboardHandle);
_(FLeaderboardTemplate);
_(FDeferredLeaderboardRead);
_(FDeferredLeaderboardWrite);
_(FLeaderboardEntry);
_(FViewIdToLeaderboardName);
_(FSteamPlayerClanData);
_(FMarketplaceListCache);
_(FMarketplaceOfferData);
_(UOnlineSubsystemSteamworks);

/* ---------------------------------------------------------- UOnlineGameSettings ---------------------------------------------------------- */

_(UOnlineGameSettings);

/* ---------------------------------------------------------- UOnlinePlayerStorage ---------------------------------------------------------- */

_(FOnlineProfileSetting);
_(UOnlinePlayerStorage);

/* ---------------------------------------------------------- UOnlineProfileSettings ---------------------------------------------------------- */

_(UOnlineProfileSettings);

/* ---------------------------------------------------------- UGearboxProfileSettings ---------------------------------------------------------- */

_(UGearboxProfileSettings);

/* ---------------------------------------------------------- UWillowProfileSettings ---------------------------------------------------------- */

_(UWillowProfileSettings);

/* ---------------------------------------------------------- FExec ---------------------------------------------------------- */

_(FExec);

/* ---------------------------------------------------------- UPlayer ---------------------------------------------------------- */

_(UPlayer);

/* ---------------------------------------------------------- ULocalPlayer ---------------------------------------------------------- */

_(FSynchronizedActorVisibilityHistory);
_(FCurrentPostProcessVolumeInfo);
_(FPostProcessSettingsOverride);
_(FWorldLightingOverride);
_(ULocalPlayer);

/* ---------------------------------------------------------- UAIDefinition ---------------------------------------------------------- */

_(UAIDefinition);

/* ---------------------------------------------------------- UWillowAIDefinition ---------------------------------------------------------- */

_(UWillowAIDefinition);

/* ---------------------------------------------------------- UParticleSystem ---------------------------------------------------------- */

_(FParticleSystemLOD);
_(FLODSoloTrack);
_(UParticleSystem);

/* ---------------------------------------------------------- UDamageType ---------------------------------------------------------- */

_(UDamageType);

/* ---------------------------------------------------------- UKillZDamageType ---------------------------------------------------------- */

_(UKillZDamageType);

/* ---------------------------------------------------------- UWillowDamageType ---------------------------------------------------------- */

_(UWillowDamageType);

/* ---------------------------------------------------------- UWillowDamageSource ---------------------------------------------------------- */

_(UWillowDamageSource);

/* ---------------------------------------------------------- UWillowDmgSource_Skill ---------------------------------------------------------- */

_(UWillowDmgSource_Skill);

/* ---------------------------------------------------------- UWillowDmgSource_Bullet ---------------------------------------------------------- */

_(UWillowDmgSource_Bullet);

/* ---------------------------------------------------------- UWillowDmgSource_StatusEffect ---------------------------------------------------------- */

_(UWillowDmgSource_StatusEffect);

/* ---------------------------------------------------------- UEngineBaseTypes ---------------------------------------------------------- */

_(FRenderingPerformanceOverrides);
_(FSubtitleCue);
_(UEngineBaseTypes);

/* ---------------------------------------------------------- UChannel ---------------------------------------------------------- */

_(UChannel);

/* ---------------------------------------------------------- USaveGameChannel ---------------------------------------------------------- */

_(USaveGameChannel);

/* ---------------------------------------------------------- UStatChannel ---------------------------------------------------------- */

_(UStatChannel);

/* ---------------------------------------------------------- UActorChannel ---------------------------------------------------------- */

_(UActorChannel);

/* ---------------------------------------------------------- UWillowPauseTicker ---------------------------------------------------------- */

_(FPauseTimerData);
_(UWillowPauseTicker);

/* ---------------------------------------------------------- UDamagePipeline ---------------------------------------------------------- */

_(FReflectionInfo);
_(FDamageEventSummary);
_(UDamagePipeline);

_(FObjectInstancingGraph);

_(UObjectReferencer);

/* ---------------------------------------------------------- UInterpTrackInst ---------------------------------------------------------- */

_(UInterpTrackInst);

/* ---------------------------------------------------------- UInterpTrackInstDirector ---------------------------------------------------------- */

_(UInterpTrackInstDirector);

/* ---------------------------------------------------------- UInterpTrackInstMove ---------------------------------------------------------- */

_(UInterpTrackInstMove);

_(UInterpTrackInstProperty);

_(FIOManager);
_(FIOSystem);

_(FTransactionBase);

/* ---------------------------------------------------------- UQSortComparer ---------------------------------------------------------- */

_(UQSortComparer);

/* ---------------------------------------------------------- UWeaponTypeComparer ---------------------------------------------------------- */

_(UWeaponTypeComparer);

/* ---------------------------------------------------------- UInventoryUIStatComparer ---------------------------------------------------------- */

_(UInventoryUIStatComparer);

/* ---------------------------------------------------------- FRunnable ---------------------------------------------------------- */

_(FRunnable);

/* ---------------------------------------------------------- FRunnableThread ---------------------------------------------------------- */

_(FRunnableThread);

/* ---------------------------------------------------------- FRefCountedObject ---------------------------------------------------------- */

_(FRefCountedObject);

/* ---------------------------------------------------------- FBatchedElementParameters ---------------------------------------------------------- */

_(FBatchedElementParameters);

_(FAsyncIOHandle);
_(FAsyncIORequest);
_(FAsyncIOSystemBase);

/* ---------------------------------------------------------- Shader PLACEHOLDER ---------------------------------------------------------- */

_(FShaderTarget);
_(FParameterAllocation);
_(FShaderParameterMap);
_(FShaderCompilerEnvironment);
_(FShaderCompilerError);
_(FShaderCompilerOutput);
_(FShaderCompileJob);
_(FBatchedShaderCompileJob);
_(FShaderCompileThreadRunnable);
_(FShaderCompilingThreadManager);

/* ---------------------------------------------------------- FRenderResource ---------------------------------------------------------- */

_(FRenderResource);
_(FVertexBuffer);
_(FIndexBuffer);
_(FRawIndexBuffer16or32);
_(FRawIndexBuffer);
_(FRawStaticIndexBuffer);

/* ---------------------------------------------------------- UPostProcessEffect ---------------------------------------------------------- */

_(UPostProcessEffect);

/* ---------------------------------------------------------- UMaterialEffect ---------------------------------------------------------- */

_(UMaterialEffect);

/* ---------------------------------------------------------- UPostProcessChain ---------------------------------------------------------- */

_(UPostProcessChain);

/* ---------------------------------------------------------- UDOFEffect ---------------------------------------------------------- */

_(UDOFEffect);

/* ---------------------------------------------------------- UDOFAndBloomEffect ---------------------------------------------------------- */

_(UDOFAndBloomEffect);

/* ---------------------------------------------------------- UDOFBloomMotionBlurEffect ---------------------------------------------------------- */

_(UDOFBloomMotionBlurEffect);

/* ---------------------------------------------------------- UUberPostProcessEffect ---------------------------------------------------------- */

_(UUberPostProcessEffect);

/* ---------------------------------------------------------- UWillowPhysicalMaterialProperty ---------------------------------------------------------- */

_(FRtpcParameterValue);
_(FImpactResponseParameters);
_(FImpactResponseEffect);
_(FImpactResponseData);
_(FWheelSlipModifierData);
_(UWillowPhysicalMaterialProperty);

/* ---------------------------------------------------------- AActor ---------------------------------------------------------- */

_(FTimerData);
_(FTraceHitInfo);
_(FImpactInfo);
_(FTraceNotifyInfo);
_(FAnimSlotInfo);
_(FAnimSlotDesc);
_(FRigidBodyState);
_(FRigidBodyContactInfo);
_(CollisionImpactData);
_(FPhysEffectInfo);
_(FActorReference);
_(FNavReference);
_(FBasedPosition);
_(FResourcePoolReference);
_(AActor);

/* ---------------------------------------------------------- AAnemoneInfectionState ---------------------------------------------------------- */

_(FFDisplayTimer);
_(AAnemoneInfectionState);

/* ---------------------------------------------------------- AKeyPoint ---------------------------------------------------------- */

_(AKeyPoint);

/* ---------------------------------------------------------- AWillowBoundaryTurret ---------------------------------------------------------- */

_(AWillowBoundaryTurret);

/* ---------------------------------------------------------- ALevelLandmark ---------------------------------------------------------- */

_(ALevelLandmark);

/* ---------------------------------------------------------- AProximityActor ---------------------------------------------------------- */

_(AProximityActor);

/* ---------------------------------------------------------- ATeleporterDestination ---------------------------------------------------------- */

_(ATeleporterDestination);

/* ---------------------------------------------------------- AWillowPersonalTeleporter ---------------------------------------------------------- */

_(AWillowPersonalTeleporter);

/* ---------------------------------------------------------- AStationTeleporterDestination ---------------------------------------------------------- */

_(AStationTeleporterDestination);

/* ---------------------------------------------------------- AGBXNavMesh ---------------------------------------------------------- */

_(FGBXNavMeshVertex);
_(FGBXNavMeshPoly);
_(FGBXNavMeshPolyRef);
_(FGBXNavMeshSpecialMove);
_(FGBXNavmeshCrossLevelConnection);
_(FGBXNavMeshPolyData);
_(FGBXNavMeshPathSize);
_(FGBXNavMeshObstacleData);
_(FGBXNavMeshLookupCell);
_(FGBXNavMeshPolyLookup);
_(FGBXLineCheckResult);
_(FGBXConnectedNavMesh);
_(AGBXNavMesh);

/* ---------------------------------------------------------- UGBXNavMeshPathFinder ---------------------------------------------------------- */

_(FIGBXNavMeshObstaclePointer);
_(FGBXNavMeshPathPoint);
_(FGBXNavMeshPath);
_(UGBXNavMeshPathFinder);

/* ---------------------------------------------------------- ASkillEffectManager ---------------------------------------------------------- */

_(FDeferredSkillActivationData);
_(ASkillEffectManager);

/* ---------------------------------------------------------- APopulationPoint ---------------------------------------------------------- */

_(APopulationPoint);

/* ---------------------------------------------------------- AWillowVersusDuelArena ---------------------------------------------------------- */

_(AWillowVersusDuelArena);

/* ---------------------------------------------------------- AGearboxAIMoveNode ---------------------------------------------------------- */

_(FNodeData);
_(AGearboxAIMoveNode);

/* ---------------------------------------------------------- AWillowAIMoveNode ---------------------------------------------------------- */

_(AWillowAIMoveNode);

/* ---------------------------------------------------------- AWireManager ---------------------------------------------------------- */

_(AWireManager);

/* ---------------------------------------------------------- ATemporalField ---------------------------------------------------------- */

_(ATemporalField);

/* ---------------------------------------------------------- AWillowRadarManager ---------------------------------------------------------- */

_(FServerDynamicRadarIconData);
_(FRemoteDynamicRadarIconData);
_(AWillowRadarManager);

/* ---------------------------------------------------------- ACameraActor ---------------------------------------------------------- */

_(ACameraActor);

/* ---------------------------------------------------------- ADynamicCameraActor ---------------------------------------------------------- */

_(ADynamicCameraActor);

/* ---------------------------------------------------------- AWillowSpectatorPoint ---------------------------------------------------------- */

_(AWillowSpectatorPoint);

/* ---------------------------------------------------------- UWorldBody ---------------------------------------------------------- */

_(UWorldBody);

/* ---------------------------------------------------------- AEmitter ---------------------------------------------------------- */

_(AEmitter__FCheckpointRecord);
_(AEmitter);

/* ---------------------------------------------------------- AEmitterCameraLensEffectBase ---------------------------------------------------------- */

_(AEmitterCameraLensEffectBase);

/* ---------------------------------------------------------- AWillowEmitter ---------------------------------------------------------- */

_(AWillowEmitter);

/* ---------------------------------------------------------- ADynamicSMActor ---------------------------------------------------------- */

_(ADynamicSMActor);

/* ---------------------------------------------------------- AInterpActor ---------------------------------------------------------- */

_(AInterpActor__FCheckpointRecord);
_(AInterpActor);

/* ---------------------------------------------------------- AKActor ---------------------------------------------------------- */

_(AKActor);

/* ---------------------------------------------------------- AKActorFromStatic ---------------------------------------------------------- */

_(AKActorFromStatic);

/* ---------------------------------------------------------- AKActorSpawnable ---------------------------------------------------------- */

_(AKActorSpawnable);

/* ---------------------------------------------------------- AKActorPizazz ---------------------------------------------------------- */

_(FImpulseData);
_(AKActorPizazz);

/* ---------------------------------------------------------- ASceneCaptureActor ---------------------------------------------------------- */

_(ASceneCaptureActor);

/* ---------------------------------------------------------- ASceneCaptureReflectActor ---------------------------------------------------------- */

_(ASceneCaptureReflectActor);

/* ---------------------------------------------------------- ASceneCapturePortalActor ---------------------------------------------------------- */

_(ASceneCapturePortalActor);

/* ---------------------------------------------------------- APortalTeleporter ---------------------------------------------------------- */

_(APortalTeleporter);

/* ---------------------------------------------------------- AParticleEventManager ---------------------------------------------------------- */

_(AParticleEventManager);

/* ---------------------------------------------------------- ADecalManager ---------------------------------------------------------- */

_(FActiveDecalInfo);
_(ADecalManager);

/* ---------------------------------------------------------- UReachSpec ---------------------------------------------------------- */

_(UReachSpec);

/* ---------------------------------------------------------- AEmitterPool ---------------------------------------------------------- */

_(FEmitterBaseInfo);
_(AEmitterPool);

/* ---------------------------------------------------------- AWillowLightProjectileManager ---------------------------------------------------------- */

_(FReplicatedLightProjectile);
_(FLightProjectile);
_(FBeamDamageData);
_(FBeamLocationData);
_(FServerBeamState);
_(FReplicatedBeamState);
_(FBeamState);
_(FReplicatedBeamEndPoints);
_(AWillowLightProjectileManager);

/* ---------------------------------------------------------- ADroppedPickup ---------------------------------------------------------- */

_(ADroppedPickup);

/* ---------------------------------------------------------- AWillowPickup ---------------------------------------------------------- */

_(FPickupMemento);
_(AWillowPickup);

/* ---------------------------------------------------------- ABrush ---------------------------------------------------------- */

_(FGeomSelection);
_(ABrush);

/* ---------------------------------------------------------- UModel ---------------------------------------------------------- */

_(FVert);
_(FBspNode);
_(FBspSurf);
_(FLeaf);

/* ---------------------------------------------------------- AVolume ---------------------------------------------------------- */

_(AVolume);

/* ---------------------------------------------------------- APortalVolume ---------------------------------------------------------- */

_(APortalVolume);

/* ---------------------------------------------------------- APostProcessVolume ---------------------------------------------------------- */

_(APostProcessVolume);

/* ---------------------------------------------------------- APhysicsVolume ---------------------------------------------------------- */

_(FCheckpointRecord);
_(APhysicsVolume);

/* ---------------------------------------------------------- ALadderVolume ---------------------------------------------------------- */

_(ALadderVolume);

/* ---------------------------------------------------------- AActionSkill ---------------------------------------------------------- */

_(FActionSkillCustomEventReplicationData);
_(FCachedWeaponInfo);
_(AActionSkill);

/* ---------------------------------------------------------- ADeathtrapActionSkill ---------------------------------------------------------- */

_(ADeathtrapActionSkill);

/* ---------------------------------------------------------- AScorpioActionSkill ---------------------------------------------------------- */

_(AScorpioActionSkill);

/* ---------------------------------------------------------- FCheckResult ---------------------------------------------------------- */

_(FIteratorList);
_(FIteratorActorList);
_(FCheckResult);

/* ---------------------------------------------------------- ACamera ---------------------------------------------------------- */

_(FTCameraCache);
_(FTViewTarget);
_(FViewTargetTransitionParams);
_(ACamera);

/* ---------------------------------------------------------- UProjectile ---------------------------------------------------------- */

_(AProjectile);

/* ---------------------------------------------------------- UWillowDamagePipeline ---------------------------------------------------------- */

_(UWillowDamagePipeline);

/* ---------------------------------------------------------- UBehaviorBase ---------------------------------------------------------- */

_(FBehaviorKernelInfo);
_(FBehaviorParameterUnion);
_(FBehaviorParameters);
_(FBehaviorContextData);
_(FBehaviorOutputLinkDescriptionData);
_(UBehaviorBase);

/* ---------------------------------------------------------- UBehavior_RemoteEvent ---------------------------------------------------------- */

_(UBehavior_RemoteEvent);

/* ---------------------------------------------------------- UBehavior_ActivateSkill ---------------------------------------------------------- */

_(UBehavior_ActivateSkill);

/* ---------------------------------------------------------- UBehavior_AIThrowProjectileAtTarget ---------------------------------------------------------- */

_(FTrajectoryData);
_(FAIThrowProjectileBehaviorSequenceStateData);
_(UBehavior_AIThrowProjectileAtTarget);

/* ---------------------------------------------------------- UBehavior_SetShieldTriggeredState ---------------------------------------------------------- */

_(UBehavior_SetShieldTriggeredState);

/* ---------------------------------------------------------- UCameraModifier ---------------------------------------------------------- */

_(UCameraModifier);

/* ---------------------------------------------------------- UCameraModifier_CameraShake ---------------------------------------------------------- */

_(FCameraShakeInstance);
_(UCameraModifier_CameraShake);

/* ---------------------------------------------------------- UEngineTypes ---------------------------------------------------------- */

_(FLocalizedSubtitle);
_(FLightMapRef);
_(FDominantShadowInfo);
_(FLightmassLightSettings);
_(FLightmassPointLightSettings);
_(FLightmassDirectionalLightSettings);
_(FLightmassPrimitiveSettings);
_(FLightmassDebugOptions);
_(FSwarmDebugOptions);
_(FRootMotionCurve);
_(FPrimitiveMaterialRef);
_(FPostProcessMaterialRef);
_(UEngineTypes);

/* ---------------------------------------------------------- UExporter ---------------------------------------------------------- */

_(UExporter);

/* ---------------------------------------------------------- USoundClass ---------------------------------------------------------- */

_(FSoundClassEditorData);
_(FSoundClassProperties);
_(USoundClass);

/* ---------------------------------------------------------- USubsystem ---------------------------------------------------------- */

_(USubsystem);

/* ---------------------------------------------------------- UAkBaseSoundObject ---------------------------------------------------------- */

_(UAkBaseSoundObject);

/* ---------------------------------------------------------- USoundNode ---------------------------------------------------------- */

_(USoundNode);

/* ---------------------------------------------------------- USoundNodeWave ---------------------------------------------------------- */

_(USoundNodeWave);

/* ---------------------------------------------------------- USoundCue ---------------------------------------------------------- */

_(FSoundNodeEditorData);
_(USoundCue);

/* ---------------------------------------------------------- UMusicTrackDataStructures ---------------------------------------------------------- */

_(FMusicTrackStruct);
_(FMusicStateInfo);
_(UMusicTrackDataStructures);

/* ---------------------------------------------------------- UUISoundTheme ---------------------------------------------------------- */

_(FSoundEventMapping);
_(UUISoundTheme);

/* ---------------------------------------------------------- UUIRoot ---------------------------------------------------------- */

_(FUIRangeData);
_(FTextureCoordinates);
_(FUIProviderScriptFieldValue);
_(FUIProviderFieldValue);
_(FInputKeyAction);
_(FUIDataStoreBinding);
_(FInputEventParameters);
_(FSubscribedInputEventParameters);
_(FUIAxisEmulationDefinition);
_(FRawInputKeyEventData);
_(UUIRoot);

/* ---------------------------------------------------------- UUISceneClient ---------------------------------------------------------- */

_(UUISceneClient);

/* ---------------------------------------------------------- UGameUISceneClient ---------------------------------------------------------- */

_(UGameUISceneClient);

/* ---------------------------------------------------------- UDataStoreClient ---------------------------------------------------------- */

_(FPlayerDataStoreGroup);
_(UDataStoreClient);

/* ---------------------------------------------------------- UUIDataProvider ---------------------------------------------------------- */

_(FUIDataProviderField);
_(UUIDataProvider);

/* ---------------------------------------------------------- UUIResourceCombinationProvider ---------------------------------------------------------- */

_(UUIResourceCombinationProvider);

/* ---------------------------------------------------------- UUIDataProvider_OnlinePlayerStorageArray ---------------------------------------------------------- */

_(UUIDataProvider_OnlinePlayerStorageArray);

/* ---------------------------------------------------------- UUIDataProvider_OnlinePlayerDataBase ---------------------------------------------------------- */

_(UUIDataProvider_OnlinePlayerDataBase);

/* ---------------------------------------------------------- UUIDataProvider_OnlinePartyChatList ---------------------------------------------------------- */

_(UUIDataProvider_OnlinePartyChatList);

/* ---------------------------------------------------------- UUIDataProvider_PlayerAchievements ---------------------------------------------------------- */

_(UUIDataProvider_PlayerAchievements);

/* ---------------------------------------------------------- UUIDataProvider_OnlineFriendMessages ---------------------------------------------------------- */

_(UUIDataProvider_OnlineFriendMessages);

/* ---------------------------------------------------------- UUIDataProvider_OnlineFriends ---------------------------------------------------------- */

_(UUIDataProvider_OnlineFriends);

/* ---------------------------------------------------------- UUIDataProvider_OnlinePlayerStorage ---------------------------------------------------------- */

_(FPlayerStorageArrayProvider);
_(UUIDataProvider_OnlinePlayerStorage);

/* ---------------------------------------------------------- UUIDataProvider_OnlineProfileSettings ---------------------------------------------------------- */

_(UUIDataProvider_OnlineProfileSettings);

/* ---------------------------------------------------------- UUIDataProvider_SettingsArray ---------------------------------------------------------- */

_(UUIDataProvider_SettingsArray);

/* ---------------------------------------------------------- UUIPropertyDataProvider ---------------------------------------------------------- */

_(UUIPropertyDataProvider);

/* ---------------------------------------------------------- UUIDynamicDataProvider ---------------------------------------------------------- */

_(UUIDynamicDataProvider);

/* ---------------------------------------------------------- UUIDataProvider_Settings ---------------------------------------------------------- */

_(FSettingsArrayProvider);
_(UUIDataProvider_Settings);

/* ---------------------------------------------------------- UUIResourceDataProvider ---------------------------------------------------------- */

_(UUIResourceDataProvider);

/* ---------------------------------------------------------- UUIWeaponSummary ---------------------------------------------------------- */

_(UUIWeaponSummary);

/* ---------------------------------------------------------- UUIDataProvider_MenuItem ---------------------------------------------------------- */

_(UUIDataProvider_MenuItem);

/* ---------------------------------------------------------- UUIDynamicFieldProvider ---------------------------------------------------------- */

_(UUIDynamicFieldProvider);

/* ---------------------------------------------------------- UUIDataStore ---------------------------------------------------------- */

_(UUIDataStore);

/* ---------------------------------------------------------- UUIDataStore_GameResource ---------------------------------------------------------- */

_(FGameResourceDataProvider);
_(UUIDataStore_GameResource);

/* ---------------------------------------------------------- UUIDataStore_MenuItems ---------------------------------------------------------- */

_(UUIDataStore_MenuItems);

/* ---------------------------------------------------------- UUIDataStore_DynamicResource ---------------------------------------------------------- */

_(FDynamicResourceProviderDefinition);
_(UUIDataStore_DynamicResource);

/* ---------------------------------------------------------- UUIDataStore_Remote ---------------------------------------------------------- */

_(UUIDataStore_Remote);

/* ---------------------------------------------------------- UUIDataStore_OnlineGameSearch ---------------------------------------------------------- */

_(FGameSearchCfg);
_(UUIDataStore_OnlineGameSearch);

/* ---------------------------------------------------------- UUIDataStore_OnlinePlayerData ---------------------------------------------------------- */

_(UUIDataStore_OnlinePlayerData);

/* ---------------------------------------------------------- UUIDataStore_Settings ---------------------------------------------------------- */

_(UUIDataStore_Settings);

/* ---------------------------------------------------------- UUIDataStore_OnlineGameSettings ---------------------------------------------------------- */

_(FGameSettingsCfg);
_(UUIDataStore_OnlineGameSettings);

/* ---------------------------------------------------------- UInteraction ---------------------------------------------------------- */

_(UInteraction);

/* ---------------------------------------------------------- UInput ---------------------------------------------------------- */

_(FKeyBind);
_(UInput);

/* ---------------------------------------------------------- UPlayerInput ---------------------------------------------------------- */

_(UPlayerInput);

/* ---------------------------------------------------------- UWillowPlayerInput ---------------------------------------------------------- */

_(FInputDeviceAxisAddress);
_(FAccelStateData);
_(FInputAxisData);
_(FDeviceLookAxisData);
_(FInputDeviceButtonAddress);
_(FInputButtonData);
_(FKeyRebindingData);
_(UWillowPlayerInput);

/* ---------------------------------------------------------- UUIInteraction ---------------------------------------------------------- */

_(FUIKeyRepeatData);
_(FUIAxisEmulationData);
_(UUIInteraction);

/* ---------------------------------------------------------- UWillowUIInteraction ---------------------------------------------------------- */

_(FColumnData);
_(FtMenuData);
_(FtMenuTextPos);
_(FMenuHeaderData);
_(FColumnLayoutData);
_(FtMenuLayout);
_(FSkillIndexLevelRequirementPair);
_(FDebugConsoleCommand);
_(FNetworkChannelData);
_(FItemPartSettings);
_(FGearBuilderWeightedInventoryPart);
_(FGearBuilderInventoryPartSlot);
_(FItemSettings);
_(FGearBuilderWeightedWeaponPart);
_(FGearBuilderWeaponPartSlot);
_(FWeaponSettings);
_(FItemBuilderData);
_(FItemBuilderBalanceDefinition);
_(FGearBuilderCustomizationData);
_(FGearBuilderCustomizationUsageData);
_(UWillowUIInteraction);

/* ---------------------------------------------------------- UGFxInteraction ---------------------------------------------------------- */

_(UGFxInteraction);

/* ---------------------------------------------------------- UConsole ---------------------------------------------------------- */

_(FAutoCompleteCommand);
_(FAutoCompleteNode);
_(UConsole);

/* ---------------------------------------------------------- UGFxMoviePlayer ---------------------------------------------------------- */

_(GFxMovieInfo);
_(FGFxMovie);

_(FExternalTexture);
_(FSoundThemeBinding);
_(FGFxDataStoreBinding);
_(FGFxWidgetBinding);
_(FASValue);
_(UGFxMoviePlayer);

/* ---------------------------------------------------------- UPCContextMenuObject ---------------------------------------------------------- */

_(FPCContextMenuItem);
_(UPCContextMenuObject);

/* ---------------------------------------------------------- UGFxMovie ---------------------------------------------------------- */

_(UGFxMovie);

/* ---------------------------------------------------------- UGFxObject ---------------------------------------------------------- */

_(FASDisplayInfo);
_(FASColorTransform);
_(UGFxObject);

/* ---------------------------------------------------------- UCreditsGFxObject ---------------------------------------------------------- */

_(UCreditsGFxObject);

/* ---------------------------------------------------------- UGearboxAccountGFxObject ---------------------------------------------------------- */

_(UGearboxAccountGFxObject);

/* ---------------------------------------------------------- UShieldBarGFxObject ---------------------------------------------------------- */

_(UShieldBarGFxObject);

/* ---------------------------------------------------------- UAmmoPanelGFxObject ---------------------------------------------------------- */

_(UAmmoPanelGFxObject);

/* ---------------------------------------------------------- UMontageGFxObject ---------------------------------------------------------- */

_(UMontageGFxObject);

/* ---------------------------------------------------------- UScrollingListGFxObject ---------------------------------------------------------- */

_(UScrollingListGFxObject);

/* ---------------------------------------------------------- UMultitypeScrollingListGFxObject ---------------------------------------------------------- */

_(UMultitypeScrollingListGFxObject);

/* ---------------------------------------------------------- UVendingMachineFeedbackGFxObject ---------------------------------------------------------- */

_(UVendingMachineFeedbackGFxObject);

/* ---------------------------------------------------------- UFastTravelStationGFxObject ---------------------------------------------------------- */

_(UFastTravelStationGFxObject);

/* ---------------------------------------------------------- UHealthBarGFxObject ---------------------------------------------------------- */

_(UHealthBarGFxObject);

/* ---------------------------------------------------------- UValueGFxObject ---------------------------------------------------------- */

_(UValueGFxObject);

/* ---------------------------------------------------------- UEridiumValueGFxObject ---------------------------------------------------------- */

_(UEridiumValueGFxObject);

/* ---------------------------------------------------------- USkillTreeGFxObject ---------------------------------------------------------- */

_(Fartifact_datum);
_(FSkillTreeUICell);
_(USkillTreeGFxObject);

/* ---------------------------------------------------------- UStatusMenuMapGFxObject ---------------------------------------------------------- */

_(FMapObjectData);
_(FClipRect);
_(UStatusMenuMapGFxObject);

/* ---------------------------------------------------------- UItemCardGFxObject ---------------------------------------------------------- */

_(UItemCardGFxObject);

/* ---------------------------------------------------------- UItemOfTheDayPanelGFxObject ---------------------------------------------------------- */

_(UItemOfTheDayPanelGFxObject);

/* ---------------------------------------------------------- UGFxClikWidget ---------------------------------------------------------- */

_(FEventData);
_(UGFxClikWidget);

/* ---------------------------------------------------------- UWillowGFxClikWidget ---------------------------------------------------------- */

_(UWillowGFxClikWidget);

/* ---------------------------------------------------------- UDeferredDataProviderGFxObject ---------------------------------------------------------- */

_(UDeferredDataProviderGFxObject);

/* ---------------------------------------------------------- UBaseTopLevelPanelGFxObject ---------------------------------------------------------- */

_(FItemCardInfo);
_(UBaseTopLevelPanelGFxObject);

/* ---------------------------------------------------------- UTwoPanelInterfaceGFxObject ---------------------------------------------------------- */

_(UTwoPanelInterfaceGFxObject);

/* ---------------------------------------------------------- UChallengesScreenGFxObject ---------------------------------------------------------- */

_(UChallengesScreenGFxObject);

/* ---------------------------------------------------------- UGFxMovieState ---------------------------------------------------------- */

_(FMovieStateData);
_(FMovieStateStruct);
_(UGFxMovieState);

/* ---------------------------------------------------------- UGFxMovieStatePlayerAware ---------------------------------------------------------- */

_(FMovieRangeStateData);
_(UGFxMovieStatePlayerAware);

/* ---------------------------------------------------------- UGearboxGFxMovie ---------------------------------------------------------- */

_(UGearboxGFxMovie);

/* ---------------------------------------------------------- UGFxMovieInteractiveObject ---------------------------------------------------------- */

_(UGFxMovieInteractiveObject);

/* ---------------------------------------------------------- UWillowGFxMovie ---------------------------------------------------------- */

_(UWillowGFxMovie);

/* ---------------------------------------------------------- UWillowGFxMoviePressStart ---------------------------------------------------------- */

_(UWillowGFxMoviePressStart);

/* ---------------------------------------------------------- UHashDisplayGFxMovie ---------------------------------------------------------- */

_(UHashDisplayGFxMovie);

/* ---------------------------------------------------------- UGearboxAccountGFxMovie ---------------------------------------------------------- */

_(UGearboxAccountGFxMovie);

/* ---------------------------------------------------------- UTextChatGFxMovie ---------------------------------------------------------- */

_(UTextChatGFxMovie);

/* ---------------------------------------------------------- UOnlineMessageGFxMovie ---------------------------------------------------------- */

_(UOnlineMessageGFxMovie);

/* ---------------------------------------------------------- UEchoVersionGFxMovie ---------------------------------------------------------- */

_(UEchoVersionGFxMovie);

/* ---------------------------------------------------------- UGFxMovieMissionStatus ---------------------------------------------------------- */

_(UGFxMovieMissionStatus);

/* ---------------------------------------------------------- UWillowGFxDialogBox ---------------------------------------------------------- */

_(FDialogBoxButton);
_(FDialogBoxLayout);
_(UWillowGFxDialogBox);

/* ---------------------------------------------------------- UWillowGFxTrainingDialogBox ---------------------------------------------------------- */

_(UWillowGFxTrainingDialogBox);

/* ---------------------------------------------------------- UItemPickupGFxMovie ---------------------------------------------------------- */

_(UItemPickupGFxMovie);

/* ---------------------------------------------------------- UWillowGFxMovie3D ---------------------------------------------------------- */

_(UWillowGFxMovie3D);

/* ---------------------------------------------------------- UWillowGFxMovieCredits ---------------------------------------------------------- */

_(UWillowGFxMovieCredits);

/* ---------------------------------------------------------- UQuestAcceptGFxMovie ---------------------------------------------------------- */

_(UQuestAcceptGFxMovie);

/* ---------------------------------------------------------- UWeaponScopeGFxMovie ---------------------------------------------------------- */

_(UWeaponScopeGFxMovie);

/* ---------------------------------------------------------- UWillowGFxThirdPersonMovie ---------------------------------------------------------- */

_(UWillowGFxThirdPersonMovie);

/* ---------------------------------------------------------- UFastTravelStationGFxMovie ---------------------------------------------------------- */

_(UFastTravelStationGFxMovie);

/* ---------------------------------------------------------- UWillowInventoryGFxMovie ---------------------------------------------------------- */

_(UWillowInventoryGFxMovie);

/* ---------------------------------------------------------- UHUDWidget_Base ---------------------------------------------------------- */

_(UHUDWidget_Base);

/* ---------------------------------------------------------- UHUDWidget_Challenges ---------------------------------------------------------- */

_(UHUDWidget_Challenges);

/* ---------------------------------------------------------- UHUDWidget_Trading ---------------------------------------------------------- */

_(UHUDWidget_Trading);

/* ---------------------------------------------------------- UHUDWidget_WorldSpace ---------------------------------------------------------- */

_(FWorldSpaceIcon);
_(FObjectiveIcon);
_(FPlayerIcon);
_(FWorldSpacePlayerInfo);
_(UHUDWidget_WorldSpace);

/* ---------------------------------------------------------- UHUDWidget_Minimap ---------------------------------------------------------- */

_(FMinimapIconClip);
_(FMinimapObjectiveIconClip);
_(UHUDWidget_Minimap);

/* ---------------------------------------------------------- UHUDWidget_Missions ---------------------------------------------------------- */

_(FMissionWidgetMessage);
_(UHUDWidget_Missions);

/* ---------------------------------------------------------- UHUDWidget_Crosshairs ---------------------------------------------------------- */

_(UHUDWidget_Crosshairs);

/* ---------------------------------------------------------- UBaseInventoryPanelGFxObject ---------------------------------------------------------- */

_(UBaseInventoryPanelGFxObject);

/* ---------------------------------------------------------- UStatusMenuEquippedPanelGFxObject ---------------------------------------------------------- */

_(UStatusMenuEquippedPanelGFxObject);

/* ---------------------------------------------------------- UChallengesPanelGFxObject ---------------------------------------------------------- */

_(UChallengesPanelGFxObject);

/* ---------------------------------------------------------- UBadassPanelGFxObject ---------------------------------------------------------- */

_(UBadassPanelGFxObject);

/* ---------------------------------------------------------- InventoryDataProviderGFxObject ---------------------------------------------------------- */

_(FHeavyInventoryElement);
_(FSortFilterConfiguration);
_(UInventoryDataProviderGFxObject);

/* ---------------------------------------------------------- UTradingPanelGFxObject ---------------------------------------------------------- */

_(UTradingPanelGFxObject);

/* ---------------------------------------------------------- UStatusMenuInventoryPanelGFxObject ---------------------------------------------------------- */

_(UStatusMenuInventoryPanelGFxObject);

/* ---------------------------------------------------------- UInventoryListPanelGFxObject ---------------------------------------------------------- */

_(UInventoryListPanelGFxObject);

/* ---------------------------------------------------------- UTranslatorTag ---------------------------------------------------------- */

_(UTranslatorTag);

/* ---------------------------------------------------------- UTranslationContext ---------------------------------------------------------- */

_(UTranslationContext);

/* ---------------------------------------------------------- UAnimNotify ---------------------------------------------------------- */

_(UAnimNotify);

/* ---------------------------------------------------------- UAnimMetaData ---------------------------------------------------------- */

_(UAnimMetaData);

/* ---------------------------------------------------------- UAnimSequence ---------------------------------------------------------- */

_(FAnimNotifyEvent);
_(FRawAnimSequenceTrack);
_(FTimeModifier);
_(FSkelControlModifier);
_(FTranslationTrack);
_(FRotationTrack);
_(FCurveTrack);
_(FCompressedTrack);
_(FDeltaTrackInfo);
_(UAnimSequence);

/* ---------------------------------------------------------- UAnimSet ---------------------------------------------------------- */

_(AnimSetMeshLinkup);
_(UAnimSet);

/* ---------------------------------------------------------- UInterpTrack ---------------------------------------------------------- */

_(SupportedSubTrackInfo);
_(SubTrackGroup);
_(UInterpTrack);

/* ---------------------------------------------------------- UInterpTrackMove ---------------------------------------------------------- */

_(FInterpLookupPoint);
_(FInterpLookupTrack);
_(UInterpTrackMove);

/* ---------------------------------------------------------- UInterpGroup ---------------------------------------------------------- */

_(UInterpGroup);

/* ---------------------------------------------------------- UExpressionEvaluator ---------------------------------------------------------- */

_(UExpressionEvaluator);

/* ---------------------------------------------------------- UWeaponActionAvailableExpressionEvaluator ---------------------------------------------------------- */

_(UWeaponActionAvailableExpressionEvaluator);

/* ---------------------------------------------------------- UKMeshProps ---------------------------------------------------------- */

_(UKMeshProps);

/* ---------------------------------------------------------- URB_BodySetup ---------------------------------------------------------- */

_(FKCachedConvexDataElement);
_(FKCachedConvexData);
_(URB_BodySetup);

/* ---------------------------------------------------------- URB_ConstraintSetup ---------------------------------------------------------- */

_(FLinearDOFSetup);
_(URB_ConstraintSetup);

/* ---------------------------------------------------------- UPhysicsAssetInstance ---------------------------------------------------------- */

_(UPhysicsAssetInstance);

/* ---------------------------------------------------------- UPhysicsAsset ---------------------------------------------------------- */

_(UPhysicsAsset);

/* ---------------------------------------------------------- UAttributeExpression ---------------------------------------------------------- */

_(AttributeExpressionData);
_(ConditionalSoundData);
_(UAttributeExpression);

/* ---------------------------------------------------------- UAttributeModifier ---------------------------------------------------------- */

_(UAttributeModifier);

_(UGBXNavMeshPathModifier);
_(UGBXNavMeshPathModifier_Simplify);
_(UGBXNavMeshPathModifier_SmoothTurns);

_(FString);

_(FName);
_(FNameEntry);
_(FNameEntryPoolAllocator);

_(FCylinder);
_(FAutomatedTestingDatum);
_(FVector);
_(FVector4);

/* ---------------------------------------------------------- APlayerReplicationInfo ---------------------------------------------------------- */

_(APlayerReplicationInfo);

/* ---------------------------------------------------------- AWillowPlayerReplicationInfo ---------------------------------------------------------- */

_(FReplicatedStandInGear);
_(FTrackedSkillState);
_(AWillowPlayerReplicationInfo);

_(FRotator);
_(FTPOV);

_(FColor);
_(UObject_PMF);

_(FObjectResource);

/* ---------------------------------------------------------- UField ---------------------------------------------------------- */

_(UField);

/* ---------------------------------------------------------- UEnum ---------------------------------------------------------- */

_(UEnum);

_(FOutputDevice);

_(FOutputDeviceFile);

_(FOutputDeviceConsole);

_(FOutputDeviceConsoleWindowsInherited);

_(FSynchronize);

_(FCriticalSection);
_(FBufferedLine);
_(FOutputDeviceRedirector);

_(FOutputDeviceError);

_(FContextSupplier);

/* ---------------------------------------------------------- FFeedbackContext ---------------------------------------------------------- */

_(FFeedbackContext);

_(FOutputDeviceRedirectorBase);
_(UTextBuffer);

_(UProperty);
_(UObjectProperty);

_(UByteProperty);
_(UDelegateProperty);

/* ---------------------------------------------------------- UStruct ---------------------------------------------------------- */

_(UStruct);
// _(TMap_FName_UFunctionPtr);
/* ---------------------------------------------------------- UState ---------------------------------------------------------- */

_(UState);
_(FGCReferenceInfo);
_(FGCReferenceTokenStream);
_(FRepRecord);

/* ---------------------------------------------------------- UClass ---------------------------------------------------------- */

_(UClass);

/* ---------------------------------------------------------- UComponent ---------------------------------------------------------- */

_(UComponent);

_(FCurveEdInterface);
_(UScriptStruct);

/* ---------------------------------------------------------- UStructProperty ---------------------------------------------------------- */

_(UStructProperty);
_(FOutParmRec);
_(FFrame);
_(FPushedState);

/* ---------------------------------------------------------- UFunction ---------------------------------------------------------- */

_(UFunction);

/* ---------------------------------------------------------- UDistributionFloat ---------------------------------------------------------- */

_(UDistributionFloat);

/* ---------------------------------------------------------- UDistributionVector ---------------------------------------------------------- */

_(UDistributionVector);

/* ---------------------------------------------------------- UFactory ---------------------------------------------------------- */

_(UFactory);
_(FSceneInterface);

/* ---------------------------------------------------------- UActorComponent ---------------------------------------------------------- */

_(UActorComponent);

/* ---------------------------------------------------------- UWillowCoverComponent ---------------------------------------------------------- */

_(UWillowCoverComponent);

/* ---------------------------------------------------------- URadialBlurComponent ---------------------------------------------------------- */

_(URadialBlurComponent);

/* ---------------------------------------------------------- UMovementComponent ---------------------------------------------------------- */

_(UMovementComponent);

/* ---------------------------------------------------------- UGearboxDialogComponent ---------------------------------------------------------- */

_(UGearboxDialogComponent);

/* ---------------------------------------------------------- UComponentLifetimeManagerComponent ---------------------------------------------------------- */

_(UComponentLifetimeManagerComponent);

/* ---------------------------------------------------------- USpecialMoveComponent ---------------------------------------------------------- */

_(USpecialMoveComponent);

/* ---------------------------------------------------------- UAkComponent ---------------------------------------------------------- */

_(FPendingFaceFXInfo);
_(FPendingSubtitleInfo);
_(UAkComponent);

/* ---------------------------------------------------------- UStatusEffectsComponent ---------------------------------------------------------- */

_(FActiveStatusEffect);
_(FSocketEmitter);
_(FHitRegionEmitters);
_(FEffectSoundData);
_(FOngoingEffectInfo);
_(UStatusEffectsComponent);

/* ---------------------------------------------------------- UAIComponent ---------------------------------------------------------- */

_(FAIRange);
_(FPriorityData);
_(FAITreeData);
_(FAIResourceData);
_(FAIHoldData);
_(UAIComponent);

/* ---------------------------------------------------------- APerch ---------------------------------------------------------- */

_(APerch);

_(FDecalState);
_(FDecalInteraction);

/* ---------------------------------------------------------- UHeightFogComponent ---------------------------------------------------------- */

_(UHeightFogComponent);

/* ---------------------------------------------------------- USequenceObject ---------------------------------------------------------- */

_(USequenceObject);

/* ---------------------------------------------------------- UGBXDefinition ---------------------------------------------------------- */

_(UGBXDefinition);

/* ---------------------------------------------------------- UWillowPopulationPointDefinition ---------------------------------------------------------- */

_(FSpawnAnimPair);
_(FSpawnAnimData);
_(UWillowPopulationPointDefinition);

/* ---------------------------------------------------------- UGearboxCalloutDefinition ---------------------------------------------------------- */

_(UGearboxCalloutDefinition);

/* ---------------------------------------------------------- USkillExpressionEvaluatorDefinition ---------------------------------------------------------- */

_(USkillExpressionEvaluatorDefinition);

/* ---------------------------------------------------------- USkillTreeDefinition ---------------------------------------------------------- */

_(USkillTreeDefinition);

/* ---------------------------------------------------------- UCreditsLineDefinition ---------------------------------------------------------- */

_(UCreditsLineDefinition);

/* ---------------------------------------------------------- UDefinitionGlobalsDefinition ---------------------------------------------------------- */

_(FDefinitionIconDatum);
_(UDefinitionGlobalsDefinition);

/* ---------------------------------------------------------- UBlackMarketDefinition ---------------------------------------------------------- */

_(FBlackMarketUpgradeLevelData);
_(UBlackMarketDefinition);

/* ---------------------------------------------------------- UPersonalTeleporterDefinition ---------------------------------------------------------- */

_(UPersonalTeleporterDefinition);

/* ---------------------------------------------------------- UInteractiveObjectLootListDefinition ---------------------------------------------------------- */

_(UInteractiveObjectLootListDefinition);

/* ---------------------------------------------------------- UPhaseLockDefinition ---------------------------------------------------------- */

_(UPhaseLockDefinition);

/* ---------------------------------------------------------- UBehaviorAliasDefinition ---------------------------------------------------------- */

_(UBehaviorAliasDefinition);

/* ---------------------------------------------------------- UBehaviorAliasLookupDefinition ---------------------------------------------------------- */

_(FBehaviorAliasReference);
_(UBehaviorAliasLookupDefinition);

/* ---------------------------------------------------------- UInputSetDefinition ---------------------------------------------------------- */

_(UInputSetDefinition);

/* ---------------------------------------------------------- UInputContextDefinition ---------------------------------------------------------- */

_(UInputContextDefinition);

/* ---------------------------------------------------------- UPopulationDefinition ---------------------------------------------------------- */

_(UPopulationDefinition);

/* ---------------------------------------------------------- UCustomizationData ---------------------------------------------------------- */

_(UCustomizationData);

/* ---------------------------------------------------------- UAIPawnBalanceModifierDefinition ---------------------------------------------------------- */

_(UAIPawnBalanceModifierDefinition);

/* ---------------------------------------------------------- ULookAxisDefinition ---------------------------------------------------------- */

_(ULookAxisDefinition);

/* ---------------------------------------------------------- UFractalViewWanderingDefinition ---------------------------------------------------------- */

_(UFractalViewWanderingDefinition);

/* ---------------------------------------------------------- UWillowVersusDuelGlobals ---------------------------------------------------------- */

_(FDuelTeamInfo);
_(FDuelTeamPair);
_(UWillowVersusDuelGlobals);

/* ---------------------------------------------------------- UFocusCameraDefinition ---------------------------------------------------------- */

_(UFocusCameraDefinition);

/* ---------------------------------------------------------- UInjuredDefinition ---------------------------------------------------------- */

_(UInjuredDefinition);

/* ---------------------------------------------------------- USkillTreeBranchLayoutDefinition ---------------------------------------------------------- */

_(FTierLayout);
_(USkillTreeBranchLayoutDefinition);

/* ---------------------------------------------------------- UGameReleaseDefinition ---------------------------------------------------------- */

_(UGameReleaseDefinition);

/* ---------------------------------------------------------- UPawnInteractionDefinition ---------------------------------------------------------- */

_(UPawnInteractionDefinition);

/* ---------------------------------------------------------- UWillowPawnInteractionDefinition ---------------------------------------------------------- */

_(UWillowPawnInteractionDefinition);

/* ---------------------------------------------------------- USprintDefinition ---------------------------------------------------------- */

_(USprintDefinition);

/* ---------------------------------------------------------- UFeatherBoneBlendDefinition ---------------------------------------------------------- */

_(FFeatherBoneBlendData);
_(UFeatherBoneBlendDefinition);

/* ---------------------------------------------------------- URootMotionDefinition ---------------------------------------------------------- */

_(URootMotionDefinition);

/* ---------------------------------------------------------- UDownloadableAssetLibraryDefinition ---------------------------------------------------------- */

_(UDownloadableAssetLibraryDefinition);

/* ---------------------------------------------------------- UCustomizationDefinition ---------------------------------------------------------- */

_(UCustomizationDefinition);

/* ---------------------------------------------------------- ULockoutDefinition ---------------------------------------------------------- */

_(ULockoutDefinition);

/* ---------------------------------------------------------- UPopulationBodyTag ---------------------------------------------------------- */

_(UPopulationBodyTag);

/* ---------------------------------------------------------- UPerchDefinition ---------------------------------------------------------- */

_(FPerchAnimData);
_(UPerchDefinition);

/* ---------------------------------------------------------- UInputRemappingDefinition ---------------------------------------------------------- */

_(FInputRemappingAxisData);
_(FInputRemappingButtonData);
_(UInputRemappingDefinition);

/* ---------------------------------------------------------- UMarketingUnlockDefinition ---------------------------------------------------------- */

_(UMarketingUnlockDefinition);

/* ---------------------------------------------------------- UBlackMarketUpgradeDefinition ---------------------------------------------------------- */

_(UBlackMarketUpgradeDefinition);

/* ---------------------------------------------------------- UWillowCoverStanceDefinition ---------------------------------------------------------- */

_(UWillowCoverStanceDefinition);

/* ---------------------------------------------------------- UEnvironmentTagDefinition ---------------------------------------------------------- */

_(UEnvironmentTagDefinition);

/* ---------------------------------------------------------- UWillowDialogEmoteDefinition ---------------------------------------------------------- */

_(UWillowDialogEmoteDefinition);

/* ---------------------------------------------------------- UBodyWeaponHoldDefinition ---------------------------------------------------------- */

_(FConditionalAnimData);
_(FBodyWeaponActionData);
_(FBodyWeaponActionPostureData);
_(FBodyHandIKHoldData);
_(FCustomBodyHandIKHoldData);
_(UBodyWeaponHoldDefinition);

/* ---------------------------------------------------------- UStaggerDefinition ---------------------------------------------------------- */

_(FStaggeredRecoveryRotationData);
_(UStaggerDefinition);

/* ---------------------------------------------------------- UDownloadableFixupAIPawnNamesDefinition ---------------------------------------------------------- */

_(FAIPawnPlaythroughThreeData);
_(UDownloadableFixupAIPawnNamesDefinition);

/* ---------------------------------------------------------- UAIResource ---------------------------------------------------------- */

_(FAIResourceRestriction);
_(UAIResource);

/* ---------------------------------------------------------- UExplosionDefinition ---------------------------------------------------------- */

_(FExplosionScaleData);
_(FRecentExplosion);
_(UExplosionDefinition);

/* ---------------------------------------------------------- UStanceTypeDefinition ---------------------------------------------------------- */

_(UStanceTypeDefinition);

/* ---------------------------------------------------------- UWillowAutoAimProfileDefinition ---------------------------------------------------------- */

_(UWillowAutoAimProfileDefinition);

/* ---------------------------------------------------------- UWillowAutoAimStrategyDefinition ---------------------------------------------------------- */

_(FProfileDefinition);
_(UWillowAutoAimStrategyDefinition);

/* ---------------------------------------------------------- USkillTreeGFxDefinition ---------------------------------------------------------- */

_(USkillTreeGFxDefinition);

/* ---------------------------------------------------------- UChallengesPanelDefinition ---------------------------------------------------------- */

_(UChallengesPanelDefinition);

/* ---------------------------------------------------------- UBodyClassDeathDefinition ---------------------------------------------------------- */

_(FTechDeathData);
_(UBodyClassDeathDefinition);

/* ---------------------------------------------------------- USpecialMoveDefinition ---------------------------------------------------------- */

_(FSMBehavior);
_(FSMNotify);
_(USpecialMoveDefinition);

/* ---------------------------------------------------------- UGearboxAnimDefinition ---------------------------------------------------------- */

_(FTimedAnimBehaviorEvent);
_(UGearboxAnimDefinition);

/* ---------------------------------------------------------- UWillowAnimDefinition ---------------------------------------------------------- */

_(UWillowAnimDefinition);

/* ---------------------------------------------------------- USpecialMove_PhaseLock ---------------------------------------------------------- */

_(USpecialMove_PhaseLock);

/* ---------------------------------------------------------- USpecialMove_Perch ---------------------------------------------------------- */

_(USpecialMove_Perch);

/* ---------------------------------------------------------- USpecialMove_PerchLoop ---------------------------------------------------------- */

_(USpecialMove_PerchLoop);

/* ---------------------------------------------------------- USpecialMove_PerchRandomLoop ---------------------------------------------------------- */

_(FSMPerchRandomPair);
_(USpecialMove_PerchRandomLoop);

/* ---------------------------------------------------------- USpecialMove_Cover ---------------------------------------------------------- */

_(USpecialMove_Cover);

/* ---------------------------------------------------------- USpecialMove_Cringe ---------------------------------------------------------- */

_(USpecialMove_Cringe);

/* ---------------------------------------------------------- USpecialMove_Motion ---------------------------------------------------------- */

_(USpecialMove_Motion);

/* ---------------------------------------------------------- USpecialMove_PhysicsJump ---------------------------------------------------------- */

_(USpecialMove_PhysicsJump);

/* ---------------------------------------------------------- USpecialMove_Dodge ---------------------------------------------------------- */

_(USpecialMove_Dodge);

/* ---------------------------------------------------------- USpecialMove_Cloak ---------------------------------------------------------- */

_(USpecialMove_Cloak);

/* ---------------------------------------------------------- USpecialMove_Turn ---------------------------------------------------------- */

_(USpecialMove_Turn);

/* ---------------------------------------------------------- UPlayerTrainingMessageListDefinition ---------------------------------------------------------- */

_(UPlayerTrainingMessageListDefinition);

/* ---------------------------------------------------------- UPlayerChallengeListDefinition ---------------------------------------------------------- */

_(UPlayerChallengeListDefinition);

/* ---------------------------------------------------------- UTextMarkupDictionary ---------------------------------------------------------- */

_(FTextMarkupEntry);
_(UTextMarkupDictionary);

/* ---------------------------------------------------------- UDeveloperPerksDefinition ---------------------------------------------------------- */

_(FDeveloperData);
_(FPerkData);
_(UDeveloperPerksDefinition);

/* ---------------------------------------------------------- UCombatMusicParameters ---------------------------------------------------------- */

_(UCombatMusicParameters);

/* ---------------------------------------------------------- UAttributePresentationListDefinition ---------------------------------------------------------- */

_(UAttributePresentationListDefinition);

/* ---------------------------------------------------------- UGenericReviveMessageDefinition ---------------------------------------------------------- */

_(UGenericReviveMessageDefinition);

/* ---------------------------------------------------------- UPackageAssetSublibrary ---------------------------------------------------------- */

_(UPackageAssetSublibrary);

/* ---------------------------------------------------------- UPackageAssetLibrary ---------------------------------------------------------- */

_(UPackageAssetLibrary);

/* ---------------------------------------------------------- UChallengeConditionDefinition ---------------------------------------------------------- */

_(UChallengeConditionDefinition);

/* ---------------------------------------------------------- UChallengeCategoryDefinition ---------------------------------------------------------- */

_(UChallengeCategoryDefinition);

/* ---------------------------------------------------------- UHUDScalingAnchorDefinition ---------------------------------------------------------- */

_(UHUDScalingAnchorDefinition);

/* ---------------------------------------------------------- UCoverSearchCriteria ---------------------------------------------------------- */

_(UCoverSearchCriteria);

/* ---------------------------------------------------------- UAwarenessZoneDefinition ---------------------------------------------------------- */

_(UAwarenessZoneDefinition);

/* ---------------------------------------------------------- UAwarenessZoneCollectionDefinition ---------------------------------------------------------- */

_(UAwarenessZoneCollectionDefinition);

/* ---------------------------------------------------------- UTargetingDefinition ---------------------------------------------------------- */

_(UTargetingDefinition);

/* ---------------------------------------------------------- UGearboxDialogPriority ---------------------------------------------------------- */

_(UGearboxDialogPriority);

/* ---------------------------------------------------------- UDownloadablePackageDefinition ---------------------------------------------------------- */

_(UDownloadablePackageDefinition);

/* ---------------------------------------------------------- UGearboxDialogGlobalsDefinition ---------------------------------------------------------- */

_(UGearboxDialogGlobalsDefinition);

/* ---------------------------------------------------------- ULevelDependencyList ---------------------------------------------------------- */

_(FPersistentMapDependencies);
_(ULevelDependencyList);

/* ---------------------------------------------------------- USkillTreeBranchDefinition ---------------------------------------------------------- */

_(FTier);
_(USkillTreeBranchDefinition);

/* ---------------------------------------------------------- UCurrencyListDefinition ---------------------------------------------------------- */

_(FCurrencyPresentation);
_(UCurrencyListDefinition);

/* ---------------------------------------------------------- UInputActionDefinition ---------------------------------------------------------- */

_(UInputActionDefinition);

/* ---------------------------------------------------------- UInputDeviceDefinition ---------------------------------------------------------- */

_(FInputDeviceAxisData);
_(FLookAxisDefinitionData);
_(FInputDeviceButtonData);
_(UInputDeviceDefinition);

/* ---------------------------------------------------------- UInputDeviceCollectionDefinition ---------------------------------------------------------- */

_(UInputDeviceCollectionDefinition);

/* ---------------------------------------------------------- UDownloadableContentDefinition ---------------------------------------------------------- */

_(UDownloadableContentDefinition);

/* ---------------------------------------------------------- UDownloadableCustomizationSetDefinition ---------------------------------------------------------- */

_(UDownloadableCustomizationSetDefinition);

/* ---------------------------------------------------------- UDownloadableVehicleDefinition ---------------------------------------------------------- */

_(UDownloadableVehicleDefinition);

/* ---------------------------------------------------------- UDownloadableContentDefinition ---------------------------------------------------------- */

_(UDownloadableCharacterDefinition);

/* ---------------------------------------------------------- UDownloadableItemSetDefinition ---------------------------------------------------------- */

_(UDownloadableItemSetDefinition);

/* ---------------------------------------------------------- UDownloadableBalanceModifierDefinition ---------------------------------------------------------- */

_(UDownloadableBalanceModifierDefinition);

/* ---------------------------------------------------------- UDownloadableExpansionDefinition ---------------------------------------------------------- */

_(FDlcLevelTravelPair);
_(UDownloadableExpansionDefinition);

/* ---------------------------------------------------------- URegionDefinition ---------------------------------------------------------- */

_(URegionDefinition);

/* ---------------------------------------------------------- UWillowRegionDefinition ---------------------------------------------------------- */

_(UWillowRegionDefinition);

/* ---------------------------------------------------------- UMissionDirectivesDefinition ---------------------------------------------------------- */

_(UMissionDirectivesDefinition);

/* ---------------------------------------------------------- UGFxTextListDefinition ---------------------------------------------------------- */

_(UGFxTextListDefinition);

/* ---------------------------------------------------------- UCoordinatedEffectDefinition ---------------------------------------------------------- */

_(FCoordinatedScalarParameter);
_(FCoordinatedVectorParameter);
_(FCoordinatedParticleSystemDefinition);
_(FCoordinatedAudioDefinition);
_(UCoordinatedEffectDefinition);

/* ---------------------------------------------------------- UPlayerEventProviderDefinition ---------------------------------------------------------- */

_(UPlayerEventProviderDefinition);

/* ---------------------------------------------------------- UPlayerNameIdentifierDefinition ---------------------------------------------------------- */

_(UPlayerNameIdentifierDefinition);

/* ---------------------------------------------------------- UGearboxDialogEventTag ---------------------------------------------------------- */

_(UGearboxDialogEventTag);

/* ---------------------------------------------------------- UWillowDialogEventTag ---------------------------------------------------------- */

_(UWillowDialogEventTag);

/* ---------------------------------------------------------- UWillowGFxUIManagerDefinition ---------------------------------------------------------- */

_(UWillowGFxUIManagerDefinition);

/* ---------------------------------------------------------- UTravelStationDefinition ---------------------------------------------------------- */

_(UTravelStationDefinition);

/* ---------------------------------------------------------- UTravelStationDefinition ---------------------------------------------------------- */

_(ULevelTravelStationDefinition);

/* ---------------------------------------------------------- UFastTravelStationDefinition ---------------------------------------------------------- */

_(UFastTravelStationDefinition);

/* ---------------------------------------------------------- UGestaltSkeletalMeshDefinition ---------------------------------------------------------- */

_(FGestaltAccessoryNameEntry);
_(FGestaltPart);
_(FGestaltInfo);
_(FGestaltSocketRemapEntry);
_(FGestaltPartPermutation);
_(FGestaltPartBoundsEntry);
_(UGestaltSkeletalMeshDefinition);

/* ---------------------------------------------------------- UGearboxGlobalsDefinition ---------------------------------------------------------- */

_(UGearboxGlobalsDefinition);

/* ---------------------------------------------------------- UWillowDialogGlobalsDefinition ---------------------------------------------------------- */

_(UWillowDialogGlobalsDefinition);

/* ---------------------------------------------------------- UGFxManagerDefinition ---------------------------------------------------------- */

_(FAkEventResolver);
_(UGFxManagerDefinition);

/* ---------------------------------------------------------- UColiseumRuleDefinition ---------------------------------------------------------- */

_(UColiseumRuleDefinition);

/* ---------------------------------------------------------- UGearboxDialogNameTag ---------------------------------------------------------- */

_(UGearboxDialogNameTag);

/* ---------------------------------------------------------- UWillowDialogNameTag ---------------------------------------------------------- */

_(FScaleformPortraitData);
_(FVideoPortraitData);
_(FEchoPortraitInfo);
_(FEmotePortraitInfo);
_(FEmoteStance);
_(UWillowDialogNameTag);

/* ---------------------------------------------------------- UPawnAllegiance ---------------------------------------------------------- */

_(FOpinionData);
_(UPawnAllegiance);

/* ---------------------------------------------------------- UBadassRewardDefinition ---------------------------------------------------------- */

_(UBadassRewardDefinition);

/* ---------------------------------------------------------- UBaseHitRegionDefinition ---------------------------------------------------------- */

_(UBaseHitRegionDefinition);

/* ---------------------------------------------------------- UBodyClassDefinition ---------------------------------------------------------- */

_(FTurnData);
_(FExtraWeaponSlot);
_(FPainDialogLine);
_(FCustomCringeData);
_(FBreathingLoopInfo);
_(FInjuredLoopOverride);
_(FVehicleCrewMappingStruct);
_(UBodyClassDefinition);

/* ---------------------------------------------------------- UTurnDefinition ---------------------------------------------------------- */

_(UTurnDefinition);

/* ---------------------------------------------------------- UInventoryPartListCollectionDefinition ---------------------------------------------------------- */

_(UInventoryPartListCollectionDefinition);

/* ---------------------------------------------------------- UWeaponPartListCollectionDefinition ---------------------------------------------------------- */

_(FWeaponCustomPartTypeData);
_(UWeaponPartListCollectionDefinition);

/* ---------------------------------------------------------- UItemPartListCollectionDefinition ---------------------------------------------------------- */

_(FItemCustomPartTypeData);
_(UItemPartListCollectionDefinition);

/* ---------------------------------------------------------- UFiringModeSoundDefinition ---------------------------------------------------------- */

_(UFiringModeSoundDefinition);

/* ---------------------------------------------------------- UExplosionCollectionDefinition ---------------------------------------------------------- */

_(FConditionalExplosionData);
_(UExplosionCollectionDefinition);

/* ---------------------------------------------------------- UHUDDefinition ---------------------------------------------------------- */

_(UHUDDefinition);

/* ---------------------------------------------------------- UGFxMovieDefinition ---------------------------------------------------------- */

_(FGFxMenuLink);
_(UGFxMovieDefinition);

/* ---------------------------------------------------------- UHashDisplayGFxDefinition ---------------------------------------------------------- */

_(UHashDisplayGFxDefinition);

/* ---------------------------------------------------------- UWillowGFxColiseumOverlayDefinition ---------------------------------------------------------- */

_(UWillowGFxColiseumOverlayDefinition);

/* ---------------------------------------------------------- UWillowGFxMovie3DDefinition ---------------------------------------------------------- */

_(UWillowGFxMovie3DDefinition);

/* ---------------------------------------------------------- UCreditsGFxDefinition ---------------------------------------------------------- */

_(FCreditsLine);
_(FCreditsTextureInfo);
_(UCreditsGFxDefinition);

/* ---------------------------------------------------------- UWeaponScopeGFxDefinition ---------------------------------------------------------- */

_(FLabelToLinkageMapping);
_(UWeaponScopeGFxDefinition);

/* ---------------------------------------------------------- UUpsellNotificationGFxMovieDefinition ---------------------------------------------------------- */

_(UUpsellNotificationGFxMovieDefinition);

/* ---------------------------------------------------------- UItemInspectionGFxMovieDefinition ---------------------------------------------------------- */

_(UItemInspectionGFxMovieDefinition);

/* ---------------------------------------------------------- UWillowGFxThirdPersonDefinition ---------------------------------------------------------- */

_(FThirdPersonMenuView);
_(UWillowGFxThirdPersonDefinition);

/* ---------------------------------------------------------- UWillowInventoryGFxDefinition ---------------------------------------------------------- */

_(UWillowInventoryGFxDefinition);

/* ---------------------------------------------------------- UTradingGFxDefinition ---------------------------------------------------------- */

_(UTradingGFxDefinition);

/* ---------------------------------------------------------- UVendingMachineExGFxDefinition ---------------------------------------------------------- */

_(UVendingMachineExGFxDefinition);

/* ---------------------------------------------------------- UUpsellGFxMovieDefinition ---------------------------------------------------------- */

_(UUpsellGFxMovieDefinition);

/* ---------------------------------------------------------- UWillowHUDGFxMovieDefinition ---------------------------------------------------------- */

_(FScaledHUDElement);
_(UWillowHUDGFxMovieDefinition);

/* ---------------------------------------------------------- UTrainingMessageDefinition ---------------------------------------------------------- */

_(UTrainingMessageDefinition);

/* ---------------------------------------------------------- UResourceDefinition ---------------------------------------------------------- */

_(UResourceDefinition);

/* ---------------------------------------------------------- UBehaviorProviderDefinition ---------------------------------------------------------- */

_(FSubarrayData);
_(FBehaviorVariableLinkData);
_(FBehaviorVariableLinkData2);
_(FBehaviorActionLinkData);
_(FBehaviorOutputLinkData);
_(FBehaviorOutputLinkData2);
_(FBehaviorEventUserData);
_(FBehaviorEventData);
_(FBehaviorEventData2);
_(FBehaviorSequenceActionData);
_(FBehaviorSequenceActionData2);
_(FBehaviorVariableValue);
_(FBehaviorVariableValueUnion_Mirror);
_(FBehaviorVariableData);
_(FBehaviorSequenceData);
_(UBehaviorProviderDefinition);

/* ---------------------------------------------------------- UBehaviorKernel ---------------------------------------------------------- */

_(FBehaviorExecutionRecord);
_(FBehaviorThread);
_(FBehaviorEventState);
_(FBehaviorVariableState);
_(FBehaviorSequenceState);
_(FBehaviorProcess);
_(FProviderRecord);
_(FBehaviorKernelArrayStats);
_(FBehaviorKernelStats);
_(UBehaviorKernel);

/* ---------------------------------------------------------- UWeaponPartListDefinition ---------------------------------------------------------- */

_(FPartGradeWeightData);
_(UWeaponPartListDefinition);

/* ---------------------------------------------------------- UEffectCollectionDefinition ---------------------------------------------------------- */

_(FConditionalParticleEffectData);
_(UEffectCollectionDefinition);

/* ---------------------------------------------------------- UFiringModeDefinition ---------------------------------------------------------- */

_(FBulletImpactEventData);
_(FBulletEventResponse);
_(FBulletTimerEvent);
_(FWaveMotionData);
_(FFiringPatternLine);
_(UFiringModeDefinition);

/* ---------------------------------------------------------- AWillowProjectile ---------------------------------------------------------- */

_(FHomingTargetedActorInfo);
_(FHitActorData);
_(AWillowProjectile);

/* ---------------------------------------------------------- AWillowServerSideProjectile ---------------------------------------------------------- */

_(AWillowServerSideProjectile);

/* ---------------------------------------------------------- UWeaponGlowEffectDefinition ---------------------------------------------------------- */

_(UWeaponGlowEffectDefinition);

/* ---------------------------------------------------------- UManufacturerDefinition ---------------------------------------------------------- */

_(FManufacturerCustomGradeWeightData);
_(FManufacturerGradeData);
_(UManufacturerDefinition);

/* ---------------------------------------------------------- UEngineInteractionIconDefinition ---------------------------------------------------------- */

_(UEngineInteractionIconDefinition);

/* ---------------------------------------------------------- UInventoryCardPresentationDefinition ---------------------------------------------------------- */

_(UInventoryCardPresentationDefinition);

_(FRecentDamageTracker);
_(UDamageTypeDefinition);

/* ---------------------------------------------------------- UWillowDamageTypeDefinition ---------------------------------------------------------- */

_(FPlayerRecentDamageEventData);
_(UWillowDamageTypeDefinition);

/* ---------------------------------------------------------- UImpactDefinition ---------------------------------------------------------- */

_(UImpactDefinition);

/* ---------------------------------------------------------- UWillowImpactDefinition ---------------------------------------------------------- */

_(UWillowImpactDefinition);

/* ---------------------------------------------------------- UWillowExplosionImpactDefinition ---------------------------------------------------------- */

_(FDecalData);
_(UWillowExplosionImpactDefinition);

/* ---------------------------------------------------------- UAttributeInitializationDefinition ---------------------------------------------------------- */

_(AttributeInitializationData);
_(BalanceFormula);
_(Variance);
_(Range);
_(ConditionalValueExpression);
_(ConditionalInitializationExpressions);
_(AttributeBaseValueData);
_(UAttributeInitializationDefinition);

/* ---------------------------------------------------------- UBehavior_AttemptStatusEffect ---------------------------------------------------------- */

_(UBehavior_AttemptStatusEffect);

/* ---------------------------------------------------------- UGameBalanceDefinition ---------------------------------------------------------- */

_(FMissionStateBalanceAdjustment);
_(FRegionBalanceData);
_(UGameBalanceDefinition);

/* ---------------------------------------------------------- UAnemoneInfectionDefinition ---------------------------------------------------------- */

_(UAnemoneInfectionDefinition);

/* ---------------------------------------------------------- UMeleeDefinition ---------------------------------------------------------- */

_(UMeleeDefinition);

/* ---------------------------------------------------------- UAttributeEffect ---------------------------------------------------------- */

_(AppliedAttributeEffect);
_(AttributeEffectData);
_(UAttributeEffect);

/* ---------------------------------------------------------- UGearboxLocationRequest ---------------------------------------------------------- */

_(UGearboxLocationRequest);

/* ---------------------------------------------------------- AWorldDiscoveryArea ---------------------------------------------------------- */

_(AWorldDiscoveryArea);

/* ---------------------------------------------------------- UBehavior_CauseDamage ---------------------------------------------------------- */

_(UBehavior_CauseDamage);

/* ---------------------------------------------------------- UGbxMessageDefinition ---------------------------------------------------------- */

_(UGbxMessageDefinition);

/* ---------------------------------------------------------- UBalanceModifierDefinition ---------------------------------------------------------- */

_(FBalanceModification);
_(FBlackMarketPostLaunchUpgradeData);
_(FMapSpecificBalanceModificationList);
_(UBalanceModifierDefinition);

/* ---------------------------------------------------------- UAttributeValueResolver ---------------------------------------------------------- */

_(UAttributeValueResolver);

/* ---------------------------------------------------------- UGlobalAttributeValueResolver ---------------------------------------------------------- */

_(UGlobalAttributeValueResolver);

/* ---------------------------------------------------------- UAmmoDropWeightAttributeValueResolver ---------------------------------------------------------- */

_(UAmmoDropWeightAttributeValueResolver);

/* ---------------------------------------------------------- UAmmoResourceUpgradeAttributeValueResolver ---------------------------------------------------------- */

_(UAmmoResourceUpgradeAttributeValueResolver);

/* ---------------------------------------------------------- URule ---------------------------------------------------------- */

_(FFlagEvalConditional);
_(FFlagEvalORConnector);
_(URule);

/* ---------------------------------------------------------- URulePlaceholder ---------------------------------------------------------- */

_(URulePlaceholder);

/* ---------------------------------------------------------- UFlagDefinition ---------------------------------------------------------- */

_(FFlagDefinitionInitialization);
_(UFlagDefinition);

/* ---------------------------------------------------------- URuleEventDef ---------------------------------------------------------- */

_(URuleEventDef);

/* ---------------------------------------------------------- UMissionDefinition ---------------------------------------------------------- */

_(FObjectiveDependencyData);
_(FRewardData);
_(UMissionDefinition);

/* ---------------------------------------------------------- UMissionObjectiveDefinition ---------------------------------------------------------- */

_(FKillMissionData);
_(UMissionObjectiveDefinition);

/* ---------------------------------------------------------- UMissionObjectiveSetDefinition ---------------------------------------------------------- */

_(UMissionObjectiveSetDefinition);

/* ---------------------------------------------------------- UCharacterClassDefinition ---------------------------------------------------------- */

_(FDamageTypeResistance);
_(UCharacterClassDefinition);

/* ---------------------------------------------------------- UWillowCharacterClassDefinition ---------------------------------------------------------- */

_(FAttributeCategory);
_(FDeathByWeaponStatID);
_(FDeathByDamageTypeStatID);
_(FDeathByWeaponDamageStatID);
_(UWillowCharacterClassDefinition);

/* ---------------------------------------------------------- UAIClassDefinition ---------------------------------------------------------- */

_(UAIClassDefinition);

/* ---------------------------------------------------------- UPlayerClassDefinition ---------------------------------------------------------- */

_(FPlayerClassAchievementUnlockData);
_(UPlayerClassDefinition);

/* ---------------------------------------------------------- UChallengeDefinition ---------------------------------------------------------- */

_(FChallengeData);
_(FConditionLevel);
_(UChallengeDefinition);

/* ---------------------------------------------------------- UAssetLibraryManager ---------------------------------------------------------- */

_(FAssetLibConfig);
_(FSKULibrarySet);
_(FSKURuntimeLibrarySet);
_(UAssetLibraryManager);

/* ---------------------------------------------------------- UGlobalsDefinition ---------------------------------------------------------- */

_(FKillSkillDuration);
_(FExpAwardWeight);
_(FLevelBasedExpScale);
_(FRarityLevelColor);
_(FLevelBasedDamageScale);
_(FLevelBasedStatusEffectChanceScale);
_(FStatusEffectTypeCommonProperties);
_(FPlayThroughData);
_(FSlaughterMissionChain);
_(FInputContextData);
_(UGlobalsDefinition);

/* ---------------------------------------------------------- USkillDefinition ---------------------------------------------------------- */

_(FBonusAttributeModifierUpgrade);
_(FSkillEffectData);
_(FSkillConstraintData);
_(FSkillDamagedEventConstraintData);
_(FSkillActionData);
_(FSkillEventResponseData);
_(FNamedSkillEvent);
_(FSkillDamageEventData);
_(FSkillKillEventData);
_(USkillDefinition);

/* ---------------------------------------------------------- USkill ---------------------------------------------------------- */

_(FAppliedSkillEffect);
_(USkill);

/* ---------------------------------------------------------- UInteractiveObjectDefinition ---------------------------------------------------------- */

_(UInteractiveObjectDefinition);

/* ---------------------------------------------------------- UBodyHitRegionDefinition ---------------------------------------------------------- */

_(FGoreTriggerData);
_(FDamageReactionData);
_(UBodyHitRegionDefinition);

/* ---------------------------------------------------------- UCurrencyAttributeValueResolver ---------------------------------------------------------- */

_(FCurrencyState);
_(UCurrencyAttributeValueResolver);

/* ---------------------------------------------------------- UAttributeContextResolver ---------------------------------------------------------- */

_(UAttributeContextResolver);

/* ---------------------------------------------------------- UAttributeDefinitionBase ---------------------------------------------------------- */

_(FAttributePriorityData);
_(UAttributeDefinitionBase);

/* ---------------------------------------------------------- UAttributeDefinitionMultiContext ---------------------------------------------------------- */

_(UAttributeDefinitionMultiContext);

/* ---------------------------------------------------------- UAttributePresentationDefinition ---------------------------------------------------------- */

_(FAttributePresentationValueRemappingData);
_(FModifierValuePresentationData);
_(UAttributePresentationDefinition);

/* ---------------------------------------------------------- UProjectileDefinition ---------------------------------------------------------- */

_(FHomingRadiusThreshold);
_(UProjectileDefinition);

/* ---------------------------------------------------------- UIUpdatePostProcessOverride ---------------------------------------------------------- */

_(FPostProcessOverlay);
_(FAttributeDefinitionDefault);
_(FAttributeScalarParam);
_(FMaterialEffectModifier);
_(FDOFEffectData);
_(FDOFEffectModifierData);
_(FPostProcessChainOptions);
_(FPostProcessChainRecord);
_(UIUpdatePostProcessOverride);

/* ---------------------------------------------------------- UGearboxGlobals ---------------------------------------------------------- */

_(FVantageSpot);
_(FObjectKey);
_(FLevelStateRecord);
_(FValidNameRange);
_(FLocationInfo);
_(FPopulationActor);
_(FCoverCandidate);
_(FCoverDebugScoringInfo);
_(FCoverDebugPriority);
_(FGearboxCoverState);
_(FGearboxCoverTransition);
_(UGearboxGlobals);

/* ---------------------------------------------------------- UGearboxCoverStateManager ---------------------------------------------------------- */

_(FCoverSpotInfo);
_(UGearboxCoverStateManager);

/* ---------------------------------------------------------- UWillowGlobals ---------------------------------------------------------- */

_(FLoadingMovieExceptionInfo);
_(UWillowGlobals);

/* ---------------------------------------------------------- UIScreenParticle ---------------------------------------------------------- */

_(FScreenParticleModifier);
_(FScreenParticleScalarParamOverTime);
_(FScreenParticleVectorParamOverTime);
_(FScreenParticleParamOverTime);
_(FScreenParticleRecord);
_(FScreenParticleInitParams);
_(UIScreenParticle);

/* ---------------------------------------------------------- UStatusEffectDefinition ---------------------------------------------------------- */

_(FDamageSurfaceTypeModifier);
_(UStatusEffectDefinition);

/* ---------------------------------------------------------- UWillowInventoryDefinition ---------------------------------------------------------- */

_(UIStatData);
_(AttributeSlotEffectData);
_(AttributeSlotUpgradeData);
_(UWillowInventoryDefinition);

/* ---------------------------------------------------------- UItemDefinition ---------------------------------------------------------- */

_(FItemBehaviorSet);
_(UItemDefinition);

/* ---------------------------------------------------------- UUsableItemDefinition ---------------------------------------------------------- */

_(UUsableItemDefinition);

/* ---------------------------------------------------------- UEquipableItemDefinition ---------------------------------------------------------- */

_(UEquipableItemDefinition);

/* ---------------------------------------------------------- UGrenadeModDefinition ---------------------------------------------------------- */

_(FGrenadeModBehaviorSequenceStateData);
_(UGrenadeModDefinition);

/* ---------------------------------------------------------- UShieldDefinition ---------------------------------------------------------- */

_(UShieldDefinition);

/* ---------------------------------------------------------- UClassModDefinition ---------------------------------------------------------- */

_(UClassModDefinition);

/* ---------------------------------------------------------- UItemPoolDefinition ---------------------------------------------------------- */

_(FBalancedInventoryData);
_(UItemPoolDefinition);

/* ---------------------------------------------------------- UKeyedItemPoolDefinition ---------------------------------------------------------- */

_(UKeyedItemPoolDefinition);

/* ---------------------------------------------------------- UItemPool ---------------------------------------------------------- */

_(FItemPoolInfo);
_(UItemPool);

/* ---------------------------------------------------------- UItemPoolListDefinition ---------------------------------------------------------- */

_(UItemPoolListDefinition);

/* ---------------------------------------------------------- UWillowInventoryPartDefinition ---------------------------------------------------------- */

_(UWillowInventoryPartDefinition);

/* ---------------------------------------------------------- UWeaponPartDefinition ---------------------------------------------------------- */

_(UWeaponPartDefinition);

/* ---------------------------------------------------------- UWeaponNamePartDefinition ---------------------------------------------------------- */

_(UWeaponNamePartDefinition);

/* ---------------------------------------------------------- UItemPartDefinition ---------------------------------------------------------- */

_(UItemPartDefinition);

/* ---------------------------------------------------------- UEquipableItemPartDefinition ---------------------------------------------------------- */

_(UEquipableItemPartDefinition);

/* ---------------------------------------------------------- UGrenadeModPartDefinition ---------------------------------------------------------- */

_(FGrenadeModPartBehaviorSequenceStateData);
_(UGrenadeModPartDefinition);

/* ---------------------------------------------------------- UShieldPartDefinition ---------------------------------------------------------- */

_(UShieldPartDefinition);

/* ---------------------------------------------------------- UUsableItemPartDefinition ---------------------------------------------------------- */

_(UUsableItemPartDefinition);

/* ---------------------------------------------------------- UItemNamePartDefinition ---------------------------------------------------------- */

_(UItemNamePartDefinition);

/* ---------------------------------------------------------- UItemPartListDefinition ---------------------------------------------------------- */

_(FItemPartGradeWeightData);
_(UItemPartListDefinition);

/* ---------------------------------------------------------- UPlayerClassIdentifierDefinition ---------------------------------------------------------- */

_(FCustomizationItemData);
_(UPlayerClassIdentifierDefinition);

/* ---------------------------------------------------------- UAttributeDefinition ---------------------------------------------------------- */

_(UAttributeDefinition);

/* ---------------------------------------------------------- UDesignerAttributeDefinition ---------------------------------------------------------- */

_(UDesignerAttributeDefinition);

/* ---------------------------------------------------------- USequenceVariable ---------------------------------------------------------- */

_(USequenceVariable);

/* ---------------------------------------------------------- USequenceOp ---------------------------------------------------------- */

_(FSeqOpInputLink);
_(FSeqOpOutputInputLink);
_(FSeqOpOutputLink);
_(FSeqVarLink);
_(FSeqEventLink);
_(USequenceOp);

/* ---------------------------------------------------------- USequence ---------------------------------------------------------- */

_(FActivateOp);
_(FQueuedActivationInfo);
_(USequence);

/* ---------------------------------------------------------- USequenceEvent ---------------------------------------------------------- */

_(USequenceEvent);

/* ---------------------------------------------------------- USeqEvent_TakeDamage ---------------------------------------------------------- */

_(USeqEvent_TakeDamage);

/* ---------------------------------------------------------- USequenceEventCustomEnableCondition ---------------------------------------------------------- */

_(USequenceEventCustomEnableCondition);

/* ---------------------------------------------------------- USeqEvent_TakeHitRegionDamage ---------------------------------------------------------- */

_(USeqEvent_TakeHitRegionDamage);

/* ---------------------------------------------------------- USequenceAction ---------------------------------------------------------- */

_(USequenceAction);

/* ---------------------------------------------------------- USeqAct_ExecuteSkill ---------------------------------------------------------- */

_(USeqAct_ExecuteSkill);

/* ---------------------------------------------------------- USeqAct_Latent ---------------------------------------------------------- */

_(USeqAct_Latent);

/* ---------------------------------------------------------- ATrigger ---------------------------------------------------------- */

_(ATrigger);

/* ---------------------------------------------------------- AInteractionProxy ---------------------------------------------------------- */

_(AInteractionProxy);

/* ---------------------------------------------------------- APawnInteractionProxy ---------------------------------------------------------- */

_(APawnInteractionProxy);

/* ---------------------------------------------------------- ALight ---------------------------------------------------------- */

_(ALight);

/* ---------------------------------------------------------- APointLight ---------------------------------------------------------- */

_(APointLight);
_(ADominantPointLight);
_(APointLightMovable);
_(APointLightToggleable);
_(ASkyLight);
_(ASkyLightToggleable);
_(ALightShafts);
_(ADirectionalLight);
_(ADirectionalLightToggleable);
_(ADominantDirectionalLight);
_(ADominantDirectionalLightMovable);


_(FConsoleMessage);
_(FKismetDrawTextInfo);
_(AHUD);
_(AGearboxHUD);
_(IInterface_NavigationHandle);
_(FBox);

_(FBoxSphereBounds);

_(FNavigationOctreeObject);
_(FGuid);

/* ---------------------------------------------------------- ANavigationPoint ---------------------------------------------------------- */

_(ANavigationPoint_FCheckpointRecord);
_(FAreaTestSortedPoint);
_(ANavigationPoint);

/* ---------------------------------------------------------- ATeleporter ---------------------------------------------------------- */

_(ATeleporter);

/* ---------------------------------------------------------- APlayerStart ---------------------------------------------------------- */

_(APlayerStart);

/* ---------------------------------------------------------- APortalMarker ---------------------------------------------------------- */

_(APortalMarker);

/* ---------------------------------------------------------- APylon ---------------------------------------------------------- */

_(FNavMeshPathSize);
_(FPolyReference);
_(APylon);

/* ---------------------------------------------------------- ADynamicPylon ---------------------------------------------------------- */

_(ADynamicPylon);

/* ---------------------------------------------------------- ALadder ---------------------------------------------------------- */

_(ALadder);

/* ---------------------------------------------------------- ACoverLink ---------------------------------------------------------- */

_(FCoverReference);
_(FCoverInfo);
_(FCovPosInfo);
_(FFireLinkItem);
_(FFireLink);
_(FDynamicLinkInfo);
_(FExposedLink);
_(FSlotMoveRef);
_(FCoverSlot);
_(ACoverLink);

/* ---------------------------------------------------------- UWillowAIComponent ---------------------------------------------------------- */

_(FCombatZone);
_(FCoverExposureData);
_(FCombatZoneSearchData);
_(FCombatPointSearchData);
_(FCombatPointData);
_(FCombatPointDebugData);
_(UWillowAIComponent);


_(FPathStore);
_(FNavMeshPathParams);
_(UNavigationHandle);

_(FClientAdjustment);
_(FConnectedPeerInfo);
_(FInputEntry);
_(FInputMatchRequest);
_(FDebugTextInfo);

/* ---------------------------------------------------------- AController ---------------------------------------------------------- */

_(AController_eventNotifyHitWall_Parms);
_(FVisiblePortalInfo);
_(AController);

/* ---------------------------------------------------------- AAIController ---------------------------------------------------------- */

_(AAIController);

/* ---------------------------------------------------------- AGearboxAIController ---------------------------------------------------------- */

_(AGearboxAIController);

/* ---------------------------------------------------------- AGearboxMind ---------------------------------------------------------- */

_(FTargetIteratorData);
_(AGearboxMind);

/* ---------------------------------------------------------- AWillowMind ---------------------------------------------------------- */

_(AWillowMind);

_(FScriptInterface);
_(FFadePickupParticle);
_(FHUDWidget_ChallengeData);

_(FInteractionIconWithOverrides);
_(UInteractionIconDefinition);

/* ---------------------------------------------------------- UWillowHUDGFxMovie ---------------------------------------------------------- */

_(FTrackedSkillIconState);
_(FCriticalTextMessage);
_(FCriticalTextMessageArray);
_(FHUDInteractionIcon);
_(FAvailableTrackedSkill);
_(FInjuredStringReplacementSet);
_(UWillowHUDGFxMovie);

_(AWillowHUD);

_(TScriptInterface);
_(APlayerController);

/* ---------------------------------------------------------- ADebugCameraController ---------------------------------------------------------- */

_(ADebugCameraController);

/* ---------------------------------------------------------- AGamePlayerController ---------------------------------------------------------- */

_(AGamePlayerController);

/* ---------------------------------------------------------- AGearboxPlayerController ---------------------------------------------------------- */

_(FGearboxViewShakeInfo);
_(AGearboxPlayerController);

/* ---------------------------------------------------------- UOnlineGameSearch ---------------------------------------------------------- */

_(FOnlineGameSearchResult);
_(FOverrideSkill);
_(FNamedObjectProperty);
_(FOnlineGameSearchParameter);
_(FOnlineGameSearchSortClause);
_(FOnlineGameSearchORClause);
_(FOnlineGameSearchQuery);
_(UOnlineGameSearch);

/* ---------------------------------------------------------- UMeshBeaconClient ---------------------------------------------------------- */

_(FClientConnectionRequest);
_(FClientBandwidthTestData);
_(UMeshBeaconClient);

/* ---------------------------------------------------------- UMeshBeaconHost ---------------------------------------------------------- */

_(FClientConnectionBandwidthTestData);
_(FClientMeshBeaconConnection);
_(UMeshBeaconHost);

/* ---------------------------------------------------------- ULANServerBrowserGFxMovie ---------------------------------------------------------- */

_(FResultEntry);
_(ULANServerBrowserGFxMovie);

/* ---------------------------------------------------------- AWillowPlayerController ---------------------------------------------------------- */

_(FPostProcessOverlayInfo);
_(FSpeedKillData);
_(FLungeData);
_(FLurchData);
_(FMissionPlaythroughData);
_(FRecentlyResistedAttackData);
_(FStatusMenuMissionEligibilityData);
_(FTrainingData);
_(FTaggedGFxMovie);
_(FCustomizationUnlockData);
_(FPendingClientTrainingMessage);
_(FPendingMissionRewardsData);
_(AWillowPlayerController);

/* ---------------------------------------------------------- UWeaponTypeDefinition ---------------------------------------------------------- */

_(FConditionalAnimationData);
_(FNameExpressionData);
_(FWeaponPartAttachmentData);
_(UWeaponTypeDefinition);

_(FURL);

_(FSeamlessTravelHandler);

_(ULevelBase);
_(FLevelGuids);

/* ---------------------------------------------------------- UMetaData ---------------------------------------------------------- */

_(UMetaData);

_(ATeamInfo);

_(FKeyValuePair);
_(FPlayerResponseLine);
_(FServerResponseLine);

/* ---------------------------------------------------------- AInfo ---------------------------------------------------------- */

_(AInfo);

/* ---------------------------------------------------------- AHeightFog ---------------------------------------------------------- */

_(AHeightFog);

/* ---------------------------------------------------------- APotentialClimbWatcher ---------------------------------------------------------- */

_(APotentialClimbWatcher);

/* ---------------------------------------------------------- AInternetLink ---------------------------------------------------------- */

_(FIpAddr);
_(AInternetLink);

/* ---------------------------------------------------------- ACoverGroup ---------------------------------------------------------- */

_(ACoverGroup);

/* ---------------------------------------------------------- ARoute ---------------------------------------------------------- */

_(ARoute);

/* ---------------------------------------------------------- APopulationOpportunity ---------------------------------------------------------- */

_(FOpportunityCleanupParameters);
_(FOpportunitySavedState);
_(APopulationOpportunity);

_(FEncounterLimitState);
_(FEncounterLimitData);
_(FSpawnOption);
_(FEncounterWaveData);
_(APopulationEncounter);

/* ---------------------------------------------------------- UPopulationMaster ---------------------------------------------------------- */

_(FSpawnedPopulationActor);
_(FRemovedPopulationActor);
_(FPopulationMasterStat);
_(FPopulationOpportunityStat);
_(FPopulationOpportunitySavedActor);
_(FPopulationOpportunityTracker);
_(FEncounterWaveTracker);
_(FEncounterTracker);
_(UPopulationMaster);

/* ---------------------------------------------------------- AWorldSoundManager ---------------------------------------------------------- */

_(FWorldEventSource);
_(AWorldSoundManager);

/* ---------------------------------------------------------- AWillowWorldSoundManager ---------------------------------------------------------- */

_(AWillowWorldSoundManager);

/* ---------------------------------------------------------- AWillowBaseStats ---------------------------------------------------------- */

_(FWillowStatProperty);
_(AWillowBaseStats);

/* ---------------------------------------------------------- AWillowPlayerStats ---------------------------------------------------------- */

_(AWillowPlayerStats);

_(AZoneInfo);
_(FLevelGroup);
_(FNetViewer);
_(FCompartmentRunList);
_(FPhysXSimulationProperties);
_(FPhysXSceneProperties);
_(FApexModuleDestructibleSettings);
_(FPhysXEmitterVerticalProperties);
_(FPhysXVerticalProperties);
_(FWorldFractureSettings);
_(FScreenMessageString);
_(FLightmassWorldInfoSettings);
_(FNavMeshPathConstraintCacheDatum);
_(FNavMeshPathGoalEvaluatorCacheDatum);
_(FHostMigrationState);
_(FNavigationArea);

/* ---------------------------------------------------------- USurface ---------------------------------------------------------- */

_(USurface);

/* ---------------------------------------------------------- UMaterialInterface ---------------------------------------------------------- */

_(FLightmassMaterialInterfaceSettings);
_(UMaterialInterface);

/* ---------------------------------------------------------- UMaterial ---------------------------------------------------------- */

_(FMaterialInput);
_(FColorMaterialInput);
_(FScalarMaterialInput);
_(FVectorMaterialInput);
_(FVector2MaterialInput);
_(UMaterial);

/* ---------------------------------------------------------- UMaterialInstance ---------------------------------------------------------- */

_(FStaticSwitchParameter);
_(FStaticComponentMaskParameter);
_(FNormalParameter);
_(FStaticTerrainLayerWeightParameter);
_(FStaticParameterSet);
_(UMaterialInstance);

/* ---------------------------------------------------------- UMaterialInstanceConstant ---------------------------------------------------------- */

_(FFontParameterValue);
_(FScalarParameterValue);
_(FTextureParameterValue);
_(FVectorParameterValue);
_(UMaterialInstanceConstant);

_(UFogVolumeDensityComponent);
_(ULightFunction);

/* ---------------------------------------------------------- ULightEnvironmentComponent ---------------------------------------------------------- */

_(ULightEnvironmentComponent);

/* ---------------------------------------------------------- UDynamicLightEnvironmentComponent ---------------------------------------------------------- */

_(UDynamicLightEnvironmentComponent);

_(LightingChannelContainer);

/* ---------------------------------------------------------- UPrimitiveComponent ---------------------------------------------------------- */

_(FMaterialViewRelevance);
_(FRBCollisionChannelContainer);
_(UPrimitiveComponent);

/* ---------------------------------------------------------- USpriteComponent ---------------------------------------------------------- */

_(USpriteComponent);

/* ---------------------------------------------------------- UBrushComponent ---------------------------------------------------------- */

_(FKCachedConvexData_Mirror);
_(UBrushComponent);

/* ---------------------------------------------------------- UDrawFrustumComponent ---------------------------------------------------------- */

_(UDrawFrustumComponent);

/* ---------------------------------------------------------- UDrawConeComponent ---------------------------------------------------------- */

_(UDrawConeComponent);

/* ---------------------------------------------------------- UDrawLightConeComponent ---------------------------------------------------------- */

_(UDrawLightConeComponent);

/* ---------------------------------------------------------- ULineBatchComponent ---------------------------------------------------------- */

_(FConvexVolume);
_(FTemporalAAParameters);
_(FDepthOfFieldParams);
_(FLightChannelInfo);
_(FLightChannelAllocator);
_(FSceneView);
_(FPrimitiveDrawInterface);
_(FLine);
_(FPoint);
_(ULineBatchComponent);

/* ---------------------------------------------------------- UArrowComponent ---------------------------------------------------------- */

_(UArrowComponent);

/* ---------------------------------------------------------- UDecalComponent ---------------------------------------------------------- */

_(FDecalReceiver);
_(UDecalComponent);

/* ---------------------------------------------------------- UMeshComponent ---------------------------------------------------------- */

_(UMeshComponent);

/* ---------------------------------------------------------- UStaticMeshComponent ---------------------------------------------------------- */

_(FPaintedVertex);
_(FStaticMeshComponentLODInfo);
_(UStaticMeshComponent);

/* ---------------------------------------------------------- USkeletalMeshComponent ---------------------------------------------------------- */

_(FGestaltLODModelFragment);
_(FGestaltLODModel);
_(FSocketRemapEntry);
_(FGestaltAccessoryEntry);
_(FGestaltDataContainer);
_(FActiveMorph);
_(FAttachment);
_(FBonePair);
_(FSkelMeshComponentLODInfo);
_(USkeletalMeshComponent);

/* ---------------------------------------------------------- UGearLikenessMeshComponent ---------------------------------------------------------- */

_(UGearLikenessMeshComponent);

/* ---------------------------------------------------------- UGearboxSkeletalMeshComponent ---------------------------------------------------------- */

_(UGearboxSkeletalMeshComponent);

/* ---------------------------------------------------------- ULensFlareComponent ---------------------------------------------------------- */

_(FLensFlareElementInstance);
_(FLensFlareElementMaterials);
_(ULensFlareComponent);

/* ---------------------------------------------------------- UParticleSystemComponent ---------------------------------------------------------- */

_(FParticleEmitterInstance);
_(FParticleEmitterInstanceMotionBlurInfo);
_(FViewParticleEmitterInstanceMotionBlurInfo);
_(FParticleSysParam);
_(FParticleEventData);
_(FParticleEventSpawnData);
_(FParticleEventDeathData);
_(FParticleEventCollideData);
_(FParticleEventTraceData);
_(FParticleEventKismetData);
_(UParticleSystemComponent);

/* ---------------------------------------------------------- UCylinderComponent ---------------------------------------------------------- */

_(UCylinderComponent);

/* ---------------------------------------------------------- USphereComponent ---------------------------------------------------------- */

_(USphereComponent);

/* ---------------------------------------------------------- UBulletListenerComponent ---------------------------------------------------------- */

_(UBulletListenerComponent);

/* ---------------------------------------------------------- UDrawSphereComponent ---------------------------------------------------------- */

_(UDrawSphereComponent);

/* ---------------------------------------------------------- UDrawLightRadiusComponent ---------------------------------------------------------- */

_(UDrawLightRadiusComponent);

_(IAppearanceBehavior);

/* ---------------------------------------------------------- ULightComponent ---------------------------------------------------------- */

_(ULightComponent);

/* ---------------------------------------------------------- UDirectionalLightComponent ---------------------------------------------------------- */

_(UDirectionalLightComponent);

/* ---------------------------------------------------------- UDominantDirectionalLightComponent ---------------------------------------------------------- */

_(UDominantDirectionalLightComponent);

/* ---------------------------------------------------------- UPointLightComponent ---------------------------------------------------------- */

_(UPointLightComponent);

/* ---------------------------------------------------------- USpotLightComponent ---------------------------------------------------------- */

_(USpotLightComponent);

/* ---------------------------------------------------------- UWillowPointLight ---------------------------------------------------------- */

_(FLightValues);
_(UWillowPointLight);

_(FReverbSettings);
_(FInteriorSettings);
_(AReverbVolume);

/* ---------------------------------------------------------- UAudioComponent ---------------------------------------------------------- */

_(FAudioComponentParam);
_(FWaveInstance);
_(UAudioComponent);

/* ---------------------------------------------------------- UAudioDevice ---------------------------------------------------------- */

_(FListener);
_(FAudioClassInfo);
_(UAudioDevice);

_(FLUTBlender);
_(FPostProcessSettings);

_(FRawDistribution);
_(FRawDistributionFloat);
_(FRawDistributionVector);

_(AMutator);
_(AAutoTestManager);

/* ---------------------------------------------------------- AReplicationInfo ---------------------------------------------------------- */

_(AReplicationInfo);

_(FManualCoverTypeInfo);
_(FCoverReplicationInfo);
_(ACoverReplicator);

/* ---------------------------------------------------------- AWillowVersusDuelInfo ---------------------------------------------------------- */

_(FTempWeaponStruct);
_(FTempProfileStruct);
_(AWillowVersusDuelInfo);

/* ---------------------------------------------------------- UResourcePoolDefinition ---------------------------------------------------------- */

_(UResourcePoolDefinition);

/* ---------------------------------------------------------- UResourcePool ---------------------------------------------------------- */

_(UResourcePool);

/* ---------------------------------------------------------- UShieldResourcePool ---------------------------------------------------------- */

_(UShieldResourcePool);

/* ---------------------------------------------------------- UExperienceResourcePool ---------------------------------------------------------- */

_(UExperienceResourcePool);

/* ---------------------------------------------------------- UAmmoResourcePool ---------------------------------------------------------- */

_(UAmmoResourcePool);

/* ---------------------------------------------------------- UResourcePoolManager ---------------------------------------------------------- */

_(FResourcePoolIdentityState);
_(FRarelyChangedPoolState);
_(AResourcePoolManager);

_(AGameReplicationInfo);

/* ---------------------------------------------------------- AWillowGameReplicationInfo ---------------------------------------------------------- */

_(FActiveWaypointData);
_(FActiveAreaWaypointData);
_(AWillowGameReplicationInfo);

_(ACrowdPopulationManagerBase);

_(FArchive);

/* ---------------------------------------------------------- FArchiveTagUsedNonRecursive ---------------------------------------------------------- */

_(FArchiveTagUsedNonRecursive);

/* ---------------------------------------------------------- FArchiveFileReaderWindows ---------------------------------------------------------- */

_(FArchiveFileReaderWindows);

_(FSerializableObject);

/* ---------------------------------------------------------- FAsyncLineCheckmanager ---------------------------------------------------------- */

_(FAsyncLineCheckmanager);

/* ---------------------------------------------------------- FRBPhysScene ---------------------------------------------------------- */

_(FRBPhysScene);

_(UObjectSerializer);

_(FPatchReader);
_(FPatchData);
_(FScriptPatchData);
_(FEnumPatchData);
_(FObjectExport);
_(FObjectImport);

/* ---------------------------------------------------------- UTexture ---------------------------------------------------------- */

_(FTextureGroupContainer);
_(UTexture);

/* ---------------------------------------------------------- UTextureRenderTarget ---------------------------------------------------------- */

_(UTextureRenderTarget);

/* ---------------------------------------------------------- UTextureRenderTarget2D ---------------------------------------------------------- */

_(UTextureRenderTarget2D);

/* ---------------------------------------------------------- UTextureMovie ---------------------------------------------------------- */

_(UTextureMovie);

/* ---------------------------------------------------------- UTexture2D ---------------------------------------------------------- */

_(FTexture2DMipMap);
_(FTextureLinkedListMirror);
_(UTexture2D);

_(FGenerationInfo);
_(FCompressedChunk);
_(FThreadSafeCounter);
_(FResourceBulkDataInterface);
_(FTexture2DResourceMem);
_(FTextureType);

_(AInventory);

_(FAttributeSlotData);
_(FInventorySerialNumber);
_(AWillowInventory);

/* ---------------------------------------------------------- UWillowInventoryStorage ---------------------------------------------------------- */

_(FChestData);
_(UWillowInventoryStorage);

/* ---------------------------------------------------------- UWillowItemTypes ---------------------------------------------------------- */

_(FItemDefinitionData);
_(FItemMemento);
_(UWillowItemTypes);

/* ---------------------------------------------------------- AWeapon ---------------------------------------------------------- */

_(AWeapon_eventGetPhysicalFireStartLoc_Parms);
_(AWeapon);

_(FReplicatedInventoryCardData);

/* ---------------------------------------------------------- AWillowWeapon ---------------------------------------------------------- */

_(FLockOnTargetStateStruct);
_(FWeaponBoneControllerInstance);
_(FShellCasingImpact);
_(AWillowWeapon);

/* ---------------------------------------------------------- AInventoryManager ---------------------------------------------------------- */

_(AInventoryManager);

/* ---------------------------------------------------------- AWillowInventoryManager ---------------------------------------------------------- */

_(AWillowInventoryManager);

_(FDebugNavCost);

/* ---------------------------------------------------------- FStateFrame ---------------------------------------------------------- */

_(FStateFrame);
_(UObjectVtbl);

/* ---------------------------------------------------------- AWorldInfo ---------------------------------------------------------- */

_(AWorldInfo);

_(FGameTypePrefix);
_(FGameClassShortName);

/* ---------------------------------------------------------- AGameInfo ---------------------------------------------------------- */

_(AGameInfo);
_(FInterval);
_(FSHA1);
_(ULinker);
_(ULinkerLoad);

/* ---------------------------------------------------------- UPackage ---------------------------------------------------------- */

_(UPackage);
_(FTextureAllocations);
_(FPackageFileSummary);

/* ---------------------------------------------------------- AGearboxGameInfo ---------------------------------------------------------- */

_(AGearboxGameInfo);

/* ---------------------------------------------------------- AWillowGameInfo ---------------------------------------------------------- */

_(FWaypointActorData);
_(FAreaWaypointData);
_(FColiseumStat);
_(FColiseumPlayerInfo);
_(AWillowGameInfo);

/* ---------------------------------------------------------- UGearboxPlayerInput ---------------------------------------------------------- */

_(UGearboxPlayerInput);

_(DamagePipeline);

_(FTexture2D);
_(FMaterialFileHeader);
_(FBaseMaterialData);
_(FMaterialData);

_(UConst);

_(Commandlet_eventMain_Parms);
_(UCommandlet);
_(UHelpCommandlet);
_(USystem);

/* ---------------------------------------------------------- UInterface ---------------------------------------------------------- */

_(UInterface);

/* ---------------------------------------------------------- UISimpleAnimPlayer ---------------------------------------------------------- */

_(FSimpleAnimData);
_(FSimpleAnimStateData);
_(UISimpleAnimPlayer);

/* ---------------------------------------------------------- UISkillTreeListener ---------------------------------------------------------- */

_(UISkillTreeListener);

/* ---------------------------------------------------------- UIDamageCauser ---------------------------------------------------------- */

_(UIDamageCauser);

/* ---------------------------------------------------------- UIKilledBehavior ---------------------------------------------------------- */

_(UIKilledBehavior);

/* ---------------------------------------------------------- UIProjectileBehavior ---------------------------------------------------------- */

_(UIProjectileBehavior);

/* ---------------------------------------------------------- UIGFxActorMovie ---------------------------------------------------------- */

_(UIGFxActorMovie);

/* ---------------------------------------------------------- UIShop ---------------------------------------------------------- */

_(FShopItemData);
_(UIShop);

/* ---------------------------------------------------------- UIMissionDirector ---------------------------------------------------------- */

_(FMissionDirectorData);
_(UIMissionDirector);

/* ---------------------------------------------------------- UIMission ---------------------------------------------------------- */

_(FObjectiveStatusData);
_(FMissionData);
_(FMissionStatusPlayerData);
_(FMissionRewardData);
_(FUnloadableDlcMissionStatusData);
_(FMissionStatusData);
_(FReplicatedMissionDirectiveData);
_(FReplicatedMissionData);
_(FReplicatedMissionStatusData);
_(FReplicatedMissionObjectiveData);
_(FReplicatedMissionFilterData);
_(FMissionRewardPresentationData);
_(UIMission);

/* ---------------------------------------------------------- UILootable ---------------------------------------------------------- */

_(FSpawnedAttachedLootData);
_(FSpawnedDroppedLootData);
_(UILootable);

/* ---------------------------------------------------------- UIUsable ---------------------------------------------------------- */

_(UIUsable);

/* ---------------------------------------------------------- UICounterBehavior ---------------------------------------------------------- */

_(FCounterEventReactionData);
_(FBehaviorCounterState);
_(FCounterBehaviorUserState);
_(UICounterBehavior);

/* ---------------------------------------------------------- UIBehaviorProvider ---------------------------------------------------------- */

_(FSpecializedBehaviorEvent);
_(UIBehaviorProvider);

/* ---------------------------------------------------------- UINounAttributeProvider ---------------------------------------------------------- */

_(FNounAttributeState);
_(FReplicatedNounAttributeState);
_(UINounAttributeProvider);

/* ---------------------------------------------------------- UIBodyCompositionInstance ---------------------------------------------------------- */

_(FReplicatedCoordinatedEffect);
_(UIBodyCompositionInstance);

/* ---------------------------------------------------------- UIMeleeAttacker ---------------------------------------------------------- */

_(FMeleeOverTimeState);
_(UIMeleeAttacker);

/* ---------------------------------------------------------- UGearboxDialogInterface ---------------------------------------------------------- */

_(FGearboxDialogData);
_(FGearboxDialogReplicatedData);
_(UGearboxDialogInterface);

/* ---------------------------------------------------------- USpecialMoveInterface ---------------------------------------------------------- */

_(FSpecialMoveData);
_(FReplicatedSpecialMoveData);
_(USpecialMoveInterface);

/* ---------------------------------------------------------- UAnimNodeSpecialMoveBlend ---------------------------------------------------------- */

_(FSlotAnimParameters);
_(UAnimNodeSpecialMoveBlend);

/* ---------------------------------------------------------- UIInstanceData ---------------------------------------------------------- */

_(FComponentData);
_(FInstanceDataUnion);
_(FInstanceDataSet);
_(FReplicatedInstanceDataState);
_(UIInstanceData);

/* ---------------------------------------------------------- AWillowPopulationPoint ---------------------------------------------------------- */

_(AWillowPopulationPoint);

/* ---------------------------------------------------------- UInstanceDataHelper ---------------------------------------------------------- */

_(FBodyInstanceDataUnion);
_(FBodyCompositionData);
_(UInstanceDataHelper);

_(FInfoBarData);
_(UITargetable);

_(IIWeaponBoneController);

_(UIBalancedActor);
_(UIAttributeSlotEffectProvider);
_(UIItemCardable);

/* ---------------------------------------------------------- UIBehaviorConsumer ---------------------------------------------------------- */

_(FBehaviorConsumerHandle);
_(FReplicatedBehaviorEvent);
_(FReplicatedBehaviorConsumerState);
_(UIBehaviorConsumer);

/* ---------------------------------------------------------- AChallengeManager ---------------------------------------------------------- */

_(AChallengeManager);

/* ---------------------------------------------------------- UBehaviorSequenceCustomEnableCondition ---------------------------------------------------------- */

_(FLinkedBehaviorSequence);
_(UBehaviorSequenceCustomEnableCondition);

/* ---------------------------------------------------------- UBehaviorSequenceEnableByMission ---------------------------------------------------------- */

_(FMissionStateSelectionData);
_(FMissionObjectiveStateSelectionData);
_(UBehaviorSequenceEnableByMission);

/* ---------------------------------------------------------- UVendingMachineExGFxMovie ---------------------------------------------------------- */

_(UVendingMachineExGFxMovie);

/* ---------------------------------------------------------- AMissionTracker ---------------------------------------------------------- */

_(FMissionSetData);
_(FMissionObserversData);
_(FMissionWaypointsData);
_(FLevelTransitionData);
_(FTimedMissionData);
_(FDefendMissionData);
_(FDefendTargetData);
_(FBlockedMissionData);
_(FObjectiveUpdateData);
_(FMinimapIconHelper_Director);
_(FMissionKickoffData);
_(AMissionTracker);

/* ---------------------------------------------------------- ABlackMarketUpgradeManager ---------------------------------------------------------- */

_(ABlackMarketUpgradeManager);

/* ---------------------------------------------------------- UITimerBehavior ---------------------------------------------------------- */

_(FTimerEventReactionData);
_(FBehaviorTimerState);
_(FTimerBehaviorUserState);
_(UITimerBehavior);

/* ---------------------------------------------------------- UGestaltPartMatrices ---------------------------------------------------------- */

_(GestaltAccessoryPartEntry);
_(GestaltAccessoryGroupEntry);
_(GestaltAccessoryMeshEntry);
_(UGestaltPartMatrices);

/* ---------------------------------------------------------- UWillowWeaponTypes ---------------------------------------------------------- */

_(FWeaponAccessorySetup);
_(FWeaponDefinitionData);
_(FWeaponMemento);
_(FWeaponBoneControllerData);
_(FExtraMuzzleEffect);
_(UWillowWeaponTypes);

/* ---------------------------------------------------------- AWillowTradeManager ---------------------------------------------------------- */

_(FTradeSlot);
_(AWillowTradeManager);

/* ---------------------------------------------------------- APlayerStandIn ---------------------------------------------------------- */

_(APlayerStandIn);

/* ---------------------------------------------------------- UPlayerSaveGame ---------------------------------------------------------- */

_(FSkillSaveGameData);
_(FResourceSaveGameData);
_(FInventorySaveGameData);
_(FUnloadableDlcItemSaveGameData);
_(FWeaponSaveGameData);
_(FUnloadableDlcWeaponSaveGameData);
_(FInventorySlotSaveGameData);
_(FMissionPlaythroughSaveGameData);
_(FUnloadableDlcEchoCallData);
_(FPlayerUIPreferences);
_(FRegionGameStageData);
_(FUnloadableDlcRegionGameStageData);
_(FWorldDiscoveryData);
_(FChosenVehicleCustomization);
_(FExpansionData);
_(FUnloadableDlcChallengeData);
_(FOneOffLevelChallengeData);
_(FBankSlot);
_(FLockoutData);
_(FUnloadableDlcLockoutData);
_(UPlayerSaveGame);

/* ---------------------------------------------------------- UWillowDeclarations ---------------------------------------------------------- */

_(FCellInfo);
_(FCellContentData);
_(FPanelInfo);
_(FCardInfoRelativeToPanel);
_(FCardInfo);
_(FPendingMissionRewardData);
_(FUnloadableDlcPendingRewardData);
_(FMissionStatusPresentation);
_(UWillowDeclarations);

/* ---------------------------------------------------------- UStatusMenuGFxDefinition ---------------------------------------------------------- */

_(FDirectionData);
_(UStatusMenuGFxDefinition);

/* ---------------------------------------------------------- UMissionRewardGFxObject ---------------------------------------------------------- */

_(UMissionRewardGFxObject);

/* ---------------------------------------------------------- UQuestAcceptGFxDefinition ---------------------------------------------------------- */

_(UQuestAcceptGFxDefinition);

/* ---------------------------------------------------------- UItemInspectionGFxMovie ---------------------------------------------------------- */

_(UItemInspectionGFxMovie);

/* ---------------------------------------------------------- UTradingGFxMovie ---------------------------------------------------------- */

_(UTradingGFxMovie);

/* ---------------------------------------------------------- UStatusMenuExGFxMovie ---------------------------------------------------------- */

_(FCachedInvData);
_(UStatusMenuExGFxMovie);

/* ---------------------------------------------------------- AWillowItem ---------------------------------------------------------- */

_(FUIStatModifierData);
_(AWillowItem);

/* ---------------------------------------------------------- AWillowUsableItem ---------------------------------------------------------- */

_(AWillowUsableItem);

/* ---------------------------------------------------------- AWillowUsableCustomizationItem ---------------------------------------------------------- */

_(AWillowUsableCustomizationItem);

/* ---------------------------------------------------------- AWillowEquipAbleItem ---------------------------------------------------------- */

_(AWillowEquipAbleItem);

/* ---------------------------------------------------------- AWillowGrenadeMod ---------------------------------------------------------- */

_(AWillowGrenadeMod);

/* ---------------------------------------------------------- AWillowClassMod ---------------------------------------------------------- */

_(AWillowClassMod);

/* ---------------------------------------------------------- AWillowArtifact ---------------------------------------------------------- */

_(AWillowArtifact);

/* ---------------------------------------------------------- AWillowShield ---------------------------------------------------------- */

_(AWillowShield);

_(UTextBufferFactory);
_(FPackageInfo);

_(FFieldNetCache);
_(FClassNetCache);

_(UPackageMap);
_(UArrayProperty);
_(UObjectRedirector);

_(VfTable__FCopyProgress);
_(FCopyProgress);
_(FTimeStamp);
_(VfTable__FFileManager);
_(FFileManager);

_(UBlurEffect);

_(VfTable__IInterface_Speaker);
_(IInterface_Speaker);


/* ---------------------------------------------------------- UBaseBalanceDefinition ---------------------------------------------------------- */

_(FGameStageRangeData);
_(FGameStageGradeWeightData);
_(UBaseBalanceDefinition);

/* ---------------------------------------------------------- UInteractiveObjectBalanceDefinition ---------------------------------------------------------- */

_(FLootAttachmentData);
_(FLootConfigurationData);
_(FInteractiveObjectGradeModifierData);
_(FInteractiveObjectGameStageGradeWeightData);
_(UInteractiveObjectBalanceDefinition);

/* ---------------------------------------------------------- UAIPawnBalanceDefinition ---------------------------------------------------------- */

_(FAITransformedName);
_(FAIPawnPlaythroughData);
_(FAIPawnGradeModifierData);
_(FAIPawnGameStageGradeWeightData);
_(UAIPawnBalanceDefinition);

/* ---------------------------------------------------------- UInventoryBalanceDefinition ---------------------------------------------------------- */

_(FInventoryGradeModifierData);
_(FInventoryGameStageGradeWeightData); 
_(FInventoryManufacturerBalanceData);
_(UInventoryBalanceDefinition);

/* ---------------------------------------------------------- UItemBalanceDefinition ---------------------------------------------------------- */

_(UItemBalanceDefinition);

/* ---------------------------------------------------------- UClassModBalanceDefinition ---------------------------------------------------------- */

_(UClassModBalanceDefinition);

/* ---------------------------------------------------------- UWeaponBalanceDefinition ---------------------------------------------------------- */

_(UWeaponBalanceDefinition);

/* ---------------------------------------------------------- UMissionWeaponBalanceDefinition ---------------------------------------------------------- */

_(UMissionWeaponBalanceDefinition);

/* ---------------------------------------------------------- APawn ---------------------------------------------------------- */

_(FScalarParameterInterpStruct);
_(FBalanceDefSpawnedActorState);
_(APawn);

/* ---------------------------------------------------------- AWillowInteractiveObject ---------------------------------------------------------- */

_(FInteractiveObjectReplicatedStateData);
_(AWillowInteractiveObject);

/* ---------------------------------------------------------- AWillowVendingMachineBase ---------------------------------------------------------- */

_(AWillowVendingMachineBase);

/* ---------------------------------------------------------- AWillowVendingMachineBlackMarket ---------------------------------------------------------- */

_(AWillowVendingMachineBlackMarket);

/* ---------------------------------------------------------- ATravelStation ---------------------------------------------------------- */

_(ATravelStation);

/* ---------------------------------------------------------- ALevelTravelStation ---------------------------------------------------------- */

_(ALevelTravelStation);

/* ---------------------------------------------------------- AFastTravelStation ---------------------------------------------------------- */

_(AFastTravelStation);

/* ---------------------------------------------------------- AGamePawn ---------------------------------------------------------- */

_(AGamePawn);

/* ---------------------------------------------------------- AGearboxPawn ---------------------------------------------------------- */

_(AGearboxPawn);

/* ---------------------------------------------------------- AWillowPawn ---------------------------------------------------------- */

_(FHolsteredGearDisplaySlot);
_(FBloodSplatterTrace);
_(FGoreEffect);
_(FMaterialScalarFadeReplication);
_(AWillowPawn);

/* ---------------------------------------------------------- AWillowAIPawn ---------------------------------------------------------- */

_(FRagdollDeathImpulseStruct);
_(FStaggerStateData);
_(FWillowCoverState);
_(FPerchStateData);
_(FDamageLocationData);
_(FSplineAnimPathData);
_(AWillowAIPawn);

/* ---------------------------------------------------------- ADeployableTurretActor ---------------------------------------------------------- */

_(FTurretEffect);
_(FTurretDamageEffectData);
_(ADeployableTurretActor);

/* ---------------------------------------------------------- AWillowPlayerPawn ---------------------------------------------------------- */

_(FSpeedTravelData);
_(FWeatherSystemEffects);
_(FAttachmentData);
_(AWillowPlayerPawn);

_(FLinearColor);

_(FViewportClient);

/* ---------------------------------------------------------- UGameViewportClient ---------------------------------------------------------- */

_(FTitleSafeZoneArea);
_(FPerPlayerSplitscreenData);
_(FSplitscreenData);
_(FDebugDisplayProperty);
_(UGameViewportClient);

/* ---------------------------------------------------------- UWillowGameViewportClient ---------------------------------------------------------- */

_(FSubtitleProfile);
_(FLoginState);
_(FGamepadState);
_(UWillowGameViewportClient);

/* ---------------------------------------------------------- UClient ---------------------------------------------------------- */

_(UClient);

/* ---------------------------------------------------------- UWindowsClient ---------------------------------------------------------- */

_(UWindowsClient);

/* ---------------------------------------------------------- UEngine ---------------------------------------------------------- */

_(FStatColorMapEntry);
_(FStatColorMapping);
_(FDropNoteInfo);
_(UEngine);

/* ---------------------------------------------------------- UGameEngine ---------------------------------------------------------- */

_(FLevelStreamingStatus);
_(FFullyLoadedPackagesInfo);
_(FNamedNetDriver);
_(FAnimTag);
_(UGameEngine);

/* ---------------------------------------------------------- USparkServiceConfiguration ---------------------------------------------------------- */

_(FSparkMicropatch);
_(USparkServiceConfiguration);

_(FHttpParameters);
_(USparkInterface);

/* ---------------------------------------------------------- UGearboxEngine ---------------------------------------------------------- */

_(UGearboxEngine);

/* ---------------------------------------------------------- UWillowGameEngine ---------------------------------------------------------- */

_(UWillowGameEngine);

_(FNetObjectNotify);
_(UNetDriver);

_(FDemoRewindPoint);
_(UDemoRecDriver);

/* ---------------------------------------------------------- FPacketSimulationSettings ---------------------------------------------------------- */

_(FPacketSimulationSettings);
_(DelayedPacket);
_(FDownloadInfo);
_(UNetConnection);
_(UChildConnection);

_(FPackageFileCache);
_(FDLCInfo);
_(FMapPackageFileCache);

_(FKSphereElem);
_(FKBoxElem);
_(FKSphylElem);
_(FPlane);
_(FPlaneAligned);
_(FKConvexElem);
_(FKConvexGeomRenderInfo);

_(FKCachedPerTriData);
_(FCoverIndexPair);
_(FGuidPair);
_(FPrecomputedVisibilityCell);
_(FCompressedVisibilityChunk);
_(FPrecomputedVisibilityBucket);
_(FVector2D);
_(FPrecomputedVisibilityHandler);
_(FPrecomputedVolumeDistanceField);
_(FSphere);
_(FBoneAtom);
_(FStreamableTextureInstance);

/* ---------------------------------------------------------- ULevel ---------------------------------------------------------- */

_(ULevel);

_(FMatrix);
_(FQuat);
_(FKAggregateGeom);

_(FNetworkNotify);
_(UGuidCache);
_(UPendingLevel);
_(UDemoPlayPendingLevel);

_(FLevelViewportInfo);
_(FPrimitiveHashBase);

/* ---------------------------------------------------------- UWorld ---------------------------------------------------------- */

_(UWorld);
_(FBitReader);
_(FInBunch);

_(FBitWriter);
_(FOutBunch);

_(FAsyncCompletionCallbackInfo);
_(FAsyncPackage);
_(FFilename);

_(FNetworkProfiler);

_(FSetElementId);
_(FConfigSection);
_(FConfigFile);
_(FConfigCacheIni);

_(FArchiveCountMem);
_(FMemoryArchive);
_(FMemoryWriter);
_(FBufferArchive);
_(FMemoryReader);
_(FBufferReader);
_(FGameplayProfiler);

_(ConsoleCommandLibrary);
_(FGPPFrameMarker);
_(FSceneViewFamily);
_(ULevelStreaming);

_(FPoly);
_(UPolys);

_(FDeferredCleanupInterface);
_(FPendingCleanupObjects);
_(FEngineLoop);
_(FFontImportOptionsData);
_(UFontImportOptions);
_(FFontCharacter);
_(UFont);

_(UDebugger);
_(FDebuggerLog);

_(FStringOutputDevice);

_(UDebuggerCore);
_(UDebuggerInterface);

/* ---------------------------------------------------------- FStreamingViewInfo ---------------------------------------------------------- */

_(FStreamingViewInfo);

/* ---------------------------------------------------------- FStreamingManagerBase ---------------------------------------------------------- */

_(FStreamingManagerBase);

/* ---------------------------------------------------------- FStreamingManagerCollection ---------------------------------------------------------- */

_(FStreamingManagerCollection);

_(FStatChartLine);
_(FStatChart);

_(FHitProxyId);
_(HHitProxy);

_(FTransformEntry);
_(FMaskRegion);

_(FCanvasBaseRenderItem);

_(FCanvasSortElement);
_(FCanvas);

/* ---------------------------------------------------------- UCanvas ---------------------------------------------------------- */

_(FCanvasIcon);
_(FDepthFieldGlowInfo);
_(FFontRenderInfo);
_(FCanvasUVTri);
_(FTextSizingParameters);
_(FWrappedStringElement);
_(UCanvas);

/* ---------------------------------------------------------- FSimpleElementVertex ---------------------------------------------------------- */

_(FSimpleElementVertex);

/* ---------------------------------------------------------- FBatchedElements ---------------------------------------------------------- */

_(FBatchedPoint);
_(FBatchedThickLines);
_(FBatchedSprite);
_(FBatchedMeshElement);
_(FBatchedQuadMeshElement);
_(FBatchedElements);

TARRAY(void);
TARRAY(BYTE);
TARRAY(FLOAT);
TARRAY(LOOKUPVALUE);
TARRAY(INT);
TARRAY(DWORD);
TARRAY(TCHAR);
TARRAY(TArray_INT);
TARRAY(BITFIELD);

TARRAY_PTR(void);
