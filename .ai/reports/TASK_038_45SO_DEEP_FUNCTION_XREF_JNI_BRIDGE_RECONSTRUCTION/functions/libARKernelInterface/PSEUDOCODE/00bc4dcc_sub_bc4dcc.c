// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xbc4dcc
// Recovered Name: sub_bc4dcc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbc4dcc | Size: 364 bytes | SHA256: 8c74dc407cc35f78e72335059e2ba09bcb17b056384981c59ffaf5cab03f0697
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _Znwm
// Strings referenced:
//   ";MEITU_AMBIENT_LIGHT_ADJUST"
//   ";MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"
//   ";MEITU_USE_HEAD_MASK_TEXTURE"
//   ";MEITU_USE_MASK_TEXTURE"
//   ";MEITU_USE_MATERIAL_COLOR_RGB"

void sub_bc4dcc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 91 instructions
    /* 0xbc4dcc */ ldrb w8, [sp, #0x12];
    /* 0xbc4dd0 */ add x0, x22, #0x58;
    /* 0xbc4dd4 */ cmp w8, #0;
    /* 0xbc4dd8 */ adrp x8, #0x1b3000;
    /* 0xbc4ddc */ add x8, x8, #0x48c;
    /* 0xbc4de0 */ csel x1, x19, x8, eq;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    /* 0xbc4de8 */ ldrb w8, [sp, #0x13];
    /* 0xbc4dec */ add x0, x22, #0x58;
    /* 0xbc4df0 */ cmp w8, #0;
    /* 0xbc4df4 */ adrp x8, #0x1ae000;
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
}
