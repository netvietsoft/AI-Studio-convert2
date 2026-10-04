// Reconstructed Pseudocode for FN_libffmpeg_002E336C (sub_2E336C)
// Library: libffmpeg.so | RVA: 0x2E336C | Size: 11304B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: av_log;ff_cbs_write_simple_unsigned;ff_cbs_write_unsigned;ff_cbs_write_signed */
/* String XREFs: show_existing_frame;show_existing_frame;frame_to_show_map_idx;display_frame_id;frame_type */

int sub_2E336C(void* ctx) {
    // Function prologue: set up stack frame
    sub_2E664C(ctx);
    sub_2E6C24(ctx);
    sub_2E6F10(ctx);
    sub_2E66A0(ctx);
    sub_2E6878(ctx);
    av_log(...);
    ff_cbs_write_simple_unsigned(...);
    ff_cbs_write_unsigned(...);
    ff_cbs_write_signed(...);
    return 0;
}
