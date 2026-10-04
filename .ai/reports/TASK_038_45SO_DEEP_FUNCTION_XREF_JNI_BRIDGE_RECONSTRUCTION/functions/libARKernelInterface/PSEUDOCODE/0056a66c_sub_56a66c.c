// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a66c
// Recovered Name: sub_56a66c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a66c | Size: 28 bytes | SHA256: faca4c9ebcea7de86a85d40498cf4b7b4a2a3c04dcf834c0cb5f44277d00ab18
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFacialLandmark2D(JI)[F (table at 0x10ccec0)

jlong sub_56a66c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56a66c */ cbz x2, #0x56a6f0;
    /* 0x56a670 */ cmp w3, #0x13;
    /* 0x56a674 */ b.hi #0x56a6f0;
    /* 0x56a678 */ mov w8, #0x5c0;
    /* 0x56a67c */ umaddl x8, w3, w8, x2;
    /* 0x56a680 */ ldrb w8, [x8, #0x48];
    /* 0x56a684 */ cbz w8, #0x56a6f0;
}
