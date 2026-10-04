// Function: MMCodec::MediaRecorderWrapperRestartEncoder(void*)
// RVA: 0x196180, Size: 192 bytes
int64_t _ZN7MMCodec34MediaRecorderWrapperRestartEncoderEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorder14restartEncoderEv(...); // call imported API via PLT at 0x196184
    return a0;
    const char* s_78a37 = "MediaRecorderWrapperRestartEncoder"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1961f0
    const char* s_78a37 = "MediaRecorderWrapperRestartEncoder"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x196230
    return a0;
}
