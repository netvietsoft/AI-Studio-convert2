// Library: libarkernel3.so
// Function ID: libarkernel3::0x7591dc
// Recovered Name: sub_7591dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7591dc | Size: 248 bytes | SHA256: 8c2ce9d2e2f521779010142dad4ca184ecdb1fc99e4188029ef1232453743d09
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_7591dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x7591dc */ stp x29, x30, [sp, #0x110];
    /* 0x7591e0 */ stp x28, x21, [sp, #0x120];
    /* 0x7591e4 */ stp x20, x19, [sp, #0x130];
    /* 0x7591e8 */ add x29, sp, #0x110;
    /* 0x7591ec */ mrs x20, tpidr_el0;
    /* 0x7591f0 */ movi v0.2d, #0000000000000000;
    /* 0x7591f4 */ nop ;
    /* 0x7591f8 */ adr x9, #0x665f80;
    /* 0x7591fc */ ldr x8, [x20, #0x28];
    /* 0x759200 */ mov x19, x0;
    /* 0x759204 */ mov x3, x2;
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
