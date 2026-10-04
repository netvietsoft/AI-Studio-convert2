// Function: PVGCOLOR::PVGOpenGL::writeRGBA16DataToTexture2D(void*, int, int, int, int)
// RVA: 0x51eb0, Size: 348 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL26writeRGBA16DataToTexture2DEPviiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindTexture(...); // call PLT API at 0x51ef4
    glPixelStorei(...); // call PLT API at 0x51f00
    glPixelStorei(...); // call PLT API at 0x51f18
    glTexSubImage2D(...); // call PLT API at 0x51f40
    glPixelStorei(...); // call PLT API at 0x51f4c
    glPixelStorei(...); // call PLT API at 0x51f58
    glGetError(...); // call PLT API at 0x51f5c
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> writeRGBADataToTexture2D, glGetError %0x
";
    const char* str = "writeRGBA16DataToTexture2D";
    __android_log_print(...); // call PLT API at 0x51fa4
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL writeRGBA16DataToTexture2D failed: invalid parameters texture=%d data=%p
";
    const char* str = "writeRGBA16DataToTexture2D";
    __android_log_print(...); // call PLT API at 0x51fec
    return a0;
}
