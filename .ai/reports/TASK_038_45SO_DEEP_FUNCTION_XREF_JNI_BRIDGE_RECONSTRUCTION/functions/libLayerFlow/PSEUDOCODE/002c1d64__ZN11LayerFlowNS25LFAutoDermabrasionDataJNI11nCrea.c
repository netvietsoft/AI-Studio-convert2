// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1d64
// Recovered Name: _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI11nCreateInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1d64 | Size: 36 bytes | SHA256: 929538d7700d98b4a6d835c9db271fe2e9955d64ea878b2cec5f06bd101fff7d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x531e50)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI11nCreateInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2c1d64 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2c1d68 */ mov x29, sp;
    /* 0x2c1d6c */ mov w0, #0xc;
    _Znwm();
    /* 0x2c1d74 */ mov w8, #1;
    /* 0x2c1d78 */ str xzr, [x0];
    /* 0x2c1d7c */ str w8, [x0, #8];
    /* 0x2c1d80 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
