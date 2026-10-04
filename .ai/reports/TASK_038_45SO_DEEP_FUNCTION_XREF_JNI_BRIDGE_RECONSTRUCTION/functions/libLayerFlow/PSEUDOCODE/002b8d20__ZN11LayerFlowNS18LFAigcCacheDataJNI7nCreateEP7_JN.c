// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8d20
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI7nCreateEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2b8d20 | Size: 148 bytes | SHA256: c51f365a1635c48ad6ead22f3b1ceb36b8f82d78673842ba3845b7edba1e138b
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x5310d8)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "LFAigcCacheDataJNI::nCreate addr => %p"

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI7nCreateEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x2b8d20 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2b8d24 */ str x19, [sp, #0x10];
    /* 0x2b8d28 */ mov x29, sp;
    /* 0x2b8d2c */ mov w0, #0xc0;
    _Znwm();
    /* 0x2b8d34 */ mov w8, #-1;
    /* 0x2b8d38 */ str xzr, [x0];
    /* 0x2b8d3c */ movi v0.2d, #0000000000000000;
    /* 0x2b8d40 */ str w8, [x0];
    /* 0x2b8d44 */ mov x8, x0;
    /* 0x2b8d48 */ mov x19, x0;
    __android_log_print();
    return x0;
}
