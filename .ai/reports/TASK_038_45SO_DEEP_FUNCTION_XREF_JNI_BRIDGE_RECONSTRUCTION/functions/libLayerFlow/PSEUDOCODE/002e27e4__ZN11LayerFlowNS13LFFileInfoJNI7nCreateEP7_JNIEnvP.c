// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e27e4
// Recovered Name: _ZN11LayerFlowNS13LFFileInfoJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e27e4 | Size: 36 bytes | SHA256: 95feaccb051b44bb94eb92beffa0863c99cdd6d947d71fd8929b9e7bdb0bb0a7
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x537b70)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS13LFFileInfoJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2e27e4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e27e8 */ mov x29, sp;
    /* 0x2e27ec */ mov w0, #0x30;
    _Znwm();
    /* 0x2e27f4 */ movi v0.2d, #0000000000000000;
    /* 0x2e27f8 */ stp q0, q0, [x0];
    /* 0x2e27fc */ str q0, [x0, #0x20];
    /* 0x2e2800 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
