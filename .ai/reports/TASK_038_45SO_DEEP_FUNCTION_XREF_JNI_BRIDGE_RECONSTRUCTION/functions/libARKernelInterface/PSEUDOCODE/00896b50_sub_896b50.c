// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x896b50
// Recovered Name: sub_896b50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x896b50 | Size: 1508 bytes | SHA256: 74c0813d40face96b56eeeaa116342e6de1bbaf0851380e2b2c983d740e92e77
// Callers: 0 | Callees: 9 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, memmove
// Strings referenced:
//   "HairBeautyAlpha"
//   "HairBeautyColor"
//   "pNX"

void sub_896b50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 377 instructions
    /* 0x896b50 */ stp x29, x30, [sp, #0x10];
    /* 0x896b54 */ stp x28, x27, [sp, #0x20];
    /* 0x896b58 */ stp x26, x25, [sp, #0x30];
    /* 0x896b5c */ stp x24, x23, [sp, #0x40];
    /* 0x896b60 */ stp x22, x21, [sp, #0x50];
    /* 0x896b64 */ stp x20, x19, [sp, #0x60];
    /* 0x896b68 */ add x29, sp, #0x10;
    /* 0x896b6c */ sub sp, sp, #0x650;
    /* 0x896b70 */ mrs x28, tpidr_el0;
    /* 0x896b74 */ mov x20, x0;
    /* 0x896b78 */ ldr x8, [x28, #0x28];
    sub_8dde24();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_a048d8();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _Znwm();
    sub_625e08();
    sub_623544();
    sub_59ca20();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_a04444();
    sub_59ca20();
    memmove();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_59ca20();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
    sub_7593e8();
}
