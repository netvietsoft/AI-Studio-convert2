// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a480
// Recovered Name: sub_58a480
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a480 | Size: 20 bytes | SHA256: 6ed476fd9a538b1f07953110505a946a47ceb9a27f7b41abcf85268e144df62d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMaxHValue(J)F (table at 0x10d0280)

jlong sub_58a480(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a480 */ cbz x2, #0x58a48c;
    /* 0x58a484 */ mov x0, x2;
    /* 0x58a488 */ b #0xa2c2b4;
    /* 0x58a48c */ fmov s0, #1.00000000;
    return x0;
}
