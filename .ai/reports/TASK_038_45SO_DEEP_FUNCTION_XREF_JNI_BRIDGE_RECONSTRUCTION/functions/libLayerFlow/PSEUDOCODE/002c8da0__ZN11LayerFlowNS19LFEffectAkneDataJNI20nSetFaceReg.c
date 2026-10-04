// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8da0
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI20nSetFaceRegionSwitchEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8da0 | Size: 20 bytes | SHA256: f15ec33dd10eab77bf225f075fcad96abd8fd954492ef9d8eeb85d69bcf89407
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFaceRegionSwitch(JJ)V (table at 0x533218)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI20nSetFaceRegionSwitchEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2c8da0 */ ldrb w8, [x3, #4];
    /* 0x2c8da4 */ ldr w9, [x3];
    /* 0x2c8da8 */ strb w8, [x2, #4];
    /* 0x2c8dac */ str w9, [x2];
    return x0;
}
