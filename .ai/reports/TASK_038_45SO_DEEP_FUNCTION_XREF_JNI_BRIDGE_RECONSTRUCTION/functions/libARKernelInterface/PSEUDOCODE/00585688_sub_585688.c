// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585688
// Recovered Name: sub_585688
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585688 | Size: 32 bytes | SHA256: 7dde8556e86bb7eb21f8800c6814f7202022f45a6caf0b1ea49b98213bb24c9c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeTextEnum(J)I (table at 0x10cfb60)

jlong sub_585688(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x585688 */ cbz x2, #0x5856a0;
    /* 0x58568c */ ldr x0, [x2, #0x20];
    /* 0x585690 */ cbz x0, #0x5856a8;
    /* 0x585694 */ ldr x8, [x0];
    /* 0x585698 */ ldr x1, [x8, #0x30];
    /* 0x58569c */ br x1;
    /* 0x5856a0 */ mov w0, wzr;
    return x0;
}
