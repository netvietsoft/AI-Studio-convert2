// Function: MTFilterKernel::GPUImageProgram::SetUniformMatrix3fv(char const*, float const*, bool, int, bool)
// RVA: 0x168718, Size: 196 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram19SetUniformMatrix3fvEPKcPKfbib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x168744
    glUniformMatrix3fv(...); // call PLT API at 0x16876c
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x168774
    glIsProgram(...); // call PLT API at 0x168788
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniformMatrix3fv";
    __android_log_print(...); // call PLT API at 0x1687c4
    return a0;
}
