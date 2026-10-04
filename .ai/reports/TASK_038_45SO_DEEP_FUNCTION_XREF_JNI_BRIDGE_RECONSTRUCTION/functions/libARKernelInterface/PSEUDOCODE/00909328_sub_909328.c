// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x909328
// Recovered Name: sub_909328
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x909328 | Size: 3344 bytes | SHA256: 3a8659ed7dabea618430ccf38cd4645c5d988537bf2e8cf07bbf548c2b74c75d
// Callers: 0 | Callees: 5 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "0F"
//   "EnableSmallFaceReduceAlpha"
//   "HairSoftAlpha"
//   "HairSoftAlphaSecond"
//   "MergesrcAlpha"

void sub_909328(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 836 instructions
    /* 0x909328 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x90932c */ stp x28, x27, [sp, #0x10];
    /* 0x909330 */ stp x26, x25, [sp, #0x20];
    /* 0x909334 */ stp x24, x23, [sp, #0x30];
    /* 0x909338 */ stp x22, x21, [sp, #0x40];
    /* 0x90933c */ stp x20, x19, [sp, #0x50];
    /* 0x909340 */ mov x29, sp;
    /* 0x909344 */ sub sp, sp, #0x1b0;
    /* 0x909348 */ mrs x24, tpidr_el0;
    /* 0x90934c */ mov x19, x0;
    /* 0x909350 */ ldr x8, [x24, #0x28];
    sub_8dde54();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_a045fc();
    sub_58f19c();
    _ZdlPv();
    sub_58f19c();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    return x0;
    sub_7593e8();
    __stack_chk_fail();
}
