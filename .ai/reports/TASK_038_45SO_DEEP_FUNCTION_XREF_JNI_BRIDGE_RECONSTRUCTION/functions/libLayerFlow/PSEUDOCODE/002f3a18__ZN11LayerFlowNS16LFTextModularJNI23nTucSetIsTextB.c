// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3a18
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI23nTucSetIsTextBackgroundEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3a18 | Size: 16 bytes | SHA256: 1a262718728e2e62ec6be8d41e5f3718ca9607f6128ccbf95399ccae03a050b8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsTextBackground(JZ)V (table at 0x53b368)

jobject _ZN11LayerFlowNS16LFTextModularJNI23nTucSetIsTextBackgroundEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f3a18 */ tst w3, #0xff;
    /* 0x2f3a1c */ cset w8, ne;
    /* 0x2f3a20 */ strb w8, [x2, #0x28];
    return x0;
}
