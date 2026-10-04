// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e7418
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI14nSetMouthColorEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e7418 | Size: 24 bytes | SHA256: 6965303d3140393007f38dded7a1b43abddd0749906e0a32c9dd6aa2a1b230b3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetMouthColor(JJ)V (table at 0x538980)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI14nSetMouthColorEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x2e7418 */ cbz x3, #0x2e7428;
    /* 0x2e741c */ ldr q0, [x3];
    /* 0x2e7420 */ stur q0, [x2, #0x10];
    return x0;
    /* 0x2e7428 */ stp xzr, xzr, [x2, #0x10];
    return x0;
}
