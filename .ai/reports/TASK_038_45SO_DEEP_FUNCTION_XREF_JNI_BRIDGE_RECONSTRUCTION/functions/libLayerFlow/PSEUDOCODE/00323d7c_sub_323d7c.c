// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x323d7c
// Recovered Name: sub_323d7c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x323d7c | Size: 40 bytes | SHA256: 532cc39138478b0b87e52faaa88c6466302a891dea3ba03e8537299a358230a6
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetStickerModularTo(JJ)Z (table at 0x53c830)

jlong sub_323d7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x323d7c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x323d80 */ mov x29, sp;
    /* 0x323d84 */ ldr x8, [x2];
    /* 0x323d88 */ mov x2, x3;
    /* 0x323d8c */ add x0, x8, #0x38;
    /* 0x323d90 */ add x1, x8, #0x38;
    _ZNSt6__ndk116__variant_detail12__assignmentINS0_8__traitsIJ15LFOriginModular22LFIdentityPhotoModular15LFPuzzleModular20LFPuzzleFrameModular20LFPuzzleImageModular21LFPuzzleLayoutModular21LFPuzzleFusionModular21LFPuzzleSpliceModular19LFAutoBeautyModular17LFCreativeModular22LFSpecialEffectModular13LFEditModular16LFEnhanceModular16LFCompareModular19LFBgBeautifyModular15LFFilterModular16LFStickerModular20LFLiveStickerModular13LFMarkModular14LFFrameModular13LFTextModular13LFBlurModular18LFAutoBrushModular19LFSkinWhitenModular19LFSkinGlowUpModular20LFOneTapPhotoModular19LFFaceRemoldModular17LFFaceFullModular15LFMakeUpModular18LFMakeupBagModular17LFWakeSkinModular21LFDermabrasionModular14LFMatteModular13LFAkneModular17LFFixTeethModular18LFBodyShapeModular18LFHeadScaleModular21LFWrinkleCleanModular17LFSlimmingModular12LFEyeModular18LFDenseHairModular23LFOneClickBeautyModular19LFAutoMosaicModular25LFAutoColorCorrectModular17LFAutoSlimModular25LFAutoWrinkleCleanModular25LFAutoDermabrasionModular19LFAutoRemoveModular19LFCommonAigcModularEEEE12__assign_altB8ne180000ILm16ESJ_RKSJ_EEvRNS0_5__altIXT_ET0_EEOT1_();
    /* 0x323d98 */ mov w0, #1;
    /* 0x323d9c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
