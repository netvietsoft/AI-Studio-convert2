// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e7430
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI14nGetBlushColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e7430 | Size: 44 bytes | SHA256: 0481babb2dd76c22c9944233ede2f3ce78111d3eff9a713c6885045af2804c5a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetBlushColor(J)J (table at 0x538998)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI14nGetBlushColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2e7430 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e7434 */ str x19, [sp, #0x10];
    /* 0x2e7438 */ mov x29, sp;
    /* 0x2e743c */ mov w0, #0x10;
    /* 0x2e7440 */ mov x19, x2;
    _Znwm();
    /* 0x2e7448 */ ldr q0, [x19, #0x20];
    /* 0x2e744c */ str q0, [x0];
    /* 0x2e7450 */ ldr x19, [sp, #0x10];
    /* 0x2e7454 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
