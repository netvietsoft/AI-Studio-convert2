// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55e49c
// Recovered Name: sub_55e49c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55e49c | Size: 32 bytes | SHA256: 3a0348e8caaf6965846fb0aaedfee2a26e03c247aeb70f9cc24f6c5ab0d3a205
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetImageOrVideoChanged(JZ)V (table at 0x10cc1a0)

jlong sub_55e49c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x55e49c */ cbz x2, #0x55e4b8;
    /* 0x55e4a0 */ ldr x0, [x2];
    /* 0x55e4a4 */ cbz x0, #0x55e4b8;
    /* 0x55e4a8 */ and w8, w3, #0xff;
    /* 0x55e4ac */ cmp w8, #1;
    /* 0x55e4b0 */ cset w1, eq;
    /* 0x55e4b4 */ b #0x6081ac;
    return x0;
}
