// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bdaa4
// Recovered Name: _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI12nGetEndColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bdaa4 | Size: 68 bytes | SHA256: e2605bffd30c18f0c4ae82032e333f154b53500c1cca7e60ef5c24d68183bec2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetEndColor(J)I (table at 0x53ff10)

jobject _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI12nGetEndColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x3bdaa4 */ ldp x8, x9, [x2, #0x18];
    /* 0x3bdaa8 */ sub x9, x9, x8;
    /* 0x3bdaac */ cmp x9, #0x10;
    /* 0x3bdab0 */ b.hs #0x3bdabc;
    /* 0x3bdab4 */ mov w0, wzr;
    return x0;
    /* 0x3bdabc */ ldp s0, s1, [x8];
    /* 0x3bdac0 */ fcvtzs w9, s0;
    /* 0x3bdac4 */ ldp s0, s2, [x8, #8];
    /* 0x3bdac8 */ fcvtzs w8, s1;
    /* 0x3bdacc */ fcvtzs w10, s2;
    return x0;
}
