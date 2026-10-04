// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x583150
// Recovered Name: sub_583150
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x583150 | Size: 32 bytes | SHA256: c896e710e0764924f632090dc15cfad791bc2567ce71b70a1d9e1ec38b859dd4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTouchTransScale(J)F (table at 0x10cf7a0)

jlong sub_583150(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x583150 */ cbz x2, #0x583168;
    /* 0x583154 */ ldr x0, [x2, #0x230];
    /* 0x583158 */ cbz x0, #0x583170;
    /* 0x58315c */ ldr x8, [x0];
    /* 0x583160 */ ldr x1, [x8, #0x30];
    /* 0x583164 */ br x1;
    /* 0x583168 */ movi d0, #0000000000000000;
    return x0;
}
