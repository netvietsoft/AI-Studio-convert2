// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x784d14
// Recovered Name: sub_784d14
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x784d14 | Size: 2368 bytes | SHA256: dd5645951d9e22b05aa240a19ac321e2e2ed6bfe7c6b5c5c126d34df60c44f4e
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BLEND_MODE_ADD"
//   "BLEND_MODE_COLOR"
//   "BLEND_MODE_COLOR_BURN"
//   "BLEND_MODE_COLOR_DODGE"
//   "BLEND_MODE_DARKEN"

void sub_784d14(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 592 instructions
    /* 0x784d14 */ stp x29, x30, [sp, #0x40];
    /* 0x784d18 */ str x21, [sp, #0x50];
    /* 0x784d1c */ stp x20, x19, [sp, #0x60];
    /* 0x784d20 */ add x29, sp, #0x40;
    /* 0x784d24 */ mrs x20, tpidr_el0;
    /* 0x784d28 */ mov x19, x0;
    /* 0x784d2c */ add x21, x0, #0x950;
    /* 0x784d30 */ ldr x8, [x20, #0x28];
    /* 0x784d34 */ stur x8, [x29, #-8];
    /* 0x784d38 */ ldr x1, [x0, #0x950];
    /* 0x784d3c */ add x0, x0, #0x948;
    sub_57688c();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    sub_58f19c();
    sub_58f19c();
    sub_61467c();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
