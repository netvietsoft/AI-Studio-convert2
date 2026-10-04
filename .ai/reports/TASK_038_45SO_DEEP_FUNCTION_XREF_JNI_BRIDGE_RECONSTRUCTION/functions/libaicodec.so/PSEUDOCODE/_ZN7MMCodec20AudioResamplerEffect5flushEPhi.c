// Function: MMCodec::AudioResamplerEffect::flush(unsigned char*, int)
// RVA: 0xed238, Size: 508 bytes
int64_t _ZN7MMCodec20AudioResamplerEffect5flushEPhi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0xed280
    av_samples_fill_arrays(...); // call imported API via PLT at 0xed2a0
    swr_convert(...); // call imported API via PLT at 0xed2bc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed2e8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e486 = "[%s(%d)]:> swr_convert() failed [%s]
"; // string xref
    const char* s_881e0 = "flush"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xed310
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed33c
    const char* s_7dbf2 = "%s/MTMV_AICodec: [%s(%d)]:> swr_convert() failed [%s]

"; // string xref
    const char* s_881e0 = "flush"; // string xref
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed388
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89f09 = "[%s(%d)]:> Fill sample error![%s]
"; // string xref
    const char* s_881e0 = "flush"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xed3b0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xed3dc
    const char* s_7b544 = "%s/MTMV_AICodec: [%s(%d)]:> Fill sample error![%s]

"; // string xref
    const char* s_881e0 = "flush"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xed400
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xed430
}
