// Function: MTFilterKernel::CGLProgram::SetUniformMatrix3fv(char const*, float const*, bool, int)
// RVA: 0x140500, Size: 220 bytes
int64_t _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix3fvEPKcPKfbi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x140528
    glUniformMatrix3fv(...); // call PLT API at 0x140550
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140554
    const char* str = "FilterKernel";
    const char* str = "SetUniformMatrix3fv there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x14057c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140590
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x1405c4
    return a0;
}
