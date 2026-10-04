// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x583760
// Recovered Name: sub_583760
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x583760 | Size: 60 bytes | SHA256: a2e37841296dd45a79b82a662a26698cd266eec18f8dc4b0b1b56013805fe0f6
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetDesignedDraggable(J)Z (table at 0x10cf8d8)

jlong sub_583760(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x583760 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x583764 */ mov x29, sp;
    /* 0x583768 */ cbz x2, #0x58378c;
    /* 0x58376c */ ldr x0, [x2, #0x980];
    /* 0x583770 */ cbz x0, #0x583798;
    /* 0x583774 */ ldr x8, [x0];
    /* 0x583778 */ ldr x8, [x8, #0x30];
    /* 0x58377c */ blr x8;
    /* 0x583780 */ and w0, w0, #1;
    /* 0x583784 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
