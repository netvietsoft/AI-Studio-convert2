// Library: libAIModelSearchKit.so
// Function ID: libAIModelSearchKit::0x72698
// Recovered Name: sub_72698
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x72698 | Size: 152 bytes | SHA256: 48445fb2cb7d09ae8f8e8eec7bc229d3554e2e264f44377c03741c1bd9b49ab9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_72698(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x72698 */ stp x29, x30, [sp, #0x100];
    /* 0x7269c */ stp x28, x19, [sp, #0x110];
    /* 0x726a0 */ add x29, sp, #0x100;
    /* 0x726a4 */ stp x3, x4, [x29, #-0x78];
    /* 0x726a8 */ sub x9, x29, #0x78;
    /* 0x726ac */ mov x10, sp;
    /* 0x726b0 */ stp x5, x6, [x29, #-0x68];
    /* 0x726b4 */ add x10, x10, #0x80;
    /* 0x726b8 */ sub x3, x29, #0x50;
    /* 0x726bc */ stur x7, [x29, #-0x58];
    /* 0x726c0 */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
