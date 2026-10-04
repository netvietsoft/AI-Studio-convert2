// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579398
// Recovered Name: sub_579398
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579398 | Size: 20 bytes | SHA256: a04bb93c0b38c172f012d9e590113484b27c24f354df72d0653af39ea2305a80
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetGenderType(JI)V (table at 0x10ce2a0)

jlong sub_579398(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579398 */ cbz x2, #0x5793a8;
    /* 0x57939c */ mov x0, x2;
    /* 0x5793a0 */ mov w1, w3;
    /* 0x5793a4 */ b #0x8e0b00;
    return x0;
}
