// Reconstructed Pseudocode for FN_libffmpegfilter_00024588 (avfilter_graph_request_oldest)
// Library: libffmpegfilter.so | RVA: 0x24588 | Size: 312B | Visibility: FACT

/* Imported APIs: av_buffersink_get_frame_flags;ff_request_frame;av_log;ff_filter_graph_run_once */
/* String XREFs: EOF on sink link %s:%s. */

int avfilter_graph_request_oldest(void* ctx) {
    // Function prologue: set up stack frame
    sub_244E8(ctx);
    av_buffersink_get_frame_flags(...);
    ff_request_frame(...);
    av_log(...);
    ff_filter_graph_run_once(...);
    return 0;
}
