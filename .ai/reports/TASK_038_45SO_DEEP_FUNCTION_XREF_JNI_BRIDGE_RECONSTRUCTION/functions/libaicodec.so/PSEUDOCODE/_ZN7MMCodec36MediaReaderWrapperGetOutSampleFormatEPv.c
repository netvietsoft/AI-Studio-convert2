// Function: MMCodec::MediaReaderWrapperGetOutSampleFormat(void*)
// RVA: 0x18f37c, Size: 364 bytes
int64_t _ZN7MMCodec36MediaReaderWrapperGetOutSampleFormatEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader17getOutAudioFormatEv(...); // call imported API via PLT at 0x18f394
    _Znwm(...); // call imported API via PLT at 0x18f3f0
    return a0;
    const char* s_89a86 = "MediaReaderWrapperGetOutSampleFormat"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18f48c
    const char* s_89a86 = "MediaReaderWrapperGetOutSampleFormat"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18f4cc
    return a0;
}
