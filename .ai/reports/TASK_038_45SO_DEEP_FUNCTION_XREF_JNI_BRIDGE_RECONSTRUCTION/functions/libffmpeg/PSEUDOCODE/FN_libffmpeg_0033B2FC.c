// Reconstructed Pseudocode for FN_libffmpeg_0033B2FC (sub_33B2FC)
// Library: libffmpeg.so | RVA: 0x33B2FC | Size: 10968B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: av_log;avpriv_mpegaudio_decode_header;av_channel_layout_uninit;ff_mpa_l2_select_table;avpriv_request_sample;memmove;memcpy;ff_get_buffer;memset;abort */
/* String XREFs: discarding ID3 tag;Header missing;devices.;incorrect frame size - multiple frames in buffer?;incomplete frame */

int sub_33B2FC(void* ctx) {
    // Function prologue: set up stack frame
    sub_33E014(ctx);
    sub_33E058(ctx);
    sub_33E7F0(ctx);
    sub_33E058(ctx);
    sub_33E058(ctx);
    av_log(...);
    avpriv_mpegaudio_decode_header(...);
    av_channel_layout_uninit(...);
    ff_mpa_l2_select_table(...);
    avpriv_request_sample(...);
    return 0;
}
