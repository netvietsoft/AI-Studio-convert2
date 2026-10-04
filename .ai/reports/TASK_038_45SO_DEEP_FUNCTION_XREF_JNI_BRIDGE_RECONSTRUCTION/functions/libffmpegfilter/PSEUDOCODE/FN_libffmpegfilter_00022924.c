// Reconstructed Pseudocode for FN_libffmpegfilter_00022924 (avfilter_graph_alloc)
// Library: libffmpegfilter.so | RVA: 0x22924 | Size: 72B | Visibility: FACT

/* Imported APIs: av_mallocz;av_opt_set_defaults;ff_framequeue_global_init */
/* String XREFs:  */

int avfilter_graph_alloc(void* ctx) {
    // Function prologue: set up stack frame
    av_mallocz(...);
    av_opt_set_defaults(...);
    ff_framequeue_global_init(...);
    return 0;
}
