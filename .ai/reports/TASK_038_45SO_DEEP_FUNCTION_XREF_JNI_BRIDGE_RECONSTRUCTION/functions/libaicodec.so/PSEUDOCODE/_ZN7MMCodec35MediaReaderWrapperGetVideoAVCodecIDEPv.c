// Function: MMCodec::MediaReaderWrapperGetVideoAVCodecID(void*)
// RVA: 0x18e66c, Size: 172 bytes
int64_t _ZN7MMCodec35MediaReaderWrapperGetVideoAVCodecIDEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...); // call imported API via PLT at 0x18e678
    return a0;
    const char* s_91b10 = "MediaReaderWrapperGetVideoAVCodecID"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18e6c8
    const char* s_91b10 = "MediaReaderWrapperGetVideoAVCodecID"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18e708
    return a0;
}
