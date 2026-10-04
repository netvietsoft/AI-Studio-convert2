// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8010
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI14nSetSkinWhitenEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8010 | Size: 32 bytes | SHA256: 9f0281bfef0d3f2d5fdbaac8257d94598af4d15fef70871cd1e2aa24563b0cd2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetSkinWhiten(JJ)V (table at 0x5363b0)

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI14nSetSkinWhitenEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d8010 */ add x8, x2, #0x118;
    /* 0x2d8014 */ cbz x3, #0x2d8024;
    /* 0x2d8018 */ ldp q1, q0, [x3];
    /* 0x2d801c */ stp q1, q0, [x8];
    return x0;
    /* 0x2d8024 */ movi v0.2d, #0000000000000000;
    /* 0x2d8028 */ stp q0, q0, [x8];
    return x0;
}
