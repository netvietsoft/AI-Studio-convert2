// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55ee5c
// Recovered Name: sub_55ee5c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55ee5c | Size: 52 bytes | SHA256: 6ccff026342199de2d105bd7ccb73fe0461e1f915d2476352eb7dff62d415a2c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetAnimalID(JI)I (table at 0x10cc248)

jlong sub_55ee5c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x55ee5c */ mov w0, #-1;
    /* 0x55ee60 */ cbz x2, #0x55ee8c;
    /* 0x55ee64 */ cmp w3, #9;
    /* 0x55ee68 */ b.hi #0x55ee8c;
    /* 0x55ee6c */ mov w8, #0x140;
    /* 0x55ee70 */ umaddl x8, w3, w8, x2;
    /* 0x55ee74 */ ldrb w8, [x8, #0x20];
    /* 0x55ee78 */ cbz w8, #0x55ee8c;
    /* 0x55ee7c */ mov w8, w3;
    /* 0x55ee80 */ mov w9, #0x140;
    /* 0x55ee84 */ umaddl x8, w8, w9, x2;
    return x0;
}
