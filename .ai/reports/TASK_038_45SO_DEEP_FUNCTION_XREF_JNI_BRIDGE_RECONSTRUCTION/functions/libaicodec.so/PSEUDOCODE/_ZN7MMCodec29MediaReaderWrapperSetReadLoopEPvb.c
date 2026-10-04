// Function: MMCodec::MediaReaderWrapperSetReadLoop(void*, bool)
// RVA: 0x191fa4, Size: 176 bytes
int64_t _ZN7MMCodec29MediaReaderWrapperSetReadLoopEPvb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader11setReadLoopEb(...); // call imported API via PLT at 0x191fb4
    return a0;
    const char* s_7e892 = "MediaReaderWrapperSetReadLoop"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x192004
    const char* s_7e892 = "MediaReaderWrapperSetReadLoop"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x192044
    return a0;
}
