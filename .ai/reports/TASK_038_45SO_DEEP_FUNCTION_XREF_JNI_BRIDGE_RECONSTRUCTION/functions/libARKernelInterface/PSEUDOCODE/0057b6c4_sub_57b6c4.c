// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b6c4
// Recovered Name: sub_57b6c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b6c4 | Size: 20 bytes | SHA256: 5e5d6575459770728c174b01d70a01ef6a30e47bc1d7efbe117f7ba5476da94b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsContinuousInputStream(JZ)V (table at 0x10ce8d0)

jlong sub_57b6c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b6c4 */ cbz x2, #0x57b6d4;
    /* 0x57b6c8 */ tst w3, #0xff;
    /* 0x57b6cc */ cset w8, ne;
    /* 0x57b6d0 */ strb w8, [x2, #0x1d];
    return x0;
}
