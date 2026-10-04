// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5771cc
// Recovered Name: sub_5771cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5771cc | Size: 16 bytes | SHA256: b4617d79798347e725cd2799828c1310c4dd6a71bff4d94aad06a28be62755d1
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeClearCallbackPartCallbackObject(J)V (table at 0x10cdc58)

jlong sub_5771cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x5771cc */ cbz x2, #0x5771d8;
    /* 0x5771d0 */ mov x0, x2;
    /* 0x5771d4 */ b #0x57484c;
    return x0;
}
