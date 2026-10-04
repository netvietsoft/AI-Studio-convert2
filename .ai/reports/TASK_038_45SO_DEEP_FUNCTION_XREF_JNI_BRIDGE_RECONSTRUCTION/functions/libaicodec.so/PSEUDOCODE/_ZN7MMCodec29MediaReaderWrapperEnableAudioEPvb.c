// Function: MMCodec::MediaReaderWrapperEnableAudio(void*, bool)
// RVA: 0x1912ec, Size: 176 bytes
int64_t _ZN7MMCodec29MediaReaderWrapperEnableAudioEPvb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader14setEnableAudioEb(...); // call imported API via PLT at 0x1912fc
    return a0;
    const char* s_880e8 = "MediaReaderWrapperEnableAudio"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x19134c
    const char* s_880e8 = "MediaReaderWrapperEnableAudio"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x19138c
    return a0;
}
