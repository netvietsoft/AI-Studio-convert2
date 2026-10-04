// Function: MTFilterKernel::CGLProgram::SetUniform4f(char const*, float, float, float, float)
// RVA: 0x140888, Size: 228 bytes
int64_t _ZN14MTFilterKernel10CGLProgram12SetUniform4fEPKcffff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x1408b4
    glUniform4f(...); // call PLT API at 0x1408e0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1408e4
    const char* str = "FilterKernel";
    const char* str = "SetUniform4f there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x14090c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140920
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x140954
    return a0;
}
