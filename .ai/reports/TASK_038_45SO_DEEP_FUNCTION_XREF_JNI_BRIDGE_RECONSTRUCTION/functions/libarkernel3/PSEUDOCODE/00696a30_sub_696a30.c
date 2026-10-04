// Library: libarkernel3.so
// Function ID: libarkernel3::0x696a30
// Recovered Name: sub_696a30
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x696a30 | Size: 256 bytes | SHA256: 8a9d559ed9775b16b337ac297d1409272bff791f8eb61500f5c312ff9523eef5
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_696a30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x696a30 */ stp x29, x30, [sp, #0x110];
    /* 0x696a34 */ stp x28, x21, [sp, #0x120];
    /* 0x696a38 */ stp x20, x19, [sp, #0x130];
    /* 0x696a3c */ add x29, sp, #0x110;
    /* 0x696a40 */ mrs x20, tpidr_el0;
    /* 0x696a44 */ movi v0.2d, #0000000000000000;
    /* 0x696a48 */ nop ;
    /* 0x696a4c */ adr x9, #0x665f80;
    /* 0x696a50 */ ldr x8, [x20, #0x28];
    /* 0x696a54 */ mov x19, x0;
    /* 0x696a58 */ mov x3, x2;
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
