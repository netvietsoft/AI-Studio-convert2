// Library: libARSPM.so
// Function ID: libARSPM::0x3a8368
// Recovered Name: sub_3a8368
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3a8368 | Size: 600 bytes | SHA256: 15293a1503ae0691307a6cb2d2a7ece635fcbcbb7a7e651b5cd8f77cf4995265
// Callers: 0 | Callees: 8 | Imports: 0

// Strings referenced:
//   "%s = colorAttrib;"
//   "MAX_FIXED_RESOLVE_LEVEL"
//   "MAX_FIXED_SEGMENTS"
//   "PRECISION"
//   "bool is_conic_curve() { return isinf(p23.w); }bool is_triangular_conic_curve() { return isinf(p23.z); }"

void sub_3a8368(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 150 instructions
    /* 0x3a8368 */ stp x29, x30, [sp, #0x20];
    /* 0x3a836c */ str x25, [sp, #0x30];
    /* 0x3a8370 */ stp x24, x23, [sp, #0x40];
    /* 0x3a8374 */ stp x22, x21, [sp, #0x50];
    /* 0x3a8378 */ stp x20, x19, [sp, #0x60];
    /* 0x3a837c */ add x29, sp, #0x20;
    /* 0x3a8380 */ ldr x8, [x3, #0xa0];
    /* 0x3a8384 */ fmov d0, #4.00000000;
    /* 0x3a8388 */ adrp x25, #0x66000;
    /* 0x3a838c */ add x25, x25, #0xb94;
    /* 0x3a8390 */ mov x22, x2;
    sub_1da048();
    sub_1da048();
    sub_1da048();
    sub_3a9684();
    sub_1d99c4();
    sub_1d99c4();
    sub_1da35c();
    sub_1d99c4();
    sub_1d93f8();
    sub_1da35c();
    sub_1d99c4();
    sub_1d93f8();
    sub_1d99c4();
    sub_1d99c4();
    sub_1d99c4();
    sub_1d99c4();
    sub_1d95e8();
    sub_1d95e8();
    sub_343850();
    sub_2d1b70();
    sub_1d95e8();
    return x0;
}
