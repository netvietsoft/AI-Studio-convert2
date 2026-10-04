// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6d54
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI12nSetMaterialEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6d54 | Size: 28 bytes | SHA256: 3238eeeb8fd09d38ae1a51ae88df7798c7d24d0dcfc076007a984fef37fa0ab7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetMaterial(JJ)V (table at 0x535fc0)

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI12nSetMaterialEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2d6d54 */ cbz x3, #0x2d6d64;
    /* 0x2d6d58 */ ldr q0, [x3];
    /* 0x2d6d5c */ stur q0, [x2, #8];
    return x0;
    /* 0x2d6d64 */ strb wzr, [x2, #8];
    /* 0x2d6d68 */ str xzr, [x2, #0x10];
    return x0;
}
