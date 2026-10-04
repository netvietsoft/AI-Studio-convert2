// Reconstructed Pseudocode for FN_libffmpeg_0022774C (sub_22774C)
// Library: libffmpeg.so | RVA: 0x22774C | Size: 2780B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_trace_header;memcpy;av_log;ff_cbs_write_unsigned;ff_cbs_write_simple_unsigned;abort */
/* String XREFs: Frame;frame_marker;profile_low_bit;profile_high_bit;show_existing_frame */

int sub_22774C(void* ctx) {
    // Function prologue: set up stack frame
    sub_2293F8(ctx);
    sub_229220(ctx);
    sub_229220(ctx);
    sub_229704(ctx);
    sub_2295E0(ctx);
    ff_cbs_trace_header(...);
    memcpy(...);
    av_log(...);
    ff_cbs_write_unsigned(...);
    ff_cbs_write_simple_unsigned(...);
    return 0;
}
