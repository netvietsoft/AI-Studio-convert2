// Function: MMCodec::AudioResamplerEffect::init()
// RVA: 0xecc44, Size: 480 bytes
int64_t _ZN7MMCodec20AudioResamplerEffect4initEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_channel_layout_default(...); // call imported API via PLT at 0xecc7c
    av_channel_layout_default(...); // call imported API via PLT at 0xecc88
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xecc90
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xecca0
    swr_alloc_set_opts2(...); // call imported API via PLT at 0xecccc
    swr_init(...); // call imported API via PLT at 0xeccd8
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xecd10
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xecd24
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6cfba = "[%s(%d)]:> Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xecd64
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xecd90
    av_get_sample_fmt_name(...); // call imported API via PLT at 0xecda4
    const char* s_7db71 = "%s/MTMV_AICodec: [%s(%d)]:> Cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %d channels!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xecde0
    swr_free(...); // call imported API via PLT at 0xecde8
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xece20
}
