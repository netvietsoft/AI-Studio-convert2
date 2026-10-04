// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5c24
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5c24 | Size: 400 bytes | SHA256: 187af5ecc8ecfaa877ef558352592f7aa8897088dbbaa2ca4f7453a5252fbbad
// Callers: 0 | Callees: 4 | Imports: 1

// Dynamic Registration: nSetInfo(J[J)V (table at 0x535b70)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI8nSetInfoEP7_JNIEnvP7_jclasslP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 100 instructions
    /* 0x2d5c24 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x2d5c28 */ str x27, [sp, #0x10];
    /* 0x2d5c2c */ stp x26, x25, [sp, #0x20];
    /* 0x2d5c30 */ stp x24, x23, [sp, #0x30];
    /* 0x2d5c34 */ stp x22, x21, [sp, #0x40];
    /* 0x2d5c38 */ stp x20, x19, [sp, #0x50];
    /* 0x2d5c3c */ mov x29, sp;
    /* 0x2d5c40 */ cbz x2, #0x2d5d5c;
    /* 0x2d5c44 */ mov x19, x3;
    /* 0x2d5c48 */ cbz x3, #0x2d5d5c;
    /* 0x2d5c4c */ ldr x8, [x0];
    sub_2d5db4();
    _ZdlPv();
    _ZNSt6__ndk16vectorI17WrinkleCleanModelNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    sub_2bc260();
    return x0;
    sub_526544();
}
