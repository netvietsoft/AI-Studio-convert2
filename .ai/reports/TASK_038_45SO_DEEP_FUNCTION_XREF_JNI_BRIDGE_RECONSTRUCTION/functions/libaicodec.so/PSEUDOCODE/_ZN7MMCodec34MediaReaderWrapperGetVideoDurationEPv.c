// Function: MMCodec::MediaReaderWrapperGetVideoDuration(void*)
// RVA: 0x18dc34, Size: 180 bytes
int64_t _ZN7MMCodec34MediaReaderWrapperGetVideoDurationEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...); // call imported API via PLT at 0x18dc40
    const char* s_777c6 = "MediaReaderWrapperGetVideoDuration"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x18dc8c
    const char* s_777c6 = "MediaReaderWrapperGetVideoDuration"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x18dcd0
    return a0;
    return a0;
}
