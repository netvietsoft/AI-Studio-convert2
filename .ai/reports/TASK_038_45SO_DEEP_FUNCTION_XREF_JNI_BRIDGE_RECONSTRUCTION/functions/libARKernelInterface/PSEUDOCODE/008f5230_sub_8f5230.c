// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8f5230
// Recovered Name: sub_8f5230
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8f5230 | Size: 2088 bytes | SHA256: 4c5fd3e1c09acad1bcb0d3a6f5ba47801dd32199661d9a4a54885a9365970094
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "FaceForehead"
//   "FluffyHair"
//   "Hairline"
//   "RoundHead"
//   "pNX"

void sub_8f5230(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 522 instructions
    /* 0x8f5230 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x8f5234 */ stp x28, x27, [sp, #0x10];
    /* 0x8f5238 */ stp x26, x25, [sp, #0x20];
    /* 0x8f523c */ stp x24, x23, [sp, #0x30];
    /* 0x8f5240 */ stp x22, x21, [sp, #0x40];
    /* 0x8f5244 */ stp x20, x19, [sp, #0x50];
    /* 0x8f5248 */ mov x29, sp;
    /* 0x8f524c */ sub sp, sp, #0x1c0;
    /* 0x8f5250 */ mrs x26, tpidr_el0;
    /* 0x8f5254 */ mov x19, x0;
    /* 0x8f5258 */ ldr x8, [x26, #0x28];
    sub_8dde24();
    sub_8ff968();
    sub_8ff970();
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
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_a048d8();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_a048d8();
    _ZdlPv();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
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
    return x0;
    __stack_chk_fail();
    sub_7593e8();
    sub_7593e8();
    sub_7593e8();
}
