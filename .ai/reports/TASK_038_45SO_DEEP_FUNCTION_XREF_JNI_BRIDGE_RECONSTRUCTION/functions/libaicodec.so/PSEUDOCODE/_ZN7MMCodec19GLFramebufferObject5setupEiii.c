// Function: MMCodec::GLFramebufferObject::setup(int, int, int)
// RVA: 0x175130, Size: 1088 bytes
int64_t _ZN7MMCodec19GLFramebufferObject5setupEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetIntegerv(...); // call imported API via PLT at 0x1751a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_76ed7 = "[%s(%d)]:> GL_MAX_TEXTURE_SIZE %d"; // string xref
    const char* s_82af3 = "setup"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x175234
    const char* s_6c75a = "%s/MTMV_AICodec: [%s(%d)]:> GL_MAX_TEXTURE_SIZE %d
"; // string xref
    const char* s_82af3 = "setup"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17526c
    glGetIntegerv(...); // call imported API via PLT at 0x175278
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7d5a5 = "[%s(%d)]:> GL_MAX_RENDERBUFFER_SIZE %d"; // string xref
    const char* s_82af3 = "setup"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1752fc
    const char* s_84d94 = "%s/MTMV_AICodec: [%s(%d)]:> GL_MAX_RENDERBUFFER_SIZE %d
"; // string xref
    const char* s_82af3 = "setup"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x175334
    glGetIntegerv(...); // call imported API via PLT at 0x175340
    _ZN7MMCodec19GLFramebufferObject17_resetImageReaderEv(...); // call imported API via PLT at 0x17534c
    (*x8)(...); // indirect call at 0x175364
    glBindFramebuffer(...); // call imported API via PLT at 0x175370
    glGenFramebuffers(...); // call imported API via PLT at 0x175390
    glBindFramebuffer(...); // call imported API via PLT at 0x1753a0
    glGenTextures(...); // call imported API via PLT at 0x1753bc
    _ZN7MMCodec2GL13bindTexture2DEj(...); // call imported API via PLT at 0x1753c8
    glTexParameteri(...); // call imported API via PLT at 0x1753d8
    glTexParameteri(...); // call imported API via PLT at 0x1753e8
    glTexParameteri(...); // call imported API via PLT at 0x1753f8
    glTexParameteri(...); // call imported API via PLT at 0x175408
    glTexImage2D(...); // call imported API via PLT at 0x175430
    glFramebufferTexture2D(...); // call imported API via PLT at 0x17544c
    (*x8)(...); // indirect call at 0x175464
    glFramebufferRenderbuffer(...); // call imported API via PLT at 0x175478
    glClearColor(...); // call imported API via PLT at 0x175490
    glClear(...); // call imported API via PLT at 0x175498
    glCheckFramebufferStatus(...); // call imported API via PLT at 0x1754a0
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72276 = "[%s(%d)]:> Failed to initialize framebuffer object %d"; // string xref
    const char* s_82af3 = "setup"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1754ec
    const char* s_757b5 = "%s/MTMV_AICodec: [%s(%d)]:> Failed to initialize framebuffer object %d
"; // string xref
    const char* s_82af3 = "setup"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x175524
    glBindFramebuffer(...); // call imported API via PLT at 0x175538
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x17556c
}
