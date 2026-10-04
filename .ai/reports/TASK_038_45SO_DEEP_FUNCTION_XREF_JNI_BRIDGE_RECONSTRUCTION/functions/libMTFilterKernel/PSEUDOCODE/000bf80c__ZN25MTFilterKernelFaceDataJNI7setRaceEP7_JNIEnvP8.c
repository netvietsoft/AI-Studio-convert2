// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbf80c
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI7setRaceEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbf80c | Size: 120 bytes | SHA256: 658b8e65319d72dbe3e309eb82c0edcc8543b90c676042137774cebc486ac210
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetRace(JII)V (table at 0x1ca440)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setRace, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI7setRaceEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xbf80c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbf810 */ str x19, [sp, #0x10];
    /* 0xbf814 */ mov x29, sp;
    /* 0xbf818 */ cbz x2, #0xbf844;
    /* 0xbf81c */ cmp w3, #9;
    /* 0xbf820 */ b.gt #0xbf844;
    /* 0xbf824 */ mov w8, #0x2b58;
    /* 0xbf828 */ mvn w9, w4;
    /* 0xbf82c */ mov w10, #0x2348;
    /* 0xbf830 */ smaddl x8, w3, w8, x2;
    /* 0xbf834 */ lsr w9, w9, #0x1f;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
