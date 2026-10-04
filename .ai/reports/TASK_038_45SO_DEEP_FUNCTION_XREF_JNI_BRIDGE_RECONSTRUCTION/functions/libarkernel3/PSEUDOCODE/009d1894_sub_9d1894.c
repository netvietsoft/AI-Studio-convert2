// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d1894
// Recovered Name: sub_9d1894
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d1894 | Size: 248 bytes | SHA256: dcb16442627fe96169d683cbc600cfa765c7059ea574d548d030e37bddd3a6fe
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_9d1894(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x9d1894 */ stp x29, x30, [sp, #0x110];
    /* 0x9d1898 */ stp x28, x21, [sp, #0x120];
    /* 0x9d189c */ stp x20, x19, [sp, #0x130];
    /* 0x9d18a0 */ add x29, sp, #0x110;
    /* 0x9d18a4 */ mrs x20, tpidr_el0;
    /* 0x9d18a8 */ movi v0.2d, #0000000000000000;
    /* 0x9d18ac */ adrp x9, #0x665000;
    /* 0x9d18b0 */ add x9, x9, #0xf80;
    /* 0x9d18b4 */ ldr x8, [x20, #0x28];
    /* 0x9d18b8 */ mov x19, x0;
    /* 0x9d18bc */ mov x3, x2;
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
