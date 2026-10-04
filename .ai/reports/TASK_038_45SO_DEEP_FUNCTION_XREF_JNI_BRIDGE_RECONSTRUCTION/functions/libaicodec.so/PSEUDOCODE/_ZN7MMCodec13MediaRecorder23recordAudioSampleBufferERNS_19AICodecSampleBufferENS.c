// Function: MMCodec::MediaRecorder::recordAudioSampleBuffer(MMCodec::AICodecSampleBuffer&, std::__ndk1::function<void ()>)
// RVA: 0xe4864, Size: 1280 bytes
int64_t _ZN7MMCodec13MediaRecorder23recordAudioSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec19AICodecSampleBuffer12getMediaTypeEv(...); // call imported API via PLT at 0xe48a4
    pthread_self(...); // call imported API via PLT at 0xe48cc
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8caa1 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> invalid media type"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe48f8
    pthread_self(...); // call imported API via PLT at 0xe491c
    const char* s_684bc = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> invalid media type
"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe4944
    return a0;
    _ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv(...); // call imported API via PLT at 0xe4984
    _ZN7MMCodec10MediaParam8hasAudioEv(...); // call imported API via PLT at 0xe4994
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xe49c0
    _ZNK7MMCodec28AICodecFFmpegAudioDataBuffer18getAudioBufferSizeEv(...); // call imported API via PLT at 0xe49d8
    av_get_bytes_per_sample(...); // call imported API via PLT at 0xe49e4
    _ZNK7MMCodec28AICodecFFmpegAudioDataBuffer14getAudioBufferEv(...); // call imported API via PLT at 0xe49f4
    av_samples_fill_arrays(...); // call imported API via PLT at 0xe4a14
    _ZNK7MMCodec28AICodecFFmpegAudioDataBuffer18getAudioBufferSizeEv(...); // call imported API via PLT at 0xe4a60
    _ZN7MMCodec14OutMediaHandle8sendDataEPPhmPmlNS_11MediaType_tENSt6__ndk18functionIFvvEEE(...); // call imported API via PLT at 0xe4a88
    pthread_self(...); // call imported API via PLT at 0xe4ac8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7a07c = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> get null data buffer form sample buffer"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe4af4
    pthread_self(...); // call imported API via PLT at 0xe4b18
    const char* s_711c2 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> get null data buffer form sample buffer
"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe4b40
    pthread_self(...); // call imported API via PLT at 0xe4b80
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_83f9c = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> fail to fill sample array %d"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe4bb0
    pthread_self(...); // call imported API via PLT at 0xe4bd4
    const char* s_67340 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> fail to fill sample array %d
"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe4c00
    (*x8)(...); // indirect call at 0xe4c24
    void* g_2010d0 = (void*)0x2010d0; // global ref
    pthread_self(...); // call imported API via PLT at 0xe4c68
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_67395 = "[%s(%d)]:> [MediaRecorder(%p)](%ld):> fail to send frame to RecorderHandle::audio %d"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe4c98
    pthread_self(...); // call imported API via PLT at 0xe4cbc
    const char* s_83fdf = "%s/MTMV_AICodec: [%s(%d)]:> [MediaRecorder(%p)](%ld):> fail to send frame to RecorderHandle::audio %d
"; // string xref
    const char* s_8cada = "recordAudioSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe4ce8
    (*x9)(...); // indirect call at 0xe4d08
    (*x9)(...); // indirect call at 0xe4d44
    __stack_chk_fail(...); // call imported API via PLT at 0xe4d60
}
