// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1e6d8
// Recovered Name: sub_1e6d8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1e6d8 | Size: 1776 bytes | SHA256: f69f5de935f99682a9792a25179be7e9d2f5b7dee737fc346e718ac0188d29b0
// Callers: 0 | Callees: 5 | Imports: 40

// Calls external APIs: abort, av_channel_layout_check, av_channel_layout_compare, av_channel_layout_copy, av_channel_layout_describe, av_channel_layout_uninit, av_frame_copy_props, av_get_sample_fmt_name, av_log, av_opt_get_chlayout, av_opt_get_int, av_opt_get_sample_fmt, av_opt_set_int, av_realloc_array, av_rescale, ff_all_channel_counts, ff_all_formats, ff_all_samplerates, ff_avfilter_link_set_in_status, ff_channel_layouts_ref, ff_filter_frame, ff_filter_set_ready, ff_formats_ref, ff_get_audio_buffer, ff_inlink_acknowledge_status, ff_inlink_consume_frame, ff_inlink_queued_frames, ff_inlink_request_frame, ff_inlink_set_status, ff_make_channel_layout_list, ff_outlink_frame_wanted, ff_outlink_get_status, swr_alloc, swr_alloc_set_opts2, swr_convert, swr_free, swr_get_class, swr_get_delay, swr_init, swr_next_pts
// Strings referenced:
//   "!av_channel_layout_compare(&outlink->ch_layout, &out_layout)"
//   "ochl"
//   "osf"
//   "osr"
//   "outlink->format == out_format"

void sub_1e6d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 444 instructions
    /* 0x1e6d8 */ add w1, w8, #1;
    /* 0x1e6dc */ mov w2, #4;
    /* 0x1e6e0 */ b #0x3cd10;
    /* 0x1e6e4 */ stp x30, x19, [sp, #-0x10]!;
    /* 0x1e6e8 */ ldr x19, [x0, #0x48];
    /* 0x1e6ec */ mov x8, #-0x8000000000000000;
    /* 0x1e6f0 */ str x8, [x19, #0x20];
    swr_alloc();
    /* 0x1e6f8 */ mov x8, x0;
    /* 0x1e6fc */ mov w9, #-0xc;
    /* 0x1e700 */ cmp x0, #0;
    return x0;
    av_opt_set_int();
    av_opt_get_sample_fmt();
    av_opt_get_int();
    ff_all_formats();
    ff_formats_ref();
    ff_all_samplerates();
    ff_formats_ref();
    ff_all_channel_counts();
    ff_channel_layouts_ref();
    sub_1eebc();
    ff_all_samplerates();
    ff_formats_ref();
    sub_1eebc();
    ff_all_formats();
    ff_formats_ref();
    av_opt_get_chlayout();
    av_channel_layout_check();
    ff_make_channel_layout_list();
    ff_all_channel_counts();
    av_channel_layout_uninit();
    ff_channel_layouts_ref();
    return x0;
    ff_outlink_get_status();
    ff_inlink_set_status();
    sub_1edc8();
    ff_inlink_acknowledge_status();
    ff_inlink_queued_frames();
    ff_inlink_consume_frame();
    swr_get_delay();
    ff_get_audio_buffer();
    av_frame_copy_props();
    av_channel_layout_copy();
    av_rescale();
    swr_next_pts();
    swr_convert();
    ff_filter_frame();
    sub_1edc8();
    ff_filter_frame();
    return x0;
    ff_avfilter_link_set_in_status();
    sub_1eecc();
    ff_outlink_frame_wanted();
    sub_1eed4();
    sub_1eecc();
    sub_1eed4();
    sub_1eecc();
    ff_inlink_request_frame();
    ff_filter_set_ready();
    swr_alloc_set_opts2();
    swr_init();
    av_opt_get_int();
    av_opt_get_chlayout();
    av_opt_get_sample_fmt();
    av_channel_layout_compare();
    av_channel_layout_uninit();
    av_channel_layout_describe();
    av_channel_layout_describe();
    av_get_sample_fmt_name();
    av_get_sample_fmt_name();
    av_log();
    return x0;
    sub_1eea8();
    av_log();
    abort();
    sub_1eea8();
    av_log();
    abort();
    sub_1eea8();
    av_log();
    abort();
    return x0;
    return x0;
    swr_get_class();
    return x0;
}
