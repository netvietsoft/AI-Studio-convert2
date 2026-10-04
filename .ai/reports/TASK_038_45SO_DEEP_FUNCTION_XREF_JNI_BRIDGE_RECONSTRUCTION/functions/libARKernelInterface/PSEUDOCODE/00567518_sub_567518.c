// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567518
// Recovered Name: sub_567518
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567518 | Size: 20 bytes | SHA256: 361dea8d362bad301545ad75f6716a3d9e0d1243be2565687a4bc44652a2ec04
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsWithoutCache(J)Z (table at 0x10cca40)

jlong sub_567518(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567518 */ cbz x2, #0x567524;
    /* 0x56751c */ ldrb w0, [x2, #8];
    return x0;
    /* 0x567524 */ mov w0, wzr;
    return x0;
}
