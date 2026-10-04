// Function: MMCodec::AndroidMediaEncoder::codecOpen(void*)
// RVA: 0xf1d90, Size: 1880 bytes
int64_t _ZN7MMCodec19AndroidMediaEncoder9codecOpenEPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglGetCurrentContext(...); // call imported API via PLT at 0xf1dc8
    eglGetCurrentDisplay(...); // call imported API via PLT at 0xf1dd4
    eglGetCurrentSurface(...); // call imported API via PLT at 0xf1de0
    eglGetCurrentSurface(...); // call imported API via PLT at 0xf1dec
    glGetIntegerv(...); // call imported API via PLT at 0xf1dfc
    glGetIntegerv(...); // call imported API via PLT at 0xf1e08
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf1e0c
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_86f99 = "[%s(%d)]:> %s input parameter is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf1e58
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_685a2 = "%s/MTMV_AICodec: [%s(%d)]:> %s input parameter is invalid
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf1e98
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf1eb0
    (*x8)(...); // indirect call at 0xf1ed8
    ANativeWindow_release(...); // call imported API via PLT at 0xf1eec
    (*x8)(...); // indirect call at 0xf1f04
    (*x8)(...); // indirect call at 0xf1f18
    ANativeWindow_fromSurface(...); // call imported API via PLT at 0xf1f28
    (*x8)(...); // indirect call at 0xf1f40
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6bb90 = "[%s(%d)]:> %s eglSetup failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf1f88
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_674f7 = "%s/MTMV_AICodec: [%s(%d)]:> %s eglSetup failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf1fc8
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_712cc = "[%s(%d)]:> %s state is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf2014
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_6bb24 = "%s/MTMV_AICodec: [%s(%d)]:> %s state is invalid
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf2054
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a331 = "[%s(%d)]:> %s get surface failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf20a0
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_81bde = "%s/MTMV_AICodec: [%s(%d)]:> %s get surface failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf20e0
    _ZN7MMCodec14AndroidEncoder9codecOpenEPv(...); // call imported API via PLT at 0xf20f4
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8f91c = "[%s(%d)]:> %s java CodecOpen failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf213c
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_6bb55 = "%s/MTMV_AICodec: [%s(%d)]:> %s java CodecOpen failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf217c
    (*x8)(...); // indirect call at 0xf218c
    _Znwm(...); // call imported API via PLT at 0xf21ac
    _ZN7MMCodec8GLShaderC1Ev(...); // call imported API via PLT at 0xf21b4
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xf21cc
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0xf21e0
    _ZN7MMCodec8GLShader18initWithByteArraysERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_(...); // call imported API via PLT at 0xf21f0
    _ZdlPv(...); // call imported API via PLT at 0xf2200
    _ZdlPv(...); // call imported API via PLT at 0xf2210
    (*x8)(...); // indirect call at 0xf2224
    eglMakeCurrent(...); // call imported API via PLT at 0xf223c
    glBindFramebuffer(...); // call imported API via PLT at 0xf224c
    glViewport(...); // call imported API via PLT at 0xf2258
    _ZN7MMCodec7EglCore18makeNothingCurrentEv(...); // call imported API via PLT at 0xf2264
    _Znwm(...); // call imported API via PLT at 0xf2274
    void* g_1fdd80 = (void*)0x1fdd80; // global ref
    void* g_1fde10 = (void*)0x1fde10; // global ref
    _ZN7MMCodec10ThreadPoolC1EmNSt6__ndk18functionIFvvEEES4_(...); // call imported API via PLT at 0xf22b0
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_712eb = "[%s(%d)]:> [%s:%d]egl make current failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf2314
    const char* s_67493 = "codecOpen"; // string xref
    const char* s_8f94c = "%s/MTMV_AICodec: [%s(%d)]:> [%s:%d]egl make current failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf2358
    (*x8)(...); // indirect call at 0xf2370
    (*x8)(...); // indirect call at 0xf23a0
    (*x8)(...); // indirect call at 0xf23b8
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0xf2400
    _ZdlPv(...); // call imported API via PLT at 0xf2418
    _ZdlPv(...); // call imported API via PLT at 0xf242c
    (*x9)(...); // indirect call at 0xf2464
    (*x8)(...); // indirect call at 0xf2494
    _ZdlPv(...); // call imported API via PLT at 0xf249c
    sub_CEBC4(...); // call internal func at 0xf24a8
    (*x8)(...); // indirect call at 0xf24c4
    __stack_chk_fail(...); // call imported API via PLT at 0xf24e0
    sub_CEBC4(...); // call internal func at 0xf24e4
}
