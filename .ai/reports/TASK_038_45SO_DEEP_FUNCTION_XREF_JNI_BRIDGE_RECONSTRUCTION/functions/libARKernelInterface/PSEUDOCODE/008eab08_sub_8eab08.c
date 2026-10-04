// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8eab08
// Recovered Name: sub_8eab08
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8eab08 | Size: 1448 bytes | SHA256: 56d486e706435866c055b41a4f29f15bf85d18a875264bae5ffd7a1514606551
// Callers: 0 | Callees: 7 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, memmove
// Strings referenced:
//   "BlusherColor"
//   "HairBeautyAlpha"
//   "pNX"

void sub_8eab08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 362 instructions
    /* 0x8eab08 */ stp x29, x30, [sp, #0x140];
    /* 0x8eab0c */ stp x28, x27, [sp, #0x150];
    /* 0x8eab10 */ stp x26, x25, [sp, #0x160];
    /* 0x8eab14 */ stp x24, x23, [sp, #0x170];
    /* 0x8eab18 */ stp x22, x21, [sp, #0x180];
    /* 0x8eab1c */ stp x20, x19, [sp, #0x190];
    /* 0x8eab20 */ add x29, sp, #0x140;
    /* 0x8eab24 */ mrs x28, tpidr_el0;
    /* 0x8eab28 */ mov x20, x0;
    /* 0x8eab2c */ ldr x8, [x28, #0x28];
    /* 0x8eab30 */ stur x8, [x29, #-0x20];
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
