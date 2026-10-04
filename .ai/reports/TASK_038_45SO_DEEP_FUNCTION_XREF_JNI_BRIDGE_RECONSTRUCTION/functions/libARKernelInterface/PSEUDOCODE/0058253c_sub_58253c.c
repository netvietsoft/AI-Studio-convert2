// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58253c
// Recovered Name: sub_58253c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58253c | Size: 32 bytes | SHA256: 3f5450a1130e5eca89b5dd9db5e0344c63c27ad3c27f36381b8204f145ed8d2f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetRotate(J)F (table at 0x10cf518)

jlong sub_58253c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x58253c */ cbz x2, #0x582554;
    /* 0x582540 */ ldr x0, [x2, #0x380];
    /* 0x582544 */ cbz x0, #0x58255c;
    /* 0x582548 */ ldr x8, [x0];
    /* 0x58254c */ ldr x1, [x8, #0x30];
    /* 0x582550 */ br x1;
    /* 0x582554 */ movi d0, #0000000000000000;
    return x0;
}
