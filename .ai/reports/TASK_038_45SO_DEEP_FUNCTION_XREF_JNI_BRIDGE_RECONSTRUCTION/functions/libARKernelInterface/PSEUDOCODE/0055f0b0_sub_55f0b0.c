// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55f0b0
// Recovered Name: sub_55f0b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55f0b0 | Size: 28 bytes | SHA256: 1b71d082b64f555b929fc3e33f1ab4892e1741a7c24d06d98948d89060f91c4d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLandmark2D(JI)[F (table at 0x10cc2a8)

jlong sub_55f0b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x55f0b0 */ cbz x2, #0x55f138;
    /* 0x55f0b4 */ cmp w3, #9;
    /* 0x55f0b8 */ b.hi #0x55f138;
    /* 0x55f0bc */ mov w8, #0x140;
    /* 0x55f0c0 */ umaddl x8, w3, w8, x2;
    /* 0x55f0c4 */ ldrb w8, [x8, #0x44];
    /* 0x55f0c8 */ cbz w8, #0x55f138;
}
