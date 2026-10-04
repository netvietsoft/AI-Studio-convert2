// Reconstructed Pseudocode for FN_libffmpegfilter_000229E4 (avfilter_graph_free)
// Library: libffmpegfilter.so | RVA: 0x229E4 | Size: 104B | Visibility: FACT

/* Imported APIs: avfilter_free;ff_graph_thread_free;av_freep;av_opt_free */
/* String XREFs:  */

int avfilter_graph_free(void* ctx) {
    // Function prologue: set up stack frame
    avfilter_free(...);
    ff_graph_thread_free(...);
    av_freep(...);
    av_opt_free(...);
    return 0;
}
