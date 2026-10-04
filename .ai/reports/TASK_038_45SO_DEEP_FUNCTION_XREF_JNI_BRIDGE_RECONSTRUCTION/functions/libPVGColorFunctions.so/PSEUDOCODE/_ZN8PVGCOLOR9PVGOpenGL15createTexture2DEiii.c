// Function: PVGCOLOR::PVGOpenGL::createTexture2D(int, int, int)
// RVA: 0x519ec, Size: 516 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL15createTexture2DEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call PLT API at 0x51a24
    glBindTexture(...); // call PLT API at 0x51a34
    glTexParameterf(...); // call PLT API at 0x51a50
    glTexParameterf(...); // call PLT API at 0x51a60
    glTexParameterf(...); // call PLT API at 0x51a7c
    glTexParameterf(...); // call PLT API at 0x51a8c
    glGetError(...); // call PLT API at 0x51af8
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL createTexture2D failed: glGenTextures returned 0, err %0x
";
    const char* str = "createTexture2D";
    __android_log_print(...); // call PLT API at 0x51b20
    glTexImage2D(...); // call PLT API at 0x51b70
    glGetError(...); // call PLT API at 0x51b74
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> createTexture2D, glGetError %0x
";
    const char* str = "createTexture2D";
    __android_log_print(...); // call PLT API at 0x51bbc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x51bec
}
