// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a35c
// Recovered Name: sub_58a35c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a35c | Size: 20 bytes | SHA256: 63c59d2848a46f099e1b4fb8108e14fd5f6ba86417a4b54ba22f320500d8e5c2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentAlpha(J)F (table at 0x10d0208)

jlong sub_58a35c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a35c */ cbz x2, #0x58a368;
    /* 0x58a360 */ mov x0, x2;
    /* 0x58a364 */ b #0xa2c20c;
    /* 0x58a368 */ fmov s0, #1.00000000;
    return x0;
}
