// Reconstructed Pseudocode for FN_libffmpeg_002DDC54 (sub_2DDC54)
// Library: libffmpeg.so | RVA: 0x2DDC54 | Size: 6688B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: memcpy;ff_refstruct_ref;av_buffer_ref;av_log;ff_cbs_write_unsigned;ff_cbs_trace_header;ff_cbs_write_simple_unsigned;ff_refstruct_unref;av_buffer_unref;memmove */
/* String XREFs: OBU header;obu_forbidden_bit;obu_type;obu_extension_flag;obu_has_size_field */

int sub_2DDC54(void* ctx) {
    // Function prologue: set up stack frame
    sub_2E72E0(ctx);
    sub_2E67E0(ctx);
    sub_2E6918(ctx);
    sub_2E726C(ctx);
    sub_2E6664(ctx);
    memcpy(...);
    ff_refstruct_ref(...);
    av_buffer_ref(...);
    av_log(...);
    ff_cbs_write_unsigned(...);
    return 0;
}
