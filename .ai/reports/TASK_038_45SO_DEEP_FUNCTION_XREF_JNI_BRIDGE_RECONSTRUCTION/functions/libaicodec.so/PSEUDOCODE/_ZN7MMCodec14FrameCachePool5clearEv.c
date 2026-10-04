// Function: MMCodec::FrameCachePool::clear()
// RVA: 0x155e38, Size: 444 bytes
int64_t _ZN7MMCodec14FrameCachePool5clearEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x155e60
    const char* s_7e538 = "clear"; // string xref
    const char* s_82854 = "%s/MTMV_AICodec: [%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed
"; // string xref
    (*x8)(...); // indirect call at 0x155ec4
    pthread_self(...); // call imported API via PLT at 0x155ee4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bf3a = "[%s(%d)]:> [FrameCachePool(%p)](%ld):> un ref frame %p:%p failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x155f18
    pthread_self(...); // call imported API via PLT at 0x155f2c
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x155f58
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x155fc4
    sub_D867C(...); // call internal func at 0x155fc8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x155fd4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x155fe8
}
