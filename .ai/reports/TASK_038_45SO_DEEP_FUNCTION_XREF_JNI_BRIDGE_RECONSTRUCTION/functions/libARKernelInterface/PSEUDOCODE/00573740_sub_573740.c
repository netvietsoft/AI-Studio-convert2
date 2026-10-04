// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573740
// Recovered Name: sub_573740
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573740 | Size: 148 bytes | SHA256: d43e773a2c118f150a55e01557e564978333e12d7d06df1069c0193aa144d44b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetShapeBlendShape(JI[F)V (table at 0x10cda78)

jlong sub_573740(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x573740 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x573744 */ stp x22, x21, [sp, #0x10];
    /* 0x573748 */ stp x20, x19, [sp, #0x20];
    /* 0x57374c */ mov x29, sp;
    /* 0x573750 */ cbz x2, #0x5737c4;
    /* 0x573754 */ mov x19, x4;
    /* 0x573758 */ cbz x4, #0x5737c4;
    /* 0x57375c */ ldr x8, [x0];
    /* 0x573760 */ mov x21, x2;
    /* 0x573764 */ mov x1, x19;
    /* 0x573768 */ mov x2, xzr;
    return x0;
}
