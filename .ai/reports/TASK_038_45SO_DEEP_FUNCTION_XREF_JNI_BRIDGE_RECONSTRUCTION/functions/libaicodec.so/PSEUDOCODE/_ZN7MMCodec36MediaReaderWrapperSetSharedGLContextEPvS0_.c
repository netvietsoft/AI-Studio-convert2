// Function: MMCodec::MediaReaderWrapperSetSharedGLContext(void*, void*)
// RVA: 0x192054, Size: 296 bytes
int64_t _ZN7MMCodec36MediaReaderWrapperSetSharedGLContextEPvS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MTMediaReader17getAICodecContextEv(...); // call imported API via PLT at 0x192070
    _ZN7MMCodec14AICodecContext18setSharedGLContextEPv(...); // call imported API via PLT at 0x192088
    const char* s_8e0d7 = "MediaReaderWrapperSetSharedGLContext"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7d667 = "[%s(%d)]:> MediaReaderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1920cc
    const char* s_8e0d7 = "MediaReaderWrapperSetSharedGLContext"; // string xref
    const char* s_6a6d0 = "%s/MTMV_AICodec: [%s(%d)]:> MediaReaderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x192118
    _Znwm(...); // call imported API via PLT at 0x192120
    _ZN7MMCodec14AICodecContextC1Ev(...); // call imported API via PLT at 0x192128
    _ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE(...); // call imported API via PLT at 0x192134
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x19213c
    _ZN7MMCodec14AICodecContext18setSharedGLContextEPv(...); // call imported API via PLT at 0x192154
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x192170
}
