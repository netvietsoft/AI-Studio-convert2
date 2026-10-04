// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e7554
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI16nSetEyeBrowColorEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e7554 | Size: 24 bytes | SHA256: 3b13c396586ab98d999b6cb6b864ca5ac42d786f5f2a5ba9569dc1804d8cbb80
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEyeBrowColor(JJ)V (table at 0x538a40)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI16nSetEyeBrowColorEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x2e7554 */ cbz x3, #0x2e7564;
    /* 0x2e7558 */ ldr q0, [x3];
    /* 0x2e755c */ str q0, [x2];
    return x0;
    /* 0x2e7564 */ stp xzr, xzr, [x2];
    return x0;
}
