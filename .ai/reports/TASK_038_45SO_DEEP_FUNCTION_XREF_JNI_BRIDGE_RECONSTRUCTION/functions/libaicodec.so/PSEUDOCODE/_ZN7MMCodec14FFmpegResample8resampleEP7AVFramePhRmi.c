// Function: MMCodec::FFmpegResample::resample(AVFrame*, unsigned char*, unsigned long&, int)
// RVA: 0x167cb4, Size: 2192 bytes
int64_t _ZN7MMCodec14FFmpegResample8resampleEP7AVFramePhRmi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x167cfc
    av_channel_layout_uninit(...); // call imported API via PLT at 0x167d0c
    av_channel_layout_copy(...); // call imported API via PLT at 0x167d18
    const char* s_6fd58 = "Failed to copy channel layout.
";
    void* g_202130 = (void*)0x202130; // global ref
    fwrite(...); // call imported API via PLT at 0x167d54
    swr_free(...); // call imported API via PLT at 0x167dc0
    swr_alloc_set_opts2(...); // call imported API via PLT at 0x167de8
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x167e18
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x167e30
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c0c4 = "[%s(%d)]:> Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x167e70
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x167e9c
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x167eb4
    const char* s_6a53e = "%s/MTMV_AICodec: [%s(%d)]:> Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167ef0
    swr_free(...); // call imported API via PLT at 0x167ef8
    return a0;
    swr_init(...); // call imported API via PLT at 0x167f34
    _Znwm(...); // call imported API via PLT at 0x167f48
    av_channel_layout_uninit(...); // call imported API via PLT at 0x167f58
    av_channel_layout_copy(...); // call imported API via PLT at 0x167f64
    const char* s_6fd58 = "Failed to copy channel layout.
";
    void* g_202130 = (void*)0x202130; // global ref
    fwrite(...); // call imported API via PLT at 0x167f88
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x16800c
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x168020
    av_samples_fill_arrays(...); // call imported API via PLT at 0x168040
    swr_set_compensation(...); // call imported API via PLT at 0x168070
    swr_convert(...); // call imported API via PLT at 0x168098
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_894a1 = "[%s(%d)]:> audio buffer is probably too small, try reInit swr_ctx"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1680ec
    swr_init(...); // call imported API via PLT at 0x168108
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6814e = "[%s(%d)]:> av_samples_get_buffer_size() failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168150
    const char* s_83bfb = "%s/MTMV_AICodec: [%s(%d)]:> av_samples_get_buffer_size() failed

"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x16818c
    const char* s_79b56 = "resample"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_868cb = "[%s(%d)]:> [%s] av_samples_fill_arrays() failed
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1681d4
    const char* s_79b56 = "resample"; // string xref
    const char* s_8945e = "%s/MTMV_AICodec: [%s(%d)]:> [%s] av_samples_fill_arrays() failed

"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168214
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1682a4
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x1682b0
    swr_convert(...); // call imported API via PLT at 0x1682dc
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c134 = "[%s(%d)]:> swr_convert() failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168320
    const char* s_756e1 = "%s/MTMV_AICodec: [%s(%d)]:> swr_convert() failed

"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168364
    const char* s_6c6bc = "%s/MTMV_AICodec: [%s(%d)]:> audio buffer is probably too small, try reInit swr_ctx
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1683ac
    swr_init(...); // call imported API via PLT at 0x1683b4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_721ee = "[%s(%d)]:> reInit swr_ctx failed"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1683f0
    const char* s_868fc = "%s/MTMV_AICodec: [%s(%d)]:> reInit swr_ctx failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168424
    swr_free(...); // call imported API via PLT at 0x16842c
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x16843c
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x168454
    memmove(...); // call imported API via PLT at 0x16847c
    memmove(...); // call imported API via PLT at 0x1684a4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8af5d = "[%s(%d)]:> swr_set_compensation() failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168504
    const char* s_78d97 = "%s/MTMV_AICodec: [%s(%d)]:> swr_set_compensation() failed

"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __stack_chk_fail(...); // call imported API via PLT at 0x168540
}
