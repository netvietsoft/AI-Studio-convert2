// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x582c04
// Recovered Name: sub_582c04
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x582c04 | Size: 32 bytes | SHA256: 46be58cf4627ba7a740c4ff73ac93800fb5c5c5aff655934758848aae697444f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeAppendAnimation(J)J (table at 0x10cf6b0)

jlong sub_582c04(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x582c04 */ cbz x2, #0x582c1c;
    /* 0x582c08 */ ldr x0, [x2, #0xad0];
    /* 0x582c0c */ cbz x0, #0x582c1c;
    /* 0x582c10 */ ldr x8, [x0];
    /* 0x582c14 */ ldr x1, [x8, #0x30];
    /* 0x582c18 */ br x1;
    /* 0x582c1c */ mov x0, xzr;
    return x0;
}
