// Reconstructed Pseudocode for FN_libffmpeg_0029C928 (ff_hevc_hls_filter)
// Library: libffmpeg.so | RVA: 0x29C928 | Size: 2844B | Visibility: FACT

/* Imported APIs: ff_progress_frame_report */
/* String XREFs: ncode_frame_init(lame_internal_flags *  const sample_t *const *) */

int ff_hevc_hls_filter(void* ctx) {
    // Function prologue: set up stack frame
    sub_29D444(ctx);
    sub_29E6B0(ctx);
    sub_29D444(ctx);
    sub_29E6B0(ctx);
    sub_29D444(ctx);
    ff_progress_frame_report(...);
    return 0;
}
