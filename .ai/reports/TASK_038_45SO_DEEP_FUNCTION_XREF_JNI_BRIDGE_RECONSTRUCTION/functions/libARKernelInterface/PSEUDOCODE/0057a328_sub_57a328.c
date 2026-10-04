// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a328
// Recovered Name: sub_57a328
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a328 | Size: 16 bytes | SHA256: 5dbe833c9157741db1c800abf4005dbd0bfe279378dfa51552fafea4ad7890cf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeStopBGM(J)V (table at 0x10ce5b8)

jlong sub_57a328(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57a328 */ cbz x2, #0x57a334;
    /* 0x57a32c */ mov x0, x2;
    /* 0x57a330 */ b #0x90adcc;
    return x0;
}
