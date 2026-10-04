// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbf8fc
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI6setAgeEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbf8fc | Size: 120 bytes | SHA256: a88e08efc44061dfe44dbd2db0b6338ccc0fd8574c089277ba654544f06cc4ee
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetAge(JII)V (table at 0x1ca470)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setAge, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI6setAgeEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xbf8fc */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbf900 */ str x19, [sp, #0x10];
    /* 0xbf904 */ mov x29, sp;
    /* 0xbf908 */ cbz x2, #0xbf934;
    /* 0xbf90c */ cmp w3, #9;
    /* 0xbf910 */ b.gt #0xbf934;
    /* 0xbf914 */ mov w8, #0x2b58;
    /* 0xbf918 */ mvn w9, w4;
    /* 0xbf91c */ mov w10, #0x2340;
    /* 0xbf920 */ smaddl x8, w3, w8, x2;
    /* 0xbf924 */ lsr w9, w9, #0x1f;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
