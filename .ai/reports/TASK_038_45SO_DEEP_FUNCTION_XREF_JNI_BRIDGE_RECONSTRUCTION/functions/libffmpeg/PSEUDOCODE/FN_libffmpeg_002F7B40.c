// Reconstructed Pseudocode for FN_libffmpeg_002F7B40 (ff_mjpeg_decode_frame_from_buf)
// Library: libffmpeg.so | RVA: 0x2F7B40 | Size: 6888B | Visibility: FACT

/* Imported APIs: av_dict_free;av_freep;ff_mjpeg_find_marker;av_log;av_malloc;av_strerror;ff_jpegls_decode_lse;ff_mjpeg_decode_dqt;av_fourcc_make_string;ff_mjpeg_decode_dht */
/* String XREFs: %¯Î1 «¿-Cëâ6?üÿÿÿ;marker=%x avail_size_in_buf=%td;APIC;startcode: %X;restart marker: %d */

int ff_mjpeg_decode_frame_from_buf(void* ctx) {
    // Function prologue: set up stack frame
    sub_2F9628(ctx);
    sub_2F9CF8(ctx);
    sub_2F3DDC(ctx);
    sub_2F9CF8(ctx);
    sub_2F9CF8(ctx);
    av_dict_free(...);
    av_freep(...);
    ff_mjpeg_find_marker(...);
    av_log(...);
    av_malloc(...);
    return 0;
}
