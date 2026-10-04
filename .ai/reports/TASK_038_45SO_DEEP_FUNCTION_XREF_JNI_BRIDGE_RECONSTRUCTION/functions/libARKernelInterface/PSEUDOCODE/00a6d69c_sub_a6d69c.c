// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa6d69c
// Recovered Name: sub_a6d69c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa6d69c | Size: 4988 bytes | SHA256: 6bd3038d0fe3b0c04411990ceef81f1a43cceaa21784bb7787c1c339168ea094
// Callers: 0 | Callees: 16 | Imports: 5

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, __android_log_print, __stack_chk_fail, memmove
// Strings referenced:
//   "ColorfulPath"
//   "DiamondMixColor1"
//   "DiamondMixColor2"
//   "DiamondShimmerColor"
//   "DoubleMouthMaskFirst"

void sub_a6d69c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1247 instructions
    /* 0xa6d69c */ stp x29, x30, [sp, #0x60];
    /* 0xa6d6a0 */ str x25, [sp, #0x70];
    /* 0xa6d6a4 */ stp x24, x23, [sp, #0x80];
    /* 0xa6d6a8 */ stp x22, x21, [sp, #0x90];
    /* 0xa6d6ac */ stp x20, x19, [sp, #0xa0];
    /* 0xa6d6b0 */ add x29, sp, #0x60;
    /* 0xa6d6b4 */ mrs x22, tpidr_el0;
    /* 0xa6d6b8 */ mov x20, x1;
    /* 0xa6d6bc */ mov x19, x0;
    /* 0xa6d6c0 */ ldr x8, [x22, #0x28];
    /* 0xa6d6c4 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_5a8d1c();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5a8da0();
    sub_68c86c();
    sub_5a8f24();
    sub_68c87c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZdlPv();
    sub_68c86c();
    sub_5a8f24();
    sub_68c87c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_a19264();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5cb124();
    memmove();
    _ZdlPv();
    sub_5cb124();
    memmove();
    _ZdlPv();
    sub_5cb124();
    memmove();
    _ZdlPv();
    sub_68c86c();
    sub_68c06c();
    sub_5a8d0c();
    sub_58f19c();
    sub_5bccd0();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_68c06c();
    sub_5a8d0c();
    sub_58f19c();
    sub_5bccd0();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_68c87c();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    sub_68c86c();
    sub_68c06c();
    sub_5a8d0c();
    sub_58f19c();
    sub_5bccd0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_68c87c();
    sub_5a8d1c();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8de8();
    sub_68c86c();
    sub_68c06c();
    sub_5a8d0c();
    sub_58f19c();
    sub_5bccd0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_68c87c();
    sub_5b7fa8();
    sub_5a6b20();
    __android_log_print();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8da0();
    sub_5cb124();
    _ZdlPv();
    sub_5a8de8();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
