// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b53c
// Recovered Name: sub_57b53c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b53c | Size: 20 bytes | SHA256: 01a88f5f839187f70eb3175e9451da7fad1f9ed7e3573ef124e415e5d85024a7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetPreviewSize(JII)V (table at 0x10ce840)

jlong sub_57b53c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b53c */ cbz x2, #0x57b54c;
    /* 0x57b540 */ mov w8, w3;
    /* 0x57b544 */ orr x8, x8, x4, lsl #32;
    /* 0x57b548 */ stur x8, [x2, #0xc];
    return x0;
}
