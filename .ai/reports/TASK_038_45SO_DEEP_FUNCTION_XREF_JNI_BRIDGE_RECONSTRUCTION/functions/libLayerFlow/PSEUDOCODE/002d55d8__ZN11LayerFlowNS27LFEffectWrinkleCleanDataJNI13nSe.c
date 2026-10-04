// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d55d8
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nSetNeckLevelEP7_JNIEnvP7_jclassld
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d55d8 | Size: 12 bytes | SHA256: 0529001584c0b6c09d792cd9e6cf111bfd4d1071ff992a868f91249d868bbd1d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetNeckLevel(JD)V (table at 0x535918)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nSetNeckLevelEP7_JNIEnvP7_jclassld(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d55d8 */ cbz x2, #0x2d55e0;
    /* 0x2d55dc */ str d0, [x2, #8];
    return x0;
}
