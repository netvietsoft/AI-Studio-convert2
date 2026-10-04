// Library: libglide-webp.so
// Function ID: libglide-webp::0x128d4
// Recovered Name: sub_128d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x128d4 | Size: 212 bytes | SHA256: 6f52f29b2376d333b8efe35495663fec60fd383623bb84a342d815855abb0eca
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __stack_chk_fail, vsnprintf
// Strings referenced:
//   "java/lang/IllegalArgumentException"

void sub_128d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x128d4 */ stp x29, x30, [sp, #0x20];
    /* 0x128d8 */ add x29, sp, #0x20;
    /* 0x128dc */ sub sp, sp, #0x500;
    /* 0x128e0 */ stp x2, x3, [sp, #0x80];
    /* 0x128e4 */ stp x4, x5, [sp, #0x90];
    /* 0x128e8 */ stp x6, x7, [sp, #0xa0];
    /* 0x128ec */ stp q0, q1, [sp];
    /* 0x128f0 */ stp q2, q3, [sp, #0x20];
    /* 0x128f4 */ stp q4, q5, [sp, #0x40];
    /* 0x128f8 */ stp q6, q7, [sp, #0x60];
    /* 0x128fc */ mrs x20, tpidr_el0;
    vsnprintf();
    return x0;
    __stack_chk_fail();
}
