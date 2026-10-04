// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d72c
// Recovered Name: sub_57d72c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d72c | Size: 12 bytes | SHA256: b69c578dde5c213a65156646a04001dafe042c77423c0f711dab8eafe30998eb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerMarginMinValue(JI)V (table at 0x10cef90)

jlong sub_57d72c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d72c */ cbz x2, #0x57d734;
    /* 0x57d730 */ str w3, [x2, #0x38];
    return x0;
}
