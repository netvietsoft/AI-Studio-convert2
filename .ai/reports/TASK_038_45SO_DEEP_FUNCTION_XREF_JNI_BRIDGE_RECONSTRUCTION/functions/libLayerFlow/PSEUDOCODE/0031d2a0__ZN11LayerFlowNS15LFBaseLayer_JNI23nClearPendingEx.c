// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x31d2a0
// Recovered Name: _ZN11LayerFlowNS15LFBaseLayer_JNI23nClearPendingExceptionsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x31d2a0 | Size: 72 bytes | SHA256: 3d4111d054de2f7ad7998c030388b96e4d80c80e3fc2adc4804d23701ae41e66
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nClearPendingExceptions()V (table at 0x53c218)

jobject _ZN11LayerFlowNS15LFBaseLayer_JNI23nClearPendingExceptionsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x31d2a0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x31d2a4 */ str x19, [sp, #0x10];
    /* 0x31d2a8 */ mov x29, sp;
    /* 0x31d2ac */ ldr x8, [x0];
    /* 0x31d2b0 */ mov x19, x0;
    /* 0x31d2b4 */ ldr x8, [x8, #0x720];
    /* 0x31d2b8 */ blr x8;
    /* 0x31d2bc */ tst w0, #0xff;
    /* 0x31d2c0 */ b.eq #0x31d2dc;
    /* 0x31d2c4 */ ldr x8, [x19];
    /* 0x31d2c8 */ ldr x1, [x8, #0x88];
    return x0;
}
