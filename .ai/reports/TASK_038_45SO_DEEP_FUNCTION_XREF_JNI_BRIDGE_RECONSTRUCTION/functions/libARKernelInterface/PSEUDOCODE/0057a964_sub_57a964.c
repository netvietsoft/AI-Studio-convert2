// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a964
// Recovered Name: sub_57a964
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a964 | Size: 20 bytes | SHA256: f6a1229422329ff53f79ee6b4516ca622c7342ff963e9f9659fd4a8a6d56e0fc
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultAlpha(J)I (table at 0x10ce6a8)

jlong sub_57a964(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57a964 */ cbz x2, #0x57a970;
    /* 0x57a968 */ mov x0, x2;
    /* 0x57a96c */ b #0x90b0b0;
    /* 0x57a970 */ mov w0, #0x64;
    return x0;
}
