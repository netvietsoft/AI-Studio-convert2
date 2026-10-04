// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3af94c
// Recovered Name: sub_3af94c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3af94c | Size: 2556 bytes | SHA256: 3f337202b8a37704492a3b1da4e68db004afce5f80a01c50038b800b5c3a4beb
// Callers: 0 | Callees: 10 | Imports: 6

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZNSt6__ndk19to_stringEi, _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "230"
//   "unsupported categoryId="
//   "unsupported dense hair functionId="

void sub_3af94c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 639 instructions
    /* 0x3af94c */ mov w2, w20;
    /* 0x3af950 */ ldp x20, x19, [sp, #0xf0];
    /* 0x3af954 */ ldr d8, [sp, #0x90];
    /* 0x3af958 */ ldp x22, x21, [sp, #0xe0];
    /* 0x3af95c */ ldp x24, x23, [sp, #0xd0];
    /* 0x3af960 */ ldp x26, x25, [sp, #0xc0];
    /* 0x3af964 */ ldp x28, x27, [sp, #0xb0];
    /* 0x3af968 */ ldp x29, x30, [sp, #0xa0];
    /* 0x3af96c */ add sp, sp, #0x100;
    /* 0x3af970 */ b #0x3b0348;
    /* 0x3af974 */ mov w8, #0x59e3;
    sub_525b68();
    _Znwm();
    _ZdlPv();
    return x0;
    _ZNSt6__ndk19to_stringEi();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZdlPv();
    _ZdlPv();
    _ZN11LayerFlowNS24LFSmartFaceRemoldMapping13createModularEiiiibPNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZNSt6__ndk18optionalINS_7variantIJ15LFOriginModular22LFIdentityPhotoModular15LFPuzzleModular20LFPuzzleFrameModular20LFPuzzleImageModular21LFPuzzleLayoutModular21LFPuzzleFusionModular21LFPuzzleSpliceModular19LFAutoBeautyModular17LFCreativeModular22LFSpecialEffectModular13LFEditModular16LFEnhanceModular16LFCompareModular19LFBgBeautifyModular15LFFilterModular16LFStickerModular20LFLiveStickerModular13LFMarkModular14LFFrameModular13LFTextModular13LFBlurModular18LFAutoBrushModular19LFSkinWhitenModular19LFSkinGlowUpModular20LFOneTapPhotoModular19LFFaceRemoldModular17LFFaceFullModular15LFMakeUpModular18LFMakeupBagModular17LFWakeSkinModular21LFDermabrasionModular14LFMatteModular13LFAkneModular17LFFixTeethModular18LFBodyShapeModular18LFHeadScaleModular21LFWrinkleCleanModular17LFSlimmingModular12LFEyeModular18LFDenseHairModular23LFOneClickBeautyModular19LFAutoMosaicModular25LFAutoColorCorrectModular17LFAutoSlimModular25LFAutoWrinkleCleanModular25LFAutoDermabrasionModular19LFAutoRemoveModular19LFCommonAigcModularEEEEC2B8ne180000ISS_TnNS_9enable_ifIXclsr22_CheckOptionalLikeCtorIT_OS1J_EE17__enable_implicitIS1J_EEEiE4typeELi0EEEONS0_IS1J_EE();
    sub_3b1144();
    sub_3b064c();
    _ZN15LFFilterModularD2Ev();
    _ZNSt6__ndk19to_stringEi();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_2cbab0();
    sub_2be95c();
    sub_3b1144();
    _ZdlPv();
    _ZN18LFDenseHairModularD2Ev();
    _ZdlPv();
    sub_526544();
    __stack_chk_fail();
}
