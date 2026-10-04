// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbe468
// Recovered Name: _ZN25MTFilterKernelFaceDataJNI8finalizeEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbe468 | Size: 16 bytes | SHA256: 075613fde03fe98c599c09ef39f44cbd1f4294cfbbaab3321ee0ea6b8301f531
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: finalizer(J)V (table at 0x1ca2f0)
// Calls external APIs: free

jlong _ZN25MTFilterKernelFaceDataJNI8finalizeEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xbe468 */ cbz x2, #0xbe474;
    /* 0xbe46c */ mov x0, x2;
    /* 0xbe470 */ b #0x1b4260;
    return x0;
}
