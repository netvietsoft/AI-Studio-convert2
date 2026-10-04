// Function: MMCodec::MediaReaderWrapperReleaseSampleBuffer(void*, void**)
// RVA: 0x190e40, Size: 196 bytes
int64_t _ZN7MMCodec37MediaReaderWrapperReleaseSampleBufferEPvPS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader19releaseSampleBufferERPNS_19AICodecSampleBufferE(...); // call imported API via PLT at 0x190e48
    return a0;
    const char* s_8c5a0 = "MediaReaderWrapperReleaseSampleBuffer"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190eb4
    const char* s_8c5a0 = "MediaReaderWrapperReleaseSampleBuffer"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190ef4
    return a0;
}
