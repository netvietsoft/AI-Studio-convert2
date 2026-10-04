// Function: MTFilterKernel::CGLProgram::SetUniformMatrix4fv(char const*, float const*, bool, int)
// RVA: 0x140424, Size: 220 bytes
int64_t _ZN14MTFilterKernel10CGLProgram19SetUniformMatrix4fvEPKcPKfbi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel10CGLProgram18GetUniformLocationEPKc(...); // call internal at 0x14044c
    glUniformMatrix4fv(...); // call PLT API at 0x140474
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x140478
    const char* str = "FilterKernel";
    const char* str = "SetUniformMatrix4fv there is no uniform called: %s , m_Program = %d";
    __android_log_print(...); // call PLT API at 0x1404a0
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1404b4
    const char* str = "FilterKernel";
    const char* str = "Error:CGLProgram  shader:vertex:%s fragment:%s";
    __android_log_print(...); // call PLT API at 0x1404e8
    return a0;
}
