// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x568c2c
// Recovered Name: sub_568c2c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x568c2c | Size: 20 bytes | SHA256: 361dea8d362bad301545ad75f6716a3d9e0d1243be2565687a4bc44652a2ec04
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsWithoutCache(J)Z (table at 0x10cccb0)

jlong sub_568c2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x568c2c */ cbz x2, #0x568c38;
    /* 0x568c30 */ ldrb w0, [x2, #8];
    return x0;
    /* 0x568c38 */ mov w0, wzr;
    return x0;
}
