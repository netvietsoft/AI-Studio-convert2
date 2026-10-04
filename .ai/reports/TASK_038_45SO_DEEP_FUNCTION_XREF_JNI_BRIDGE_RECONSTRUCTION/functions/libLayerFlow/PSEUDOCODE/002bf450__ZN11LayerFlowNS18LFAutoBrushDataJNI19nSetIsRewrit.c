// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bf450
// Recovered Name: _ZN11LayerFlowNS18LFAutoBrushDataJNI19nSetIsRewriteEffectEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bf450 | Size: 16 bytes | SHA256: 8e2f3c58e1cea637aa223ea19229a2ac9592935a41f962dfb1d010b4fe2a3b47
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetIsRewriteEffect(JZ)V (table at 0x531ca0)

jobject _ZN11LayerFlowNS18LFAutoBrushDataJNI19nSetIsRewriteEffectEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2bf450 */ tst w3, #0xff;
    /* 0x2bf454 */ cset w8, ne;
    /* 0x2bf458 */ strb w8, [x2, #0x50];
    return x0;
}
