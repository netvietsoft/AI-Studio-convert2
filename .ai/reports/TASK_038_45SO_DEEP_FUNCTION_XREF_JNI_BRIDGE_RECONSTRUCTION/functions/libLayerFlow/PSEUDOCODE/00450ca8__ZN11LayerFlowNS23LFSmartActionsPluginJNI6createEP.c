// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x450ca8
// Recovered Name: _ZN11LayerFlowNS23LFSmartActionsPluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x450ca8 | Size: 104 bytes | SHA256: 02308764e17bce0f516d4e894e2dc18189e70970cb83bc7b5e73b06780f7a5b1
// Callers: 0 | Callees: 2 | Imports: 3

// Dynamic Registration: nCreate()J (table at 0x546ab8)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZdlPv, _Znwm
// Strings referenced:
//   "create"
//   "iklf"
//   "jniSmartActionsPlg<%s:%d> ++++++ creating LFSmartActionsPluginJNI %p"

jobject _ZN11LayerFlowNS23LFSmartActionsPluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x450ca8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x450cac */ stp x20, x19, [sp, #0x10];
    /* 0x450cb0 */ mov x29, sp;
    /* 0x450cb4 */ mov w0, #0x28;
    _Znwm();
    /* 0x450cbc */ mov x19, x0;
    _ZN11LayerFlowNS23LFSmartActionsPluginJNIC1Ev();
    /* 0x450cc4 */ adrp x0, #0x1d9000;
    /* 0x450cc8 */ add x0, x0, #0x93c;
    /* 0x450ccc */ adrp x2, #0x1d8000;
    /* 0x450cd0 */ add x2, x2, #0x3d0;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    _ZdlPv();
    sub_526544();
}
