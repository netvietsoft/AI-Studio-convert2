// Function: MTFilterKernel::CGLProgram::SetUniform2f(char const*, float, float)
// RVA: 0x1407c4, Size: 196 bytes
int64_t _ZN14MTFilterKernel10CGLProgram12SetUniform2fEPKcff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x1407e4
    glUniform2f(...); // call PLT API at 0x140804
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140808
    const char* str = "FilterKernel";
    const char* str = "SetUniform2f there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x140830
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140844
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x140874
    return a0;
}
