// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2290
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2290 | Size: 16 bytes | SHA256: 0f440c94363d49f5b54342bf0b3f26b8183e8340c8b041b9fe74defa7085261d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x532018)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c2290 */ cbz x2, #0x2c229c;
    /* 0x2c2294 */ mov x0, x2;
    /* 0x2c2298 */ b #0x52a280;
    return x0;
}
