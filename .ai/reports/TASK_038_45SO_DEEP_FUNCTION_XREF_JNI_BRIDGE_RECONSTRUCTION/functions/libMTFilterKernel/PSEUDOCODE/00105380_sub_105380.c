// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x105380
// Recovered Name: sub_105380
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x105380 | Size: 1720 bytes | SHA256: 9b05bce5a4bde54e650502d5e1a88fadadad19456566cf999e6a73bda86b76a4
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, memmove, strlen
// Strings referenced:
//   "Fail to GPUImageMyBoxFilter::init: _blurRadius = %d is not support"
//   "Fail to GPUImageMyBoxFilter::init: whiteTexture = %d in context, which need set by filter"
//   "FilterKernel"

void sub_105380(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 430 instructions
    /* 0x105380 */ stp x29, x30, [sp, #0x70];
    /* 0x105384 */ str x27, [sp, #0x80];
    /* 0x105388 */ stp x26, x25, [sp, #0x90];
    /* 0x10538c */ stp x24, x23, [sp, #0xa0];
    /* 0x105390 */ stp x22, x21, [sp, #0xb0];
    /* 0x105394 */ stp x20, x19, [sp, #0xc0];
    /* 0x105398 */ add x29, sp, #0x70;
    /* 0x10539c */ mrs x25, tpidr_el0;
    /* 0x1053a0 */ ldr x8, [x25, #0x28];
    /* 0x1053a4 */ stur x8, [x29, #-8];
    /* 0x1053a8 */ ldr x8, [x1, #0x188];
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
    _ZN14MTFilterKernel19MTTwoPassFilterBase4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel19MTTwoPassFilterBase4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel19MTTwoPassFilterBase4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
}
