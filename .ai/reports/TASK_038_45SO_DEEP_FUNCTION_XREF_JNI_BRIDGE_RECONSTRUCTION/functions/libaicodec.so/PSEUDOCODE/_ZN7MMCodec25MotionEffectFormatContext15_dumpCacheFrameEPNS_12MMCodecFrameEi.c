// Function: MMCodec::MotionEffectFormatContext::_dumpCacheFrame(MMCodec::MMCodecFrame*, int)
// RVA: 0x150a14, Size: 512 bytes
int64_t _ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec12MMCodecFrame12allocAVFrameEv(...); // call imported API via PLT at 0x150a44
    _ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_(...); // call imported API via PLT at 0x150a90
    _ZN7MMCodec18MediaHandleContext17getAICodecContextEv(...); // call imported API via PLT at 0x150a98
    _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(...); // call imported API via PLT at 0x150aa0
    _ZdlPv(...); // call imported API via PLT at 0x150ae0
    av_get_time_base_q(...); // call imported API via PLT at 0x150b2c
    av_rescale_q(...); // call imported API via PLT at 0x150b3c
    return a0;
    return a0;
    pthread_self(...); // call imported API via PLT at 0x150b84
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8bda8 = "[%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> allocAVFrame failed"; // string xref
    const char* s_783d1 = "_dumpCacheFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x150bb0
    pthread_self(...); // call imported API via PLT at 0x150bd4
    const char* s_8bdee = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectFormatContext(%p)](%ld):> allocAVFrame failed
"; // string xref
    const char* s_783d1 = "_dumpCacheFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x150bfc
    return a0;
}
