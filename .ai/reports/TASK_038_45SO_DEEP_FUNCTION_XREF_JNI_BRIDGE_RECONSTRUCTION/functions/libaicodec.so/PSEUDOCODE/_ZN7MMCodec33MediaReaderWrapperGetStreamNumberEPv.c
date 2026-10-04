// Function: MMCodec::MediaReaderWrapperGetStreamNumber(void*)
// RVA: 0x18d970, Size: 172 bytes
int64_t _ZN7MMCodec33MediaReaderWrapperGetStreamNumberEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...); // call imported API via PLT at 0x18d97c
    return a0;
    const char* s_777a4 = "MediaReaderWrapperGetStreamNumber"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18d9cc
    const char* s_777a4 = "MediaReaderWrapperGetStreamNumber"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18da0c
    return a0;
}
