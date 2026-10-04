// Function: PVGCOLOR::PVGOpenGL::writeRGBADataToTexture2D(void*, int, int, int, int)
// RVA: 0x51d54, Size: 348 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL24writeRGBADataToTexture2DEPviiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindTexture(...); // call PLT API at 0x51d98
    glPixelStorei(...); // call PLT API at 0x51da4
    glPixelStorei(...); // call PLT API at 0x51dbc
    glTexSubImage2D(...); // call PLT API at 0x51de4
    glPixelStorei(...); // call PLT API at 0x51df0
    glPixelStorei(...); // call PLT API at 0x51dfc
    glGetError(...); // call PLT API at 0x51e00
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> writeRGBADataToTexture2D, glGetError %0x
";
    const char* str = "writeRGBADataToTexture2D";
    __android_log_print(...); // call PLT API at 0x51e48
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL writeRGBADataToTexture2D failed: invalid parameters texture=%d data=%p
";
    const char* str = "writeRGBADataToTexture2D";
    __android_log_print(...); // call PLT API at 0x51e90
    return a0;
}
