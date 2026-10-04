// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eebf0
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI17nSetBodyConcealerEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eebf0 | Size: 12 bytes | SHA256: 5ece030981c7560efad171b1a1583b5f0130b8ab4c3e4befaa046883efeff8ae
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBodyConcealer(JZ)V (table at 0x539bb8)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI17nSetBodyConcealerEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2eebf0 */ and w8, w3, #0xff;
    /* 0x2eebf4 */ str w8, [x2, #0x30];
    return x0;
}
