// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d944
// Recovered Name: sub_56d944
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d944 | Size: 36 bytes | SHA256: 7a3459dbe4cc500ebe272b1b3f37143dfa05a418f8a82680e215ca2cc88f8768
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFoodScore(JIF)V (table at 0x10cd3b8)

jlong sub_56d944(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x56d944 */ cbz x2, #0x56d964;
    /* 0x56d948 */ cmp w3, #9;
    /* 0x56d94c */ b.hi #0x56d964;
    /* 0x56d950 */ mov w8, #0x34;
    /* 0x56d954 */ mov w9, #1;
    /* 0x56d958 */ umaddl x8, w3, w8, x2;
    /* 0x56d95c */ strb w9, [x8, #0x34];
    /* 0x56d960 */ str s0, [x8, #0x38];
    return x0;
}
