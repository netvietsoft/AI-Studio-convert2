// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x572740
// Recovered Name: sub_572740
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x572740 | Size: 216 bytes | SHA256: 7aa67f4ef03eeb2caa04339423c6d911cdccb738c2d3f57fc6ea2ed88ef86d80
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetHandKeyPoints(JI[F)V (table at 0x10cd880)
// Calls external APIs: memcpy

jlong sub_572740(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x572740 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x572744 */ stp x24, x23, [sp, #0x10];
    /* 0x572748 */ stp x22, x21, [sp, #0x20];
    /* 0x57274c */ stp x20, x19, [sp, #0x30];
    /* 0x572750 */ mov x29, sp;
    /* 0x572754 */ cbz x2, #0x572804;
    /* 0x572758 */ mov w21, w3;
    /* 0x57275c */ cmp w3, #9;
    /* 0x572760 */ b.hi #0x572804;
    /* 0x572764 */ ldr x8, [x0];
    /* 0x572768 */ mov x1, x4;
    memcpy();
    return x0;
}
