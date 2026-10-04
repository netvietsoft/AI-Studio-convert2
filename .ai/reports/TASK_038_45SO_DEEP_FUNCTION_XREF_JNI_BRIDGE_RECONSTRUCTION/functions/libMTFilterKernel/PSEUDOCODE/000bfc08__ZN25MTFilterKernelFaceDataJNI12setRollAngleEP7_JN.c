// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfc08
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI12setRollAngleEP7_JNIEnvP8_jobjectlif
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfc08 | Size: 120 bytes | SHA256: 8b59798d86a945f84b9c73a8b24a9baff6cec618cc65f0cd0b65cdba9a243b7e
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetRollAngle(JIF)V (table at 0x1ca518)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setAge, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI12setRollAngleEP7_JNIEnvP8_jobjectlif(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xbfc08 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbfc0c */ str x19, [sp, #0x10];
    /* 0xbfc10 */ mov x29, sp;
    /* 0xbfc14 */ cbz x2, #0xbfc40;
    /* 0xbfc18 */ cmp w3, #9;
    /* 0xbfc1c */ b.gt #0xbfc40;
    /* 0xbfc20 */ mov w8, #0x2b58;
    /* 0xbfc24 */ fcmp s0, #0.0;
    /* 0xbfc28 */ mov w9, #0x2320;
    /* 0xbfc2c */ smaddl x8, w3, w8, x2;
    /* 0xbfc30 */ cset w10, pl;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
