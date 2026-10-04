// Function: PVGCOLOR::PVGOpenGL::readRGBA16DataFromTexture2D(int, int, int, void*)
// RVA: 0x52160, Size: 340 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL27readRGBA16DataFromTexture2DEiiiPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetIntegerv(...); // call PLT API at 0x521b0
    glGenFramebuffers(...); // call PLT API at 0x521c0
    glBindFramebuffer(...); // call PLT API at 0x521cc
    glFramebufferTexture2D(...); // call PLT API at 0x521e4
    glPixelStorei(...); // call PLT API at 0x521f0
    glReadPixels(...); // call PLT API at 0x52210
    glPixelStorei(...); // call PLT API at 0x5221c
    glBindFramebuffer(...); // call PLT API at 0x52228
    glDeleteFramebuffers(...); // call PLT API at 0x52234
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL readRGBA16DataFromTexture2D failed: invalid parameters texture=%d data=%p
";
    const char* str = "readRGBA16DataFromTexture2D";
    __android_log_print(...); // call PLT API at 0x52280
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x522b0
}
