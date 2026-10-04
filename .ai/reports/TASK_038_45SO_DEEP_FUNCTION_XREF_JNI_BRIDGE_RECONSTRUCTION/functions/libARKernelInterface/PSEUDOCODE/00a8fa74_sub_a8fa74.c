// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa8fa74
// Recovered Name: sub_a8fa74
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa8fa74 | Size: 720 bytes | SHA256: 9aacf4a56f15e26e324483a40931a7aeba0ea88b172d91d1e09c32eba87ce842
// Callers: 0 | Callees: 6 | Imports: 8

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_, _ZdlPv, __stack_chk_fail, memchr, memcmp
// Strings referenced:
//   ";MEITU_MASK_CHANNEL"
//   ";MEITU_USE_GL_EXT_shader_framebuffer_fetch"
//   ";MEITU_USE_MAKEUP_ADAPT"
//   ";MEITU_USE_MASK_TEXTURE"
//   ";MEITU_USE_MOUTH_SEGMENT_MASK_TEXTURE"

void sub_a8fa74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 180 instructions
    /* 0xa8fa74 */ stp x29, x30, [sp, #0x40];
    /* 0xa8fa78 */ stp x28, x27, [sp, #0x50];
    /* 0xa8fa7c */ stp x26, x25, [sp, #0x60];
    /* 0xa8fa80 */ stp x24, x23, [sp, #0x70];
    /* 0xa8fa84 */ stp x22, x21, [sp, #0x80];
    /* 0xa8fa88 */ stp x20, x19, [sp, #0x90];
    /* 0xa8fa8c */ add x29, sp, #0x40;
    /* 0xa8fa90 */ mrs x22, tpidr_el0;
    /* 0xa8fa94 */ mov x20, x0;
    /* 0xa8fa98 */ mov x19, x8;
    /* 0xa8fa9c */ ldr x9, [x22, #0x28];
    sub_570f58();
    sub_58f19c();
    memchr();
    memcmp();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_69add8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_69bc74();
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    sub_c36eb4();
    sub_69add8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_a8f2ec();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    return x0;
    __stack_chk_fail();
}
