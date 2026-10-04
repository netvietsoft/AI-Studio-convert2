// Reconstructed Pseudocode for FN_libffmpeg_003696D0 (sub_3696D0)
// Library: libffmpeg.so | RVA: 0x3696D0 | Size: 3156B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_alloc_unit_content;ff_cbs_trace_header;av_log;abort;av_buffer_ref */
/* String XREFs: Frame;frame_type;profile;show_frame;first_partition_length_in_bytes */

int sub_3696D0(void* ctx) {
    // Function prologue: set up stack frame
    sub_36A8CC(ctx);
    sub_36A32C(ctx);
    sub_36A32C(ctx);
    sub_36A8CC(ctx);
    sub_36A32C(ctx);
    ff_cbs_alloc_unit_content(...);
    ff_cbs_trace_header(...);
    av_log(...);
    abort(...);
    av_buffer_ref(...);
    return 0;
}
