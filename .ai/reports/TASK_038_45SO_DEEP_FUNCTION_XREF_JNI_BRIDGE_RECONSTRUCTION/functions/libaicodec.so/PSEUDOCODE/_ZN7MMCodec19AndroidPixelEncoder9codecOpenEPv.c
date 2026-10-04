// Function: MMCodec::AndroidPixelEncoder::codecOpen(void*)
// RVA: 0xf6080, Size: 160 bytes
int64_t _ZN7MMCodec19AndroidPixelEncoder9codecOpenEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec14AndroidEncoder9codecOpenEPv(...); // call imported API via PLT at 0xf6088
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f91c = "[%s(%d)]:> %s java CodecOpen failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf60d0
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_6bb55 = "%s/MTMV_AICodec: [%s(%d)]:> %s java CodecOpen failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf6110
    return a0;
}
