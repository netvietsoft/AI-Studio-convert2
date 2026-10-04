// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d55a4
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI17nGetForeheadLevelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d55a4 | Size: 20 bytes | SHA256: 0c5c405d308f8636fb8cea5c3ea5773282fc7ffb4d2c4bdbb7ecf629c5d8d9c0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetForeheadLevel(J)D (table at 0x5358d0)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI17nGetForeheadLevelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d55a4 */ cbz x2, #0x2d55b0;
    /* 0x2d55a8 */ ldr d0, [x2];
    return x0;
    /* 0x2d55b0 */ movi d0, #0000000000000000;
    return x0;
}
