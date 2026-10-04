// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a2f8
// Recovered Name: sub_57a2f8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a2f8 | Size: 16 bytes | SHA256: 249096a93db8278165736e150de89dac77a768fc809498e0ede642be2699afaa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativePlayBGM(J)V (table at 0x10ce570)

jlong sub_57a2f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57a2f8 */ cbz x2, #0x57a304;
    /* 0x57a2fc */ mov x0, x2;
    /* 0x57a300 */ b #0x90ab88;
    return x0;
}
