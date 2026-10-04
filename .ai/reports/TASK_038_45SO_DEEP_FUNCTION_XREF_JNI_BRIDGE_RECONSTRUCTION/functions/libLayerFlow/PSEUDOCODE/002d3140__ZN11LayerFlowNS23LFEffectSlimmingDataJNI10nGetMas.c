// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d3140
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI10nGetMaskIdEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d3140 | Size: 32 bytes | SHA256: 62161de96d85440c92ce7ff167074f5030b71f3ee7656a9e607bbaf9e104c982
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetMaskId(J)Ljava/lang/String; (table at 0x5350a8)

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI10nGetMaskIdEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d3140 */ ldrb w8, [x2, #0x28];
    /* 0x2d3144 */ ldr x10, [x0];
    /* 0x2d3148 */ add x11, x2, #0x29;
    /* 0x2d314c */ ldr x9, [x2, #0x38];
    /* 0x2d3150 */ tst w8, #1;
    /* 0x2d3154 */ ldr x2, [x10, #0x538];
    /* 0x2d3158 */ csel x1, x11, x9, eq;
    /* 0x2d315c */ br x2;
}
