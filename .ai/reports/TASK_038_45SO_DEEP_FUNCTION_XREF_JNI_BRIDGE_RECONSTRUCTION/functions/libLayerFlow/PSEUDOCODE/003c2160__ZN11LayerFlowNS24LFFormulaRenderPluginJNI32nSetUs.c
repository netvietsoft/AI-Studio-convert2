// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c2160
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI32nSetUseBodyInOneExpForBodyHeightEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c2160 | Size: 20 bytes | SHA256: de11ba0911884c8a2b8821005578453856a6e8de84e8bf93a5c31d1443a390c2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetUseBodyInOneExpForBodyHeight(JZ)V (table at 0x5404f8)

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI32nSetUseBodyInOneExpForBodyHeightEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x3c2160 */ and w8, w3, #0xff;
    /* 0x3c2164 */ mov x0, x2;
    /* 0x3c2168 */ cmp w8, #1;
    /* 0x3c216c */ cset w1, eq;
    /* 0x3c2170 */ b #0x45d71c;
}
