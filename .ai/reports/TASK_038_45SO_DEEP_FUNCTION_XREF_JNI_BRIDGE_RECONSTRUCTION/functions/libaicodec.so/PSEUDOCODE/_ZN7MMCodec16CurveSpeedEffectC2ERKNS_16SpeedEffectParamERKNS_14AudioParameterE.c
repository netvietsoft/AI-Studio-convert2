// Function: MMCodec::CurveSpeedEffect::CurveSpeedEffect(MMCodec::SpeedEffectParam const&, MMCodec::AudioParameter const&)
// RVA: 0x11bd58, Size: 668 bytes
int64_t _ZN7MMCodec16CurveSpeedEffectC2ERKNS_16SpeedEffectParamERKNS_14AudioParameterE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec11SpeedEffectC2ERKNS_16SpeedEffectParamERKNS_14AudioParameterE(...); // call imported API via PLT at 0x11bd74
    void* g_202010 = (void*)0x202010; // global ref
    _ZN7MMCodec12CurveFactory11createCurveERKNS_11CurveParamsEd(...); // call imported API via PLT at 0x11bd90
    _Znwm(...); // call imported API via PLT at 0x11bd9c
    _ZN7MMCodec10MTResampleC1Ev(...); // call imported API via PLT at 0x11bda4
    _Znwm(...); // call imported API via PLT at 0x11bdb0
    _ZN7MMCodec8MMBufferC1Em(...); // call imported API via PLT at 0x11bdbc
    _Znwm(...); // call imported API via PLT at 0x11bde8
    _ZN6rtSOLA5CSOLAC1Ev(...); // call imported API via PLT at 0x11bdf0
    _ZN6rtSOLA5CSOLA11SOLAReStartEfi(...); // call imported API via PLT at 0x11be08
    pthread_self(...); // call imported API via PLT at 0x11be30
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88b58 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> SOLAReStart failed"; // string xref
    const char* s_7927d = "CurveSpeedEffect"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11be5c
    pthread_self(...); // call imported API via PLT at 0x11be80
    const char* s_8ebc9 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> SOLAReStart failed
"; // string xref
    const char* s_7927d = "CurveSpeedEffect"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11bea8
    const char* s_67aa0 = "Assertion %s failed at %s:%d
"; // string xref
    const char* s_67abe = "false"; // string xref
    const char* s_6fa06 = "/Users/meitu/apollo-ws/proj/android/aicodec/src/main/cpp/src/effect/video/CurveSpeedEffect.cpp"; // string xref
    av_log(...); // call imported API via PLT at 0x11bed0
    abort(...); // call imported API via PLT at 0x11bed4
    _ZN7MMCodec10MTResample4initE14AVSampleFormatiiS1_ii(...); // call imported API via PLT at 0x11bef0
    (*x8)(...); // indirect call at 0x11bf08
    pthread_self(...); // call imported API via PLT at 0x11bf30
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8d076 = "[%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> "; // string xref
    const char* s_7927d = "CurveSpeedEffect"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x11bf5c
    pthread_self(...); // call imported API via PLT at 0x11bf80
    const char* s_6e806 = "%s/MTMV_AICodec: [%s(%d)]:> [CurveSpeedEffect(%p)](%ld):> 
"; // string xref
    const char* s_7927d = "CurveSpeedEffect"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x11bfa8
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x11bfcc
    _ZN7MMCodec11SpeedEffectD2Ev(...); // call imported API via PLT at 0x11bfd4
    _ZN7MMCodec11SpeedEffectD2Ev(...); // call imported API via PLT at 0x11bfe8
}
