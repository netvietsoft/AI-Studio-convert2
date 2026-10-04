// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a9c4
// Recovered Name: sub_57a9c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a9c4 | Size: 20 bytes | SHA256: 660e33e45a8e5aa0d10425342142dfd7bf602d93e0d222fe452df8538523ffc7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetErrorCode(J)I (table at 0x10ce6d8)

jlong sub_57a9c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57a9c4 */ cbz x2, #0x57a9d0;
    /* 0x57a9c8 */ mov x0, x2;
    /* 0x57a9cc */ b #0x90b188;
    /* 0x57a9d0 */ mov w0, wzr;
    return x0;
}
