// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d018
// Recovered Name: sub_57d018
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d018 | Size: 28 bytes | SHA256: 026c80f7d78dd5deb91c342f86170ffe97d9c631f1d02a8a315c1280a75b98ff
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextureWidth(JI)I (table at 0x10cebd0)

jlong sub_57d018(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57d018 */ cbz x2, #0x57d02c;
    /* 0x57d01c */ mov w8, #0x64;
    /* 0x57d020 */ smaddl x8, w3, w8, x2;
    /* 0x57d024 */ ldr w0, [x8, #0x6c];
    return x0;
    /* 0x57d02c */ mov w0, wzr;
    return x0;
}
