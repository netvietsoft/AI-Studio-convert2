// Function: MMCodec::ObjectPool<AVFrame>::release_object(AVFrame&)
// RVA: 0x123518, Size: 364 bytes
int64_t _ZN7MMCodec10ObjectPoolI7AVFrameE14release_objectERS1_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x123530
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_68a05 = "[%s(%d)]:> %p isn't in pool, maybe leak !!!!!!"; // string xref
    const char* s_88be7 = "release_object"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x123598
    const char* s_7f218 = "%s/MTMV_AICodec: [%s(%d)]:> %p isn't in pool, maybe leak !!!!!!
"; // string xref
    const char* s_88be7 = "release_object"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1235d8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1235e8
    sub_124AA0(...); // call internal func at 0x123620
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123658
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123664
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123678
}
