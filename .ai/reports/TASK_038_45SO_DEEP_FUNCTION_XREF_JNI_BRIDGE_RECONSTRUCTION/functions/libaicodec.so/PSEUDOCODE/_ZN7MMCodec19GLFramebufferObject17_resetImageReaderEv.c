// Function: MMCodec::GLFramebufferObject::_resetImageReader()
// RVA: 0x175570, Size: 656 bytes
int64_t _ZN7MMCodec19GLFramebufferObject17_resetImageReaderEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglGetCurrentContext(...); // call imported API via PLT at 0x1755a4
    eglGetCurrentDisplay(...); // call imported API via PLT at 0x1755ac
    eglGetCurrentSurface(...); // call imported API via PLT at 0x1755b8
    eglGetCurrentSurface(...); // call imported API via PLT at 0x1755c4
    glGetIntegerv(...); // call imported API via PLT at 0x1755d4
    glGetIntegerv(...); // call imported API via PLT at 0x1755e0
    _ZN7MMCodec8GLShaderD1Ev(...); // call imported API via PLT at 0x1755f0
    _ZdlPv(...); // call imported API via PLT at 0x1755f8
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x17560c
    _ZNSt6__ndk118condition_variable10notify_allEv(...); // call imported API via PLT at 0x175614
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x17561c
    (*x8)(...); // indirect call at 0x17564c
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x175654
    (*x8)(...); // indirect call at 0x175668
    (*x8)(...); // indirect call at 0x1756a4
    _ZdlPv(...); // call imported API via PLT at 0x1756ac
    (*x8)(...); // indirect call at 0x1756c4
    eglMakeCurrent(...); // call imported API via PLT at 0x1756f8
    glBindFramebuffer(...); // call imported API via PLT at 0x175708
    glViewport(...); // call imported API via PLT at 0x175714
    (*x8)(...); // indirect call at 0x175728
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv(...); // call imported API via PLT at 0x175730
    eglMakeCurrent(...); // call imported API via PLT at 0x175744
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d54e = "[%s(%d)]:> [%d]egl make current failed"; // string xref
    const char* s_7363a = "_resetImageReader"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17578c
    const char* s_71874 = "%s/MTMV_AICodec: [%s(%d)]:> [%d]egl make current failed
"; // string xref
    const char* s_7363a = "_resetImageReader"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1757cc
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1757fc
}
