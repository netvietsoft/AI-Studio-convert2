// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee524
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetAutoCustomColorEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee524 | Size: 32 bytes | SHA256: c21cecae527726e8c7fb6e7457bc1749a7b5f42d51abf091e8ad72f8ffb543a4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetAutoCustomColor(J)Ljava/lang/String; (table at 0x5397e0)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetAutoCustomColorEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2ee524 */ ldrb w8, [x2, #0x80];
    /* 0x2ee528 */ ldr x10, [x0];
    /* 0x2ee52c */ add x11, x2, #0x81;
    /* 0x2ee530 */ ldr x9, [x2, #0x90];
    /* 0x2ee534 */ tst w8, #1;
    /* 0x2ee538 */ ldr x2, [x10, #0x538];
    /* 0x2ee53c */ csel x1, x11, x9, eq;
    /* 0x2ee540 */ br x2;
}
