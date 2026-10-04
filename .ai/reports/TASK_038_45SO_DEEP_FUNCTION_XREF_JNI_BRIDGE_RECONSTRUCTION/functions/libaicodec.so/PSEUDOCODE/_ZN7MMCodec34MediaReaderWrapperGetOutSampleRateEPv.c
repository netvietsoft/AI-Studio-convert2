// Function: MMCodec::MediaReaderWrapperGetOutSampleRate(void*)
// RVA: 0x18f4e8, Size: 192 bytes
int64_t _ZN7MMCodec34MediaReaderWrapperGetOutSampleRateEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader21getOutAudioSampleRateEv(...); // call imported API via PLT at 0x18f4ec
    return a0;
    const char* s_908b9 = "MediaReaderWrapperGetOutSampleRate"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18f558
    const char* s_908b9 = "MediaReaderWrapperGetOutSampleRate"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18f598
    return a0;
}
