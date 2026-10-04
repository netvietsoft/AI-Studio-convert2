// Library: libarkernel3.so
// Function ID: libarkernel3::0x9fb03c
// Recovered Name: sub_9fb03c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9fb03c | Size: 1520 bytes | SHA256: 429b7fabe892465b173a66033d3b59a188b4f5581fdad9c48754d4c749af2667
// Callers: 0 | Callees: 4 | Imports: 4

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdlPv, _Znwm
// Strings referenced:
//   ";MEITU_AMBIENT_LIGHT_ADJUST"
//   ";MEITU_BLEND_NORMAL"
//   ";MEITU_REVERSE_MATERIAL_COLOR"
//   ";MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"
//   ";MEITU_USE_HEAD_MASK_TEXTURE"

void sub_9fb03c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 380 instructions
    /* 0x9fb03c */ stp x29, x30, [sp, #0xa0];
    /* 0x9fb040 */ stp x22, x21, [sp, #0xb0];
    /* 0x9fb044 */ stp x20, x19, [sp, #0xc0];
    /* 0x9fb048 */ add x29, sp, #0xa0;
    /* 0x9fb04c */ mrs x21, tpidr_el0;
    /* 0x9fb050 */ ldr x8, [x21, #0x28];
    /* 0x9fb054 */ stur x8, [x29, #-8];
    /* 0x9fb058 */ cbz x0, #0x9fb154;
    /* 0x9fb05c */ movi v0.2s, #0x40;
    /* 0x9fb060 */ adrp x8, #0x286000;
    /* 0x9fb064 */ add x22, sp, #0x18;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_cccfe0();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
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
    sub_aa2af4();
    sub_9faecc();
    _ZdlPv();
    _Znwm();
    sub_9fb72c();
}
