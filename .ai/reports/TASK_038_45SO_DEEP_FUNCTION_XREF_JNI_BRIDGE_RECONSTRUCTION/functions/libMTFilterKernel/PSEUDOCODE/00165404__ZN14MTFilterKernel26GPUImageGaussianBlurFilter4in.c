// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x165404
// Recovered Name: _ZN14MTFilterKernel26GPUImageGaussianBlurFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x165404 | Size: 136 bytes | SHA256: b0953fe8e357745da3cd60b5e799959f9021034746d5d23a5ba7a981ba78d358
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "Fail to GPUImageGaussianBlurFilter::init : GPUImageTwoPassTextureSamplingFilter::init is wrong!"
//   "FilterKernel"

void _ZN14MTFilterKernel26GPUImageGaussianBlurFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0x165404 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x165408 */ stp x20, x19, [sp, #0x10];
    /* 0x16540c */ mov x29, sp;
    /* 0x165410 */ mov x19, x0;
    _ZN14MTFilterKernel21GPUImageTwoPassFilter4initEPNS_15GPUImageContextERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_SB_SB_();
    /* 0x165418 */ mov w20, w0;
    /* 0x16541c */ tbnz w0, #0, #0x165444;
    MTRTFILTERKERNEL_GetLogLevel();
    /* 0x165424 */ cmp w0, #5;
    /* 0x165428 */ b.gt #0x165444;
    /* 0x16542c */ adrp x1, #0x7c000;
    __android_log_print();
    return x0;
}
