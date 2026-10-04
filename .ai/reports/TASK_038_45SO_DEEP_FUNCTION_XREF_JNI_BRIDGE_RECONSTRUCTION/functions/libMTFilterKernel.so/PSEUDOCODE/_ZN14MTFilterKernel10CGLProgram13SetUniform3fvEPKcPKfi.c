// Function: MTFilterKernel::CGLProgram::SetUniform3fv(char const*, float const*, int)
// RVA: 0x14029c, Size: 196 bytes
int64_t _ZN14MTFilterKernel10CGLProgram13SetUniform3fvEPKcPKfi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x1402bc
    glUniform3fv(...); // call PLT API at 0x1402dc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1402e0
    const char* str = "FilterKernel";
    const char* str = "SetUniform3fv there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x140308
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x14031c
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x14034c
    return a0;
}
