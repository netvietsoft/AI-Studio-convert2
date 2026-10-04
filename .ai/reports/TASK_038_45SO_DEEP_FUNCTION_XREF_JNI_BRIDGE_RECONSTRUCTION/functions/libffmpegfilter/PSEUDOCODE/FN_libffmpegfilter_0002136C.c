// Reconstructed Pseudocode for FN_libffmpegfilter_0002136C (ff_filter_alloc)
// Library: libffmpegfilter.so | RVA: 0x2136C | Size: 356B | Visibility: FACT

/* Imported APIs: av_mallocz;av_strdup;av_opt_set_defaults;av_memdup;av_freep;av_free */
/* String XREFs:  */

int ff_filter_alloc(void* ctx) {
    // Function prologue: set up stack frame
    sub_228E8(ctx);
    sub_228E8(ctx);
    av_mallocz(...);
    av_strdup(...);
    av_opt_set_defaults(...);
    av_memdup(...);
    av_freep(...);
    return 0;
}
