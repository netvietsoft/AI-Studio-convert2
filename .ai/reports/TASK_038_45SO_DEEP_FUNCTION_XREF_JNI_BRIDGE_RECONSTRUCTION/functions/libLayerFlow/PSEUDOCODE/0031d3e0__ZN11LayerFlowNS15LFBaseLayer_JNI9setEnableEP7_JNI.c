// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x31d3e0
// Recovered Name: _ZN11LayerFlowNS15LFBaseLayer_JNI9setEnableEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x31d3e0 | Size: 16 bytes | SHA256: 0ad6c9f3cf6ffa4b82008d5e27e7f9ba0274a62012e9c236ce4a244dd0e79e8d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEnable(JZ)V (table at 0x53c290)

jobject _ZN11LayerFlowNS15LFBaseLayer_JNI9setEnableEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x31d3e0 */ tst w3, #0xff;
    /* 0x31d3e4 */ mov x0, x2;
    /* 0x31d3e8 */ cset w1, ne;
    /* 0x31d3ec */ b #0x3aad2c;
}
