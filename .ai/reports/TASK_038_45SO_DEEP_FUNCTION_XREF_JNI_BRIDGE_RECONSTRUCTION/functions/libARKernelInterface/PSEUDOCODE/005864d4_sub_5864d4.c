// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5864d4
// Recovered Name: sub_5864d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5864d4 | Size: 32 bytes | SHA256: c896e710e0764924f632090dc15cfad791bc2567ce71b70a1d9e1ec38b859dd4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFontSize(J)F (table at 0x10cfc20)

jlong sub_5864d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x5864d4 */ cbz x2, #0x5864ec;
    /* 0x5864d8 */ ldr x0, [x2, #0x230];
    /* 0x5864dc */ cbz x0, #0x5864f4;
    /* 0x5864e0 */ ldr x8, [x0];
    /* 0x5864e4 */ ldr x1, [x8, #0x30];
    /* 0x5864e8 */ br x1;
    /* 0x5864ec */ movi d0, #0000000000000000;
    return x0;
}
