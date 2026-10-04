// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a538
// Recovered Name: sub_58a538
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a538 | Size: 20 bytes | SHA256: 1dbd378709ec12e53f62e308585df464fd3e1c0735e76df2ed0300d5ee16dd4a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPositionType(J)I (table at 0x10d02f8)

jlong sub_58a538(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a538 */ cbz x2, #0x58a544;
    /* 0x58a53c */ mov x0, x2;
    /* 0x58a540 */ b #0xa2d464;
    /* 0x58a544 */ mov w0, wzr;
    return x0;
}
