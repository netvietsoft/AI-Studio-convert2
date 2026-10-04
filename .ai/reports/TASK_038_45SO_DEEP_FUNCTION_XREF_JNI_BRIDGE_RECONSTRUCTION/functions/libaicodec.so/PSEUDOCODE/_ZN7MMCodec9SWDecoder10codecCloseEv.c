// Function: MMCodec::SWDecoder::codecClose()
// RVA: 0x147ed0, Size: 312 bytes
int64_t _ZN7MMCodec9SWDecoder10codecCloseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avcodec_close(...); // call imported API via PLT at 0x147ef8
    pthread_self(...); // call imported API via PLT at 0x147f24
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x147f34
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8122f = "[%s(%d)]:> [SWDecoder(%p)](%ld):> Close codec error, stream Index=[%d] %s"; // string xref
    const char* s_8f8d8 = "codecClose"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x147f6c
    pthread_self(...); // call imported API via PLT at 0x147f90
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x147fa0
    const char* s_88fc4 = "%s/MTMV_AICodec: [%s(%d)]:> [SWDecoder(%p)](%ld):> Close codec error, stream Index=[%d] %s
"; // string xref
    const char* s_8f8d8 = "codecClose"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x147fd4
    avcodec_free_context(...); // call imported API via PLT at 0x147fdc
    return a0;
}
