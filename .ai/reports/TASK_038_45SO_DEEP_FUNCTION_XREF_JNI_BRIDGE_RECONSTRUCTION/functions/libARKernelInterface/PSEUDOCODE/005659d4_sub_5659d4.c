// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5659d4
// Recovered Name: sub_5659d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5659d4 | Size: 40 bytes | SHA256: 413242804db9b5c978b0569c42c431c58f2173e7712b2a07b82e2a60c70946bc
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetErrorCode(JI)I (table at 0x10cc7b8)

jlong sub_5659d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x5659d4 */ cbz x2, #0x5659f4;
    /* 0x5659d8 */ ldr w8, [x2, #0xc];
    /* 0x5659dc */ cmp w8, w3;
    /* 0x5659e0 */ b.le #0x5659f4;
    /* 0x5659e4 */ mov w8, #0x198;
    /* 0x5659e8 */ smaddl x8, w3, w8, x2;
    /* 0x5659ec */ ldr w0, [x8, #0x14];
    return x0;
    /* 0x5659f4 */ mov w0, wzr;
    return x0;
}
