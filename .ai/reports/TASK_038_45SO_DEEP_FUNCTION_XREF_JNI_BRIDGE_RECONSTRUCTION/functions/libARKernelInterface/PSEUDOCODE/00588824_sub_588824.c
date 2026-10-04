// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x588824
// Recovered Name: sub_588824
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x588824 | Size: 60 bytes | SHA256: 085ba35a9b3120c076e7237aa89f4737fdb3ea5e7ae9975ea97e24be3642fcc9
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetShrink(J)Z (table at 0x10cfef0)

jlong sub_588824(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x588824 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x588828 */ mov x29, sp;
    /* 0x58882c */ cbz x2, #0x588850;
    /* 0x588830 */ ldr x0, [x2, #0x980];
    /* 0x588834 */ cbz x0, #0x58885c;
    /* 0x588838 */ ldr x8, [x0];
    /* 0x58883c */ ldr x8, [x8, #0x30];
    /* 0x588840 */ blr x8;
    /* 0x588844 */ and w0, w0, #1;
    /* 0x588848 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
