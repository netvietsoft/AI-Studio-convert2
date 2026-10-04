// Function: MMCodec::FFmpegResample::resample(AVFrame*, unsigned char**, int*, int)
// RVA: 0x167428, Size: 2188 bytes
int64_t _ZN7MMCodec14FFmpegResample8resampleEP7AVFramePPhPii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x167470
    av_channel_layout_uninit(...); // call imported API via PLT at 0x167480
    av_channel_layout_copy(...); // call imported API via PLT at 0x16748c
    const char* s_6fd58 = "Failed to copy channel layout.
";
    void* g_202130 = (void*)0x202130; // global ref
    fwrite(...); // call imported API via PLT at 0x1674c8
    swr_free(...); // call imported API via PLT at 0x167534
    swr_alloc_set_opts2(...); // call imported API via PLT at 0x16755c
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x16758c
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x1675a4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c0c4 = "[%s(%d)]:> Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1675e4
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x167610
    av_get_sample_fmt_name(...); // call imported API via PLT at 0x167628
    const char* s_6a53e = "%s/MTMV_AICodec: [%s(%d)]:> Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167664
    swr_free(...); // call imported API via PLT at 0x16766c
    return a0;
    swr_init(...); // call imported API via PLT at 0x1676a8
    _Znwm(...); // call imported API via PLT at 0x1676bc
    av_channel_layout_uninit(...); // call imported API via PLT at 0x1676cc
    av_channel_layout_copy(...); // call imported API via PLT at 0x1676d8
    const char* s_6fd58 = "Failed to copy channel layout.
";
    void* g_202130 = (void*)0x202130; // global ref
    fwrite(...); // call imported API via PLT at 0x1676fc
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1677b4
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x1677c4
    av_samples_get_buffer_size(...); // call imported API via PLT at 0x167818
    _ZN7MMCodec8MMBuffer7reallocEm(...); // call imported API via PLT at 0x16782c
    av_samples_fill_arrays(...); // call imported API via PLT at 0x16784c
    swr_set_compensation(...); // call imported API via PLT at 0x167880
    swr_convert(...); // call imported API via PLT at 0x1678a8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_894a1 = "[%s(%d)]:> audio buffer is probably too small, try reInit swr_ctx"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1678f8
    swr_init(...); // call imported API via PLT at 0x167914
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6814e = "[%s(%d)]:> av_samples_get_buffer_size() failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x16795c
    const char* s_83bfb = "%s/MTMV_AICodec: [%s(%d)]:> av_samples_get_buffer_size() failed

"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167998
    const char* s_79b56 = "resample"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_868cb = "[%s(%d)]:> [%s] av_samples_fill_arrays() failed
"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1679e0
    const char* s_79b56 = "resample"; // string xref
    const char* s_8945e = "%s/MTMV_AICodec: [%s(%d)]:> [%s] av_samples_fill_arrays() failed

"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167a20
    swr_convert(...); // call imported API via PLT at 0x167a38
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c134 = "[%s(%d)]:> swr_convert() failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x167a7c
    const char* s_756e1 = "%s/MTMV_AICodec: [%s(%d)]:> swr_convert() failed

"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167adc
    const char* s_6c6bc = "%s/MTMV_AICodec: [%s(%d)]:> audio buffer is probably too small, try reInit swr_ctx
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167b3c
    swr_init(...); // call imported API via PLT at 0x167b44
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_721ee = "[%s(%d)]:> reInit swr_ctx failed"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x167b80
    const char* s_868fc = "%s/MTMV_AICodec: [%s(%d)]:> reInit swr_ctx failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x167bb4
    swr_free(...); // call imported API via PLT at 0x167bbc
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x167bcc
    av_sample_fmt_is_planar(...); // call imported API via PLT at 0x167bd8
    memmove(...); // call imported API via PLT at 0x167c00
    void* g_201008 = (void*)0x201008; // global ref
    memmove(...); // call imported API via PLT at 0x167c2c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8af5d = "[%s(%d)]:> swr_set_compensation() failed
"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x167c74
    const char* s_78d97 = "%s/MTMV_AICodec: [%s(%d)]:> swr_set_compensation() failed

"; // string xref
    const char* s_79b56 = "resample"; // string xref
    __stack_chk_fail(...); // call imported API via PLT at 0x167cb0
}
