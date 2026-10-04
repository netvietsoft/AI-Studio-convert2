// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581f54
// Recovered Name: sub_581f54
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581f54 | Size: 32 bytes | SHA256: 8dbe186f3c92eed024dedf4546f76204337558b6cc68c6dfb4cd6c876a3b88e5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetTag(J)J (table at 0x10cf3f8)

jlong sub_581f54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x581f54 */ cbz x2, #0x581f6c;
    /* 0x581f58 */ ldr x0, [x2, #0x20];
    /* 0x581f5c */ cbz x0, #0x581f74;
    /* 0x581f60 */ ldr x8, [x0];
    /* 0x581f64 */ ldr x1, [x8, #0x30];
    /* 0x581f68 */ br x1;
    /* 0x581f6c */ mov x0, xzr;
    return x0;
}
