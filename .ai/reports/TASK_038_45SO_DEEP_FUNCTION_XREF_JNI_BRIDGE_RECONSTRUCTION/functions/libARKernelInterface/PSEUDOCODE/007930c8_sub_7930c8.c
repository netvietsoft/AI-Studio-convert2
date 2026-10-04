// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x7930c8
// Recovered Name: sub_7930c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7930c8 | Size: 484 bytes | SHA256: 74563565076c428e14a44d613f2bc1b8503ac47eb8b8f30afce55051ec5fe737
// Callers: 0 | Callees: 4 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "MEITU_USE_MAKEUP_ADAPT"
//   "MEITU_USE_MASK_TEXTURE;MEITU_MASK_CHANNEL"
//   "MEITU_USE_MOUTH_SEGMENT_MASK_TEXTURE"
//   "MEITU_USE_SOURCE_TEXTURE;MEITU_USE_MATERIAL_TEXTURE;MEITU_USE_MATERIAL_COLOR_RGB"

void sub_7930c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 121 instructions
    /* 0x7930c8 */ stp x29, x30, [sp, #0x20];
    /* 0x7930cc */ stp x22, x21, [sp, #0x30];
    /* 0x7930d0 */ stp x20, x19, [sp, #0x40];
    /* 0x7930d4 */ add x29, sp, #0x20;
    /* 0x7930d8 */ mrs x22, tpidr_el0;
    /* 0x7930dc */ mov x19, x8;
    /* 0x7930e0 */ mov x20, x0;
    /* 0x7930e4 */ ldr x8, [x22, #0x28];
    /* 0x7930e8 */ adrp x1, #0x1ae000;
    /* 0x7930ec */ add x1, x1, #0x2ed;
    /* 0x7930f0 */ mov x0, x19;
    sub_58f19c();
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    sub_69add8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_69bc74();
    _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZdlPv();
    sub_69add8();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_c162e4();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    return x0;
    __stack_chk_fail();
}
