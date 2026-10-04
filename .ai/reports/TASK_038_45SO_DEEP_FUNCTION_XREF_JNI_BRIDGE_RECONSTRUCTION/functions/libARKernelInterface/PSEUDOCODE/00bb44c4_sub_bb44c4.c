// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbb44c4
// Recovered Name: sub_bb44c4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbb44c4 | Size: 784 bytes | SHA256: db94bd447a8b55886f2452dfba262babaeaba9f9c1387b65221ae685b8295153
// Callers: 0 | Callees: 3 | Imports: 2

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, __stack_chk_fail
// Strings referenced:
//   "Multiply"
//   "Normal"
//   "Screen"
//   "Softlight"

void sub_bb44c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 196 instructions
    /* 0xbb44c4 */ stp x29, x30, [sp, #0x40];
    /* 0xbb44c8 */ stp x28, x27, [sp, #0x50];
    /* 0xbb44cc */ stp x26, x25, [sp, #0x60];
    /* 0xbb44d0 */ stp x24, x23, [sp, #0x70];
    /* 0xbb44d4 */ stp x22, x21, [sp, #0x80];
    /* 0xbb44d8 */ stp x20, x19, [sp, #0x90];
    /* 0xbb44dc */ add x29, sp, #0x40;
    /* 0xbb44e0 */ movi v0.2d, #0000000000000000;
    /* 0xbb44e4 */ mrs x25, tpidr_el0;
    /* 0xbb44e8 */ adrp x24, #0x2ee000;
    /* 0xbb44ec */ add x24, x24, #0x179;
    sub_bb49d0();
    sub_bb49d0();
    sub_bb49d0();
    sub_bb49d0();
    sub_bb49d0();
    sub_bb49d0();
    sub_bb54f8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_bb54f8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_bb54f8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_bb54f8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_bb54a8();
    return x0;
    __stack_chk_fail();
}
