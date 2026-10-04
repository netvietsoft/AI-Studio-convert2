// Function: MMCodec::PacketQueue::put(AVPacket*, bool, bool, int)
// RVA: 0x1587f8, Size: 820 bytes
int64_t _ZN7MMCodec11PacketQueue3putEP8AVPacketbbi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x15883c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158848
    _ZN7MMCodec14AICodecContext15acquireAVPacketEv(...); // call imported API via PLT at 0x158850
    _Znwm(...); // call imported API via PLT at 0x15888c
    void* g_2006f8 = (void*)0x2006f8; // global ref
    _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE9force_putERKS2_(...); // call imported API via PLT at 0x1588d8
    pthread_self(...); // call imported API via PLT at 0x158900
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8be91 = "[%s(%d)]:> [PacketQueue(%p)](%ld):> input pkt is null"; // string xref
    const char* s_7e534 = "put"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x15892c
    pthread_self(...); // call imported API via PLT at 0x158950
    const char* s_7bf7b = "%s/MTMV_AICodec: [%s(%d)]:> [PacketQueue(%p)](%ld):> input pkt is null
"; // string xref
    const char* s_7e534 = "put"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x158978
    pthread_self(...); // call imported API via PLT at 0x1589a4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_690e3 = "[%s(%d)]:> [PacketQueue(%p)](%ld):> acquireAVPacket is null"; // string xref
    const char* s_7e534 = "put"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1589d0
    pthread_self(...); // call imported API via PLT at 0x1589f4
    const char* s_8f076 = "%s/MTMV_AICodec: [%s(%d)]:> [PacketQueue(%p)](%ld):> acquireAVPacket is null
"; // string xref
    const char* s_7e534 = "put"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x158a1c
    _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE3putERKS2_(...); // call imported API via PLT at 0x158a30
    (*x8)(...); // indirect call at 0x158a5c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x158a64
    (*x8)(...); // indirect call at 0x158a8c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x158a94
    return a0;
    _ZN7MMCodec11PacketQueue8MMPacketD2Ev(...); // call imported API via PLT at 0x158ad0
    sub_DC738(...); // call internal func at 0x158ad8
    __cxa_begin_catch(...); // call imported API via PLT at 0x158ae0
    _ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket(...); // call imported API via PLT at 0x158aec
    __cxa_rethrow(...); // call imported API via PLT at 0x158b00
    __cxa_end_catch(...); // call imported API via PLT at 0x158b08
    __stack_chk_fail(...); // call imported API via PLT at 0x158b24
    sub_CEBC4(...); // call internal func at 0x158b28
}
