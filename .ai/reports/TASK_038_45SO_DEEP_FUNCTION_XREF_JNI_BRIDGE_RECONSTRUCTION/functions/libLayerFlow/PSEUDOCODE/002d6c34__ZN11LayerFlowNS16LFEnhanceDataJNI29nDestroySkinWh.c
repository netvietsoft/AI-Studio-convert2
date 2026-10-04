// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6c34
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI29nDestroySkinWhiteningMaterialEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6c34 | Size: 16 bytes | SHA256: a79b7e411c106c060fcc1b873464da94c770dc62ae2e1510e11f408531fc3fbf
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x535ed0)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI29nDestroySkinWhiteningMaterialEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d6c34 */ cbz x2, #0x2d6c40;
    /* 0x2d6c38 */ mov x0, x2;
    /* 0x2d6c3c */ b #0x52a280;
    return x0;
}
