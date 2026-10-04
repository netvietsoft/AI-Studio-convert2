// Library: libarkernel3.so
// Function ID: libarkernel3::0x55ee98
// Recovered Name: sub_55ee98
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55ee98 | Size: 188 bytes | SHA256: a42cd7a3e10f160122bd2afc6182f0c27e73843d57b2b2e73023376f99155e18
// Callers: 0 | Callees: 3 | Imports: 0


void sub_55ee98(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x55ee98 */ stp x29, x30, [sp, #0x20];
    /* 0x55ee9c */ stp x24, x23, [sp, #0x30];
    /* 0x55eea0 */ stp x22, x21, [sp, #0x40];
    /* 0x55eea4 */ stp x20, x19, [sp, #0x50];
    /* 0x55eea8 */ add x29, sp, #0x20;
    /* 0x55eeac */ mov x23, x0;
    /* 0x55eeb0 */ mov x0, x3;
    /* 0x55eeb4 */ mov w19, w4;
    /* 0x55eeb8 */ fmov s8, s3;
    /* 0x55eebc */ fmov s9, s2;
    /* 0x55eec0 */ fmov s10, s1;
    sub_560f54();
    sub_560f30();
    sub_55ef54();
    sub_560f54();
    return x0;
}
