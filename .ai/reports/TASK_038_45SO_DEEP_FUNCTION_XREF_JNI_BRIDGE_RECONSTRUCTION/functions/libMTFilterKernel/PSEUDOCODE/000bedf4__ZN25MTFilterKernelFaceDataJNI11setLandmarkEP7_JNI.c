// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbedf4
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI11setLandmarkEP7_JNIEnvP8_jobjectliiP12_jfloatArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbedf4 | Size: 1272 bytes | SHA256: c7c0491a0a0c826ac32d6493b5ec35c856945828175142e1be12c4fcd50dddbe
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetLandmark(JII[F)Z (table at 0x1ca410)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setLandmark, data size is 0"
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setLandmark, faceData object is NULL"
//   "ERROR:MTFilterKernel::FilterkernelNativeFace setLandmark,error type"
//   "FilterKernel"

jobject _ZN25MTFilterKernelFaceDataJNI11setLandmarkEP7_JNIEnvP8_jobjectliiP12_jfloatArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 318 instructions
    /* 0xbedf4 */ stp x29, x30, [sp, #-0x50]!;
    /* 0xbedf8 */ str x25, [sp, #0x10];
    /* 0xbedfc */ stp x24, x23, [sp, #0x20];
    /* 0xbee00 */ stp x22, x21, [sp, #0x30];
    /* 0xbee04 */ stp x20, x19, [sp, #0x40];
    /* 0xbee08 */ mov x29, sp;
    /* 0xbee0c */ cbz x2, #0xbeea8;
    /* 0xbee10 */ mov w19, w4;
    /* 0xbee14 */ cmp w4, #9;
    /* 0xbee18 */ b.gt #0xbeecc;
    /* 0xbee1c */ cbz x5, #0xbf188;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
}
