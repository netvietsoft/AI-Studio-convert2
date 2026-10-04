// Function: PVGCOLOR::PVGOpenGL::readRGBADataFromTexture2D(int, int, int, void*)
// RVA: 0x5200c, Size: 340 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL25readRGBADataFromTexture2DEiiiPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetIntegerv(...); // call PLT API at 0x5205c
    glGenFramebuffers(...); // call PLT API at 0x5206c
    glBindFramebuffer(...); // call PLT API at 0x52078
    glFramebufferTexture2D(...); // call PLT API at 0x52090
    glPixelStorei(...); // call PLT API at 0x5209c
    glReadPixels(...); // call PLT API at 0x520bc
    glPixelStorei(...); // call PLT API at 0x520c8
    glBindFramebuffer(...); // call PLT API at 0x520d4
    glDeleteFramebuffers(...); // call PLT API at 0x520e0
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL readRGBADataFromTexture2D failed: invalid parameters texture=%d data=%p
";
    const char* str = "readRGBADataFromTexture2D";
    __android_log_print(...); // call PLT API at 0x5212c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x5215c
}
