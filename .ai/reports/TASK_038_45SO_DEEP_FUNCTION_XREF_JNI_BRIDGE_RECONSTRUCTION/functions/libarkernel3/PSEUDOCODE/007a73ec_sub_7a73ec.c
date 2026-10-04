// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a73ec
// Recovered Name: sub_7a73ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a73ec | Size: 188 bytes | SHA256: 001fc882227a6b98f0d2cb1def68adbc8875aa83c8c0d80cf44522964e3debf7
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FaceLiftFluffyHairPart]"

void sub_7a73ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x7a73ec */ stp x29, x30, [sp, #0x50];
    /* 0x7a73f0 */ str x21, [sp, #0x60];
    /* 0x7a73f4 */ stp x20, x19, [sp, #0x70];
    /* 0x7a73f8 */ add x29, sp, #0x50;
    /* 0x7a73fc */ mrs x20, tpidr_el0;
    /* 0x7a7400 */ mov x19, x0;
    /* 0x7a7404 */ ldr x8, [x20, #0x28];
    /* 0x7a7408 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x7a7410 */ movi v0.2d, #0000000000000000;
    /* 0x7a7414 */ adrp x8, #0x1b8000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
}
