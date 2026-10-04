// Library: libarkernel3.so
// Function ID: libarkernel3::0x661548
// Recovered Name: sub_661548
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x661548 | Size: 256 bytes | SHA256: 646fcb164ab866b918f77f322b175d02b46018ce2be7ece69a5b0be123de7109
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_661548(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x661548 */ stp x29, x30, [sp, #0x110];
    /* 0x66154c */ stp x28, x21, [sp, #0x120];
    /* 0x661550 */ stp x20, x19, [sp, #0x130];
    /* 0x661554 */ add x29, sp, #0x110;
    /* 0x661558 */ mrs x20, tpidr_el0;
    /* 0x66155c */ movi v0.2d, #0000000000000000;
    /* 0x661560 */ nop ;
    /* 0x661564 */ adr x9, #0x665f80;
    /* 0x661568 */ ldr x8, [x20, #0x28];
    /* 0x66156c */ mov x19, x0;
    /* 0x661570 */ mov x3, x2;
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
