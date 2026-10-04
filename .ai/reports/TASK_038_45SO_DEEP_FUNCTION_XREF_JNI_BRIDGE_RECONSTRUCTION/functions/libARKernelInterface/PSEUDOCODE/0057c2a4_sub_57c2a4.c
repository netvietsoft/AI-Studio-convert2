// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c2a4
// Recovered Name: sub_57c2a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c2a4 | Size: 52 bytes | SHA256: b568fc004b72d67a7cda9797b6edd59926a89341c52b27049ab815bf7e089eb2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetShoulderRectScore(JI)F (table at 0x10cea68)

jlong sub_57c2a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x57c2a4 */ movi d0, #0000000000000000;
    /* 0x57c2a8 */ cbz x2, #0x57c2d4;
    /* 0x57c2ac */ cmp w3, #9;
    /* 0x57c2b0 */ b.hi #0x57c2d4;
    /* 0x57c2b4 */ mov w8, #0xa0;
    /* 0x57c2b8 */ umaddl x8, w3, w8, x2;
    /* 0x57c2bc */ ldrb w8, [x8, #0x34];
    /* 0x57c2c0 */ cbz w8, #0x57c2d4;
    /* 0x57c2c4 */ mov w8, w3;
    /* 0x57c2c8 */ mov w9, #0xa0;
    /* 0x57c2cc */ umaddl x8, w8, w9, x2;
    return x0;
}
