// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x440314
// Recovered Name: sub_440314
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x440314 | Size: 2116 bytes | SHA256: 2a64cbbf938a078bdef2708d0af9e5218bafd3336a683c179177d1de38c17a61
// Callers: 0 | Callees: 64 | Imports: 2

// Calls external APIs: __android_log_print, __stack_chk_fail
// Strings referenced:
//   "18:57:58"
//   "2.5.53.0-mtxx-63"
//   "Aug 26 2026"
//   "JNI_OnLoad LayerFlow.so done. %s compiled at %s %s"
//   "LFAiModelInfoJNI register jni methods error!"

void sub_440314(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 529 instructions
    /* 0x440314 */ mov w0, #6;
    __android_log_print();
    /* 0x44031c */ mov w19, #-1;
    /* 0x440320 */ ldr x8, [x20, #0x28];
    /* 0x440324 */ ldr x9, [sp, #8];
    /* 0x440328 */ cmp x8, x9;
    /* 0x44032c */ b.ne #0x440b54;
    /* 0x440330 */ mov w0, w19;
    /* 0x440334 */ ldp x20, x19, [sp, #0x20];
    /* 0x440338 */ ldp x29, x30, [sp, #0x10];
    /* 0x44033c */ add sp, sp, #0x30;
    return x0;
    _ZN11LayerFlowNS15LFJsonPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFGenericPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS25LFPrepareManagerPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS22LFOutputImagePluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS27LFMaterialDownloadPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS29LFResourceDownloaderPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS19LFSetLayerPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS23LFSmartActionsPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS13LFMaterialJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS16LFAiModelInfoJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS13LFFontInfoJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS13LFFileInfoJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS17LFBlockingWaitJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFVisionDetectServiceJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS29LFAutoMagicPenResourceDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS21LFBlurResourceDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFCreativeStickerInfoJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS23LFCreativeAigcResultJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS15CLFNetHeaderJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFStickerLocateStatusJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFFormulaRenderPluginJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFFilterModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS16LFBlurModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS20LFCreativeModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS25LFSpecialEffectModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS13LFEditDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS16LFEnhanceDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS22LFBgBeautifyModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS16LFMarkModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS19LFStickerModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS23LFLiveStickerModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS16LFTextModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFAutoBrushDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS19LFAutoBeautyDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS17LFFrameModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFMakeUpModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN22LFMakeupRuntimeDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS21LFMakeupBagModularJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS19LFSkinWhitenDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS17LFFaceFullDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS19LFFaceRemoldDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFAigcCacheDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFImageWithPathJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS34LFStraightLegsAIGCRequestResultJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS30LFBody3DEffectRequestResultJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS19LFEffectAkneDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS25LFEffectAutoMosaicDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFEffectBodyShapeDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFEffectDenseHairDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS18LFEffectEyeDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS23LFEffectFixTeethDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS23LFEffectSlimmingDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS20LFEffectMatteDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS27LFEffectDermabrasionDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS13LFExifInfoJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS25LFAutoColorCorrectDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS17LFAutoSlimDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI18registerJniMethodsEP7_JNIEnv();
    _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI18registerJniMethodsEP7_JNIEnv();
    __android_log_print();
    __stack_chk_fail();
}
