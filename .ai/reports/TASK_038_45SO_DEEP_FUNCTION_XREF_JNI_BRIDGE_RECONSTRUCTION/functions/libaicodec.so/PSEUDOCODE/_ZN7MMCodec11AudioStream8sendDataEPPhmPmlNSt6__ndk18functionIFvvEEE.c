// Function: MMCodec::AudioStream::sendData(unsigned char**, unsigned long, unsigned long*, long, std::__ndk1::function<void ()>)
// RVA: 0xcfacc, Size: 1928 bytes
int64_t _ZN7MMCodec11AudioStream8sendDataEPPhmPmlNSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xcfb20
    _ZN7MMCodec13ThreadContext7isValidEv(...); // call imported API via PLT at 0xcfb34
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0xcfb44
    av_get_bytes_per_sample(...); // call imported API via PLT at 0xcfb5c
    _ZN7MMCodec14FFmpegResample20getNextOutBufferSizeEii(...); // call imported API via PLT at 0xcfba0
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0xcfbbc
    _ZN7MMCodec11initAVFrameEP7AVFrame(...); // call imported API via PLT at 0xcfbcc
    av_channel_layout_uninit(...); // call imported API via PLT at 0xcfbd8
    av_channel_layout_default(...); // call imported API via PLT at 0xcfbe4
    _ZN7MMCodec14FFmpegResample8resampleEP7AVFramePhRmi(...); // call imported API via PLT at 0xcfc34
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xcfc48
    av_samples_get_buffer_size(...); // call imported API via PLT at 0xcfc60
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xcfc7c
    av_samples_fill_arrays(...); // call imported API via PLT at 0xcfc9c
    pthread_self(...); // call imported API via PLT at 0xcfcd0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8183d = "[%s(%d)]:> [AudioStream(%p)](%ld):> encoder didn't start"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcfcfc
    pthread_self(...); // call imported API via PLT at 0xcfd20
    const char* s_67248 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> encoder didn't start
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcfd48
    pthread_self(...); // call imported API via PLT at 0xcfd70
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xcfd80
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7c433 = "[%s(%d)]:> [AudioStream(%p)](%ld):> encode thread state is invalid:%d"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcfdb0
    pthread_self(...); // call imported API via PLT at 0xcfdd4
    _ZN7MMCodec13ThreadContext14getThreadStateEv(...); // call imported API via PLT at 0xcfde4
    const char* s_7d7af = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> encode thread state is invalid:%d
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec16addSamplesToFifoEP11AVAudioFifoPPhi(...); // call imported API via PLT at 0xcfe44
    _ZN7MMCodec11AudioStream26_writeFIFODataToFrameQueueEb(...); // call imported API via PLT at 0xcfe54
    pthread_self(...); // call imported API via PLT at 0xcfe80
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89c21 = "[%s(%d)]:> [AudioStream(%p)](%ld):> getNextOutBufferSize failed[%d]"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcfeb0
    pthread_self(...); // call imported API via PLT at 0xcfed4
    const char* s_90a6b = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> getNextOutBufferSize failed[%d]
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    pthread_self(...); // call imported API via PLT at 0xcff20
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a837 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Add sample to fifo error!"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcff4c
    pthread_self(...); // call imported API via PLT at 0xcff70
    const char* s_7eab8 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Add sample to fifo error!
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcff98
    _Znwm(...); // call imported API via PLT at 0xcffa4
    _ZN7MMCodec8MMBufferC1Em(...); // call imported API via PLT at 0xcffb4
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0xcffc4
    pthread_self(...); // call imported API via PLT at 0xcffec
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79ee6 = "[%s(%d)]:> [AudioStream(%p)](%ld):> realloc buffer failed[%d]"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd001c
    pthread_self(...); // call imported API via PLT at 0xd0040
    const char* s_6836d = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> realloc buffer failed[%d]
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd006c
    (*x8)(...); // indirect call at 0xd0084
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd00e0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e05f = "[%s(%d)]:> [AudioStream(%p)](%ld):> resample failed[%d]"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd0110
    pthread_self(...); // call imported API via PLT at 0xd0134
    const char* s_89c65 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> resample failed[%d]
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0160
    pthread_self(...); // call imported API via PLT at 0xd018c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd0198
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8c71e = "[%s(%d)]:> [AudioStream(%p)](%ld):> Fill sample error![%s]"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd01c8
    pthread_self(...); // call imported API via PLT at 0xd01ec
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xd01f8
    const char* s_7ea6b = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Fill sample error![%s]
"; // string xref
    const char* s_75bc1 = "sendData"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd0224
    _ZdlPv(...); // call imported API via PLT at 0xd0234
    __stack_chk_fail(...); // call imported API via PLT at 0xd0250
}
