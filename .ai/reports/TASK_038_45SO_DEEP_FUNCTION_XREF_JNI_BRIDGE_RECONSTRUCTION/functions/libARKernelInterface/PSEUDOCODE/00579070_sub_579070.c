// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579070
// Recovered Name: sub_579070
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579070 | Size: 20 bytes | SHA256: e4adb3390fbdb135fa4c790f159ae1199f02bd355481e02d2929c744b3d9446e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetPartControlLayer(JI)V (table at 0x10ce1b0)

jlong sub_579070(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579070 */ cbz x2, #0x579080;
    /* 0x579074 */ mov x0, x2;
    /* 0x579078 */ mov w1, w3;
    /* 0x57907c */ b #0x8e0a00;
    return x0;
}
