// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a908
// Recovered Name: sub_56a908
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a908 | Size: 64 bytes | SHA256: 6c9c28029e34caba8df42606b826206d714eb3af423fb13783743f000807a0c4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetGender(JI)I (table at 0x10ccf20)

jlong sub_56a908(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x56a908 */ mov w0, #-1;
    /* 0x56a90c */ cbz x2, #0x56a944;
    /* 0x56a910 */ cmp w3, #0x13;
    /* 0x56a914 */ b.hi #0x56a944;
    /* 0x56a918 */ mov w8, #0x5c0;
    /* 0x56a91c */ umaddl x8, w3, w8, x2;
    /* 0x56a920 */ ldrb w8, [x8, #0x70];
    /* 0x56a924 */ cbz w8, #0x56a944;
    /* 0x56a928 */ mov w8, w3;
    /* 0x56a92c */ mov w9, #0x5c0;
    /* 0x56a930 */ umaddl x8, w8, w9, x2;
    return x0;
}
