// Function: MMCodec::MediaReaderWrapperGetAudioFrame(void*, unsigned char**, void*)
// RVA: 0x1911ec, Size: 256 bytes
int64_t _ZN7MMCodec31MediaReaderWrapperGetAudioFrameEPvPPhS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader13getAudioFrameENS_10ReadOptionERPhRNS_9FrameInfoE(...); // call imported API via PLT at 0x191238
    const char* s_6df61 = "MediaReaderWrapperGetAudioFrame"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x191280
    const char* s_6df61 = "MediaReaderWrapperGetAudioFrame"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1912c0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1912e8
}
