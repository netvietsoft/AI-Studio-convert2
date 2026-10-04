// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57162c
// Recovered Name: sub_57162c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57162c | Size: 16 bytes | SHA256: 65d195a8b584a9e2c6b40f5003e096fc9fbe21a7c4251f95d6641b49b02ce5ba
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReplayBGM(J)V (table at 0x10cd718)

jlong sub_57162c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57162c */ cbz x2, #0x571638;
    /* 0x571630 */ mov x0, x2;
    /* 0x571634 */ b #0x89217c;
    return x0;
}
