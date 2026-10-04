// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5798c4
// Recovered Name: sub_5798c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5798c4 | Size: 36 bytes | SHA256: b727cc531053f4a70833c8f911b7bda09ba78271338869e20622b895afcc7b70
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFaceIDsAlpha(JII)F (table at 0x10ce330)

jlong sub_5798c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x5798c4 */ cbz x2, #0x5798e0;
    /* 0x5798c8 */ ldr x8, [x2];
    /* 0x5798cc */ mov x0, x2;
    /* 0x5798d0 */ mov w1, w3;
    /* 0x5798d4 */ mov w2, w4;
    /* 0x5798d8 */ ldr x5, [x8, #0x58];
    /* 0x5798dc */ br x5;
    /* 0x5798e0 */ movi d0, #0000000000000000;
    return x0;
}
