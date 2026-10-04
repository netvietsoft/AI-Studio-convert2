// Function: MMCodec::initOutputFrame(AVFrame**, MMCodec::AudioParam_t*, int)
// RVA: 0xec2c0, Size: 648 bytes
int64_t _ZN7MMCodec15initOutputFrameEPP7AVFramePNS_12AudioParam_tEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_alloc(...); // call imported API via PLT at 0xec2e8
    av_channel_layout_default(...); // call imported API via PLT at 0xec30c
    av_frame_get_buffer(...); // call imported API via PLT at 0xec320
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a2d8 = "[%s(%d)]:> Parmater err!
"; // string xref
    const char* s_7b4e0 = "initOutputFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xec378
    const char* s_7b4f0 = "%s/MTMV_AICodec: [%s(%d)]:> Parmater err!

"; // string xref
    const char* s_7b4e0 = "initOutputFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xec3b4
    return a0;
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xec3f0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b51c = "[%s(%d)]:> Get frame buffer error![%s]
"; // string xref
    const char* s_7b4e0 = "initOutputFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xec418
    return a0;
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xec468
    const char* s_81b31 = "%s/MTMV_AICodec: [%s(%d)]:> Get frame buffer error![%s]

"; // string xref
    const char* s_7b4e0 = "initOutputFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xec48c
    return a0;
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_75e94 = "[%s(%d)]:> Malloc frame err!
"; // string xref
    const char* s_7b4e0 = "initOutputFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xec4f4
    const char* s_8f870 = "%s/MTMV_AICodec: [%s(%d)]:> Malloc frame err!

"; // string xref
    const char* s_7b4e0 = "initOutputFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xec530
    return a0;
}
