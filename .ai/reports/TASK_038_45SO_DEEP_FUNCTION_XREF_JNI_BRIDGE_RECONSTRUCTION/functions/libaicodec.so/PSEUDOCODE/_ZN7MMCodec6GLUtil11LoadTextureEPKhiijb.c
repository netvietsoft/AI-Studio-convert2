// Function: MMCodec::GLUtil::LoadTexture(unsigned char const*, int, int, unsigned int, bool)
// RVA: 0x10de18, Size: 1124 bytes
int64_t _ZN7MMCodec6GLUtil11LoadTextureEPKhiijb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call imported API via PLT at 0x10de5c
    glBindTexture(...); // call imported API via PLT at 0x10de6c
    _Znam(...); // call imported API via PLT at 0x10de90
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_82147 = "[%s(%d)]:> glGenTextures error !"; // string xref
    const char* s_6890b = "LoadTexture"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10def0
    const char* s_91122 = "%s/MTMV_AICodec: [%s(%d)]:> glGenTextures error !
"; // string xref
    const char* s_6890b = "LoadTexture"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10df2c
    _Znam(...); // call imported API via PLT at 0x10df48
    void* g_201004 = (void*)0x201004; // global ref
    glTexImage2D(...); // call imported API via PLT at 0x10dfd4
    glTexImage2D(...); // call imported API via PLT at 0x10e024
    glTexImage2D(...); // call imported API via PLT at 0x10e1e8
    _ZdaPv(...); // call imported API via PLT at 0x10e1f0
    glTexParameteri(...); // call imported API via PLT at 0x10e200
    glTexParameteri(...); // call imported API via PLT at 0x10e210
    glTexParameteri(...); // call imported API via PLT at 0x10e220
    glTexParameteri(...); // call imported API via PLT at 0x10e230
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x10e278
}
