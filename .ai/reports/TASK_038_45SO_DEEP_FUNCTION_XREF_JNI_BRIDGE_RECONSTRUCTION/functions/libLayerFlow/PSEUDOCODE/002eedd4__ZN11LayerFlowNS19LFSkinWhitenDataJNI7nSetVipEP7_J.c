// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eedd4
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI7nSetVipEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eedd4 | Size: 16 bytes | SHA256: c66a8cd01d1c3bfe79bd0ce699468dd03b22a1f783a07e0c334b3a1b843a65a0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetVip(JZ)V (table at 0x539d68)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI7nSetVipEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2eedd4 */ tst w3, #0xff;
    /* 0x2eedd8 */ cset w8, ne;
    /* 0x2eeddc */ strb w8, [x2, #8];
    return x0;
}
