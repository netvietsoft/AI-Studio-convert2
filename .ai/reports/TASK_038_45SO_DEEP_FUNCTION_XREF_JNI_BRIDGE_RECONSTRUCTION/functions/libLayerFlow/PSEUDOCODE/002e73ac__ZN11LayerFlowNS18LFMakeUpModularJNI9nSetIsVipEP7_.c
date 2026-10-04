// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e73ac
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI9nSetIsVipEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e73ac | Size: 16 bytes | SHA256: 5e082d0d13090349712fe51f5ef9e764ad62c37606e273eacda2e3f312f9ee19
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsVip(JZ)V (table at 0x5388f0)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI9nSetIsVipEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e73ac */ tst w3, #0xff;
    /* 0x2e73b0 */ cset w8, ne;
    /* 0x2e73b4 */ strb w8, [x2, #0xc];
    return x0;
}
