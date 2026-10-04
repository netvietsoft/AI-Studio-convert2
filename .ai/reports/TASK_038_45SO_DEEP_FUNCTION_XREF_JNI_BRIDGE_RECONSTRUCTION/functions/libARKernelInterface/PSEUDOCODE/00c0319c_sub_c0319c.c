// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc0319c
// Recovered Name: sub_c0319c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc0319c | Size: 76 bytes | SHA256: e1f9d27c7ed2862039b4948b9f8a6d17c90594d97af3a7a90d0a00ce861cc07b
// Callers: 7 | Callees: 2 | Imports: 0

// Strings referenced:
//   "'GPInstanceSegmentData' expected."
//   "GPInstanceSegmentData"

void sub_c0319c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0xc0319c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xc031a0 */ stp x20, x19, [sp, #0x10];
    /* 0xc031a4 */ mov x29, sp;
    /* 0xc031a8 */ adrp x2, #0x22b000;
    /* 0xc031ac */ add x2, x2, #0xa19;
    /* 0xc031b0 */ mov w1, #1;
    /* 0xc031b4 */ mov x19, x0;
    sub_f0f180();
    /* 0xc031bc */ mov x20, x0;
    /* 0xc031c0 */ cbnz x0, #0xc031d8;
    /* 0xc031c4 */ adrp x2, #0x190000;
    sub_f0ebec();
    return x0;
}
