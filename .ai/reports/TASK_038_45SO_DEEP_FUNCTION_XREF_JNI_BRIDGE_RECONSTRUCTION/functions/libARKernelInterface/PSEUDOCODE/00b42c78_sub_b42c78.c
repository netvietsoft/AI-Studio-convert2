// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb42c78
// Recovered Name: sub_b42c78
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb42c78 | Size: 6016 bytes | SHA256: 45bf3567b1f4fc652115bfba89848d72fb56286851b8feed0c596d300e1089ce
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "Alpha"
//   "AnimalMirrorH"
//   "AnimalMirrorV"
//   "AnimalOffset"
//   "AnimalRotate"

void sub_b42c78(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1504 instructions
    /* 0xb42c78 */ stp x29, x30, [sp, #0x50];
    /* 0xb42c7c */ stp x24, x23, [sp, #0x60];
    /* 0xb42c80 */ stp x22, x21, [sp, #0x70];
    /* 0xb42c84 */ stp x20, x19, [sp, #0x80];
    /* 0xb42c88 */ add x29, sp, #0x50;
    /* 0xb42c8c */ mrs x23, tpidr_el0;
    /* 0xb42c90 */ mov x19, x0;
    /* 0xb42c94 */ mov x20, x1;
    /* 0xb42c98 */ ldr x8, [x23, #0x28];
    /* 0xb42c9c */ stur x8, [x29, #-8];
    /* 0xb42ca0 */ ldr w8, [x0, #0x1e8];
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    sub_691180();
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _Znwm();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_61d798();
    return x0;
    sub_59c568();
    __stack_chk_fail();
    sub_59c568();
    sub_59c568();
}
