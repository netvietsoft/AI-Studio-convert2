// Function: MMCodec::EglCore::_getConfig(int, int)
// RVA: 0x10e830, Size: 364 bytes
int64_t _ZN7MMCodec7EglCore10_getConfigEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglChooseConfig(...); // call imported API via PLT at 0x10e8b8
    return a0;
    eglGetError(...); // call imported API via PLT at 0x10e908
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f8d7 = "[%s(%d)]:> unable to find RGB8888; elgError: 0x%04X / Egl Version[%d] EGLConfig"; // string xref
    const char* s_74fde = "_getConfig"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10e934
    eglGetError(...); // call imported API via PLT at 0x10e958
    const char* s_7dedd = "%s/MTMV_AICodec: [%s(%d)]:> unable to find RGB8888; elgError: 0x%04X / Egl Version[%d] EGLConfig
"; // string xref
    const char* s_74fde = "_getConfig"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10e980
    __stack_chk_fail(...); // call imported API via PLT at 0x10e998
}
