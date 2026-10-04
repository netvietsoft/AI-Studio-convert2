// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x44e4e8
// Recovered Name: _ZN11LayerFlowNS22LFOutputImagePluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x44e4e8 | Size: 320 bytes | SHA256: 233ceb78078bac7322242bf4ae29423ca7afb05a2a87b5dd43ce6480eabe2e01
// Callers: 0 | Callees: 2 | Imports: 3

// Dynamic Registration: nCreate()J (table at 0x5466b0)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZdlPv, _Znwm
// Strings referenced:
//   "()I"
//   "(JII)V"
//   "(Landroid/graphics/Bitmap;)V"
//   "callbackType"
//   "create"

jobject _ZN11LayerFlowNS22LFOutputImagePluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 80 instructions
    /* 0x44e4e8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x44e4ec */ str x23, [sp, #0x10];
    /* 0x44e4f0 */ stp x22, x21, [sp, #0x20];
    /* 0x44e4f4 */ stp x20, x19, [sp, #0x30];
    /* 0x44e4f8 */ mov x29, sp;
    /* 0x44e4fc */ mov x21, x0;
    /* 0x44e500 */ mov w0, #0x48;
    /* 0x44e504 */ mov x20, x1;
    _Znwm();
    /* 0x44e50c */ mov x19, x0;
    _ZN11LayerFlowNS22LFOutputImagePluginJNIC2Ev();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    _ZdlPv();
    sub_526544();
}
