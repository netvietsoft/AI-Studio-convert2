// Reconstructed Pseudocode for FN_libffmpeg_0026C4AC (sub_26C4AC)
// Library: libffmpeg.so | RVA: 0x26C4AC | Size: 8488B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_hevc_compute_poc;av_log;ff_hevc_frame_nb_refs;ff_hevc_decode_short_term_rps;av_freep;av_malloc_array;ff_progress_frame_report;ff_hevc_slice_rpl;ff_refstruct_replace;ff_hevc_clear_refs */
/* String XREFs: Ignoring POC change between slices: %d -> %d;PPS id out of range: %d;PPS changed between slices.;Unknown slice type: %d.;Invalid slice segment address: %u. */

int sub_26C4AC(void* ctx) {
    // Function prologue: set up stack frame
    sub_26E5D4(ctx);
    sub_27243C(ctx);
    sub_2724AC(ctx);
    sub_2724AC(ctx);
    sub_27243C(ctx);
    ff_hevc_compute_poc(...);
    av_log(...);
    ff_hevc_frame_nb_refs(...);
    ff_hevc_decode_short_term_rps(...);
    av_freep(...);
    return 0;
}
