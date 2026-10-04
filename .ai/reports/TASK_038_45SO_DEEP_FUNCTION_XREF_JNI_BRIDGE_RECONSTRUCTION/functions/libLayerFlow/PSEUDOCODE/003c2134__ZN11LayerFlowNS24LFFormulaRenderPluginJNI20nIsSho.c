// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c2134
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI20nIsShouldSetSrcImageEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c2134 | Size: 28 bytes | SHA256: 27ec21e9ef88d6bb1a29c9f795578fc6e5ecf7c3c9ede586801f5783ab323cba
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nIsShouldSetSrcImage(J)Z (table at 0x5404c8)

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI20nIsShouldSetSrcImageEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x3c2134 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3c2138 */ mov x29, sp;
    /* 0x3c213c */ mov x0, x2;
    _ZNK11LayerFlowNS21LFFormulaRenderPlugin19isShouldSetSrcImageEv();
    /* 0x3c2144 */ and w0, w0, #1;
    /* 0x3c2148 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
