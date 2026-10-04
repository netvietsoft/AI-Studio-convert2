// Function: MMCodec::FormatContext::receiveFrame(MMCodec::DecoderBase*, int, MMCodec::MMCodecFrame*)
// RVA: 0x149e30, Size: 1004 bytes
int64_t _ZN7MMCodec13FormatContext12receiveFrameEPNS_11DecoderBaseEiPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x9)(...); // indirect call at 0x149e9c
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x149eb8
    pthread_self(...); // call imported API via PLT at 0x149f14
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6b3b7 = "[%s(%d)]:> [FormatContext(%p)](%ld):> stream index is invalid %d"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x149f44
    pthread_self(...); // call imported API via PLT at 0x149f68
    const char* s_90551 = "%s/MTMV_AICodec: [%s(%d)]:> [FormatContext(%p)](%ld):> stream index is invalid %d
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x149f94
    return a0;
    pthread_self(...); // call imported API via PLT at 0x149fe4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d77d = "[%s(%d)]:> [FormatContext(%p)](%ld):> avstream is null"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14a010
    pthread_self(...); // call imported API via PLT at 0x14a034
    const char* s_6ebe4 = "%s/MTMV_AICodec: [%s(%d)]:> [FormatContext(%p)](%ld):> avstream is null
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14a05c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bed0 = "[%s(%d)]:> find pts:%lld 's duration failed"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14a140
    const char* s_7befc = "%s/MTMV_AICodec: [%s(%d)]:> find pts:%lld 's duration failed
"; // string xref
    const char* s_89055 = "receiveFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x14a17c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14a184
    av_get_time_base_q(...); // call imported API via PLT at 0x14a198
    av_rescale_q(...); // call imported API via PLT at 0x14a1a8
    av_get_time_base_q(...); // call imported API via PLT at 0x14a1bc
    av_rescale_q(...); // call imported API via PLT at 0x14a1cc
    __stack_chk_fail(...); // call imported API via PLT at 0x14a1f0
    _ZdlPv(...); // call imported API via PLT at 0x14a214
}
