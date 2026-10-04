// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d55e4
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nGetEyeLevelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d55e4 | Size: 20 bytes | SHA256: 6739d6d68af4579db3cc028b8d6c5d15020ab1897b6d08df2b0b16fb229d9eef
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetEyeLevel(J)D (table at 0x535930)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nGetEyeLevelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d55e4 */ cbz x2, #0x2d55f0;
    /* 0x2d55e8 */ ldr d0, [x2, #0x10];
    return x0;
    /* 0x2d55f0 */ movi d0, #0000000000000000;
    return x0;
}
