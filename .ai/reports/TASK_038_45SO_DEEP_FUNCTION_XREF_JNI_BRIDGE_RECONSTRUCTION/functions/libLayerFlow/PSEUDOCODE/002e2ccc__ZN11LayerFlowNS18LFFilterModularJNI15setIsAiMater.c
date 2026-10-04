// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e2ccc
// Recovered Name: _ZN11LayerFlowNS18LFFilterModularJNI15setIsAiMaterialEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e2ccc | Size: 16 bytes | SHA256: 154a850fd8252d0b6b920142b21959a4a27bc50a0589eed83ff153b70f7a8d2c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: setIsAiMaterial(JZ)V (table at 0x537db0)

jobject _ZN11LayerFlowNS18LFFilterModularJNI15setIsAiMaterialEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e2ccc */ tst w3, #0xff;
    /* 0x2e2cd0 */ cset w8, ne;
    /* 0x2e2cd4 */ strb w8, [x2, #0x58];
    return x0;
}
