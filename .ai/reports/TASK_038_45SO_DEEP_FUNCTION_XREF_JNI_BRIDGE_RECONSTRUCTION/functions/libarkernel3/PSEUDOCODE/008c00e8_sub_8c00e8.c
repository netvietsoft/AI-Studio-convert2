// Library: libarkernel3.so
// Function ID: libarkernel3::0x8c00e8
// Recovered Name: sub_8c00e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8c00e8 | Size: 192 bytes | SHA256: 3e578a862983114c40ace9bb03b49aae4a45d1024623f69d622cec06549d5d1b
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairPart::HairDict]"

void sub_8c00e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x8c00e8 */ stp x29, x30, [sp, #0x50];
    /* 0x8c00ec */ str x21, [sp, #0x60];
    /* 0x8c00f0 */ stp x20, x19, [sp, #0x70];
    /* 0x8c00f4 */ add x29, sp, #0x50;
    /* 0x8c00f8 */ mrs x20, tpidr_el0;
    /* 0x8c00fc */ mov x19, x0;
    /* 0x8c0100 */ ldr x8, [x20, #0x28];
    /* 0x8c0104 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x8c010c */ movi v0.2d, #0000000000000000;
    /* 0x8c0110 */ adrp x8, #0x248000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
    return x0;
}
