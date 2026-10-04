// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3ca830
// Recovered Name: sub_3ca830
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3ca830 | Size: 856 bytes | SHA256: 51aa164af343a0fe3e9e345ad548f6eb8feb3e92be3e1f58c8f9c090e1d6d3b2
// Callers: 0 | Callees: 8 | Imports: 7

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, __dynamic_cast, __stack_chk_fail
// Strings referenced:
//   "(J[IJ)V"
//   "ZN11LayerFlowNS21LFFormulaRenderPlugin18setupBlurCallbacksEPS0_NSt6__ndk110shared_ptrINS_22CLFFormulaRenderPluginEEEE3$_0"
//   "cbBlurResourceDataHandler"
//   "iklf"
//   "jniFormulaRender<%s:%d> blurResourceData == nullptr"

void sub_3ca830(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 214 instructions
    /* 0x3ca830 */ stp x29, x30, [sp, #0x20];
    /* 0x3ca834 */ stp x28, x27, [sp, #0x30];
    /* 0x3ca838 */ stp x26, x25, [sp, #0x40];
    /* 0x3ca83c */ stp x24, x23, [sp, #0x50];
    /* 0x3ca840 */ stp x22, x21, [sp, #0x60];
    /* 0x3ca844 */ stp x20, x19, [sp, #0x70];
    /* 0x3ca848 */ add x29, sp, #0x20;
    /* 0x3ca84c */ mrs x27, tpidr_el0;
    /* 0x3ca850 */ mov x21, x0;
    /* 0x3ca854 */ mov x22, x2;
    /* 0x3ca858 */ ldr x9, [x27, #0x28];
    _ZN11LayerFlowNS12LFBasePlugin11getLFShopIdEv();
    __dynamic_cast();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _Znwm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_2c39cc();
    _ZN11LayerFlowNS14BlockingSignal18generateBlockingIdEl();
    sub_3027e0();
    _ZN11LayerFlowNS14BlockingSignal13waitForSignalEll();
    sub_5263b0();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_526544();
    __stack_chk_fail();
    return x0;
    return x0;
}
