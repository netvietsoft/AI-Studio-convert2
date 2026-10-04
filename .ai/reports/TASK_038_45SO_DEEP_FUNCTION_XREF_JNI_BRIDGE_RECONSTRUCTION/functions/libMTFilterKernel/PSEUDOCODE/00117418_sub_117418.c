// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x117418
// Recovered Name: sub_117418
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x117418 | Size: 1720 bytes | SHA256: 3847aa570d126a44f86f0e03e0e12ea189acee8e34f738ab30a918c9c82a70ed
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, memmove, strlen
// Strings referenced:
//   "Fail to GPUImageMyBoxFilter::init: _blurRadius = %d is not support"
//   "Fail to GPUImageMyBoxFilter::init: whiteTexture = %d in context, which need set by filter"
//   "FilterKernel"

void sub_117418(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 430 instructions
    /* 0x117418 */ stp x29, x30, [sp, #0x70];
    /* 0x11741c */ str x27, [sp, #0x80];
    /* 0x117420 */ stp x26, x25, [sp, #0x90];
    /* 0x117424 */ stp x24, x23, [sp, #0xa0];
    /* 0x117428 */ stp x22, x21, [sp, #0xb0];
    /* 0x11742c */ stp x20, x19, [sp, #0xc0];
    /* 0x117430 */ add x29, sp, #0x70;
    /* 0x117434 */ mrs x25, tpidr_el0;
    /* 0x117438 */ ldr x8, [x25, #0x28];
    /* 0x11743c */ stur x8, [x29, #-8];
    /* 0x117440 */ ldr x8, [x1, #0x188];
    strlen();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    strlen();
    strlen();
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
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
}
