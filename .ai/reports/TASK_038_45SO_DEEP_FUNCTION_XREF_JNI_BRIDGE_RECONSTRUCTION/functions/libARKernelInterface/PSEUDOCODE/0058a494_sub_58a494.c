// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a494
// Recovered Name: sub_58a494
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a494 | Size: 20 bytes | SHA256: d55c913d4ba6a1cf8cbfb0e0a1d7246f77ac0e49480faba110afd8ed2bdcd4c0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMinHValue(J)F (table at 0x10d0298)

jlong sub_58a494(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a494 */ cbz x2, #0x58a4a0;
    /* 0x58a498 */ mov x0, x2;
    /* 0x58a49c */ b #0xa2c2bc;
    /* 0x58a4a0 */ fmov s0, #1.00000000;
    return x0;
}
