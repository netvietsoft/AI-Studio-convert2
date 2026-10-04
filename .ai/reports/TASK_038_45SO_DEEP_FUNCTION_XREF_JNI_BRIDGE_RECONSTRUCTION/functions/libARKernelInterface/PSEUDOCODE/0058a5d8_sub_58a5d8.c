// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a5d8
// Recovered Name: sub_58a5d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a5d8 | Size: 20 bytes | SHA256: d5aa5282c1d98621e643f7fe649eaaf1d165150db087f317e17e64e84077c845
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultW(J)F (table at 0x10d03b8)

jlong sub_58a5d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a5d8 */ cbz x2, #0x58a5e4;
    /* 0x58a5dc */ mov x0, x2;
    /* 0x58a5e0 */ b #0xa2d4a4;
    /* 0x58a5e4 */ movi d0, #0000000000000000;
    return x0;
}
