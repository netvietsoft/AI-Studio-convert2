// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a8b4
// Recovered Name: sub_8a8b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a8b4 | Size: 32 bytes | SHA256: 80e56166675a946ebe9bbea3afc80780e0a615515d5dd232f415359ba19477ce
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetVendor(JI)I (table at 0x9aa88)

jlong sub_8a8b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8a8b4 */ cbz x2, #0x8a8cc;
    /* 0x8a8b8 */ ldr x8, [x2];
    /* 0x8a8bc */ mov x0, x2;
    /* 0x8a8c0 */ mov w1, w3;
    /* 0x8a8c4 */ ldr x4, [x8, #0x48];
    /* 0x8a8c8 */ br x4;
    /* 0x8a8cc */ mov w0, #-1;
    return x0;
}
