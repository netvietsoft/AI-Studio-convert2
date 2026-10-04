// Function: MMCodec::StreamBase::findBestFrame(long, int, MMCodec::MMCodecFrame*&)
// RVA: 0x151d78, Size: 2436 bytes
int64_t _ZN7MMCodec10StreamBase13findBestFrameEliRPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x151dbc
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x151dec
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x151df8
    gettimeofday(...); // call imported API via PLT at 0x151e14
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x151e24
    gettimeofday(...); // call imported API via PLT at 0x151e3c
    _ZN7MMCodec11PacketQueue6serialEv(...); // call imported API via PLT at 0x151e88
    _ZN7MMCodec10FrameQueue11nbRemainingEv(...); // call imported API via PLT at 0x151ea4
    _ZN7MMCodec12findFramePtsEPNS_18MediaHandleContextEl(...); // call imported API via PLT at 0x151ebc
    _ZN7MMCodec10FrameQueue12peekReadableEii(...); // call imported API via PLT at 0x151f20
    _Znwm(...); // call imported API via PLT at 0x151fac
    _ZdlPv(...); // call imported API via PLT at 0x152038
    (*x8)(...); // indirect call at 0x152130
    (*x8)(...); // indirect call at 0x1521e0
    _ZdlPv(...); // call imported API via PLT at 0x1521ec
    pthread_self(...); // call imported API via PLT at 0x152218
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8674a = "[%s(%d)]:> [StreamBase(%p)](%ld):> try again get frame %lld, timeout:%d"; // string xref
    const char* s_6ed36 = "findBestFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15224c
    pthread_self(...); // call imported API via PLT at 0x152270
    const char* s_8918c = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> try again get frame %lld, timeout:%d
"; // string xref
    const char* s_6ed36 = "findBestFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1522a0
    (*x8)(...); // indirect call at 0x15231c
    (*x8)(...); // indirect call at 0x15233c
    pthread_self(...); // call imported API via PLT at 0x15235c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89161 = "[%s(%d)]:> [StreamBase(%p)](%ld):> no init"; // string xref
    const char* s_6ed36 = "findBestFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x152388
    pthread_self(...); // call imported API via PLT at 0x1523ac
    const char* s_87a0d = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> no init
"; // string xref
    const char* s_6ed36 = "findBestFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1523d4
    (*x8)(...); // indirect call at 0x152400
    (*x8)(...); // indirect call at 0x15243c
    _ZdlPv(...); // call imported API via PLT at 0x152464
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1524a0
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x15250c
    _ZN7MMCodec18MediaHandleContext14getPacketQueueEi(...); // call imported API via PLT at 0x152528
    _ZN7MMCodec10FrameQueue10getEofFlagEv(...); // call imported API via PLT at 0x152534
    _ZN7MMCodec11PacketQueue5isEofEv(...); // call imported API via PLT at 0x15254c
    pthread_self(...); // call imported API via PLT at 0x1525b8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67f4f = "[%s(%d)]:> [StreamBase(%p)](%ld):> can't get frame %lld!"; // string xref
    const char* s_6ed36 = "findBestFrame"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1525e8
    pthread_self(...); // call imported API via PLT at 0x15260c
    const char* s_8be46 = "%s/MTMV_AICodec: [%s(%d)]:> [StreamBase(%p)](%ld):> can't get frame %lld!
"; // string xref
    const char* s_6ed36 = "findBestFrame"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x152638
    sub_123F28(...); // call internal func at 0x15265c
    sub_D206C(...); // call internal func at 0x152674
    _ZdlPv(...); // call imported API via PLT at 0x1526d0
    void* g_2010b0 = (void*)0x2010b0; // global ref
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1526d8
    __stack_chk_fail(...); // call imported API via PLT at 0x1526f8
}
