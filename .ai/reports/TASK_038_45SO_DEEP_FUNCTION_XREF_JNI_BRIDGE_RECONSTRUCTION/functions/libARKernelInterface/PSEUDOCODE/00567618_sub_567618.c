// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x567618
// Recovered Name: sub_567618
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x567618 | Size: 20 bytes | SHA256: 6fd73ae00bf5aa75b64af535d1a0dbbae18bfb6cc1f7773fda3fe0b63cf91bda
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTriangleIndex(JIJ)V (table at 0x10ccb60)

jlong sub_567618(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x567618 */ cbz x2, #0x567628;
    /* 0x56761c */ mov w8, #0x88;
    /* 0x567620 */ smaddl x8, w3, w8, x2;
    /* 0x567624 */ str x4, [x8, #0x48];
    return x0;
}
