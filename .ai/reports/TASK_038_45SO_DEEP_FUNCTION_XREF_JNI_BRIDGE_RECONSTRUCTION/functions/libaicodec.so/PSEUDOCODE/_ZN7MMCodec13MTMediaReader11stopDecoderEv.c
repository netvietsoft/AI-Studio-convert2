// Function: MMCodec::MTMediaReader::stopDecoder()
// RVA: 0x12fe54, Size: 600 bytes
int64_t _ZN7MMCodec13MTMediaReader11stopDecoderEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x12fe8c
    pthread_self(...); // call imported API via PLT at 0x12fec0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_793eb = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> stopping.. "; // string xref
    const char* s_7a989 = "stopDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12feec
    pthread_self(...); // call imported API via PLT at 0x12ff10
    const char* s_67cb9 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> stopping.. 
"; // string xref
    const char* s_7a989 = "stopDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x12ff38
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x12ff4c
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x12ff68
    _ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x12ff74
    _ZN7MMCodec23AICodecSampleBufferPool31purgeCodecDataBeforeTearingDownEv(...); // call imported API via PLT at 0x12ff80
    _ZN7MMCodec23AICodecSampleBufferPool31purgeCodecDataBeforeTearingDownEv(...); // call imported API via PLT at 0x12ff8c
    (*x8)(...); // indirect call at 0x12ff9c
    pthread_self(...); // call imported API via PLT at 0x12ffb8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d41b = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> stopped with AICodecContext %p"; // string xref
    const char* s_7a989 = "stopDecoder"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x12ffe8
    pthread_self(...); // call imported API via PLT at 0x130004
    const char* s_91443 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> stopped with AICodecContext %p
"; // string xref
    const char* s_7a989 = "stopDecoder"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x130030
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x13003c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x130050
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x13008c
    __stack_chk_fail(...); // call imported API via PLT at 0x1300a8
}
