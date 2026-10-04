// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dd9a4
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI10nSetLiftOnEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dd9a4 | Size: 16 bytes | SHA256: 36b7dcc3d90b2dcc8b703814f4878497d6564054bfefb1353217cb1b449c6b44
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetLiftOn(JZ)V (table at 0x5373f0)

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI10nSetLiftOnEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2dd9a4 */ tst w3, #0xff;
    /* 0x2dd9a8 */ cset w8, ne;
    /* 0x2dd9ac */ strb w8, [x2, #0x2c];
    return x0;
}
