// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f27fc
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI19nSetIsStrikethroughEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f27fc | Size: 16 bytes | SHA256: 6eba8d86b65a8e3834fbbaff602454565d7dfdbd880f532fefcc029652751d90
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsStrikethrough(JZ)V (table at 0x53a840)

jobject _ZN11LayerFlowNS16LFTextModularJNI19nSetIsStrikethroughEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f27fc */ tst w3, #0xff;
    /* 0x2f2800 */ cset w8, ne;
    /* 0x2f2804 */ strb w8, [x2, #0x18];
    return x0;
}
