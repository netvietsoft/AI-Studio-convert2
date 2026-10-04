// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xcd90
// Recovered Name: sub_cd90
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xcd90 | Size: 716 bytes | SHA256: f0f9893657f7e3b8ab025fbfdb78a0b8031bb1d4eed8092ea29878d92408d1a3
// Callers: 0 | Callees: 6 | Imports: 3

// Calls external APIs: _Unwind_Resume, __stack_chk_fail, strlen
// Strings referenced:
//   "sfhio7er!@#$nnskl22"

void sub_cd90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 179 instructions
    /* 0xcd90 */ stp x29, x30, [sp, #0xa0];
    /* 0xcd94 */ add x29, sp, #0xa0;
    /* 0xcd98 */ mov x19, x8;
    /* 0xcd9c */ mrs x8, tpidr_el0;
    /* 0xcda0 */ ldr x8, [x8, #0x28];
    /* 0xcda4 */ mov x20, x0;
    /* 0xcda8 */ stur x8, [x29, #-0x38];
    sub_da6c();
    /* 0xcdb0 */ mov x22, x0;
    /* 0xcdb4 */ cbz x22, #0xce80;
    /* 0xcdb8 */ adrp x8, #0x62000;
    sub_27548();
    sub_27548();
    sub_2b41c();
    sub_2b41c();
    sub_dbd0();
    strlen();
    sub_2c0cc();
    return x0;
    __stack_chk_fail();
    sub_2c258();
    _Unwind_Resume();
    _Unwind_Resume();
}
