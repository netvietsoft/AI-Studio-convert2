// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e6a48
// Recovered Name: _ZN11LayerFlowNS23LFLiveStickerModularJNI19nModularSetIsStrokeEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e6a48 | Size: 16 bytes | SHA256: f7314e3317a323a26024e0d6903ec48728326e2092f8f16d1bb33038acefc628
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nModularSetIsStroke(JZ)V (table at 0x5385d8)

jobject _ZN11LayerFlowNS23LFLiveStickerModularJNI19nModularSetIsStrokeEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e6a48 */ tst w3, #0xff;
    /* 0x2e6a4c */ cset w8, ne;
    /* 0x2e6a50 */ strb w8, [x2, #0x53];
    return x0;
}
