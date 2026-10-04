// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa6ea18
// Recovered Name: sub_a6ea18
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa6ea18 | Size: 4192 bytes | SHA256: 34a5cf647b0bdfdd49a16d639e5630856cf320103bf607b2423e0948d5c8f041
// Callers: 0 | Callees: 6 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "%.2f,%.2f,%.2f,%.2f"
//   "%.f,%.f,%.f"
//   "%.f,%.f,%.f,%.f"
//   "%.f,%.f,%.f,%.f,%.f"
//   "%d,%d"

void sub_a6ea18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1048 instructions
    /* 0xa6ea18 */ stp x29, x30, [sp, #0x148];
    /* 0xa6ea1c */ str x28, [sp, #0x158];
    /* 0xa6ea20 */ stp x24, x23, [sp, #0x160];
    /* 0xa6ea24 */ stp x22, x21, [sp, #0x170];
    /* 0xa6ea28 */ stp x20, x19, [sp, #0x180];
    /* 0xa6ea2c */ add x29, sp, #0x148;
    /* 0xa6ea30 */ mrs x24, tpidr_el0;
    /* 0xa6ea34 */ mov x19, x0;
    /* 0xa6ea38 */ mov x20, x1;
    /* 0xa6ea3c */ ldr x8, [x24, #0x28];
    /* 0xa6ea40 */ stur x8, [x29, #-0x10];
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    _Znwm();
    sub_58f19c();
    sub_6904cc();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    _Znwm();
    sub_58f19c();
    sub_6904cc();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_6904cc();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    _Znwm();
    sub_58f19c();
    sub_68fe74();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_a1925c();
    sub_a6fa78();
    sub_58f19c();
    _ZdlPv();
    sub_61d798();
    return x0;
    __stack_chk_fail();
}
