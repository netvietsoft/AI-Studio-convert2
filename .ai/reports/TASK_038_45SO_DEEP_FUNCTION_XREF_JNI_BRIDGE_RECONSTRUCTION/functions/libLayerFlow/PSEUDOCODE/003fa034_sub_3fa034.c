// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fa034
// Recovered Name: sub_3fa034
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3fa034 | Size: 768 bytes | SHA256: d9d156e12d02f7f8030c69c0b35a5adce2b0268b00c324df16792c4c3c17345c
// Callers: 0 | Callees: 2 | Imports: 10

// Calls external APIs: _ZN12MTImageKitNS12CMTIKManager13processRenderEb, _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb, _ZN12MTImageKitNS15CMTIKHairFilter15setFunctionTypeENS_13CMTIKHairTypeE, _ZN12MTImageKitNS15CMTIKHairFilter20applyCurlyHairEffectEiNSt6__ndk110shared_ptrINS_5ImageEEE, _ZN12MTImageKitNS15CMTIKHairFilter20applyShinyHairEffectEif, _ZN12MTImageKitNS15CMTIKHairFilter21applySmoothHairEffectEif, _ZN12MTImageKitNS15CMTIKHairFilter23applyStraightHairEffectEiiNSt6__ndk110shared_ptrINS_5ImageEEE, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc, _ZNSt6__ndk119__shared_weak_count14__release_weakEv
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> apply straight hair, faceId=%d, alpha=%.2f, softSwitch=%d"
//   "CLFDenseHairProcessor<%s:%d> hair style material path is empty, materialId=%lld"
//   "CLFDenseHairProcessor<%s:%d> renderPlugin->cbSetNetHeader is nullptr."
//   "applyLayer"
//   "loadHairDyeConfig"

void sub_3fa034(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 192 instructions
    /* 0x3fa034 */ ldrb w8, [sp, #0x390];
    /* 0x3fa038 */ ldr w24, [x22, #8];
    /* 0x3fa03c */ tbnz w8, #0, #0x3fac94;
    /* 0x3fa040 */ ldr q0, [sp, #0x390];
    /* 0x3fa044 */ ldr x8, [sp, #0x3a0];
    /* 0x3fa048 */ str q0, [sp, #0x100];
    /* 0x3fa04c */ str x8, [sp, #0x110];
    /* 0x3fa050 */ b #0x3faca4;
    /* 0x3fa054 */ mov x0, x20;
    /* 0x3fa058 */ mov w1, #8;
    _ZN12MTImageKitNS15CMTIKHairFilter15setFunctionTypeENS_13CMTIKHairTypeE();
    _ZN12MTImageKitNS15CMTIKHairFilter20applyCurlyHairEffectEiNSt6__ndk110shared_ptrINS_5ImageEEE();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN12MTImageKitNS15CMTIKHairFilter15setFunctionTypeENS_13CMTIKHairTypeE();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS15CMTIKHairFilter23applyStraightHairEffectEiiNSt6__ndk110shared_ptrINS_5ImageEEE();
    sub_5263e0();
    _ZN12MTImageKitNS12CMTIKManager13processRenderEb();
    _ZN12MTImageKitNS15CMTIKHairFilter15setFunctionTypeENS_13CMTIKHairTypeE();
    _ZN12MTImageKitNS15CMTIKHairFilter20applyShinyHairEffectEif();
    _ZN12MTImageKitNS15CMTIKHairFilter15setFunctionTypeENS_13CMTIKHairTypeE();
    _ZN12MTImageKitNS15CMTIKHairFilter21applySmoothHairEffectEif();
    _ZN12MTImageKitNS12CMTIKManager13processRenderEb();
    _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb();
    sub_2bc260();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
}
