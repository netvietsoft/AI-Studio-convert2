// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57160c
// Recovered Name: sub_57160c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57160c | Size: 16 bytes | SHA256: a04d89ba618b5d64989e994e4752888d8af54046415607a085e4cf834ef67eba
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativePlayBGM(J)V (table at 0x10cd6e8)

jlong sub_57160c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57160c */ cbz x2, #0x571618;
    /* 0x571610 */ mov x0, x2;
    /* 0x571614 */ b #0x89211c;
    return x0;
}
