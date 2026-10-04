// Function: MMCodec::StreamBase::findNextFrame(int, MMCodec::MMCodecFrame*&)
// RVA: 0x152718, Size: 916 bytes
int64_t _ZN7MMCodec10StreamBase13findNextFrameEiRPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x152750
    (*x8)(...); // indirect call at 0x152774
    (*x8)(...); // indirect call at 0x152798
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x1527a4
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x1527b0
    gettimeofday(...); // call imported API via PLT at 0x1527cc
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x1527dc
    gettimeofday(...); // call imported API via PLT at 0x1527f4
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x152838
    (*x8)(...); // indirect call at 0x1528ec
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x152900
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x15290c
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x152924
    pthread_self(...); // call imported API via PLT at 0x152970
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89161 = "[%s(%d)]:> [StreamBase(%p)](%ld):> no init"; // string xref
    const char* s_6b51c = "findNextFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15299c
    pthread_self(...); // call imported API via PLT at 0x1529c0
    const char* s_87a0d = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> no init
"; // string xref
    const char* s_6b51c = "findNextFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1529e8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x152a50
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x152a9c
    __stack_chk_fail(...); // call imported API via PLT at 0x152aa8
}
