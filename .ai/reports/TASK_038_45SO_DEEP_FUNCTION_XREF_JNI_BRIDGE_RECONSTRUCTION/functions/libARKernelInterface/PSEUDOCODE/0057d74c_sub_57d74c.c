// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d74c
// Recovered Name: sub_57d74c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d74c | Size: 20 bytes | SHA256: 3cd7db222d4389bc5684f07eb08c1986811e9f25a83289d52eb494947a877dbf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerMarginLimitOnlyMove(JZ)V (table at 0x10cefc0)

jlong sub_57d74c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d74c */ cbz x2, #0x57d75c;
    /* 0x57d750 */ tst w3, #0xff;
    /* 0x57d754 */ cset w8, ne;
    /* 0x57d758 */ strb w8, [x2, #0x3c];
    return x0;
}
