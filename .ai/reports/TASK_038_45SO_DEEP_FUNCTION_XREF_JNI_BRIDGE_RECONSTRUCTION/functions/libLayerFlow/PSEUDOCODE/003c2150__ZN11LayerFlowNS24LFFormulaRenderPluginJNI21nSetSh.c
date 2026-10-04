// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c2150
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI21nSetShouldSetSrcImageEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c2150 | Size: 16 bytes | SHA256: 81c0cbb42b2a808ed3a5038ec9f917db88e66e5fda740a48331a94ed5d9148b0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetShouldSetSrcImage(JZ)V (table at 0x5404e0)

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI21nSetShouldSetSrcImageEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x3c2150 */ tst w3, #0xff;
    /* 0x3c2154 */ mov x0, x2;
    /* 0x3c2158 */ cset w1, ne;
    /* 0x3c215c */ b #0x45d588;
}
