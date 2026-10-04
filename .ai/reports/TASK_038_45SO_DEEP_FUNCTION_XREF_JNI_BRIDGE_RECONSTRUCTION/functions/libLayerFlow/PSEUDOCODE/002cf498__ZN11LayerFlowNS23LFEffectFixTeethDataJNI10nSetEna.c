// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cf498
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI10nSetEnableEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cf498 | Size: 16 bytes | SHA256: 765430d314e383b51fa9b22a6276060c60ff7b70b8417b0b0a1843f3dd3a1199
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEnable(JZ)V (table at 0x5345e0)

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI10nSetEnableEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2cf498 */ tst w3, #0xff;
    /* 0x2cf49c */ cset w8, ne;
    /* 0x2cf4a0 */ strb w8, [x2];
    return x0;
}
