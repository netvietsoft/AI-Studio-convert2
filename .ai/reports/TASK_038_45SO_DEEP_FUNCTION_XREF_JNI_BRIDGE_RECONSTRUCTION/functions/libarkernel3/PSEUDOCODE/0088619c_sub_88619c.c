// Library: libarkernel3.so
// Function ID: libarkernel3::0x88619c
// Recovered Name: sub_88619c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x88619c | Size: 1260 bytes | SHA256: e4e57bcdd3e05fc2b15e460bc8c8f12de2252a02ff25124b9e7ea8787812f4ab
// Callers: 0 | Callees: 11 | Imports: 8

// Calls external APIs: _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc, _ZNSt6__ndk19to_stringEm, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   ";DIRECTIONAL_LIGHT"
//   ";LIGHT_COUNT "
//   ";POINT_LIGHT"
//   ";POINT_LIGHT_COUNT "
//   "RENDER;FACE_SEGMENT_MASK"

void sub_88619c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 315 instructions
    /* 0x88619c */ stp x29, x30, [sp, #0xa0];
    /* 0x8861a0 */ str x25, [sp, #0xb0];
    /* 0x8861a4 */ stp x24, x23, [sp, #0xc0];
    /* 0x8861a8 */ stp x22, x21, [sp, #0xd0];
    /* 0x8861ac */ stp x20, x19, [sp, #0xe0];
    /* 0x8861b0 */ add x29, sp, #0xa0;
    /* 0x8861b4 */ mrs x23, tpidr_el0;
    /* 0x8861b8 */ mov x20, x0;
    /* 0x8861bc */ ldr x8, [x23, #0x28];
    /* 0x8861c0 */ stur x8, [x29, #-8];
    sub_910d48();
    sub_5604d4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk19to_stringEm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk19to_stringEm();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    _ZdlPv();
    _ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE();
    sub_5604d4();
    sub_560420();
    memmove();
    sub_560420();
    memmove();
    sub_a7fc58();
    sub_ccc19c();
    sub_ccc19c();
    sub_a7b38c();
    _ZdlPv();
    _ZdlPv();
    sub_ccc46c();
    sub_a7fc4c();
    sub_a6f088();
    sub_cc02e0();
    sub_ccc46c();
    sub_a7fc4c();
    sub_a6f088();
    sub_cc02e0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
