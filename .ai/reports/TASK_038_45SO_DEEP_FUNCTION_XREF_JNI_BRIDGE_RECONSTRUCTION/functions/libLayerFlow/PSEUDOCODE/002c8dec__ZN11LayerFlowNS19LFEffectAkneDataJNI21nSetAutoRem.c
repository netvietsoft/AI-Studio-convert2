// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8dec
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI21nSetAutoRemoveSpotsAiEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8dec | Size: 16 bytes | SHA256: d5ec992f2aa34227f066ae3a0312e33fc7b21c661052eceb62e1d11f97c8beb1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetAutoRemoveSpotsAi(JZ)V (table at 0x5332a8)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI21nSetAutoRemoveSpotsAiEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c8dec */ tst w3, #0xff;
    /* 0x2c8df0 */ cset w8, ne;
    /* 0x2c8df4 */ strb w8, [x2, #7];
    return x0;
}
