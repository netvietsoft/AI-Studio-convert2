// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55f16c
// Recovered Name: sub_55f16c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55f16c | Size: 60 bytes | SHA256: 41e03893e1b760bd0809124c9d33b0fe9d64b18a640b7184ca72d0030b053642
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetAnimalLabel(JI)I (table at 0x10cc2d8)

jlong sub_55f16c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x55f16c */ mov w0, wzr;
    /* 0x55f170 */ cbz x2, #0x55f19c;
    /* 0x55f174 */ cmp w3, #9;
    /* 0x55f178 */ b.hi #0x55f19c;
    /* 0x55f17c */ mov w8, #0x140;
    /* 0x55f180 */ umaddl x8, w3, w8, x2;
    /* 0x55f184 */ ldrb w8, [x8, #0x18];
    /* 0x55f188 */ cbz w8, #0x55f1a0;
    /* 0x55f18c */ mov w8, w3;
    /* 0x55f190 */ mov w9, #0x140;
    /* 0x55f194 */ umaddl x8, w8, w9, x2;
    return x0;
    return x0;
}
