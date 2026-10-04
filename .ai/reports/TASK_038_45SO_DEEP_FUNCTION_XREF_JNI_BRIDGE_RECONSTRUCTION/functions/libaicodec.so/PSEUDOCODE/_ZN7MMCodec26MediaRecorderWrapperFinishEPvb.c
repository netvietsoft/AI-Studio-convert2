// Function: MMCodec::MediaRecorderWrapperFinish(void*, bool)
// RVA: 0x195ba0, Size: 196 bytes
int64_t _ZN7MMCodec26MediaRecorderWrapperFinishEPvb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorder6finishEb(...); // call imported API via PLT at 0x195ba8
    return a0;
    const char* s_8e158 = "MediaRecorderWrapperFinish"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x195c14
    const char* s_8e158 = "MediaRecorderWrapperFinish"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x195c54
    return a0;
}
