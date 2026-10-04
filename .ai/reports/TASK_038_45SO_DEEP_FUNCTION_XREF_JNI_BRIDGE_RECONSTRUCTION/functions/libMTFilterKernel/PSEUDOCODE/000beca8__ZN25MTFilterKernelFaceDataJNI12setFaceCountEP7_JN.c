// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbeca8
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI12setFaceCountEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbeca8 | Size: 12 bytes | SHA256: d48d25218b8421a7f1ff9d2e0eea74db2c9ea7ff481d239c0bce24602e051a80
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceCount(JI)V (table at 0x1ca3c8)

jlong _ZN25MTFilterKernelFaceDataJNI12setFaceCountEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0xbeca8 */ cbz x2, #0xbecb4;
    /* 0xbecac */ str w3, [x2];
    return x0;
}
