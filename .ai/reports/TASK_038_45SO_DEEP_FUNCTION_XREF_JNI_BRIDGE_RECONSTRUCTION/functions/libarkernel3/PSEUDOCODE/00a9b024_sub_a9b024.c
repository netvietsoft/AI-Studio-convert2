// Library: libarkernel3.so
// Function ID: libarkernel3::0xa9b024
// Recovered Name: sub_a9b024
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa9b024 | Size: 52 bytes | SHA256: 5373f287c4b63c77048f9bebd0b243cb639b89d98f1d0e6462c8b18c15644ab4
// Callers: 0 | Callees: 1 | Imports: 0

// Strings referenced:
//   "No suit for segment mask"
//   "handleSourceSizeSegmentMask"
//   "mtlabar3"

void sub_a9b024(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0xa9b024 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xa9b028 */ mov x29, sp;
    /* 0xa9b02c */ adrp x1, #0x199000;
    /* 0xa9b030 */ add x1, x1, #0xbc4;
    /* 0xa9b034 */ adrp x2, #0x217000;
    /* 0xa9b038 */ add x2, x2, #0x113;
    /* 0xa9b03c */ adrp x3, #0x25f000;
    /* 0xa9b040 */ add x3, x3, #0x2d2;
    /* 0xa9b044 */ mov w0, #2;
    sub_cccfe0();
    /* 0xa9b04c */ mov x0, xzr;
    return x0;
}
