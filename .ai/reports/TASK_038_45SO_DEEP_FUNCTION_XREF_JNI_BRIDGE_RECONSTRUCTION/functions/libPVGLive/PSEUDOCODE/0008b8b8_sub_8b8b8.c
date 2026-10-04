// Library: libPVGLive.so
// Function ID: libPVGLive::0x8b8b8
// Recovered Name: sub_8b8b8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x8b8b8 | Size: 28 bytes | SHA256: 12c06b3f16536e264ee2d0a5ab4c1b40866cf117bb3ac447ebf921ded8809083
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeMetadataCount(J)J (table at 0x9ac08)

jlong sub_8b8b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8b8b8 */ cbz x2, #0x8b8cc;
    /* 0x8b8bc */ ldr x8, [x2];
    /* 0x8b8c0 */ mov x0, x2;
    /* 0x8b8c4 */ ldr x1, [x8, #0x28];
    /* 0x8b8c8 */ br x1;
    /* 0x8b8cc */ mov x0, xzr;
    return x0;
}
