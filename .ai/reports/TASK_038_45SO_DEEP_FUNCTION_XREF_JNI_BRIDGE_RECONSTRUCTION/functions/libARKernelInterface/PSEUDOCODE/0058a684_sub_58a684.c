// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a684
// Recovered Name: sub_58a684
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a684 | Size: 20 bytes | SHA256: e69b3d1ea6564b46f67c942fac7ceffd750b2ccfe8b0ef1eb01b215e17d4aa4e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentValue(J)F (table at 0x10d0418)

jlong sub_58a684(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a684 */ cbz x2, #0x58a690;
    /* 0x58a688 */ mov x0, x2;
    /* 0x58a68c */ b #0xa2d4f0;
    /* 0x58a690 */ movi d0, #0000000000000000;
    return x0;
}
