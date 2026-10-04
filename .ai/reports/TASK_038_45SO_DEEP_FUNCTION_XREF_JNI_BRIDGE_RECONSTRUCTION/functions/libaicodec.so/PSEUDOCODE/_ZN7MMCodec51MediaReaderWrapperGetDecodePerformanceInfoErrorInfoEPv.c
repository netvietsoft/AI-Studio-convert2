// Function: MMCodec::MediaReaderWrapperGetDecodePerformanceInfoErrorInfo(void*)
// RVA: 0x193504, Size: 192 bytes
int64_t _ZN7MMCodec51MediaReaderWrapperGetDecodePerformanceInfoErrorInfoEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader18getPerformanceInfoEv(...); // call imported API via PLT at 0x193510
    return a0;
    const char* s_789bd = "MediaReaderWrapperGetDecodePerformanceInfoErrorInfo"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x193570
    const char* s_789bd = "MediaReaderWrapperGetDecodePerformanceInfoErrorInfo"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1935b0
    void* g_6fc01 = (void*)0x6fc01; // global ref
    return a0;
}
