// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x7db308
// Recovered Name: sub_7db308
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7db308 | Size: 7308 bytes | SHA256: 75ff3134839dd440611d8dbdaaeb10d2aee69cc598da37a4e0a99e9737f9a6df
// Callers: 0 | Callees: 11 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "ApexNasi"
//   "BabyFace"
//   "BeautyFaceTemple"
//   "BottomHalfOfFace"
//   "BrowHeadSpaceing"

void sub_7db308(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1827 instructions
    /* 0x7db308 */ stp x29, x30, [sp, #0x20];
    /* 0x7db30c */ stp x28, x27, [sp, #0x30];
    /* 0x7db310 */ stp x26, x25, [sp, #0x40];
    /* 0x7db314 */ stp x24, x23, [sp, #0x50];
    /* 0x7db318 */ stp x22, x21, [sp, #0x60];
    /* 0x7db31c */ stp x20, x19, [sp, #0x70];
    /* 0x7db320 */ add x29, sp, #0x20;
    /* 0x7db324 */ sub sp, sp, #1, lsl #12;
    /* 0x7db328 */ sub sp, sp, #0x710;
    /* 0x7db32c */ mrs x22, tpidr_el0;
    /* 0x7db330 */ mov x20, x0;
    sub_8dde24();
    sub_765020();
    sub_8e0920();
    sub_8e0920();
    sub_7fd248();
    sub_7f156c();
    sub_7f185c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_a048d8();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    sub_7593fc();
    _ZdlPv();
    sub_7f181c();
    return x0;
    sub_7593e8();
    __stack_chk_fail();
}
