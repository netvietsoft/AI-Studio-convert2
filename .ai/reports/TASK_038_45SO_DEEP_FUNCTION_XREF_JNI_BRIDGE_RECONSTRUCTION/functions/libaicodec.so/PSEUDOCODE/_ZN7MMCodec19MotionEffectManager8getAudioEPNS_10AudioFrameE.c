// Function: MMCodec::MotionEffectManager::getAudio(MMCodec::AudioFrame*)
// RVA: 0x12107c, Size: 812 bytes
int64_t _ZN7MMCodec19MotionEffectManager8getAudioEPNS_10AudioFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1210b0
    _ZNK7MMCodec12MotionEffect14getEffectParamEv(...); // call imported API via PLT at 0x1210e8
    _ZN7MMCodec12MotionEffect12getTimestampEl(...); // call imported API via PLT at 0x1210f4
    _ZN7MMCodec12MotionEffect16getFileTimestampEl(...); // call imported API via PLT at 0x121134
    _ZN7MMCodec12MotionEffect8getAudioEPNS_10AudioFrameEl(...); // call imported API via PLT at 0x121144
    pthread_self(...); // call imported API via PLT at 0x1211c0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x1211d0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_751b6 = "[%s(%d)]:> [MotionEffectManager(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x121208
    pthread_self(...); // call imported API via PLT at 0x12122c
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x12123c
    const char* s_85eef = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectManager(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x121270
    pthread_self(...); // call imported API via PLT at 0x1212a8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6faaf = "[%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, audio clock:%lld"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1212d8
    pthread_self(...); // call imported API via PLT at 0x1212fc
    const char* s_834ec = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffectManager(%p)](%ld):> found no speed effect, audio clock:%lld
"; // string xref
    const char* s_765e4 = "getAudio"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x121328
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x121334
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x121374
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x121388
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x12139c
}
