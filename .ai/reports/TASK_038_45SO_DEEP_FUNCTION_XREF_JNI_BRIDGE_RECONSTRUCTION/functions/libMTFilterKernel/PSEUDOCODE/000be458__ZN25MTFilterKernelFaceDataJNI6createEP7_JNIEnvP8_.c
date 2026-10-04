// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbe458
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbe458 | Size: 16 bytes | SHA256: c4fe4a96e93c35940f935c26b18ecc59c218437cc07af6469e1b9ba4d3f71b43
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeCreate()J (table at 0x1ca2d8)
// Calls external APIs: calloc

jlong _ZN25MTFilterKernelFaceDataJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xbe458 */ mov w1, #0xb180;
    /* 0xbe45c */ mov w0, #1;
    /* 0xbe460 */ movk w1, #1, lsl #16;
    /* 0xbe464 */ b #0x1b4250;
}
