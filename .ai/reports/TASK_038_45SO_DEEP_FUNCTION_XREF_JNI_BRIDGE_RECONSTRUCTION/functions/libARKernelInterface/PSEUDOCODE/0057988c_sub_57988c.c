// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57988c
// Recovered Name: sub_57988c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57988c | Size: 24 bytes | SHA256: d63811732e2a4a5f97b50dfc2af6fe3eedf476a7107ce4d5fdc8f70c323f8310
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceIDAlpha(JI)F (table at 0x10ce300)

jlong sub_57988c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x57988c */ cbz x2, #0x57989c;
    /* 0x579890 */ mov x0, x2;
    /* 0x579894 */ mov w1, w3;
    /* 0x579898 */ b #0x8e0be8;
    /* 0x57989c */ fmov s0, #1.00000000;
    return x0;
}
