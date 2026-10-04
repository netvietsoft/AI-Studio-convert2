// Function: MMCodec::AudioStream::setEncoder(int)
// RVA: 0xceeb8, Size: 268 bytes
int64_t _ZN7MMCodec11AudioStream10setEncoderEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avcodec_find_encoder(...); // call imported API via PLT at 0xceed4
    return a0;
    pthread_self(...); // call imported API via PLT at 0xcef14
    avcodec_get_name(...); // call imported API via PLT at 0xcef20
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89be8 = "[%s(%d)]:> [AudioStream(%p)](%ld):> Cannot find codec %s"; // string xref
    const char* s_70ef7 = "setEncoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcef50
    pthread_self(...); // call imported API via PLT at 0xcef74
    avcodec_get_name(...); // call imported API via PLT at 0xcef80
    const char* s_7b1a7 = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> Cannot find codec %s
"; // string xref
    const char* s_70ef7 = "setEncoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xcefac
    return a0;
}
