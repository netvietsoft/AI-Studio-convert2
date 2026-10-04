// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8fc0
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI15nSetOpenEyeModeEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2b8fc0 | Size: 12 bytes | SHA256: 43f3e1a4a55b2acdfd448f23d5dfc3adc379d1c6e548e1c930cfdb14a3b99893
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetOpenEyeMode(JI)V (table at 0x531120)

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI15nSetOpenEyeModeEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2b8fc0 */ cbz x2, #0x2b8fc8;
    /* 0x2b8fc4 */ str w3, [x2];
    return x0;
}
