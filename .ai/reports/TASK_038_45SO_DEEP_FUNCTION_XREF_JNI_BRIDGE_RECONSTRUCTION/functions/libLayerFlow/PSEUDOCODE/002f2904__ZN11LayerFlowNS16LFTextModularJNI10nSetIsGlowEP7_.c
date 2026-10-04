// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2904
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI10nSetIsGlowEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2904 | Size: 16 bytes | SHA256: d1d823a10c52108fd933158c16e32452bdafba17d0c9d22b33bada8571b49f0b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsGlow(JZ)V (table at 0x53a990)

jobject _ZN11LayerFlowNS16LFTextModularJNI10nSetIsGlowEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2904 */ tst w3, #0xff;
    /* 0x2f2908 */ cset w8, ne;
    /* 0x2f290c */ strb w8, [x2, #0x49];
    return x0;
}
