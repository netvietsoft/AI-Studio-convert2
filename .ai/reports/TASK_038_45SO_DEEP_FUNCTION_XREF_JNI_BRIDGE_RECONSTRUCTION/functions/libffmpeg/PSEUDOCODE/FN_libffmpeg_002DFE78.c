// Reconstructed Pseudocode for FN_libffmpeg_002DFE78 (sub_2DFE78)
// Library: libffmpeg.so | RVA: 0x2DFE78 | Size: 10332B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_read_simple_unsigned;ff_cbs_read_unsigned;ff_cbs_read_signed;av_log */
/* String XREFs: e_internal_flags *const);l.h;show_existing_frame;frame_to_show_map_idx;display_frame_id */

int sub_2DFE78(void* ctx) {
    // Function prologue: set up stack frame
    sub_2E73B0(ctx);
    sub_2E6F10(ctx);
    sub_2E66D8(ctx);
    sub_2E69DC(ctx);
    sub_2E6A64(ctx);
    ff_cbs_read_simple_unsigned(...);
    ff_cbs_read_unsigned(...);
    ff_cbs_read_signed(...);
    av_log(...);
    return 0;
}
