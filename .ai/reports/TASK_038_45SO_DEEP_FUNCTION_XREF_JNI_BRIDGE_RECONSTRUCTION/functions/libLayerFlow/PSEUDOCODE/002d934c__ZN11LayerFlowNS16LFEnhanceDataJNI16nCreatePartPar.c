// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d934c
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI16nCreatePartParamEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d934c | Size: 228 bytes | SHA256: f03796bac84dada3bbbd6c8be29e4dc562044e3a9ff22d95b1b01dc9150918a1
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreatePartParam()J (table at 0x536950)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI16nCreatePartParamEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x2d934c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d9350 */ mov x29, sp;
    /* 0x2d9354 */ mov w0, #0x1f8;
    _Znwm();
    /* 0x2d935c */ movi v0.2d, #0000000000000000;
    /* 0x2d9360 */ mov x8, #1;
    /* 0x2d9364 */ str xzr, [x0, #0x1e0];
    /* 0x2d9368 */ movk x8, #0x4248, lsl #48;
    /* 0x2d936c */ add x9, x0, #0x150;
    /* 0x2d9370 */ stp xzr, xzr, [x0, #0x1e8];
    /* 0x2d9374 */ stp q0, q0, [x0];
    return x0;
}
