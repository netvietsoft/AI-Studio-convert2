// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa93488
// Recovered Name: sub_a93488
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa93488 | Size: 2368 bytes | SHA256: 2616774ffa9e857c44d2da00ae733819974e68b257d1ca69c5ca8b0d34c4f496
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BLEND_MODE_ADD"
//   "BLEND_MODE_COLOR"
//   "BLEND_MODE_COLOR_BURN"
//   "BLEND_MODE_COLOR_DODGE"
//   "BLEND_MODE_DARKEN"

void sub_a93488(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 592 instructions
    /* 0xa93488 */ stp x29, x30, [sp, #0x40];
    /* 0xa9348c */ str x21, [sp, #0x50];
    /* 0xa93490 */ stp x20, x19, [sp, #0x60];
    /* 0xa93494 */ add x29, sp, #0x40;
    /* 0xa93498 */ mrs x20, tpidr_el0;
    /* 0xa9349c */ mov x19, x0;
    /* 0xa934a0 */ add x21, x0, #0xa88;
    /* 0xa934a4 */ ldr x8, [x20, #0x28];
    /* 0xa934a8 */ stur x8, [x29, #-8];
    /* 0xa934ac */ ldr x1, [x0, #0xa88];
    /* 0xa934b0 */ add x0, x0, #0xa80;
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
