// Library: libglide-webp.so
// Function ID: libglide-webp::0x129b0
// Recovered Name: sub_129b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x129b0 | Size: 212 bytes | SHA256: 97dfcb3d0d82439c4a3fe56a8e69aa20f3bf985ece187780ca6fa0f568fe8b18
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __stack_chk_fail, vsnprintf
// Strings referenced:
//   "java/lang/IllegalStateException"

void sub_129b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x129b0 */ stp x29, x30, [sp, #0x20];
    /* 0x129b4 */ add x29, sp, #0x20;
    /* 0x129b8 */ sub sp, sp, #0x500;
    /* 0x129bc */ stp x2, x3, [sp, #0x80];
    /* 0x129c0 */ stp x4, x5, [sp, #0x90];
    /* 0x129c4 */ stp x6, x7, [sp, #0xa0];
    /* 0x129c8 */ stp q0, q1, [sp];
    /* 0x129cc */ stp q2, q3, [sp, #0x20];
    /* 0x129d0 */ stp q4, q5, [sp, #0x40];
    /* 0x129d4 */ stp q6, q7, [sp, #0x60];
    /* 0x129d8 */ mrs x20, tpidr_el0;
    vsnprintf();
    return x0;
    __stack_chk_fail();
}
