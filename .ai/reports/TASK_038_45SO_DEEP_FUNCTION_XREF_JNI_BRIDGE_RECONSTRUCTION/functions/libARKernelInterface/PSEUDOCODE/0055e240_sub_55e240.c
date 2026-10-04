// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55e240
// Recovered Name: sub_55e240
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55e240 | Size: 12 bytes | SHA256: 3415799fd669625351d4d184a96c120af45c3c67ce086bddab5338b8510ba5c8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetEnableQNN(J)Z (table at 0x10cc158)

jlong sub_55e240(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x55e240 */ cbz x2, #0x55e264;
    /* 0x55e244 */ ldr x0, [x2];
    /* 0x55e248 */ cbz x0, #0x55e260;
}
