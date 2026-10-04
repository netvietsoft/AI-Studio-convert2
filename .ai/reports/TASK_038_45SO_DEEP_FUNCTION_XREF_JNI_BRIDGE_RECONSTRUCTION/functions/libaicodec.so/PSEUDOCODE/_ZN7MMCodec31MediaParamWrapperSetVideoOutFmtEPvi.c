// Function: MMCodec::MediaParamWrapperSetVideoOutFmt(void*, int)
// RVA: 0x193d48, Size: 408 bytes
int64_t _ZN7MMCodec31MediaParamWrapperSetVideoOutFmtEPvi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x193db8
    _ZN7MMCodec10MediaParam14setVideoOutFmtENS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x193e14
    return a0;
    const char* s_6b862 = "MediaParamWrapperSetVideoOutFmt"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_83d13 = "[%s(%d)]:> MediaParamWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x193e84
    const char* s_6b862 = "MediaParamWrapperSetVideoOutFmt"; // string xref
    const char* s_6b803 = "%s/MTMV_AICodec: [%s(%d)]:> MediaParamWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x193ec4
    return a0;
}
