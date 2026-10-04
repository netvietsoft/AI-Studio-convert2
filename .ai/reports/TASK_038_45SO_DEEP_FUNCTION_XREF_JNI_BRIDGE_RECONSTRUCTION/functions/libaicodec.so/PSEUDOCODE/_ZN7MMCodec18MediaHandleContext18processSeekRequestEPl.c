// Function: MMCodec::MediaHandleContext::processSeekRequest(long*)
// RVA: 0x146d08, Size: 2024 bytes
int64_t _ZN7MMCodec18MediaHandleContext18processSeekRequestEPl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x146d2c
    av_get_time_base_q(...); // call imported API via PLT at 0x146d50
    av_rescale_q(...); // call imported API via PLT at 0x146d70
    _ZN7MMCodec11PacketQueue7isFlushEv(...); // call imported API via PLT at 0x146d98
    pthread_self(...); // call imported API via PLT at 0x146dc0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8a6ad = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> Video seek mode:%d, seek time:%lld"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x146df8
    pthread_self(...); // call imported API via PLT at 0x146e1c
    const char* s_902f8 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> Video seek mode:%d, seek time:%lld
"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x146e50
    (*x8)(...); // indirect call at 0x146e70
    av_get_time_base_q(...); // call imported API via PLT at 0x146ea0
    av_rescale_q(...); // call imported API via PLT at 0x146ec0
    pthread_self(...); // call imported API via PLT at 0x146ee8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_73238 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> Audio seek mode:%d, seek time:%lld"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x146f20
    pthread_self(...); // call imported API via PLT at 0x146f44
    const char* s_7ac23 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> Audio seek mode:%d, seek time:%lld
"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x146f78
    (*x8)(...); // indirect call at 0x146f98
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x146fb0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x146fd4
    _ZN7MMCodec11PacketQueue8tagFlushEv(...); // call imported API via PLT at 0x147020
    _ZN7MMCodec11PacketQueue5flushEv(...); // call imported API via PLT at 0x147028
    _ZN7MMCodec11PacketQueue6setEofEb(...); // call imported API via PLT at 0x147034
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x147040
    _ZN7MMCodec13AICodecGlobal11flushPacketEv(...); // call imported API via PLT at 0x147044
    _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(...); // call imported API via PLT at 0x14705c
    (*x8)(...); // indirect call at 0x147080
    pthread_self(...); // call imported API via PLT at 0x1470b0
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_75403 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> seek error! none streams, thread exit"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1470dc
    pthread_self(...); // call imported API via PLT at 0x147100
    const char* s_6c418 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> seek error! none streams, thread exit
"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x147128
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x147150
    pthread_self(...); // call imported API via PLT at 0x147158
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6d9a4 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> audio seekFrame error![%d:%s], thread exit"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x14718c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1471ac
    pthread_self(...); // call imported API via PLT at 0x1471b4
    const char* s_6a1f7 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> audio seekFrame error![%d:%s], thread exit
"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1471e4
    _ZN7MMCodec18MediaHandleContext15isWebpAnimationEv(...); // call imported API via PLT at 0x147224
    pthread_self(...); // call imported API via PLT at 0x14725c
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6eb46 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> Skip Video seek mode:%d, seek time:%lld"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x147294
    pthread_self(...); // call imported API via PLT at 0x1472b8
    const char* s_7e3eb = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> Skip Video seek mode:%d, seek time:%lld
"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1472ec
    _ZN7MMCodec13AICodecGlobal11getInstanceEv(...); // call imported API via PLT at 0x147344
    _ZN7MMCodec13AICodecGlobal10skipPacketEv(...); // call imported API via PLT at 0x147348
    _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(...); // call imported API via PLT at 0x147360
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x147384
    return a0;
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1473c0
    pthread_self(...); // call imported API via PLT at 0x1473c8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6b2d5 = "[%s(%d)]:> [MediaHandleContext(%p)](%ld):> video seekFrame error![%d:%s], thread exit"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1473fc
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x14741c
    pthread_self(...); // call imported API via PLT at 0x147424
    const char* s_916e4 = "%s/MTMV_AICodec: [%s(%d)]:> [MediaHandleContext(%p)](%ld):> video seekFrame error![%d:%s], thread exit
"; // string xref
    const char* s_6a1e4 = "processSeekRequest"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x147454
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x14746c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x147480
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x147494
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1474a8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1474bc
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1474d0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1474e4
}
