// Reconstructed Pseudocode for FN_libffmpeg_00352178 (sub_352178)
// Library: libffmpeg.so | RVA: 0x352178 | Size: 10684B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: av_log;avpriv_mpegaudio_decode_header;av_channel_layout_uninit;ff_mpa_l2_select_table;avpriv_request_sample;memmove;memcpy;ff_get_buffer;memset;abort */
/* String XREFs: discarding ID3 tag;Header missing;6>ñJ > ¤>Õé;incorrect frame size - multiple frames in buffer?;incomplete frame */

int sub_352178(void* ctx) {
    // Function prologue: set up stack frame
    sub_35550C(ctx);
    sub_354D48(ctx);
    sub_354D8C(ctx);
    sub_354D8C(ctx);
    sub_354D8C(ctx);
    av_log(...);
    avpriv_mpegaudio_decode_header(...);
    av_channel_layout_uninit(...);
    ff_mpa_l2_select_table(...);
    avpriv_request_sample(...);
    return 0;
}
