// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbeb28
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI7getRaceEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbeb28 | Size: 128 bytes | SHA256: 6d59fdd69b6426eecdbbde267142889874a264c46c9c7d2500412f8440cde4a2
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetRace(JI)I (table at 0x1ca380)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getFaceRect, faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI7getRaceEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0xbeb28 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbeb2c */ mov x29, sp;
    /* 0xbeb30 */ cbz x2, #0xbeb6c;
    /* 0xbeb34 */ ldr w8, [x2];
    /* 0xbeb38 */ cmp w8, w3;
    /* 0xbeb3c */ b.le #0xbeb90;
    /* 0xbeb40 */ mov w8, #0x2b58;
    /* 0xbeb44 */ mov w9, #0x2348;
    /* 0xbeb48 */ smaddl x8, w3, w8, x2;
    /* 0xbeb4c */ ldrb w8, [x8, x9];
    /* 0xbeb50 */ cbz w8, #0xbeb9c;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    return x0;
}
