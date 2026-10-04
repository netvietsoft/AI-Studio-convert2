// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a518
// Recovered Name: sub_58a518
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a518 | Size: 16 bytes | SHA256: c27370d44fcf6e1310fdd899735b544a82b87fe8a5d0b1bd8bfbe3eb52261cc3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValueXYZ(JFFF)V (table at 0x10d02c8)

jlong sub_58a518(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a518 */ cbz x2, #0x58a524;
    /* 0x58a51c */ mov x0, x2;
    /* 0x58a520 */ b #0xa2d3e4;
    return x0;
}
