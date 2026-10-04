// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e780
// Recovered Name: sub_56e780
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e780 | Size: 48 bytes | SHA256: 2efa7999d82cd8b70c0dd0b20e021be46dd4586a70b8563eb5df0824555419da
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetTagVersion()Ljava/lang/String; (table at 0x10cd550)

jlong sub_56e780(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x56e780 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x56e784 */ str x19, [sp, #0x10];
    /* 0x56e788 */ mov x29, sp;
    /* 0x56e78c */ mov x19, x0;
    sub_606204();
    /* 0x56e794 */ ldr x8, [x19];
    /* 0x56e798 */ mov x1, x0;
    /* 0x56e79c */ ldr x2, [x8, #0x538];
    /* 0x56e7a0 */ mov x0, x19;
    /* 0x56e7a4 */ ldr x19, [sp, #0x10];
    /* 0x56e7a8 */ ldp x29, x30, [sp], #0x20;
}
