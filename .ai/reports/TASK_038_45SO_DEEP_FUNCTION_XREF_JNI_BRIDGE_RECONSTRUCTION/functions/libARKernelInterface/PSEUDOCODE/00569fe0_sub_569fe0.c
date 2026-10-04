// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x569fe0
// Recovered Name: sub_569fe0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x569fe0 | Size: 36 bytes | SHA256: 5c603877e253147cbcc3b247933a9e31b790899a38f2862d712919869e982e47
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceID(JII)V (table at 0x10ccde8)

jlong sub_569fe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x569fe0 */ cbz x2, #0x56a000;
    /* 0x569fe4 */ cmp w3, #0x13;
    /* 0x569fe8 */ b.hi #0x56a000;
    /* 0x569fec */ mov w8, #0x5c0;
    /* 0x569ff0 */ mov w9, #1;
    /* 0x569ff4 */ umaddl x8, w3, w8, x2;
    /* 0x569ff8 */ strb w9, [x8, #0x28];
    /* 0x569ffc */ str w4, [x8, #0x2c];
    return x0;
}
