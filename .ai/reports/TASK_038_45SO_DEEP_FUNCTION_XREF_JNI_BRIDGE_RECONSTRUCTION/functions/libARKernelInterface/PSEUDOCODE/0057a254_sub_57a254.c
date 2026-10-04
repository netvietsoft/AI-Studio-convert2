// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a254
// Recovered Name: sub_57a254
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a254 | Size: 16 bytes | SHA256: 42bd1a8e923fed80dbdfd161f8c5056a8a70a325132309d7592f4e66eee4de0a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeRelease(J)V (table at 0x10ce4f8)

jlong sub_57a254(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57a254 */ cbz x2, #0x57a260;
    /* 0x57a258 */ mov x0, x2;
    /* 0x57a25c */ b #0x90a74c;
    return x0;
}
