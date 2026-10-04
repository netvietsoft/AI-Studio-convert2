// Function: MMCodec::MTMediaReader::releaseSampleBuffer(MMCodec::AICodecSampleBuffer*&)
// RVA: 0x13331c, Size: 328 bytes
int64_t _ZN7MMCodec13MTMediaReader19releaseSampleBufferERPNS_19AICodecSampleBufferE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x133338
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x133354
    pthread_self(...); // call imported API via PLT at 0x133380
    const char* s_73108 = "start decoder"; // string xref
    const char* s_6ba3e = "open"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86305 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't %s"; // string xref
    const char* s_86336 = "releaseSampleBuffer"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1333c4
    pthread_self(...); // call imported API via PLT at 0x1333e8
    const char* s_73108 = "start decoder"; // string xref
    const char* s_6ba3e = "open"; // string xref
    const char* s_8d460 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):>  didn't %s
"; // string xref
    const char* s_86336 = "releaseSampleBuffer"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13342c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x133438
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x133458
}
