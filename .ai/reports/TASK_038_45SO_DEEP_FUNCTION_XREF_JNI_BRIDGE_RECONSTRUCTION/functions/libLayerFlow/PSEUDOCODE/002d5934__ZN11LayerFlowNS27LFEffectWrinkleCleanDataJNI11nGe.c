// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5934
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI11nGetModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5934 | Size: 44 bytes | SHA256: ce46c2868ba084b1c596d307ac9c30360ff3ac12d20aa7a83641217d3662278a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetModular(J)Ljava/lang/String; (table at 0x535b28)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI11nGetModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2d5934 */ cbz x2, #0x2d5958;
    /* 0x2d5938 */ ldrb w8, [x2, #8];
    /* 0x2d593c */ ldr x10, [x0];
    /* 0x2d5940 */ add x11, x2, #9;
    /* 0x2d5944 */ ldr x9, [x2, #0x18];
    /* 0x2d5948 */ tst w8, #1;
    /* 0x2d594c */ ldr x2, [x10, #0x538];
    /* 0x2d5950 */ csel x1, x11, x9, eq;
    /* 0x2d5954 */ br x2;
    /* 0x2d5958 */ mov x0, xzr;
    return x0;
}
