// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e632c
// Recovered Name: _ZN11LayerFlowNS18LFImageWithPathJNI7nCreateEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e632c | Size: 80 bytes | SHA256: 47cbc35cc969b1d8814328c5bac654cea79e02d6b7465527725340da1a08954e
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x538308)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "LFImageWithPathJNI::nCreate addr => %p"
//   "iklf_"

jobject _ZN11LayerFlowNS18LFImageWithPathJNI7nCreateEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x2e632c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e6330 */ str x19, [sp, #0x10];
    /* 0x2e6334 */ mov x29, sp;
    /* 0x2e6338 */ mov w0, #0x28;
    _Znwm();
    /* 0x2e6340 */ movi v0.2d, #0000000000000000;
    /* 0x2e6344 */ mov x19, x0;
    /* 0x2e6348 */ str xzr, [x0, #0x20];
    /* 0x2e634c */ adrp x1, #0x1e1000;
    /* 0x2e6350 */ add x1, x1, #0x361;
    /* 0x2e6354 */ adrp x2, #0x1d8000;
    __android_log_print();
    return x0;
}
