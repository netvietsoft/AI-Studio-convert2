// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbe590
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI11getLandmarkEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbe590 | Size: 1280 bytes | SHA256: 42490cbacdb96568937708cc9231e802cf57c8a972db87fba1b58fe6ed00a6db
// Callers: 0 | Callees: 1 | Imports: 5

// Dynamic Registration: nativeGetLandmark(JII)[F (table at 0x1ca338)
// Calls external APIs: _ZdaPv, _Znam, __android_log_print, __stack_chk_fail, memcpy
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getLandmark, faceData object is NULL"
//   "ERROR:MTFilterKernel::FilterkernelNativeFace getLandmark,error type"
//   "FilterKernel"

jobject _ZN25MTFilterKernelFaceDataJNI11getLandmarkEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 320 instructions
    /* 0xbe590 */ stp x29, x30, [sp, #-0x50]!;
    /* 0xbe594 */ str x28, [sp, #0x10];
    /* 0xbe598 */ stp x24, x23, [sp, #0x20];
    /* 0xbe59c */ stp x22, x21, [sp, #0x30];
    /* 0xbe5a0 */ stp x20, x19, [sp, #0x40];
    /* 0xbe5a4 */ mov x29, sp;
    /* 0xbe5a8 */ sub sp, sp, #2, lsl #12;
    /* 0xbe5ac */ sub sp, sp, #0xe00;
    /* 0xbe5b0 */ mrs x23, tpidr_el0;
    /* 0xbe5b4 */ ldr x8, [x23, #0x28];
    /* 0xbe5b8 */ stur x8, [x29, #-8];
    memcpy();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    _Znam();
    MTRTFILTERKERNEL_GetLogLevel();
    _Znam();
    _ZdaPv();
    __stack_chk_fail();
}
