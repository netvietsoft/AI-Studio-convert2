// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x165490
// Recovered Name: sub_165490
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x165490 | Size: 668 bytes | SHA256: ad9617ed20f58a6755393dd436c3201eac6b116c6d9e05704833498c6f8eb0fb
// Callers: 0 | Callees: 4 | Imports: 6

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, __stack_chk_fail, memmove, strlen
// Strings referenced:
//   "Fail to GPUImageGaussianBlurFilter::init : GPUImageTwoPassTextureSamplingFilter::init is wrong!"
//   "FilterKernel"

void sub_165490(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 167 instructions
    /* 0x165490 */ stp x29, x30, [sp, #0x40];
    /* 0x165494 */ stp x28, x27, [sp, #0x50];
    /* 0x165498 */ stp x26, x25, [sp, #0x60];
    /* 0x16549c */ stp x24, x23, [sp, #0x70];
    /* 0x1654a0 */ stp x22, x21, [sp, #0x80];
    /* 0x1654a4 */ stp x20, x19, [sp, #0x90];
    /* 0x1654a8 */ add x29, sp, #0x40;
    /* 0x1654ac */ mrs x27, tpidr_el0;
    /* 0x1654b0 */ adrp x26, #0x1c5000;
    /* 0x1654b4 */ mov x19, x0;
    /* 0x1654b8 */ ldr x8, [x27, #0x28];
    strlen();
    _Znwm();
    memmove();
    strlen();
    _Znwm();
    memmove();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_c3100();
    sub_c3100();
    sub_1b0544();
    _ZdlPv();
    _ZdlPv();
    __stack_chk_fail();
}
