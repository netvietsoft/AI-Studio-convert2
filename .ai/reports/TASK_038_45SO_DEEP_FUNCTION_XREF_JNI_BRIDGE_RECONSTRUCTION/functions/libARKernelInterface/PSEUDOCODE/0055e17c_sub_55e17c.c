// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55e17c
// Recovered Name: sub_55e17c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55e17c | Size: 12 bytes | SHA256: 3415799fd669625351d4d184a96c120af45c3c67ce086bddab5338b8510ba5c8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetEnableMakeupAdapt(J)Z (table at 0x10cc128)

jlong sub_55e17c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x55e17c */ cbz x2, #0x55e1a0;
    /* 0x55e180 */ ldr x0, [x2];
    /* 0x55e184 */ cbz x0, #0x55e19c;
}
