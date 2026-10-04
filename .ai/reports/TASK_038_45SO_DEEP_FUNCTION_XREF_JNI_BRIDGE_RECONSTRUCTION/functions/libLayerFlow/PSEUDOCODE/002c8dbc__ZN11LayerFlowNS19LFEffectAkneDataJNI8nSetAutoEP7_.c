// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8dbc
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI8nSetAutoEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8dbc | Size: 16 bytes | SHA256: d485a247d3154e18c1529d7d99df00de8bd0bedfac701924cd31001f83332d6e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetAuto(JZ)V (table at 0x533248)

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI8nSetAutoEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c8dbc */ tst w3, #0xff;
    /* 0x2c8dc0 */ cset w8, ne;
    /* 0x2c8dc4 */ strb w8, [x2, #5];
    return x0;
}
