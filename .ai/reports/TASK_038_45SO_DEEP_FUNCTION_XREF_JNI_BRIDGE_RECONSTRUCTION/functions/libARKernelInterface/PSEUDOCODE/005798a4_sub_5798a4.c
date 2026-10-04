// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5798a4
// Recovered Name: sub_5798a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5798a4 | Size: 32 bytes | SHA256: 2ef838508da7259c23cd72965fcd6890faaeac6d48991a66755f2afb6f402895
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceIDsAlpha(JIIF)V (table at 0x10ce318)

jlong sub_5798a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x5798a4 */ cbz x2, #0x5798c0;
    /* 0x5798a8 */ ldr x8, [x2];
    /* 0x5798ac */ mov x0, x2;
    /* 0x5798b0 */ mov w1, w3;
    /* 0x5798b4 */ mov w2, w4;
    /* 0x5798b8 */ ldr x5, [x8, #0x50];
    /* 0x5798bc */ br x5;
    return x0;
}
