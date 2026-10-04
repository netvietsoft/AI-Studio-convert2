// Function: MTFilterKernel::CGLProgram::SetUniform1fv(char const*, float const*, int)
// RVA: 0x14096c, Size: 196 bytes
int64_t _ZN14MTFilterKernel10CGLProgram13SetUniform1fvEPKcPKfi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x14098c
    glUniform1fv(...); // call PLT API at 0x1409ac
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1409b0
    const char* str = "FilterKernel";
    const char* str = "SetUniform1fv there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x1409d8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1409ec
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x140a1c
    return a0;
}
