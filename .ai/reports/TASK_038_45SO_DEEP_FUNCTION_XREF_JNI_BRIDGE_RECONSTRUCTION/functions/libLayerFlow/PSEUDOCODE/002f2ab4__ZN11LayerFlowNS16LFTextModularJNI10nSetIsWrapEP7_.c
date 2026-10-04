// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2ab4
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI10nSetIsWrapEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2ab4 | Size: 16 bytes | SHA256: 134cad51dfd73af77743eb9c87fd1397cfc101ccb79ef0afdabfe00175c64813
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsWrap(JZ)V (table at 0x53ab70)

jobject _ZN11LayerFlowNS16LFTextModularJNI10nSetIsWrapEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2ab4 */ tst w3, #0xff;
    /* 0x2f2ab8 */ cset w8, ne;
    /* 0x2f2abc */ strb w8, [x2, #0xa5];
    return x0;
}
