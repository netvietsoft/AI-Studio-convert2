// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55d6d4
// Recovered Name: sub_55d6d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55d6d4 | Size: 152 bytes | SHA256: 42241350ecb0f5208310c69099b59dcc1092587ec671e6643903fe6f21dcc238
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_55d6d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x55d6d4 */ stp x29, x30, [sp, #0x100];
    /* 0x55d6d8 */ stp x28, x19, [sp, #0x110];
    /* 0x55d6dc */ add x29, sp, #0x100;
    /* 0x55d6e0 */ stp x3, x4, [x29, #-0x78];
    /* 0x55d6e4 */ sub x9, x29, #0x78;
    /* 0x55d6e8 */ mov x10, sp;
    /* 0x55d6ec */ stp x5, x6, [x29, #-0x68];
    /* 0x55d6f0 */ add x10, x10, #0x80;
    /* 0x55d6f4 */ sub x3, x29, #0x50;
    /* 0x55d6f8 */ stur x7, [x29, #-0x58];
    /* 0x55d6fc */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
