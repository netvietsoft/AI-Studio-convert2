// Function: MMCodec::MediaParamWrapperSetVideoInParam(void*, int, int, int)
// RVA: 0x193b00, Size: 392 bytes
int64_t _ZN7MMCodec32MediaParamWrapperSetVideoInParamEPviii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x193b7c
    _ZN7MMCodec10MediaParam15setVideoInParamEiiNS_16VIDEO_PIX_FORMATE(...); // call imported API via PLT at 0x193be4
    const char* s_8050b = "MediaParamWrapperSetVideoInParam"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_83d13 = "[%s(%d)]:> MediaParamWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x193c28
    const char* s_8050b = "MediaParamWrapperSetVideoInParam"; // string xref
    const char* s_6b803 = "%s/MTMV_AICodec: [%s(%d)]:> MediaParamWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x193c68
    return a0;
}
