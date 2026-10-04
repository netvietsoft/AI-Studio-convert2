// Function: MMCodec::MediaReaderWrapperCleanup(void*)
// RVA: 0x190a28, Size: 172 bytes
int64_t _ZN7MMCodec25MediaReaderWrapperCleanupEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader7cleanupEv(...); // call imported API via PLT at 0x190a34
    return a0;
    const char* s_7e836 = "MediaReaderWrapperCleanup"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190a84
    const char* s_7e836 = "MediaReaderWrapperCleanup"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190ac4
    return a0;
}
