// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d7380
// Recovered Name: sub_9d7380
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d7380 | Size: 2300 bytes | SHA256: 226aec2e4dc6c94abb86cb3c49c0748c7e86c00787c84efebdfc3be9ccc4c3f0
// Callers: 0 | Callees: 24 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Alpha"
//   "AnimalMirrorH"
//   "AnimalMirrorV"
//   "AnimalOffset"
//   "AnimalRotate"

void sub_9d7380(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 575 instructions
    /* 0x9d7380 */ stp x29, x30, [sp, #0x20];
    /* 0x9d7384 */ stp x28, x27, [sp, #0x30];
    /* 0x9d7388 */ stp x26, x25, [sp, #0x40];
    /* 0x9d738c */ stp x24, x23, [sp, #0x50];
    /* 0x9d7390 */ stp x22, x21, [sp, #0x60];
    /* 0x9d7394 */ stp x20, x19, [sp, #0x70];
    /* 0x9d7398 */ add x29, sp, #0x20;
    /* 0x9d739c */ mrs x8, tpidr_el0;
    /* 0x9d73a0 */ mov x19, x0;
    /* 0x9d73a4 */ add x0, x0, #0x440;
    /* 0x9d73a8 */ str x8, [sp, #8];
    sub_864560();
    sub_9b0424();
    sub_6607b8();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_9d7c7c();
    sub_9d7d4c();
    sub_9d7d4c();
    sub_9d7d4c();
    sub_9d7d4c();
    sub_9d7d4c();
    sub_9d7d4c();
    sub_9d7d4c();
    sub_9d7f3c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d800c();
    sub_9d81fc();
    sub_9d82cc();
    sub_9d82cc();
    sub_9d82cc();
    sub_9d82cc();
    sub_9d82cc();
    sub_9d84bc();
    sub_9d86d0();
    sub_9d86d0();
    sub_9d87cc();
    sub_9d88c8();
    sub_9d89c4();
    sub_9d8ac0();
    sub_9d8bbc();
    sub_9d8bbc();
    sub_9d8bbc();
    sub_9d8bbc();
    sub_9d8bbc();
    sub_9d8cb8();
    sub_9d8cb8();
    sub_9d8cb8();
    sub_9d8db4();
    sub_9d87cc();
    sub_9d8eb0();
    sub_9d8eb0();
    sub_9d87cc();
    sub_9d8eb0();
    sub_9d8fac();
    sub_9d90a8();
    sub_9d8db4();
    sub_9d8db4();
    sub_a2d4dc();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d4dc();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d4dc();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d4dc();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d4dc();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d1c4();
    sub_a2d4dc();
    sub_a2d4dc();
    sub_a2d4dc();
    sub_a2d4dc();
    sub_a2d4dc();
    return x0;
    __stack_chk_fail();
}
