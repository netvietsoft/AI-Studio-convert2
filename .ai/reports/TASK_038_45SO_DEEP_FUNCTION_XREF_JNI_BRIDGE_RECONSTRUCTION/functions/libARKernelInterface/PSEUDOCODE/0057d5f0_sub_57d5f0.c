// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d5f0
// Recovered Name: sub_57d5f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d5f0 | Size: 20 bytes | SHA256: 7cae5ca1bc28125bb9f45f8a25ab0f21892809284653925b7e3311a865b5f213
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetClickEventDistanceValue(J)I (table at 0x10cedc8)

jlong sub_57d5f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d5f0 */ cbz x2, #0x57d5fc;
    /* 0x57d5f4 */ ldr w0, [x2, #0x10];
    return x0;
    /* 0x57d5fc */ mov w0, wzr;
    return x0;
}
