// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2bc0
// Recovered Name: _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI11nCreateInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2bc0 | Size: 32 bytes | SHA256: b7ee303adcd837bbd1272d06f36e6f7d903365199c334ee4dfb82a290972b828
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x532240)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI11nCreateInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2c2bc0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2c2bc4 */ mov x29, sp;
    /* 0x2c2bc8 */ mov w0, #0x18;
    _Znwm();
    /* 0x2c2bd0 */ stp xzr, xzr, [x0, #8];
    /* 0x2c2bd4 */ str xzr, [x0];
    /* 0x2c2bd8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
