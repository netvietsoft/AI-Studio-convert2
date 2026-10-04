// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df890
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI20nSetEnableBackgroundEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df890 | Size: 20 bytes | SHA256: 9edb16aefad8f9c14c86ae209d2beebb988f461a497bdd997a03c07402235b0c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEnableBackground(JZ)V (table at 0x537828)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI20nSetEnableBackgroundEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2df890 */ and w8, w3, #0xff;
    /* 0x2df894 */ cmp w8, #1;
    /* 0x2df898 */ cset w8, eq;
    /* 0x2df89c */ strb w8, [x2, #0x58];
    return x0;
}
