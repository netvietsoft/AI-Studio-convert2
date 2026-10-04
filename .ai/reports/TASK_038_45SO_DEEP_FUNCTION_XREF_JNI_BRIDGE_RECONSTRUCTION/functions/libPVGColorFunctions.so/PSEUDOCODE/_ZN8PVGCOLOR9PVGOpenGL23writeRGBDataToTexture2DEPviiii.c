// Function: PVGCOLOR::PVGOpenGL::writeRGBDataToTexture2D(void*, int, int, int, int)
// RVA: 0x51bf0, Size: 356 bytes
int64_t _ZN8PVGCOLOR9PVGOpenGL23writeRGBDataToTexture2DEPviiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindTexture(...); // call PLT API at 0x51c34
    glPixelStorei(...); // call PLT API at 0x51c40
    glPixelStorei(...); // call PLT API at 0x51c60
    glTexSubImage2D(...); // call PLT API at 0x51c88
    glPixelStorei(...); // call PLT API at 0x51c94
    glPixelStorei(...); // call PLT API at 0x51ca0
    glGetError(...); // call PLT API at 0x51ca4
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> writeRGBADataToTexture2D, glGetError %0x
";
    const char* str = "writeRGBDataToTexture2D";
    __android_log_print(...); // call PLT API at 0x51cec
    const char* str = "PVGColorFunctions";
    const char* str = "[%s(%d)]:> PVGOpenGL writeRGBDataToTexture2D failed: invalid parameters texture=%d data=%p
";
    const char* str = "writeRGBDataToTexture2D";
    __android_log_print(...); // call PLT API at 0x51d34
    return a0;
}
