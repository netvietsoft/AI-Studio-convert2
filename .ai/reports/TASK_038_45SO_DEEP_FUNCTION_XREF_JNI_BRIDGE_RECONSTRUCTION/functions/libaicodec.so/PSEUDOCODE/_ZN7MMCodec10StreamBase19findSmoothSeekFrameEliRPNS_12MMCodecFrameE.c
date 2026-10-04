// Function: MMCodec::StreamBase::findSmoothSeekFrame(long, int, MMCodec::MMCodecFrame*&)
// RVA: 0x152aac, Size: 960 bytes
int64_t _ZN7MMCodec10StreamBase19findSmoothSeekFrameEliRPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x152ae0
    (*x8)(...); // indirect call at 0x152b04
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x152b0c
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x152b18
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x152b30
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x152b50
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x152b78
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x152b90
    (*x8)(...); // indirect call at 0x152bb4
    (*x8)(...); // indirect call at 0x152bf0
    pthread_self(...); // call imported API via PLT at 0x152c18
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89161 = "[%s(%d)]:> [StreamBase(%p)](%ld):> no init"; // string xref
    const char* s_7ae5e = "findSmoothSeekFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x152c44
    pthread_self(...); // call imported API via PLT at 0x152c68
    const char* s_87a0d = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> no init
"; // string xref
    const char* s_7ae5e = "findSmoothSeekFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x152c90
    pthread_self(...); // call imported API via PLT at 0x152cbc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8280b = "[%s(%d)]:> [StreamBase(%p)](%ld):> can't get %lld frame, direction:%lld!"; // string xref
    const char* s_7ae5e = "findSmoothSeekFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x152cf4
    pthread_self(...); // call imported API via PLT at 0x152d18
    const char* s_891e6 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> can't get %lld frame, direction:%lld!
"; // string xref
    const char* s_7ae5e = "findSmoothSeekFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x152d4c
    (*x8)(...); // indirect call at 0x152d8c
    (*x8)(...); // indirect call at 0x152dd8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x152de0
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x152e4c
    __stack_chk_fail(...); // call imported API via PLT at 0x152e68
}
