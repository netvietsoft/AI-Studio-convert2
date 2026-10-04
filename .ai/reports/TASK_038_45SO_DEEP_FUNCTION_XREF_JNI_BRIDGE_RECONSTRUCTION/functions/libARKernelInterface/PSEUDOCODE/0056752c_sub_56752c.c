// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56752c
// Recovered Name: sub_56752c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56752c | Size: 12 bytes | SHA256: e27dab6673c9f68a103003dd6bd22b3f7a02ab3b334ef57a9643b2612a349705
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceCount(JI)V (table at 0x10cca58)

jlong sub_56752c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56752c */ cbz x2, #0x567534;
    /* 0x567530 */ str w3, [x2, #0xc];
    return x0;
}
