// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a9ec
// Recovered Name: sub_56a9ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a9ec | Size: 60 bytes | SHA256: c31835c9822e4f9eac2b52a5b87e4ab177b3ffbc6e3631ef20c6e0f17c4a062a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetSkin(JI)I (table at 0x10ccf80)

jlong sub_56a9ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x56a9ec */ mov w0, #-1;
    /* 0x56a9f0 */ cbz x2, #0x56aa24;
    /* 0x56a9f4 */ cmp w3, #0x13;
    /* 0x56a9f8 */ b.hi #0x56aa24;
    /* 0x56a9fc */ mov w8, #0x5c0;
    /* 0x56aa00 */ umaddl x8, w3, w8, x2;
    /* 0x56aa04 */ ldrb w8, [x8, #0x5d0];
    /* 0x56aa08 */ cbz w8, #0x56aa24;
    /* 0x56aa0c */ mov w8, w3;
    /* 0x56aa10 */ mov w9, #0x5c0;
    /* 0x56aa14 */ umaddl x8, w8, w9, x2;
    return x0;
}
