// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8cc8
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI13nSetLeftCheckEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8cc8 | Size: 16 bytes | SHA256: 34e97e4023669bb2b9033e7d058467093dfd98e419120647f31fc08bce2e472e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetLeftCheck(JZ)V (table at 0x533140)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI13nSetLeftCheckEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c8cc8 */ tst w3, #0xff;
    /* 0x2c8ccc */ cset w8, ne;
    /* 0x2c8cd0 */ strb w8, [x2, #1];
    return x0;
}
