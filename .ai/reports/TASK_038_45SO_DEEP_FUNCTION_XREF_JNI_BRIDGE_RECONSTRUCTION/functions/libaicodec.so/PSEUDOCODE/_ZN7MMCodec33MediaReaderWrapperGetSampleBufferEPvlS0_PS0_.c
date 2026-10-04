// Function: MMCodec::MediaReaderWrapperGetSampleBuffer(void*, long, void*, void**)
// RVA: 0x190d6c, Size: 212 bytes
int64_t _ZN7MMCodec33MediaReaderWrapperGetSampleBufferEPvlS0_PS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader15getSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE(...); // call imported API via PLT at 0x190d84
    return a0;
    const char* s_90909 = "MediaReaderWrapperGetSampleBuffer"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190df0
    const char* s_90909 = "MediaReaderWrapperGetSampleBuffer"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190e30
    return a0;
}
