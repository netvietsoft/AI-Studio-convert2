// Library: libarkernel3.so
// Function ID: libarkernel3::0x777ac8
// Recovered Name: sub_777ac8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x777ac8 | Size: 248 bytes | SHA256: 232d648a9c828a55dc0d5712ed65f7f702d54ee78144f2df28df6a5b3083fdd2
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_777ac8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x777ac8 */ stp x29, x30, [sp, #0x110];
    /* 0x777acc */ stp x28, x21, [sp, #0x120];
    /* 0x777ad0 */ stp x20, x19, [sp, #0x130];
    /* 0x777ad4 */ add x29, sp, #0x110;
    /* 0x777ad8 */ mrs x20, tpidr_el0;
    /* 0x777adc */ movi v0.2d, #0000000000000000;
    /* 0x777ae0 */ adrp x9, #0x665000;
    /* 0x777ae4 */ add x9, x9, #0xf80;
    /* 0x777ae8 */ ldr x8, [x20, #0x28];
    /* 0x777aec */ mov x19, x0;
    /* 0x777af0 */ mov x3, x2;
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
