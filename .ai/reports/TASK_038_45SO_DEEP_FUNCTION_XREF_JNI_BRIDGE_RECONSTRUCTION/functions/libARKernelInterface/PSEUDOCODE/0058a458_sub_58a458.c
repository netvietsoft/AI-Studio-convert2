// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a458
// Recovered Name: sub_58a458
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a458 | Size: 20 bytes | SHA256: 8e724d16723991dd5f0e53da7aea94d88a8dfa7edc444b28af1a4357927fcdbf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultAlpha(J)F (table at 0x10d0250)

jlong sub_58a458(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a458 */ cbz x2, #0x58a464;
    /* 0x58a45c */ mov x0, x2;
    /* 0x58a460 */ b #0xa2c2a4;
    /* 0x58a464 */ fmov s0, #1.00000000;
    return x0;
}
