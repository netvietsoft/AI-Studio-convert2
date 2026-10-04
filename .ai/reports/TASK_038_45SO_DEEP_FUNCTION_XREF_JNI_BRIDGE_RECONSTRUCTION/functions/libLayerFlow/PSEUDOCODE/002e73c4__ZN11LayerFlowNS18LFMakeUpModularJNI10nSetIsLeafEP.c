// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e73c4
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI10nSetIsLeafEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e73c4 | Size: 16 bytes | SHA256: 294710fbd2af2c3e5cf93764669f4b4a781ecd55dc5a6598daac57e05bcbebab
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsLeaf(JZ)V (table at 0x538920)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI10nSetIsLeafEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e73c4 */ tst w3, #0xff;
    /* 0x2e73c8 */ cset w8, ne;
    /* 0x2e73cc */ strb w8, [x2, #0xd];
    return x0;
}
