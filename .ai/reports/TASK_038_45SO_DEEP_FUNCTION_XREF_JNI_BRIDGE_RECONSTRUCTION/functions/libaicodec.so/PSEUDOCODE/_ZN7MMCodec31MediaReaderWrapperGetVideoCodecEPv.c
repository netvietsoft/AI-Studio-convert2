// Function: MMCodec::MediaReaderWrapperGetVideoCodec(void*)
// RVA: 0x18e718, Size: 176 bytes
int64_t _ZN7MMCodec31MediaReaderWrapperGetVideoCodecEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...); // call imported API via PLT at 0x18e724
    return a0;
    const char* s_6dedb = "MediaReaderWrapperGetVideoCodec"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18e774
    const char* s_6dedb = "MediaReaderWrapperGetVideoCodec"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18e7b4
    void* g_6fc01 = (void*)0x6fc01; // global ref
    return a0;
}
