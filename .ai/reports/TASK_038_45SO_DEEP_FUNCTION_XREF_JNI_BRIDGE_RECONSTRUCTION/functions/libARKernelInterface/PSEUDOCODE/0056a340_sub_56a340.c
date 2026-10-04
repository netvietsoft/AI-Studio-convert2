// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a340
// Recovered Name: sub_56a340
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a340 | Size: 28 bytes | SHA256: 08d9bdc8a23813cc35d8e82096221519fa7a4919b45f55fb3dfd1ffafa06b7f8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetRightEarPointCount2D(JII)V (table at 0x10cd148)

jlong sub_56a340(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56a340 */ cbz x2, #0x56a358;
    /* 0x56a344 */ cmp w3, #0x13;
    /* 0x56a348 */ b.hi #0x56a358;
    /* 0x56a34c */ mov w8, #0x5c0;
    /* 0x56a350 */ umaddl x8, w3, w8, x2;
    /* 0x56a354 */ str w4, [x8, #0x1d0];
    return x0;
}
