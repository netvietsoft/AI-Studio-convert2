// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e745c
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI14nSetBlushColorEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e745c | Size: 24 bytes | SHA256: 2ba23e065803d6d1f6266779436f87c9086d9d0e898f4b6b8f252d806adecd40
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBlushColor(JJ)V (table at 0x5389b0)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI14nSetBlushColorEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x2e745c */ cbz x3, #0x2e746c;
    /* 0x2e7460 */ ldr q0, [x3];
    /* 0x2e7464 */ stur q0, [x2, #0x20];
    return x0;
    /* 0x2e746c */ stp xzr, xzr, [x2, #0x20];
    return x0;
}
