// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x2c73c
// Recovered Name: avfilter_graph_segment_apply
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2c73c | Size: 216 bytes | SHA256: ab913dfa687725b24d4ecd9361a991af2adc1b82f962f41016c21c398f7a54c8
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: av_log, avfilter_graph_segment_apply_opts, avfilter_graph_segment_create_filters, avfilter_graph_segment_init, avfilter_graph_segment_link

void avfilter_graph_segment_apply(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x2c73c */ str x30, [sp, #-0x30]!;
    /* 0x2c740 */ stp x22, x21, [sp, #0x10];
    /* 0x2c744 */ stp x20, x19, [sp, #0x20];
    /* 0x2c748 */ cbz w1, #0x2c754;
    /* 0x2c74c */ mov w20, #-0x26;
    /* 0x2c750 */ b #0x2c804;
    /* 0x2c754 */ mov x21, x3;
    /* 0x2c758 */ mov x22, x2;
    /* 0x2c75c */ mov x19, x0;
    avfilter_graph_segment_create_filters();
    /* 0x2c764 */ tbnz w0, #0x1f, #0x2c7b4;
    avfilter_graph_segment_apply_opts();
    avfilter_graph_segment_init();
    avfilter_graph_segment_link();
    sub_2d124();
    av_log();
    sub_2d918();
    return x0;
}
