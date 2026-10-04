// Library: libffmpeg.so
// Function ID: libffmpeg::0x2124b8
// Recovered Name: ff_msmpeg4_pred_dc
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2124b8 | Size: 688 bytes | SHA256: 1cd773abe3ca5f63883d9371bdf9e76779d2cfa212b791605d2afe3792c835f1
// Callers: 0 | Callees: 1 | Imports: 0


void ff_msmpeg4_pred_dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 172 instructions
    /* 0x2124b8 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x2124bc */ stp x28, x27, [sp, #0x10];
    /* 0x2124c0 */ stp x26, x25, [sp, #0x20];
    /* 0x2124c4 */ stp x24, x23, [sp, #0x30];
    /* 0x2124c8 */ stp x22, x21, [sp, #0x40];
    /* 0x2124cc */ stp x20, x19, [sp, #0x50];
    /* 0x2124d0 */ add x8, x0, w1, sxtw #2;
    /* 0x2124d4 */ ldr x9, [x0, #0x598];
    /* 0x2124d8 */ cmp w1, #4;
    /* 0x2124dc */ mov w11, #0xc;
    /* 0x2124e0 */ mov x19, x3;
    sub_212768();
    sub_212768();
    return x0;
}
