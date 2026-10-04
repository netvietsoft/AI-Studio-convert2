// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579878
// Recovered Name: sub_579878
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579878 | Size: 20 bytes | SHA256: 3fb0fccbfc0107682b5a3dc8c42df645c232f2c734d7b1edded610a309738cec
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceIDAlpha(JIF)V (table at 0x10ce2e8)

jlong sub_579878(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579878 */ cbz x2, #0x579888;
    /* 0x57987c */ mov x0, x2;
    /* 0x579880 */ mov w1, w3;
    /* 0x579884 */ b #0x8e0bd8;
    return x0;
}
