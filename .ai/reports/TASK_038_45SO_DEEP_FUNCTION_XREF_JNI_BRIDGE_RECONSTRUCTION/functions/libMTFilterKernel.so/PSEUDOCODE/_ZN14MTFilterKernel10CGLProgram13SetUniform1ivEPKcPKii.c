// Function: MTFilterKernel::CGLProgram::SetUniform1iv(char const*, int const*, int)
// RVA: 0x1400f8, Size: 200 bytes
int64_t _ZN14MTFilterKernel10CGLProgram13SetUniform1ivEPKcPKii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGetUniformLocation(...); // call PLT API at 0x14011c
    glUniform1iv(...); // call PLT API at 0x14013c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140140
    const char* str = "FilterKernel";
    const char* str = "SetUniform1i there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x140168
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x14017c
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x1401ac
    return a0;
}
