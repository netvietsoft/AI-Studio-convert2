// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d7a8
// Recovered Name: sub_57d7a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d7a8 | Size: 20 bytes | SHA256: f0686210ee3aee0340839a828b3240cb1b8dfb26aa9294c86aef4186bed9415f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetEnableMoveAdsorb(J)Z (table at 0x10cf038)

jlong sub_57d7a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d7a8 */ cbz x2, #0x57d7b4;
    /* 0x57d7ac */ ldrb w0, [x2, #0x44];
    return x0;
    /* 0x57d7b4 */ mov w0, wzr;
    return x0;
}
