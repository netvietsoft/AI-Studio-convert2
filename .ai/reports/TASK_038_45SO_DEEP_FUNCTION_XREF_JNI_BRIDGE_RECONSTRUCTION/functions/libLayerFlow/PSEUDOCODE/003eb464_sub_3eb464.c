// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3eb464
// Recovered Name: sub_3eb464
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3eb464 | Size: 1184 bytes | SHA256: af9f37a3d3f765327425da3eddd0150ebb36857d3d8614b7112cee1e818d54fd
// Callers: 0 | Callees: 11 | Imports: 23

// Calls external APIs: _ZN12MTImageKitNS12CMTIKManager17getPrivateContextEv, _ZN12MTImageKitNS12CMTIKManager9addFilterEPNS_11CMTIKFilterElb, _ZN12MTImageKitNS19CMTIKVLAIBodyDetect11ImageDetectENSt6__ndk110shared_ptrINS_5ImageEEEbibbbbb, _ZN12MTImageKitNS20CMTIKBgVirtualFilter12setMaskImageEPhii, _ZN12MTImageKitNS20CMTIKBgVirtualFilter15setARConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE, _ZN12MTImageKitNS20CMTIKBgVirtualFilter16setOldEffectPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_, _ZN12MTImageKitNS20CMTIKBgVirtualFilter19setBodySegmentImageEPhii, _ZN12MTImageKitNS20CMTIKBgVirtualFilter9setParamsEPNS_22CMTIKBgVirtualParams_TE, _ZN12MTImageKitNS20CMTIKBgVirtualFilterC1Ev, _ZN12MTImageKitNS22CMTIKVLAISegmentDetect11ImageDetectENSt6__ndk110shared_ptrINS_5ImageEEENS_12CMTIKSegmentENS_5_Vec2IiEEiPb, _ZN12MTImageKitNS5Image13convertToRGBAEb, _ZN12MTImageKitNS5Image6resizeENS_5_Vec2IiEE, _ZN12MTImageKitNS5Image8getWidthEv, _ZN12MTImageKitNS5Image9getHeightEv, _ZN12MTImageKitNS7Context16isCurrentContextEv, _ZN12MTImageKitNS7Context19useAsCurrentContextEv, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNK12MTImageKitNS5Image9imageDataEv, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, memmove, strlen
// Strings referenced:
//   "CLFBlurProcessor<%s:%d> blurFullBodySegment changed current render context, restore manager context."
//   "CLFBlurProcessor<%s:%d> segmented by app, maskImage size: %d, %d"
//   "applyLayer"
//   "iklf"

void sub_3eb464(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 296 instructions
    /* 0x3eb464 */ adrp x0, #0x1d9000;
    /* 0x3eb468 */ add x0, x0, #0x93c;
    /* 0x3eb46c */ adrp x3, #0x1ce000;
    /* 0x3eb470 */ add x3, x3, #0xbb0;
    /* 0x3eb474 */ mov w1, #6;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    /* 0x3eb47c */ mov w19, wzr;
    /* 0x3eb480 */ b #0x3eb904;
    /* 0x3eb484 */ stp xzr, xzr, [sp, #0x50];
    /* 0x3eb488 */ ldp x9, x8, [sp, #0xa0];
    /* 0x3eb48c */ stp x9, x8, [sp, #0x40];
    sub_5263b0();
    _ZN12MTImageKitNS19CMTIKVLAIBodyDetect11ImageDetectENSt6__ndk110shared_ptrINS_5ImageEEEbibbbbb();
    sub_2bbdb4();
    sub_3ebd58();
    sub_3ebddc();
    sub_5263b0();
    sub_3ebddc();
    sub_2bbdb4();
    sub_2bbdb4();
    _ZN12MTImageKitNS12CMTIKManager17getPrivateContextEv();
    _ZN12MTImageKitNS7Context16isCurrentContextEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS7Context19useAsCurrentContextEv();
    _ZN12MTImageKitNS7Context16isCurrentContextEv();
    sub_3ebe48();
    _ZN12MTImageKitNS5Image8getWidthEv();
    _ZN12MTImageKitNS5Image9getHeightEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS5Image8getWidthEv();
    _ZN12MTImageKitNS5Image9getHeightEv();
    sub_3ebe9c();
    _ZN12MTImageKitNS5Image6resizeENS_5_Vec2IiEE();
    _ZdlPv();
    sub_5263b0();
    _ZN12MTImageKitNS22CMTIKVLAISegmentDetect11ImageDetectENSt6__ndk110shared_ptrINS_5ImageEEENS_12CMTIKSegmentENS_5_Vec2IiEEiPb();
    sub_3ebddc();
    sub_2bbdb4();
    sub_2bbdb4();
    _ZN12MTImageKitNS15CMTIKBodyResultD2Ev();
    _ZN12MTImageKitNS5Image13convertToRGBAEb();
    _Znwm();
    _ZN12MTImageKitNS20CMTIKBgVirtualFilterC1Ev();
    _ZN12MTImageKitNS12CMTIKManager9addFilterEPNS_11CMTIKFilterElb();
    _ZN11LayerFlowNS12CLFBlurLayer15mappingToParamsERN12MTImageKitNS22CMTIKBgVirtualParams_TE();
    _ZN11LayerFlowNS12CLFBlurLayer16getResourcePathsEv();
    sub_2fa2e8();
    _ZN12MTImageKitNS20CMTIKBgVirtualFilter16setOldEffectPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_();
    _ZdlPv();
    strlen();
    _Znwm();
    memmove();
    _ZN12MTImageKitNS20CMTIKBgVirtualFilter15setARConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE();
    _ZdlPv();
    _ZN12MTImageKitNS5Image8getWidthEv();
    _ZN12MTImageKitNS5Image9getHeightEv();
    _ZNK12MTImageKitNS5Image9imageDataEv();
    _ZN12MTImageKitNS20CMTIKBgVirtualFilter19setBodySegmentImageEPhii();
    _ZN12MTImageKitNS20CMTIKBgVirtualFilter12setMaskImageEPhii();
    _ZN12MTImageKitNS20CMTIKBgVirtualFilter9setParamsEPNS_22CMTIKBgVirtualParams_TE();
    _ZdlPv();
    _ZdlPv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
