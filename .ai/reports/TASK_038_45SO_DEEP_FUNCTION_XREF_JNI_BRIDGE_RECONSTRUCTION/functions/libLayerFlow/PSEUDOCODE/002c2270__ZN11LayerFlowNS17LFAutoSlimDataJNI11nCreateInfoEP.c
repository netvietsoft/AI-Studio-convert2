// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2270
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI11nCreateInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2270 | Size: 32 bytes | SHA256: 02c44af95d532b0b9e1994a1631fdd01c4079c8e9e122323588e41ba6da756c9
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x532000)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI11nCreateInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2c2270 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2c2274 */ mov x29, sp;
    /* 0x2c2278 */ mov w0, #0x18;
    _Znwm();
    /* 0x2c2280 */ stp xzr, xzr, [x0, #8];
    /* 0x2c2284 */ str xzr, [x0];
    /* 0x2c2288 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
