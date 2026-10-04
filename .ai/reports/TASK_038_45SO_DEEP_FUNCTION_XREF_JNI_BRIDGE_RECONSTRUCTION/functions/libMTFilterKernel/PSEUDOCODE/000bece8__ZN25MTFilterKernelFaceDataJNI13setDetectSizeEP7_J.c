// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbece8
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI13setDetectSizeEP7_JNIEnvP8_jobjectlii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbece8 | Size: 20 bytes | SHA256: 46c259884087424aaa934414bb078e3275c11b4a131607fe1776f3cfc4e65eb9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetDetectSize(JII)V (table at 0x1ca3e0)

jlong _ZN25MTFilterKernelFaceDataJNI13setDetectSizeEP7_JNIEnvP8_jobjectlii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0xbece8 */ cbz x2, #0xbecfc;
    /* 0xbecec */ scvtf s0, w3;
    /* 0xbecf0 */ scvtf s1, w4;
    /* 0xbecf4 */ stp s0, s1, [x2, #4];
    return x0;
}
