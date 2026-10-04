// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a574
// Recovered Name: sub_58a574
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a574 | Size: 20 bytes | SHA256: bb917902b3a088ecb920d5edc3518947bd567c74d10df77b168b2282dc695969
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentZ(J)F (table at 0x10d0340)

jlong sub_58a574(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a574 */ cbz x2, #0x58a580;
    /* 0x58a578 */ mov x0, x2;
    /* 0x58a57c */ b #0xa2d47c;
    /* 0x58a580 */ movi d0, #0000000000000000;
    return x0;
}
