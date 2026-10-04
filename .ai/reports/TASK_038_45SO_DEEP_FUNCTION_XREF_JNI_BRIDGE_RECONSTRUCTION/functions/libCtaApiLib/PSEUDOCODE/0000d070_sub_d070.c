// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xd070
// Recovered Name: sub_d070
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xd070 | Size: 2556 bytes | SHA256: ddcd18b3f80eb2027705bb5c8ccaa9cf26a0bd6a69d86fb9746345c8561a15df
// Callers: 0 | Callees: 8 | Imports: 3

// Calls external APIs: _Unwind_Resume, __stack_chk_fail, free
// Strings referenced:
//   "sfhio7er!@#$nnskl22"

void sub_d070(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 639 instructions
    /* 0xd070 */ stp x29, x30, [sp, #0x50];
    /* 0xd074 */ add x29, sp, #0x50;
    /* 0xd078 */ sub sp, sp, #0x260;
    /* 0xd07c */ mov x21, x8;
    /* 0xd080 */ mrs x8, tpidr_el0;
    /* 0xd084 */ ldr x8, [x8, #0x28];
    /* 0xd088 */ mov x20, x0;
    /* 0xd08c */ str x8, [sp, #0x28];
    sub_da6c();
    /* 0xd094 */ mov x19, x0;
    /* 0xd098 */ cbz x19, #0xd4c0;
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_27548();
    sub_2b41c();
    sub_2b41c();
    return x0;
    sub_dbd0();
    sub_dbd0();
    sub_dbd0();
    __stack_chk_fail();
    sub_dbd0();
    sub_25188();
    sub_dc70();
    sub_2bc70();
    free();
    sub_2c258();
    sub_2c258();
    sub_2c258();
    _Unwind_Resume();
    _Unwind_Resume();
}
