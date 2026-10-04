// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572818
// Recovered Name: sub_572818
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572818 | Size: 28 bytes | SHA256: 1726618030c203bef923d2b580340f51eb9bfc490cc566730c8812d1ecd1089e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHandKeyPoints(JI)[F (table at 0x10cd898)

jlong sub_572818(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x572818 */ cbz x2, #0x5728a0;
    /* 0x57281c */ cmp w3, #9;
    /* 0x572820 */ b.hi #0x5728a0;
    /* 0x572824 */ mov w8, #0xec;
    /* 0x572828 */ umaddl x8, w3, w8, x2;
    /* 0x57282c */ ldrb w8, [x8, #0x58];
    /* 0x572830 */ cbz w8, #0x5728a0;
}
