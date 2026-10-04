// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a2b4
// Recovered Name: sub_57a2b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a2b4 | Size: 28 bytes | SHA256: 53095c5af7853db6204a7b4df31d41bd293d414b3dad01f8909ea51ac21fac46
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetApply(JZ)V (table at 0x10ce540)

jlong sub_57a2b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57a2b4 */ cbz x2, #0x57a2cc;
    /* 0x57a2b8 */ and w8, w3, #0xff;
    /* 0x57a2bc */ mov x0, x2;
    /* 0x57a2c0 */ cmp w8, #1;
    /* 0x57a2c4 */ cset w1, eq;
    /* 0x57a2c8 */ b #0x90aa74;
    return x0;
}
