// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x2cd84
// Recovered Name: avfilter_graph_segment_init
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2cd84 | Size: 168 bytes | SHA256: db1ec841cb75caeb3a393bde355f6bd744c3948686e25ab111f9f9c0fffb5f3a
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: avfilter_init_dict
// Strings referenced:
//   "avfilter_graph_segment_init"

void avfilter_graph_segment_init(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x2cd84 */ cbz w1, #0x2cd90;
    /* 0x2cd88 */ mov w0, #-0x26;
    return x0;
    /* 0x2cd90 */ str x30, [sp, #-0x30]!;
    /* 0x2cd94 */ stp x22, x21, [sp, #0x10];
    /* 0x2cd98 */ stp x20, x19, [sp, #0x20];
    /* 0x2cd9c */ mov x19, x0;
    /* 0x2cda0 */ mov x20, xzr;
    /* 0x2cda4 */ ldr x8, [x19, #0x10];
    /* 0x2cda8 */ cmp x20, x8;
    /* 0x2cdac */ b.hs #0x2ce24;
    avfilter_init_dict();
    sub_2cd68();
    sub_2d918();
    return x0;
}
