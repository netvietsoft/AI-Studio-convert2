// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f0c50
// Recovered Name: _ZN11LayerFlowNS19LFStickerModularJNI17nSetIsMaskCoveredEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f0c50 | Size: 20 bytes | SHA256: 44b70686c9692b518e112d37952b28bd6b74ad7da1fb540446a7a55b4f46a85f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsMaskCovered(JZ)V (table at 0x53a3f8)

jobject _ZN11LayerFlowNS19LFStickerModularJNI17nSetIsMaskCoveredEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2f0c50 */ and w8, w3, #0xff;
    /* 0x2f0c54 */ cmp w8, #1;
    /* 0x2f0c58 */ cset w8, eq;
    /* 0x2f0c5c */ strb w8, [x2, #0xd0];
    return x0;
}
