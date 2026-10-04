// Library: libbytehook.so
// Function ID: libbytehook::0x5b88
// Recovered Name: sub_5b88
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5b88 | Size: 152 bytes | SHA256: bb7a1265ddd150dbd9ad15e7d418fa5222085863625e42dc4979f62f728d3a79
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: strncmp

void sub_5b88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x5b88 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x5b8c */ stp x24, x23, [sp, #0x10];
    /* 0x5b90 */ stp x22, x21, [sp, #0x20];
    /* 0x5b94 */ stp x20, x19, [sp, #0x30];
    /* 0x5b98 */ mov x29, sp;
    /* 0x5b9c */ ldr x22, [x0, #0x18];
    /* 0x5ba0 */ mov x20, x1;
    /* 0x5ba4 */ mov x19, x0;
    /* 0x5ba8 */ mov x21, xzr;
    /* 0x5bac */ mov w23, #0xfefe;
    /* 0x5bb0 */ cbz x22, #0x5bf4;
    strncmp();
    return x0;
}
