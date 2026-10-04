// Function: MMCodec::FFmpegMediaStream::findAudioCodecDelayInfo()
// RVA: 0x138630, Size: 2296 bytes
int64_t _ZN7MMCodec17FFmpegMediaStream23findAudioCodecDelayInfoEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_init_packet(...); // call imported API via PLT at 0x138694
    av_get_time_base_q(...); // call imported API via PLT at 0x1386c0
    av_rescale_q(...); // call imported API via PLT at 0x1386d0
    av_seek_frame(...); // call imported API via PLT at 0x1386e4
    pthread_self(...); // call imported API via PLT at 0x138710
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x13871c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71af8 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> av_seek_frame:%s"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13874c
    pthread_self(...); // call imported API via PLT at 0x138770
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x13877c
    const char* s_7d02e = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> av_seek_frame:%s
"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1387a8
    av_read_frame(...); // call imported API via PLT at 0x1387bc
    av_packet_unref(...); // call imported API via PLT at 0x1387d8
    av_read_frame(...); // call imported API via PLT at 0x1387e4
    pthread_self(...); // call imported API via PLT at 0x1388b4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6e9f6 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> It's not audio stream, doesn't need to find delay info."; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1388e0
    pthread_self(...); // call imported API via PLT at 0x138904
    const char* s_81193 = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> It's not audio stream, doesn't need to find delay info.
"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13892c
    av_packet_unref(...); // call imported API via PLT at 0x138938
    av_seek_frame(...); // call imported API via PLT at 0x13894c
    return a0;
    strlen(...); // call imported API via PLT at 0x1389b8
    _Znwm(...); // call imported API via PLT at 0x1389f4
    memmove(...); // call imported API via PLT at 0x138a18
    const char* s_84800 = "mpegts"; // string xref
    sub_13A2E0(...); // call internal func at 0x138a3c
    void* g_2010e4 = (void*)0x2010e4; // global ref
    av_packet_unref(...); // call imported API via PLT at 0x138ab4
    _ZdlPv(...); // call imported API via PLT at 0x138ac4
    av_get_time_base_q(...); // call imported API via PLT at 0x138ad8
    av_rescale_q(...); // call imported API via PLT at 0x138ae8
    av_seek_frame(...); // call imported API via PLT at 0x138afc
    pthread_self(...); // call imported API via PLT at 0x138b28
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x138b34
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71af8 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> av_seek_frame:%s"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x138b64
    pthread_self(...); // call imported API via PLT at 0x138b88
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x138b94
    const char* s_7d02e = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> av_seek_frame:%s
"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x138bc0
    av_packet_unref(...); // call imported API via PLT at 0x138c18
    av_read_frame(...); // call imported API via PLT at 0x138c2c
    _Znwm(...); // call imported API via PLT at 0x138d38
    _ZdlPv(...); // call imported API via PLT at 0x138dc0
    pthread_self(...); // call imported API via PLT at 0x138e20
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83641 = "[%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Not enough audio Frame to find leading info"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x138e4c
    pthread_self(...); // call imported API via PLT at 0x138e74
    const char* s_6a05d = "%s/MTMV_AICodec: [%s(%d)]:> [FFmpegMediaStream(%p)](%ld):> Not enough audio Frame to find leading info
"; // string xref
    const char* s_8d64c = "findAudioCodecDelayInfo"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x138e9c
    sub_D206C(...); // call internal func at 0x138eb8
    sub_13E178(...); // call internal func at 0x138ed4
    sub_D22F8(...); // call internal func at 0x138ef0
    _ZdlPv(...); // call imported API via PLT at 0x138f04
    __stack_chk_fail(...); // call imported API via PLT at 0x138f24
}
