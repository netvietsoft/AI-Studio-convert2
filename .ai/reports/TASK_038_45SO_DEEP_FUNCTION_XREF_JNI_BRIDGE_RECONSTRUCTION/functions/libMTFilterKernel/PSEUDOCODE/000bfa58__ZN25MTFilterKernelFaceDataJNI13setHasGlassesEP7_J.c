// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfa58
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI13setHasGlassesEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfa58 | Size: 116 bytes | SHA256: 6bc6f80453f56d51428e8d7f622796fb57751939347dcd77634c4b57b6554a6f
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetHasGlasses(JII)V (table at 0x1ca4b8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setHasGlasses, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI13setHasGlassesEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0xbfa58 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbfa5c */ str x19, [sp, #0x10];
    /* 0xbfa60 */ mov x29, sp;
    /* 0xbfa64 */ cbz x2, #0xbfa8c;
    /* 0xbfa68 */ cmp w3, #9;
    /* 0xbfa6c */ b.gt #0xbfa8c;
    /* 0xbfa70 */ mov w8, #0x2b58;
    /* 0xbfa74 */ cmp w4, #0;
    /* 0xbfa78 */ mov w9, #0x2b60;
    /* 0xbfa7c */ smaddl x8, w3, w8, x2;
    /* 0xbfa80 */ cset w10, ne;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
