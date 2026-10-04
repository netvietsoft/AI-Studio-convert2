// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a254
// Recovered Name: sub_58a254
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a254 | Size: 16 bytes | SHA256: e889eeda6e0ba6f58ddfba6d432b14d78313956f21b0860a2550816bd162f909
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentColorAlpha(JF)V (table at 0x10d01a8)

jlong sub_58a254(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a254 */ cbz x2, #0x58a260;
    /* 0x58a258 */ mov x0, x2;
    /* 0x58a25c */ b #0xa2c16c;
    return x0;
}
