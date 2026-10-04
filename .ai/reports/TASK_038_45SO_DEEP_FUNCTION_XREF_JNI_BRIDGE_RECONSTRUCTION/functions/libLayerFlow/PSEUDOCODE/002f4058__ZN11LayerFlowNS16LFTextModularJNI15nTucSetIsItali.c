// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4058
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI15nTucSetIsItalicEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4058 | Size: 16 bytes | SHA256: 7002ca9bb15fd3eb5b87e3bef602412bad412aca60e328c1a3be446ed4247f52
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsItalic(JZ)V (table at 0x53b6c8)

jobject _ZN11LayerFlowNS16LFTextModularJNI15nTucSetIsItalicEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f4058 */ tst w3, #0xff;
    /* 0x2f405c */ cset w8, ne;
    /* 0x2f4060 */ strb w8, [x2, #0xb2];
    return x0;
}
