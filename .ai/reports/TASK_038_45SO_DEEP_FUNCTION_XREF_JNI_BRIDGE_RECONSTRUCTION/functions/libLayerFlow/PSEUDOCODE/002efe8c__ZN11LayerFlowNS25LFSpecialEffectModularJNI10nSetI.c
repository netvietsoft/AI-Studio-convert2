// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2efe8c
// Recovered Name: _ZN11LayerFlowNS25LFSpecialEffectModularJNI10nSetIsLiveEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2efe8c | Size: 20 bytes | SHA256: 2274f084abf6163bbcdcefd3365848371f4658f2d453cbdc829f2d1b1a881e62
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsLive(JZ)V (table at 0x539f48)

jobject _ZN11LayerFlowNS25LFSpecialEffectModularJNI10nSetIsLiveEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2efe8c */ and w8, w3, #0xff;
    /* 0x2efe90 */ cmp w8, #1;
    /* 0x2efe94 */ cset w8, eq;
    /* 0x2efe98 */ strb w8, [x2, #0x2c];
    return x0;
}
