// Function: MMCodec::VideoStream::setEncoder(int)
// RVA: 0xd5474, Size: 244 bytes
int64_t _ZN7MMCodec11VideoStream10setEncoderEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avcodec_find_encoder(...); // call imported API via PLT at 0xd5490
    return a0;
    pthread_self(...); // call imported API via PLT at 0xd54d0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_72514 = "[%s(%d)]:> [VideoStream(%p)](%ld):> Cannot find %d coder"; // string xref
    const char* s_70ef7 = "setEncoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xd5500
    pthread_self(...); // call imported API via PLT at 0xd5524
    const char* s_75c04 = "%s/MTMV_AICodec: [%s(%d)]:> [VideoStream(%p)](%ld):> Cannot find %d coder
"; // string xref
    const char* s_70ef7 = "setEncoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xd5550
    return a0;
}
