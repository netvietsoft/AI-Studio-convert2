// Function: MMCodec::PacketQueue::get(AVPacket*, bool, MMCodec::PacketQueue::PacketInfo&)
// RVA: 0x158e9c, Size: 512 bytes
int64_t _ZN7MMCodec11PacketQueue3getEP8AVPacketbRNS0_10PacketInfoE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x158ed4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158ee0
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x158eec
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x158f00
    _ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE4takeERS2_i(...); // call imported API via PLT at 0x158f2c
    av_packet_move_ref(...); // call imported API via PLT at 0x158f3c
    pthread_self(...); // call imported API via PLT at 0x158f80
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_784cd = "[%s(%d)]:> [PacketQueue(%p)](%ld):> Queue take failed"; // string xref
    const char* s_756a2 = "get"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x158fac
    pthread_self(...); // call imported API via PLT at 0x158fd0
    const char* s_7e53e = "%s/MTMV_AICodec: [%s(%d)]:> [PacketQueue(%p)](%ld):> Queue take failed
"; // string xref
    const char* s_756a2 = "get"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x158ff8
    (*x8)(...); // indirect call at 0x159024
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x15902c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x159044
    return a0;
    _ZN7MMCodec11PacketQueue8MMPacketD2Ev(...); // call imported API via PLT at 0x15907c
    __stack_chk_fail(...); // call imported API via PLT at 0x159098
}
