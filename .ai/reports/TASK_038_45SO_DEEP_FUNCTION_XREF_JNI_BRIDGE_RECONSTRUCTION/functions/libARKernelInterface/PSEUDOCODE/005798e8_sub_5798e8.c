// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5798e8
// Recovered Name: sub_5798e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5798e8 | Size: 24 bytes | SHA256: f8e0b8938096334ab60224db39a3f140aae38726f169335a1202b6eaa089b8e7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeClearFaceIDAlpha(J)V (table at 0x10ce348)

jlong sub_5798e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x5798e8 */ cbz x2, #0x5798fc;
    /* 0x5798ec */ ldr x8, [x2];
    /* 0x5798f0 */ mov x0, x2;
    /* 0x5798f4 */ ldr x1, [x8, #0x60];
    /* 0x5798f8 */ br x1;
    return x0;
}
