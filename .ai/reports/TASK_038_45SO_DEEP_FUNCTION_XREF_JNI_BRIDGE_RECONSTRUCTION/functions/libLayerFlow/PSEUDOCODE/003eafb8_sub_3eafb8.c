// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3eafb8
// Recovered Name: sub_3eafb8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3eafb8 | Size: 1196 bytes | SHA256: 5e2c01a13acb0327211eb927ef6e4053f3be9efe7911f772f22d564120514a15
// Callers: 0 | Callees: 10 | Imports: 6

// Calls external APIs: _ZN12MTImageKitNS5Image8getWidthEv, _ZN12MTImageKitNS5Image9getHeightEv, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm
// Strings referenced:
//   "CLFBlurProcessor<%s:%d> Blur layer has no material, return false."
//   "CLFBlurProcessor<%s:%d> Blur layer has no render plugin, return false."
//   "CLFBlurProcessor<%s:%d> Dynamic cast to CLFBlurLayer failed"
//   "applyLayer"
//   "iklf"

void sub_3eafb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 299 instructions
    /* 0x3eafb8 */ ldr x8, [x24, #0x28];
    /* 0x3eafbc */ ldur x9, [x29, #-8];
    /* 0x3eafc0 */ cmp x8, x9;
    /* 0x3eafc4 */ b.ne #0x3ebc98;
    /* 0x3eafc8 */ mov w0, w19;
    /* 0x3eafcc */ add sp, sp, #0x1e0;
    /* 0x3eafd0 */ ldp x20, x19, [sp, #0x50];
    /* 0x3eafd4 */ ldp x22, x21, [sp, #0x40];
    /* 0x3eafd8 */ ldp x24, x23, [sp, #0x30];
    /* 0x3eafdc */ ldp x26, x25, [sp, #0x20];
    /* 0x3eafe0 */ ldp x28, x27, [sp, #0x10];
    return x0;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZdlPv();
    _ZN11LayerFlowNS12CLFBlurLayer10getModularEv();
    _ZN11LayerFlowNS16CLFBaseProcessor19solidifyFilterChainEb();
    _ZN12MTImageKitNS5Image8getWidthEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _Znwm();
    _ZdlPv();
    _ZN12MTImageKitNS5Image9getHeightEv();
    _Znwm();
    _ZdlPv();
    sub_3eabd8();
    sub_3ebc9c();
    sub_3ebd08();
    _ZdlPv();
    sub_3e679c();
    sub_3ebd58();
    sub_3ebddc();
    sub_2bbdb4();
}
