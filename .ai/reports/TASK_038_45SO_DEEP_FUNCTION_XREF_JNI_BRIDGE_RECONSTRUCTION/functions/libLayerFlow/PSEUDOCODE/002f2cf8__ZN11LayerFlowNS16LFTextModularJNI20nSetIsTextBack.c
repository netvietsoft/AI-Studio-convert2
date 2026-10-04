// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2cf8
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI20nSetIsTextBackgroundEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2cf8 | Size: 16 bytes | SHA256: 5ee23e3bb4c62a2e64d6ac722f08df16445c7b0a90b224f2bff0e3da3a2f74eb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsTextBackground(JZ)V (table at 0x53ade0)

jobject _ZN11LayerFlowNS16LFTextModularJNI20nSetIsTextBackgroundEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2cf8 */ tst w3, #0xff;
    /* 0x2f2cfc */ cset w8, ne;
    /* 0x2f2d00 */ strb w8, [x2, #0x130];
    return x0;
}
