// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bdc70
// Recovered Name: _ZN11LayerFlowNS21LFBlurResourceDataJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bdc70 | Size: 44 bytes | SHA256: 04fc363152f1bcac0395dc58d30ec946709a5f69be4c92b82372b9601552230b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53ff40)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS21LFBlurResourceDataJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x3bdc70 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3bdc74 */ mov x29, sp;
    /* 0x3bdc78 */ mov w0, #0x58;
    _Znwm();
    /* 0x3bdc80 */ movi v0.2d, #0000000000000000;
    /* 0x3bdc84 */ stp q0, q0, [x0];
    /* 0x3bdc88 */ stp q0, q0, [x0, #0x20];
    /* 0x3bdc8c */ str q0, [x0, #0x40];
    /* 0x3bdc90 */ str xzr, [x0, #0x50];
    /* 0x3bdc94 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
