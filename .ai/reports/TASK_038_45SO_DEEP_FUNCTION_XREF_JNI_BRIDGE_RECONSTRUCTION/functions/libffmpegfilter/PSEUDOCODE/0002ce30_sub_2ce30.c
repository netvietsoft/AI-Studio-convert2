// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x2ce30
// Recovered Name: sub_2ce30
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2ce30 | Size: 756 bytes | SHA256: 38c546e6c068046f09a4eecae89a845a131d6d9202fa7621566672ece9e7b985
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: av_log, avfilter_inout_free, avfilter_link
// Strings referenced:
//   "avfilter_graph_segment_link"

void sub_2ce30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 189 instructions
    /* 0x2ce30 */ stp x29, x30, [sp, #0x10];
    /* 0x2ce34 */ stp x28, x27, [sp, #0x20];
    /* 0x2ce38 */ stp x26, x25, [sp, #0x30];
    /* 0x2ce3c */ stp x24, x23, [sp, #0x40];
    /* 0x2ce40 */ stp x22, x21, [sp, #0x50];
    /* 0x2ce44 */ stp x20, x19, [sp, #0x60];
    /* 0x2ce48 */ str xzr, [x2];
    /* 0x2ce4c */ str xzr, [x3];
    /* 0x2ce50 */ cbz w1, #0x2ce5c;
    /* 0x2ce54 */ mov w26, #-0x26;
    /* 0x2ce58 */ b #0x2d0ac;
    sub_2d958();
    avfilter_link();
    sub_2d924();
    sub_2d958();
    avfilter_link();
    sub_2d924();
    avfilter_inout_free();
    avfilter_inout_free();
    return x0;
    sub_2cd68();
    av_log();
}
