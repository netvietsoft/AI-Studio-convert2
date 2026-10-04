// Function: MMCodec::InMediaHandle::getOutVideoFormat(int)
// RVA: 0x14472c, Size: 260 bytes
int64_t _ZN7MMCodec13InMediaHandle17getOutVideoFormatEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x144798
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71d16 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]"; // string xref
    const char* s_753ec = "getOutVideoFormat"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1447c8
    pthread_self(...); // call imported API via PLT at 0x1447ec
    const char* s_8776a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_753ec = "getOutVideoFormat"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x144818
    return a0;
}
