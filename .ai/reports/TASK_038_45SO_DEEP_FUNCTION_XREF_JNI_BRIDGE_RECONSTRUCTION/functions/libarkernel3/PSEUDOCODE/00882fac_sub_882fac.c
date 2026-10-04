// Library: libarkernel3.so
// Function ID: libarkernel3::0x882fac
// Recovered Name: sub_882fac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x882fac | Size: 764 bytes | SHA256: a2042be4da542beb41f6afc80dc15b383211b7ae8b061c2d97c8cddb38826903
// Callers: 0 | Callees: 8 | Imports: 6

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc, _ZNSt6__ndk19to_stringEm, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   ";BLEND_NUM "
//   ";MEITU_AMBIENT_LIGHT_ADJUST"
//   ";MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"
//   ";MEITU_USE_MAKEUP_ADAPT"
//   ";definedBlend%zu(a,b) %s(a,b)"

void sub_882fac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 191 instructions
    /* 0x882fac */ stp x29, x30, [sp, #0x140];
    /* 0x882fb0 */ stp x28, x27, [sp, #0x150];
    /* 0x882fb4 */ stp x26, x25, [sp, #0x160];
    /* 0x882fb8 */ stp x24, x23, [sp, #0x170];
    /* 0x882fbc */ stp x22, x21, [sp, #0x180];
    /* 0x882fc0 */ stp x20, x19, [sp, #0x190];
    /* 0x882fc4 */ add x29, sp, #0x140;
    /* 0x882fc8 */ mrs x25, tpidr_el0;
    /* 0x882fcc */ mov x19, x8;
    /* 0x882fd0 */ mov x20, x0;
    /* 0x882fd4 */ ldr x8, [x25, #0x28];
    sub_5604d4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_aa2a10();
    sub_aa1c78();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_86d604();
    sub_8832a8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZdlPv();
    _ZNSt6__ndk19to_stringEm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    sub_881e90();
    sub_cccfe0();
    sub_5604d4();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
