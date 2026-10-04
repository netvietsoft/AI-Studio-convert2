// Function: MTFilterKernel::GLUtils::LoadTexture_BYTE(unsigned char*, int, int, unsigned int)
// RVA: 0x142f7c, Size: 376 bytes
int64_t _ZN14MTFilterKernel7GLUtils16LoadTexture_BYTEEPhiij(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call PLT API at 0x142fbc
    glBindTexture(...); // call PLT API at 0x142fcc
    glPixelStorei(...); // call PLT API at 0x142fe4
    glTexImage2D(...); // call PLT API at 0x14300c
    glPixelStorei(...); // call PLT API at 0x143018
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x143020
    const char* str = "FilterKernel";
    const char* str = "ERROR in loadTexture!";
    __android_log_print(...); // call PLT API at 0x143040
    glTexImage2D(...); // call PLT API at 0x143070
    glTexParameterf(...); // call PLT API at 0x14308c
    glTexParameterf(...); // call PLT API at 0x14309c
    glTexParameteri(...); // call PLT API at 0x1430ac
    glTexParameteri(...); // call PLT API at 0x1430bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x1430f0
}
