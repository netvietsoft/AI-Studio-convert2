// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55d770
// Recovered Name: sub_55d770
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55d770 | Size: 152 bytes | SHA256: cfc517c3e6fac0776c29066d2059a1a1e590b955f753bb788a0b31cfb580e755
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_55d770(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x55d770 */ stp x29, x30, [sp, #0x100];
    /* 0x55d774 */ stp x28, x19, [sp, #0x110];
    /* 0x55d778 */ add x29, sp, #0x100;
    /* 0x55d77c */ stp x3, x4, [x29, #-0x78];
    /* 0x55d780 */ sub x9, x29, #0x78;
    /* 0x55d784 */ mov x10, sp;
    /* 0x55d788 */ stp x5, x6, [x29, #-0x68];
    /* 0x55d78c */ add x10, x10, #0x80;
    /* 0x55d790 */ sub x3, x29, #0x50;
    /* 0x55d794 */ stur x7, [x29, #-0x58];
    /* 0x55d798 */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
