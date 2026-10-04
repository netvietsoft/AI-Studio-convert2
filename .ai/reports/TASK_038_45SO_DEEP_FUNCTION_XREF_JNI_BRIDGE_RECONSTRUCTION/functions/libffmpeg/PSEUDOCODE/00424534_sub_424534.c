// Library: libffmpeg.so
// Function ID: libffmpeg::0x424534
// Recovered Name: sub_424534
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x424534 | Size: 20 bytes | SHA256: 5b8da2c68474dab51d2415aa526abb498f9ef75d2e833ed282a25bb5ea05631e
// Callers: 2 | Callees: 0 | Imports: 0

// Strings referenced:
//   "libavformat/segment.c"

void sub_424534(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x424534 */ adrp x4, #0xaf000;
    /* 0x424538 */ add x4, x4, #0x865;
    /* 0x42453c */ mov x0, xzr;
    /* 0x424540 */ mov w1, wzr;
    return x0;
}
