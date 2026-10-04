// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbf974
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI9getFaceIDEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbf974 | Size: 112 bytes | SHA256: a398b2797cd652aa798f6aaa37231ac64e7039b28c8bd7ed594e416271f02b05
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetFaceID(JI)I (table at 0x1ca488)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getFaceID, faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI9getFaceIDEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 28 instructions
    /* 0xbf974 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbf978 */ mov x29, sp;
    /* 0xbf97c */ cbz x2, #0xbf9b4;
    /* 0xbf980 */ ldr w8, [x2];
    /* 0xbf984 */ cmp w8, w3;
    /* 0xbf988 */ b.le #0xbf9d8;
    /* 0xbf98c */ mov w8, #0x2b58;
    /* 0xbf990 */ smaddl x8, w3, w8, x2;
    /* 0xbf994 */ ldrb w8, [x8, #0xc];
    /* 0xbf998 */ cbz w8, #0xbf9d8;
    /* 0xbf99c */ sxtw x8, w3;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
}
