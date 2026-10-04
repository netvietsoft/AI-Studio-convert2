// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3c18
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI13nTucSetIsGlowEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3c18 | Size: 16 bytes | SHA256: 583ee531056d119996b977b1d32c09c3db7581165a154128414ec442493f20ec
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsGlow(JZ)V (table at 0x53b458)

jobject _ZN11LayerFlowNS16LFTextModularJNI13nTucSetIsGlowEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f3c18 */ tst w3, #0xff;
    /* 0x2f3c1c */ cset w8, ne;
    /* 0x2f3c20 */ strb w8, [x2, #0x54];
    return x0;
}
