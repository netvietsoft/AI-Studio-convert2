// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8ce0
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI12nSetForeheadEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8ce0 | Size: 16 bytes | SHA256: 24e16b44610b1ec1b43ca093a4d2badd51e1610f795e31c8f008a5fcd22368ce
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetForehead(JZ)V (table at 0x533170)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI12nSetForeheadEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c8ce0 */ tst w3, #0xff;
    /* 0x2c8ce4 */ cset w8, ne;
    /* 0x2c8ce8 */ strb w8, [x2, #2];
    return x0;
}
