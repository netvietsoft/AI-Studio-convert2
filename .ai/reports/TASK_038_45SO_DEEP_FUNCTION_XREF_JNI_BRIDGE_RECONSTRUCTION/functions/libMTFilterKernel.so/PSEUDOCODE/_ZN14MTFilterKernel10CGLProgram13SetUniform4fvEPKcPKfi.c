// Function: MTFilterKernel::CGLProgram::SetUniform4fv(char const*, float const*, int)
// RVA: 0x140360, Size: 196 bytes
int64_t _ZN14MTFilterKernel10CGLProgram13SetUniform4fvEPKcPKfi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x140380
    glUniform4fv(...); // call PLT API at 0x1403a0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1403a4
    const char* str = "FilterKernel";
    const char* str = "SetUniform4fv there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x1403cc
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1403e0
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x140410
    return a0;
}
