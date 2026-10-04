// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb11b10
// Recovered Name: sub_b11b10
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb11b10 | Size: 756 bytes | SHA256: d7d4fd9db84aea2d9ab7cd16d558223884dc318469f1a0c0cda815f5053b6570
// Callers: 0 | Callees: 6 | Imports: 4

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   ";DIRECTIONAL_LIGHT;LIGHT_COUNT %s"
//   ";POINT_LIGHT;POINT_LIGHT_COUNT %s"
//   "RENDER;FACE_SEGMENT_MASK"
//   "Shaders/zhy/facelight.fs"
//   "Shaders/zhy/facelight.vs"

void sub_b11b10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 189 instructions
    /* 0xb11b10 */ stp x29, x30, [sp, #0x90];
    /* 0xb11b14 */ stp x26, x25, [sp, #0xa0];
    /* 0xb11b18 */ stp x24, x23, [sp, #0xb0];
    /* 0xb11b1c */ stp x22, x21, [sp, #0xc0];
    /* 0xb11b20 */ stp x20, x19, [sp, #0xd0];
    /* 0xb11b24 */ add x29, sp, #0x90;
    /* 0xb11b28 */ mrs x23, tpidr_el0;
    /* 0xb11b2c */ mov x20, x0;
    /* 0xb11b30 */ ldr x8, [x23, #0x28];
    /* 0xb11b34 */ stur x8, [x29, #-8];
    sub_630ec4();
    sub_58f19c();
    sub_a45f10();
    sub_b11e04();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_a45f10();
    sub_b11e04();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_5a6eb4();
    sub_58f19c();
    sub_5abbf8();
    memmove();
    sub_5abbf8();
    memmove();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
