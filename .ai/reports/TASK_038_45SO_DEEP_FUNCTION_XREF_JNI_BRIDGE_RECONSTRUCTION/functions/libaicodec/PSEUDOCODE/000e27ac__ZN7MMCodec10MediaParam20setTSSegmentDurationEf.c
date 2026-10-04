// Library: libaicodec.so
// Function ID: libaicodec::0xe27ac
// Recovered Name: _ZN7MMCodec10MediaParam20setTSSegmentDurationEf
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xe27ac | Size: 40 bytes | SHA256: 6639c698e486ad10de2898f0a3a41748cec9471dca962883d94f9d36a96bd24b
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN7MMCodec10MediaParam20setTSSegmentDurationEf(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0xe27ac */ ldr x8, [x0, #0x20];
    /* 0xe27b0 */ str s0, [x0, #0x40];
    /* 0xe27b4 */ cbz x8, #0xe27cc;
    /* 0xe27b8 */ mov w9, #0x447a0000;
    /* 0xe27bc */ fmov s1, w9;
    /* 0xe27c0 */ fmul s0, s0, s1;
    /* 0xe27c4 */ fcvtzs x9, s0;
    /* 0xe27c8 */ str x9, [x8, #0xe0];
    /* 0xe27cc */ mov w0, #1;
    return x0;
}
