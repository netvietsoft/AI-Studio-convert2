// Reconstructed Pseudocode for FN_libffmpegfilter_0002090C (avfilter_link)
// Library: libffmpegfilter.so | RVA: 0x2090C | Size: 516B | Visibility: FACT

/* Imported APIs: av_mallocz;ff_framequeue_init;av_get_media_type_string;av_log;abort */
/* String XREFs: mestamps;Filters must be initialized before linking.;Media type mismatch between the '%s' filter output pad %d (%s) and the '%s' filt;src->graph;dst->graph */

int avfilter_link(void* ctx) {
    // Function prologue: set up stack frame
    sub_22864(ctx);
    sub_22858(ctx);
    sub_22844(ctx);
    sub_22858(ctx);
    sub_22844(ctx);
    av_mallocz(...);
    ff_framequeue_init(...);
    av_get_media_type_string(...);
    av_log(...);
    abort(...);
    return 0;
}
