// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x86eb4
// Recovered Name: sub_86eb4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x86eb4 | Size: 152 bytes | SHA256: cf59a8db29431f8c59830939b8c4d45c2897b39d526843f096f92bd1b860db5e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_86eb4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x86eb4 */ stp x29, x30, [sp, #0x100];
    /* 0x86eb8 */ stp x28, x19, [sp, #0x110];
    /* 0x86ebc */ add x29, sp, #0x100;
    /* 0x86ec0 */ stp x3, x4, [x29, #-0x78];
    /* 0x86ec4 */ sub x9, x29, #0x78;
    /* 0x86ec8 */ mov x10, sp;
    /* 0x86ecc */ stp x5, x6, [x29, #-0x68];
    /* 0x86ed0 */ add x10, x10, #0x80;
    /* 0x86ed4 */ sub x3, x29, #0x50;
    /* 0x86ed8 */ stur x7, [x29, #-0x58];
    /* 0x86edc */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
