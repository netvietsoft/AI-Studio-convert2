// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d570c
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nGetFaceIdEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d570c | Size: 20 bytes | SHA256: 8d3ee84bcd16a9d6b52dfe928094f2ea06d38cf6e037ce2d663c38d0510d325d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFaceId(J)I (table at 0x535a50)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nGetFaceIdEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d570c */ cbz x2, #0x2d5718;
    /* 0x2d5710 */ ldr w0, [x2, #4];
    return x0;
    /* 0x2d5718 */ mov w0, wzr;
    return x0;
}
