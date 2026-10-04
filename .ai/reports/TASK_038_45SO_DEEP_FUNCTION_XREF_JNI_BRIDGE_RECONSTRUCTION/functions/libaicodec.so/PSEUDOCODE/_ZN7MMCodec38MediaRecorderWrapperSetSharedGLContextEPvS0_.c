// Function: MMCodec::MediaRecorderWrapperSetSharedGLContext(void*, void*)
// RVA: 0x194e2c, Size: 196 bytes
int64_t _ZN7MMCodec38MediaRecorderWrapperSetSharedGLContextEPvS0_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorder10getContextEv(...); // call imported API via PLT at 0x194e40
    _ZN7MMCodec14AICodecContext18setSharedGLContextEPv(...); // call imported API via PLT at 0x194e48
    return a0;
    const char* s_75aa7 = "MediaRecorderWrapperSetSharedGLContext"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x194e9c
    const char* s_75aa7 = "MediaRecorderWrapperSetSharedGLContext"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x194edc
    return a0;
}
