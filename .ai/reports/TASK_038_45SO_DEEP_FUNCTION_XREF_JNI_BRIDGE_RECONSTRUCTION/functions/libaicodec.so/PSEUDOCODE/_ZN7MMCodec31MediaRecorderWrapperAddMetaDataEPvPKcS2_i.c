// Function: MMCodec::MediaRecorderWrapperAddMetaData(void*, char const*, char const*, int)
// RVA: 0x1951a4, Size: 400 bytes
int64_t _ZN7MMCodec31MediaRecorderWrapperAddMetaDataEPvPKcS2_i(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znwm(...); // call imported API via PLT at 0x195220
    _ZN7MMCodec13MediaRecorder11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE(...); // call imported API via PLT at 0x195274
    return a0;
    const char* s_6f197 = "MediaRecorderWrapperAddMetaData"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1952d4
    const char* s_6f197 = "MediaRecorderWrapperAddMetaData"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x195314
    return a0;
}
