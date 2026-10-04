// Function: MMCodec::MediaRecorderWrapperWillResignActive(void*)
// RVA: 0x196028, Size: 172 bytes
int64_t _ZN7MMCodec36MediaRecorderWrapperWillResignActiveEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorder18didEnterBackgroundEv(...); // call imported API via PLT at 0x196034
    return a0;
    const char* s_85439 = "MediaRecorderWrapperWillResignActive"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x196084
    const char* s_85439 = "MediaRecorderWrapperWillResignActive"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1960c4
    return a0;
}
