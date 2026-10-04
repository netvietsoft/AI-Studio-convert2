// Reconstructed Pseudocode for FN_libffmpegfilter_0002198C (avfilter_init_dict)
// Library: libffmpegfilter.so | RVA: 0x2198C | Size: 208B | Visibility: FACT

/* Imported APIs: av_opt_set_dict2 */
/* String XREFs: Filter already initialized;Error applying generic filter options. */

int avfilter_init_dict(void* ctx) {
    // Function prologue: set up stack frame
    sub_22864(ctx);
    sub_228A4(ctx);
    sub_21254(ctx);
    sub_22864(ctx);
    av_opt_set_dict2(...);
    return 0;
}
