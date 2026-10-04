// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x62420c
// Recovered Name: sub_62420c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x62420c | Size: 832 bytes | SHA256: 67f395a25b7f6fdad305e7867e0fcfb88f9749cfc8250b3c214f6541e68192bb
// Callers: 0 | Callees: 4 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "%d"
//   "(a,b)"
//   "(a,b)    "
//   ";BLEND_NUM %d"
//   ";MEITU_AMBIENT_LIGHT_ADJUST"

void sub_62420c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 208 instructions
    /* 0x62420c */ stp x29, x30, [sp, #0x100];
    /* 0x624210 */ stp x28, x27, [sp, #0x110];
    /* 0x624214 */ stp x26, x25, [sp, #0x120];
    /* 0x624218 */ stp x24, x23, [sp, #0x130];
    /* 0x62421c */ stp x22, x21, [sp, #0x140];
    /* 0x624220 */ stp x20, x19, [sp, #0x150];
    /* 0x624224 */ add x29, sp, #0x100;
    /* 0x624228 */ mov x19, x8;
    /* 0x62422c */ mrs x8, tpidr_el0;
    /* 0x624230 */ mov x20, x0;
    /* 0x624234 */ str x8, [sp, #8];
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_c162e4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_626f94();
    sub_624164();
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    sub_624164();
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
