// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a20d4
// Recovered Name: sub_7a20d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a20d4 | Size: 260 bytes | SHA256: 35869e89ecee678d93c48136c6a67b90fdd7906a726f8e7df055940774cfe030
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FaceLiftFluffyHairPart::SliderControlParameter]"

void sub_7a20d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x7a20d4 */ stp x29, x30, [sp, #0x40];
    /* 0x7a20d8 */ stp x22, x21, [sp, #0x50];
    /* 0x7a20dc */ stp x20, x19, [sp, #0x60];
    /* 0x7a20e0 */ add x29, sp, #0x40;
    /* 0x7a20e4 */ mrs x22, tpidr_el0;
    /* 0x7a20e8 */ mov x21, x1;
    /* 0x7a20ec */ mov x20, x0;
    /* 0x7a20f0 */ ldr x8, [x22, #0x28];
    /* 0x7a20f4 */ stur x8, [x29, #-8];
    /* 0x7a20f8 */ adrp x8, #0x1a1000;
    /* 0x7a20fc */ add x8, x8, #0xb5b;
    sub_655e30();
    _Znwm();
    sub_7a7208();
    sub_6561ac();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
