// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a244
// Recovered Name: sub_58a244
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a244 | Size: 16 bytes | SHA256: 8d1b597f4b88ed09eb8d353dda492f6b099d61e07f9af2c14b502cf973e5792f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentColorInfo(JFFF)V (table at 0x10d0190)

jlong sub_58a244(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a244 */ cbz x2, #0x58a250;
    /* 0x58a248 */ mov x0, x2;
    /* 0x58a24c */ b #0xa2bfd8;
    return x0;
}
