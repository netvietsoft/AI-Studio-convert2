// Function: MTFilterKernel::GPUImageProgram::SetUniformMatrix4fv(char const*, float const*, bool, int, bool)
// RVA: 0x168654, Size: 196 bytes
int64_t _ZN14MTFilterKernel15GPUImageProgram19SetUniformMatrix4fvEPKcPKfbib(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN14MTFilterKernel15GPUImageProgram18GetUniformLocationEPKc(...); // call internal at 0x168680
    glUniformMatrix4fv(...); // call PLT API at 0x1686a8
    MTRTFILTERKERNEL_GetLogLevel(...); // call internal at 0x1686b0
    glIsProgram(...); // call PLT API at 0x1686c4
    const char* str = "FilterKernel";
    const char* str = "%s there is no uniform called: %s , m_Program = %d, %d";
    const char* str = "SetUniformMatrix4fv";
    __android_log_print(...); // call PLT API at 0x168700
    return a0;
}
