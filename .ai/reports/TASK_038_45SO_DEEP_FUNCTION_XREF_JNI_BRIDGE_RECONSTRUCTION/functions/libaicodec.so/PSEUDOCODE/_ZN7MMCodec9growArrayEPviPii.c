// Function: MMCodec::growArray(void*, int, int*, int)
// RVA: 0x163874, Size: 400 bytes
int64_t _ZN7MMCodec9growArrayEPviPii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_realloc_array(...); // call imported API via PLT at 0x1638b4
    memset(...); // call imported API via PLT at 0x1638e0
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6efa2 = "[%s(%d)]:> Array too big."; // string xref
    const char* s_83b96 = "growArray"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x163938
    const char* s_7863d = "%s/MTMV_AICodec: [%s(%d)]:> Array too big.
"; // string xref
    const char* s_83b96 = "growArray"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x163974
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8a8a0 = "[%s(%d)]:> Could not alloc buffer."; // string xref
    const char* s_83b96 = "growArray"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1639c8
    const char* s_6ff84 = "%s/MTMV_AICodec: [%s(%d)]:> Could not alloc buffer.
"; // string xref
    const char* s_83b96 = "growArray"; // string xref
}
