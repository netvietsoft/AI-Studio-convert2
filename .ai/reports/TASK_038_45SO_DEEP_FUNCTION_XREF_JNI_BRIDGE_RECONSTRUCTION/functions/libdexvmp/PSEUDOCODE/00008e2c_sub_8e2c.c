// Library: libdexvmp.so
// Function ID: libdexvmp::0x8e2c
// Recovered Name: sub_8e2c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8e2c | Size: 48 bytes | SHA256: 8acd56440fb1781a0a7411a3f5d4fc82eb9975e4cc265abcddc52b3a4eaf8622
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __cxa_atexit

void sub_8e2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x8e2c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e30 */ mov x29, sp;
    /* 0x8e34 */ cbz x0, #0x8e3c;
    /* 0x8e38 */ blr x0;
    /* 0x8e3c */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x8e44 */ mov x1, x0;
    /* 0x8e48 */ adrp x2, #0x8a000;
    /* 0x8e4c */ adrp x0, #0x8000;
    /* 0x8e50 */ add x2, x2, #0;
    /* 0x8e54 */ add x0, x0, #0xe2c;
}
