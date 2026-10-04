// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x625034
// Recovered Name: sub_625034
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x625034 | Size: 604 bytes | SHA256: 79d7af49dae86dd993eaff2cc421acdae576094f5d314f30a68fd702a37a3109
// Callers: 0 | Callees: 2 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __cxa_atexit, __stack_chk_fail
// Strings referenced:
//   "BlendAdd"
//   "BlendAverage"
//   "BlendColorBurn"
//   "BlendColorDodge"
//   "BlendDarken"

void sub_625034(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 151 instructions
    /* 0x625034 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x625038 */ str x28, [sp, #0x10];
    /* 0x62503c */ stp x22, x21, [sp, #0x20];
    /* 0x625040 */ stp x20, x19, [sp, #0x30];
    /* 0x625044 */ mov x29, sp;
    /* 0x625048 */ sub sp, sp, #0x220;
    /* 0x62504c */ mrs x20, tpidr_el0;
    /* 0x625050 */ adrp x1, #0x1f2000;
    /* 0x625054 */ add x1, x1, #0x11a;
    /* 0x625058 */ ldr x8, [x20, #0x28];
    /* 0x62505c */ add x0, sp, #8;
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_570f58();
    _ZdlPv();
    __cxa_atexit();
    return x0;
    __stack_chk_fail();
}
