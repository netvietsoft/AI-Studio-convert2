// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x324718
// Recovered Name: sub_324718
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x324718 | Size: 40 bytes | SHA256: 7ef9131670ad7bcb31af33fd6007572e133c6dd057203daac5947bd5f7756e22
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetBodyShapeModularTo(JJ)Z (table at 0x53c9b0)

jlong sub_324718(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x324718 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x32471c */ mov x29, sp;
    /* 0x324720 */ ldr x8, [x2];
    /* 0x324724 */ mov x2, x3;
    /* 0x324728 */ add x0, x8, #0x38;
    /* 0x32472c */ add x1, x8, #0x38;
    _ZNSt6__ndk116__variant_detail12__assignmentINS0_8__traitsIJ15LFOriginModular22LFIdentityPhotoModular15LFPuzzleModular20LFPuzzleFrameModular20LFPuzzleImageModular21LFPuzzleLayoutModular21LFPuzzleFusionModular21LFPuzzleSpliceModular19LFAutoBeautyModular17LFCreativeModular22LFSpecialEffectModular13LFEditModular16LFEnhanceModular16LFCompareModular19LFBgBeautifyModular15LFFilterModular16LFStickerModular20LFLiveStickerModular13LFMarkModular14LFFrameModular13LFTextModular13LFBlurModular18LFAutoBrushModular19LFSkinWhitenModular19LFSkinGlowUpModular20LFOneTapPhotoModular19LFFaceRemoldModular17LFFaceFullModular15LFMakeUpModular18LFMakeupBagModular17LFWakeSkinModular21LFDermabrasionModular14LFMatteModular13LFAkneModular17LFFixTeethModular18LFBodyShapeModular18LFHeadScaleModular21LFWrinkleCleanModular17LFSlimmingModular12LFEyeModular18LFDenseHairModular23LFOneClickBeautyModular19LFAutoMosaicModular25LFAutoColorCorrectModular17LFAutoSlimModular25LFAutoWrinkleCleanModular25LFAutoDermabrasionModular19LFAutoRemoveModular19LFCommonAigcModularEEEE12__assign_altB8ne180000ILm35ES12_RKS12_EEvRNS0_5__altIXT_ET0_EEOT1_();
    /* 0x324734 */ mov w0, #1;
    /* 0x324738 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
