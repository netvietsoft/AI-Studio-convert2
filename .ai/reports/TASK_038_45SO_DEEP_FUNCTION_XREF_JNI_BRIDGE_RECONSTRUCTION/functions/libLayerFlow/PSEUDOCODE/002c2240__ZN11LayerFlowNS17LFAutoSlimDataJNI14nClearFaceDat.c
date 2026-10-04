// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2240
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2240 | Size: 48 bytes | SHA256: 372e3fdc07346afcdaf0924ea5e3af596af31738f509857e9cb7d0fc24c8510a
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nClearFaceData(J)V (table at 0x531fe8)

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x2c2240 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c2244 */ str x19, [sp, #0x10];
    /* 0x2c2248 */ mov x29, sp;
    /* 0x2c224c */ mov x19, x2;
    /* 0x2c2250 */ ldr x1, [x19, #0x28]!;
    /* 0x2c2254 */ sub x0, x19, #8;
    sub_2c23b0();
    /* 0x2c225c */ stp x19, xzr, [x19, #-8];
    /* 0x2c2260 */ str xzr, [x19, #8];
    /* 0x2c2264 */ ldr x19, [sp, #0x10];
    /* 0x2c2268 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
