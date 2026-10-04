// Reconstructed Pseudocode for FN_libffmpegfilter_00022AA8 (avfilter_graph_alloc_filter)
// Library: libffmpegfilter.so | RVA: 0x22AA8 | Size: 196B | Visibility: FACT

/* Imported APIs: ff_graph_thread_init;av_realloc_array;ff_filter_alloc;av_log */
/* String XREFs: Error initializing threading: %s. */

int avfilter_graph_alloc_filter(void* ctx) {
    // Function prologue: set up stack frame
    sub_24FA0(ctx);
    ff_graph_thread_init(...);
    av_realloc_array(...);
    ff_filter_alloc(...);
    av_log(...);
    return 0;
}
