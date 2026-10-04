// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3fb6bc
// Recovered Name: sub_3fb6bc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3fb6bc | Size: 1012 bytes | SHA256: 3ec471af9ff165f120483b494630a7120ce9c12481a6ea32a3b196731e890d4d
// Callers: 0 | Callees: 5 | Imports: 12

// Calls external APIs: _ZN12MTImageKitNS12CMTIKManager13processRenderEb, _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb, _ZN12MTImageKitNS15CMTIKHairFilter11getSrcImageEv, _ZN12MTImageKitNS15CMTIKHairFilter16setHairMaskImageENSt6__ndk110shared_ptrINS_5ImageEEEb, _ZN12MTImageKitNS15CMTIKHairFilter18setWhitenHairImageENSt6__ndk110shared_ptrINS_5ImageEEE, _ZN12MTImageKitNS15CMTIKHairFilter21setDyeHairRenderAlphaEf, _ZN12MTImageKitNS15CMTIKHairFilter22setDyeHairMaterialInfoENS_11DyeHairInfoEb, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, memmove
// Strings referenced:
//   "CLFDenseHairProcessor<%s:%d> aigc error."
//   "applyLayer"
//   "iklf"

void sub_3fb6bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 253 instructions
    /* 0x3fb6bc */ ldr x1, [sp, #0x2e0];
    /* 0x3fb6c0 */ ldr x2, [sp, #0x2e8];
    /* 0x3fb6c4 */ cmp x1, x2;
    /* 0x3fb6c8 */ b.eq #0x3fb9c4;
    /* 0x3fb6cc */ ldrb w8, [sp, #0x2fc];
    /* 0x3fb6d0 */ cbz w8, #0x3fb8ec;
    /* 0x3fb6d4 */ add x8, sp, #0x390;
    /* 0x3fb6d8 */ mov x0, x20;
    _ZN12MTImageKitNS15CMTIKHairFilter11getSrcImageEv();
    /* 0x3fb6e0 */ ldr x8, [sp, #0x390];
    /* 0x3fb6e4 */ cbz x8, #0x3fb8ac;
    sub_4001c4();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263b0();
    _ZN12MTImageKitNS15CMTIKHairFilter16setHairMaskImageENSt6__ndk110shared_ptrINS_5ImageEEEb();
    sub_2bbdb4();
    sub_5263b0();
    _ZN12MTImageKitNS15CMTIKHairFilter18setWhitenHairImageENSt6__ndk110shared_ptrINS_5ImageEEE();
    sub_2bbdb4();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZNSt6__ndk16vectorIN12MTImageKitNS19DyeHairMaterialDataENS_9allocatorIS2_EEE16__init_with_sizeB8ne180000IPS2_S7_EEvT_T0_m();
    _ZN12MTImageKitNS15CMTIKHairFilter22setDyeHairMaterialInfoENS_11DyeHairInfoEb();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZN12MTImageKitNS15CMTIKHairFilter21setDyeHairRenderAlphaEf();
    _ZN12MTImageKitNS12CMTIKManager13processRenderEb();
    _ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    memmove();
}
