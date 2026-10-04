// Function: MMCodec::MediaRecorderWrapperRecordAudio(void*, unsigned char*, unsigned long)
// RVA: 0x19566c, Size: 192 bytes
int64_t _ZN7MMCodec31MediaRecorderWrapperRecordAudioEPvPhm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MediaRecorder11recordAudioEPhi(...); // call imported API via PLT at 0x195670
    return a0;
    const char* s_7b113 = "MediaRecorderWrapperRecordAudio"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c317 = "[%s(%d)]:> MediaRecorderWrapper %s handle is null"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1956dc
    const char* s_7b113 = "MediaRecorderWrapperRecordAudio"; // string xref
    const char* s_86ad6 = "%s/MTMV_AICodec: [%s(%d)]:> MediaRecorderWrapper %s handle is null
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x19571c
    return a0;
}
