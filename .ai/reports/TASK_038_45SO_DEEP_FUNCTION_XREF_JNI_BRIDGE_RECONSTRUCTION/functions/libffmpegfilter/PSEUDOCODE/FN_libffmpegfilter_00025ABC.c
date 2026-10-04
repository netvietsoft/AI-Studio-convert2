// Reconstructed Pseudocode for FN_libffmpegfilter_00025ABC (av_buffersrc_add_frame_flags)
// Library: libffmpegfilter.so | RVA: 0x25ABC | Size: 1112B | Visibility: FACT

/* Imported APIs: av_channel_layout_copy;av_channel_layout_compare;av_get_sample_fmt_name;av_log;av_color_space_name;av_frame_alloc;av_frame_move_ref;av_frame_clone;ff_filter_frame */
/* String XREFs: le-protocol=data --enable-protocol=file --enable-protocol=pipe --enable-protocol;et loop count;et loop count;le-protocol=data --enable-protocol=file --enable-protocol=pipe --enable-protocol;Changing video frame properties on the fly is not supported by all filters. */

int av_buffersrc_add_frame_flags(void* ctx) {
    // Function prologue: set up stack frame
    sub_264FC(ctx);
    sub_264FC(ctx);
    sub_26530(ctx);
    sub_26530(ctx);
    sub_26514(ctx);
    av_channel_layout_copy(...);
    av_channel_layout_compare(...);
    av_get_sample_fmt_name(...);
    av_log(...);
    av_color_space_name(...);
    return 0;
}
