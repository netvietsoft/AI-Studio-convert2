// Function: MMCodec::MediaReaderWrapperSetCallback(void*, void*, void (*)(void*, void*, int, int, double, double, void*))
// RVA: 0x19217c, Size: 452 bytes
int64_t _ZN7MMCodec29MediaReaderWrapperSetCallbackEPvS0_PFvS0_S0_iiddS0_E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_201328 = (void*)0x201328; // global ref
    _ZN7MMCodec13MTMediaReader11setCallbackENSt6__ndk18functionIFvidPvEEE(...); // call imported API via PLT at 0x1921bc
    const char* s_6dfa4 = "MediaReaderWrapperSetCallback"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x192218
    const char* s_6dfa4 = "MediaReaderWrapperSetCallback"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x192274
    _ZN7MMCodec13MTMediaReader11setCallbackENSt6__ndk18functionIFvidPvEEE(...); // call imported API via PLT at 0x192284
    (*x8)(...); // indirect call at 0x1922b0
    return a0;
    (*x9)(...); // indirect call at 0x192320
    __stack_chk_fail(...); // call imported API via PLT at 0x19233c
}
