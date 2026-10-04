// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d064
// Recovered Name: sub_57d064
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d064 | Size: 28 bytes | SHA256: ddc83c010fe1ec02d1f2e08fdb0b0c09665bccf2b1489c0f14a303ad0ec659e2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextureUserDefineFlag(JI)I (table at 0x10cec18)

jlong sub_57d064(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57d064 */ cbz x2, #0x57d078;
    /* 0x57d068 */ mov w8, #0x64;
    /* 0x57d06c */ smaddl x8, w3, w8, x2;
    /* 0x57d070 */ ldr w0, [x8, #0x60];
    return x0;
    /* 0x57d078 */ mov w0, wzr;
    return x0;
}
