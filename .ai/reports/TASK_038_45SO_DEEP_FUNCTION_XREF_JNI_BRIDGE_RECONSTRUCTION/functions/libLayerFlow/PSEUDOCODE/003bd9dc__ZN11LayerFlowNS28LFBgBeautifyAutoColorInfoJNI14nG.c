// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bd9dc
// Recovered Name: _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI14nGetStartColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bd9dc | Size: 68 bytes | SHA256: e61ce267aded0bb33d05379a32447012544fd46ffc442ea701aa4312935837d5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetStartColor(J)I (table at 0x53fee0)

jobject _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI14nGetStartColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x3bd9dc */ ldp x8, x9, [x2];
    /* 0x3bd9e0 */ sub x9, x9, x8;
    /* 0x3bd9e4 */ cmp x9, #0x10;
    /* 0x3bd9e8 */ b.hs #0x3bd9f4;
    /* 0x3bd9ec */ mov w0, wzr;
    return x0;
    /* 0x3bd9f4 */ ldp s0, s1, [x8];
    /* 0x3bd9f8 */ fcvtzs w9, s0;
    /* 0x3bd9fc */ ldp s0, s2, [x8, #8];
    /* 0x3bda00 */ fcvtzs w8, s1;
    /* 0x3bda04 */ fcvtzs w10, s2;
    return x0;
}
