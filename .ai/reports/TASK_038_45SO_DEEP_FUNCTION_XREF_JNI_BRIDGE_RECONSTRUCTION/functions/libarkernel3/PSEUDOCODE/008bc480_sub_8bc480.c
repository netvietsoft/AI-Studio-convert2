// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bc480
// Recovered Name: sub_8bc480
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bc480 | Size: 248 bytes | SHA256: bbf7d2246fdec601eda821056a581c62b565cb730306cab818f88e45b94c0be1
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::HairBeautyType]"

void sub_8bc480(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x8bc480 */ stp x29, x30, [sp, #0x110];
    /* 0x8bc484 */ stp x28, x21, [sp, #0x120];
    /* 0x8bc488 */ stp x20, x19, [sp, #0x130];
    /* 0x8bc48c */ add x29, sp, #0x110;
    /* 0x8bc490 */ mrs x20, tpidr_el0;
    /* 0x8bc494 */ movi v0.2d, #0000000000000000;
    /* 0x8bc498 */ nop ;
    /* 0x8bc49c */ adr x9, #0x8c01d8;
    /* 0x8bc4a0 */ ldr x8, [x20, #0x28];
    /* 0x8bc4a4 */ mov x19, x0;
    /* 0x8bc4a8 */ mov x3, x2;
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
