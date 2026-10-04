// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5728b0
// Recovered Name: sub_5728b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5728b0 | Size: 36 bytes | SHA256: 39eef5bd419521178de15ea519d99ceb019e5efbe4271172f03d5616d0ac9bb2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHandScore(JIF)V (table at 0x10cd8b0)

jlong sub_5728b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x5728b0 */ cbz x2, #0x5728d0;
    /* 0x5728b4 */ cmp w3, #9;
    /* 0x5728b8 */ b.hi #0x5728d0;
    /* 0x5728bc */ mov w8, #0xec;
    /* 0x5728c0 */ mov w9, #1;
    /* 0x5728c4 */ umaddl x8, w3, w8, x2;
    /* 0x5728c8 */ strb w9, [x8, #0x40];
    /* 0x5728cc */ str s0, [x8, #0x44];
    return x0;
}
