// Function: MMCodec::OutMediaHandle::_writeTrailer()
// RVA: 0xeb008, Size: 320 bytes
int64_t _ZN7MMCodec14OutMediaHandle13_writeTrailerEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_gettime_relative(...); // call imported API via PLT at 0xeb024
    av_write_trailer(...); // call imported API via PLT at 0xeb034
    av_gettime_relative(...); // call imported API via PLT at 0xeb03c
    return a0;
    return a0;
    pthread_self(...); // call imported API via PLT at 0xeb098
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xeb0a4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86e8c = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> write file trailer error[%s]"; // string xref
    const char* s_86ed0 = "_writeTrailer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xeb0d4
    pthread_self(...); // call imported API via PLT at 0xeb0f8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xeb104
    const char* s_7db1b = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> write file trailer error[%s]
"; // string xref
    const char* s_86ed0 = "_writeTrailer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xeb130
    return a0;
}
