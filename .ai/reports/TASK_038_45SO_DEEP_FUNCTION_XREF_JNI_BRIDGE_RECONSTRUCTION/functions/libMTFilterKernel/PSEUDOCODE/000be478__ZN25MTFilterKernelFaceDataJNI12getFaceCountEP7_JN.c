// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbe478
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI12getFaceCountEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbe478 | Size: 72 bytes | SHA256: 08f4935574e8ab87ea66c2da1af0060c72d0cd5de65703186d9173855ccbe728
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetFaceCount(J)I (table at 0x1ca308)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getFaceCount, faceData object is NULL"
//   "FilterKernel"

jlong _ZN25MTFilterKernelFaceDataJNI12getFaceCountEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0xbe478 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xbe47c */ mov x29, sp;
    /* 0xbe480 */ cbz x2, #0xbe490;
    /* 0xbe484 */ ldr w0, [x2];
    /* 0xbe488 */ ldp x29, x30, [sp], #0x10;
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    /* 0xbe494 */ cmp w0, #5;
    /* 0xbe498 */ b.gt #0xbe4b4;
    /* 0xbe49c */ adrp x1, #0x7c000;
    /* 0xbe4a0 */ add x1, x1, #0x24e;
    __android_log_print();
    return x0;
}
