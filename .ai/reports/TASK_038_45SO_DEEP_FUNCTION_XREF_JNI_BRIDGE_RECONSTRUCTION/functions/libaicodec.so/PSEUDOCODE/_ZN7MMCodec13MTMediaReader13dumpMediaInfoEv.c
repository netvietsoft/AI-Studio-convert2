// Function: MMCodec::MTMediaReader::dumpMediaInfo()
// RVA: 0x130f28, Size: 640 bytes
int64_t _ZN7MMCodec13MTMediaReader13dumpMediaInfoEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x130f64
    const char* s_835ef = "dumpMediaInfo"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72f6b = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> 
File: %s(%p %zu)
duration: %f ms
muxer: %s
stream number: %d
is picture: %d
video index: "; // string xref
    __android_log_print(...); // call imported API via PLT at 0x13105c
    pthread_self(...); // call imported API via PLT at 0x131080
    return a0;
    const char* s_835ef = "dumpMediaInfo"; // string xref
    const char* s_69e59 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> 
File: %s(%p %zu)
duration: %f ms
muxer: %s
stream number: %d
is picture:"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x13118c
    return a0;
}
