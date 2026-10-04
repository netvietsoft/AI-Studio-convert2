// Library: libarkernel3.so
// Function ID: libarkernel3::0x8c30b4
// Recovered Name: sub_8c30b4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8c30b4 | Size: 192 bytes | SHA256: b037b9cd1ed524a381fbdad8565f9bcb34f026c8e51b5f3ff2d6ee02d9d88a2b
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairSoftPart]"

void sub_8c30b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x8c30b4 */ stp x29, x30, [sp, #0x50];
    /* 0x8c30b8 */ str x21, [sp, #0x60];
    /* 0x8c30bc */ stp x20, x19, [sp, #0x70];
    /* 0x8c30c0 */ add x29, sp, #0x50;
    /* 0x8c30c4 */ mrs x20, tpidr_el0;
    /* 0x8c30c8 */ mov x19, x0;
    /* 0x8c30cc */ ldr x8, [x20, #0x28];
    /* 0x8c30d0 */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x8c30d8 */ movi v0.2d, #0000000000000000;
    /* 0x8c30dc */ adrp x8, #0x1fe000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
    return x0;
}
