// Library: libManis.so
// Function ID: libManis::0x32c48c
// Recovered Name: sub_32c48c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32c48c | Size: 20 bytes | SHA256: 241085117f4a8b7caa5b0e2d1aa3f4a94382e44d3413612b8adabeab4f7966bd
// Callers: 3 | Callees: 0 | Imports: 0


void sub_32c48c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x32c48c */ cbz x0, #0x32c4c4;
    /* 0x32c490 */ ldr x8, [x0];
    /* 0x32c494 */ cbz x8, #0x32c4c4;
    /* 0x32c498 */ ldur x8, [x8, #-8];
    /* 0x32c49c */ cbz x8, #0x32c4c4;
}
