// Function: MMCodec::InMediaHandle::nextInvalid(int)
// RVA: 0x1434e4, Size: 444 bytes
int64_t _ZN7MMCodec13InMediaHandle11nextInvalidEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x143550
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_71d16 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]"; // string xref
    const char* s_6d998 = "nextInvalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x143580
    pthread_self(...); // call imported API via PLT at 0x1435a4
    const char* s_8776a = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Cannot find this stream [index=%d]
"; // string xref
    const char* s_6d998 = "nextInvalid"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1435d0
    return a0;
    pthread_self(...); // call imported API via PLT at 0x143608
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d94b = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream %d is null, no data have found!"; // string xref
    const char* s_6d998 = "nextInvalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x143638
    pthread_self(...); // call imported API via PLT at 0x14365c
    const char* s_84a15 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> Stream %d is null, no data have found!
"; // string xref
    const char* s_6d998 = "nextInvalid"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x143688
    return a0;
}
