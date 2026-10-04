// Library: libarkernel3.so
// Function ID: libarkernel3::0x8c17dc
// Recovered Name: sub_8c17dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8c17dc | Size: 528 bytes | SHA256: 4d080973214dd78931dbd2f5318980c37790fa27a858bb4ff052cd40bfa41991
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupHairSoftPart]"
//   "const char *utils::getClassUniqueString() [T = mtlabar3::MakeupPart]"

void sub_8c17dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 132 instructions
    /* 0x8c17dc */ stp x29, x30, [sp, #0x40];
    /* 0x8c17e0 */ str x23, [sp, #0x50];
    /* 0x8c17e4 */ stp x22, x21, [sp, #0x60];
    /* 0x8c17e8 */ stp x20, x19, [sp, #0x70];
    /* 0x8c17ec */ add x29, sp, #0x40;
    /* 0x8c17f0 */ mrs x22, tpidr_el0;
    /* 0x8c17f4 */ mov x20, x1;
    /* 0x8c17f8 */ mov x19, x0;
    /* 0x8c17fc */ ldr x8, [x22, #0x28];
    /* 0x8c1800 */ stur x8, [x29, #-8];
    /* 0x8c1804 */ adrp x8, #0x1fe000;
    sub_655e30();
    sub_a2f61c();
    sub_655fa0();
    _ZdlPv();
    _Znwm();
    sub_8c30b0();
    sub_6561ac();
    _ZdlPv();
    return x0;
    sub_655f8c();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
