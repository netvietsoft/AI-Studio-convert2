// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3240d0
// Recovered Name: sub_3240d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3240d0 | Size: 40 bytes | SHA256: 83e726478e13fb30211c137922a89f2f2dc19972e479fb63782cbb80f4255f0c
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetFrameModularTo(JJ)Z (table at 0x53c8a8)

jlong sub_3240d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x3240d0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3240d4 */ mov x29, sp;
    /* 0x3240d8 */ ldr x8, [x2];
    /* 0x3240dc */ mov x2, x3;
    /* 0x3240e0 */ add x0, x8, #0x38;
    /* 0x3240e4 */ add x1, x8, #0x38;
    _ZNSt6__ndk116__variant_detail12__assignmentINS0_8__traitsIJ15LFOriginModular22LFIdentityPhotoModular15LFPuzzleModular20LFPuzzleFrameModular20LFPuzzleImageModular21LFPuzzleLayoutModular21LFPuzzleFusionModular21LFPuzzleSpliceModular19LFAutoBeautyModular17LFCreativeModular22LFSpecialEffectModular13LFEditModular16LFEnhanceModular16LFCompareModular19LFBgBeautifyModular15LFFilterModular16LFStickerModular20LFLiveStickerModular13LFMarkModular14LFFrameModular13LFTextModular13LFBlurModular18LFAutoBrushModular19LFSkinWhitenModular19LFSkinGlowUpModular20LFOneTapPhotoModular19LFFaceRemoldModular17LFFaceFullModular15LFMakeUpModular18LFMakeupBagModular17LFWakeSkinModular21LFDermabrasionModular14LFMatteModular13LFAkneModular17LFFixTeethModular18LFBodyShapeModular18LFHeadScaleModular21LFWrinkleCleanModular17LFSlimmingModular12LFEyeModular18LFDenseHairModular23LFOneClickBeautyModular19LFAutoMosaicModular25LFAutoColorCorrectModular17LFAutoSlimModular25LFAutoWrinkleCleanModular25LFAutoDermabrasionModular19LFAutoRemoveModular19LFCommonAigcModularEEEE12__assign_altB8ne180000ILm19ESM_RKSM_EEvRNS0_5__altIXT_ET0_EEOT1_();
    /* 0x3240ec */ mov w0, #1;
    /* 0x3240f0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
