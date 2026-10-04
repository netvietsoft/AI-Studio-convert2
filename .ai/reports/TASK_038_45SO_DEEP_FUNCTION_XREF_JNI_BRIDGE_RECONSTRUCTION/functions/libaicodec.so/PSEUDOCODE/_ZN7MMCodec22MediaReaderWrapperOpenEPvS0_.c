// Function: MMCodec::MediaReaderWrapperOpen(void*, void*)
// RVA: 0x190774, Size: 176 bytes
int64_t _ZN7MMCodec22MediaReaderWrapperOpenEPvS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader4openEPS0_(...); // call imported API via PLT at 0x190780
    return a0;
    const char* s_6a7a3 = "MediaReaderWrapperOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1907d4
    const char* s_6a7a3 = "MediaReaderWrapperOpen"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190814
    return a0;
}
