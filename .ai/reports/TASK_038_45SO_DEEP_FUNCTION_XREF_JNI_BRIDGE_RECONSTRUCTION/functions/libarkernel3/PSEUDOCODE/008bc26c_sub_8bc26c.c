// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bc26c
// Recovered Name: sub_8bc26c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bc26c | Size: 528 bytes | SHA256: 8f94ea7a71ab384945529103a79801f8b6256c3565d8dd19df8bcfec9153b46e
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupCommonDict]"
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairPart::HairDict]"

void sub_8bc26c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x8bc26c */ stp x29, x30, [sp, #0x40];
    /* 0x8bc270 */ str x23, [sp, #0x50];
    /* 0x8bc274 */ stp x22, x21, [sp, #0x60];
    /* 0x8bc278 */ stp x20, x19, [sp, #0x70];
    /* 0x8bc27c */ add x29, sp, #0x40;
    /* 0x8bc280 */ mrs x22, tpidr_el0;
    /* 0x8bc284 */ mov x20, x1;
    /* 0x8bc288 */ mov x19, x0;
    /* 0x8bc28c */ ldr x8, [x22, #0x28];
    /* 0x8bc290 */ stur x8, [x29, #-8];
    /* 0x8bc294 */ adrp x8, #0x248000;
    sub_655e30();
    sub_a2f61c();
    sub_655fa0();
    _ZdlPv();
    _Znwm();
    sub_8c00e4();
    sub_6561ac();
    _ZdlPv();
    return x0;
    sub_655f8c();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
