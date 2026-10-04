// Library: libarkernel3.so
// Function ID: libarkernel3::0x8c02e8
// Recovered Name: sub_8c02e8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8c02e8 | Size: 408 bytes | SHA256: eb6ee31c5d18a8bc59bcda13683b3f93396c2f96347b84d201394528d1a68348
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairPart::HairDict]"
//   "const char *utils::getClassUniqueString() [T = std::vector<mtlabar3::MakeupHairPart::HairDict>]"

void sub_8c02e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 102 instructions
    /* 0x8c02e8 */ stp x29, x30, [sp, #0x60];
    /* 0x8c02ec */ str x21, [sp, #0x70];
    /* 0x8c02f0 */ stp x20, x19, [sp, #0x80];
    /* 0x8c02f4 */ add x29, sp, #0x60;
    /* 0x8c02f8 */ mrs x20, tpidr_el0;
    /* 0x8c02fc */ mov x19, x8;
    /* 0x8c0300 */ movi v0.2d, #0000000000000000;
    /* 0x8c0304 */ ldr x8, [x20, #0x28];
    /* 0x8c0308 */ nop ;
    /* 0x8c030c */ adr x9, #0x8c044c;
    /* 0x8c0310 */ stur x8, [x29, #-8];
    _Znwm();
    sub_65616c();
    sub_65616c();
    sub_65616c();
    return x0;
    sub_65616c();
    sub_65616c();
    sub_106b814();
    __stack_chk_fail();
    return x0;
    return x0;
    return x0;
}
