// Function: MTFilterKernel::CGLProgram::SetUniform3f(char const*, float, float, float)
// RVA: 0x1401c0, Size: 220 bytes
int64_t _ZN14MTFilterKernel10CGLProgram12SetUniform3fEPKcfff(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x1401e8
    glUniform3f(...); // call PLT API at 0x140210
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140214
    const char* str = "FilterKernel";
    const char* str = "SetUniform3f there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x14023c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140250
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x140284
    return a0;
}
