// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2de698
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI11nGetModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2de698 | Size: 32 bytes | SHA256: 913f2ead3ebc34ef74b3567e2df252d97537c9b0e92319f991d3d735110ff833
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetModular(J)Ljava/lang/String; (table at 0x537660)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI11nGetModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2de698 */ ldrb w8, [x2, #0x10];
    /* 0x2de69c */ ldr x10, [x0];
    /* 0x2de6a0 */ add x11, x2, #0x11;
    /* 0x2de6a4 */ ldr x9, [x2, #0x20];
    /* 0x2de6a8 */ tst w8, #1;
    /* 0x2de6ac */ ldr x2, [x10, #0x538];
    /* 0x2de6b0 */ csel x1, x11, x9, eq;
    /* 0x2de6b4 */ br x2;
}
