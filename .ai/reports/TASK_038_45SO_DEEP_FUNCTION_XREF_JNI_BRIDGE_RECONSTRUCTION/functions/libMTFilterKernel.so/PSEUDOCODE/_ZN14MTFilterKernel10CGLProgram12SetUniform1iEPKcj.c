// Function: MTFilterKernel::CGLProgram::SetUniform1i(char const*, unsigned int)
// RVA: 0x14003c, Size: 188 bytes
int64_t _ZN14MTFilterKernel10CGLProgram12SetUniform1iEPKcj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x140058
    glUniform1i(...); // call PLT API at 0x140074
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140078
    const char* str = "FilterKernel";
    const char* str = "SetUniform1i there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x1400a0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1400b4
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x1400e4
    return a0;
}
