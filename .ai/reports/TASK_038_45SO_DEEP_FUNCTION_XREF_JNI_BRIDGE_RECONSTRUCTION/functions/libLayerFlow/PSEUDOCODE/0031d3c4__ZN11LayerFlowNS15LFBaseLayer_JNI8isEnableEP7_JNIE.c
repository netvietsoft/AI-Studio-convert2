// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x31d3c4
// Recovered Name: _ZN11LayerFlowNS15LFBaseLayer_JNI8isEnableEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x31d3c4 | Size: 28 bytes | SHA256: 502fd14a78e8a2137a50eeb8cd0d872dd9b982b7f2b768537fde805b0929d3c9
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nIsEnable(J)Z (table at 0x53c278)

jobject _ZN11LayerFlowNS15LFBaseLayer_JNI8isEnableEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x31d3c4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x31d3c8 */ mov x29, sp;
    /* 0x31d3cc */ mov x0, x2;
    _ZN11LayerFlowNS11LFBaseLayer8isEnableEv();
    /* 0x31d3d4 */ and w0, w0, #1;
    /* 0x31d3d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
