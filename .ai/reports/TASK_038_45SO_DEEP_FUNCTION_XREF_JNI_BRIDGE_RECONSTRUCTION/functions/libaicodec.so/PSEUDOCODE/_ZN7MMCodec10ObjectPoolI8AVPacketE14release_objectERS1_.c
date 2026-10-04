// Function: MMCodec::ObjectPool<AVPacket>::release_object(AVPacket&)
// RVA: 0x123858, Size: 364 bytes
int64_t _ZN7MMCodec10ObjectPoolI8AVPacketE14release_objectERS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x123870
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68a05 = "[%s(%d)]:> %p isn't in pool, maybe leak !!!!!!"; // string xref
    const char* s_88be7 = "release_object"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1238d8
    const char* s_7f218 = "%s/MTMV_AICodec: [%s(%d)]:> %p isn't in pool, maybe leak !!!!!!
"; // string xref
    const char* s_88be7 = "release_object"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x123918
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123928
    sub_1255D8(...); // call internal func at 0x123960
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123998
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1239a4
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1239b8
}
