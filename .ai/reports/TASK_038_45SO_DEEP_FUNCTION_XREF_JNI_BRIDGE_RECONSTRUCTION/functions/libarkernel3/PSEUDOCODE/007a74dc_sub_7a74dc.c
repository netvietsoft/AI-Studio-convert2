// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a74dc
// Recovered Name: sub_7a74dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a74dc | Size: 416 bytes | SHA256: 079275c12f3b13c69be720a2a06fb142675c59cab40b191b009015a896b9f7a6
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FaceLiftFluffyHairPart::SliderControlParameter]"
//   "const char *utils::getClassUniqueString() [T = std::vector<mtlabar3::FaceLiftFluffyHairPart::SliderControlParameter>]"

void sub_7a74dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 104 instructions
    /* 0x7a74dc */ stp x29, x30, [sp, #0x60];
    /* 0x7a74e0 */ str x21, [sp, #0x70];
    /* 0x7a74e4 */ stp x20, x19, [sp, #0x80];
    /* 0x7a74e8 */ add x29, sp, #0x60;
    /* 0x7a74ec */ mrs x20, tpidr_el0;
    /* 0x7a74f0 */ mov x19, x8;
    /* 0x7a74f4 */ movi v0.2d, #0000000000000000;
    /* 0x7a74f8 */ ldr x8, [x20, #0x28];
    /* 0x7a74fc */ nop ;
    /* 0x7a7500 */ adr x9, #0x7a7640;
    /* 0x7a7504 */ stur x8, [x29, #-8];
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
