// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58bc94
// Recovered Name: sub_58bc94
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58bc94 | Size: 12 bytes | SHA256: 755bcb6dd8c6627ce6936bd9ad238f37170815f36b62eaf4e5c02ca1f3897de5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetGroupAlpha(JF)V (table at 0x10d0850)

jlong sub_58bc94(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x58bc94 */ cbz x2, #0x58bc9c;
    /* 0x58bc98 */ str s0, [x2, #0x18];
    return x0;
}
