// Function: MMCodec::InMediaHandle::isInSameVideoGOP(long, long)
// RVA: 0x14422c, Size: 352 bytes
int64_t _ZN7MMCodec13InMediaHandle16isInSameVideoGOPEll(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_get_time_base_q(...); // call imported API via PLT at 0x144264
    av_rescale_q(...); // call imported API via PLT at 0x144274
    av_get_time_base_q(...); // call imported API via PLT at 0x14427c
    av_rescale_q(...); // call imported API via PLT at 0x14428c
    _ZN7MMCodec18MediaHandleContext11isInSameGOPElli(...); // call imported API via PLT at 0x1442b0
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1442fc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_90246 = "[%s(%d)]:> [InMediaHandle(%p)](%ld):> no open"; // string xref
    const char* s_767d6 = "isInSameVideoGOP"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x144328
    pthread_self(...); // call imported API via PLT at 0x14434c
    const char* s_8a658 = "%s/MTMV_AICodec: [%s(%d)]:> [InMediaHandle(%p)](%ld):> no open
"; // string xref
    const char* s_767d6 = "isInSameVideoGOP"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x144374
    return a0;
}
