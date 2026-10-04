// Library: libarkernel3.so
// Function ID: libarkernel3::0x61c794
// Recovered Name: sub_61c794
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61c794 | Size: 76 bytes | SHA256: c1b56befb2a42bd3c5769926630e2958cebb035d79809215871df06ff95664a1
// Callers: 7 | Callees: 2 | Imports: 0

// Strings referenced:
//   "'GPInstanceSegmentData' expected."
//   "GPInstanceSegmentData"

void sub_61c794(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x61c794 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x61c798 */ stp x20, x19, [sp, #0x10];
    /* 0x61c79c */ mov x29, sp;
    /* 0x61c7a0 */ adrp x2, #0x24f000;
    /* 0x61c7a4 */ add x2, x2, #0xbeb;
    /* 0x61c7a8 */ mov w1, #1;
    /* 0x61c7ac */ mov x19, x0;
    sub_b7a990();
    /* 0x61c7b4 */ mov x20, x0;
    /* 0x61c7b8 */ cbnz x0, #0x61c7d0;
    /* 0x61c7bc */ adrp x2, #0x19a000;
    sub_b7a3fc();
    return x0;
}
