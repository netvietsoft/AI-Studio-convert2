// Function: MMCodec::MediaReaderWrapperOpen(void*)
// RVA: 0x1906c0, Size: 180 bytes
int64_t _ZN7MMCodec22MediaReaderWrapperOpenEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader4openEPS0_(...); // call imported API via PLT at 0x1906d0
    return a0;
    const char* s_6a7a3 = "MediaReaderWrapperOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190724
    const char* s_6a7a3 = "MediaReaderWrapperOpen"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190764
    return a0;
}
