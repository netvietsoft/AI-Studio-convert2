// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d572c
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nGetMaskIdEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d572c | Size: 44 bytes | SHA256: ce46c2868ba084b1c596d307ac9c30360ff3ac12d20aa7a83641217d3662278a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetMaskId(J)Ljava/lang/String; (table at 0x535a80)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nGetMaskIdEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2d572c */ cbz x2, #0x2d5750;
    /* 0x2d5730 */ ldrb w8, [x2, #8];
    /* 0x2d5734 */ ldr x10, [x0];
    /* 0x2d5738 */ add x11, x2, #9;
    /* 0x2d573c */ ldr x9, [x2, #0x18];
    /* 0x2d5740 */ tst w8, #1;
    /* 0x2d5744 */ ldr x2, [x10, #0x538];
    /* 0x2d5748 */ csel x1, x11, x9, eq;
    /* 0x2d574c */ br x2;
    /* 0x2d5750 */ mov x0, xzr;
    return x0;
}
