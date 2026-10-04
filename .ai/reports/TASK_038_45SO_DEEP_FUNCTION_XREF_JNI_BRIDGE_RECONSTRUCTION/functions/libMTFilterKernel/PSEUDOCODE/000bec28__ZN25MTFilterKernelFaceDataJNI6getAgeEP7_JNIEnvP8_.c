// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbec28
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI6getAgeEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbec28 | Size: 128 bytes | SHA256: 66265b66fb1b48ae9b18f7e5ffbf177f6a809e0fad88524971fc7b0a5213da36
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetAge(JI)I (table at 0x1ca3b0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getAge, faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI6getAgeEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0xbec28 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbec2c */ mov x29, sp;
    /* 0xbec30 */ cbz x2, #0xbec6c;
    /* 0xbec34 */ ldr w8, [x2];
    /* 0xbec38 */ cmp w8, w3;
    /* 0xbec3c */ b.le #0xbec90;
    /* 0xbec40 */ mov w8, #0x2b58;
    /* 0xbec44 */ mov w9, #0x2340;
    /* 0xbec48 */ smaddl x8, w3, w8, x2;
    /* 0xbec4c */ ldrb w8, [x8, x9];
    /* 0xbec50 */ cbz w8, #0xbec9c;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    return x0;
}
