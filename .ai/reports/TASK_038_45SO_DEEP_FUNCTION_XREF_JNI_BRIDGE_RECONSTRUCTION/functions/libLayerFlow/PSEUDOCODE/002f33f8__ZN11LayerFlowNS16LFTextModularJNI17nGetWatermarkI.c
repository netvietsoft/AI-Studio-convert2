// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f33f8
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI17nGetWatermarkInfoEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f33f8 | Size: 64 bytes | SHA256: 2cb0283c3a6ef3ffb5fa423579cb3763be693647bb73e6c7fb5ad071b91447fe
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetWatermarkInfo(J)J (table at 0x53b1a0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFTextModularJNI17nGetWatermarkInfoEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x2f33f8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2f33fc */ str x19, [sp, #0x10];
    /* 0x2f3400 */ mov x29, sp;
    /* 0x2f3404 */ mov w0, #0x38;
    /* 0x2f3408 */ mov x19, x2;
    _Znwm();
    /* 0x2f3410 */ ldr x8, [x19, #0xa8];
    /* 0x2f3414 */ ldur q0, [x19, #0x98];
    /* 0x2f3418 */ ldur q1, [x19, #0x88];
    /* 0x2f341c */ ldur q2, [x19, #0x78];
    /* 0x2f3420 */ str x8, [x0, #0x30];
    return x0;
}
