// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5638
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nSetLipLevelEP7_JNIEnvP7_jclassld
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5638 | Size: 12 bytes | SHA256: 0883907a016c8d4b655d23685dc5f0c3ae0884dc18e29fb7cb0980a2c6fd8d9d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetLipLevel(JD)V (table at 0x5359a8)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nSetLipLevelEP7_JNIEnvP7_jclassld(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d5638 */ cbz x2, #0x2d5640;
    /* 0x2d563c */ str d0, [x2, #0x20];
    return x0;
}
