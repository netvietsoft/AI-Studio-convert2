// Function: MMCodec::MediaReaderWrapperGetVideoFrame(void*, long, void*, void*, void*)
// RVA: 0x190f04, Size: 244 bytes
int64_t _ZN7MMCodec31MediaReaderWrapperGetVideoFrameEPvlS0_S0_S0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader13getVideoFrameElNS_10ReadOptionERNS_10VideoFrameERNS_9FrameInfoE(...); // call imported API via PLT at 0x190f44
    const char* s_8c5c6 = "MediaReaderWrapperGetVideoFrame"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x190f8c
    const char* s_8c5c6 = "MediaReaderWrapperGetVideoFrame"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x190fcc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x190ff4
}
