// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f37b0
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI10nTucCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f37b0 | Size: 64 bytes | SHA256: 77bbf4abaebd6e68acbce97b3a381b2a80e008044e95abb38ae8eb82af2ff040
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nTucCreate()J (table at 0x53b260)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFTextModularJNI10nTucCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x2f37b0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2f37b4 */ mov x29, sp;
    /* 0x2f37b8 */ mov w0, #0xf8;
    _Znwm();
    /* 0x2f37c0 */ movi v0.2d, #0000000000000000;
    /* 0x2f37c4 */ stp q0, q0, [x0];
    /* 0x2f37c8 */ stp q0, q0, [x0, #0x20];
    /* 0x2f37cc */ stp q0, q0, [x0, #0x40];
    /* 0x2f37d0 */ stp q0, q0, [x0, #0x60];
    /* 0x2f37d4 */ stp q0, q0, [x0, #0x80];
    /* 0x2f37d8 */ stp q0, q0, [x0, #0xa0];
    return x0;
}
