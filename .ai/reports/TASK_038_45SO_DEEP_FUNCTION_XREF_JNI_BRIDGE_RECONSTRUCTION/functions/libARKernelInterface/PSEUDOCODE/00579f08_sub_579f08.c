// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579f08
// Recovered Name: sub_579f08
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579f08 | Size: 16 bytes | SHA256: 13c537c58fce981821ece2ea05833e45afdc4f177800f8349a09905672f4fd11
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeControlResetState(J)V (table at 0x10ce480)

jlong sub_579f08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x579f08 */ cbz x2, #0x579f14;
    /* 0x579f0c */ mov x0, x2;
    /* 0x579f10 */ b #0x90a7cc;
    return x0;
}
