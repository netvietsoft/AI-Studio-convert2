// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x302284
// Recovered Name: _ZN11LayerFlowNS16LFFormulaShopJNI16nSetIsMagicHouseEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x302284 | Size: 16 bytes | SHA256: 9c5ce3cb66d2aeb0cf3ff083f23badef4c64f9e0f199576d0f646174b89f6384
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsMagicHouse(JZ)V (table at 0x53bfa0)

jobject _ZN11LayerFlowNS16LFFormulaShopJNI16nSetIsMagicHouseEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x302284 */ tst w3, #0xff;
    /* 0x302288 */ mov x0, x2;
    /* 0x30228c */ cset w1, ne;
    /* 0x302290 */ b #0x442f98;
}
