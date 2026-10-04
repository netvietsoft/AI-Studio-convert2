// Library: libfantasy.so
// Function ID: libfantasy::0xba6e0
// Recovered Name: sub_ba6e0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xba6e0 | Size: 120 bytes | SHA256: b6e181feb78c9e5e37a65a86f9938ee4badd75e8042b16c0ed07534ebc8f54af
// Callers: 0 | Callees: 0 | Imports: 0


void sub_ba6e0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xba6e0 */ cbz x1, #0xba750;
    /* 0xba6e4 */ ldp x8, x9, [x0, #0xa0];
    /* 0xba6e8 */ mov x10, xzr;
    /* 0xba6ec */ cbz x9, #0xba710;
    /* 0xba6f0 */ mov x11, x8;
    /* 0xba6f4 */ ldrsh w12, [x11], #8;
    /* 0xba6f8 */ cmn w12, #1;
    /* 0xba6fc */ b.ne #0xba710;
    /* 0xba700 */ add x10, x10, #1;
    /* 0xba704 */ cmp x9, x10;
    /* 0xba708 */ b.ne #0xba6f4;
    return x0;
}
