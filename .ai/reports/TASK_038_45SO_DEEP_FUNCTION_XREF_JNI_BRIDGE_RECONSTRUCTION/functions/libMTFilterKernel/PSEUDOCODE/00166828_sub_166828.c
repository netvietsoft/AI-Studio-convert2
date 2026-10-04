// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x166828
// Recovered Name: sub_166828
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x166828 | Size: 1796 bytes | SHA256: 0605b901bbe37bb4085d6f7d750fad7f049da8a52c8c0fca1b045516666f44c3
// Callers: 0 | Callees: 4 | Imports: 6

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, __stack_chk_fail, memmove, strlen
// Strings referenced:
//   "Fail to GPUImageGaussianBlurWithRadiusFilter::init : kGPUImageGaussianBlurWithRadiusFilterFragmentShaderString is wrong!, _hasMask = %d"
//   "Fail to GPUImageGaussianBlurWithRadiusFilter::init: blackTexture = %d, whiteTexture = %d in context, which need set by filter"
//   "FilterKernel"

void sub_166828(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 449 instructions
    /* 0x166828 */ stp x29, x30, [sp, #0x70];
    /* 0x16682c */ str x27, [sp, #0x80];
    /* 0x166830 */ stp x26, x25, [sp, #0x90];
    /* 0x166834 */ stp x24, x23, [sp, #0xa0];
    /* 0x166838 */ stp x22, x21, [sp, #0xb0];
    /* 0x16683c */ stp x20, x19, [sp, #0xc0];
    /* 0x166840 */ add x29, sp, #0x70;
    /* 0x166844 */ mrs x25, tpidr_el0;
    /* 0x166848 */ adrp x26, #0x1c5000;
    /* 0x16684c */ mov x19, x0;
    /* 0x166850 */ ldr x8, [x25, #0x28];
    strlen();
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_c3100();
    sub_1b0544();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    __stack_chk_fail();
}
