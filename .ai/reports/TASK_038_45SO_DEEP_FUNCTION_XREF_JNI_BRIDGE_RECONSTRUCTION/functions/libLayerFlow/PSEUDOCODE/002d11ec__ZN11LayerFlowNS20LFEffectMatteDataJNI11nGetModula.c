// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d11ec
// Recovered Name: _ZN11LayerFlowNS20LFEffectMatteDataJNI11nGetModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d11ec | Size: 32 bytes | SHA256: 6f2ca251fbc5554cd1d41f8ee065c9b11353aa4a7d342bc627814e3b3acb3f40
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetModular(J)Ljava/lang/String; (table at 0x534910)

jobject _ZN11LayerFlowNS20LFEffectMatteDataJNI11nGetModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d11ec */ ldrb w8, [x2, #8];
    /* 0x2d11f0 */ ldr x10, [x0];
    /* 0x2d11f4 */ add x11, x2, #9;
    /* 0x2d11f8 */ ldr x9, [x2, #0x18];
    /* 0x2d11fc */ tst w8, #1;
    /* 0x2d1200 */ ldr x2, [x10, #0x538];
    /* 0x2d1204 */ csel x1, x11, x9, eq;
    /* 0x2d1208 */ br x2;
}
