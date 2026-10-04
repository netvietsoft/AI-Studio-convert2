// Function: MMCodec::AudioStream::init(MMCodec::MediaParam*, int)
// RVA: 0xcebf8, Size: 428 bytes
int64_t _ZN7MMCodec11AudioStream4initEPNS_10MediaParamEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10MediaParam20readOutAudioSettingsEPNS_12AudioParam_tE(...); // call imported API via PLT at 0xcec1c
    _ZN7MMCodec10MediaParam19readInAudioSettingsEPNS_12AudioParam_tE(...); // call imported API via PLT at 0xcec2c
    return a0;
    pthread_self(...); // call imported API via PLT at 0xcec68
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_817a4 = "[%s(%d)]:> [AudioStream(%p)](%ld):> read out audio settings error!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xcec94
    pthread_self(...); // call imported API via PLT at 0xcecc0
    const char* s_75b1e = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> read out audio settings error!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    pthread_self(...); // call imported API via PLT at 0xced0c
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_89ba6 = "[%s(%d)]:> [AudioStream(%p)](%ld):> read in audio settings error!"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xced38
    pthread_self(...); // call imported API via PLT at 0xced64
    const char* s_7c3df = "%s/MTMV_AICodec: [%s(%d)]:> [AudioStream(%p)](%ld):> read in audio settings error!
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xced8c
    return a0;
}
