// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a2c68
// Recovered Name: sub_7a2c68
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a2c68 | Size: 244 bytes | SHA256: c7ddeaeac5e3c58df5045c62724eccb5a3c88258eeeee9f749f16c3281eae84b
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FluffyHairOption]"

void sub_7a2c68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 61 instructions
    /* 0x7a2c68 */ stp x29, x30, [sp, #0x110];
    /* 0x7a2c6c */ stp x28, x21, [sp, #0x120];
    /* 0x7a2c70 */ stp x20, x19, [sp, #0x130];
    /* 0x7a2c74 */ add x29, sp, #0x110;
    /* 0x7a2c78 */ mrs x20, tpidr_el0;
    /* 0x7a2c7c */ movi v0.2d, #0000000000000000;
    /* 0x7a2c80 */ nop ;
    /* 0x7a2c84 */ adr x9, #0x7a73dc;
    /* 0x7a2c88 */ ldr x8, [x20, #0x28];
    /* 0x7a2c8c */ mov x19, x0;
    /* 0x7a2c90 */ mov x3, x2;
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
