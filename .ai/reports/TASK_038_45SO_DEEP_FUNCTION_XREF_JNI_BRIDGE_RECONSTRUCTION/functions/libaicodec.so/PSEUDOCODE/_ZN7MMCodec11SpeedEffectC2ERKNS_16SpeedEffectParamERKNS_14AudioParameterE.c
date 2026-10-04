// Function: MMCodec::SpeedEffect::SpeedEffect(MMCodec::SpeedEffectParam const&, MMCodec::AudioParameter const&)
// RVA: 0x119594, Size: 372 bytes
int64_t _ZN7MMCodec11SpeedEffectC2ERKNS_16SpeedEffectParamERKNS_14AudioParameterE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec6AVIRefC2Ev(...); // call imported API via PLT at 0x1195b8
    void* g_202010 = (void*)0x202010; // global ref
    _ZN7MMCodec11CurveParamsC1ERKS0_(...); // call imported API via PLT at 0x1195e4
    av_get_bytes_per_sample(...); // call imported API via PLT at 0x1195f8
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x119630
    pthread_self(...); // call imported API via PLT at 0x119638
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85e76 = "[%s(%d)]:> [SpeedEffect(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s"; // string xref
    const char* s_69d35 = "SpeedEffect"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x119670
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0x11969c
    pthread_self(...); // call imported API via PLT at 0x1196a4
    const char* s_88a2e = "%s/MTMV_AICodec: [%s(%d)]:> [SpeedEffect(%p)](%ld):> av_get_bytes_per_sample failed %d %d->%s
"; // string xref
    const char* s_69d35 = "SpeedEffect"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1196d8
    return a0;
    _ZN7MMCodec6AVIRefD2Ev(...); // call imported API via PLT at 0x1196fc
}
