// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ddf5c
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI19nCreateFaceFullInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ddf5c | Size: 100 bytes | SHA256: 8cd7c6c39b730f045d81b7c70624067cf2c2e731efa63cd1ae02b8c39fda0d1d
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x5371c8)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "nCreateFaceFullInfo is called, addr => %p"

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI19nCreateFaceFullInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x2ddf5c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ddf60 */ str x19, [sp, #0x10];
    /* 0x2ddf64 */ mov x29, sp;
    /* 0x2ddf68 */ mov w0, #0x50;
    _Znwm();
    /* 0x2ddf70 */ movi v0.2d, #0000000000000000;
    /* 0x2ddf74 */ movi v1.2d, #0xffffffffffffffff;
    /* 0x2ddf78 */ mov x19, x0;
    /* 0x2ddf7c */ mov w8, #-1;
    /* 0x2ddf80 */ str wzr, [x0, #0x40];
    /* 0x2ddf84 */ nop ;
    __android_log_print();
    return x0;
}
