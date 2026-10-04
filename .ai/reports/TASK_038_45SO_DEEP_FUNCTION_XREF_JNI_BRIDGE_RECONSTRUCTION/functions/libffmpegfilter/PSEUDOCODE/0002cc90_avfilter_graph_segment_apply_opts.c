// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x2cc90
// Recovered Name: avfilter_graph_segment_apply_opts
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x2cc90 | Size: 216 bytes | SHA256: ef48bf0d010f186673cdc7b727a23df2dab461ff020bc933e57973ef717ac7eb
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: av_dict_count, av_opt_set_dict2
// Strings referenced:
//   "avfilter_graph_segment_apply_opts"

void avfilter_graph_segment_apply_opts(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x2cc90 */ cbz w1, #0x2cc9c;
    /* 0x2cc94 */ mov w0, #-0x26;
    return x0;
    /* 0x2cc9c */ str x30, [sp, #-0x40]!;
    /* 0x2cca0 */ stp x24, x23, [sp, #0x10];
    /* 0x2cca4 */ stp x22, x21, [sp, #0x20];
    /* 0x2cca8 */ stp x20, x19, [sp, #0x30];
    /* 0x2ccac */ mov x19, x0;
    /* 0x2ccb0 */ mov x22, xzr;
    /* 0x2ccb4 */ mov w21, wzr;
    /* 0x2ccb8 */ ldr x8, [x19, #0x10];
    av_opt_set_dict2();
    av_dict_count();
    sub_2cd68();
    return x0;
}
