// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e750
// Recovered Name: sub_56e750
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e750 | Size: 48 bytes | SHA256: 0a99309c890e4d3d261fb1d953825590ad8dc6303278e44b29d797baddaa8ee5
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetCurrentVersion()Ljava/lang/String; (table at 0x10cd538)

jlong sub_56e750(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x56e750 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x56e754 */ str x19, [sp, #0x10];
    /* 0x56e758 */ mov x29, sp;
    /* 0x56e75c */ mov x19, x0;
    sub_6061f8();
    /* 0x56e764 */ ldr x8, [x19];
    /* 0x56e768 */ mov x1, x0;
    /* 0x56e76c */ ldr x2, [x8, #0x538];
    /* 0x56e770 */ mov x0, x19;
    /* 0x56e774 */ ldr x19, [sp, #0x10];
    /* 0x56e778 */ ldp x29, x30, [sp], #0x20;
}
