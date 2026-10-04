// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e3fb0
// Recovered Name: _ZN11LayerFlowNS17LFFrameModularJNI9nGetScaleEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e3fb0 | Size: 108 bytes | SHA256: 34a8381f73e12ec9d797e56f4436965c5506397cada33e7926080e50da0fc9b5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetScale(J)[F (table at 0x537fc0)

jobject _ZN11LayerFlowNS17LFFrameModularJNI9nGetScaleEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2e3fb0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2e3fb4 */ str x21, [sp, #0x10];
    /* 0x2e3fb8 */ stp x20, x19, [sp, #0x20];
    /* 0x2e3fbc */ mov x29, sp;
    /* 0x2e3fc0 */ ldp x9, x8, [x2, #0x20];
    /* 0x2e3fc4 */ mov x19, x2;
    /* 0x2e3fc8 */ ldr x10, [x0];
    /* 0x2e3fcc */ mov x20, x0;
    /* 0x2e3fd0 */ sub x8, x8, x9;
    /* 0x2e3fd4 */ lsr x21, x8, #2;
    /* 0x2e3fd8 */ ldr x8, [x10, #0x5a8];
    return x0;
}
