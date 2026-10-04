// Reconstructed Pseudocode for FN_libffmpeg_002DC4B4 (sub_2DC4B4)
// Library: libffmpeg.so | RVA: 0x2DC4B4 | Size: 6048B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_cbs_alloc_unit_content;av_log;ff_cbs_read_simple_unsigned;av_buffer_alloc;ff_cbs_read_unsigned;abort;ff_refstruct_replace */
/* String XREFs: obu_size;Invalid OBU length: unit too short (%zu).;output_frame_width_in_tiles_minus_1;output_frame_height_in_tiles_minus_1;tile_count_minus_1 */

int sub_2DC4B4(void* ctx) {
    // Function prologue: set up stack frame
    sub_2DF824(ctx);
    sub_2E71A0(ctx);
    sub_2DFADC(ctx);
    sub_2E699C(ctx);
    sub_2DFADC(ctx);
    ff_cbs_alloc_unit_content(...);
    av_log(...);
    ff_cbs_read_simple_unsigned(...);
    av_buffer_alloc(...);
    ff_cbs_read_unsigned(...);
    return 0;
}
