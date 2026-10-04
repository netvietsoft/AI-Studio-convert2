// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x323c84
// Recovered Name: sub_323c84
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x323c84 | Size: 40 bytes | SHA256: 62aa6ed411f1d0211fc8e9bbbc804e9fb6c1ade81065d6b29a9c2f21a9457f17
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetBackgroundModularTo(JJ)Z (table at 0x53c800)

jlong sub_323c84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x323c84 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x323c88 */ mov x29, sp;
    /* 0x323c8c */ ldr x8, [x2];
    /* 0x323c90 */ mov x2, x3;
    /* 0x323c94 */ add x0, x8, #0x38;
    /* 0x323c98 */ add x1, x8, #0x38;
    _ZNSt6__ndk116__variant_detail12__assignmentINS0_8__traitsIJ15LFOriginModular22LFIdentityPhotoModular15LFPuzzleModular20LFPuzzleFrameModular20LFPuzzleImageModular21LFPuzzleLayoutModular21LFPuzzleFusionModular21LFPuzzleSpliceModular19LFAutoBeautyModular17LFCreativeModular22LFSpecialEffectModular13LFEditModular16LFEnhanceModular16LFCompareModular19LFBgBeautifyModular15LFFilterModular16LFStickerModular20LFLiveStickerModular13LFMarkModular14LFFrameModular13LFTextModular13LFBlurModular18LFAutoBrushModular19LFSkinWhitenModular19LFSkinGlowUpModular20LFOneTapPhotoModular19LFFaceRemoldModular17LFFaceFullModular15LFMakeUpModular18LFMakeupBagModular17LFWakeSkinModular21LFDermabrasionModular14LFMatteModular13LFAkneModular17LFFixTeethModular18LFBodyShapeModular18LFHeadScaleModular21LFWrinkleCleanModular17LFSlimmingModular12LFEyeModular18LFDenseHairModular23LFOneClickBeautyModular19LFAutoMosaicModular25LFAutoColorCorrectModular17LFAutoSlimModular25LFAutoWrinkleCleanModular25LFAutoDermabrasionModular19LFAutoRemoveModular19LFCommonAigcModularEEEE12__assign_altB8ne180000ILm14ESH_RKSH_EEvRNS0_5__altIXT_ET0_EEOT1_();
    /* 0x323ca0 */ mov w0, #1;
    /* 0x323ca4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
