// Function: MMCodec::StreamBase::seek(long, MMCodec::SeekMode_t)
// RVA: 0x151440, Size: 624 bytes
int64_t _ZN7MMCodec10StreamBase4seekElNS_10SeekMode_tE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x1514b8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8da70 = "[%s(%d)]:> [StreamBase(%p)](%ld):> hold MediaHandleContext %p: seek to %lld, mode %d"; // string xref
    const char* s_8387e = "seek"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1514f0
    pthread_self(...); // call imported API via PLT at 0x151514
    const char* s_69038 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> hold MediaHandleContext %p: seek to %lld, mode %d
"; // string xref
    const char* s_8387e = "seek"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x151548
    pthread_self(...); // call imported API via PLT at 0x151584
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_827d1 = "[%s(%d)]:> [StreamBase(%p)](%ld):> unknown seek direction"; // string xref
    const char* s_8387e = "seek"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1515b0
    pthread_self(...); // call imported API via PLT at 0x1515cc
    const char* s_71fc7 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> unknown seek direction
"; // string xref
    const char* s_8387e = "seek"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1515f4
    (*x8)(...); // indirect call at 0x151614
    (*x8)(...); // indirect call at 0x151628
    _ZN7MMCodec10FrameQueue10setEofFlagEb(...); // call imported API via PLT at 0x151658
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x151660
    (*x8)(...); // indirect call at 0x151678
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1516ac
}
