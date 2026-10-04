// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c628
// Recovered Name: sub_57c628
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c628 | Size: 148 bytes | SHA256: 129ead3b07da8aea102a19736282170c8b75a6d2ff86863efdcac8782153f84f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetScores(JI)[F (table at 0x10ceae0)

jlong sub_57c628(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x57c628 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57c62c */ str x21, [sp, #0x10];
    /* 0x57c630 */ stp x20, x19, [sp, #0x20];
    /* 0x57c634 */ mov x29, sp;
    /* 0x57c638 */ cbz x2, #0x57c6a0;
    /* 0x57c63c */ mov w19, w3;
    /* 0x57c640 */ cmp w3, #9;
    /* 0x57c644 */ b.hi #0x57c6a0;
    /* 0x57c648 */ ldr x8, [x0];
    /* 0x57c64c */ mov w1, #9;
    /* 0x57c650 */ mov x20, x2;
    return x0;
}
