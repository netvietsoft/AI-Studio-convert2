// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbf9e4
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI9setFaceIDEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbf9e4 | Size: 116 bytes | SHA256: 5fc2b3ef2ccc0e169f60b81f8ffe45dd128b50176a9066647e8bd17d75f056c3
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetFaceID(JII)V (table at 0x1ca4a0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setFaceID, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI9setFaceIDEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0xbf9e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbf9e8 */ str x19, [sp, #0x10];
    /* 0xbf9ec */ mov x29, sp;
    /* 0xbf9f0 */ cbz x2, #0xbfa18;
    /* 0xbf9f4 */ cmp w3, #9;
    /* 0xbf9f8 */ b.gt #0xbfa18;
    /* 0xbf9fc */ mov w8, #0x2b58;
    /* 0xbfa00 */ mvn w9, w4;
    /* 0xbfa04 */ smaddl x8, w3, w8, x2;
    /* 0xbfa08 */ lsr w9, w9, #0x1f;
    /* 0xbfa0c */ strb w9, [x8, #0xc];
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
