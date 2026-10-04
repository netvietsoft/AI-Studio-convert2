// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a698
// Recovered Name: sub_58a698
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a698 | Size: 20 bytes | SHA256: 2050178b81bf930713dfa20dfb5808c3a247430b1db0831dade5cbe78fb93d24
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultValue(J)F (table at 0x10d0430)

jlong sub_58a698(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a698 */ cbz x2, #0x58a6a4;
    /* 0x58a69c */ mov x0, x2;
    /* 0x58a6a0 */ b #0xa2d4e8;
    /* 0x58a6a4 */ movi d0, #0000000000000000;
    return x0;
}
