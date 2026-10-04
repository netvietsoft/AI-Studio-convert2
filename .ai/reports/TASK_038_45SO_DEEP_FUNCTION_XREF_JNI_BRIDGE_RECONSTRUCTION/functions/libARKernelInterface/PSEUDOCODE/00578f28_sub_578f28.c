// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x578f28
// Recovered Name: sub_578f28
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x578f28 | Size: 24 bytes | SHA256: 45e12d56581aeba94de8c20e225499e222ee35a4cd6bfe1f50015069e82f4d7e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeRelease(J)V (table at 0x10ce120)

jlong sub_578f28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x578f28 */ cbz x2, #0x578f3c;
    /* 0x578f2c */ ldr x8, [x2];
    /* 0x578f30 */ mov x0, x2;
    /* 0x578f34 */ ldr x1, [x8, #0x30];
    /* 0x578f38 */ br x1;
    return x0;
}
