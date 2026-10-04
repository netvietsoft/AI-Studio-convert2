# TASK_038 — REGISTER_NATIVES DYNAMIC REGISTRATION RECOVERY

## Overview
Across all 45 vendor libraries, exactly **3038 dynamically registered methods** in **59 distinct JNINativeMethod tables** were statically recovered.

### libARKernelInterface.so (805 methods in 2 tables)

- **Table VA `0x10cc0b0`** (804 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeCreateInstance` | `()J` | `0x55defc` | `native_nativeCreateInstance` |
| `nativeDestroyInstance` | `(J)V` | `0x55df2c` | `native_nativeDestroyInstance` |
| `nativeReset` | `(J)V` | `0x55df44` | `native_nativeReset` |
| `nativeSetData` | `(JLjava/lang/String;)V` | `0x55df5c` | `native_nativeSetData` |
| `nativeSetEnableMakeupAdapt` | `(JZ)V` | `0x55e0e4` | `native_nativeSetEnableMakeupAdapt` |
| `nativeGetEnableMakeupAdapt` | `(J)Z` | `0x55e17c` | `native_nativeGetEnableMakeupAdapt` |
| `nativeSetEnableQNN` | `(JZ)V` | `0x55e1a8` | `native_nativeSetEnableQNN` |
| `nativeGetEnableQNN` | `(J)Z` | `0x55e240` | `native_nativeGetEnableQNN` |
| `nativeSetARAiModelPath` | `(JILjava/lang/String;)V` | `0x55e26c` | `native_nativeSetARAiModelPath` |
| `nativeGetARAiModelPath` | `(JI)Ljava/lang/String;` | `0x55e3a8` | `native_nativeGetARAiModelPath` |
| `nativeSetImageOrVideoChanged` | `(JZ)V` | `0x55e49c` | `native_nativeSetImageOrVideoChanged` |
| `nativeCreateInstance` | `()J` | `0x55e538` | `native_nativeCreateInstance` |
| `nativeDestroyInstance` | `(J)V` | `0x55ede8` | `native_nativeDestroyInstance` |
| `nativeReset` | `(J)V` | `0x55ee00` | `native_nativeReset` |
| `nativeSetAnimalCount` | `(JI)V` | `0x55ee18` | `native_nativeSetAnimalCount` |
| ... *(789 more entries)* | ... | ... | ... |

- **Table VA `0x10d56b0`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeInitBitmapDC` | `(II[BII)V` | `0x697760` | `native_nativeInitBitmapDC` |

### libCtaApiLib.so (11 methods in 1 tables)

- **Table VA `0x88010`** (11 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `cepahsul` | `(Z)Ljava/lang/String;` | `0x13788` | `native_cepahsul` |
| `dnepah` | `(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;JZZLjava/lang/String;)Ljava/lang/String;` | `0x13a50` | `native_dnepah` |
| `dnprecobjs` | `(Landroid/content/Context;JLjava/lang/String;)Ljava/lang/String;` | `0x16734` | `native_dnprecobjs` |
| `dnprecohdjs` | `()Ljava/lang/String;` | `0x18518` | `native_dnprecohdjs` |
| `guulam` | `(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;` | `0x188e0` | `native_guulam` |
| `dnepmret` | `([BLjava/lang/String;)[B` | `0x19218` | `native_dnepmret` |
| `dneulret` | `([B)[B` | `0x18ce0` | `native_dneulret` |
| `eneulret` | `(Ljava/lang/String;)Ljava/lang/String;` | `0x18edc` | `native_eneulret` |
| `sgwret` | `(Ljava/lang/String;)Ljava/lang/String;` | `0x19540` | `native_sgwret` |
| `gscret` | `(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;` | `0x1979c` | `native_gscret` |
| `testEncrypt` | `(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;` | `0x19e80` | `native_testEncrypt` |

### libKKMusicFX.so (11 methods in 2 tables)

- **Table VA `0x7f8d0`** (10 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `analyzeAudio` | `(Ljava/lang/String;)Lcom/meitu/media/mfx/MFXManager$AudioSourceInfo;` | `0x4473c` | `native_analyzeAudio` |
| `_initNative` | `()J` | `0x44b08` | `native__initNative` |
| `_setChainSettings` | `(JLcom/meitu/media/mfx/EqualizerFX$ChainSettings;)V` | `0x44b48` | `native__setChainSettings` |
| `nativeCreate` | `(Ljava/lang/String;)J` | `0x45118` | `native_nativeCreate` |
| `nativeRelease` | `()V` | `0x451b4` | `native_nativeRelease` |
| `setTimeRange` | `(JJ)V` | `0x45220` | `native_setTimeRange` |
| `calculateAndWaitLUFS` | `()F` | `0x4525c` | `native_calculateAndWaitLUFS` |
| `_toFormula` | `(J)Ljava/lang/String;` | `0x45330` | `native__toFormula` |
| `_fromFormula` | `(Ljava/lang/String;)J` | `0x454b8` | `native__fromFormula` |
| `_adjustStrength` | `(Ljava/lang/String;JI)I` | `0x455f4` | `native__adjustStrength` |

- **Table VA `0x80050`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `initialiseJUCE` | `(Landroid/content/Context;)V` | `0x5e594` | `native_initialiseJUCE` |

### libLayerFlow.so (1907 methods in 31 tables)

- **Table VA `0x531048`** (30 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2b8b98` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2b8bbc` | `native_nDestroy` |
| `getKey` | `(J)Ljava/lang/String;` | `0x2b8c1c` | `native_getKey` |
| `setKey` | `(JLjava/lang/String;)V` | `0x2b8c24` | `native_setKey` |
| `getModuleDirPath` | `(J)Ljava/lang/String;` | `0x2b8c98` | `native_getModuleDirPath` |
| `setModuleDirPath` | `(JLjava/lang/String;)V` | `0x2b8ca0` | `native_setModuleDirPath` |
| `nCreate` | `()J` | `0x2b8d20` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2b8db4` | `native_nDestroy` |
| `nGetOpenEyeMode` | `(J)I` | `0x2b8fac` | `native_nGetOpenEyeMode` |
| `nSetOpenEyeMode` | `(JI)V` | `0x2b8fc0` | `native_nSetOpenEyeMode` |
| `nGetFaceReshapeAigcCache` | `(J)Ljava/util/Map;` | `0x2b8fcc` | `native_nGetFaceReshapeAigcCache` |
| `nSetFaceReshapeAigcCache` | `(JLjava/util/Map;)V` | `0x2b9670` | `native_nSetFaceReshapeAigcCache` |
| `nGetGazeCorrectAigcCache` | `(J)Ljava/util/Map;` | `0x2b9d04` | `native_nGetGazeCorrectAigcCache` |
| `nSetGazeCorrectAigcCache` | `(JLjava/util/Map;)V` | `0x2ba344` | `native_nSetGazeCorrectAigcCache` |
| `nGetBody3DEffectAigcCache` | `(J)Ljava/util/Map;` | `0x2ba680` | `native_nGetBody3DEffectAigcCache` |
| ... *(15 more entries)* | ... | ... | ... |

- **Table VA `0x531808`** (13 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2bdfcc` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2bdfe8` | `native_nDestroy` |
| `nGetMaterialId` | `(J)J` | `0x2bdff8` | `native_nGetMaterialId` |
| `nSetMaterialId` | `(JJ)V` | `0x2be000` | `native_nSetMaterialId` |
| `nGetValue` | `(J)I` | `0x2be008` | `native_nGetValue` |
| `nSetValue` | `(JI)V` | `0x2be010` | `native_nSetValue` |
| `nDestroy` | `(J)V` | `0x2be018` | `native_nDestroy` |
| `getEnable` | `(J)Z` | `0x2be060` | `native_getEnable` |
| `setEnable` | `(JZ)V` | `0x2be068` | `native_setEnable` |
| `getModular` | `(J)Ljava/lang/String;` | `0x2be078` | `native_getModular` |
| `setModular` | `(JLjava/lang/String;)V` | `0x2be080` | `native_setModular` |
| `getModes` | `(J)Ljava/util/ArrayList;` | `0x2be100` | `native_getModes` |
| `setModes` | `(J[Lcom/layer/flow/datas/LFAutoBeautyData$AutoBeautyMode;)V` | `0x2be240` | `native_setModes` |

- **Table VA `0x5319d0`** (31 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2bed10` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2bed60` | `native_nDestroy` |
| `nGetMaterialId` | `(J)J` | `0x2bee04` | `native_nGetMaterialId` |
| `nSetMaterialId` | `(JJ)V` | `0x2bee0c` | `native_nSetMaterialId` |
| `nGetMaterialType` | `(J)I` | `0x2bee14` | `native_nGetMaterialType` |
| `nSetMaterialType` | `(JI)V` | `0x2bee1c` | `native_nSetMaterialType` |
| `nGetProtectType` | `(J)I` | `0x2bee24` | `native_nGetProtectType` |
| `nSetProtectType` | `(JI)V` | `0x2bee2c` | `native_nSetProtectType` |
| `nGetStroke` | `(J)D` | `0x2bee34` | `native_nGetStroke` |
| `nSetStroke` | `(JD)V` | `0x2bee3c` | `native_nSetStroke` |
| `nGetMargin` | `(J)D` | `0x2bee44` | `native_nGetMargin` |
| `nSetMargin` | `(JD)V` | `0x2bee4c` | `native_nSetMargin` |
| `nGetColor` | `(J)Ljava/lang/String;` | `0x2bee54` | `native_nGetColor` |
| `nSetColor` | `(JLjava/lang/String;)V` | `0x2bee5c` | `native_nSetColor` |
| `nGetTextFeature` | `(J)J` | `0x2beee0` | `native_nGetTextFeature` |
| ... *(16 more entries)* | ... | ... | ... |

- **Table VA `0x531d48`** (141 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2c1bc8` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2c1be8` | `native_nDestroy` |
| `nGetEnable` | `(J)Z` | `0x2c1c24` | `native_nGetEnable` |
| `nSetEnable` | `(JZ)V` | `0x2c1c2c` | `native_nSetEnable` |
| `nDestroy` | `(J)V` | `0x2c1c40` | `native_nDestroy` |
| `nGetModular` | `(J)Ljava/lang/String;` | `0x2c1c7c` | `native_nGetModular` |
| `nSetModular` | `(JLjava/lang/String;)V` | `0x2c1c84` | `native_nSetModular` |
| `nIsEnable` | `(J)Z` | `0x2c1d04` | `native_nIsEnable` |
| `nSetEnable` | `(JZ)V` | `0x2c1d0c` | `native_nSetEnable` |
| `nGetInfoPointer` | `(J)J` | `0x2c1d1c` | `native_nGetInfoPointer` |
| `nSetInfo` | `(JJ)V` | `0x2c1d50` | `native_nSetInfo` |
| `nCreate` | `()J` | `0x2c1d64` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2c1d88` | `native_nDestroy` |
| `nGetFaceLevel` | `(J)I` | `0x2c1d98` | `native_nGetFaceLevel` |
| `nSetFaceLevel` | `(JI)V` | `0x2c1da0` | `native_nSetFaceLevel` |
| ... *(126 more entries)* | ... | ... | ... |

- **Table VA `0x532c30`** (122 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nDestroy` | `(J)V` | `0x2c6dbc` | `native_nDestroy` |
| `getEnable` | `(J)Z` | `0x2c6e00` | `native_getEnable` |
| `setEnable` | `(JZ)V` | `0x2c6e08` | `native_setEnable` |
| `getModular` | `(J)Ljava/lang/String;` | `0x2c6e18` | `native_getModular` |
| `setModular` | `(JLjava/lang/String;)V` | `0x2c6e20` | `native_setModular` |
| `getMaterialId` | `(J)J` | `0x2c6ea0` | `native_getMaterialId` |
| `setMaterialId` | `(JJ)V` | `0x2c6ea8` | `native_setMaterialId` |
| `getFilterAlpha` | `(J)I` | `0x2c6eb0` | `native_getFilterAlpha` |
| `setFilterAlpha` | `(JI)V` | `0x2c6eb8` | `native_setFilterAlpha` |
| `getSliderParams` | `(J)Ljava/util/Map;` | `0x2c6ec0` | `native_getSliderParams` |
| `setSliderParams` | `(JLjava/util/Map;)V` | `0x2c6ec8` | `native_setSliderParams` |
| `getMode` | `(J)Ljava/lang/String;` | `0x2c7bf8` | `native_getMode` |
| `setMode` | `(JLjava/lang/String;)V` | `0x2c7c00` | `native_setMode` |
| `getBounds` | `(J)Ljava/util/List;` | `0x2c7c74` | `native_getBounds` |
| `setBounds` | `(JLjava/util/List;)V` | `0x2c7c7c` | `native_setBounds` |
| ... *(107 more entries)* | ... | ... | ... |

- **Table VA `0x5337e0`** (104 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nDestroy` | `(J)V` | `0x2cb424` | `native_nDestroy` |
| `nGetOptType` | `(J)I` | `0x2cb470` | `native_nGetOptType` |
| `nSetOptType` | `(JI)V` | `0x2cb478` | `native_nSetOptType` |
| `nGetFaceId` | `(J)I` | `0x2cb480` | `native_nGetFaceId` |
| `nSetFaceId` | `(JI)V` | `0x2cb488` | `native_nSetFaceId` |
| `nGetMaterialId` | `(J)J` | `0x2cb490` | `native_nGetMaterialId` |
| `nSetMaterialId` | `(JJ)V` | `0x2cb498` | `native_nSetMaterialId` |
| `nGetAlpha` | `(J)F` | `0x2cb4a0` | `native_nGetAlpha` |
| `nSetAlpha` | `(JF)V` | `0x2cb4a8` | `native_nSetAlpha` |
| `nIsHighLights` | `(J)Z` | `0x2cb4b0` | `native_nIsHighLights` |
| `nSetHighLights` | `(JZ)V` | `0x2cb4b8` | `native_nSetHighLights` |
| `nDestroy` | `(J)V` | `0x2cb4c8` | `native_nDestroy` |
| `nIsEnable` | `(J)Z` | `0x2cb534` | `native_nIsEnable` |
| `nSetEnable` | `(JZ)V` | `0x2cb53c` | `native_nSetEnable` |
| `nGetModular` | `(J)Ljava/lang/String;` | `0x2cb54c` | `native_nGetModular` |
| ... *(89 more entries)* | ... | ... | ... |

- **Table VA `0x5341f0`** (129 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nDestroy` | `(J)V` | `0x2ce5b8` | `native_nDestroy` |
| `nCreate` | `()J` | `0x2ce604` | `native_nCreate` |
| `nGetData` | `(J)D` | `0x2ce628` | `native_nGetData` |
| `nSetData` | `(JD)V` | `0x2ce630` | `native_nSetData` |
| `nGetFaceId` | `(J)I` | `0x2ce638` | `native_nGetFaceId` |
| `nSetFaceId` | `(JI)V` | `0x2ce640` | `native_nSetFaceId` |
| `nDestroy` | `(J)V` | `0x2ce648` | `native_nDestroy` |
| `nCreate` | `()J` | `0x2ce694` | `native_nCreate` |
| `nGetData` | `(J)I` | `0x2ce6b4` | `native_nGetData` |
| `nSetData` | `(JI)V` | `0x2ce6bc` | `native_nSetData` |
| `nGetFaceId` | `(J)I` | `0x2ce6c4` | `native_nGetFaceId` |
| `nSetFaceId` | `(JI)V` | `0x2ce6cc` | `native_nSetFaceId` |
| `nDestroy` | `(J)V` | `0x2ce6d4` | `native_nDestroy` |
| `nCreate` | `()J` | `0x2ce720` | `native_nCreate` |
| `nGetFaceId` | `(J)I` | `0x2ce754` | `native_nGetFaceId` |
| ... *(114 more entries)* | ... | ... | ... |

- **Table VA `0x534e98`** (105 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2d3210` | `native_nCreate` |
| `nDestroyData` | `(J)V` | `0x2d3234` | `native_nDestroyData` |
| `nIsEnable` | `(J)Z` | `0x2d32f4` | `native_nIsEnable` |
| `nSetEnable` | `(JZ)V` | `0x2d32fc` | `native_nSetEnable` |
| `nGetModular` | `(J)Ljava/lang/String;` | `0x2d330c` | `native_nGetModular` |
| `nSetModular` | `(JLjava/lang/String;)V` | `0x2d332c` | `native_nSetModular` |
| `nIsBgProtect` | `(J)Z` | `0x2d33ac` | `native_nIsBgProtect` |
| `nSetBgProtect` | `(JZ)V` | `0x2d33b4` | `native_nSetBgProtect` |
| `nGetInfoPointers` | `(J)[J` | `0x2d33c8` | `native_nGetInfoPointers` |
| `nSetInfo` | `(J[J)V` | `0x2d368c` | `native_nSetInfo` |
| `nCreate` | `()J` | `0x2d2c54` | `native_nCreate` |
| `nDestroyModel` | `(J)V` | `0x2d2c7c` | `native_nDestroyModel` |
| `nGetFaceParamsPointers` | `(J)[J` | `0x2d2ce8` | `native_nGetFaceParamsPointers` |
| `nSetFaceParams` | `(J[J)V` | `0x2d2e9c` | `native_nSetFaceParams` |
| `nGetImageWidth` | `(J)F` | `0x2d3100` | `native_nGetImageWidth` |
| ... *(90 more entries)* | ... | ... | ... |

- **Table VA `0x5358a0`** (200 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2d5538` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2d5560` | `native_nDestroy` |
| `nGetForeheadLevel` | `(J)D` | `0x2d55a4` | `native_nGetForeheadLevel` |
| `nSetForeheadLevel` | `(JD)V` | `0x2d55b8` | `native_nSetForeheadLevel` |
| `nGetNeckLevel` | `(J)D` | `0x2d55c4` | `native_nGetNeckLevel` |
| `nSetNeckLevel` | `(JD)V` | `0x2d55d8` | `native_nSetNeckLevel` |
| `nGetEyeLevel` | `(J)D` | `0x2d55e4` | `native_nGetEyeLevel` |
| `nSetEyeLevel` | `(JD)V` | `0x2d55f8` | `native_nSetEyeLevel` |
| `nGetNasoLevel` | `(J)D` | `0x2d5604` | `native_nGetNasoLevel` |
| `nSetNasoLevel` | `(JD)V` | `0x2d5618` | `native_nSetNasoLevel` |
| `nGetLipLevel` | `(J)D` | `0x2d5624` | `native_nGetLipLevel` |
| `nSetLipLevel` | `(JD)V` | `0x2d5638` | `native_nSetLipLevel` |
| `nIsUseAutoClean` | `(J)Z` | `0x2d5644` | `native_nIsUseAutoClean` |
| `nSetUseAutoClean` | `(JZ)V` | `0x2d5658` | `native_nSetUseAutoClean` |
| `nCreate` | `()J` | `0x2d566c` | `native_nCreate` |
| ... *(185 more entries)* | ... | ... | ... |

- **Table VA `0x537030`** (63 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2dd730` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2dd754` | `native_nDestroy` |
| `nGetMake` | `(J)Ljava/lang/String;` | `0x2dd7b4` | `native_nGetMake` |
| `nSetMake` | `(JLjava/lang/String;)V` | `0x2dd7dc` | `native_nSetMake` |
| `nGetModel` | `(J)Ljava/lang/String;` | `0x2dd854` | `native_nGetModel` |
| `nSetModel` | `(JLjava/lang/String;)V` | `0x2dd880` | `native_nSetModel` |
| `nDestroy` | `(J)V` | `0x2dda44` | `native_nDestroy` |
| `nPrintInfo` | `(J)V` | `0x2ddabc` | `native_nPrintInfo` |
| `nIsEnable` | `(J)Z` | `0x2ddc00` | `native_nIsEnable` |
| `nSetEnable` | `(JZ)V` | `0x2ddc08` | `native_nSetEnable` |
| `nSetModular` | `(JLjava/lang/String;)V` | `0x2ddc18` | `native_nSetModular` |
| `nGetModular` | `(J)Ljava/lang/String;` | `0x2ddc98` | `native_nGetModular` |
| `nGetFaceIdsFromFaceMaps` | `(J)[I` | `0x2ddca0` | `native_nGetFaceIdsFromFaceMaps` |
| `nGetFaceDataByFaceId` | `(JI)J` | `0x2ddcec` | `native_nGetFaceDataByFaceId` |
| `nRemoveFaceDataByFaceId` | `(JI)V` | `0x2ddd70` | `native_nRemoveFaceDataByFaceId` |
| ... *(48 more entries)* | ... | ... | ... |

- **Table VA `0x537648`** (53 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nDestroy` | `(J)V` | `0x2de620` | `native_nDestroy` |
| `nGetModular` | `(J)Ljava/lang/String;` | `0x2de698` | `native_nGetModular` |
| `nSetModular` | `(JLjava/lang/String;)V` | `0x2de6b8` | `native_nSetModular` |
| `nIsEnable` | `(J)Z` | `0x2de738` | `native_nIsEnable` |
| `nSetEnable` | `(JZ)V` | `0x2de740` | `native_nSetEnable` |
| `nGetFaceIdsFromFaceMaps` | `(J)[I` | `0x2de750` | `native_nGetFaceIdsFromFaceMaps` |
| `nGetFaceDataByFaceId` | `(JI)J` | `0x2de810` | `native_nGetFaceDataByFaceId` |
| `nRemoveFaceDataByFaceId` | `(JI)V` | `0x2dea7c` | `native_nRemoveFaceDataByFaceId` |
| `nPutFaceDataByFaceId` | `(JIJ)V` | `0x2dead8` | `native_nPutFaceDataByFaceId` |
| `nClearFaceData` | `(J)V` | `0x2dec4c` | `native_nClearFaceData` |
| `nCreate` | `()J` | `0x2dec7c` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2decf4` | `native_nDestroy` |
| `nGetFeatureParamDictListSize` | `(J)I` | `0x2ded98` | `native_nGetFeatureParamDictListSize` |
| `nGetFeatureParamDictListKeys` | `(JI)[Ljava/lang/String;` | `0x2dedb4` | `native_nGetFeatureParamDictListKeys` |
| `nGetFeatureParamDictListValue` | `(JILjava/lang/String;)[Ljava/lang/Integer;` | `0x2def04` | `native_nGetFeatureParamDictListValue` |
| ... *(38 more entries)* | ... | ... | ... |

- **Table VA `0x537b70`** (69 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2e27e4` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2e2808` | `native_nDestroy` |
| `nGetUrl` | `(J)Ljava/lang/String;` | `0x2e2868` | `native_nGetUrl` |
| `nSetUrl` | `(JLjava/lang/String;)V` | `0x2e2870` | `native_nSetUrl` |
| `nGetFilePath` | `(J)Ljava/lang/String;` | `0x2e28e4` | `native_nGetFilePath` |
| `nSetFilePath` | `(JLjava/lang/String;)V` | `0x2e28ec` | `native_nSetFilePath` |
| `nDestroy` | `(J)V` | `0x2e2aec` | `native_nDestroy` |
| `getEnable` | `(J)Z` | `0x2e2b4c` | `native_getEnable` |
| `setEnable` | `(JZ)V` | `0x2e2b54` | `native_setEnable` |
| `getModular` | `(J)Ljava/lang/String;` | `0x2e2b64` | `native_getModular` |
| `setModular` | `(JLjava/lang/String;)V` | `0x2e2b6c` | `native_setModular` |
| `getMaterialId` | `(J)J` | `0x2e2bec` | `native_getMaterialId` |
| `setMaterialId` | `(JJ)V` | `0x2e2bf4` | `native_setMaterialId` |
| `getFilterAlpha` | `(J)I` | `0x2e2bfc` | `native_getFilterAlpha` |
| `setFilterAlpha` | `(JI)V` | `0x2e2c04` | `native_setFilterAlpha` |
| ... *(54 more entries)* | ... | ... | ... |

- **Table VA `0x538308`** (97 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2e632c` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2e637c` | `native_nDestroy` |
| `nGetPath` | `(J)Ljava/lang/String;` | `0x2e6418` | `native_nGetPath` |
| `nSetPath` | `(JLjava/lang/String;)V` | `0x2e6450` | `native_nSetPath` |
| `nSaveImageTo` | `(JLjava/lang/String;)Z` | `0x2e64f8` | `native_nSaveImageTo` |
| `nLoadImageFrom` | `(JLjava/lang/String;)Z` | `0x2e65b8` | `native_nLoadImageFrom` |
| `nModularDestroy` | `(J)V` | `0x2e6898` | `native_nModularDestroy` |
| `nModularGetEnable` | `(J)Z` | `0x2e68f8` | `native_nModularGetEnable` |
| `nModularSetEnable` | `(JZ)V` | `0x2e6900` | `native_nModularSetEnable` |
| `nModularGetModular` | `(J)Ljava/lang/String;` | `0x2e6910` | `native_nModularGetModular` |
| `nModularSetModular` | `(JLjava/lang/String;)V` | `0x2e6918` | `native_nModularSetModular` |
| `nModularGetRotate` | `(J)D` | `0x2e6998` | `native_nModularGetRotate` |
| `nModularSetRotate` | `(JD)V` | `0x2e69a0` | `native_nModularSetRotate` |
| `nModularGetCenterX` | `(J)D` | `0x2e69a8` | `native_nModularGetCenterX` |
| `nModularSetCenterX` | `(JD)V` | `0x2e69b0` | `native_nModularSetCenterX` |
| ... *(82 more entries)* | ... | ... | ... |

- **Table VA `0x538eb0`** (163 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nDestroy` | `(J)V` | `0x2ec390` | `native_nDestroy` |
| `nGetEnable` | `(J)Z` | `0x2ec3cc` | `native_nGetEnable` |
| `nSetEnable` | `(JZ)V` | `0x2ec3d4` | `native_nSetEnable` |
| `nGetModular` | `(J)Ljava/lang/String;` | `0x2ec3e8` | `native_nGetModular` |
| `nGetMaterialId` | `(J)J` | `0x2ec3f0` | `native_nGetMaterialId` |
| `nSetMaterialId` | `(JJ)V` | `0x2ec3f8` | `native_nSetMaterialId` |
| `nGetAlpha` | `(J)I` | `0x2ec400` | `native_nGetAlpha` |
| `nSetAlpha` | `(JI)V` | `0x2ec408` | `native_nSetAlpha` |
| `nCreate` | `()J` | `0x2ec4fc` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2ec534` | `native_nDestroy` |
| `nAddData` | `(JIIFF)V` | `0x2ec574` | `native_nAddData` |
| `nClear` | `(J)V` | `0x2ec6ec` | `native_nClear` |
| `nAddMaskBitmap` | `(JILjava/lang/String;Landroid/graphics/Bitmap;)V` | `0x2ec74c` | `native_nAddMaskBitmap` |
| `nDestroy` | `(J)V` | `0x2ece24` | `native_nDestroy` |
| `nGetEnable` | `(J)Z` | `0x2ece84` | `native_nGetEnable` |
| ... *(148 more entries)* | ... | ... | ... |

- **Table VA `0x539e28`** (67 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nDestroy` | `(J)V` | `0x2efcc0` | `native_nDestroy` |
| `getEnable` | `(J)Z` | `0x2efd04` | `native_getEnable` |
| `setEnable` | `(JZ)V` | `0x2efd0c` | `native_setEnable` |
| `getModular` | `(J)Ljava/lang/String;` | `0x2efd1c` | `native_getModular` |
| `setModular` | `(JLjava/lang/String;)V` | `0x2efd24` | `native_setModular` |
| `getMaterialId` | `(J)J` | `0x2efda4` | `native_getMaterialId` |
| `setMaterialId` | `(JJ)V` | `0x2efdac` | `native_setMaterialId` |
| `getFilterAlpha` | `(J)I` | `0x2efdb4` | `native_getFilterAlpha` |
| `setFilterAlpha` | `(JI)V` | `0x2efdbc` | `native_setFilterAlpha` |
| `getSliderParams` | `(J)Ljava/util/Map;` | `0x2efdc4` | `native_getSliderParams` |
| `setSliderParams` | `(JLjava/util/Map;)V` | `0x2efdcc` | `native_setSliderParams` |
| `nGetIsLive` | `(J)Z` | `0x2efe84` | `native_nGetIsLive` |
| `nSetIsLive` | `(JZ)V` | `0x2efe8c` | `native_nSetIsLive` |
| `nDestroy` | `(J)V` | `0x2f05e0` | `native_nDestroy` |
| `nGetEnable` | `(J)Z` | `0x2f0668` | `native_nGetEnable` |
| ... *(52 more entries)* | ... | ... | ... |

- **Table VA `0x53a570`** (210 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x2f12e8` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x2f1338` | `native_nDestroy` |
| `nGetImageList` | `(J)[J` | `0x2f1408` | `native_nGetImageList` |
| `nSetImageList` | `(J[J)V` | `0x2f1934` | `native_nSetImageList` |
| `nGetBboxLoc` | `(J)[I` | `0x2f1cd4` | `native_nGetBboxLoc` |
| `nSetBboxLoc` | `(J[I)V` | `0x2f1d60` | `native_nSetBboxLoc` |
| `nDestroy` | `(J)V` | `0x2f2678` | `native_nDestroy` |
| `nGetWatermarkAngle` | `(J)D` | `0x2f2688` | `native_nGetWatermarkAngle` |
| `nSetWatermarkAngle` | `(JD)V` | `0x2f2690` | `native_nSetWatermarkAngle` |
| `nGetWatermarkDensity` | `(J)D` | `0x2f2698` | `native_nGetWatermarkDensity` |
| `nSetWatermarkDensity` | `(JD)V` | `0x2f26a0` | `native_nSetWatermarkDensity` |
| `nGetWatermarkSize` | `(J)D` | `0x2f26a8` | `native_nGetWatermarkSize` |
| `nSetWatermarkSize` | `(JD)V` | `0x2f26b0` | `native_nSetWatermarkSize` |
| `nGetWatermarkDislocation` | `(J)D` | `0x2f26b8` | `native_nGetWatermarkDislocation` |
| `nSetWatermarkDislocation` | `(JD)V` | `0x2f26c0` | `native_nSetWatermarkDislocation` |
| ... *(195 more entries)* | ... | ... | ... |

- **Table VA `0x53bdb8`** (4 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nGenerateBlockingIdByType8` | `(B)J` | `0x3010d4` | `native_nGenerateBlockingIdByType8` |
| `nNotifyWithNativeHandlerResult` | `(JJJ)V` | `0x3010dc` | `native_nNotifyWithNativeHandlerResult` |
| `nNotifyWithIntResult` | `(JJI)V` | `0x3010ec` | `native_nNotifyWithIntResult` |
| `nNotifyWithBoolResult` | `(JJZ)V` | `0x3010fc` | `native_nNotifyWithBoolResult` |

- **Table VA `0x53be38`** (18 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `(Z)J` | `0x301608` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x301790` | `native_nDestroy` |
| `nStart` | `(JLjava/lang/String;[J)Z` | `0x3017a8` | `native_nStart` |
| `nSetOrigin` | `(JLandroid/graphics/Bitmap;)V` | `0x301a30` | `native_nSetOrigin` |
| `nSetOriginNB` | `(JJ)V` | `0x301c14` | `native_nSetOriginNB` |
| `nGetErrorCode` | `(J)I` | `0x301db0` | `native_nGetErrorCode` |
| `nCancel` | `(J)V` | `0x301db8` | `native_nCancel` |
| `nRemoveLayers` | `(J[J)V` | `0x302078` | `native_nRemoveLayers` |
| `nSetFaceId` | `(JI)V` | `0x302228` | `native_nSetFaceId` |
| `nGetFaceId` | `(J)I` | `0x302234` | `native_nGetFaceId` |
| `nGetNativeFaceResult` | `(J)J` | `0x30223c` | `native_nGetNativeFaceResult` |
| `nGetLayerHandlers` | `(J)[J` | `0x301dc0` | `native_nGetLayerHandlers` |
| `nSetApplicationCtx` | `(JLandroid/content/Context;)V` | `0x302244` | `native_nSetApplicationCtx` |
| `nGetErrorMsg` | `(J)Ljava/lang/String;` | `0x30254c` | `native_nGetErrorMsg` |
| `nSetAutoCleanup` | `(JZ)V` | `0x302274` | `native_nSetAutoCleanup` |
| ... *(3 more entries)* | ... | ... | ... |

- **Table VA `0x53c218`** (100 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nClearPendingExceptions` | `()V` | `0x31d2a0` | `native_nClearPendingExceptions` |
| `nDestroy` | `(J)V` | `0x31d2e8` | `native_nDestroy` |
| `nGetName` | `(J)Ljava/lang/String;` | `0x31d318` | `native_nGetName` |
| `nGetLayerId` | `(J)J` | `0x31d3bc` | `native_nGetLayerId` |
| `nIsEnable` | `(J)Z` | `0x31d3c4` | `native_nIsEnable` |
| `nSetEnable` | `(JZ)V` | `0x31d3e0` | `native_nSetEnable` |
| `nGetFilterUUID` | `(J)J` | `0x31d3f0` | `native_nGetFilterUUID` |
| `nCreateLayerBy` | `(Ljava/lang/String;)J` | `0x31d3f8` | `native_nCreateLayerBy` |
| `nCreateLayerByCategoryFunction` | `(IIIIIZ)J` | `0x31d608` | `native_nCreateLayerByCategoryFunction` |
| `nUpdateLayerByCategoryFunction` | `(JIIIIIZ)Z` | `0x31d710` | `native_nUpdateLayerByCategoryFunction` |
| `nAddSolidifiedOneClickLayer` | `(JLcom/layer/flow/datas/LFEffectOneClickBeautyData$OneClickBeautyModular;I)V` | `0x31d760` | `native_nAddSolidifiedOneClickLayer` |
| `nGetSubLayersFromOneClickLayer` | `(J)Ljava/util/ArrayList;` | `0x31d9a0` | `native_nGetSubLayersFromOneClickLayer` |
| `nHasSubLayers` | `(J)Z` | `0x31dddc` | `native_nHasSubLayers` |
| `nSetSubFormulaJson` | `(JJLjava/lang/String;I)V` | `0x31e0c4` | `native_nSetSubFormulaJson` |
| `nGetSubFormulaMaterialId` | `(J)J` | `0x31e378` | `native_nGetSubFormulaMaterialId` |
| ... *(85 more entries)* | ... | ... | ... |

- **Table VA `0x53fc70`** (47 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x3bbadc` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x3bbb1c` | `native_nDestroy` |
| `nGetTextStyleConfigPath` | `(J)Ljava/lang/String;` | `0x3bbbb4` | `native_nGetTextStyleConfigPath` |
| `nSetTextStyleConfigPath` | `(JLjava/lang/String;)V` | `0x3bbcec` | `native_nSetTextStyleConfigPath` |
| `nGetDensity` | `(J)D` | `0x3bbd6c` | `native_nGetDensity` |
| `nSetDensity` | `(JD)V` | `0x3bbd74` | `native_nSetDensity` |
| `nGetLeftMargin` | `(J)I` | `0x3bbd7c` | `native_nGetLeftMargin` |
| `nSetLeftMargin` | `(JI)V` | `0x3bbd84` | `native_nSetLeftMargin` |
| `nGetRightMargin` | `(J)I` | `0x3bbd8c` | `native_nGetRightMargin` |
| `nSetRightMargin` | `(JI)V` | `0x3bbd94` | `native_nSetRightMargin` |
| `nGetTopMargin` | `(J)I` | `0x3bbd9c` | `native_nGetTopMargin` |
| `nSetTopMargin` | `(JI)V` | `0x3bbda4` | `native_nSetTopMargin` |
| `nGetBottomMargin` | `(J)I` | `0x3bbdac` | `native_nGetBottomMargin` |
| `nSetBottomMargin` | `(JI)V` | `0x3bbdb4` | `native_nSetBottomMargin` |
| `nGetViewWidth` | `(J)D` | `0x3bbdbc` | `native_nGetViewWidth` |
| ... *(32 more entries)* | ... | ... | ... |

- **Table VA `0x540198`** (41 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x3bfcbc` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x3bfd08` | `native_nDestroy` |
| `nSetUrl` | `(JLjava/lang/String;)V` | `0x3bfd68` | `native_nSetUrl` |
| `nSetCachePath` | `(JLjava/lang/String;)V` | `0x3bfddc` | `native_nSetCachePath` |
| `nGetStickerLocateStatus` | `(J)J` | `0x3bfe5c` | `native_nGetStickerLocateStatus` |
| `nSetStickerLocateStatus` | `(JJ)V` | `0x3bfe90` | `native_nSetStickerLocateStatus` |
| `nCreate` | `()J` | `0x3c0044` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x3c00a0` | `native_nDestroy` |
| `nSetMakeupCallback` | `(JLcom/layer/flow/plugin/LFFormulaRenderPlugin$IMakeupCallBack;)V` | `0x3c0194` | `native_nSetMakeupCallback` |
| `nSetCreativeCallback` | `(JLcom/layer/flow/plugin/LFFormulaRenderPlugin$ICreativeCallback;)V` | `0x3c0310` | `native_nSetCreativeCallback` |
| `nSetSpecialEffectCallback` | `(JLcom/layer/flow/plugin/LFFormulaRenderPlugin$ISpecialEffectCallback;)V` | `0x3c0420` | `native_nSetSpecialEffectCallback` |
| `nNotifyCreativeAigcResult` | `(JJJ)V` | `0x3c0530` | `native_nNotifyCreativeAigcResult` |
| `nSetBlurCallback` | `(JLcom/layer/flow/plugin/LFFormulaRenderPlugin$IBlurCallback;)V` | `0x3c0540` | `native_nSetBlurCallback` |
| `nNotifyBlurResourceData` | `(JJJ)V` | `0x3c0650` | `native_nNotifyBlurResourceData` |
| `nSetAutoBrushCallback` | `(JLcom/layer/flow/plugin/LFFormulaRenderPlugin$IAutoBrushCallback;)V` | `0x3c0764` | `native_nSetAutoBrushCallback` |
| ... *(26 more entries)* | ... | ... | ... |

- **Table VA `0x541d48`** (2 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `(Ljava/lang/String;)J` | `0x3d24bc` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x3d264c` | `native_nDestroy` |

- **Table VA `0x541e38`** (26 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x3d2b50` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x3d2b98` | `native_nDestroy` |
| `nGetAppId` | `(J)Ljava/lang/String;` | `0x3d2bc8` | `native_nGetAppId` |
| `nSetAppId` | `(JLjava/lang/String;)V` | `0x3d2bd0` | `native_nSetAppId` |
| `nGetOsType` | `(J)Ljava/lang/String;` | `0x3d2c44` | `native_nGetOsType` |
| `nSetOsType` | `(JLjava/lang/String;)V` | `0x3d2c4c` | `native_nSetOsType` |
| `nGetCountryId` | `(J)Ljava/lang/String;` | `0x3d2ccc` | `native_nGetCountryId` |
| `nSetCountryId` | `(JLjava/lang/String;)V` | `0x3d2cd4` | `native_nSetCountryId` |
| `nGetLevel1` | `(J)Ljava/lang/String;` | `0x3d2d54` | `native_nGetLevel1` |
| `nSetLevel1` | `(JLjava/lang/String;)V` | `0x3d2d5c` | `native_nSetLevel1` |
| `nGetLevel2` | `(J)Ljava/lang/String;` | `0x3d2ddc` | `native_nGetLevel2` |
| `nSetLevel2` | `(JLjava/lang/String;)V` | `0x3d2de4` | `native_nSetLevel2` |
| `nGetLevel3` | `(J)Ljava/lang/String;` | `0x3d2e64` | `native_nGetLevel3` |
| `nSetLevel3` | `(JLjava/lang/String;)V` | `0x3d2e6c` | `native_nSetLevel3` |
| `nGetLevel4` | `(J)Ljava/lang/String;` | `0x3d2eec` | `native_nGetLevel4` |
| ... *(11 more entries)* | ... | ... | ... |

- **Table VA `0x542138`** (18 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x3d4610` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x3d4648` | `native_nDestroy` |
| `nGetCenterX` | `(J)F` | `0x3d4658` | `native_nGetCenterX` |
| `nSetCenterX` | `(JF)V` | `0x3d4660` | `native_nSetCenterX` |
| `nGetCenterY` | `(J)F` | `0x3d4668` | `native_nGetCenterY` |
| `nSetCenterY` | `(JF)V` | `0x3d4670` | `native_nSetCenterY` |
| `nGetWidthRatio` | `(J)F` | `0x3d4678` | `native_nGetWidthRatio` |
| `nSetWidthRatio` | `(JF)V` | `0x3d4680` | `native_nSetWidthRatio` |
| `nGetWHRatio` | `(J)F` | `0x3d4688` | `native_nGetWHRatio` |
| `nSetWHRatio` | `(JF)V` | `0x3d4690` | `native_nSetWHRatio` |
| `nGetFlip` | `(J)Z` | `0x3d4698` | `native_nGetFlip` |
| `nSetFlip` | `(JZ)V` | `0x3d46a0` | `native_nSetFlip` |
| `nGetVFlip` | `(J)Z` | `0x3d46b0` | `native_nGetVFlip` |
| `nSetVFlip` | `(JZ)V` | `0x3d46b8` | `native_nSetVFlip` |
| `nGetRotate` | `(J)F` | `0x3d46c8` | `native_nGetRotate` |
| ... *(3 more entries)* | ... | ... | ... |

- **Table VA `0x545dd0`** (4 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x43fc80` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x43fcc0` | `native_nDestroy` |
| `nSetAIModelDir` | `(JLjava/lang/String;)V` | `0x43fcd8` | `native_nSetAIModelDir` |
| `nSetManager` | `(JJ)Z` | `0x43fd74` | `native_nSetManager` |

- **Table VA `0x5461d8`** (31 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x448554` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x448594` | `native_nDestroy` |
| `nGetResourceNeeded` | `(J)Z` | `0x448688` | `native_nGetResourceNeeded` |
| `nSetResourceNeeded` | `(JZ)V` | `0x4486a4` | `native_nSetResourceNeeded` |
| `nCreate` | `()J` | `0x4486b8` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x448910` | `native_nDestroy` |
| `nOnPreparedDownloadInfos` | `(JJJ)V` | `0x448c18` | `native_nOnPreparedDownloadInfos` |
| `nOnMaterialDownloadProgress` | `(JJJ)V` | `0x448c28` | `native_nOnMaterialDownloadProgress` |
| `nOnAiModelDownloadProgress` | `(JJJ)V` | `0x448c3c` | `native_nOnAiModelDownloadProgress` |
| `nOnFontDownloadProgress` | `(JJJ)V` | `0x448c50` | `native_nOnFontDownloadProgress` |
| `nOnFileDownloadProgress` | `(JJJ)V` | `0x448c64` | `native_nOnFileDownloadProgress` |
| `nCreate` | `()J` | `0x448c78` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x448cb8` | `native_nDestroy` |
| `nGetAllXX` | `(JI)[J` | `0x448ce8` | `native_nGetAllXX` |
| `nSetAllXX` | `(JI[J)V` | `0x44971c` | `native_nSetAllXX` |
| ... *(16 more entries)* | ... | ... | ... |

- **Table VA `0x5466b0`** (3 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x44e4e8` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x44e718` | `native_nDestroy` |
| `nSetRunInOffScreenContextOnly` | `(JZ)V` | `0x44e854` | `native_nSetRunInOffScreenContextOnly` |

- **Table VA `0x5467c8`** (4 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `(Ljava/lang/String;)J` | `0x44f110` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x44f2a4` | `native_nDestroy` |
| `nOnAiModelDownloaded` | `(JLjava/lang/String;Z)V` | `0x44f2bc` | `native_nOnAiModelDownloaded` |
| `nPutLocalMaterials` | `(Ljava/util/HashMap;Ljava/util/HashMap;)V` | `0x44f36c` | `native_nPutLocalMaterials` |

- **Table VA `0x546a08`** (4 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x450774` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x4507dc` | `native_nDestroy` |
| `nSetLayers` | `(J[J)V` | `0x45083c` | `native_nSetLayers` |
| `nSetDownloadInfos` | `(JJ)V` | `0x450a98` | `native_nSetDownloadInfos` |

- **Table VA `0x546ab8`** (3 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nCreate` | `()J` | `0x450ca8` | `native_nCreate` |
| `nDestroy` | `(J)V` | `0x450d10` | `native_nDestroy` |
| `nSetAction` | `(JI)V` | `0x450d70` | `native_nSetAction` |

- **Table VA `0x548390`** (5 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeCreate` | `(Ljava/lang/String;)J` | `0x46fe44` | `native_nativeCreate` |
| `nativeDispose` | `(J)V` | `0x46ffe8` | `native_nativeDispose` |
| `nativeIsSceneReady` | `(J)Z` | `0x470018` | `native_nativeIsSceneReady` |
| `nativeDetectAtPath` | `(JLjava/lang/String;I)Ljava/lang/String;` | `0x470040` | `native_nativeDetectAtPath` |
| `nativeDetectBitmap` | `(JLandroid/graphics/Bitmap;[BI)Ljava/lang/String;` | `0x47061c` | `native_nativeDetectBitmap` |

### libMTFilterKernel.so (42 methods in 1 tables)

- **Table VA `0x1ca2d8`** (42 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeCreate` | `()J` | `0xbe458` | `native_nativeCreate` |
| `finalizer` | `(J)V` | `0xbe468` | `native_finalizer` |
| `nativeGetFaceCount` | `(J)I` | `0xbe478` | `native_nativeGetFaceCount` |
| `nativeGetFaceRect` | `(JI)[F` | `0xbe4c0` | `native_nativeGetFaceRect` |
| `nativeGetLandmark` | `(JII)[F` | `0xbe590` | `native_nativeGetLandmark` |
| `nativeGetDetectWidth` | `(J)I` | `0xbea90` | `native_nativeGetDetectWidth` |
| `nativeGetDetectHeight` | `(J)I` | `0xbeadc` | `native_nativeGetDetectHeight` |
| `nativeGetRace` | `(JI)I` | `0xbeb28` | `native_nativeGetRace` |
| `nativeGetGender` | `(JI)I` | `0xbeba8` | `native_nativeGetGender` |
| `nativeGetAge` | `(JI)I` | `0xbec28` | `native_nativeGetAge` |
| `nativeSetFaceCount` | `(JI)V` | `0xbeca8` | `native_nativeSetFaceCount` |
| `nativeSetDetectSize` | `(JII)V` | `0xbece8` | `native_nativeSetDetectSize` |
| `nativeSetFaceRect` | `(JI[F)V` | `0xbed30` | `native_nativeSetFaceRect` |
| `nativeSetLandmark` | `(JII[F)Z` | `0xbedf4` | `native_nativeSetLandmark` |
| `nativeSetLandmarkVisible` | `(JII[F)Z` | `0xbf2ec` | `native_nativeSetLandmarkVisible` |
| ... *(27 more entries)* | ... | ... | ... |

### libMTLReportTool.so (10 methods in 1 tables)

- **Table VA `0x19568`** (10 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeCreateInstance` | `()J` | `0xb07c` | `native_nativeCreateInstance` |
| `nativeDestroyInstance` | `(J)V` | `0xb0bc` | `native_nativeDestroyInstance` |
| `nativeVersion` | `()Ljava/lang/String;` | `0xb0ec` | `native_nativeVersion` |
| `init` | `(Ljava/lang/String;)V` | `0xb11c` | `native_init` |
| `setConfigParams` | `(Ljava/lang/String;)V` | `0xb2a8` | `native_setConfigParams` |
| `setLogCallback` | `(Lkotlin/jvm/functions/Function1;)V` | `0xb434` | `native_setLogCallback` |
| `release` | `()V` | `0xb7cc` | `native_release` |
| `getVersion` | `()Ljava/lang/String;` | `0xb9a0` | `native_getVersion` |
| `setTagExclude` | `(Ljava/lang/String;I)I` | `0xbaa4` | `native_setTagExclude` |
| `testLog` | `()V` | `0xbc5c` | `native_testLog` |

### libPVGCodec.so (128 methods in 4 tables)

- **Table VA `0x139fe8`** (25 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_setup` | `()J` | `0x118cc4` | `native_native_setup` |
| `native_finalize` | `(J)I` | `0x118d18` | `native_native_finalize` |
| `native_setAudioOutParameter` | `(JIII)I` | `0x118dfc` | `native_native_setAudioOutParameter` |
| `native_setEnablePositiveValue` | `(JZ)I` | `0x118ec0` | `native_native_setEnablePositiveValue` |
| `native_setAudioSmoothingTime` | `(JI)I` | `0x118f80` | `native_native_setAudioSmoothingTime` |
| `native_setAudioDecoderParam` | `(JJJ)I` | `0x11903c` | `native_native_setAudioDecoderParam` |
| `native_open` | `(JLjava/lang/String;)I` | `0x1190fc` | `native_native_open` |
| `native_getAudioFrame` | `(J)[I` | `0x1194b4` | `native_native_getAudioFrame` |
| `native_setup` | `()J` | `0x119744` | `native_native_setup` |
| `native_finalize` | `(J)I` | `0x119784` | `native_native_finalize` |
| `native_setListener` | `(JZ)I` | `0x119850` | `native_native_setListener` |
| `native_setTimeParam` | `(JJJ)I` | `0x119a58` | `native_native_setTimeParam` |
| `native_process` | `(JLjava/lang/String;Ljava/lang/String;)I` | `0x119e3c` | `native_native_process` |
| `native_abort` | `(J)I` | `0x11a2a4` | `native_native_abort` |
| `native_setup` | `()J` | `0x11a4f4` | `native_native_setup` |
| ... *(10 more entries)* | ... | ... | ... |

- **Table VA `0x13a290`** (4 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_setup` | `()J` | `0x11bd58` | `native_native_setup` |
| `native_finalize` | `(J)I` | `0x11bd98` | `native_native_finalize` |
| `native_setParamHints` | `(JLjava/lang/String;Ljava/lang/String;)Z` | `0x11be64` | `native_native_setParamHints` |
| `native_transcode` | `(JLjava/lang/String;Ljava/lang/String;)Z` | `0x11c248` | `native_native_transcode` |

- **Table VA `0x13a338`** (9 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `setLogLevel` | `(I)V` | `0x11cfb0` | `native_setLogLevel` |
| `setLogCallbackLevel` | `(I)V` | `0x11cfd4` | `native_setLogCallbackLevel` |
| `setLogCallback` | `(Lcom/meitu/media/PVGCodec/IProcessor$LogCallback;)V` | `0x11d2f8` | `native_setLogCallback` |
| `setAndroidContext` | `(Landroid/content/Context;)V` | `0x11d704` | `native_setAndroidContext` |
| `checkIsSupportCudaDecode` | `(Ljava/lang/String;Ljava/lang/String;)I` | `0x11d728` | `native_checkIsSupportCudaDecode` |
| `getVersion` | `()Ljava/lang/String;` | `0x11da38` | `native_getVersion` |
| `getPVGVideoCodecVersion` | `()Ljava/lang/String;` | `0x11db00` | `native_getPVGVideoCodecVersion` |
| `getPVGImageCodecVersion` | `()Ljava/lang/String;` | `0x11dbc8` | `native_getPVGImageCodecVersion` |
| `getPVGColorFunctionVersion` | `()Ljava/lang/String;` | `0x11dc90` | `native_getPVGColorFunctionVersion` |

- **Table VA `0x13a4d8`** (90 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_setup` | `()J` | `0x11dfe0` | `native_native_setup` |
| `native_finalize` | `(J)I` | `0x11e020` | `native_native_finalize` |
| `native_addMedia` | `(JLjava/lang/String;DDDD)I` | `0x11e104` | `native_native_addMedia` |
| `native_getDuration` | `(J)D` | `0x11e3e8` | `native_native_getDuration` |
| `native_setListener` | `(JZ)I` | `0x11e4a0` | `native_native_setListener` |
| `native_process` | `(JLjava/lang/String;)I` | `0x11e7bc` | `native_native_process` |
| `native_abort` | `(J)I` | `0x11ea70` | `native_native_abort` |
| `native_setup` | `()J` | `0x11ecb0` | `native_native_setup` |
| `native_finalize` | `(J)I` | `0x11ecf0` | `native_native_finalize` |
| `native_init` | `(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)I` | `0x11edd4` | `native_native_init` |
| `native_getOutDuration` | `(J)D` | `0x11f440` | `native_native_getOutDuration` |
| `native_process` | `(J)I` | `0x11f504` | `native_native_process` |
| `native_setListener` | `(JZ)I` | `0x11f5bc` | `native_native_setListener` |
| `native_setup` | `()J` | `0x11f800` | `native_native_setup` |
| `native_finalize` | `(J)I` | `0x11f840` | `native_native_finalize` |
| ... *(75 more entries)* | ... | ... | ... |

### libPVGLive.so (36 methods in 1 tables)

- **Table VA `0x9a938`** (36 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeSetLogLevel` | `(I)I` | `0x8a3c0` | `native_nativeSetLogLevel` |
| `nativeSetDebug` | `(Z)I` | `0x8a3c8` | `native_nativeSetDebug` |
| `nativeIsDebug` | `()Z` | `0x8a3d8` | `native_nativeIsDebug` |
| `nativeSetAndroidContext` | `(Landroid/content/Context;)I` | `0x8a3f0` | `native_nativeSetAndroidContext` |
| `nativeGetAndroidContext` | `()Landroid/content/Context;` | `0x8a414` | `native_nativeGetAndroidContext` |
| `nativeCreateInstance` | `(I)J` | `0x8a4cc` | `native_nativeCreateInstance` |
| `nativeDestroyInstance` | `(J)V` | `0x8a4d4` | `native_nativeDestroyInstance` |
| `nativeVersion` | `()Ljava/lang/String;` | `0x8a4e4` | `native_nativeVersion` |
| `nativeOpenFile` | `(JLjava/lang/String;I)I` | `0x8a520` | `native_nativeOpenFile` |
| `nativeClose` | `(J)V` | `0x8a650` | `native_nativeClose` |
| `nativeIsMotionPhoto` | `(J)Z` | `0x8a668` | `native_nativeIsMotionPhoto` |
| `nativeVendor` | `(J)I` | `0x8a698` | `native_nativeVendor` |
| `nativeExtractImageToFile` | `(JLjava/lang/String;)I` | `0x8a6b4` | `native_nativeExtractImageToFile` |
| `nativeExtractVideoToFile` | `(JLjava/lang/String;)I` | `0x8a7b4` | `native_nativeExtractVideoToFile` |
| `nativeSetVendor` | `(JI)I` | `0x8a8b4` | `native_nativeSetVendor` |
| ... *(21 more entries)* | ... | ... | ... |

### libPVGVideoCodec.so (3 methods in 2 tables)

- **Table VA `0x1181d8`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `callNativeOpaque` | `(Ljava/lang/String;Ljava/lang/String;Landroid/media/MediaFormat;)V` | `0x9810c` | `native_callNativeOpaque` |

- **Table VA `0x1187f8`** (2 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_SurfaceTextureCallback` | `(J)V` | `0xa3ce8` | `native_native_SurfaceTextureCallback` |
| `native_ImageReaderCB` | `(J)V` | `0xa3c84` | `native_native_ImageReaderCB` |

### libaicodec.so (47 methods in 4 tables)

- **Table VA `0x1feb88`** (2 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `getVersion` | `()Lcom/meitu/media/aicodec/AICodec$Version;` | `0x105e44` | `native_getVersion` |
| `getVersionString` | `()Ljava/lang/String;` | `0x106008` | `native_getVersionString` |

- **Table VA `0x1febd0`** (26 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_open` | `(JLjava/lang/String;)J` | `0x106d8c` | `native_native_open` |
| `native_start` | `(J)Z` | `0x106f1c` | `native_native_start` |
| `native_stop` | `(J)V` | `0x106fd0` | `native_native_stop` |
| `native_pause` | `(J)V` | `0x107068` | `native_native_pause` |
| `native_resume` | `(J)V` | `0x107100` | `native_native_resume` |
| `native_close` | `(J)V` | `0x107198` | `native_native_close` |
| `native_hasAudio` | `(J)Z` | `0x10725c` | `native_native_hasAudio` |
| `native_hasVideo` | `(J)Z` | `0x107304` | `native_native_hasVideo` |
| `native_getDuration` | `(J)D` | `0x1073ac` | `native_native_getDuration` |
| `native_getVideoDuration` | `(J)D` | `0x10745c` | `native_native_getVideoDuration` |
| `native_getAudioDuration` | `(J)D` | `0x10750c` | `native_native_getAudioDuration` |
| `native_getVideoWidth` | `(J)I` | `0x1075bc` | `native_native_getVideoWidth` |
| `native_getVideoHeight` | `(J)I` | `0x107664` | `native_native_getVideoHeight` |
| `native_getFps` | `(J)F` | `0x10770c` | `native_native_getFps` |
| `native_getRotation` | `(J)I` | `0x1077bc` | `native_native_getRotation` |
| ... *(11 more entries)* | ... | ... | ... |

- **Table VA `0x1fee58`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_getVideoFrame` | `(JJ[Ljava/nio/ByteBuffer;[I[J[I[Z)I` | `0x108040` | `native_native_getVideoFrame` |

- **Table VA `0x1ff0c8`** (18 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `native_init` | `()J` | `0x116d18` | `native_native_init` |
| `native_finalize` | `(J)V` | `0x116d58` | `native_native_finalize` |
| `native_setAudioInParam` | `(JIII)I` | `0x116d88` | `native_native_setAudioInParam` |
| `native_setAudioOutParam` | `(JIII)I` | `0x116e50` | `native_native_setAudioOutParam` |
| `native_setVideoInParam` | `(JII)I` | `0x116f18` | `native_native_setVideoInParam` |
| `native_setVideoOutParam` | `(JIIIIII)I` | `0x116fe0` | `native_native_setVideoOutParam` |
| `native_setVideoOutCodec` | `(JI)I` | `0x117340` | `native_native_setVideoOutCodec` |
| `native_setVideoOutProfile` | `(JI)I` | `0x117400` | `native_native_setVideoOutProfile` |
| `native_init` | `(Ljava/lang/String;J)J` | `0x117658` | `native_native_init` |
| `native_finalize` | `(J)V` | `0x117894` | `native_native_finalize` |
| `native_setEnableHardwareMode` | `(JZ)I` | `0x1178c4` | `native_native_setEnableHardwareMode` |
| `native_registerEGLContext` | `(J)I` | `0x117974` | `native_native_registerEGLContext` |
| `native_start` | `(J)I` | `0x117acc` | `native_native_start` |
| `native_recordAudio` | `(JLjava/nio/ByteBuffer;)I` | `0x117b88` | `native_native_recordAudio` |
| `native_setEnableAsyncSendVideo` | `(JZ)I` | `0x117d00` | `native_native_setEnableAsyncSendVideo` |
| ... *(3 more entries)* | ... | ... | ... |

### libaidetectionplugin.so (5 methods in 1 tables)

- **Table VA `0x81dc8`** (5 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeSetAILogLevel` | `(I)V` | `0x405b8` | `native_nativeSetAILogLevel` |
| `nativeSetEnableParamsCapture` | `(Z)V` | `0x405c0` | `native_nativeSetEnableParamsCapture` |
| `nativeSetSingleModelPath` | `(Ljava/lang/String;Ljava/lang/String;)V` | `0x405cc` | `native_nativeSetSingleModelPath` |
| `nativeSetDetectParams` | `(Ljava/lang/String;Ljava/lang/String;)V` | `0x406c8` | `native_nativeSetDetectParams` |
| `nativeGetDetectParamsValue` | `(Ljava/lang/String;)Ljava/lang/String;` | `0x40794` | `native_nativeGetDetectParamsValue` |

### libarkernel3.so (6 methods in 6 tables)

- **Table VA `0x10cd2b0`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `Hij` | `()*` | `0x964550` | `native_Hij` |

- **Table VA `0x10cd2f0`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `HIJ` | `()*` | `0x985454` | `native_HIJ` |

- **Table VA `0x10cd340`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `HIJ` | `()*` | `0x9a7050` | `native_HIJ` |

- **Table VA `0x10cd3a0`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `HIJ` | `()*` | `0xa29564` | `native_HIJ` |

- **Table VA `0x10cd530`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `hij` | `()*` | `0xb46428` | `native_hij` |

- **Table VA `0x10f9230`** (1 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeInitBitmapDC` | `(II[BII)V` | `0xb11040` | `native_nativeInitBitmapDC` |

### libbytehook.so (10 methods in 1 tables)

- **Table VA `0x117a8`** (10 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeGetVersion` | `()Ljava/lang/String;` | `0x9234` | `native_nativeGetVersion` |
| `nativeInit` | `(IZ)I` | `0x926c` | `native_nativeInit` |
| `nativeAddIgnore` | `(Ljava/lang/String;)I` | `0x927c` | `native_nativeAddIgnore` |
| `nativeGetMode` | `()I` | `0x92f0` | `native_nativeGetMode` |
| `nativeGetDebug` | `()Z` | `0x930c` | `native_nativeGetDebug` |
| `nativeSetDebug` | `(Z)V` | `0x9324` | `native_nativeSetDebug` |
| `nativeGetRecordable` | `()Z` | `0x9330` | `native_nativeGetRecordable` |
| `nativeSetRecordable` | `(Z)V` | `0x9348` | `native_nativeSetRecordable` |
| `nativeGetRecords` | `(I)Ljava/lang/String;` | `0x9354` | `native_nativeGetRecords` |
| `nativeGetArch` | `()Ljava/lang/String;` | `0x93a4` | `native_nativeGetArch` |

### libfntvcrash.so (7 methods in 1 tables)

- **Table VA `0x15600`** (7 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeInit` | `(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ZZ)I` | `0x936c` | `native_nativeInit` |
| `nativeNotifyJavaCrashed` | `()V` | `0x9ed8` | `native_nativeNotifyJavaCrashed` |
| `fC` | `(Ljava/lang/String;)Ljava/lang/Class;` | `0xb160` | `native_fC` |
| `inv0` | `(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;[Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;` | `0xb260` | `native_inv0` |
| `set0` | `(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;Ljava/lang/Object;)V` | `0xbe88` | `native_set0` |
| `get0` | `(Ljava/lang/Object;Ljava/lang/String;ZLjava/lang/String;)Ljava/lang/Object;` | `0xc204` | `native_get0` |
| `nrInit` | `()Z` | `0xc5b8` | `native_nrInit` |

### libglide-webp.so (10 methods in 1 tables)

- **Table VA `0x68000`** (10 entries):
| Method Name | JVM Signature | Native RVA | Recovered Binding |
|---|---|---|---|
| `nativeCreateFromDirectByteBuffer` | `(Ljava/nio/ByteBuffer;)Lcom/bumptech/glide/integration/webp/WebpImage;` | `0x13058` | `native_nativeCreateFromDirectByteBuffer` |
| `nativeGetFrame` | `(I)Lcom/bumptech/glide/integration/webp/WebpFrame;` | `0x131b0` | `native_nativeGetFrame` |
| `nativeGetSizeInBytes` | `()I` | `0x13484` | `native_nativeGetSizeInBytes` |
| `nativeDispose` | `()V` | `0x13588` | `native_nativeDispose` |
| `nativeFinalize` | `()V` | `0x13694` | `native_nativeFinalize` |
| `nativeRenderFrame` | `(IILandroid/graphics/Bitmap;)V` | `0x13698` | `native_nativeRenderFrame` |
| `nativeDispose` | `()V` | `0x13c28` | `native_nativeDispose` |
| `nativeFinalize` | `()V` | `0x13d70` | `native_nativeFinalize` |
| `nativeDecodeStream` | `(Ljava/io/InputStream;Landroid/graphics/BitmapFactory$Options;F[B)Landroid/graphics/Bitmap;` | `0x14a0c` | `native_nativeDecodeStream` |
| `nativeDecodeByteArray` | `([BIILandroid/graphics/BitmapFactory$Options;F[B)Landroid/graphics/Bitmap;` | `0x14aa0` | `native_nativeDecodeByteArray` |

