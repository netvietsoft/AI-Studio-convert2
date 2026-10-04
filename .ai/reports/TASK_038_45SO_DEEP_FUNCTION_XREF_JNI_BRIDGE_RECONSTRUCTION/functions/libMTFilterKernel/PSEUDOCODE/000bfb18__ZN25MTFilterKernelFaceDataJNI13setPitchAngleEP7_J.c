// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfb18
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI13setPitchAngleEP7_JNIEnvP8_jobjectlif
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfb18 | Size: 120 bytes | SHA256: bbcca260c13d2eaf62905a0bf255913504f1c655ba218f9422997621923af890
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetPitchAngle(JIF)V (table at 0x1ca4e8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace setAge, faceData object is NULL or face index == %d out range"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI13setPitchAngleEP7_JNIEnvP8_jobjectlif(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0xbfb18 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbfb1c */ str x19, [sp, #0x10];
    /* 0xbfb20 */ mov x29, sp;
    /* 0xbfb24 */ cbz x2, #0xbfb50;
    /* 0xbfb28 */ cmp w3, #9;
    /* 0xbfb2c */ b.gt #0xbfb50;
    /* 0xbfb30 */ mov w8, #0x2b58;
    /* 0xbfb34 */ fcmp s0, #0.0;
    /* 0xbfb38 */ mov w9, #0x2330;
    /* 0xbfb3c */ smaddl x8, w3, w8, x2;
    /* 0xbfb40 */ cset w10, pl;
    MTRTFILTERKERNEL_GetLogLevel();
    return x0;
}
