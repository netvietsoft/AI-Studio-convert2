// Function: MMCodec::MediaReaderWrapperGetSampleFormat(void*)
// RVA: 0x18ef44, Size: 364 bytes
int64_t _ZN7MMCodec33MediaReaderWrapperGetSampleFormatEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...); // call imported API via PLT at 0x18ef5c
    _Znwm(...); // call imported API via PLT at 0x18efb8
    return a0;
    const char* s_6defb = "MediaReaderWrapperGetSampleFormat"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18f054
    const char* s_6defb = "MediaReaderWrapperGetSampleFormat"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18f094
    return a0;
}
