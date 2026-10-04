// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fa508
// Recovered Name: sub_3fa508
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3fa508 | Size: 1064 bytes | SHA256: 8e0a206b07170e8af1992da96dd1ec1189ef1d83a2c5d495735adf15f811108a
// Callers: 0 | Callees: 6 | Imports: 10

// Calls external APIs: _ZN12MTImageKitNS15CMTIKHairFilter11getSrcImageEv, _ZN12MTImageKitNS15CMTIKHairFilter15applyHairEffectEiNSt6__ndk110shared_ptrINS_5ImageEEE, _ZN12MTImageKitNS15CMTIKHairFilter20applyHairStyleEffectEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEf, _ZN12MTImageKitNS24CMTIKHairFlowAIGCRequest16requestWithImageENSt6__ndk110shared_ptrINS_5ImageEEENS2_INS_14CMTIKNetHeaderEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_8functionIFviiEEENSF_IFvS4_S4_S4_EEE, _ZN12MTImageKitNS6FileIO14CheckFileExistEPKc, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, memmove
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> apply configurable hair style effect, materialId=%lld, path=%s, alpha=%.2f"
//   "CLFDenseHairProcessor<%s:%d> applyHairStyleEffect failed, materialId=%lld, result=%d"
//   "CLFDenseHairProcessor<%s:%d> hair flow AIGC request failed, materialId=%lld, result=%d"
//   "applyLayer"
//   "configuration.plist"

void sub_3fa508(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 266 instructions
    /* 0x3fa508 */ ldr x0, [sp, #0x318];
    _ZdlPv();
    /* 0x3fa510 */ tbnz w24, #0, #0x3fa85c;
    /* 0x3fa514 */ mov w0, #0x40;
    _Znwm();
    /* 0x3fa51c */ ldp x8, x9, [sp, #0x10];
    /* 0x3fa520 */ mov x25, x0;
    /* 0x3fa524 */ stp xzr, xzr, [x0, #8];
    /* 0x3fa528 */ stp xzr, xzr, [x0, #0x30];
    /* 0x3fa52c */ str x9, [x0];
    /* 0x3fa530 */ str x8, [x25, #0x18]!;
    _ZN12MTImageKitNS15CMTIKHairFilter11getSrcImageEv();
    sub_5263b0();
    _ZN12MTImageKitNS24CMTIKHairFlowAIGCRequest16requestWithImageENSt6__ndk110shared_ptrINS_5ImageEEENS2_INS_14CMTIKNetHeaderEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_8functionIFviiEEENSF_IFvS4_S4_S4_EEE();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263b0();
    _ZN12MTImageKitNS15CMTIKHairFilter15applyHairEffectEiNSt6__ndk110shared_ptrINS_5ImageEEE();
    sub_2bbdb4();
    _ZNSt6__ndk14pairINS_10shared_ptrIN12MTImageKitNS5ImageEEEiED2Ev();
    sub_3fcac0();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _Znwm();
    memmove();
    _ZN12MTImageKitNS6FileIO14CheckFileExistEPKc();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_2bc260();
    _ZN12MTImageKitNS15CMTIKHairFilter20applyHairStyleEffectEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEf();
    _ZdlPv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZdlPv();
}
