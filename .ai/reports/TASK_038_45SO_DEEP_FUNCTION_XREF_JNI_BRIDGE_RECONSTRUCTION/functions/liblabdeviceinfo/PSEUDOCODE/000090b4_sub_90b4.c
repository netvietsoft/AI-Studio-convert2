// Library: liblabdeviceinfo.so
// Function ID: liblabdeviceinfo::0x90b4
// Recovered Name: sub_90b4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90b4 | Size: 108 bytes | SHA256: 945ea725cd4cb271cd6baffc7d22730bd34ef29af104bf5ebdf1fff90373889b
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: abort

void sub_90b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x90b4 */ stp x29, x30, [sp, #0x100];
    /* 0x90b8 */ str x28, [sp, #0x110];
    /* 0x90bc */ add x29, sp, #0x100;
    /* 0x90c0 */ mov x8, #-0x38;
    /* 0x90c4 */ mov x9, sp;
    /* 0x90c8 */ sub x10, x29, #0x78;
    /* 0x90cc */ movk x8, #0xff80, lsl #32;
    /* 0x90d0 */ add x9, x9, #0x80;
    /* 0x90d4 */ stp x1, x2, [x29, #-0x78];
    /* 0x90d8 */ stp x9, x8, [x29, #-0x10];
    /* 0x90dc */ add x8, x10, #0x38;
    sub_e720();
    abort();
}
