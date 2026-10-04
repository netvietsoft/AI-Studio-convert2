// Library: libAIModelSearchKit.so
// Function ID: libAIModelSearchKit::0x72734
// Recovered Name: sub_72734
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x72734 | Size: 152 bytes | SHA256: 690d532d6ab7ad54816a062275083656d13f079a48444d91332fac0ed1a2d5f0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_72734(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x72734 */ stp x29, x30, [sp, #0x100];
    /* 0x72738 */ stp x28, x19, [sp, #0x110];
    /* 0x7273c */ add x29, sp, #0x100;
    /* 0x72740 */ stp x3, x4, [x29, #-0x78];
    /* 0x72744 */ sub x9, x29, #0x78;
    /* 0x72748 */ mov x10, sp;
    /* 0x7274c */ stp x5, x6, [x29, #-0x68];
    /* 0x72750 */ add x10, x10, #0x80;
    /* 0x72754 */ sub x3, x29, #0x50;
    /* 0x72758 */ stur x7, [x29, #-0x58];
    /* 0x7275c */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
