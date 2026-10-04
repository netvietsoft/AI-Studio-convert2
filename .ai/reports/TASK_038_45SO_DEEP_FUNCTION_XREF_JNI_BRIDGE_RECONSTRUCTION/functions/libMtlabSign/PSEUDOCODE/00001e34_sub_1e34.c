// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x1e34
// Recovered Name: sub_1e34
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1e34 | Size: 152 bytes | SHA256: 89a888a74c74743b550311249d1925bf3610aec111d450bbe399673bd7a678c4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_1e34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x1e34 */ stp x29, x30, [sp, #0x100];
    /* 0x1e38 */ stp x28, x19, [sp, #0x110];
    /* 0x1e3c */ add x29, sp, #0x100;
    /* 0x1e40 */ stp x3, x4, [x29, #-0x78];
    /* 0x1e44 */ sub x9, x29, #0x78;
    /* 0x1e48 */ mov x10, sp;
    /* 0x1e4c */ stp x5, x6, [x29, #-0x68];
    /* 0x1e50 */ add x10, x10, #0x80;
    /* 0x1e54 */ sub x3, x29, #0x50;
    /* 0x1e58 */ stur x7, [x29, #-0x58];
    /* 0x1e5c */ stp q0, q1, [sp];
    return x0;
    __stack_chk_fail();
}
