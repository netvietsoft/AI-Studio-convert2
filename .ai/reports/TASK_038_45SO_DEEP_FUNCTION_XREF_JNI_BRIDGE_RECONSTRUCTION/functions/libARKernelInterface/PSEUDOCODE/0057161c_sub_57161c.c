// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57161c
// Recovered Name: sub_57161c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57161c | Size: 16 bytes | SHA256: 4591894b4f29f3dcce0f255f5ba9088f4b2f69a00b2175e44226d57171282d87
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativePauseBGM(J)V (table at 0x10cd700)

jlong sub_57161c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57161c */ cbz x2, #0x571628;
    /* 0x571620 */ mov x0, x2;
    /* 0x571624 */ b #0x89214c;
    return x0;
}
