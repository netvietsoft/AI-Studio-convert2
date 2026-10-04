// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579e1c
// Recovered Name: sub_579e1c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579e1c | Size: 20 bytes | SHA256: 5c7f5d6c03a8a87089c6820cd661e1739f23724048efb8dbebfa70ef4a9f2f56
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetEyePartAlphaSide(JI)V (table at 0x10ce3f0)

jlong sub_579e1c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579e1c */ cbz x2, #0x579e2c;
    /* 0x579e20 */ mov x0, x2;
    /* 0x579e24 */ mov w1, w3;
    /* 0x579e28 */ b #0x8e0f08;
    return x0;
}
