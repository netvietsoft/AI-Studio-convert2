// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfacc
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI5clearEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfacc | Size: 24 bytes | SHA256: a4a6a8f0e809e2ab8d038e85b66e3a5b85dd95517c5bcf31dd5a9f65b148d957
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeClear(J)V (table at 0x1ca4d0)
// Calls external APIs: memset

jlong _ZN25MTFilterKernelFaceDataJNI5clearEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0xbfacc */ cbz x2, #0xbfae4;
    /* 0xbfad0 */ mov x0, x2;
    /* 0xbfad4 */ mov w2, #0xb180;
    /* 0xbfad8 */ mov w1, wzr;
    /* 0xbfadc */ movk w2, #1, lsl #16;
    /* 0xbfae0 */ b #0x1b42c0;
}
