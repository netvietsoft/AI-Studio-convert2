// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cb4b8
// Recovered Name: _ZN11LayerFlowNS24LFEffectDenseHairDataJNI14nSetHighLightsEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cb4b8 | Size: 16 bytes | SHA256: 765430d314e383b51fa9b22a6276060c60ff7b70b8417b0b0a1843f3dd3a1199
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetHighLights(JZ)V (table at 0x5338d0)

jobject _ZN11LayerFlowNS24LFEffectDenseHairDataJNI14nSetHighLightsEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2cb4b8 */ tst w3, #0xff;
    /* 0x2cb4bc */ cset w8, ne;
    /* 0x2cb4c0 */ strb w8, [x2];
    return x0;
}
