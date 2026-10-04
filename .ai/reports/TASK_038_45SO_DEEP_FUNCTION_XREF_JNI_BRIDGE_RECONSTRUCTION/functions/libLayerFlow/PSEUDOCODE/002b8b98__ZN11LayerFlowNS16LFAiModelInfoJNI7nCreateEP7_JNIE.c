// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8b98
// Recovered Name: _ZN11LayerFlowNS16LFAiModelInfoJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2b8b98 | Size: 36 bytes | SHA256: 3c68b4793bcdd5dfd780562b4144521e44958d545183c309e16c3a2f9777d779
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x531048)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFAiModelInfoJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2b8b98 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2b8b9c */ mov x29, sp;
    /* 0x2b8ba0 */ mov w0, #0x30;
    _Znwm();
    /* 0x2b8ba8 */ movi v0.2d, #0000000000000000;
    /* 0x2b8bac */ stp q0, q0, [x0];
    /* 0x2b8bb0 */ str q0, [x0, #0x20];
    /* 0x2b8bb4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
