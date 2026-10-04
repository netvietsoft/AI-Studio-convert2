// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e73ec
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI14nGetMouthColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e73ec | Size: 44 bytes | SHA256: 53705dfe6df57c8179edd9f9655acd5ed03fff6d7f232f5090221b8cfc0ee7a9
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetMouthColor(J)J (table at 0x538968)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI14nGetMouthColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2e73ec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e73f0 */ str x19, [sp, #0x10];
    /* 0x2e73f4 */ mov x29, sp;
    /* 0x2e73f8 */ mov w0, #0x10;
    /* 0x2e73fc */ mov x19, x2;
    _Znwm();
    /* 0x2e7404 */ ldr q0, [x19, #0x10];
    /* 0x2e7408 */ str q0, [x0];
    /* 0x2e740c */ ldr x19, [sp, #0x10];
    /* 0x2e7410 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
