// Function: MMCodec::OutMediaHandle::open(unsigned char*, unsigned long, char const*)
// RVA: 0xe7a28, Size: 1108 bytes
int64_t _ZN7MMCodec14OutMediaHandle4openEPhmPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_7a12a = "mp3"; // string xref
    av_match_ext(...); // call imported API via PLT at 0xe7a70
    const char* s_7125e = "aac"; // string xref
    av_match_ext(...); // call imported API via PLT at 0xe7a98
    pthread_self(...); // call imported API via PLT at 0xe7abc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f7ba = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> alloc output context using format "adts""; // string xref
    const char* s_6ba3e = "open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe7ae8
    pthread_self(...); // call imported API via PLT at 0xe7b04
    const char* s_8adb0 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> alloc output context using format "adts"
"; // string xref
    const char* s_6ba3e = "open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe7b2c
    const char* s_68542 = "adts"; // string xref
    avformat_alloc_output_context2(...); // call imported API via PLT at 0xe7b44
    av_mallocz(...); // call imported API via PLT at 0xe7b54
    avio_alloc_context(...); // call imported API via PLT at 0xe7b8c
    av_free(...); // call imported API via PLT at 0xe7bd8
    const char* s_8e426 = "mp4"; // string xref
    avformat_alloc_output_context2(...); // call imported API via PLT at 0xe7bf8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xe7c08
    strlen(...); // call imported API via PLT at 0xe7c10
    _Znwm(...); // call imported API via PLT at 0xe7c48
    memmove(...); // call imported API via PLT at 0xe7c68
    const char* s_8f80a = "alloc output context2 error:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xe7c80
    _ZdlPv(...); // call imported API via PLT at 0xe7ca8
    pthread_self(...); // call imported API via PLT at 0xe7cc4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_6ba3e = "open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe7d08
    pthread_self(...); // call imported API via PLT at 0xe7d24
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_6ba3e = "open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe7d64
    (*x8)(...); // indirect call at 0xe7dc8
    _ZdlPv(...); // call imported API via PLT at 0xe7dd8
    avformat_free_context(...); // call imported API via PLT at 0xe7de4
    return a0;
    sub_D22F8(...); // call internal func at 0xe7e34
    _ZdlPv(...); // call imported API via PLT at 0xe7e5c
    __stack_chk_fail(...); // call imported API via PLT at 0xe7e78
}
