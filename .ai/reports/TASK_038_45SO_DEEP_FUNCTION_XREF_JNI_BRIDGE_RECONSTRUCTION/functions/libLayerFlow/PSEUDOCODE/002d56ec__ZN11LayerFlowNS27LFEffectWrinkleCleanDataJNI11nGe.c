// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d56ec
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI11nGetOptTypeEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d56ec | Size: 20 bytes | SHA256: dc2a5aeb67482f129c304dc1c88cb1e3c175d1a9b758e52d43c4c70cfe55cc96
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetOptType(J)I (table at 0x535a20)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI11nGetOptTypeEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d56ec */ cbz x2, #0x2d56f8;
    /* 0x2d56f0 */ ldr w0, [x2];
    return x0;
    /* 0x2d56f8 */ mov w0, wzr;
    return x0;
}
