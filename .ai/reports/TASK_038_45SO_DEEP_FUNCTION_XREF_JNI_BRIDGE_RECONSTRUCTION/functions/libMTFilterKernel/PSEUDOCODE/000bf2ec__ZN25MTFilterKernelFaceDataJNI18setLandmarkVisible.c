// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbf2ec
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI18setLandmarkVisibleEP7_JNIEnvP8_jobjectliiP12_jfloatArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbf2ec | Size: 1284 bytes | SHA256: e194205c0799ab1b9e688de26b20ec16a42f496eed33cf7918d4b9ea817745d7
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetLandmarkVisible(JII[F)Z (table at 0x1ca428)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setLandmark, data size is 0"
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setLandmark, faceData object is NULL"
//   "ERROR:MTFilterKernel::FilterkernelNativeFace setLandmark,error type"
//   "FilterKernel"

jobject _ZN25MTFilterKernelFaceDataJNI18setLandmarkVisibleEP7_JNIEnvP8_jobjectliiP12_jfloatArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 321 instructions
    /* 0xbf2ec */ stp x29, x30, [sp, #-0x50]!;
    /* 0xbf2f0 */ str x25, [sp, #0x10];
    /* 0xbf2f4 */ stp x24, x23, [sp, #0x20];
    /* 0xbf2f8 */ stp x22, x21, [sp, #0x30];
    /* 0xbf2fc */ stp x20, x19, [sp, #0x40];
    /* 0xbf300 */ mov x29, sp;
    /* 0xbf304 */ cbz x2, #0xbf330;
    /* 0xbf308 */ mov w19, w4;
    /* 0xbf30c */ cmp w4, #9;
    /* 0xbf310 */ b.le #0xbf358;
    /* 0xbf314 */ mov w0, wzr;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    MTRTFILTERKERNEL_GetLogLevel();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
}
