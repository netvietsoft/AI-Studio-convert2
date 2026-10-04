// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a370
// Recovered Name: sub_58a370
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a370 | Size: 20 bytes | SHA256: 741f5c448ba30fe31dda7e641a8163d3e46e32bb1b599be675279a9b14241930
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentOpacity(J)F (table at 0x10d0220)

jlong sub_58a370(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a370 */ cbz x2, #0x58a37c;
    /* 0x58a374 */ mov x0, x2;
    /* 0x58a378 */ b #0xa2c214;
    /* 0x58a37c */ fmov s0, #1.00000000;
    return x0;
}
