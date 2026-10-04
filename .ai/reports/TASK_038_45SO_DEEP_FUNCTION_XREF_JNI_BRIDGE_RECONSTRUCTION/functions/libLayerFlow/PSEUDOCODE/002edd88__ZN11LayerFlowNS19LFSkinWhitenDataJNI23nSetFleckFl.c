// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2edd88
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nSetFleckFlowForceLocalEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2edd88 | Size: 24 bytes | SHA256: 55e5c79fb526b359ea1f1e4b5b54948cb048d51e86161d87541330caa6af642f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFleckFlowForceLocal(JZ)V (table at 0x539558)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI23nSetFleckFlowForceLocalEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x2edd88 */ cbz x2, #0x2edd9c;
    /* 0x2edd8c */ and w8, w3, #0xff;
    /* 0x2edd90 */ cmp w8, #1;
    /* 0x2edd94 */ cset w8, eq;
    /* 0x2edd98 */ strb w8, [x2];
    return x0;
}
