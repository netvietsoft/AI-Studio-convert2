// Function: MMCodec::MediaReaderWrapperGetMediaMuxer(void*)
// RVA: 0x18dad0, Size: 176 bytes
int64_t _ZN7MMCodec31MediaReaderWrapperGetMediaMuxerEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...); // call imported API via PLT at 0x18dadc
    return a0;
    const char* s_91af0 = "MediaReaderWrapperGetMediaMuxer"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18db2c
    const char* s_91af0 = "MediaReaderWrapperGetMediaMuxer"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18db6c
    void* g_6fc01 = (void*)0x6fc01; // global ref
    return a0;
}
