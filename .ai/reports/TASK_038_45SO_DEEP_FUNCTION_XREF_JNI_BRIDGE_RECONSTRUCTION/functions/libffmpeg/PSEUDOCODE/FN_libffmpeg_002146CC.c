// Reconstructed Pseudocode for FN_libffmpeg_002146CC (ff_cbs_bsf_generic_filter)
// Library: libffmpeg.so | RVA: 0x2146CC | Size: 428B | Visibility: FACT

/* Imported APIs: ff_bsf_get_packet_ref;av_packet_get_side_data;ff_cbs_read_packet_side_data;ff_cbs_write_fragment_data;av_packet_new_side_data;memcpy;ff_cbs_fragment_reset;ff_cbs_read_packet;ff_cbs_write_packet;av_log */
/* String XREFs: Failed to read extradata from packet side data.;Failed to read %s from packet.;No %s found in packet.;Failed to write extradata into packet side data.;Failed to write %s into packet. */

int ff_cbs_bsf_generic_filter(void* ctx) {
    // Function prologue: set up stack frame
    sub_2149A4(ctx);
    sub_2149A4(ctx);
    ff_bsf_get_packet_ref(...);
    av_packet_get_side_data(...);
    ff_cbs_read_packet_side_data(...);
    ff_cbs_write_fragment_data(...);
    av_packet_new_side_data(...);
    return 0;
}
