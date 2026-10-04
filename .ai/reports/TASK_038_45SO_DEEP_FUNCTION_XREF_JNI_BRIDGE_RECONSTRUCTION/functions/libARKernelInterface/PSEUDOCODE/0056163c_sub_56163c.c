// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56163c
// Recovered Name: sub_56163c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56163c | Size: 40 bytes | SHA256: 974160ff5f6fa17d73021d5c9282a8518268593ade40818fb19c2e8130ea2adf
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetBodyRect(JIFFFF)V (table at 0x10cc548)

jlong sub_56163c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x56163c */ cbz x2, #0x561660;
    /* 0x561640 */ cmp w3, #9;
    /* 0x561644 */ b.hi #0x561660;
    /* 0x561648 */ mov w8, #0x770;
    /* 0x56164c */ mov w9, #1;
    /* 0x561650 */ umaddl x8, w3, w8, x2;
    /* 0x561654 */ strb w9, [x8, #0x18];
    /* 0x561658 */ stp s0, s1, [x8, #0x20];
    /* 0x56165c */ stp s2, s3, [x8, #0x28];
    return x0;
}
