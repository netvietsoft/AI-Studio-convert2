// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577b24
// Recovered Name: sub_577b24
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577b24 | Size: 20 bytes | SHA256: c5c316227d51c8a1aec6677d7ff63ad4f8885dafdef15366c55cc7f9d03b0f65
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNativeData(JJ)V (table at 0x10cde08)

jlong sub_577b24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x577b24 */ cbz x2, #0x577b34;
    /* 0x577b28 */ mov x0, x2;
    /* 0x577b2c */ mov x1, x3;
    /* 0x577b30 */ b #0x5754c4;
    return x0;
}
