// Reconstructed Pseudocode for FN_libffmpeg_00372A58 (sub_372A58)
// Library: libffmpeg.so | RVA: 0x372A58 | Size: 8744B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_read_simple_unsigned;ff_cbs_read_unsigned;av_log;av_buffer_allocz */
/* String XREFs: Slice Header;first_mb_in_slice;slice_type;pic_parameter_set_id;colour_plane_id */

int sub_372A58(void* ctx) {
    // Function prologue: set up stack frame
    sub_3A1E70(ctx);
    sub_3A0E50(ctx);
    sub_39E0B4(ctx);
    sub_3A0648(ctx);
    sub_388840(ctx);
    ff_cbs_read_simple_unsigned(...);
    ff_cbs_read_unsigned(...);
    av_log(...);
    av_buffer_allocz(...);
    return 0;
}
