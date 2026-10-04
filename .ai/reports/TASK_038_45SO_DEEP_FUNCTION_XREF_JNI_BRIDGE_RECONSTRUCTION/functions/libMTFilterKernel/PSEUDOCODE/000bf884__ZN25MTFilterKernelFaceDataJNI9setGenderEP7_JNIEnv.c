// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbf884
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI9setGenderEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbf884 | Size: 120 bytes | SHA256: 5627a4dfdb2eb62cbf249ce843a2d8cd56ad19e7a9c1fa63878db2afd8ec968e
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetGender(JII)V (table at 0x1ca458)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setGender, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI9setGenderEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xbf884 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbf888 */ str x19, [sp, #0x10];
    /* 0xbf88c */ mov x29, sp;
    /* 0xbf890 */ cbz x2, #0xbf8bc;
    /* 0xbf894 */ cmp w3, #9;
    /* 0xbf898 */ b.gt #0xbf8bc;
    /* 0xbf89c */ mov w8, #0x2b58;
    /* 0xbf8a0 */ mvn w9, w4;
    /* 0xbf8a4 */ mov w10, #0x2338;
    /* 0xbf8a8 */ smaddl x8, w3, w8, x2;
    /* 0xbf8ac */ lsr w9, w9, #0x1f;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
