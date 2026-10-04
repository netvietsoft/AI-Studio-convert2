// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbc3cb0
// Recovered Name: sub_bc3cb0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbc3cb0 | Size: 1384 bytes | SHA256: 6f877e2e9d94482f0da379871d12186597189d3a03846decf79a928b6ea92862
// Callers: 0 | Callees: 5 | Imports: 6

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   ";MEITU_AMBIENT_LIGHT_ADJUST"
//   ";MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"
//   ";MEITU_USE_GL_FragCoord"
//   ";MEITU_USE_HEAD_MASK_TEXTURE"
//   ";MEITU_USE_LUT_COLOR_RGB;MEITU_USE_LUT_TEXTURE_4x4"

void sub_bc3cb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 346 instructions
    /* 0xbc3cb0 */ stp x29, x30, [sp, #0x120];
    /* 0xbc3cb4 */ stp x28, x23, [sp, #0x130];
    /* 0xbc3cb8 */ stp x22, x21, [sp, #0x140];
    /* 0xbc3cbc */ stp x20, x19, [sp, #0x150];
    /* 0xbc3cc0 */ add x29, sp, #0x120;
    /* 0xbc3cc4 */ mrs x21, tpidr_el0;
    /* 0xbc3cc8 */ mov x20, x0;
    /* 0xbc3ccc */ adrp x1, #0x22f000;
    /* 0xbc3cd0 */ add x1, x1, #0xdd6;
    /* 0xbc3cd4 */ ldr x8, [x21, #0x28];
    /* 0xbc3cd8 */ add x0, sp, #0x38;
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_570f58();
    sub_5bccd0();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _Znwm();
    sub_a8ee98();
    _ZdlPv();
    _ZdlPv();
    sub_57688c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
