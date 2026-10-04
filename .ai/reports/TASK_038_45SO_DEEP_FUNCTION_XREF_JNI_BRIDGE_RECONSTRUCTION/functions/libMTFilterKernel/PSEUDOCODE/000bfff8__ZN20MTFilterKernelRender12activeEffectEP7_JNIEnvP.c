// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfff8
// Recovered Name: _ZN20MTFilterKernelRender12activeEffectEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfff8 | Size: 16 bytes | SHA256: b4ab71d8cae2651dc4599fdffaca84f851d4289a863cbc32f50efb7f8e0dd738
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nActiveEffect(J)V (table at 0x1ca608)

jlong _ZN20MTFilterKernelRender12activeEffectEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xbfff8 */ cbz x2, #0xc0004;
    /* 0xbfffc */ mov x0, x2;
    /* 0xc0000 */ b #0x1aa7fc;
    return x0;
}
