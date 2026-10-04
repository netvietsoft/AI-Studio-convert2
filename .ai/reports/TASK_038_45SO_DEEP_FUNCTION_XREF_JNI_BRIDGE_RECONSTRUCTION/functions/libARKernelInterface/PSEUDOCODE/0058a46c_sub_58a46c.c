// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a46c
// Recovered Name: sub_58a46c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a46c | Size: 20 bytes | SHA256: c8d8a59a0314c17b40d8bc0c294fc010b211232396181bdb74bc80f2a99a6519
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultOpacity(J)F (table at 0x10d0268)

jlong sub_58a46c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a46c */ cbz x2, #0x58a478;
    /* 0x58a470 */ mov x0, x2;
    /* 0x58a474 */ b #0xa2c2ac;
    /* 0x58a478 */ fmov s0, #1.00000000;
    return x0;
}
