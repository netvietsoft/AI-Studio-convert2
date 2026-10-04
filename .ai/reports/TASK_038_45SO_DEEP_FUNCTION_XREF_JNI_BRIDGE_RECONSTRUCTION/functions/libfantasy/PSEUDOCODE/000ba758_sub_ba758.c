// Library: libfantasy.so
// Function ID: libfantasy::0xba758
// Recovered Name: sub_ba758
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xba758 | Size: 40 bytes | SHA256: 05c986bafa68d6c6995474f3f3a8c7580fd6fe23c6992d56040ec612cb855b9b
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: memcpy

void sub_ba758(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0xba758 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xba75c */ mov x29, sp;
    /* 0xba760 */ mov x8, x0;
    /* 0xba764 */ add x0, x1, #8;
    /* 0xba768 */ mov w2, #0x90;
    /* 0xba76c */ add x1, x8, #0xe0;
    memcpy();
    /* 0xba774 */ mov w0, #1;
    /* 0xba778 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
