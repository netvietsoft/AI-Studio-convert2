// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57cfe0
// Recovered Name: sub_57cfe0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57cfe0 | Size: 28 bytes | SHA256: 79931315ac2ef7b81a202e8c7fadd8b08544527eddda88bbfea0a5d479fd7deb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextureType(JI)I (table at 0x10ceba0)

jlong sub_57cfe0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57cfe0 */ cbz x2, #0x57cff4;
    /* 0x57cfe4 */ mov w8, #0x64;
    /* 0x57cfe8 */ smaddl x8, w3, w8, x2;
    /* 0x57cfec */ ldr w0, [x8, #0x64];
    return x0;
    /* 0x57cff4 */ mov w0, wzr;
    return x0;
}
