// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbeba8
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI9getGenderEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbeba8 | Size: 128 bytes | SHA256: 4505374e488754a3bfa1fbf28cf5aa4311ecabcd906c0da89116716715d3bb02
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetGender(JI)I (table at 0x1ca398)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getFaceRect, faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI9getGenderEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0xbeba8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbebac */ mov x29, sp;
    /* 0xbebb0 */ cbz x2, #0xbebec;
    /* 0xbebb4 */ ldr w8, [x2];
    /* 0xbebb8 */ cmp w8, w3;
    /* 0xbebbc */ b.le #0xbec10;
    /* 0xbebc0 */ mov w8, #0x2b58;
    /* 0xbebc4 */ mov w9, #0x2338;
    /* 0xbebc8 */ smaddl x8, w3, w8, x2;
    /* 0xbebcc */ ldrb w8, [x8, x9];
    /* 0xbebd0 */ cbz w8, #0xbec1c;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    return x0;
}
