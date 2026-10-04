// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x578cb8
// Recovered Name: sub_578cb8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x578cb8 | Size: 128 bytes | SHA256: 5d851377f1376079510b73945c7990970d6c049eac1e64d59d874c95f32bbfc5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetImageData(J[BII)V (table at 0x10ce060)

jlong sub_578cb8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x578cb8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x578cbc */ str x21, [sp, #0x10];
    /* 0x578cc0 */ stp x20, x19, [sp, #0x20];
    /* 0x578cc4 */ mov x29, sp;
    /* 0x578cc8 */ cbz x2, #0x578d28;
    /* 0x578ccc */ mov x19, x2;
    /* 0x578cd0 */ str wzr, [x2];
    /* 0x578cd4 */ stp w4, w5, [x2, #0x10];
    /* 0x578cd8 */ cbz x3, #0x578d24;
    /* 0x578cdc */ ldr x8, [x0];
    /* 0x578ce0 */ mov x1, x3;
    return x0;
}
