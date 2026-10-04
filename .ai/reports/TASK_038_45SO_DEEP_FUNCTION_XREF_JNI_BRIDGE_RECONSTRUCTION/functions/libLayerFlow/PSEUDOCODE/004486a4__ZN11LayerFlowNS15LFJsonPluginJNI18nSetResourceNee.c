// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x4486a4
// Recovered Name: _ZN11LayerFlowNS15LFJsonPluginJNI18nSetResourceNeededEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x4486a4 | Size: 20 bytes | SHA256: 4e0fc5cc8c5eb836c8e0fa67e1d40872cf4b69f2c93694e5237ba194eeda7333
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetResourceNeeded(JZ)V (table at 0x546220)

jobject _ZN11LayerFlowNS15LFJsonPluginJNI18nSetResourceNeededEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x4486a4 */ and w8, w3, #0xff;
    /* 0x4486a8 */ mov x0, x2;
    /* 0x4486ac */ cmp w8, #1;
    /* 0x4486b0 */ cset w1, eq;
    /* 0x4486b4 */ b #0x460274;
}
