// Function: MMCodec::PacketQueue::tagFlush()
// RVA: 0x159334, Size: 260 bytes
int64_t _ZN7MMCodec11PacketQueue8tagFlushEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x159348
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x159350
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x159360
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x159368
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x15937c
    pthread_self(...); // call imported API via PLT at 0x1593a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7344d = "[%s(%d)]:> [PacketQueue(%p)](%ld):> %d"; // string xref
    const char* s_78503 = "tagFlush"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1593d0
    pthread_self(...); // call imported API via PLT at 0x1593f4
    const char* s_6b5cb = "%s/MTMV_AICodec: [%s(%d)]:> [PacketQueue(%p)](%ld):> %d
"; // string xref
    const char* s_78503 = "tagFlush"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x159428
    return a0;
}
