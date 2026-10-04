// Function: MTFilterKernel::CGLProgram::SetUniform1f(char const*, float)
// RVA: 0x140708, Size: 188 bytes
int64_t _ZN14MTFilterKernel10CGLProgram12SetUniform1fEPKcf(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x140724
    glUniform1f(...); // call PLT API at 0x140740
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140744
    const char* str = "FilterKernel";
    const char* str = "SetUniform1f there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x14076c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140780
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x1407b0
    return a0;
}
