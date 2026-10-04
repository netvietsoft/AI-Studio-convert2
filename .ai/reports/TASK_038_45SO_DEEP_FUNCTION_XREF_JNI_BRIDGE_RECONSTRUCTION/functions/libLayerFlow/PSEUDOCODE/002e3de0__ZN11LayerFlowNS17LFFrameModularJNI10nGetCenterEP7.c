// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e3de0
// Recovered Name: _ZN11LayerFlowNS17LFFrameModularJNI10nGetCenterEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e3de0 | Size: 108 bytes | SHA256: 5f4eb4c5824a3ffc4d18b67be68a85a5ca629658473a513f3b96ec0e3c1fff05
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetCenter(J)[F (table at 0x537f90)

jobject _ZN11LayerFlowNS17LFFrameModularJNI10nGetCenterEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x2e3de0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2e3de4 */ str x21, [sp, #0x10];
    /* 0x2e3de8 */ stp x20, x19, [sp, #0x20];
    /* 0x2e3dec */ mov x29, sp;
    /* 0x2e3df0 */ ldp x9, x8, [x2, #8];
    /* 0x2e3df4 */ mov x19, x2;
    /* 0x2e3df8 */ ldr x10, [x0];
    /* 0x2e3dfc */ mov x20, x0;
    /* 0x2e3e00 */ sub x8, x8, x9;
    /* 0x2e3e04 */ lsr x21, x8, #2;
    /* 0x2e3e08 */ ldr x8, [x10, #0x5a8];
    return x0;
}
