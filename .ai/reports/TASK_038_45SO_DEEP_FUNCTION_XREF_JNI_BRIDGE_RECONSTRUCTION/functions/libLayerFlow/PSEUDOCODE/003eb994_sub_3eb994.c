// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3eb994
// Recovered Name: sub_3eb994
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3eb994 | Size: 776 bytes | SHA256: 6ab17ad128070ff15c1a0d2baaab822c1305defe03f5c662f3042d7f01d72ec8
// Callers: 0 | Callees: 13 | Imports: 4

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "CLFBlurProcessor<%s:%d> restore manager render context failed, return false."
//   "applyLayer"
//   "iklf"

void sub_3eb994(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 194 instructions
    /* 0x3eb994 */ ldur x20, [x29, #-0x80];
    /* 0x3eb998 */ cbz x20, #0x3eb9c4;
    /* 0x3eb99c */ add x1, x20, #8;
    /* 0x3eb9a0 */ mov x0, #-1;
    sub_5263e0();
    /* 0x3eb9a8 */ cbnz x0, #0x3eb9c4;
    /* 0x3eb9ac */ ldr x8, [x20];
    /* 0x3eb9b0 */ mov x0, x20;
    /* 0x3eb9b4 */ ldr x8, [x8, #0x10];
    /* 0x3eb9b8 */ blr x8;
    /* 0x3eb9bc */ mov x0, x20;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS15CMTIKBodyResultD2Ev();
    sub_2bc2e0();
    sub_2bc2f4();
    sub_2bc24c();
    sub_2bc24c();
    sub_2be95c();
    sub_2be95c();
    sub_2bc2f4();
    _ZdlPv();
    sub_2bbdb4();
    sub_2bbdb4();
    sub_2bbdb4();
    _ZN12MTImageKitNS15CMTIKBodyResultD2Ev();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_3ebf84();
    _ZN11LayerFlowNS17BlurResourcePathsD2Ev();
    sub_2bbdb4();
    sub_3ebd08();
    _ZdlPv();
    sub_2bbdb4();
    _ZN13LFBlurModularD2Ev();
    sub_3c3eb0();
    sub_3ebf84();
    sub_526544();
    sub_3ebf84();
    __stack_chk_fail();
}
