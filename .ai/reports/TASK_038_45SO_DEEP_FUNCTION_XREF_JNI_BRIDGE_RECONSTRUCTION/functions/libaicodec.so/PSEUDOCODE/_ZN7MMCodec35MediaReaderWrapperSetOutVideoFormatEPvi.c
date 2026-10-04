// Function: MMCodec::MediaReaderWrapperSetOutVideoFormat(void*, int)
// RVA: 0x1923f0, Size: 372 bytes
int64_t _ZN7MMCodec35MediaReaderWrapperSetOutVideoFormatEPvi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x192460
    _ZN7MMCodec13MTMediaReader14setVideoFormatENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x1924ac
    return a0;
    const char* s_6942a = "MediaReaderWrapperSetOutVideoFormat"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x192508
    const char* s_6942a = "MediaReaderWrapperSetOutVideoFormat"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x192548
    return a0;
}
