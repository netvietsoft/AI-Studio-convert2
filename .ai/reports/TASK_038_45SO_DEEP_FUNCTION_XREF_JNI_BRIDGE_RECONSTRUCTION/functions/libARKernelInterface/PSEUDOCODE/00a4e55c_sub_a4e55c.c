// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa4e55c
// Recovered Name: sub_a4e55c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa4e55c | Size: 1428 bytes | SHA256: 76ef1c0ae256f4ecd1dd636a99af745d7da3b38118f09acbaa381a9f75e81691
// Callers: 0 | Callees: 16 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BlendFunc"
//   "DynamicOnePicture"
//   "DynamicRight"
//   "FabbyMaskType"
//   "FovY"

void sub_a4e55c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 357 instructions
    /* 0xa4e55c */ stp x29, x30, [sp, #0x40];
    /* 0xa4e560 */ str x27, [sp, #0x50];
    /* 0xa4e564 */ stp x26, x25, [sp, #0x60];
    /* 0xa4e568 */ stp x24, x23, [sp, #0x70];
    /* 0xa4e56c */ stp x22, x21, [sp, #0x80];
    /* 0xa4e570 */ stp x20, x19, [sp, #0x90];
    /* 0xa4e574 */ add x29, sp, #0x40;
    /* 0xa4e578 */ mrs x25, tpidr_el0;
    /* 0xa4e57c */ mov x21, x1;
    /* 0xa4e580 */ mov x20, x0;
    /* 0xa4e584 */ ldr x8, [x25, #0x28];
    sub_61bfa0();
    sub_5b7fa8();
    sub_5cb9b8();
    _ZdlPv();
    sub_5a8da0();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    sub_68c87c();
    sub_5789c8();
    sub_570f58();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    sub_5a8de8();
    sub_5a8de8();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5a8de8();
    sub_a4eaf0();
    sub_5a8cfc();
    sub_baa180();
    sub_a4f04c();
    sub_5a8cfc();
    sub_baa180();
    sub_59e3a4();
    return x0;
    __stack_chk_fail();
}
