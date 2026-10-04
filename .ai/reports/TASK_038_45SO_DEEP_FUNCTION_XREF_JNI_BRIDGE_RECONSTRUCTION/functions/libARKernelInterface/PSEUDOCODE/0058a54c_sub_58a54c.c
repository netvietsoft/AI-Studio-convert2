// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a54c
// Recovered Name: sub_58a54c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a54c | Size: 20 bytes | SHA256: 5ff960b932ae654610b671835f420c97c84e5c54cbabd1a5143fef7c536cb277
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentX(J)F (table at 0x10d0310)

jlong sub_58a54c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a54c */ cbz x2, #0x58a558;
    /* 0x58a550 */ mov x0, x2;
    /* 0x58a554 */ b #0xa2d46c;
    /* 0x58a558 */ movi d0, #0000000000000000;
    return x0;
}
