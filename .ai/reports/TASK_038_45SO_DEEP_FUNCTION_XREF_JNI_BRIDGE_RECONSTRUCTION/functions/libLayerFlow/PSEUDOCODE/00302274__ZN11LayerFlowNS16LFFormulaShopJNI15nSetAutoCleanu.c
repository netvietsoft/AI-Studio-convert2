// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x302274
// Recovered Name: _ZN11LayerFlowNS16LFFormulaShopJNI15nSetAutoCleanupEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x302274 | Size: 16 bytes | SHA256: d27c02d825709a00778760d2c0078d7a01f9674bb62573f34a779182d892ca05
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetAutoCleanup(JZ)V (table at 0x53bf88)

jobject _ZN11LayerFlowNS16LFFormulaShopJNI15nSetAutoCleanupEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x302274 */ tst w3, #0xff;
    /* 0x302278 */ mov x0, x2;
    /* 0x30227c */ cset w1, ne;
    /* 0x302280 */ b #0x442d18;
}
