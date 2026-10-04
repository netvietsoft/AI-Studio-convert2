// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a8ec
// Recovered Name: sub_57a8ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a8ec | Size: 20 bytes | SHA256: f6fa75b80c5b906cba1151c0cd845c4a70a5946322bdc98d58c5df256b8ee613
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayer(JI)V (table at 0x10ce648)

jlong sub_57a8ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57a8ec */ cbz x2, #0x57a8fc;
    /* 0x57a8f0 */ mov x0, x2;
    /* 0x57a8f4 */ mov w1, w3;
    /* 0x57a8f8 */ b #0x90b088;
    return x0;
}
