// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c2174
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI35nShouldUseBodyInOneExpForBodyHeightEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c2174 | Size: 28 bytes | SHA256: b199d468a8e4c76d472c74e9b7f0f98bf468d7b911038faae6274bcd10add5e6
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nShouldUseBodyInOneExpForBodyHeight(J)Z (table at 0x540510)

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI35nShouldUseBodyInOneExpForBodyHeightEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x3c2174 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3c2178 */ mov x29, sp;
    /* 0x3c217c */ mov x0, x2;
    _ZNK11LayerFlowNS21LFFormulaRenderPlugin34shouldUseBodyInOneExpForBodyHeightEv();
    /* 0x3c2184 */ and w0, w0, #1;
    /* 0x3c2188 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
