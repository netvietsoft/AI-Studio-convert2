// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5676b8
// Recovered Name: sub_5676b8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5676b8 | Size: 20 bytes | SHA256: 641b22924eb8ac64ac2931405aa9152ffad3cde905e845a4df1d1840c18d4bc7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceID(JII)V (table at 0x10ccbc0)

jlong sub_5676b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5676b8 */ cbz x2, #0x5676c8;
    /* 0x5676bc */ mov w8, #0x88;
    /* 0x5676c0 */ smaddl x8, w3, w8, x2;
    /* 0x5676c4 */ str w4, [x8, #0x14];
    return x0;
}
