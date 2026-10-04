// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x583050
// Recovered Name: sub_583050
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x583050 | Size: 60 bytes | SHA256: 83f5edf0e82dacad056d091990e7a59a2010abde007d82d2ae142248f626a3db
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsCurrentRenderThumbnail(J)Z (table at 0x10cf770)

jlong sub_583050(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x583050 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x583054 */ mov x29, sp;
    /* 0x583058 */ cbz x2, #0x58307c;
    /* 0x58305c */ ldr x0, [x2, #0x710];
    /* 0x583060 */ cbz x0, #0x583088;
    /* 0x583064 */ ldr x8, [x0];
    /* 0x583068 */ ldr x8, [x8, #0x30];
    /* 0x58306c */ blr x8;
    /* 0x583070 */ and w0, w0, #1;
    /* 0x583074 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
