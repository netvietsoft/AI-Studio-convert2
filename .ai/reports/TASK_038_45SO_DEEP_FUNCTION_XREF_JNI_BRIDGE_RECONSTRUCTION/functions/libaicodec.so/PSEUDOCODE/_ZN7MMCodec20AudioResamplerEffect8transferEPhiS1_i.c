// Function: MMCodec::AudioResamplerEffect::transfer(unsigned char*, int, unsigned char*, int)
// RVA: 0xece24, Size: 1028 bytes
int64_t _ZN7MMCodec20AudioResamplerEffect8transferEPhiS1_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xece7c
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xece8c
    av_samples_fill_arrays(...); // call imported API via PLT at 0xeceb0
    swr_get_delay(...); // call imported API via PLT at 0xecec0
    av_rescale_rnd(...); // call imported API via PLT at 0xeced4
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xecee8
    av_samples_get_buffer_size(...); // call imported API via PLT at 0xecf00
    swr_set_compensation(...); // call imported API via PLT at 0xecf38
    av_samples_fill_arrays(...); // call imported API via PLT at 0xecf60
    swr_convert(...); // call imported API via PLT at 0xecf7c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xecfa8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e486 = "[%s(%d)]:> swr_convert() failed [%s]
"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xecfd0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xecffc
    const char* s_7dbf2 = "%s/MTMV_AICodec: [%s(%d)]:> swr_convert() failed [%s]

"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed048
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89f09 = "[%s(%d)]:> Fill sample error![%s]
"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xed070
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed09c
    const char* s_7b544 = "%s/MTMV_AICodec: [%s(%d)]:> Fill sample error![%s]

"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed0e8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89f09 = "[%s(%d)]:> Fill sample error![%s]
"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xed110
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed13c
    const char* s_7b544 = "%s/MTMV_AICodec: [%s(%d)]:> Fill sample error![%s]

"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xed160
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8af5d = "[%s(%d)]:> swr_set_compensation() failed
"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xed1d8
    const char* s_78d97 = "%s/MTMV_AICodec: [%s(%d)]:> swr_set_compensation() failed

"; // string xref
    const char* s_89f2c = "transfer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xed21c
    __stack_chk_fail(...); // call imported API via PLT at 0xed224
}
