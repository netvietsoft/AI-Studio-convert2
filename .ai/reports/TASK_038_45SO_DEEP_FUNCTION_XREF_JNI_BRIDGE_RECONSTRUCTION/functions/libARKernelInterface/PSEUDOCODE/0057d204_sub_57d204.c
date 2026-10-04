// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d204
// Recovered Name: sub_57d204
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d204 | Size: 12 bytes | SHA256: e27dab6673c9f68a103003dd6bd22b3f7a02ab3b334ef57a9643b2612a349705
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTimeLineType(JI)V (table at 0x10cec78)

jlong sub_57d204(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d204 */ cbz x2, #0x57d20c;
    /* 0x57d208 */ str w3, [x2, #0xc];
    return x0;
}
