// Function: MMCodec::InMediaHandle::resume()
// RVA: 0x1437fc, Size: 348 bytes
int64_t _ZN7MMCodec13InMediaHandle6resumeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext12statCallbackEii(...); // call imported API via PLT at 0x14382c
    const char* s_88f22 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream index=%d needn't deal
"; // string xref
    const char* s_68da6 = "resume"; // string xref
    const char* s_6ea7a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream index=%d needn't deal

"; // string xref
    pthread_self(...); // call imported API via PLT at 0x1438b8
    const char* s_7d752 = "MTMV_AICodec";
    __android_log_print(...); // call imported API via PLT at 0x1438e0
    pthread_self(...); // call imported API via PLT at 0x1438f4
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x143918
    (*x8)(...); // indirect call at 0x143934
    return a0;
}
