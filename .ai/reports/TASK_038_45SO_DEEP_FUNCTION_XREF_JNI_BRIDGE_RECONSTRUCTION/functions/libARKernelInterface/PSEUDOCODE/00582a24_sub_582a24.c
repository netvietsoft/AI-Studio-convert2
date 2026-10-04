// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x582a24
// Recovered Name: sub_582a24
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x582a24 | Size: 32 bytes | SHA256: 6b71f65649224c3f1db6086f01b767daf393357f4f2a86cb1c803c86a982e04a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetBlendMode(J)I (table at 0x10cf650)

jlong sub_582a24(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x582a24 */ cbz x2, #0x582a3c;
    /* 0x582a28 */ ldr x0, [x2, #0x740];
    /* 0x582a2c */ cbz x0, #0x582a44;
    /* 0x582a30 */ ldr x8, [x0];
    /* 0x582a34 */ ldr x1, [x8, #0x30];
    /* 0x582a38 */ br x1;
    /* 0x582a3c */ mov w0, wzr;
    return x0;
}
