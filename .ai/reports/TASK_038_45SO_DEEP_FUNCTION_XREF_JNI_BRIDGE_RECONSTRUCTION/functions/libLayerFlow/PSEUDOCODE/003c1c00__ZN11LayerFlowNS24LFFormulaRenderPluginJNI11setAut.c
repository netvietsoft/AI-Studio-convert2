// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c1c00
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI11setAutotestEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c1c00 | Size: 56 bytes | SHA256: 93b68f4b8766d08c18c07f65737f0054bd498765c4c20eb0ff648f1aef1b31f5
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetAutotest(JZ)V (table at 0x540438)
// Calls external APIs: _ZN12MTImageKitNS23CMTIKGlobalCommonConfig11setAutotestEb

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI11setAutotestEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x3c1c00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3c1c04 */ stp x20, x19, [sp, #0x10];
    /* 0x3c1c08 */ mov x29, sp;
    /* 0x3c1c0c */ and w8, w3, #0xff;
    /* 0x3c1c10 */ mov x19, x2;
    /* 0x3c1c14 */ cmp w8, #1;
    /* 0x3c1c18 */ cset w20, eq;
    /* 0x3c1c1c */ mov w0, w20;
    _ZN12MTImageKitNS23CMTIKGlobalCommonConfig11setAutotestEb();
    /* 0x3c1c24 */ mov x0, x19;
    /* 0x3c1c28 */ mov w1, w20;
}
