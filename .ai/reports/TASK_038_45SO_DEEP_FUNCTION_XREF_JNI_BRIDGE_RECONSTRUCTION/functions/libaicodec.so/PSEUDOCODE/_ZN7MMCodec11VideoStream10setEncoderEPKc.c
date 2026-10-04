// Function: MMCodec::VideoStream::setEncoder(char const*)
// RVA: 0xd5568, Size: 244 bytes
int64_t _ZN7MMCodec11VideoStream10setEncoderEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avcodec_find_encoder_by_name(...); // call imported API via PLT at 0xd5584
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd55c4
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_86cac = "[%s(%d)]:> [VideoStream(%p)](%ld):> Cannot find %s coder"; // string xref
    const char* s_70ef7 = "setEncoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd55f4
    pthread_self(...); // call imported API via PLT at 0xd5618
    const char* s_748ad = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> Cannot find %s coder
"; // string xref
    const char* s_70ef7 = "setEncoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd5644
    return a0;
}
