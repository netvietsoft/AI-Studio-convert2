// Library: libarkernel3.so
// Function ID: libarkernel3::0x666ce8
// Recovered Name: sub_666ce8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x666ce8 | Size: 256 bytes | SHA256: 7260a8c080bc0f54d42ab6873d2785f28e7240c86102612b45bc937b3d39b427
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_666ce8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x666ce8 */ stp x29, x30, [sp, #0x110];
    /* 0x666cec */ stp x28, x21, [sp, #0x120];
    /* 0x666cf0 */ stp x20, x19, [sp, #0x130];
    /* 0x666cf4 */ add x29, sp, #0x110;
    /* 0x666cf8 */ mrs x20, tpidr_el0;
    /* 0x666cfc */ movi v0.2d, #0000000000000000;
    /* 0x666d00 */ nop ;
    /* 0x666d04 */ adr x9, #0x665f80;
    /* 0x666d08 */ ldr x8, [x20, #0x28];
    /* 0x666d0c */ mov x19, x0;
    /* 0x666d10 */ mov x3, x2;
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
