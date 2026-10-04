// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xcb38
// Recovered Name: sub_cb38
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xcb38 | Size: 584 bytes | SHA256: 54878ac8a30a5250e30a151521df9de9b25dae1163759259cecf2ed23263e238
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _Unwind_Resume, __stack_chk_fail

void sub_cb38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 146 instructions
    /* 0xcb38 */ stp x29, x30, [sp, #0x30];
    /* 0xcb3c */ add x29, sp, #0x30;
    /* 0xcb40 */ mov x19, x8;
    /* 0xcb44 */ mrs x8, tpidr_el0;
    /* 0xcb48 */ ldr x8, [x8, #0x28];
    /* 0xcb4c */ mov x20, x0;
    /* 0xcb50 */ str x8, [sp, #0x18];
    /* 0xcb54 */ add x8, sp, #8;
    sub_cd80();
    /* 0xcb5c */ mov x8, sp;
    /* 0xcb60 */ mov x0, x20;
    sub_d05c();
    sub_2c390();
    sub_2ba38();
    return x0;
    sub_2c258();
    sub_2c258();
    __stack_chk_fail();
    sub_2c258();
    sub_2c258();
    sub_2c258();
    _Unwind_Resume();
}
