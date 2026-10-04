// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1bc8
// Recovered Name: _ZN11LayerFlowNS25LFAutoColorCorrectDataJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1bc8 | Size: 32 bytes | SHA256: 8f358eab7eeb7d8ff2c91fceca2cdfb7e0d04ff8b4f58009375deb2eb7afb17f
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x531d48)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS25LFAutoColorCorrectDataJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2c1bc8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2c1bcc */ mov x29, sp;
    /* 0x2c1bd0 */ mov w0, #0x20;
    _Znwm();
    /* 0x2c1bd8 */ movi v0.2d, #0000000000000000;
    /* 0x2c1bdc */ stp q0, q0, [x0];
    /* 0x2c1be0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
