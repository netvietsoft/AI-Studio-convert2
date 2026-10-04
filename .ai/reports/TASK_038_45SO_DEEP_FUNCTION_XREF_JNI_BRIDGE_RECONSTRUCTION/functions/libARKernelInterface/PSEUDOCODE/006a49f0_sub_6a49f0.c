// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x6a49f0
// Recovered Name: sub_6a49f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6a49f0 | Size: 364 bytes | SHA256: 74f96b57ccb115e25eb848301ad2b52bc70a4dd6338b51638cfdf30d75ae557e
// Callers: 0 | Callees: 3 | Imports: 4

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   ";MEITU_AMBIENT_LIGHT_ADJUST"
//   ";MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"
//   ";MEITU_USE_HEAD_MASK_TEXTURE"
//   ";MEITU_USE_MAKEUP_ADAPT"
//   ";MEITU_USE_MATERIAL_TEXTURE"

void sub_6a49f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 91 instructions
    /* 0x6a49f0 */ stp x29, x30, [sp, #0x20];
    /* 0x6a49f4 */ str x23, [sp, #0x30];
    /* 0x6a49f8 */ stp x22, x21, [sp, #0x40];
    /* 0x6a49fc */ stp x20, x19, [sp, #0x50];
    /* 0x6a4a00 */ add x29, sp, #0x20;
    /* 0x6a4a04 */ mrs x22, tpidr_el0;
    /* 0x6a4a08 */ mov x20, x8;
    /* 0x6a4a0c */ mov x19, x0;
    /* 0x6a4a10 */ ldr x8, [x22, #0x28];
    /* 0x6a4a14 */ adrp x1, #0x1a7000;
    /* 0x6a4a18 */ add x1, x1, #0x98f;
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_c162e4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_6a472c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
