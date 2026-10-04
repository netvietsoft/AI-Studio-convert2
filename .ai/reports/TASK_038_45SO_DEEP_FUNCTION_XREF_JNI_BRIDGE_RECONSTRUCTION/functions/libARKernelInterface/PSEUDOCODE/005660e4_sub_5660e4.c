// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5660e4
// Recovered Name: sub_5660e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5660e4 | Size: 20 bytes | SHA256: bcc79c72c6a689bf1a6506d4227145655e92c73d0dd4b2149bfb4d35763f14dc
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFace2DReconstructorType(J)I (table at 0x10cc860)

jlong sub_5660e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5660e4 */ cbz x2, #0x5660f0;
    /* 0x5660e8 */ ldr w0, [x2, #0xc];
    return x0;
    /* 0x5660f0 */ mov w0, #-1;
    return x0;
}
