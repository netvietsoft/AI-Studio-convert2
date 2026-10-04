// Library: libarkernel3.so
// Function ID: libarkernel3::0x9de778
// Recovered Name: sub_9de778
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9de778 | Size: 248 bytes | SHA256: 5a2e2bf490d0f6eda0c716f662d9111a9d7bd406390b1ec31ea25a6f9772625a
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_9de778(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x9de778 */ stp x29, x30, [sp, #0x110];
    /* 0x9de77c */ stp x28, x21, [sp, #0x120];
    /* 0x9de780 */ stp x20, x19, [sp, #0x130];
    /* 0x9de784 */ add x29, sp, #0x110;
    /* 0x9de788 */ mrs x20, tpidr_el0;
    /* 0x9de78c */ movi v0.2d, #0000000000000000;
    /* 0x9de790 */ adrp x9, #0x665000;
    /* 0x9de794 */ add x9, x9, #0xf80;
    /* 0x9de798 */ ldr x8, [x20, #0x28];
    /* 0x9de79c */ mov x19, x0;
    /* 0x9de7a0 */ mov x3, x2;
    sub_664ba4();
    sub_65616c();
    sub_a2d518();
    sub_664ce0();
    return x0;
    sub_664ce0();
    sub_65616c();
    sub_106b814();
    __stack_chk_fail();
}
