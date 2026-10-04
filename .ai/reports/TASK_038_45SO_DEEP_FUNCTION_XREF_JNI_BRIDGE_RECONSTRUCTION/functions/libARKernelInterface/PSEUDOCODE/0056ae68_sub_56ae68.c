// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56ae68
// Recovered Name: sub_56ae68
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56ae68 | Size: 28 bytes | SHA256: 24a9bb4c39a27a3a4f6e82900fd5d5ec037ee74771dbbb513c8bedd621c962a0
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetNeckPoints(JI)[F (table at 0x10cd070)

jlong sub_56ae68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56ae68 */ cbz x2, #0x56aef0;
    /* 0x56ae6c */ cmp w3, #0x13;
    /* 0x56ae70 */ b.hi #0x56aef0;
    /* 0x56ae74 */ mov w8, #0x5c0;
    /* 0x56ae78 */ umaddl x8, w3, w8, x2;
    /* 0x56ae7c */ ldrb w8, [x8, #0xb8];
    /* 0x56ae80 */ cbz w8, #0x56aef0;
}
