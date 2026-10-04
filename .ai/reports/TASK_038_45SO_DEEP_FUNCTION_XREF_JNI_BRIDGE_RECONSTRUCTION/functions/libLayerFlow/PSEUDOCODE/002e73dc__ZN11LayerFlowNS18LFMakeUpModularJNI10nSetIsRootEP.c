// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e73dc
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI10nSetIsRootEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e73dc | Size: 16 bytes | SHA256: 59373b905b1f497a75cc86a6ffff092c3e881a87018e8d2cc976b6bc8db3ece0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsRoot(JZ)V (table at 0x538950)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI10nSetIsRootEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e73dc */ tst w3, #0xff;
    /* 0x2e73e0 */ cset w8, ne;
    /* 0x2e73e4 */ strb w8, [x2, #0xe];
    return x0;
}
