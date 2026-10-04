// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a974
// Recovered Name: sub_56a974
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a974 | Size: 60 bytes | SHA256: 407d129e32f4cba82b3eed162bf3a55777fa83f6bb8beae7e0c0e3af918b87d9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetRace(JI)I (table at 0x10ccf50)

jlong sub_56a974(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x56a974 */ mov w0, #-1;
    /* 0x56a978 */ cbz x2, #0x56a9ac;
    /* 0x56a97c */ cmp w3, #0x13;
    /* 0x56a980 */ b.hi #0x56a9ac;
    /* 0x56a984 */ mov w8, #0x5c0;
    /* 0x56a988 */ umaddl x8, w3, w8, x2;
    /* 0x56a98c */ ldrb w8, [x8, #0x5c8];
    /* 0x56a990 */ cbz w8, #0x56a9ac;
    /* 0x56a994 */ mov w8, w3;
    /* 0x56a998 */ mov w9, #0x5c0;
    /* 0x56a99c */ umaddl x8, w8, w9, x2;
    return x0;
}
