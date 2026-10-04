// Function: MMCodec::ffmpeg_log_callback(void*, int, char const*, std::__va_list)
// RVA: 0x12e3bc, Size: 544 bytes
int64_t _ZN7MMCodec19ffmpeg_log_callbackEPviPKcSt9__va_list(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_log_get_level(...); // call imported API via PLT at 0x12e3f0
    av_log_format_line(...); // call imported API via PLT at 0x12e428
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_810f5 = "[%s(%d)]:> ffmpeg_log %s"; // string xref
    const char* s_835db = "ffmpeg_log_callback"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12e47c
    const char* s_8ed41 = "%s/MTMV_AICodec: [%s(%d)]:> ffmpeg_log %s
"; // string xref
    const char* s_835db = "ffmpeg_log_callback"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_810f5 = "[%s(%d)]:> ffmpeg_log %s"; // string xref
    const char* s_835db = "ffmpeg_log_callback"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12e4f4
    const char* s_8ed41 = "%s/MTMV_AICodec: [%s(%d)]:> ffmpeg_log %s
"; // string xref
    const char* s_835db = "ffmpeg_log_callback"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_810f5 = "[%s(%d)]:> ffmpeg_log %s"; // string xref
    const char* s_835db = "ffmpeg_log_callback"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12e56c
    const char* s_8ed41 = "%s/MTMV_AICodec: [%s(%d)]:> ffmpeg_log %s
"; // string xref
    const char* s_835db = "ffmpeg_log_callback"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12e5ac
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x12e5d8
}
