// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57885c
// Recovered Name: sub_57885c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57885c | Size: 268 bytes | SHA256: c5710b8e5977ef88eb0af5001180219efb7ec95778328158a0b6fd9bea850afb
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetFaceliftOffsetPoint(J[F[FII)V (table at 0x10ce000)

jlong sub_57885c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0x57885c */ stp x29, x30, [sp, #-0x50]!;
    /* 0x578860 */ stp x26, x25, [sp, #0x10];
    /* 0x578864 */ stp x24, x23, [sp, #0x20];
    /* 0x578868 */ stp x22, x21, [sp, #0x30];
    /* 0x57886c */ stp x20, x19, [sp, #0x40];
    /* 0x578870 */ mov x29, sp;
    /* 0x578874 */ cbz x2, #0x578950;
    /* 0x578878 */ ldr x8, [x0];
    /* 0x57887c */ mov x26, x2;
    /* 0x578880 */ mov x1, x3;
    /* 0x578884 */ mov x2, xzr;
    sub_575844();
    return x0;
}
