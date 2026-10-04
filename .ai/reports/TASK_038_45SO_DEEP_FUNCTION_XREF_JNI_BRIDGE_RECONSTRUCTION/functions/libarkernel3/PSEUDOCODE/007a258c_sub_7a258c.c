// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a258c
// Recovered Name: sub_7a258c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a258c | Size: 260 bytes | SHA256: 621a6dc0e70e0ddf62dd5fdcc61603a8668739805f6c0f95bb88611ca5f77a05
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::FluffyHairOption]"

void sub_7a258c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x7a258c */ stp x29, x30, [sp, #0x40];
    /* 0x7a2590 */ stp x22, x21, [sp, #0x50];
    /* 0x7a2594 */ stp x20, x19, [sp, #0x60];
    /* 0x7a2598 */ add x29, sp, #0x40;
    /* 0x7a259c */ mrs x22, tpidr_el0;
    /* 0x7a25a0 */ mov x21, x1;
    /* 0x7a25a4 */ mov x20, x0;
    /* 0x7a25a8 */ ldr x8, [x22, #0x28];
    /* 0x7a25ac */ stur x8, [x29, #-8];
    /* 0x7a25b0 */ adrp x8, #0x1da000;
    /* 0x7a25b4 */ add x8, x8, #0xecc;
    sub_655e30();
    _Znwm();
    sub_7a72f8();
    sub_6561ac();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
