// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x7d158
// Recovered Name: sub_7d158
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7d158 | Size: 3020 bytes | SHA256: 3c9db2cbfe750225d1c7fddf0530cd2a0dea3d0212e3fe26b0b75f1ef11f081d
// Callers: 0 | Callees: 1 | Imports: 31

// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, __android_log_print, av_audio_fifo_alloc, av_audio_fifo_free, av_audio_fifo_read, av_audio_fifo_size, av_channel_layout_copy, av_channel_layout_default, av_channel_layout_uninit, av_frame_alloc, av_frame_free, av_frame_get_buffer, av_frame_unref, av_packet_alloc, av_packet_free, av_rescale_q, av_seek_frame, av_strerror, av_write_trailer, avcodec_flush_buffers, avcodec_free_context, avcodec_open2, avcodec_parameters_from_context, avformat_free_context, avformat_write_header, avio_closep, avio_open, pthread_self, swr_alloc_set_opts2, swr_free, swr_init
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> FFmpeg audio transcode failed: alloc packet/frame failed, pkt=%p decFrame=%p encFrame=%p"
//   "%s/%s: F[%s, L(%d)], T(%p):> FFmpeg audio transcode failed: create audio fifo failed"
//   "%s/%s: F[%s, L(%d)], T(%p):> FFmpeg audio transcode failed: open encoder failed, codec=%s"
//   "%s/%s: F[%s, L(%d)], T(%p):> FFmpeg audio transcode failed: open output file failed, output=%s"
//   "%s/%s: F[%s, L(%d)], T(%p):> FFmpeg audio transcode failed: read encoder frame during flush failed"

void sub_7d158(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 755 instructions
    /* 0x7d158 */ ldr w9, [x8, #0x164];
    /* 0x7d15c */ cmp w9, #1;
    /* 0x7d160 */ b.lt #0x7d174;
    /* 0x7d164 */ add x0, x0, #0x160;
    /* 0x7d168 */ add x1, x8, #0x160;
    av_channel_layout_copy();
    /* 0x7d170 */ b #0x7d180;
    /* 0x7d174 */ add x0, x0, #0x160;
    /* 0x7d178 */ mov w1, #2;
    av_channel_layout_default();
    /* 0x7d180 */ ldr x8, [x23, #0x58];
    av_channel_layout_uninit();
    av_channel_layout_copy();
    avcodec_open2();
    avcodec_parameters_from_context();
    avio_open();
    avformat_write_header();
    swr_alloc_set_opts2();
    swr_init();
    av_audio_fifo_alloc();
    av_rescale_q();
    av_seek_frame();
    avcodec_flush_buffers();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_packet_alloc();
    av_frame_alloc();
    av_frame_alloc();
    av_audio_fifo_size();
    av_audio_fifo_size();
    av_audio_fifo_size();
    av_audio_fifo_size();
    av_frame_unref();
    av_channel_layout_copy();
    av_frame_get_buffer();
    av_audio_fifo_read();
    sub_7ecac();
    av_channel_layout_uninit();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    swr_free();
    av_write_trailer();
    avio_closep();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    avio_closep();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    swr_free();
    av_write_trailer();
    avio_closep();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_frame_free();
    av_frame_free();
    av_packet_free();
    av_audio_fifo_free();
    swr_free();
    av_write_trailer();
    avio_closep();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    av_strerror();
    pthread_self();
    __android_log_print();
    av_strerror();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_audio_fifo_free();
    swr_free();
    av_write_trailer();
    avio_closep();
    av_channel_layout_uninit();
    avcodec_free_context();
    avformat_free_context();
    avcodec_free_context();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    av_channel_layout_uninit();
}
