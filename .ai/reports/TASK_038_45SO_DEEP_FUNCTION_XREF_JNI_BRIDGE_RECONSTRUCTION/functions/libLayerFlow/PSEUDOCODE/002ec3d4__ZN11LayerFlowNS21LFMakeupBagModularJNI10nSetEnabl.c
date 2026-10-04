// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ec3d4
// Recovered Name: _ZN11LayerFlowNS21LFMakeupBagModularJNI10nSetEnableEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ec3d4 | Size: 20 bytes | SHA256: dcd2d2a78ecda4b816c5a99c8dd5a91a372b234ccaf326a702d295ea8a3c2b2b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEnable(JZ)V (table at 0x538ee0)

jobject _ZN11LayerFlowNS21LFMakeupBagModularJNI10nSetEnableEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2ec3d4 */ and w8, w3, #0xff;
    /* 0x2ec3d8 */ cmp w8, #1;
    /* 0x2ec3dc */ cset w8, eq;
    /* 0x2ec3e0 */ strb w8, [x2];
    return x0;
}
