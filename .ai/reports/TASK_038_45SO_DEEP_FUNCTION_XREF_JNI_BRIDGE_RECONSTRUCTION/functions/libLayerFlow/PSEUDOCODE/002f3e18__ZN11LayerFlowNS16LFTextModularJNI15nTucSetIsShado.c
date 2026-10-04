// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f3e18
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI15nTucSetIsShadowEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f3e18 | Size: 16 bytes | SHA256: 4eb60874f1d7aa92617b950205b2aaed9fb8293cc2628b5365ac5534d2bb6c89
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsShadow(JZ)V (table at 0x53b548)

jobject _ZN11LayerFlowNS16LFTextModularJNI15nTucSetIsShadowEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f3e18 */ tst w3, #0xff;
    /* 0x2f3e1c */ cset w8, ne;
    /* 0x2f3e20 */ strb w8, [x2, #0x80];
    return x0;
}
