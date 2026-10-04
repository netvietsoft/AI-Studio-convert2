// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c22f8
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI10nSetOneKeyEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c22f8 | Size: 16 bytes | SHA256: 02b715282ed45d1806cf9c07ee7b18e1425719f79c737ce661f89de0deb74d30
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetOneKey(JZ)V (table at 0x532138)

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI10nSetOneKeyEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c22f8 */ tst w3, #0xff;
    /* 0x2c22fc */ cset w8, ne;
    /* 0x2c2300 */ strb w8, [x2, #0x14];
    return x0;
}
