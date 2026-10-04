// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581668
// Recovered Name: sub_581668
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581668 | Size: 60 bytes | SHA256: 1febe460733d7e5b38f900243302460418b7d5ec55a337dde6ad35a909331736
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeValid(J)Z (table at 0x10cf230)

jlong sub_581668(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x581668 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x58166c */ mov x29, sp;
    /* 0x581670 */ cbz x2, #0x581694;
    /* 0x581674 */ ldr x0, [x2, #0x20];
    /* 0x581678 */ cbz x0, #0x5816a0;
    /* 0x58167c */ ldr x8, [x0];
    /* 0x581680 */ ldr x8, [x8, #0x30];
    /* 0x581684 */ blr x8;
    /* 0x581688 */ and w0, w0, #1;
    /* 0x58168c */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
