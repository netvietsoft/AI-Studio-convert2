// Reconstructed Pseudocode for FN_libffmpeg_0036BD60 (sub_36BD60)
// Library: libffmpeg.so | RVA: 0x36BD60 | Size: 4032B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_alloc_unit_content;ff_cbs_read_simple_unsigned;ff_cbs_read_unsigned;av_buffer_ref;av_buffer_allocz;av_log;ff_cbs_read_signed;abort */
/* String XREFs: Slice Header;slice_vertical_position;slice_vertical_position_extension;priority_breakpoint;quantiser_scale_code */

int sub_36BD60(void* ctx) {
    // Function prologue: set up stack frame
    sub_36E07C(ctx);
    sub_36DF9C(ctx);
    sub_36E1E0(ctx);
    sub_36E308(ctx);
    sub_36E298(ctx);
    ff_cbs_alloc_unit_content(...);
    ff_cbs_read_simple_unsigned(...);
    ff_cbs_read_unsigned(...);
    av_buffer_ref(...);
    av_buffer_allocz(...);
    return 0;
}
