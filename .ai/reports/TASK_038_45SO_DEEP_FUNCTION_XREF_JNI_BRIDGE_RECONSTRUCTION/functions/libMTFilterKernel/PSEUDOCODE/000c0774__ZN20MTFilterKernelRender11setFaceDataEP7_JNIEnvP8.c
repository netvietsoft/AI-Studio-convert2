// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc0774
// Recovered Name: _ZN20MTFilterKernelRender11setFaceDataEP7_JNIEnvP8_jobjectll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xc0774 | Size: 24 bytes | SHA256: 1e9817dfc883fc4b2af6df4584a110733788ee3900429b1755aa2cc7ed75f183
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFaceData(JJ)V (table at 0x1ca6b0)

jlong _ZN20MTFilterKernelRender11setFaceDataEP7_JNIEnvP8_jobjectll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0xc0774 */ cbz x2, #0xc0788;
    /* 0xc0778 */ cbz x3, #0xc0788;
    /* 0xc077c */ mov x0, x2;
    /* 0xc0780 */ mov x1, x3;
    /* 0xc0784 */ b #0x1aa3d8;
    return x0;
}
