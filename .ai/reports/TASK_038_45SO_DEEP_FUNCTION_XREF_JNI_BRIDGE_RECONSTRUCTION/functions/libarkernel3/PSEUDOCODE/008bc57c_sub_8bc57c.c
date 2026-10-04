// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bc57c
// Recovered Name: sub_8bc57c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bc57c | Size: 528 bytes | SHA256: 0f6379d403ea9700f15f080d29cf7c1b944c280f40ef0d16ad80d106531ae046
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairPart]"
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupPart]"

void sub_8bc57c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x8bc57c */ stp x29, x30, [sp, #0x40];
    /* 0x8bc580 */ str x23, [sp, #0x50];
    /* 0x8bc584 */ stp x22, x21, [sp, #0x60];
    /* 0x8bc588 */ stp x20, x19, [sp, #0x70];
    /* 0x8bc58c */ add x29, sp, #0x40;
    /* 0x8bc590 */ mrs x22, tpidr_el0;
    /* 0x8bc594 */ mov x20, x1;
    /* 0x8bc598 */ mov x19, x0;
    /* 0x8bc59c */ ldr x8, [x22, #0x28];
    /* 0x8bc5a0 */ stur x8, [x29, #-8];
    /* 0x8bc5a4 */ adrp x8, #0x1da000;
    sub_655e30();
    sub_a2f61c();
    sub_655fa0();
    _ZdlPv();
    _Znwm();
    sub_8c01f0();
    sub_6561ac();
    _ZdlPv();
    return x0;
    sub_655f8c();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
