// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee968
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI13nSetFleckFlawEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee968 | Size: 16 bytes | SHA256: f6d71bdcd1fbb207cec7d1aa9df9e2dcd85cf145f1afbec95b7a9b862fd3d67d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFleckFlaw(JZ)V (table at 0x539888)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI13nSetFleckFlawEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2ee968 */ tst w3, #0xff;
    /* 0x2ee96c */ cset w8, ne;
    /* 0x2ee970 */ strb w8, [x2, #0xb0];
    return x0;
}
