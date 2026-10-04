// Function: MMCodec::AICodecFFmpegAudioDataBuffer::transferAndWrite(AVFrame*, void const*)
// RVA: 0x128a2c, Size: 1460 bytes
int64_t _ZN7MMCodec28AICodecFFmpegAudioDataBuffer16transferAndWriteEP7AVFramePKv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec12AudioParam_t13isFormatEqualERKS0_S2_(...); // call imported API via PLT at 0x128a6c
    (*x8)(...); // indirect call at 0x128aa0
    _Znwm(...); // call imported API via PLT at 0x128aac
    _ZN7MMCodec14FFmpegResampleC1Ev(...); // call imported API via PLT at 0x128ab4
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x128ac4
    _ZN7MMCodec14FFmpegResample20setTargetAudioParamsE14AVSampleFormatii(...); // call imported API via PLT at 0x128ad8
    _ZN7MMCodec14FFmpegResample20getNextOutBufferSizeEii(...); // call imported API via PLT at 0x128afc
    av_fast_realloc(...); // call imported API via PLT at 0x128b18
    _ZN7MMCodec14FFmpegResample8resampleEP7AVFramePhRmi(...); // call imported API via PLT at 0x128b34
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d792 = "[%s(%d)]:> re sample failed %d"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x128b80
    const char* s_7a8aa = "%s/MTMV_AICodec: [%s(%d)]:> re sample failed %d
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x128bc0
    _ZN7MMCodec14FFmpegResample20getNextOutBufferSizeEii(...); // call imported API via PLT at 0x128bdc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128c10
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8b7ce = "[%s(%d)]:> getNextOutBufferSize failed %d %s"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x128c3c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128c64
    const char* s_79363 = "%s/MTMV_AICodec: [%s(%d)]:> getNextOutBufferSize failed %d %s
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x128c8c
    return a0;
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x128cd4
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x128cec
    av_fast_realloc(...); // call imported API via PLT at 0x128d08
    av_samples_fill_arrays(...); // call imported API via PLT at 0x128d28
    av_samples_copy(...); // call imported API via PLT at 0x128d48
    av_frame_unref(...); // call imported API via PLT at 0x128d64
    av_frame_alloc(...); // call imported API via PLT at 0x128d78
    av_frame_ref(...); // call imported API via PLT at 0x128d84
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x128dac
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128df4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8ec8e = "[%s(%d)]:> av_samples_get_buffer_size error![%s]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x128e1c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128e48
    const char* s_780dd = "%s/MTMV_AICodec: [%s(%d)]:> av_samples_get_buffer_size error![%s]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128e94
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e907 = "[%s(%d)]:> av_samples_fill_arrays error![%s]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x128ebc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128ee8
    const char* s_793a2 = "%s/MTMV_AICodec: [%s(%d)]:> av_samples_fill_arrays error![%s]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128f34
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82405 = "[%s(%d)]:> av_samples_copy error![%s]"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x128f5c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x128f88
    const char* s_75211 = "%s/MTMV_AICodec: [%s(%d)]:> av_samples_copy error![%s]
"; // string xref
    const char* s_6fb97 = "transferAndWrite"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x128fac
    _ZdlPv(...); // call imported API via PLT at 0x128fd0
    __stack_chk_fail(...); // call imported API via PLT at 0x128fdc
}
