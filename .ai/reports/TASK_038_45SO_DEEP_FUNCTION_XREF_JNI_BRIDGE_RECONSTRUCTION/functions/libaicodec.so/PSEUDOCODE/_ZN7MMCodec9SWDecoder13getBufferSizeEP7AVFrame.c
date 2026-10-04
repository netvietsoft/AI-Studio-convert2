// Function: MMCodec::SWDecoder::getBufferSize(AVFrame*)
// RVA: 0x1496ac, Size: 256 bytes
int64_t _ZN7MMCodec9SWDecoder13getBufferSizeEP7AVFrame(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_image_get_buffer_size(...); // call imported API via PLT at 0x1496ec
    pthread_self(...); // call imported API via PLT at 0x149710
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_877c5 = "[%s(%d)]:> [SWDecoder(%p)](%ld):> invalid state"; // string xref
    const char* s_78e9a = "getBufferSize"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14973c
    pthread_self(...); // call imported API via PLT at 0x149760
    const char* s_6d9fa = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> invalid state
"; // string xref
    const char* s_78e9a = "getBufferSize"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x149788
    return a0;
    return a0;
}
