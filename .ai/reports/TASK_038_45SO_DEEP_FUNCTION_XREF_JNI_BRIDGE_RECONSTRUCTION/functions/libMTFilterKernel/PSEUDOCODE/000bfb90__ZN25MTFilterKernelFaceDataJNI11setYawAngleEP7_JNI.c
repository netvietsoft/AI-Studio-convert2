// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfb90
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI11setYawAngleEP7_JNIEnvP8_jobjectlif
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfb90 | Size: 120 bytes | SHA256: 4be082484ae37f640efac0568764357026a192a4a549be226875de6861638761
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetYawAngle(JIF)V (table at 0x1ca500)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setAge, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI11setYawAngleEP7_JNIEnvP8_jobjectlif(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xbfb90 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbfb94 */ str x19, [sp, #0x10];
    /* 0xbfb98 */ mov x29, sp;
    /* 0xbfb9c */ cbz x2, #0xbfbc8;
    /* 0xbfba0 */ cmp w3, #9;
    /* 0xbfba4 */ b.gt #0xbfbc8;
    /* 0xbfba8 */ mov w8, #0x2b58;
    /* 0xbfbac */ fcmp s0, #0.0;
    /* 0xbfbb0 */ mov w9, #0x2328;
    /* 0xbfbb4 */ smaddl x8, w3, w8, x2;
    /* 0xbfbb8 */ cset w10, pl;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
