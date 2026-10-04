// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585588
// Recovered Name: sub_585588
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585588 | Size: 20 bytes | SHA256: d73cc71998df06e02b56b05ee5a543166721098f8a3b1e35acd15805e7876183
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerAlpha(JJF)V (table at 0x10cfae8)

jlong sub_585588(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x585588 */ cbz x2, #0x585598;
    /* 0x58558c */ mov x0, x2;
    /* 0x585590 */ mov x1, x3;
    /* 0x585594 */ b #0x5843ac;
    return x0;
}
