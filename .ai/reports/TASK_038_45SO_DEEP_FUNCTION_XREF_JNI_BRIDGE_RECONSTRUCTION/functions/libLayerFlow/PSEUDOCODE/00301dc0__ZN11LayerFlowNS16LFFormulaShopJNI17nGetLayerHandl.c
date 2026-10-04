// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x301dc0
// Recovered Name: _ZN11LayerFlowNS16LFFormulaShopJNI17nGetLayerHandlersEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x301dc0 | Size: 528 bytes | SHA256: 24614eaaeb17623c93866a947bd28666c0aa8ea6abd843bba451115d43b09168
// Callers: 0 | Callees: 7 | Imports: 4

// Dynamic Registration: nGetLayerHandlers(J)[J (table at 0x53bf40)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, __stack_chk_fail

jobject _ZN11LayerFlowNS16LFFormulaShopJNI17nGetLayerHandlersEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x301dc0 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x301dc4 */ stp x28, x27, [sp, #0x10];
    /* 0x301dc8 */ stp x26, x25, [sp, #0x20];
    /* 0x301dcc */ stp x24, x23, [sp, #0x30];
    /* 0x301dd0 */ stp x22, x21, [sp, #0x40];
    /* 0x301dd4 */ stp x20, x19, [sp, #0x50];
    /* 0x301dd8 */ mov x29, sp;
    /* 0x301ddc */ sub sp, sp, #0x30;
    /* 0x301de0 */ mrs x8, tpidr_el0;
    /* 0x301de4 */ mov x19, x0;
    /* 0x301de8 */ mov x0, x2;
    _ZN11LayerFlowNS13LFFormulaShop12getCLFLayersEv();
    _Znwm();
    _ZN11LayerFlowNS11LFBaseLayerC1Ev();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZN11LayerFlowNS11LFBaseLayer16getNativeHandlerEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_301fd0();
    sub_526544();
    __stack_chk_fail();
}
