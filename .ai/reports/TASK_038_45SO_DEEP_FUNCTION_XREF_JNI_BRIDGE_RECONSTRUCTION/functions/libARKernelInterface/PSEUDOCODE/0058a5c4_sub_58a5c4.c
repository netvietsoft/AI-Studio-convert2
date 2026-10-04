// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a5c4
// Recovered Name: sub_58a5c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a5c4 | Size: 20 bytes | SHA256: 0e92fafe915951d95dadd1e15138af6bfd5378dd7795416a84f5f4037ea882ec
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultZ(J)F (table at 0x10d03a0)

jlong sub_58a5c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a5c4 */ cbz x2, #0x58a5d0;
    /* 0x58a5c8 */ mov x0, x2;
    /* 0x58a5cc */ b #0xa2d49c;
    /* 0x58a5d0 */ movi d0, #0000000000000000;
    return x0;
}
