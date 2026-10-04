// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ba24
// Recovered Name: sub_58ba24
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58ba24 | Size: 20 bytes | SHA256: 9db115556cc8d8ab2669d951c31d51d1aa4d2638f62183cc9faa047de3c00c26
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentValue(J)I (table at 0x10d07d8)

jlong sub_58ba24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58ba24 */ cbz x2, #0x58ba30;
    /* 0x58ba28 */ ldr w0, [x2, #0x94];
    return x0;
    /* 0x58ba30 */ mov w0, #-1;
    return x0;
}
