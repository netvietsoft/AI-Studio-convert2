// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5720
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nSetFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5720 | Size: 12 bytes | SHA256: 6bcae25d3b899f03c36066bcd207dea764e54ce68e3073f5d573f8e31907c98d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFaceId(JI)V (table at 0x535a68)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nSetFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d5720 */ cbz x2, #0x2d5728;
    /* 0x2d5724 */ str w3, [x2, #4];
    return x0;
}
