// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x2c814
// Recovered Name: avfilter_graph_segment_free
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2c814 | Size: 100 bytes | SHA256: 8c446aa69df4c39c611d69e445ae38ca07b61e1ac100f2c8850161f1a02e112d
// Callers: 0 | Callees: 4 | Imports: 1

// Calls external APIs: av_freep

void avfilter_graph_segment_free(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x2c814 */ str x30, [sp, #-0x30]!;
    /* 0x2c818 */ stp x22, x21, [sp, #0x10];
    /* 0x2c81c */ stp x20, x19, [sp, #0x20];
    /* 0x2c820 */ ldr x20, [x0];
    /* 0x2c824 */ cbz x20, #0x2c86c;
    sub_2d948();
    /* 0x2c82c */ ldr x8, [x20, #0x10];
    /* 0x2c830 */ cmp x22, x8;
    /* 0x2c834 */ b.hs #0x2c84c;
    /* 0x2c838 */ ldur x8, [x20, #8];
    /* 0x2c83c */ add x0, x8, x21;
    sub_2ca70();
    sub_2d988();
    av_freep();
    av_freep();
    sub_2d918();
    sub_2d918();
    return x0;
}
