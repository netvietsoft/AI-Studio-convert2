// Function: MMCodec::AndroidVideoStream::flush()
// RVA: 0xf8ff0, Size: 236 bytes
int64_t _ZN7MMCodec18AndroidVideoStream5flushEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xf9010
    pthread_self(...); // call imported API via PLT at 0xf9038
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_808b9 = "[%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidVideoStream flush encoder failed"; // string xref
    const char* s_881e0 = "flush"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf9064
    pthread_self(...); // call imported API via PLT at 0xf9088
    const char* s_81d2d = "%s/MTMV_AICodec: [%s(%d)]:> [AndroidVideoStream(%p)](%ld):> AndroidVideoStream flush encoder failed
"; // string xref
    const char* s_881e0 = "flush"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf90b0
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xf90b8
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0xf90c8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xf90d8
}
