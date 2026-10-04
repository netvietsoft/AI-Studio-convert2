// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d0644
// Recovered Name: _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI11nGetModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d0644 | Size: 32 bytes | SHA256: 6f2ca251fbc5554cd1d41f8ee065c9b11353aa4a7d342bc627814e3b3acb3f40
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetModular(J)Ljava/lang/String; (table at 0x5347c0)

jobject _ZN11LayerFlowNS24LFEffectHeadScaleDataJNI11nGetModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d0644 */ ldrb w8, [x2, #8];
    /* 0x2d0648 */ ldr x10, [x0];
    /* 0x2d064c */ add x11, x2, #9;
    /* 0x2d0650 */ ldr x9, [x2, #0x18];
    /* 0x2d0654 */ tst w8, #1;
    /* 0x2d0658 */ ldr x2, [x10, #0x538];
    /* 0x2d065c */ csel x1, x11, x9, eq;
    /* 0x2d0660 */ br x2;
}
