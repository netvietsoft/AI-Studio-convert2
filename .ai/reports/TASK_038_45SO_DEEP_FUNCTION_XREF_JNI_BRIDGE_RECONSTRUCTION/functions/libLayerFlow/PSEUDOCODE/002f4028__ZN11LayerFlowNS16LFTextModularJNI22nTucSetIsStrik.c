// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4028
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI22nTucSetIsStrikethroughEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4028 | Size: 16 bytes | SHA256: f6d71bdcd1fbb207cec7d1aa9df9e2dcd85cf145f1afbec95b7a9b862fd3d67d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nTucSetIsStrikethrough(JZ)V (table at 0x53b668)

jobject _ZN11LayerFlowNS16LFTextModularJNI22nTucSetIsStrikethroughEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f4028 */ tst w3, #0xff;
    /* 0x2f402c */ cset w8, ne;
    /* 0x2f4030 */ strb w8, [x2, #0xb0];
    return x0;
}
