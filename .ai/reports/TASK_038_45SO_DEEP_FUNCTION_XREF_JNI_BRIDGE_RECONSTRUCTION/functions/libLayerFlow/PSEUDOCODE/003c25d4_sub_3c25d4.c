// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c25d4
// Recovered Name: sub_3c25d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3c25d4 | Size: 3248 bytes | SHA256: 9c9cf47e8ab08aa9bf06a0870aa0659176e3d41e60042bf3bb52a2909a82d8d5
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, _ZNSt6__ndk15mutexD1Ev, __stack_chk_fail
// Strings referenced:
//   "abExperimentCallbackObj"
//   "autoBrushCallbackObj"
//   "bgCallbackObj"
//   "blurCallbackObj"
//   "cloudFilterCallbackObj"

void sub_3c25d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 812 instructions
    /* 0x3c25d4 */ stp x29, x30, [sp, #0x10];
    /* 0x3c25d8 */ stp x22, x21, [sp, #0x20];
    /* 0x3c25dc */ stp x20, x19, [sp, #0x30];
    /* 0x3c25e0 */ add x29, sp, #0x10;
    /* 0x3c25e4 */ adrp x8, #0x54a000;
    /* 0x3c25e8 */ mrs x21, tpidr_el0;
    /* 0x3c25ec */ mov x19, x0;
    /* 0x3c25f0 */ ldr x8, [x8, #0xdd0];
    /* 0x3c25f4 */ ldr x9, [x21, #0x28];
    /* 0x3c25f8 */ add x8, x8, #0x10;
    /* 0x3c25fc */ str x9, [sp, #8];
    _ZNSt6__ndk15mutex4lockEv();
    _ZNSt6__ndk15mutex6unlockEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZNSt6__ndk15mutexD1Ev();
    _ZN11LayerFlowNS21LFFormulaRenderPluginD1Ev();
    return x0;
    __stack_chk_fail();
    sub_2bf8c4();
}
