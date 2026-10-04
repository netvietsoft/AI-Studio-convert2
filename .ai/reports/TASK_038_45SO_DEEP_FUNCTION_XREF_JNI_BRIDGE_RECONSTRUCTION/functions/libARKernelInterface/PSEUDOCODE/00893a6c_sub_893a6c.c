// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x893a6c
// Recovered Name: sub_893a6c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x893a6c | Size: 1908 bytes | SHA256: 45e950eb9c5d13643efb5be34525b53537db09e381b4f6f4093b5fd551f28d0a
// Callers: 0 | Callees: 25 | Imports: 7

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZdaPv, _Znam, _Znwm, __android_log_print, __stack_chk_fail, memset
// Strings referenced:
//   "%p, RenderForFace:ImageShowWidth:%d,%d"
//   "(x) ((x).r)"
//   "CoreMaskDaubPart::RenderForFace"
//   "FrameBuffer:%d"
//   "Hair Eraser:"

void sub_893a6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 477 instructions
    /* 0x893a6c */ stp x29, x30, [sp, #0x30];
    /* 0x893a70 */ stp x28, x27, [sp, #0x40];
    /* 0x893a74 */ stp x26, x25, [sp, #0x50];
    /* 0x893a78 */ stp x24, x23, [sp, #0x60];
    /* 0x893a7c */ stp x22, x21, [sp, #0x70];
    /* 0x893a80 */ stp x20, x19, [sp, #0x80];
    /* 0x893a84 */ add x29, sp, #0x30;
    /* 0x893a88 */ mrs x27, tpidr_el0;
    /* 0x893a8c */ adrp x25, #0x10c5000;
    /* 0x893a90 */ mov x28, x1;
    /* 0x893a94 */ ldr x8, [x27, #0x28];
    sub_5a6b20();
    __android_log_print();
    sub_5a6b20();
    __android_log_print();
    sub_5a6b20();
    __android_log_print();
    sub_c38b3c();
    _Znwm();
    memset();
    sub_69bba0();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_69b7c4();
    sub_69b7cc();
    sub_69b7d4();
    sub_69add8();
    sub_c41220();
    sub_698564();
    sub_69856c();
    _Znwm();
    sub_697830();
    sub_698574();
    sub_6979b8();
    _Znam();
    memset();
    _Znwm();
    memset();
    sub_69bba0();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_c37e90();
    sub_90a85c();
    sub_8e0920();
    sub_5a6b20();
    __android_log_print();
    sub_697fb4();
    sub_6981a0();
    sub_c37e90();
    _ZdaPv();
    sub_c38b3c();
    sub_69add8();
    sub_5a6b20();
    __android_log_print();
    sub_bc6554();
    sub_698a74();
    sub_5a6b20();
    __android_log_print();
    _Znwm();
    memset();
    sub_69bba0();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_69b7cc();
    sub_69b7d4();
    sub_69b7cc();
    sub_69b7d4();
    sub_69da9c();
    sub_69daa4();
    sub_bc66b8();
    sub_69add8();
    sub_697fb4();
    sub_6981a0();
    sub_698574();
    sub_698448();
    sub_697894();
    return x0;
    __stack_chk_fail();
}
