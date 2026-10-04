// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbeadc
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI15getDetectHeightEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbeadc | Size: 76 bytes | SHA256: 9094a690c5be9d3b76c0a1aafccf2f50590ae013ba4a32dc1b759092afde8d25
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetDetectHeight(J)I (table at 0x1ca368)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getDetectHeight,faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI15getDetectHeightEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0xbeadc */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbeae0 */ mov x29, sp;
    /* 0xbeae4 */ cbz x2, #0xbeaf8;
    /* 0xbeae8 */ ldr s0, [x2, #8];
    /* 0xbeaec */ fcvtzs w0, s0;
    /* 0xbeaf0 */ ldp x29, x30, [sp], #0x10;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    /* 0xbeafc */ cmp w0, #5;
    /* 0xbeb00 */ b.gt #0xbeb1c;
    /* 0xbeb04 */ adrp x1, #0x7c000;
    __android_log_print();
    return x0;
}
