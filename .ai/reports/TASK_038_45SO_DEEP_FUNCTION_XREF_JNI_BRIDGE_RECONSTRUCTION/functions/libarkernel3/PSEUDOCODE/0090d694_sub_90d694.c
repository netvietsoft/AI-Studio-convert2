// Library: libarkernel3.so
// Function ID: libarkernel3::0x90d694
// Recovered Name: sub_90d694
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90d694 | Size: 848 bytes | SHA256: e4522eb9f42c28921c344e6e34437c1130bc61e2a7e9cf52df3f2e41c18992e6
// Callers: 0 | Callees: 18 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   ";MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"
//   ";MEITU_USE_GL_EXT_shader_framebuffer_fetch"
//   ";MEITU_USE_MASK_TEXTURE"
//   ";MEITU_USE_MATERIAL_TEXTURE"
//   "EMPTY_DEFINED"

void sub_90d694(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 212 instructions
    /* 0x90d694 */ stp x29, x30, [sp, #0x50];
    /* 0x90d698 */ stp x24, x23, [sp, #0x60];
    /* 0x90d69c */ stp x22, x21, [sp, #0x70];
    /* 0x90d6a0 */ stp x20, x19, [sp, #0x80];
    /* 0x90d6a4 */ add x29, sp, #0x50;
    /* 0x90d6a8 */ mrs x23, tpidr_el0;
    /* 0x90d6ac */ adrp x9, #0x10cd000;
    /* 0x90d6b0 */ mov x21, x2;
    /* 0x90d6b4 */ ldr x8, [x23, #0x28];
    /* 0x90d6b8 */ ldr x9, [x9, #0x8e8];
    /* 0x90d6bc */ mov x20, x1;
    sub_aa2934();
    sub_cc62f4();
    sub_5604d4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_cccfe0();
    sub_a7fc58();
    sub_5604d4();
    sub_a7b280();
    sub_a7fc58();
    sub_5604d4();
    sub_a7b280();
    _ZdlPv();
    sub_9fed38();
    sub_9fed7c();
    sub_9fed7c();
    sub_9fed7c();
    sub_9fed7c();
    sub_9fed74();
    sub_9fed7c();
    sub_9fee78();
    sub_9fee80();
    sub_9fed6c();
    sub_9fee88();
    sub_aa3168();
    sub_9fee90();
    sub_9fed54();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_cc6028();
    sub_106b814();
    __stack_chk_fail();
}
