// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbea90
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI14getDetectWidthEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbea90 | Size: 76 bytes | SHA256: 1d2ac7eca10ee812a9c52e435e42449c2b6b6aad0479967498e9e43198adb0d9
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetDetectWidth(J)I (table at 0x1ca350)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getDetectWidth,faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI14getDetectWidthEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0xbea90 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbea94 */ mov x29, sp;
    /* 0xbea98 */ cbz x2, #0xbeaac;
    /* 0xbea9c */ ldr s0, [x2, #4];
    /* 0xbeaa0 */ fcvtzs w0, s0;
    /* 0xbeaa4 */ ldp x29, x30, [sp], #0x10;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    /* 0xbeab0 */ cmp w0, #5;
    /* 0xbeab4 */ b.gt #0xbead0;
    /* 0xbeab8 */ adrp x1, #0x7c000;
    __android_log_print();
    return x0;
}
