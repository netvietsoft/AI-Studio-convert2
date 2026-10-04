// Function: MMCodec::MediaReaderWrapperClose(void*)
// RVA: 0x190824, Size: 172 bytes
int64_t _ZN7MMCodec23MediaReaderWrapperCloseEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader5closeEv(...); // call imported API via PLT at 0x190830
    return a0;
    const char* s_6df49 = "MediaReaderWrapperClose"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190880
    const char* s_6df49 = "MediaReaderWrapperClose"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1908c0
    return a0;
}
