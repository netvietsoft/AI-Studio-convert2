// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579020
// Recovered Name: sub_579020
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579020 | Size: 20 bytes | SHA256: c3dbcadf4600e00688e9fc19490c4ebf4cef6e11705c662ef83a468fe41f9df8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPartType(J)I (table at 0x10ce150)

jlong sub_579020(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579020 */ cbz x2, #0x57902c;
    /* 0x579024 */ mov x0, x2;
    /* 0x579028 */ b #0x8e0920;
    /* 0x57902c */ mov w0, wzr;
    return x0;
}
