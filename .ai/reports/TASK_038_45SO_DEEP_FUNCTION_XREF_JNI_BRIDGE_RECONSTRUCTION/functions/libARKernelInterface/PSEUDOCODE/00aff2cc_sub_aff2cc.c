// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xaff2cc
// Recovered Name: sub_aff2cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaff2cc | Size: 448 bytes | SHA256: 94bd22f358434226d3ca0cac5e1dce45b0d1eeba33275e6046677966555817b5
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%0.2f, %0.2f"
//   "%d, %d"
//   "DefaultSize"
//   "MaskBlurNumber"
//   "MaskBlurRange"

void sub_aff2cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 112 instructions
    /* 0xaff2cc */ stp x29, x30, [sp, #0xa0];
    /* 0xaff2d0 */ stp x22, x21, [sp, #0xb0];
    /* 0xaff2d4 */ stp x20, x19, [sp, #0xc0];
    /* 0xaff2d8 */ add x29, sp, #0xa0;
    /* 0xaff2dc */ mrs x22, tpidr_el0;
    /* 0xaff2e0 */ mov x19, x0;
    /* 0xaff2e4 */ mov x20, x1;
    /* 0xaff2e8 */ ldr x8, [x22, #0x28];
    /* 0xaff2ec */ stur x8, [x29, #-8];
    /* 0xaff2f0 */ ldr w8, [x0, #0x1e8];
    /* 0xaff2f4 */ cmp w8, #0x8c;
    sub_58f19c();
    _ZdlPv();
    sub_aff48c();
    sub_58f19c();
    _ZdlPv();
    sub_aff48c();
    sub_58f19c();
    _ZdlPv();
    sub_92d558();
    return x0;
    __stack_chk_fail();
}
