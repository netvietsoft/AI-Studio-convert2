// Function: MMCodec::InMediaHandle::getMediaInfo(MMCodec::MediaParam_t*)
// RVA: 0x141b50, Size: 2496 bytes
int64_t _ZN7MMCodec13InMediaHandle12getMediaInfoEPNS_12MediaParam_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x141bcc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87724 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> More than limit stream numbers
"; // string xref
    const char* s_6c3d2 = "getMediaInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x141bf8
    pthread_self(...); // call imported API via PLT at 0x141c1c
    const char* s_901d6 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> More than limit stream numbers

"; // string xref
    const char* s_6c3d2 = "getMediaInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x141c44
    strlen(...); // call imported API via PLT at 0x141c74
    av_strlcpy(...); // call imported API via PLT at 0x141c90
    _ZN7MMCodec18MediaHandleContext16getTotalDurationEib(...); // call imported API via PLT at 0x141d08
    avcodec_get_name(...); // call imported API via PLT at 0x141d1c
    av_strlcpy(...); // call imported API via PLT at 0x141d2c
    _ZN7MMCodec14getProfileNameE9AVCodecIDi(...); // call imported API via PLT at 0x141d54
    __strlen_chk(...); // call imported API via PLT at 0x141d74
    void* g_201170 = (void*)0x201170; // global ref
    av_strlcpy(...); // call imported API via PLT at 0x141d98
    const char* s_7125e = "aac"; // string xref
    strcmp(...); // call imported API via PLT at 0x141dd0
    av_init_packet(...); // call imported API via PLT at 0x141de4
    av_seek_frame(...); // call imported API via PLT at 0x141e30
    av_packet_unref(...); // call imported API via PLT at 0x141e40
    av_read_frame(...); // call imported API via PLT at 0x141e4c
    av_packet_unref(...); // call imported API via PLT at 0x141eac
    av_read_frame(...); // call imported API via PLT at 0x141eb8
    const char* s_7a12a = "mp3"; // string xref
    strcmp(...); // call imported API via PLT at 0x141f40
    void* g_201220 = (void*)0x201220; // global ref
    _ZN7MMCodec16getDisplayMatrixEP8AVStreamRi(...); // call imported API via PLT at 0x141f64
    av_guess_sample_aspect_ratio(...); // call imported API via PLT at 0x141f88
    av_mul_q(...); // call imported API via PLT at 0x141fb8
    av_rescale(...); // call imported API via PLT at 0x141fcc
    _ZN7MMCodec19getVideoOuterFormatE13AVPixelFormat(...); // call imported API via PLT at 0x141fe0
    pthread_self(...); // call imported API via PLT at 0x142028
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d1c6 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Media stream format connot support
"; // string xref
    const char* s_6c3d2 = "getMediaInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142054
    pthread_self(...); // call imported API via PLT at 0x142078
    const char* s_71cba = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Media stream format connot support

"; // string xref
    const char* s_6c3d2 = "getMediaInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1420a0
    av_packet_unref(...); // call imported API via PLT at 0x142118
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x142150
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_838f6 = "[%s(%d)]:> error: %s"; // string xref
    const char* s_7f521 = "getAACDuration"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142178
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1421a0
    const char* s_902d1 = "%s/MTMV_AICodec: [%s(%d)]:> error: %s
"; // string xref
    const char* s_7f521 = "getAACDuration"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1421c4
    avformat_seek_file(...); // call imported API via PLT at 0x1421e0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x142210
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6eaf2 = "[%s(%d)]:> avformat_seek_file %s"; // string xref
    const char* s_7f521 = "getAACDuration"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142238
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x142260
    const char* s_6eb13 = "%s/MTMV_AICodec: [%s(%d)]:> avformat_seek_file %s
"; // string xref
    const char* s_7f521 = "getAACDuration"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142284
    av_get_time_base_q(...); // call imported API via PLT at 0x1422a0
    av_rescale_q(...); // call imported API via PLT at 0x1422b0
    _ZN7MMCodec19getAudioOuterFormatE14AVSampleFormat(...); // call imported API via PLT at 0x1422d8
    _ZdlPv(...); // call imported API via PLT at 0x142318
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x142344
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d751 = "[%s(%d)]:> av_seek_frame %s"; // string xref
    const char* s_7f521 = "getAACDuration"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14236c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x142394
    const char* s_8efa3 = "%s/MTMV_AICodec: [%s(%d)]:> av_seek_frame %s
"; // string xref
    const char* s_7f521 = "getAACDuration"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1423b8
    pthread_self(...); // call imported API via PLT at 0x1423f8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7830b = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> InMediaHandle::getMediaInfo In parameter is null
"; // string xref
    const char* s_6c3d2 = "getMediaInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x142424
    pthread_self(...); // call imported API via PLT at 0x142448
    const char* s_6a17a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> InMediaHandle::getMediaInfo In parameter is null

"; // string xref
    const char* s_6c3d2 = "getMediaInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x142470
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x1424ec
    __stack_chk_fail(...); // call imported API via PLT at 0x14250c
}
