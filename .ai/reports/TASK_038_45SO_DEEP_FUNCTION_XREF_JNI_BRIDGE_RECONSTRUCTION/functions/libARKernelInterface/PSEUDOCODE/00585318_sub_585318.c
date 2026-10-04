// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585318
// Recovered Name: sub_585318
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585318 | Size: 152 bytes | SHA256: b011adc7ed7a8646e119a12681b014c59ceb77d27177d6cfc029b43d8fbcfe0d
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeRegisterVertexEventMark(J[I)V (table at 0x10cf980)

jlong sub_585318(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x585318 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x58531c */ stp x22, x21, [sp, #0x10];
    /* 0x585320 */ stp x20, x19, [sp, #0x20];
    /* 0x585324 */ mov x29, sp;
    /* 0x585328 */ cbz x2, #0x5853a0;
    /* 0x58532c */ ldr x8, [x0];
    /* 0x585330 */ mov x1, x3;
    /* 0x585334 */ mov x19, x3;
    /* 0x585338 */ mov x21, x2;
    /* 0x58533c */ mov x20, x0;
    /* 0x585340 */ ldr x8, [x8, #0x558];
    sub_583eb4();
    return x0;
}
