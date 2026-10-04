// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbed30
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI11setFaceRectEP7_JNIEnvP8_jobjectliP12_jfloatArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbed30 | Size: 196 bytes | SHA256: 5ca7521afa0100b1df81dcfc676f85e6400224ff871a3f90858e6fca92a97569
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetFaceRect(JI[F)V (table at 0x1ca3f8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setFaceRect, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI11setFaceRectEP7_JNIEnvP8_jobjectliP12_jfloatArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0xbed30 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xbed34 */ stp x22, x21, [sp, #0x10];
    /* 0xbed38 */ stp x20, x19, [sp, #0x20];
    /* 0xbed3c */ mov x29, sp;
    /* 0xbed40 */ mov w19, w3;
    /* 0xbed44 */ cbz x2, #0xbedb0;
    /* 0xbed48 */ cmp w19, #9;
    /* 0xbed4c */ b.gt #0xbedb0;
    /* 0xbed50 */ ldr x8, [x0];
    /* 0xbed54 */ mov x21, x2;
    /* 0xbed58 */ mov x1, x4;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
