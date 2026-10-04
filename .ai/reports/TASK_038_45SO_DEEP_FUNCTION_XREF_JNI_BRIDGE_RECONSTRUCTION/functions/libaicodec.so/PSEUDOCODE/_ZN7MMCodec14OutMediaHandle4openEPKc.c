// Function: MMCodec::OutMediaHandle::open(char const*)
// RVA: 0xe7ec4, Size: 2004 bytes
int64_t _ZN7MMCodec14OutMediaHandle4openEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc(...); // call imported API via PLT at 0xe7efc
    const char* s_7a12a = "mp3"; // string xref
    av_match_ext(...); // call imported API via PLT at 0xe7f0c
    const char* s_7125e = "aac"; // string xref
    av_match_ext(...); // call imported API via PLT at 0xe7f34
    pthread_self(...); // call imported API via PLT at 0xe7f58
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f7ba = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> alloc output context using format "adts""; // string xref
    const char* s_6ba3e = "open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe7f84
    pthread_self(...); // call imported API via PLT at 0xe7fa0
    const char* s_8adb0 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> alloc output context using format "adts"
"; // string xref
    const char* s_6ba3e = "open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe7fc8
    const char* s_68542 = "adts"; // string xref
    avformat_alloc_output_context2(...); // call imported API via PLT at 0xe7fe0
    void* g_201020 = (void*)0x201020; // global ref
    avio_open(...); // call imported API via PLT at 0xe7ffc
    strlen(...); // call imported API via PLT at 0xe8014
    strncpy(...); // call imported API via PLT at 0xe8024
    strlen(...); // call imported API via PLT at 0xe8030
    avformat_alloc_output_context2(...); // call imported API via PLT at 0xe8070
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xe8080
    strlen(...); // call imported API via PLT at 0xe8088
    _Znwm(...); // call imported API via PLT at 0xe80c0
    memmove(...); // call imported API via PLT at 0xe80e0
    const char* s_8f80a = "alloc output context2 error:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xe80f8
    _ZdlPv(...); // call imported API via PLT at 0xe8120
    pthread_self(...); // call imported API via PLT at 0xe813c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_6ba3e = "open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8180
    pthread_self(...); // call imported API via PLT at 0xe819c
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_6ba3e = "open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe81dc
    (*x8)(...); // indirect call at 0xe8244
    _Znwm(...); // call imported API via PLT at 0xe8254
    memcpy(...); // call imported API via PLT at 0xe8274
    const char* s_72645 = "av io open failed:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xe828c
    const char* s_8580a = " :"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call imported API via PLT at 0xe82b4
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xe82d4
    strlen(...); // call imported API via PLT at 0xe82dc
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0xe8318
    memmove(...); // call imported API via PLT at 0xe8338
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm(...); // call imported API via PLT at 0xe8364
    _ZdlPv(...); // call imported API via PLT at 0xe83b4
    _ZdlPv(...); // call imported API via PLT at 0xe83c4
    _ZdlPv(...); // call imported API via PLT at 0xe83d4
    _ZdlPv(...); // call imported API via PLT at 0xe83e4
    pthread_self(...); // call imported API via PLT at 0xe8400
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_6ba3e = "open"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xe8444
    pthread_self(...); // call imported API via PLT at 0xe8460
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_6ba3e = "open"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xe84a0
    (*x8)(...); // indirect call at 0xe8508
    _ZdlPv(...); // call imported API via PLT at 0xe8518
    avio_closep(...); // call imported API via PLT at 0xe8534
    avformat_free_context(...); // call imported API via PLT at 0xe853c
    return a0;
    sub_D22F8(...); // call internal func at 0xe858c
    sub_D22F8(...); // call internal func at 0xe85a4
    sub_D22F8(...); // call internal func at 0xe85bc
    _ZdlPv(...); // call imported API via PLT at 0xe85ec
    _ZdlPv(...); // call imported API via PLT at 0xe8644
    _ZdlPv(...); // call imported API via PLT at 0xe8654
    _ZdlPv(...); // call imported API via PLT at 0xe8678
    __stack_chk_fail(...); // call imported API via PLT at 0xe8694
}
