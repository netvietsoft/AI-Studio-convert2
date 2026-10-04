// Function: MMCodec::MediaReaderWrapperSeekTo(void*, long, int)
// RVA: 0x190cc0, Size: 172 bytes
int64_t _ZN7MMCodec24MediaReaderWrapperSeekToEPvli(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader9seekTo_V2Eli(...); // call imported API via PLT at 0x190ccc
    return a0;
    const char* s_7e850 = "MediaReaderWrapperSeekTo"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190d1c
    const char* s_7e850 = "MediaReaderWrapperSeekTo"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190d5c
    return a0;
}
