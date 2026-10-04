// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d81c
// Recovered Name: sub_57d81c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d81c | Size: 36 bytes | SHA256: 54d926d05338b484c86fd0689fa07ad33102294f4f91a8875c17d68d4fa8e868
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerAdsorbDatumLines(JIII)V (table at 0x10cf0e0)

jlong sub_57d81c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x57d81c */ cbz x2, #0x57d83c;
    /* 0x57d820 */ ldr w8, [x2, #0x50];
    /* 0x57d824 */ cmp w8, w3;
    /* 0x57d828 */ b.le #0x57d83c;
    /* 0x57d82c */ mov w8, w4;
    /* 0x57d830 */ add x9, x2, w3, sxtw #3;
    /* 0x57d834 */ orr x8, x8, x5, lsl #32;
    /* 0x57d838 */ stur x8, [x9, #0x54];
    return x0;
}
