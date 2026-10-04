// Library: libPVGLive.so
// Function ID: libPVGLive::0x277c8
// Recovered Name: sub_277c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x277c8 | Size: 60 bytes | SHA256: c2a57e8becc27dd4c0e6bee978f7c2cff753b8d2d03675c6ebdf84a9e7c761e5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: fread

void sub_277c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x277c8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x277cc */ mov x29, sp;
    /* 0x277d0 */ mov w2, w2;
    /* 0x277d4 */ mov x0, x1;
    /* 0x277d8 */ mov w1, #1;
    fread();
    /* 0x277e0 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x277e8 */ mov x8, x0;
    /* 0x277ec */ cmp w2, #1;
    /* 0x277f0 */ mov w0, #-1;
}
