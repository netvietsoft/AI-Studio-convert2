// Function: MMCodec::PixelTexture::loadRGBA(unsigned char*, unsigned long, int, int, int)
// RVA: 0x10cd4c, Size: 2164 bytes
int64_t _ZN7MMCodec12PixelTexture8loadRGBAEPhmiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec13MMImageWriter15queueInputImageEPKhmi(...); // call imported API via PLT at 0x10cdd8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x10cdf0
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...); // call imported API via PLT at 0x10ce0c
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82117 = "[%s(%d)]:> %s abort"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ce60
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_888ce = "%s/MTMV_AICodec: [%s(%d)]:> %s abort
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10cea0
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x10cebc
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7181d = "[%s(%d)]:> %s parameter is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10cf18
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_910ed = "%s/MTMV_AICodec: [%s(%d)]:> %s parameter is invalid
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10cf58
    _ZN7MMCodec12PixelTexture7releaseEv(...); // call imported API via PLT at 0x10cf84
    _Znwm(...); // call imported API via PLT at 0x10cf90
    _ZN7MMCodec13MMImageWriterC1Ev(...); // call imported API via PLT at 0x10cf98
    _Znwm(...); // call imported API via PLT at 0x10cfa4
    void* g_201010 = (void*)0x201010; // global ref
    sub_10D6A8(...); // call internal func at 0x10cfdc
    (*x8)(...); // indirect call at 0x10d008
    _ZN7MMCodec13MMImageWriter4initEiiiPKNS0_16onFrameAvailableE(...); // call imported API via PLT at 0x10d024
    _ZN7MMCodec13MMImageWriter15queueInputImageEPKhmi(...); // call imported API via PLT at 0x10d048
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8455b = "[%s(%d)]:> %s queueInputImage failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10d090
    const char* s_8e9b6 = "%s/MTMV_AICodec: [%s(%d)]:> %s queueInputImage failed
"; // string xref
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7dead = "[%s(%d)]:> %s Writer init failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10d10c
    const char* s_8b429 = "%s/MTMV_AICodec: [%s(%d)]:> %s Writer init failed
"; // string xref
    const char* s_6796f = "loadRGBA"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10d14c
    return a0;
    _ZN7MMCodec13MMImageWriter17dequeueInputImageERiRPf(...); // call imported API via PLT at 0x10d198
    _Znwm(...); // call imported API via PLT at 0x10d1bc
    _ZN7MMCodec8GLShaderC1Ev(...); // call imported API via PLT at 0x10d1c4
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x10d1dc
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc(...); // call imported API via PLT at 0x10d1f0
    _ZN7MMCodec8GLShader18initWithByteArraysERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_(...); // call imported API via PLT at 0x10d200
    _ZdlPv(...); // call imported API via PLT at 0x10d210
    _ZdlPv(...); // call imported API via PLT at 0x10d220
    (*x8)(...); // indirect call at 0x10d234
    _Znwm(...); // call imported API via PLT at 0x10d244
    _ZN7MMCodec19GLFramebufferObjectC1Eb(...); // call imported API via PLT at 0x10d250
    glGetIntegerv(...); // call imported API via PLT at 0x10d260
    glGetIntegerv(...); // call imported API via PLT at 0x10d26c
    (*x8)(...); // indirect call at 0x10d280
    _ZNK7MMCodec19GLFramebufferObject6enableEv(...); // call imported API via PLT at 0x10d288
    strlen(...); // call imported API via PLT at 0x10d2a0
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6adb0 = "[%s(%d)]:> %s dequeueInputImage failed"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10d310
    const char* s_6796f = "loadRGBA"; // string xref
    const char* s_8b45c = "%s/MTMV_AICodec: [%s(%d)]:> %s dequeueInputImage failed
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10d350
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x10d368
    memmove(...); // call imported API via PLT at 0x10d388
    _ZN7MMCodec12UniformValueC1EPfi(...); // call imported API via PLT at 0x10d39c
    (*x8)(...); // indirect call at 0x10d3b4
    _ZN7MMCodec12UniformValueD1Ev(...); // call imported API via PLT at 0x10d3bc
    _ZdlPv(...); // call imported API via PLT at 0x10d3cc
    strlen(...); // call imported API via PLT at 0x10d3e4
    void* g_201001 = (void*)0x201001; // global ref
    _Znwm(...); // call imported API via PLT at 0x10d420
    memmove(...); // call imported API via PLT at 0x10d440
    _ZN7MMCodec12UniformValueC1Ejib(...); // call imported API via PLT at 0x10d458
    (*x8)(...); // indirect call at 0x10d470
    _ZN7MMCodec12UniformValueD1Ev(...); // call imported API via PLT at 0x10d478
    _ZdlPv(...); // call imported API via PLT at 0x10d488
    (*x8)(...); // indirect call at 0x10d4a4
    glBindFramebuffer(...); // call imported API via PLT at 0x10d4b0
    glViewport(...); // call imported API via PLT at 0x10d4bc
    sub_D22F8(...); // call internal func at 0x10d4dc
    sub_D22F8(...); // call internal func at 0x10d4f4
    _ZdlPv(...); // call imported API via PLT at 0x10d508
    _ZdlPv(...); // call imported API via PLT at 0x10d524
    _ZdlPv(...); // call imported API via PLT at 0x10d538
    _ZN7MMCodec12UniformValueD1Ev(...); // call imported API via PLT at 0x10d550
    _ZdlPv(...); // call imported API via PLT at 0x10d568
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x10d590
    _ZdlPv(...); // call imported API via PLT at 0x10d5a0
    __stack_chk_fail(...); // call imported API via PLT at 0x10d5bc
}
