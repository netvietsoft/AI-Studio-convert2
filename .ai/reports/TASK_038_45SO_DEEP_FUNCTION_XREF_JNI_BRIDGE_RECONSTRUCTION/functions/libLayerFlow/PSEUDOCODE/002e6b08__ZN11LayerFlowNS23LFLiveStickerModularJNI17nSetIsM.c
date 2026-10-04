// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e6b08
// Recovered Name: _ZN11LayerFlowNS23LFLiveStickerModularJNI17nSetIsMaskCoveredEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e6b08 | Size: 20 bytes | SHA256: 686026d7d986ece4e14a44edbc15211d1794a0538acdb8ffe2cc90c41ae73120
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsMaskCovered(JZ)V (table at 0x538698)

jobject _ZN11LayerFlowNS23LFLiveStickerModularJNI17nSetIsMaskCoveredEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2e6b08 */ and w8, w3, #0xff;
    /* 0x2e6b0c */ cmp w8, #1;
    /* 0x2e6b10 */ cset w8, eq;
    /* 0x2e6b14 */ strb w8, [x2, #0x74];
    return x0;
}
