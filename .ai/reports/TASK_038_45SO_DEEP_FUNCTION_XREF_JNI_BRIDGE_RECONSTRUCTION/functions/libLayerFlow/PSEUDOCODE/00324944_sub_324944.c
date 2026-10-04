// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x324944
// Recovered Name: sub_324944
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x324944 | Size: 40 bytes | SHA256: 6e983b30cc39377d04763ccdd3d6fa7d1cac930d6eddde350955a793c3b01972
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetHeadScaleModularTo(JJ)Z (table at 0x53ca10)

jlong sub_324944(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x324944 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x324948 */ mov x29, sp;
    /* 0x32494c */ ldr x8, [x2];
    /* 0x324950 */ mov x2, x3;
    /* 0x324954 */ add x0, x8, #0x38;
    /* 0x324958 */ add x1, x8, #0x38;
    _ZNSt6__ndk116__variant_detail12__assignmentINS0_8__traitsIJ15LFOriginModular22LFIdentityPhotoModular15LFPuzzleModular20LFPuzzleFrameModular20LFPuzzleImageModular21LFPuzzleLayoutModular21LFPuzzleFusionModular21LFPuzzleSpliceModular19LFAutoBeautyModular17LFCreativeModular22LFSpecialEffectModular13LFEditModular16LFEnhanceModular16LFCompareModular19LFBgBeautifyModular15LFFilterModular16LFStickerModular20LFLiveStickerModular13LFMarkModular14LFFrameModular13LFTextModular13LFBlurModular18LFAutoBrushModular19LFSkinWhitenModular19LFSkinGlowUpModular20LFOneTapPhotoModular19LFFaceRemoldModular17LFFaceFullModular15LFMakeUpModular18LFMakeupBagModular17LFWakeSkinModular21LFDermabrasionModular14LFMatteModular13LFAkneModular17LFFixTeethModular18LFBodyShapeModular18LFHeadScaleModular21LFWrinkleCleanModular17LFSlimmingModular12LFEyeModular18LFDenseHairModular23LFOneClickBeautyModular19LFAutoMosaicModular25LFAutoColorCorrectModular17LFAutoSlimModular25LFAutoWrinkleCleanModular25LFAutoDermabrasionModular19LFAutoRemoveModular19LFCommonAigcModularEEEE12__assign_altB8ne180000ILm36ES13_RKS13_EEvRNS0_5__altIXT_ET0_EEOT1_();
    /* 0x324960 */ mov w0, #1;
    /* 0x324964 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
