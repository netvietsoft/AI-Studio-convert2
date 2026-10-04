// Library: libarkernel3.so
// Function ID: libarkernel3::0x883444
// Recovered Name: sub_883444
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x883444 | Size: 1200 bytes | SHA256: 4bb0595c9835fb0bd69c58043c81d91c5ee219b67e91061ff1f80e37ccc04375
// Callers: 0 | Callees: 4 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __cxa_atexit, __stack_chk_fail
// Strings referenced:
//   "BlendAdd"
//   "BlendAverage"
//   "BlendColorBurn"
//   "BlendColorDodge"
//   "BlendDarken"

void sub_883444(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 300 instructions
    /* 0x883444 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x883448 */ stp x28, x23, [sp, #0x10];
    /* 0x88344c */ stp x22, x21, [sp, #0x20];
    /* 0x883450 */ stp x20, x19, [sp, #0x30];
    /* 0x883454 */ mov x29, sp;
    /* 0x883458 */ sub sp, sp, #0x230;
    /* 0x88345c */ adrp x8, #0x289000;
    /* 0x883460 */ mrs x21, tpidr_el0;
    /* 0x883464 */ adrp x9, #0x1111000;
    /* 0x883468 */ add x9, x9, #0x6a0;
    /* 0x88346c */ ldr q0, [x8, #0x4f0];
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    sub_5604d4();
    _Znwm();
    sub_63b9dc();
    _ZdlPv();
    __cxa_atexit();
    return x0;
    sub_5687b4();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
