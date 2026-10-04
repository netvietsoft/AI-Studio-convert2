// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df9a0
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI9nSetFixedEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df9a0 | Size: 16 bytes | SHA256: 8a7119d0ecb3b5873f9a12625a9531e2293121b9cc9d9c72cf02f43b2281a2bd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFixed(JZ)V (table at 0x537930)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI9nSetFixedEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2df9a0 */ tst w3, #0xff;
    /* 0x2df9a4 */ cset w8, ne;
    /* 0x2df9a8 */ strb w8, [x2, #0x1c];
    return x0;
}
