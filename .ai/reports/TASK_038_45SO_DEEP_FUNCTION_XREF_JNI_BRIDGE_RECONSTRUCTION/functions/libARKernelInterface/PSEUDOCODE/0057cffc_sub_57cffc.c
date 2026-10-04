// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57cffc
// Recovered Name: sub_57cffc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57cffc | Size: 28 bytes | SHA256: 411ed7b77d2f7e4512cee15d494e92cd5728f2d38e49dde4583505c3c818956c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTextureID(JI)I (table at 0x10cebb8)

jlong sub_57cffc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57cffc */ cbz x2, #0x57d010;
    /* 0x57d000 */ mov w8, #0x64;
    /* 0x57d004 */ smaddl x8, w3, w8, x2;
    /* 0x57d008 */ ldr w0, [x8, #0x68];
    return x0;
    /* 0x57d010 */ mov w0, wzr;
    return x0;
}
