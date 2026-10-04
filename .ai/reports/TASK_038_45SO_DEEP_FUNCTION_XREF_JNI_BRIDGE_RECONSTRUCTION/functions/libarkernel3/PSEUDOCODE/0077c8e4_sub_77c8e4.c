// Library: libarkernel3.so
// Function ID: libarkernel3::0x77c8e4
// Recovered Name: sub_77c8e4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x77c8e4 | Size: 440 bytes | SHA256: e57d0bd5f856fe11155af3194a4840cbcd763b1bf6723c37eb10d18925af5216
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"
//   "const char *utils::getClassUniqueString() [T = std::vector<mtlabar3::SegmentMaskType>]"

void sub_77c8e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 110 instructions
    /* 0x77c8e4 */ stp x29, x30, [sp, #0x60];
    /* 0x77c8e8 */ str x21, [sp, #0x70];
    /* 0x77c8ec */ stp x20, x19, [sp, #0x80];
    /* 0x77c8f0 */ add x29, sp, #0x60;
    /* 0x77c8f4 */ mrs x20, tpidr_el0;
    /* 0x77c8f8 */ mov x19, x8;
    /* 0x77c8fc */ nop ;
    /* 0x77c900 */ adr x9, #0x77ca4c;
    /* 0x77c904 */ ldr x8, [x20, #0x28];
    /* 0x77c908 */ movi v0.2d, #0000000000000000;
    /* 0x77c90c */ stur x8, [x29, #-8];
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
    return x0;
}
