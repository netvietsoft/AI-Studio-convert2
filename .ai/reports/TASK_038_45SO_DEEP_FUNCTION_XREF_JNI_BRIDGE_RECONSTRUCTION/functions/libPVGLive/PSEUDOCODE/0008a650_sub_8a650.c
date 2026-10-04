// Library: libPVGLive.so
// Function ID: libPVGLive::0x8a650
// Recovered Name: sub_8a650
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8a650 | Size: 24 bytes | SHA256: 80beebdbd5338560cbcaf5f570f71bd4ad44c2c6a001a8384e2c7aaf4bb6e9f7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeClose(J)V (table at 0x9aa10)

jlong sub_8a650(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x8a650 */ cbz x2, #0x8a664;
    /* 0x8a654 */ ldr x8, [x2];
    /* 0x8a658 */ mov x0, x2;
    /* 0x8a65c */ ldr x1, [x8];
    /* 0x8a660 */ br x1;
    return x0;
}
