// Library: libdexvmp.so
// Function ID: libdexvmp::0x8f28
// Recovered Name: sub_8f28
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8f28 | Size: 300 bytes | SHA256: 3e79882b3626880ad8077ddbbdb4d1056a82118ba18cd8474e7c07f47f5e2fd4
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: memset

void sub_8f28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 75 instructions
    /* 0x8f28 */ stp x29, x30, [sp, #0x30];
    /* 0x8f2c */ add x29, sp, #0x30;
    /* 0x8f30 */ sub sp, sp, #0x10;
    /* 0x8f34 */ mov w24, w5;
    /* 0x8f38 */ mov w23, w4;
    /* 0x8f3c */ mov w19, w3;
    /* 0x8f40 */ mov x20, x2;
    /* 0x8f44 */ mov x21, x1;
    /* 0x8f48 */ mov x22, x0;
    /* 0x8f4c */ mov w1, wzr;
    /* 0x8f50 */ mov w2, #0x4020;
    memset();
    sub_9070();
    return x0;
}
