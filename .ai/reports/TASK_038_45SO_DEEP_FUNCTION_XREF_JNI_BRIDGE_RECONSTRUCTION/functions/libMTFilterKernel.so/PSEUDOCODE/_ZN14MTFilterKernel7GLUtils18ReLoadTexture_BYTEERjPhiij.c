// Function: MTFilterKernel::GLUtils::ReLoadTexture_BYTE(unsigned int&, unsigned char*, int, int, unsigned int)
// RVA: 0x1430f4, Size: 500 bytes
int64_t _ZN14MTFilterKernel7GLUtils18ReLoadTexture_BYTEERjPhiij(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glBindTexture(...); // call PLT API at 0x143134
    glPixelStorei(...); // call PLT API at 0x14314c
    glTexSubImage2D(...); // call PLT API at 0x143174
    glGenTextures(...); // call PLT API at 0x143184
    glBindTexture(...); // call PLT API at 0x143194
    glTexParameterf(...); // call PLT API at 0x1431b0
    glTexParameterf(...); // call PLT API at 0x1431c0
    glTexParameteri(...); // call PLT API at 0x1431d0
    glTexParameteri(...); // call PLT API at 0x1431e0
    glPixelStorei(...); // call PLT API at 0x1431f8
    glTexImage2D(...); // call PLT API at 0x143220
    glPixelStorei(...); // call PLT API at 0x14322c
    glTexSubImage2D(...); // call PLT API at 0x143260
    glTexImage2D(...); // call PLT API at 0x143298
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1432a4
    const char* str = "FilterKernel";
    const char* str = "ERROR in ReLoadTexture_BYTE!";
    __android_log_print(...); // call PLT API at 0x1432c4
    return a0;
}
