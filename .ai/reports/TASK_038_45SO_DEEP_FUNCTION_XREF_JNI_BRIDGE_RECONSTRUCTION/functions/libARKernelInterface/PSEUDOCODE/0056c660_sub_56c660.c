// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56c660
// Recovered Name: sub_56c660
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56c660 | Size: 92 bytes | SHA256: d8ef6a0a586bc6f1b7a5ef83d8a953ffe82b134c8e97a44a58fb3c8a44ae46d5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMeshInfo(JIIJJJJJIJ)V (table at 0x10cd238)

jlong sub_56c660(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x56c660 */ cbz x2, #0x56c6b8;
    /* 0x56c664 */ cmp w3, #0x13;
    /* 0x56c668 */ b.hi #0x56c6b8;
    /* 0x56c66c */ cbz w4, #0x56c6b8;
    /* 0x56c670 */ ldr w8, [sp, #0x10];
    /* 0x56c674 */ cbz w8, #0x56c6b8;
    /* 0x56c678 */ mov w9, #0x5c0;
    /* 0x56c67c */ ldr x10, [sp];
    /* 0x56c680 */ ldr x11, [sp, #8];
    /* 0x56c684 */ nop ;
    /* 0x56c688 */ umaddl x9, w3, w9, x2;
    return x0;
}
