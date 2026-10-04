// Library: libarkernel3.so
// Function ID: libarkernel3::0x5fac5c
// Recovered Name: sub_5fac5c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5fac5c | Size: 740 bytes | SHA256: 391a234b627a62b768c06ac3c17f26f3ace6281cc5279fe62c5790e18dd9f6e5
// Callers: 0 | Callees: 26 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "an scale mask frame buffer."
//   "segment mask edge"

void sub_5fac5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 185 instructions
    /* 0x5fac5c */ stp x29, x30, [sp, #0x28];
    /* 0x5fac60 */ str x27, [sp, #0x38];
    /* 0x5fac64 */ stp x26, x25, [sp, #0x40];
    /* 0x5fac68 */ stp x24, x23, [sp, #0x50];
    /* 0x5fac6c */ stp x22, x21, [sp, #0x60];
    /* 0x5fac70 */ stp x20, x19, [sp, #0x70];
    /* 0x5fac74 */ add x29, sp, #0x28;
    /* 0x5fac78 */ mrs x27, tpidr_el0;
    /* 0x5fac7c */ mov x21, x0;
    /* 0x5fac80 */ ldr x8, [x27, #0x28];
    /* 0x5fac84 */ stur x8, [x29, #-0x10];
    sub_5f722c();
    sub_d7c64c();
    sub_d7d420();
    sub_aa2a10();
    sub_aa192c();
    sub_e3bf28();
    sub_e3b56c();
    sub_e3b574();
    sub_a7fc40();
    sub_5aa23c();
    sub_e3ac50();
    sub_e1f07c();
    sub_d7ad58();
    sub_d7ae98();
    sub_d7b0fc();
    sub_e16e04();
    sub_e1738c();
    sub_e16cc8();
    sub_e16cc8();
    sub_aa2a10();
    sub_aa192c();
    sub_e16ca8();
    sub_e3b56c();
    sub_e3b574();
    sub_d93424();
    sub_e17544();
    sub_f6789c();
    sub_f678d8();
    sub_e16cc8();
    sub_e16cc8();
    sub_5ab304();
    return x0;
    sub_562d14();
    sub_5ab304();
    sub_106b814();
    __stack_chk_fail();
}
