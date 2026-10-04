// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c458
// Recovered Name: sub_57c458
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c458 | Size: 172 bytes | SHA256: 4581e864a3095b6d5e3ed0153b182700f439cc30e4f070de8605fada6a7728ae
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLandmark2D(JI)[F (table at 0x10ceab0)

jlong sub_57c458(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x57c458 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57c45c */ stp x22, x21, [sp, #0x10];
    /* 0x57c460 */ stp x20, x19, [sp, #0x20];
    /* 0x57c464 */ mov x29, sp;
    /* 0x57c468 */ cbz x2, #0x57c4e8;
    /* 0x57c46c */ mov w21, w3;
    /* 0x57c470 */ cmp w3, #9;
    /* 0x57c474 */ b.hi #0x57c4e8;
    /* 0x57c478 */ ldr x8, [x0];
    /* 0x57c47c */ mov w1, #0x12;
    /* 0x57c480 */ mov x19, x2;
    return x0;
}
