// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1647a0
// Recovered Name: sub_1647a0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1647a0 | Size: 400 bytes | SHA256: e211b0bc0c7967b722e259af375e6ab4a58301809a745be9bf0c036ca70d0dc5
// Callers: 0 | Callees: 5 | Imports: 3

// Calls external APIs: _ZdlPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "Fail to GPUImageGaussianBlurFilter::init : GPUImageTwoPassTextureSamplingFilter::init is wrong!"
//   "FilterKernel"

void sub_1647a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 100 instructions
    /* 0x1647a0 */ stp x29, x30, [sp, #0x40];
    /* 0x1647a4 */ str x21, [sp, #0x50];
    /* 0x1647a8 */ stp x20, x19, [sp, #0x60];
    /* 0x1647ac */ add x29, sp, #0x40;
    /* 0x1647b0 */ mrs x21, tpidr_el0;
    /* 0x1647b4 */ fmov s0, #2.00000000;
    /* 0x1647b8 */ mov x19, x0;
    /* 0x1647bc */ ldr x8, [x21, #0x28];
    /* 0x1647c0 */ mov w0, #4;
    /* 0x1647c4 */ mov x20, x1;
    /* 0x1647c8 */ stur x8, [x29, #-8];
    _ZN14MTFilterKernel26GPUImageGaussianBlurFilter36vertexShaderForOptimizedBlurOfRadiusEif();
    _ZN14MTFilterKernel26GPUImageGaussianBlurFilter38fragmentShaderForOptimizedBlurOfRadiusEif();
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
    sub_1b0544();
    _ZdlPv();
    _ZdlPv();
    __stack_chk_fail();
}
