// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ed2a0
// Recovered Name: _ZN11LayerFlowNS13LFMaterialJNI9setIsAigcEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ed2a0 | Size: 20 bytes | SHA256: 6b77cc85d79064c4633db79fc658dd5743d5e559de5e49aca2ddf012322899ae
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: setIsAigc(JZ)V (table at 0x539498)

jobject _ZN11LayerFlowNS13LFMaterialJNI9setIsAigcEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2ed2a0 */ and w8, w3, #0xff;
    /* 0x2ed2a4 */ cmp w8, #1;
    /* 0x2ed2a8 */ cset w8, eq;
    /* 0x2ed2ac */ strb w8, [x2, #0x20];
    return x0;
}
