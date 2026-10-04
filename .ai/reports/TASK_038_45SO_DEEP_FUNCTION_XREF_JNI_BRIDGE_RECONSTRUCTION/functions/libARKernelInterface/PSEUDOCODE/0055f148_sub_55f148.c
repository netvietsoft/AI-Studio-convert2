// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55f148
// Recovered Name: sub_55f148
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55f148 | Size: 36 bytes | SHA256: 7cf969d214d18e759e733d3d007ab5551dc2f34ff80c96222713800a68e6c59a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetAnimalLabel(JII)V (table at 0x10cc2c0)

jlong sub_55f148(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x55f148 */ cbz x2, #0x55f168;
    /* 0x55f14c */ cmp w3, #9;
    /* 0x55f150 */ b.hi #0x55f168;
    /* 0x55f154 */ mov w8, #0x140;
    /* 0x55f158 */ mov w9, #1;
    /* 0x55f15c */ umaddl x8, w3, w8, x2;
    /* 0x55f160 */ strb w9, [x8, #0x18];
    /* 0x55f164 */ str w4, [x8, #0x1c];
    return x0;
}
