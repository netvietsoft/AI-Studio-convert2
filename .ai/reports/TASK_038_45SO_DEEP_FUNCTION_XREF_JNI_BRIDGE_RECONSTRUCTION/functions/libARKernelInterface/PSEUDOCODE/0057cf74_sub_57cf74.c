// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57cf74
// Recovered Name: sub_57cf74
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57cf74 | Size: 108 bytes | SHA256: dfeae470e6b25dbbf016bf01e61e1fa559efd0cfc50b5172c561de9dd55fddef
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativePushTextureData(JIIII)I (table at 0x10ceb88)

jlong sub_57cf74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x57cf74 */ cbz x2, #0x57cfd8;
    /* 0x57cf78 */ ldr w8, [x2, #0xc];
    /* 0x57cf7c */ cmp w8, #0x1e;
    /* 0x57cf80 */ b.lt #0x57cf8c;
    /* 0x57cf84 */ sub w8, w8, #1;
    /* 0x57cf88 */ str w8, [x2, #0xc];
    /* 0x57cf8c */ mov w9, #0x64;
    /* 0x57cf90 */ smaddl x8, w8, w9, x2;
    /* 0x57cf94 */ mov w9, #0x3f800000;
    /* 0x57cf98 */ stp xzr, xzr, [x8, #0x10];
    /* 0x57cf9c */ str w9, [x8, #0x20];
    return x0;
    return x0;
}
