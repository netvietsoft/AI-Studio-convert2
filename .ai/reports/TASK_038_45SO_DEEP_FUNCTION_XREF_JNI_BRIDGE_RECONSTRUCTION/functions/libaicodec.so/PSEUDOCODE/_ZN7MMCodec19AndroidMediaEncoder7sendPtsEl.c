// Function: MMCodec::AndroidMediaEncoder::sendPts(long)
// RVA: 0xf289c, Size: 552 bytes
int64_t _ZN7MMCodec19AndroidMediaEncoder7sendPtsEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec14EglSurfaceBase19setPresentationTimeEl(...); // call imported API via PLT at 0xf28d0
    const char* s_6992a = "sendPts"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7dc96 = "[%s(%d)]:> %s setPresentationTime failed, %lld"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf291c
    const char* s_6992a = "sendPts"; // string xref
    const char* s_89f46 = "%s/MTMV_AICodec: [%s(%d)]:> %s setPresentationTime failed, %lld
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf2960
    av_get_time_base_q(...); // call imported API via PLT at 0xf2964
    av_rescale_q(...); // call imported API via PLT at 0xf2978
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xf2984
    sub_F43BC(...); // call internal func at 0xf29c4
    void* g_201001 = (void*)0x201001; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xf2a00
    return a0;
    const char* s_6992a = "sendPts"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_712cc = "[%s(%d)]:> %s state is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf2a58
    const char* s_6992a = "sendPts"; // string xref
    const char* s_6bb24 = "%s/MTMV_AICodec: [%s(%d)]:> %s state is invalid
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf2a98
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xf2ab8
}
