// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d89c8
// Recovered Name: sub_9d89c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d89c8 | Size: 248 bytes | SHA256: 9d992eb2aedb1899f6e5547d93f396f9d143e3d58074e990c9063233ba7b23f5
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_9d89c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x9d89c8 */ stp x29, x30, [sp, #0x110];
    /* 0x9d89cc */ stp x28, x21, [sp, #0x120];
    /* 0x9d89d0 */ stp x20, x19, [sp, #0x130];
    /* 0x9d89d4 */ add x29, sp, #0x110;
    /* 0x9d89d8 */ mrs x20, tpidr_el0;
    /* 0x9d89dc */ movi v0.2d, #0000000000000000;
    /* 0x9d89e0 */ adrp x9, #0x665000;
    /* 0x9d89e4 */ add x9, x9, #0xf80;
    /* 0x9d89e8 */ ldr x8, [x20, #0x28];
    /* 0x9d89ec */ mov x19, x0;
    /* 0x9d89f0 */ mov x3, x2;
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
