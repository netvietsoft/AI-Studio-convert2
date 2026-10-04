// Library: libARSPM.so
// Function ID: libARSPM::0x16cdec
// Recovered Name: sub_16cdec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x16cdec | Size: 112 bytes | SHA256: 1b58e3c24ed7cd2004dd4f7075858e782b4e8378fec774686f8375eb949d5acf
// Callers: 0 | Callees: 2 | Imports: 0

// Strings referenced:
//   "../../../../src/core/SkBlurMask.cpp"

void sub_16cdec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 28 instructions
    /* 0x16cdec */ mov w0, #1;
    /* 0x16cdf0 */ ldp x20, x19, [sp, #0xb0];
    /* 0x16cdf4 */ ldp x22, x21, [sp, #0xa0];
    /* 0x16cdf8 */ ldp x24, x23, [sp, #0x90];
    /* 0x16cdfc */ ldp x29, x30, [sp, #0x80];
    /* 0x16ce00 */ add sp, sp, #0xc0;
    return x0;
    /* 0x16ce08 */ adrp x0, #0x68000;
    /* 0x16ce0c */ add x0, x0, #0xd;
    /* 0x16ce10 */ adrp x1, #0x67000;
    /* 0x16ce14 */ add x1, x1, #0x376;
    sub_2cfaa0();
    sub_2666c0();
    sub_2cfaa0();
    sub_2666c0();
    sub_2cfaa0();
    sub_2666c0();
}
