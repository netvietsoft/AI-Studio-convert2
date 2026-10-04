// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a5ec
// Recovered Name: sub_58a5ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a5ec | Size: 20 bytes | SHA256: 1fce898e6c4aac606adf74aea14ac3a3f6fc0b35ff541aadd5cedec2431bfe24
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMaxValue(J)F (table at 0x10d03d0)

jlong sub_58a5ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a5ec */ cbz x2, #0x58a5f8;
    /* 0x58a5f0 */ mov x0, x2;
    /* 0x58a5f4 */ b #0xa2d4ac;
    /* 0x58a5f8 */ movi d0, #0000000000000000;
    return x0;
}
