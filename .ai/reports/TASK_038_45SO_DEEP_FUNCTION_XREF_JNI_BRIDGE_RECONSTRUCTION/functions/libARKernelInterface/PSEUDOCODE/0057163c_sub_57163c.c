// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57163c
// Recovered Name: sub_57163c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57163c | Size: 16 bytes | SHA256: 5198b16459209aabcd4211bbf6ac5759bdb058beb1a96581e5ebdbd5b4629ad8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeStopBGM(J)V (table at 0x10cd730)

jlong sub_57163c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57163c */ cbz x2, #0x571648;
    /* 0x571640 */ mov x0, x2;
    /* 0x571644 */ b #0x8921ac;
    return x0;
}
