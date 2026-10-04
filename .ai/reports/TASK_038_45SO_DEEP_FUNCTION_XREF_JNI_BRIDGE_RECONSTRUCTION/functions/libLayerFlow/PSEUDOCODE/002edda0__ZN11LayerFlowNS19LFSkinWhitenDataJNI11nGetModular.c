// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2edda0
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI11nGetModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2edda0 | Size: 32 bytes | SHA256: 913f2ead3ebc34ef74b3567e2df252d97537c9b0e92319f991d3d735110ff833
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetModular(J)Ljava/lang/String; (table at 0x539588)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI11nGetModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2edda0 */ ldrb w8, [x2, #0x10];
    /* 0x2edda4 */ ldr x10, [x0];
    /* 0x2edda8 */ add x11, x2, #0x11;
    /* 0x2eddac */ ldr x9, [x2, #0x20];
    /* 0x2eddb0 */ tst w8, #1;
    /* 0x2eddb4 */ ldr x2, [x10, #0x538];
    /* 0x2eddb8 */ csel x1, x11, x9, eq;
    /* 0x2eddbc */ br x2;
}
