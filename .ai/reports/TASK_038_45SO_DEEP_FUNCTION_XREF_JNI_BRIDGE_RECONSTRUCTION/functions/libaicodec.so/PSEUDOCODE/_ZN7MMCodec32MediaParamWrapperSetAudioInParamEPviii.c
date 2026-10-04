// Function: MMCodec::MediaParamWrapperSetAudioInParam(void*, int, int, int)
// RVA: 0x1938b8, Size: 392 bytes
int64_t _ZN7MMCodec32MediaParamWrapperSetAudioInParamEPviii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x193934
    _ZN7MMCodec10MediaParam15setAudioInParamEiiNS_19AUDIO_SAMPLE_FORMATE(...); // call imported API via PLT at 0x19399c
    const char* s_6ccd9 = "MediaParamWrapperSetAudioInParam"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_83d13 = "[%s(%d)]:> MediaParamWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1939e0
    const char* s_6ccd9 = "MediaParamWrapperSetAudioInParam"; // string xref
    const char* s_6b803 = "%s/MTMV_AICodec: [%s(%d)]:> MediaParamWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x193a20
    return a0;
}
