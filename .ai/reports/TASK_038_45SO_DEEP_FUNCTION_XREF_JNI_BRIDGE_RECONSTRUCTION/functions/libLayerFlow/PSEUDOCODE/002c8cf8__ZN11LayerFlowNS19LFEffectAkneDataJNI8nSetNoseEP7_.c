// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8cf8
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI8nSetNoseEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8cf8 | Size: 16 bytes | SHA256: 896c1ecde604ec1823aba66117af69a3dc7ad020bbc9145a3c8c00abb26f3a17
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetNose(JZ)V (table at 0x5331a0)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI8nSetNoseEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c8cf8 */ tst w3, #0xff;
    /* 0x2c8cfc */ cset w8, ne;
    /* 0x2c8d00 */ strb w8, [x2, #3];
    return x0;
}
