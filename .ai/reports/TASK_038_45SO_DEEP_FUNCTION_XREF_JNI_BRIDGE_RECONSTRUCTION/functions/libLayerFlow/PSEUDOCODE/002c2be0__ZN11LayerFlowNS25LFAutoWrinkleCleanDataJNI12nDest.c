// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2be0
// Recovered Name: _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2be0 | Size: 16 bytes | SHA256: 58e8b2f461511665d825b037bd1776073847aad78d6efc16e1748a9df8bdf470
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x532258)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c2be0 */ cbz x2, #0x2c2bec;
    /* 0x2c2be4 */ mov x0, x2;
    /* 0x2c2be8 */ b #0x52a280;
    return x0;
}
