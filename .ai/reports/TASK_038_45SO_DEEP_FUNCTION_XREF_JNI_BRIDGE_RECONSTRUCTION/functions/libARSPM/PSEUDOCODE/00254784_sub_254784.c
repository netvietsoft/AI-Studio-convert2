// Library: libARSPM.so
// Function ID: libARSPM::0x254784
// Recovered Name: sub_254784
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x254784 | Size: 328 bytes | SHA256: c00b013d5dfd11eae6c871519accb59b0a75ab6942d7fcf87a6f2b0d03fd2d63
// Callers: 0 | Callees: 3 | Imports: 0

// Strings referenced:
//   "GaussianBlur"
//   "disabled-by-default-skia.gpu"
//   "sigmaX"
//   "sigmaY"

void sub_254784(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 82 instructions
    /* 0x254784 */ stp x29, x30, [sp, #0x30];
    /* 0x254788 */ stp x28, x27, [sp, #0x40];
    /* 0x25478c */ stp x26, x25, [sp, #0x50];
    /* 0x254790 */ stp x24, x23, [sp, #0x60];
    /* 0x254794 */ stp x22, x21, [sp, #0x70];
    /* 0x254798 */ stp x20, x19, [sp, #0x80];
    /* 0x25479c */ add x29, sp, #0x30;
    /* 0x2547a0 */ sub sp, sp, #0x210;
    /* 0x2547a4 */ ldp x9, x10, [x29, #0x60];
    /* 0x2547a8 */ adrp x25, #0x515000;
    /* 0x2547ac */ stp q1, q0, [sp, #0xd0];
    sub_207b3c();
    sub_207b3c();
    sub_30ebac();
    sub_2d1ce4();
}
