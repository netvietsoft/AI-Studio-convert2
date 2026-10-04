// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3ea99c
// Recovered Name: sub_3ea99c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3ea99c | Size: 456 bytes | SHA256: 136ba76a299a2e465e93dde66966dbf7c5c75f2f1bae8eebf4624d7ccf329762
// Callers: 0 | Callees: 8 | Imports: 4

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "applyLayer"
//   "iklf"
//   "pcsBg<%s:%d> lack of parameters, no effect specified, we use gauss blur as default"

void sub_3ea99c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x3ea99c */ ldur x20, [x29, #-0x10];
    /* 0x3ea9a0 */ cbz x20, #0x3ea41c;
    /* 0x3ea9a4 */ add x1, x20, #8;
    /* 0x3ea9a8 */ mov x0, #-1;
    sub_5263e0();
    /* 0x3ea9b0 */ cbnz x0, #0x3ea41c;
    /* 0x3ea9b4 */ ldr x8, [x20];
    /* 0x3ea9b8 */ mov x0, x20;
    /* 0x3ea9bc */ ldr x8, [x8, #0x10];
    /* 0x3ea9c0 */ blr x8;
    /* 0x3ea9c4 */ mov x0, x20;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_3eac60();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_2bbdb4();
    _ZdlPv();
    _ZdlPv();
    _ZN12MTImageKitNS21CMTIKBGBeautifyInfo_TD2Ev();
    _ZdlPv();
    _ZN19LFBgBeautifyModularD2Ev();
    sub_3eacf4();
    sub_3c3eb0();
    sub_526544();
    __stack_chk_fail();
}
