// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a37c
// Recovered Name: sub_56a37c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a37c | Size: 208 bytes | SHA256: 5402b30345d4074926b58362c7390c6cb35b0de1ed37b45c044505f512a5f658
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetRightEarLandmark2D(JI[F)V (table at 0x10cd178)
// Calls external APIs: memcpy

jlong sub_56a37c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x56a37c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x56a380 */ str x23, [sp, #0x10];
    /* 0x56a384 */ stp x22, x21, [sp, #0x20];
    /* 0x56a388 */ stp x20, x19, [sp, #0x30];
    /* 0x56a38c */ mov x29, sp;
    /* 0x56a390 */ cbz x2, #0x56a438;
    /* 0x56a394 */ mov w21, w3;
    /* 0x56a398 */ cmp w3, #0x13;
    /* 0x56a39c */ b.hi #0x56a438;
    /* 0x56a3a0 */ ldr x8, [x0];
    /* 0x56a3a4 */ mov x1, x4;
    memcpy();
    return x0;
}
