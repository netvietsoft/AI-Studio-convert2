// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3780
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI17nSetIsMaskCoveredEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3780 | Size: 20 bytes | SHA256: 2c8dfa68eef45a6a66bada826cec150a05a4c66469d8cd9c826b6c94b867f0a4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsMaskCovered(JZ)V (table at 0x53b218)

jobject _ZN11LayerFlowNS16LFTextModularJNI17nSetIsMaskCoveredEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2f3780 */ and w8, w3, #0xff;
    /* 0x2f3784 */ cmp w8, #1;
    /* 0x2f3788 */ cset w8, eq;
    /* 0x2f378c */ strb w8, [x2, #0xc8];
    return x0;
}
