// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e7528
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI16nGetEyeBrowColorEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e7528 | Size: 44 bytes | SHA256: 67d08c379be71d9967dfb11686d25a9aadfdb8968f25de5d1271f9edd5abfe69
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetEyeBrowColor(J)J (table at 0x538a28)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI16nGetEyeBrowColorEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2e7528 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e752c */ str x19, [sp, #0x10];
    /* 0x2e7530 */ mov x29, sp;
    /* 0x2e7534 */ mov w0, #0x10;
    /* 0x2e7538 */ mov x19, x2;
    _Znwm();
    /* 0x2e7540 */ ldr q0, [x19];
    /* 0x2e7544 */ str q0, [x0];
    /* 0x2e7548 */ ldr x19, [sp, #0x10];
    /* 0x2e754c */ ldp x29, x30, [sp], #0x20;
    return x0;
}
