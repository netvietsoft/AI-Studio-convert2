// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c2f4
// Recovered Name: sub_57c2f4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c2f4 | Size: 52 bytes | SHA256: 632eb1c8e65b8ab4b847107fc3fdbcb66e41adc4368f3514ef00e853cbd30b9e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetShoulderPointThreshold(JI)F (table at 0x10cea80)

jlong sub_57c2f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x57c2f4 */ movi d0, #0000000000000000;
    /* 0x57c2f8 */ cbz x2, #0x57c324;
    /* 0x57c2fc */ cmp w3, #9;
    /* 0x57c300 */ b.hi #0x57c324;
    /* 0x57c304 */ mov w8, #0xa0;
    /* 0x57c308 */ umaddl x8, w3, w8, x2;
    /* 0x57c30c */ ldrb w8, [x8, #0xb0];
    /* 0x57c310 */ cbz w8, #0x57c324;
    /* 0x57c314 */ mov w8, w3;
    /* 0x57c318 */ mov w9, #0xa0;
    /* 0x57c31c */ umaddl x8, w8, w9, x2;
    return x0;
}
