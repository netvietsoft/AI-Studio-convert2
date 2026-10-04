// Reconstructed Pseudocode for FN_libffmpeg_00374C80 (sub_374C80)
// Library: libffmpeg.so | RVA: 0x374C80 | Size: 7496B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_write_simple_unsigned;ff_cbs_write_unsigned;av_log */
/* String XREFs: Slice Header;first_mb_in_slice;slice_type;pic_parameter_set_id;colour_plane_id */

int sub_374C80(void* ctx) {
    // Function prologue: set up stack frame
    sub_39E0B4(ctx);
    sub_39E414(ctx);
    sub_389638(ctx);
    sub_39E038(ctx);
    sub_389770(ctx);
    ff_cbs_write_simple_unsigned(...);
    ff_cbs_write_unsigned(...);
    av_log(...);
    return 0;
}
