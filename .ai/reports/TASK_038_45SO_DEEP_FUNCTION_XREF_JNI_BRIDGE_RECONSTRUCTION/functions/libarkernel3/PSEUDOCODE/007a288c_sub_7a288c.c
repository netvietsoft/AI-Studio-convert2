// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a288c
// Recovered Name: sub_7a288c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a288c | Size: 260 bytes | SHA256: 238bf23b80834edd31edaaab0ab03c52f5b6d993b05e0cdd105be14a29802c73
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FaceLiftFluffyHairPart]"

void sub_7a288c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x7a288c */ stp x29, x30, [sp, #0x40];
    /* 0x7a2890 */ stp x22, x21, [sp, #0x50];
    /* 0x7a2894 */ stp x20, x19, [sp, #0x60];
    /* 0x7a2898 */ add x29, sp, #0x40;
    /* 0x7a289c */ mrs x22, tpidr_el0;
    /* 0x7a28a0 */ mov x21, x1;
    /* 0x7a28a4 */ mov x20, x0;
    /* 0x7a28a8 */ ldr x8, [x22, #0x28];
    /* 0x7a28ac */ stur x8, [x29, #-8];
    /* 0x7a28b0 */ adrp x8, #0x1b8000;
    /* 0x7a28b4 */ add x8, x8, #0x75d;
    sub_655e30();
    _Znwm();
    sub_7a73e8();
    sub_6561ac();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
